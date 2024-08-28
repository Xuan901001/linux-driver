# linux-driver

## What a linux kernel module is ?

Linux kernel module is just a piece of software which runs in the kernel space.
For example in the kernel space you can access the hardware directly，but can’t use flaot variable out of the box and the stack is a little bit smaller when it is in user space and you can load them dynamically into the kernel and out of the kernel.

## The preparation necessary to use a raspberry pi for linux kernel modules
install the kernel modules：

```
sudo apt-get install raspberrypi-kerenl-headers
```
## Create first hello world kernel module:
```
vim mymodule.c
```
## Create Makefile
```
vim Makefile
```
## To build the kernel module, follow these steps:
1. **Run `make`**  
   This will compile and build the kernel module. You can check the files with `ls` to see that we have successfully built our first Linux kernel module. Besides the `Makefile` and `mymodule.c`, everything else is created by `make`. Among these files, `mymodule.ko` is the most important as it is the kernel module.

2. **Load the module into the kernel**  
   ```
   sudo insmod mymodule.ko
3. **Verify that the module is loaded**
   ```
   lsmod | grep mymodule
   ```
   This command searches for our module in the kernel.
4. **Check the kernel log**
   ```
   dmesg | tail
   ```
   This command displays the last 10 lines of the kernel log, where you will see "Hello, Kernel!"
   
5. **Remove the module**
   ```
   sudo rmmod mymodule
   ```   
6. **Check the kernel log again**
   ```
   dmesg | tail
   ```
   This will show "Goodbye, Kernel!"
