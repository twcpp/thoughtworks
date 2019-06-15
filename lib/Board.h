#include <vector>
#include <iostream>
using  namespace std;

class Board {
public:
    Board(int h, int w);
    vector<vector<bool>> getBoard();

private:
    int h;
    int w;
    vector<vector<bool>> cells;

};


