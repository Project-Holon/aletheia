/*
 * file:     dwc_rap.c
 * unit:     yes
 * function: DWC_RAP_SetState, DWC_RAP_IsWorkAllocated, DWC_RAP_CreateWork, DWC_RAP_DestroyWork, DWC_RAP_StepLogin, DWC_RAP_SetRecvCallbacks, DWC_RAP_SetAcceptFriendCallback, DWC_RAP_OnNewClientNop, DWC_RAP_AttemptCallback, DWC_RAP_StartMatchWithKey, DWC_RAP_StartMatchWithFilter, DWC_RAP_EndCancel, DWC_RAP_RunStateMachine, DWC_RAP_SendPacket, DWC_RAP_SendAck, DWC_RAP_SendMessage, DWC_RAP_SendPendingAck, DWC_RAP_OnLogin, DWC_RAP_OnReceiveTimeout, DWC_RAP_OnUpdateServers, DWC_RAP_OnFriendStatusNop, DWC_RAP_OnFriendDeleted, DWC_RAP_OnBuddyFriendNop, DWC_RAP_ClearPeerCounters, DWC_RAP_SetupRecvTimeouts, DWC_RAP_EnterConnected, DWC_RAP_OnMatched, DWC_RAP_EvalCallbackAccept, DWC_RAP_OnSendComplete, DWC_RAP_UpdatePeerVchatFlag, DWC_RAP_OnReceive, DWC_RAP_OnConnectionClosed, DWC_RAP_HandleError, DWC_RAP_CanSendToAllPeers, DWC_RAP_SendHeartbeat, DWC_RAP_StepSession, DWC_RAP_GetMyAidIfConnected, DWC_RAP_OnVchatStopped, DWC_RAP_EnableLocalVchat, DWC_RAP_StartVchat, DWC_RAP_StartVchatDefaultHeap, DWC_RAP_StopVchat, DWC_RAP_IsVchatActive, DWC_RAP_CleanupVchat, DWC_RAP_SetVchatTalkLock, DWC_RAP_GetErrorMessageClass, DWC_RAP_ProgressDisconnect, DWC_RAP_ResetToIdle, DWC_RAP_Shutdown, DWC_RAP_PollFriendStatus, DWC_RAP_SetOwnStatus, DWC_RAP_GetFriendStatusData, DWC_RAP_GetFriendStatus, DWC_RAP_StartFriendMatch, DWC_RAP_GetTargetFriendIndex, DWC_RAP_OnFriendServerMatched, DWC_RAP_OnFriendClientMatched, DWC_RAP_OnNewClient, DWC_RAP_GetVchatState, DWC_RAP_GetVchatEnabled, DWC_RAP_GetNewClientAid, DWC_RAP_GetCanceledPeerIndex, DWC_RAP_SetVchatEnabled, DWC_RAP_FreeRecvBuffer, DWC_RAP_AllocRecvBuffer, DWC_RAP_FreeRecvBuffers, DWC_RAP_IsUserDataChanged, DWC_RAP_ClearUserDataChanged, DWC_RAP_IsStateIdle, DWC_RAP_IsStateInSession, DWC_RAP_FlushDeletedFriends, DWC_RAP_GetResult, DWC_RAP_StoreAllowConnect, DWC_RAP_IsDisconnected, DWC_RAP_StoreErrorOnDisconnect, DWC_RAP_SetErrorCallback, DWC_RAP_SetErrorHookCallback
 * address:  0x02155374
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from dwc_rap.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   DWC_GetAIDBitmap 0x0216B908 arm ov009
 *   DWC_GetLastErrorEx  0x02059E38  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm
 *   GFL_NET_STATE_GetError  0x0203CA98  arm
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   _sAssertEmpty     0x021A1C5C  data  ov009  a1
 *   _sDwcRapFile     0x021A1C60  data  ov009  a1
 *   GFL_NET_AllocAligned  0x0203D7C8  arm
 *   GF_PANIC_Fail  0x02034714  arm
 *   DWC_CheckHasProfile  0x020597C8  arm
 *   DWC_CheckValidConsole  0x02059760  arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   DWC_ClearError 0x02059F18 arm
 *   _pRapWorkAddr 0x021A8264  data  ov009  a4
 *   _sGameName     0x021A1C6C  data  ov009  a1
 *   DWC_InitInetEx  0x0205C6AC  arm
 *   DWC_ConnectInetAsync  0x0205C758  arm
 *   DWC_CheckInet  0x0205C88C  arm
 *   DWC_GetInetStatus  0x0205CA20  arm
 *   DWC_ProcessInet  0x0205C8E0  arm
 *   DWC_InitFriendsMatch  0x0216AB20  arm
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   DWC_LoginAsync  0x0216B0E0  arm
 *   DWC_ProcessFriendsMatch  0x0216AE88  arm
 *   DWC_UpdateServersAsync  0x0216B1E0  arm
 *   DWC_SetBuddyFriendCallback  0x02168994  arm
 *   _sMatchKey     0x021A1C74  data  ov009  a1
 *   _sMatchFilterFormat     0x021A1974  data  ov009  a1
 *   DWC_AddMatchKeyString  0x0216CA04  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   sprintf  0x02094530  arm
 *   GF_STANDARD_GetStringLength  0x0203F004  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   DWC_ConnectToAnybodyAsync  0x0216B284  arm
 *   DWC_SetUserSendCallback  0x02177138  arm
 *   DWC_SetUserRecvCallback  0x02177160  arm
 *   DWC_SetConnectionClosedCallback  0x0216B634  arm
 *   DWC_SetUserRecvTimeoutCallback  0x02177188  arm
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   DWC_SendReliableBitmap  0x02176FD4  arm
 *   DWC_GetMyAID  0x0216B838  arm
 *   DWC_CheckDirtyFlag  0x0205984C  arm
 *   DWC_ClearDirtyFlag  0x02059870  arm
 *   DWC_SetRecvTimeoutTime  0x02177270  arm
 *   VCT_MAIN_HandlePacket  0x021AEF44  thumb  ov013
 *   DWC_GetNumConnectionHost  0x0216B804  arm  ov009
 *   GFL_NET_HANDLE_RemoveHandle  0x0203A338  arm
 *   DWC_CleanupInet  0x0205CC20  arm
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   DWC_ShutdownFriendsMatch  0x0216AD50  arm  ov009
 *   DWC_NdCleanupAsync  0x021C5B80  arm  ov114
 *   DWC_GdbShutdown  0x021E1340  arm
 *   DWC_IsValidAID  0x0216B94C  arm  ov009
 *   DWC_IsSendableReliable  0x02176DEC  arm  ov009
 *   VCT_MAIN_Update  0x021AEE14  thumb  ov013
 *   VCT_MAIN_ConnectPeers  0x021AF238  thumb  ov013
 *   VCT_MAIN_Start  0x021AEF6C  thumb  ov013
 *   VCT_MAIN_SetExitCallback  0x021AF18C  thumb  ov013
 *   VCT_MAIN_HangUp  0x021AF13C  thumb  ov013
 *   VCT_MAIN_Exit 0x021AF1A0 thumb ov013
 *   VCT_MAIN_DisconnectPeers 0x021AF2AC thumb ov013
 *   VCT_MAIN_SetMuted 0x021AF30C thumb ov013
 *   DWC_IsBuddyFriendData  0x0205912C  arm
 *   DWC_GetFriendStatusData  0x02168848  arm  ov009
 *   DWC_SetOwnStatusData 0x021688FC arm ov009
 *   DWC_SetupGameServer  0x0216B354  arm  ov009
 *   DWC_ConnectToGameServerAsync  0x0216B408  arm  ov009
 *   DWC_CloseConnectionHardFromServer  0x0216B7E0  arm  ov009
 *   VCT_MAIN_GetVoiceLevel 0x021AF210 thumb ov013
 *   DWC_SetRecvBuffer  0x021770EC  arm  ov009
 */
