#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <chrono>
#include <algorithm>

#define MAX_SIZE 100

using namespace std;

#include "Leaderboard.h"
#include "Init.h"
#include "Command.h"
#include "Display.h"
#include "consoletext.h"

bool PlayMenu();
void NewGame(Grid& Board, int& GameOver, int& ValidCells);
void GamePlay(Grid& Board, int& GameOver, int& ValidCells, float& elapsed_time);

int main()
{
    int c;
    DisableResizeWindow();
    SetWindowSize(70, 50);
    SetScreenBufferSize(70, 50);
    SetColor(255);
    while (1)
        {
            Leaderboard LB;
            system("cls");
            cout << "Welcome to Minesweeper made by MinhGiang & HoaiNam\n";
            cout << "1. Play game\n2. See Leaderboard\n3. Exit\nEnter a command:\n";
            cin >> c;
            if (c == 1) while(!PlayMenu());
            else if (c == 2) {SeeLeaderboard(LB); continue;}
            if (c == 3) {cout << "See u again!! :>"; break;}
            else {cout << "Invalid Command!"; continue;};
        }
    return 0;
}

bool PlayMenu() {
    system("cls");
    cout << "1. New game\n2. Load saved game\nEnter a command:\n";
    int c;
    cin >> c;
    Grid Board;
    int GameOver = 0, ValidCells;
    float elapsed_time;
    if(c == 1)
        NewGame(Board, GameOver, ValidCells);
    else if(c == 2) {
        ifstream fin;
        fin.open("Save.txt");
        bool saved;
        fin >> saved;
        if (!saved) {
            cout << "No saved game found!\n";
            return false;
        }
        fin >> Board.dif >> Board.row >> Board.col >> Board.Mines >> ValidCells >> elapsed_time;
        for (int i = 0; i < Board.row; i++) {
            for (int j = 0; j < Board.col; j++) {
                fin >> Board.Board[i][j];
            }
        }
        for (int i = 0; i < Board.row; i++) {
            for (int j = 0; j < Board.col; j++) {
                fin >> Board.isMine[i][j];
            }
        }
        for (int i = 0; i < Board.row; i++) {
            for (int j = 0; j < Board.col; j++) {
                fin >> Board.isFlag[i][j];
            }
        }
        for (int i = 0; i < Board.row; i++) {
            for (int j = 0; j < Board.col; j++) {
                fin >> Board.isFlip[i][j];
            }
        }        
        fin.close();
        GamePlay(Board, GameOver, ValidCells, elapsed_time);
        return true;
    }
}

void NewGame(Grid& Board, int& GameOver, int& ValidCells) {
    memset(Board.Board, 0, sizeof Board.Board);
    memset(Board.isMine, 0, sizeof Board.isMine);
    memset(Board.isFlag, 0, sizeof Board.isFlag);
    memset(Board.isFlip, 0, sizeof Board.isFlip);
    Init(Board);
    GameOver = 0, ValidCells = Board.row * Board.col - Board.Mines;
    float elapsed_time = 0;
    GamePlay(Board, GameOver, ValidCells, elapsed_time);
}

void GamePlay(Grid& Board, int& GameOver, int& ValidCells, float& elapsed_time)
{
    Leaderboard LB;
    LoadLeaderboard(LB);
    auto start = chrono::steady_clock::now();
    while (!GameOver)
    {
        DisplayBoard(Board);
        if (!Command(Board, GameOver, ValidCells, start)) break;
        if (GameOver)
        {
            FlipAllMines(Board);
            DisplayBoard(Board);
            if (GameOver == 1) cout << "\nYou lose\n";
            else {
                auto end = chrono::steady_clock::now();
                chrono::duration<double> elapsed_seconds = end - start;
                elapsed_time += elapsed_seconds.count();
                cout << "\nYou win (" << fixed << setprecision(2) << elapsed_time << "seconds)\n";
                SaveNewScore(elapsed_time, LB, Board.dif);
                ofstream fout;
                fout.open("Save.txt");
                fout << 0;
                fout.close();
            }
            Sleep(1000);
            system("pause");
        }
    }
}