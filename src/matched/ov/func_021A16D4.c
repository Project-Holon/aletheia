/*
 * function: FIELD_3DBG_SetBillboardVisible
 * address:  0x021A16D4
 * packet:   pkt_021A16D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x8.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17995.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_3DBG_SetBillboardVisible(u8 *p, u32 v)
{
    ((struct Obj17995 *)p)->f8 = v;
}
