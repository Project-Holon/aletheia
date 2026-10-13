/*
 * function: FIELD_PLACE_NAME_ReleaseClactPalette
 * address:  0x021BC788
 * packet:   pkt_021BC788
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x2c.
 *
 * symbols:
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18190.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void CLACT_ReleasePalette(u32 i);

void FIELD_PLACE_NAME_ReleaseClactPalette(u8 *p)
{
    CLACT_ReleasePalette(((struct Obj18190 *)p)->f2C);
}
