# -g includes extra debugging info, -Wall gives possible warnings in src code.
C_FLAGS = -g -Wall

trout: main.c trout.o util.o
	gcc $(C_FLAGS) main.c trout.o util.o -o trout



trout.o: trout.c util.c
	gcc $(C_FLAGS) -g trout.c -c -o trout.o

util.o: trout.c util.c
	gcc $(C_FLAGS) -g util.c -c -o util.o
