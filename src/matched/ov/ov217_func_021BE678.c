/*
 * function: RESEARCH_GRAPH_MoveGroupBackward
 * address:  0x021BE678
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   RESEARCH_GRAPH_MoveToFirstEntry  0x021BE7D8  thumb  ov217
 *   RESEARCH_GRAPH_DrawIndexCursor  0x021BE934  thumb  ov217
 *   RESEARCH_GRAPH_CycleGroup  0x021BEA3C  thumb  ov217
 *   RESEARCH_GRAPH_SyncArrow  0x021BEAF8  thumb  ov217
 *   RESEARCH_GRAPH_HideAllPercentages  0x021BEF98  thumb  ov217
 *   RESEARCH_GRAPH_LoadBackground  0x021BF08C  thumb  ov217
 *   RESEARCH_GRAPH_PrintGroupLabel  0x021BF11C  thumb  ov217
 *   RESEARCH_GRAPH_PrintKindLabel  0x021BF13C  thumb  ov217
 *   RESEARCH_GRAPH_PrintTimeLabel  0x021BF264  thumb  ov217
 *   RESEARCH_GRAPH_PrintTeamLabel  0x021BF2FC  thumb  ov217
 *   RESEARCH_GRAPH_SetTeamLabelVisible  0x021BF38C  thumb  ov217
 *   RESEARCH_GRAPH_SetTriangleActorVisible  0x021BF47C  thumb  ov217
 *   RESEARCH_GRAPH_ClearUpdatedFlag  0x021BF704  thumb  ov217
 *   RESEARCH_GRAPH_GetLeftCircle  0x021BF76C  thumb  ov217
 *   RESEARCH_GRAPH_GetGroupValue  0x021BF810  thumb  ov217
 *   RESEARCH_GRAPH_BuildGraphTable  0x021BFC60  thumb  ov217
 *   CircleGraph_QueueErase  0x021C116C  thumb  ov217
 *
 * Per-frame step for the record's +0x3C8 sub-state; the tail is the
 * fixed-order call list that re-arms the sub-system (delta +1).
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

extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern u32 RESEARCH_GRAPH_MoveToFirstEntry(u32 a0);
extern int RESEARCH_GRAPH_DrawIndexCursor(char *p);
extern void RESEARCH_GRAPH_CycleGroup(char *p, int a);
extern void RESEARCH_GRAPH_SyncArrow(u8 *p);
extern void RESEARCH_GRAPH_HideAllPercentages(char *p);
extern void RESEARCH_GRAPH_LoadBackground(char *p);
extern void RESEARCH_GRAPH_PrintGroupLabel(char *p);
extern void RESEARCH_GRAPH_PrintKindLabel(char *p);
extern void RESEARCH_GRAPH_PrintTimeLabel(char *p);
extern void RESEARCH_GRAPH_PrintTeamLabel(char *p);
extern void RESEARCH_GRAPH_SetTeamLabelVisible(char *p);
extern void RESEARCH_GRAPH_SetTriangleActorVisible(char *p);
extern void RESEARCH_GRAPH_ClearUpdatedFlag(void *p);
extern u8 *RESEARCH_GRAPH_GetLeftCircle(void *p);
extern u32 RESEARCH_GRAPH_GetGroupValue(void *p);
extern void RESEARCH_GRAPH_BuildGraphTable(char *p);
extern void CircleGraph_QueueErase(u8 *h);

void RESEARCH_GRAPH_MoveGroupBackward(char *p)
{
    if (((struct Obj00021 *)p)->f3C8 != 0) {
        if (RESEARCH_GRAPH_GetGroupValue(p) != 0) {
            CircleGraph_QueueErase(RESEARCH_GRAPH_GetLeftCircle(p));
        }
    }
    RESEARCH_GRAPH_BuildGraphTable(p);
    RESEARCH_GRAPH_ClearUpdatedFlag(p);
    RESEARCH_GRAPH_CycleGroup(p, 1);
    ((struct Obj00021 *)p)->f3C8 = 0;
    RESEARCH_GRAPH_LoadBackground(p);
    RESEARCH_GRAPH_DrawIndexCursor(p);
    RESEARCH_GRAPH_PrintGroupLabel(p);
    RESEARCH_GRAPH_PrintKindLabel(p);
    RESEARCH_GRAPH_MoveToFirstEntry((u32)p);
    RESEARCH_GRAPH_PrintTimeLabel(p);
    RESEARCH_GRAPH_PrintTeamLabel(p);
    RESEARCH_GRAPH_SetTeamLabelVisible(p);
    RESEARCH_GRAPH_HideAllPercentages(p);
    RESEARCH_GRAPH_SetTriangleActorVisible(p);
    RESEARCH_GRAPH_SyncArrow((u8 *)p);
    GFL_USE_PlaySeDefaultVolume(1352);
}
