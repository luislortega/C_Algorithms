#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int precio;
    int cantidad;
} Item;

typedef struct{
    Item *item;
    struct Node *next;
} Node;

typedef struct {
    Node *node;
} LinkedList;

/* Initial State */
void initLinkedList(LinkedList*);
int getOptions();

/* CRUD */
void createItem(LinkedList*);
void readItem(LinkedList*);
void updateItem(LinkedList*);
void deleteItem(LinkedList*);

/* Item manipulation */
Item* swap(Item*, Item*);
Item* compareTo(Item*, Item*); //Make the real compareTo...
void createNode(Node*);

int main(){
    LinkedList linkedList;
    initLinkedList(&linkedList);
    while(1){
        switch(getOptions()){
            case 1:
                createItem(&linkedList);
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
/**
 * Initial state
 */
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

/**
* CRUD
*/
void createItem(LinkedList *linkedList){
    Node *node = (Node*)malloc(sizeof(Node));
    createNode(node);
}

/**
* Item manipulation
*/

void createNode(Node *node){
    printf("******************************************* \n");
    printf("Ingresa un id para el Item: \n");
    printf("Ingresa un precio para el Item: \n");
    printf("Ingresa una cantidad para el Item: \n");
    printf("******************************************* \n");
    node->next = NULL;
}