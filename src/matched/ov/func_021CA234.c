/*
 * function: BSUBWAY_SCR_GetWinCount
 * address:  0x021CA234
 * packet:   pkt_021CA234
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 16-bit halfword at +0xe of the object.
 */
#include "../include/Obj18345.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 BSUBWAY_SCR_GetWinCount(u8 *p)
{
    return ((struct Obj18345 *)p)->fE;
}

