/*
 * function: RESEARCH_GRAPH_ToggleEntry
 * address:  0x021BE808
 * packet:   pkt_ov217_021BE808
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_AreCirclesIdle 0x021BF78C thumb ov217
 *   RESEARCH_GRAPH_SetGraphKind 0x021BF764 thumb ov217
 *   RESEARCH_GRAPH_LoadBackground 0x021BF08C thumb ov217
 *   RESEARCH_GRAPH_DrawIndexCursor 0x021BE934 thumb ov217
 *   RESEARCH_GRAPH_PrintSliceLabel 0x021BF15C thumb ov217
 *   RESEARCH_GRAPH_PrintTimeLabel 0x021BF264 thumb ov217
 *   RESEARCH_GRAPH_PrintTeamLabel 0x021BF2FC thumb ov217
 *   RESEARCH_GRAPH_SetTeamLabelVisible 0x021BF38C thumb ov217
 *   RESEARCH_GRAPH_SetDetailLabelVisible 0x021BF3B4 thumb ov217
 *   RESEARCH_GRAPH_SetTriangleActorVisible 0x021BF47C thumb ov217
 *   RESEARCH_GRAPH_SyncArrow 0x021BEAF8 thumb ov217
 *   RESEARCH_GRAPH_LayoutArrow 0x021BEEA4 thumb ov217
 *   RESEARCH_GRAPH_HideAllPercentages 0x021BEF98 thumb ov217
 *   RESEARCH_GRAPH_UpdatePercentages 0x021BEF30 thumb ov217
 *   RESEARCH_GRAPH_ShowPercentages 0x021BEFD4 thumb ov217
 *   CircleGraph_QueueErase 0x021C116C thumb ov217
 *   CircleGraph_HoldUpdate 0x021C118C thumb ov217
 *   CircleGraph_QueueDrawFast 0x021C1160 thumb ov217
 *   CircleGraph_SetEnabled 0x021C1184 thumb ov217
 *   RESEARCH_GRAPH_GetGroupValue 0x021BF810 thumb ov217
 *   RESEARCH_GRAPH_GetLeftCircle 0x021BF76C thumb ov217
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 RESEARCH_GRAPH_AreCirclesIdle(u32 a0);
extern void RESEARCH_GRAPH_SetGraphKind(void *p, u32 k);
extern void RESEARCH_GRAPH_LoadBackground(char *p);
extern int RESEARCH_GRAPH_DrawIndexCursor(char *p);
extern void RESEARCH_GRAPH_PrintSliceLabel(char *p);
extern void RESEARCH_GRAPH_PrintTimeLabel(char *p);
extern void RESEARCH_GRAPH_PrintTeamLabel(char *p);
extern void RESEARCH_GRAPH_SetTeamLabelVisible(char *p);
extern void RESEARCH_GRAPH_SetDetailLabelVisible(char *p);
extern void RESEARCH_GRAPH_SetTriangleActorVisible(char *p);
extern void RESEARCH_GRAPH_SyncArrow(u8 *p);
extern void RESEARCH_GRAPH_LayoutArrow(char *p);
extern void RESEARCH_GRAPH_HideAllPercentages(char *p);
extern void RESEARCH_GRAPH_UpdatePercentages(char *p);
extern void RESEARCH_GRAPH_ShowPercentages(char *p);
extern void CircleGraph_QueueErase(u8 *h);
extern void CircleGraph_HoldUpdate(u8 *h, u32 v);
extern void CircleGraph_QueueDrawFast(u8 *h);
extern void CircleGraph_SetEnabled(u8 *h, u32 v);
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);
void RESEARCH_GRAPH_ToggleEntry(char *p)
{
    int flag = 0;
    u32 k;
    if (RESEARCH_GRAPH_AreCirclesIdle((u32)p) == 0) {
        return;
    }
    if (((struct Obj00021 *)p)->f3C8 != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        CircleGraph_QueueErase(RESEARCH_GRAPH_GetLeftCircle(p));
        flag = 1;
    }
    switch (((struct Obj00021 *)p)->f2CC) {
    case 0:
        k = 1;
        break;
    case 1:
        k = 0;
        break;
    }
    RESEARCH_GRAPH_SetGraphKind(p, k);
    RESEARCH_GRAPH_LoadBackground(p);
    RESEARCH_GRAPH_DrawIndexCursor(p);
    RESEARCH_GRAPH_PrintSliceLabel(p);
    RESEARCH_GRAPH_PrintTimeLabel(p);
    RESEARCH_GRAPH_PrintTeamLabel(p);
    RESEARCH_GRAPH_SetTeamLabelVisible(p);
    RESEARCH_GRAPH_SetDetailLabelVisible(p);
    RESEARCH_GRAPH_SetTriangleActorVisible(p);
    RESEARCH_GRAPH_SyncArrow((u8 *)p);
    RESEARCH_GRAPH_LayoutArrow(p);
    RESEARCH_GRAPH_HideAllPercentages(p);
    if (((struct Obj00021 *)p)->f3C8 != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        RESEARCH_GRAPH_UpdatePercentages(p);
        RESEARCH_GRAPH_ShowPercentages(p);
    }
    if (((struct Obj00021 *)p)->f3C8 != 0 && RESEARCH_GRAPH_GetGroupValue(p) != 0) {
        if (flag != 0) {
            CircleGraph_HoldUpdate(RESEARCH_GRAPH_GetLeftCircle(p), 0x14);
        }
        CircleGraph_QueueDrawFast(RESEARCH_GRAPH_GetLeftCircle(p));
        CircleGraph_SetEnabled(RESEARCH_GRAPH_GetLeftCircle(p), 1);
    }
    GFL_USE_PlaySeDefaultVolume(0x548);
}
