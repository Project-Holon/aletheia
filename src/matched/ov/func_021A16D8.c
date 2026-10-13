/*
 * function: FIELD_3DBG_SetBillboardPolygonId
 * address:  0x021A16D8
 * packet:   pkt_021A16D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x1e.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17996.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_3DBG_SetBillboardPolygonId(u8 *p, u8 v)
{
    ((struct Obj17996 *)p)->f1E = v;
}
