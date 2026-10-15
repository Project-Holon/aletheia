/*
 * function: RESEARCH_GRAPH_EnterDrawSlow
 * address:  0x021BDF58
 * packet:   pkt_ov217_021BDF58
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb
 *   RESEARCH_GRAPH_GetSubState  0x021BE4DC  thumb  ov217
 *   RESEARCH_GRAPH_IncSubState  0x021BE4E0  thumb  ov217
 *   RESEARCH_GRAPH_BuildGraphTable  0x021BFC60  thumb  ov217
 *   RESEARCH_GRAPH_ClearUpdatedFlag  0x021BF704  thumb  ov217
 *   RESEARCH_GRAPH_EnableOamsA  0x021BF568  thumb  ov217
 *   RESEARCH_GRAPH_SetSlicesFromGraphA  0x021BEC84  thumb  ov217
 *   RESEARCH_GRAPH_GetLeftCircle  0x021BF76C  thumb  ov217
 *   CircleGraph_SetEnabled  0x021C1184  thumb  ov217
 *   CircleGraph_QueueDrawSlow  0x021C1154  thumb  ov217
 *   RESEARCH_GRAPH_SetIndex  0x021BE930  thumb  ov217
 *   RESEARCH_GRAPH_LayoutActors  0x021BF3D8  thumb  ov217
 *   RESEARCH_GRAPH_LayoutTouchRects  0x021BEFF8  thumb  ov217
 *   RESEARCH_GRAPH_MoveToSelectedEntry  0x021BE7F0  thumb  ov217
 *   RESEARCH_GRAPH_DisableOams  0x021BF574  thumb  ov217
 *   RESEARCH_GRAPH_LoadBackground  0x021BF08C  thumb  ov217
 *   RESEARCH_GRAPH_PrintSliceLabel  0x021BF15C  thumb  ov217
 *   RESEARCH_GRAPH_PrintTimeLabel  0x021BF264  thumb  ov217
 *   RESEARCH_GRAPH_SetDetailLabelVisible  0x021BF3B4  thumb  ov217
 *   RESEARCH_GRAPH_PrintTeamLabel  0x021BF2FC  thumb  ov217
 *   RESEARCH_GRAPH_LayoutArrow  0x021BEEA4  thumb  ov217
 *   RESEARCH_GRAPH_SetTriangleActorVisible  0x021BF47C  thumb  ov217
 *   RESEARCH_GRAPH_DrawIndexCursor  0x021BE934  thumb  ov217
 *   RESEARCH_GRAPH_SetStateChanged  0x021BE448  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GFL_USE_IsAnySeBusy(void);
extern u32 RESEARCH_GRAPH_GetSubState(void *p);
extern void RESEARCH_GRAPH_IncSubState(void *p);
extern void RESEARCH_GRAPH_BuildGraphTable(char *p);
extern void RESEARCH_GRAPH_ClearUpdatedFlag(void *p);
extern void RESEARCH_GRAPH_EnableOamsA(void *p);
extern void RESEARCH_GRAPH_SetSlicesFromGraphA(u8 *p, int mode);
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern void CircleGraph_SetEnabled(u8 *h, u32 v);
extern void CircleGraph_QueueDrawSlow(u8 *h);

extern void RESEARCH_GRAPH_SetIndex(void *p, u32 v);
extern void RESEARCH_GRAPH_LayoutActors(char *p);
extern void RESEARCH_GRAPH_LayoutTouchRects(u8 *p);
extern u32 RESEARCH_GRAPH_MoveToSelectedEntry(u32 a0);
extern void RESEARCH_GRAPH_DisableOams(void *p);
extern void RESEARCH_GRAPH_LoadBackground(char *p);
extern void RESEARCH_GRAPH_PrintSliceLabel(char *p);
extern void RESEARCH_GRAPH_PrintTimeLabel(char *p);
extern void RESEARCH_GRAPH_SetDetailLabelVisible(char *p);
extern void RESEARCH_GRAPH_PrintTeamLabel(char *p);
extern void RESEARCH_GRAPH_LayoutArrow(char *p);
extern void RESEARCH_GRAPH_SetTriangleActorVisible(char *p);
extern int RESEARCH_GRAPH_DrawIndexCursor(char *p);
extern void RESEARCH_GRAPH_SetStateChanged(void *p);

void RESEARCH_GRAPH_EnterDrawSlow(u8 *p)
{
    switch (RESEARCH_GRAPH_GetSubState(p)) {
    case 0:
        RESEARCH_GRAPH_BuildGraphTable((char *)p);
        RESEARCH_GRAPH_ClearUpdatedFlag(p);
        RESEARCH_GRAPH_EnableOamsA(p);
        RESEARCH_GRAPH_SetSlicesFromGraphA(p, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphA(p, 1);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetLeftCircle(p), 1);
        CircleGraph_QueueDrawSlow(RESEARCH_GRAPH_GetLeftCircle(p));
        RESEARCH_GRAPH_IncSubState(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct Obj00021 *)p)->f28 >= 0x78)
                RESEARCH_GRAPH_IncSubState(p);
            else
                GFL_USE_PlaySeDefaultVolume(0x76B);
        }
        break;
    case 2:
        *(int *)&((struct Obj00021 *)p)->f3C8 = 1;
        RESEARCH_GRAPH_SetIndex(p, 1);
        RESEARCH_GRAPH_LayoutActors((char *)p);
        RESEARCH_GRAPH_LayoutTouchRects(p);
        RESEARCH_GRAPH_MoveToSelectedEntry((u32)p);
        RESEARCH_GRAPH_DisableOams(p);
        RESEARCH_GRAPH_LoadBackground((char *)p);
        RESEARCH_GRAPH_PrintSliceLabel((char *)p);
        RESEARCH_GRAPH_PrintTimeLabel((char *)p);
        RESEARCH_GRAPH_SetDetailLabelVisible((char *)p);
        RESEARCH_GRAPH_PrintTeamLabel((char *)p);
        RESEARCH_GRAPH_LayoutArrow((char *)p);
        RESEARCH_GRAPH_SetTriangleActorVisible((char *)p);
        if (((struct Obj00021 *)p)->f3CC == 0)
            RESEARCH_GRAPH_DrawIndexCursor((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x76C);
        RESEARCH_GRAPH_SetStateChanged(p);
        break;
    }
}
