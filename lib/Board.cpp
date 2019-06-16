#include "Board.h"

inline int Board::encodePos(int x, int y){
    return x * w + y;
}

Board::Board(int h, int w, vector<pair<int, int>> &live_cell) {
    this->h = h;
    this->w = w;
    cells = vector<vector<bool>>(h,vector<bool>(w));
    while (!que.empty())
        que.pop();
    for (auto i : live_cell){
        cells[i.first][i.second] = true;
        que.push(encodePos(i.first, i.second));
    }
    iter = 0;
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
    bool vis[h+5][w+5];
    memset(vis, false, sizeof(vis));
    int last_value = que.back();
    while (!que.empty())
    {
        int head = que.front();
        que.pop();
        int x = head / w, y = head % w;
        for (int ix = -1; ix <= 1; ix++)
        {
            for (int iy = -1; iy <= 1; iy++)
            {
                int tx = x + ix;
                int ty = y + iy;
                if (tx < 0 || tx >= h || ty < 0 || ty >= w)
                    continue;
                int cnt = countnNeighbor(tmp, tx, ty);
                if (cnt == 3)
                {
                    cells[tx][ty] = true;
                    if (!tmp[tx][ty] && !vis[tx][ty])
                    {
                        que.push(encodePos(tx, ty));
                        vis[tx][ty] = true;
                    }
                    continue;
                }
                else if (cnt != 2 && tmp[tx][ty])
                {
                    cells[tx][ty] = false;
                    if (!vis[tx][ty])
                    {
                        que.push(encodePos(tx, ty));
                        vis[tx][ty] = true;
                    }
                }
            }
        }
        if (head == last_value)   // already process all changed cells from last round
            break;
    }
    iter++;
}

void Board::processBoard_naive()
{
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

