CC = gcc

CFLAGS = -Wall -Wextra -Werror -O0 -g -std=c11 -I..
LDFLAGS = -lm

.PHONY: all grade cache clean

all: cache clean

cache:
	$(CC) *.c	 $(CFLAGS) $(LDFLAGS) -o cache
	- ./cache

clean:
	rm -f *.o cache
