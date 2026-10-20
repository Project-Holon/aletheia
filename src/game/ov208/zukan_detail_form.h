#ifndef GAME_OV208_ZUKAN_DETAIL_FORM_H
#define GAME_OV208_ZUKAN_DETAIL_FORM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_form.c, prototypes copied from their definitions. */

struct Ov208Ctx;
struct Ov208Form;
struct Ov208Mdl;
struct Ov208AnmState;
struct Ov208Turn;
struct Ov208Ent;

#include "../types.h"
#include "../ov208/zukan_detail_form_types.h"

void ZUKAN_DETAIL_FORM_SetHeapId(u16 *p, u32 value);
int ZUKAN_DETAIL_FORM_Init(void *proc, int *seq, u16 *heap, u8 *unused, struct Ov208Ctx *key);
int ZUKAN_DETAIL_FORM_Exit(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
int ZUKAN_DETAIL_FORM_Main(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_HandleKeyEvent(void *proc, int *seq, u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int ev);
void ZUKAN_DETAIL_FORM_DrawModels(u32 unused, u32 unused2, u32 unused3, struct Ov208Form *p);
void ZUKAN_DETAIL_FORM_ApplyPendingDisplay(int unused, char *p);
void ZUKAN_DETAIL_FORM_BuildFormLabelText(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, u32 *outStr, u32 *outB, int *outC, int *outD, u16 idx);
void ZUKAN_DETAIL_FORM_CreateTextWindows(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_DeleteTextWindows(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_CreatePrintQueues(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_DeletePrintQueues(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_UpdatePrintQueues(void *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_FlushPrintWindow(void *heap, struct Ov208Form *p, struct Ov208Ctx *key, int i);
void ZUKAN_DETAIL_FORM_DrawSpeciesLabels(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_DrawFormLabel(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int i, u32 print, u32 win, u32 *active, u16 idx);
void ZUKAN_DETAIL_FORM_DrawFormLabelMain(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_DrawFormLabelSub(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_UpdateBgScrollForState(void *unused, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_InitModelSystem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_ExitModelSystem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
u32 ZUKAN_DETAIL_FORM_AddModel(void *sys, u32 species, u32 form, u32 gender, u32 shiny, u32 isEgg, u32 direction, u32 extra);
void ZUKAN_DETAIL_FORM_DeleteModel(int sys, int obj);
void ZUKAN_DETAIL_FORM_CenterModelOffset(u32 obj);
void ZUKAN_DETAIL_FORM_GetModelPosition(u32 obj, ZukanDetailFormVec *out);
void ZUKAN_DETAIL_FORM_CreateModelItem(struct Ov208Mdl *item, u32 heap, void *sys, u32 species, u32 form, u32 gender, u32 shiny, u32 isEgg, u32 direction, u32 extra);
void ZUKAN_DETAIL_FORM_DestroyModelItem(struct Ov208Mdl *p, int cam);
void ZUKAN_DETAIL_FORM_InitAnimState(struct Ov208AnmState *s, int side, struct Ov208Form *form);
void ZUKAN_DETAIL_FORM_RestartModelAnim(struct Ov208Mdl *s);
void ZUKAN_DETAIL_FORM_SignalAnimDone(int *p);
void ZUKAN_DETAIL_FORM_StopModelAnim(struct Ov208Mdl *p);
void ZUKAN_DETAIL_FORM_OnAnimStopRequest(struct Ov208Turn *t);
void ZUKAN_DETAIL_FORM_ToggleModelVisibility(u16 *heap,struct Ov208Form *p,struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_LoadIconResources(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_ReleaseIconResources(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
u32 ZUKAN_DETAIL_FORM_CreateIconActor(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg);
void ZUKAN_DETAIL_FORM_DeleteIconActor(int charKey, int actor);
void ZUKAN_DETAIL_FORM_BuildFormEntries(u16 *heap, struct Ov208Ctx *key, struct Ov208Ent *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next);
void ZUKAN_DETAIL_FORM_RefreshFormEntries(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_PlaceModelItem(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, int item0Index, int item1Index, int pose, u16 idx);
void ZUKAN_DETAIL_FORM_CreateCurrentIcon(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key, u16 idx);
void ZUKAN_DETAIL_FORM_RebuildModels(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_RebuildModelsSwapped(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_RebuildModelsSingle(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_RebuildSideModels(void *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_SwapIconActor(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_UpdateState(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_HandleStateEvent(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *ctx, int ev);
void ZUKAN_DETAIL_FORM_CreateArrowActors(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_DeleteArrowActors(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);
int ZUKAN_DETAIL_FORM_HandleTouchArrows(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_UpdateArrowVisibility(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_UpdateArrowAnim(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_UpdateCursorMarkers(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2);
void ZUKAN_DETAIL_FORM_UpdateScrollMarkers(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_UpdateScrollInput(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
u32 ZUKAN_DETAIL_FORM_HandleScrollTouch(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
int ZUKAN_DETAIL_FORM_HandleScrollKey(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_GetScrollSlotRange(int slotCount, int slot, u8 *lo, u8 *mid, u8 *hi);
u16 ZUKAN_DETAIL_FORM_GetScrollSlotAtX(u16 slotCount, u8 x);
u16 ZUKAN_DETAIL_FORM_CountEntriesBefore(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2, u16 skip, u16 stop);
u16 ZUKAN_DETAIL_FORM_GetEntryIndex(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2, u16 skip, u16 want);
void ZUKAN_DETAIL_FORM_UpdateSlideLeft(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_FORM_AdvanceSelection(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_PlaceSideModels(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *unused2);
void ZUKAN_DETAIL_FORM_UpdateSlideRight(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_FORM_UpdateSlideBoth(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_FORM_RebuildSideItems(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_SwapItems(u16 *unused, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_SetActorsNormalMode(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_SetActorsAlphaMode(u16 *heap, struct Ov208Form *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_FORM_GetModelOffsets(VecF *pos, u32 species, u32 form, u32 gender, u32 shiny, u32 personality, u32 side, u32 extra);
void ZUKAN_DETAIL_FORM_ConvertModelPosition(struct Ov208Mdl *item, int index, ZukanDetailFormVec *out);
void ZUKAN_DETAIL_FORM_SelectModelPosition(int item, int pose, int out);
void ZUKAN_DETAIL_FORM_CopyModelPosition(struct Ov208Mdl *item, int index, VecF *dst);
/* END mkheaders: generated region */

#endif
