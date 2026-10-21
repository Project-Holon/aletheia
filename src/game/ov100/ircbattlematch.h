#ifndef GAME_OV100_IRCBATTLEMATCH_H
#define GAME_OV100_IRCBATTLEMATCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ircbattlematch.c, prototypes copied from their definitions. */

struct IrcBattleMatchWork;
struct TcbTask;
struct MessageRef;
struct Proc;
struct IrcBattleMatchParam;
typedef struct IrcBattleMatchWork IrcBattleMatchWork;
typedef struct MessageRef MessageRef;
typedef struct IrcBattleMatchParam IrcBattleMatchParam;

#include "../types.h"

char *IRCBATTLEMATCH_GetRecvBuffer(void);
int IRCBATTLEMATCH_GetRecvSize(void);
int IRCBATTLEMATCH_IsEqual(int a, int b);
int IRCBATTLEMATCH_AbortSession(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWipeEnd(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_BlendBgPalette(IrcBattleMatchWork *work, int bgSlot, int paletteCount);
void IRCBATTLEMATCH_SetPaletteFade(IrcBattleMatchWork *work,int enable);
void IRCBATTLEMATCH_StartExitWipe(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_LoadActorResources(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_CreateActor(IrcBattleMatchWork *work,int x,int y,int slot,int animSeq);
void IRCBATTLEMATCH_NudgeActor(IrcBattleMatchWork *work,int dx,int dy,int slot);
void IRCBATTLEMATCH_MoveActor(IrcBattleMatchWork *work,int x,int y,int slot);
void IRCBATTLEMATCH_SetPlayerReady(IrcBattleMatchWork *work,int aid);
void IRCBATTLEMATCH_OnChangeoverConnected(void *userArg);
void IRCBATTLEMATCH_RecvModeHandler(unsigned aid,int size,int *data,IrcBattleMatchWork *work,void *handle);
void IRCBATTLEMATCH_RecvMyStatusHandler(int aid,int size,void *data,IrcBattleMatchWork *work,void *handle);
void IRCBATTLEMATCH_NoOp(void);
struct Party *IRCBATTLEMATCH_GetParty(int index,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_RecvTrainerInfoHandler(int aid,int size,void *data,IrcBattleMatchWork *work,void *handle);
void IRCBATTLEMATCH_RecvMacAddressHandler(int aid,int size,void *data,IrcBattleMatchWork *work,void *handle);
void IRCBATTLEMATCH_RecvPlayerSlotsHandler(int aid,int size,void *data,IrcBattleMatchWork *work,void *handle);
void IRCBATTLEMATCH_StepWaitTouchThenExit(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitTimeout(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitFinalSync(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepShowStartMessage(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_GetSharedBattleReadyCount(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepApplyPartyRules(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendRegulation(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendPlayerSlots(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendMacAddress(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendTrainerInfo(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendMyStatus(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepCompareModes(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepResumeWaiting(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitQuitChoice(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenQuitConfirm(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendMode(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepRegisterCommands(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_CollectMacAddresses(void *userArg);
void IRCBATTLEMATCH_OnChangeoverResult(void *userArg,int role);
void IRCBATTLEMATCH_SetupDisplay(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_VBlankTask(struct TcbTask *tcb,void *work);
void IRCBATTLEMATCH_OpenQuitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_OpenWaitMenu(IrcBattleMatchWork *work,int twoItems);
void IRCBATTLEMATCH_PrintMainMessage(MessageRef *message,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_PrintPlayerMessage(int msgId,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_PrintRetryMessage(int msgId,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_FreeMessageWindows(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_InitWindowSystem(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_ExitWindowSystem(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_DeleteActor(IrcBattleMatchWork *work,unsigned slot);
void IRCBATTLEMATCH_PrintWaitingMessage(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_InitScreen(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitFadeIn(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_IsCompatibleGameKind(int a,int b);
void IRCBATTLEMATCH_StepStartSession(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_ExitScreen(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepStartChangeover(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepRedrawWaitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitQuitChoiceDuringWait(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitErrorDialogClose(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitWirelessStep(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenWirelessWaitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepRestoreWaitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitCancelChoice(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitTouchThenCancel(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenQuitConfirmDuringWait(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenCancelConfirm(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepCountdownThenExit(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepShowErrorMessage(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitErrorChoice(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenErrorConfirm(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_IconAnimLeft(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_IconAnimRight(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepShowDisconnectMessage(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepAnimateIcons(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitSession(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_ProcInit(struct Proc *proc, int seq, IrcBattleMatchParam *param);
u32 IRCBATTLEMATCH_ProcMain(u32 a, u32 b, u32 c, IrcBattleMatchWork *work);
int IRCBATTLEMATCH_ProcExit(struct Proc *proc, int b, int c, IrcBattleMatchWork *work);
/* END mkheaders: generated region */

#endif
