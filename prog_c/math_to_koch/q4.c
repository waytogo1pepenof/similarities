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

    double deg;
    int n;
    double alpha_x, alpha_y;
    for (int i = 0; i < 10; i++) {
        deg = i / 10.0;
        for (int j = 0; j < 5; j++) {
            n = j % 4;
            alpha_x = x[n] * cos(deg) - y[n] * sin(deg);
            alpha_y = x[n] * sin(deg) + y[n] * cos(deg);
            fprintf(fp, "%lf\t%lf\n", alpha_x, alpha_y);
        }
        fprintf(fp, "\n");
    }
    
    fclose(fp);
    return 0;
}