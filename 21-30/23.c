/*!
 * @author Luis Ortega
 * hace operaciones aritmeticas con cadenas char
 */
#include <stdio.h>

char* stringOperando = "";
void entradas();
float evaluar();
void salidas(float);

/*!
 * Funcion main
 * @return 0
 */
int main(){
    entradas();
    float resultado = evaluar();
    salidas(resultado);
    return 0;
}

/*!
 * Entrada de valores
 */
void entradas(){
    printf("Ingresa una operacion aritmetica");
    scanf("%s", stringOperando);
}

/*!
 * Obtiene el numero a evaluar, si es una operacion anidada o es una operacion iniciada como negativo
 * @return profundidad de la anidacion || operaciones profundad || valor negativo en caos de serlo
 */
float obtenerValores(){
    if (*stringOperando >= '0' && *stringOperando <= '9'){
        int numero = *stringOperando++-'0';
        while (*stringOperando >= '0' && *stringOperando <= '9'){
            numero = 10 * numero + *stringOperando++ - '0';
            printf("Concatenando los valores: %i \n", numero);
        }
        printf("Valor numerico: %i \n", numero);
        return numero; //59
    }
    else if (*stringOperando == '('){
        stringOperando++;
        float aritmeticaxProfundidad = evaluar(); //Operaciones profundas
        stringOperando++;
        printf("Valores dentro de la profundidad: %f \n", aritmeticaxProfundidad);
        return aritmeticaxProfundidad;
    }
    else if (*stringOperando == '-'){
        stringOperando++;
        printf("Valor negativo devuelto: %f \n", -obtenerValores());
        return -obtenerValores();
    }
    // ya no tenemos que evaluar
    return 0;
}

/*!
 * Hace las operaciones de prioridad
 * @return nuestra operacion de prioridad
 */
float prioridad(){
    float valor = obtenerValores();
    /*!
     * Es un while para ir comprobando signos continuos
     */
    while (*stringOperando== '*' || *stringOperando == '/'){
        valor = (*stringOperando++ == '*')? valor * obtenerValores() : valor / obtenerValores();
    }
    return valor;
}

/*!
 * Evalua una expresion aritmetica en String
 * @return resultado de la operacion
 */
float evaluar(){
    float resultado = prioridad();
    printf("Prioridad: %f \n", resultado);
    /*!
     * Es un while para ir comprobando signos continuos
     */
    while (*stringOperando == '+' || *stringOperando == '-'){
        resultado = (*stringOperando++ == '+') ? resultado + prioridad(): resultado - prioridad();
    }
    return resultado;
}

/*!
 * Imprime el resultado
 * @param resultado
 */
void salidas(float resultado){
    printf("Resultado %f", resultado);
}