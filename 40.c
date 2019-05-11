/**
 * @author Luis Gerardo Leon Ortega
 *
 * CRUD:
 * [x] CREATE
 * [x] READ
 * [x] UPDATE
 * [ ] DELETE
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *element; //This is the link for the item.
    size_t used;
    size_t size;
} ArrayList;

void initArrayList(ArrayList*, size_t);
void insertInArrayList(ArrayList*, int);
void updateInArrayList(ArrayList*, int, int);
void deleteInArrayList(ArrayList*, int, size_t);

int main(){
    ArrayList lista;
    initArrayList(&lista, 4);
    //elements...
    insertInArrayList(&lista, 1);
    insertInArrayList(&lista, 2);
    insertInArrayList(&lista, 3);
    insertInArrayList(&lista, 4);
    //Update
    updateInArrayList(&lista, 2, 202); //Position - 1
    //Delete
    deleteInArrayList(&lista, 2, lista.used); //Position - 1
    //Prints
    for (int i = 0; i < lista.size; ++i) {
        printf("%d\n", lista.element[i]);
    }
}

void initArrayList(ArrayList *arrayList, size_t initialSize) {
    arrayList->element = (int *)malloc(initialSize * sizeof(int)); //Reserva el espacio en memoria para el elemento tipo int
    arrayList->used = 0;
    arrayList->size = initialSize;
}

void insertInArrayList(ArrayList *arrayList, int element) {
    if (arrayList->used == arrayList->size) {
        arrayList->size *= 2;
        arrayList->element = (int *)realloc(arrayList->element, arrayList->size * sizeof(int));
    }
    arrayList->element[arrayList->used++] = element;
}

void updateInArrayList(ArrayList *arrayList, int posicion, int nuevo_elemento){
    arrayList->element[posicion] = nuevo_elemento;
}

void deleteInArrayList(ArrayList *arrayList, int posicion, size_t tamano){
    /**
     * Algoritmo:
     *
     * Agarrar el tamaño del vector y desde el elemento que se va a eliminar hasta el tamaño total del arrayList menos 1.
     *
     * dentro del bucle, recorrer la informacion de el siguiente al anterior.
     *
     * al finalizar el proceso, simplemente actualizar el tamaño total del arrayList
     */
    if(posicion == tamano){
        printf("Estas tratando de borrar el final de la lista.");
    }else{
        for (int i = posicion; i < tamano-1; ++i) {
            arrayList->element[i] = arrayList->element[i+1];
        }
        arrayList->size = arrayList->size - 1;
    }
}