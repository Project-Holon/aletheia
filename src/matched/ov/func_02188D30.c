/*
 * function: func_02188D30
 * address:  0x02188D30
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Loads the 32-bit word at byte +0x110 of the object.
 */
#include "../include/Obj17878.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_02188D30(u8 *p)
{
    return ((struct Obj17878 *)p)->f110;
}

