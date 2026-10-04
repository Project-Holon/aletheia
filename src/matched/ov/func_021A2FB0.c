/*
 * function: func_021A2FB0
 * address:  0x021A2FB0
 * packet:   pkt_021A2FB0
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
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_021A5778  0x021A5778  thumb  ov021
 *   func_021A59DC  0x021A59DC  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj09180.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02188CFC(u32, u32, u32, u32);
extern int func_021A5778(u32 a);
extern int func_021A59DC(u32 a);

int func_021A2FB0(u32 a, u32 b, u32 c, u32 d)
{
if (func_02188CFC(((struct Obj09180 *)((u8 *)(a)))->f0, b, c, d) == 0) {
    return func_021A5778(((struct Obj09180 *)((u8 *)(a)))->f8);
}
return func_021A59DC(((struct Obj09180 *)((u8 *)(a)))->fC);
}

