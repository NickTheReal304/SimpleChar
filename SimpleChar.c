#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h> /* For the character driver support */

int simpleChar_open(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

ssize_t simpleChar_read(struct inode *pfile, char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

ssize_t simpleChar_write(struct inode *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return length;
}

int simpleChar_close(struct inode *pinode, struct file *pfile)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
    return 0;
}

struct file_operations simpleChar_file_operations = {
    .owner = THIS_MODULE,
    .open = simpleChar_open,
    .read = simpleChar_read,
    .write = simpleChar_write,
    .release = simpleChar_close,
};

int simpleChar_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

    /* Register with kernel and indicate that we are registering a charater device driver */
    register_chrdev(240 /* Major number */,
                    "SimpleChar" /* Name of the driver */,
                    simpleChar_file_operations /* File operations*/);
    return 0;
}

void simpleChar_module_exit(void)
{
    printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

    /* Register with kernel and indicate that we are registering a charater device driver */
    unregister_chrdev(240 /* Major number */,
                      "SimpleChar" /* Name of the driver */, );
}

module_init(simpleChar_module_init);
module_init(simpleChar_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nick Wong");
MODULE_DESCRIPTION("It is a simple implementation");