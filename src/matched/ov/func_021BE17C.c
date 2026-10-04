/*
 * function: func_021BE17C
 * address:  0x021BE17C
 * packet:   pkt_021BE17C
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4 of the object.
 */
#include "../include/Obj18253.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021BE17C(u8 *p)
{
    return ((struct Obj18253 *)p)->f4;
}

