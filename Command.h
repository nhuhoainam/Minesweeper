#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED
#include <chrono>

#define MAX_SIZE 100

struct Grid;

bool Command(Grid &Board, int &GameOver, int &ValidCells, std::chrono::steady_clock::time_point& start);
void InputCommand(int &Type, Grid &Board, int &x, int &y);
void Flip(Grid &Board,int x, int y, int &GameOver, int &ValidCells);
void Flag(Grid &Board, int x, int y);
void FlipAround(Grid &Board, int x, int y, int &GameOver, int &ValidCells);
void FlipAllMines(Grid &Board);

#endif // COMMAND_H_INCLUDED
