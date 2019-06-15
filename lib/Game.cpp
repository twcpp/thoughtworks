//
// Created by xxmen on 2019-06-15.
//

#include "Game.h"
#include <unistd.h>
#include <cstdlib>
#include <curses.h>


std::mutex m;


void Game::getInput(){
    char c;
    while(true){
        cin.get(c);
        m.lock();
        if(c == '='){
            if(delay > 200){
                delay -= 200;
            }
        }else if(c == '-'){
            delay += 200;
        }
        m.unlock();
    }

}


Game::Game(Board &b, Display &d, int delay)
{
    this->b = b;
    this->d = d;
    this->delay = delay;

}
void Game::setDelay(int delay)
{
    this->delay = delay;
}
void Game::play()
{
    d.printBoard(b);
    while(true){
        m.lock();
        int st = 1000 * delay;
        m.unlock();
        usleep(st);
        cout << delay << endl;
        b.processBoard();
        system("clear");
        d.printBoard(b);

    }
}