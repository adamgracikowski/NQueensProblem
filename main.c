#include "NQueensProblem.c"

int main(void)
{
    srand((unsigned)time(NULL));

    const char *sizeMsg = "Enter size of the chessboard: ",
               *errorMsg = "Invalid input.";
    int size;

    printf(sizeMsg);
    if (scanf("%d", &size) != 1)
    {
        printf(errorMsg);
        return -1;
    }
    solveNQueenProblem(size);
    system("pause");
    return 0;
}