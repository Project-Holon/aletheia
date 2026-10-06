/*
 * function: func_021A2FD0
 * address:  0x021A2FD0
 * packet:   pkt_021A2FD0
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
 *   func_021A3CB0  0x021A3CB0  thumb  ov021
 *   func_021A3CE8  0x021A3CE8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00614.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int func_021A3CB0(u32 a, u32 b);
extern u32 func_021A3CE8(u32);

int func_021A2FD0(u32 a, u32 b, u32 c, u32 d)
{
func_021A3CB0(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4, 1);
return func_021A3CE8(*(u32 *)&((struct Obj00614 *)((u8 *)(a)))->f4);
}

