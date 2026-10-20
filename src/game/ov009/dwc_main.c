/*
 * file:     dwc_main.c
 * unit:     yes
 * function: DWC_InitFriendsMatch, DWC_ShutdownFriendsMatch, DWC_ProcessFriendsMatch, DWC_LoginAsync, DWC_UpdateServersAsync, DWC_ConnectToAnybodyAsync, DWC_SetupGameServer, DWC_ConnectToGameServerAsync, DWC_SetConnectionClosedCallback, DWC_CloseAllConnectionsHard, DWC_CloseConnectionHardFromServer, DWC_GetNumConnectionHost, DWC_GetMyAID, DWC_GetAIDList, DWC_GetAIDBitmap, DWC_IsValidAID, DWC_GetState, DWC_GetServerAID, DWC_IsServerMyself, DWCi_GT2Startup, DWCi_GetGT2Connection, DWCi_GetConnectionAID, DWCi_GT2GetConnectionListIdx, DWCi_ClearGT2ConnectionList, DWCi_GetGT2ConnectionByIdx, DWCi_GetGT2ConnectionByProfileID, DWCi_GetConnectionInfoByIdx, DWCi_IsValidAID, DWCi_SetState, DWCi_DeleteAID, DWCi_GetAIDBitmapFromList, DWCi_HandleGPError, DWCi_HandleGT2Error, DWCi_CloseConnectionHard, DWCi_LoginCallback, DWCi_UpdateServersCallback, DWCi_MatchedCallback, DWCi_GPErrorCallback, DWCi_GPRecvBuddyMessageCallback, DWCi_GT2ReceivedCallback, DWCi_GT2ClosedProcess, DWCi_GT2ClosedCallback, DWCi_GT2PingCallback, DWCi_GT2SocketErrorCallback, DWCi_CustomCommonInit, DWCi_GetServerOrSubServerAID, DWCi_IsGetAIDValid
 * address:  0x0216AB20
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gcd_gamename                   0x021AE01C data a1
 *   gt2Listen  0x02195B20  arm
 *   gt2SetUnrecognizedMessageCallback  0x02195E68  arm
 *   DWCi_SetupGameServer  0x0216D138  arm
 *   DWCi_GT2UnrecognizedMessageCallback  0x0216E4C0  arm
 *   DWCi_StopMatch  0x0216EB68  arm
 *   DWCi_GPSetServerStatus  0x0216F20C  arm
 *   DWCi_CloseMatch  0x0216F6C0  arm
 *   DWCi_SetMatchStatus  0x02175F4C  arm
 *   DWCi_NodeInfoList_Clear  0x0217601C  arm
 *   DWCi_NodeInfoList_RemoveAID  0x02176164  arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID  0x021763AC  arm
 *   qr2_shutdown  0x0219B540  arm
 *   CloseStatsConnection  0x02193D00  arm
 *   DWCi_IsError  0x02059F38  arm  arm9
 *   DWC_GetInetStatus  0x0205CA20  arm  arm9
 *   DWCi_IsServerUpdating  0x02168D7C  arm
 *   DWCi_UpdateServersAsync  0x02168DA4  arm
 *   DWCi_StopFriendProcess  0x02168E50  arm
 *   DWCi_InitGPProcessCount  0x0216909C  arm
 *   DWCi_ShutdownFriend  0x021691FC  arm
 *   DWCi_BeginCloseStatsConnection  0x02169FF8  arm
 *   DWCi_EndCloseStatsConnection  0x0216A00C  arm
 *   DWCi_StopLogin  0x0216A3B8  arm
 *   DWCi_ShutdownLogin  0x0216A404  arm
 *   DWCi_RecvCallback  0x02177340  arm
 *   DWCi_PingCallback  0x02177398  arm
 *   DWCi_ShutdownTransport  0x0217772C  arm
 *   GOAGetLastError  0x0217ED54  arm
 *   ServerBrowserFree  0x0219ED4C  arm
 *   DWCi_WStrLen  0x021686E0  arm
 *   DWCi_MatchGPRecvBuddyMsgCallback  0x0216EAB8  arm
 *   GSIStartAvailableCheckA  0x0217C750  arm
 *   gpDestroy  0x0218592C  arm
 *   gt2CreateSocket  0x02195AB4  arm
 *   gt2CloseSocket  0x02195AD8  arm
 *   gt2CloseConnectionHard  0x02195DC4  arm
 *   gt2CloseAllConnectionsHard  0x02195DE4  arm
 *   gt2AddressToString  0x02198620  arm
 *   gDwcPrefixScm  0x021A2028  data
 *   gDwcPrefixScn  0x021A202C  data
 *   gDwcPrefixGpcm  0x021A2030  data
 *   gDwcPrefixMat  0x021A2038  data
 *   gDwcGlobalState  0x021AA878  data
 *   gDwcNodeAidList  0x021AA880  data
 *   gDwcConnectionArray  0x021AA8A0  data
 *   gDwcNodeInfoBuffer  0x021AA920  data
 *   DWCi_GetMathRand32  0x021685CC  arm
 *   DWCi_SetError  0x02059F54  arm  arm9
 *   DWC_Free  0x0205A1B0  arm  arm9
 *   DWCi_NNFreeNegotiateList  0x02176B34  arm
 *   gpProcess  0x02185948  arm
 *   gpSetCallback  0x0218597C  arm
 *   DWCi_GT2ConnectAttemptCallback  0x0216E5B0  arm
 *   DWCi_ClearQR2Key  0x0216EC18  arm
 *   DWCi_ShutdownMatch  0x0216F334  arm
 *   gcd_secret_key               0x021AE11C  data
 *   strncpy                      0x02094860  arm
 */
#define GAME_TYPES_U32_LONG
#include "dwc_transport.h"
#include "dwc_match.h"
#include "dwc_friend.h"
#include "../../matched/arm9_sdk/libc/string.h"
#include "dwc_cnt_types.h"

struct GTI2Connection;

#include "gpi_types.h"

typedef struct {
    int result;
    int errorCode;
    int fatal;
} GPErrorArg;


#include "../arm9/dwc_memfunc.h"
#include "../arm9/mi_memory.h"
#include "../arm9/dwc_error.h"
extern void DWCi_LoginInit(DWCstLoginControl *logcnt, DWCstAccUserData *userdata,
                           void **pGpObj, int productID, u32 gamecode,
                           u16 *playerName,
                           void (*callback)(int, int, void *), void *param);
