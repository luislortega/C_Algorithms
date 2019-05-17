#include <stdio.h>

//Funciones
int factorial(int);
int multiplicacionEntera(int, int);
int exponenciacionEntera(int, int);
int maximoComunDivisor(int, int);
int sumaVectores(int[], int);
int busquedaBinariaRecursiva(int[], int, int, int);
int solucionDeRecurrencia(int, int, int);

int main(){
    //Variables
    int opcion;
    int numero1;
    int numero2;
    int numero3;
    int resultado;
    int numeros[999];
    int busqueda;
    printf("Ingrese una opcion \n");
    printf("1. Factorial \n"); //Listo
    printf("2. Multiplicacion entera \n");
    printf("3. Exponenciacion entera \n");
    printf("4. MCD \n");
    printf("5. Suma de los elementos de un vector \n");
    printf("6. Busqueda binaria \n");
    printf("7. Solucion de una recurrencia \n");
    scanf("%i", &opcion); // opcion
    switch (opcion){
        case 1:
            printf("Ingresa un numero para tu factorial \n");
            scanf("%i", &numero1);
            resultado = factorial(numero1);
            printf("El resultado es %i", resultado);
            break;
        case 2:
            printf("Ingresa dos numeros para tu multiplicacion entera \n");
            printf("Ingresa tu primer nuermo \n");
            scanf("%i", &numero1);
            printf("Ingresa tu segundo numero \n");
            scanf("%i", &numero2);
            resultado = multiplicacionEntera(numero1, numero2);
            printf("El resultado es %i", resultado);
            break;
        case 3:
            printf("Ingrese dos numeros para la exponenciacion entera \n");
            printf("Ingresa tu primer nuermo \n");
            scanf("%i", &numero1);
            printf("Ingresa tu segundo numero \n");
            scanf("%i", &numero2);
            resultado = exponenciacionEntera(numero1, numero2);
            printf("El resultado es %i", resultado);
            break;
        case 4:
            printf("Ingrese dos numeros para el maximo comun divisor \n");
            printf("Ingresa tu primer nuermo \n");
            scanf("%i", &numero1);
            printf("Ingresa tu segundo numero \n");
            scanf("%i", &numero2);
            resultado = maximoComunDivisor(numero1, numero2);
            printf("El resultado es %i", resultado);
            break;
        case 5:
            printf("Ingresa el tamaño de su vector \n");
            scanf("%i", &numero1);

            for (int i = 0; i < numero1; ++i) {
                printf("Ingresa el numero [%i] del vector \n", i);
                scanf(" %i", &numeros[i]);
            }

            resultado = sumaVectores(numeros, numero1-1);

            printf("El resultado de la suma es: %i", resultado);

            break;
        case 6:

            printf("Ingresa el tamaño de tu vector \n");
            scanf("%i", &numero1);

            printf("Ingrese %i valores para la busqueda binaria \n", numero1);

            for (int i = 0; i < numero1; ++i) {
                printf("Ingresa el numero [%i] \n", i);
                scanf(" %i", &numeros[i]);
            }

            printf("Ingresa el numero a buscar \n");
            scanf("%i", &busqueda);
            resultado = busquedaBinariaRecursiva(numeros, busqueda, 0, numero1-1);
            printf("El resultado es %i ", resultado);
            break;
        case 7:
            //Solucion de una recurrencia
            printf("Ingrese un valor para buscarlo con la solución de una relación de recurrencia lineal homogénea con coeficientes constantes de segundo orden \n");
            printf("Ingrese tu caso base f(0) \n");
            scanf("%i", &numero1);
            printf("Ingrese tu caso base f(1) \n");
            scanf("%i", &numero2);
            printf("Hasta que f(n) quieres hacerlo \n");
            scanf("%i", &numero3);
            resultado = solucionDeRecurrencia(numero3, numero1, numero2);
            printf("El resultado es: %i", resultado);
            break;
        default:
            printf("Escoge una opcion valida :)");
            break;

    }
    return 0;
}
/*
 * Nota para mi gran maestro Rios:
 *
 * Hice los algoritmos tal y como estan en el pdf pero vi que podia comprimirlos
 * de forma ternaria :( espero no me baje puntos, son los mismos algoritmos pero simplificados
 *
 * GRACIAS!!!
 */

int factorial(int n){
    return (n <= 0)? 1 :  n * factorial(n-1);
}

int multiplicacionEntera(int n, int b){
    return (b <= 0)? 0 : n + multiplicacionEntera(n, b-1);
}

int exponenciacionEntera(int n, int b){
    return (b <= 0) ? 1 : n * exponenciacionEntera(n, b-1);
}

int maximoComunDivisor(int n, int b){
    return (n < b) ? maximoComunDivisor(b, n) : (b == 0) ? n : maximoComunDivisor(b, n%b);
}

int sumaVectores(int arreglo[], int n){
    return (n == 0) ? arreglo[n] : sumaVectores(arreglo, n-1) + arreglo[n];
}

int busquedaBinariaRecursiva(int arreglo[], int busqueda, int izquierda, int derecha){
    if (izquierda > derecha) return -1;
    int mitad = (izquierda + derecha) / 2;
    if (busqueda == arreglo[mitad]){
        return mitad;
    }
    return (busqueda < arreglo[mitad]) ? busquedaBinariaRecursiva(arreglo, busqueda, izquierda, mitad-1) : busquedaBinariaRecursiva(arreglo, busqueda, mitad +1, derecha);
}

int solucionDeRecurrencia(int n, int base1, int base2){
    return (n == 0) ? base1 : ( n == 1) ? base2 : 5*solucionDeRecurrencia(n-1, base1, base2) + (-4)*solucionDeRecurrencia(n-2, base1, base2);
}
