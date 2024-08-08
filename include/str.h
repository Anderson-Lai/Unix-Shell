#ifndef STRING
#define STRING

#include <stddef.h>

typedef struct string string;
typedef string* String;

String string_create(const char* str);
void string_delete(String* str);

void string_append(String* str, const char* text);
void string_pop_back(String* str);

char* string_at(String str, size_t index);
size_t string_size(String str);

void string_print(String str);

#endif
