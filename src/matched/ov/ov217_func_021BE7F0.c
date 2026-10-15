/*
 * function: RESEARCH_GRAPH_MoveToSelectedEntry
 * address:  0x021BE7F0
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
 *   RESEARCH_GRAPH_SetEntryFromSlice  0x021BEA54  thumb  ov217
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

extern void RESEARCH_GRAPH_SetEntryFromSlice(char *p);
extern u32 RESEARCH_GRAPH_LayoutArrow();
extern void RESEARCH_GRAPH_PrintSliceLabel(char *p);
u32 RESEARCH_GRAPH_MoveToSelectedEntry(u32 a0)
{
    RESEARCH_GRAPH_SetEntryFromSlice((char *)a0);
    RESEARCH_GRAPH_PrintSliceLabel((char *)a0);
    return RESEARCH_GRAPH_LayoutArrow(a0);
}

