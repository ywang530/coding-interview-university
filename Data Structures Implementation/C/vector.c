#include <stdlib.h>


// typedef struct customVector vector;

typedef struct customVector{
    int size;
    int capacity;
    int* data;
}customVector;

customVector* vector_new(int capacity){
    customVector* vector = malloc(sizeof(customVector));

    vector->size=0;
    vector->capacity = capacity;
    vector->data = (int*)malloc(sizeof(int) * capacity);

    return vector;
}

int vector_size(customVector* ptr){
    return ptr->size;
}

int vector_capacity(customVector* ptr){
    return ptr->capacity;
}

void vector_delete(customVector* ptr){
    free(ptr->data);
    free(ptr);
}

int main(){
    customVector* ptr = vector_new(5);
    
    vector_delete(ptr);
} 