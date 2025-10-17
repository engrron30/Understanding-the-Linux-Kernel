SRC_DIR := $(shell pwd)
INC_DIR := $(SRC_DIR)/include/

CFLAGS += -I$(INC_DIR)
# CFLAGS += -D__CHECK_DEV_ACCESS__ is not set

.PHONY: all clean
all:
	make -C ronmod_kernel_code all
	make -C ronmod_userspace_code CFLAGS="$(CFLAGS)" all

clean:
	make -C ronmod_kernel_code clean
	make -C ronmod_userspace_code clean
