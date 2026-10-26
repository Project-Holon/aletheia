/*
 * file:     research_common.c
 * unit:     yes
 * function: RESEARCH_COMMON_Create, RESEARCH_COMMON_Destroy, RESEARCH_COMMON_GetHeapId, RESEARCH_COMMON_GetContext, RESEARCH_COMMON_GetAppResource, RESEARCH_COMMON_GetTouchRects, RESEARCH_COMMON_SetScreen, RESEARCH_COMMON_SetEntryHandled, RESEARCH_COMMON_GetPreviousScreen, RESEARCH_COMMON_GetEntryHandled, RESEARCH_COMMON_UpdatePaletteAnime, RESEARCH_COMMON_StartPaletteAnime, RESEARCH_COMMON_StopPaletteAnime, RESEARCH_COMMON_RestorePaletteAnime, RESEARCH_COMMON_GetInputFlag, RESEARCH_COMMON_SetInputFlag, RESEARCH_COMMON_ClearFields, RESEARCH_COMMON_Alloc, RESEARCH_COMMON_Free, RESEARCH_COMMON_Init, RESEARCH_COMMON_Exit, RESEARCH_COMMON_InitClact, RESEARCH_COMMON_ExitClact, RESEARCH_COMMON_ClearResourceIds, RESEARCH_COMMON_RegisterResources, RESEARCH_COMMON_ReleaseResources, RESEARCH_COMMON_ClearClactUnit, RESEARCH_COMMON_CreateClactUnit, RESEARCH_COMMON_DeleteClactUnit, RESEARCH_COMMON_ClearActor, RESEARCH_COMMON_CreateActor, RESEARCH_COMMON_DeleteActor, RESEARCH_COMMON_ClearPalAnm, RESEARCH_COMMON_CreatePalAnm, RESEARCH_COMMON_DeletePalAnm, RESEARCH_COMMON_AllocSlotBuffers, RESEARCH_COMMON_FreeSlotBuffers, RESEARCH_COMMON_ClearPaletteAnime, RESEARCH_COMMON_CreatePaletteAnime, RESEARCH_COMMON_DestroyPaletteAnime, RESEARCH_COMMON_BindPaletteAnime, RESEARCH_COMMON_ExitPaletteAnime, RESEARCH_COMMON_StartPaletteAnimeImpl, RESEARCH_COMMON_StopPaletteAnimeImpl, RESEARCH_COMMON_RestorePaletteAnimeImpl, RESEARCH_COMMON_UpdatePaletteAnimeImpl, RESEARCH_COMMON_InitTouchRects, RESEARCH_COMMON_GetResourceId, RESEARCH_COMMON_GetClactUnit
 * address:  0x021C097C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, PALETTE_ANIME_ReleaseOriginal.c by tools/splitfile.py.
 *
 * symbols:
 *   d_021C3F50 0x021C3F50 data a4
 *   RESEARCH_COMMON_SetInputFlag 0x021C09FC thumb ov217
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   RESEARCH_COMMON_SetScreen  0x021C09BC  thumb  ov217
 *   RESEARCH_COMMON_Create  0x021C097C  thumb  ov217
 *   RESEARCH_COMMON_Destroy  0x021C099C  thumb  ov217
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   RESEARCH_COMMON_UpdatePaletteAnime 0x021C09D0 thumb ov217
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
 *   RESEARCH_COMMON_GetPreviousScreen  0x021C09C8  thumb  ov217
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *   RESEARCH_COMMON_SetEntryHandled  0x021C09C4  thumb  ov217
 *   RESEARCH_COMMON_StartPaletteAnime  0x021C09D8  thumb  ov217
 *   PALETTE_ANIME_Start  0x021C29F8  thumb  ov217
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *   RESEARCH_COMMON_GetAppResource 0x021C09B4 thumb ov217
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PALANM_Delete  0x02021540  thumb
 *   RESEARCH_COMMON_GetContext  0x021C09B0  thumb  ov217
 *   MI_CpuFill8  0x02082BCC  arm
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   d_021C3F64  0x021C3F64  data
 *   d_021C3F9C  0x021C3F9C  data
 *   d_021C3F80 0x021C3F80 data a4
 *   d_021C3F5C     0x021C3F5C  data   a4
 *   d_021C3F60     0x021C3F60  data   a1
 *   d_021C3F48  0x021C3F48  data  a1
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   CLACT_InitSystem  0x0204A48C  arm  arm9
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 */
#include "research_common.h"
#include "research_clact.h"

