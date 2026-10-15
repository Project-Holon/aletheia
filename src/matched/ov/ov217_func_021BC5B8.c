/*
 * function: RESEARCH_LIST_IsListPaletteAnimeRunning
 * address:  0x021BC5B8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALETTE_ANIME_IsRunning  0x021C2A10  thumb  ov217
 *
 * Reports whether the a1-th entry of the +0x9c handle array is still
 * active.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 PALETTE_ANIME_IsRunning();
u32 RESEARCH_LIST_IsListPaletteAnimeRunning(u32 a0, u32 a1)
{
    if (PALETTE_ANIME_IsRunning(*(u32*)(((u8*)a0 + ((u32)a1 << 2) + 156))) == 0) {
    return 1;
    }
    return 0;
}
