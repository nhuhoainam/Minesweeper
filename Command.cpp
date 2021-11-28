#include "Command.h"
#include <iostream>

using namespace std;



void Command(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver)
{
    int Type, x, y;
    InputCommand(Type, row, col, x, y);
    if (Type == 1) Flip(Board, row, col, x, y, Mines, isFlip, isMine, isFlag, GameOver);
    else if (Type == 2) FlipAround(Board, row, col, x, y, Mines, isFlip, isMine, isFlag, GameOver);
    else Flag(Board, x, y, Mines, isFlip, isMine, isFlag);
}

void InputCommand(int &Type, int &row, int &col, int &x, int &y)
{
    cout << "Please input a command:\n";
    while (1)
    {
        cin >> Type >> x >> y;
        x--, y--;
        if (x > -1 || x < row || y > -1 || y < col) return;
        cout << "Wrong input, Try again!\n";
    }
}

void Flip(int (&Board)[100][100], int &row, int &col, int x, int y, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver)
{
    if (isFlag[row][col]) return;
    isFlip[row][col] = 1;
    if (isMine[row][col]) {GameOver = 1; return;}
    if (Board[row][col] == 0)
    {
        int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int k = 0; k < 8; k++)
            if (isInBoard(row, col, x + ChangeX[k], y + ChangeY[k])
                && Board[x + ChangeX[k]][y + ChangeY[k]] == 0
                    && !isFlip[x + ChangeX[k]][ y + ChangeY[k]])
                        Flip(Board, row, col, x + ChangeX[k], y + ChangeY[k], Mines, isFlip, isMine, isFlag, GameOver);
    }
}

void FlipAround(int (&Board)[100][100], int &row, int &col, int x, int y, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver)
{
    int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++)
        if (isInBoard(row, col, x + ChangeX[k], y + ChangeY[k])
                && !isFlip[x + ChangeX[k]][ y + ChangeY[k]])
                    Flip(Board, row, col, x + ChangeX[k], y + ChangeY[k], Mines, isFlip, isMine, isFlag, GameOver);
}

void Flag(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100])
{
    if (isFlip[row][col]) return;
    if (isFlag[row][col]) Mines -= isMine[row][col];
        else Mines += isMine[row][col];
    isFlag[row][col] = !isFlag[row][col];
}

//bool isInBoard(int &row, int &col, int x, int y) {return (x < row && x > -1 && y > -1 && y < col);}
