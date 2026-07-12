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
    int input;
    int temp_x, temp_y;
    x = 1;
    y = 1;

    FILE *fp;
    int ch;

    read_map();
    // print_map();
    print_mini_map(x, y);

    while(1) {
        if (map[y][x] == 2) {
            printf("---\nGOOOOOOal!!!!\n---\n");
            return 0;
        } else {
            printf("[what will you move next?]\n| Up:[8]\n| Left:[4]\n| Right:[6]\n| Down:[2]\n| load:[0]\n| save:[1]\n");
            scanf("%d", &input);
            switch (input) {
                case 8:
                    temp_y = y - 1;
                    temp_x = x;
                    break;
                case 2:
                    temp_y = y + 1;
                    temp_x = x;
                    break;
                case 4:
                    temp_y = y;
                    temp_x = x - 1;
                    break;
                case 6:
                    temp_y = y;
                    temp_x = x + 1;
                    break;

                case 1:
                    fp = fopen("data.txt", "w");
                    if (!fp) {
                        perror("Cannot open data.txt");
                        exit(1);
                    } else {
                        fprintf(fp, "X=%d\nY=%d", x, y);
                        fclose(fp);
                        printf("[Done saving! (%d, %d)]\n", x, y);
                        temp_y = y;
                        temp_x = x;
                    }
                    break;
                case 0:
                    fp = fopen("data.txt", "rt");
                    if (!fp) {
                        perror("Cannot open data.txt");
                        exit(1);
                    } else {
                        fscanf(fp, "X=%d\nY=%d", &temp_x, &temp_y);
                        fclose(fp);
                        printf("[Done loading! (%d, %d)]\n", temp_x, temp_y);
                    }
                    break;
            
                default:
                    printf("[Invalid input...]\n");
                    temp_x = x;
                    temp_y = y;
                    break;
            }
            if (map[temp_y][temp_x] == 1) {
                printf("[Cannot pass this way(%d, %d)...]\n", temp_x, temp_y);
            } else {
                y = temp_y;
                x = temp_x;
            }
        }
        print_mini_map(x, y);
    }
    return 0;
}