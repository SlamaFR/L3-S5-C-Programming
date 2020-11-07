#ifndef __BOARD_H
#define __BOARD_H

typedef struct
{
    int row;
    int col;
}
Square;

typedef struct
{
    int row;
    int col;
    Square **blocks;
}
Board;

/**
 * @brief Create a board and fills every Square with appropriate coordinates.
 * 
 * @param b Board pointer.
 * @param row Number of rows.
 * @param col Nomber of columns.
 */
int initBoard(Board *b, int row, int col);

/**
 * @brief Scramble the board by making random moves.
 * 
 * @param b Board.
 * @param moves Amount of moves to make.
 */
void scramble(Board *b, int moves);

/**
 * @brief Swap a Square with the blank Square if this one is around.
 * 
 * @param b Board pointer.
 * @param col column index.
 * @param row row index.
 * @return whether the swap succeeded.
 */
int swapSquare(Board *b, int col, int row);

/**
 * @brief Get a Square from the board
 * 
 * @param b Board pointer.
 * @param col column index.
 * @param row row index. 
 * @param square Square pointer to store result.
 */
void getSquare(Board *b, int col, int row, Square **square);

/**
 * @param b Board.
 * @return int whether the board is solved.
 */
int win(Board b);

/**
 * @brief Free the allocated board
 * 
 * @param b Board. 
 */
void freeBoard(Board b);

#endif /* __BOARD_H */
