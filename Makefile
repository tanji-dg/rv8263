ifneq ($(KERNELRELEASE),)
obj-m := rtc-rv8263.o
else
KDIR := /lib/modules/`uname -r`/build

all:
	$(MAKE) -C $(KDIR) M=$$PWD
endif
