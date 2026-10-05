/*
 * function: func_021AC514
 * address:  0x021AC514
 * packet:   pkt_021AC514
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
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12096.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021ABE18(u32, u32, u32, u32);
extern u32 func_021C6580(u32, u32);

int func_021AC514(u32 a, u32 b, u32 c, u32 d)
{
return func_021C6580(func_021ABE18(((struct Obj12096 *)((u8 *)(a)))->f0, b, c, d), ((struct Obj12096 *)((u8 *)(a)))->f4);
}

