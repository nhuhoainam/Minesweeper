#include "Init.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

void Init(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100], int (&isMine)[100][100], int (&isFlag)[100][100])
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            Board[i][j] = isFlip[i][j] = isMine[i][j] = isFlag[i][j] = 0;
    SetDif(row, col, Mines);
    RanMines(isMine, row, col, Mines);
    BoardSetup(Board, row, col, isMine);
}

void SetDif(int &row, int &col, int &Mines)
{
    system("cls");
    cout << "Choose level: \n";
    int r[] = {8, 16, 16}, c[] = {8, 16, 30}, Ms[] = {10, 40, 99};
    string lvname[] = {"1. Beginner", "2. Intermediate", "3. Expert"};
    for (int i = 0; i < 3; i++)
        cout << lvname[i] << ": " << r[i] << " x " << c[i] << " " << Ms[i] << " Mines\n";
    int level;
    cin >> level;
    level--;
    row = r[level], col = c[level], Mines = Ms[level];
}

void RanMines(int (&Board)[100][100], int &row, int &col, int &Mines)
{
    vector <int> num;
    for (int i = 0; i < col * row; i++) num.push_back(i);
    unsigned rd = chrono::system_clock::now().time_since_epoch().count();
    shuffle(num.begin(), num.end(), default_random_engine(rd));
    for (int i = 0; i < Mines; i++) Board[num[i] / col][num[i] % col]++;
}

void BoardSetup(int (&Board)[100][100], int &row, int &col, int (&isMine)[100][100])
{
    int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (isMine[i][j])
            {
                for (int k = 0; k < 8; k++)
                    if (isInBoard(row, col, i + ChangeX[k], j + ChangeY[k]))
                        Board[i + ChangeX[k]][j + ChangeY[k]]++;
            }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (isMine[i][j]) Board[i][j] = 9;
}

bool isInBoard(int &row, int &col, int x, int y) {return (x < row && x > -1 && y > -1 && y < col);}
