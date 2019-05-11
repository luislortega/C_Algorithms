/**
 * @author Luis Gerardo Leon Ortega
 * problema 13.
 */
#include<stdio.h>

int elevar(int, int);
void floatToString(float, char*, int);
void reversa(char*, int);
int enteroString(int, char[], int);

int main()
{
    char res[20];
    float n = 233.007;

    floatToString(n, res, 3);

    printf("\n\"%s\"\n", res);
    return 0;
}

/*
 * Convierte un numero entero dado a String
 */
int enteroString(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

    while (i < d){
        str[i++] = '0';
    }

    reversa(str, i);
    str[i] = '\0';
    return i;
}

/**
 * Proceso para convertir float a char
 * @params: float del valor, apuntador del char que contendra el string y la precision de decimales que tendra.
 */
void floatToString(float n, char *res, int precision)
{
    int parteEntera = (int)n; //parte entera
    float parteFloat = n - (float)parteEntera; //parte decimal

    int i = enteroString(parteEntera, res, 0);

    if (precision != 0)
    {
        res[i] = '.';
        parteFloat = parteFloat * elevar(10, precision);
        enteroString((int)parteFloat, res + i + 1, precision);
    }
}

/**
 * Saca eleva la base a x
 * @params int con la base y int x la potencia a la que se elevara
 */
int elevar(int base, int x)
{
    if (x != 0)
        return (base*elevar(base, x-1));
    else
        return 1;
}

/**
 * cambia la orientacion del numero
 * @param char* apuntador del string alamacenador, int longitud el tamaño de nuestro String invertido
 */
void reversa(char *string, int longitud)
{
    int i=0, j=longitud-1, temp;
    while (i<j)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
        i++; j--;
    }
}


