#ifndef GAME_OV120_GTSNEGO_DISP_H
#define GAME_OV120_GTSNEGO_DISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gtsnego_disp.c, prototypes copied from their definitions. */

struct GtsnegoDispCtx;
struct GtsnegoDispEntry;
struct GtsnegoActorSys;
typedef struct GtsnegoDispCtx GtsnegoDispCtx;

struct GtsnegoParentCtx;
struct GFLNetHandle;
#include "../types.h"

struct TcbTask;

void GTSNEGO_DISP_SetCallback(void **slot, void *callback);
void GTSNEGO_DISP_SetStateCallback(void *dispCtx, void *callback, int line);
void GTSNEGO_DISP_OnTradeSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
void GTSNEGO_DISP_OnStatusSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
void GTSNEGO_DISP_OnRecordSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
int GTSNEGO_DISP_StartTrade(int choice, struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CycleRowB(int delta, struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CycleRowC(int delta, struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CycleRowA(int delta, struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_MoveRowCursor(int selection, struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_OnRowCursorMoved(int selection,struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_MoveCursorVertical(int direction,struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitWipeDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_StartWipe(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowTradeReady(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitTradeStart(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowTradeConfirm(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ConfirmStatus(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_PrepareTrade(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_StartSync(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_SendStatus(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_SendRecord(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_SendHandshake(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitNegotiation(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CheckNegotiation(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitPartnerReady(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleTradeKeys(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ScoreMatch(int matchData, void *param);
void GTSNEGO_DISP_StartMatchmaking(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnMenuCallback(u32 selection,s32 event,void *);
void GTSNEGO_DISP_OnConfirmDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleConfirmKeys(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_CreateConfirmUi(struct GtsnegoDispCtx *dispCtx);
void *GTSNEGO_DISP_GetEntry(void **list,int index);
void *GTSNEGO_DISP_GetEntryClamped(void **list,int index);
void GTSNEGO_DISP_ShowSubPlanes(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_Teardown(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnDisconnect(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnDisconnectCallback(u32 unused, s32 buttonIndex, void *);
void GTSNEGO_DISP_CreateExitTooltip(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnExitMenuDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OpenExitMenu(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowListMessage(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_EndList(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ListCursorUp(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ListCursorDown(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnListConfirmDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_DeleteMenuWindow(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleListInput(struct GtsnegoDispCtx *p);
void GTSNEGO_DISP_WaitSelectStart(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowPokemonList(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowPartySelect(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_SelectParty(struct GtsnegoDispCtx *dispCtx,int position);
int GTSNEGO_DISP_CheckPartySelect(struct GtsnegoDispCtx *dispCtx, int position);
void GTSNEGO_DISP_OnPartySelected(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnPartyMenuDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OpenPartyMenu(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandlePartyInput(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ResetScreen(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_Create(void *owner, int unused, struct GtsnegoParentCtx *parentCtx);
int GTSNEGO_DISP_Step(int unusedA, int unusedB, int unusedC, struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_Delete(void *owner, int unusedA, int unusedB, struct GtsnegoDispCtx *dispCtx);
struct GtsnegoActorSys *GTSNEGO_DISP_CreateMsgSystem(u32 heap,void *arg);
void GTSNEGO_DISP_DrawSystem(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_DeleteMsgSystem(struct GtsnegoActorSys *actorSys);
struct Unit *GTSNEGO_DISP_GetUnit(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_InitBgLayers(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_BlendPalette(struct GtsnegoActorSys *actorSys,int bank,int *offset,int *size,int count);
void GTSNEGO_DISP_SetTradePalette(struct GtsnegoActorSys *actorSys,int flag,int mode);
void GTSNEGO_DISP_VBlank(struct TcbTask *unused, void *actorSysArg);
void GTSNEGO_DISP_RegisterGraphics(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_Noop(struct GtsnegoActorSys *actorSys, int unusedFlag);
void GTSNEGO_DISP_RedrawActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_ResetActors(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_CreateTouchbar(struct GtsnegoActorSys *actorSys, int actorPlttSlot);
struct TouchBar *GTSNEGO_DISP_GetTouchbar(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_DeleteTouchbar(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_CreateCursorActor(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_SetCursorState(struct GtsnegoActorSys *actorSys, void *taskMenuWin, u32 position);
/* END mkheaders: generated region */

#endif
