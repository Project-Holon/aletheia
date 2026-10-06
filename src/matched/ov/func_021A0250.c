/*
 * function: func_021A0250
 * address:  0x021A0250
 * packet:   pkt_021A0250
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12082.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int func_021A0250(u32 a)
{
if (((struct Obj12082 *)((u8 *)(a)))->f0 < ((struct Obj12082 *)((u8 *)(a)))->f2) {
    return 1;
}
return 0;
}

