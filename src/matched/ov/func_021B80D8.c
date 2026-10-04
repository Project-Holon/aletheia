/*
 * function: func_021B80D8
 * address:  0x021B80D8
 * packet:   pkt_021B8038
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Follows the pointer at +0x4, then loads the 32-bit word at +0x8 of its target.
 */
#include "../include/Obj00454.h"
#include "../include/Obj18105.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021B80D8(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj00454 *)p)->f4;

    return ((struct Obj18105 *)q)->f8;
}

