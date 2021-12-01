#include <iostream>
#include <windows.h>

using namespace std;

#include "Init.h"
#include "Command.h"
#include "Display.h"
#include "consoletext.h"

void GamePlay()
{
    int Board[100][100], isMine[100][100], row, col, Mines, isFlag[100][100];
    bool isFlip[100][100];
    memset(Board, 0, sizeof Board);
    memset(isMine, 0, sizeof isMine);
    memset(isFlag, 0, sizeof isFlag);
    memset(isFlip, 0, sizeof isFlip);
    Init(Board, row, col, Mines, isFlip, isMine, isFlag);
    int GameOver = 0, ValidCells = row * col - Mines;
    while (!GameOver)
    {
        DisplayBoard(Board, row, col, Mines, isFlip, isMine, isFlag);
        Command(Board, row, col, Mines, isFlip, isMine, isFlag, GameOver, ValidCells);
        if (GameOver)
        {
            DisplayBoard(Board, row, col, Mines, isFlip, isMine, isFlag);
            if (GameOver == 1) cout << "\nU lose\n";
            else cout << "\nU win\n";
            Sleep(3);
        }
    }
}

int main()
{
    int c;
    DisableResizeWindow();
    SetWindowSize(60, 15);
    SetScreenBufferSize(60, 15);
    while (1)
        {
            system("cls");
            cout << "Welcome to Minesweeper made by MinhGiang & HoaiNam\n";
            cout << "1. Play game\n2. Exit\nPlease input 1 or 2:\n";
            cin >> c;
            if (c == 2) {cout << "See u again!! :>"; break;}
            GamePlay();
        }
    return 0;
}

