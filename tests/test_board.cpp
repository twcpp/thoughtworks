//
// Created by Bang  on 2019-06-13.
//
#include <catch2/catch.hpp>
#include "../lib/Board.h"
#include <iostream>
#include <time.h>

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

TEST_CASE("should return board after 5 iteration") {
    vector<pair<int, int>> test1;
    test1.push_back(pair<int,int>(0,0));
    test1.push_back(pair<int,int>(0,3));
    test1.push_back(pair<int,int>(1,2));
    test1.push_back(pair<int,int>(2,2));
    test1.push_back(pair<int,int>(3,0));

    vector<vector<bool>> right_board = vector<vector<bool>>(4,vector<bool>(4));
    right_board[0][1] = right_board[0][2] = right_board[1][0] = right_board[1][3] = true;
    right_board[2][1] = right_board[2][2] = true;

    auto *board = new Board(4, 4, test1);
    for (int i = 0; i < 5; i++)
        board->processBoard();
    REQUIRE(board->getBoard() == right_board);
}

TEST_CASE("should return same board") {
    int h = 500, w = 500;
    vector<pair<int, int>> test1;
    for (int i = 0; i < 100 * 100; i++)
        test1.push_back(pair<int, int>(rand() % h, rand() % w));

    clock_t start, end; // typedef long clock_t
    start = clock();

    auto *right_board = new Board(h, w, test1);
    for (int i = 0; i < 500; i++)
        right_board->processBoard_naive();

    end = clock();
    double duration =(double)(end - start)/CLOCKS_PER_SEC;
    cout<<"Total time: "<<duration<<" s"<<endl;

    start = clock();

    auto *board = new Board(h, w, test1);
    for (int i = 0; i < 500; i++)
        board->processBoard();

    end = clock();
    duration =(double)(end - start)/CLOCKS_PER_SEC;
    cout<<"Total time: "<<duration<<" s"<<endl;

    REQUIRE(board->getBoard() == right_board->getBoard());
}





