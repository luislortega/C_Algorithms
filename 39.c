/**
 * f you need a dynamic array, you can't escape pointers. Why are you afraid though? They won't bite (as long as you're careful, that is).
 * There's no built-in dynamic array in C, you'll just have to write one yourself. In C++, you can use the built-in std::vector class.
 * C# and just about every other high-level language also have some similar class that manages dynamic arrays for you.
 * If you do plan to write your own, here's something to get you started: most dynamic array implementations work by starting off with an array of some (small) default size, then whenever you run out of space when adding a new element, double the size of the array.
 * As you can see in the example below, it's not very difficult at all: (I've omitted safety checks for brevity)
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    size_t used;
    size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
    a->array = (int *)malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(Array *a, int element) {
    // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // Therefore a->used can go up to a->size
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (int *)realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int main(){
    Array a;
    int i;

    initArray(&a, 5);  // initially 5 elements
    for (i = 0; i < 100; i++)
        insertArray(&a, i);  // automatically resizes as necessary
    printf("%d\n", a.array[9]);  // print 10th element
    printf("%d\n", a.used);  // print number of elements
    freeArray(&a);
}
