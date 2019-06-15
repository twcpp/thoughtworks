#include "Board.h"

Board::Board(int h, int w, vector<pair<int, int>> &live_cell) {
    this->h = h;
    this->w = w;
    cells = vector<vector<bool>>(h,vector<bool>(w));
    for (auto i : live_cell){
        cells[i.first][i.second] = true;
    }
}

vector<vector<bool>> Board::getBoard() {
    return cells;
}

void processBoard() {

}