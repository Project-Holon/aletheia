/*
 * file:     townmap.c
 * unit:     yes
 * function: TOWNMAP_Create, TOWNMAP_Destroy, TOWNMAP_Update, TOWNMAP_ProcInit, TOWNMAP_ProcClear, TOWNMAP_ProcRun, TOWNMAP_ProcIsFinished, TOWNMAP_ProcSetStep, TOWNMAP_ProcFinish, TOWNMAP_StepFadeIn, TOWNMAP_StepFadeOut, TOWNMAP_StepBrowse, TOWNMAP_BackButtonInit, TOWNMAP_BackButtonFree, TOWNMAP_BackButtonUpdate, TOWNMAP_BackButtonGetPressed, TOWNMAP_BackButtonIsHeld, TOWNMAP_CursorInit, TOWNMAP_CursorClear, TOWNMAP_CursorUpdate, TOWNMAP_CursorGetPos, TOWNMAP_CursorSetPos, TOWNMAP_CursorIsPressed, TOWNMAP_CursorGetHeldKeys, TOWNMAP_CursorSetHoverTown, TOWNMAP_CursorMoveHoverSprite, TOWNMAP_CursorGetHoverTown, TOWNMAP_CursorSetSnapToTown, TOWNMAP_MapInit, TOWNMAP_MapFree, TOWNMAP_MapUpdate, TOWNMAP_MapSetZoom, TOWNMAP_MapSetScroll, TOWNMAP_MapGetScroll, TOWNMAP_MapAddScroll, TOWNMAP_MapFindTownUnderCursor, TOWNMAP_MapFindNearestTown, TOWNMAP_TownGetField, TOWNMAP_MapHighlightTown, TOWNMAP_MapClearHighlight, TOWNMAP_MapFindTownById, TOWNMAP_TownIsRevealed, TOWNMAP_TownInit, TOWNMAP_TownFree, TOWNMAP_TownSetShown, TOWNMAP_TownHitTest, TOWNMAP_TownTestNear, TOWNMAP_TownSetScale, TOWNMAP_TownSetScroll, TOWNMAP_TownSetFrame, TOWNMAP_TownHighlight, TOWNMAP_TownUnhighlight, TOWNMAP_MarkerInit, TOWNMAP_DeleteMarker, TOWNMAP_UpdateMarkerPosition, TOWNMAP_InitScroll, TOWNMAP_ClearScroll, TOWNMAP_StepScrollZoom, TOWNMAP_StartScrollZoom, TOWNMAP_IsScrollZoomDone, TOWNMAP_IsScrollZooming, TOWNMAP_ApplyScroll, TOWNMAP_GetScrollPosition, TOWNMAP_MoveScroll, TOWNMAP_InitSelection, TOWNMAP_ExitSelection, TOWNMAP_DrawSelection, TOWNMAP_ClearSelection
 * address:  0x021B95A0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   ov067_id       0x00000043  data
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GF_FONT_Create  0x0201D7EC  thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GF_FONT_SetTextColor  0x0201DD78  thumb
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb
 *   BG_SYS_ChangeScrollImmediate  0x02040618  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_RefreshWmIconAtTopRight  0x0203D34C  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   TCB_DeleteTask  0x02030EAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   FADE_Start  0x0204E720  arm
 *   FADE_IsActive  0x0204E804  arm
 *   UI_GetInputMode 0x020355C4 arm
 *   d_021BBB78 0x021BBB78 data ov072 a4
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_StopActorAnim  0x0204B974  arm
 *   TOUCHBAR_Create  0x021B62E0  thumb  ov067
 *   TOUCHBAR_SetAllButtonsPriority  0x021B6520  thumb  ov067
 *   d_021BBB8C     0x021BBB8C  data  a4
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   TOUCHBAR_Update  0x021B63D0  thumb  ov067
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   TOUCHPANEL_GetPointTrg  0x02035D20  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   CLACT_GetActorAnimSeq  0x0204B898  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_StartActorAnim  0x0204B95C  arm
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   TOUCHBAR_IsBusy  0x021B6498  thumb  ov067
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   KEY_GetCont  0x0203630C  arm
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Mag        0x0207CBD0  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   BUTTON_MAN_ScaleVec  0x020520A4  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   d_021BBD60     0x021BBD60  data  ov072
 *   GFL_HEAP_Free 0x020307B0 arm
 *   SYMBOL_MAP_ResolveZoneId 0x02166C7C thumb ov010
 *   SYMBOL_MAP_CheckEventFlag  0x02166CD0  thumb  ov010
 *   CLACT_SetActorAffineMode  0x0204B570  arm
 *   BUTTON_MAN_InitSphere  0x02051F1C  arm
 *   BUTTON_MAN_InitSegment  0x0205207C  arm
 *   BUTTON_MAN_SegmentSphereTest  0x02051F34  arm
 *   CLACT_SetActorScale  0x0204B5AC  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   TOWNMAP_DeleteMarker  0x021BAF24  thumb
 *   TOWNMAP_UpdateMarkerPosition  0x021BAF3C  thumb
 *   TOWNMAP_InitScroll  0x021BAF74  thumb
 *   TOWNMAP_ClearScroll  0x021BAF9C  thumb
 *   TOWNMAP_StepScrollZoom  0x021BAFA8  thumb
 *   TOWNMAP_StartScrollZoom  0x021BB0B4  thumb
 *   TOWNMAP_IsScrollZoomDone  0x021BB0DC  thumb
 *   TOWNMAP_IsScrollZooming  0x021BB0E0  thumb
 *   TOWNMAP_ApplyScroll  0x021BB0E4  thumb
 *   TOWNMAP_GetScrollPosition  0x021BB190  thumb
 *   TOWNMAP_MoveScroll  0x021BB19C  thumb
 *   TOWNMAP_InitSelection  0x021BB1BC  thumb
 *   TOWNMAP_ExitSelection  0x021BB204  thumb
 *   TOWNMAP_DrawSelection  0x021BB220  thumb
 *   TOWNMAP_ClearSelection  0x021BB3D0  thumb
 *   TOWNMAP_GRH_InitTextBox  0x021BB3E8  thumb
 *   TOWNMAP_GRH_ExitTextBox  0x021BB42C  thumb
 *   TOWNMAP_GRH_PrintTextBoxMessage  0x021BB448  thumb
 *   TOWNMAP_GRH_ClearTextBox  0x021BB49C  thumb
 *   TOWNMAP_GRH_InitLabel  0x021BB4B4  thumb
 *   TOWNMAP_GRH_ExitLabel  0x021BB534  thumb
 *   TOWNMAP_GRH_UpdateLabel  0x021BB548  thumb
 *   TOWNMAP_GRH_SetLabelTown  0x021BB5AC  thumb
 *   TOWNMAP_GRH_SetLabelVisible  0x021BB5B4  thumb
 *   TOWNMAP_GRH_InitTouch  0x021BB5D4  thumb
 *   TOWNMAP_GRH_ClearTouch  0x021BB5E0  thumb
 *   TOWNMAP_GRH_UpdateTouch  0x021BB5EC  thumb
 *   TOWNMAP_GRH_GetTouchDrag  0x021BB6AC  thumb
 *   TOWNMAP_GRH_RestartTouchDrag  0x021BB6DC  thumb
 *   TOWNMAP_GRH_EmptyTask  0x021BB6E4  thumb
 *   TOWNMAP_GRH_Create  0x021BB6E8  thumb
 *   TOWNMAP_GRH_Delete  0x021BB738  thumb
 *   TOWNMAP_GRH_DrawSprites  0x021BB758  thumb
 *   TOWNMAP_GRH_GetBgId  0x021BB764  thumb
 *   TOWNMAP_GRH_GetHandle  0x021BB778  thumb
 *   TOWNMAP_GRH_GetActor  0x021BB784  thumb
 *   TOWNMAP_GRH_GetResourceIds  0x021BB790  thumb
 *   TOWNMAP_GRH_ResetDisplay  0x021BB7BC  thumb
 *   TOWNMAP_GRH_UpdateTask  0x021BB80C  thumb
 *   TOWNMAP_GRH_InitBgLayers  0x021BB820  thumb
 *   TOWNMAP_GRH_ExitBgLayers  0x021BB968  thumb
 *   TOWNMAP_GRH_TransferBgData  0x021BB9B0  thumb
 *   TOWNMAP_GRH_InitSprites  0x021BB9B8  thumb
 *   TOWNMAP_GRH_ExitSprites  0x021BBAB4  thumb
 *   TOWNMAP_GRH_DrawClactSystem  0x021BBAFC  thumb
 *   TOWNMAP_GRH_VBlankSprites  0x021BBB04  thumb
 *   TOWNMAP_GRH_GetSpriteActor  0x021BBB0C  thumb
 *   TOWNMAP_GRH_GetSpriteHandle  0x021BBB14  thumb
 *   TOWNMAP_GRH_GetSpriteResourceId  0x021BBB1C  thumb
 *   TOWNMAP_GRH_LoadTownInfo  0x021BBB24  thumb
 *   TOWNMAP_GRH_FreeTownInfo  0x021BBB34  thumb
 *   TOWNMAP_GRH_GetTownInfoValue  0x021BBB3C  thumb
 *   BG_SYS_ChangeScroll  0x02041EE4  arm
 *   BG_SYS_ChangeCenter  0x02041FB0  arm
 *   BG_SYS_ChangeScale  0x02041F6C  arm
 *   BMP_WIN_GetWidth  0x02045738  arm
 *   PRINTSYS_MeasureWidestLine  0x0201D304  thumb
 *   TOWNMAP_MapSetZoom  0x021BA5B0  thumb
 *   TOWNMAP_TownIsRevealed  0x021BA834  thumb
 *   BMP_WIN_Create  0x020450F0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   BG_SYS_MarkTileDirty  0x02041B6C  arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   TOWNMAP_TownGetField  0x021BA774  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "townmap_types.h"

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct GfFont;
struct HeapTask;
struct Ctx;
struct MsgBank;
struct Node;
struct Rec;
struct Proc;
struct Actor;
struct PtS;
struct Vec2;
struct Out;
struct TownmapVec3;
struct TownmapVec;
struct Pair;
#include "../arm9/bg_sys.h"

#include "../types.h"

struct TouchBar;

typedef struct { u32 w[16]; } ButtonTable;

typedef struct { int x,y,z; } TownmapVec;

struct TownmapVec3 { int x; int y; int z; };

struct TownmapPt { u16 x; u16 y; };

#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gf_font.h"
#include "../arm9/msgdata.h"
struct GameSystem;
struct GameData;
#include "../arm9/gamesystem.h"
#include "../arm9/net.h"
struct TcbTask;
#include "../arm9/gfl_use.h"
struct TcbTask;
#include "../arm9/tcb_list.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/fade.h"
#include "../arm9/ui.h"
#include "../arm9/arc_tool.h"
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
#ifdef __MWERKS__
#define CLACT_RegisterCharacter CLACT_RegisterCharacterHeader
#endif
#include "../arm9/clact.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef CLACT_RegisterCharacter
extern s32 CLACT_RegisterCharacter(void *arc, u32 id, u32 a, u32 b, u32 heap);
#endif
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
struct ClactActor;
struct Unit;
struct ActorInitParam;
struct ClactVec2;
struct Pair32;
#include "../ov067/touchbar_types.h"
extern struct ClactActor *CLACT_CreateActor(struct Unit *unit, u32 char_idx, u32 pltt_idx, u32 cell_idx, const struct ActorInitParam *init, u16 space, u16 heap_id);
extern void CLACT_SetActorAutoAnim(struct ClactActor *actor, u32 enable);
extern void CLACT_StopActorAnim(struct ClactActor *actor);
#ifdef __MWERKS__
#define TOUCHBAR_Create TOUCHBAR_CreateHeader
#endif
#include "../ov067/touchbar.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef TOUCHBAR_Create
extern struct TouchBar *TOUCHBAR_Create(TouchBarParams *r, int heap);
#endif
extern void TOUCHBAR_Delete(TouchBar *bar);
extern void CLACT_DeleteActor(struct ClactActor *actor);
extern void CLACT_ReleaseCellAnim(u32 idx);
extern void CLACT_ReleaseCharacter(u32 idx);
extern void CLACT_ReleasePalette(u32 idx);
extern void TOUCHBAR_Update(TouchBar *bar);
extern void CLACT_GetActorSurfacePos(struct ClactActor *actor, struct ClactVec2 *out, u16 space);
#include "../arm9/touchpanel.h"
#include "../arm9/key.h"
extern u32 CLACT_IsActorAnimActive(struct ClactActor *actor);
extern u16 CLACT_GetActorAnimSeq(struct ClactActor *actor);
extern void CLACT_SetActorAnimSeq(struct ClactActor *actor, u16 value);
extern void CLACT_StartActorAnim(struct ClactActor *actor);
extern int TOUCHBAR_GetPressedButtonIdIfDone(TouchBar *bar);
extern int TOUCHBAR_IsBusy(TouchBar *bar);
extern void CLACT_AddActorSurfacePos(struct ClactActor *actor, const struct ClactVec2 *delta, u32 which);
extern void CLACT_SetActorDrawEnable(struct ClactActor *actor, u32 value);
extern void CLACT_SetActorBgPriority(struct ClactActor *actor, unsigned int priority);
#include "../arm9/fx_vec.h"
#include "../arm9/button_man.h"
extern void CLACT_RestartActorAnim(struct ClactActor *actor);
#include "../ov010/symbol_map.h"
extern void CLACT_SetActorAffineMode(struct ClactActor *actor, u32 value);
struct Pair32;
extern void CLACT_SetActorScale(struct ClactActor *actor, struct Pair32 *src);
int TOWNMAP_Create(void *taskArg, void *unused, TownMapArgs *args);
int TOWNMAP_Destroy(void *taskArg, int unusedA, int unusedB, TownMapWork *work);
int TOWNMAP_Update(int taskArg, int unusedA, int unusedB, TownMapWork *work);
void TOWNMAP_ProcInit(TownMapProc *proc, TownMapWork *work, TownMapStepFunc step);
void TOWNMAP_ProcClear(TownMapProc *proc);
void TOWNMAP_ProcRun(TownMapProc *proc);
int TOWNMAP_ProcIsFinished(TownMapProc *proc);
void TOWNMAP_ProcSetStep(TownMapProc *proc, TownMapStepFunc step);
void TOWNMAP_ProcFinish(TownMapProc *proc);
void TOWNMAP_StepFadeIn(TownMapProc *proc, int *state, struct TownMapWork *unused2);
void TOWNMAP_StepFadeOut(TownMapProc *proc, int *state, struct TownMapWork *unused2);
void TOWNMAP_StepBrowse(TownMapProc *proc,int *unusedState,TownMapWork *work);
void TOWNMAP_BackButtonInit(TownMapButtonBar *bar, u32 unusedMode, struct Unit *clactSet, u8 bgLayer, u8 palette, u8 tileBase, u32 ctx, u16 heapId);
void TOWNMAP_BackButtonFree(TownMapButtonBar *bar);
void TOWNMAP_BackButtonUpdate(TownMapButtonBar *bar, void *scroll);
int TOWNMAP_BackButtonGetPressed(TownMapButtonBar *bar);
int TOWNMAP_BackButtonIsHeld(TownMapButtonBar *bar);
void TOWNMAP_CursorInit(TownMapCursor *cursor, void *arrowSprite, void *hoverSprite, int heapId);
void TOWNMAP_CursorClear(TownMapCursor *cursor);
void TOWNMAP_CursorUpdate(TownMapCursor *cursor, TownMapMap *map);
void TOWNMAP_CursorGetPos(TownMapCursor *cursor, TownMapPoint *pos);
void TOWNMAP_CursorSetPos(TownMapCursor *cursor, const TownMapPoint *pos);
int TOWNMAP_CursorIsPressed(TownMapCursor *cursor);
int TOWNMAP_CursorGetHeldKeys(TownMapCursor *cursor);
void TOWNMAP_CursorSetHoverTown(TownMapCursor *cursor, TownMapTown *town, const TownMapPoint *scroll);
void TOWNMAP_CursorMoveHoverSprite(TownMapCursor *cursor, const TownMapPoint *scroll);
TownMapTown *TOWNMAP_CursorGetHoverTown(TownMapCursor *cursor);
void TOWNMAP_CursorSetSnapToTown(TownMapCursor *cursor, int snapToTown);
void TOWNMAP_MapInit(TownMapMap *map, u16 townId, u16 townSubId, struct TownMapInfoRow *mapInfo, TownMapGfx *gfx, struct GameData *gameData, u16 heapId, int pickMode);
void TOWNMAP_MapFree(TownMapMap *map);
void TOWNMAP_MapUpdate(TownMapMap *map);
void TOWNMAP_MapSetZoom(TownMapMap *map, u32 scale, const TownMapPoint *center);
void TOWNMAP_MapSetScroll(TownMapMap *map, const TownMapPoint *scroll);
void TOWNMAP_MapGetScroll(TownMapMap *map, TownMapPoint *scroll);
void TOWNMAP_MapAddScroll(TownMapMap *map, const TownMapPoint *delta);
TownMapTown *TOWNMAP_MapFindTownUnderCursor(TownMapMap *map, TownMapCursor *cursor);
TownMapTown *TOWNMAP_MapFindNearestTown(TownMapMap *map, TownMapCursor *cursor);
int TOWNMAP_TownGetField(TownMapTown *town, int field);
void TOWNMAP_MapHighlightTown(TownMapMap *map, TownMapTown *selected);
void TOWNMAP_MapClearHighlight(TownMapMap *map);
TownMapTown *TOWNMAP_MapFindTownById(TownMapMap *map, u32 townId, int townSubId);
int TOWNMAP_TownIsRevealed(TownMapTown *town);
void TOWNMAP_TownInit(TownMapTown *town, struct TownMapInfoRow *mapInfo, int townIndex, struct Unit *clactSet, int plttRes, int cellRes, int charRes, void *gameData, u16 heapId, int pickMode);
void TOWNMAP_TownFree(TownMapTown *town);
void TOWNMAP_TownSetShown(TownMapTown *town, int shown);
u32 TOWNMAP_TownHitTest(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll);
int TOWNMAP_TownTestNear(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll, u32 *distSq);
void TOWNMAP_TownSetScale(TownMapTown *town, int scale, const TownMapPoint *center);
void TOWNMAP_TownSetScroll(TownMapTown *town, const TownMapPoint *scroll);
void TOWNMAP_TownSetFrame(TownMapTown *town, int frame);
void TOWNMAP_TownHighlight(TownMapTown *town);
void TOWNMAP_TownUnhighlight(TownMapTown *town);
void TOWNMAP_MarkerInit(TownMapMarker *marker, TownMapTown *town, struct Unit *clactSet, int plttRes, int cellRes, int charRes, u16 heapId);
void TOWNMAP_DeleteMarker(TownMapMarker *marker);
void TOWNMAP_UpdateMarkerPosition(TownMapMarker *marker, const TownMapPoint *scroll);
void TOWNMAP_InitScroll(TownMapScroll *scroll, u32 bgIdA, u32 bgIdB, int heapId);
void TOWNMAP_ClearScroll(TownMapScroll *scroll);
void TOWNMAP_StepScrollZoom(TownMapScroll *scroll, TownMapMap *map);
void TOWNMAP_StartScrollZoom(TownMapScroll *scroll, int scaleTo, const TownMapPoint *from, const TownMapPoint *to);
int TOWNMAP_IsScrollZoomDone(TownMapScroll *scroll);
int TOWNMAP_IsScrollZooming(TownMapScroll *scroll);
void TOWNMAP_ApplyScroll(TownMapScroll *scroll, const TownMapPoint *pos);
void TOWNMAP_GetScrollPosition(TownMapScroll *scroll, TownMapPoint *out);
void TOWNMAP_MoveScroll(TownMapScroll *scroll, const TownMapPoint *delta);
void TOWNMAP_InitSelection(TownMapSelection *sel, int bgId, void *font, struct MsgBank *nameMsg, struct MsgBank *detailMsg, u16 heapId);
void TOWNMAP_ExitSelection(TownMapSelection *sel);
void TOWNMAP_DrawSelection(TownMapSelection *sel, TownMapTown *town);
void TOWNMAP_ClearSelection(TownMapSelection *sel);
#include "townmap_grh.h"
struct TownMapInfoRow;
extern char ov067_id[];
extern const TownMapPoint d_021BBB78;
extern ButtonTable d_021BBB8C;
extern char d_021BBD60[];
struct BmpWin;
#include "../arm9/bmp_win.h"
struct Strbuf;
#include "../arm9/strbuf.h"
struct Bmp;
typedef short s16_p07;
#include "../arm9/bmp.h"
#include "../arm9/zonedata.h"
#include "../arm9/printsys.h"

int TOWNMAP_Create(void *taskArg, void *unused, TownMapArgs *args)
{
    TownMapPoint pt;
    TownMapPoint org;
    TownMapWork *work;
    u32 ctx;
    int pickMode;
    TownMapTown *town;

    GF_OVERLAY_Load((uptr)ov067_id);
    GFL_HEAP_CreateChildHeap(1, 0x44, 0x60000);
    work = PROCSYS_AllocProcWork(taskArg, sizeof(TownMapWork), 0x44);
    MI_CpuFill8(work, 0, sizeof(TownMapWork));
    work->args = args;
    pickMode = work->args->mode == 2;
    work->fontSystem = GF_FONT_Create(0x17, 0, 0, 0, 0x44);
    work->nameMsg = MSGDATA_CreateFromArchive(0, 2, 0x59, 0x44);
    work->detailMsg = MSGDATA_CreateFromArchive(0, 2, 0xb9, 0x44);
    work->gfx = TOWNMAP_GRH_Create(0x44);
    work->mapInfo = TOWNMAP_GRH_LoadTownInfo(0x44);
    TOWNMAP_ProcInit(&work->proc, work, TOWNMAP_StepFadeIn);
    ctx = (uptr)GAMESYSTEM_GetGameData((struct GameSystem *)work->args->gameCtx);
    if (work->args->mode != 1) {
        TOWNMAP_GRH_InitTextBox(&work->panel, TOWNMAP_GRH_GetBgId(work->gfx, 1), work->fontSystem, work->detailMsg, 0, 0x15, 0x18, 3, 0x44);
        GF_FONT_SetTextColor(0xf, 1, 0);
        TOWNMAP_GRH_PrintTextBoxMessage(&work->panel, 0, 0x10, 0);
        GF_FONT_SetDefaultTextColor();
    }
    TOWNMAP_BackButtonInit(&work->buttonBar, work->args->mode, TOWNMAP_GRH_GetHandle(work->gfx, 0), TOWNMAP_GRH_GetBgId(work->gfx, 0), 0xf, 8, ctx, 0x44);
    TOWNMAP_GRH_InitLabel(&work->label, TOWNMAP_GRH_GetBgId(work->gfx, 1), work->fontSystem, work->nameMsg, TOWNMAP_GRH_GetActor(work->gfx, 0), 0x44);
    BG_SYS_ChangeScrollImmediate(TOWNMAP_GRH_GetBgId(work->gfx, 1), 3, -4);
    TOWNMAP_MapInit(&work->map, args->townId, args->townSubId, work->mapInfo, work->gfx, GAMESYSTEM_GetGameData((struct GameSystem *)work->args->gameCtx), (u16)0x44, pickMode);
    TOWNMAP_CursorInit(&work->cursor, (void *)TOWNMAP_GRH_GetActor(work->gfx, 1), (void *)TOWNMAP_GRH_GetActor(work->gfx, 2), 0x44);
    town = TOWNMAP_MapFindTownById(&work->map, args->townId, args->townSubId);
    if (town != 0) {
        pt.x = TOWNMAP_TownGetField(town, 4);
        pt.y = TOWNMAP_TownGetField(town, 5);
    } else {
        pt.x = 0x80;
        pt.y = 0x60;
    }
    TOWNMAP_CursorSetPos(&work->cursor, &pt);
    TOWNMAP_InitScroll(&work->scroll, TOWNMAP_GRH_GetBgId(work->gfx, 3), TOWNMAP_GRH_GetBgId(work->gfx, 2), 0x44);
    TOWNMAP_InitSelection(&work->selection, TOWNMAP_GRH_GetBgId(work->gfx, 5), work->fontSystem, work->nameMsg, work->detailMsg, 0x44);
    TOWNMAP_GRH_InitTouch(&work->touch, 0x44);
    town = TOWNMAP_MapFindTownUnderCursor(&work->map, &work->cursor);
    if (town != 0) {
        TOWNMAP_GRH_SetLabelTown(&work->label, town);
        TOWNMAP_DrawSelection(&work->selection, town);
        work->hoverTown = town;
        TOWNMAP_MapGetScroll(&work->map, &org);
        TOWNMAP_CursorSetHoverTown(&work->cursor, town, &org);
    }
    if (GFL_NET_GetRunState()) {
        GFL_NET_RefreshWmIconAtTopRight(1, 0x44);
    }
    work->vblankTask = GFL_USE_AddMainTask(TOWNMAP_GRH_EmptyTask, (void *)work, 0);
    return 1;
}

int TOWNMAP_Destroy(void *taskArg, int unusedA, int unusedB, TownMapWork *work)
{
    TCB_DeleteTask(work->vblankTask);
    TOWNMAP_GRH_ClearTouch(&work->touch);
    TOWNMAP_ExitSelection(&work->selection);
    TOWNMAP_ClearScroll(&work->scroll);
    TOWNMAP_MapFree(&work->map);
    TOWNMAP_CursorClear(&work->cursor);
    TOWNMAP_GRH_ExitLabel(&work->label);
    if (work->args->mode != 1) {
        TOWNMAP_GRH_ExitTextBox(&work->panel);
    }
    TOWNMAP_BackButtonFree(&work->buttonBar);
    TOWNMAP_ProcClear(&work->proc);
    TOWNMAP_GRH_FreeTownInfo(work->mapInfo);
    TOWNMAP_GRH_Delete(work->gfx);
    MSGDATA_Delete((struct MsgBank *)work->detailMsg);
    MSGDATA_Delete((struct MsgBank *)work->nameMsg);
    GF_FONT_Delete(work->fontSystem);
    PROCSYS_FreeProcWork(taskArg);
    GFL_HEAP_DeleteChecked(0x44);
    GF_OVERLAY_Unload((uptr)ov067_id);
    return 1;
}

int TOWNMAP_Update(int taskArg, int unusedA, int unusedB, TownMapWork *work) {
    TOWNMAP_ProcRun(&work->proc);
    TOWNMAP_GRH_DrawSprites(work->gfx);
    return TOWNMAP_ProcIsFinished(&work->proc) != 0;
}

void TOWNMAP_ProcInit(TownMapProc *proc, TownMapWork *work, TownMapStepFunc step)
{
    MI_CpuFill8(proc, 0, sizeof(TownMapProc));
    proc->arg = work;
    TOWNMAP_ProcSetStep(proc, step);
}

void TOWNMAP_ProcClear(TownMapProc *proc)
{
    MI_CpuFill8(proc, 0, sizeof(TownMapProc));
}

void TOWNMAP_ProcRun(TownMapProc *proc) {
    if (proc->finished == 0) proc->call(proc, &proc->stepState, proc->arg);
}

int TOWNMAP_ProcIsFinished(TownMapProc *proc)
{
    return proc->finished;
}

void TOWNMAP_ProcSetStep(TownMapProc *proc, TownMapStepFunc step)
{
    proc->call = step;
    proc->stepState = 0;
}

void TOWNMAP_ProcFinish(TownMapProc *proc)
{
    proc->finished = 1;
}

void TOWNMAP_StepFadeIn(TownMapProc *proc, int *state, struct TownMapWork *unused2)
{
    switch (state[0]) {
    case 0:
        FADE_Start(3, 0x10, 0, 0);
        state[0] = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) {
            state[0] = 2;
        }
        break;
    case 2:
        TOWNMAP_ProcSetStep(proc, TOWNMAP_StepBrowse);
        break;
    }
}

/*
 * note: trailing two-byte alignment padding.
 */
