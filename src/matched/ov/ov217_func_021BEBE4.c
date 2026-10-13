/*
 * function: func_021BEBE4
 * address:  0x021BEBE4
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
 *   BMP_OAM_SetPalette  0x02025A54  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25917.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void BMP_OAM_SetPalette(u8 *g, u32 a);
extern u32 func_021BF594();
u32 func_021BEBE4(u32 a0)
{
    BMP_OAM_SetPalette((u8 *)(((struct Obj25917 *)(((u8*)a0)))->f3AC), 1);
    return func_021BF594(a0, 5);
}

