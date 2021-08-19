#include<linux/init.h>
#include<linux/module.h>

#include<linux/fs.h>
int simple_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "inside the %s function\n",__FUNCTION__);
	return 0;
}

ssize_t simple_read (struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "inside the %s function\n",__FUNCTION__);
	return 0;
}
ssize_t simple_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_ALERT "inside the %s function\n",__FUNCTION__);
	return length;
}
int simple_close (struct inode *pinode, struct file *pfile)
{
	printk(KERN_ALERT "inside the %s function\n",__FUNCTION__);
	return 0;
}

struct file_operations simple_file_operation ={
.owner =THIS_MODULE,
.open = simple_open,
.read = simple_read,
.write = simple_write,
.release = simple_close,
};
int simple_module_init(void)
{
    printk(KERN_ALERT "Inside the %s function\n",__FUNCTION__);

    register_chrdev(240, "simple chr drv",&simple_file_operation);
return 0;
}
void simple_module_exit(void)
{
    printk(KERN_ALERT "inside the %s function\n",__FUNCTION__);
    unregister_chrdev(240,"simple chr drv");
}
module_init(simple_module_init);
module_exit(simple_module_exit);
