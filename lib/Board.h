#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using  namespace std;
#define  MAXH 1000
#define  MAXW 1000

class Board {
public:
    Board(){}
    Board(int h, int w, vector<pair<int, int>> &live_cell) ;
    vector<vector<bool>> &getBoard();
    void processBoard();
    void processBoard_naive();
    int countnNeighbor(vector<vector<bool>> &tmp, int x, int y);
    inline int encodePos(int x, int y);

private:
    int h;
    int w;
    vector<vector<bool>> cells;
    queue<int> que;
    int iter;
};


