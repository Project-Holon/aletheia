/*
 * function: func_021AD6A4
 * address:  0x021AD6A4
 * packet:   pkt_021AD6A4
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
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12097.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021ABE18(u32, u32, u32, u32);
extern u32 func_021C6628(u32, u32);

int func_021AD6A4(u32 a, u32 b, u32 c, u32 d)
{
return func_021C6628(func_021ABE18(*(u32 *)((u8 *)(((struct Obj12097 *)((u8 *)(b)))->f18)), b, c, d), ((struct Obj12097 *)((u8 *)(b)))->f10);
}

