#ifndef GAME_OV095_BTLV_SCD_H
#define GAME_OV095_BTLV_SCD_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_scd.c, prototypes copied from their definitions. */

struct BtlvCore;
struct BtlMain;
struct BtlSide;
struct BtlClient;
struct BtlPokeParam;
union BtlAction;
struct BtlvYesNoWork;

#include "../ov095/btlv_scd_types.h"
#include "../types.h"

BtlvAuxView *BTLV_SCD_Create(struct BtlvCore *core, struct BtlMain *mainModule, struct BtlSide *pokeCon, void *taskList, void *fontMain, struct BtlClient *client, int viewParam, u16 heapId);
void BTLV_SCD_CreateInput(BtlvAuxView *view);
void BTLV_SCD_StartInputSlideIn(BtlvAuxView *view, u32 mode);
void BTLV_SCD_StartInputSlideOut(BtlvAuxView *view);
int BTLV_SCD_IsInputSlideDone(BtlvAuxView *view);
void BTLV_SCD_OnSlideInDone(BtlvAuxView *view);
void BTLV_SCD_OnSlideOutStart(BtlvAuxView *view);
void BTLV_SCD_Nop(BtlvAuxView *view);
void BTLV_SCD_CloseInputIfOpen(BtlvAuxView *view);
void BTLV_SCD_CloseInput(BtlvAuxView *view);
int BTLV_SCD_IsInputIdle(BtlvAuxView *view);
void BTLV_SCD_Delete(BtlvAuxView *view);
void BTLV_SCD_ClearTasks(BtlvAuxView *view);
void BTLV_SCD_PushTask(BtlvAuxView *view, BtlvScdStepFn openFn, BtlvScdStepFn waitFn);
int BTLV_SCD_RunTask(BtlvAuxView *view);
void BTLV_SCD_StartActionMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, u8 clientSlot, union BtlAction *action);
void BTLV_SCD_StartActionMenuBackOnly(BtlvAuxView *view, struct BtlPokeParam *pokeParam, u8 canBack, union BtlAction *action);
u32 BTLV_SCD_WaitActionMenu(BtlvAuxView *view);
void BTLV_SCD_StartMoveMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);
void BTLV_SCD_StartRotateMenu(BtlvAuxView *view, BtlvRotateSet *rotateSet, union BtlAction *action);
int BTLV_SCD_WaitMoveMenu(BtlvAuxView *view);
void BTLV_SCD_ReopenMenu(BtlvAuxView *view);
void BTLV_SCD_StartMoveInfoMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);
void BTLV_SCD_StartTargetMenu(BtlvAuxView *view, struct BtlPokeParam *pokeParam, union BtlAction *action);
int BTLV_SCD_WaitTargetMenu(BtlvAuxView *view);
void BTLV_SCD_CancelMenus(BtlvAuxView *view);
int BTLV_SCD_OpenActionMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitActionTouchStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitBackTouchStep(int *state, BtlvAuxView *view);
int BTLV_SCD_OpenMoveMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitMoveTouchStep(int *state, BtlvAuxView *view);
int BTLV_SCD_OpenRotateMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitRotateTouchStep(int *state, BtlvAuxView *view);
void BTLV_SCD_ClearTargetSet(BtlvTargetSet *targets);
void BTLV_SCD_SetTargetsMain(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code);
void BTLV_SCD_SetTargetsAltKind1(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code);
void BTLV_SCD_SetTargetsAltKind2(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 code);
void BTLV_SCD_AddFrontEnemyTargets(BtlvTargetSet *targets, struct BtlMain *mainModule, u16 moveId, u32 userViewPos);
int BTLV_SCD_PickTargetFromTouch(BtlvTargetSet *targets, int index, struct BtlMain *mainModule, u8 *outSlot);
void BTLV_SCD_ShowTargetMenu(u8 *slots, u8 count, int altMode, BtlvAuxView *view);
void BTLV_SCD_ShowTargetSetMenu(BtlvTargetSet *targets, BtlvAuxView *view);
u8 BTLV_SCD_IsTargetChosen(BtlvAuxView *view);
int BTLV_SCD_OpenTargetMenuStep(int *state, BtlvAuxView *view);
int BTLV_SCD_WaitTargetTouchStep(int *state, BtlvAuxView *view);
void BTLV_SCD_BuildTargetSet(BtlvTargetSet *targets, BtlvAuxView *view);
void BTLV_SCD_ShowRotateScreen(BtlvAuxView *view, void *payload);
int BTLV_SCD_PollTouchKey(BtlvAuxView *view, u8 *outKey);
void BTLV_SCD_CloseInputScreen(BtlvAuxView *view);
void BTLV_SCD_OpenChoiceScreen(BtlvAuxView *view, struct BtlvYesNoWork *value);
int BTLV_SCD_PollChoiceScreen(BtlvAuxView *view, u32 *outChoice);
u8 *BTLV_SCD_GetInputFlags(BtlvAuxView *view);
void BTLV_SCD_BeginCloseSequence(BtlvAuxView *view);
int BTLV_SCD_RunCloseSequence(BtlvAuxView *view);
void BTLV_SCD_ShowCounterScreen(BtlvAuxView *view, void *payload);
int BTLV_SCD_PollCounterTouch(BtlvAuxView *view);
/* END mkheaders: generated region */

#endif