extern unsigned long strlen(const char *s);
#include "qr2.h"
struct ServerBrowser;
#include "sb_serverbrowsing.h"
extern void DWCi_BeginCloseStatsConnection(void);
#include "gstats.h"
extern void DWCi_EndCloseStatsConnection(void);
extern int gpProcess(void **conn);
extern void gpDestroy(int **p);
extern void DWCi_ShutdownLogin(void);
extern void DWCi_ShutdownFriend(void);
extern void DWCi_ShutdownMatch(void);
extern void DWCi_ShutdownTransport(void);
#include "gt2main.h"
#include "../arm9/dwc_connectinet.h"
#include "gsavailable.h"
extern int gpInitialize(void **connection, int productID, int namespaceID, int partnerID);
extern int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param);
extern int DWCi_LoginAsync(void);
extern void DWCi_StopLogin(int error, int errorCode);
extern void DWCi_LoginProcess(void);
extern void DWCi_FriendProcess(void);
extern void DWCi_MatchProcess(int fullSpec);
extern void DWCi_TransportProcess(void);

extern void DWCi_GPErrorCallback(void **, void *, void *);
#include "dwc_common.h"
extern int DWCi_IsServerUpdating(void);
extern void DWCi_SetupGameServer(int topology, unsigned char numEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern int DWCi_GetProfileIDFromList(int index);
extern int gpIsBuddy(void **connection, int profile);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
extern unsigned char DWCi_IsLockedBuddyStatus(char *buddyStatus);
#include "../arm9/msl_strtod.h"
extern void DWCi_CustomCommonInit(u8 matchType);
extern void DWCi_ConnectToGameServerAsync(int topology, int serverPid, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern int DWCi_GPSetServerStatus(int matchType);
extern int DWC_CancelMatch(void);

extern void DWCi_NNFreeNegotiateList(void);
extern void DWCi_ClearQR2Key(void);
extern void DWCi_NodeInfoList_Clear(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_CloseMatch(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int pid);
#include "gt2utility.h"
struct GTI2Socket;
extern void DWCi_GT2SocketErrorCallback(void *socket);
extern void DWCi_GT2ConnectAttemptCallback(void *userdata, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len);
extern int DWCi_GT2UnrecognizedMessageCallback(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern int DWCi_NodeInfoList_RemoveAID(unsigned char aid);
extern void DWCi_StopMatch(int error, int errorCode);
extern void DWCi_StopFriendProcess(int error, int errorCode);
extern void DWCi_InitGPProcessCount(void);
extern void DWCi_ClearQR2Key(void);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern char *strchr(const char *s, int c);
extern char *strncpy(char *dest, const char *src, unsigned long n);
extern void DWCi_MatchGPRecvBuddyMsgCallback(int unused, int profileID, char *message);
extern void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable);
extern int DWCi_IsShutdownMatch(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void DWCi_ClearTransConnection(int i);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern int DWCi_IsBackupMine(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_GetFriendListIndex(int profileID);
extern int DWCi_IsFullMesh(void);
extern void DWCi_ProcessMatchSCClosing(int clientPid);
extern int DWCi_StopMeshMaking(void);

extern int DWCi_IsServerChangeEnabled(void);
extern void DWCi_PingCallback(void *connection, int latency);
struct GTI2Socket;
#include "gsplatformsocket.h"
extern void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);

void DWC_InitFriendsMatch(DWCstAccUserData *userdata, int productID, char *secretKey, int sendBufSize, int recvBufSize, void *friendList, int friendListLen);
void DWC_ShutdownFriendsMatch(void);
void DWC_ProcessFriendsMatch(void);
int DWC_ConnectToGameServerAsync(int topology, int serverIndex, void (*matchedCallback)(int, int, int, int, int, void *), void *matchedParam, void (*newClientCallback)(int, void *), void *newClientParam, int (*attemptCallback)(unsigned char *, void *), unsigned char *connectionUserData, void *attemptParam);
int DWC_GetNumConnectionHost(void);
int DWC_GetState(void);
int DWC_IsServerMyself(void);
unsigned char DWC_GetServerAID(void);
int DWCi_IsGetAIDValid(void);
int DWCi_CloseConnectionHard(unsigned char aid);
void DWCi_SetState(int state);

void DWCi_ClearGT2ConnectionList(void);
void DWCi_UpdateServersCallback(int error, int isChanged);
void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index, void *param);
void DWCi_LoginCallback(int error, int profileID, void *param);
void DWCi_GT2ConnectedCallback(void *connection, int result);
void DWCi_GT2ReceivedCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_GT2ClosedCallback(void *connection, int reason);
void DWCi_GT2PingCallback(void *connection, int latency);
void DWCi_GT2ClosedProcess(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
void DWCi_GPRecvBuddyMessageCallback(void **pconnection, GPRecvBuddyMessageArg *arg);
int DWCi_GetAIDBitmapFromList(unsigned char *p, int n);
int DWCi_HandleGT2Error(int result);
int DWCi_HandleGPError(int result);

unsigned char DWCi_GetServerOrSubServerAID(void);
int DWCi_DeleteAID(unsigned char aid);
extern char gcd_gamename[];
extern char gcd_secret_key[];
extern struct DwcGlobal gDwcGlobalState;
extern char gDwcPrefixScm[];
extern char gDwcPrefixScn[];
extern char gDwcPrefixGpcm[];
extern char gDwcPrefixMat[];
extern void *gDwcConnectionArray[32];
extern unsigned char gDwcNodeAidList[];
extern char gDwcNodeInfoBuffer[];


void DWC_InitFriendsMatch(DWCstAccUserData *userdata, int productID,
                          char *secretKey, int sendBufSize, int recvBufSize,
                          void *friendList, int friendListLen)
{
    int len;

    gDwcGlobalState.st = DWC_Alloc(4, sizeof(DWCstDwcCnt));
    MI_CpuFill8(gDwcGlobalState.st, 0, sizeof(DWCstDwcCnt));
    DWC_ClearError();

    gDwcGlobalState.st->gt2Socket = 0;
    gDwcGlobalState.st->gt2Callbacks.connected = DWCi_GT2ConnectedCallback;
    gDwcGlobalState.st->gt2Callbacks.received = DWCi_GT2ReceivedCallback;
    gDwcGlobalState.st->gt2Callbacks.closed = DWCi_GT2ClosedCallback;
    gDwcGlobalState.st->gt2Callbacks.ping = DWCi_GT2PingCallback;
    gDwcGlobalState.st->sendBufSize =
        sendBufSize == 0 ? 0x2000 : (unsigned long)sendBufSize;
    gDwcGlobalState.st->recvBufSize =
        recvBufSize == 0 ? 0x2000 : (unsigned long)recvBufSize;
    gDwcGlobalState.st->gp = 0;
    gDwcGlobalState.st->userdata = userdata;
    gDwcGlobalState.st->state = 0;
    gDwcGlobalState.st->prevState = 0;
    gDwcGlobalState.st->closeAllHard = 0;
    gDwcGlobalState.st->profileID = 0;
    gDwcGlobalState.st->gameName = gcd_gamename;
    gDwcGlobalState.st->secretKey = gcd_secret_key;
    gDwcGlobalState.st->loginCallback = 0;
    gDwcGlobalState.st->loginParam = 0;
    gDwcGlobalState.st->updateCallback = 0;
    gDwcGlobalState.st->updateParam = 0;
    gDwcGlobalState.st->matchedCallback = 0;
    gDwcGlobalState.st->matchedParam = 0;
    gDwcGlobalState.st->closedCallback = 0;
    gDwcGlobalState.st->closedParam = 0;

    DWCi_ClearGT2ConnectionList();

    DWCi_LoginInit(&gDwcGlobalState.st->login, userdata,
                   &gDwcGlobalState.st->gp, productID, userdata->gamecode,
                   gDwcGlobalState.st->playerName,
                   DWCi_LoginCallback, 0);

    DWCi_FriendInit((FriendCnt *)(gDwcGlobalState.st->friendCnt),
                    &gDwcGlobalState.st->gp,
                    gDwcGlobalState.st->playerName,
                    friendList, friendListLen);

    DWCi_MatchInit(&gDwcGlobalState.st->match,
                   &gDwcGlobalState.st->gp, &gDwcGlobalState.st->gt2Socket,
                   &gDwcGlobalState.st->gt2Callbacks, gcd_gamename,
                   gcd_secret_key, (sptr)(friendList), friendListLen);

    DWCi_InitTransport((TransInfo *)gDwcGlobalState.st->transInfo);

    if (strlen(secretKey) >= 0x100)
        len = 0xff;
    else
        len = (int)strlen(secretKey);
    MI_CpuCopy8(secretKey, gcd_secret_key, len);
    gcd_secret_key[len] = 0;
}


/*
 * sdk:      DWC_ShutdownFriendsMatch (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void DWC_ShutdownFriendsMatch(void)
{
    if (gDwcGlobalState.st == 0)
        return;
    if (gDwcGlobalState.st->match.qr2Obj != 0) {
        qr2_shutdown(gDwcGlobalState.st->match.qr2Obj);
        gDwcGlobalState.st->match.qr2Obj = 0;
    }
    gDwcGlobalState.st->match.qr2ShutdownReq = 0;
    if (gDwcGlobalState.st->match.sbObj != 0) {
        ServerBrowserFree(gDwcGlobalState.st->match.sbObj);
        gDwcGlobalState.st->match.sbObj = 0;
    }
    DWCi_NNFreeNegotiateList();
    DWCi_BeginCloseStatsConnection();
    CloseStatsConnection();
    DWCi_EndCloseStatsConnection();
    if (gDwcGlobalState.st->gp != 0) {
        gpSetCallback(&gDwcGlobalState.st->gp, 0, 0, 0);
        gpSetCallback(&gDwcGlobalState.st->gp, 3, 0, 0);
        gpSetCallback(&gDwcGlobalState.st->gp, 1, 0, 0);
        gpSetCallback(&gDwcGlobalState.st->gp, 2, 0, 0);
        gpProcess(&gDwcGlobalState.st->gp);
        gpDestroy((int **)(&gDwcGlobalState.st->gp));
        gDwcGlobalState.st->gp = 0;
    }
    DWCi_ShutdownLogin();
    DWCi_ShutdownFriend();
    DWCi_ShutdownMatch();
    DWCi_ShutdownTransport();
    if (gDwcGlobalState.st->gt2Socket != 0) {
        gt2CloseSocket(gDwcGlobalState.st->gt2Socket);
        gDwcGlobalState.st->gt2Socket = 0;
    }
    DWC_Free(4, gDwcGlobalState.st, 0);
    gDwcGlobalState.st = 0;
}


void DWC_ProcessFriendsMatch(void)
{
    DWC_UpdateConnection();
    if (gDwcGlobalState.st == 0 || gDwcGlobalState.st->state == 0)
        return;
    if (DWCi_IsError())
        return;

    switch (gDwcGlobalState.st->state)
    {
    case 0:
        break;
    case 1:
        switch (GSIAvailableCheckThink())
        {
        case 1:
            if (DWCi_HandleGPError(gpInitialize(&gDwcGlobalState.st->gp,
                    gDwcGlobalState.st->login.productID, 0x10, 0xb)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&gDwcGlobalState.st->gp,
                    0, DWCi_GPErrorCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&gDwcGlobalState.st->gp,
                    3, (void (*)(void **, void *, void *))DWCi_GPRecvBuddyMessageCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&gDwcGlobalState.st->gp,
                    7, (void (*)(void **, void *, void *))(DWCi_GPRecvBuddyAuthCallback), 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&gDwcGlobalState.st->gp,
                    1, (void (*)(void **, void *, void *))(DWCi_GPRecvBuddyRequestCallback), 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&gDwcGlobalState.st->gp,
                    2, (void (*)(void **, void *, void *))(DWCi_GPRecvBuddyStatusCallback), 0)))
                return;
            DWCi_SetState(2);
            if (DWCi_LoginAsync() == 0)
                DWCi_StopLogin(2, 0xffffb17c);
            break;
        case 2:
            DWCi_StopLogin(3, 0xffffb172);
            return;
        case 3:
            DWCi_StopLogin(4, 0xffffb17b);
            return;
        }
        break;
    case 2:
        DWCi_LoginProcess();
        break;
    case 3:
        DWCi_FriendProcess();
        DWCi_MatchProcess(0);
        break;
    case 4:
        DWCi_MatchProcess(1);
        DWCi_FriendProcess();
        break;
    case 5:
        DWCi_TransportProcess();
        DWCi_FriendProcess();
        /* stand-in: the image reloads qr2MatchType for each compare */
        if (*(volatile u8 *)&gDwcGlobalState.st->match.qr2MatchType == 2
                || *(volatile u8 *)&gDwcGlobalState.st->match.qr2MatchType == 3)
            DWCi_MatchProcess(1);
        else if (*(int *)gDwcGlobalState.st != 0)
            DWCi_MatchProcess(0);
        break;
    }

    if (gDwcGlobalState.st->match.qr2ShutdownReq == 1)
    {
        if (gDwcGlobalState.st->match.qr2Obj != 0)
        {
            qr2_shutdown(gDwcGlobalState.st->match.qr2Obj);
            gDwcGlobalState.st->match.qr2Obj = 0;
        }
        gDwcGlobalState.st->match.qr2ShutdownReq = 0;
    }
}




/*
 * sdk:      DWC_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWC_LoginAsync(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param)
{
    u32 len;

    if (!ingamesn)
        return 0;
    if (DWCi_IsError() || gDwcGlobalState.st->state != 0)
        return 0;
    gDwcGlobalState.st->loginCallback = callback;
    gDwcGlobalState.st->loginParam = param;
    if (!ingamesn || ingamesn[0] == 0) {
        len = 0;
    } else {
        MIi_CpuClear16(0, gDwcGlobalState.st->playerName, 0x34);
        len = (u32)DWCi_WStrLen(ingamesn) > 25 ? 25 : (u32)DWCi_WStrLen(ingamesn);
        MIi_CpuCopy16(ingamesn, gDwcGlobalState.st->playerName, len * 2);
    }
    gDwcGlobalState.st->playerName[len] = 0;
    if (DWC_GetInetStatus() != 4) {
        DWCi_StopLogin(2, -60010);
        return 0;
    }
    DWCi_SetState(1);
    GSIStartAvailableCheckA(gDwcGlobalState.st->gameName);
    return 1;
}




/*
 * sdk:      DWC_UpdateServersAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWC_UpdateServersAsync(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam)
{
	if (DWCi_IsError() || gDwcGlobalState.st->state < 3 || DWCi_IsServerUpdating())
		return 0;
	gDwcGlobalState.st->updateCallback = updateCallback;
	gDwcGlobalState.st->updateParam = updateParam;
	DWCi_UpdateServersAsync(gDwcGlobalState.st->login.authToken, gDwcGlobalState.st->login.partnerChallenge, (void (*)(int, u8, int))(DWCi_UpdateServersCallback), 0, statusCallback, statusParam, deleteCallback, (sptr)deleteParam);
	return 1;
}




/*
 * sdk:      DWC_ConnectToAnybodyAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWC_ConnectToAnybodyAsync(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (DWCi_IsError() || gDwcGlobalState.st->state != 3)
		return 0;
	DWCi_ClearGT2ConnectionList();
	gDwcGlobalState.st->matchedCallback = matchedCallback;
	gDwcGlobalState.st->matchedParam = matchedParam;
	DWCi_SetState(4);
	DWCi_CustomCommonInit(0);
	DWCi_ConnectToAnybodyAsync(topology, maxEntry - 1, addFilter, DWCi_MatchedCallback, 0, newClientCallback, newClientParam, evalCallback, evalParam, attemptCallback, connectionUserData, attemptParam);
	return 1;
}




/*
 * sdk:      DWC_SetupGameServer (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWC_SetupGameServer(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (DWCi_IsError() || gDwcGlobalState.st->state != 3)
		return 0;
	DWCi_ClearGT2ConnectionList();
	gDwcGlobalState.st->matchedCallback = matchedCallback;
	gDwcGlobalState.st->matchedParam = matchedParam;
	DWCi_SetState(4);
	DWCi_CustomCommonInit(2);
	DWCi_SetupGameServer(topology, (unsigned char)(maxEntry - 1), DWCi_MatchedCallback, 0, newClientCallback, newClientParam, attemptCallback, connectionUserData, attemptParam);
	return 1;
}




int DWC_ConnectToGameServerAsync(
    int topology, int serverIndex,
    void (*matchedCallback)(int, int, int, int, int, void *),
    void *matchedParam, void (*newClientCallback)(int, void *),
    void *newClientParam, int (*attemptCallback)(unsigned char *, void *),
    unsigned char *connectionUserData, void *attemptParam)
{
    unsigned char numEntry;
    unsigned char maxEntry;
    GPBuddyStatus status;
    int buddyIdx;
    char valueStr[4];
    int dwcError;

    buddyIdx = -1;

    if (DWCi_IsError() || gDwcGlobalState.st->state != 3)
        return 0;

    DWCi_ClearGT2ConnectionList();
    gDwcGlobalState.st->matchedCallback = matchedCallback;
    gDwcGlobalState.st->matchedParam = matchedParam;
    DWCi_SetState(4);

    dwcError = DWCi_GetProfileIDFromList(serverIndex);
    if (dwcError == 0 || !gpIsBuddy(&gDwcGlobalState.st->gp, dwcError))
    {
        dwcError = 0xb;
        goto error;
    }

    gpGetBuddyIndex(&gDwcGlobalState.st->gp, dwcError, &buddyIdx);
    gpGetBuddyStatus(&gDwcGlobalState.st->gp, buddyIdx, &status);
    if (status.status != 6)
    {
        dwcError = 0xb;
        goto error;
    }

    valueStr[0] = 0x30;
    if (DWCi_IsLockedBuddyStatus((char *)(&status)))
    {
        dwcError = 0x15;
        goto error;
    }

    DWC_GetCommonValueString(gDwcPrefixScm, valueStr, status.statusString, 0x2f);
    maxEntry = (unsigned char)strtoul(valueStr, 0, 10);
    DWC_GetCommonValueString(gDwcPrefixScn, valueStr, status.statusString, 0x2f);
    numEntry = (unsigned char)strtoul(valueStr, 0, 10);
    if (numEntry == maxEntry)
    {
        dwcError = 0xc;
        goto error;
    }

    DWCi_CustomCommonInit(3);
    DWCi_ConnectToGameServerAsync(topology, dwcError, DWCi_MatchedCallback, 0,
                                  newClientCallback, newClientParam,
                                  attemptCallback, connectionUserData,
                                  attemptParam);
    return 1;

error:
    DWCi_SetError(dwcError, 0);
    gDwcGlobalState.st->matchedCallback(dwcError, 0, 1, 0, 0,
                                    gDwcGlobalState.st->matchedParam);
    if (gDwcGlobalState.st != 0 && gDwcGlobalState.st->state == 4)
    {
        DWCi_SetState(3);
        DWCi_GPSetServerStatus(1);
    }
    return 1;
}




/*
 * Sets the connection-closed callback and its parameter; 0 when the block is
 * absent, 1 when they were stored.
 */
int DWC_SetConnectionClosedCallback(MatchedCallback callback, void *param)
{
    if (gDwcGlobalState.st == 0)
        return 0;
    gDwcGlobalState.st->closedCallback = callback;
    gDwcGlobalState.st->closedParam = param;
    return 1;
}




/*
 * sdk:      DWC_CloseAllConnectionsHard (libdwcmatch.TWL.HYB.a dwc_main.o)
 */
int DWC_CloseAllConnectionsHard(void)
{
    DWCstNodeInfo *pNodeInfo;
    int i;
    int anyGT2ConnectionExist = 0;

    gDwcGlobalState.st->match.cancelFromConnection = 1;
    if (DWC_CancelMatch())
        return 1;
    if (gDwcGlobalState.st == 0 || DWCi_IsError() ||
        (gDwcGlobalState.st->state != 4 && gDwcGlobalState.st->state != 5))
        return -1;
    for (i = 0; i < 32; i++) {
        if (gDwcConnectionArray[i] != 0) {
            anyGT2ConnectionExist = 1;
            break;
        }
    }
    if (anyGT2ConnectionExist == 0) {
        DWCi_NodeInfoList_GetCount();
        DWCi_GPSetServerStatus(1);
        DWCi_NNFreeNegotiateList();
        DWCi_SetState(3);
        DWCi_ClearQR2Key();
        DWCi_NodeInfoList_Clear();
        DWCi_SetMatchStatus(0);
        DWCi_CloseMatch();
        return 1;
    }
    gDwcGlobalState.st->closeAllHard = 1;
    gt2CloseAllConnectionsHard(gDwcGlobalState.st->gt2Socket);
    while (DWCi_NodeInfoList_GetCount() > 1) {
        for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
            if (pNodeInfo->profileID != gDwcGlobalState.st->profileID)
                DWCi_GT2ClosedProcess(0, 0, 1, pNodeInfo->aid);
        }
    }
    gDwcGlobalState.st->closeAllHard = 0;
    DWCi_NodeInfoList_Clear();
    DWCi_SetMatchStatus(0);
    DWCi_CloseMatch();
    if (DWC_GetState() != 3) {
        DWCi_NNFreeNegotiateList();
        DWCi_SetState(3);
        DWCi_ClearQR2Key();
    }
    return 0;
}




/*
 * Returns -3 when DWC_IsServerMyself rejects the call, else the DWCi_CloseConnectionHard result.
 */
int DWC_CloseConnectionHardFromServer(unsigned char aid)
{
    if (DWC_IsServerMyself() == 0) return -3;
    return DWCi_CloseConnectionHard(aid);
}



int DWC_GetNumConnectionHost(void)
{
    int num;

    if (gDwcGlobalState.st == 0 || DWCi_IsGetAIDValid() == 0) {
        num = 0;
    } else {
        num = DWCi_NodeInfoList_GetCount();
    }
    return num;
}



/*
 * DWC_GetMyAID: this host's aid, or 0xff when none is valid.
 */
unsigned char DWC_GetMyAID(void)
{
    DWCstNodeInfo *node;

    if (gDwcGlobalState.st == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0xff;
    }
    node = DWCi_NodeInfoList_GetNodeInfoForProfileID(gDwcGlobalState.st->profileID);
    if (node == 0) {
        return 0xff;
    }
    return node->aid;
}



/*
 * DWC_GetAIDList: fills the static aid list from the node list and returns the node count.
 */
int DWC_GetAIDList(unsigned char **out)
{
    int i;

    if (gDwcGlobalState.st == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0;
    }
    MI_CpuFill8(gDwcNodeAidList, 0, 0x20);
    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
        gDwcNodeAidList[i] = DWCi_NodeInfoList_GetNodeInfoForIndex(i)->aid;
    }
    *out = gDwcNodeAidList;
    return DWCi_NodeInfoList_GetCount();
}



