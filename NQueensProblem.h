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

typedef struct Chessboard
{
    int size;
    char **fields;
} Chessboard;

typedef struct Position
{
    int row, col;
} Position;

bool initChessboard(Chessboard *board, const int size);
void emptyChessboard(Chessboard *board);
void freeChessboard(Chessboard *board);
void printChessboard(Chessboard *board);

#endif // NQUEENSPROBLEM_H