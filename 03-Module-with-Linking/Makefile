# The desired output is the obj-m. In this case, we should expect
# mod_output.ko as output when build is successful.
obj-m		:= mod_output.o
ronmod-objs	:= mod_entry.o factorial.o

KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

