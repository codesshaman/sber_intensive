CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: build

build: strlen_tests strcmp_tests strcpy_tests

strlen_tests:
	$(CC) $(CFLAGS) -D STRLEN s21_string.c s21_string_test.c -o ../build/Quest_1

clean:
	rm -rf s21_string.o s21_string_test.o ../build/Quest_1 ../build/Quest_2 ../build/Quest_3

rebuild: clean strlen_tests strcmp_tests strcpy_tests

strcmp_tests:
	$(CC) $(CFLAGS) -D STRCMP s21_string.c s21_string_test.c -o ../build/Quest_2

strcpy_tests:
	$(CC) $(CFLAGS) -D STRCPY s21_string.c s21_string_test.c -o ../build/Quest_3