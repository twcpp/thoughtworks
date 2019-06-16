#include "Display.h"

void Display::printBoard(Board &board){
    vector<vector<bool>> &cells = board.getBoard();
    for (auto row:cells)
    {
        for (bool i:row)
        {
            if (i)                // live cell
                //cout<<"◉ ";
                cout<<"🌝 ";
            else                  // dead cell
                //cout<<"☐ ";
                cout<<"🌚 ";
        }
        cout<<endl;
    }
    cout<<endl;

}