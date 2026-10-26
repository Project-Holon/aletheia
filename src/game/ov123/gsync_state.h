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
void GSYNC_STATE_SetNextState(GsyncStateWork *state,GsyncStateFunc nextState,int unused);
void GSYNC_STATE_ChangeState(GsyncStateWork *state,GsyncStateFunc nextState,int unused);
void GSYNC_STATE_StateWaitFade(GsyncStateWork *state);
void GSYNC_STATE_StateFadeOutAfterMessage(GsyncStateWork *state);
void GSYNC_STATE_StateFreeDownloadAndExit(GsyncStateWork *state);
void GSYNC_STATE_StateWaitInputCancelSave(GsyncStateWork *state);
void GSYNC_STATE_StateErrorMessage(GsyncStateWork *state);
void GSYNC_STATE_StateSetErrorExit(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageInput(GsyncStateWork *state);
void GSYNC_STATE_StateClearMessageExit(GsyncStateWork *state);
void GSYNC_STATE_StateWaitEndingBgm(GsyncStateWork *state);
void GSYNC_STATE_StateShowResultMessage(GsyncStateWork *state);
void GSYNC_STATE_ResetSlotActors(void *state, u32 frame);
void GSYNC_STATE_LoadReceivedMon(GsyncStateWork *state);
void GSYNC_STATE_StateSaveFinishMessage(GsyncStateWork *state);
void GSYNC_STATE_StatePollResponse(GsyncStateWork *state);
void GSYNC_STATE_StateSendRequest(GsyncStateWork *state);
void GSYNC_STATE_StateSaveMainWait(GsyncStateWork *state);
void GSYNC_STATE_StateSaveStart(GsyncStateWork *state);
void GSYNC_STATE_StateCleanupDownload(GsyncStateWork *state);
void GSYNC_STATE_StateFreeReceivedMon(GsyncStateWork *state);
void GSYNC_STATE_StateExtraSaveMain(GsyncStateWork *state);
void GSYNC_STATE_StateExtraSaveLoadStart(GsyncStateWork *state);
void GSYNC_STATE_StateFreeExtraSaveBuffer(GsyncStateWork *state);
void GSYNC_STATE_StateExtraSaveMainSecond(GsyncStateWork *state);
void GSYNC_STATE_StateExtraSaveLoadStartSecond(GsyncStateWork *state);
void GSYNC_STATE_StateMusicalSaveApply(GsyncStateWork *state);
void GSYNC_STATE_StateMusicalSaveCreate(GsyncStateWork *state,int dataSize);
void GSYNC_STATE_StateDownloadReset(GsyncStateWork *state);
void GSYNC_STATE_StateMusicalSaveRetry(GsyncStateWork *state);
void GSYNC_STATE_StateWaitDownloadIdle(GsyncStateWork *state);
void GSYNC_STATE_StateRequestFile(GsyncStateWork *state);
void GSYNC_STATE_StateWaitDownloadIdleThenRequest(GsyncStateWork *state);
void GSYNC_STATE_StateRequestFileList(GsyncStateWork *state);
void GSYNC_STATE_StateSetFileAttribute(GsyncStateWork *state);
void GSYNC_STATE_StateInitDownload(GsyncStateWork *state);
void GSYNC_STATE_StateSelectNextDownload(GsyncStateWork *state);
void GSYNC_STATE_CopyMonRecord(void *saveSystem, char *records);
int GSYNC_STATE_StoreListEntries(void *saveSystem,u8 *listBuffer);
int GSYNC_STATE_HasListEntry(void *saveSystem,GsyncWireList *list);
void GSYNC_STATE_BuildMonEntry(GsyncStateWork *state, void *unused, int species, int gender, int form, int entryArg, int value);
void GSYNC_STATE_BuildMonEntries(GsyncStateWork *state,void *saveSystem,u8 *records);
void GSYNC_STATE_ApplyIconRecords(GsyncStateWork *state,GsyncWireList *list);
void GSYNC_STATE_PrepareReceivedList(GsyncStateWork *state, void *saveSystem, GsyncWireList *list, int *errorCode);
int GSYNC_STATE_UpdateCurrentEntry(GsyncStateWork *state);
void GSYNC_STATE_StateReceiveList(GsyncStateWork *state);
void GSYNC_STATE_StateSendListRequest(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageThenSend(GsyncStateWork *state);
void GSYNC_STATE_StateShowProgressMessage(GsyncStateWork *state);
void GSYNC_STATE_StateWaitInputFirst(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageThenPrintSecond(GsyncStateWork *state);
void GSYNC_STATE_StateWaitInputSecond(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageThenPrintThird(GsyncStateWork *state);
void GSYNC_STATE_StateConfirmMenuSelect(GsyncStateWork *state);
void GSYNC_STATE_StateOpenConfirmMenu(GsyncStateWork *state);
void GSYNC_STATE_StateShowEmptyMessage(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageEnd(GsyncStateWork *state);
void GSYNC_STATE_StateWaitInputClearWindow(GsyncStateWork *state);
void GSYNC_STATE_StateWaitInputPrintNext(GsyncStateWork *state);
void GSYNC_STATE_StatePrintErrorMessage(GsyncStateWork *state);
void GSYNC_STATE_StateReceiveResponse(GsyncStateWork *state);
void GSYNC_STATE_StateSendResponse(GsyncStateWork *state);
void GSYNC_STATE_StateWaitInputThird(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageThenPrintFourth(GsyncStateWork *state);
void GSYNC_STATE_StateWaitInputFourth(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageThenPrintFifth(GsyncStateWork *state);
void GSYNC_STATE_ParseResponse(GsyncStateWork *work,int resultCode,int *responseCode);
void GSYNC_STATE_StateReceiveParsedResponse(GsyncStateWork *state);
void GSYNC_STATE_StateSendParsedRequest(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageClearStream(GsyncStateWork *state);
void GSYNC_STATE_StatePrintFinalMessage(GsyncStateWork *state);
void GSYNC_STATE_StateReceiveFinalResponse(GsyncStateWork *state);
void GSYNC_STATE_StateSendFinalRequest(GsyncStateWork *state);
void GSYNC_STATE_StatePlaySeWaitInput(GsyncStateWork *state);
void GSYNC_STATE_StateWaitMessageThenNext(GsyncStateWork *state);
void GSYNC_STATE_StateShowCompletionMessage(GsyncStateWork *state);
void GSYNC_STATE_StateSaveErrorExit(GsyncStateWork *state);
void GSYNC_STATE_StateTrainerRecordSaveStart(GsyncStateWork *state);
void GSYNC_STATE_StateReceiveRecordResponse(GsyncStateWork *state);
void GSYNC_STATE_StateSendRecordRequest(GsyncStateWork *state);
void GSYNC_STATE_StateStartTransferAnimation(GsyncStateWork *state);
void GSYNC_STATE_StateTransferAnimationStep(GsyncStateWork *state);
void GSYNC_STATE_StateTransferAnimationOpen(GsyncStateWork *state);
void GSYNC_STATE_StateTransferAnimationEffect(GsyncStateWork *state);
void GSYNC_STATE_StateCreateReceivedMonIcon(GsyncStateWork *state);
void GSYNC_STATE_StateStoreReceivedMon(GsyncStateWork *state);
void GSYNC_STATE_DestroyHttpConnection(void *arg, u32 errorCode, u32 errorType, int dwcError);
void GSYNC_STATE_CommitReceivedMon(GsyncStateWork *state);
int GSYNC_STATE_ProcInit(void *procSys,int unused,GsyncConn *connection);
int GSYNC_STATE_ProcMain(void *unused0, int unused1, int unused2, GsyncStateWork *state);
int GSYNC_STATE_ProcExit(void *procSys, int unused0, int unused1, GsyncStateWork *state);
/* END mkheaders: generated region */

#endif
