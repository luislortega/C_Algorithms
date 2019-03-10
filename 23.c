/**
 * @author Luis Ortega
 *
 *  FUCNIONA DE FORMA RECURSIVA PARA LOS OBJETOS ANIDADOS DE FORMA (A+B*(B-A*(A-B)))
 *
 * #NOEXAMENPARCIAL
 */
#include <stdio.h>

char* stringOperando = "";
void entradas();
float evaluar();
void salidas(float);

int main(){
    /* entradas */
    entradas();
    /* proceso */
    float resultado = evaluar();
    /* salidas */
    salidas(resultado);
    return 0;
}

/**
 * Entradas
 */
void entradas(){
    printf("Ingresa una operacion aritmetica");
    scanf("%s", stringOperando);
}

/**
 * Operacion profunda
 * @return profundidad de la anidacion || valor anidado || valor negativo en caos de serlo
 */
float operacion(){
    if (*stringOperando >= '0' && *stringOperando <= '9'){
        int operando = *stringOperando++-'0';
        while (*stringOperando >= '0' && *stringOperando <= '9'){
            operando= 10 * operando+ *stringOperando++ - '0';
        }
        return operando; //Si se puede evaluar los valores para ser evaluados
    }
    else if (*stringOperando == '('){
        /*
         * Extraemos los valores adentro de los corchetes '( A+B )'
         */
        stringOperando++;
        float anidado= evaluar();
        stringOperando++;
        return anidado;
    }
    else if (*stringOperando == '-'){
        /*
         * Retornamos el valor negativo
         */
        stringOperando++;
        return -operacion();
    }
    /*
     * En caso de que ya no hayan operaciones
     */
    return 0;
}

/**
 * Hace las operaciones de primer rango
 * @return nuestra operacion de primer rango
 */
float primerRango(){
    //Sacamos el char a evaluar, podria ser un numero 0..9, valores anidados entre parentesis o un numero negatico
    float primerRango = operacion();
    while (*stringOperando== '*' || *stringOperando == '/'){
        /*
         * Cuando se hace una operacion basica igual se revisa que su operacion no contenga una operacion
         * de mayor rango
         *
         * EJEMPLO:
         *
         * 5*(2*2) || 5 / (2+3)
         */
        primerRango = (*stringOperando++ == '*')? primerRango * operacion() : primerRango / operacion();
    }
    return primerRango;
}

/**
 * Evalua nuestra operacion aritmetica
 * @return resultado de la operacion aritmetica
 */
float evaluar(){
    /*
     * Revisamos si nuestra operacion tiene una operacion de primer rango
     * que serian la multiplicacion o division.
     */
    float resultado = primerRango();
    //Mientras ya no tengamos operaciones aritmeticas basicas.
    while (*stringOperando == '+' || *stringOperando == '-'){
        /*
         * Cuando se hace una operacion basica igual se revisa que su operacion no contenga una operacion
         * de mayor rango
         *
         * EJEMPLO:
         *
         * 5+(2*2) || 5 - (2+3)
         */
        resultado = (*stringOperando++ == '+')? resultado + primerRango(): resultado - primerRango();
    }
    return resultado;
}

void salidas(float resultado){
    printf("Resultado %f", resultado);
}