#include "dwc_rap_types.h"
#include "net_devwifi_shared_types.h"
#include "dwc_rap_shared_types.h"

struct OSOwnerInfo;

typedef void (*VoidFunc)(void);

typedef struct {
    u8 language, favoriteColor, month, day;
    u16 nickName[11], nickNameLength, comment[27], commentLength;
} OSOwnerInfo;

extern int DWC_GetAIDBitmap(void);

int DWC_GetLastErrorEx(int *errorCode, int *errorType);

void GFL_NET_STATE_SetError(int errorCode, u32 errorType, u32 dwcError, u32 gameCode);

u32 GFL_NET_STATE_GetError(void);

void *GFL_NET_AllocAligned(u32 heap, u32 size, const char *file, u16 line);

void GF_PANIC_Fail(const char *expr, u32 line, const char *file);

int DWC_CheckHasProfile(struct DWCstAccUserData *userdata);

int DWC_CheckValidConsole(struct DWCstAccUserData *userdata);

extern void GFL_NET_FreeAligned(void *);

extern void DWC_ClearError(void);

void DWC_InitInetEx(void *inetControl, u16 dmaNo, u16 powerMode, u16 priority);

void DWC_ConnectInetAsync(void);

int DWC_CheckInet(void);

int DWC_GetInetStatus(void);

void DWC_ProcessInet(void);

void DWC_InitFriendsMatch(struct DWCstAccUserData *userdata, int productID, char *secretKey, int sendBufSize, int recvBufSize, void *friendList, int friendListLen);

void OS_GetOwnerInfo(struct OSOwnerInfo *info);

int DWC_LoginAsync(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);

void DWC_ProcessFriendsMatch(void);

int DWC_UpdateServersAsync(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);

int DWC_SetBuddyFriendCallback(void (*callback)(int, void *), void *param);

u8 DWC_AddMatchKeyString(u8 keyID, char *keyString, char *valueSrc);

void MI_CpuFill8(void *dst, int value, int size);

u32 sprintf(char *dst, char *fmt, ...);

u32 GF_STANDARD_GetStringLength(const u8 *str);

u32 GFL_NET_GetUserArg(void);

int DWC_ConnectToAnybodyAsync(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);

int DWC_SetUserSendCallback(int callback, int param);

int DWC_SetUserRecvCallback(int callback, int param);

int DWC_SetConnectionClosedCallback(int callback, int param);

int DWC_SetUserRecvTimeoutCallback(int callback, int param);

int DWC_CloseAllConnectionsHard(void);

void MI_CpuCopy8(void *src, void *dst, int size);

unsigned long DWC_SendReliableBitmap(unsigned long bitmap, void *buffer, int size);

unsigned char DWC_GetMyAID(void);

int DWC_CheckDirtyFlag(void *userdata);

void DWC_ClearDirtyFlag(struct DWCstAccUserData *userdata);

int DWC_SetRecvTimeoutTime(u8 aid, u32 time);

int VCT_MAIN_HandlePacket(int aid, u8 *data, int size);

extern int DWC_GetNumConnectionHost(void);

extern void GFL_NET_HANDLE_RemoveHandle(u32);

extern void DWC_CleanupInet(void);

extern u32 GPOWER_GetSpecialPowerId(void);

extern void DWC_ShutdownFriendsMatch(void);

extern int DWC_NdCleanupAsync(void);

extern int DWC_GdbShutdown(void);

extern int DWC_IsValidAID(u8);

extern int DWC_IsSendableReliable(u8 a);

void VCT_MAIN_Update(int);

int VCT_MAIN_ConnectPeers(u32 aidBitmap, int myAid);

extern void VCT_MAIN_Start(void *, int, int);

extern void VCT_MAIN_SetExitCallback(void (*cb)(void));

extern void VCT_MAIN_Exit(void);

extern int VCT_MAIN_DisconnectPeers(int);

extern void VCT_MAIN_SetMuted(int);

extern void VCT_MAIN_HangUp(void);

extern int DWC_IsBuddyFriendData(void *frienddata);

extern unsigned char DWC_GetFriendStatusData(void *p, int a, u8 *b);

extern int DWC_SetOwnStatusData(char *, unsigned long);

int DWC_SetupGameServer(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);

int DWC_ConnectToGameServerAsync(int, int, void *, u32, void *, u32, void *, int *, u32);

extern int DWC_CloseConnectionHardFromServer(u8);

extern int VCT_MAIN_GetVoiceLevel(void);

extern int DWC_SetRecvBuffer(unsigned char aid, void *recvBuffer, int size);

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

extern DwcRapWork *_pRapWork;

extern char _sAssertEmpty[];

extern char _sDwcRapFile[];

/* stand-in: second name for the address of _pRapWork; with one name the compiler shares the literal-pool word and the bytes change. */
extern char _pRapWorkAddr[];

extern char _sGameName[];

extern char _sMatchKey[];

extern char _sMatchFilterFormat[];

/*
 * Stores a word at +0x754 of the block the pointer holds.
 */
void DWC_RAP_SetState(int state)
{
    _pRapWork->state = state;
}

/*
 * True when the block pointer is set.
 */
int DWC_RAP_IsWorkAllocated(void)
{
    return _pRapWork != 0;
}

/*
 * Allocates the 0x7AC-byte ov009 work block into _pRapWork (asserting it
 * was empty) and initialises it.  GFL_NET_AllocAligned's last two arguments look
 * like a file/line pair (_sDwcRapFile, 302).
 */
int DWC_RAP_CreateWork(int userData, int friendList)
{
    GFLNetInitializeStruct *netInit;
    int slot;

    netInit = GFL_NET_GetInitParam();
    if (_pRapWork != 0)
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    _pRapWork = GFL_NET_AllocAligned(netInit->heapId, sizeof(DwcRapWork), _sDwcRapFile, 302);
    for (slot = 0; slot < 32; slot++)
        _pRapWork->deletedFriendIndex[slot] = -1;
    DWC_RAP_SetState(DWC_RAP_STATE_START);
    _pRapWork->vchatPlayerCount = 0;
    _pRapWork->targetFriendIndex = -1;
    _pRapWork->maxPlayers = netInit->maxConnectNum;
    _pRapWork->newClientAid = -1;
    _pRapWork->vchatEnabled = 0;
    _pRapWork->forceFatalError = 0;
    _pRapWork->vchatLocalOn = 1;
    _pRapWork->vchatPeerOn = 1;
    _pRapWork->vchatGateOpen = 1;
    _pRapWork->userData = (void *)userData;
    _pRapWork->friendList = (u8 *)friendList;
    _pRapWork->connectArmed = 1;
    for (slot = 0; slot < 32; slot++)
        _pRapWork->friendStatus[slot] = 0;
    if (DWC_CheckHasProfile((struct DWCstAccUserData *)_pRapWork->userData) == 0)
        return 1;
    if (DWC_CheckValidConsole((struct DWCstAccUserData *)_pRapWork->userData) == 0)
        return 2;
    return 0;
}

/*
 * DWC_RAP_FreeRecvBuffers receives the preceding call's live r0 result; its older
 * source declares no arguments. This caller preserves that register payload.
 */
void DWC_RAP_DestroyWork(void)
{
    if (_pRapWork) {
        GFL_NET_GetInitParam();
        DWC_RAP_FreeRecvBuffers();
        GFL_NET_FreeAligned(_pRapWork);
        _pRapWork = 0;
    }
    DWC_ClearError();
}

/*
 * Login half of the state machine (states START to MATCH idle): connect to
 * the access point, init friends match, log in, update the friend list.
 * Returns the result code to report, or the error handler result.
 */