void TOWNMAP_StepFadeOut(TownMapProc *proc, int *state, struct TownMapWork *unused2) {
    switch (*state) {
    case 0: FADE_Start(3,0,16,0); *state = 1; break;
    case 1: if (FADE_IsActive() == 0) *state = 2; break;
    case 2: TOWNMAP_ProcFinish(proc); break;
    }
}

void TOWNMAP_StepBrowse(TownMapProc *proc,int *unusedState,TownMapWork *work)
{
    u8 moved;
    TownMapTown *hovered;
    int keys;
    TownMapTown *under;
    int pressed;
    moved=0;
    if (TOWNMAP_BackButtonIsHeld(&work->buttonBar) == 0) {
        if (work->zooming!=0 && TOWNMAP_IsScrollZooming(&work->scroll)==0) {
            TownMapVec touchDelta;
            TownMapPoint pos,delta={0,0};
            u32 touchOut;
            TownMapPoint scrollBefore,scrollAfter;
            TOWNMAP_CursorGetPos(&work->cursor,&pos);
            keys=TOWNMAP_CursorGetHeldKeys(&work->cursor);
            if (pos.y<16 && (keys&0x40)) { delta.y-=4; moved=1; }
            if (pos.y<=168 && pos.y>136 && (keys&0x80)) { delta.y+=4; moved=1; }
            if (pos.x<16 && (keys&0x20)) { delta.x-=4; moved=1; }
            if (pos.x>240 && (keys&0x10)) { delta.x+=4; moved=1; }
            if (TOWNMAP_IsScrollZooming(&work->scroll)==0 && TOWNMAP_GRH_GetTouchDrag(&work->touch,&touchDelta,&touchOut)) {
                delta.x=-(int)(((s64)touchDelta.x*4096+2048)>>12)>>12;
                delta.y=-(int)(((s64)touchDelta.y*4096+2048)>>12)>>12;
                TOWNMAP_GRH_RestartTouchDrag(&work->touch); moved=1;
            }
            if (moved != 0) {
                TOWNMAP_MapGetScroll(&work->map,&scrollBefore);
                TOWNMAP_MoveScroll(&work->scroll,&delta);
                delta.x*=-1; delta.y*=-1;
                TOWNMAP_MapAddScroll(&work->map,&delta);
                TOWNMAP_MapGetScroll(&work->map,&scrollAfter);
                TOWNMAP_CursorMoveHoverSprite(&work->cursor,&scrollAfter);
            }
        }
        if (moved==0 && TOWNMAP_IsScrollZooming(&work->scroll)==0) {
            if (work->args->mode==0 || work->args->mode==2) {
                hovered=TOWNMAP_CursorGetHoverTown(&work->cursor);
                under=TOWNMAP_MapFindTownUnderCursor(&work->map, &work->cursor);
                if (hovered!=0 && hovered==under && TOWNMAP_CursorIsPressed(&work->cursor)!=0 && TOWNMAP_TownGetField(hovered,12)!=0) {
                    work->args->result=2;
                    work->args->townId=TOWNMAP_TownGetField(hovered,0);
                    work->args->pickedX=TOWNMAP_TownGetField(hovered,13);
                    work->args->pickedY=TOWNMAP_TownGetField(hovered,14);
                    GFL_USE_PlaySeDefaultVolume(0x54c); TOWNMAP_ProcSetStep(proc,TOWNMAP_StepFadeOut);
                }
            }
            if (UI_GetInputMode()==0) pressed=1; else pressed=TOWNMAP_CursorIsPressed(&work->cursor);
            if (pressed != 0) {
                hovered=TOWNMAP_MapFindTownUnderCursor(&work->map, &work->cursor);
                if (hovered!=work->hoverTown && hovered!=0) {
                    TownMapPoint scrollNow;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                    TOWNMAP_DrawSelection(&work->selection, hovered); TOWNMAP_MapHighlightTown(&work->map,hovered);
                    work->hoverTown=hovered; TOWNMAP_MapGetScroll(&work->map,&scrollNow);
                    TOWNMAP_CursorSetHoverTown(&work->cursor,hovered,&scrollNow);
                    if (work->zooming==0) TOWNMAP_GRH_SetLabelTown(&work->label,hovered);
                } else if (hovered==0 && work->hoverTown!=0) {
                    TOWNMAP_ClearSelection(&work->selection); TOWNMAP_GRH_SetLabelVisible(&work->label,0); TOWNMAP_MapClearHighlight(&work->map);
                    TOWNMAP_CursorSetHoverTown(&work->cursor,0,0); work->hoverTown=0;
                }
            }
        }
        if (work->zooming!=0) TOWNMAP_GRH_SetLabelVisible(&work->label,0);
        TOWNMAP_CursorSetSnapToTown(&work->cursor,moved ? 0 : 1);
    }
    TOWNMAP_BackButtonUpdate(&work->buttonBar,&work->scroll);
    if (TOWNMAP_IsScrollZooming(&work->scroll)==0) TOWNMAP_CursorUpdate(&work->cursor,&work->map);
    TOWNMAP_MapUpdate(&work->map); TOWNMAP_StepScrollZoom(&work->scroll,&work->map);
    TOWNMAP_GRH_UpdateLabel(&work->label); TOWNMAP_GRH_UpdateTouch(&work->touch);
    switch (TOWNMAP_BackButtonGetPressed(&work->buttonBar)) {
    case 0:
        work->args->result=1; TOWNMAP_ProcSetStep(proc,TOWNMAP_StepFadeOut); break;
    case 1:
        work->args->result=0; TOWNMAP_ProcSetStep(proc,TOWNMAP_StepFadeOut); break;
    case 7:
        if (work->zooming==0 && TOWNMAP_IsScrollZooming(&work->scroll)==0) {
            TownMapPoint cursorPos;
            TOWNMAP_CursorGetPos(&work->cursor,&cursorPos);
            TOWNMAP_StartScrollZoom(&work->scroll,8192,&d_021BBB78,&cursorPos);
            GFL_USE_PlaySeDefaultVolume(0x648);
            if (work->hoverTown!=0) {
                TOWNMAP_ClearSelection(&work->selection); TOWNMAP_GRH_SetLabelVisible(&work->label,0); TOWNMAP_MapClearHighlight(&work->map);
                TOWNMAP_CursorSetHoverTown(&work->cursor,0,0); work->hoverTown=0;
            }
            work->zooming=1;
        } else if (work->zooming==1 && TOWNMAP_IsScrollZooming(&work->scroll)==0) {
            TownMapPoint zoomCenter;
            TOWNMAP_GetScrollPosition(&work->scroll,&zoomCenter); zoomCenter.x+=128; zoomCenter.y+=96;
            TOWNMAP_StartScrollZoom(&work->scroll,4096,&zoomCenter,&d_021BBB78);
            GFL_USE_PlaySeDefaultVolume(0x649);
            if (work->hoverTown!=0) {
                TOWNMAP_ClearSelection(&work->selection); TOWNMAP_GRH_SetLabelVisible(&work->label,0); TOWNMAP_MapClearHighlight(&work->map);
                TOWNMAP_CursorSetHoverTown(&work->cursor,0,0); work->hoverTown=0;
            }
            work->zooming=0;
        }
        break;
    }
    TOWNMAP_IsScrollZoomDone(&work->scroll);
}

