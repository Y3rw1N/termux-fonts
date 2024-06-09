CC = gcc
SRCS = $(wildcard src/*c)
CFLAGS = -Wall -Wextra -o
BIN_DIR = bin
BIN_NAME = termux-font
TARGET = $(BIN_DIR)/$(BIN_NAME)
LIBS = -lcurl

all: $(TARGET)

$(TARGET):
	@mkdir -p $(BIN_DIR) || true
	$(CC) $(CFLAGS) $(TARGET) $(SRCS) $(LIBS)

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean