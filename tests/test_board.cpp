//
// Created by Bang  on 2019-06-13.
//
#include <catch2/catch.hpp>
#include "../lib/Board.h"
#include <iostream>

TEST_CASE("should return board") {
    auto *board = new Board(4, 4);
    vector<vector<bool>> right_board = vector<vector<bool>>(4,vector<bool>(4));
    REQUIRE(board->getBoard() == right_board);
}