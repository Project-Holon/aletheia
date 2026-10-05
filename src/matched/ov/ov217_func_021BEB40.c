/*
 * function: func_021BEB40
 * address:  0x021BEB40
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BF594  0x021BF594  thumb  ov217
 *   func_021BF5BC  0x021BF5BC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25912.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02025A54(u8 *g, u32 a);
extern u32 func_021BF594();
extern void func_021BF5BC(u8 *a0, u32 a1);
u32 func_021BEB40(u32 a0)
{
    func_02025A54((u8 *)(((struct Obj25912 *)(((u8*)a0)))->f3AC), 0);
    func_021BF5BC((u8 *)a0, 5);
    func_021BF5BC((u8 *)a0, 6);
    return func_021BF594(a0, 2);
}

