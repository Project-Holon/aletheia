/*
 * function: SOCLi_StartupSocket
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
 *   SOCLi_GetSizeSocket  0x0215D200  arm  ov009
 *   OS_DisableInterrupts  0x02087988  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   SOCLi_InitSocket  0x0215D2A8  arm  ov009
 *   SOCLi_SocketRegister  0x0215F2DC  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gSoclConfig  0x021A1CD8  data
 */

#include "../include/G_021A1CD8.h"

extern unsigned long SOCLi_GetSizeSocket(void *param);
extern unsigned long OS_DisableInterrupts(void);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern unsigned char *SOCLi_InitSocket(void *socket, void *param);
extern void SOCLi_SocketRegister(int a);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct G_021A1CD8 *gSoclConfig;

void *SOCLi_StartupSocket(void *param)
{
	void *socket;
	unsigned long enable;
	unsigned long size;

	size = SOCLi_GetSizeSocket(param);
	enable = OS_DisableInterrupts();
	socket = gSoclConfig->alloc(size);
	if (socket) {
		MI_CpuFill8(socket, 0, size);
		SOCLi_InitSocket(socket, param);
		SOCLi_SocketRegister((int)socket);
	}
	OS_RestoreInterrupts(enable);
	return socket;
}
