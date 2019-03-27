#include <stdio.h>

#define N 5

void printStars();

int main(){
    printStars();
}

void printStars(){
    int par = 0;
    for (int i = 1; i <= N/2; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
    if(N % 2 != 0){
        par = 1;
    }
    for (int i = (N/2)+par; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

