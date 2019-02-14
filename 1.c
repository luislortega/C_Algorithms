/**
 * Author: Luis Gerardo Leon Ortega
 * Entrada: un numero n
 * Salida general: MCD de dos numeros con algoritmo de Euclides
 * Proceso general:
 * a. Dividir el mayor de los dos números por el más pequeño
 * b. A continuación dividir el divisor por el resto
 * c. Continuar el proceso de dividir el último resto hasta que la división
 * sea exacta.
 * d. El último divisor es el MCD
 */
#include <stdio.h>

void f(int*);

int main() {
    int x = 47;
    printf("x = %d \n", x);
    printf("direccion de x = %x \n", &x);
    f(&x);
    printf("x = %d \n", x);
    return 0;
}

void f(int *r){
    printf("r= %d \n", r);
    printf("el tamano es: %d \n",sizeof(r));
    *r = 5;
    printf("r = %d \n", *r);
}