/* Description of the shared actor, read from ROM data. */
struct ActorTemplate {
    struct ActorHeader header;
    u32 unitIndex;
    u32 charIndex;
    u32 paletteIndex;
    u32 cellAnimIndex;
    u16 priority;
    u16 pad;
};

/* ROM data read by the palette-animation setup. */
struct PaletteAnimeBindData {
    u16 *palette;
    u16 *original;
    u8 colorCount;
};

#include "../arm9/arc_tool.h"
#include "../arm9/gfl_heap_wrap.h"
struct Actor;
struct ClactActor;
struct Unit;
struct ClactSysInit;
struct DispVramCfg;
struct ActorInitParam;
#include "../arm9/clact.h"
#include "../arm9/palanm.h"
#include "../arm9/mi_memory.h"
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"
struct DispVramCfg;
struct SysInit;

/* palette_anime.c */
#include "palette_anime.h"
struct PaletteAnime;

struct ResearchCommon *RESEARCH_COMMON_Create(u32 heapId, const struct Ctx *ctx);
u32 RESEARCH_COMMON_Destroy(struct ResearchCommon *common);
u32 RESEARCH_COMMON_GetHeapId(struct ResearchCommon *common);
const struct Ctx *RESEARCH_COMMON_GetContext(struct ResearchCommon *common);
void *RESEARCH_COMMON_GetAppResource(struct ResearchCommon *common);
void *RESEARCH_COMMON_GetTouchRects(struct ResearchCommon *common);
void RESEARCH_COMMON_SetScreen(struct ResearchCommon *common, u32 screen);
void RESEARCH_COMMON_SetEntryHandled(struct ResearchCommon *common, u32 value);
u32 RESEARCH_COMMON_GetPreviousScreen(struct ResearchCommon *common);
u32 RESEARCH_COMMON_GetEntryHandled(struct ResearchCommon *common);
void RESEARCH_COMMON_UpdatePaletteAnime(struct ResearchCommon *common);
void RESEARCH_COMMON_StartPaletteAnime(struct ResearchCommon *common, u32 index);
void RESEARCH_COMMON_StopPaletteAnime(struct ResearchCommon *common);
void RESEARCH_COMMON_RestorePaletteAnime(struct ResearchCommon *common);
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

extern u8 d_021C3F64[];
extern u8 d_021C3F9C[];
extern const struct ActorTemplate d_021C3F80;
extern u8 d_021C3F5C[];
extern u8 d_021C3F60[];
extern const u8 d_021C3F48[];

/* Allocates the shared object and brings up every resource it owns. */
struct ResearchCommon *RESEARCH_COMMON_Create(u32 heapId, const struct Ctx *ctx)
{
    struct ResearchCommon *common;
    common = RESEARCH_COMMON_Alloc(heapId);
    RESEARCH_COMMON_ClearFields(common);
    RESEARCH_COMMON_Init(common, ctx, heapId);
    return common;
}

/* Releases every resource, then the object. */
u32 RESEARCH_COMMON_Destroy(struct ResearchCommon *common)
{
    RESEARCH_COMMON_Exit(common);
    return RESEARCH_COMMON_Free(common);
}

/* Returns the heap id. */
u32 RESEARCH_COMMON_GetHeapId(struct ResearchCommon *common)
{
    return common->heapId;
}

/* Returns the context pointer, word at +4. */
const struct Ctx *RESEARCH_COMMON_GetContext(struct ResearchCommon *common)
{
    return common->ctx;
}

/* Returns the shared resource data. */
void *RESEARCH_COMMON_GetAppResource(struct ResearchCommon *common)
{
    return common->appResource;
}

/* Returns the touch-rectangle table. */
void *RESEARCH_COMMON_GetTouchRects(struct ResearchCommon *common)
{
    return common->touchRects;
}

/* Records a screen change: the old current screen becomes the previous one. */
void RESEARCH_COMMON_SetScreen(struct ResearchCommon *common, u32 screen)
{
    common->previousScreen = common->currentScreen;
    common->currentScreen = screen;
}

/* Sets the entry-handled value. */
void RESEARCH_COMMON_SetEntryHandled(struct ResearchCommon *common, u32 value)
{
    common->entryHandled = value;
}

/* Returns the previous screen. */
u32 RESEARCH_COMMON_GetPreviousScreen(struct ResearchCommon *common)
{
    return common->previousScreen;
}

/* Returns the entry-handled value. */
u32 RESEARCH_COMMON_GetEntryHandled(struct ResearchCommon *common)
{
    return common->entryHandled;
}

