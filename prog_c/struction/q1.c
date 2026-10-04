#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};

int main() {    
    struct Date today = {2026, 10, 04};
    
    printf("today is...\n%d / %d / %d", today.year, today.month, today.day);
    // today is...
    // 2026 / 10 / 4
    return 0;
}