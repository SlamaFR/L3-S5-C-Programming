#include <stdio.h>
#include <stdlib.h>

/*
 * Pour calculer "nCk" il faut "2 * nCk - 1" calculs.
 */
int b(int n, int p) {
    if (p > n) return -1;
    if (p == 0 || n == p) return 1;
    return b(n - 1, p) + b(n - 1, p - 1);
}

unsigned long b2(int n, int p) {
    if (p > n) return -1;
    if (p == 0 || n == p) return 1;

    int i, j;
    unsigned long *tab = malloc((n + 1) * sizeof(unsigned long)), val;

    if (tab == NULL) {
        return -1;
    }

    for (i = 0; i <= n; i++) {
        tab[i] = 1;
        for (j = i - 1; j > 0; j--) {
            tab[j] = tab[j] + tab[j - 1];
        }
    }

    val = tab[p];
    free(tab);
    return val;
}

int main(int ac, char **av) {
    unsigned long res;

    if (ac < 4) {
        fprintf(stderr, "Usage : %s [1|2] k n\n", av[0]);
        return 1;
    }

    int n = atoi(av[3]), p = atoi(av[2]);

    switch (atoi(av[1])) {
        case 1:
            printf("Computing %d choose %d with method 1...\n", n, p);
            res = b(n, p);
            break;
        case 2:
            printf("Computing %d choose %d with method 2...\n", n, p);
            res = b2(n, p);
            break;
        default:
            return 0;
    }

    if (res < 0) return 1;

    printf("%ld\n", res);
    return 0;
}