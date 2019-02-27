/**
 * @author Luis Gerardo Leon Ortega
 * Calculate all three-digit numbers such that the sum of the cubes of
 * the digits is equal to the number.
 */
#include "stdio.h"

void leer(int*);
void proceso(int);
void salida();
int concatena(int, int);


int main() {
    int n;
    leer(&n);
    proceso(n);
    salida();
    return 0;
}

void leer(int* n){
    printf("Ingresa la cantidad de iteraciones que haras");
    scanf("%i", n);
}

void proceso(int n){
    for (int i = 1; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                n--;
                int concatenado = concatena(i, j);
                concatenado = concatena(concatenado, k);

                if(((i*i*i)+(j*j*j)+(k*k*k)) == concatenado){
                    printf("Los numeros son: %i - %i - %i \n", i, j, k);
                }

                if(n == 0){
                    return;
                }
            }
        }
    }
}

void salida(){
    printf("Ejecucion terminada");
}

int concatena(int x, int y) {
    int pow = 10;
    while(y >= pow){
        pow *= 10;
    }
    return x * pow + y;
}

