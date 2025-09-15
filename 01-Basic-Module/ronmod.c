#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

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
