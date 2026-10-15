/*
 * function: SOCLi_GetSizeSocket
 * address:  0x0215D200
 * packet:   pkt_ov009_0215D200
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_GetSizeSocket (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   func_0215F0C8  0x0215F0C8  arm  ov009
 *   SOCLi_GetSizeCommandPipe  0x0215D280  arm  ov009
 */

typedef struct {
	unsigned char a;
	unsigned char b;
	unsigned short send;
	unsigned short f4;
	unsigned short recv;
	unsigned short sendbuf;
	unsigned short rbuf1;
	unsigned short rbuf2;
	unsigned short cfg;
	unsigned char pipe1[4];
	unsigned char pipe2[4];
} Param;

extern unsigned long func_0215F0C8(unsigned long size);
extern unsigned long SOCLi_GetSizeCommandPipe(void *param);

unsigned long SOCLi_GetSizeSocket(Param *param)
{
	unsigned long size;

	size = 0xbc;
	if (param->send) {
		size += 0x114;
		size += func_0215F0C8(param->send);
		size += func_0215F0C8(param->sendbuf);
		size += SOCLi_GetSizeCommandPipe(param->pipe1);
	}
	if (param->recv) {
		size += 0x110;
		size += func_0215F0C8(param->recv);
		size += func_0215F0C8(param->rbuf1);
		size += func_0215F0C8(param->rbuf2);
		size += SOCLi_GetSizeCommandPipe(param->pipe2);
	}
	return size;
}
