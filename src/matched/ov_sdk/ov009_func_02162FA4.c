/*
 * function: CPSi_SslCleanup
 * address:  0x02162FA4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the 0x170 bytes of the object at 0x021AA664.
 *
 * symbols:
 *   gCpsSslSessionCache  0x021AA664  data
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

#include "../include/G_CPSSslSession.h"

extern struct CPSSslSession gCpsSslSessionCache;
extern void MI_CpuFill8(void *p, int v, int n);

void CPSi_SslCleanup(void)
{
    MI_CpuFill8(((char *)&gCpsSslSessionCache), 0, 0x170);
}

