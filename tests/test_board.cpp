//
// Created by Bang  on 2019-06-13.
//
#include <catch2/catch.hpp>
#include "../lib/Circle.h"

TEST_CASE("should return board") {
    auto *board = new Board(4, 4);
    REQUIRE(board->getBoard() == [[0,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,0]]);
}