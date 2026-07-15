#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float x, y;

    FILE *fp;
    fp = fopen("a.txt", "wt");
    if (!fp) {
        perror("Cannot open this file.");
        exit(1);
    }

    for (int i = 0; i < 100; i++) {
        x = i / 10.0;
        y = sin(x);
        fprintf(fp, "%lf\t%lf\n", x, y);
    }

    fclose(fp);
    return 0;
}