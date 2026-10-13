/*
 * function: func_021F9680
 * address:  0x021F9680
 * packet:   pkt_021F9680
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_StartSeq  0x020064F4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23185.h"

typedef unsigned int   u32;
extern void GFL_USE_StartSeq(u32 a);

void func_021F9680(char *p, int a)
{
    ((struct Obj23185 *)p)->f28 = 1;
    GFL_USE_StartSeq(a);
}
