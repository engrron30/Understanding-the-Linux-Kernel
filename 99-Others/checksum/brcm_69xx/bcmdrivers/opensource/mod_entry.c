#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

#include "mod_chksum.h"

#define FAST_CUM_STRING			"fast_checksum"
#define FAST_CUM_DEV_PATH		"/dev/checksum"
#define FAST_CHECKSUM			8
#define FAST_CUM_LENGTH			1024
#define FAST_CHECK_PACKET		FAST_CUM_LENGTH + 32

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Electronix");
MODULE_DESCRIPTION("Fast Checksum Module");
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
    const char *s = "The quick brown fox jumps over the lazy dog";
    uint32_t c = get_fast_cum((const uint8_t*)s, strlen(s));
    printk("CRC32: 0x%08x\n", c); 
    return 0;
}

static void __exit ronmod_exit(void)
{
    printk(KERN_INFO "[RONMOD] Module exiting...\n");
}

module_init(ronmod_init);
module_exit(ronmod_exit);

