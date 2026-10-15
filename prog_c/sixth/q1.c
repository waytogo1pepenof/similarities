#include <stdio.h>

int cal_array(const int (*x)[3], const int (*y)[2], const int (*z)[2], int (*ans)[2]) {
    int temp[2][2] = {0};
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                temp[i][j] = temp[i][j] + (x[i][k] * y[k][j]);
            }
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans[i][j] = temp[i][j] + z[i][j];
        }
    }
    return 0;
}

int main(void) {
    const int x[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    const int y[3][2] = {
        {6, 5},
        {4, 3},
        {2, 1}
    };

    const int z[2][2] = {
        {10, 6},
        {4, 9},
    };

    int ans[2][2] = {0};

    cal_array(x, y, z, ans);
    
    printf("answer = {\n");
    for (int i = 0; i < 2; i++) {
        printf("{");
        for (int j = 0; j < 2; j++) {
            printf("%d", ans[i][j]);
            if (j != 1) {
                printf(", ");
            }
        }
        printf("}, ");
        printf("\n");
    }
    printf("}");

    return 0;
}