void TOWNMAP_BackButtonInit(TownMapButtonBar *bar, u32 unusedMode, struct Unit *clactSet, u8 bgLayer, u8 palette, u8 tileBase, u32 ctx, u16 heapId)
{
    TouchBarParams req;
    ButtonTable table;
    SpriteInit init;
    void *archive;

    MI_CpuFill8(bar, 0, sizeof(TownMapButtonBar));
    bar->ctx = ctx;
    archive = ARC_TOOL_CreateHandle(0x55, heapId);
    bar->charRes = CLACT_RegisterPaletteEx(archive, 2, 0, 0, 0, 4, heapId);
    bar->plttRes = (s32)CLACT_RegisterCharacter(archive, 8, 0, 0, (u32)heapId);
    bar->cellRes = CLACT_RegisterCellAnim(archive, 0xc, 0x13, heapId);
    ARC_TOOL_DeleteHandle(archive);
    MI_CpuFill8(&init, 0, 8);
    init.x = 0xa8;
    init.y = 0xa8;
    init.animSeq = 7;
    bar->sprite = CLACT_CreateActor((struct Unit *)clactSet, bar->plttRes, bar->charRes, bar->cellRes, (const struct ActorInitParam *)&init, 0, heapId);
    CLACT_SetActorAutoAnim((struct ClactActor *)bar->sprite, 1);
    CLACT_StopActorAnim((struct ClactActor *)bar->sprite);
    table = d_021BBB8C;
    MI_CpuFill8(&req, 0, sizeof(req));
    req.defs = (TouchBarButtonDef *)&table;
    req.count = 2;
    req.actorSys = (struct Unit *)clactSet;
    req.bgLayer = bgLayer;
    req.bgPlttSlot = palette;
    req.actorPlttSlot = tileBase + 4;
    req.iconSet = 2;
    bar->buttonMan = TOUCHBAR_Create(&req, heapId);
    TOUCHBAR_SetAllButtonsPriority(bar->buttonMan, 10);
}

