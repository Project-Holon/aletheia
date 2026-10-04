/*
 * function: func_021DEE68
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_021DEEA4  0x021DEEA4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj22920.h"

typedef unsigned int u32;

extern void func_02082BCC(void *, int, int);
extern void func_021DEEA4(u32 *p, void *f);

void func_021DEE68(void *p, int a, void *b)
{
    func_02082BCC(p, 0, 0x10);
    ((struct Obj22920 *)p)->fC = (u32)a;
    func_021DEEA4(p, b);
}
