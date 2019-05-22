CONFIG_MODULE_SIG=n
KERNEL_SOURCE ?= /lib/modules/$(shell uname -r)/build

ifneq ($(KERNELRELEASE),)

	obj-m := task_list_mod.o

# Otherwise we were called directly from the command
# line; invoke the kernel build system.
else
	PWD  := $(shell pwd)

default:
	    ${MAKE}  -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules

clean:
	    ${MAKE} -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean
endif


