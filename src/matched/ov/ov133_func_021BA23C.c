/*
 * function: DUP_FITTING_ITEM_ElemSetF2C
 * address: 0x021BA23C
 * packet: pkt_ov133_021BA23C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23335.h"
typedef unsigned char u8;
typedef unsigned int u32;
void DUP_FITTING_ITEM_ElemSetF2C(u8 *p, u32 value)
{
    ((struct Obj23335 *)p)->f2C=value;
}
