SRC := $(wildcard src/*.c)
OBJS := $(SRC:.c=.o)

# Librarys
INCLUDE := -I/usr/local/include
LDFLAGS := -L/usr/local/lib
LDLIBS := -lcurl -ljson-c

CFLAGS := -std=c99 -Wall -Wextra -Ideps

test: test.o $(OBJS)

clean:
	rm -f test test.o $(OBJS)

valgrind: test
	valgrind --leak-check=full ./$<

.PHONY: clean valgrind
