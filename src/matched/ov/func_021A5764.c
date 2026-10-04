/*
 * function: func_021A5764
 * address:  0x021A5764
 * packet:   pkt_021A5728
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x1c of the object.
 */
#include "../include/Obj18051.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021A5764(u8 *p)
{
    return ((struct Obj18051 *)p)->f1C;
}

