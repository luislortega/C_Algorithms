#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int precio;
    int cantidad;
} Item;

typedef struct{
    Item **item;
    struct Node **next;
} Node;

typedef struct {
    Node **node;
} LinkedList;

void initLinkedList(LinkedList*);
int getOptions();

int main(){
    LinkedList list;
    initLinkedList(&list);
    while(1){
        switch(getOptions()){
            case 1:
                printf("Do something");
                break;
            case 2:
                printf("Do something");
                break;
            case 3:
                printf("Do something");
                break;
            case 4:
                printf("Do something");
                break;
            case 5:
                printf("Do something");
                break;
            default:
                exit(0);
        }
    }
}

void initLinkedList(LinkedList *linkedList){
    linkedList->node = NULL;
}

int getOptions(){
    int option = 0;
    printf("*****************CRUD MENU***************** \n");
    printf("Welcome please type an answer... \n");
    printf("[1] Create an Item \n");
    printf("[2] Read an Item \n");
    printf("[3] Update an Item \n");
    printf("[4] Delete an Item \n");
    printf("[5] Exit \n");
    printf("*******************************************\n");
    scanf("%i", &option);
    return option;
}