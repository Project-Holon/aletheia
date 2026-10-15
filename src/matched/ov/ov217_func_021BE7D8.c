/*
 * function: RESEARCH_GRAPH_MoveToFirstEntry
 * address:  0x021BE7D8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_GRAPH_ClearEntryIndex  0x021BEAEC  thumb  ov217
 *   RESEARCH_GRAPH_LayoutArrow  0x021BEEA4  thumb  ov217
 *   RESEARCH_GRAPH_PrintSliceLabel  0x021BF15C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_GRAPH_ClearEntryIndex(u8 *);
extern u32 RESEARCH_GRAPH_LayoutArrow();
extern void RESEARCH_GRAPH_PrintSliceLabel(char *p);
u32 RESEARCH_GRAPH_MoveToFirstEntry(u32 a0)
{
    RESEARCH_GRAPH_ClearEntryIndex((u8 *)a0);
    RESEARCH_GRAPH_PrintSliceLabel((char *)a0);
    return RESEARCH_GRAPH_LayoutArrow(a0);
}

