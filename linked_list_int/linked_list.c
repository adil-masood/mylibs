#include<stdio.h>
#include <stdlib.h>
#include"linked_list.h"

point init(){
   point ptr = {NULL,NULL,NULL};
   return ptr;
}
void list_traverse(point *ptr){
    if(ptr->head != NULL){
        int i=0;
        ptr->current = ptr->head;
        while(ptr->current->link != NULL){
            printf("(%d) : ",i);
            printf("Value = %d , ptr = %p\n", ptr->current->value,ptr->current->link);
            ptr->current=ptr->current->link;
            i++;
        }
        printf("(%d) : ",i);
        printf("Value = %d , ptr = %p\n", ptr->current->value,ptr->current->link);
    } 
}
void list_insert(point *ptr,int value,int pos){ //pos = -1 to place at the end
    if(pos>-1){
        node *temp = (node *)malloc(sizeof(node));
        temp->value = value;
        temp->link = NULL;
        if(pos == 0){
            temp->link = ptr->head;
            ptr->head = temp;
        }
        else{
            ptr->current = ptr->head;
            for(int i=0;i<pos-1;i++){
                ptr->current = ptr->current->link;
            }
            temp->link = ptr->current->link;
            ptr->current->link = temp;
            ptr->current = temp;
        }
    }
}
void list_push(point *ptr,int value){
    if(ptr->head == NULL){
        ptr->head = (node *)malloc(sizeof(node));
        ptr->head->value = value;
        ptr->head->link = NULL;
        ptr->current = ptr->head;
        ptr->tail = ptr->head;
    }
    else{
        node *temp = (node *)malloc(sizeof(node));
        temp->value = value;
        temp->link = NULL;
        ptr->tail->link = temp;
        ptr->tail = temp;
    }
}
void list_pop(point *ptr){
    if(ptr->head != NULL){
        if(ptr->head->link == NULL){
            free(ptr->head);
            ptr->head=NULL;
        }
        else{
            if(ptr->current->link == NULL){
                ptr->current = ptr->head;
            }
            while(ptr->current->link->link !=NULL){
                ptr->current = ptr->current->link;
            }
            free(ptr->current->link);
            ptr->current->link = NULL;
            ptr->tail = ptr->current;
        }
    }
}
void list_delete(point *ptr,int pos){ //pos = -1 to place at the end
    node *temp;
    if(pos>-1){
        if(ptr->head != NULL){
            if(pos == 0){
                temp = ptr->head;
                ptr->head = ptr->head->link;
                free(temp);
            }
            else{
                ptr->current = ptr->head;
                for(int i=0;i<pos-1;i++){
                    ptr->current = ptr->current->link;
                }
                temp = ptr->current->link;
                ptr->current->link = temp->link;
                free(temp);
            }
        }
    }
}
int list_length(point *ptr){
    int i=0;
    if(ptr->head != NULL){
        i++;
        ptr->current = ptr->head;
        while(ptr->current->link != NULL){
            ptr->current = ptr->current->link;
            i++;
        }
    }
    return i;
}