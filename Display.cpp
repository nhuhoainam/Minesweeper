#include "Display.h"
#include "consoletext.h"
#include <iostream>
#include <iomanip>

using namespace std;

void DisplayBoard(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100], int (&isMine)[100][100], int (&isFlag)[100][100])
{
    system("cls");
    SetBGColor(12);
    for (int i = 0; i <= col; i++) { 
        cout.width(3), cout << left << i;
    }
    cout.width(3), cout << "y" << endl;
    for (int i = 0; i < row; i++)
        {
            SetBGColor(12);
            cout.width(3);
            cout << left << i + 1;
            SetBGColor(1);
            for (int j = 0; j < col; j++)
                if (isFlag[i][j]) cout.width(3), cout << left << "F";
                    else
                    {
                        if (!isFlip[i][j]) cout.width(3), cout << left << "U";
                        else
                        {
                            cout.width(3);
                            if (isMine[i][j]) cout << left << "B";
                            else cout << left << Board[i][j];
                        }
                    }
            cout << endl;
        }
    SetBGColor(12);
    cout.width(3), cout << left << 'x' << endl;
    SetBGColor(0);
}
