/*
 * function: func_021C0D14
 * address:  0x021C0D14
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
 *   func_021C29E8  0x021C29E8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25994.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C29E8();
u32 func_021C0D14(u8 *a0)
{
    return func_021C29E8(((struct Obj25994 *)(((u8*)a0)))->f2C, *(u32*)(((u8*)0x21C3F50)), *(u32*)(((u8*)0x21C3F50) + 4), *(u8*)(((u8*)0x21C3F50) + 8));
}

