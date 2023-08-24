# The N Queens Problem:

## Table of Contents:

- [What is the N Queens Problem?](#what-is-the-n-queens-problem?)
- [Existence](#existence)
- [About the implementation](#about-the-implementation)
- [Author](#author)
- [Contributing](#contributing)
- [Show your support](#show-your-support)

## [What is the N Queens Problem?](https://en.wikipedia.org/wiki/Eight_queens_puzzle)

The N Queens Problem is the problem of placing N chess queens on an N×N chessboard so that no two queens threaten each other. A solution requires that no two queens share the same row, column, or diagonal.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1f/Eight-queens-animation.gif/220px-Eight-queens-animation.gif" alt="Eight Queens Problem" />
</p>

The original problem was first posed in the mid-19th century and required placing only 8 non-attacking queens on an 8×8 chessboard. It has exactly 92 distinct solutions.

The problem was discussed in detail on the [Numberphile](https://youtu.be/jPcBU0Z2Hj8?si=hYurs9K3ZyR5jUYI) YouTube channel.

## Existence:

Solutions to the N Queens Problem exist for all natural numbers n with the exception of n = 2 and n = 3.

## About the implementation:

In order to solve the N Queens Problem a **backtracing algorithm** was chosen. 

`bool solveNQueenProblem(const int size)` function is responsible for finding a solution where `size` parameter indicates the dimensions of the chessboard.
When `solveNQueenProblem` finds a solution, it displays a message: "`Soution found.`" and prints the chessboard to the standard output. Otherwise it displays: "`Solution not found`".

The main idea of the algorithm is to place queens one by one in different columns, starting from the leftmost column and check for clashes with already placed queens. 

`bool isValidPositionForQueen(const Position p, Chessboard *board)` is responsible for deciding whether a queen can be placed in a position `p` or not. 
The idea of filling the chessboard column by column allows the `isValidPositionForQueen` function to check only columns to the left of the currently processed column.

`bool solveNQueenProblem(const int size)` use a self-implemented square array `Chessboard` (with **dynamic memory allocation**) to represent the chessboard.

```cpp
typedef struct Chessboard
{
    int size;
    char **fields;
} Chessboard;

typedef struct Position
{
    int row, col;
} Position;
```

Such structure allows to solve the N Queens Problem for different dimensions of the chessboard.

Helper functions of the `Chessboard` structure include:

|Function:|Explanation:|
|---|---|
|`bool initChessboard(Chessboard *board, const int size)`|Allocates memory for the `board` insance of `Chessboard`. If failure occurs, it sets `board->fields` to `NULL` and returns `false`.|
|`void freeChessboard(Chessboard *board)`|Dealocates memory alocated for the `board` object. It successfully prevents from any memory leaks.|
|`void emptyChessboard(Chessboard *board)`|Sets all fields of the `board` to `EMPTY`.|
|`void printChessboard(Chessboard *board)`|Displays the contents of the `board` to the standard output.|

To make the usage of the programme more entertaining the `solveNQueenProblem` function supports an **animaton**, which can be disabled by setting `INTERACTIVE_PRINT`
to `0` in `KnightsTourProblem.h` header file.

An exemplary solution of the the N Queens Problem generated by the programme is shown in the picture below (for N = 25).

<p align="center">
  <img src="https://github.com/adamgracikowski/NQueensProblem/blob/main/NQueensProblem.png" alt="NQueensProblem.png" />
</p>

## Author:

My GitHub: [@adamgracikowski](https://github.com/adamgracikowski)

## Contributing:

All contributions, issues, and feature requests are welcome! 🤝

## Show your support:

Give a ⭐️ if you like this project and its documentation!
