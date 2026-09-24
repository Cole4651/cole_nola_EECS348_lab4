CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic
TARGET = task1

.PHONY: all clean

all: $(TARGET)

$(TARGET): task1.c
	$(CC) $(CFLAGS) task1.c -o $(TARGET)

clean:
	rm -f $(TARGET)