# Basic Module

Module in C needs to define init and exit functions. These function 
can serve as entry and exit points whenever they are loaded to the 
kernel.

        static int __init ronmod_init();
        static void __exit ronmod_exit();

This module is compiled as ronmod.ko based on what obj-m is
defined in Makefile.

        obj-m := ronmod.o                       # m stands for module

When someone executed `insmod ronmod.ko` in the terminal, 
ronmod_init() function is supposed to be observed in the kernel logs 
by running dmesg command. 

        insmod ronmod.ko                        # Observe ronmod_init printk in dmesg logs

Executing `rmmod ronmod.ko` in the terminal will trigger the
ronmod_exit() function.

        rmmod ronmod.ko                         # Observe ronmod_exit printk in dmesg logs
