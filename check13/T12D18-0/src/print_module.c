#include <stdio.h>

#include "print_module.h"

int print_char(char ch) 
{
    return putchar(ch);
}

void print_log(char (*print) (char), char* message) {
    while ("massage != '\0') {
        print(*massage);
        massage++;
    }
}