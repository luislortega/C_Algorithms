#include <stdio.h>
#include <stdlib.h>


struct item {
    int id;
    int precio;
    int cantidad;
};

struct node {
    struct item item;
    struct node *next;
};

struct linkedList {
    struct node *node;
};

typedef struct item Item;
typedef struct node Node;
typedef struct linkedList LinkedList;


/* Initial State */
void initLinkedList(LinkedList*);
int getOptions();

/* CRUD */
void createItem(LinkedList*);
void readItem(LinkedList*);
void updateItem(LinkedList*);
void deleteItem(LinkedList*);
void printAllItems(LinkedList*);

/* Item manipulation */
Item* swap(Item*, Item*);
Item* compareTo(Item*, Item*); //Make the real compareTo...
void printItem(struct item);
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
                printAllItems(&linkedList);
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
    printf("[5] Print all items \n");
    printf("[6] Exit \n");
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
    if (linkedList->node == NULL){
        linkedList->node = node;
    }else{
        Node *loadNode = linkedList->node;
        while (loadNode->next != NULL){
            loadNode = loadNode->next;
        }
        loadNode->next = node;
    }
}

void printAllItems(LinkedList   *linkedList){
    if (linkedList->node != NULL){
        Node *loadNode = linkedList->node;
        while (loadNode->next != NULL){
            printItem(loadNode->item);
            loadNode = loadNode->next;
        }
        printItem(loadNode->item); //Last item.
    }
}

/**
* Item manipulation
*/

void printItem(struct item item){
    printf("ID %i \n", item.id);
}

void createNode(Node *node){
    printf("*******************ITEM******************** \n");
    printf("Ingresa un id para el Item: \n");
    scanf("%i", &node->item.id);
    printf("Ingresa un precio para el Item: \n");
    scanf("%i", &node->item.precio);
    printf("Ingresa una cantidad para el Item: \n");
    scanf("%i", &node->item.cantidad);
    printf("******************************************* \n");
    node->next = NULL;
}