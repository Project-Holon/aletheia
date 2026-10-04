/*
 * function: func_021BC8B4
 * address:  0x021BC8B4
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
 *   func_021BC8B4  0x021BC8B4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00025.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct GfFont;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
void func_021BC8B4(u32 a0)
{
    u8 s[4];
    *(u32 *)&((struct Obj00025 *)(((u8*)a0)))->fC = (u32)func_0201D7EC(23, 0, 0, 0, (u32)(((struct Obj00025 *)(((u8*)a0)))->f8));
}