int DWC_RAP_StepLogin(void)
{
    OSOwnerInfo ownerInfo;
    void *friendListArg;
    int friendFlags;
    int result;

    switch (_pRapWork->state) {
    case DWC_RAP_STATE_START:
        GFL_NET_GetInitParam();
        DWC_InitInetEx(_pRapWork->inetWork, 2, 1, 0x14);
        DWC_ConnectInetAsync();
        DWC_RAP_SetState(DWC_RAP_STATE_WAIT_INET);
        _pRapWork->vchatActive = 0;
    case DWC_RAP_STATE_WAIT_INET:
        if (DWC_CheckInet() != 0) {
            if (DWC_GetInetStatus() == 4)
                DWC_RAP_SetState(DWC_RAP_STATE_INIT_LOGIN);
            else
                DWC_RAP_SetState(DWC_RAP_STATE_ERROR);
        } else {
            DWC_ProcessInet();
            break;
        }
    case DWC_RAP_STATE_INIT_LOGIN:
        result = DWC_RAP_HandleError();
        if (result != 0)
            return result;
        friendFlags = 0;
        friendListArg = _pRapWork->friendList;
        if (friendListArg != 0)
            friendFlags = 0x20;
        DWC_InitFriendsMatch(_pRapWork->userData, 0x2FC6, _sGameName, 0, 0, friendListArg, friendFlags);
        _pRapWork->friendsMatchInit = 1;
        { u16 ingameName[2] = {0, 0};
        OS_GetOwnerInfo((struct OSOwnerInfo *)(&ownerInfo));
        DWC_LoginAsync(ingameName, 0, (void (*)(int,  int,  void *))((VoidFunc)DWC_RAP_OnLogin), 0);
        }
        DWC_RAP_SetState(DWC_RAP_STATE_LOGIN);
    case DWC_RAP_STATE_LOGIN:
        DWC_ProcessFriendsMatch();
        break;
    case DWC_RAP_STATE_UPDATE_SERVERS:
        if (_pRapWork->friendList != 0) {
            if (DWC_UpdateServersAsync(0, DWC_RAP_OnUpdateServers, _pRapWork->userData,
                              DWC_RAP_OnFriendStatusNop, _pRapWorkAddr, DWC_RAP_OnFriendDeleted,
                              _pRapWorkAddr) == 0) {
                GFL_NET_STATE_SetError(0, 0, 0, DWC_RAP_RESULT_FATAL);
            } else {
                DWC_SetBuddyFriendCallback((void (*)(int,  void *))DWC_RAP_OnBuddyFriendNop, 0);
                DWC_ProcessFriendsMatch();
            }
        }
        DWC_RAP_SetState(DWC_RAP_STATE_WAIT_UPDATE);
        break;
    case DWC_RAP_STATE_WAIT_UPDATE:
        DWC_ProcessFriendsMatch();
        if (_pRapWork->friendList == 0)
            DWC_RAP_SetState(DWC_RAP_STATE_IDLE);
        break;
    case DWC_RAP_STATE_IDLE:
        DWC_ProcessFriendsMatch();
        { int resultCode = DWC_RAP_RESULT_IDLE; _pRapWork->result = resultCode; return resultCode; }
    }
    return DWC_RAP_HandleError();
}

/*
 * Stores two words at +0x27C and +0x280 of the block the module pointer holds.
 */
void DWC_RAP_SetRecvCallbacks(int serverFunc, int clientFunc)
{
    _pRapWork->serverRecvFunc = (DwcRapRecvFunc)serverFunc;
    _pRapWork->clientRecvFunc = (DwcRapRecvFunc)clientFunc;
}

/*
 * Sets the callback that decides whether a joining friend is accepted.
 */
void DWC_RAP_SetAcceptFriendCallback(void (*acceptFunc)(void))
{
    _pRapWork->acceptFriendFunc = (int (*)(int, u32))acceptFunc;
}

/*
 * New client callback of the match calls; nothing to do.
 */
void DWC_RAP_OnNewClientNop(void)
{
}

/*
 * Connect attempt callback of the match calls; answers with the allowConnect flag.
 */
u8 DWC_RAP_AttemptCallback(void)
{
    return _pRapWork->allowConnect;
}

/*
 * Starts a match search for any partner: builds the "key = value" filter string,
 * resets the receive buffers, enters the matching state and registers the
 * transport callbacks.
 */
int DWC_RAP_StartMatchWithKey(void *matchValue, int maxPlayers, int useFilter, int unused)
{
    int slot;

    if (_pRapWork == 0)
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    if (_pRapWork->state != DWC_RAP_STATE_IDLE)
        return 0;
    DWC_RAP_FreeRecvBuffers();
    if (DWC_AddMatchKeyString(0, _sMatchKey, matchValue) == 0)
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    MI_CpuFill8(_pRapWork->matchFilter, 0, 0x80);
    sprintf((char *)_pRapWork->matchFilter, _sMatchFilterFormat, _sMatchKey, matchValue);
    if ((int)GF_STANDARD_GetStringLength((const u8 *)_pRapWork->matchFilter) >= 0x80)
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    if (useFilter)
        DWC_AddMatchKeyString(1, _pRapWork->matchFilter, _pRapWork->matchFilter);
    for (slot = 0; slot < maxPlayers; slot++)
        DWC_RAP_AllocRecvBuffer(slot);
    DWC_RAP_SetState(DWC_RAP_STATE_MATCHING);
    _pRapWork->maxPlayers = maxPlayers;
    if (DWC_ConnectToAnybodyAsync(2, maxPlayers, _pRapWork->matchFilter, (VoidFunc)DWC_RAP_OnMatched,
                      (void *)GFL_NET_GetUserArg(), DWC_RAP_OnNewClientNop,
                      (void *)GFL_NET_GetUserArg(), (VoidFunc)DWC_RAP_EvalCallbackAccept,
                      (void *)GFL_NET_GetUserArg(), (VoidFunc)DWC_RAP_AttemptCallback,
                      &_pRapWork->connectionUserData, (void *)GFL_NET_GetUserArg()) == 0)
        return 0;
    _pRapWork->connectMode = 0;
    DWC_SetUserSendCallback((int)((VoidFunc)DWC_RAP_OnSendComplete), 0);
    DWC_SetUserRecvCallback((int)((VoidFunc)DWC_RAP_OnReceive), 0);
    DWC_SetConnectionClosedCallback((int)((VoidFunc)DWC_RAP_OnConnectionClosed), 0);
    DWC_SetUserRecvTimeoutCallback((int)((VoidFunc)DWC_RAP_OnReceiveTimeout), 0);
    _pRapWork->sendInFlight = 0;
    _pRapWork->connectArmed = 1;
    return 1;
}

/*
 * Starts a match search with a caller supplied filter string; otherwise like
 * the key version.
 */
int DWC_RAP_StartMatchWithFilter(int filter, int maxPlayers, int evalFunc, int evalParam)
{
    int slot;

    if (_pRapWork == 0)
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    if (_pRapWork->state != DWC_RAP_STATE_IDLE)
        return 0;
    DWC_RAP_FreeRecvBuffers();
    for (slot = 0; slot < maxPlayers; slot++)
        DWC_RAP_AllocRecvBuffer(slot);
    DWC_RAP_SetState(DWC_RAP_STATE_MATCHING);
    _pRapWork->maxPlayers = maxPlayers;
    if (DWC_ConnectToAnybodyAsync(1, maxPlayers, (char *)filter, (VoidFunc)DWC_RAP_OnMatched, 0, DWC_RAP_OnNewClientNop, 0, (void *)evalFunc, (void *)evalParam,
                      0, 0, 0) == 0)
        return 0;
    _pRapWork->connectMode = 0;
    DWC_SetUserSendCallback((int)((VoidFunc)DWC_RAP_OnSendComplete), 0);
    DWC_SetUserRecvCallback((int)((VoidFunc)DWC_RAP_OnReceive), 0);
    DWC_SetConnectionClosedCallback((int)((VoidFunc)DWC_RAP_OnConnectionClosed), 0);
    DWC_SetUserRecvTimeoutCallback((int)((VoidFunc)DWC_RAP_OnReceiveTimeout), 0);
    _pRapWork->sendInFlight = 0;
    _pRapWork->connectArmed = 1;
    _pRapWork->result = DWC_RAP_RESULT_IDLE;
    return 1;
}

