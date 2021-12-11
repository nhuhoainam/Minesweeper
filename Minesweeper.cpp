#include <iostream>
#include <iomanip>
#include <windows.h>
#include <chrono>

#define MAX_SIZE 100

using namespace std;

#include "Init.h"
#include "Command.h"
#include "Display.h"
#include "consoletext.h"

struct Grid;

void GamePlay()
{
    Grid Board;
    Init(Board);
    int GameOver = 0, ValidCells = Board.row * Board.col - Board.Mines;
    auto start = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds;
    while (!GameOver)
    {
        DisplayBoard(Board);
        Command(Board, GameOver, ValidCells);
        if (GameOver)
        {
            FlipAllMines(Board);
            DisplayBoard(Board);
            if (GameOver == 1) cout << "\nYou lose\n";
            else {
                auto end = chrono::steady_clock::now();
                elapsed_seconds = end - start;
                cout << "\nYou win (" << fixed << setprecision(1) << elapsed_seconds.count() << "seconds)\n";
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

