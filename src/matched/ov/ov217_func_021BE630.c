/*
 * function: RESEARCH_GRAPH_ApplySelection
 * address:  0x021BE630
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_SetIndex  0x021BE930  thumb  ov217
 *   RESEARCH_GRAPH_DrawIndexCursor  0x021BE934  thumb  ov217
 *   RESEARCH_GRAPH_DrawIndexCursorDim  0x021BE9B8  thumb  ov217
 *   RESEARCH_GRAPH_LayoutTouchRects  0x021BEFF8  thumb  ov217
 *   RESEARCH_GRAPH_LayoutActors  0x021BF3D8  thumb  ov217
 *   RESEARCH_GRAPH_LayoutMarkerActor  0x021BF4AC  thumb  ov217
 *   RESEARCH_GRAPH_GetGroupValue  0x021BF810  thumb  ov217
 *
 * Sub-state step for a1 in {1,2}, gated on the +0x3C8 handle being busy;
 * otherwise the fixed call list runs unconditionally.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_GRAPH_SetIndex(void *p, u32 v);
extern void RESEARCH_GRAPH_DrawIndexCursorDim(u8 *p);
extern int RESEARCH_GRAPH_DrawIndexCursor(char *p);
extern void RESEARCH_GRAPH_LayoutTouchRects(u8 *p);
extern void RESEARCH_GRAPH_LayoutActors(char *p);
extern void RESEARCH_GRAPH_LayoutMarkerActor(char *p);
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
void RESEARCH_GRAPH_ApplySelection(u8 *a0, u32 a1)
{
    if ((u32)(a1 - 1) <= 1) {
    if (((struct Obj00021 *)a0)->f3C8 == 0) {
    return;
    }
    if (RESEARCH_GRAPH_GetGroupValue(a0) == 0) {
    return;
    }
    }
    RESEARCH_GRAPH_DrawIndexCursorDim(a0);
    RESEARCH_GRAPH_SetIndex(a0, a1);
    RESEARCH_GRAPH_DrawIndexCursor((char *)a0);
    RESEARCH_GRAPH_LayoutActors((char *)a0);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)a0);
    RESEARCH_GRAPH_LayoutTouchRects(a0);
}
