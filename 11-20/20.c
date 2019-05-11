/**
 * @author Luis Gerardo Leon Ortega
 *  Escribe una función que reciba dos racionales en  el formato de dos pares enteros (numerador y denominador).
 * La función realizará la suma de los dos "racionales" y simplificará el racional resultante. La función no devuelve el valor e imprime el racional resultante simplificado.
 * El prototipo a utilizar es void sumarFracciones(int r1numerador, r1denominador, r2numerador, r2denominador). Implementa las funciones que consideres adecuadas.
 */

#include "stdio.h"

void sumarFraccion(int*, int*, int*, int*);
void salidas(int, int);

int main() {
    /* entradas */
    int d1, d2, n1,n2;
    printf("Ingresa el numerador numero 1 \n");
    scanf("%i", &n1);
    printf("Ingresa el denominador numero 1 \n");
    scanf("%i", &d1);
    printf("Ingresa el numerador numero 2 \n");
    scanf("%i", &n2);
    printf("Ingresa el denominador numero 2 \n");
    scanf("%i", &d2);
    /* procedimiento */
    sumarFraccion(&n1, &n2, &d1, &d2);
    /* salidas */
    salidas(n1,d1);
    return 0;
}

void sumarFraccion(int* n1, int* n2,int* d1, int* d2){
    int nFinal = (*n2 * *d1 )+(*n1 * *d2 );
    int dFinal = *d1 * *d2;
    int esSimplificable = 1;
    while(esSimplificable){
        if(dFinal % 2 == 0 && nFinal % 2 == 0){
            dFinal = dFinal / 2;
            nFinal = nFinal / 2;
        }else{
            if(dFinal % 3 == 0 && nFinal % 3 == 0){
                dFinal = dFinal / 3;
                nFinal = nFinal / 3;
            }else{
                if(dFinal % 5 == 0 && nFinal % 5 == 0){
                    dFinal = dFinal / 5;
                    nFinal = nFinal / 5;
                }else{
                    if(dFinal % 7 == 0 && nFinal % 7 == 0){
                        dFinal = dFinal / 7;
                        nFinal = nFinal / 7;
                    }else{
                         if(dFinal % 13 == 0 && nFinal % 13 == 0){
                        dFinal = dFinal / 13;
                        nFinal = nFinal / 13;
                    }else{
                         if(dFinal % 17 == 0 && nFinal % 17 == 0){
                        dFinal = dFinal / 17;
                        nFinal = nFinal / 17;
                    }else{
                        *d1 = dFinal;
                        *n1 = nFinal;
                        esSimplificable = 0;
                    }
                    }
                    }
                }
            }
        }
    }
}

void salidas(int nFinal,int dFinal){
    if(dFinal == 0){
        printf("Error");
    }else{
        printf("El resultado es: \n");
        printf("%i \n", nFinal);
        printf("_ \n");
        printf("%i \n", dFinal);
    }
}
