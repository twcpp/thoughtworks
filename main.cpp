#include <iostream>
#include "lib/Game.h"

using namespace std;

void gamePlay(Game &g){  // main game play function
    g.play();
}

void getSpeedInput(Game &g){  // function for listening user input
    g.getInput();
}

int main(int argc, char** argv) {
    int h, w;                        // size of the board
    ios::sync_with_stdio(false);
    Board board;
    if(argc == 3){                  // if user input h and w, randomly initialized live cells
        h = atoi(argv[1]);
        w = atoi(argv[2]);
        vector<pair<int, int>> live_cell;
        srand(time(NULL));          // seed for random generator
        for (int i = 0; i < h * w / 10; i++)         // randomly initialized live cells
            live_cell.push_back(pair<int, int>(rand() % h, rand() % w));
        board = Board(h,w,live_cell);


    }else if(argc == 2){            // if user input a filename, initialize cells with pre-defined list.
        board = Board(argv[1]);
    } else{
        cout << "invalid arguments" << endl;
        return -1;
    }

    auto display = Display();
    auto game = Game(board,display,1000);
    thread t_game (ref(gamePlay),ref(game));          // main game play thread
    thread t_listen (ref(getSpeedInput),ref(game));   // thread for listening user input
    t_game.join();
    t_listen.join();
    return 0;
}