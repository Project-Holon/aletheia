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
void GTSNEGO_MSG_CreateActorAt(u8 *actorSys,u16 x,u16 y,int isRightSide);
void GTSNEGO_MSG_DeleteActors(u8 *actorSys);
void GTSNEGO_MSG_SetActorMode(u8 *actorSys,u32 slot);
void GTSNEGO_MSG_InitWindows(u8 *actorSys, int includeFirstIcon);
void GTSNEGO_MSG_DeleteTileHandle(u8 *actorSys);
void GTSNEGO_MSG_DrawTileRow(struct GtsnegoActorSys *actorSys, int row);
void GTSNEGO_MSG_FillTileRow(struct GtsnegoActorSys *actorSys, int row);
void GTSNEGO_MSG_DrawTileRows(struct GtsnegoActorSys *actorSys,void *list,int first);
void GTSNEGO_MSG_TeardownActorList(u8 *actorSys);
void GTSNEGO_MSG_TeardownTileRows(u8 *actorSys);
int GTSNEGO_MSG_CursorDown(void *unused,int *listState);
int GTSNEGO_MSG_CursorUp(void *unused,int *listState);
void GTSNEGO_MSG_SetCursorIndex(void *unused, int *listState, int index);
void GTSNEGO_MSG_CreateCursorActor(u8 *actorSys);
void GTSNEGO_MSG_DeleteCursorActor(u8 *actorSys);
void GTSNEGO_MSG_CreateIconActors(u8 *actorSys,int flag);
void GTSNEGO_MSG_DeleteIconActors(u8 *actorSys);
void GTSNEGO_MSG_RestartIconAnim(struct GtsnegoActorSys *actorSys, u32 flag);
void GTSNEGO_MSG_SetScrollState(struct GtsnegoActorSys *actorSys, int state);
void GTSNEGO_MSG_ClearScrollState(struct GtsnegoActorSys *actorSys);
int GTSNEGO_MSG_StepScroll(u8 *actorSys, int *out);
void GTSNEGO_MSG_ScrollAllRows(u8 *actorSys, int flag);
void GTSNEGO_MSG_SetupRowBg(void *actorSys);
void GTSNEGO_MSG_CreateListActor(u8 *actorSys, int slot, int outfit);
void GTSNEGO_MSG_SetListActorPos(u8 *actorSys, int index, int x, int y);
void GTSNEGO_MSG_SetListEntry(u8 *actorSys, void *entry, int index);
void GTSNEGO_MSG_MoveListActor(u8 *actorSys, int index, int delta);
void GTSNEGO_MSG_ScrollListDown(u8 *actorSys, void *entry);
void GTSNEGO_MSG_ScrollListUp(u8 *actorSys, void *entry);
void GTSNEGO_MSG_FillListRange(u8 *actorSys, void *container, int offset);
int GTSNEGO_MSG_GetListRowY(struct GtsnegoActorSys *actorSys, int index, int count);
int GTSNEGO_MSG_GetListRowYF(struct GtsnegoActorSys *actorSys, int y, int count);
void GTSNEGO_MSG_SetIconY(struct GtsnegoActorSys *actorSys, int index, int count);
int GTSNEGO_MSG_SetIconYClamped(struct GtsnegoActorSys *actorSys,int y,int count);
void GTSNEGO_MSG_CycleIdleAnim(char *actorSys);
void GTSNEGO_MSG_CreateIdleActors(u8 *actorSys);
void GTSNEGO_MSG_DeleteIdleActors(char *actorSys);
void GTSNEGO_MSG_SetIdleAnim(struct GtsnegoActorSys *actorSys,int outfit);
void GTSNEGO_MSG_CreateIdleUi(u8 *actorSys);
void GTSNEGO_MSG_StepIdleFade(struct GtsnegoActorSys *actorSys);
void GTSNEGO_MSG_Teardown(u8 *actorSys);
void GTSNEGO_MSG_DeleteButtons(u8 *msgCtx);
char *GTSNEGO_MSG_Create(u32 heap,u32 msgFileId);
void GTSNEGO_MSG_Main(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_Delete(char *msgCtx);
void GTSNEGO_MSG_PrintWindow(struct GtsnegoMsgCtx *msgCtx,u16 msgId);
void GTSNEGO_MSG_PrintWindowB(u8 *msgCtx, int msgId);
int GTSNEGO_MSG_UpdatePrintStream(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_DeleteWindow(struct GtsnegoMsgCtx *msgCtx);
void *GTSNEGO_MSG_OpenMenu(char *msgCtx,int position);
int GTSNEGO_MSG_UpdateButtons(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_DeleteRows(char *msgCtx);
int GTSNEGO_MSG_CreateRow(u8 *msgCtx, int msgId, int x, int y, int width, int bgLayer);
int GTSNEGO_MSG_CreateRowEx(int msgCtx, int msgId, int x, int y);
void GTSNEGO_MSG_RedrawRow(char *msgCtx,u16 msgId,int row);
void GTSNEGO_MSG_FlushRowLayer(char *msgCtx);
void GTSNEGO_MSG_ClearRows(char *msgCtx);
void GTSNEGO_MSG_CreateYesNoUi(char *msgCtx,int callback,int callbackWork);
void GTSNEGO_MSG_CreateListUi(char *msgCtx,int callback,int callbackWork,int rowAIndex,int rowBIndex,int rowCIndex);
void GTSNEGO_MSG_RedrawRowA(char *msgCtx,int index);
void GTSNEGO_MSG_RedrawRowB(char *msgCtx,int index);
void GTSNEGO_MSG_RedrawRowC(char *msgCtx,int index);
void GTSNEGO_MSG_DeleteButtonsKeep(u8 *msgCtx);
void *GTSNEGO_MSG_CreateTooltip(char *msgCtx,u16 msgId);
void GTSNEGO_MSG_PrintTooltip(char *msgCtx,u16 msgId);
void GTSNEGO_MSG_PrintEntry(char *msgCtx,void *status);
void GTSNEGO_MSG_DeleteEntryWindow(struct GtsnegoMsgCtx *msgCtx);
int GTSNEGO_MSG_PrintListEntry(char *msgCtx, void *status, int row);
void GTSNEGO_MSG_PrintList(char *msgCtx,void *list);
void GTSNEGO_MSG_PrintListEntryAt(char *msgCtx,void *list,int index);
void GTSNEGO_MSG_ShiftListDown(char *msgCtx);
void GTSNEGO_MSG_PrintListRange(char *msgCtx,void *list,int start);
void GTSNEGO_MSG_PrintListEntryN(char *msgCtx,void *list,int index);
void GTSNEGO_MSG_ShiftListUp(char *msgCtx);
void *GTSNEGO_MSG_OpenMenuB(char *msgCtx,int position);
void GTSNEGO_MSG_CloseMenu(struct TaskMenuWork *taskMenu);
void GTSNEGO_MSG_CreateDraw(struct GtsnegoMsgCtx *msgCtx,void *actorSys);
void GTSNEGO_MSG_DeleteDraw(u8 *msgCtx);
void GTSNEGO_MSG_PrintDraw(struct GtsnegoMsgCtx *msgCtx, void *sentence);
void GTSNEGO_MSG_PrintStatus(struct GtsnegoMsgCtx *msgCtx, u16 msgId);
void GTSNEGO_MSG_CreateConfirmUi(u8 *msgCtx, int callback, int callbackWork);
void GTSNEGO_MSG_SetDecide(struct GtsnegoMsgCtx *msgCtx);
void GTSNEGO_MSG_DeleteConfirmWindow(u8 *msgCtx);
int GTSNEGO_MSG_IsConfirmFinished(u8 *msgCtx);
void GTSNEGO_MSG_PrintPair(char *msgCtx,int unused,u32 tradeCount);
void GTSNEGO_MSG_PrintSingle(char *msgCtx, void *status);
void GTSNEGO_MSG_PrintSummary(char *msgCtx,void *status,u32 tradeCount);
void GTSNEGO_MSG_DeleteAll(char *msgCtx);
/* END mkheaders: generated region */

#endif
