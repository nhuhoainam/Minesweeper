#include <iostream>
#include <iomanip>
#include <windows.h>
#include <chrono>

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
    auto start = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds;
    while (!GameOver)
    {
        DisplayBoard(Board, row, col, Mines, isFlip, isMine, isFlag);
        Command(Board, row, col, Mines, isFlip, isMine, isFlag, GameOver, ValidCells);
        if (GameOver)
        {
            DisplayBoard(Board, row, col, Mines, isFlip, isMine, isFlag);
            if (GameOver == 1) cout << "\nU lose\n";
            else {
                auto end = chrono::steady_clock::now();
                elapsed_seconds = end - start;
                cout << "\nU win (" << fixed << setprecision(1) << elapsed_seconds.count() << "seconds)\n"; 
            }
            Sleep(1000);
            system("pause");
        }
    }
}

int main()
{
    int c;
    DisableResizeWindow();
    SetWindowSize(70, 50);
    SetScreenBufferSize(70, 50);
    SetColor(255);
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

