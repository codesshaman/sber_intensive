#ifndef SRC_LIST_H_
#define SRC_LIST_H_

struct node {
    int id;
    int status;
    struct node *next;
};

struct node *init(struct door *door);
struct node *add_door(struct node *elem, struct door *door);
void destroy(struct node *root);
void print_list(struct node *head);
struct node *remove_door(struct node *elem, struct node *root);
struct node *find_door(int door_id, struct node *root);
#endif  // SRC_LIST_H_
