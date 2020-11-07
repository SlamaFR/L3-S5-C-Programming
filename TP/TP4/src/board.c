#include <stdlib.h>
#include <stdio.h>
#include "../include/board.h"

int isBlank(Board b, Square square)
{
    return square.col == b.col - 1 && square.row == b.row - 1;
}

void getSquare(Board *b, int col, int row, Square **square)
{
    if (square && col >= 0 && col < b->col && row >= 0 && row < b->row)
    {
        *square = &(b->blocks[col][row]);
    }
}

void findBlankSquareAround(Board *b, int col, int row, Square **square)
{
    getSquare(b, col - 1, row, square);
    if (*square && isBlank(*b, **square))
    {
        return;
    }
    getSquare(b, col + 1, row, square);
    if (*square && isBlank(*b, **square))
    {
        return;
    }
    getSquare(b, col, row - 1, square);
    if (*square && isBlank(*b, **square))
    {
        return;
    }
    getSquare(b, col, row + 1, square);
    if (*square && isBlank(*b, **square))
    {
        return;
    }
}

int initBoard(Board *b, int col, int row)
{
    int i, j;

    b->col = col;
    b->row = row;

    if ((b->blocks = calloc(b->col, sizeof(Square*))) == NULL)
    {
        return 0;
    }
    for (i = 0; i < b->col; i++)
    {
        if(((b->blocks)[i] = calloc(b->row, sizeof(Square))) == NULL)
        {
            return 0;
        }
    }

    for (i = 0; i < b->col; i++)
    {
        for (j = 0; j < b->row; j++)
        {
            ((b->blocks)[i][j]).col = i;
            ((b->blocks)[i][j]).row = j;
        }
    }
    return 1;
}

void freeBoard(Board b)
{
    int i;
    for (i = 0; i < b.col; i++)
    {
        free(b.blocks[i]);
    }
    free(b.blocks);
}

void swapSquares(Square *s1, Square *s2)
{
    Square tmp = *s1;
    *s1 = *s2;
    *s2 = tmp;
}

int swapSquare(Board *b, int col, int row)
{
    Square *square = NULL, *blank = NULL;

    getSquare(b, col, row, &square);
    findBlankSquareAround(b, col, row, &blank);

    if (square == NULL)
    {
        return 0;
    }
    if (blank == NULL || !isBlank(*b, *blank))
    {
        return 0;
    }

    swapSquares(square, blank);
    return 1;
}

int win(Board b)
{
    int i, j;

    for (i = 0; i < b.col; i++)
    {
        for (j = 0; j < b.row; j++)
        {
            if (b.blocks[i][j].col != i || b.blocks[i][j].row != j)
            {
                return 0;
            }
        }
    }

    return 1;
}

void scramble(Board *b, int moves)
{
    int col = b->col - 1, row = b->row - 1, i, r;

    for (i = 0; i < moves; i++)
    {
        r = rand() % 4;
        switch (r)
        {
        case 0:
            if (swapSquare(b, col - 1, row))
            {
                col--;
            }
            break;
        case 1:
            if (swapSquare(b, col + 1, row))
            {
                col++;
            }
            break;
        case 2:
            if (swapSquare(b, col, row - 1))
            {
                row--;
            }
            break;
        case 3:
            if (swapSquare(b, col, row + 1))
            {
                row++;
            }
            break;
        }
    }
}
