#include<stdio.h>
#include <stdlib.h>
#include"linked_list.h"
int main(){
    int op;
    point ls = init();
    int value;
    int pos;
    while(1){
        list_traverse(&ls);
        printf("Enter the operation number(1-):\n");
        printf("1.LENGTH\n");
        printf("2.PUSH\n");
        printf("3.POP\n");
        printf("4.INSERT at Location\n");
        printf("5.DELETE from Location\n");
        printf(": ");
        scanf("%d",&op);
        switch (op)
        {
        case 1:
            printf("LENGTH = %d\n",list_length(&ls));
            scanf("%d",&value);
            break;
        case 2:
            printf("Value to be Pushed : ");
            scanf("%d",&value);
            list_push(&ls,value);
            break;
        case 3:
            list_pop(&ls);
            break;
        case 4:
            printf("Position : ");
            scanf("%d",&pos);
            printf("Value to be Inserted : ");
            scanf("%d",&value);
            list_insert(&ls,value,pos);
            break;
        case 5:
            printf("Position : ");
            scanf("%d",&pos);
            list_delete(&ls,pos);
            break;
        default:
            break;
        }
        printf("\e[1;1H\e[2J");
    }
}