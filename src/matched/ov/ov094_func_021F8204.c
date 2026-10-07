/*
 * function: func_021F8204
 * address: 0x021F8204
 * packet: pkt_ov094_021F8204
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02207D60 0x02207D60 thumb ov094
 *   d_0220AF20 0x0220AF20 data a4
 */

#include "../include/G_0220AF20.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02207D60(u8 *, int);
extern struct G_0220AF20 *d_0220AF20;
int func_021F8204(int index)
{
    return func_02207D60(*(u8 **)(((u8 *)d_0220AF20) + 0x1a4), index);
}
