/*
 * function: DUP_FITTING_ITEM_ElemGetNext
 * address: 0x021BA208
 * packet: pkt_ov133_021BA208
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23330.h"
typedef unsigned char u8;
typedef unsigned int u32;
u32 DUP_FITTING_ITEM_ElemGetNext(u8 *p)
{
    return ((struct Obj23330 *)p)->f30;
}
