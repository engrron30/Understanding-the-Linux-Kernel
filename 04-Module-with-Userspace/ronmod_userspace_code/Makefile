TARGET = ronmod_ctl


.PHONY: all
all: $(TARGET)

$(TARGET): userspace_ron.o
	gcc userspace_ron.o -o $(TARGET)

userspace_ron.o: userspace_ron.c
	gcc -c userspace_ron.c -o userspace_ron.o

clean:
	rm -rf *.o $(TARGET)
