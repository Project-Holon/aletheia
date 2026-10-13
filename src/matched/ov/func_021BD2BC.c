/*
 * function: PLACE_NAME_LETTER_SetHeapId
 * address:  0x021BD2BC
 * packet:   pkt_021BD2BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field setter at +0x0.
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18218.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void PLACE_NAME_LETTER_SetHeapId(u8 *p, int v)
{
    ((struct Obj18218 *)p)->f0 = v;
}
