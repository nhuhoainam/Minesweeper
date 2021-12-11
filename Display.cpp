#include "Display.h"
#include "consoletext.h"
#include "Init.h"
#include <iostream>
#include <iomanip>

using namespace std;

void DisplayBoard(Grid &Board)
{
    system("cls");
    SetBGColor(12);
    for (int i = 0; i <= Board.col; i++) {
        cout.width(3), cout << left << i;
    }
    cout.width(3); cout << "y"; cout << '\n';
    for (int i = 0; i < Board.row; i++)
        {
            SetBGColor(12);
            cout.width(3);
            cout << left << i + 1;
            SetBGColor(1);
            for (int j = 0; j < Board.col; j++)
                if (Board.isFlag[i][j]) cout.width(3), cout << left << "F";
                    else
                    {
                        if (!Board.isFlip[i][j]) cout.width(3), cout << left << "U";
                        else
                        {
                            cout.width(3);
                            if (Board.isMine[i][j]) cout << left << "B";
                            else cout << left << Board.Board[i][j];
                        }
                    }
            cout << '\n';
        }
    SetBGColor(12);
    cout.width(3), cout << left << 'x' << '\n';
    SetBGColor(0);
}
