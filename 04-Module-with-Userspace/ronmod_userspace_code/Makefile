#####################################################
#####						#####
#####		MAKEFILE VARIABLES		#####
#####						#####
#####################################################
TARGET = ronmod_ctl
SRC_DIR := $(shell pwd)


#####################################################
#####						#####
#####		MAKEFILE TARGET/RECIPES		#####
#####						#####
#####################################################
.PHONY: all clean
all: $(TARGET)

$(TARGET): userspace_ron.o
	gcc userspace_ron.o -o $(TARGET)

userspace_ron.o: userspace_ron.c
	gcc $(LDFLAGS) -c userspace_ron.c -o userspace_ron.o

clean:
	rm -rf *.o $(TARGET)
