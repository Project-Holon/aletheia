/*
 * function: func_021B7934
 * address:  0x021B7934
 * packet:   pkt_021B7934
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
 *   func_021B9464  0x021B9464  thumb  ov021
 *   func_021B87C8  0x021B87C8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18099.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021B87C8(u32, u32);
extern u16 *func_021B9464(u16 *p);

int func_021B7934(u32 a, u32 b)
{
((struct Obj18099 *)((u8 *)(a)))->f2 = 1;
func_021B9464((u16 *)(a + 80));
return func_021B87C8((a + 32), b);
}

