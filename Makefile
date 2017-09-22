CC=g++
CC_OPT=-Wall -W
CC_OPT_DEBUG=-g3 -O0
CC_OPT_RELEASE=-O2
LD=ar rcs
LD_OPT=
SRC_DIR=src
BUILD_DIR=build
SOURCES  = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS  = $(addprefix $(BUILD_DIR)/, $(subst .cpp,.o,$(notdir $(SOURCES))))
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
build: libdblitr.a

build_dir:
	mkdir -p build

libdblitr.a: $(OBJECTS)
	$(LD) $@ $^ $(LD_OPT)

$(BUILD_DIR)/%.o: $(SOURCES) build_dir
	$(CC) -o $@ -c $(SOURCES) $(CC_OPT)

.PHONY: clean
clean:
	$(RM) $(RM_TARGETS)