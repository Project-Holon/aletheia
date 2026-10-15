/*
 * function: MYSTERY_NET_InitTask
 * address:  0x021DEE68
 * packet:   pkt_021DEE68
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *   MYSTERY_NET_SetHandler  0x021DEEA4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22920.h"

typedef unsigned int u32;

extern void MI_CpuFill8(void *, int, int);
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);

void MYSTERY_NET_InitTask(void *p, int a, void *b)
{
    MI_CpuFill8(p, 0, 0x10);
    ((struct Obj22920 *)p)->fC = (u32)a;
    MYSTERY_NET_SetHandler(p, b);
}
