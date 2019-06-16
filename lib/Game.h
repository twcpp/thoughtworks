#ifndef TW_GAME_H
#define TW_GAME_H


#include "Display.h"
#include <thread>
#include <mutex>

class Game
{
public:
    Game(Board &b, Display &d, int delay);
    void play();                            // main game function
    void getInput();                        // get user input for controlling speed

private:
    Board b;
    Display d;
    int delay;  // delay in ms
};


#endif //TW_GAME_H
