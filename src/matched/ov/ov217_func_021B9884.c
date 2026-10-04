/*
 * function: func_021B9884
 * address:  0x021B9884
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
 *   func_021C099C  0x021C099C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08431.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C099C(u32 a0);
u32 func_021B9884(u32 a0)
{
    func_021C099C(((struct Obj08431 *)(((u8*)a0)))->fC);
    ((struct Obj08431 *)(((u8*)a0)))->fC = 0;
    return 0;
}

