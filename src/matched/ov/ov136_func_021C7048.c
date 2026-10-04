/*
 * function: func_021C7048
 * address: 0x021C7048
 * packet: pkt_ov136_021C7048
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj10607.h"
typedef unsigned char u8;
int func_021C7048(u8 *p)
{
    if (p[0x20] != 6) {
        ((struct Obj10607 *)p)->f28 = 0x15;
        return 0;
    }
    ((struct Obj10607 *)p)->f14 = 2;
    return 6;
}
