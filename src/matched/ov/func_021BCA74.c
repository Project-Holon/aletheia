/*
 * function: func_021BCA74
 * address:  0x021BCA74
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x48 of the object.
 */
#include "../include/Obj18197.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021BCA74(u8 *p)
{
    return ((struct Obj18197 *)p)->f48;
}

