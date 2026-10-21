#ifndef RESEARCH_COMMON_H
#define RESEARCH_COMMON_H

#include "../ov217/research_clact.h"

struct Ctx;
struct Cfg;
struct PaletteFade;
struct PaletteAnime;

/* Touch hit rectangle, edges in pixels. */
struct ResearchCommonTouchRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
};

/*
 * Object shared by the three research screens (top, list, graph): the CLACT
 * system, its resources and unit, one actor, the palette animation system and
 * the touch rectangles. 64 bytes, created by RESEARCH_COMMON_Create.
 */
struct ResearchCommon {
    u16 heapId;
    u16 pad2;                           /* alignment before the pointer */
    const struct Ctx *ctx;
    void *appResource;
    struct ResearchCommonTouchRect touchRects[2];
    s32 resourceIds[3];                 /* character, palette, cell animation */
    struct ClactUnit *clactUnits[1];
    struct ClactActor *actor;
    void *palAnm;
    struct PaletteAnime *paletteAnime[1];
    u32 previousScreen;
    u32 currentScreen;
    u32 entryHandled;
    u32 inputFlag;
};

#include "../types.h"
struct ResearchCommon;
struct ResearchCommon *RESEARCH_COMMON_Create(u32 heapId, const struct Ctx *ctx);
u32 RESEARCH_COMMON_Destroy(struct ResearchCommon *common);
u32 RESEARCH_COMMON_GetHeapId(struct ResearchCommon *common);
u32 RESEARCH_COMMON_GetContext(u32 *common);
u32 RESEARCH_COMMON_GetAppResource(struct ResearchCommon *common);
void *RESEARCH_COMMON_GetTouchRects(struct ResearchCommon *common);
void RESEARCH_COMMON_SetScreen(struct ResearchCommon *common, u32 screen);
void RESEARCH_COMMON_SetEntryHandled(struct ResearchCommon *common, u32 value);
u32 RESEARCH_COMMON_GetPreviousScreen(struct ResearchCommon *common);
u32 RESEARCH_COMMON_GetEntryHandled(struct ResearchCommon *common);
void RESEARCH_COMMON_UpdatePaletteAnime(u32 common);
void RESEARCH_COMMON_StartPaletteAnime(struct ResearchCommon *common, u32 index);
void RESEARCH_COMMON_StopPaletteAnime(u32 common);
void RESEARCH_COMMON_RestorePaletteAnime(u32 common);
u32 RESEARCH_COMMON_GetInputFlag(struct ResearchCommon *common);
void RESEARCH_COMMON_SetInputFlag(struct ResearchCommon *common);
void RESEARCH_COMMON_ClearFields(struct ResearchCommon *common);
struct ResearchCommon *RESEARCH_COMMON_Alloc(u32 heapId);
u32 RESEARCH_COMMON_Free(struct ResearchCommon *common);
void RESEARCH_COMMON_Init(struct ResearchCommon *common, const struct Ctx *ctx, u32 heapId);
void RESEARCH_COMMON_Exit(struct ResearchCommon *common);
void RESEARCH_COMMON_InitClact(struct ResearchCommon *common);
void RESEARCH_COMMON_ExitClact(u32 a);
void RESEARCH_COMMON_ClearResourceIds(struct ResearchCommon *common);
void RESEARCH_COMMON_RegisterResources(struct ResearchCommon *common);
void RESEARCH_COMMON_ReleaseResources(struct ResearchCommon *common);
void RESEARCH_COMMON_ClearClactUnit(struct ResearchCommon *common);
void RESEARCH_COMMON_CreateClactUnit(struct ResearchCommon *common);
void RESEARCH_COMMON_DeleteClactUnit(struct ResearchCommon *common);
void RESEARCH_COMMON_ClearActor(struct ResearchCommon *common);
void RESEARCH_COMMON_CreateActor(struct ResearchCommon *common);
void RESEARCH_COMMON_DeleteActor(struct ResearchCommon *common);
void RESEARCH_COMMON_ClearPalAnm(struct ResearchCommon *common);
void RESEARCH_COMMON_CreatePalAnm(struct ResearchCommon *common);
void RESEARCH_COMMON_DeletePalAnm(struct ResearchCommon *common);
void RESEARCH_COMMON_AllocSlotBuffers(struct ResearchCommon *common);
void RESEARCH_COMMON_FreeSlotBuffers(struct ResearchCommon *common);
void RESEARCH_COMMON_ClearPaletteAnime(struct ResearchCommon *common);
void RESEARCH_COMMON_CreatePaletteAnime(struct ResearchCommon *common);
void RESEARCH_COMMON_DestroyPaletteAnime(struct ResearchCommon *common);
void RESEARCH_COMMON_BindPaletteAnime(struct ResearchCommon *common);
void RESEARCH_COMMON_ExitPaletteAnime(struct ResearchCommon *common);
void RESEARCH_COMMON_StartPaletteAnimeImpl(struct ResearchCommon *common, u32 index);
void RESEARCH_COMMON_StopPaletteAnimeImpl(struct ResearchCommon *common, u32 index);
void RESEARCH_COMMON_RestorePaletteAnimeImpl(struct ResearchCommon *common, u32 index);
void RESEARCH_COMMON_UpdatePaletteAnimeImpl(struct ResearchCommon *common);
void RESEARCH_COMMON_InitTouchRects(struct ResearchCommon *common);
u32 RESEARCH_COMMON_GetResourceId(struct ResearchCommon *common, u32 index);
u32 RESEARCH_COMMON_GetClactUnit(struct ResearchCommon *common, u32 index);

#endif
