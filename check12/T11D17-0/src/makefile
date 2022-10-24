all: door_struct

door_struct: dmanager_module.o
	gcc dmanager_module.o -o ../build/Quest_1

dmanager_module.o: dmanager_module.c
	gcc -c -Wall -Wextra -Werror dmanager_module.c

rebuild: clean all

clean:
	rm -f *.o*~