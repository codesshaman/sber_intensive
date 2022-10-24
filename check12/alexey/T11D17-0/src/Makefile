GCC = gcc
CFLAGS = -Wall -Werror -Wextra
STRUCT_OBJ = dmanager_module.c
LIST_OBJ = list.c list_test.c
EX_PATH = ../build
I_DIR = ../

all: door_struct list_test

door_struct: $(STRUCT_OBJS)
	$(GCC) $(GGFLAGS) $(STRUCT_OBJ) -I$(I_DIR) -o $(EX_PATH)/Quest_1

list_test: $(LIST_OBJS)
	$(GCC) $(CFLAGS) $(LIST_OBJ) -D LIST_TEST -o $(EX_PATH)/Quest_2

clean:
	rm -rf *.o ../build/*

rebuild: clean all