/*
 * DWC_GetAIDBitmap: the bitmap of every aid in the current node list.
 */
int DWC_GetAIDBitmap(void)
{
    unsigned char *list;
    int n;

    if (gDwcGlobalState.st == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0;
    }
    n = DWC_GetAIDList(&list);
    return DWCi_GetAIDBitmapFromList(list, n);
}



/*
 * sdk:      DWC_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWC_IsValidAID(unsigned char aid)
{
	if (gDwcGlobalState.st == 0)
		return 0;
	if (aid == DWC_GetMyAID())
		return 0;
	if (DWCi_NodeInfoList_GetNodeInfoForAID(aid))
		return 1;
	return 0;
}



int DWC_GetState(void)
{
    DWCstDwcCnt *p = gDwcGlobalState.st;

    return p != 0 ? p->state : 0;
}



/*
 * DWC_GetServerAID: the aid of node 0 while a match is running, else 0xff.
 */
unsigned char DWC_GetServerAID(void)
{
    DWCstDwcCnt *p = gDwcGlobalState.st;
    DWCstNodeInfo *node;

    if (p == 0 || p->match.state == 0 || p->match.state == 9 ||
        p->match.state == 10 || p->match.state == 11 ||
        p->match.connectionEstablished == 0 || p->match.qr2HostState == 0) {
        return 0xff;
    }
    node = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
    if (node == 0) {
        return 0xff;
    }
    return node->aid;
}