void TOWNMAP_BackButtonFree(TownMapButtonBar *bar)
{
    TOUCHBAR_Delete(bar->buttonMan);
    CLACT_DeleteActor((struct ClactActor *)bar->sprite);
    CLACT_ReleaseCellAnim(bar->cellRes);
    CLACT_ReleaseCharacter(bar->plttRes);
    CLACT_ReleasePalette(bar->charRes);
    MI_CpuFill8(bar, 0, sizeof(TownMapButtonBar));
}

/*
 * EXACT*: the unlabelled follower at 0x021BA028 (push {r4,lr}; getter
 * over TOUCHBAR_GetPressedButtonIdIfDone) is outside the handed 216-byte extent.
 * Lever: each sprite-animation pick written as if/else of two calls
 * (tail-merged, h load hoisted over the bne), and CLACT_SetActorAnimSeq's second
 * parameter int here (no truncation before the blx).
 */
void TOWNMAP_BackButtonUpdate(TownMapButtonBar *bar, void *scroll)
{
    u32 touchX;
    u32 touchY;
    TownmapScreenPos spritePos;
    int hit;

    TOUCHBAR_Update(bar->buttonMan);
    bar->pressed = -1;
    switch (bar->animState) {
    case 0:
        hit = 0;
        CLACT_GetActorSurfacePos((struct ClactActor *)bar->sprite, (struct ClactVec2 *)&spritePos, 0);
        if (TOUCHPANEL_GetPointTrg(&touchX, &touchY)) {
            if (touchX - spritePos.x <= 0x18 && touchY - spritePos.y <= 0x18) {
                hit = 1;
                UI_SetInputMode(1);
            }
        } else if (KEY_GetTrg() & 4) {
            UI_SetInputMode(hit);
            hit = 1;
        }
        if (hit && CLACT_IsActorAnimActive((void *)bar->sprite) == 0 && TOWNMAP_IsScrollZooming(scroll) == 0) {
            if (CLACT_GetActorAnimSeq((void *)bar->sprite) == 7)
                CLACT_SetActorAnimSeq((void *)bar->sprite, 9);
            else
                CLACT_SetActorAnimSeq((void *)bar->sprite, 10);
            CLACT_StartActorAnim((void *)bar->sprite);
            bar->pressed = 7;
            bar->animState = 1;
        }
        break;
    case 1:
        if (CLACT_IsActorAnimActive((void *)bar->sprite) == 0) {
            if (CLACT_GetActorAnimSeq((void *)bar->sprite) == 9)
                CLACT_SetActorAnimSeq((void *)bar->sprite, 8);
            else
                CLACT_SetActorAnimSeq((void *)bar->sprite, 7);
            bar->animState = 0;
        }
        break;
    }
}

