/*
 * function: func_021F9CA4
 * address:  0x021F9CA4
 * packet:   pkt_021F9CA4
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj24813.h"

extern void MI_CpuFill8(void *, int, int);

void func_021F9CA4(void *p)
{
    MI_CpuFill8(p, 0, 0x10);
    ((struct Obj24813 *)p)->fC = -1;
}
