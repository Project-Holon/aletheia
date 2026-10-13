/*
 * function: FIELD_SUBSCREEN_RequestMode
 * address:  0x021A0F30
 * packet:   pkt_021A0F30
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
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12083.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A0EE4(u32, u32);

int FIELD_SUBSCREEN_RequestMode(u32 a, u32 b)
{
((struct Obj12083 *)((u8 *)(a)))->f4 = func_021A0EE4(a, b);
((struct Obj12083 *)((u8 *)(a)))->f8 = 1;
return 1;
}

