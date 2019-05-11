/**
 * @author Luis Gerardo Leon Ortega
 * Write a program that receives a number and tells you if that number is even or odd
 */
#include "stdio.h"

void leer(int*);
void proceso(int, int*);
void salida(int);

int main() {
    int x, resultado; //resultado 0 = impar 1 = par
    leer(&x);
    proceso(x, &resultado);
    salida(resultado);
    return 0;
}

void leer(int* x){
    scanf("%i", x);
}

void proceso(int x, int* resultado){
    *resultado = (x == 0 || x % 2 == 0) ? 1 : 0;
}

void salida(int resultado){
    if(resultado){
        printf("Es par");
    }else{
        printf("Es impar");
    }
}