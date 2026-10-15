/*
 * function: DUP_FITTING_ITEM_ElemGetF2C
 * address: 0x021BA240
 * packet: pkt_ov133_021BA240
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23336.h"
typedef unsigned char u8;
typedef unsigned int u32;
u32 DUP_FITTING_ITEM_ElemGetF2C(u8 *p)
{
    return ((struct Obj23336 *)p)->f2C;
}
