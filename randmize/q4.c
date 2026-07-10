#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice;
    srand(time(NULL));
    dice = rand() % 3;
    if (dice < 2) {
        printf("Bye\n");
    } else {
        printf("Hello\n");
    }
}