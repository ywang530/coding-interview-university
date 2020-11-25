// Implement a vector (mutable array with automatic resizing):

// typedef struct customArray Array;
typedef struct customArray{
    int size;
    int capacity;
    int* data;
}Array;

/* Arracy functions */

Array* array_new(int capacity);

void array_destroy(Array *ptr);

// size() - number of items
int array_szie(Array *ptr);

// capacity() - number of items it can hold
int array_capacity(Array *prt);

// is_empty()
int array_is_empty(Array *ptr);

// at(index) - returns item at given index, 
// blows up if index out of bounds push(item)
int array_at(Array *ptr, int idx);

// insert(index, item) - inserts item at index, 
// shifts that index's value and trailing elements to the right
void array_insert(Array *ptr, int idx, int val);

// prepend(item) - can use insert above at index 0
void array_prepend(Array *ptr, int val);

// pop() - remove from end, return value
int array_pop(Array *ptr);

// delete(index) - delete item at index, 
// shifting all trailing elements left
void array_delete(Array *ptr, int idx);

// remove(item) - looks for value and 
// removes index holding it (even if in multiple places)
void array_remove(Array *ptr, int val);

// find(item) - looks for value and 
// returns first index with that value, -1 if not found
int array_find(Array *ptr, int val);

// resize(new_capacity) // private function
// when you reach capacity, resize to double the size
// when popping an item, if size is 1/4 of capacity, resize to half
void array_resize(Array *prt, int new_capacity);