/*
 * Sets 0xd through DWC_RAP_SetState when the word at +0x754 is 0xc, else 0xb.
 */
void DWC_RAP_EndCancel(void)
{
        void DWC_RAP_SetState(int state);
    if (_pRapWork->state == DWC_RAP_STATE_MATCH_FAILING) {
        DWC_RAP_SetState(DWC_RAP_STATE_MATCH_FAILED);
        return;
    }
    DWC_RAP_SetState(DWC_RAP_STATE_CANCELED);
}

static inline int SetResult(int result)
{
    _pRapWork->result = result;
    return result;
}

int DWC_RAP_RunStateMachine(int cancelRequest)
{
    DWC_RAP_SendPendingAck();
    switch (_pRapWork->state) {
    case DWC_RAP_STATE_START:
    case DWC_RAP_STATE_WAIT_INET:
    case DWC_RAP_STATE_INIT_LOGIN:
    case DWC_RAP_STATE_LOGIN:
    case DWC_RAP_STATE_UPDATE_SERVERS:
    case DWC_RAP_STATE_WAIT_UPDATE:
        return DWC_RAP_StepLogin();
    case DWC_RAP_STATE_MATCHING:
        if (cancelRequest != 0)
            DWC_RAP_SetState(DWC_RAP_STATE_CANCELING);
        if (_pRapWork->connectMode == 2 && _pRapWork->targetFriendIndex >= 0
            && _pRapWork->friendStatus[_pRapWork->targetFriendIndex] != 6)
            DWC_RAP_SetState(DWC_RAP_STATE_MATCH_FAILING);
        break;
    case DWC_RAP_STATE_CANCELING:
    case DWC_RAP_STATE_MATCH_FAILING:
        DWC_CloseAllConnectionsHard();
        DWC_RAP_EndCancel();
        break;
    case DWC_RAP_STATE_CONNECTED: {
        GFLNetInitializeStruct *netInit = GFL_NET_GetInitParam();
        if (_pRapWork->vchatEnabled != 0)
            DWC_RAP_StartVchat((void *)netInit->heapId);
        _pRapWork->vchatLocalOn = 0;
        DWC_RAP_SetState(DWC_RAP_STATE_IN_SESSION);
        return SetResult(DWC_RAP_RESULT_CONNECTED);
    }
    case DWC_RAP_STATE_CANCELED:
        DWC_RAP_SetState(DWC_RAP_STATE_IDLE);
        _pRapWork->sendInFlight = 0;
        _pRapWork->newClientAid = -1;
        return SetResult(DWC_RAP_RESULT_CANCELED);
    case DWC_RAP_STATE_MATCH_FAILED:
        DWC_RAP_SetState(DWC_RAP_STATE_IDLE);
        _pRapWork->sendInFlight = 0;
        _pRapWork->newClientAid = -1;
        return SetResult(DWC_RAP_RESULT_MATCH_FAILED);
    case DWC_RAP_STATE_ERROR:
        return DWC_RAP_HandleError();
    case DWC_RAP_STATE_CLOSING:
        if (_pRapWork->vchatActive == 0) {
            DWC_CloseAllConnectionsHard();
            DWC_RAP_SetState(DWC_RAP_STATE_CLOSED);
            break;
        }
    case DWC_RAP_STATE_IDLE: {
        int result = DWC_RAP_StepSession();
        if (result == 0)
            return SetResult(DWC_RAP_RESULT_IDLE);
        return result;
    }
    }
    return DWC_RAP_StepSession();
}

int DWC_RAP_SendPacket(void *data, int size, int packetType)
{
    int aidBitmap;

    if (size >= 0x100)
        return 0;
    if (_pRapWork->sendInFlight != 0)
        return 0;
    _pRapWork->sendHeader.word = packetType | (_pRapWork->vchatLocalOn << 8);
    _pRapWork->sendSeq = _pRapWork->sendSeq + 1;
    _pRapWork->sendHeader.octet[2] = _pRapWork->sendSeq;
    MI_CpuCopy8(data, _pRapWork->sendPayload, size);
    _pRapWork->sendInFlight = 1;
    aidBitmap = (u16)DWC_GetAIDBitmap();
    if (aidBitmap != DWC_SendReliableBitmap(aidBitmap, _pRapWork, size + 4)) {
        _pRapWork->sendInFlight = 0;
        return 0;
    }
    return 1;
}

/*
 * Flag test on the three-argument call.
 */
int DWC_RAP_SendAck(int data, int size)
{
    if (DWC_RAP_SendPacket((void *)data, size, 3) != 0) {
        return 1;
    }

    return 0;
}

int DWC_RAP_SendMessage(int data, int size)
{
    if (_pRapWork->sendStateReady == 0)
        return 0;
    if (DWC_RAP_SendPacket((void *)data, size, 1) == 0)
        return 0;
    _pRapWork->sendStateReady = 0;
    if (_pRapWork->clientRecvFunc != 0) {
        int myAid = DWC_GetMyAID();
        _pRapWork->clientRecvFunc(myAid, (u8 *)data, (u16)size);
    }
    return 1;
}

void DWC_RAP_SendPendingAck(void)
{
    int ackValue;
    if (_pRapWork->ackPending) {
        ackValue = 0;
        if (DWC_RAP_SendAck((int)&ackValue, 4))
            _pRapWork->ackPending = 0;
    }
}

void DWC_RAP_OnLogin(int error)
{
    if (DWC_CheckDirtyFlag((void *)_pRapWork->userData) != 0) {
        DWC_ClearDirtyFlag((struct DWCstAccUserData *)_pRapWork->userData);
        _pRapWork->userDataChanged = 1;
    }
    if (error == 0)
        DWC_RAP_SetState(DWC_RAP_STATE_UPDATE_SERVERS);
    else
        DWC_RAP_SetState(DWC_RAP_STATE_ERROR);
}

void DWC_RAP_OnReceiveTimeout(unsigned int aid)
{
    if (aid < 2 && _pRapWork->peerAlive) {
        DWC_CloseAllConnectionsHard();
        _pRapWork->newClientAid = -1;
        DWC_RAP_SetState(DWC_RAP_STATE_TIMED_OUT);
    }
}

void DWC_RAP_OnUpdateServers(int error)
{
    if (error == 0) {
        DWC_RAP_SetState(DWC_RAP_STATE_IDLE);
        return;
    }

    DWC_RAP_SetState(DWC_RAP_STATE_ERROR);
}

/*
 * Friend status callback of the update call; nothing to do.
 */
void DWC_RAP_OnFriendStatusNop(void)
{
}

/*
 * Stores a and b into every one of 0x20 slots at +0x17C and +0x1FC whose first word is -1.
 */
void DWC_RAP_OnFriendDeleted(int deletedIndex, int srcIndex)
{
    int slot;

    GFL_NET_GetInitParam();
    for (slot = 0; slot < 0x20; slot++) {
        if (_pRapWork->deletedFriendIndex[slot] == -1) {
            _pRapWork->deletedFriendIndex[slot] = deletedIndex;
            _pRapWork->deletedFriendSrcIndex[slot] = srcIndex;
        }
    }
}

void DWC_RAP_OnBuddyFriendNop(void)
{
}

/*
 * Clears the eight bytes at +0x784 of the block the module pointer holds.
 */
