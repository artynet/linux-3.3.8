/*
 * mcuio I2c controller driver
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/types.h>
#include <linux/regmap.h>
#include <linux/workqueue.h>
#include <linux/kthread.h>
#include <linux/irq.h>
#include <linux/interrupt.h>

#include <linux/mcuio.h>
#include <linux/mcuio_ids.h>
#include <linux/mcuio-proto.h>

#include "mcuio-internal.h"

static int mcuio_simple_i2c_probe(struct mcuio_device *mdev)
{
	return -ENODEV;
}

static int mcuio_simple_i2c_remove(struct mcuio_device *mdev)
{
	return 0;
}

static const struct mcuio_device_id mcuio_simple_i2c_drv_ids[] = {
	{
		.class = MCUIO_CLASS_I2C_CONTROLLER,
		.class_mask = 0xffff,
	},
	/* Terminator */
	{
		.device = MCUIO_NO_DEVICE,
		.class = MCUIO_CLASS_UNDEFINED,
	},
};


static struct mcuio_driver mcuio_simple_i2c_driver = {
	.driver = {
		.name = "mcuio-simple-i2c",
	},
	.id_table = mcuio_simple_i2c_drv_ids,
	.probe = mcuio_simple_i2c_probe,
	.remove = mcuio_simple_i2c_remove,
};

static int __init mcuio_simple_i2c_init(void)
{
	return mcuio_driver_register(&mcuio_simple_i2c_driver, THIS_MODULE);
}

static void __exit mcuio_simple_i2c_exit(void)
{
	return mcuio_driver_unregister(&mcuio_simple_i2c_driver);
}

subsys_initcall(mcuio_simple_i2c_init);
module_exit(mcuio_simple_i2c_exit);

MODULE_VERSION(GIT_VERSION); /* Defined in local Makefile */
MODULE_AUTHOR("Davide Ciminaghi");
MODULE_DESCRIPTION("MCUIO simple i2c controller driver");
MODULE_LICENSE("GPL v2");
