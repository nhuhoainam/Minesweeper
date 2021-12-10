#include "Init.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <chrono>

#define MAX_SIZE 100

using namespace std;

void Init(Grid &Board)
{
    for (int i = 0; i < Board.row; i++)
        for (int j = 0; j < Board.col; j++)
            Board.Board[i][j] = Board.isFlip[i][j] = Board.isMine[i][j] = Board.isFlag[i][j] = 0;
    SetDif(Board);
    RanMines(Board);
    BoardSetup(Board);
}

void SetDif(Grid &Board)
{
    system("cls");
    cout << "Choose level: \n";
    int r[] = {8, 16, 16}, c[] = {8, 16, 30}, Ms[] = {10, 40, 99};
    string lvname[] = {"1. Beginner", "2. Intermediate", "3. Expert"};
    for (int i = 0; i < 3; i++)
        cout << lvname[i] << ": " << r[i] << " x " << c[i] << " " << Ms[i] << " Board.Mines\n";
    int level;
    cin >> level;
    level--;
    Board.row = r[level], Board.col = c[level], Board.Mines = Ms[level];
}

void RanMines(Grid &Board)
{
    vector <int> num;
    for (int i = 0; i < Board.col * Board.row; i++) num.push_back(i);
    unsigned rd = chrono::system_clock::now().time_since_epoch().count();
    shuffle(num.begin(), num.end(), default_random_engine(rd));
    for (int i = 0; i < Board.Mines; i++) Board.Board[num[i] / Board.col][num[i] % Board.col]++;
}

void BoardSetup(Grid &Board)
{
    int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < Board.row; i++)
        for (int j = 0; j < Board.col; j++)
            if (Board.isMine[i][j])
            {
                for (int k = 0; k < 8; k++)
                    if (isInBoard(Board, i + ChangeX[k], j + ChangeY[k]))
                        Board.Board[i + ChangeX[k]][j + ChangeY[k]]++;
            }

    for (int i = 0; i < Board.row; i++)
        for (int j = 0; j < Board.col; j++)
            if (Board.isMine[i][j]) Board.Board[i][j] = 9;
}

bool isInBoard(Grid &Board, int x, int y) {return (x < Board.row && x > -1 && y > -1 && y < Board.col);}
