#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "door_struct.h"
#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void sort(struct door* doors);
void output(struct door* doors);
void status(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    status(doors);
    sort(doors);
    output(doors);

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
        doors[i].status = rand() % 2; }
}

void sort(struct door* doors) {
  int temp;
  for (int i = 0; i < DOORS_COUNT; i++) {
    for (int j = 0; j < DOORS_COUNT-i-1; j++) {
      if (doors[j].id > doors[j+1].id) {
        temp = doors[j].id;
        doors[j].id = doors[j+1].id;
        doors[j+1].id = temp;
      }
    }
  }
}

void output(struct door* doors) {
    for (int i=0; i < DOORS_COUNT; i++)
      printf("%d,%d\n", doors[i].id, doors[i].status);
}

void status(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++)
        if (doors[i].status == 1)
            doors[i].status = 0;
}
