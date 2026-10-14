/*
 * function: PALETTE_ANIME_Alloc
 * address:  0x021C2DA0
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
 *   PALETTE_ANIME_Alloc  0x021C2DA0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26037.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 PALETTE_ANIME_Alloc(u32 a0)
{
    u8 s[4];
    u32 p1 = (u32)func_02030734(a0, 32, 0, (const char *)0x21C408C, 667);
    ((struct Obj26037 *)((u8*)p1))->f0 = a0;
    return p1;
}

