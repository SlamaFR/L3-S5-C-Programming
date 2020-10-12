#include <stdio.h>
#include <string.h>

void reverse(char *string, int size) {
    int i;
    char tmp;
    for (i = 0; i < size / 2; i++) {
        tmp = string[i];
        string[i] = string[size - i - 1];
        string[size - i - 1] = tmp;
    }
}

int main(int ac, char **av) {
    int i;

    for (i = 1; i < ac; i++) {
        reverse(av[i], strlen(av[i]));
        printf("%s\n", av[i]);
    }
    return 0;
}