void DWC_RAP_ClearPeerCounters(void)
{
    MI_CpuFill8((char *)_pRapWork->peerCounter, 0, 8);
}

void DWC_RAP_SetupRecvTimeouts(void)
{
    int aid, peer;

    for (aid = 0; aid < 2; aid++)
        DWC_SetRecvTimeoutTime(aid, 0);
    if (DWC_GetMyAID() == 0) {
        for (peer = 0; peer < _pRapWork->maxPlayers; peer++) {
            if (peer != DWC_GetMyAID() && (DWC_GetAIDBitmap() & (1 << peer)) != 0) {
                if (DWC_SetRecvTimeoutTime(peer, 10000) == 0)
                    GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
            }
        }
    } else {
        if (DWC_SetRecvTimeoutTime(0, 10000) == 0)
            GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    }
    _pRapWork->peerAlive = 1;
    DWC_RAP_ClearPeerCounters();
}

/*
 * Enables slot 9 then calls the wakeup.
 */
void DWC_RAP_EnterConnected(int peerIndex)
{
    DWC_RAP_SetState(DWC_RAP_STATE_CONNECTED);
    DWC_RAP_SetupRecvTimeouts();
}

void DWC_RAP_OnMatched(int error, int cancel, int self, int isServer, int peerIndex)
{
    DwcRapWork *work;

    if (error == 0) {
        if (cancel == 0)
            DWC_RAP_EnterConnected(peerIndex);
        else
            DWC_RAP_EndCancel();
    } else {
        DWC_RAP_SetState(DWC_RAP_STATE_ERROR);
    }
    work = _pRapWork;
    if (work->connectEventFunc != 0) {
        int myAid = DWC_GetMyAID();
        _pRapWork->connectEventFunc(myAid, work->connectEventArg);
    }
}

/*
 * Evaluate callback of the match calls; accepts every candidate.
 */
int DWC_RAP_EvalCallbackAccept(void)
{
    return 1;
}

/*
 * User send callback of the transport: the packet went out.
 */
void DWC_RAP_OnSendComplete(int size, u32 aid)
{
    if (aid < 2) {
        _pRapWork->sendInFlight = 0;
        _pRapWork->peerCounter[aid] = 0;
    }
}

void DWC_RAP_UpdatePeerVchatFlag(unsigned int header)
{
    if (header & 0x100) {
        _pRapWork->vchatPeerOn = 1;
    } else {
        _pRapWork->vchatPeerOn = 0;
    }
}

void DWC_RAP_OnReceive(u32 aid, u8 *data, int size)
{
    u32 header = data[0] | ((data[3] << 24) | (data[2] << 16) | (data[1] << 8));

    if (aid >= 2)
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    if (aid < 2) {
        _pRapWork->peerAlive = 1;
        if ((u8)header == 1) {
            DWC_RAP_UpdatePeerVchatFlag(header);
            _pRapWork->lastRecvSeq = data[2];
            _pRapWork->ackPending = 1;
        } else if ((u8)header == 3) {
            _pRapWork->sendStateReady = 1;
            return;
        } else {
            if (VCT_MAIN_HandlePacket(aid, data, size) == 0)
                return;
            return;
        }
        if (DWC_GetMyAID() == 0) {
            if (_pRapWork->serverRecvFunc != 0)
                _pRapWork->serverRecvFunc(aid, data + 4, (u16)(size - 4));
        } else {
            if (_pRapWork->clientRecvFunc != 0)
                _pRapWork->clientRecvFunc(aid, data + 4, (u16)(size - 4));
        }
    }
}

void DWC_RAP_OnConnectionClosed(int error, int isLocal, int isServer, u32 aid)
{
    if (aid < 2) {
        _pRapWork->sendInFlight = 0;
        _pRapWork->peerCounter[2] = 0;
        _pRapWork->connectPending = 0;
        if (error == 0) {
            if (_pRapWork->connectArmed == 1 && DWC_GetNumConnectionHost() == 1) {
                if (_pRapWork->state != DWC_RAP_STATE_CANCELING) {
                    DWC_RAP_SetState(DWC_RAP_STATE_CLOSING);
                }
                if (_pRapWork->vchatActive != 0) {
                    DWC_RAP_CleanupVchat();
                }
            }
            if (isLocal == 0) {
                DWC_RAP_SetState(DWC_RAP_STATE_CLOSING);
            }
        }
        if (_pRapWork->errorOnDisconnect != 0) {
            u32 *errorInfo = (u32 *)GFL_NET_STATE_GetError();
            if (errorInfo[3] == 0) {
                GFL_NET_STATE_SetError(errorInfo[0], errorInfo[1], errorInfo[2], DWC_RAP_RESULT_DISCONNECT_ERROR);
            }
        }
        GFL_NET_HANDLE_RemoveHandle(aid);
        {
            void (*closedFunc)(u32, u32) = _pRapWork->connectionClosedFunc;
            if (closedFunc != 0) {
                closedFunc(aid, _pRapWork->connectionClosedArg);
            }
        }
    }
}

/*
 * Handles a DWC error: runs the error callbacks, then reacts by error type.
 * The goto into the case 4 body keeps the short branch of the original.
 */
int DWC_RAP_HandleError(void)
{
    int errorCode, errorType;
    int dwcError;
    u32 result;
    u32 code = 0;
    int (*hookFunc)(u32, u32, u32, int);

    dwcError = DWC_GetLastErrorEx(&errorCode, &errorType);
    if (dwcError == 0) goto useCode;
    hookFunc = _pRapWork->errorHookFunc;
    if (hookFunc != 0) {
        if (hookFunc(_pRapWork->errorHookArg, errorCode, errorType, dwcError) == 1)
            return code;
    }
    hookFunc = _pRapWork->errorFunc;
    if (hookFunc != 0)
        hookFunc(_pRapWork->errorArg, errorCode, errorType, dwcError);
    code = errorCode;
    if (errorCode == 0 || errorType == 1)
        code = dwcError;
    result = code;
    switch (errorType) {
    case 1:
        DWC_ClearError();
        if (_pRapWork != 0 && _pRapWork->state == DWC_RAP_STATE_ERROR)
            DWC_RAP_SetState(DWC_RAP_STATE_IDLE);
        break;
    case 2:
        if (errorCode <= -40000 && errorCode >= -41999)
            DWC_GdbShutdown();
        if (_pRapWork != 0 && _pRapWork->state == DWC_RAP_STATE_ERROR)
            DWC_RAP_SetState(DWC_RAP_STATE_IDLE);
        break;
    case 4:
        if (errorCode <= -40000 && errorCode >= -41999) {
            DWC_GdbShutdown();
        useCode:
            result = code;
        }
        break;
    case 5:
        DWC_NdCleanupAsync();
        break;
    case 3:
    case 6:
        if (_pRapWork != 0) {
            switch (_pRapWork->state) {
            case DWC_RAP_STATE_LOGIN: case DWC_RAP_STATE_IDLE: case DWC_RAP_STATE_MATCHING: case DWC_RAP_STATE_CANCELING: case DWC_RAP_STATE_CONNECTED: case DWC_RAP_STATE_IN_SESSION: case DWC_RAP_STATE_CANCELED:
            case DWC_RAP_STATE_ERROR: case DWC_RAP_STATE_CLOSING: case DWC_RAP_STATE_CLOSED: case DWC_RAP_STATE_TIMED_OUT:
                if (_pRapWork->friendsMatchInit == 1) {
                    DWC_ShutdownFriendsMatch();
                    _pRapWork->friendsMatchInit = 0;
                }
                /* fall through */
            case DWC_RAP_STATE_START: case DWC_RAP_STATE_WAIT_INET: case DWC_RAP_STATE_INIT_LOGIN:
                DWC_CleanupInet();
                break;
            default:
                break;
            }
        }
        if (_pRapWork != 0)
            DWC_RAP_SetState(DWC_RAP_STATE_FATAL_DISCONNECT);
        break;
    case 7:
        if (_pRapWork != 0) {
            DWC_RAP_SetState(DWC_RAP_STATE_FATAL_ERROR);
            if (_pRapWork->fatalErrorFunc != 0)
                _pRapWork->fatalErrorFunc(-errorCode);
        }
        break;
    default:
        break;
    }
    if (_pRapWork->forceFatalError != 0) {
        result = DWC_RAP_RESULT_FATAL;
        GFL_NET_STATE_SetError(errorCode, errorType, dwcError, result);
    } else if (_pRapWork->state == DWC_RAP_STATE_TIMED_OUT) {
        result = DWC_RAP_RESULT_TIMEOUT_ERROR;
        GFL_NET_STATE_SetError(errorCode, errorType, dwcError, result);
    } else if (dwcError != 0) {
        GFL_NET_STATE_SetError(errorCode, errorType, dwcError, 0);
        GPOWER_GetSpecialPowerId();
    }
    return result;
}

