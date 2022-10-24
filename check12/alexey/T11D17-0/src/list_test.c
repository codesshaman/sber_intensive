#include <stdio.h>
#include <stdlib.h>
#include "door_struct.h"
#include "list.h"

void test_list();
int main() {
    #ifdef LIST_TEST
    test_list();
    #endif
}

void test_list() {
    struct door door1;
    door1.id = 42;
    door1.status = 0;
    struct node *FIRST = init(&door1);
    struct door door2;
    door2.id = 69;
    door2.status = 1;
    add_door(FIRST, &door2);
    struct door door3;
    door3.id = 73;
    door3.status = 1;
    add_door(FIRST, &door3);
    print_list(FIRST);
    struct node *door_69 = find_door(69, FIRST);
    printf("\n Found door:\n%d, %d\n", door_69->id, door_69->status);
    FIRST = remove_door(FIRST->next, FIRST);
    print_list(FIRST);
    FIRST = remove_door(FIRST, FIRST);
    print_list(FIRST);
    destroy(FIRST);
}
