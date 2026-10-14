/*
 * function: RESEARCH_COMMON_DestroyPaletteAnime
 * address:  0x021C0D08
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 44)) to PALETTE_ANIME_Destroy.
 *
 * symbols:
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25993.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 PALETTE_ANIME_Destroy(void *a0);

void RESEARCH_COMMON_DestroyPaletteAnime(u8 *a0)
{
    PALETTE_ANIME_Destroy((void *)(((struct Obj25993 *)a0)->f2C));
}

