SRC_DIR := $(shell pwd)
INC_DIR := $(SRC_DIR)/include/

.PHONY: all clean
all:
	make -C ronmod_kernel_code all
	make -C ronmod_userspace_code all

clean:
	make -C ronmod_kernel_code clean
	make -C ronmod_userspace_code clean
