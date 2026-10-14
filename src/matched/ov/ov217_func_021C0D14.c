/*
 * function: RESEARCH_COMMON_BindPaletteAnime
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
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
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

extern u32 PALETTE_ANIME_Bind();
u32 RESEARCH_COMMON_BindPaletteAnime(u8 *a0)
{
    return PALETTE_ANIME_Bind(((struct Obj25994 *)(((u8*)a0)))->f2C, *(u32*)(((u8*)0x21C3F50)), *(u32*)(((u8*)0x21C3F50) + 4), *(u8*)(((u8*)0x21C3F50) + 8));
}

