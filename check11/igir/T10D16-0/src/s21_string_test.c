#include <stdio.h>
#include <stdlib.h>
#include "s21_string.h"

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();

int main() {
    #ifdef strlen_tests
    s21_strlen_test();
    #elif strcmp_tests
    s21_strcmp_test();
    #elif strcpy_tests
    s21_strcpy_test();
    #endif
    /*#endif
    #endif
    #endif
    #endif
    #endif*/
}

void s21_strlen_test() {
      const char str[] = "";
      const char str2[] = "qwertyuiopasdfghjklz";
      const char str3[] = "ячсмитьбю";

      printf("Test_Input_1: %s\n", str);
      int res1 = s21_strlen(str);
      printf("Output: %d\n", res1);
      if (res1 == 0)
            printf("SUCCESS\n");
      else
            printf("FAIL\n");

      printf("Test_Input_2: %s\n", str2);
      int res2 = s21_strlen(str2);
      printf("Output: %d\n", res2);
      if (res2 != 25)
            printf("SUCCESS\n");
      else
            printf("FAIL\n");

      printf("Test_Input_2: %s\n", str3);
      int res3 = s21_strlen(str3);
      printf("Output: %d\n", res3);
      if (res3 == 9)
            printf("SUCCESS");
      else
            printf("FAIL");
}

void s21_strcmp_test() {
      char str1[] = "", str2[] = "1";
      char str3[] = "1234567890", str4[] = "1234567890";
      char str5[] = "abrakadabra", str6[] = "abrakada";

      printf("Test_Input_1: %s, %s\n", str1, str2);
      int res1 = s21_strcmp(str1, str2);
      printf("Output: %d\n", res1);
      if (res1 < 0)
            printf("SUCCESS\n");
      else
            printf("FAIL\n");

      printf("Test_Input_1: %s, %s\n", str3, str4);
      int res2 = s21_strcmp(str3, str4);
      printf("Output: %d\n", res2);
      if (res2 == 0)
            printf("SUCCESS\n");
      else
            printf("FAIL\n");

      printf("Test_Input_1: %s, %s\n", str5, str6);
      int res3 = s21_strcmp(str5, str6);
      printf("Output: %d\n", res3);
      if (res3 > 0)
            printf("SUCCESS");
      else
            printf("FAIL");
}

void s21_strcpy_test() {
      const char str1[] = "1", str3[] = "ALAKAZAM", str5[] = "";
      char str2[5], str4[12], str6[0];

      printf("Test_Input_1: %s, %s\n", str1, str2);
      int res1 = s21_strcpy(str2, str1);
      printf("Output: %d\n", res1);
      printf("%s\n", str2);
      if (res1 == 1)
            printf("SUCCESS\n");
      else
            printf("FAIL\n");

      printf("Test_Input_2: %s, %s\n", str3, str4);
      int res2 = s21_strcpy(str4, str3);
      printf("Output: %d\n", res2);
      printf("%s\n", str4);
      if (res2 == 1)
            printf("SUCCESS\n");
      else
            printf("FAIL\n");

      printf("Test_Input_3: %s, %s\n", str5, str6);
      int res3 = s21_strcpy(str6, str5);
      printf("Output: %d\n", res3);
      printf("%s\n", str6);
      if (res3 == 0)
            printf("SUCCESS\n");
      else
            printf("FAIL\n");
} 
