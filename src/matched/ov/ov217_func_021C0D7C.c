/*
 * function: RESEARCH_COMMON_UpdatePaletteAnimeImpl
 * address:  0x021C0D7C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed getter, tail call to PALETTE_ANIME_Update.
 *
 * symbols:
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void PALETTE_ANIME_Update(u32);
void RESEARCH_COMMON_UpdatePaletteAnimeImpl(u32 *p)
{
    PALETTE_ANIME_Update(p[0xb]);
}

