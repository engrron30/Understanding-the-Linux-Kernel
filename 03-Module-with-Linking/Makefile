# The desired output is the obj-m. In this case, we should expect
# mod_output.ko as output when build is successful.
#
# To compile the KO file, we added the needed objects for it
# listed in the mod_output-objs which are the (1) mod_entry and
# (2) factorial files.
#
# So, if another C file needed to be linked, just add the file
# name to the mod_output-objs list
#
obj-m		:= mod_output.o
mod_output-objs	:= mod_entry.o factorial.o

KVER := $(shell uname -r)
KDIR := /lib/modules/$(KVER)/build
PWD  := $(shell pwd)

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

