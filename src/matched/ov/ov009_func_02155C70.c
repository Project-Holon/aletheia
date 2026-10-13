/*
 * function: DWC_RAP_ClearPeerCounters
 * address:  0x02155C70
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clears the eight bytes at +0x784 of the block the module pointer holds.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

#include "../include/G__anon_Work.h"

extern struct _anon_Work *g_021A8264;
extern void MI_CpuFill8(void *p, int v, int n);

void DWC_RAP_ClearPeerCounters(void)
{
    MI_CpuFill8(((char *)g_021A8264) + 0x784, 0, 8);
}

