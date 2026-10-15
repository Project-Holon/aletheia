/*
 * function: RESEARCH_TOP_StartPaletteAnime
 * address:  0x021BA31C
 * packet:   pkt_ov217_021BA31C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing.
 *
 * Promoted by the recursive unblocker lane: the +0008 ABS32 RESEARCH_COMMON_StartPaletteAnime
 * pool word now resolves as `matched` against layout/matched/ov217/
 * pkt_ov217_021C09D8.json, which was built bottom-up
 * (PALETTE_ANIME_StartImpl -> PALETTE_ANIME_Start -> RESEARCH_COMMON_StartPaletteAnimeImpl -> RESEARCH_COMMON_StartPaletteAnime).
 *
 * symbols:
 *   RESEARCH_COMMON_StartPaletteAnime  0x021C09D8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25816.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);
void RESEARCH_TOP_StartPaletteAnime(u8 *a0)
{
    RESEARCH_COMMON_StartPaletteAnime((u8 *)(((struct Obj25816 *)((u8*)a0))->f0), 0);
}
