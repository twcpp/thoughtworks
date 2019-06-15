//
// Created by Bang  on 2019-06-13.
//
#include <catch2/catch.hpp>
#include "../lib/Board.h"
#include <iostream>

TEST_CASE("should return empty board") {
    vector<pair<int, int>> empty;
    auto *board = new Board(4, 4, empty);
    vector<vector<bool>> right_board = vector<vector<bool>>(4,vector<bool>(4));
    REQUIRE(board->getBoard() == right_board);
}

TEST_CASE("should return board") {
    vector<pair<int, int>> test1;
    test1.push_back(pair<int,int>(1,2));
    auto *board = new Board(4, 4, test1);
    vector<vector<bool>> right_board = vector<vector<bool>>(4,vector<bool>(4));
    right_board[1][2] = true;
    REQUIRE(board->getBoard() == right_board);
}

TEST_CASE("should return num of neighbor1") {
    vector<pair<int, int>> test1;
    test1.push_back(pair<int,int>(1,2));
    vector<vector<bool>> right_board = vector<vector<bool>>(4,vector<bool>(4));
    auto *board = new Board(4, 4, test1);
    right_board[1][2] = true;
    REQUIRE(board->countnNeighbor(right_board, 3, 3) == 0);
}

TEST_CASE("should return num of neighbor2") {
    vector<pair<int, int>> test1;
    test1.push_back(pair<int,int>(1,2));
    vector<vector<bool>> right_board = vector<vector<bool>>(4,vector<bool>(4));
    right_board[1][2] = true;
    auto *board = new Board(4, 4, test1);
    REQUIRE(board->countnNeighbor(right_board, 1, 1) == 1);
}

TEST_CASE("should return board after 1 iteration") {
    vector<pair<int, int>> test1;
    test1.push_back(pair<int,int>(0,0));
    test1.push_back(pair<int,int>(0,3));
    test1.push_back(pair<int,int>(1,1));
    test1.push_back(pair<int,int>(1,2));
    test1.push_back(pair<int,int>(2,1));
    test1.push_back(pair<int,int>(2,2));
    test1.push_back(pair<int,int>(3,0));
    test1.push_back(pair<int,int>(3,3));

    vector<vector<bool>> right_board = vector<vector<bool>>(4,vector<bool>(4));
    right_board[0][1] = right_board[0][2] = right_board[1][0] = right_board[1][3] = true;
    right_board[2][0] = right_board[2][3] = right_board[3][1] = right_board[3][2] = true;

    auto *board = new Board(4, 4, test1);
    board->processBoard();
    REQUIRE(board->getBoard() == right_board);
}



