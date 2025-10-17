#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>

#include "ronmod_def.h"

static int major_number = 0;
module_param(major_number, int, 0644);
MODULE_PARM_DESC(major_number, "Major number for ronmod device");

/***********************************************************************************
 *		Driver File Operations
 ***********************************************************************************/
static int ron_open(struct inode *inode, struct file *file);
static int ron_close(struct inode *inode, struct file *file);
static long ron_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

struct file_operations ron_fops = {
	.owner			= THIS_MODULE,
	.open			= ron_open,
	.unlocked_ioctl		= ron_ioctl,
	.release		= ron_close,
};

static int ron_open(struct inode *inode, struct file *file)
{
	printk("[RONMOD] ron_open is triggered by userspace\n");

	return 0;
}

static int ron_close(struct inode *inode, struct file *file)
{
	printk("[RONMOD] ron_close was called!\n");
	return 0;
}

static long ron_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    int value;

    switch (cmd)
    {
        case RONMOD_CMD_HELLO:
            printk(KERN_INFO "[RONMOD] IOCTL: Hello command received\n");
            break;

        case RONMOD_CMD_SET_VALUE:
            if (copy_from_user(&value, (int __user *)arg, sizeof(value)))
                return -EFAULT;
            printk(KERN_INFO "[RONMOD] IOCTL: Set value = %d\n", value);
            break;

        case RONMOD_CMD_GET_VALUE:
            value = 42; // Example
            if (copy_to_user((int __user *)arg, &value, sizeof(value)))
                return -EFAULT;
            printk(KERN_INFO "[RONMOD] IOCTL: Get value = %d\n", value);
            break;

        default:
            return -EINVAL;
    }

    return 0;
}

/***********************************************************************************
 *		Module Entry and Exit Functions
 ***********************************************************************************/
#define RONMOD_MAJOR_NUM		240
#define RONMOD_DEV_STR			"ronmod"

static int __init ronmod_init(void)
{
	printk(KERN_INFO "[RONMOD] Basic module is loaded!\n");

	major_number = register_chrdev(RONMOD_MAJOR_NUM, RONMOD_DEV_STR, &ron_fops);
	if (major_number < 0) {
		printk("[RONMOD] Failed to register device\n");
		return major_number;
	}

	printk("[RONMOD] Successfully registered %s with major_num=%d\n", RONMOD_DEV_PATH, RONMOD_MAJOR_NUM);
	return 0;
}

static void __exit ronmod_exit(void)
{
	unregister_chrdev(RONMOD_MAJOR_NUM, RONMOD_DEV_STR);
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
