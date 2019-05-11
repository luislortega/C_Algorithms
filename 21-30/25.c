#include <stdio.h>

int main(){
    char variable[10][100];

    printf("Enter Strings\n");
    for (int i = 0; i < 10 ;i++){
        scanf("%100s", variable[i]);
    }
    
    for (int j = 0; j < 10; ++j) {
        printf("\n %s",variable[j]);
    }
    return 0;
}