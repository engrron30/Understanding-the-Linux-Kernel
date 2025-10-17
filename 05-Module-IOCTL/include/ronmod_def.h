#ifndef RONMOD_DEF_H
#define RONMOD_DEF_H

#define DEV_PATH		"/dev"
#define RONMOD_DEV_PATH		DEV_PATH"/ronmod"
//#define RONMOD_MAJOR_NUM	381

// Magic number — must be unique per driver
#define RONMOD_MAGIC 'r'

// IOCTL commands
#define RONMOD_CMD_HELLO		_IO(RONMOD_MAGIC, 0)
#define RONMOD_CMD_SET_VALUE		_IOW(RONMOD_MAGIC, 1, int)
#define RONMOD_CMD_GET_VALUE		_IOR(RONMOD_MAGIC, 2, int)

#endif
