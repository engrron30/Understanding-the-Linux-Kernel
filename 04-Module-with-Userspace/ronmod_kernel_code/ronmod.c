#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include "ronmod_def.h"

static int major_number = 0;

/***********************************************************************************
 *		Driver File Operations
 ***********************************************************************************/
static int ron_open(struct inode *inode, struct file *file);

struct file_operations ron_fops = {
	.owner	= THIS_MODULE,
	.open	= ron_open,
};

static int ron_open(struct inode *inode, struct file *file)
{
	printk("[RONMOD] ron_open is triggered by userspace\n");

	return 0;
}


/***********************************************************************************
 *		Module Entry and Exit Functions
 ***********************************************************************************/
static int __init ronmod_init(void)
{
	printk(KERN_INFO "[RONMOD] Basic module is loaded!\n");

	major_number = register_chrdev(RONMOD_MAJOR_NUM, RONMOD_DEV_PATH, 0);
	if (major_number < 0) {
		printk("[RONMOD] Failed to register device\n");
		return major_number
	}

	printk("[RONMOD] Successfully registered %s with major_num=%d\n", RONMOD_DEV_PATH, major_number);
	return 0;
}

static void __exit ronmod_exit(void)
{
	printk(KERN_WARNING "[RONMOD] Module is exiting...\n");
}


/***********************************************************************************
 *		Module Macros
 ***********************************************************************************/
module_init(ronmod_init);
module_exit(ronmod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EngrRon");
MODULE_DESCRIPTION("Basic kernel module with printk example");
MODULE_VERSION("1.0");
