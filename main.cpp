#include <iostream>
#include "lib/Game.h"

using namespace std;

int main() {
    int h, w;
    cin>>h>>w;

    vector<pair<int, int>> test1;
    test1.push_back(pair<int,int>(0,0));
    test1.push_back(pair<int,int>(0,3));
    test1.push_back(pair<int,int>(1,2));
    test1.push_back(pair<int,int>(2,2));
    test1.push_back(pair<int,int>(3,0));

    auto board = Board(h, w, test1);
    auto display = Display();
    auto game = Game(board,display,1000);
    game.play();
    return 0;
}