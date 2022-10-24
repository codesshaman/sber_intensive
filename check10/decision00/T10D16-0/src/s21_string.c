#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

int s21_strlen(const char* str) {
    int length = 0;
    for ( ; *(str + length); length++)
    {};
    return length;
}

int s21_strcmp(char *str1, char *str2) {
    for ( ; *str1 && *str1 == *str2; str1++, str2++)
    {};
    return *str1 - *str2;
}

char s21_strcpy(char *dest, char *str) {
while ('\0' != *str)
       *dest++ = *str++;
    *dest++ = '\0';
    return *dest;
}
