/*
 * function: func_021B8248
 * address:  0x021B8248
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x4c of the object.
 */
#include "../include/Obj18108.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021B8248(u8 *p)
{
    return ((struct Obj18108 *)p)->f4C;
}

