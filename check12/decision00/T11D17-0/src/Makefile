all: door_struct

door_struct: dmanager_module.o
	gcc -Wall -Werror -Wextra dmanager_module.o -o ../build/Quest_1

dmanager_module.o: dmanager_module.c
	gcc -c -Wall -Werror -Wextra dmanager_module.c 

clean: 
	rm *.o
	rm ../build/Quest_*

rebuild: clean all