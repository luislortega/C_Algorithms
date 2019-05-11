/**
 * @author Luis Gerardo Leon Ortega
 *
 * EL PROYECTO SUPONE QUE INGRESAS TODOS LOS ITEMS AL INICIO.
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
    printf("other) Crash the program. \n");
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
    if (searchItemById(arrayList, idToSearch)){
        if(idToSearch != arrayList->size){
            for (int i = idToSearch; i < arrayList->size; ++i) {
                if(i == arrayList->size-1){
                    arrayList->items[i] = NULL;
                }else{
                    arrayList->items[i-1] = arrayList->items[i];
                }
            }
        }else{
            free(arrayList->items[idToSearch-1]);
        }
        arrayList->used--;
        printf("El item ha sido eliminado. \n");
    }else{
        printf("No existe ese item. \n");
    }
}

Item* searchItemById(ArrayList *arrayList, int idToSearch){
    Item* item = NULL;
    for (int i = 0; i < arrayList->size; ++i) {
        if((i+1) == idToSearch){
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