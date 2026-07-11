#include <stdio.h>
#include <stdlib.h>

#define W 12
#define H 10
char map[H][W];

int read_map() {
    FILE *fp;
    int ch;

    fp = fopen("map.txt", "rt");

    if (!fp) {
        perror("Cannot open this file.");
        exit(1);
    }

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {\
            ch = fgetc(fp);

            if (ch == -1) {
                perror("Cannot input this data.");
                exit(1);
            }

            switch (ch) {
                case '\n':
                    x--;
                    break;
                case ' ':
                    map[y][x] = 0;
                    break;
                case '#':
                    map[y][x] = 1;
                    break;
                case 'G':
                    map[y][x] = 2;
                    break;
            
                default:
                    printf("invalid data: ( %d, %d)|%d|%c\n", x, y, ch, ch);
                    return 0;
            }
        }
    }

    fclose(fp);
    return 0;
}

// print_map関数を便宜上省略、read_map関数が完璧であるという仮定の下。

int print_mini_map(int x, int y) {
    printf("(%d, %d)\n", x , y);

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (i == 0 && j == 0) {
                printf("o");
            } else {
                switch (map[y+i][x+j]) {
                    case 0:
                        printf(".");
                        break;
                    case 1:
                        printf("#");
                        break;
                    case 2:
                        printf("G");
                        break;
            
                    // defaultはもう省略、入力の時点で不正値を弾いてるからOKってことにしとく。
                }
            }            
        }
        printf("\n");
    }
}

int main() {
    int x, y;
    x = 1;
    y = 1;

    read_map();
    // print_map();
    print_mini_map(x, y);
    return 0;
}