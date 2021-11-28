#include "Command.h"
#include <iostream>

using namespace std;



void Command(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver, int &ValidCells)
{
    int Type, x, y;
    InputCommand(Type, row, col, x, y);
    if (Type == 1) Flip(Board, row, col, x, y, Mines, isFlip, isMine, isFlag, GameOver, ValidCells);
    else if (Type == 2) FlipAround(Board, row, col, x, y, Mines, isFlip, isMine, isFlag, GameOver, ValidCells);
    else Flag(Board, x, y, Mines, isFlip, isMine, isFlag);
    if (Mines == 0 || ValidCells == 0) GameOver = 2;
}

void InputCommand(int &Type, int &row, int &col, int &x, int &y)
{
    cout << "1 x y: Open cell x, y \n2 x y: Open all cells around cell x, y \n3 x y: Flag cell x, y\n";
    cout << "Please input a command:\n";
    while (1)
    {
        cin >> Type >> x >> y;
        x--, y--;
        if (Type > 0 && Type < 4 && x > -1 && x < row && y > -1 && y < col) return;
        cout << "Wrong input, Try again!\n";
    }
}

void Flip(int (&Board)[100][100], int &row, int &col, int x, int y, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver, int &ValidCells)
{
    if (isFlag[x][y] || isFlip[x][y]) return;
    isFlip[x][y] = 1;
    if (isMine[x][y]) {GameOver = 1; return;}
    ValidCells--;
    if (Board[x][y] == 0)
    {
        int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int k = 0; k < 8; k++)
            if (isInBoard(row, col, x + ChangeX[k], y + ChangeY[k])
                    && !isFlip[x + ChangeX[k]][ y + ChangeY[k]])
                        Flip(Board, row, col, x + ChangeX[k], y + ChangeY[k], Mines, isFlip, isMine, isFlag, GameOver, ValidCells);
    }
}

void FlipAround(int (&Board)[100][100], int &row, int &col, int x, int y, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver, int &ValidCells)
{
    Flip(Board, row, col, x, y, Mines, isFlip, isMine, isFlag, GameOver, ValidCells);
    int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++)
        if (isInBoard(row, col, x + ChangeX[k], y + ChangeY[k])
                && !isFlip[x + ChangeX[k]][ y + ChangeY[k]])
                    Flip(Board, row, col, x + ChangeX[k], y + ChangeY[k], Mines, isFlip, isMine, isFlag, GameOver, ValidCells);
}

void Flag(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100])
{
    if (isFlip[row][col]) return;
    if (isFlag[row][col]) Mines -= isMine[row][col];
        else Mines += isMine[row][col];
    isFlag[row][col] = !isFlag[row][col];
}
