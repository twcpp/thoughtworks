//
// Created by xxmen on 2019-06-15.
//

#include "Game.h"
#include <unistd.h>

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
        usleep(1000*delay);
        b.processBoard();
        d.printBoard(b);
    }
}