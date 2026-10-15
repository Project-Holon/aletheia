/*
 * function: DUP_FITTING_ITEM_ElemGetData
 * address: 0x021BA20C
 * packet: pkt_ov133_021BA20C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23331.h"
typedef unsigned char u8;
typedef unsigned int u32;
u32 DUP_FITTING_ITEM_ElemGetData(u8 *p)
{
    return ((struct Obj23331 *)p)->f4;
}
