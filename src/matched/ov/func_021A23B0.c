/*
 * function: func_021A23B0
 * address:  0x021A23B0
 * packet:   pkt_021A23B0
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
 *   func_021A0244  0x021A0244  thumb  ov021
 *   func_021A2CF8  0x021A2CF8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18002.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021A0244(u32, u32, u32, u32);
extern u8 func_021A2CF8(char *p);

int func_021A23B0(u32 a, u32 b, u32 c, u32 d)
{
if (func_021A0244(((struct Obj18002 *)((u8 *)(a)))->f4, b, c, d) != 0) {
    return 0;
}
if (func_021A2CF8((char *)a) == 0) {
    return 1;
}
return 0;
}

