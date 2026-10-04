/*
 * function: func_021ABEA0
 * address:  0x021ABEA0
 * packet:   pkt_021ABEA0
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
 *   func_021ABF2C  0x021ABF2C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021ABF2C(u32, u32);

int func_021ABEA0(u32 a, u32 b)
{
return ((struct Obj18084 *)((u8 *)(func_021ABF2C(a, b))))->f4;
}

