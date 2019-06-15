#include <iostream>
#include "lib/Board.h"

using namespace std;

int main() {
    int h, w;
    cin>>h>>w;
    Board board = Board(h, w);
    auto b = board.getBoard();
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }

}