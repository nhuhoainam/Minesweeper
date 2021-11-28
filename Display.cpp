#include "Display.h"
#include <iostream>

using namespace std;

void DisplayBoard(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100], int (&isMine)[100][100], int (&isFlag)[100][100])
{
    system("cls");
    for (int i = 0; i <= col; i++) cout << i << " ";
    cout << "y\n";
    for (int i = 0; i < row; i++)
        {
            cout << i + 1 << " ";
            for (int j = 0; j < col; j++)
                if (isFlag[i][j]) cout << "F "; //cout.width(3);
                    else
                    {
                        if (!isFlip[i][j]) cout << "U "; //cout.width(3);
                        else
                        {
                            if (isMine[i][j]) cout << "B "; //cout.width(3);
                            else cout << Board[i][j] << " "; //cout.width(3);
                        }
                    }
            cout << '\n';
        }
    cout << "x\n";
}
