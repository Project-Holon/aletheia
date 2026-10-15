/*
 * function: RESEARCH_LIST_StartPaletteAnime
 * address: 0x021BC574
 * packet: pkt_ov217_021BC574
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   RESEARCH_COMMON_StartPaletteAnime 0x021C09D8 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);

void RESEARCH_LIST_StartPaletteAnime(u8 **p, u32 i)
{
    RESEARCH_COMMON_StartPaletteAnime(*p, i);
}
