/*
 * function: RESEARCH_GRAPH_Cleanup
 * address:  0x021BE384
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
 *   RESEARCH_GRAPH_SetStateChanged  0x021BE448  thumb  ov217
 *   RESEARCH_GRAPH_SetActive  0x021BE460  thumb  ov217
 *   RESEARCH_GRAPH_PushCommand  0x021BE498  thumb  ov217
 *   RESEARCH_GRAPH_DeleteFont  0x021BFB54  thumb  ov217
 *   RESEARCH_GRAPH_DeleteMessages  0x021BFBA0  thumb  ov217
 *   RESEARCH_GRAPH_DeleteWordSet  0x021BFBD0  thumb  ov217
 *   RESEARCH_GRAPH_DestroyCircles  0x021BFC28  thumb  ov217
 *   RESEARCH_GRAPH_DestroyArrow  0x021BFED4  thumb  ov217
 *   RESEARCH_GRAPH_DestroyPercentages  0x021BFF5C  thumb  ov217
 *   RESEARCH_GRAPH_ExitOverlayBackgrounds  0x021C0084  thumb  ov217
 *   RESEARCH_GRAPH_DummyBg7  0x021C00F8  thumb  ov217
 *   RESEARCH_GRAPH_ShowBackground7  0x021C0114  thumb  ov217
 *   RESEARCH_GRAPH_DummyBg3  0x021C0170  thumb  ov217
 *   RESEARCH_GRAPH_ShowBackground3  0x021C018C  thumb  ov217
 *   RESEARCH_GRAPH_DestroyLabels  0x021C0230  thumb  ov217
 *   RESEARCH_GRAPH_ReleaseEntryResources  0x021C02A8  thumb  ov217
 *   RESEARCH_GRAPH_ReleaseCursorResources  0x021C0358  thumb  ov217
 *   RESEARCH_GRAPH_DeleteUnits  0x021C03D0  thumb  ov217
 *   RESEARCH_GRAPH_DeleteActors  0x021C0494  thumb  ov217
 *   RESEARCH_GRAPH_DeleteBmps  0x021C06AC  thumb  ov217
 *   RESEARCH_GRAPH_DeleteOamSys  0x021C06E0  thumb  ov217
 *   RESEARCH_GRAPH_DeleteOamObjects  0x021C0794  thumb  ov217
 *   RESEARCH_GRAPH_DeletePalAnm  0x021C0800  thumb  ov217
 *   RESEARCH_GRAPH_DestroyPaletteAnime  0x021C085C  thumb  ov217
 *   RESEARCH_GRAPH_RestorePaletteAnime  0x021C08A8  thumb  ov217
 *   RESEARCH_GRAPH_UnregisterVBlank  0x021C08F0  thumb  ov217
 *   RESEARCH_GRAPH_ClearNotifyFlag  0x021C0968  thumb  ov217
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
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

extern void RESEARCH_GRAPH_SetStateChanged(void *p);
extern void RESEARCH_GRAPH_SetActive(void *p, u32 v);
extern void RESEARCH_GRAPH_PushCommand(u8 *a0, u32 a1);
extern void RESEARCH_GRAPH_DeleteFont(u8 *a0);
extern void RESEARCH_GRAPH_DeleteMessages(int *p);
extern void RESEARCH_GRAPH_DeleteWordSet(u8 *a0);
extern void RESEARCH_GRAPH_DestroyCircles(char *p);
extern void RESEARCH_GRAPH_DestroyArrow(u8 *a0);
extern void RESEARCH_GRAPH_DestroyPercentages(int *p);
extern u32 RESEARCH_GRAPH_ExitOverlayBackgrounds();
extern u32 RESEARCH_GRAPH_DummyBg7();
extern u32 RESEARCH_GRAPH_ShowBackground7();
extern u32 RESEARCH_GRAPH_DummyBg3();
extern u32 RESEARCH_GRAPH_ShowBackground3();
extern void RESEARCH_GRAPH_DestroyLabels(int *p);
extern u32 RESEARCH_GRAPH_ReleaseEntryResources(u32 a0);
extern u32 RESEARCH_GRAPH_ReleaseCursorResources(u32 a0);
extern void RESEARCH_GRAPH_DeleteUnits(int *p);
extern void RESEARCH_GRAPH_DeleteActors(int *p);
extern void RESEARCH_GRAPH_DeleteBmps(int *p);
extern void RESEARCH_GRAPH_DeleteOamSys(u8 *a0);
extern void RESEARCH_GRAPH_DeleteOamObjects(int *p);
extern u32 RESEARCH_GRAPH_DeletePalAnm(u32 a0);
extern void RESEARCH_GRAPH_DestroyPaletteAnime(int *p);
extern void RESEARCH_GRAPH_RestorePaletteAnime(int *);
extern void RESEARCH_GRAPH_UnregisterVBlank(u8 *a0);
extern void RESEARCH_GRAPH_ClearNotifyFlag(unsigned char *a0);
extern void RESEARCH_COMMON_StopPaletteAnime(u32 a0);
extern void RESEARCH_COMMON_RestorePaletteAnime(u32 a0);
void RESEARCH_GRAPH_Cleanup(u8 *a0)
{
    RESEARCH_GRAPH_RestorePaletteAnime((int *)a0);
    RESEARCH_GRAPH_DestroyPaletteAnime((int *)a0);
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct Obj00021 *)((u8*)a0))->f0);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct Obj00021 *)((u8*)a0))->f0);
    RESEARCH_GRAPH_UnregisterVBlank((u8 *)a0);
    RESEARCH_GRAPH_DestroyPercentages((int *)a0);
    RESEARCH_GRAPH_DestroyArrow(a0);
    RESEARCH_GRAPH_DestroyCircles((char *)a0);
    RESEARCH_GRAPH_DeletePalAnm((u32)a0);
    RESEARCH_GRAPH_DeleteBmps((int *)a0);
    RESEARCH_GRAPH_DeleteOamObjects((int *)a0);
    RESEARCH_GRAPH_DeleteOamSys((u8 *)a0);
    RESEARCH_GRAPH_DeleteActors((int *)a0);
    RESEARCH_GRAPH_DeleteUnits((int *)a0);
    RESEARCH_GRAPH_ReleaseEntryResources((u32)a0);
    RESEARCH_GRAPH_ReleaseCursorResources((u32)a0);
    RESEARCH_GRAPH_DestroyLabels((int *)a0);
    RESEARCH_GRAPH_ShowBackground3(a0);
    RESEARCH_GRAPH_DummyBg3(a0);
    RESEARCH_GRAPH_ShowBackground7(a0);
    RESEARCH_GRAPH_DummyBg7(a0);
    RESEARCH_GRAPH_ExitOverlayBackgrounds(a0);
    RESEARCH_GRAPH_DeleteWordSet((u8 *)a0);
    RESEARCH_GRAPH_DeleteMessages((int *)a0);
    RESEARCH_GRAPH_DeleteFont((u8 *)a0);
    RESEARCH_GRAPH_SetActive((void *)a0, 0);
    RESEARCH_GRAPH_PushCommand((u8 *)a0, 13);
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    RESEARCH_GRAPH_ClearNotifyFlag((unsigned char *)a0);
    *(u32 *)&((struct Obj00021 *)(((u8*)a0)))->f3C4 = 0;
    ((struct Obj00021 *)(((u8*)a0)))->f3E0 = 1;
}

