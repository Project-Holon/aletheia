/*
 * function: func_02162FA4
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
 *   g_021AA664  0x021AA664  data
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

#include "../include/G_CPSSslSession.h"

extern struct CPSSslSession g_021AA664;
extern void MI_CpuFill8(void *p, int v, int n);

void func_02162FA4(void)
{
    MI_CpuFill8(((char *)&g_021AA664), 0, 0x170);
}

