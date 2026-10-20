#ifndef GAME_OV137_GURU2_RECEIPT_H
#define GAME_OV137_GURU2_RECEIPT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of guru2_receipt.c, prototypes copied from their definitions. */

struct Guru2Lobby;

#include "../types.h"
#include "../ov137/guru2_receipt_shared_types.h"

int GURU2_RECEIPT_ProcInit(void *proc,u32 *state,u8 *ctx);
void *GURU2_RECEIPT_GetUnionApp(u8 *p);
void GURU2_RECEIPT_SendMemberCount(int memberCount,int unused,struct Guru2Lobby *p);
void GURU2_RECEIPT_UnionAppNoop(void);
int GURU2_RECEIPT_ProcMain(int proc,int seq,int parentWork,u8 *p);
int GURU2_RECEIPT_ProcExit(void *proc,int seq,void *parentWork,u8 *p);
void GURU2_RECEIPT_AnimatePalette(void *unused, u8 *p);
void GURU2_RECEIPT_VBlank(void *task, void *work);
void GURU2_RECEIPT_UpdateQueues(u8 *p);
void GURU2_RECEIPT_SetVramBanks(void);
void GURU2_RECEIPT_InitBg(void);
void GURU2_RECEIPT_InitStrings(u8 *p,void *arc);
void GURU2_RECEIPT_FreeStrings(u8 *p);
void GURU2_RECEIPT_ExitBg(void);
void GURU2_RECEIPT_LoadGraphics(void *p,void *arc);
void GURU2_RECEIPT_InitActors(const u8 *p);
void GURU2_RECEIPT_FreeActors(u8 *p);
void GURU2_RECEIPT_CreatePlayerActors(u8 *p);
void GURU2_RECEIPT_CreateWindows(struct Guru2Lobby *p);
void GURU2_RECEIPT_PrintTitle(void *p, void *text, void *font);
void GURU2_RECEIPT_DeleteWindows(u8 *p);
int GURU2_RECEIPT_StateInit(char *p, int state);
int GURU2_RECEIPT_StateIdleStart(char *p,int state);
void GURU2_RECEIPT_HandleKeys(char *p);
void GURU2_RECEIPT_Noop(char *p);
int GURU2_RECEIPT_StateGoToMessage(char *p,int state);
void GURU2_RECEIPT_SetPendingState(char *p, int nextState);
int GURU2_RECEIPT_StateWaitMessage(char *p,int state);
int GURU2_RECEIPT_StateReopenRecruit(char *p,int state);
int GURU2_RECEIPT_StateOpenStartMenu(char *p,int state);
int GURU2_RECEIPT_StateStartMenu(char *p,int state);
int GURU2_RECEIPT_StateResetWait(char *p,int state);
int GURU2_RECEIPT_StateWaitAnswers(char *p, int state);
int GURU2_RECEIPT_StateAnswersDone(char *p,int state);
int GURU2_RECEIPT_StateOpenCancelMenu(char *p,int state);
int GURU2_RECEIPT_StateCancelMenu(char *p, int state);
int GURU2_RECEIPT_StateSendStartRequest(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateWaitStartReady(struct Guru2Lobby *p,int state);
int GURU2_RECEIPT_StateShowStartMessage(char *p,int state);
int GURU2_RECEIPT_StateWaitEndWipe(char *p,int state);
int GURU2_RECEIPT_StateOpenQuitMenu(char *p,int state);
int GURU2_RECEIPT_StateQuitMenu(char *p, int state);
int GURU2_RECEIPT_StateShowQuitMessage(char *p, int state);
int GURU2_RECEIPT_StateQuitDelay(char *p,int state);
int GURU2_RECEIPT_StateSetSyncToken(char *p, int state);
int GURU2_RECEIPT_StateCheckSyncToken(char *p, int state);
int GURU2_RECEIPT_StateWaitMessageToError(char *p,int state);
int GURU2_RECEIPT_StateWaitMessageToStart(char *p,int state);
int GURU2_RECEIPT_StateShowTimeoutMessage(char *p, int state);
int GURU2_RECEIPT_StateArmTimeout(char *p,int state);
int GURU2_RECEIPT_StateTimeout(char *p, int state);
int GURU2_RECEIPT_StateEndSession(char *p);
void GURU2_RECEIPT_SetStateFromParent(char *p,int state,int player);
void GURU2_RECEIPT_SetStateFromChild(struct Guru2Lobby *p, int command, int player);
int GURU2_RECEIPT_CountMembers(void *p);
void GURU2_RECEIPT_Noop2(char *unused);
int GURU2_RECEIPT_GetMemberCount(void *p);
unsigned GURU2_RECEIPT_GetJoinedBits(void *p);
int GURU2_RECEIPT_UpdateMemberSlots(char *p);
void GURU2_RECEIPT_PrintMessage(char *p, int message, int unused);
int GURU2_RECEIPT_IsMessageDone(char *p);
void GURU2_RECEIPT_ClearMessageFrame(u8 *p);
void GURU2_RECEIPT_UpdatePlayerActors(u8 *p);
void GURU2_RECEIPT_LoadCharBuffer(char *p, void *unused);
void GURU2_RECEIPT_FreeCharBuffer(u8 *p);
void GURU2_RECEIPT_SetPlayerIcon(u8 *p, u8 *paletteData, int member, int outfit, int unused);
int GURU2_RECEIPT_UpdateMemberChange(FrameObj *obj, int unused);
u32 GURU2_RECEIPT_GetKeyTrg(void);
/* END mkheaders: generated region */

#endif
