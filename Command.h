#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

void Command(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100],
             int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver);
void InputCommand(int &Type, int &row, int &col, int &x, int &y);
void Flip(int (&Board)[100][100], int &row, int &col, int x, int y, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver);
void Flag(int (&Board)[100][100], int &row, int &col, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100]);
void FlipAround(int (&Board)[100][100], int &row, int &col, int x, int y, int &Mines, bool (&isFlip)[100][100],
                  int (&isMine)[100][100], int (&isFlag)[100][100], int &GameOver);
bool isInBoard(int &row, int &col, int x, int y);

#endif // COMMAND_H_INCLUDED