int DWC_IsServerMyself(void)
{
    if (gDwcGlobalState.st == 0) {
        return 0;
    }
    if (DWC_GetServerAID() == 0xff) {
        return 0;
    }
    return gDwcGlobalState.st->match.qr2HostState == 2;
}



/*
 * sdk:      DWCi_GT2Startup (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWCi_GT2Startup(void)
{
	int gt2Result;
	unsigned short baseport;

	if (gDwcGlobalState.st->gt2Socket != 0)
		return 0;
	baseport = DWCi_GetMathRand32(0x4000) + 0xc000;
	gt2Result = gt2CreateSocket(&gDwcGlobalState.st->gt2Socket, gt2AddressToString(0, baseport, 0), gDwcGlobalState.st->sendBufSize, gDwcGlobalState.st->recvBufSize, DWCi_GT2SocketErrorCallback);
	if (DWCi_HandleGT2Error(gt2Result))
		return gt2Result;
	gt2Listen(gDwcGlobalState.st->gt2Socket, DWCi_GT2ConnectAttemptCallback);
	gt2SetUnrecognizedMessageCallback(gDwcGlobalState.st->gt2Socket, DWCi_GT2UnrecognizedMessageCallback);
	return gt2Result;
}



/*
 * DWCi_GetGT2Connection: the connection whose aid matches, or zero.
 */
