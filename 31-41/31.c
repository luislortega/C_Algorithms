/**
 * Triangulo 9
 */
#include <stdio.h>
#define SIZE 3

void procesoTriangulo(int[SIZE][SIZE]);

int main() {
    int matriz[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("Ingresa la posicion [%i][%i] \n",i,j);
            scanf(" %i", &matriz[i][j]);
        }
    }

    //Print values
    for (int k = 0; k < SIZE; ++k) {
        for (int i = 0; i < SIZE; ++i) {
            printf("| %i |", matriz[k][i]);
        }
        printf("\n \n");
    }

    procesoTriangulo(matriz);

    return 0;
}

/**
 * Triangulo 9
 * de arriba para abajo
 * imprimiendo las filas de izquierda a derecha
 * @param matriz
 */
void procesoTriangulo(int matriz[SIZE][SIZE]){
    printf("Resultado: \n");
    int tamano = SIZE;

    for (int k = 0; k < SIZE; ++k) {
        for (int i = 0; i < tamano; ++i) {
            printf("| %i |", matriz[k][i]);
        }
        tamano = tamano - 1;
        printf("\n");
    }

    int c1 = 0;
    int c2 = 1
    printf("Resultado2:%i \n", matriz[SIZE-1][0]);
    for (int j = 0; j < SIZE; ++j) {
        for (int i = 0; i <= SIZE; ++i) {

        }
    }


}

