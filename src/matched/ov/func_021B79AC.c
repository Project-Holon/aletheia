/*
 * function: func_021B79AC
 * address:  0x021B79AC
 * packet:   pkt_021B79AC
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
 *   func_021B9164  0x021B9164  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01358.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_021B9164(u32, u32, u32, u32);

int func_021B79AC(u32 a, u32 b, u32 c, u32 d)
{
func_021B9164(b, (a + 32), a, d);
((struct Obj01358 *)((u8 *)(b)))->f2 = 0;
return 0;
}

