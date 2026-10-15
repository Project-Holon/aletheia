/*
 * function: RESEARCH_GRAPH_EnterDrawMedium
 * address:  0x021BE108
 * packet:   pkt_ov217_021BE108
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_GetSubState 0x021BE4DC thumb ov217
 *   RESEARCH_GRAPH_SetSlicesFromGraphB 0x021BED10 thumb ov217
 *   CircleGraph_SetEnabled 0x021C1184 thumb ov217
 *   CircleGraph_QueueDrawMedium 0x021C1178 thumb ov217
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RESEARCH_GRAPH_ClearUpdatedFlag 0x021BF704 thumb ov217
 *   RESEARCH_GRAPH_ResetTimer 0x021BF728 thumb ov217
 *   RESEARCH_GRAPH_BuildGraphTable 0x021BFC60 thumb ov217
 *   RESEARCH_GRAPH_LoadBackground 0x021BF08C thumb ov217
 *   RESEARCH_GRAPH_PrintSliceLabel 0x021BF15C thumb ov217
 *   RESEARCH_GRAPH_SetDetailLabelVisible 0x021BF3B4 thumb ov217
 *   RESEARCH_GRAPH_SetTeamLabelVisible 0x021BF38C thumb ov217
 *   RESEARCH_GRAPH_LayoutArrow 0x021BEEA4 thumb ov217
 *   RESEARCH_GRAPH_LayoutActors 0x021BF3D8 thumb ov217
 *   RESEARCH_GRAPH_HideAllPercentages 0x021BEF98 thumb ov217
 *   RESEARCH_GRAPH_SetCenterDepth 0x021BEC64 thumb ov217
 *   RESEARCH_GRAPH_IncSubState 0x021BE4E0 thumb ov217
 *   RESEARCH_GRAPH_SwapCenterPairs 0x021BEC0C thumb ov217
 *   RESEARCH_GRAPH_PrintTimeLabel 0x021BF264 thumb ov217
 *   RESEARCH_GRAPH_PrintTeamLabel 0x021BF2FC thumb ov217
 *   RESEARCH_GRAPH_LayoutMarkerActor 0x021BF4AC thumb ov217
 *   RESEARCH_GRAPH_SetTriangleActorVisible 0x021BF47C thumb ov217
 *   RESEARCH_GRAPH_SetStateChanged 0x021BE448 thumb ov217
 *   RESEARCH_GRAPH_GetRightCircle 0x021BF77C thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 RESEARCH_GRAPH_GetSubState(void *p);
extern u8 *RESEARCH_GRAPH_GetRightCircle(void *p);
extern void RESEARCH_GRAPH_SetSlicesFromGraphB(u8 *p, u32 mode);
extern void CircleGraph_SetEnabled(u8 *h, u32 v);
extern void CircleGraph_QueueDrawMedium(u8 *h);

extern int GFL_USE_IsAnySeBusy(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_GRAPH_ClearUpdatedFlag(void *p);
extern void RESEARCH_GRAPH_ResetTimer(void *p);
extern void RESEARCH_GRAPH_BuildGraphTable(char *p);
extern void RESEARCH_GRAPH_LoadBackground(char *p);
extern void RESEARCH_GRAPH_PrintSliceLabel(char *p);
extern void RESEARCH_GRAPH_SetDetailLabelVisible(char *p);
extern void RESEARCH_GRAPH_SetTeamLabelVisible(char *p);
extern void RESEARCH_GRAPH_LayoutArrow(char *p);
extern void RESEARCH_GRAPH_LayoutActors(char *p);
extern void RESEARCH_GRAPH_HideAllPercentages(char *p);
extern void RESEARCH_GRAPH_SetCenterDepth(void *p);
extern void RESEARCH_GRAPH_IncSubState(void *p);
extern void RESEARCH_GRAPH_SwapCenterPairs(void *p);
extern void RESEARCH_GRAPH_PrintTimeLabel(char *p);
extern void RESEARCH_GRAPH_PrintTeamLabel(char *p);
extern void RESEARCH_GRAPH_LayoutMarkerActor(char *p);
extern void RESEARCH_GRAPH_SetTriangleActorVisible(char *p);
extern void RESEARCH_GRAPH_SetStateChanged(void *p);
void RESEARCH_GRAPH_EnterDrawMedium(char *p)
{
    switch (RESEARCH_GRAPH_GetSubState(p)) {
    case 0:
        ((struct Obj00021 *)p)->f3D0 = 1;
        RESEARCH_GRAPH_ClearUpdatedFlag(p);
        RESEARCH_GRAPH_ResetTimer(p);
        RESEARCH_GRAPH_BuildGraphTable(p);
        RESEARCH_GRAPH_LoadBackground(p);
        RESEARCH_GRAPH_PrintSliceLabel(p);
        RESEARCH_GRAPH_SetDetailLabelVisible(p);
        RESEARCH_GRAPH_SetTeamLabelVisible(p);
        RESEARCH_GRAPH_LayoutArrow(p);
        RESEARCH_GRAPH_LayoutActors(p);
        RESEARCH_GRAPH_HideAllPercentages(p);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)p, 0);
        RESEARCH_GRAPH_SetSlicesFromGraphB((u8 *)p, 1);
        RESEARCH_GRAPH_SetCenterDepth(p);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetRightCircle(p), 1);
        CircleGraph_QueueDrawMedium(RESEARCH_GRAPH_GetRightCircle(p));
        RESEARCH_GRAPH_IncSubState(p);
        break;
    case 1:
        if (GFL_USE_IsAnySeBusy() == 0) {
            if (((struct Obj00021 *)p)->f28 >= 0x3c) {
                RESEARCH_GRAPH_IncSubState(p);
                return;
            }
            GFL_USE_PlaySeDefaultVolume(0x76b);
        }
        break;
    case 2:
        ((struct Obj00021 *)p)->f3D0 = 0;
        RESEARCH_GRAPH_SwapCenterPairs(p);
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetRightCircle(p), 0);
        RESEARCH_GRAPH_LoadBackground(p);
        RESEARCH_GRAPH_SetDetailLabelVisible(p);
        RESEARCH_GRAPH_PrintSliceLabel(p);
        RESEARCH_GRAPH_PrintTimeLabel(p);
        RESEARCH_GRAPH_PrintTeamLabel(p);
        RESEARCH_GRAPH_LayoutArrow(p);
        RESEARCH_GRAPH_LayoutActors(p);
        RESEARCH_GRAPH_LayoutMarkerActor(p);
        RESEARCH_GRAPH_SetTriangleActorVisible(p);
        GFL_USE_PlaySeDefaultVolume(0x76c);
        RESEARCH_GRAPH_SetStateChanged(p);
        break;
    }
}