int DWC_RAP_CanSendToAllPeers(void)
{
    int aid;
    int hasPeer = 0;
    for (aid = 0; aid < _pRapWork->maxPlayers; aid++) {
        if (aid != DWC_GetMyAID() && DWC_IsValidAID(aid)) {
            hasPeer = 1;
            if (DWC_IsSendableReliable((u8)aid) == 0) {
                return 0;
            }
        }
    }
    return hasPeer;
}

int DWC_RAP_SendHeartbeat(u32 counterIndex)
{
    if (_pRapWork->sendInFlight == 0 && DWC_RAP_CanSendToAllPeers() != 0
        && (DWC_GetAIDBitmap() & 0xFFFE) != 0) {
        _pRapWork->sendInFlight = 1;
        _pRapWork->sendHeader.word = ((u32)_pRapWork->vchatLocalOn << 8) | 2;
        DWC_SendReliableBitmap(DWC_GetAIDBitmap(), _pRapWork, 4);
        _pRapWork->peerCounter[counterIndex] = 0;
        return 1;
    }
    return 0;
}

int DWC_RAP_StepSession(void)
{
    DwcRapWork *work;
    int peer;

    DWC_RAP_FlushDeletedFriends();
    DWC_ProcessFriendsMatch();
    DWC_RAP_PollFriendStatus();
    if (_pRapWork->vchatActive != 0) {
        int muteVchat;
        if (_pRapWork->vchatLocalOn == 1 && _pRapWork->vchatPeerOn == 1 && _pRapWork->vchatGateOpen == 1)
            muteVchat = 0;
        else
            muteVchat = 1;
        VCT_MAIN_Update(muteVchat);
        work = _pRapWork;
        if (work->vchatAidBitmap != DWC_GetAIDBitmap() && work->vchatTalkLock == 0 && work->vchatEnabled != 0) {
            if (VCT_MAIN_ConnectPeers(DWC_GetAIDBitmap(), DWC_GetMyAID()) != 0)
                _pRapWork->vchatAidBitmap = DWC_GetAIDBitmap();
        }
    }
    if (_pRapWork->state == DWC_RAP_STATE_TIMED_OUT) {
        int result = DWC_RAP_HandleError();
        if (result == 0)
            return DWC_RAP_RESULT_TIMED_OUT;
        return result;
    }
    if (_pRapWork->state == DWC_RAP_STATE_CLOSED)
        return DWC_RAP_RESULT_CLOSED;
    if (_pRapWork->state == DWC_RAP_STATE_CONNECTED || _pRapWork->state == DWC_RAP_STATE_IN_SESSION) {
        for (peer = 0; peer < _pRapWork->maxPlayers; peer++) {
            if (_pRapWork->peerCounter[peer]++ >= 0xf0 && _pRapWork->sendInFlight == 0 && DWC_RAP_SendHeartbeat(peer) != 0) {
                DWC_RAP_ClearPeerCounters();
                break;
            }
        }
    }
    return DWC_RAP_HandleError();
}

/*
 * Three functions: 0x021562EC, 0x0215631C, 0x02156330.
 */
int DWC_RAP_GetMyAidIfConnected(void)
{
    DwcRapWork *work = _pRapWork;
    if (work != 0) {
        u32 state = work->state;
        if (state == DWC_RAP_STATE_CONNECTED || state == DWC_RAP_STATE_IN_SESSION || state == DWC_RAP_STATE_CLOSING) {
            return DWC_GetMyAID();
        }
    }
    return -1;
}

void DWC_RAP_OnVchatStopped(void)
{
    _pRapWork->vchatActive = 0;
}

void DWC_RAP_EnableLocalVchat(void)
{
    _pRapWork->vchatLocalOn = 1;
}

/*
 * Start the session: set the ready flags and register the setter callback.
 */
void DWC_RAP_StartVchat(void *heapId)
{
    u32 sessionSize;
    _pRapWork->vchatLocalOn = 1;
    _pRapWork->vchatPeerOn = 1;
    _pRapWork->vchatGateOpen = 1;
    if (_pRapWork->vchatActive == 0) {
        sessionSize = 1;
        switch (_pRapWork->vchatPlayerCount) {
        case 2:
            sessionSize = 1;
            break;
        case 3:
            sessionSize = 2;
            break;
        case 4:
            sessionSize = 3;
            break;
        case 5:
            sessionSize = 4;
            break;
        default:
            sessionSize = 4;
            break;
        }
        VCT_MAIN_Start(heapId, sessionSize, 1);
        VCT_MAIN_SetExitCallback(DWC_RAP_OnVchatStopped);
        _pRapWork->vchatActive = 1;
    }
}

/*
 * Halfword at +0x56 of the block GFL_NET_GetInitParam returns, passed on.
 */
void DWC_RAP_StartVchatDefaultHeap(int unused)
{
    DWC_RAP_StartVchat((void *)GFL_NET_GetInitParam()->heapId);
}

/*
 * Asks the voice chat module to stop when it is running.
 */
void DWC_RAP_StopVchat(void)
{
        void VCT_MAIN_HangUp(void);
    if (_pRapWork->vchatActive) VCT_MAIN_HangUp();
}

/*
 * True while the voice chat is running.
 */
int DWC_RAP_IsVchatActive(void) {
 return _pRapWork->vchatActive;
}

void DWC_RAP_CleanupVchat(void)
{
    VCT_MAIN_Exit();
    if (_pRapWork) {
        _pRapWork->vchatActive = 0;
        _pRapWork->vchatAidBitmap = 0;
        _pRapWork->vchatLocalOn = 0;
    }
}

/*
 * Retains the live result of DWC_GetMyAID as VCT_MAIN_DisconnectPeers's argument.
 */
void DWC_RAP_SetVchatTalkLock(int lock)
{
    if (lock) {
        VCT_MAIN_DisconnectPeers(DWC_GetMyAID());
        _pRapWork->vchatTalkLock = 1;
    } else {
        _pRapWork->vchatTalkLock = 0;
    }
    VCT_MAIN_SetMuted(_pRapWork->vchatTalkLock);
}

/*
 * Classify a network error code (and its error kind) into a message class.
 */
