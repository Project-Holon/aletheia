/*
 * function: SOCLi_TrashSocket
 * address:  0x0215EBB4
 * packet:   pkt_ov009_0215EBB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_TrashSocket (libsoc.TWL.HYB.a(socl_close.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   SOCLi_CleanupSocket  0x0215EA1C  arm  ov009
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021AA4B8  0x021AA4B8  data
 */

#include "../include/G_021AA4B8.h"

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern void SOCLi_CleanupSocket(void *socket);
extern struct G_021AA4B8 *g_021AA4B8;

void SOCLi_TrashSocket(void)
{
	unsigned long enable;

	enable = OS_DisableInterrupts();
	while (g_021AA4B8 != 0)
		SOCLi_CleanupSocket(g_021AA4B8);
	OS_RestoreInterrupts(enable);
}