void *DWCi_GetGT2Connection(unsigned char aid)
{
    int i;

    if (gDwcGlobalState.st == 0) {
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (gDwcConnectionArray[i] != 0 && aid == ((DWCstConnectionInfo *)gt2GetConnectionData(gDwcConnectionArray[i]))->aid) {
            return gDwcConnectionArray[i];
        }
    }
    return 0;
}



/*
 * Byte at +1 of the block, or 0xff when there is none.
 */
int DWCi_GetConnectionAID(void *connection)
{
    DWCstConnectionInfo *info = (DWCstConnectionInfo *)gt2GetConnectionData(connection);

    return info ? info->aid : 0xff;
}


/*
 * Returns the index of the first null word in the 0x20-entry word table, or
 * -1 when the whole table is occupied.
 */
int DWCi_GT2GetConnectionListIdx(void)
{
    int i;

    for (i = 0; i < 0x20; i++)
        if (gDwcConnectionArray[i] == 0) return i;
    return -1;
}


void DWCi_ClearGT2ConnectionList(void)
{
    MIi_CpuClear32(0, gDwcConnectionArray, 0x80);
    MIi_CpuClear32(0, gDwcNodeInfoBuffer, 0x100);
}


/*
 * Address of the i-th word of the table.
 */
void **DWCi_GetGT2ConnectionByIdx(int i)
{
    return &gDwcConnectionArray[i];
}


