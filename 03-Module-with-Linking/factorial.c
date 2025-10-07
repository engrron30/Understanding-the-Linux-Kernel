#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>		// module_param()

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ronald");
MODULE_DESCRIPTION("Kernel module with parameters example");
MODULE_VERSION("1.0");


/*static int __init ronmod_init(void)
{
    printk(KERN_INFO "[RONMOD] Module loaded with value=%d and name=%s\n", value, name);
    return 0;
}

static void __exit ronmod_exit(void)
{
    printk(KERN_INFO "[RONMOD] Module exiting, goodbye %s!\n", name);
}

module_init(ronmod_init);
module_exit(ronmod_exit);
*/
