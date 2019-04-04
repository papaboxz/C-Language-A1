CC = gcc
CC_FLAGS = -g -std=c99 -pedantic -W -Wall
FILES = main.c menu.c street.c rentalProperty.c node.c
OUT_EXE = assign1
build: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)
clean:
	rm -f *.o core *.exe *~ *.out *.stackdump
rebuild:
	make clean
