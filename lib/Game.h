//
// Created by xxmen on 2019-06-15.
//

#ifndef TW_GAME_H
#define TW_GAME_H


#include "Display.h"
#include <thread>
#include <mutex>

class Game
{
public:
    Game(Board &b, Display &d, int delay);
    void play();
    void setDelay(int delay);
    void getInput();

private:
    Board b;
    Display d;
    int delay;  // in ms
};


#endif //TW_GAME_H
