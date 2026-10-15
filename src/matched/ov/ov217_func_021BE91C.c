/*
 * function: RESEARCH_GRAPH_CycleIndex
 * address:  0x021BE91C
 * packet:   pkt_021BE91C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _s32_div_f  0x0209C0A4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14736.h"

extern int _s32_div_f(int, int);

void RESEARCH_GRAPH_CycleIndex(char *p, int a)
{
    ((struct Obj14736 *)p)->f34 = (((struct Obj14736 *)p)->f34 + a + 5) % 5;
}
