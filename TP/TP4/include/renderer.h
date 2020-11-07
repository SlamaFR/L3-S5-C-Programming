#ifndef __RENDERER_H
#define __RENDERER_H

#include <MLV/MLV_all.h>
#include "board.h"

#define WIDTH (MLV_get_desktop_height() * .8)
#define HEIGHT WIDTH

#define MINIMUM_MARGIN (MLV_get_desktop_height() * .1)

#define H_CELL_SIZE(b) ((HEIGHT - 2 * MINIMUM_MARGIN) / b.row)
#define W_CELL_SIZE(b) ((WIDTH - 2 * MINIMUM_MARGIN) / b.col)
#define CELL_MARGIN ((WIDTH / HEIGHT) * 3)

#define X(b) ((WIDTH - b.col * W_CELL_SIZE(b) - (b.col - 1) * CELL_MARGIN) / 2)
#define Y(b) ((HEIGHT - b.row * H_CELL_SIZE(b) - (b.row - 1) * CELL_MARGIN) / 2)

/**
 * @brief Create window.
 * 
 * @param b Board.
 */
void initWindow(Board b);

/**
 * @brief Draw the board on the window.
 * 
 * @param b Board.
 * @param image Image of the puzzle.
 */
void drawBoard(Board b, MLV_Image *image);

/**
 * @brief Draw the moves counter.
 * 
 * @param b Board.
 * @param moves Moves count.
 */
void drawMoves(Board b, int moves);

/**
 * @brief Draw the victory label.
 * 
 * @param b Board.
 */
void drawVictory(Board b);

#endif /* __RENDERER_H */
