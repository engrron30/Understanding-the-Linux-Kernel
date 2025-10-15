###################################################
#####		MAKEFILE VARIABLES		###
##################################################
TARGET = ronmod_ctl
SRC_DIR := $(shell pwd)
INC_DIR := $(SRC_DIR)/../include

CFLAGS += -I$(INC_DIR)


###################################################
#####		MAKEFILE TARGET/RECIPES		###
##################################################
.PHONY: all
all: $(TARGET)

$(TARGET): userspace_ron.o
	gcc $(CFLAGS) userspace_ron.o -o $(TARGET)

userspace_ron.o: userspace_ron.c
	gcc $(CFLAGS) -c userspace_ron.c -o userspace_ron.o

clean:
	rm -rf *.o $(TARGET)
