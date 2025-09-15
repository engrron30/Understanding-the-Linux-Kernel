// File: rtnl_lock_example.c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/netdevice.h>	// for rtnl_lock/unlock
#include <linux/rtnetlink.h>	// rtnl_lock prototypes
#include <linux/delay.h>	// for msleep

#define DEV_NAME_TO_FIND		"enp0s8"
#define HOLD_RTNL_DURATION_SECS		60

static int __init rtnl_example_init(void)
{
    struct net_device *dev;
    pr_info("===================== RTNL Example by Ronald ============================\n");

    rtnl_lock();
    pr_info("RTNL lock acquired\n");

    /* Example operation: find a network device by name */
    dev = dev_get_by_name(&init_net, DEV_NAME_TO_FIND);
    if (dev) {
        pr_info("Found device: %s\n", dev->name);
	for (int i = 0; i < HOLD_RTNL_DURATION_SECS; ++i) {
	    msleep(1000);
            pr_info("[%d] Still holding rtnl_lock\n", i);
	}
        dev_put(dev);

    } else {
        pr_info("Device %s not found\n", DEV_NAME_TO_FIND);
    }

    rtnl_unlock();
    pr_info("===================== RTNL Example is ended ============================\n");

    return 0;
}

static void __exit rtnl_example_exit(void)
{
    pr_info("RTNL example: unloading module\n");
}

module_init(rtnl_example_init);
module_exit(rtnl_example_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ronald");
MODULE_DESCRIPTION("RTNL lock demo module");

