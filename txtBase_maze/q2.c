# include <stdio.h>
# include <stdlib.h>

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

int main() {
	read_map();
	print_map();
}