#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void zero(struct door* doors);
void ouput(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);
    zero(doors);
    ouput(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
void sort(struct door* doors) {
struct door element;
    for (int i = 0; i < DOORS_COUNT - 1; i++)
        for (int j = 0; j < DOORS_COUNT - 1 - i; j++) {
            if (doors[j].id > doors[j+1].id) {
            element = doors[j];
            doors[j] = doors[j+1];
            doors[j+1] = element;
            }
        }
}


void zero(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}

void ouput(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        printf("%d, %d\n", doors[i].id, doors[i].status);
}
