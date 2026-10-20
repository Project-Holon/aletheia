#ifndef GAME_OV009_DWC_RAP_H
#define GAME_OV009_DWC_RAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_rap.c, prototypes copied from their definitions. */

#include "../types.h"

void DWC_RAP_SetState(int state);
int DWC_RAP_IsWorkAllocated(void);
int DWC_RAP_CreateWork(int userData, int friendList);
void DWC_RAP_DestroyWork(void);
int DWC_RAP_StepLogin(void);
void DWC_RAP_SetRecvCallbacks(int serverFunc, int clientFunc);
void DWC_RAP_SetAcceptFriendCallback(void (*acceptFunc)(void));
void DWC_RAP_OnNewClientNop(void);
u8 DWC_RAP_AttemptCallback(void);
int DWC_RAP_StartMatchWithKey(void *matchValue, int maxPlayers, int useFilter, int unused);
int DWC_RAP_StartMatchWithFilter(int filter, int maxPlayers, int evalFunc, int evalParam);
void DWC_RAP_EndCancel(void);
int DWC_RAP_RunStateMachine(int cancelRequest);
int DWC_RAP_SendPacket(void *data, int size, int packetType);
int DWC_RAP_SendAck(int data, int size);
int DWC_RAP_SendMessage(int data, int size);
void DWC_RAP_SendPendingAck(void);
void DWC_RAP_OnLogin(int error);
void DWC_RAP_OnReceiveTimeout(unsigned int aid);
void DWC_RAP_OnUpdateServers(int error);
void DWC_RAP_OnFriendStatusNop(void);
void DWC_RAP_OnFriendDeleted(int deletedIndex, int srcIndex);
void DWC_RAP_OnBuddyFriendNop(void);
void DWC_RAP_ClearPeerCounters(void);
void DWC_RAP_SetupRecvTimeouts(void);
void DWC_RAP_EnterConnected(int peerIndex);
void DWC_RAP_OnMatched(int error, int cancel, int self, int isServer, int peerIndex);
int DWC_RAP_EvalCallbackAccept(void);
void DWC_RAP_OnSendComplete(int size, u32 aid);
void DWC_RAP_UpdatePeerVchatFlag(unsigned int header);
void DWC_RAP_OnReceive(u32 aid, u8 *data, int size);
void DWC_RAP_OnConnectionClosed(int error, int isLocal, int isServer, u32 aid);
int DWC_RAP_HandleError(void);
int DWC_RAP_CanSendToAllPeers(void);
int DWC_RAP_SendHeartbeat(u32 counterIndex);
int DWC_RAP_StepSession(void);
int DWC_RAP_GetMyAidIfConnected(void);
void DWC_RAP_OnVchatStopped(void);
void DWC_RAP_EnableLocalVchat(void);
void DWC_RAP_StartVchat(void *heapId);
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
int DWC_RAP_GetFriendStatusData(int friendIndex);
unsigned char DWC_RAP_GetFriendStatus(int friendIndex);
int DWC_RAP_StartFriendMatch(int friendIndex, int maxPlayers, int limitToTwo);
int DWC_RAP_GetTargetFriendIndex(void);
void DWC_RAP_OnFriendServerMatched(int error, int cancel, int self, int isServer, int peerIndex);
void DWC_RAP_OnFriendClientMatched(int error, int cancel, int self, int isServer, int peerIndex);
void DWC_RAP_OnNewClient(int aid);
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
void DWC_RAP_SetErrorCallback(int (*errorFunc)(u32, u32, u32, int), u32 errorArg);
void DWC_RAP_SetErrorHookCallback(int (*hookFunc)(u32, u32, u32, int), u32 hookArg);
/* END mkheaders: generated region */

#endif