int TOWNMAP_BackButtonGetPressed(TownMapButtonBar *bar) {
    int pressed;
    pressed = TOUCHBAR_GetPressedButtonIdIfDone(bar->buttonMan);
    if (pressed == -1) pressed = bar->pressed;
    return pressed;
}

int TOWNMAP_BackButtonIsHeld(TownMapButtonBar *bar)
{
    return TOUCHBAR_IsBusy(bar->buttonMan);
}

void TOWNMAP_CursorInit(TownMapCursor *cursor, void *arrowSprite, void *hoverSprite, int heapId)
{
    int zero = 0;
    int one;

    MI_CpuFill8(cursor, 0, sizeof(TownMapCursor));
    cursor->arrowSprite = arrowSprite;
    cursor->hoverSprite = hoverSprite;
    cursor->x = 0x80;
    cursor->y = 0x60;
    CLACT_AddActorSurfacePos((struct ClactActor *)arrowSprite, (const struct ClactVec2 *)((const struct Vec2 *)(&cursor->x)), 0);
    CLACT_AddActorSurfacePos((struct ClactActor *)cursor->hoverSprite, (const struct ClactVec2 *)((const struct Vec2 *)(&cursor->x)), 0);
    CLACT_SetActorDrawEnable(cursor->arrowSprite, 1);
    one = 1;
    CLACT_SetActorDrawEnable((struct ClactActor *)cursor->hoverSprite, 0);
    CLACT_SetActorBgPriority((struct ClactActor *)cursor->arrowSprite, 0);
    CLACT_SetActorDrawPriority((struct ClactActor *)cursor->arrowSprite, 0);
    CLACT_SetActorBgPriority((struct ClactActor *)cursor->hoverSprite, 2);
    CLACT_SetActorDrawPriority(cursor->hoverSprite, 3);
    CLACT_SetActorAutoAnim(cursor->hoverSprite, 1);
    if (UI_GetInputMode() == 0) {
        CLACT_SetActorDrawEnable(cursor->arrowSprite, one);
    } else {
        CLACT_SetActorDrawEnable(cursor->arrowSprite, zero);
    }
}

void TOWNMAP_CursorClear(TownMapCursor *cursor)
{
    MI_CpuFill8(cursor, 0, sizeof(TownMapCursor));
}

void TOWNMAP_CursorUpdate(TownMapCursor *cursor, TownMapMap *map)
{
    struct TownmapVec3 keyDir = { 0, 0, 0 };
    struct TownmapVec3 pull = { 0, 0, 0 };
    struct TownmapVec3 townPos;
    struct TownmapVec3 cursorPos;
    TownMapPoint scroll;
    u32 touchX;
    u32 touchY;
    int moved;
    TownMapTown *town;
    int stepX;
    int stepY;
    s16 clamped;

    moved = 0;
    cursor->pressed = 0;
    if (KEY_GetCont() & 0x40) {
        UI_SetInputMode(0);
        keyDir.y -= 0x1000;
        moved = 1;
    }
    if (KEY_GetCont() & 0x80) {
        UI_SetInputMode(0);
        keyDir.y += 0x1000;
        moved = 1;
    }
    if (KEY_GetCont() & 0x20) {
        UI_SetInputMode(0);
        keyDir.x -= 0x1000;
        moved = 1;
    }
    if (KEY_GetCont() & 0x10) {
        UI_SetInputMode(0);
        keyDir.x += 0x1000;
        moved = 1;
    }
    if (cursor->snapToTown != 0 && UI_GetInputMode() == 0 && (town = TOWNMAP_MapFindNearestTown(map, cursor)) != 0) {
        TOWNMAP_MapGetScroll(map, &scroll);
        townPos.x = FX_F32_TO_FX32(scroll.x + TOWNMAP_TownGetField(town, 4));
        townPos.y = FX_F32_TO_FX32(scroll.y + TOWNMAP_TownGetField(town, 5));
        townPos.z = 0;
        cursorPos.x = FX_F32_TO_FX32(cursor->x);
        cursorPos.y = FX_F32_TO_FX32(cursor->y);
        cursorPos.z = 0;
        VEC_Subtract((const VecFx32 *)&townPos, (const VecFx32 *)&cursorPos, (VecFx32 *)&pull);
        if (VEC_Mag((const VecFx32 *)&pull) > 0x1000) {
            VEC_Normalize((const VecFx32 *)&pull, (VecFx32 *)&pull);
            BUTTON_MAN_ScaleVec((const VecFx32 *)&pull, 0x1000, (VecFx32 *)&pull);
        }
        moved = 1;
    }
    if (moved) {
        VEC_Normalize((const VecFx32 *)&keyDir, (VecFx32 *)&keyDir);
        stepX = pull.x + keyDir.x * 3;
        stepY = pull.y + keyDir.y * 3;
        if (stepX > 0 && stepX < 0x1000)
            stepX = 0x1000;
        else if (stepX > -0x1000 && stepX < 0)
            stepX = -0x1000;
        if (stepY > 0 && stepY < 0x1000)
            stepY = 0x1000;
        else if (stepY > -0x1000 && stepY < 0)
            stepY = -0x1000;
        cursor->x += (s16)(stepX >> 12);
        cursor->y += (s16)(stepY >> 12);
        clamped = cursor->x;
        if (clamped > 0xf8)
            clamped = 0xf8;
        else if (clamped < 0)
            clamped = 0;
        cursor->x = clamped;
        clamped = cursor->y;
        if (clamped > 0xa8)
            clamped = 0xa8;
        else if (clamped < 8)
            clamped = 8;
        cursor->y = clamped;
        CLACT_AddActorSurfacePos((struct ClactActor *)cursor->arrowSprite, (const struct ClactVec2 *)((const struct Vec2 *)(&cursor->x)), 0);
    }
    if (KEY_GetTrg() & 1) {
        UI_SetInputMode(0);
        cursor->pressed = 1;
    }
    if (TOUCHPANEL_GetPointTrg(&touchX, &touchY)) {
        UI_SetInputMode(1);
        if (touchX <= 0xf8 && touchY - 8 <= 0xa0) {
            cursor->pressed = 1;
            cursor->x = touchX;
            cursor->y = touchY;
        }
    }
    if (UI_GetInputMode() == 0)
        CLACT_SetActorDrawEnable((struct ClactActor *)cursor->arrowSprite, 1);
    else
        CLACT_SetActorDrawEnable((struct ClactActor *)cursor->arrowSprite, 0);
}

void TOWNMAP_CursorGetPos(TownMapCursor *cursor, TownMapPoint *pos) {
    pos->x = cursor->x;
    pos->y = cursor->y;
}

void TOWNMAP_CursorSetPos(TownMapCursor *cursor, const TownMapPoint *pos) {
    cursor->x = pos->x;
    cursor->y = pos->y;
    CLACT_AddActorSurfacePos((struct ClactActor *)cursor->arrowSprite, (const struct ClactVec2 *)&cursor->x, 0);
}

int TOWNMAP_CursorIsPressed(TownMapCursor *cursor)
{
    return cursor->pressed;
}

int TOWNMAP_CursorGetHeldKeys(TownMapCursor *cursor)
{
    return KEY_GetCont();
}

void TOWNMAP_CursorSetHoverTown(TownMapCursor *cursor, TownMapTown *town, const TownMapPoint *scroll)
{
    TownmapScreenPos pos;

    if (town == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)cursor->hoverSprite, 0);
        cursor->hoverTown = 0;
        return;
    }
    if (cursor->hoverTown != town) {
        pos.x = scroll->x + TOWNMAP_TownGetField(town, 4);
        pos.y = scroll->y + TOWNMAP_TownGetField(town, 5);
        CLACT_AddActorSurfacePos((struct ClactActor *)cursor->hoverSprite, (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 0);
        CLACT_SetActorDrawEnable((struct ClactActor *)cursor->hoverSprite, 1);
        CLACT_RestartActorAnim((struct ClactActor *)cursor->hoverSprite);
        cursor->hoverTown = town;
    }
}

