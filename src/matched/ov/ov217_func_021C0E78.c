/*
 * function: func_021C0E78
 * address:  0x021C0E78
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
 *   func_021C0E78  0x021C0E78  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06714.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_021C0E78(u32 a0, u32 a1, u32 a2)
{
    ((struct Obj06714 *)((u8*)a0))->f0 = (u32)func_02030734(a2, ((u32)a1 << 2), 0, (const char *)0x21C4050, 211);
    ((struct Obj06714 *)(((u8*)a0)))->f4 = a1;
}

