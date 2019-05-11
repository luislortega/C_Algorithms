/**
 * @author: Luis Gerardo Leon Ortega
 * @param check if the var n is a palindrome
 */
#include <stdio.h>

int main() {
    int n, reverse = 0, t;

    scanf("%d", &n);

    t = n;

    while (t != 0)
    {
        reverse = reverse * 10;
        reverse = reverse + t % 10;
        t = t/10;
    }

    if (n == reverse)
        printf("%d is a palindrome number.\n", n);
    else
        printf("%d isn't a palindrome number.\n", n);
    return 0;
}

