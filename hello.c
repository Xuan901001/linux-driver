#include <linux/module.h>
#include <linux/init.h>

/* Meta Information */
MODULE_LICENSE("GPL"); /*有些發行版只載入在GPL下許可的模組*/
MODULE_AUTHOR("Xuan"); /*模組作者資訊*/
MODULE_DESCRIPTION("A hello world LKM"); /*模組描述的訊息*/

/**
 * @brief This function is called, when the module is loaded into the kernel
 */
static int __init my_init(void) {
 /* __init是一個標記，用來告訴核心這個函數只在模組初始化時執行*/
	printk("Hello, Kernel!\n");
	return 0;
}

/**
 * @brief This function is called, when the module is removed from the kernel
 */
/*當模組被從核心移除時，這個函數會被呼叫*/
static void __exit my_exit(void) {
	printk("Goodbye, Kernel\n");
}

module_init(my_init); /*定義模組初始化函數為my_init*/
module_exit(my_exit); /*定義模組退出函數為my_exit*/

