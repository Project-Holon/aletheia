/*
 * function: func_0215F0D4
 * address:  0x0215F0D4
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Clears the eight bytes of the object at 0x021AA4AC.
 *
 * symbols:
 *   g_021AA4AC  0x021AA4AC  data
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

#include "../include/G_SOCLResource.h"

extern struct SOCLResource g_021AA4AC;
extern void MI_CpuFill8(void *p, int v, int n);

void func_0215F0D4(void)
{
    MI_CpuFill8(((char *)&g_021AA4AC), 0, 8);
}

