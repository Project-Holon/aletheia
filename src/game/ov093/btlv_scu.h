#ifndef GAME_OV093_BTLV_SCU_H
#define GAME_OV093_BTLV_SCU_H




/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btlv_scu.c, prototypes copied from their definitions. */

struct BtlvCore;
struct BtlvMessage;
struct BtlContext;
struct BtlMonTable;
struct Strbuf;
struct TcblTask;
struct BtlvScu;
struct BmpWin;

#include "../types.h"
#include "../ov093/btlv_scu_types.h"
#include "../arm9/printsys_shared_types.h"

void BTLV_SCU_PlaySeUnlessMainStep(struct BtlvCore *core, int seNo);
void BTLV_SCU_InitMessage(struct BtlvMessage *msg, int kind, int id);
void BTLV_SCU_AppendMessageArg(struct BtlvMessage *msg, u32 val);
void BTLV_SCU_SetMessageParam(struct BtlvMessage *msg, u8 param);
BtlvScu *BTLV_SCU_Create(struct BtlvCore *core, struct BtlContext *context, struct BtlMonTable *monTable, void *taskSys, void *fontMain, void *fontSub, u8 clientIndex, int heapId);
void BTLV_SCU_SetupDisplay(BtlvScu *scu);
u16 BTLV_SCU_LoadArcTiles(BtlvScu *scu, u32 arcId, u32 fileId, u32 layer);
void BTLV_SCU_Delete(BtlvScu *scu);
void BTLV_SCU_ReloadGraphics(const BtlvScu *scu);
u32 BTLV_SCU_IsFadeDone(void);
void BTLV_SCU_StartEntryScene(BtlvScu *scu, u32 quickMode);
int BTLV_SCU_RunProc(BtlvScu *scu);
void BTLV_SCU_StartBrightnessFade(int speed);
int BTLV_SCU_ProcQuickEntry(BtlvScu *scu, int *state, u8 *sides, u8 count);
int BTLV_SCU_ProcQuickEntrySingle(BtlvScu *scu, int *state);
int BTLV_SCU_ProcQuickEntryDouble(BtlvScu *scu, int *state);
int BTLV_SCU_ProcQuickEntryTriple(BtlvScu *scu, int *state);
int BTLV_SCU_ProcEntrySingleWild(int *state, BtlvScu *scu);
int BTLV_SCU_GetEntryMessageId(BtlvScu *scu);
int BTLV_SCU_ProcEntrySingleTrainer(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntrySingleLink(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleWild(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleTrainerLocal(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleTrainerComm(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleLinkLocal(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryDoubleLinkComm(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryTriple(int *state, BtlvScu *scu);
int BTLV_SCU_ProcEntryTripleLink(int *state, BtlvScu *scu);
int BTLV_SCU_PhaseTrainerIntro(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseTrainerIntroComm(BtlvScu *scu, int *state);
int BTLV_SCU_RunTrainerIntroOne(BtlvScu *scu, int *state, u16 trainerClient);
int BTLV_SCU_RunTrainerIntroTwo(BtlvScu *scu, int *state, u16 trainerClientA, u16 trainerClientB);
int BTLV_SCU_PhaseOpponentSendOutSingle(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseOpponentSendOutDouble(BtlvScu *scu, int *state);
int BTLV_SCU_RunOpponentSendOutDoubleOneTrainer(BtlvScu *scu, int *state, u8 trainerClient);
int BTLV_SCU_RunOpponentSendOutDoubleTwoTrainers(BtlvScu *scu, int *state, u16 clientA, u16 clientB);
int BTLV_SCU_PhaseOpponentSendOutTriple(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseOwnSendOutSingle(BtlvScu *scu, int *state);
int BTLV_SCU_PhaseOwnSendOutDouble(BtlvScu *scu, int *state);
int BTLV_SCU_RunOwnSendOutDoubleSolo(BtlvScu *scu, int *state, u8 ownClient);
int BTLV_SCU_RunOwnSendOutDoublePartner(BtlvScu *scu, int *state, u32 ownClient, u8 partnerClient);
int BTLV_SCU_PhaseOwnSendOutTriple(BtlvScu *scu, int *state);
u16 BTLV_SCU_GetSendOutMessageId(BtlvScu *scu, int monCount);
void BTLV_SCU_PrintMessageInstant(BtlvScu *scu, struct Strbuf *str);
void BTLV_SCU_StartMessage(BtlvScu *scu, struct Strbuf *str, u16 wait, PrintCallback callback);
u32 BTLV_SCU_ConsumeMessageEnded(BtlvScu *scu);
int BTLV_SCU_UpdateMessage(BtlvScu *scu);
void BTLV_SCU_StartWazaEffect(BtlvScu *scu, int attackerPos, int defenderPos, u32 wazaId, u32 effectSeq, int turnCount, u8 continueCount);
int BTLV_SCU_ProcWazaEffect(int *state, BtlvScu *scu);
int BTLV_SCU_RunWazaProc(BtlvScu *scu);
void BTLV_SCU_StartMonDamageAnim(BtlvScu *scu, u8 slotIdx, u16 motionId, int instant);
int BTLV_SCU_IsMonDamageAnimDone(BtlvScu *scu);
void BTLV_SCU_StartMonMotion(BtlvScu *scu, u8 slotIdx, u32 motionId);
int BTLV_SCU_IsMonMotionDone(BtlvScu *scu);
void BTLV_SCU_StartMonExit(BtlvScu *scu, int slotIdx, u32 flag);
int BTLV_SCU_IsMonExitDone(BtlvScu *scu);
void BTLV_SCU_LoadAndShowMon(BtlvScu *scu, u8 slotIdx);
int BTLV_SCU_IsMonLoadDone(BtlvScu *scu);
void BTLV_SCU_StartMonWithdraw(BtlvScu *scu, u16 viewPos, u16 effectId, int instant);
u32 BTLV_SCU_IsMonWithdrawDone(BtlvScu *scu);
void BTLV_SCU_TaskMonWithdraw(struct TcblTask *task, void *workPtr);
void BTLV_SCU_StartMonSendOut(BtlvScu *scu, u8 slotIdx, int clientId, u8 partyIdx, int quiet);
int BTLV_SCU_IsMonSendOutDone(BtlvScu *scu);
void BTLV_SCU_TaskMonSendOut(struct TcblTask *task, void *workPtr);
void BTLV_SCU_StartHpGaugeUpdate(BtlvScu *scu, u8 slotIdx, int instant);
int BTLV_SCU_IsHpGaugeIdle(BtlvScu *scu);
void BTLV_SCU_HideMonPair(BtlvScu *scu, int slotA, int slotB);
int BTLV_SCU_ShowMonPair(BtlvScu *scu, int slotA, int slotB);
void BTLV_SCU_HideMon(BtlvScu *scu, int slotIdx);
int BTLV_SCU_ShowMon(BtlvScu *scu, int slotIdx);
void BTLV_SCU_StartPosCueEffect(struct BtlvScu *unused, int viewPos);
int BTLV_SCU_IsPosCueEffectDone(struct BtlvScu *unused, int viewPos);
void BTLV_SCU_StartMonFormChange(BtlvScu *scu, u8 slotIdx, u32 flag);
u32 BTLV_SCU_IsMonFormChangeDone(BtlvScu *scu);
void BTLV_SCU_TaskMonFormChange(struct TcblTask *task, void *workPtr);
void BTLV_SCU_StartMonGraphicSwapFrom(BtlvScu *scu, u32 destPos, u32 srcPos, u32 flag);
void BTLV_SCU_StartMonGraphicSwap(BtlvScu *scu, u32 viewPos, u32 flag);
u32 BTLV_SCU_IsMonGraphicSwapDone(BtlvScu *scu);
void BTLV_SCU_TaskMonGraphicSwap(struct TcblTask *task, void *workPtr);
void BTLV_SCU_InitMsgWinFade(BtlvScuWinSlide *fade, struct BmpWin *win);
void BTLV_SCU_StartMsgWinFadeOut(BtlvScuWinSlide *fade);
void BTLV_SCU_StartMsgWinFadeIn(BtlvScuWinSlide *fade, int keepText);
int BTLV_SCU_UpdateMsgWinFade(BtlvScuWinSlide *fade);
void BTLV_SCU_StartMsgWinFadeOutTask(BtlvScu *scu);
u32 BTLV_SCU_IsMsgWinFadeOutTaskDone(BtlvScu *scu);
void BTLV_SCU_TaskMsgWinFadeOut(struct TcblTask *task, void *workPtr);
void BTLV_SCU_InitMonSlots(BtlvScu *scu);
void BTLV_SCU_ResetMonSlots(BtlvScu *scu);
void BTLV_SCU_InitMonSlot(BtlvScuMonSlot *slot, BtlvScu *owner, u8 slotIdx);
void BTLV_SCU_ResetMonSlot(BtlvScuMonSlot *slot);
void BTLV_SCU_HideMonSlot(BtlvScuMonSlot *slot);
void BTLV_SCU_ShowMonSlot(BtlvScuMonSlot *slot);
BtlvScuPlateSide BTLV_SCU_GetNamePlateSide(struct BtlContext *ctx, u32 viewPos);
void BTLV_SCU_StartNamePlate(BtlvScu *scu, u8 viewPos, int closeLater);
int BTLV_SCU_ProcNamePlateAt(BtlvScu *scu, u32 viewPos);
void BTLV_SCU_HideNamePlateAt(BtlvScu *scu, u32 viewPos);
int BTLV_SCU_IsNamePlateHiddenAt(BtlvScu *scu, u32 viewPos);
void BTLV_SCU_RefreshNamePlateAt(BtlvScu *scu, u8 viewPos);
int BTLV_SCU_ProcNamePlateMosaicAt(BtlvScu *scu, u32 viewPos);
void BTLV_SCU_InitNamePlates(BtlvScu *scu, u32 tile);
void BTLV_SCU_FreeNamePlates(BtlvScu *scu);
void BTLV_SCU_PrepareNamePlate(BtlvScuNamePlate *plate, u8 viewPos, int closeLater);
int BTLV_SCU_ProcNamePlate(BtlvScuNamePlate *plate);
void BTLV_SCU_DrawNamePlate(BtlvScuNamePlate *plate);
void BTLV_SCU_HideNamePlate(BtlvScuNamePlate *plate);
int BTLV_SCU_IsNamePlateHidden(BtlvScuNamePlate *plate);
void BTLV_SCU_RefreshNamePlate(BtlvScuNamePlate *plate, u8 viewPos);
int BTLV_SCU_ProcNamePlateMosaic(BtlvScuNamePlate *plate);
void BTLV_SCU_GetBallStates(BtlvScu *scu, u32 *outStates, u32 clientA, u32 clientB, u32 sideFlag);
void BTLV_SCU_PrintWaitMessage(BtlvScu *scu);
int BTLV_SCU_UpdateWaitMessage(BtlvScu *scu);
void BTLV_SCU_NoOp(char *unused);
void BTLV_SCU_StartFadeIn(BtlvScu *scu);
void BTLV_SCU_ClearWaitWindow(BtlvScu *scu);
int BTLV_SCU_GetWaitState(BtlvScu *scu);
void BTLV_SCU_StartBallWindowOpen(BtlvScu *scu, void **partySource, BtlvBallStates *states);
int BTLV_SCU_UpdateBallWindowOpen(BtlvScu *scu);
void BTLV_SCU_StartBallWindowRefresh(BtlvScu *scu);
int BTLV_SCU_UpdateBallWindowRefresh(BtlvScu *scu);
void BTLV_SCU_StartBallWindowClose(BtlvScu *scu);
int BTLV_SCU_UpdateBallWindowClose(BtlvScu *scu);
int BTLV_SCU_StepBallWindowOpen(int *state, BtlvScu *scu);
int BTLV_SCU_StepBallWindowRefresh(int *state, BtlvScu *scu);
int BTLV_SCU_StepBallWindowClose(int *state, BtlvScu *scu);
/* END mkheaders: generated region */

#endif
