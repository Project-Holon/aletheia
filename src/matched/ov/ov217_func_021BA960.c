/*
 * function: func_021BA960
 * address:  0x021BA960
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BA960  0x021BA960  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10954.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_0204AFD8();
u32 func_021BA960(u32 a0)
{
    func_0204A8D4(((struct Obj10954 *)(((u8*)a0)))->f68);
    func_0204ADA4(((struct Obj10954 *)(((u8*)a0)))->f6C);
    return func_0204AFD8(((struct Obj10954 *)(((u8*)a0)))->f70);
}

