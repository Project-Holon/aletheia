#ifndef GAME_OV009_SOCL_WRITE_H
#define GAME_OV009_SOCL_WRITE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of socl_write.c, prototypes copied from their definitions. */

struct SOCLSocket;
struct SOCLiCommandWrite;

#include "../types.h"

int SOCL_WriteTo(int s, void *buffer, int buffer_len, unsigned short remote_port, unsigned long remote_ip, int flags);
int SOCLi_AllocWriteBuffer(struct SOCLSocket *socket, int n, int m, int *out, int f5);
long SOCLi_GetWriteBufferFreeSize(struct SOCLSocket *socket);
int SOCLi_GetOptimumSendBufLen(int len);
int SOCLi_MemCpy(u8 *dst, int len, struct SOCLiCommandWrite *r);
/* END mkheaders: generated region */

#endif
