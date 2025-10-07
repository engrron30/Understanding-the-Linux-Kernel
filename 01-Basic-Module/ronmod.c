#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/* Module in C needs to define init and exit functions. These function 
 * can serve as entry and exit points whenever they are loaded to the 
 * kernel.
 *
 * This module is compiled as ronmod.ko based on what obj-m is
 * defined in Makefile.
 *
 * When someone executed `insmod ronmod.ko` in the terminal, 
 * ronmod_init() function is supposed to be observed in the kernel logs 
 * by running dmesg command. 
 *
 * Executing `rmmod ronmod.ko` in the terminal will trigger the
 * ronmod_exit() function.
 * */
static int __init ronmod_init(void)
{
	printk(KERN_INFO "[RONMOD] Basic module is loaded!\n");
	printk(KERN_DEBUG "[RONMOD] Basic Debug example.\n");
	return 0;
}

static void __exit ronmod_exit(void)
{
	printk(KERN_WARNING "[RONMOD] Module is exiting...\n");
}

module_init(ronmod_init);
module_exit(ronmod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EngrRon");
MODULE_DESCRIPTION("Basic kernel module with printk example");
MODULE_VERSION("1.0");
