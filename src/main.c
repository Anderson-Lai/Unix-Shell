#include "parse.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

#define DEBUG_STRING

#ifdef DEBUG_VECTOR
#include "vector.h"
#include <stdlib.h>

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

#elif defined(DEBUG_STRING)
#include "str.h"

int main(int argc, char** argv) {
    
    String str = string_create("i want to fly");
    string_append(&str, " no you can't");
    
    string_print(str);
    
    string_pop_back(&str);
    string_pop_back(&str);
    string_pop_back(&str);
    string_pop_back(&str);
    string_pop_back(&str);

    printf("%c\n", *string_at(str, 2));
    printf("%zu\n", string_size(str));
    string_print(str);

    string_append(&str, " abcd\n");
    string_print(str);

    string_delete(&str);
    return 0;
}

#else

int main(int argc, char** argv) {

    printf("This is an implementation of a Unix shell in C\n");
    
    char buffer[BUFFER_SIZE] = {};
    
    while (1) {
        printf("> $ ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        if (parse_buffer(buffer)) 
            break;

        memset(buffer, '\0', BUFFER_SIZE);
    }
    
    printf("Exiting shell\n");

    return 0;
}
#endif

