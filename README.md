# Understanding-Kernel-Objects

Let's define module as the kernel object. Kernel object is derived from a C file that when compiled, it generates a KO file. This KO file can be inserted to the kernel as object to run the code defined in C before it is compiled. Once loaded, the module can also be removed from the kernel and insert again from time to time.

## Basic Module

Let's make a simple module to understand how it is inserted in the module then gets loaded. In this section, the goal is to understand:
    (1) How to load the compile KO file;
    (2) Basic kernel code syntax;
    (2) How to use *printk* and see its output in kernel logs using *dmesg*.

## Basic Module with Parameters

Let's add some difficulty by adding parameters to the module.

## Module with Character Device
