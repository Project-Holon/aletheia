/*
 * function: func_02188C5C
 * address:  0x02188C5C
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x3c of the object.
 */
#include "../include/Obj17859.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02188C5C(u8 *p)
{
    return ((struct Obj17859 *)p)->f3C;
}

