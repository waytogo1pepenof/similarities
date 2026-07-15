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

int print_map() {
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            switch (map[y][x]) {
            case 0:
                printf(" ");
                break;
            case 1:
                printf("#");
                break;
            case 2:
                printf("G");
                break;
            
            default:
                printf("invalid data.");
                return 0;
            }
        }
        printf("\n");
    }
}

int main() {
    read_map();
    print_map();
    return 0;
}