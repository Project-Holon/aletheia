/*
 * function: RESEARCH_COMMON_CreatePaletteAnime
 * address:  0x021C0CF8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
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

extern u32 PALETTE_ANIME_Create(u32 a0);
void RESEARCH_COMMON_CreatePaletteAnime(u32 a0)
{
    ((struct Obj00791 *)(((u8*)a0 + 0)))->f2C = PALETTE_ANIME_Create(((struct Obj00791 *)((u8*)a0))->f0);
}

