#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

#include "ronmod_def.h"

int main()
{
	bool ret_val = false;
	int fd = -1;
	printf("Welcome to ronmod_ctl\n");

#ifdef __CHECK_DEV_ACCESS__
	if (access(RONMOD_DEV_PATH, F_OK) != 0)
	{
		printf("[USERSPACE] %s not found! Do mknod first.\n", RONMOD_DEV_PATH);
		goto exit;
	}
#endif

	fd = open(RONMOD_DEV_PATH, O_RDWR);
	if (fd < 0)
	{
		printf("[USERSPACE] Error to open device\n");
		goto exit;
	}

	printf("Sending HELLO command...\n");
	ioctl(fd, RONMOD_CMD_HELLO);

	printf("Sending SET_VALUE=123 command...\n");
	val = 123;
	ioctl(fd, RONMOD_CMD_SET_VALUE, &val);

	printf("Sending GET_VALUE command...\n");
	ioctl(fd, RONMOD_CMD_GET_VALUE, &val);
	printf("Kernel returned value = %d\n", val);

	close(fd);
	ret_val = true;
	printf("[USERSPACE] Success\n");

exit:
	return ret_val ? 0 : 1;
}
