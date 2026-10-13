/*
 * function: FIELD_PLACE_NAME_SetFont
 * address:  0x021BD09C
 * packet:   pkt_021BD09C
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
#include "../include/Obj18208.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void FIELD_PLACE_NAME_SetFont(u8 *p, u32 v)
{
    ((struct Obj18208 *)p)->f18 = v;
}
