#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>

int koch (double x0, double y0, double x1, double y1, int n, FILE *fp) {
    double fin_x[5], fin_y[5];
    double whole_len_x, whole_len_y;

    double cos_sixty = 1.0 / 2.0;
    double sin_sixty = sqrt(3.0) / 2.0;

    whole_len_x = x1 - x0;
    whole_len_y = y1 - y0;

    fin_x[0] = x0;
    fin_x[1] = x0 + whole_len_x / 3.0;
    fin_x[3] = x0 + whole_len_x * 2.0/3.0;
    fin_x[4] = x1;

    fin_y[0] = y0;
    fin_y[1] = y0 + whole_len_y / 3.0;
    fin_y[3] = y0 + whole_len_y * 2.0/3.0;
    fin_y[4] = y1;

    fin_x[2] = fin_x[1] + ((fin_x[3] - fin_x[1]) * cos_sixty - (fin_y[3] - fin_y[1]) * sin_sixty);
    fin_y[2] = fin_y[1] + ((fin_y[3] - fin_y[1]) * cos_sixty + (fin_x[3] - fin_x[1]) * sin_sixty);

    if (n < 0) {
        printf("[invalid: please input n > 0]");
        return 0;
    }

    if (n == 0) {
        fprintf(fp, "%lf\t%lf\n", x0, y0);
        return 0;
    } else {
        for (int i = 0; i < 4; i++) {
            koch(fin_x[i], fin_y[i], fin_x[i+1], fin_y[i+1], n - 1, fp);
        }
    }

    return 0;
}

int main() {

    FILE *fp;
    fp = fopen("a.txt", "wt");
    if (!fp) {
        perror("Cannot open this file.");
        exit(1);
    }

    int depth = 5;

    koch(0.0, 0.0, 300.0, 0.0, depth, fp);
    fprintf(fp, "%lf\t%lf\n", 300.0, 0.0);
    
    fclose(fp);
    return 0;
}