#include <stdlib.h>
#include <stdio.h>

/*  Vector/Arracy */
typedef struct customVector
{
    int* data;
    int capacity;
    int size;
}vector;

/* Single Linked List */
typedef struct customNode
{
    int value;
    node* next;
}node;

/* Stack */
typedef struct customStack
{
    int top;
    int capacity;
    int* array;
}stack;


/* Queue */
typedef struct customNode
{
    int value;
    node* next;
}node;

typedef struct customQueue
{
    int data;
    node* tail;
    node* head;
}queue;


