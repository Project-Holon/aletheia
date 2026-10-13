/*
 * function: FIELD_SUBSCREEN_IsIdle
 * address:  0x021A0ED4
 * packet:   pkt_021A0ED4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17989.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_SUBSCREEN_IsIdle(u32 a)
{
if (((struct Obj17989 *)((u8 *)(a)))->f8 == 0) {
    return 1;
}
return 0;
}

