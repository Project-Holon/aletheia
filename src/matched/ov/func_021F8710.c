/*
 * function: func_021F8710
 * address:  0x021F8710
 * packet:   pkt_021FD1CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data
 */

#include "../include/G_0220AF20.h"

extern struct G_0220AF20 *d_0220AF20;

int func_021F8710(void)
{
    return *(int *)((char *)((void *)d_0220AF20) + 0x1bc);
}
