#include <stdio.h>
#include <stdbool.h>
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

	close(fd);
	ret_val = true;
	printf("[USERSPACE] Success\n");

exit:
	return ret_val ? 0 : 1;
}
