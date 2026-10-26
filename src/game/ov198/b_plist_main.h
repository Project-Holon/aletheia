#ifndef GAME_OV198_B_PLIST_MAIN_H
#define GAME_OV198_B_PLIST_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of b_plist_main.c, prototypes copied from their definitions. */

struct ClactActor;
struct B_PlistWork;
struct B_PlistHost;
struct TcbTask;
struct Summary;

#include "../types.h"

void B_PLIST_MAIN_SyncMoveActors(struct B_PlistWork *p);
void B_PLIST_MAIN_SetActorAnimSeq(struct ClactActor *a, u16 b);
u16 B_PLIST_MAIN_GetMonAnimState(struct B_PlistWork *p);
void B_PLIST_MAIN_UpdateActorAnims(struct B_PlistWork *p);
void B_PLIST_MAIN_CreateToolActors(struct B_PlistWork *p);
void B_PLIST_MAIN_ShiftActors(struct B_PlistWork *p,int a,short delta);
void B_PLIST_MAIN_SwapActorPos(struct B_PlistWork *p, int slotA, int slotB);
void B_PLIST_MAIN_Create(struct B_PlistHost *host);
void B_PLIST_MAIN_Task(struct TcbTask *task, void *arg);
int B_PLIST_MAIN_Init(struct B_PlistWork *p);
int B_PLIST_MAIN_WaitPrintQue(struct B_PlistWork *p);
int B_PLIST_MAIN_WaitWipe(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleSelectInput(struct B_PlistWork *p);
int B_PLIST_MAIN_ConfirmSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleModeSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleListSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleMoveSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleSlotSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleSlotSelectFade(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleItemSelect(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleConfirmCancel(struct B_PlistWork *p);
u32 B_PLIST_MAIN_EnterState1A(struct B_PlistWork *p);
int B_PLIST_MAIN_HandlePartySelect(struct B_PlistWork *p);
u32 B_PLIST_MAIN_ApplyPartyListPage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMonMenuPage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplySummaryPage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMoveListPage(struct B_PlistWork *a);
int B_PLIST_MAIN_ApplyMoveDetailPage(struct B_PlistWork *p);
u32 B_PLIST_MAIN_ApplyMoveListWithNewMovePage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMoveDetailWithNewMovePage(struct B_PlistWork *a);
u32 B_PLIST_MAIN_ApplyMoveListForItemPage(struct B_PlistWork *a);
int B_PLIST_MAIN_RedrawByMode(struct B_PlistWork *p);
u32 B_PLIST_MAIN_RefreshAndState16(struct B_PlistWork *p);
u32 B_PLIST_MAIN_ClearPrintStream(struct B_PlistWork *p);
int B_PLIST_MAIN_WaitPrintStream(struct B_PlistWork *a);
int B_PLIST_MAIN_HandleSkipKey(struct B_PlistWork *p);
int B_PLIST_MAIN_CheckBusyFlag(struct B_PlistWork *p);
int B_PLIST_MAIN_BeginFadeOut(struct B_PlistWork *p);
u32 B_PLIST_MAIN_WaitFadeOut(struct B_PlistWork *p);
int B_PLIST_MAIN_Delete(struct TcbTask *task,struct B_PlistWork *p);
void B_PLIST_MAIN_InitBg(struct B_PlistWork *p);
void B_PLIST_MAIN_ExitBg(void);
void B_PLIST_MAIN_LoadGraphics(struct B_PlistWork *p);
void B_PLIST_MAIN_CreateTextResources(struct B_PlistWork *p);
void B_PLIST_MAIN_DeleteTextResources(struct B_PlistWork *p);
void B_PLIST_MAIN_ReadSummary(void *unused,void *mon,struct Summary *p);
void B_PLIST_MAIN_ReadParty(struct B_PlistWork *p);
int B_PLIST_MAIN_HandleCursorInput(struct B_PlistWork *p);
int B_PLIST_MAIN_GetSlotState(struct B_PlistWork *p,int i);
u8 B_PLIST_MAIN_NextSelectable(struct B_PlistWork *p,int i,int delta);
void B_PLIST_MAIN_DrawExpBar(struct B_PlistWork *p,int mode);
int B_PLIST_MAIN_ApplyMode(struct B_PlistWork *p,unsigned mode);
void B_PLIST_MAIN_LoadModePalette(struct B_PlistWork *p,u32 n);
int B_PLIST_MAIN_GetRowStatus(struct B_PlistWork *p);
int B_PLIST_MAIN_PrintStatusMessage(struct B_PlistWork *p);
u8 B_PLIST_MAIN_IsRowFlagged(struct B_PlistWork *p);
int B_PLIST_MAIN_GetOwnerFlag18(struct B_PlistWork *p);
u32 B_PLIST_MAIN_IsBattleSlot(struct B_PlistWork *a, u32 b);
u32 B_PLIST_MAIN_CheckMoveUsable(struct B_PlistWork *p);
int B_PLIST_MAIN_IsSlotSelectable(struct B_PlistWork *p,int i);
int B_PLIST_MAIN_IsIndexValid(struct B_PlistWork *p, unsigned int v);
unsigned B_PLIST_MAIN_IsIndexInParty(struct B_PlistWork *p, int index);
void B_PLIST_MAIN_InitSelectionForMode(struct B_PlistWork *p, u32 state);
void B_PLIST_MAIN_InitOrder(struct B_PlistWork *p);
void B_PLIST_MAIN_SwapOrder(struct B_PlistWork *p, int a, int b);
u32 B_PLIST_MAIN_IsInSelection(struct B_PlistWork *p, u32 c);
int B_PLIST_MAIN_GetOrderIndex(struct B_PlistWork *p, int i);
void B_PLIST_MAIN_SetSelectionEntry(struct B_PlistWork *p, u32 b, u32 c);
void B_PLIST_MAIN_PushSelectionPair(struct B_PlistWork *p, int a, int b);
int B_PLIST_MAIN_PopSelectionPair(struct B_PlistWork *p, unsigned char *a, unsigned char *b, int clear);
int B_PLIST_MAIN_BeginMode8(struct B_PlistWork *p);
int B_PLIST_MAIN_PrintRowMessage(struct B_PlistWork *p);
int B_PLIST_MAIN_ConfirmSwap(struct B_PlistWork *p);
int B_PLIST_MAIN_EndSwap(struct B_PlistWork *p);
void B_PLIST_MAIN_GetFramePos(u8 *a, u8 *b, unsigned int c);
void B_PLIST_MAIN_CopyFrame(u8 *dst, unsigned bg, unsigned which);
void B_PLIST_MAIN_MoveActorByFlag(struct B_PlistWork *p, int a, int b);
int B_PLIST_MAIN_UpdateSwapFrames(struct B_PlistWork *p);
int B_PLIST_MAIN_FinishSwap(struct B_PlistWork *p);
int B_PLIST_MAIN_CanSwap(struct B_PlistWork *p);
int B_PLIST_MAIN_HasSwappable(struct B_PlistWork *p);
void B_PLIST_MAIN_CommitSwap(struct B_PlistWork *p);
void B_PLIST_MAIN_ClearSelection(struct B_PlistWork *p);
u32 B_PLIST_MAIN_CheckCancel(struct B_PlistWork *p);
void B_PLIST_MAIN_PlaySe(struct B_PlistWork *p, u32 b);
void B_PLIST_MAIN_PlaySe2(struct B_PlistWork *p, u32 b);
void B_PLIST_MAIN_CreateCursor(struct B_PlistWork *p,u32 index,u32 b);
u32 B_PLIST_MAIN_DeleteCursor(struct B_PlistWork *p);
void B_PLIST_MAIN_RecreateCursor(struct B_PlistWork *p, u32 a, u32 b);
void B_PLIST_MAIN_SetActorsVisible(struct B_PlistWork *p, u32 v);
void B_PLIST_MAIN_LayoutCursorActors(struct B_PlistWork *p, u32 idx);
void B_PLIST_MAIN_ShowCursor(struct B_PlistWork *p, unsigned idx);
void B_PLIST_MAIN_HideCursor(struct B_PlistWork *p);
void B_PLIST_MAIN_HideCursorOnTouch(struct B_PlistWork *p);
void B_PLIST_MAIN_MoveCursor(struct B_PlistWork *p, u32 idx);
/* END mkheaders: generated region */

#endif
