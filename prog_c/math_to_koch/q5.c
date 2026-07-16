#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int koch (double x0, double y0, double x1, double y1, int n, FILE *fp) {
    double fin_x[5], fin_y[5];
    double whole_len_x, whole_len_y;
    // 変数については別記画像ファイルを参照（list.png）
    whole_len_x = x1 - x0;
    whole_len_y = y1 - y0;

    fin_x[0] = x0;
    fin_x[1] = whole_len_x / 3;
    fin_x[3] = whole_len_x * (2/3);
    
    fin_y[0] = y0;
    fin_y[1] = whole_len_y / 3;
    fin_y[3] = whole_len_y * (2/3);

    double sixty_deg = M_PI / 3.0;
    fin_x[2] = fin_x[3] * cos(sixty_deg) - fin_y[3] * sin(sixty_deg);
    fin_y[2] = fin_x[3] * sin(sixty_deg) + fin_y[3] * cos(sixty_deg);

    fin_x[4] = x1;
    fin_y[4] = y1;

    if (n < 0) {
        printf("[invalid: please input n > 0]");
        return 0;
    }

    if (n == 0) {
        fprintf(fp, "%lf\t%lf\n", fin_x[0], fin_y[0]);
        fprintf(fp, "%lf\t%lf\n", fin_x[4], fin_y[4]);
    } else {
        for (int i = 0; i < 5; i++) {
            koch(fin_x[i], fin_y[i], fin_x[i+1], fin_y[i+1], n - 1, fp);
        }
        fprintf(fp, "\n");
    }

}

int main() {

    FILE *fp;
    fp = fopen("a.txt", "wt");
    if (!fp) {
        perror("Cannot open this file.");
        exit(1);
    }

    koch(0, 0, 12, 0, 3, fp);
    
    fclose(fp);
    return 0;
}