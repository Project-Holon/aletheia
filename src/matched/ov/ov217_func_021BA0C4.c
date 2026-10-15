/*
 * function: RESEARCH_TOP_CleanupListObject
 * address:  0x021BA0C4
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
 *   RESEARCH_TOP_PushCommand  0x021BA144  thumb  ov217
 *   RESEARCH_TOP_SetCommandReady  0x021BA150  thumb  ov217
 *   RESEARCH_TOP_DeleteFont  0x021BA5D8  thumb  ov217
 *   RESEARCH_TOP_DeleteMessages  0x021BA624  thumb  ov217
 *   RESEARCH_TOP_ExitOverlayBackgrounds  0x021BA748  thumb  ov217
 *   RESEARCH_TOP_DummyBg7  0x021BA7B4  thumb  ov217
 *   RESEARCH_TOP_ShowBackground7  0x021BA7D0  thumb  ov217
 *   RESEARCH_TOP_DummyBg3  0x021BA82C  thumb  ov217
 *   RESEARCH_TOP_ShowBackground3  0x021BA848  thumb  ov217
 *   RESEARCH_TOP_DestroyLabels  0x021BA8E0  thumb  ov217
 *   RESEARCH_TOP_ReleaseEntryResources  0x021BA960  thumb  ov217
 *   RESEARCH_TOP_ReleaseCursorResources  0x021BA9D0  thumb  ov217
 *   RESEARCH_TOP_DeleteUnits  0x021BAA28  thumb  ov217
 *   RESEARCH_TOP_DeleteActor  0x021BAAB8  thumb  ov217
 *   RESEARCH_TOP_DestroyPaletteAnime  0x021BAAF4  thumb  ov217
 *   RESEARCH_TOP_RestorePaletteAnime  0x021BAB38  thumb  ov217
 *   RESEARCH_TOP_UnregisterVBlank  0x021BAB68  thumb  ov217
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00511.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_TOP_PushCommand(u8 *a0, u32 a1);
extern u32 RESEARCH_TOP_SetCommandReady();
extern void RESEARCH_TOP_DeleteFont(u8 *a0);
extern void RESEARCH_TOP_DeleteMessages(int *p);
extern u32 RESEARCH_TOP_ExitOverlayBackgrounds();
extern u32 RESEARCH_TOP_DummyBg7();
extern u32 RESEARCH_TOP_ShowBackground7();
extern u32 RESEARCH_TOP_DummyBg3();
extern u32 RESEARCH_TOP_ShowBackground3();
extern void RESEARCH_TOP_DestroyLabels(int *p);
extern u32 RESEARCH_TOP_ReleaseEntryResources(u32 a0);
extern u32 RESEARCH_TOP_ReleaseCursorResources(u32 a0);
extern void RESEARCH_TOP_DeleteUnits(int *p);
extern void RESEARCH_TOP_DeleteActor(u8 *a0);
extern void RESEARCH_TOP_DestroyPaletteAnime(int *p);
extern void RESEARCH_TOP_RestorePaletteAnime(char *self);
extern void RESEARCH_TOP_UnregisterVBlank(void);
extern void RESEARCH_COMMON_StopPaletteAnime(u32 a0);
extern void RESEARCH_COMMON_RestorePaletteAnime(u32 a0);
u32 RESEARCH_TOP_CleanupListObject(u32 a0)
{
    RESEARCH_TOP_UnregisterVBlank();
    RESEARCH_COMMON_StopPaletteAnime(*(u32 *)&((struct Obj00511 *)((u8*)a0))->f0);
    RESEARCH_COMMON_RestorePaletteAnime(*(u32 *)&((struct Obj00511 *)((u8*)a0))->f0);
    RESEARCH_TOP_RestorePaletteAnime((char *)a0);
    RESEARCH_TOP_DestroyPaletteAnime((int *)a0);
    RESEARCH_TOP_DeleteActor((u8 *)a0);
    RESEARCH_TOP_DeleteUnits((int *)a0);
    RESEARCH_TOP_ReleaseEntryResources(a0);
    RESEARCH_TOP_ReleaseCursorResources(a0);
    RESEARCH_TOP_DestroyLabels((int *)a0);
    RESEARCH_TOP_ShowBackground3(a0);
    RESEARCH_TOP_DummyBg3(a0);
    RESEARCH_TOP_ShowBackground7(a0);
    RESEARCH_TOP_DummyBg7(a0);
    RESEARCH_TOP_ExitOverlayBackgrounds(a0);
    RESEARCH_TOP_DeleteMessages((int *)a0);
    RESEARCH_TOP_DeleteFont((u8 *)a0);
    ((struct Obj00511 *)((u8*)a0))->f88 = 1;
    RESEARCH_TOP_PushCommand((u8 *)a0, 6);
    return RESEARCH_TOP_SetCommandReady(a0);
}

