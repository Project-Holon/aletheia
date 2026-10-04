/*
 * function: func_021B8220
 * address:  0x021B8220
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x14 of the object.
 */
#include "../include/Obj18107.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021B8220(u8 *p)
{
    return ((struct Obj18107 *)p)->f14;
}

