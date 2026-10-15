/*
 * function: RESEARCH_GRAPH_Init
 * address:  0x021BD718
 * packet:   pkt_ov217_021BD718
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_CreateCommandQueue  0x021BFB14  thumb  ov217
 *   RESEARCH_GRAPH_CreateFont  0x021BFB38  thumb  ov217
 *   RESEARCH_GRAPH_CreateMessages  0x021BFB74  thumb  ov217
 *   RESEARCH_GRAPH_CreateWordSet  0x021BFBC0  thumb  ov217
 *   RESEARCH_GRAPH_InitTouchRects  0x021BFE40  thumb  ov217
 *   RESEARCH_GRAPH_LayoutTouchRects  0x021BEFF8  thumb  ov217
 *   RESEARCH_GRAPH_InitScreen  0x021BFF78  thumb  ov217
 *   RESEARCH_GRAPH_InitOverlayBackgrounds  0x021BFFC8  thumb  ov217
 *   RESEARCH_GRAPH_LoadBackground6  0x021C00AC  thumb  ov217
 *   RESEARCH_GRAPH_UpdateBackground7  0x021C00FC  thumb  ov217
 *   RESEARCH_GRAPH_LoadBackground2  0x021C0124  thumb  ov217
 *   RESEARCH_GRAPH_UpdateBackground3  0x021C0174  thumb  ov217
 *   RESEARCH_GRAPH_CreateLabels  0x021C01B8  thumb  ov217
 *   RESEARCH_GRAPH_RegisterEntryResources  0x021C0250  thumb  ov217
 *   RESEARCH_GRAPH_RegisterCursorResources  0x021C02C8  thumb  ov217
 *   RESEARCH_GRAPH_CreateUnits  0x021C03A0  thumb  ov217
 *   RESEARCH_GRAPH_CreateActors  0x021C0408  thumb  ov217
 *   RESEARCH_GRAPH_CreateBmps  0x021C04CC  thumb  ov217
 *   RESEARCH_GRAPH_DrawBmps  0x021C04FC  thumb  ov217
 *   RESEARCH_GRAPH_DrawBadge  0x021C05B0  thumb  ov217
 *   RESEARCH_GRAPH_CreateOamSys  0x021C06C8  thumb  ov217
 *   RESEARCH_GRAPH_CreateOamObjects  0x021C06F0  thumb  ov217
 *   RESEARCH_GRAPH_BuildGraphTable  0x021BFC60  thumb  ov217
 *   RESEARCH_GRAPH_CreateCircles  0x021BFBFC  thumb  ov217
 *   RESEARCH_GRAPH_CreateArrow  0x021BFE8C  thumb  ov217
 *   RESEARCH_GRAPH_CreatePercentages  0x021BFF00  thumb  ov217
 *   RESEARCH_GRAPH_CreatePalAnm  0x021C07BC  thumb  ov217
 *   RESEARCH_GRAPH_CreatePaletteAnime  0x021C083C  thumb  ov217
 *   RESEARCH_GRAPH_BindPaletteAnime  0x021C0878  thumb  ov217
 *   RESEARCH_GRAPH_RegisterVBlank  0x021C08D4  thumb  ov217
 *   RESEARCH_GRAPH_RestartNetwork  0x021C08C4  thumb  ov217
 *   RESEARCH_GRAPH_PrintTitle  0x021BF100  thumb  ov217
 *   RESEARCH_GRAPH_PrintGroupLabel  0x021BF11C  thumb  ov217
 *   RESEARCH_GRAPH_PrintKindLabel  0x021BF13C  thumb  ov217
 *   RESEARCH_GRAPH_PrintSliceLabel  0x021BF15C  thumb  ov217
 *   RESEARCH_GRAPH_PrintTimeLabel  0x021BF264  thumb  ov217
 *   RESEARCH_GRAPH_PrintTeamLabel  0x021BF2FC  thumb  ov217
 *   RESEARCH_GRAPH_SetTeamLabelVisible  0x021BF38C  thumb  ov217
 *   RESEARCH_GRAPH_SetDetailLabelVisible  0x021BF3B4  thumb  ov217
 *   RESEARCH_GRAPH_LayoutActors  0x021BF3D8  thumb  ov217
 *   RESEARCH_GRAPH_LoadBackground  0x021BF08C  thumb  ov217
 *   RESEARCH_GRAPH_SetTriangleActorVisible  0x021BF47C  thumb  ov217
 *   RESEARCH_GRAPH_EnableOams  0x021BF55C  thumb  ov217
 *   RESEARCH_GRAPH_StartSlotPaletteAnime  0x021BF594  thumb  ov217
 *   RESEARCH_GRAPH_SyncArrow  0x021BEAF8  thumb  ov217
 *   RESEARCH_GRAPH_FadeIn  0x021BE8FC  thumb  ov217
 *   RESEARCH_GRAPH_GetTransitionKind  0x021BE46C  thumb  ov217
 *   RESEARCH_GRAPH_PushCommand  0x021BE498  thumb  ov217
 *   RESEARCH_GRAPH_DrawIndexCursor  0x021BE934  thumb  ov217
 *   RESEARCH_GRAPH_SetStateChanged  0x021BE448  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int   u32;
extern void RESEARCH_GRAPH_CreateCommandQueue(u32 a0);
extern void RESEARCH_GRAPH_CreateFont(u32 a0);
typedef unsigned char  u8;
struct W;
extern void RESEARCH_GRAPH_CreateMessages(struct W *p);
extern void RESEARCH_GRAPH_CreateWordSet(u32 a0);
extern void RESEARCH_GRAPH_InitTouchRects(u8 *p);
extern void RESEARCH_GRAPH_LayoutTouchRects(u8 *p);
extern void RESEARCH_GRAPH_InitScreen(void);
extern void RESEARCH_GRAPH_InitOverlayBackgrounds(char *p);
extern void RESEARCH_GRAPH_LoadBackground6(char *p);
extern void RESEARCH_GRAPH_UpdateBackground7(void *p);
extern void RESEARCH_GRAPH_LoadBackground2(char *p);
extern void RESEARCH_GRAPH_UpdateBackground3(void *p);
extern void RESEARCH_GRAPH_CreateLabels(char *p);
extern void RESEARCH_GRAPH_RegisterEntryResources(char *p);
extern void RESEARCH_GRAPH_RegisterCursorResources(char *p);
extern void RESEARCH_GRAPH_CreateUnits(u8 *p);
extern void RESEARCH_GRAPH_CreateActors(u8 *p);
extern void RESEARCH_GRAPH_CreateBmps(u8 *p);
extern void RESEARCH_GRAPH_DrawBmps(u8 *p);
extern void RESEARCH_GRAPH_DrawBadge(u8 *p);
extern void RESEARCH_GRAPH_CreateOamSys(u8 *p);
extern void RESEARCH_GRAPH_CreateOamObjects(u8 *p);
extern void RESEARCH_GRAPH_BuildGraphTable(char *p);
extern void RESEARCH_GRAPH_CreateCircles(char *p);
extern void RESEARCH_GRAPH_CreateArrow(char *p);
extern void RESEARCH_GRAPH_CreatePercentages(char *p);
extern void RESEARCH_GRAPH_CreatePalAnm(u8 *p);
extern void RESEARCH_GRAPH_CreatePaletteAnime(u8 *p);
extern void RESEARCH_GRAPH_BindPaletteAnime(u8 *p);
extern void RESEARCH_GRAPH_RegisterVBlank(char *p);
extern void RESEARCH_GRAPH_RestartNetwork(u32 a0);
extern void RESEARCH_GRAPH_PrintTitle(char *p);
extern void RESEARCH_GRAPH_PrintGroupLabel(char *p);
extern void RESEARCH_GRAPH_PrintKindLabel(char *p);
extern void RESEARCH_GRAPH_PrintSliceLabel(char *p);
extern void RESEARCH_GRAPH_PrintTimeLabel(char *p);
extern void RESEARCH_GRAPH_PrintTeamLabel(char *p);
extern void RESEARCH_GRAPH_SetTeamLabelVisible(char *p);
extern void RESEARCH_GRAPH_SetDetailLabelVisible(char *p);
extern void RESEARCH_GRAPH_LayoutActors(char *p);
extern void RESEARCH_GRAPH_LoadBackground(char *p);
extern void RESEARCH_GRAPH_SetTriangleActorVisible(char *p);
extern void RESEARCH_GRAPH_EnableOams(void *p);
extern void RESEARCH_GRAPH_StartSlotPaletteAnime(char *p, int i);
extern void RESEARCH_GRAPH_SyncArrow(u8 *p);
extern void RESEARCH_GRAPH_FadeIn(void);
extern u32 RESEARCH_GRAPH_GetTransitionKind(u8 *a0);
extern void RESEARCH_GRAPH_PushCommand(u8 *a0, u32 a1);
extern int RESEARCH_GRAPH_DrawIndexCursor(char *p);
extern void RESEARCH_GRAPH_SetStateChanged(void *p);

void RESEARCH_GRAPH_Init(unsigned char *p)
{
    int r;
    RESEARCH_GRAPH_CreateCommandQueue((u32)p);
    RESEARCH_GRAPH_CreateFont((u32)p);
    RESEARCH_GRAPH_CreateMessages((struct W *)p);
    RESEARCH_GRAPH_CreateWordSet((u32)p);
    RESEARCH_GRAPH_InitTouchRects(p);
    RESEARCH_GRAPH_LayoutTouchRects(p);
    RESEARCH_GRAPH_InitScreen();
    RESEARCH_GRAPH_InitOverlayBackgrounds((char *)p);
    RESEARCH_GRAPH_LoadBackground6((char *)p);
    RESEARCH_GRAPH_UpdateBackground7(p);
    RESEARCH_GRAPH_LoadBackground2((char *)p);
    RESEARCH_GRAPH_UpdateBackground3(p);
    RESEARCH_GRAPH_CreateLabels((char *)p);
    RESEARCH_GRAPH_RegisterEntryResources((char *)p);
    RESEARCH_GRAPH_RegisterCursorResources((char *)p);
    RESEARCH_GRAPH_CreateUnits(p);
    RESEARCH_GRAPH_CreateActors(p);
    RESEARCH_GRAPH_CreateBmps(p);
    RESEARCH_GRAPH_DrawBmps(p);
    RESEARCH_GRAPH_DrawBadge(p);
    RESEARCH_GRAPH_CreateOamSys(p);
    RESEARCH_GRAPH_CreateOamObjects(p);
    RESEARCH_GRAPH_BuildGraphTable((char *)p);
    RESEARCH_GRAPH_CreateCircles((char *)p);
    RESEARCH_GRAPH_CreateArrow((char *)p);
    RESEARCH_GRAPH_CreatePercentages((char *)p);
    RESEARCH_GRAPH_CreatePalAnm(p);
    RESEARCH_GRAPH_CreatePaletteAnime(p);
    RESEARCH_GRAPH_BindPaletteAnime(p);
    RESEARCH_GRAPH_RegisterVBlank((char *)p);
    RESEARCH_GRAPH_RestartNetwork((u32)p);
    RESEARCH_GRAPH_PrintTitle((char *)p);
    RESEARCH_GRAPH_PrintGroupLabel((char *)p);
    RESEARCH_GRAPH_PrintKindLabel((char *)p);
    RESEARCH_GRAPH_PrintSliceLabel((char *)p);
    RESEARCH_GRAPH_PrintTimeLabel((char *)p);
    RESEARCH_GRAPH_PrintTeamLabel((char *)p);
    RESEARCH_GRAPH_SetTeamLabelVisible((char *)p);
    RESEARCH_GRAPH_SetDetailLabelVisible((char *)p);
    RESEARCH_GRAPH_LayoutActors((char *)p);
    RESEARCH_GRAPH_LoadBackground((char *)p);
    RESEARCH_GRAPH_SetTriangleActorVisible((char *)p);
    RESEARCH_GRAPH_EnableOams(p);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)p, 0);
    RESEARCH_GRAPH_StartSlotPaletteAnime((char *)p, 7);
    RESEARCH_GRAPH_SyncArrow(p);
    *(int *)&((struct Obj00021 *)p)->f3C4 = 1;
    RESEARCH_GRAPH_FadeIn();
    r = RESEARCH_GRAPH_GetTransitionKind(p);
    RESEARCH_GRAPH_PushCommand(p, 1);
    RESEARCH_GRAPH_PushCommand(p, r);
    if (r == 3)
        RESEARCH_GRAPH_DrawIndexCursor((char *)p);
    RESEARCH_GRAPH_SetStateChanged(p);
}
