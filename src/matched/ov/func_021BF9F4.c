/*
 * function: func_021BF9F4
 * address:  0x021BF9F4
 * packet:   pkt_021BF9F4
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
 *   func_02188D38  0x02188D38  thumb  ov021
 *   func_021C72AC  0x021C72AC  thumb  ov021
 *   func_021C6DE0  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01861.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188D38(u8 *p);
extern u32 func_021C6DE0(u32, u32, u32);
extern void *func_021C72AC(u32 a, u16 b, int c, int d);

int func_021BF9F4(u32 a, u32 b, u32 c, u32 d)
{
return func_021C6DE0(func_02188D38((u8 *)(((struct Obj01861 *)((u8 *)(a)))->f4)), (u32)func_021C72AC(((struct Obj01861 *)((u8 *)(a)))->f4, 60, 8, 1), 0);
}

