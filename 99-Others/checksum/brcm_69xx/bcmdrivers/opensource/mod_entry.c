#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

#include "mod_chksum.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EngrRon");
MODULE_DESCRIPTION("Kernel module with multiple functions");
MODULE_VERSION("1.3");

/* --- Parameters --- */
static int a = 5;
static int b = 3;
module_param(a, int, 0644);
MODULE_PARM_DESC(a, "First integer");
module_param(b, int, 0644);
MODULE_PARM_DESC(b, "Second integer");

/* --- Init / Exit --- */
static int __init ronmod_init(void)
{
    printk(KERN_INFO "[RONMOD] Module loaded with a=%d, b=%d\n", a, b);

    return 0;
}

static void __exit ronmod_exit(void)
{
    printk(KERN_INFO "[RONMOD] Module exiting...\n");
    uint32_t c = crc32((const uint8_t*)s, strlen(s));
    printk("CRC32: 0x%08x\n", c); 
}

module_init(ronmod_init);
module_exit(ronmod_exit);

