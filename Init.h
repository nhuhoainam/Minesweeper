#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#define MAX_SIZE 100

struct Grid {
    int Board[MAX_SIZE][MAX_SIZE], isMine[MAX_SIZE][MAX_SIZE], row = 0, col = 0, Mines = 0, 
        isFlag[MAX_SIZE][MAX_SIZE];
    bool isFlip[MAX_SIZE][MAX_SIZE];
};

void Init(Grid& Board);
void SetDif(Grid (&Board));
void RanMines(Grid (&Board));
//void Display(Grid (&Board));
void BoardSetup(Grid (&Board));
bool isInBoard(Grid (&Board), int x, int y);

#endif // INIT_H_INCLUDED
