/*
 * function: SOCLi_InitResource
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
 *   SOCLi_Resource  0x021AA4AC  data
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

#include "../include/G_SOCLResource.h"

extern struct SOCLResource SOCLi_Resource;
extern void MI_CpuFill8(void *p, int v, int n);

void SOCLi_InitResource(void)
{
    MI_CpuFill8(((char *)&SOCLi_Resource), 0, 8);
}

