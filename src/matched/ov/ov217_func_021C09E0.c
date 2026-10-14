/*
 * function: RESEARCH_COMMON_StopPaletteAnime
 * address:  0x021C09E0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 0 to RESEARCH_COMMON_StopPaletteAnimeImpl.
 *
 * symbols:
 *   RESEARCH_COMMON_StopPaletteAnimeImpl  0x021C0D5C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RESEARCH_COMMON_StopPaletteAnimeImpl(u8 *p, u32 i);

void RESEARCH_COMMON_StopPaletteAnime(u32 a0)
{
    RESEARCH_COMMON_StopPaletteAnimeImpl((u8 *)a0, 0);
}

