/*
 * function: func_021BD5B4
 * address:  0x021BD5B4
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
 *   func_021BD5B4  0x021BD5B4  thumb  ov217
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25893.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void func_021BD5B4(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct Obj25893 *)(((u8*)a0 + 0)))->f8);
}

