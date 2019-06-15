//
// Created by xxmen on 2019-06-15.
//

#include "Display.h"

void Display::printBoard(Board &board){
    vector<vector<bool>> &cells = board.getBoard();
    for (auto row:cells)
    {
        for (bool i:row)
        {
            if (i)
                cout<<"◉ ";
            else
                cout<<"☐ ";
        }
        //cout<<"\n --------------------- "<<endl;
        cout<<endl;
    }
    cout<<endl;

}