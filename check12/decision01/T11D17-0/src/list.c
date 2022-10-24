#include "door_struct.h"
#include "list.h"
#include <stdlib.h>
#include <stdio.h>

struct node *init(struct door *door) {
    struct node *el = malloc(sizeof(struct node));
    el->id = door->id;
    el->status = door->status;
    el->next = NULL;
    return el;
}

struct node *add_door(struct node *elem, struct door *door) {
    struct node *new_elem = NULL;
    if (elem != NULL) {
        new_elem = malloc(sizeof(struct node));
        new_elem->id = door->id;
        new_elem->status = door->status;
        new_elem->next = elem->next;
        elem->next = new_elem;
    }
    return new_elem;
}

void destroy(struct node *root) {
    struct node *curr_el = root;
    struct node *next_el = root;
    if (root != NULL) {
        while (next_el->next != NULL) {
            next_el = curr_el->next;
            free(curr_el);
        }
        free(next_el);
    }
}

void print_list(struct node *root) {
    struct node *tmp = root;
    if (root != NULL) {
        while (tmp->next != NULL) {
            printf("%d, %d\n", tmp->id, tmp->status);
            tmp = tmp->next;
        }
        printf("%d, %d", tmp->id, tmp->status);
    }
}

struct node *remove_door(struct node *elem, struct node *root) {
    struct node *tmp = root;
    struct node *tmp_del = root;
    if (root != NULL) {
        while ((tmp != elem) && (tmp->next != elem) && tmp->next != NULL) {
            tmp = tmp->next;
        }
        if (tmp->next == NULL) {
            free(tmp);
        } else {
            if (tmp == elem) {
                tmp = root;
                root = root->next;
                free(tmp);
            } else {
                tmp_del = tmp->next;
                tmp->next = tmp_del->next;
                free(tmp_del);
            }
        }
    }
    return root;
}

struct node *find_door(int door_id, struct node *root) {
    struct node *tmp = root;
    while ((door_id != tmp->id) || (tmp->next != NULL)) {
        tmp = tmp->next;
    }
    if (tmp->id != door_id) {
        tmp = NULL;
    }
    return tmp;
}