/* Veneer: updates palette animation 0. */
void RESEARCH_COMMON_UpdatePaletteAnime(struct ResearchCommon *common)
{
    RESEARCH_COMMON_UpdatePaletteAnimeImpl(common);
}

/* Veneer: starts the palette animation at index. */
void RESEARCH_COMMON_StartPaletteAnime(struct ResearchCommon *common, u32 index)
{
    RESEARCH_COMMON_StartPaletteAnimeImpl(common, index);
}

/* Veneer: stops palette animation 0. */
void RESEARCH_COMMON_StopPaletteAnime(struct ResearchCommon *common)
{
    RESEARCH_COMMON_StopPaletteAnimeImpl(common, 0);
}

/* Veneer: restores the colours of palette animation 0. */
void RESEARCH_COMMON_RestorePaletteAnime(struct ResearchCommon *common)
{
    RESEARCH_COMMON_RestorePaletteAnimeImpl(common, 0);
}

/* Returns the input flag. */
u32 RESEARCH_COMMON_GetInputFlag(struct ResearchCommon *common)
{
    return common->inputFlag;
}

/* Sets the input flag. */
void RESEARCH_COMMON_SetInputFlag(struct ResearchCommon *common)
{
    common->inputFlag = 1;
}

/* Clears the object and every sub-object slot. */
void RESEARCH_COMMON_ClearFields(struct ResearchCommon *common)
{
    MI_CpuFill8(common, 0, sizeof(struct ResearchCommon));
    common->previousScreen = 0;
    common->currentScreen = 0;
    RESEARCH_COMMON_ClearResourceIds(common);
    RESEARCH_COMMON_ClearClactUnit(common);
    RESEARCH_COMMON_ClearActor(common);
    RESEARCH_COMMON_ClearPalAnm(common);
    RESEARCH_COMMON_ClearPaletteAnime(common);
}

/* Allocates the 64-byte object. */
struct ResearchCommon *RESEARCH_COMMON_Alloc(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, sizeof(struct ResearchCommon), 0, (const char *)0x21C4020, 481);
}

/* Frees the object. */
u32 RESEARCH_COMMON_Free(struct ResearchCommon *common)
{
    return GFL_HEAP_Free(common);
}

/* Creates the CLACT system, resources, unit, actor, palette animation and touch table. */
void RESEARCH_COMMON_Init(struct ResearchCommon *common, const struct Ctx *ctx, u32 heapId)
{
    common->heapId = heapId;
    common->ctx = ctx;
    common->appResource = GAMESYSTEM_GetGameData((struct GameSystem *)ctx);
    RESEARCH_COMMON_InitClact(common);
    RESEARCH_COMMON_RegisterResources(common);
    RESEARCH_COMMON_CreateClactUnit(common);
    RESEARCH_COMMON_CreateActor(common);
    RESEARCH_COMMON_CreatePalAnm(common);
    RESEARCH_COMMON_AllocSlotBuffers(common);
    RESEARCH_COMMON_InitTouchRects(common);
    RESEARCH_COMMON_CreatePaletteAnime(common);
    RESEARCH_COMMON_BindPaletteAnime(common);
}

/* Tears the sub-objects down in reverse order of creation. */
void RESEARCH_COMMON_Exit(struct ResearchCommon *common)
{
    RESEARCH_COMMON_ExitPaletteAnime(common);
    RESEARCH_COMMON_DestroyPaletteAnime(common);
    RESEARCH_COMMON_FreeSlotBuffers(common);
    RESEARCH_COMMON_DeletePalAnm(common);
    RESEARCH_COMMON_DeleteActor(common);
    RESEARCH_COMMON_DeleteClactUnit(common);
    RESEARCH_COMMON_ReleaseResources(common);
    RESEARCH_COMMON_ExitClact((uptr)common);
}

/*
 * Initializes the CLACT system.
 * Both data sites carried the contested ov217 token; dropping it lets the
 * function's own region pick the objects.
 * See docs/idioms/omitting-an-overlay-hint-can-attest-where-naming-it-cannot.md.
 */
void RESEARCH_COMMON_InitClact(struct ResearchCommon *common)
{
    CLACT_InitSystem((const struct ClactSysInit *)d_021C3F64, (const struct DispVramCfg *)d_021C3F9C, common->heapId);
}

/* Veneer: shuts the CLACT system down. */
void RESEARCH_COMMON_ExitClact(u32 a)
{
    CLACT_ExitSystem();
}

/* Clears the three resource ids. */
void RESEARCH_COMMON_ClearResourceIds(struct ResearchCommon *common)
{
    int i;
    for (i = 0; i < 3; i++)
        common->resourceIds[i] = 0;
}

