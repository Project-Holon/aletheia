/*
 * function: FLD_SCENEAREA_SetEnabled
 * address:  0x021AB75C
 * packet:   pkt_021AB75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x18.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18074.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FLD_SCENEAREA_SetEnabled(u8 *p, u32 v)
{
    ((struct Obj18074 *)p)->f18 = v;
}
