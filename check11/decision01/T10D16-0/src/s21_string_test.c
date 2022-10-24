//  Copyright 2022 Evelyne Aristotle
#include "./s21_string.h"

int main() {
    printf("Select:\n1 test normal\n2 test abnormal\n3 test boundary\n");
    int test;
    scanf("%d", &test);
#ifdef STRLEN
    char *str = NULL;
    switch (test) {
        case 1:
            str = "Thisisthetest";
            break;
        case 2:
            str = "Thisisthetestthetesttesttesttest";
            break;
        case 3:
            str = "Thisisthetestthetestt";
            break;
    }
    unsigned long count = s21_strlen_test(str);
    printf("%s \n", str);
    printf("%zu \n", count);
    if (count > 0 && count <= 21)
        printf("SUCCESS");
    else
        printf("FAIL");
#endif

#ifdef STRCMP
    char *str1 = NULL;
    char *str2 = NULL;
    switch (test) {
        case 1:
            str1 = "Thisisthetest";
            str2 = "Thisisthetest";
            break;
        case 2:
            str1 = "Thisisthetestthetesttesttesttest";
            str2 = "Thisisthete";
            break;
        case 3:
            str1 = "Thisisthetestthetestt";
            str2 = "\0";
            break;
    }
    unsigned long count = s21_strcmp_test(str1, str2);
    printf("%s %s", str1, str2);
            printf("%zu \n", count);
    if (count == 0)
        printf("SUCCESS");
    else
        printf("FAIL");
#endif

#ifdef STRCPY
    char *str1 = NULL;
    char *str2 = NULL;
    switch (test) {
        case 1:
            str1 = "T\0";
            str2 = "T\0";
            break;
        case 2:
            str1 = "\0";
            str2 = "Thisisthetest\0";
            break;
        case 3:
            str1 = "\0";
            str2 = "\0";
            break;
    }
    printf("%s\n", str1);
    printf("%s\n", str2);
    s21_strcpy_test(str1, str2);
    printf("%s \n", str2);
    if (*str2 == *str1)
        printf("SUCCESS");
    else
        printf("FAIL");
#endif
}