/*
 * DWCi_GetGT2ConnectionByProfileID: the connection slot whose peer profile id matches, or null.
 */
void **DWCi_GetGT2ConnectionByProfileID(int pid, int flag)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (gDwcConnectionArray[i] != 0 && pid == ((DWCstConnectionInfo *)gt2GetConnectionData(gDwcConnectionArray[i]))->profileID) {
            return DWCi_GetGT2ConnectionByIdx(i);
        }
    }
    return 0;
}


/*
 * Address of the i-th entry of the eight-byte table.
 */
void *DWCi_GetConnectionInfoByIdx(int i)
{
    return gDwcNodeInfoBuffer + i * 8;
}


/*
 * sdk:      DWCi_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWCi_IsValidAID(unsigned char aid)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		if (gDwcConnectionArray[i] != 0) {
			if (aid == ((DWCstConnectionInfo *)gt2GetConnectionData(gDwcConnectionArray[i]))->aid)
				return 1;
		}
	}
	return 0;
}





/*
 * DWCi_SetState: remembers the current state and sets the new one.
 */
void DWCi_SetState(int v)
{
    gDwcGlobalState.st->prevState = gDwcGlobalState.st->state;
    gDwcGlobalState.st->state = v;
}





int DWCi_DeleteAID(unsigned char aid)
{
    DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForAID(aid);
    int profileID;

    if (pNodeInfo == 0) return 0;
    profileID = pNodeInfo->profileID;
    DWCi_NodeInfoList_RemoveAID(aid);
    return profileID;
}




/*
 * Builds a bit mask over the first n bytes of the array: m |= 1 << p[i].
 */
int DWCi_GetAIDBitmapFromList(unsigned char *p, int n)
{
    int m = 0;
    int i;

    for (i = 0; i < n; i++)
        m |= 1 << p[i];
    return m;
}





/*
 * sdk:      DWCi_HandleGPError (dwc_main.o)
 *
 * Extra open callee of DWCi_GPErrorCallback (0x0216C08C).
 */
int DWCi_HandleGPError(int result)
{
    int errorCode;
    int dwcError;

    if (result == 0) return 0;
    switch (result) {
    case 1: dwcError = 9; errorCode = -1; break;
    case 2: dwcError = 9; errorCode = -2; break;
    case 3: dwcError = 6; errorCode = -10; break;
    case 4: dwcError = 6; errorCode = -20; break;
    }
    switch (gDwcGlobalState.st->state) {
    case 1:
        errorCode += (int)0xffff11b8;
        DWCi_StopLogin(dwcError, errorCode);
        break;
    case 2:
        errorCode += (int)0xffff11b8;
        if (gDwcGlobalState.st->login.state < 1)
            DWCi_StopLogin(dwcError, errorCode);
        break;
    case 4:
        errorCode += (int)0xfffec398;
        DWCi_StopMatch(dwcError, errorCode);
        break;
    default:
        errorCode += (int)0xfffe9c88;
        break;
    }
    DWCi_StopFriendProcess(dwcError, errorCode);
    return result;
}





/*
 * sdk:      DWCi_HandleGT2Error (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWCi_HandleGT2Error(int result)
{
	int dwcError;
	int errorCode;

	if (result == 0)
		return 0;
	switch (result) {
	case 1:
		dwcError = 9;
		errorCode = -1;
		break;
	case 2:
	case 5:
		dwcError = 0;
		errorCode = 0;
		result = 0;
		break;
	case 3:
		dwcError = 6;
		errorCode = -10;
		break;
	case 4:
		dwcError = 6;
		errorCode = -30;
		break;
	case 6:
		dwcError = 6;
		errorCode = -70;
		break;
	case 7:
		dwcError = 6;
		errorCode = -80;
		break;
	}
	if (dwcError != 0)
		DWCi_StopLogin(dwcError, errorCode - 67000);
	return result;
}





/*
 * DWCi_CloseConnectionHard: closes an aid's connection, or runs the closed path for a node with none.
 */
