#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dblitr/dblitr.h"

TEST_CASE("abs() returns the number given in constructor", "[]") {
    elh::doubled_iterator i{8};
    REQUIRE(i.abs() == 8);
}
