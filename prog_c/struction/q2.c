#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};

int main() {
    struct Ellipse data = {{1, 1}, 4, 2};

    double surface;
    surface = 3.14 * data.a * data.b;
    printf("surface is...\n%lf", surface);
    // surface is...
    // 25.12000
    return 0;
    
}