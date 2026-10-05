/*
 * function: func_021A2E90
 * address:  0x021A2E90
 * packet:   pkt_021A2E90
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
 *   func_021A41A8  0x021A41A8  thumb  ov021
 *   func_021A5920  0x021A5920  thumb  ov021
 *   func_021A3810  0x021A3810  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05861.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_020307B0(u32);
extern u32 func_021A3810(u32);
extern u32 func_021A41A8(u32, u32, u32, u32);
extern u32 func_021A5920(u32);

int func_021A2E90(u32 a, u32 b, u32 c, u32 d)
{
if (((struct Obj05861 *)((u8 *)(a)))->f8 != 0) {
    func_021A41A8(((struct Obj05861 *)((u8 *)(a)))->f8, b, c, d);
}
if (((struct Obj05861 *)((u8 *)(a)))->fC != 0) {
    func_021A5920(((struct Obj05861 *)((u8 *)(a)))->fC);
}
func_021A3810(((struct Obj05861 *)((u8 *)(a)))->f4);
return func_020307B0(a);
}

