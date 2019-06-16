#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;

class Board {
public:
    Board(){}
    Board(string filename);
    Board(int h, int w, vector<pair<int, int>> &live_cell) ;
    vector<vector<bool>> &getBoard();
    int getIter();
    bool processBoard();                                          // process board for 1 iteration
    void processBoard_naive();                                    // naive process board for 1 iteration
    int countnNeighbor(vector<vector<bool>> &tmp, int x, int y);  // count the number of live cell in neighbors
    inline int encodePos(int x, int y);                           // encode x and y in a single int

private:
    int h;                        // board height
    int w;                        // board width
    vector<vector<bool>> cells;   // board
    queue<int> que;               // queue for storing changed cells
    int iter;                     // iteration counter
};


