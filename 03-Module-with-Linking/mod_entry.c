#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EngrRon");
MODULE_DESCRIPTION("Kernel module with multiple functions");
MODULE_VERSION("1.3");

/* --- Parameters --- */
static int a = 5;
static int b = 3;
module_param(a, int, 0644);
module_param(b, int, 0644);
MODULE_PARM_DESC(a, "First integer");
MODULE_PARM_DESC(b, "Second integer");

/* --- Extra functions --- */
static int add(int x, int y)
{
    return x + y;
}

static int mul(int x, int y)
{
    return x * y;
}

static int factorial(int n)
{
    int result = 1;
    int i;
    for (i = 1; i <= n; i++)
        result *= i;
    return result;
}

/* --- Init / Exit --- */
static int __init ronmod_init(void)
{
    printk(KERN_INFO "[RONMOD] Module loaded with a=%d, b=%d\n", a, b);

    printk(KERN_INFO "[RONMOD] add(%d, %d) = %d\n", a, b, add(a, b));
    printk(KERN_INFO "[RONMOD] mul(%d, %d) = %d\n", a, b, mul(a, b));
    printk(KERN_INFO "[RONMOD] factorial(%d) = %d\n", a, factorial(a));

    return 0;
}

static void __exit ronmod_exit(void)
{
    printk(KERN_INFO "[RONMOD] Module exiting...\n");
}

module_init(ronmod_init);
module_exit(ronmod_exit);

