/*
 * function: func_021A398C
 * address:  0x021A398C
 * packet:   pkt_021A36E0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x18 of the object.
 */
#include "../include/Obj18043.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021A398C(u8 *p)
{
    return ((struct Obj18043 *)p)->f18;
}

