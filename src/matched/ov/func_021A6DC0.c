/*
 * function: FIELDMAP_CTRL_HYBRID_GetMode
 * address:  0x021A6DC0
 * packet:   pkt_021A6DC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field getter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18063.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELDMAP_CTRL_HYBRID_GetMode(u8 *p)
{
    return ((struct Obj18063 *)p)->f0;
}
