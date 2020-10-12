#include <printf.h>

/*
 * Avec float, la valeur stagne à partir du 2097153e terme.
 *
 * Avec double, le temps de calcul avant que la valeur stagne est trop
 * long, j'ai terminé le programme après 10 minutes, sans résultat.
 * On peut donc penser que la valeur stagne à partir d'un terme extrêmement
 * élevé.
 */

int main(void) {
    double un = 0, old = -1;
    unsigned long i = 1;

    while (old != un) {
        old = un;
        un += ((double) 1 / (double) i);
        i++;
    }

    printf("%ld : %f\n", i, un);
    return 0;
}
