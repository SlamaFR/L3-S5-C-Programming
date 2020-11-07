#include <MLV/MLV_all.h>
#include "../include/renderer.h"
#include "../include/board.h"

void initWindow(Board b)
{
    MLV_create_window_with_default_font("Jeu de Taquin", NULL, WIDTH, HEIGHT, "src/din.ttf", Y(b) / 2);
}

void drawBoard(Board b, MLV_Image *image)
{
    int i, j, x, y, x_image, y_image;
    Square square;

    const int boardWidth = CELL_MARGIN + b.col * (W_CELL_SIZE(b) + CELL_MARGIN);
    const int boardHeight = CELL_MARGIN + b.row * (H_CELL_SIZE(b) + CELL_MARGIN);
    MLV_draw_filled_rectangle(X(b) - CELL_MARGIN, Y(b) - CELL_MARGIN, boardWidth, boardHeight, MLV_COLOR_GRAY10);

    for (i = 0; i < b.col; i++)
    {
        for (j = 0; j < b.row; j++)
        {
            square = b.blocks[i][j];

            x = X(b) + i * (W_CELL_SIZE(b) + CELL_MARGIN);
            y = Y(b) + j * (H_CELL_SIZE(b) + CELL_MARGIN);

            if (square.col == b.col - 1 && square.row == b.row - 1)
            {
                MLV_draw_filled_rectangle(x, y, W_CELL_SIZE(b), H_CELL_SIZE(b), MLV_COLOR_GRAY5);
            }
            else
            {
                x_image = square.col * W_CELL_SIZE(b);
                y_image = square.row * H_CELL_SIZE(b);

                MLV_draw_partial_image(image, x_image, y_image, W_CELL_SIZE(b), H_CELL_SIZE(b), x, y);
            }
        }
    }
}

void drawMoves(Board b, int moves)
{
    char s[24];
    sprintf(s, "Coups : %d", moves);
    MLV_draw_text_box(0, 1 * Y(b) / 4, WIDTH, Y(b) / 2, s, 0,
                      MLV_COLOR_BLACK, MLV_COLOR_WHITE, MLV_COLOR_BLACK, 
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}

void drawVictory(Board b)
{
    MLV_draw_text_box(0, HEIGHT - 3 * Y(b) / 4, WIDTH, Y(b) / 2, "Victoire !", 0,
                      MLV_COLOR_BLACK, MLV_COLOR_GREEN, MLV_COLOR_BLACK, 
                      MLV_TEXT_CENTER, MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER);
}
