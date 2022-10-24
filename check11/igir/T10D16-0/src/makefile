CC = gcc
CFLAGS = -Wall -Wextra -Werror

TEST = s21_string_test.c
STRING = s21_string.c

all: strlen_tests strlen_tests

strlen_tests: $(TEST) $(STRING)
	$(CC) $(CFLAGS) -D strlen_tests $(TEST) $(STRING) -o ../build/Quest_1

strcmp_tests: $(TEST) $(STRING)
	$(CC) $(CFLAGS) -D strcmp_tests $(TEST) $(STRING) -o ../build/Quest_2
	
strcpy_tests: $(TEST) $(STRING)
	$(CC) $(CFLAGS) -D strcpy_tests $(TEST) $(STRING) -o ../build/Quest_3
