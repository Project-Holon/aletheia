#ifndef GAME_OV123_GSYNC_STATE_H
#define GAME_OV123_GSYNC_STATE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gsync_state.c, prototypes copied from their definitions. */

#include "../ov123/gsync_types.h"
#include "../types.h"

int GSYNC_STATE_HandleHttpError(GsyncStateWork *state,int resultCode);
int GSYNC_STATE_IsConnectionAlive(GsyncStateWork *state);
int GSYNC_STATE_IsCommIdleWithTarget(GsyncStateWork *state);
int GSYNC_STATE_IsCommReady(GsyncStateWork *state);
void GSYNC_STATE_SetNextState(GsyncStateWork *state,u32 nextState,int unused);
void GSYNC_STATE_ChangeState(GsyncStateWork *state,u32 nextState,int unused);
void GSYNC_STATE_StateWaitFade(char *state);
void GSYNC_STATE_StateFadeOutAfterMessage(char *state);
void GSYNC_STATE_StateFreeDownloadAndExit(u8 *state);
void GSYNC_STATE_StateWaitInputCancelSave(unsigned char *state);
void GSYNC_STATE_StateErrorMessage(char *state);
void GSYNC_STATE_StateSetErrorExit(char *state);
void GSYNC_STATE_StateWaitMessageInput(char *state);
void GSYNC_STATE_StateClearMessageExit(char *state);
void GSYNC_STATE_StateWaitEndingBgm(char *state);
void GSYNC_STATE_StateShowResultMessage(int state);
void GSYNC_STATE_ResetSlotActors(char *state);
void GSYNC_STATE_LoadReceivedMon(GsyncStateWork *state);
void GSYNC_STATE_StateSaveFinishMessage(char *state);
void GSYNC_STATE_StatePollResponse(char *state);
void GSYNC_STATE_StateSendRequest(char *state);
void GSYNC_STATE_StateSaveMainWait(u8 *state);
void GSYNC_STATE_StateSaveStart(int state);
void GSYNC_STATE_StateCleanupDownload(int state);
void GSYNC_STATE_StateFreeReceivedMon(u8 *state);
void GSYNC_STATE_StateExtraSaveMain(u8 *state);
void GSYNC_STATE_StateExtraSaveLoadStart(int state);
void GSYNC_STATE_StateFreeExtraSaveBuffer(u8 *state);
void GSYNC_STATE_StateExtraSaveMainSecond(char *state);
void GSYNC_STATE_StateExtraSaveLoadStartSecond(int state);
void GSYNC_STATE_StateMusicalSaveApply(u8 *state);
void GSYNC_STATE_StateMusicalSaveCreate(int state,int dataSize);
void GSYNC_STATE_StateDownloadReset(int state);
void GSYNC_STATE_StateMusicalSaveRetry(int state);
void GSYNC_STATE_StateWaitDownloadIdle(int state);
void GSYNC_STATE_StateRequestFile(int state);
void GSYNC_STATE_StateWaitDownloadIdleThenRequest(int state);
void GSYNC_STATE_StateRequestFileList(int state);
void GSYNC_STATE_StateSetFileAttribute(u8 *state);
void GSYNC_STATE_StateInitDownload(char *state);
void GSYNC_STATE_StateSelectNextDownload(char *state);
void GSYNC_STATE_CopyMonRecord(void *saveSystem, char *records);
int GSYNC_STATE_StoreListEntries(int saveSystem,u8 *listBuffer);
int GSYNC_STATE_HasListEntry(int saveSystem,GsyncConn *list);
void GSYNC_STATE_BuildMonEntry(GsyncStateWork *state, int unused, int species, int gender, int form, int entryArg, int value);
void GSYNC_STATE_BuildMonEntries(GsyncStateWork *state,int saveSystem,u8 *records);
void GSYNC_STATE_ApplyIconRecords(GsyncStateWork *state,GsyncConn *list);
void GSYNC_STATE_PrepareReceivedList(GsyncStateWork *state, void *saveSystem, GsyncConn *list, int *errorCode);
int GSYNC_STATE_UpdateCurrentEntry(GsyncStateWork *state);
void GSYNC_STATE_StateReceiveList(char *state);
void GSYNC_STATE_StateSendListRequest(char *state);
void GSYNC_STATE_StateWaitMessageThenSend(char *state);
void GSYNC_STATE_StateShowProgressMessage(char *state);
void GSYNC_STATE_StateWaitInputFirst(char *state);
void GSYNC_STATE_StateWaitMessageThenPrintSecond(char *state);
void GSYNC_STATE_StateWaitInputSecond(char *state);
void GSYNC_STATE_StateWaitMessageThenPrintThird(char *state);
void GSYNC_STATE_StateConfirmMenuSelect(char *state);
void GSYNC_STATE_StateOpenConfirmMenu(char *state);
void GSYNC_STATE_StateShowEmptyMessage(char *state);
void GSYNC_STATE_StateWaitMessageEnd(char *state);
void GSYNC_STATE_StateWaitInputClearWindow(char *state);
void GSYNC_STATE_StateWaitInputPrintNext(char *state);
void GSYNC_STATE_StatePrintErrorMessage(char *state);
void GSYNC_STATE_StateReceiveResponse(char *state);
void GSYNC_STATE_StateSendResponse(char *state);
void GSYNC_STATE_StateWaitInputThird(char *state);
void GSYNC_STATE_StateWaitMessageThenPrintFourth(char *state);
void GSYNC_STATE_StateWaitInputFourth(char *state);
void GSYNC_STATE_StateWaitMessageThenPrintFifth(char *state);
void GSYNC_STATE_ParseResponse(GsyncStateWork *work,int resultCode,int *responseCode);
void GSYNC_STATE_StateReceiveParsedResponse(char *state);
void GSYNC_STATE_StateSendParsedRequest(char *state);
void GSYNC_STATE_StateWaitMessageClearStream(char *state);
void GSYNC_STATE_StatePrintFinalMessage(char *state);
void GSYNC_STATE_StateReceiveFinalResponse(char *state);
void GSYNC_STATE_StateSendFinalRequest(char *state);
void GSYNC_STATE_StatePlaySeWaitInput(char *state);
void GSYNC_STATE_StateWaitMessageThenNext(char *state);
void GSYNC_STATE_StateShowCompletionMessage(char *state);
void GSYNC_STATE_StateSaveErrorExit(char *state);
void GSYNC_STATE_StateTrainerRecordSaveStart(char *state);
void GSYNC_STATE_StateReceiveRecordResponse(char *state);
void GSYNC_STATE_StateSendRecordRequest(char *state);
void GSYNC_STATE_StateStartTransferAnimation(char *state);
void GSYNC_STATE_StateTransferAnimationStep(char *state);
void GSYNC_STATE_StateTransferAnimationOpen(char *state);
void GSYNC_STATE_StateTransferAnimationEffect(char *state);
void GSYNC_STATE_StateCreateReceivedMonIcon(char *state);
void GSYNC_STATE_StateStoreReceivedMon(char *state);
void GSYNC_STATE_DestroyHttpConnection(char *state);
void GSYNC_STATE_CommitReceivedMon(GsyncStateWork *state);
int GSYNC_STATE_ProcInit(void *procSys,int unused,GsyncConn *connection);
int GSYNC_STATE_ProcMain(void *unused0, int unused1, int unused2, GsyncStateWork *state);
int GSYNC_STATE_ProcExit(void *procSys, int unused0, int unused1, GsyncStateWork *state);
/* END mkheaders: generated region */

#endif