void TOWNMAP_CursorMoveHoverSprite(TownMapCursor *cursor, const TownMapPoint *scroll)
{
    TownmapScreenPos pos;

    if (cursor->hoverTown) {
        pos.x = scroll->x + TOWNMAP_TownGetField(cursor->hoverTown, 4);
        pos.y = scroll->y + TOWNMAP_TownGetField(cursor->hoverTown, 5);
        CLACT_AddActorSurfacePos((struct ClactActor *)cursor->hoverSprite, (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 0);
    }
}

TownMapTown *TOWNMAP_CursorGetHoverTown(TownMapCursor *cursor)
{
    return cursor->hoverTown;
}

void TOWNMAP_CursorSetSnapToTown(TownMapCursor *cursor, int snapToTown)
{
    cursor->snapToTown = snapToTown;
}

void TOWNMAP_MapInit(TownMapMap *map, u16 townId, u16 townSubId, struct TownMapInfoRow *mapInfo, TownMapGfx *gfx, struct GameData *gameData, u16 heapId, int pickMode)
{
    u32 i;
    struct Unit *clactSet;
    int markerBank0, markerBank1, markerBank2;
    int linkBank0, linkBank1, linkBank2;
    TownMapTown *startTown;

    i = 0;
    clactSet = TOWNMAP_GRH_GetHandle(gfx, 0);
    MI_CpuFill8(map, 0, sizeof(TownMapMap));
    map->townCount = 0x3d;
    map->gameData = (void *)gameData;
    map->towns = GFL_HEAP_Alloc(heapId, map->townCount * sizeof(*map->towns), 0, d_021BBD60, 0x8C5);
    MI_CpuFill8(map->towns, 0, map->townCount * sizeof(*map->towns));
    TOWNMAP_GRH_GetResourceIds(gfx, &markerBank0, &markerBank1, &markerBank2);
    for (; i < map->townCount; i++) {
        TOWNMAP_TownInit(&map->towns[i], mapInfo, i, clactSet, markerBank0, markerBank1, markerBank2, (void *)gameData, heapId, pickMode);
    }
    startTown = TOWNMAP_MapFindTownById(map, townId, townSubId);
    TOWNMAP_GRH_GetResourceIds(gfx, &linkBank0, &linkBank1, &linkBank2);
    TOWNMAP_MarkerInit(&map->marker, startTown, clactSet, linkBank0, linkBank1, linkBank2, heapId);
    map->minScrollY = 0;
    map->minScrollX = 0;
    map->maxScrollX = 0;
    map->maxScrollY = 0;
    TOWNMAP_MapClearHighlight(map);
}

void TOWNMAP_MapFree(TownMapMap *map)
{
    u32 i;

    TOWNMAP_DeleteMarker(&map->marker);
    for (i = 0; i < map->townCount; i++)
        TOWNMAP_TownFree(&map->towns[i]);
    GFL_HEAP_Free(map->towns);
    MI_CpuFill8(map, 0, sizeof(TownMapMap));
}

/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void TOWNMAP_MapUpdate(TownMapMap *map)
{
}

void TOWNMAP_MapSetZoom(TownMapMap *map, u32 scale, const TownMapPoint *center)
{
    u32 i;
    TownMapPoint negated;

    if (scale == 0x1000) {
        map->minScrollY = 0;
        map->minScrollX = 0;
        map->maxScrollX = 0;
        map->maxScrollY = 0;
    } else {
        map->minScrollY = -0x48;
        map->minScrollX = -0x80;
        map->maxScrollX = 0x80;
        map->maxScrollY = 0x60;
    }
    negated.x = -center->x;
    negated.y = -center->y;
    TOWNMAP_MapSetScroll(map, &negated);
    for (i = 0; i < map->townCount; i++) {
        TOWNMAP_TownSetScale(&map->towns[i], scale, &d_021BBB78);
        TOWNMAP_TownSetScroll(&map->towns[i], (TownMapPoint *)&map->scrollX);
    }
    TOWNMAP_UpdateMarkerPosition(&map->marker, (const TownMapPoint *)&map->scrollX);
}

void TOWNMAP_MapSetScroll(TownMapMap *map, const TownMapPoint *scroll)
{
    u32 i;
    int x;
    int y;

    x = map->maxScrollX;
    if (scroll->x <= x) {
        x = map->minScrollX;
        if (scroll->x >= x) {
            x = scroll->x;
        }
    }
    map->scrollX = x;
    y = map->maxScrollY;
    if (scroll->y <= y) {
        y = map->minScrollY;
        if (scroll->y >= y) {
            y = scroll->y;
        }
    }
    map->scrollY = y;
    for (i = 0; i < map->townCount; i++) {
        TOWNMAP_TownSetScroll(&map->towns[i], (TownMapPoint *)&map->scrollX);
    }
    TOWNMAP_UpdateMarkerPosition(&map->marker, (const TownMapPoint *)&map->scrollX);
}

/*
 * note:     listing extent (12) runs 2 bytes past the compiled function (10);
 *           trailing alignment padding, no byte difference.  A two-word copy
 *           at a nonzero offset is a struct assignment (hoists both loads and
 *           allocates r2/r0); two locals let the stores reorder and diff.
 */
void TOWNMAP_MapGetScroll(TownMapMap *map, TownMapPoint *scroll)
{
    *scroll = *(TownMapPoint *)&map->scrollX;
}

void TOWNMAP_MapAddScroll(TownMapMap *map, const TownMapPoint *delta)
{
    map->scrollX = delta->x + map->scrollX;
    map->scrollY = map->scrollY + delta->y;
    TOWNMAP_MapSetScroll(map, (TownMapPoint *)&map->scrollX);
}

TownMapTown *TOWNMAP_MapFindTownUnderCursor(TownMapMap *map, TownMapCursor *cursor)
{
    TownMapPoint pos;
    u32 i;

    TOWNMAP_CursorGetPos(cursor, &pos);
    for (i = 0; i < map->townCount; i++) {
        if (TOWNMAP_TownHitTest(&map->towns[i], &pos, (TownMapPoint *)&map->scrollX) != 0) {
            return &map->towns[i];
        }
    }
    return 0;
}

TownMapTown *TOWNMAP_MapFindNearestTown(TownMapMap *map, TownMapCursor *cursor)
{
    TownMapPoint pos;
    u32 i;
    u32 bestDist;
    u32 dist;
    int bestIndex;

    TOWNMAP_CursorGetPos(cursor, &pos);
    bestIndex = -1;
    bestDist = -1;
    for (i = 0; i < map->townCount; i++) {
        if (TOWNMAP_TownTestNear(&map->towns[i], &pos, (TownMapPoint *)&map->scrollX, &dist) != 0 && bestDist > dist) {
            bestIndex = i;
            bestDist = dist;
        }
    }
    if (bestIndex == -1) {
        return 0;
    }
    return &map->towns[bestIndex];
}

/*
 * call width: r1 is explicitly narrowed before the call, so extern takes u16.
 */
int TOWNMAP_TownGetField(TownMapTown *town, int field) {
 if (field>=2 && field<=10) return town->values[field-2];
 if (field==12) return town->selectable;
 return TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)town->info,(u16)(town->index),field);
}

void TOWNMAP_MapHighlightTown(TownMapMap *map, TownMapTown *selected)
{
    u32 i;
    TownMapTown *town;

    for (i = 0; i < map->townCount; i++) {
        town = &map->towns[i];
        if (town == selected)
            TOWNMAP_TownHighlight(town);
        else
            TOWNMAP_TownUnhighlight(town);
    }
}

void TOWNMAP_MapClearHighlight(TownMapMap *map)
{
    u32 i;

    for (i = 0; i < map->townCount; i++)
        TOWNMAP_TownUnhighlight(&map->towns[i]);
}

TownMapTown *TOWNMAP_MapFindTownById(TownMapMap *map, u32 townId, int townSubId)
{
    u32 i;
    u32 zoneId;
    TownMapTown *town;

    zoneId = SYMBOL_MAP_ResolveZoneId(map->gameData, townId);
    for (i = 0; i < map->townCount; i++) {
        town = &map->towns[i];
        if (zoneId == TOWNMAP_TownGetField(town, 0))
            return town;
    }
    return 0;
}

int TOWNMAP_TownIsRevealed(TownMapTown *town)
{
    int flag;

    flag = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)town->info, (u16)(town->index), 15);
    if ((flag != 65535 && town->visited != 0 && town->locked == 0) || flag == 65535)
        return 1;
    return 0;
}

void TOWNMAP_TownInit(TownMapTown *town, struct TownMapInfoRow *mapInfo, int townIndex, struct Unit *clactSet, int plttRes, int cellRes, int charRes, void *gameData, u16 heapId, int pickMode)
{
    SpriteInit init;
    u32 flag;
    int i;

    MI_CpuFill8(town, 0, sizeof(TownMapTown));
    town->scale = 0x1000;
    town->info = (char *)mapInfo;
    town->index = townIndex;
    flag = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)mapInfo, (u16)townIndex, 15);
    if (flag != 0xFFFF)
        town->visited = SYMBOL_MAP_CheckEventFlag(gameData, flag);
    else
        town->visited = 0;
    if (pickMode)
        town->visited = 1;
    for (i = 0; i < 9; i++)
        town->values[i] = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)town->info, (u16)town->index, i + 2);
    if (pickMode)
        town->selectable = 1;
    else
        town->selectable = town->visited && TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)town->info, (u16)town->index, 12);
    flag = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)town->info, (u16)town->index, 16);
    if (flag != 0xFFFF)
        town->locked = SYMBOL_MAP_CheckEventFlag(gameData, flag) == 0;
    else
        town->locked = 0;
    if (pickMode)
        town->locked = 0;
    switch (TOWNMAP_TownGetField(town, 11)) {
    case 0:
        town->frameNormal = 2;
        town->frameHighlight = 1;
        break;
    case 2:
        town->frameNormal = 3;
        town->frameHighlight = 0xff;
        break;
    case 1:
        town->frameNormal = 0xff;
        town->frameHighlight = 0xff;
        break;
    case 3:
        town->frameNormal = 3;
        town->frameHighlight = 0xd;
        break;
    case 4:
        town->frameNormal = 0xf;
        town->frameHighlight = 0xe;
        break;
    case 5:
        town->frameNormal = 0x12;
        if (town->visited)
            town->frameHighlight = 0x11;
        else
            town->frameHighlight = 0x10;
        break;
    }
    if (TOWNMAP_TownGetField(town, 11) != 1) {
        MI_CpuFill8(&init, 0, 8);
        init.x = TOWNMAP_TownGetField(town, 2);
        init.y = TOWNMAP_TownGetField(town, 3);
        town->sprite = CLACT_CreateActor((struct Unit *)clactSet, plttRes, charRes, cellRes, (const struct ActorInitParam *)&init, 0, heapId);
        CLACT_SetActorAffineMode((struct ClactActor *)town->sprite, 2);
        CLACT_SetActorBgPriority((struct ClactActor *)town->sprite, 2);
        CLACT_SetActorDrawPriority((struct ClactActor *)town->sprite, 4);
    }
    TOWNMAP_TownUnhighlight(town);
}

