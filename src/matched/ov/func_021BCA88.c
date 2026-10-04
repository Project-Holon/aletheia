/*
 * function: func_021BCA88
 * address:  0x021BCA88
 * packet:   pkt_021BCA74
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4c of the object.
 */
#include "../include/Obj18200.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021BCA88(u8 *p)
{
    return ((struct Obj18200 *)p)->f4C;
}

