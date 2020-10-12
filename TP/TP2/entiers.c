#include <math.h>
#include <stdio.h>

int main(void) {
    int i, x, y, z;

    for (i = 0; i <= 500; i++) {

        x = i / 100;
        y = (i - x * 100) / 10;
        z = (i - x * 100 - y * 10);

        if (pow(x, 3) + pow(y, 3) + pow(z, 3) == i) {
            printf("%d ", i);
        }
    }
    printf("\n");
    return 0;
}
