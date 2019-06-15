//
// Created by Bang  on 2019-06-13.
//
#include <catch2/catch.hpp>
#include "../lib/Circle.h"

TEST_CASE("should return area") {
    auto *circle = new Circle(5);
    REQUIRE(circle->area() == 31.415926);
}