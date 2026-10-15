/*
 * function: MYSTERY_DeleteParticle
 * address:  0x021D6D38
 * packet:   pkt_021D6D38
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22854.h"

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void MI_CpuFill8(void *, int, int);

void MYSTERY_DeleteParticle(void *p)
{
    func_020307B0(((struct Obj22854 *)p)->f8);
    MI_CpuFill8(p, 0, 0x10);
}
