//
// Created by xxmen on 2019-06-15.
//

#include "Game.h"
#include <cstdlib>
#include <termios.h>  // for tcxxxattr, ECHO, etc ..
#include <unistd.h>    // for STDIN_FILENO
#include <cstring>


std::mutex m;

int getch (){
    char ch;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    memcpy(&newt, &oldt, sizeof(newt));
    newt.c_lflag &= ~( ECHO | ICANON | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}

void Game::getInput(){
    char c;
    while(true){
        c = getch();
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
    system("clear");
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