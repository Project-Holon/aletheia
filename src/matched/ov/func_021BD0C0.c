/*
 * function: func_021BD0C0
 * address:  0x021BD0C0
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the byte at byte +0x40 of the object.
 */
#include "../include/Obj18210.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u8 func_021BD0C0(u8 *p)
{
    return ((struct Obj18210 *)p)->f40;
}

