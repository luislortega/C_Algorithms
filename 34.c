#include<stdio.h>

int main(){
    char variable[100];
    char palabra[10];
    /* testing with paragraph */
    scanf("%99[^\n]", variable);
    printf("%s", variable);
    printf("\n prueba: %c", variable[1]);
    /* testing with words */
    scanf("%s", palabra);
    printf("%c", palabra[1]);
    return 0;
}