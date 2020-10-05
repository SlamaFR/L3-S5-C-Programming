#include <stdio.h>

int main(int ac, char **av) {
    FILE *file;
    int c;

    if (ac < 2) return 1;

    file = fopen(av[1], "w+");
    if (file == NULL) return 1;

    while ((c = getchar()) != EOF) {
        fputc(c, stdout);
        fputc(c, file);
    }

    fclose(file);
    return 0;
}