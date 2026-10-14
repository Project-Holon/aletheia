/*
 * function: RESEARCH_COMMON_UpdatePaletteAnime
 * address:  0x021C09D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards its first argument to RESEARCH_COMMON_UpdatePaletteAnimeImpl.
 *
 * symbols:
 *   RESEARCH_COMMON_UpdatePaletteAnimeImpl  0x021C0D7C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void RESEARCH_COMMON_UpdatePaletteAnimeImpl(u32 *p);

void RESEARCH_COMMON_UpdatePaletteAnime(u32 a0)
{
    RESEARCH_COMMON_UpdatePaletteAnimeImpl((u32 *)a0);
}

