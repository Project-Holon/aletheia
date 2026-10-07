/*
 * function: func_02189BA8
 * address:  0x02189BA8
 * packet:   pkt_ov021_02189BA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02189B28  0x02189B28  thumb  ov021
 *   d_021D373C     0x021D373C  data  a4
 */

#include "../include/G__anon_Ent.h"

extern struct _anon_Ent d_021D373C[];
unsigned int func_02189B28(unsigned int x);

int func_02189BA8(int x)
{
    return d_021D373C[(int)func_02189B28((unsigned int)x)].f0;
}
