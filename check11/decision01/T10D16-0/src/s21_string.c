//  Copyright 2022 Evelyne Aristotle
# include "./s21_string.h"

size_t s21_strlen_test(const char * str) {
    size_t length = 0;
    for (; *(str + length); length ++)
        continue;
    return length;
}

int s21_strcmp_test(char *str1, char *str2) {
    for (; *str1 && *str1 == *str2; str1++, str2++)
    {};
    return *str1 - *str2;
}

char s21_strcpy_test(char *str1, char *str2) {
    while (*str1 != '\0') {
    *str2++ = *str1++;
    }
    return *str2;
}
