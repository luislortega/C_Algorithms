#include <stdio.h>

void entradas(int*);
void proceso(int, int*, int, int);
void salida(int);

int main() {
    /* entradas */
    int  binario, decimalBInario = 0, base = 1, temporal = 0;
    entradas(&binario);
    /* proceso */
    proceso(binario, &decimalBInario, base, temporal);
    /* salida */
    salida(decimalBInario);
    return 0;
}

void entradas(int* num){
    printf("Ingresa el numero binario");
    scanf("%i", num);
}

void proceso(int binario, int* decimalBinario, int base, int temporal){
    while(binario > 0){
        temporal = binario % 10;
        *decimalBinario += temporal * base;
        binario = binario / 10;
        base = base * 2;
    }
}

void salida(int decimalBinario){
    printf("Resultado: %i", decimalBinario);
}