int DWC_RAP_GetErrorMessageClass(int errorCode, int errorType)
{
    int errorGroup100 = errorCode / 100;
    int errorGroup1000 = errorCode / 1000;

    if (errorCode == 20101)
        return 1;
    if (errorGroup1000 == 23)
        return 1;
    if (errorCode == 20108)
        return 2;
    if (errorCode == 20110)
        return 3;
    if (errorGroup100 == 512)
        return 4;
    if (errorGroup100 == 500)
        return 5;
    if (errorCode == 51103)
        return 6;
    if (errorGroup100 == 510)
        return 6;
    if (errorGroup100 == 511)
        return 6;
    if (errorGroup100 == 513)
        return 6;
    if (errorCode >= 52000 && errorCode <= 52003)
        return 8;
    if (errorCode >= 52010 && errorCode <= 52012)
        return 8;
    if (errorCode >= 52100 && errorCode <= 52103)
        return 8;
    if (errorCode >= 52110 && errorCode <= 52112)
        return 8;
    if (errorCode >= 52200 && errorCode <= 52203)
        return 8;
    if (errorCode >= 52210 && errorCode <= 52212)
        return 8;
    if (errorCode >= 52400 && errorCode <= 52403)
        return 8;
    if (errorCode >= 52410 && errorCode <= 52412)
        return 8;
    if (errorCode >= 52500 && errorCode <= 52503)
        return 8;
    if (errorCode >= 52510 && errorCode <= 52512)
        return 8;
    if (errorCode >= 52700 && errorCode <= 52703)
        return 8;
    if (errorCode >= 52710 && errorCode <= 52712)
        return 8;
    if (errorCode == 80430)
        return 9;
    if (errorGroup1000 == 20)
        return 0;
    if (errorGroup100 == 520)
        return 0;
    if (errorGroup100 == 521)
        return 0;
    if (errorGroup100 == 522)
        return 0;
    if (errorGroup100 == 523)
        return 0;
    if (errorGroup100 == 530)
        return 0;
    if (errorGroup100 == 531)
        return 0;
    if (errorGroup100 == 532)
        return 0;
    if (errorCode < 10000)
        return 14;
    if (errorGroup1000 == 31)
        return 12;
    switch (errorType) {
    case 0:
    case 1:
        return 14;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        return 11;
    default:
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
        break;
    case 7:
        return 15;
    }
    return -1;
}

int DWC_RAP_ProgressDisconnect(int pollOnly)
{
    u32 errorCode, errorType;
    if (DWC_GetLastErrorEx((int *)(&errorCode), (int *)(&errorType)) != 0) {
        DWC_ClearError();
    }
    if (pollOnly == 0) {
        switch (_pRapWork->state) {
        case DWC_RAP_STATE_MATCHING:
        case DWC_RAP_STATE_CONNECTED:
        case DWC_RAP_STATE_IN_SESSION:
            if (_pRapWork->vchatActive != 0) {
                VCT_MAIN_HangUp();
            }
            DWC_RAP_SetState(DWC_RAP_STATE_CLOSING);
            break;
        case DWC_RAP_STATE_IDLE:
        case DWC_RAP_STATE_FATAL_DISCONNECT:
        case DWC_RAP_STATE_CLOSED:
        case DWC_RAP_STATE_TIMED_OUT:
            return 1;
        default:
            break;
        }
    } else {
        switch (_pRapWork->state) {
        case DWC_RAP_STATE_IDLE:
        case DWC_RAP_STATE_CLOSED:
        case DWC_RAP_STATE_TIMED_OUT:
            return 1;
        default:
            break;
        }
    }
    return 0;
}

int DWC_RAP_ResetToIdle(void)
{
    u32 state = _pRapWork->state;
    if (state == DWC_RAP_STATE_CLOSED || state == DWC_RAP_STATE_TIMED_OUT || state == DWC_RAP_STATE_FATAL_DISCONNECT || state == DWC_RAP_STATE_IDLE) {
        u32 idleState = 6;
        DWC_RAP_SetState(idleState);
        _pRapWork->result = DWC_RAP_RESULT_IDLE;
        _pRapWork->newClientAid = idleState - 7;
        return 1;
    }
    return 0;
}

void DWC_RAP_Shutdown(void)
{
    if (_pRapWork != 0) {
        DWC_ClearError();
        if (_pRapWork->friendsMatchInit != 0)
            DWC_ShutdownFriendsMatch();
        _pRapWork->friendsMatchInit = 0;
        DWC_CleanupInet();
        DWC_RAP_CleanupVchat();
        DWC_RAP_DestroyWork();
    }
}

void DWC_RAP_PollFriendStatus(void)
{
    if (_pRapWork->friendList != 0) {
        u32 slot = _pRapWork->friendPollCursor & 0x1f;
        u32 byteOffset = slot * 12;
        int statusLen;
        if (DWC_IsBuddyFriendData(_pRapWork->friendList + byteOffset) != 0) {
            u32 status = DWC_GetFriendStatusData(_pRapWork->friendList + byteOffset,
                                  (int)_pRapWork->friendStatusData[slot], (u8 *)((&statusLen)));
            if (statusLen < 1) {
                _pRapWork->friendStatus[slot] = 0;
                MI_CpuFill8(_pRapWork->friendStatusData[slot], 0, 0x20);
            } else {
                _pRapWork->friendStatus[slot] = status;
            }
        }
        _pRapWork->friendPollCursor += 1;
    }
}

int DWC_RAP_SetOwnStatus(char *data, int size)
{
    if (size > 32)
        GF_PANIC_Fail(_sAssertEmpty, 0, _sAssertEmpty);
    return DWC_SetOwnStatusData(data, size);
}

/*
 * Status string of one friend.
 */
int DWC_RAP_GetFriendStatusData(int friendIndex)
{
    return (int)_pRapWork->friendStatusData[friendIndex];
}

/*
 * Byte at +0x32c past the index of the block the module pointer holds.
 */
unsigned char DWC_RAP_GetFriendStatus(int friendIndex)
{
    return _pRapWork->friendStatus[friendIndex];
}

int DWC_RAP_StartFriendMatch(int friendIndex, int maxPlayers, int limitToTwo)
{
    int entryCount = maxPlayers;
    int started;
    int slot;

    if (DWC_RAP_IsUserDataChanged() != 0)
        return -4;
    if (_pRapWork->state != DWC_RAP_STATE_IDLE) {
        _pRapWork->peerCounter[2]++;
        if (_pRapWork->peerCounter[2] > 0x78)
            return -3;
        return -1;
    }
    DWC_RAP_FreeRecvBuffers();
    _pRapWork->aidBitmapAtConnect = 0;
    _pRapWork->connectArmed = 1;
    _pRapWork->targetFriendIndex = friendIndex;
    _pRapWork->maxPlayers = maxPlayers;
    _pRapWork->canceledPeerIndex = -1;
    if (limitToTwo != 0)
        entryCount = 2;
    _pRapWork->connectPending = 1;
    if (friendIndex < 0) {
        started = DWC_SetupGameServer(2, entryCount, DWC_RAP_OnFriendServerMatched, (void *)GFL_NET_GetUserArg(), DWC_RAP_OnNewClient,
                          (void *)GFL_NET_GetUserArg(), DWC_RAP_AttemptCallback, &_pRapWork->connectionUserData,
                          (void *)GFL_NET_GetUserArg());
        _pRapWork->connectMode = 1;
    } else {
        started = DWC_ConnectToGameServerAsync(2, friendIndex, DWC_RAP_OnFriendClientMatched, 0, DWC_RAP_OnNewClient,
                          GFL_NET_GetUserArg(), DWC_RAP_AttemptCallback, &_pRapWork->connectionUserData,
                          GFL_NET_GetUserArg());
        _pRapWork->connectMode = 2;
    }
    if (started == 0) {
        _pRapWork->peerCounter[2]++;
        if (_pRapWork->peerCounter[2] > 0x78)
            GFL_NET_STATE_SetError(0, 0, 0, DWC_RAP_RESULT_DISCONNECT_ERROR);
        return -2;
    }
    _pRapWork->peerCounter[2] = 0;
    for (slot = 0; slot < maxPlayers; slot++)
        DWC_RAP_AllocRecvBuffer(slot);
    DWC_RAP_SetState(DWC_RAP_STATE_MATCHING);
    DWC_SetUserSendCallback((int)DWC_RAP_OnSendComplete, 0);
    DWC_SetUserRecvCallback((int)DWC_RAP_OnReceive, 0);
    DWC_SetConnectionClosedCallback((int)DWC_RAP_OnConnectionClosed, 0);
    DWC_SetUserRecvTimeoutCallback((int)DWC_RAP_OnReceiveTimeout, 0);
    _pRapWork->sendInFlight = 0;
    return 0;
}

