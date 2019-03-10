#include <stdio.h>

void procedimiento(char[20][100]);
void salidas(char[20][100]);

int main(){
    /* entradass */
    char people[20][100];
    /* procedimiento */
    procedimiento(people);
    /* salidas */
    salidas(people);
    return 0;
}

void procedimiento(char people[20][100]){
    for (int i = 0; i < 20 ;i++){
        printf("Ingresa el nombre[%i]: \n", i);
        scanf("%100s", people[i]); //Max size of words is 100
    }
}

void salidas(char people[20][100]){
    int busqueda = 0;
    printf("¿Que posicion deseas buscar? INDEX 0 \n");
    scanf("%i", &busqueda);
    printf("El nombre en esa posicion es: %s \n", people[busqueda]);
}
