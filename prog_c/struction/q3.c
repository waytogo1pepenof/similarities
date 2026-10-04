#include <stdio.h>
#include <math.h>

struct Coodinate {
    int x;
    int y;
    int z;
};

int two_pow(int input) {
    return input * input;
}

int main() {
    struct Coodinate A = {1, 5, 2};
    struct Coodinate B = {5, 3, 1};
    struct Coodinate C = {2, 8, 4};

    int a_b = two_pow(A.x - B.x) + two_pow(A.y - B.y) + two_pow(A.z - B.z);
    int zero_c = two_pow(C.x) + two_pow(C.y) + two_pow(C.z);

    double output;
    printf("bigger is...\n");
    if (a_b > zero_c) {
        output = sqrt(a_b);
    } else {
        output = sqrt(zero_c);
    }
    printf("%lf", output);
    // bigger is...
    // 9.165151
    return 0;
}