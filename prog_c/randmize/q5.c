#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gen(int kotai) {
    int p;
    int gold = 0;
    srand(time(NULL));
    for (int i = 0; i < kotai; i++) {
        p = rand() % 10;
        if (p == 0) {
            gen(2);
        } else {
            gold++;
        }
    }
    return gold;
}

int main() {
    int total = 0;

    for (int i = 0; i < 100; i++) {
        total = total + gen(100);
    }
    printf("average: %d", total / 100);

    return 0;
}