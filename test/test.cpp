#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dblitr/dblitr.h"

TEST_CASE("abs() returns the number given in constructor", "[]") {
    elh::doubled_iterator<10, 10> i{8};
    REQUIRE(i.abs() == 8);

    elh::doubled_iterator<10, 10> h{4212};
    REQUIRE(h.abs() == 4212);
}

TEST_CASE("crd() returns the number given in constructor", "[]") {
    elh::doubled_iterator<10, 10> i{8};
    REQUIRE(i.crd().first == 8);
    REQUIRE(i.crd().second == 0);

    elh::doubled_iterator<10, 10> h{23};
    REQUIRE(h.crd().first == 3);
    REQUIRE(h.crd().second == 2);
}

TEST_CASE("abs set and get", "[]") {
    elh::doubled_iterator<10, 10> i{0};
    i.set_abs(100);
    REQUIRE(i.abs() == 100);
}
