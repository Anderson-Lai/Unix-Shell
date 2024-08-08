#include "str.h"
#include <stdio.h>

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
