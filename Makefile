CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb

heap: heap.c
	$(CC) $(CFLAGS) -o heap heap.c
