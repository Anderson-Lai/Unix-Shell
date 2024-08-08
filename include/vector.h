#ifndef VECTOR
#define VECTOR

#include <stddef.h>

typedef struct vector vector;
typedef vector* Vector;

Vector vector_create(size_t size);
void vector_delete(Vector* vec);

void vector_push_back(Vector* vec, void* value);
void vector_pop_back(Vector* vec);

void* vector_at(Vector vec, size_t index);
size_t vector_size(Vector vec);

#endif
