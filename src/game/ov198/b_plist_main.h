#ifndef GAME_OV198_B_PLIST_MAIN_H
#define GAME_OV198_B_PLIST_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of b_plist_main.c, prototypes copied from their definitions. */

struct B_PlistWork;
struct TcbTask;
struct Summary;

#include "../types.h"

void B_PLIST_MAIN_SyncMoveActors(u8 *p);
void B_PLIST_MAIN_SetActorAnimSeq(struct ClactActor *a, u16 b);
u16 B_PLIST_MAIN_GetMonAnimState(char *p);
void B_PLIST_MAIN_UpdateActorAnims(u8 *p);
void B_PLIST_MAIN_CreateToolActors(u8 *p);
void B_PLIST_MAIN_ShiftActors(u8 *p,int a,short delta);
void B_PLIST_MAIN_SwapActorPos(char *p, int slotA, int slotB);
void B_PLIST_MAIN_Create(u8 *p);
void B_PLIST_MAIN_Task(void *task,u8 *p);
int B_PLIST_MAIN_Init(u8 *p);
int B_PLIST_MAIN_WaitPrintQue(u8 *p);
int B_PLIST_MAIN_WaitWipe(u8 *p);
int B_PLIST_MAIN_HandleSelectInput(u8 *p);
int B_PLIST_MAIN_ConfirmSelect(u8 *p);
int B_PLIST_MAIN_HandleModeSelect(u8 *p);
int B_PLIST_MAIN_HandleListSelect(u8 *p);
int B_PLIST_MAIN_HandleMoveSelect(u8 *p);
int B_PLIST_MAIN_HandleSlotSelect(u8 *p);
int B_PLIST_MAIN_HandleSlotSelectFade(u8 *p);
int B_PLIST_MAIN_HandleItemSelect(u8 *p);
int B_PLIST_MAIN_HandleConfirmCancel(u8 *p);
u32 B_PLIST_MAIN_EnterState1A(u8 *p);
int B_PLIST_MAIN_HandlePartySelect(u8 *p);
u32 B_PLIST_MAIN_ApplyPartyListPage(u32 a);
u32 B_PLIST_MAIN_ApplyMonMenuPage(u32 a);
u32 B_PLIST_MAIN_ApplySummaryPage(u32 a);
u32 B_PLIST_MAIN_ApplyMoveListPage(u32 a);
int B_PLIST_MAIN_ApplyMoveDetailPage(char *p);
u32 B_PLIST_MAIN_ApplyMoveListWithNewMovePage(u32 a);
u32 B_PLIST_MAIN_ApplyMoveDetailWithNewMovePage(u32 a);
u32 B_PLIST_MAIN_ApplyMoveListForItemPage(u32 a);
int B_PLIST_MAIN_RedrawByMode(u8 *p);
u32 B_PLIST_MAIN_RefreshAndState16(u8 *p);
u32 B_PLIST_MAIN_ClearPrintStream(u8 *p);
int B_PLIST_MAIN_WaitPrintStream(struct B_PlistWork *a);
int B_PLIST_MAIN_HandleSkipKey(char *p);
int B_PLIST_MAIN_CheckBusyFlag(char *p);
int B_PLIST_MAIN_BeginFadeOut(char *p);
u32 B_PLIST_MAIN_WaitFadeOut(u8 *p);
int B_PLIST_MAIN_Delete(struct TcbTask *task,char *p);
void B_PLIST_MAIN_InitBg(u8 *p);
void B_PLIST_MAIN_ExitBg(void);
void B_PLIST_MAIN_LoadGraphics(char *p);
void B_PLIST_MAIN_CreateTextResources(char *p);
void B_PLIST_MAIN_DeleteTextResources(u8 *p);
void B_PLIST_MAIN_ReadSummary(void *unused,void *mon,struct Summary *p);
void B_PLIST_MAIN_ReadParty(u8 *p);
int B_PLIST_MAIN_HandleCursorInput(u8 *p);
int B_PLIST_MAIN_GetSlotState(u8 *p,int i);
u8 B_PLIST_MAIN_NextSelectable(u8 *p,int i,int delta);
void B_PLIST_MAIN_DrawExpBar(u8 *p,int mode);
int B_PLIST_MAIN_ApplyMode(u8 *p,unsigned mode);
void B_PLIST_MAIN_LoadModePalette(u8 *p,u32 n);
int B_PLIST_MAIN_GetRowStatus(u8 *p);
int B_PLIST_MAIN_PrintStatusMessage(u8 *p);
u8 B_PLIST_MAIN_IsRowFlagged(u8 *p);
int B_PLIST_MAIN_GetOwnerFlag18(char **p);
u32 B_PLIST_MAIN_IsBattleSlot(u32 a, u32 b);
u32 B_PLIST_MAIN_CheckMoveUsable(u8 *p);
int B_PLIST_MAIN_IsSlotSelectable(u8 *p,int i);
int B_PLIST_MAIN_IsIndexValid(char **p, unsigned int v);
unsigned B_PLIST_MAIN_IsIndexInParty(u8 *p, int index);
void B_PLIST_MAIN_InitSelectionForMode(u8 *p, u32 state);
void B_PLIST_MAIN_InitOrder(u8 *p);
void B_PLIST_MAIN_SwapOrder(u8 *p, int a, int b);
u32 B_PLIST_MAIN_IsInSelection(u8 **p, u32 c);
int B_PLIST_MAIN_GetOrderIndex(u8 *p, int i);
void B_PLIST_MAIN_SetSelectionEntry(u8 **p, u32 b, u32 c);
void B_PLIST_MAIN_PushSelectionPair(u8 *p, int a, int b);
int B_PLIST_MAIN_PopSelectionPair(unsigned char *p, unsigned char *a, unsigned char *b, int clear);
int B_PLIST_MAIN_BeginMode8(u8 *p);
int B_PLIST_MAIN_PrintRowMessage(u8 *p);
int B_PLIST_MAIN_ConfirmSwap(u8 *p);
int B_PLIST_MAIN_EndSwap(char *p);
void B_PLIST_MAIN_GetFramePos(u8 *a, u8 *b, unsigned int c);
void B_PLIST_MAIN_CopyFrame(u8 *dst, unsigned bg, unsigned which);
void B_PLIST_MAIN_MoveActorByFlag(u8 *p, int a, int b);
int B_PLIST_MAIN_UpdateSwapFrames(u8 *p);
int B_PLIST_MAIN_FinishSwap(u8 *p);
int B_PLIST_MAIN_CanSwap(u8 *p);
int B_PLIST_MAIN_HasSwappable(u8 *p);
void B_PLIST_MAIN_CommitSwap(u8 *p);
void B_PLIST_MAIN_ClearSelection(u8 **p);
u32 B_PLIST_MAIN_CheckCancel(u8 **p);
void B_PLIST_MAIN_PlaySe(u8 **p, u32 b);
void B_PLIST_MAIN_PlaySe2(u8 **p, u32 b);
void B_PLIST_MAIN_CreateCursor(u8 *p,u32 index,u32 b);
u32 B_PLIST_MAIN_DeleteCursor(u8 *p);
void B_PLIST_MAIN_RecreateCursor(u8 *p, u32 a, u32 b);
void B_PLIST_MAIN_SetActorsVisible(u8 *p, u32 v);
void B_PLIST_MAIN_LayoutCursorActors(u8 *p, u32 idx);
void B_PLIST_MAIN_ShowCursor(u8 *p, unsigned idx);
/* END mkheaders: generated region */

#endif
