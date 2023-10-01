CC = gcc
CFLAGS =
LDFLAGS =


all: build run clean

build: main.c database.c
	@$(CC) $(CFLAGS) $^ -o main.exe $(LDFLAGS)

run: main.exe
	@$^

clean:
	@del main.exe