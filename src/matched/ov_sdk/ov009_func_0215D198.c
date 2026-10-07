/*
 * function: func_0215D198
 * address:  0x0215D198
 * packet:   pkt_ov009_0215D198
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_StartupSocket (libsoc.TWL.HYB.a(socl_create.o))
 *
 * symbols:
 *   func_0215D200  0x0215D200  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0215D2A8  0x0215D2A8  arm  ov009
 *   func_0215F2DC  0x0215F2DC  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021A1CD8  0x021A1CD8  data
 */

#include "../include/G_021A1CD8.h"

extern unsigned long func_0215D200(void *param);
extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned char *func_0215D2A8(void *socket, void *param);
extern void func_0215F2DC(int a);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct G_021A1CD8 *g_021A1CD8;

void *func_0215D198(void *param)
{
	void *socket;
	unsigned long enable;
	unsigned long size;

	size = func_0215D200(param);
	enable = OS_DisableInterrupts();
	socket = g_021A1CD8->alloc(size);
	if (socket) {
		MI_CpuFill8(socket, 0, size);
		func_0215D2A8(socket, param);
		func_0215F2DC((int)socket);
	}
	OS_RestoreInterrupts(enable);
	return socket;
}