int DWCi_CloseConnectionHard(unsigned char aid)
{
    void *conn;
    DWCstNodeInfo *node;

    if (gDwcGlobalState.st == 0 || DWCi_IsError() != 0 ||
        (gDwcGlobalState.st->state != 4 &&
         gDwcGlobalState.st->state != 5)) {
        return -1;
    }
    conn = DWCi_GetGT2Connection(aid);
    if (conn == 0) {
        node = DWCi_NodeInfoList_GetNodeInfoForAID(aid);
        if (node == 0) {
            return -2;
        }
        DWCi_GT2ClosedProcess(0, 0, 1, node->aid);
        return 0;
    }
    gt2CloseConnectionHard((sptr)conn);
    return 0;
}





void DWCi_LoginCallback(int error, int profileID, void *param)
{
	if (error == 0) {
		gDwcGlobalState.st->profileID = profileID;
		DWCi_SetState(3);
		DWCi_InitGPProcessCount();
	} else {
		DWCi_SetState(0);
	}
	if (gDwcGlobalState.st->loginCallback != 0)
		gDwcGlobalState.st->loginCallback(error, profileID, gDwcGlobalState.st->loginParam);
}





void DWCi_UpdateServersCallback(int error, int isChanged)
{
    DWCstDwcCnt *p = gDwcGlobalState.st;

    p->updateCallback(error, isChanged, p->updateParam);
}





/*
 * sdk:      DWCi_MatchedCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index, void *param)
{
	if (error == 0 && cancel != 0) {
		if (gDwcGlobalState.st->match.state == 0) {
			DWCi_SetState(3);
			DWCi_ClearQR2Key();
		}
	} else if (error == 0) {
		DWCi_SetState(5);
	}
	if (gDwcGlobalState.st->match.cancelFromConnection == 0)
		((void (*)(int, int, int, int, int, void *))gDwcGlobalState.st->matchedCallback)(error, cancel, self, isServer, index, gDwcGlobalState.st->matchedParam);
	if (error != 0 && gDwcGlobalState.st != 0 && (unsigned int)(gDwcGlobalState.st->state - 4) <= 1)
		DWCi_SetState(3);
}





void DWCi_GPErrorCallback(void **pconnection, void *arg, void *param)
{
    int v = ((GPErrorArg *)arg)->errorCode;

    if (v == 0x603 || v == 0x901 || v == 0xb01) return;
    DWCi_HandleGPError(3);
}




/*
 * sdk:      DWCi_GPRecvBuddyMessageCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void DWCi_GPRecvBuddyMessageCallback(void **pconnection, GPRecvBuddyMessageArg *arg)
{
    unsigned long len;
    char *message;
    char version[12] = {0};

    message = arg->message;
    if (memcmp(message, gDwcPrefixGpcm, strlen(gDwcPrefixGpcm)) != 0)
        return;
    message += strlen(gDwcPrefixGpcm);
    len = strchr(message, 'v') - message;
    strncpy(version, message, len);
    if (len > 10)
        return;
    if (strtoul(version, 0, 10) != 90)
        return;
    message += len + 1;
    if (memcmp(message, gDwcPrefixMat, strlen(gDwcPrefixMat)) != 0)
        return;
    if (gDwcGlobalState.st->state != 4) {
        if (gDwcGlobalState.st->state != 5)
            return;
        /* stand-in: the image reloads qr2MatchType for each compare */
        if (*(volatile u8 *)&gDwcGlobalState.st->match.qr2MatchType != 2 && *(volatile u8 *)&gDwcGlobalState.st->match.qr2MatchType != 3)
            return;
    }
    DWCi_MatchGPRecvBuddyMsgCallback((sptr)pconnection, arg->profile, message + strlen(gDwcPrefixMat));
}


void DWCi_GT2ReceivedCallback(void *connection, unsigned char *message, int size, int reliable)
{
    DWCi_RecvCallback(connection, message, size, reliable);
}



/*
 * sdk:      DWCi_GT2ClosedProcess (libdwcmatch dwc_main.o, static)
 *
 * Reconstructed from the DWARF of the defining object (param/local names and
 * registers) plus the object disassembly.  Object stamp is 4.0.0.1025.
 *
 * Closed 2026-10-01 (wave 3 lane 11) by re-deriving semantics from branch
 * targets: the fb14 if/else chain sits after the `dwcError == 0` block (the
 * image's `bne` at +0080 lands on it), its last arm is an if/else with two
 * stores, the final NodeInfoList_GetCount()==1 test is `f2d != 0`, faf0 and
 * fab8 are 64-bit fields (two stores off one base), locals declared in DWARF
 * order with pNodeInfo scoped to the IsBackupMine block, and f365 is a
 * volatile byte field (the image re-reads it, `ldrbne`).
 */
