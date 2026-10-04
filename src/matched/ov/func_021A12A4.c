/*
 * function: func_021A12A4
 * address:  0x021A12A4
 * packet:   pkt_021A12A4
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
 *   func_021A0F90  0x021A0F90  thumb  ov021
 *   func_021A8E10  0x021A8E10  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17993.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A0F90(u32, u32, u32, u32);
extern u32 func_021A8E10(u32);

int func_021A12A4(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A0F90(a, b, c, d) != 1) {
    return 0;
}
return func_021A8E10(((struct Obj17993 *)((u8 *)(a)))->f20);
}

