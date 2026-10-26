#ifndef GAME_OV137_GURU2_RECEIPT_H
#define GAME_OV137_GURU2_RECEIPT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of guru2_receipt.c, prototypes copied from their definitions. */

struct Guru2Session;
struct Guru2Lobby;
struct NNSG2dPaletteData;

#include "../types.h"

struct TcbTask;

struct UnionAppEntry;

int GURU2_RECEIPT_ProcInit(void *proc,u32 *state,struct Guru2Session *ctx);
void *GURU2_RECEIPT_GetUnionApp(struct Guru2Lobby *p);
void GURU2_RECEIPT_SendMemberCount(int memberCount, struct UnionAppEntry *unused, void *pArg);
void GURU2_RECEIPT_UnionAppNoop(int netId, struct UnionAppEntry *entry, void *arg);
int GURU2_RECEIPT_ProcMain(int proc,int seq,int parentWork,struct Guru2Lobby *p);
int GURU2_RECEIPT_ProcExit(void *proc,int seq,void *parentWork,struct Guru2Lobby *p);
void GURU2_RECEIPT_AnimatePalette(void *unused, struct Guru2Lobby *p);
void GURU2_RECEIPT_VBlank(struct TcbTask *task, void *work);
void GURU2_RECEIPT_UpdateQueues(struct Guru2Lobby *p);
void GURU2_RECEIPT_SetVramBanks(void);
void GURU2_RECEIPT_InitBg(void);
void GURU2_RECEIPT_InitStrings(struct Guru2Lobby *p,void *arc);
void GURU2_RECEIPT_FreeStrings(struct Guru2Lobby *p);
void GURU2_RECEIPT_ExitBg(void);
void GURU2_RECEIPT_LoadGraphics(struct Guru2Lobby *p,void *arc);
void GURU2_RECEIPT_InitActors(struct Guru2Lobby *p);
void GURU2_RECEIPT_FreeActors(struct Guru2Lobby *p);
void GURU2_RECEIPT_CreatePlayerActors(struct Guru2Lobby *p);
void GURU2_RECEIPT_CreateWindows(struct Guru2Lobby *p);
void GURU2_RECEIPT_PrintTitle(void *p, void *text, void *font);
void GURU2_RECEIPT_DeleteWindows(struct Guru2Lobby *p);
int GURU2_RECEIPT_StateInit(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateIdleStart(struct Guru2Lobby *p,int state);
void GURU2_RECEIPT_HandleKeys(struct Guru2Lobby *p);
void GURU2_RECEIPT_Noop(struct Guru2Lobby *p);
int GURU2_RECEIPT_StateGoToMessage(struct Guru2Lobby *p,int state);
void GURU2_RECEIPT_SetPendingState(struct Guru2Lobby *p, int nextState);
int GURU2_RECEIPT_StateWaitMessage(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateReopenRecruit(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateOpenStartMenu(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateStartMenu(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateResetWait(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateWaitAnswers(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateAnswersDone(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateOpenCancelMenu(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateCancelMenu(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateSendStartRequest(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateWaitStartReady(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateShowStartMessage(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateWaitEndWipe(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateOpenQuitMenu(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateQuitMenu(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateShowQuitMessage(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateQuitDelay(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateSetSyncToken(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateCheckSyncToken(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateWaitMessageToError(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateWaitMessageToStart(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateShowTimeoutMessage(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateArmTimeout(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateTimeout(struct Guru2Lobby *p, int state);
int GURU2_RECEIPT_StateEndSession(struct Guru2Lobby *p);
void GURU2_RECEIPT_SetStateFromParent(struct Guru2Lobby *p,int state,int player);
void GURU2_RECEIPT_SetStateFromChild(struct Guru2Lobby *p, int command, int player);
int GURU2_RECEIPT_CountMembers(struct Guru2Lobby *p);
int GURU2_RECEIPT_PrintMemberList(void *window,int unused,u16 color,struct Guru2Lobby *p);
void GURU2_RECEIPT_Noop2(struct Guru2Lobby *unused);
int GURU2_RECEIPT_GetMemberCount(struct Guru2Lobby *p);
unsigned GURU2_RECEIPT_GetJoinedBits(struct Guru2Lobby *p);
int GURU2_RECEIPT_UpdateMemberSlots(struct Guru2Lobby *p);
void GURU2_RECEIPT_PrintMessage(struct Guru2Lobby *p, int message, int unused);
int GURU2_RECEIPT_IsMessageDone(struct Guru2Lobby *p);
void GURU2_RECEIPT_ClearMessageFrame(struct Guru2Lobby *p);
void GURU2_RECEIPT_UpdatePlayerActors(struct Guru2Lobby *p);
void GURU2_RECEIPT_LoadCharBuffer(struct Guru2Lobby *p, void *unused);
void GURU2_RECEIPT_FreeCharBuffer(struct Guru2Lobby *p);
void GURU2_RECEIPT_SetPlayerIcon(struct Guru2Lobby *p, struct NNSG2dPaletteData *paletteData, int member, int outfit, int unused);
int GURU2_RECEIPT_UpdateMemberChange(struct Guru2Lobby *obj, int unused);
u32 GURU2_RECEIPT_GetKeyTrg(void);
/* END mkheaders: generated region */

#endif
