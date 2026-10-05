/*
 * function: func_02190758
 * address:  0x02190758
 * packet:   pkt_02190758
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
 *   func_02190590  0x02190590  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17927.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02190590(u32, u32, u32, u32);

int func_02190758(u32 a, u32 b, u32 c, u32 d)
{
return func_02190590(((struct Obj17927 *)((u8 *)(a)))->f4, b, c, d);
}

