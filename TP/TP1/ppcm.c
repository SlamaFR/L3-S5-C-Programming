#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int ppcm(int a, int b) {
    return (int) fabs((double) (a * b)) / gcd(a, b);
}

int ppcm_recursive(int *tab, int size) {
    if (size < 2) return 1;
    if (size == 2) return ppcm(tab[0], tab[1]);
    return ppcm(tab[0], ppcm_recursive(tab + 1, size - 1));
}

int main(int ac, char **av) {
    int numbers[ac - 1], i;

    if (ac < 2) return 1;

    for (i = 1; i < ac; i++) {
        if (atoi(av[i]) == 0) {
            numbers[i - 1] = 1;
        } else {
            numbers[i - 1] = atoi(av[i]);
        }
    }

    printf("%d\n", ppcm_recursive(numbers, ac - 1));
    return 0;
}
