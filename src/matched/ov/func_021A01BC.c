/*
 * function: FIELD_FOG_SetOffset
 * address:  0x021A01BC
 * packet:   pkt_021A01BC
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
#include "../include/Obj07212.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_FOG_SetOffset(u32 a, u32 b)
{
((struct Obj07212 *)((u8 *)(a)))->f4 = b;
((struct Obj07212 *)((u8 *)(a)))->f40 = 1;
return a;
}

