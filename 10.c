#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<float.h>

static void print_ipart(long double x) {
    int digit = (int) (modfl(x/2, &x)*2.0) + '0';
    if (x) {
        print_ipart(x);
    }
    putchar(digit);
}

void print_bin(long double x) {
    // Some TBD code
    // Handle NAN with isnan()
    // Handle infinity with isfinite()

    putchar(signbit(x) ? '-' : '+');

    long double ipart;
    long double fpart = modfl(fabsl(x), &ipart);

    print_ipart(ipart);
    putchar('.');
    while (fpart) {
        long double ipart;
        fpart = modfl(fpart * 2, &ipart);
        putchar((int)ipart + '0');
    }
    putchar('\n');
}

int main() {
    print_bin(1.25);
    print_bin(.575);
}