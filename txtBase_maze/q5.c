# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define W 12
#define H 10

char map[H][W];

int read_map() {
	FILE *fp;
	int ch;
	int count;
	
	fp = fopen("map.txt", "rt");
	
	if (!fp) {
		perror("Cannot open this file");
		exit(1);
	}
	
	for(int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			ch = fgetc(fp);
			switch(ch) {
				default:
					printf("invalidData:(%d,%d) %d %c\n", x, y, ch, ch);
					return 0;
					
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
			}
			count++;
		}
	}
	
	if (count < 130) {
		printf("too short");
		exit(1);
	}
	
	fclose(fp);
	return 0;
}

int print_map() {
	for(int y =0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			printf("%d", map[y][x]);
		}
		printf("\n");
	}
	
	printf("\n");
	
	for(int y = 0; y < H; y++) {
		for (int x = 0; x < W; x++) {
			switch(map[y][x]) {
				case 0:
					printf(" ");
					break;
				case 1:
					printf("#");;
					break;
				case 2:
					printf("G");
					break;
				case 3:
					printf(".");
					break;
			}
		}
		printf("\n");
	}
	
	return 0;
}

int maze0(int x, int y) {
	if (map[y][x] == 0) {
		printf("(%d, %d) ------\n", x, y);
        // 以下問題箇所、コメントアウトしておく
		// maze0(x, y-1);
		// maze0(x, y+1);
		// maze0(x-1, y);
		// maze0(x+1, y);
	} else if (map[y][x] == 1) {
		printf("(%d, %d) XXXXXX\n", x, y);
	} else if (map[y][x] == 2) {
		printf("(%d, %d) OOOOOO\n", x, y);
	}
	
	return 0;
}

int maze1(int x, int y, char his[H][W]) {
    // his = history（履歴）っぽい
    char newhis[H][W];

    switch (map[y][x]) {
        case 0:
            printf("(%d, %d) -----\n", x, y);
            memcpy(newhis, his, H*W);
            newhis[y][x] = 1;

            if (newhis[y-1][x] == 0) {
                maze1(x, y-1, newhis);
            } 
			if (newhis[y+1][x] == 0) {
                maze1(x, y+1, newhis);
            } 
			if (newhis[y][x-1] == 0) {
                maze1(x-1, y, newhis);
            } 
			if (newhis[y][x+1] == 0) {
                maze1(x+1, y, newhis);
            }
            break;

        case 1:
            printf("(%d, %d) xxxxx\n", x, y);
			break;
            
        case 2:
            printf("(%d, %d) ooooo\n", x, y);
			exit(0);

        default:
            printf("undefined error");
            break;
    }

    return 0;
}


int main() {
    static char his[H][W];

	read_map();
	printf("\n## PrintMap\n");
	print_map();
	maze1(1, 1, his);
}