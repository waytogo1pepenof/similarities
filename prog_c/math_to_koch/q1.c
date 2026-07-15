#include <stdio.h>
#include <stdlib.h>

int main() {
    double x[4], y[4];

    FILE *fp;
    fp = fopen("a.txt", "wt");
    if (!fp) {
        perror("Cannot open this file.");
        exit(1);
    }

    for (int i = 0; i <= 3; i++) {
        x[i] = (i ^ (i >> 1)) & 1;
        y[i] = (i >> 1) & 1;
        fprintf(fp, "%.1lf\t%.1lf\n", x[i], y[i]);
    }
    
    fclose(fp);
    return 0;
}