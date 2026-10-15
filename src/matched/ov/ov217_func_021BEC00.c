/*
 * function: RESEARCH_GRAPH_StartPaletteAnime
 * address:  0x021BEC00
 * packet:   pkt_ov217_021BEC00
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_COMMON_StartPaletteAnime 0x021C09D8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char  u8;
extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);
void RESEARCH_GRAPH_StartPaletteAnime(u32 *p)
{
    RESEARCH_COMMON_StartPaletteAnime((u8 *)(*p), 0);
}
