ifneq ($(KERNELRELEASE),)
obj-m := rtc-rv8263.o
else
KDIR := /lib/modules/`uname -r`/build

all: rtc_vl

modules:
	$(MAKE) -C $(KDIR) M=$$PWD

CC = $(CROSS_COMPILE)gcc
CFLAGS = -Wall -Wextra

rtc_vl: rtc_vl.o
	$(CC) $(CFLAGS) -o rtc_vl rtc_vl.o

clean:
		rm -f rtc_vl.o rtc_vl
endif
