#include <stdio.h>
#include <string.h>

void printAlbert() {
    printf("        \\              -''--.\n");
    printf("         \\            _`>   `\\.-'<\n");
    printf("          \\        _.'     _     '._\n");
    printf("           \\     .'   _.='   '=._   '.\n");
    printf("            \\    >_   / /_\\ /_\\ \\   _<\n");
    printf("                   / (  \\o/\\\\o/  ) \\\n");
    printf("                   >._\\ .-,_)-. /_.<\n");
    printf("                       /__/ \\__\\\n");
    printf("                         '---'\n");
}

void printBubbleUpper(unsigned int size) {
    int i;
    printf("/");
    for (i = 0; i < size + 2; i++) {
        printf("‾");
    }
    printf("\\\n");
}

void printBubbleLower(unsigned int size) {
    int i;
    printf("\\");
    for (i = 0; i < size + 2; i++) {
        printf("_");
    }
    printf("/\n");
}

int main(int ac, char **av) {
    if (ac < 2) return 1;

    unsigned int length = strlen(av[1]);

    printBubbleUpper(length);
    printf("| ");
    printf("%s", av[1]);
    printf(" |\n");
    printBubbleLower(length);
    printAlbert();
    return 0;
}
