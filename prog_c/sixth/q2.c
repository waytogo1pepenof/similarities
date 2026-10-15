#include <stdio.h>
#include <math.h>

typedef struct {
    int id;
    int height;
    int weight;
} Body;

int swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

    return 0;
}

int sort_h(Body *data) {
    int done = 0;
    int unsorted = 5;
    do {
        done = 0;
        for (int i = 0; i+1 < unsorted; i++) {
            if (data[i].height > data[i+1].height) {
                swap(&data[i].id, &data[i+1].id);
                swap(&data[i].height, &data[i+1].height);
                swap(&data[i].weight, &data[i+1].weight);
                done = 1;
            }
        }
        unsorted--;
    } while (done);

    return 0;
}

int main(void) {
    Body people[5] = {
        {1, 165, 60}, {2, 170, 68}, {3, 160, 50}, {4, 180, 75}, {5, 175, 80}
    };

    sort_h(people);    
    printf("[sorting]\n");
    for (int i = 0; i < 5; i++) {
        printf("| [id: %d]height: %d (weight: %d)\n", people[i].id, people[i].height, people[i].weight);
    }

    float ave = 0;
    for (int i = 2; i < 5; i++) {
        ave = ave + people[i].height;
    }
    ave = ave / 3;
    printf("\n[average] %.1f", ave);

    float std = 0;
    float var = 0;
    for (int i = 2; i < 5; i++) {
        var = var + pow((people[i].height - ave), 2.0);
    }
    var = var / 3;
    std = sqrt(var);
    printf("\n[standard.d] %.1f", std);

    return 0;
}