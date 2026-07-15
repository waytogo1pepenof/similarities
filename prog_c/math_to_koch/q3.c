#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        printf("%.1lf\t%.1lf\n", x[i], y[i]);
    }

    int n;
    double alpha_x, alpha_y;
    for (int i = 0; i < 5; i++) {
        n = i % 4;
        alpha_x = x[n] * cos(0.1) - y[n] * sin(0.1);
        alpha_y = x[n] * sin(0.1) + y[n] * cos(0.1);
        fprintf(fp, "%lf\t%lf\n", alpha_x, alpha_y);
    }
    
    fclose(fp);
    return 0;
}