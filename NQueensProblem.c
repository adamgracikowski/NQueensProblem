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

bool isValidPositionForQueen(const Position p, Chessboard *board)
{
    return (!isQueenInRow(p, board) &&
            !isQueenInLowerDiagonal(p, board) &&
            !isQueenInUpperDiagonal(p, board));
}

bool isQueenInRow(const Position p, Chessboard *board)
{
    for (int i = 0; i < p.col; ++i)
    {
        if (board->fields[p.row][i] == QUEEN)
            return true;
    }
    return false;
}

bool isQueenInLowerDiagonal(const Position p, Chessboard *board)
{
    for (int row = p.row, col = p.col; col >= 0 && row < board->size; row++, col--)
        if (board->fields[row][col] == QUEEN)
            return true;
    return false;
}

bool isQueenInUpperDiagonal(const Position p, Chessboard *board)
{
    for (int row = p.row, col = p.col; row >= 0 && col >= 0; row--, col--)
        if (board->fields[row][col] == QUEEN)
            return true;
    return false;
}

bool solveNQueenProblem(const int size)
{
    assert(size > 0);

    Chessboard board;
    if (!initChessboard(&board, size))
    {
        perror("Not enough memory.\n");
        return false;
    }

    bool result;
    Position start = {rand() % size, 0};
    for (int i = 0; i < size; ++i)
    {
        board.fields[(start.row + i) % size][0] = QUEEN;
        if ((result = backtracing(1, &board)))
        {
            ANIMATION(, ANIMATION_DELAY);
            printChessboard(&board);
            printf("Solution found.\n");
            freeChessboard(&board);
            return true;
        }
        else
            board.fields[(start.row + i) % size][0] = EMPTY;
    }

    printf("Solution not found.\n");
    freeChessboard(&board);
    return false;
}

bool backtracing(const int column, Chessboard *board)
{
    ANIMATION(printChessboard(board), ANIMATION_DELAY);
    int size = board->size;
    if (column == size)
        return true;

    for (int i = 0; i < size; ++i)
    {
        if (isValidPositionForQueen((Position){i, column}, board))
        {
            board->fields[i][column] = QUEEN;
            if (backtracing(column + 1, board))
                return true;
            board->fields[i][column] = EMPTY;
        }
    }
    return false;
}