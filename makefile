# All Targets
BIN=./bin/
SOURCE=./src/
INCLUDE=./include/

CFLAGS=-g -Wall -ansi -pedantic -c
C=-g -Wall -o

all: myHashTable

myHashTable: hashtable.o main.o
	@gcc $(C) myHashTable $(BIN)/hashtable.o $(BIN)/main.o

main.o: $(SOURCE)/main.c
	@gcc $(CFLAGS) $(SOURCE)/main.c -o $(BIN)/main.o

hashtable.o: $(SOURCE)/hashtable.c $(INCLUDE)/hashtable.h
	@mkdir -p bin
	@gcc $(CFLAGS) $(SOURCE)/hashtable.c -o $(BIN)/hashtable.o

#tell make that "clean" is not a file name!
.PHONY: clean run debug

clean:
	@rm -vf $(BIN)/* myHashTable

run: myHashTable
	./myHashTable

debug: myHashTable
	@gdb myHashTable

memcheck: myHashTable
	valgrind --leak-check=yes ./myHashTable