void TOWNMAP_TownFree(TownMapTown *town)
{
    if (town->sprite)
        CLACT_DeleteActor((struct ClactActor *)town->sprite);
    MI_CpuFill8(town, 0, sizeof(TownMapTown));
}

void TOWNMAP_TownSetShown(TownMapTown *town, int shown)
{
    if (town->sprite == 0 || town->frameShown == 0xff) {
        return;
    }
    if (town->locked != 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)town->sprite, 0);
        return;
    }
    if (TOWNMAP_TownGetField(town, 11) == 4 || TOWNMAP_TownGetField(town, 11) == 5) {
        TOWNMAP_TownSetFrame(town, town->frameHighlight);
        CLACT_SetActorDrawEnable((struct ClactActor *)town->sprite, 1);
    } else {
        CLACT_SetActorDrawEnable((struct ClactActor *)town->sprite, shown);
    }
}

u32 TOWNMAP_TownHitTest(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll)
{
    ButtonSphere ball;
    ButtonSegment seg;
    VecFx32 segStart;
    VecFx32 segEnd;

    segStart.x = FX_F32_TO_FX32(pos->x);
    segStart.y = FX_F32_TO_FX32(pos->y);
    segStart.z = 0;
    BUTTON_MAN_InitSphere(&ball, &segStart, 0);
    segStart.x = FX_F32_TO_FX32(scroll->x + TOWNMAP_TownGetField(town, 6));
    segStart.y = FX_F32_TO_FX32(scroll->y + TOWNMAP_TownGetField(town, 7));
    segStart.z = 0;
    segEnd.x = FX_F32_TO_FX32(scroll->x + TOWNMAP_TownGetField(town, 8));
    segEnd.y = FX_F32_TO_FX32(scroll->y + TOWNMAP_TownGetField(town, 9));
    segEnd.z = 0;
    BUTTON_MAN_InitSegment(&seg, &segStart, &segEnd, FX_F32_TO_FX32(TOWNMAP_TownGetField(town, 10)));
    if (town->locked != 0)
        return 0;
    return BUTTON_MAN_SegmentSphereTest(&seg, &ball, 0);
}

int TOWNMAP_TownTestNear(TownMapTown *town, const TownMapPoint *pos, const TownMapPoint *scroll, u32 *distSq)
{
    int x;
    int y;
    int dx;
    int dy;
    int scale;
    int limit;

    x = scroll->x + TOWNMAP_TownGetField(town, 4);
    y = scroll->y + TOWNMAP_TownGetField(town, 5);
    dx = x - pos->x;
    dx = dx * dx;
    dy = y - pos->y;
    dy = dy * dy;
    if (town->locked != 0) {
        return 0;
    }
    scale = town->scale;
    if (scale < 0) {
        scale = -scale;
    }
    limit = (scale * 0x90) >> 12;
    if ((u32)(dx + dy) < limit) {
        if (distSq != 0) {
            *distSq = dx + dy;
        }
        return 1;
    }
    return 0;
}

void TOWNMAP_TownSetScale(TownMapTown *town, int scale, const TownMapPoint *center)
{
    int i;
    int base;
    int d;
    int scaleXY[2];

    for (i = 0; i < 8; i++) {
        if (i % 2 == 0) {
            base = center->x;
        } else {
            base = center->y;
        }
        d = TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)town->info, (u16)town->index, i + 2) - base;
        d = d * scale >> 12;
        town->values[i] = d + base;
    }
    town->values[8] = scale * TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)town->info, (u16)town->index, 10) >> 12;
    town->scale = scale;
    if (town->sprite != 0) {
        scaleXY[0] = scale;
        scaleXY[1] = scale;
        CLACT_SetActorScale((struct ClactActor *)town->sprite, (struct Pair32 *)scaleXY);
    }
}

void TOWNMAP_TownSetScroll(TownMapTown *town, const TownMapPoint *scroll)
{
    TownmapScreenPos pos;

    pos.x = scroll->x + TOWNMAP_TownGetField(town, 2);
    pos.y = scroll->y + TOWNMAP_TownGetField(town, 3);
    if (town->sprite)
        CLACT_AddActorSurfacePos((struct ClactActor *)town->sprite, (const struct ClactVec2 *)((const struct Vec2 *)(&pos)), 0);
}

void TOWNMAP_TownSetFrame(TownMapTown *town, int frame)
{
    town->frameShown = frame;
    if (town->frameShown != 255) {
        if (town->sprite) {
            CLACT_SetActorDrawEnable((struct ClactActor *)town->sprite, 1);
            CLACT_SetActorAnimSeq((struct ClactActor *)((struct Actor *)(town->sprite)), town->frameShown);
        }
    } else {
        if (town->sprite)
            CLACT_SetActorDrawEnable((struct ClactActor *)town->sprite, 0);
    }
}

void TOWNMAP_TownHighlight(TownMapTown *town)
{
    int special;

    special = 0;
    if (TOWNMAP_TownGetField(town, 11) == 4 || TOWNMAP_TownGetField(town, 11) == 5) {
        special = 1;
        if (town->locked != 0) {
            special = 0;
        }
    }
    if (town->visited != 0 || special != 0) {
        TOWNMAP_TownSetShown(town, 1);
        TOWNMAP_TownSetFrame(town, town->frameNormal);
    } else {
        TOWNMAP_TownSetShown(town, 0);
    }
}

void TOWNMAP_TownUnhighlight(TownMapTown *town)
{
    int special;

    special = 0;
    if (TOWNMAP_TownGetField(town, 11) == 4 || TOWNMAP_TownGetField(town, 11) == 5) {
        special = 1;
        if (town->locked != 0) {
            special = 0;
        }
    }
    if (town->visited != 0 || special != 0) {
        if (town->sprite != 0) {
            TOWNMAP_TownSetShown(town, 1);
            TOWNMAP_TownSetFrame(town, town->frameHighlight);
        }
    } else {
        TOWNMAP_TownSetShown(town, 0);
    }
}

void TOWNMAP_MarkerInit(TownMapMarker *marker, TownMapTown *town, struct Unit *clactSet, int plttRes, int cellRes, int charRes, u16 heapId)
{
    SpriteInit init;

    MI_CpuFill8(marker, 0, sizeof(*marker));
    marker->town = town;
    MI_CpuFill8(&init, 0, 8);
    if (town != 0) {
        init.x = TOWNMAP_TownGetField(town, 2);
        init.y = TOWNMAP_TownGetField(town, 3);
    }
    marker->sprite = CLACT_CreateActor((struct Unit *)clactSet, plttRes, charRes, cellRes, (const struct ActorInitParam *)&init, 0, heapId);
    CLACT_SetActorBgPriority((struct ClactActor *)marker->sprite, 2);
    CLACT_SetActorDrawPriority((struct ClactActor *)marker->sprite, 2);
    CLACT_SetActorAnimSeq((struct ClactActor *)marker->sprite, 6);
    CLACT_SetActorAutoAnim((struct ClactActor *)marker->sprite, 1);
    if (town == 0) {
        CLACT_SetActorDrawEnable((struct ClactActor *)marker->sprite, 0);
    }
}

/* Marker actor of a town. */
void TOWNMAP_DeleteMarker(TownMapMarker *marker)
{
    CLACT_DeleteActor((struct ClactActor *)marker->sprite);
    MI_CpuFill8(marker, 0, sizeof(TownMapMarker));
}

void TOWNMAP_UpdateMarkerPosition(TownMapMarker *marker, const TownMapPoint *scroll)
{
    TownmapScreenPos pos;

    if (marker->town != 0) {
        pos.x = scroll->x + TOWNMAP_TownGetField(marker->town, 2);
        pos.y = scroll->y + TOWNMAP_TownGetField(marker->town, 3);
    }
    CLACT_AddActorSurfacePos((struct ClactActor *)marker->sprite, (const struct ClactVec2 *)&pos, 0);
}

/* Scroll and zoom of the map layers. */
void TOWNMAP_InitScroll(TownMapScroll *scroll, u32 bgIdA, u32 bgIdB, int heapId)
{
    u16 zero = 0;

    MI_CpuFill8(scroll, 0, sizeof(TownMapScroll));
    scroll->bgId[0] = bgIdA;
    scroll->bgId[1] = bgIdB;
    scroll->scale = 0x1000;
    scroll->minY = zero;
    scroll->minX = zero;
    scroll->maxX = zero;
    scroll->maxY = zero;
}

void TOWNMAP_ClearScroll(TownMapScroll *scroll)
{
    MI_CpuFill8(scroll, 0, sizeof(TownMapScroll));
}

