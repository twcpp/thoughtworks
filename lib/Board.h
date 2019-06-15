#include <vector>
#include <iostream>
#include <utility>
using  namespace std;

class Board {
public:
    Board(int h, int w, vector<pair<int, int>> &live_cell) ;
    vector<vector<bool>> getBoard();

private:
    int h;
    int w;
    vector<vector<bool>> cells;
};


