TARGET = app
CC = gcc
CFLAGS = -Wall
INCLUDE_DIRS = -I./include
SOURCES = main.c ./src/stack.c ./src/listColors.c
HEADERS = ./include/stack.h ./include/listColors.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean
