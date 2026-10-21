#ifndef GAME_OV208_ZUKAN_DETAIL_AREA_H
#define GAME_OV208_ZUKAN_DETAIL_AREA_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_area.c, prototypes copied from their definitions. */

struct Ov208Ctx;
struct Ov208AreaState;
struct TcbTask;

#include "../types.h"

void ZUKAN_DETAIL_AREA_SetHeapId(u16 *p, u16 v);
u32 ZUKAN_DETAIL_AREA_Init(void *fsm,u32 seq,u16 *heap,u32 workArg,struct Ov208Ctx *key);
u32 ZUKAN_DETAIL_AREA_Exit(void *fsm, u32 seq, void *heap, char *p, struct Ov208Ctx *key);
int ZUKAN_DETAIL_AREA_Main(void *proc, int *seq, u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_HandleKeyEvent(void *proc, void *seq, void *heap, struct Ov208AreaState *st, struct Ov208Ctx *obj, int key);
void ZUKAN_DETAIL_AREA_ApplyPendingEffect(struct TcbTask *unused, void *p);
void ZUKAN_DETAIL_AREA_BuildTownOrderTable(u16 *unused, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_LoadMapGraphics(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_NoOpLoad(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_CreateMapActors(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_DeleteMapActors(void *unused, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_CreateTownIconActors(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_DeleteTownIconActors(void *unused, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_CreateTownMarkerActors(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(void *heap, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_CreatePrintQueues(unsigned short *heap, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_DeletePrintQueues(void *unused, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_UpdatePrintQueues(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_FlushPrintWindow(u16 *heap, u8 *p, struct Ov208Ctx *key, u8 i);
void ZUKAN_DETAIL_AREA_CreateTextWindows(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_DeleteTextWindows(void *unused, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_LoadSubScreenGraphics(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_ApplySubScreenScroll(void *unused, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_UpdateScroll(int heap, int p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_UpdateScrollFade(int heap, unsigned char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_NoOpUpdate(int heap, int p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_UpdateSelectorAnim(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_LoadMarkerResources(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_ReleaseMarkerResources(void *heap, char *p, struct Ov208Ctx *key);
u32 ZUKAN_DETAIL_AREA_CreatePokemonIcon(u32 *slot, u32 palette, u32 cellAnim, u32 unit, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg, u8 x, u8 y);
void ZUKAN_DETAIL_AREA_DeletePokemonIcon(void *charKey, void *actor);
u8 ZUKAN_DETAIL_AREA_FindPlayerTownIndex(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_MovePlayerMarkerToTown(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_SetPlayerMarkerVisible(u16 *heap, u8 *p, struct Ov208Ctx *key, int on);
u32 ZUKAN_DETAIL_AREA_IsPlayerMarkerVisible(void *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_MoveCursorToSelectedTown(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_SelectPlayerTown(int heap, char *p, struct Ov208Ctx *key);
u8 ZUKAN_DETAIL_AREA_FindTownAtPoint(void *unused,char *p,struct Ov208Ctx *key,u8 x,u8 y);
int ZUKAN_DETAIL_AREA_GetTownPointDistance(void *unused, char *p, struct Ov208Ctx *key, u8 index, u8 x, u8 y, unsigned *out);
u8 ZUKAN_DETAIL_AREA_FindNearestTown(void *heap, char *p, struct Ov208Ctx *key, u8 x, u8 y);
void ZUKAN_DETAIL_AREA_HandleCursorInput(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_HandleTownTouchInput(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_UpdateMode(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_HandleModeEvent(u16 *heap, u8 *p, struct Ov208Ctx *key, int mode);
void ZUKAN_DETAIL_AREA_LoadAreaEntries(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_UpdateFadeAndOverlay(int heap, int p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_RequestModeEvent4(void *heap, int p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_DrawTownName(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_SwitchAreaSet(u16 *heap, u8 *p, struct Ov208Ctx *key, int dir, int touch);
void *ZUKAN_DETAIL_AREA_LoadAreaEntryData(int entryId, int heapId, int arcHandle);
void ZUKAN_DETAIL_AREA_FreeAreaEntryData(int data);
void ZUKAN_DETAIL_AREA_DrawAreaSetTitle(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_BeginModeTransition(void *heap, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_BeginHideOverlay(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_FinishHideOverlay(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_DrawNoDataMessage(void *heap, u8 *st, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_ClearOverlayWindow(void *unused, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_RequestBlendRestore(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_NoOpOverlay(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_UpdateTerrainIcons(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_ResetBlendAlpha(char *p);
void ZUKAN_DETAIL_AREA_ApplyBrightness(char *p);
void ZUKAN_DETAIL_AREA_SetupSplitWindows(char *p);
void ZUKAN_DETAIL_AREA_DisableWindowsAndBrightness(char *p);
void ZUKAN_DETAIL_AREA_UpdateBlendPulse(u8 *p);
void ZUKAN_DETAIL_AREA_InitBlendPulse(u8 *p);
void ZUKAN_DETAIL_AREA_SetMapActorsNormalMode(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_SetMapActorsAlphaMode(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_SetIconsNormalMode(u16 *heap, u8 *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_AREA_SetIconsAlphaMode(u16 *heap, u8 *p, struct Ov208Ctx *key);
/* END mkheaders: generated region */

#endif
