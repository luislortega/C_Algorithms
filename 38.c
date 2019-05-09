#include <stdio.h>
#include<stdlib.h>

/**
 * The basics of a REALLY SIMPLE - Linked list
 *
 * A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations.
 * The elements in a linked list are linked using pointers.
 */
struct Node{
    int data;
    struct Node *next;
};

int main()
{
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1; //assign data in first node
    head->next = NULL; // Link first node with

    return 0;
}
