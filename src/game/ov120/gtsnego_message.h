#ifndef GAME_OV120_GTSNEGO_MESSAGE_H
#define GAME_OV120_GTSNEGO_MESSAGE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gtsnego_message.c, prototypes copied from their definitions. */

struct GtsnegoActorSys;
struct GtsnegoMsgCtx;
struct TaskMenuWork;

#include "../types.h"

int GTSNEGO_MSG_SetCursorAnimSeq(struct GtsnegoActorSys *actorSys,u32 position);
int GTSNEGO_MSG_IsCursorAnimDone(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_CreateActorAt(struct GtsnegoActorSys *actorSys,u16 x,u16 y,int isRightSide);
void GTSNEGO_MSG_DeleteActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_SetActorMode(struct GtsnegoActorSys *actorSys,u32 slot);
void GTSNEGO_MSG_InitWindows(struct GtsnegoActorSys *actorSys, int includeFirstIcon);
void GTSNEGO_MSG_DeleteTileHandle(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_DrawTileRow(struct GtsnegoActorSys *actorSys, int row);
void GTSNEGO_MSG_FillTileRow(struct GtsnegoActorSys *actorSys, int row);
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoActorSys *actorSys,void *list,int first);
void GTSNEGO_MSG_TeardownActorList(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_TeardownTileRows(struct GtsnegoActorSys *actorSys);
int GTSNEGO_MSG_CursorDown(void *unused,int *listState);
int GTSNEGO_MSG_CursorUp(void *unused,int *listState);
void GTSNEGO_MSG_SetCursorIndex(void *unused, int *listState, int index);
void GTSNEGO_MSG_CreateCursorActor(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_DeleteCursorActor(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_CreateIconActors(struct GtsnegoActorSys *actorSys,int flag);
void GTSNEGO_MSG_DeleteIconActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoActorSys *actorSys, u32 flag);
void GTSNEGO_MSG_SetScrollState(struct GtsnegoActorSys *actorSys, int state);
void GTSNEGO_MSG_ClearScrollState(struct GtsnegoActorSys *actorSys);
int GTSNEGO_MSG_StepScroll(struct GtsnegoActorSys *actorSys, int *out);
void GTSNEGO_MSG_ScrollAllRows(struct GtsnegoActorSys *actorSys, int flag);
void GTSNEGO_MSG_SetupRowBg(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_CreateListActor(struct GtsnegoActorSys *actorSys, int slot, int outfit);
void GTSNEGO_MSG_SetListActorPos(struct GtsnegoActorSys *actorSys, int index, int x, int y);
void GTSNEGO_MSG_SetListEntry(struct GtsnegoActorSys *actorSys, void *entry, int index);
void GTSNEGO_MSG_MoveListActor(struct GtsnegoActorSys *actorSys, int index, int delta);
void GTSNEGO_MSG_ScrollListDown(struct GtsnegoActorSys *actorSys, void *entry);
void GTSNEGO_MSG_ScrollListUp(struct GtsnegoActorSys *actorSys, void *entry);
void GTSNEGO_MSG_FillListRange(struct GtsnegoActorSys *actorSys, void *container, int offset);
int GTSNEGO_MSG_GetListRowY(struct GtsnegoActorSys *actorSys, int index, int count);
int GTSNEGO_MSG_GetListRowYF(struct GtsnegoActorSys *actorSys, int y, int count);
void GTSNEGO_MSG_SetIconY(struct GtsnegoActorSys *actorSys, int index, int count);
int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoActorSys *actorSys,int y,int count);
void GTSNEGO_MSG_CycleIdleAnim(void *actorSys, u32 frame);
void GTSNEGO_MSG_CreateIdleActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_DeleteIdleActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoActorSys *actorSys,int outfit);
void GTSNEGO_MSG_CreateIdleUi(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_StepIdleFade(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_Teardown(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_DeleteButtons(struct GtsnegoMsgCtx *msgCtx);
struct GtsnegoMsgCtx *GTSNEGO_MSG_Create(u32 heap,u32 msgFileId);
void GTSNEGO_MSG_Main(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_Delete(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_PrintWindow(struct GtsnegoMsgCtx *msgCtx,u16 msgId);
void GTSNEGO_MSG_PrintWindowB(struct GtsnegoMsgCtx *msgCtx, int msgId);
int GTSNEGO_MSG_UpdatePrintStream(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_DeleteWindow(struct GtsnegoMsgCtx *msgCtx);
void *GTSNEGO_MSG_OpenMenu(struct GtsnegoMsgCtx *msgCtx,int position);
int GTSNEGO_MSG_UpdateButtons(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_DeleteRows(struct GtsnegoMsgCtx *msgCtx);
int GTSNEGO_MSG_CreateRow(struct GtsnegoMsgCtx *msgCtx, int msgId, int x, int y, int width, int bgLayer);
int GTSNEGO_MSG_CreateRowEx(struct GtsnegoMsgCtx *msgCtx, int msgId, int x, int y);
void GTSNEGO_MSG_RedrawRow(struct GtsnegoMsgCtx *msgCtx,u16 msgId,int row);
void GTSNEGO_MSG_FlushRowLayer(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_ClearRows(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_CreateYesNoUi(struct GtsnegoMsgCtx *msgCtx,void (*callback)(u32, s32, void *),void *callbackWork);
void GTSNEGO_MSG_CreateListUi(struct GtsnegoMsgCtx *msgCtx,void (*callback)(u32, s32, void *),void *callbackWork,int rowAIndex,int rowBIndex,int rowCIndex);
void GTSNEGO_MSG_RedrawRowA(struct GtsnegoMsgCtx *msgCtx,int index);
void GTSNEGO_MSG_RedrawRowB(struct GtsnegoMsgCtx *msgCtx,int index);
void GTSNEGO_MSG_RedrawRowC(struct GtsnegoMsgCtx *msgCtx,int index);
void GTSNEGO_MSG_DeleteButtonsKeep(struct GtsnegoMsgCtx *msgCtx);
void *GTSNEGO_MSG_CreateTooltip(struct GtsnegoMsgCtx *msgCtx,u16 msgId);
void GTSNEGO_MSG_PrintTooltip(struct GtsnegoMsgCtx *msgCtx,u16 msgId);
void GTSNEGO_MSG_PrintEntry(struct GtsnegoMsgCtx *msgCtx,void *status);
void GTSNEGO_MSG_DeleteEntryWindow(struct GtsnegoMsgCtx *msgCtx);
int GTSNEGO_MSG_PrintListEntry(struct GtsnegoMsgCtx *msgCtx, void *status, int row);
void GTSNEGO_MSG_PrintList(struct GtsnegoMsgCtx *msgCtx,void *list);
void GTSNEGO_MSG_PrintListEntryAt(struct GtsnegoMsgCtx *msgCtx,void *list,int index);
void GTSNEGO_MSG_ShiftListDown(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_PrintListRange(struct GtsnegoMsgCtx *msgCtx,void *list,int start);
void GTSNEGO_MSG_PrintListEntryN(struct GtsnegoMsgCtx *msgCtx,void *list,int index);
void GTSNEGO_MSG_ShiftListUp(struct GtsnegoMsgCtx *msgCtx);
void *GTSNEGO_MSG_OpenMenuB(struct GtsnegoMsgCtx *msgCtx,int position);
void GTSNEGO_MSG_CloseMenu(struct TaskMenuWork *taskMenu);
void GTSNEGO_MSG_CreateDraw(struct GtsnegoMsgCtx *msgCtx,struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_DeleteDraw(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *msgCtx, void *sentence);
void GTSNEGO_MSG_PrintStatus(struct GtsnegoMsgCtx *msgCtx, u16 msgId);
void GTSNEGO_MSG_CreateConfirmUi(struct GtsnegoMsgCtx *msgCtx, void (*callback)(u32, s32, void *), void *callbackWork);
void GTSNEGO_MSG_SetDecide(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_DeleteConfirmWindow(struct GtsnegoMsgCtx *msgCtx);
int GTSNEGO_MSG_IsConfirmFinished(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_PrintPair(struct GtsnegoMsgCtx *msgCtx,int unused,u32 tradeCount);
void GTSNEGO_MSG_PrintSingle(struct GtsnegoMsgCtx *msgCtx, void *status);
void GTSNEGO_MSG_PrintSummary(struct GtsnegoMsgCtx *msgCtx,void *status,u32 tradeCount);
void GTSNEGO_MSG_DeleteAll(struct GtsnegoMsgCtx *msgCtx);
/* END mkheaders: generated region */

#endif
