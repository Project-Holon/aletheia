/*
 * function: RESEARCH_GRAPH_SelectDirect
 * address:  0x021BE614
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_GRAPH_ApplySelection  0x021BE630  thumb  ov217
 *   RESEARCH_GRAPH_StartSlotPaletteAnime  0x021BF594  thumb  ov217
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 GFL_USE_PlaySeDefaultVolume();
extern void RESEARCH_GRAPH_ApplySelection(u8 *, u32);
extern void RESEARCH_GRAPH_StartSlotPaletteAnime(char *p, int i);
u32 RESEARCH_GRAPH_SelectDirect(u32 a0, u32 a1)
{
    RESEARCH_GRAPH_ApplySelection((u8 *)a0, a1);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)a0, 1);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

