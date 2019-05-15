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

int main(){
    LinkedList list;
}