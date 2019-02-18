/**
 * Coseno sin libreria math.h
 * @author Luis Gerardo Leon Ortega
 */
#include <stdio.h>
#include <math.h>

double pi = (3.14159265359/180);
double x;

double coseno(double);
double factorial(double);
double elevar(double, int);
double absoluto(double);

int main() {
    printf("Hola necesito que agreges un X: ");
    scanf_s("%lf", &x);

    printf("Nuestro radian %lf \n", x * pi);

    printf("Nuestra serie nos devolvio: %lf \n", coseno(x * pi));

    printf("Calculado por libreria %lf \n", cos(x * pi));
    return 0;
}

/*
 * Calculador de coseno
 */
double coseno(double x){
    double sumando, sumatoria = 0, precision = 0.0001;
    int e = 0;
    do{
        sumando = elevar(-1.0, e) / factorial(2 * e) * elevar(x, 2*e);
        sumatoria += sumando;
        e++;
    }while (absoluto(sumando) > precision);
    return sumatoria;
}

/*
 * Nuestro factorial
 */
double factorial(double x){
    double factorial = 1.0;
    while(x != 0){
        factorial *= x--;
    }
    return factorial;
}

/*
 * Elevar a ua potencia
 */
double elevar(double x, int y){
    double potencia = 1.0;
    for (int i = 0; i < y; ++i) {
        potencia *= x;
    }
    return potencia;
}

/*
 * valor absoluto
 */
double absoluto(double x){
    if(x<0){
        x*=-1;
    }
    return x;
}