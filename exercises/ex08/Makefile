CC = gcc
CFLAGS = -g -std=c11 -Wall -Wextra -pedantic $(shell pkg-config --cflags glib-2.0)
LIBS = $(shell pkg-config --libs glib-2.0)

.PHONY: all

all: ex_compile word_count

ex_compile: ex_compile.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

word_count: word_count.o
	$(CC) $(CFLAGS) $< -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
	rm -f ex_compile
	rm -f word_count
