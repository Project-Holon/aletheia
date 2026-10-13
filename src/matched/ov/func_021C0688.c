/*
 * function: HEIGHT_EX_GetAreaCount
 * address:  0x021C0688
 * packet:   pkt_021C0688
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
#include "../include/Obj18267.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 HEIGHT_EX_GetAreaCount(u8 *p)
{
    return ((struct Obj18267 *)p)->f0;
}
