#include "NQueensProblem.h"

bool initChessboard(Chessboard *board, const int size)
{
    if (board)
    {
        board->size = size;
        board->fields = malloc(board->size * sizeof(char *));
        if (!board->fields)
        {
            board->size = 0;
            return false;
        }
        for (int i = 0; i < board->size; ++i)
        {
            board->fields[i] = malloc(board->size * sizeof(char));
            if (!board->fields[i])
            {
                for (int j = 0; j < i; ++j)
                {
                    free(board->fields[j]);
                }
                free(board->fields);
                board->size = 0;
                board->fields = NULL;
                return false;
            }
        }
        emptyChessboard(board);
        return true;
    }
    return false;
}

void emptyChessboard(Chessboard *board)
{
    if (board)
    {
        for (int i = 0; i < board->size; ++i)
        {
            for (int j = 0; j < board->size; ++j)
            {
                board->fields[i][j] = EMPTY;
            }
        }
    }
}

void freeChessboard(Chessboard *board)
{
    if (board)
    {
        for (int i = 0; i < board->size; ++i)
        {
            if (board->fields[i])
                free(board->fields[i]);
        }
        free(board->fields);
    }
}

void printChessboard(Chessboard *board)
{
    for (int i = 0; i < board->size; ++i)
    {
        for (int j = 0; j < board->size; ++j)
        {
            printf("[%c]", board->fields[i][j]);
        }
        printf("\n");
    }
}