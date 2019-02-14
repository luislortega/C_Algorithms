/**
 * Algorithm tower of hanoi
 */
#include <stdio.h>
#include <string.h>

char* moverDisco(char*, char*);
void towerOfHanoi(int, char*, char*, char*);

int main() {
    printf("Hello, World!\n");
    towerOfHanoi(1, "a", "c", "b");
    return 0;
}

//Disco, origen, destino, auxiliar
void towerOfHanoi(int disco, char* origen, char* destino, char* auxiliar){
    if(disco == 1){
        printf("%char", unsigned char moverDisco(origen, destino));
    }
}

char* moverDisco(char* origen, char* destino){
    return strcat(origen,destino);
}