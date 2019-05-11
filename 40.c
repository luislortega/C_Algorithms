/**
 * @author Luis Gerardo Leon Ortega
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int precio;
    int cantidad;
} Item;

typedef struct {
    Item **items;
    int used;
    int size;
} ArrayList;


void initArrayList(ArrayList*);
int returnOptions();
void insertInArrayList(ArrayList*);
Item* createItem();

int main(){
    ArrayList lista;
    initArrayList(&lista);

    while(1){
        switch (returnOptions()){
            case 1:
                insertInArrayList(&lista);
                break;
            default:
                printf("Exit...");
                exit(0);
        }
    }
}

void initArrayList(ArrayList *arrayList) {
    int initialSize;
    printf("¿Cual sera el tamano de su ArrayList?");
    scanf("%i", &initialSize);
    arrayList->items = (Item**)malloc(initialSize * sizeof(Item**));
    arrayList->used = 0;
    arrayList->size = initialSize;
}

int returnOptions(){
    int option;
    printf(":- CRUD MENU -:. \n");
    printf("1) Create an element. \n");
    printf("2) Read an element. \n");
    printf("7) Crash the program. \n");
    scanf("%i", &option);
    return option;
}

void insertInArrayList(ArrayList *arrayList){
    if(arrayList->used < arrayList->size){
        *(arrayList->items+arrayList->used) = createItem();
        arrayList->used++;
        printf("Item agregado. \n");
    }else{
        printf("Ya no hay mas espacio. \n");
    }
}

Item* createItem(){
    Item* item = (Item*)malloc(sizeof(Item));
    printf("Ingresa el id. \n");
    scanf("%i", &item->id);
    printf("Ingresa el precio. \n");
    scanf("%i", &item->precio);
    printf("Ingresa la cantidad. \n");
    scanf("%i", &item->cantidad);
    return item;
}