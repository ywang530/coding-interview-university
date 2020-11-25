#include <stdlib.h>
#include <stdio.h>
#include "Array.h"
// Implement a vector (mutable array with automatic resizing):


Array* array_new(int capacity){
    Array* array = malloc(sizeof(Array));
    array->size=0;
    array->capacity = capacity;
    int* data = (int*)malloc(sizeof(int) * capacity);
    array->data = data;

    return array;
}

void array_destroy(Array *ptr){
    free(ptr->data);
    free(ptr);
}

int array_size(Array *ptr){
    int size = ptr != NULL ? ptr->size : 0;
    return size;
}

int array_capacity(Array *ptr){
    int capacity = ptr != NULL ? ptr->capacity : 0;
    return capacity;
}

int array_is_empty(Array *ptr){
    int empty = ptr != NULL ? ptr->size == 0 : 1;
    return empty;
}

int array_at(Array *ptr, int idx){
    if(ptr != NULL){
        if(idx < 0 || idx >= ptr->size){
            exit(EXIT_FAILURE);
        }
        else{
            return *(ptr->data+idx);
        }
    }
    return 0;
}


void array_insert(Array *ptr, int idx, int val){
    if(ptr != NULL){
        if(idx < 0 || idx >= ptr->size){
            exit(EXIT_FAILURE);
        }
        else{
            // check if need to resize
            array_resize(ptr, ptr->size+1);
            // shift items to the right
            // memove(str1, str2, # bytes)
            // str1 - a pointer to the destination array where the content is to be copied, 
            // str2 - a pointer to the source of data to be copied
            memove(ptr->data+idx+1, ptr->data+idx, sizeof(int) * (ptr->size-idx));
            *(ptr->data+idx) = val;
            ptr->size += 1;
        }
    }
    return 0;
}



void array_resize(Array *ptr, int new_capacity){
    if(ptr->size < new_capacity){
        // reach capacity, resize to double the size
        if(ptr->size == ptr->capacity){
            ptr->capacity = 2*ptr->capacity;
            ptr->data = (int*) realloc(ptr->data, sizeof(int) * ptr->capacity);
        }
    }
    else if(ptr->size > new_capacity){
        // size is 1/4 of capacity, resize to half
        if(ptr->size <= (ptr->capacity/4)){
            ptr->capacity = ptr->capacity/2;
            ptr->data = (int*) realloc(ptr->data, sizeof(int) * ptr->capacity);
        }
        
    } 
}


void array_prepend(Array *ptr, int val){
    array_insert(ptr, 0, val);
}


int array_pop(Array *ptr){
    if(ptr != NULL){
        if (ptr->size == 0)
        {
            exit(EXIT_FAILURE);;
        }
        else
        {
            array_resize(ptr, ptr->size-1);
            int pop_value = *(ptr->data + ptr->size-1);
            ptr->size -= 1;
            return pop_value;
        }
        return 0;
    }
}

void array_delete(Array *ptr, int idx){
    if(ptr != NULL){
        if(idx < 0 || idx >= ptr->size){
            exit(EXIT_FAILURE);
        }
        else{
            // check if need to resize
            array_resize(ptr, ptr->size-1);
            // shift items to the left
            // memove(str1, str2, # bytes)
            // str1 - a pointer to the destination array where the content is to be copied, 
            // str2 - a pointer to the source of data to be copied
            memove(ptr->data+idx, ptr->data+idx+1, sizeof(int) * (ptr->size-idx));
            ptr->size -= 1;
        }
    }
    return 0;
}

void array_remove(Array *ptr, int val){
    for(int i=0; i<ptr->size; i++){
        if(*(ptr->data+i) == val){
            array_delete(ptr, i);
            ptr->size -= 1;
            break;
        }
    }
}

int array_find(Array *ptr, int val){
    for (int i = 0; i < ptr->size; i++){
        if(*(ptr->data+i) == val){
            return i;
        }
    }
    return -1;
}