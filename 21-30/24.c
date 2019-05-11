#include <stdio.h>

void proceso(int*);
void salidas(int[50]);

int main(){
    /* entradas */
    int V[50];
    /* proceso */
    proceso(V);
    /* salidas */
    salidas(V);
    return 0;
}

void proceso(int* v){
    int cero = 1;
    for (int i = 0; i <= 49; ++i) {
        v[i] = (cero) ? 0 : 1;
        cero = (cero) ? 0 : 1;
    }
}

void salidas(int v[50]){
    for (int i = 0; i <= 49; ++i) {
        printf(" %i", v[i]);
    }
}
