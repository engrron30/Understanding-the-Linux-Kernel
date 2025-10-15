#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "ronmod_def.h"

int main()
{
	bool ret_val = false;
	printf("Welcome to ronmod_ctl\n");

	if (access(RONMOD_DEV_PATH, F_OK) != 0)
	{
		printf("[USERSPACE] %s not found! Do mkod first.\n", RONMOD_DEV_PATH);
		goto exit;
	}

	ret_val = true;
exit:
	return ret_val;
}
