#ifndef LINKED_LIST_H
#define LINKED_LIST_H
typedef struct node
{
    struct node *link;
    struct student *data;
}node;

typedef struct point
{
    struct node *head;
    struct node *current;
    struct node *tail;
}point;
typedef struct student{
    char *name;
    int roll;
    char *section;
    char *class;
}student;
point init();
void list_traverse(point *ptr);
void list_push(point *ptr,student *self);
void list_pop(point *ptr);
void list_insert(point *ptr,student *self,int pos);
void list_delete(point *ptr,int pos);
int list_length(point *ptr);
#endif