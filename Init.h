#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

void Init(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100], int (&isMine)[100][100], int (&isFlag)[100][100]);
void SetDif(int &row, int &col, int &Mines);
void RanMines(int (&Board)[100][100], int &row, int &col, int &Mines);
//void Display(int (&Board)[100][100], int &row, int &col);
void BoardSetup(int (&Board)[100][100], int &row, int &col, int (&isMine)[100][100]);
bool isInBoard(int &row, int &col, int x, int y);

#endif // INIT_H_INCLUDED
