/*
 * function: FIELD_3DBG_IsTextureLoaded
 * address:  0x021A1780
 * packet:   pkt_021A1780
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at +0x6 of the object.
 */
#include "../include/Obj17997.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 FIELD_3DBG_IsTextureLoaded(u8 *p)
{
    return ((struct Obj17997 *)p)->f6;
}

