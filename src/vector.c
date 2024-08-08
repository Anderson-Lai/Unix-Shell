#include "vector.h"
#include <stdlib.h>

struct vector {
    void** array;
    size_t length;
    size_t capacity;
};

Vector vector_create(size_t size) {
    size = size ? size : 1;

    vector* vec = (vector*)malloc(sizeof(vector));
    if (!vec)
        return NULL;

    vec->array = (void**)calloc(size, sizeof(void*));
    if (!vec->array) {
        free(vec);
        return NULL;
    }

    vec->length = 0;
    vec->capacity = size;

    return vec;
}

void vector_delete(Vector* vec) {
    size_t size = (*vec)->length; 

    for (size_t i = 0; i < size; i++) {
        void* element = (*vec)->array[i];
        free(element);
        element = NULL;
    }
    
    free((*vec)->array);
    (*vec)->array = NULL;

    free(*vec);
    *vec = NULL;
}

void vector_push_back(Vector* vec, void* value) {
    size_t size = (*vec)->length;
    size_t capacity = (*vec)->capacity;

    if (size >= capacity) {
        // reallocation needed
        
        void** new_array = (void**)realloc((*vec)->array, (size ? size : 1) * 2 * sizeof(void*));
        if (!new_array)
            return;

        (*vec)->array = new_array;
        (*vec)->capacity = size * 2;
    }

    (*vec)->array[size] = value;
    (*vec)->length = size + 1;
}

void vector_pop_back(Vector* vec) {
    size_t size = (*vec)->length--;

    void* element = (*vec)->array[size - 1];
    free(element);
    element = NULL;
}

void* vector_at(Vector vec, size_t index) {
    return vec->array[index];
}

size_t vector_size(Vector vec) {
    return vec->length;
}
