/*
 * function: func_021CA23C
 * address:  0x021CA23C
 * packet:   pkt_ov021_021CA23C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Saturating increment of the halfword counter at +0xe.
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12970.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_021CA23C(u8 *p)
{
    u16 v = ((struct Obj12970 *)p)->fE;
    if (v < 0xffff)
        ((struct Obj12970 *)p)->fE = v + 1;
}
