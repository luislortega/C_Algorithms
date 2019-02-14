/**
 * @author Luis Gerardo Leon Ortega
 * @ejercicio: 14
 */
#include <stdio.h>

int esRectangulo(float, float, float);
int esEquilatero(float, float, float);
int esTriangulo(float, float, float);
int tieneAngulosAgudos(float, float, float);

int main() {
    //pdf examples test
    printf("Pdf examples test: \n");
    printf("%i \n", esRectangulo(4,3,5));
    printf("%i \n", esRectangulo(8,1,6));
    printf("%i \n", esRectangulo(1,1, 1.414));
    printf("%i \n", esRectangulo(8.5,3.4, 9.154));

    //Correct test
    printf("Correct test \n");
    printf("%i \n", esRectangulo(17,8,15));
    printf("%i \n", esRectangulo(6.1,18, 19));
    printf("%i \n", esRectangulo(3,5,4));
    printf("%i \n", esRectangulo(4.5,2,4));

    //Error test
    printf("Error test: \n");
    printf("%i \n", esRectangulo(5,5,5));
    printf("%i \n", esRectangulo(1,8,6));
    printf("%i \n", esRectangulo(12,5,12));
    printf("%i \n", esRectangulo(8,8,1));
    return 0;
}

int esRectangulo(float a, float b, float c){
    int resultado = 0;
    //Demuestra que es un triangulo y no es equilatero, adentro verifica que tenga angulos agudos.
    if(esTriangulo(a,b,c) && !esEquilatero(a,b,c)){
        if(a > b && a > c){
            if(tieneAngulosAgudos(b,c,a)){
                resultado = 1;
            }
        }else if(b > c){
            if(tieneAngulosAgudos(a,c,b)){
                resultado = 1;
            }
        }else{
            if(tieneAngulosAgudos(a,b,c)){
                resultado = 1;
            }
        }
    }
    return resultado;
}


int tieneAngulosAgudos(float a, float b, float c){
    return (( a/c < 1) && (b/c < 1)) ? 1 : 0;
}

int esEquilatero(float a, float b, float c){
    return (a==b && a==c && c==b) ? 1 : 0;
}

int esTriangulo(float a, float b, float c){
    return ((a+b > c) && (a+c > b) && (b+c > a) ) ? 1 : 0;
}