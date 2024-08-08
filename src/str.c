#include "str.h"
#include "vector.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct string {
    char* str;
    size_t length;
    size_t capacity;
};

String string_create(const char* str) {
    size_t string_length = strlen(str);
    
    string* s = (string*)malloc(sizeof(string));
    if (!s)
        return NULL;
    
    s->str = strdup(str);
    if (!s->str) {
        free(s);
        return NULL;
    }

    s->length = string_length;
    s->capacity = string_length;
    return s;
}

void string_delete(String* str) {
    
    char* str_array = (*str)->str;
    free(str_array);
    str_array = NULL;

    free(*str);
    *str = NULL;
}

void string_append(String* str, const char* text) {
    size_t size = (*str)->length;
    size_t capacity = (*str)->capacity;
    size_t str_length = strlen(text);

    if (size + str_length > capacity) {
        char* new_str = (char*)realloc((*str)->str, (size + str_length) * 2);
        if (!new_str)
            return;
        
        (*str)->str = new_str;
        (*str)->capacity = (size + str_length) * 2;
    }
    
    (*str)->length = size + str_length;
    strcat((*str)->str, text);
}

void string_pop_back(String* str) {
    size_t size = (*str)->length--;

    (*str)->str[size - 1] = '\0';
}

char* string_at(String str, size_t index) {
    return &(str->str[index]);
}

size_t string_size(String str) {
    return str->length;
}

void string_print(String str) {
    printf("%s\n", str->str);
}
