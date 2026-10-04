/*
 * function: func_021BEBA4
 * address:  0x021BEBA4
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
 *   func_021BF594  0x021BF594  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25915.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02025A54(u8 *g, u32 a);
extern u32 func_021BF594();
u32 func_021BEBA4(u32 a0)
{
    func_02025A54((u8 *)(((struct Obj25915 *)(((u8*)a0)))->f3AC), 0);
    return func_021BF594(a0, 4);
}

