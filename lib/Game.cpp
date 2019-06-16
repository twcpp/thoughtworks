#include "Game.h"
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <cstring>
#include <iomanip>


std::mutex m;  // lock for delay

int getch (){  // read 1 char
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

void Game::getInput(){  // get user input for controlling speed
    char c;
    while(true){
        c = getch();
        m.lock();
        if(c == '=' || c == '+'){  // increase speed
            if(delay > 200){
                delay -= 200;
            }
            else{
                delay = 40;
            }
        }else if(c == '-'){        // decrease speed
            if (delay < 200)
                delay = 200;
            else
                delay += 200;
        }
        m.unlock();
    }

}


Game::Game(Board &b, Display &d, int delay) // init game
{
    this->b = b;
    this->d = d;
    this->delay = delay;

}

void Game::play()
{
    system("clear");   // clear screen
    cout << "Num of interation: " << b.getIter() << "    Display speed: " << setprecision(2) << 1000.0 / delay << endl;
    d.printBoard(b);
    while(true){
        m.lock();
        int st = 1000 * delay;
        m.unlock();
        usleep(st);    // for controlling speed
        bool stable = b.processBoard();
        system("clear");
        cout << "Num of interation: " << b.getIter() << "    Display speed: " << setprecision(2) << 1000.0 / delay << endl;
        d.printBoard(b);
        if (stable)    // board becoming stable
        {
            cout << "Becoming stable after " << b.getIter() << " iterations." << endl;
            break;
        }
    }
}