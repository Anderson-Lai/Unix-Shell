#include <stdio.h>
#include <string.h>
#include "parse_buffer.h"

#define BUFFER_SIZE 1024

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
