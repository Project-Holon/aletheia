/*
 * function: FIELD_G3D_MAP_SetVisible
 * address:  0x021694F8
 * packet:   pkt_021694F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the halfword at p.
 *
 * symbols:
 *   (none)

 * Addresses are Black-image addresses.
 */
#include "../include/Obj17742.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;


void FIELD_G3D_MAP_SetVisible(u8 *p, u16 v)
{
    ((struct Obj17742 *)p)->f0 = v;
}