/* Registers the character, palette and cell animation resources from archive 83. */
void RESEARCH_COMMON_RegisterResources(struct ResearchCommon *common)
{
    u16 heapId = common->heapId;
    void *arc = ARC_TOOL_CreateHandle(83, (u16)((heapId & 0x7FFF) | 0x8000));
    int charId = CLACT_RegisterCharacter(arc, 20, 0, 0, heapId);
    int paletteId = CLACT_RegisterPaletteEx(arc, 19, 0, 0, 0, 4, heapId);
    int cellAnimId = CLACT_RegisterCellAnim(arc, 21, 24, heapId);
    common->resourceIds[0] = charId;
    common->resourceIds[1] = paletteId;
    common->resourceIds[2] = cellAnimId;
    ARC_TOOL_DeleteHandle(arc);
}

/* Releases the three resources. */
void RESEARCH_COMMON_ReleaseResources(struct ResearchCommon *common)
{
    CLACT_ReleaseCharacter(common->resourceIds[0]);
    CLACT_ReleasePalette(common->resourceIds[1]);
    CLACT_ReleaseCellAnim(common->resourceIds[2]);
}

/* Clears the CLACT unit slot. */
void RESEARCH_COMMON_ClearClactUnit(struct ResearchCommon *common)
{
    common->clactUnits[0] = 0;
}

/* Creates the CLACT unit, one actor wide. */
void RESEARCH_COMMON_CreateClactUnit(struct ResearchCommon *common)
{
    common->clactUnits[0] = (struct ClactUnit *)CLACT_CreateUnit(1, 2, common->heapId);
}

/* Deletes the CLACT unit. */
void RESEARCH_COMMON_DeleteClactUnit(struct ResearchCommon *common)
{
    CLACT_DeleteUnit((struct Unit *)common->clactUnits[0]);
}

/* Clears the actor slot. */
void RESEARCH_COMMON_ClearActor(struct ResearchCommon *common)
{
    common->actor = 0;
}

/* Creates the shared actor from the ROM template and shows it. */
void RESEARCH_COMMON_CreateActor(struct ResearchCommon *common)
{
    struct ActorHeader header;
    uptr unit; u32 charId, paletteId, cellAnimId;
    header.x = d_021C3F80.header.x;
    header.y = d_021C3F80.header.y;
    header.z = d_021C3F80.header.z;
    header.animNo = d_021C3F80.header.animNo;
    header.bgPriority = d_021C3F80.header.bgPriority;
    unit = RESEARCH_COMMON_GetClactUnit(common, d_021C3F80.unitIndex);
    charId = RESEARCH_COMMON_GetResourceId(common, d_021C3F80.charIndex);
    paletteId = RESEARCH_COMMON_GetResourceId(common, d_021C3F80.paletteIndex);
    cellAnimId = RESEARCH_COMMON_GetResourceId(common, d_021C3F80.cellAnimIndex);
    common->actor = CLACT_CreateActor((struct Unit *)unit, charId, paletteId, cellAnimId, (const struct ActorInitParam *)&header, d_021C3F80.priority, common->heapId);
    CLACT_SetActorDrawEnable((struct ClactActor *)common->actor, 1);
}

/* Deletes the shared actor. */
void RESEARCH_COMMON_DeleteActor(struct ResearchCommon *common)
{
    CLACT_DeleteActor((struct ClactActor *)common->actor);
}

/* Clears the palette-animation system slot. */
void RESEARCH_COMMON_ClearPalAnm(struct ResearchCommon *common)
{
    common->palAnm = 0;
}

/* Creates the palette-animation system. */
void RESEARCH_COMMON_CreatePalAnm(struct ResearchCommon *common)
{
    common->palAnm = PALANM_Create(common->heapId);
}

/* Deletes the palette-animation system. */
void RESEARCH_COMMON_DeletePalAnm(struct ResearchCommon *common)
{
    PALANM_Delete(common->palAnm);
}

/* Allocates four 512-byte palette slot buffers and fills them from the hardware palettes. */
void RESEARCH_COMMON_AllocSlotBuffers(struct ResearchCommon *common)
{
    struct PaletteFade *slots = common->palAnm;
    PALANM_AllocSlotBuffers(slots, 0, 512, common->heapId);
    PALANM_AllocSlotBuffers(slots, 2, 512, common->heapId);
    PALANM_AllocSlotBuffers(slots, 1, 512, common->heapId);
    PALANM_AllocSlotBuffers(slots, 3, 512, common->heapId);
    PALANM_CopyHwPaletteToSlot(slots, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 2, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 1, 0, 512);
    PALANM_CopyHwPaletteToSlot(slots, 3, 0, 512);
}

