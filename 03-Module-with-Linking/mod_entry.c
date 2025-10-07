#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

#define MODULE_STRING		"MOD_WITH_LINKING"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EngrRon");
MODULE_DESCRIPTION("Kernel module with multiple functions");
MODULE_VERSION("1.3");


/*********************************************************************
 *	Insert Parameters for Module Here!
 *********************************************************************/
static int a = 5;
static int b = 3;
module_param(a, int, 0644);
module_param(b, int, 0644);
MODULE_PARM_DESC(a, "First integer");
MODULE_PARM_DESC(b, "Second integer");


/*********************************************************************
 *	Init and Exit of Module
 *********************************************************************/
static int __init ronmod_init(void)
{
    printk(KERN_INFO "[%s] Module loaded with a=%d, b=%d\n", MODULE_STRING, a, b);
    printk(KERN_INFO "[%s] factorial(%d) = %d\n", MODULE_STRING, a, factorial(a));

    return 0;
}

static void __exit ronmod_exit(void)
{
    printk(KERN_INFO "[%s] Module exiting...\n", MODULE_STRING);
}

module_init(ronmod_init);
module_exit(ronmod_exit);

