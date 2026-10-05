/*
 * function: func_021CC060
 * address:  0x021CC060
 * packet:   pkt_021CC060
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Follows the pointer at +0x8, then loads the 32-bit word at +0x5c of its target.
 */
#include "../include/Obj01219.h"
#include "../include/Obj18350.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021CC060(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj01219 *)p)->f8;

    return ((struct Obj18350 *)q)->f5C;
}

