TARGET = ronmod_ctl


.PHONY: all
all: main

main: userspace_ron.o
	gcc userspace_ron.o -o $(TARGET)

userspace_ron.o: userspace_ron.c
	gcc -c userspace_ron.c -o userspace_ron.o
