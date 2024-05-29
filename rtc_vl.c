#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/rtc.h>

#ifndef RTC_VL_READ
#include <linux/ioctl.h>
#define RTC_VL_READ _IOR('p', 0x13, int) /* Voltage low detector */
#define RTC_VL_CLR _IO('p', 0x14)		 /* Clear voltage low informat */
#endif

int main(int argc, char **argv)
{
	int fd, retval;
	const char *rtc = argv[1];
	int vl;
	fd = open(rtc, O_RDWR);
	if (fd == -1)
	{
		perror(rtc);
		exit(errno);
	}
	retval = ioctl(fd, RTC_VL_READ, &vl);
	if (retval < 0)
	{
		perror("RTC_VL_READ failed");
		exit(errno);
	}
	printf("%s flags: %d\n", rtc, vl);
	retval = ioctl(fd, RTC_VL_CLR, NULL);
	if (retval < 0)
	{
		perror("RTC_VL_CLR failed");
		exit(errno);
	}
	retval = ioctl(fd, RTC_VL_READ, &vl);
	if (retval < 0)
	{
		perror("RTC_VL_READ failed");
		exit(errno);
	}
	printf("%s flags: %d\n", rtc, vl);
	close(fd);
	return 0;
}
