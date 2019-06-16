#include "Board.h"

inline int Board::encodePos(int x, int y){                // change x and y to single int
    return x * w + y;
}

Board::Board(int h, int w, vector<pair<int, int>> &live_cell) { // constructor with randomly initialized live cell list
    this->h = h;                                         // set height
    this->w = w;                                         // set width
    cells = vector<vector<bool>>(h,vector<bool>(w));     // init cell board
    while (!que.empty())                                 // clear queue
        que.pop();
    for (auto i : live_cell){                            // add live cell
        cells[i.first][i.second] = true;
        que.push(encodePos(i.first, i.second));
    }
    iter = 0;                                            // set iteration counter to 0
}

Board::Board(string filename)                            // constructor with input file
{
    ifstream fin(filename.c_str());
    string s;
    int x, y;
    fin >> h >> w;                                       // read height and width
    cells = vector<vector<bool>>(h,vector<bool>(w));
    while (!que.empty())
        que.pop();
    while(fin>>x>>y){                                    // add live cell
        cells[x][y] = true;
        que.push(encodePos(x, y));
    }
    fin.close();
    iter = 0;                                            // set iteration counter to 0
}

int Board::getIter(){
    return iter;
}

vector<vector<bool>> &Board::getBoard() {
    return cells;
}

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};   // offset array for retrieving neighbors
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int Board::countnNeighbor(vector<vector<bool>> &tmp, int x, int y){  // count the number of live cell in neighbors
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= h || ty < 0 || ty >= w)   // check position
            continue;
        if (tmp[tx][ty])
            cnt++;
    }
    return cnt;
}

bool Board::processBoard() {    // process board for 1 iteration
    auto tmp = cells;
    bool vis[h+5][w+5];               // flag of whether (i,j) is in the queue
    memset(vis, false, sizeof(vis));  // set to false
    int last_value = que.back();      // get the last element in this round
    if (que.empty()){                 // already becoming stable
        return true;
    }
    while (!que.empty())
    {
        int head = que.front();              // get the first element
        que.pop();
        int x = head / w, y = head % w;
        for (int ix = -1; ix <= 1; ix++)     // check neightbors (containing itself)
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
                    if (!tmp[tx][ty] && !vis[tx][ty])  // cell state changed
                    {
                        que.push(encodePos(tx, ty));   // add to queue
                        vis[tx][ty] = true;            // set flag to true
                    }
                    continue;
                }
                else if (cnt != 2 && tmp[tx][ty])      // cell state changed
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
    iter++;   // increase counter
    return false;
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

