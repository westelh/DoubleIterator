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

TEST_CASE("setting position by coord", "[]") {
    elh::doubled_iterator<12, 12> i{32};
    elh::doubled_iterator<12, 12>::coord pos{1, 3};
    i.set_crd(pos);

    SECTION("checking with abs") {
        REQUIRE(i.abs() == 37);
    }

    SECTION("checking with crd") {
        REQUIRE(i.crd().first == 1);
        REQUIRE(i.crd().second == 3);
    }
}

TEST_CASE("operators test", "[operator]") {
    elh::doubled_iterator<10, 10> i{12};
    elh::doubled_iterator<10, 10> h{12};
    elh::doubled_iterator<10, 10> j{31};

    SECTION("checking operator==") {
        REQUIRE(i == h);
        REQUIRE_FALSE(i == j);
        REQUIRE_FALSE(h == j);
    }

    SECTION("checking operator!=") {
        REQUIRE_FALSE(i != h);
        REQUIRE(i != j);
        REQUIRE(h != j);
    }

    SECTION("checking operator>") {
        REQUIRE(j > h);
        REQUIRE_FALSE(i > h);
        REQUIRE_FALSE(h > j);
    }

    SECTION("checking operator<") {
        REQUIRE(i < j);
        REQUIRE_FALSE(i < h);
        REQUIRE_FALSE(j < i);
    }

    SECTION("checking operator>=") {
        REQUIRE(i >= h);
        REQUIRE(j >= h);
        REQUIRE_FALSE(i >= j);
    }
    
    SECTION("checking operator<=") {
        REQUIRE(h <= i);
        REQUIRE(h <= j);
        REQUIRE_FALSE(j <= h);
    }
}
