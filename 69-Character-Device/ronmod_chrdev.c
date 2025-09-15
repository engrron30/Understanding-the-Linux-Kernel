#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#define CHAR_DEV_NAME		"ronmod"
#define BUFFER_SIZE		1024

static int __init ronmod_init(void)
{
	/* Initialize a dev_t variable for your character device.
	 * A ret interger is also initialized for monitoring function
	 * returns whether successful or not.
	 * */
	dev_t dev;
	int ret;

	ret = alloc_chrdev_region(&dev, 0, 1, CHAR_DEV_NAME);
	printk(KERN_INFO "[RONMOD] Module with character device is loaded!\n");
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
MODULE_DESCRIPTION("Module with Character Device Example");
MODULE_VERSION("1.0");
