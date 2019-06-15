#include <iostream>
#include "lib/Game.h"

using namespace std;

void f1(Game &g){
    g.play();
}

void f2(Game &g){
    g.getInput();
}

int main() {
    int h, w;
    cin>>h>>w;

    vector<pair<int, int>> test1;
    test1.push_back(pair<int,int>(0,0));
    test1.push_back(pair<int,int>(0,3));
    test1.push_back(pair<int,int>(1,2));
    test1.push_back(pair<int,int>(2,2));
    test1.push_back(pair<int,int>(3,0));

    for (int i = 0; i < 50; i++)
        test1.push_back(pair<int,int>(rand() % h, rand() % w));

    auto board = Board(h, w, test1);
    auto display = Display();
    auto game = Game(board,display,1000);
    thread t1 (ref(f1),ref(game));
    thread t2 (ref(f2),ref(game));
    t1.join();
    t2.join();
    return 0;
}