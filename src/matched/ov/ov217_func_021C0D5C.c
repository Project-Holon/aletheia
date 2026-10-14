/*
 * function: RESEARCH_COMMON_StopPaletteAnimeImpl
 * address:  0x021C0D5C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed getter, tail call to PALETTE_ANIME_Stop.
 *
 * symbols:
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void PALETTE_ANIME_Stop(u32);
void RESEARCH_COMMON_StopPaletteAnimeImpl(u8 *p, u32 i)
{
    PALETTE_ANIME_Stop(*(u32 *)(p + i * 4 + 0x2c));
}

