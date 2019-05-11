/**
 * @author Luis Gerardo Leon Ortega
Se dice que una matriz tiene un punto silla si alguna posición de la matriz es el menor
de su fila, y a la vez el mayor de su columna. Escribir un programa que llene una matriz
con números aleatorios reales del 0 al 999 y que determine si la matriz tiene a puntos
silla.
 Example:
 Puntos silla: 1
   C
 F 22 | 21  | 20
   45 | 32 | 3
   60 | 32 | 2
*/
#include <stdio.h>
#define N 3
#define M 3

void entradas(int[N][M]);
int obtenerPuntosSilla(int[N][M]);
void salidas(int);

int main(){
    int matriz[N][M];
    int puntosSilla = 0;
    /* entrada */
    entradas(matriz);


    for (int i = 0; i < N; ++i) {
        printf("\n");
        for (int j = 0; j < M; ++j) {
            printf("| %i |", matriz[i][j]);
        }
    }
    /* proceso */
    puntosSilla = obtenerPuntosSilla(matriz);
    /* salidas */
    salidas(puntosSilla);
    return 0;
}
void entradas(int matriz[N][M]){
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            printf("Ingresa el valor[%i][%i]: \n", i, j);
            scanf(" %i", &matriz[i][j]);
        }
    }
}

int obtenerPuntosSilla(int matriz[N][M]){
    int puntosSilla = 0;
    for (int i = 0; i < N; ++i) {
        int minimum = matriz[0][0]; //Min value
        int maximum = 0; //Max value
        //Get min val
        for (int j = 0; j < M; ++j) {
            if(matriz[i][j] < minimum){
                minimum = matriz[i][j];
            }
        }
        //Get max val
        for (int j = 0; j < N; ++j) {
            if(matriz[i][j] == minimum){
                for (int k = 0; k < M; ++k) {
                    if(matriz[k][j] > maximum){
                        maximum = matriz[k][j];
                    }
                }

            }
        }
        if(minimum == maximum){
            puntosSilla = puntosSilla + 1;
        }
    }
    return puntosSilla;
}

void salidas(int puntosSilla){
    printf("\n Cantidad de puntos silla %i", puntosSilla);
}