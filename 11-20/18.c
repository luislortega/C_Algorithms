/**
 * @author Luis Gerardo Leon Ortega
 * Escribe el programa que estime el valor de la constante matemática e,
 * mediante la formula:
 * e = 1 + 1/1! + 1 / 2! + 1/3! + ....+ 1/N!
 * Leer el valor N que indica la precisión con la que se quiere obtener el
 * valor de e.
 */
 
#include "stdio.h"

void leer(int*);
void procedimiento(int, float*);
void salida(float);

int factorial(int);

int main() {
    int n;
    float resultado;
    leer(&n);
    procedimiento(n, &resultado);
    salida(resultado);
    return 0;
}

void leer(int* n){
    printf("Ingrese la precision n, debe ser entero >= 0");
    scanf("%i", n);
}

void procedimiento(int n, float* resultado){
    if(n == 0){
        *resultado = 1;
    }else{
        *resultado = 1;
        for (int i = 1; i <= n; ++i) {
            *resultado += 1.0 / factorial(i);
        }
    }

}

void salida(float resultado){
    printf("El resultado es %f", resultado);
}

int factorial(int i){
    int factorial = 1;
    for (int j = 1; j <= i; j++){
        factorial = factorial * j;
    }
    return factorial;
}
