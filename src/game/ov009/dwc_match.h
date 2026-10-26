#ifndef GAME_OV009_DWC_MATCH_H
#define GAME_OV009_DWC_MATCH_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of dwc_match.c, prototypes copied from their definitions. */

struct qr2_implementation_s;
struct SOCSockAddrIn;
struct DWCstNNInfo;

#include "../types.h"
#include "../ov009/dwc_match_ctl_types.h"
#include "../ov009/gt2main_types.h"
#include "../ov009/sb_server_types.h"

#include "../ov009/qr2_types.h"

int DWC_CancelMatch(void);
int DWC_IsValidCancelMatch(void);
u8 DWC_AddMatchKeyInt(u8 keyID, char *keyString, int *valueSrc);
u8 DWC_AddMatchKeyString(u8 keyID, char *keyString, char *valueSrc);
int DWC_GetMatchIntValue(int index, char *key, int idefault);
int DWC_GetSuspendMatch(void);
void DWCi_MatchInit(DWCstMatchControl *matchCnt, void **pGpObj, void **pGt2Socket, void *gt2Callbacks, char *gameName, char *secretKey, u8 *friendKeyListArg, int friendKeyListLenArg);
int DWCi_QR2Startup(int profileID);
void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, MatchedCallback matchedCallback, void *matchedParam, DWCMatchedSCCallback newClientCallback, void *newClientParam, DWCEvalCallback evalCallback, void *evalParam, int (*attemptCallback)(unsigned char *, void *), unsigned char *connectionUserData, void *attemptParam);
void DWCi_SetupGameServer(int topology, u8 numEntry, MatchedCallback matchedCallback, void *matchedParam, DWCMatchedSCCallback newClientCallback, void *newClientParam, int (*attemptCallback)(unsigned char *, void *), u8 *connectionUserData, void *attemptParam);
void DWCi_ConnectToGameServerAsync(int topology, int serverPid, MatchedCallback matchedCallback, void *matchedParam, DWCMatchedSCCallback newClientCallback, void *newClientParam, int (*attemptCallback)(unsigned char *, void *), u8 *connectionUserData, void *attemptParam);
void DWCi_SendStateChanged(struct qr2_implementation_s *qr2Obj);
void DWCi_MatchProcess(int fullSpec);
int DWCi_GT2UnrecognizedMessageCallback(GTI2Socket *socket, unsigned int ip, unsigned short port, unsigned char *message, int len);
void DWCi_GT2ConnectAttemptCallback(GTI2Socket * userdata, GTI2Connection * connection, unsigned int ip, unsigned short port, int latency, unsigned char * message, int len);
void DWCi_MakeGT2ConnectString(char *buf, int bufLen);
void DWCi_GT2ConnectedCallback(void * connection, int result);
void DWCi_MatchGPRecvBuddyMsgCallback(int unused, int profileID, char *message);
void DWCi_StopResendingMatchCommand(void);
void DWCi_StopMatch(int error, int errorCode);
void DWCi_ClearQR2Key(void);
void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);
void DWCi_ProcessMatchSynPacketSub_Hybrid(unsigned char aid, unsigned short type, unsigned char *data);
void DWCi_ProcessMatchSynPacketSub(unsigned char aid, unsigned short type, unsigned char *data);
void DWCi_CheckDeadAIDBitmap(unsigned int bitmap);
void DWCi_ProcessMatchPollingPacket(const Poll *p);
int DWCi_ProcessMatchClosing(int error, int errorCode, int profileID);
void DWCi_ProcessMatchSCClosing(int clientPid);
int DWCi_GPSetServerStatus(int status);
void DWCi_ShutdownMatch(void);
int DWCi_IsShutdownMatch(void);
void DWCi_ResetMatchParam(int level);
void DWCi_SetMatchCommonParam(unsigned char matchType, unsigned char numEntry, MatchedCallback callback, void *param);
void DWCi_CloseMatch(void);
int DWCi_GetDefaultMatchFilter(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
int IsPrivateAddr(unsigned int addr_in_netorder);
int DWCi_NNStartupAsync(int isQR2, int cookie, DWCstNodeInfo * node);
int DWCi_DoNatNegotiationAsync(DWCstNNInfo *nnInfo);
int DWCi_CanSendMatchCommandDirect(unsigned char command, int pid);
int DWCi_SendMatchCommand(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
void DWCi_EncodeBinaryMsgCommand(DWCstBinaryMessage *message, unsigned char command, unsigned int *data, int len);
int DWCi_SendSBMsgCommand(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len);
int DWCi_SendGPBuddyMsgCommand(void *conn, unsigned char command, int pid, const char *data);
int DWCi_ProcessRecvMatchCommand(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len);
u8 DWCi_CheckResvCommand(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve);
unsigned char DWCi_CheckResvCommand_Sub(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, unsigned char *newClientUserData, int meshReserve);
int DWCi_ProcessResvOK(int profileID, u32 publicIP, u16 publicPort);
int DWCi_HandleMatchCommandError(int error);
int DWCi_SendResvCommand(int profileID, int delay);
int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid);
int DWCi_RetryReserving(int resendPid);
int DWCi_CancelReservation(int arg);
int DWCi_CancelPreConnectedServerProcessWithResetLevel(int clientPid, int resetLevel);
int DWCi_CancelPreConnectedServerProcess(int clientPid);
int DWCi_CancelPreConnectedClientProcess(int profileID);
void DWCi_PostProcessConnection(int type);
void DWCi_PostProcessConnectionSYNFinish(void);
void DWCi_PostProcessConnectionSYNFinishHybrid(void);
void DWCi_PostProcessConnectionSYNFinishFullmesh(void);
int DWCi_PostProcessSVConnectionHybrid(void);
int DWCi_PostProcessSVConnectionFullmesh(void);
void DWCi_FinishCancelMatch(void);
int DWCi_InvalidateReservation(void);
void DWCi_RestartFromCancel(int level);
void DWCi_RestartFromTimeout(void);
int DWCi_ResumeMatch(void);
int DWCi_CloseCancelHostAsync(int profileID);
void DWCi_CloseAllConnectionsByTimeout(void);
void DWCi_SendMatchSynPacket(u8 aid, u16 type);
int DWCi_ProcessMatchSynTimeout(void);
int DWCi_ServerSynTimeoutExec(void);
void DWCi_SendTypeMatchAck(void);
int DWCi_SendCancelMatchSynCommand(int profileID, unsigned char command);
int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data);
int DWCi_ProcessCancelMatchSynTimeout(void);
u8 DWCi_GetNewMatchKey(void);
void DWCi_ClearGameMatchKeys(void);
int DWCi_IsFriendByIdxList(int profileID);
int DWCi_CheckDWCServer(void *server);
u8 DWCi_GetAIDFromProfileID(int profileID, int idxOnly);
unsigned int DWCi_GetAIDBitmask(int valid);
void DWCi_InitClWaitTimeout(void);
int DWCi_HandleSBError(int error);
int DWCi_HandleQR2Error(int error);
int DWCi_HandleNNError(int error);
int DWCi_HandleNNResult(int result);
void DWCi_SBCallback(struct ServerBrowser *sbArg, int reason, SBServer *serverArg, void *unusedArg);
void DWCi_DebugPrintServerList(void *server);
void DWCi_RandomizeServers(void);
void DWCi_QR2ServerKeyCallback(int keyid, struct qr2_buffer_s *outbuf, void *userdata);
void DWCi_QR2PlayerKeyCallback(int keytype, int index, struct qr2_buffer_s *outbuf, void *userdata);
void DWCi_QR2TeamKeyCallback(int keytype, int index, struct qr2_buffer_s *outbuf, void *userdata);
void DWCi_QR2KeyListCallback(qr2_key_type keytype, qr2_keybuffer_s *keybuffer, void *userdata);
int DWCi_QR2CountCallback(qr2_key_type keytype, void *userdata);
void DWCi_QR2AddErrorCallback(int error, char *errmsg, void *userdata);
void DWCi_QR2PublicAddrCallback(unsigned int ip, unsigned short port, void *userdata);
void DWCi_QR2NatnegCallback(int cookie, void *userdata);
void DWCi_HandleGT2UnreliableMatchCommandMessage(void *data, int len);
void DWCi_QR2ClientMsgCallback(char *data, int len, void *userdata);
void DWCi_NNProgressCallback(int state, void *param);
void DWCi_NNCompletedCallback(int result, int unused, struct SOCSockAddrIn *remoteaddr, void *nnInfoArg);
int DWCi_ProcessNNFailure(int ignoreError);
int DWCi_SendServerDownQuery(void);
int DWCi_IsBackupMine(void);
unsigned int DWCi_CreateGroupID(void);
void DWCi_SetConnectionAttemptParam(int (*attemptCallback)(unsigned char *, void *), unsigned char *connectionUserData, void *attemptParam);
void DWCi_SetupGameServer_InterChange(int init);
void DWCi_ConnectToGameServerAsync_InterChange(int profileID);
int DWCi_GetNumConnectionHost(void);
int DWCi_SendServerPolling(int immediate);
int DWCi_StartMatch(void);
void DWCi_RequestSuspendMatchInit(int suspend, void (*callback)(int, int, void *), void *suspendResultParam);
int DWCi_RequestSuspendMatchProcess(void);
int DWCi_IsServerSuspendEnabled(void);
int DWCi_IsServerChanging(void);
void DWCi_SetMatchCnt(DWCstMatchControl *a);
DWCstMatchControl *DWCi_GetMatchCnt(void);
void DWCi_SetMatchStatus(int state);
void DWCi_SetHostStatus(int host);
int DWCi_IsServerChangeEnabled(void);
void DWCi_ResetLastSomeDataRecvTimeByAidAll(void);
void DWCi_NodeInfoList_Clear(void);
int DWCi_NodeInfoList_GetCount(void);
int DWCi_NodeInfoList_InsertToTop(DWCstNodeInfo *newNode);
int DWCi_NodeInfoList_Append(DWCstNodeInfo *newNode);
int DWCi_NodeInfoList_RemoveAID(unsigned char aid);
int DWCi_NodeInfoList_RemoveProfileID(int profileID);
DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void);
DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid);
DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
unsigned char DWCi_NodeInfoList_GetFreeAID(void);
int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
void DWCi_TempNewNodeInfo_Clear(void);
int DWCi_TempNewNodeInfo_IsValid(void);
void DWCi_NodeInfo_Clear(DWCstNodeInfo *p);
int DWCi_NodeInfo_IsValid(const DWCstNodeInfo *p);
unsigned long long DWCi_GetNextMeshMakeTryTick(void);
int DWCi_StopMeshMaking(void);
int DWCi_IsFirstServer(void);
int DWCi_IsServerLocked(void);
int DWCi_GetTopologyType(void);
void DWCi_ClearMeshMakingTempInfo(void);
void DWCi_AutoSuspendComplete(void);
void DWCi_SuspendComplete(int result);
int DWCi_IsFullMesh(void);
int DWCi_GetNodeInfoCount(void);
unsigned char DWCi_IsLockedBuddyStatus(char *buddyStatus);
char *DWCi_GetResvDenyReasonString(unsigned char denyReason);
void disp_match_state(int a, int b);
void DWCi_SetMatchmakeProfileId(int v);
void DWCi_RegisterMatchmakeKeys(void);
void DWCi_NNFreeNegotiateList(void);
/* END mkheaders: generated region */

#endif
