/*
 * function: func_02190B1C
 * address:  0x02190B1C
 * packet:   pkt_02190B1C
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
 *   func_0201F73C  0x0201F73C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17931.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0201F73C(u32, u32, u32, u32);

int func_02190B1C(u32 a)
{
return func_0201F73C(((struct Obj17931 *)((u8 *)(a)))->f8, 0, 1, 13);
}

