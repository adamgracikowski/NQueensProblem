#ifndef NQUEENSPROBLEM_H
#define NQUEENSPROBLEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
#include <assert.h>

#define CLASSIC_SIZE 8
#define QUEEN 'Q'
#define EMPTY ' ' // space

//-------------------------------------------

#define INTERACTIVE_PRINT 1
// #define INTERACTIVE_PRINT 0 // uncomment this line and comment the line above to disable the animation
#define ANIMATION_DELAY 500
#define ANIMATION(instruction, delay) \
    if (INTERACTIVE_PRINT)            \
    {                                 \
        Sleep(delay);                 \
        if (system("cls"))            \
            system("clear");          \
        instruction;                  \
    }

//-------------------------------------------
typedef struct Chessboard
{
    int size;
    char **fields;
} Chessboard;

typedef struct Position
{
    int row, col;
} Position;

//-------------------------------------------

bool initChessboard(Chessboard *board, const int size);
void emptyChessboard(Chessboard *board);
void freeChessboard(Chessboard *board);
void printChessboard(Chessboard *board);

bool isValidPositionForQueen(const Position p, const Chessboard *board);
bool isQueenInRow(const Position p, const Chessboard *board);
bool isQueenInLowerDiagonal(const Position p, const Chessboard *board);
bool isQueenInUpperDiagonal(const Position p, const Chessboard *board);
bool solveNQueenProblem(const int size);
bool backtracing(const int column, Chessboard *board);

//-------------------------------------------

#endif // NQUEENSPROBLEM_H