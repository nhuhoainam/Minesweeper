#include "Command.h"
#include "Init.h"
#include <iostream>

using namespace std;

void Command(Grid &Board, int &GameOver, int &ValidCells)
{
    int Type, x, y;
    InputCommand(Type, Board, x, y);
    if (Type == 1) Flip(Board, x, y, GameOver, ValidCells);
    else if (Type == 2) FlipAround(Board, x, y, GameOver, ValidCells);
    else Flag(Board, x, y);
    if (Board.Mines == 0 || ValidCells == 0) GameOver = 2;
}

void InputCommand(int &Type, Grid &Board, int &x, int &y)
{
    cout << "1 x y: Open cell x, y \n2 x y: Open all cells around cell x, y \n3 x y: Flag cell x, y\n";
    cout << "Please input a command:\n";
    while (1)
    {
        cin >> Type >> x >> y;
        x--, y--;
        if (Type > 0 && Type < 4 && x > -1 && x < Board.row && y > -1 && y < Board.col) return;
        cout << "Wrong input, Try again!\n";
    }
}

void Flip(Grid &Board, int x, int y, int &GameOver, int &ValidCells)
{
    if (Board.isFlag[x][y] || Board.isFlip[x][y]) return;
    Board.isFlip[x][y] = 1;
    if (Board.isMine[x][y]) {GameOver = 1; return;}
    ValidCells--;
    if (Board.Board[x][y] == 0)
    {
        int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int k = 0; k < 8; k++)
            if (isInBoard(Board, x + ChangeX[k], y + ChangeY[k])
                    && !Board.isFlip[x + ChangeX[k]][ y + ChangeY[k]])
                        Flip(Board, x + ChangeX[k], y + ChangeY[k], GameOver, ValidCells);
    }
}

void FlipAround(Grid &Board, int x, int y, int &GameOver, int &ValidCells)
{
    Flip(Board, x, y, GameOver, ValidCells);
    int ChangeX[] = {-1, -1, -1, 0, 0, 1, 1, 1}, ChangeY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int k = 0; k < 8; k++)
        if (isInBoard(Board, x + ChangeX[k], y + ChangeY[k])
                && !Board.isFlip[x + ChangeX[k]][ y + ChangeY[k]])
                    Flip(Board, x + ChangeX[k], y + ChangeY[k], GameOver, ValidCells);
}

void Flag(Grid &Board, int x, int y)
{
    if (Board.isFlip[x][y]) return;
    if (Board.isFlag[x][y]) Board.Mines -= Board.isMine[x][y];
        else Board.Mines += Board.isMine[x][y];
    Board.isFlag[x][y] = !Board.isFlag[x][y];
}
