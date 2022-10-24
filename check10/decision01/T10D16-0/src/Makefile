all:

rebuild: clean

s21_string.o: ./s21_string.c
	gcc -c -std=c11 -Wall -Werror -Wextra s21_string.c -o s21_string.o

s21_string_test.o: ./s21_string_test.c
	gcc -c -std=c11 -Wall -Werror -Wextra -DLEN s21_string_test.c -o s21_string_test.o

strlen_tests: s21_string.o s21_string_test.o
	gcc s21_string.o s21_string_test.o -o ../build/Quest_1

clean: clean_b clean_l

clean_l:
	rm -rf ./*.o

clean_b:
	rm -rf ../build/*
