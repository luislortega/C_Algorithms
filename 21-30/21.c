/**
 * @author Luis Gerardo Leon Ortega
 *   Escribe una función que reciba 2 horas como dos pares de 3 argumentos ( horas, minutos y segundos).
 *   La función debe regresar el número de segundos entre esas 2 horas. El orden de envío de las horas es indistinto
 */

#include "stdio.h"

long segundos(int, int, int, int, int, int);

int main() {
    int t1hora,t1minuto,t1segundo,t2hora,t2minuto,t2segundo;
    printf("[1] \n");
    printf("Ingresa la hora \n");
    scanf(" %i", &t1hora);
    printf("Ingresa los minutos \n");
    scanf(" %i", &t1minuto);
    printf("Ingresa los segundos\n");
    scanf(" %i", &t1segundo);
    printf("[2] \n");
    printf("Ingresa la hora \n");
    scanf(" %i", &t2hora);
    printf("Ingresa los minutos \n");
    scanf(" %i", &t2minuto);
    printf("Ingresa los segundos\n");
    scanf(" %i", &t2segundo);
    long resultado = segundos(t1hora, t1minuto, t1segundo, t2hora, t2minuto, t2segundo);
    printf("El resultado es %li", resultado);
    return 0;
}

long segundos( int t1hora, int t1minuto, int t1segundo, int t2hora, int t2minuto, int t2segundo){
    int tiempo1, tiempo2, temp;
    t1hora *= (60 * 60);
    t1minuto *= 60;
    tiempo1 = t1hora + t1minuto + t1segundo;
    t2hora*= (60 * 60); 
    t2minuto *= 60;
    tiempo2 = t2hora + t2minuto + t2segundo;
    if(tiempo2 > tiempo1){
        temp = tiempo1;
        tiempo1 = tiempo2;
        tiempo2 = temp;
    }
    return tiempo1 - tiempo2;
}