CC=gcc
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99

BIN= main
OBJS= main.o list-node.o

all: $(BIN)

$(BIN): $(OBJS)


clean:
	$(RM) *.o *~ $(BIN)
