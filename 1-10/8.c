/**
 * @author Luis Gerardo Leon Ortega
 * ALGORITMO PUNTO EXTRA NUMERO 13
 */
#include <stdio.h>

void entradas(float*, int*);
int proceso(float, int);
void salidas(float, int);

int tamanoDec(float);
int tamanoEnt(int);
void imprimir(float);

int main() {
    /* entradas */
    float x = 0; int y = 0;
    entradas(&x, &y);
    /* proceso */
    int resultado = proceso(x, y);
    /* salidas */
    salidas(x,resultado);
    return 0;
}

/*
 * Entradas
 */
void entradas(float *x, int *y){
    scanf_s("%f", x);
    scanf_s("%i", y);
}

/*
 * Proceso
 */
int proceso(float a, int b){
    int longitudDecimal = tamanoDec(a), longitudEntera = tamanoEnt((int) a);
    return ((longitudDecimal + longitudEntera) < b) ? (b - (longitudDecimal + longitudEntera)) : 0;
}

/*
 * Salidas
 */
void salidas(float x, int hayMenores){
    if(hayMenores){
        imprimir(x);
        for (int i = 0; i < hayMenores; i++){
            printf("*");
        }
    }
}


/*
 * Imprime dependiendo de la cantidad de decimales
 */
void imprimir(float x){
    int decimales = tamanoDec(x);
    switch (decimales){
        case 1:
            printf("%.1f", x);
            break;
        case 2:
            printf("%.2f", x);
            break;
        case 3:
            printf("%.3f", x);
            break;
        case 4:
            printf("%.4f", x);
            break;
        case 5:
            printf("%.5f", x);
            break;
        case 6:
            printf("%.6f", x);
            break;
        case 7:
            printf("%.7f", x);
            break;
        default:
            printf("%.8f", x);
            break;
    }
}


/*
 *  tamaño de nuestro decimal
 */
int tamanoDec(float a){
    float num = a - (int) a;
    int cantidad = 0;
    for (int i = 0; i < 7; ++i) {
        num *= 10;
        //Cuando tienden a infinitos 9
        if((int)num == 9 && (int) ((num - (int)num) * 10) == 9  ) {
            break;
        }
        //cuando tienden a infinitos 0
        if((int )num == 0 && (int) ((num - (int)num) * 10) == 0  ) {
            if(i == 0){
                cantidad = 1;
            }

        }
        cantidad = cantidad + 1;
        num = (num - (int)num); //agarro solo los decimales
    }
    return cantidad;
}

/*
 * tamaño de nuestro entero
 */
int tamanoEnt(int b){
    int cantidad = 0;
    while(b != 0)
    {
        b /= 10;
        cantidad++;
    }
    return cantidad;
}