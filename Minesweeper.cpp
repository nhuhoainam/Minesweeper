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

struct Grid;

void SaveNewScore(float time, Leaderboard& LB, int dif) {
    switch(dif) {
    case 1:
        LB.Easy[LB.cntEasy++] = time;
        sort(LB.Easy, LB.Easy + LB.cntEasy);
        if (LB.cntEasy == 11)
            LB.cntEasy--;
        break;
    case 2:
        LB.Medium[LB.cntMed++] = time;
        sort(LB.Medium, LB.Medium + LB.cntMed);
        if (LB.cntMed == 11)
            LB.cntMed--;
        break;
    case 3:
        LB.Hard[LB.cntHard++] = time;
        sort(LB.Hard, LB.Hard + LB.cntHard);
        if (LB.cntHard == 11)
            LB.cntHard--;
        break;
    }
    ofstream fout;
    fout.open("Leaderboard.txt");
    fout << LB.cntEasy << ' ' << LB.cntMed << ' ' << LB.cntHard << endl;
    for(int i = 0; i < LB.cntEasy; i++) {
        fout << LB.Easy[i] << endl;
    }
    for(int i = 0; i < LB.cntMed; i++) {
        fout << LB.Medium[i] << endl;
    }
    for(int i = 0; i < LB.cntHard; i++) {
        fout << LB.Hard[i] << endl;
    }
    fout.close();
}

void GamePlay()
{
    Grid Board;
    memset(Board.Board, 0, sizeof Board.Board);
    memset(Board.isMine, 0, sizeof Board.isMine);
    memset(Board.isFlag, 0, sizeof Board.isFlag);
    memset(Board.isFlip, 0, sizeof Board.isFlip);
    Init(Board);
    int GameOver = 0, ValidCells = Board.row * Board.col - Board.Mines;
    auto start = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds;
    Leaderboard LB;
    LoadLeaderboard(LB);
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
                cout << "\nYou win (" << fixed << setprecision(2) << elapsed_seconds.count() << "seconds)\n";
                SaveNewScore(elapsed_seconds.count(), LB, Board.dif);
            }
            Sleep(1000);
            system("pause");
        }
    }
}

void LoadLeaderboard(Leaderboard& LB) {
    ifstream fin;
    fin.open("Leaderboard.txt");
    fin >> LB.cntEasy >> LB.cntMed >> LB.cntHard;
    for(int i = 0; i < LB.cntEasy; i++) {
        fin >> LB.Easy[i];
    }
    for(int i = 0; i < LB.cntMed; i++) {
        fin >> LB.Medium[i];
    }
    for(int i = 0; i < LB.cntHard; i++) {
        fin >> LB.Hard[i];
    }
    fin.close();
}

void SeeLeaderboard(Leaderboard& LB) {
    LoadLeaderboard(LB);
    system("cls");
    cout << "Easy:\n";
    for(int i = 0; i < LB.cntEasy; i++) {
        cout << fixed << setprecision(2) << i+1 << ". " << LB.Easy[i] << " secs.\n";
    }
    cout << "Medium:\n";
    for(int i = 0; i < LB.cntMed; i++) {
        cout << fixed << setprecision(2) << i+1 << ". " << LB.Medium[i] << " secs.\n";
    }
    cout << "Hard:\n";
    for(int i = 0; i < LB.cntHard; i++) {
        cout << fixed << setprecision(2) << i+1 << ". " << LB.Hard[i] << " secs.\n";
    }
    system("pause");
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
            Leaderboard LB;
            system("cls");
            cout << "Welcome to Minesweeper made by MinhGiang & HoaiNam\n";
            cout << "1. Play game\n2. See Leaderboard\n3. Exit\nEnter a command:\n";
            cin >> c;
            if (c == 2) {SeeLeaderboard(LB); continue;}
            if (c == 3) {cout << "See u again!! :>"; break;}
            GamePlay(); 
        }
    return 0;
}

