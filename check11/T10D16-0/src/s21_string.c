#include "s21_string.h"

int strlen(s) { 
    char s[];
    int length = 0;
    for(; s[length] != '\0'; length++);
    return (length);
   }