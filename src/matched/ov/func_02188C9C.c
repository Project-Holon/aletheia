/*
 * function: func_02188C9C
 * address:  0x02188C9C
 * packet:   pkt_02188C54
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Loads the halfword at byte +0xd8 of the object.
 */
#include "../include/Obj17866.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_02188C9C(u8 *p)
{
    return ((struct Obj17866 *)p)->fD8;
}

