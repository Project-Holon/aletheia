#ifndef GAME_OV009_DWC_RAP_H
#define GAME_OV009_DWC_RAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_rap.c, prototypes copied from their definitions. */

#include "../ov009/dwc_rap_types.h"
#include "../ov009/dwc_rap_types.h"
#include "../types.h"

void DWC_RAP_SetState(int state);
int DWC_RAP_IsWorkAllocated(void);
int DWC_RAP_CreateWork(void *userData, void *friendList);
void DWC_RAP_DestroyWork(void);
int DWC_RAP_StepLogin(void);
void DWC_RAP_SetRecvCallbacks(DwcRapRecvFunc serverFunc, DwcRapRecvFunc clientFunc);
void DWC_RAP_SetAcceptFriendCallback(int (*acceptFunc)(int, void *));
void DWC_RAP_OnNewClientNop(int index, void *param);
int DWC_RAP_AttemptCallback(unsigned char *userData, void *param);
int DWC_RAP_StartMatchWithKey(void *matchValue, int maxPlayers, int useFilter, int unused);
int DWC_RAP_StartMatchWithFilter(char *filter, int maxPlayers, DWCEvalCallback evalFunc, void *evalParam);
void DWC_RAP_EndCancel(void);
int DWC_RAP_RunStateMachine(int cancelRequest);
int DWC_RAP_SendPacket(void *data, int size, int packetType);
int DWC_RAP_SendAck(void *data, int size);
int DWC_RAP_SendMessage(void *data, int size);
void DWC_RAP_SendPendingAck(void);
void DWC_RAP_OnLogin(int error, int unused, void *param);
void DWC_RAP_OnReceiveTimeout(unsigned char aid, void * unused1);
void DWC_RAP_OnUpdateServers(int error);
void DWC_RAP_OnFriendStatusNop(void);
void DWC_RAP_OnFriendDeleted(int deletedIndex, int srcIndex);
void DWC_RAP_OnBuddyFriendNop(int unused0, void * unused1);
void DWC_RAP_ClearPeerCounters(void);
void DWC_RAP_SetupRecvTimeouts(void);
void DWC_RAP_EnterConnected(int peerIndex);
void DWC_RAP_OnMatched(int error, int cancel, int self, int isServer, int peerIndex, void *param);
int DWC_RAP_EvalCallbackAccept(int index, void *param);
void DWC_RAP_OnSendComplete(int size, unsigned char aid, void * unused2);
void DWC_RAP_UpdatePeerVchatFlag(unsigned int header);
void DWC_RAP_OnReceive(unsigned char aid, unsigned char * dataArg, int size, void * unused3);
void DWC_RAP_OnConnectionClosed(int error, int isLocal, int isServer, int aid, int index, void *param);
int DWC_RAP_HandleError(void);
int DWC_RAP_CanSendToAllPeers(void);
int DWC_RAP_SendHeartbeat(u32 counterIndex);
int DWC_RAP_StepSession(void);
int DWC_RAP_GetMyAidIfConnected(void);
void DWC_RAP_OnVchatStopped(void);
void DWC_RAP_EnableLocalVchat(void);
void DWC_RAP_StartVchat(int heapId);
void DWC_RAP_StartVchatDefaultHeap(int unused);
void DWC_RAP_StopVchat(void);
int DWC_RAP_IsVchatActive(void);
void DWC_RAP_CleanupVchat(void);
void DWC_RAP_SetVchatTalkLock(int lock);
int DWC_RAP_GetErrorMessageClass(int errorCode, int errorType);
int DWC_RAP_ProgressDisconnect(int pollOnly);
int DWC_RAP_ResetToIdle(void);
void DWC_RAP_Shutdown(void);
void DWC_RAP_PollFriendStatus(void);
int DWC_RAP_SetOwnStatus(char *data, int size);
u8 *DWC_RAP_GetFriendStatusData(int friendIndex);
unsigned char DWC_RAP_GetFriendStatus(int friendIndex);
int DWC_RAP_StartFriendMatch(int friendIndex, int maxPlayers, int limitToTwo);
int DWC_RAP_GetTargetFriendIndex(void);
void DWC_RAP_OnFriendServerMatched(int error, int cancel, int self, int isServer, int peerIndex, void *param);
void DWC_RAP_OnFriendClientMatched(int error, int cancel, int self, int isServer, int peerIndex, void * unused5);
void DWC_RAP_OnNewClient(int aid, void * unused1);
int DWC_RAP_GetVchatState(char *unused);
s16 DWC_RAP_GetVchatEnabled(void);
int DWC_RAP_GetNewClientAid(void);
int DWC_RAP_GetCanceledPeerIndex(void);
void DWC_RAP_SetVchatEnabled(int enabled);
void DWC_RAP_FreeRecvBuffer(u32 aid);
void DWC_RAP_AllocRecvBuffer(u32 aid);
void DWC_RAP_FreeRecvBuffers(void);
unsigned char DWC_RAP_IsUserDataChanged(void);
void DWC_RAP_ClearUserDataChanged(int unused);
int DWC_RAP_IsStateIdle(void);
int DWC_RAP_IsStateInSession(void);
void DWC_RAP_FlushDeletedFriends(void);
u32 DWC_RAP_GetResult(void);
void DWC_RAP_StoreAllowConnect(u32 allowed);
int DWC_RAP_IsDisconnected(void);
void DWC_RAP_StoreErrorOnDisconnect(u32 enabled);
void DWC_RAP_SetErrorCallback(DwcRapErrorFunc errorFunc, void *errorArg);
void DWC_RAP_SetErrorHookCallback(DwcRapErrorHookFunc hookFunc, void *hookArg);
/* END mkheaders: generated region */

#endif
