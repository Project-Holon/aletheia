/*
 * function: DUP_FITTING_ITEM_ElemSetF18
 * address: 0x021BA244
 * packet: pkt_ov133_021BA244
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23337.h"
typedef unsigned char u8;
typedef unsigned int u32;
void DUP_FITTING_ITEM_ElemSetF18(u8 *p, u32 value)
{
    ((struct Obj23337 *)p)->f18=value;
}
