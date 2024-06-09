CC = gcc
SRCS = $(wildcard src/*c)
CFLAGS = -Wall -Wextra -o
BIN_DIR = bin
BIN_NAME = termux-font
LIBS = -lcurl

$(BIN_DIR):
	mkdir -p $@

default:
	$(CC) $(SRCS) $(CFLAGS) $(BIN_DIR)$(BIN_NAME) $(LIBS)

clean:
	rm $(BIN_DIR)
	
run: $(BIN_DIR)$(BIN_NAME)
	./$<

.PHONY: clean run