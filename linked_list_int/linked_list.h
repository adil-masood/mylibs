#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct node
{
    struct node *link;
    int value;
}node;

typedef struct point
{
    struct node *head;
    struct node *current;
    struct node *tail;
}point;

point init();
void list_traverse(point *ptr);
void list_push(point *ptr,int value);
void list_pop(point *ptr);
void list_insert(point *ptr,int value,int pos);
void list_delete(point *ptr,int pos);
int list_length(point *ptr);
#endif