int DWC_RAP_GetTargetFriendIndex(void)
{
    if (_pRapWork != 0)
        return _pRapWork->targetFriendIndex;
    return -1;
}

void DWC_RAP_OnFriendServerMatched(int error, int cancel, int self, int isServer, int peerIndex)
{
    int reject = 0;
    _pRapWork->connectPending = 0;
    if (error == 0) {
        if (cancel == 0) {
            if (_pRapWork->rejectStrangers != 0 && peerIndex == -1) {
                reject = 1;
            }
            if (_pRapWork->acceptFriendFunc != 0) {
                if (_pRapWork->acceptFriendFunc(peerIndex, GFL_NET_GetUserArg()) == 0) {
                    reject = 1;
                }
            }
            if (_pRapWork->kickNewPeers != 0 || reject != 0) {
                if (peerIndex != -1) {
                    DWC_CloseConnectionHardFromServer(peerIndex);
                }
            }
            _pRapWork->targetFriendIndex = peerIndex;
            _pRapWork->aidBitmapAtConnect = DWC_GetAIDBitmap();
            if (_pRapWork->aidBitmapAtConnect == 1) {
                DWC_RAP_SetState(DWC_RAP_STATE_CANCELING);
                return;
            }
            DWC_RAP_EnterConnected(peerIndex);
            return;
        }
        if (self == 0) {
            _pRapWork->canceledPeerIndex = peerIndex;
            _pRapWork->newClientAid = reject - 1;
        }
    }
}

/*
 * The fifth input is visibly loaded into r0 before the call.
 */
void DWC_RAP_OnFriendClientMatched(int error, int cancel, int self, int isServer, int peerIndex)
{
    _pRapWork->connectPending = 0;
    if (error == 0 && cancel == 0)
        DWC_RAP_EnterConnected(peerIndex);
}

/*
 * New client callback of the host match: remembers the AID and tells the game.
 */
void DWC_RAP_OnNewClient(int aid)
{
    _pRapWork->newClientAid = aid;
    if (_pRapWork->connectEventFunc != 0)
        _pRapWork->connectEventFunc((u16)aid, _pRapWork->connectEventArg);
}

/*
 * Voice chat state query of the ov013 module (the argument is not used).
 */
int DWC_RAP_GetVchatState(char *unused)
{
    return VCT_MAIN_GetVoiceLevel();
}

/*
 * Voice chat enabled flag, 0 when no work block exists.
 */
s16 DWC_RAP_GetVchatEnabled(void)
{
    if (_pRapWork != 0)
        return _pRapWork->vchatEnabled;
    return 0;
}

/*
 * Word at +0x774 of the work block, or 0 when none is allocated.
 */
int DWC_RAP_GetNewClientAid(void)
{
    if (_pRapWork != 0)
        return _pRapWork->newClientAid;
    return 0;
}

/*
 * Index of the peer that cancelled the match, -1 when none.
 */
int DWC_RAP_GetCanceledPeerIndex(void)
{
    if (_pRapWork)
        return _pRapWork->canceledPeerIndex;
    return -1;
}

/*
 * Sets the voice chat enabled flag.
 */
void DWC_RAP_SetVchatEnabled(int enabled)
{
    _pRapWork->vchatEnabled = enabled;
}

void DWC_RAP_FreeRecvBuffer(u32 aid)
{
    void *buf;
    buf = _pRapWork->recvBuffer[aid];
    if (buf != 0) {
        GFL_NET_FreeAligned(buf);
        _pRapWork->recvBuffer[aid] = 0;
    }
}

void DWC_RAP_AllocRecvBuffer(u32 aid)
{
    GFLNetInitializeStruct *netInit = GFL_NET_GetInitParam();
    DWC_RAP_FreeRecvBuffer(aid);
    if (_pRapWork->recvBuffer[aid] == 0) {
        u32 bufSize = 0x1000;
        _pRapWork->recvBuffer[aid] =
            GFL_NET_AllocAligned(netInit->heapId, bufSize, (const char *)_sDwcRapFile, 0xb74);
        DWC_SetRecvBuffer(aid, _pRapWork->recvBuffer[aid], bufSize);
    }
}

/*
 * Resets the two slots and marks the flag at +0x7a6.
 */
void DWC_RAP_FreeRecvBuffers(void)
{
    int aid;

    for (aid = 0; aid < 2; aid++) {
        DWC_RAP_FreeRecvBuffer(aid);
    }

    _pRapWork->sendStateReady = 1;
}

/*
 * Byte at +0x7a2 of the block the module pointer holds.
 */
unsigned char DWC_RAP_IsUserDataChanged(void)
{
    return _pRapWork->userDataChanged;
}

/*
 * Clears the user data changed flag (the argument is not used).
 */
void DWC_RAP_ClearUserDataChanged(int unused) { _pRapWork->userDataChanged = 0; }

int DWC_RAP_IsStateIdle(void)
{
    if (_pRapWork) {
        if (_pRapWork->state == DWC_RAP_STATE_IDLE) return 1;
        return 0;
    }
    return 0;
}

/*
 * True in the connected and in-session states.
 */
int DWC_RAP_IsStateInSession(void)
{

    if (_pRapWork != 0) {
        if ((u32)(_pRapWork->state - 9) <= 1)
            return 1;
    }
    return 0;
}

void DWC_RAP_FlushDeletedFriends(void)
{
    int slot;

    for (slot = 0; slot < 32; slot++) {
        if (_pRapWork->deletedFriendIndex[slot] != -1) {
            GFLNetInitializeStruct *netInit = GFL_NET_GetInitParam();
            if (netInit->deleteFriendFunc != 0) {
                DwcRapWork *entry = (DwcRapWork *)((int *)_pRapWork + slot);
                u32 userArg = GFL_NET_GetUserArg();
                netInit->deleteFriendFunc(entry->deletedFriendIndex[0], entry->deletedFriendSrcIndex[0], userArg);
            }
            _pRapWork->deletedFriendIndex[slot] = -1;
        }
    }
}

u32 DWC_RAP_GetResult(void)
{
    return _pRapWork->result;
}

void DWC_RAP_StoreAllowConnect(u32 allowed)
{
    _pRapWork->allowConnect = allowed;
}

/*
 * Two functions: 0x02156D84, 0x02156DB0.
 */
int DWC_RAP_IsDisconnected(void)
{
    DwcRapWork *work = _pRapWork;
    if (work == 0) {
        return 1;
    }
    {
        u32 state = work->state;
        if (state == DWC_RAP_STATE_CLOSED || state == DWC_RAP_STATE_FATAL_DISCONNECT || state == DWC_RAP_STATE_TIMED_OUT) {
            return 1;
        }
    }
    return 0;
}

void DWC_RAP_StoreErrorOnDisconnect(u32 enabled)
{
    _pRapWork->errorOnDisconnect = enabled;
}

/*
 * Sets the error callback and its argument.
 */
void DWC_RAP_SetErrorCallback(int (*errorFunc)(u32, u32, u32, int), u32 errorArg)
{
    _pRapWork->errorFunc = errorFunc;
    _pRapWork->errorArg = errorArg;
}

/*
 * Sets the error hook callback and its argument; the hook runs before the error callback.
 */
void DWC_RAP_SetErrorHookCallback(int (*hookFunc)(u32, u32, u32, int), u32 hookArg)
{
    _pRapWork->errorHookFunc = hookFunc;
    _pRapWork->errorHookArg = hookArg;
}
