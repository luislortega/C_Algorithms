/**
 * @author Luis Gerardo Leon Ortega
 * .Escribe el programa que lea ID numérico, edad y sueldo de 10 personas y
 * que determine cuántos mayores de 35 años obtuvieron salarios
 * comprendidos entre $5000.00 y $7500.00 inclusive.
 */

#include "stdio.h"
#define size 2

void leer(int*, int*, float*);
void procedimiento(int*, float*, int*);
void salida(int);

int main() {
    int id[size], edad[size], contador = 0;
    float sueldo[size];
    leer(id, edad, sueldo);
    procedimiento(edad, sueldo, &contador);
    salida(contador);
    return 0;
}

void leer(int* id, int* edad, float* sueldo){
    for (int i = 0; i < size; ++i) {
        printf("Ingresa la id[%i] \n", i);
        scanf(" %i", &id[i]);
        printf("Ingresa la edad[%i] \n", i);
        scanf(" %i", &edad[i]);
        printf("Ingresa la sueldo[%i] \n", i);
        scanf(" %f", &sueldo[i]);
    }
}

void procedimiento(int* edad, float* sueldo, int* contador){
    for (int i = 0; i < size; ++i) {
        if(edad[i] > 35 && sueldo[i] > 5000 && sueldo[i] < 7500){
            *contador += 1;
        }
    }
}

void salida(int contador){
    printf("Hubo un total de [%i]", contador);
}
