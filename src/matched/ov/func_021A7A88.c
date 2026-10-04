/*
 * function: func_021A7A88
 * address:  0x021A7A88
 * packet:   pkt_021A7A88
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x14 of the object.
 */
#include "../include/Obj18066.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021A7A88(u8 *p)
{
    return ((struct Obj18066 *)p)->f14;
}

