#include <iostream>

using namespace std;

#include "Init.h"
#include "Command.h"
#include "Display.h"

void GamePlay()
{
    int Board[100][100], isMine[100][100], row, col, Mines, isFlag[100][100];
    bool isFlip[100][100];
    Init(Board, row, col, Mines, isFlip, isMine, isFlag);
    int GameOver = 0;
    while (!GameOver)
    {
        Command(Board, row, col, Mines, isFlip, isMine, isFlag, GameOver);
        //Display();
        if (GameOver == 1) cout << "\n\nU lose";
        if (GameOver == 2) cout << "\n\nU win";
    }
}

int main()
{
    int c;
    while (1)
        {   cout << "Welcome to Minesweeper made by MinhGiang & HoaiNam\n";
            cout << "1. Play game\n2. Exit\nPlease input 1 or 2:\n";
            cin >> c;
            if (c == 2) {cout << "See u again!! :>"; break;}
            GamePlay();
        }
    return 0;
}

