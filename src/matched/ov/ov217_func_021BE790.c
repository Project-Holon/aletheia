/*
 * function: RESEARCH_GRAPH_MoveEntryForward
 * address:  0x021BE790
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
 *   RESEARCH_GRAPH_StepEntry  0x021BEA8C  thumb  ov217
 *   RESEARCH_GRAPH_LayoutArrow  0x021BEEA4  thumb  ov217
 *   RESEARCH_GRAPH_PrintSliceLabel  0x021BF15C  thumb  ov217
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
extern void RESEARCH_GRAPH_StepEntry(u8 *p, int step);
extern void RESEARCH_GRAPH_LayoutArrow(char *p);
extern void RESEARCH_GRAPH_PrintSliceLabel(char *p);
u32 RESEARCH_GRAPH_MoveEntryForward(u32 a0)
{
    RESEARCH_GRAPH_StepEntry((u8 *)a0, 1);
    RESEARCH_GRAPH_PrintSliceLabel((char *)a0);
    RESEARCH_GRAPH_LayoutArrow((char *)a0);
    return GFL_USE_PlaySeDefaultVolume(1352);
}