void DWCi_GT2ClosedProcess(struct GTI2Connection *connection, int reason,
                           int isPseudClose, unsigned char closeAid)
{
    unsigned char aid;
    int profileID;
    int errorCode;
    int i;
    int isServer;
    int aidValid;
    DWCstConnectionInfo *conninfo;
    int dwcError;

    isServer = profileID = 0;

    if (DWCi_IsShutdownMatch())
        return;

    switch (reason) {
    case 0:
    case 1:
        errorCode = dwcError = profileID;
        break;
    case 2:
    case 3:
        dwcError = 6;
        errorCode = -7600;
        break;
    case 4:
        dwcError = 9;
        errorCode = -7601;
        break;
    }

    if (dwcError == 0) {
        if (!isPseudClose) {
            conninfo = (DWCstConnectionInfo *)gt2GetConnectionData(connection);
            if (conninfo == 0)
                return;
            aid = conninfo->aid;
        } else {
            aid = closeAid;
        }

        aidValid = DWCi_NodeInfoList_GetNodeInfoForAID(aid) != 0;

        if (!isPseudClose)
            DWCi_ClearTransConnection(aid);

        if (DWCi_NodeInfoList_GetServerNodeInfo() != 0) {
            if (aid == DWCi_NodeInfoList_GetServerNodeInfo()->aid)
                isServer = 1;
        }

        profileID = DWCi_DeleteAID(aid);
        gDwcGlobalState.st->match.suspendBitmap &= ~(1 << aid);

        if (gDwcGlobalState.st->match.suspendActive != 0 && isServer) {
            if (!DWCi_IsBackupMine())
                gDwcGlobalState.st->match.suspendRestart = 1;
        }

        i = 0;

        if (profileID == 0)
            profileID = ((DWCstConnectionInfo *)gt2GetConnectionData(DWCi_GetGT2Connection(aid)))->profileID;

        if (!isPseudClose)
            gDwcConnectionArray[conninfo->index] = 0;
    }

    if (gDwcGlobalState.st->match.isFirstServer == 1 && DWC_IsServerMyself())
        gDwcGlobalState.st->match.isFirstServer = 1;
    /* stand-in: the image reloads qr2MatchTypeExt for each compare */
    else if ((*(volatile u8 *)&gDwcGlobalState.st->match.qr2MatchTypeExt == 3 || *(volatile u8 *)&gDwcGlobalState.st->match.qr2MatchTypeExt == 2))
        gDwcGlobalState.st->match.isFirstServer = 0;
    else if (DWC_GetNumConnectionHost() == 1)
        gDwcGlobalState.st->match.isFirstServer = 1;
    else
        gDwcGlobalState.st->match.isFirstServer = 0;

    if (DWCi_IsBackupMine()) {
        DWCstNodeInfo *pNodeInfo;

        gDwcGlobalState.st->match.serverDownBase = 0;

        for (i = 0; i < DWCi_NodeInfoList_GetCount(); ) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);

            if (pNodeInfo->profileID != gDwcGlobalState.st->match.profileID &&
                DWCi_GetGT2Connection(pNodeInfo->aid) == 0) {
                if (gDwcGlobalState.st->closedCallback != 0) {
                    gDwcGlobalState.st->closedCallback(dwcError, reason == 0, isServer,
                                          pNodeInfo->aid,
                                          DWCi_GetFriendListIndex(pNodeInfo->profileID),
                                          gDwcGlobalState.st->closedParam);
                }
                DWCi_DeleteAID(pNodeInfo->aid);
            } else {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                gDwcGlobalState.st->match.serverDownBase |= 1 << pNodeInfo->aid;
                i++;
            }
        }
    }

    if (reason != 0 && DWC_IsServerMyself() == 1) {
        gDwcGlobalState.st->match.serverPollingTime = 0;

        if (DWCi_IsFullMesh()) {
            if (gDwcGlobalState.st->match.state == 0x10 && gDwcGlobalState.st->match.cmdCnt.command == 8) {
                gDwcGlobalState.st->match.cmdCnt.sendTime = 0;
            }
        }
    }

    if (gDwcGlobalState.st->closeAllHard == 0 && gDwcGlobalState.st->state == 5 && aidValid == 0) {
        if (!(gDwcGlobalState.st->match.qr2MatchType == 2 && dwcError == 0))
            return;

        DWCi_GPSetServerStatus(-1);
        DWCi_ProcessMatchSCClosing(profileID);
        return;
    }

    if (DWCi_ProcessMatchClosing(dwcError, errorCode, profileID) != 0)
        return;

    i = 0;

    if (dwcError != 0) {
        DWCi_SetError(dwcError, errorCode - 80000);
        return;
    }

    if (gDwcGlobalState.st->match.qr2MatchType == 2) {
        if (gDwcGlobalState.st->closeAllHard == 0)
            DWCi_GPSetServerStatus(-1);
        else if (DWCi_NodeInfoList_GetCount() == 1)
            DWCi_GPSetServerStatus(1);
    } else if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GPSetServerStatus(1);
    }

    if (gDwcGlobalState.st->match.qr2HostState == 2)
        qr2_send_statechanged(gDwcGlobalState.st->match.qr2Obj);

    if (gDwcGlobalState.st->closedCallback != 0 && aidValid != 0) {
        gDwcGlobalState.st->closedCallback(dwcError, reason == 0, isServer, aid,
                              DWCi_GetFriendListIndex(profileID),
                              gDwcGlobalState.st->closedParam);
    }

    if (gDwcGlobalState.st->closeAllHard == 0 && gDwcGlobalState.st->match.qr2MatchType == 2)
        return;

    if (DWCi_StopMeshMaking() == 1)
        DWCi_SetMatchStatus(1);

    if (DWCi_NodeInfoList_GetCount() == 1) {
        if (gDwcGlobalState.st->closeAllHard != 0) {
            DWCi_NNFreeNegotiateList();
            DWCi_SetState(3);
            DWCi_ClearQR2Key();
            gDwcGlobalState.st->match.qr2HostState = 0;
        } else {
            DWCi_SetMatchStatus(0xb);
        }
        return;
    }

    if (gDwcGlobalState.st->match.qr2MatchType == 3 && isServer && DWCi_NodeInfoList_GetCount() >= 1) {
        if (DWCi_NodeInfoList_GetCount() == 1 && DWCi_IsServerChangeEnabled())
            DWCi_SetMatchStatus(0xb);
        else
            DWCi_SetMatchStatus(9);
    }
}



void DWCi_GT2ClosedCallback(void *connection, int reason)
{
    DWCi_GT2ClosedProcess(connection, reason, 0, 0xff);
}


void DWCi_GT2PingCallback(void *connection, int latency)
{
    DWCi_PingCallback(connection, latency);
}


void DWCi_GT2SocketErrorCallback(void *socket)
{
    gDwcGlobalState.lastSocketError = GOAGetLastError(gt2GetSocketSOCKET(socket));
    DWCi_SetError(9, (int)0xfffe8515);
    *(int *)gDwcGlobalState.st = 0;
}



/*
 * Sets the match type byte and clears the connect group id.
 */
void DWCi_CustomCommonInit(unsigned char v)
{
    gDwcGlobalState.st->match.qr2MatchTypeExt = v;
    gDwcGlobalState.st->match.connectGroupID = 0;
}



unsigned char DWCi_GetServerOrSubServerAID(void)
{
    unsigned char aid = DWC_GetServerAID();
    if (aid == 0xff) {
        DWCstNodeInfo *info = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
        if (info != 0) aid = info->aid;
    }
    return aid;
}



/*
 * 1 unless the match type is not 2 and the match control's byte at +0x0D is zero.
 */
int DWCi_IsGetAIDValid(void)
{
    int r = 1;
    DWCstDwcCnt *p = gDwcGlobalState.st;

    if (p->match.qr2MatchTypeExt != 2)
        if (p->match.connectionEstablished == 0) r = 0;
    return r;
}
