#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>
#include "../include/board.h"
#include "../include/renderer.h"

static struct option long_options[] = {
    {"width", required_argument, 0, 'w'},
    {"height", required_argument, 0, 'h'},
    {"scramble", required_argument, 0, 's'},
    {0, 0, 0, 0}};

void stop(void *data)
{
    int *running = (int *) data;
    *running = 0;
}

int main(int argc, char *argv[])
{
    int x = -1, y = -1, i, opt, col = 4, row = 4, moves = 0, running = 1, scrambleMoves = 300;
    int optIndex = 0;

    Board b;
    MLV_Image *image;

    MLV_execute_at_exit(stop, &running);

    if (argc < 2)
    {
        fprintf(stderr, "Erreur : veuillez renseigner le chemin vers l'image.\n");
        return EXIT_FAILURE;
    }

    do
    {
        optIndex = 0;
        opt = getopt_long(argc, argv, "w:h:s:", long_options, &optIndex);
        switch (opt)
        {
        case 'w':
            col = atoi(optarg);
            break;
        case 'h':
            row = atoi(optarg);
            break;
        case 's':
            scrambleMoves = atoi(optarg);
            break;
        }

    } while (opt != -1);

    if (col < 2 || row < 2)
    {
        fprintf(stderr, "Erreur : la grille doit être au minimum de 2x2.\n");
        return EXIT_FAILURE;
    }

    initBoard(&b, col, row);
    srand(time(NULL));
    scramble(&b, scrambleMoves);
    initWindow(b);

    for (i = 0; i < argc; i++)
    {
        image = MLV_load_image(argv[i]);
        if (image != NULL)
        {
            break;
        }
    }
    MLV_resize_image(image, W_CELL_SIZE(b) * col, H_CELL_SIZE(b) * row);

    do
    {
        MLV_clear_window(MLV_COLOR_BLACK);
        drawBoard(b, image);
        drawMoves(b, moves);

        if (win(b) && moves > 0)
        {
            drawVictory(b);
            MLV_update_window();
            MLV_wait_mouse(NULL, NULL);
            break;
        }

        MLV_update_window();
        MLV_wait_mouse_or_seconds(&x, &y, 1);

        if (x < 0 || y < 0)
        {
            continue;
        }

        if (swapSquare(&b, (int)((x - X(b)) / W_CELL_SIZE(b)), (int)((y - Y(b)) / H_CELL_SIZE(b))))
        {
            moves++;
        }
    } while (running);

    MLV_free_window();
    MLV_free_image(image);
    freeBoard(b);

    return EXIT_SUCCESS;
}
