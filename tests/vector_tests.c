#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    Vector vec = vector_create(1);

    void* first = malloc(sizeof(int));
    void* second = malloc(sizeof(int));
    void* third = malloc(sizeof(int));
    void* fourth = malloc(sizeof(int));
    void* fifth = malloc(sizeof(int));
    void* sixth = malloc(sizeof(int));
    void* seventh = malloc(sizeof(int));

    *(int*)first = 3;
    *(int*)second = 0;
    *(int*)third = -4;
    *(int*)fourth = 4;
    *(int*)fifth = 9;
    *(int*)sixth = -10;
    *(int*)seventh = -2;

    vector_push_back(&vec, first);
    vector_push_back(&vec, second);
    vector_push_back(&vec, third);
    vector_push_back(&vec, fourth);
    vector_push_back(&vec, fifth);
    vector_push_back(&vec, sixth);
    vector_push_back(&vec, seventh);

    for (size_t i = 0; i < vector_size(vec); i++) {
        printf("%d\n", *(int*)vector_at(vec, i));
    }

    vector_pop_back(&vec);
    vector_pop_back(&vec);
    vector_pop_back(&vec);
    vector_pop_back(&vec);

    for (size_t i = 0; i < vector_size(vec); i++) {
        printf("%d\n", *(int*)vector_at(vec, i));
    }

    vector_delete(&vec);

    return 0;
}

