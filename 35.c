#include <stdio.h>

#define N 4

void buscarModas(int*);
int main()
{
    int a[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    buscarModas(a);
    return 0;
}

void buscarModas(int* a){
    int b[N] = {0}, k = 0, c = 1, max = 0, mode;
    printf("Ingresando numeros\n");
    for (int i = 0; i < N - 1; i++){
        mode = 0;
        for (int j = i + 1; j < N; j++){
            if (a[i] == a[j]) {
                mode++;
            }
        }
        if ((mode > max) && (mode != 0)) {
            k = 0;
            max = mode;
            b[k] = a[i];
        }else if (mode == max) {
            b[k] = a[i];
        }
        k++;
    }
    for (int i = 0; i < N; i++){
        if (a[i] == b[i]){
            c++;
        }
    }
    if (c == N){
        printf("\nModas\t= ");
        for (int l = 0; l <= k; ++l) {
            printf("%i", a[l]);
        }
    }else
    {
        printf("\nModas\t= ");
        for (int i = 0; i < k; i++){
            if(b[i] != b[i+1]){
                printf("%i \n",b[i]);
            }
        }
    }
    printf("\n");
}