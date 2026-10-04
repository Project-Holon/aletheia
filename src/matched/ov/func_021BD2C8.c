/*
 * function: func_021BD2C8
 * address:  0x021BD2C8
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the halfword at byte +0x48 of the object.
 */
#include "../include/Obj18221.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_021BD2C8(u8 *p)
{
    return ((struct Obj18221 *)p)->f48;
}

