obj-m := simple_module.o
obj-m += simple_module_init.o
obj-m += simple_module_exit.o

obj-m :=init_exit_simple_module.o
init_exit_simple_module-objs := simple_module_init.o simple_module_exit.o

obj-m := simple_module.o
obj-m += simple_module2.o

obj-m := exporting_symbol.o
obj-m += using_symbol.o

obj-m := module_param.o

obj-m := char_driver.o
