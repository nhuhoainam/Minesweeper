#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#define MAX_SIZE 100

struct Grid;

void Command(Grid &Board, int &GameOver, int &ValidCells);
void InputCommand(int &Type, Grid &Board, int &x, int &y);
void Flip(Grid &Board,int x, int y, int &GameOver, int &ValidCells);
void Flag(Grid &Board, int x, int y);
void FlipAround(Grid &Board, int x, int y, int &GameOver, int &ValidCells);

#endif // COMMAND_H_INCLUDED
