#ifndef GAME_OV120_GTSNEGO_DISP_H
#define GAME_OV120_GTSNEGO_DISP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gtsnego_disp.c, prototypes copied from their definitions. */

struct GtsnegoDispCtx;
struct GtsnegoDispEntry;
struct GtsnegoActorSys;
typedef struct GtsnegoDispCtx GtsnegoDispCtx;

struct GtsnegoDispUiCtx;
struct GFLNetHandle;
#include "../types.h"

void GTSNEGO_DISP_SetCallback(void **slot, void *callback);
void GTSNEGO_DISP_SetStateCallback(void *dispCtx, void *callback, int line);
void GTSNEGO_DISP_OnTradeSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
void GTSNEGO_DISP_OnStatusSync(u32 netId,int size,const void *data,struct GtsnegoDispCtx *dispCtx,struct GFLNetHandle *netHandle);
void GTSNEGO_DISP_OnRecordSync(u32 netId,int size,const void *data,u8 *dispCtx,struct GFLNetHandle *netHandle);
int GTSNEGO_DISP_StartTrade(int choice, u8 *dispCtx);
void GTSNEGO_DISP_CycleRowB(int delta, char *dispCtx);
void GTSNEGO_DISP_CycleRowC(int delta, char *dispCtx);
void GTSNEGO_DISP_CycleRowA(int delta, char *dispCtx);
int GTSNEGO_DISP_MoveRowCursor(int selection, char *dispCtx);
int GTSNEGO_DISP_OnRowCursorMoved(int selection,char *dispCtx);
void GTSNEGO_DISP_MoveCursorVertical(int direction,char *dispCtx);
void GTSNEGO_DISP_WaitWipeDone(u8 *dispCtx);
void GTSNEGO_DISP_StartWipe(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowTradeReady(u8 *dispCtx);
void GTSNEGO_DISP_WaitTradeStart(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowTradeConfirm(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ConfirmStatus(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_PrepareTrade(u8 *dispCtx);
void GTSNEGO_DISP_StartSync(u8 *dispCtx);
void GTSNEGO_DISP_SendStatus(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_SendRecord(u8 *dispCtx);
void GTSNEGO_DISP_SendHandshake(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_WaitNegotiation(u8 *dispCtx);
void GTSNEGO_DISP_CheckNegotiation(int *dispCtx);
void GTSNEGO_DISP_WaitPartnerReady(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleTradeKeys(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ScoreMatch(int matchData, u8 *dispCtx);
void GTSNEGO_DISP_StartMatchmaking(u8 *dispCtx);
void GTSNEGO_DISP_OnMenuCallback(void *selection,int event,u8 *dispCtx);
void GTSNEGO_DISP_OnConfirmDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandleConfirmKeys(u8 *dispCtx);
void GTSNEGO_DISP_CreateConfirmUi(u8 *dispCtx);
void *GTSNEGO_DISP_GetEntry(void **list,int index);
void *GTSNEGO_DISP_GetEntryClamped(void **list,int index);
void GTSNEGO_DISP_ShowSubPlanes(u8 *dispCtx);
void GTSNEGO_DISP_Teardown(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnDisconnect(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnDisconnectCallback(int unused, int buttonIndex, int *dispCtx);
void GTSNEGO_DISP_CreateExitTooltip(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnExitMenuDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OpenExitMenu(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowListMessage(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_EndList(struct GtsnegoDispCtx *dispCtx);
int GTSNEGO_DISP_ListCursorUp(u8 *dispCtx);
int GTSNEGO_DISP_ListCursorDown(u8 *dispCtx);
void GTSNEGO_DISP_OnListConfirmDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_DeleteMenuWindow(u8 *dispCtx);
void GTSNEGO_DISP_HandleListInput(struct GtsnegoDispUiCtx *p);
void GTSNEGO_DISP_WaitSelectStart(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowPokemonList(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_ShowPartySelect(u8 *dispCtx);
int GTSNEGO_DISP_SelectParty(u8 *dispCtx,int position);
int GTSNEGO_DISP_CheckPartySelect(struct GtsnegoDispCtx *dispCtx, int position);
void GTSNEGO_DISP_OnPartySelected(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OnPartyMenuDone(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_OpenPartyMenu(struct GtsnegoDispCtx *dispCtx);
void GTSNEGO_DISP_HandlePartyInput(u8 *dispCtx);
void GTSNEGO_DISP_ResetScreen(u8 *dispCtx);
int GTSNEGO_DISP_Create(void *owner, int unused, u8 *parentCtx);
int GTSNEGO_DISP_Step(int unusedA, int unusedB, int unusedC, u8 *dispCtx);
int GTSNEGO_DISP_Delete(void *owner, int unusedA, int unusedB, struct GtsnegoDispCtx *dispCtx);
u8 *GTSNEGO_DISP_CreateMsgSystem(u32 heap,void *arg);
void GTSNEGO_DISP_DrawSystem(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_DeleteMsgSystem(u8 *actorSys);
u32 GTSNEGO_DISP_GetUnit(struct GtsnegoActorSys *actorSys);
void GTSNEGO_DISP_InitBgLayers(u8 *actorSys);
void GTSNEGO_DISP_BlendPalette(struct GtsnegoActorSys *actorSys,int bank,int *offset,int *size,int count);
void GTSNEGO_DISP_SetTradePalette(struct GtsnegoActorSys *actorSys,int flag,int mode);
void GTSNEGO_DISP_VBlank(void *unused,u8 *actorSys);
void GTSNEGO_DISP_RegisterGraphics(u8 *actorSys);
void GTSNEGO_DISP_Noop(u8 *actorSys, int unusedFlag);
void GTSNEGO_DISP_RedrawActors(u8 *actorSys);
void GTSNEGO_DISP_ResetActors(u8 *actorSys);
void GTSNEGO_DISP_CreateTouchbar(u8 *actorSys, int actorPlttSlot);
u32 GTSNEGO_DISP_GetTouchbar(u8 *actorSys);
void GTSNEGO_DISP_DeleteTouchbar(u8 *actorSys);
void GTSNEGO_DISP_CreateCursorActor(u8 *actorSys);
void GTSNEGO_DISP_SetCursorState(u8 *actorSys, void *taskMenuWin, u32 position);
/* END mkheaders: generated region */

#endif
