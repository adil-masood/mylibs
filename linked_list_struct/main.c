#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"linked_list.h"
int main(){
    student data;
    data.name = (char *)malloc(20*sizeof(char));
    data.section = (char *)malloc(20*sizeof(char));
    data.class = (char *)malloc(20*sizeof(char));
    data.roll = 21;
    point ls = init();
    int op;
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
            scanf("%d",&data.roll);
            break;
        case 2:
            printf("Values to be Pushed : \n");
            printf("Name : ");
            scanf("%s",data.name);
            printf("Roll : ");
            scanf("%d",&data.roll);
            list_push(&ls,&data);
            break;
        case 3:
            list_pop(&ls);
            break;
        case 4:
            printf("Position : ");
            scanf("%d",&pos);
            printf("Value to be Inserted : \n");
            printf("Name : ");
            scanf("%s",data.name);
            printf("Roll : ");
            scanf("%d",&data.roll);
            list_insert(&ls,&data,pos);
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