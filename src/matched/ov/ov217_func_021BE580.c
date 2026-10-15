/*
 * function: RESEARCH_GRAPH_SelectNext
 * address: 0x021BE580
 * packet: pkt_ov217_021BE580
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   RESEARCH_GRAPH_DrawIndexCursorDim 0x021BE9B8 thumb ov217
 *   RESEARCH_GRAPH_CycleIndex 0x021BE91C thumb ov217
 *   RESEARCH_GRAPH_GetGroupValue 0x021BF810 thumb ov217
 *   RESEARCH_GRAPH_DrawIndexCursor 0x021BE934 thumb ov217
 *   RESEARCH_GRAPH_LayoutActors 0x021BF3D8 thumb ov217
 *   RESEARCH_GRAPH_LayoutMarkerActor 0x021BF4AC thumb ov217
 *   RESEARCH_GRAPH_StartSlotPaletteAnime 0x021BF594 thumb ov217
 *   RESEARCH_GRAPH_SetHighlightC 0x021BEBA4 thumb ov217
 *   RESEARCH_GRAPH_LayoutTouchRects 0x021BEFF8 thumb ov217
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void RESEARCH_GRAPH_DrawIndexCursorDim(u8 *);
extern void RESEARCH_GRAPH_CycleIndex(char *,int);
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
extern int RESEARCH_GRAPH_DrawIndexCursor(char *);
extern void RESEARCH_GRAPH_LayoutActors(char *p);
extern void RESEARCH_GRAPH_LayoutMarkerActor(char *p);
extern void RESEARCH_GRAPH_StartSlotPaletteAnime(char *p, int i);
extern u32 RESEARCH_GRAPH_SetHighlightC(u32);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_GRAPH_LayoutTouchRects(u8 *p);
void RESEARCH_GRAPH_SelectNext(u8 *p)
{
    int repeat=1;
    RESEARCH_GRAPH_DrawIndexCursorDim(p);
    RESEARCH_GRAPH_CycleIndex((char *)p,1);
    do {
        u32 index=((struct Obj00021 *)p)->f34;
        if (index-1<=1) {
            if (((struct Obj00021 *)p)->f3C8==0 || RESEARCH_GRAPH_GetGroupValue(p)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)p,1);
            } else repeat=0;
        } else if (index==4) {
            if (((struct Obj00021 *)p)->f3C8==1 || RESEARCH_GRAPH_GetGroupValue(p)==0) {
                RESEARCH_GRAPH_CycleIndex((char *)p,1);
            } else repeat=0;
        } else repeat=0;
    } while(repeat);
    RESEARCH_GRAPH_DrawIndexCursor((char *)p);
    RESEARCH_GRAPH_LayoutActors((char *)p);
    RESEARCH_GRAPH_LayoutMarkerActor((char *)p);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)p,1);
    if (((struct Obj00021 *)p)->f34==4) RESEARCH_GRAPH_SetHighlightC((u32)p);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_GRAPH_LayoutTouchRects(p);
}
