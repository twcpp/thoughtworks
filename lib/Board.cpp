#include "Board.h"

Board::Board(int h, int w, vector<pair<int, int>> &live_cell) {
    this->h = h;
    this->w = w;
    cells = vector<vector<bool>>(h,vector<bool>(w));
    for (auto i : live_cell){
        cells[i.first][i.second] = true;
    }
}

vector<vector<bool>> &Board::getBoard() {
    return cells;
}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Board::countnNeighbor(vector<vector<bool>> &tmp, int x, int y){
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= h || ty < 0 || ty >= w)
            continue;
        if (tmp[tx][ty])
            cnt++;
    }
    return cnt;
}

void Board::processBoard() {
    auto tmp = cells;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int cnt = countnNeighbor(tmp,i,j);
            switch(cnt){
                case 3:
                    cells[i][j] = true;
                    break;
                case 2:
                    break;
                default:
                    cells[i][j] = false;
                    break;
            }
        }
    }
}

