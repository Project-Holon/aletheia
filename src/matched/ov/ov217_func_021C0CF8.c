/*
 * function: func_021C0CF8
 * address:  0x021C0CF8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021C29C8  0x021C29C8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00791.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_021C29C8(u32 a0);
void func_021C0CF8(u32 a0)
{
    ((struct Obj00791 *)(((u8*)a0 + 0)))->f2C = func_021C29C8(((struct Obj00791 *)((u8*)a0))->f0);
}

