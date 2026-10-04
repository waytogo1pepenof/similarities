#include <stdio.h>

struct Body {
    int id;
    int height;
    int weight;
    float bmi;
};

int main() {
    struct Body people[4] = {
        {.id = 1, .height = 170, .weight = 60},
        {.id = 2, .height = 150, .weight = 50},
        {.id = 3, .height = 160, .weight = 56},
        {.id = 4, .height = 180, .weight = 70},
    };

    for (int i = 0; i < 4; i++) {
        float conv = people[i].height / 10;
        people[i].bmi = (people[i].weight / (conv * conv)) * 100;
    }

    printf("each people bmi is...\n");
    for (int j = 0; j < 4; j++) {
        printf("id: %d\n|| bmi: %.1f\n", people[j].id, people[j].bmi);
    }
    // each people bmi is...
    // id: 1
    // || bmi: 20.8
    // id: 2
    // || bmi: 22.2
    // id: 3
    // || bmi: 21.9
    // id: 4
    // || bmi: 21.6

    return 0;
}
