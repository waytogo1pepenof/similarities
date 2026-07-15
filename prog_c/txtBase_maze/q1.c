# include <stdio.h>
# include <stdlib.h>

int read_map() {
	FILE *fp;
	int ch;
	int count;
	
	fp = fopen("map.txt", "rt");
	
	if (!fp) {
        perror("Cannot open this file");
        exit(1);
    }

    while(ch != -1) {
        ch = fgetc(fp);
        printf("%c", ch);
    }

	fclose(fp);
	return 0;
}

int main() {
    read_map();
    return 0;
}