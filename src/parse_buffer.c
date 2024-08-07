#include "parse_buffer.h"
#include "shell.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int parse_buffer(char* buffer) {
    char* cleaned = clean_buffer(buffer);
    
    printf("%s\n", cleaned);
    size_t length = strlen(cleaned);
    if (isspace((unsigned int)cleaned[length - 1]))
        printf("Improper parsing, the command has terminating whitespace\n");

    return shell_parse_buffer(cleaned);
}

char* clean_buffer(char* buffer) {
    size_t length = strlen(buffer);
    
    char* cleaned = (char*)calloc(BUFFER_SIZE, sizeof(char));

    size_t start = 0;
    size_t end = length - 1;

    while (isspace((unsigned int)buffer[start])) {
        start++;
    }

    while (isspace((unsigned int)buffer[end])) {
        end--;
    }

    strncpy(cleaned, &(buffer[start]), end - start + 1);

    return cleaned;
}
