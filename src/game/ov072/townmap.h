#ifndef GAME_OV072_TOWNMAP_H
#define GAME_OV072_TOWNMAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of townmap.c, prototypes copied from their definitions. */

struct MsgBank;

#include "../ov072/townmap_types.h"
#include "../types.h"

int TOWNMAP_Create(void *taskArg, void *unused, TownMapArgs *args);
int TOWNMAP_Destroy(void *taskArg, int unusedA, int unusedB, TownMapWork *work);
int TOWNMAP_Update(int taskArg, int unusedA, int unusedB, TownMapWork *work);
void TOWNMAP_ProcInit(TownMapProc *proc, TownMapWork *work, TownMapStepFunc step);
void TOWNMAP_ProcClear(TownMapProc *proc);
void TOWNMAP_ProcRun(TownMapProc *proc);
int TOWNMAP_ProcIsFinished(TownMapProc *proc);
void TOWNMAP_ProcSetStep(TownMapProc *proc, TownMapStepFunc step);
void TOWNMAP_ProcFinish(TownMapProc *proc);
void TOWNMAP_StepFadeIn(TownMapProc *proc, int *state);
void TOWNMAP_StepFadeOut(TownMapProc *proc, int *state);
int TOWNMAP_StepBrowse(TownMapProc *proc,int *unusedState,TownMapWork *work);
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
/* END mkheaders: generated region */

#endif
