#include "Board.h"

Board::Board(int h, int w) {
    this->h = h;
    this->w = w;
    cells = vector<vector<bool>>(h,vector<bool>(w));
}

vector<vector<bool>> Board::getBoard() {
    return cells;
}