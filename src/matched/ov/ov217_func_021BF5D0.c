/*
 * function: RESEARCH_GRAPH_IsSlotPaletteAnimeRunning
 * address:  0x021BF5D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4) to PALETTE_ANIME_IsRunning.
 *
 * symbols:
 *   PALETTE_ANIME_IsRunning  0x021C2A10  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void PALETTE_ANIME_IsRunning(u32, u32);

void RESEARCH_GRAPH_IsSlotPaletteAnimeRunning(u8 *a0, u32 a1)
{
    PALETTE_ANIME_IsRunning((u32)(*(u32*)(a0 + (a1)*4 + 804)), (u32)(a0 + (a1)*4));
}

