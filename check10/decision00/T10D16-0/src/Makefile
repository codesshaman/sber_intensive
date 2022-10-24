all: strlen_tests strcmp_tests strcpy_tests

strlen_tests: s21_string.o
	gcc s21_string.c s21_string_test.c -D LEN -o ../build/Quest_1

strcmp_tests: s21_string.o
	gcc s21_string.c s21_string_test.c -D CMP -o ../build/Quest_2

strcpy_tests: s21_string.o
	gcc s21_string.c s21_string_test.c -D CPY -o ../build/Quest_3

s21_string.o: s21_string.c
	gcc -c -Wall -Werror -Wextra s21_string.c
	
s21_string_test.o:  s21_string_test.c
	gcc -c -Wall -Werror -Wextra s21_string_test.c

clean: cleantest cleanbuild

cleantest:
	rm -rf *.o

cleanbuild:
	rm -rf ../build/*

rebuild: clean all