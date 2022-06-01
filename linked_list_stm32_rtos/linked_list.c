#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linked_list.h"
#include"FreeRTOS.h"
point init(){
   point ptr = {NULL,NULL,NULL};
   return ptr;
}
void list_traverse(point *ptr){
    int i=0;
    if(ptr->head != NULL){
        ptr->current = ptr->head;
        while(ptr->current->link != NULL){
            printf("(%d) : ",i);
            printf("Name = %s, roll =  %d , ptr = %p\n", ptr->current->data->name,ptr->current->data->roll,ptr->current->link);
            ptr->current=ptr->current->link;
            i++;
        }
        printf("(%d) : ",i);
        printf("Name = %s, roll =  %d , ptr = %p\n", ptr->current->data->name,ptr->current->data->roll,ptr->current->link);
    }
}

void list_insert(point *ptr,student *self,int pos){ //pos = -1 to place at the end
    if(pos>-1){
        node *temp = (node *)pvPortMalloc(sizeof(node));
        student *data = (student *)pvPortMalloc(sizeof(student));
        data->name = (char *)pvPortMalloc(strlen(self->name));
        data->section = (char *)pvPortMalloc(strlen(self->section));
        data->class = (char *)pvPortMalloc(strlen(self->class));
        strcpy(data->name,self->name);
        strcpy(data->section,self->section);
        strcpy(data->class,self->class);
        data->roll = self->roll;
        temp->data = data;
        temp->link = NULL;
        ptr->current = ptr->head;
        if(pos == 0){
            temp->link = ptr->head;
            ptr->head = temp;
        }
        else{
            for(int i=0;i<pos-1;i++){
                ptr->current = ptr->current->link;
            }
            temp->link = ptr->current->link;
            ptr->current->link = temp;
            ptr->current = temp;
        }
    }
}

void list_push(point *ptr,student *self){
    node *temp = (node *)pvPortMalloc(sizeof(node));
    student *data = (student *)pvPortMalloc(sizeof(student));
    data->name = (char *)pvPortMalloc(strlen(self->name));
    data->section = (char *)pvPortMalloc(strlen(self->section));
    data->class = (char *)pvPortMalloc(strlen(self->class));
    strcpy(data->name,self->name);
    strcpy(data->section,self->section);
    strcpy(data->class,self->class);
    data->roll = self->roll;
    temp->data = data;
    temp->link = NULL;
    if(ptr->head == NULL){
        ptr->head = temp;
        ptr->current = ptr->head;
        ptr->tail = ptr->head;
    }
    else{
        ptr->tail->link = temp;
        ptr->tail = temp;
    }
    
}
void list_pop(point *ptr){
    if(ptr->head != NULL){
        if(ptr->head->link == NULL){
            vPortFree(ptr->head->data->name);
            vPortFree(ptr->head->data->section);
            vPortFree(ptr->head->data->class);
            vPortFree(ptr->head->data);
            vPortFree(ptr->head);
            ptr->head=NULL;
        }
        else{
            if(ptr->current->link == NULL){
                ptr->current = ptr->head;
            }
            while(ptr->current->link->link !=NULL){
                ptr->current = ptr->current->link;
            }
            vPortFree(ptr->current->link->data->name);
            vPortFree(ptr->current->link->data->section);
            vPortFree(ptr->current->link->data->class);
            vPortFree(ptr->current->link->data);
            vPortFree(ptr->current->link);
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
                vPortFree(temp->data->name);
                vPortFree(temp->data->section);
                vPortFree(temp->data->class);
                vPortFree(temp->data);
                vPortFree(temp);
            }
            else{
                ptr->current = ptr->head;
                for(int i=0;i<pos-1;i++){
                    ptr->current = ptr->current->link;
                }
                temp = ptr->current->link;
                ptr->current->link = temp->link;
                vPortFree(temp->data->name);
                vPortFree(temp->data->section);
                vPortFree(temp->data->class);
                vPortFree(temp->data);
                vPortFree(temp);
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