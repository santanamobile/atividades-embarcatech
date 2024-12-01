CC = gcc
CFLAGS = -Wall -Werror -O2
SRC = tarefa-20241211.c
TARGET = tarefa

all: linux windows

linux:
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

windows:
	x86_64-w64-mingw32-gcc $(CFLAGS) -o $(TARGET).exe $(SRC)

clean:
	rm -f $(OBJ) $(TARGET) $(TARGET).exe *~

.PHONY: all clean