void TOWNMAP_StepScrollZoom(TownMapScroll *scroll, TownMapMap *map)
{
    int dy;
    int dx;
    int scaleStep;

    scroll->zoomDone = 0;
    if (scroll->zooming == 0)
        return;
    scaleStep = (scroll->scaleTo - scroll->scaleFrom) / 10;
    scroll->scale = scroll->scaleFrom + scaleStep * scroll->step;
    dy = (scroll->dst.y - scroll->src.y) << 12;
    dx = (scroll->dst.x - scroll->src.x) << 12;
    scroll->pos.x = scroll->src.x + ((dx * scroll->step) / 10 >> 12);
    scroll->pos.y = scroll->src.y + ((dy * scroll->step) / 10 >> 12);
    if (scroll->scaleTo == 0x1000) {
        scroll->minY = -96 - (-96 - 0) / 10 * scroll->step;
        scroll->maxY = 72 - (72 - 0) / 10 * scroll->step;
        scroll->minX = -128 - (-128 - 0) / 10 * scroll->step;
        scroll->maxX = 128 - (128 - 0) / 10 * scroll->step;
    } else {
        scroll->minY = 0 + (-96 - 0) / 10 * scroll->step;
        scroll->maxY = 0 + (72 - 0) / 10 * scroll->step;
        scroll->minX = 0 + (-128 - 0) / 10 * scroll->step;
        scroll->maxX = 0 + (128 - 0) / 10 * scroll->step;
    }
    if (scroll->step++ >= 10) {
        scroll->step = 0;
        scroll->zooming = 0;
        scroll->scale = scroll->scaleTo;
        scroll->pos = scroll->dst;
        if (scroll->scaleTo == 0x1000) {
            scroll->minY = 0;
            scroll->minX = 0;
            scroll->maxX = 0;
            scroll->maxY = 0;
        } else {
            scroll->minY = -0x60;
            scroll->minX = -0x80;
            scroll->maxX = 0x80;
            scroll->maxY = 0x48;
        }
        scroll->zoomDone = 1;
    }
    TOWNMAP_MapSetZoom(map, scroll->scale, &scroll->pos);
    TOWNMAP_ApplyScroll(scroll, &scroll->pos);
}

/* stand-in: an enum typed local keeps the flag in a register across the load of from->x, as the original does. */
typedef enum { ZOOM_OFF, ZOOM_ON } ZoomFlag;

void TOWNMAP_StartScrollZoom(TownMapScroll *scroll, int scaleTo, const TownMapPoint *from, const TownMapPoint *to)
{
    int x;
    ZoomFlag one;

    scroll->scaleTo = scaleTo;
    scroll->scaleFrom = scroll->scale;
    one = ZOOM_ON;
    x = from->x;
    scroll->zooming = one;
    scroll->src.x = x - 0x80;
    scroll->src.y = from->y - 0x60;
    scroll->dst.x = to->x - 0x80;
    scroll->dst.y = to->y - 0x60;
}

int TOWNMAP_IsScrollZoomDone(TownMapScroll *scroll)
{
    return scroll->zoomDone;
}

int TOWNMAP_IsScrollZooming(TownMapScroll *scroll)
{
    return scroll->zooming;
}

void TOWNMAP_ApplyScroll(TownMapScroll *scroll, const TownMapPoint *pos)
{
    scroll->pos.x = (pos->x > scroll->maxX) ? scroll->maxX : ((pos->x < scroll->minX) ? scroll->minX : pos->x);
    scroll->pos.y = (pos->y > scroll->maxY) ? scroll->maxY : ((pos->y < scroll->minY) ? scroll->minY : pos->y);

    BG_SYS_ChangeScroll(scroll->bgId[0], 0, scroll->pos.x);
    BG_SYS_ChangeScroll(scroll->bgId[0], 3, scroll->pos.y);
    BG_SYS_ChangeCenter(scroll->bgId[0], 9, 0x80);
    BG_SYS_ChangeCenter(scroll->bgId[0], 12, 0x60);
    BG_SYS_ChangeScale(scroll->bgId[0], 3, scroll->scale);
    BG_SYS_ChangeScale(scroll->bgId[0], 6, scroll->scale);
    BG_SYS_ChangeScroll(scroll->bgId[1], 0, scroll->pos.x);
    BG_SYS_ChangeScroll(scroll->bgId[1], 3, scroll->pos.y);
    BG_SYS_ChangeCenter(scroll->bgId[1], 9, 0x80);
    BG_SYS_ChangeCenter(scroll->bgId[1], 12, 0x60);
    BG_SYS_ChangeScale(scroll->bgId[1], 3, scroll->scale);
    BG_SYS_ChangeScale(scroll->bgId[1], 6, scroll->scale);
}

void TOWNMAP_GetScrollPosition(TownMapScroll *scroll, TownMapPoint *out)
{
    *out = scroll->pos;
}

void TOWNMAP_MoveScroll(TownMapScroll *scroll, const TownMapPoint *delta)
{
    scroll->pos.x = delta->x + scroll->pos.x;
    scroll->pos.y += delta->y;
    TOWNMAP_ApplyScroll(scroll, &scroll->pos);
}

/* Town description shown on the bottom screen. */
void TOWNMAP_InitSelection(TownMapSelection *sel, int bgId, void *font, struct MsgBank *nameMsg, struct MsgBank *detailMsg, u16 heapId)
{
    MI_CpuFill8(sel, 0, sizeof(TownMapSelection));
    sel->box.font = font;
    sel->detailMsg = detailMsg;
    sel->box.msg = nameMsg;
    sel->box.win = BMP_WIN_Create(bgId, 0, 0, 0x20, 0x18, 0xe, 0);
    sel->box.text = (struct Strbuf *)STRBUF_Create(0xff, heapId);
}

void TOWNMAP_ExitSelection(TownMapSelection *sel)
{
    STRBUF_Delete((struct Strbuf *)sel->box.text);
    BMP_WIN_Delete(sel->box.win);
    MI_CpuFill8(sel, 0, sizeof(TownMapSelection));
}

void TOWNMAP_DrawSelection(TownMapSelection *sel, TownMapTown *town)
{
    struct Bitmap *bitmap;
    struct BmpWin *win;
    s16 centerX;
    s16 halfWidth;
    u16 msgId;

    bitmap = (struct Bitmap *)BMP_WIN_GetBmp(sel->box.win);
    BMP_Clear((struct Bmp *)bitmap, 0);
    if (town != 0) {
        MSGDATA_ReadString(sel->box.msg, ZONEDATA_GetPlaceNameId((u16)TOWNMAP_TownGetField(town, 0)), (struct Strbuf *)sel->box.text);
        centerX = ((u32)BMP_WIN_GetWidth(sel->box.win) << 3) / 2;
        halfWidth = PRINTSYS_MeasureWidestLine((struct Strbuf *)sel->box.text, sel->box.font, 0) >> 1;
        centerX = centerX - halfWidth;
        PRINTSYS_Print((struct Bmp *)bitmap, centerX, 0x30, (struct Strbuf *)sel->box.text, sel->box.font);
        msgId = TOWNMAP_TownGetField(town, 0x11);
        if (msgId != 0xFFFF) {
            MSGDATA_ReadString(sel->detailMsg, msgId, (struct Strbuf *)sel->box.text);
            PRINTSYS_Print((struct Bmp *)bitmap, 0x1c, 0x50, (struct Strbuf *)sel->box.text, sel->box.font);
        }
        if (TOWNMAP_TownIsRevealed(town)) {
            msgId = TOWNMAP_TownGetField(town, 0x12);
            if (msgId != 0xFFFF) {
                MSGDATA_ReadString(sel->detailMsg, msgId, (struct Strbuf *)sel->box.text);
                PRINTSYS_Print((struct Bmp *)bitmap, 0x10, 0x80, (struct Strbuf *)sel->box.text, sel->box.font);
            }
            msgId = TOWNMAP_TownGetField(town, 0x13);
            if (msgId != 0xFFFF) {
                MSGDATA_ReadString(sel->detailMsg, msgId, (struct Strbuf *)sel->box.text);
                PRINTSYS_Print((struct Bmp *)bitmap, 0x10, 0x90, (struct Strbuf *)sel->box.text, sel->box.font);
            }
            msgId = TOWNMAP_TownGetField(town, 0x14);
            if (msgId != 0xFFFF) {
                MSGDATA_ReadString(sel->detailMsg, msgId, (struct Strbuf *)sel->box.text);
                PRINTSYS_Print((struct Bmp *)bitmap, 0x10, 0xa0, (struct Strbuf *)sel->box.text, sel->box.font);
            }
            msgId = TOWNMAP_TownGetField(town, 0x15);
            if (msgId != 0xFFFF) {
                MSGDATA_ReadString(sel->detailMsg, msgId, (struct Strbuf *)sel->box.text);
                PRINTSYS_Print((struct Bmp *)bitmap, 0x88, 0x80, (struct Strbuf *)sel->box.text, sel->box.font);
            }
            msgId = TOWNMAP_TownGetField(town, 0x16);
            if (msgId != 0xFFFF) {
                MSGDATA_ReadString(sel->detailMsg, msgId, (struct Strbuf *)sel->box.text);
                PRINTSYS_Print((struct Bmp *)bitmap, 0x88, 0x90, (struct Strbuf *)sel->box.text, sel->box.font);
            }
            msgId = TOWNMAP_TownGetField(town, 0x17);
            if (msgId != 0xFFFF) {
                MSGDATA_ReadString(sel->detailMsg, msgId, (struct Strbuf *)sel->box.text);
                PRINTSYS_Print((struct Bmp *)bitmap, 0x88, 0xa0, (struct Strbuf *)sel->box.text, sel->box.font);
            }
        }
    }
    win = sel->box.win;
    BMP_WIN_TransferChars(win);
    BMP_WIN_MakeScreen(win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
}

void TOWNMAP_ClearSelection(TownMapSelection *sel)
{
    struct BmpWin *win = sel->box.win;

    BMP_WIN_ClearScreen(win);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(win));
}
