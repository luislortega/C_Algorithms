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
void searchInArrayList(ArrayList*);
void updateInArrayList(ArrayList*);
void deleteInArrayList(ArrayList*);

Item* createItem();
Item* searchItemById(ArrayList*, int);

int main(){
    ArrayList lista;
    initArrayList(&lista);

    while(1){
        switch (returnOptions()){
            case 1:
                insertInArrayList(&lista);
                break;
            case 2:
                searchInArrayList(&lista);
                break;
            case 3:
                updateInArrayList(&lista);
                break;
            case 4:
                deleteInArrayList(&lista);
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
    printf("3) Update an element. \n");
    printf("4) Delete an element. \n");
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
void searchInArrayList(ArrayList *arrayList){
    int idToSearch;
    printf("Ingresa el id del producto que buscas:\n");
    scanf("%d", &idToSearch);
    Item* item = searchItemById(arrayList, idToSearch);
    (item) ? printf("Item properties: \n Id: %i \n precio: %i \n cantidad: %i \n", item->id, item->precio, item->cantidad) : printf("This item does not exist \n");
};


void updateInArrayList(ArrayList *arrayList){
    int idToSearch;
    printf("Ingresa el id del producto que actualizaras:\n");
    scanf("%d", &idToSearch);
    if (searchItemById(arrayList, idToSearch)){
        Item* newItem = createItem();
        arrayList->items[idToSearch-1] = newItem;
        printf("Datos del item actualizados. \n");
    }else{
        printf("No existe ese item. \n");
    }
}

void deleteInArrayList(ArrayList *arrayList){
    int idToSearch;
    printf("Ingresa el id del producto que borraras:\n");
    scanf("%d", &idToSearch);
    
    Item* item = searchItemById(arrayList, idToSearch);
    
    if (item){
        
    }else{
        printf("No existe ese item. \n");
    }
    
    /*int flag = 0;
    int target = searchID(content);
    if(target!=-1){
        free(*(content.array+target));
        printf("The item has been erased.\n");
        if(target!=content.maxSize-1){
            while(target!=content.counter){
                (*(content.array+target))->ID = (*(content.array+target+1))->ID;
                (*(content.array+target))->quantity = (*(content.array+target+1))->quantity;
                (*(content.array+target))->price = (*(content.array+target+1))->price;
                target = target + 1;
            }
            free(*(content.array+target));
        }
        flag = 1;
    }
    return flag; */
}

Item* searchItemById(ArrayList *arrayList, int idToSearch){
    Item* item = NULL;
    for (int i = 0; i < arrayList->size; ++i) {
        if(arrayList->items[i]->id == idToSearch){
            item = arrayList->items[i];
        }
    }
    return item;
}

Item* createItem(){
    Item* item = (Item*)malloc(sizeof(Item));
    /* agrega una comprobacion que no se repita el mismo id */
    printf("Ingresa el id. \n");
    scanf("%i", &item->id);
    printf("Ingresa el precio. \n");
    scanf("%i", &item->precio);
    printf("Ingresa la cantidad. \n");
    scanf("%i", &item->cantidad);
    return item;
}