/*
 * function: FIELD_FOG_SetColorA
 * address:  0x021A01CC
 * packet:   pkt_021A01CC
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
#include "../include/Obj12081.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

int FIELD_FOG_SetColorA(u32 a, u32 b)
{
((struct Obj12081 *)((u8 *)(a)))->f3 = b;
((struct Obj12081 *)((u8 *)(a)))->f40 = 1;
return a;
}

