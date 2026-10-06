/*
 * function: func_021B7954
 * address:  0x021B7954
 * packet:   pkt_021B7954
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
 *   func_021B87BC  0x021B87BC  thumb  ov021
 *   func_021B9464  0x021B9464  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18100.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void func_021B87BC(u32 a);
extern u32 func_021B9464(u32);

u32 func_021B7954(u32 a)
{
((struct Obj18100 *)((u8 *)(a)))->f2 = 0;
func_021B87BC((a + 32));
return func_021B9464((a + 80));
}

