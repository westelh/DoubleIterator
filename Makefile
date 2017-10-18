CC=g++
CC_OPT=-Wall -W -std=c++14
CC_OPT_DEBUG=-g3 -O0
CC_OPT_RELEASE=-O2

LD=ar rcs
LD_OPT=

SRC_DIR=src
TEST_DIR=test
INCLUDE=include
BUILD_DIR=build

SOURCES  = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS  = $(addprefix $(BUILD_DIR)/, $(subst .cpp,.o,$(notdir $(SOURCES))))

TESTSRCS = $(wildcard test/*.cpp)

RM=rm -r
RM_TARGETS=build 

.PHONY: all
all: debug
	
.PHONY: debug
debug:CC_OPT+=$(CC_OPT_DEBUG)
debug: build

.PHONY: release
release: CC_OPT+=$(CC_OPT_RELEASE)
release: build 

.PHONY: build
build: $(BUILD_DIR)/libdblitr.a

.PHONY: test
test: $(BUILD_DIR)/test_all
	./$^

build_dir:
	mkdir -p build

$(BUILD_DIR)/libdblitr.a: $(OBJECTS)
	$(LD) $@ $^ $(LD_OPT)

$(BUILD_DIR)/test_all: $(TESTSRCS) $(BUILD_DIR)/libdblitr.a
	$(CC) -o $@ $(TESTSRCS) -Icatch/include -I$(INCLUDE) $(CC_OPT) -L$(BUILD_DIR) -ldblitr

$(BUILD_DIR)/%.o: $(SOURCES) build_dir
	$(CC) -o $@ -c $(SOURCES) -I$(INCLUDE) $(CC_OPT)

.PHONY: clean
clean:
	$(RM) $(RM_TARGETS)