/* Frees the four palette slot buffers. */
void RESEARCH_COMMON_FreeSlotBuffers(struct ResearchCommon *common)
{
    struct PaletteFade *slots = common->palAnm;
    PALANM_FreeSlotBuffers(slots, 0);
    PALANM_FreeSlotBuffers(slots, 2);
    PALANM_FreeSlotBuffers(slots, 1);
    PALANM_FreeSlotBuffers(slots, 3);
}

/* Clears the palette-animation slot. */
void RESEARCH_COMMON_ClearPaletteAnime(struct ResearchCommon *common)
{
    common->paletteAnime[0] = 0;
}

/* Creates the palette animation. */
void RESEARCH_COMMON_CreatePaletteAnime(struct ResearchCommon *common)
{
    common->paletteAnime[0] = PALETTE_ANIME_Create(common->heapId);
}

/* Destroys the palette animation. */
void RESEARCH_COMMON_DestroyPaletteAnime(struct ResearchCommon *common)
{
    PALETTE_ANIME_Destroy(common->paletteAnime[0]);
}

/* Binds the palette animation to its palette range from ROM data. */
extern const struct PaletteAnimeBindData d_021C3F50;

void RESEARCH_COMMON_BindPaletteAnime(struct ResearchCommon *common)
{
    const struct PaletteAnimeBindData *bind = &d_021C3F50;
    PALETTE_ANIME_Bind(common->paletteAnime[0], bind->palette, bind->original, bind->colorCount);
}

/* Restores the colours of palette animation 0. */
void RESEARCH_COMMON_ExitPaletteAnime(struct ResearchCommon *common)
{
    PALETTE_ANIME_Restore((struct PaletteAnime *)common->paletteAnime[0]);
}

/* Starts palette animation index with mode and colour from the preset table (stride 0x14). */
void RESEARCH_COMMON_StartPaletteAnimeImpl(struct ResearchCommon *common, u32 index)
{
    PALETTE_ANIME_Start((struct PaletteAnime *)common->paletteAnime[index],
                  *(u32 *)(d_021C3F5C + index * 0x14),
                  *(u16 *)(d_021C3F60 + index * 0x14));
}

/* Stops the palette animation at index. */
void RESEARCH_COMMON_StopPaletteAnimeImpl(struct ResearchCommon *common, u32 index)
{
    PALETTE_ANIME_Stop(common->paletteAnime[index]);
}

/* Restores the colours of the palette animation at index. */
void RESEARCH_COMMON_RestorePaletteAnimeImpl(struct ResearchCommon *common, u32 index)
{
    PALETTE_ANIME_Restore((struct PaletteAnime *)common->paletteAnime[index]);
}

/* Advances palette animation 0 by one frame. */
void RESEARCH_COMMON_UpdatePaletteAnimeImpl(struct ResearchCommon *common)
{
    PALETTE_ANIME_Update(common->paletteAnime[0]);
}

/* Copies the two touch rectangles from ROM, reordering each pair of bytes. */
#ifdef __MWERKS__
void RESEARCH_COMMON_InitTouchRects(struct ResearchCommon *common)
{
    int i;
    u8 *base = (u8 *)common;
    for (i = 0; i < 2; i++) {
        base[i * 4 + 0xE] = d_021C3F48[i * 4];
        base[i * 4 + 0xF] = d_021C3F48[i * 4 + 1];
        base[i * 4 + 0xC] = d_021C3F48[i * 4 + 2];
        base[i * 4 + 0xD] = d_021C3F48[i * 4 + 3];
    }
}
#else
void RESEARCH_COMMON_InitTouchRects(struct ResearchCommon *common)
{
    int i;
    for (i = 0; i < 2; i++) {
        common->touchRects[i].left = d_021C3F48[i * 4];
        common->touchRects[i].right = d_021C3F48[i * 4 + 1];
        common->touchRects[i].top = d_021C3F48[i * 4 + 2];
        common->touchRects[i].bottom = d_021C3F48[i * 4 + 3];
    }
}
#endif

/* Returns resource id index. */
u32 RESEARCH_COMMON_GetResourceId(struct ResearchCommon *common, u32 index)
{
    return common->resourceIds[index];
}

/* Returns CLACT unit index. */
u32 RESEARCH_COMMON_GetClactUnit(struct ResearchCommon *common, u32 index)
{
    return (uptr)common->clactUnits[index];
}
