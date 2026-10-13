/*
 * file:     unit_0216AB20.c
 * unit:     yes
 * function: DWC_InitFriendsMatch, DWC_ShutdownFriendsMatch, DWC_ProcessFriendsMatch, DWC_LoginAsync, DWC_UpdateServersAsync, DWC_ConnectToAnybodyAsync, DWC_SetupGameServer, DWC_ConnectToGameServerAsync, DWC_SetConnectionClosedCallback, DWC_CloseAllConnectionsHard, DWC_CloseConnectionHardFromServer, DWC_GetNumConnectionHost, DWC_GetMyAID, DWC_GetAIDList, DWC_GetAIDBitmap, DWC_IsValidAID, DWC_GetState, DWC_GetServerAID, DWC_IsServerMyself, DWCi_GT2Startup, func_0216BAF4, DWCi_GetConnectionAID, DWCi_GT2GetConnectionListIdx, DWCi_ClearGT2ConnectionList, DWCi_GetGT2ConnectionByIdx, func_0216BBDC, DWCi_GetConnectionInfoByIdx, DWCi_IsValidAID, DWCi_SetState, DWCi_DeleteAID, DWCi_GetAIDBitmapFromList, func_0216BD04, func_0216BE00, DWCi_CloseConnectionHard, DWCi_LoginCallback, DWCi_UpdateServersCallback, DWCi_MatchedCallback, DWCi_GPErrorCallback, func_0216C0C4, DWCi_GT2ReceivedCallback, DWCi_GT2ClosedProcess, DWCi_GT2ClosedCallback, DWCi_GT2PingCallback, DWCi_GT2SocketErrorCallback, DWCi_CustomCommonInit, DWCi_GetServerOrSubServerAID, DWCi_IsGetAIDValid
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
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "dwc_cnt_types.h"

struct GTI2Connection;

typedef struct GPBuddyStatus_
{
    int profile;                                    /* +0x00 */
    int status;                                     /* +0x04 */
    char statusString[256];                         /* +0x08 */
    char locationString[256];                       /* +0x108 */
    unsigned int ip;                                /* +0x208 */
    int port;                                       /* +0x20c */
    int quietModeFlags;                             /* +0x210 */
} GPBuddyStatus;

typedef struct {
    int result;
    int errorCode;
    int fatal;
} GPErrorArg;

typedef struct {
    int profile;
    int pad4;
    char *message;
} GPRecvBuddyMessageArg;

extern void *DWC_Alloc(int name, unsigned long size);
extern void MI_CpuFill8(void *dstp, u8 data, unsigned long size);
extern void DWC_ClearError(void);
extern void DWCi_LoginInit(DWCstLoginControl *logcnt, DWCstAccUserData *userdata,
                           void **pGpObj, int productID, u32 gamecode,
                           u16 *playerName,
                           void (*callback)(int, int, void *), void *param);
extern void DWCi_FriendInit(void *friendcnt, void **pGpObj,
                            u16 *playerName, void *friendList,
                            int friendListLen);
extern void DWCi_MatchInit(DWCstMatchControl *matchcnt, void **pGpObj, void **pGt2Socket,
                           DWCstGt2Callbacks *gt2Callbacks, char *gameName, char *secretKey,
                           void *friendList, int friendListLen);
extern void DWCi_InitTransport(void *info);
extern unsigned long strlen(const char *s);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void MIi_CpuClear32(unsigned long data, void *destp, unsigned long size);
extern void func_0219B540(qr2_implementation_s *qrec);
extern void func_0219ED4C(void *sb);
extern void func_02176B34(void);
extern void func_02169FF8(void);
extern void func_02193D00(void);
extern void func_0216A00C(void);
extern int func_0218597C(void **conn, int func, void *callback, void *param);
extern int func_02185948(void **conn);
extern void func_0218592C(void **p);
extern void func_0216A404(void);
extern void func_021691FC(void);
extern void func_0216F334(void);
extern void func_0217772C(void);
extern void func_02195AD8(void *socket);
extern int DWC_UpdateConnection(void);
extern int DWCi_IsError(void);
extern int GSIAvailableCheckThink(void);
extern int gpInitialize(void **connection, int productID, int namespaceID, int partnerID);
extern int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param);
extern int DWCi_LoginAsync(void);
extern void DWCi_StopLogin(int error, int errorCode);
extern void DWCi_LoginProcess(void);
extern void DWCi_FriendProcess(void);
extern void DWCi_MatchProcess(int fullSpec);
extern void DWCi_TransportProcess(void);
extern void qr2_shutdown(void *qrec);
extern void DWCi_GPErrorCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyMessageCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyAuthCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyRequestCallback(void **, void *, void *);
extern void DWCi_GPRecvBuddyStatusCallback(void **, void *, void *);
extern int func_02059F38(void);
extern void MIi_CpuClear16(u16 data, void *destp, u32 size);
extern int func_021686E0(unsigned short *p);
extern void MIi_CpuCopy16(void *srcp, void *destp, u32 size);
extern int func_0205CA20(void);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0217C750(char *gamename);
extern int func_02168D7C(void);
extern void func_02168DA4(char *authToken, char *partnerChallenge, void (*callback)(int, int), int a3, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
extern void func_0216D138(int topology, unsigned char numEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
extern int DWCi_GetProfileIDFromList(int index);
extern int gpIsBuddy(void **connection, int profile);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
extern int DWCi_IsLockedBuddyStatus(GPBuddyStatus *status);
extern int DWC_GetCommonValueString(char *key, char *value, char *string, char separator);
extern unsigned long strtoul(const char *nptr, char **endptr, int base);
extern void DWCi_CustomCommonInit(u8 matchType);
extern void DWCi_ConnectToGameServerAsync(
    int topology, int serverPid,
    void (*matchedCallback)(int, int, int, int, int, void *),
    void *matchedParam, void (*newClientCallback)(int, void *),
    void *newClientParam, int (*attemptCallback)(unsigned char *, void *),
    unsigned char *connectionUserData, void *attemptParam);
extern void DWCi_SetError(int error, int errorCode);
extern int DWCi_GPSetServerStatus(int matchType);
extern int DWC_CancelMatch(void);
extern int func_0216F20C(int status);
extern void DWCi_NNFreeNegotiateList(void);
extern void DWCi_ClearQR2Key(void);
extern void func_0217601C(void);
extern void func_02175F4C(int state);
extern void func_0216F6C0(void);
extern void func_02195DE4(int *p);
extern DWCstNodeInfo *func_021763AC(int pid);
extern unsigned long func_021685CC(unsigned long max);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_02195AB4(void **socket, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void *callback);
extern void gt2Listen(void *socket, void *callback);
extern void gt2SetUnrecognizedMessageCallback(void *socket, void *callback);
extern void DWCi_GT2SocketErrorCallback(void *socket);
extern void func_0216E5B0();
extern int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern int func_02176164(unsigned char aid);
extern void func_0216EB68(int error, int errorCode);
extern void func_02168E50(int error, int errorCode);
extern void func_02195DC4(void *conn);
extern void func_0216909C(void);
extern void func_0216EC18(void);
extern int memcmp(const void *a, const void *b, unsigned long n);
extern char *strchr(const char *s, int c);
extern char *strncpy(char *d, const char *s, unsigned long n);
extern void func_0216EAB8(void **pconnection, int profileID, char *message);
extern void func_02177340(void *connection, unsigned char *message, int size, int reliable);
extern int DWCi_IsShutdownMatch(void);
extern DWCstConnectionInfo *gt2GetConnectionData(void *connection);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void DWCi_ClearTransConnection(unsigned char aid);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern int DWCi_IsBackupMine(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern int DWCi_GetFriendListIndex(int profileID);
extern int DWCi_IsFullMesh(void);
extern void DWCi_ProcessMatchSCClosing(int clientPid);
extern int DWCi_ProcessMatchClosing(int error, int errorCode, int profileID);
extern void qr2_send_statechanged(void *qrec);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_IsServerChangeEnabled(void);
extern void func_02177398(void *connection, int latency);
extern int func_02195E60(const int *p);
extern int func_0217ED54(void);
extern void func_02059F54(int error, int errorCode);
extern void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);

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
void DWCi_CustomCommonInit(unsigned char v);
void DWCi_ClearGT2ConnectionList(void);
void DWCi_UpdateServersCallback(int error, int isChanged);
void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index, void *param);
void DWCi_LoginCallback(int error, int profileID, void *param);
void DWCi_GT2ConnectedCallback(void *connection, int result);
void DWCi_GT2ReceivedCallback(void *connection, unsigned char *message, int size, int reliable);
void DWCi_GT2ClosedCallback(void *connection, int reason);
void DWCi_GT2PingCallback(void *connection, int latency);
void DWCi_GT2ClosedProcess(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
void func_0216C0C4(void **pconnection, GPRecvBuddyMessageArg *arg);
int DWCi_GetAIDBitmapFromList(unsigned char *p, int n);
int func_0216BE00(int result);
int func_0216BD04(int result);
void DWCi_GT2SocketErrorCallback(void *socket);
unsigned char DWCi_GetServerOrSubServerAID(void);
int DWCi_DeleteAID(unsigned char aid);
extern char gcd_gamename[];
extern char gcd_secret_key[];
extern struct DwcGlobal g_021AA878;
extern char g_021A2028[];
extern char g_021A202C[];
extern char g_021A2030[];
extern char g_021A2038[];
extern void *g_021AA8A0[32];
extern unsigned char g_021AA880[];
extern char g_021AA920[];


void DWC_InitFriendsMatch(DWCstAccUserData *userdata, int productID,
                          char *secretKey, int sendBufSize, int recvBufSize,
                          void *friendList, int friendListLen)
{
    int len;

    g_021AA878.st = DWC_Alloc(4, sizeof(DWCstDwcCnt));
    MI_CpuFill8(g_021AA878.st, 0, sizeof(DWCstDwcCnt));
    DWC_ClearError();

    g_021AA878.st->gt2Socket = 0;
    g_021AA878.st->gt2Callbacks.connected = DWCi_GT2ConnectedCallback;
    g_021AA878.st->gt2Callbacks.received = DWCi_GT2ReceivedCallback;
    g_021AA878.st->gt2Callbacks.closed = DWCi_GT2ClosedCallback;
    g_021AA878.st->gt2Callbacks.ping = DWCi_GT2PingCallback;
    g_021AA878.st->sendBufSize =
        sendBufSize == 0 ? 0x2000 : (unsigned long)sendBufSize;
    g_021AA878.st->recvBufSize =
        recvBufSize == 0 ? 0x2000 : (unsigned long)recvBufSize;
    g_021AA878.st->gp = 0;
    g_021AA878.st->userdata = userdata;
    g_021AA878.st->state = 0;
    g_021AA878.st->prevState = 0;
    g_021AA878.st->closeAllHard = 0;
    g_021AA878.st->profileID = 0;
    g_021AA878.st->gameName = gcd_gamename;
    g_021AA878.st->secretKey = gcd_secret_key;
    g_021AA878.st->loginCallback = 0;
    g_021AA878.st->loginParam = 0;
    g_021AA878.st->updateCallback = 0;
    g_021AA878.st->updateParam = 0;
    g_021AA878.st->matchedCallback = 0;
    g_021AA878.st->matchedParam = 0;
    g_021AA878.st->closedCallback = 0;
    g_021AA878.st->closedParam = 0;

    DWCi_ClearGT2ConnectionList();

    DWCi_LoginInit(&g_021AA878.st->login, userdata,
                   &g_021AA878.st->gp, productID, userdata->gamecode,
                   g_021AA878.st->playerName,
                   DWCi_LoginCallback, 0);

    DWCi_FriendInit(g_021AA878.st->friendCnt,
                    &g_021AA878.st->gp,
                    g_021AA878.st->playerName,
                    friendList, friendListLen);

    DWCi_MatchInit(&g_021AA878.st->match,
                   &g_021AA878.st->gp, &g_021AA878.st->gt2Socket,
                   &g_021AA878.st->gt2Callbacks, gcd_gamename,
                   gcd_secret_key, friendList, friendListLen);

    DWCi_InitTransport(g_021AA878.st->transInfo);

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
    if (g_021AA878.st == 0)
        return;
    if (g_021AA878.st->match.qr2Obj != 0) {
        func_0219B540(g_021AA878.st->match.qr2Obj);
        g_021AA878.st->match.qr2Obj = 0;
    }
    g_021AA878.st->match.qr2ShutdownReq = 0;
    if (g_021AA878.st->match.sbObj != 0) {
        func_0219ED4C(g_021AA878.st->match.sbObj);
        g_021AA878.st->match.sbObj = 0;
    }
    func_02176B34();
    func_02169FF8();
    func_02193D00();
    func_0216A00C();
    if (g_021AA878.st->gp != 0) {
        func_0218597C(&g_021AA878.st->gp, 0, 0, 0);
        func_0218597C(&g_021AA878.st->gp, 3, 0, 0);
        func_0218597C(&g_021AA878.st->gp, 1, 0, 0);
        func_0218597C(&g_021AA878.st->gp, 2, 0, 0);
        func_02185948(&g_021AA878.st->gp);
        func_0218592C(&g_021AA878.st->gp);
        g_021AA878.st->gp = 0;
    }
    func_0216A404();
    func_021691FC();
    func_0216F334();
    func_0217772C();
    if (g_021AA878.st->gt2Socket != 0) {
        func_02195AD8(g_021AA878.st->gt2Socket);
        g_021AA878.st->gt2Socket = 0;
    }
    func_0205A1B0(4, g_021AA878.st, 0);
    g_021AA878.st = 0;
}


void DWC_ProcessFriendsMatch(void)
{
    DWC_UpdateConnection();
    if (g_021AA878.st == 0 || g_021AA878.st->state == 0)
        return;
    if (DWCi_IsError())
        return;

    switch (g_021AA878.st->state)
    {
    case 0:
        break;
    case 1:
        switch (GSIAvailableCheckThink())
        {
        case 1:
            if (func_0216BD04(gpInitialize(&g_021AA878.st->gp,
                    g_021AA878.st->login.productID, 0x10, 0xb)))
                return;
            if (func_0216BD04(gpSetCallback(&g_021AA878.st->gp,
                    0, DWCi_GPErrorCallback, 0)))
                return;
            if (func_0216BD04(gpSetCallback(&g_021AA878.st->gp,
                    3, DWCi_GPRecvBuddyMessageCallback, 0)))
                return;
            if (func_0216BD04(gpSetCallback(&g_021AA878.st->gp,
                    7, DWCi_GPRecvBuddyAuthCallback, 0)))
                return;
            if (func_0216BD04(gpSetCallback(&g_021AA878.st->gp,
                    1, DWCi_GPRecvBuddyRequestCallback, 0)))
                return;
            if (func_0216BD04(gpSetCallback(&g_021AA878.st->gp,
                    2, DWCi_GPRecvBuddyStatusCallback, 0)))
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
        if (*(volatile u8 *)&g_021AA878.st->match.qr2MatchType == 2
                || *(volatile u8 *)&g_021AA878.st->match.qr2MatchType == 3)
            DWCi_MatchProcess(1);
        else if (*(int *)g_021AA878.st != 0)
            DWCi_MatchProcess(0);
        break;
    }

    if (g_021AA878.st->match.qr2ShutdownReq == 1)
    {
        if (g_021AA878.st->match.qr2Obj != 0)
        {
            qr2_shutdown(g_021AA878.st->match.qr2Obj);
            g_021AA878.st->match.qr2Obj = 0;
        }
        g_021AA878.st->match.qr2ShutdownReq = 0;
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
    if (func_02059F38() || g_021AA878.st->state != 0)
        return 0;
    g_021AA878.st->loginCallback = callback;
    g_021AA878.st->loginParam = param;
    if (!ingamesn || ingamesn[0] == 0) {
        len = 0;
    } else {
        MIi_CpuClear16(0, g_021AA878.st->playerName, 0x34);
        len = (u32)func_021686E0(ingamesn) > 25 ? 25 : (u32)func_021686E0(ingamesn);
        MIi_CpuCopy16(ingamesn, g_021AA878.st->playerName, len * 2);
    }
    g_021AA878.st->playerName[len] = 0;
    if (func_0205CA20() != 4) {
        func_0216A3B8(2, -60010);
        return 0;
    }
    DWCi_SetState(1);
    func_0217C750(g_021AA878.st->gameName);
    return 1;
}




/*
 * sdk:      DWC_UpdateServersAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWC_UpdateServersAsync(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam)
{
	if (func_02059F38() || g_021AA878.st->state < 3 || func_02168D7C())
		return 0;
	g_021AA878.st->updateCallback = updateCallback;
	g_021AA878.st->updateParam = updateParam;
	func_02168DA4(g_021AA878.st->login.authToken, g_021AA878.st->login.partnerChallenge, DWCi_UpdateServersCallback, 0, statusCallback, statusParam, deleteCallback, deleteParam);
	return 1;
}




/*
 * sdk:      DWC_ConnectToAnybodyAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWC_ConnectToAnybodyAsync(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (func_02059F38() || g_021AA878.st->state != 3)
		return 0;
	DWCi_ClearGT2ConnectionList();
	g_021AA878.st->matchedCallback = matchedCallback;
	g_021AA878.st->matchedParam = matchedParam;
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
	if (func_02059F38() || g_021AA878.st->state != 3)
		return 0;
	DWCi_ClearGT2ConnectionList();
	g_021AA878.st->matchedCallback = matchedCallback;
	g_021AA878.st->matchedParam = matchedParam;
	DWCi_SetState(4);
	DWCi_CustomCommonInit(2);
	func_0216D138(topology, (unsigned char)(maxEntry - 1), DWCi_MatchedCallback, 0, newClientCallback, newClientParam, attemptCallback, connectionUserData, attemptParam);
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

    if (DWCi_IsError() || g_021AA878.st->state != 3)
        return 0;

    DWCi_ClearGT2ConnectionList();
    g_021AA878.st->matchedCallback = matchedCallback;
    g_021AA878.st->matchedParam = matchedParam;
    DWCi_SetState(4);

    dwcError = DWCi_GetProfileIDFromList(serverIndex);
    if (dwcError == 0 || !gpIsBuddy(&g_021AA878.st->gp, dwcError))
    {
        dwcError = 0xb;
        goto error;
    }

    gpGetBuddyIndex(&g_021AA878.st->gp, dwcError, &buddyIdx);
    gpGetBuddyStatus(&g_021AA878.st->gp, buddyIdx, &status);
    if (status.status != 6)
    {
        dwcError = 0xb;
        goto error;
    }

    valueStr[0] = 0x30;
    if (DWCi_IsLockedBuddyStatus(&status))
    {
        dwcError = 0x15;
        goto error;
    }

    DWC_GetCommonValueString(g_021A2028, valueStr, status.statusString, 0x2f);
    maxEntry = (unsigned char)strtoul(valueStr, 0, 10);
    DWC_GetCommonValueString(g_021A202C, valueStr, status.statusString, 0x2f);
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
    g_021AA878.st->matchedCallback(dwcError, 0, 1, 0, 0,
                                    g_021AA878.st->matchedParam);
    if (g_021AA878.st != 0 && g_021AA878.st->state == 4)
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
    if (g_021AA878.st == 0)
        return 0;
    g_021AA878.st->closedCallback = callback;
    g_021AA878.st->closedParam = param;
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

    g_021AA878.st->match.cancelFromConnection = 1;
    if (DWC_CancelMatch())
        return 1;
    if (g_021AA878.st == 0 || func_02059F38() ||
        (g_021AA878.st->state != 4 && g_021AA878.st->state != 5))
        return -1;
    for (i = 0; i < 32; i++) {
        if (g_021AA8A0[i] != 0) {
            anyGT2ConnectionExist = 1;
            break;
        }
    }
    if (anyGT2ConnectionExist == 0) {
        DWCi_NodeInfoList_GetCount();
        func_0216F20C(1);
        DWCi_NNFreeNegotiateList();
        DWCi_SetState(3);
        DWCi_ClearQR2Key();
        func_0217601C();
        func_02175F4C(0);
        func_0216F6C0();
        return 1;
    }
    g_021AA878.st->closeAllHard = 1;
    func_02195DE4((int *)g_021AA878.st->gt2Socket);
    while (DWCi_NodeInfoList_GetCount() > 1) {
        for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
            if (pNodeInfo->profileID != g_021AA878.st->profileID)
                DWCi_GT2ClosedProcess(0, 0, 1, pNodeInfo->aid);
        }
    }
    g_021AA878.st->closeAllHard = 0;
    func_0217601C();
    func_02175F4C(0);
    func_0216F6C0();
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

    if (g_021AA878.st == 0 || DWCi_IsGetAIDValid() == 0) {
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

    if (g_021AA878.st == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0xff;
    }
    node = func_021763AC(g_021AA878.st->profileID);
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

    if (g_021AA878.st == 0 || DWCi_IsGetAIDValid() == 0) {
        return 0;
    }
    MI_CpuFill8(g_021AA880, 0, 0x20);
    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
        g_021AA880[i] = DWCi_NodeInfoList_GetNodeInfoForIndex(i)->aid;
    }
    *out = g_021AA880;
    return DWCi_NodeInfoList_GetCount();
}



/*
 * DWC_GetAIDBitmap: the bitmap of every aid in the current node list.
 */
int DWC_GetAIDBitmap(void)
{
    unsigned char *list;
    int n;

    if (g_021AA878.st == 0 || DWCi_IsGetAIDValid() == 0) {
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
	if (g_021AA878.st == 0)
		return 0;
	if (aid == DWC_GetMyAID())
		return 0;
	if (DWCi_NodeInfoList_GetNodeInfoForAID(aid))
		return 1;
	return 0;
}



int DWC_GetState(void)
{
    DWCstDwcCnt *p = g_021AA878.st;

    return p != 0 ? p->state : 0;
}



/*
 * DWC_GetServerAID: the aid of node 0 while a match is running, else 0xff.
 */
unsigned char DWC_GetServerAID(void)
{
    DWCstDwcCnt *p = g_021AA878.st;
    DWCstNodeInfo *node;

    if (p == 0 || p->match.state == 0 || p->match.state == 9 ||
        p->match.state == 10 || p->match.state == 11 ||
        p->match.f_00D == 0 || p->match.qr2HostState == 0) {
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
    if (g_021AA878.st == 0) {
        return 0;
    }
    if (DWC_GetServerAID() == 0xff) {
        return 0;
    }
    return g_021AA878.st->match.qr2HostState == 2;
}



/*
 * sdk:      DWCi_GT2Startup (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWCi_GT2Startup(void)
{
	int gt2Result;
	unsigned short baseport;

	if (g_021AA878.st->gt2Socket != 0)
		return 0;
	baseport = func_021685CC(0x4000) + 0xc000;
	gt2Result = func_02195AB4(&g_021AA878.st->gt2Socket, func_02198620(0, baseport, 0), g_021AA878.st->sendBufSize, g_021AA878.st->recvBufSize, DWCi_GT2SocketErrorCallback);
	if (func_0216BE00(gt2Result))
		return gt2Result;
	gt2Listen(g_021AA878.st->gt2Socket, func_0216E5B0);
	gt2SetUnrecognizedMessageCallback(g_021AA878.st->gt2Socket, func_0216E4C0);
	return gt2Result;
}



/*
 * func_0216BAF4: the connection whose aid matches, or zero.
 */
void *func_0216BAF4(unsigned char aid)
{
    int i;

    if (g_021AA878.st == 0) {
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (g_021AA8A0[i] != 0 && aid == gt2GetConnectionData(g_021AA8A0[i])->aid) {
            return g_021AA8A0[i];
        }
    }
    return 0;
}



/*
 * Byte at +1 of the block, or 0xff when there is none.
 */
int DWCi_GetConnectionAID(void *connection)
{
    DWCstConnectionInfo *info = gt2GetConnectionData(connection);

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
        if (g_021AA8A0[i] == 0) return i;
    return -1;
}


void DWCi_ClearGT2ConnectionList(void)
{
    MIi_CpuClear32(0, g_021AA8A0, 0x80);
    MIi_CpuClear32(0, g_021AA920, 0x100);
}


/*
 * Address of the i-th word of the table.
 */
void **DWCi_GetGT2ConnectionByIdx(int i)
{
    return &g_021AA8A0[i];
}


/*
 * DWCi_GetGT2ConnectionByProfileID: the connection slot whose peer profile id matches, or null.
 */
void **func_0216BBDC(int pid, int flag)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (g_021AA8A0[i] != 0 && pid == gt2GetConnectionData(g_021AA8A0[i])->profileID) {
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
    return g_021AA920 + i * 8;
}


/*
 * sdk:      DWCi_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int DWCi_IsValidAID(unsigned char aid)
{
	int i;

	for (i = 0; i < 0x20; i++) {
		if (g_021AA8A0[i] != 0) {
			if (aid == gt2GetConnectionData(g_021AA8A0[i])->aid)
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
    g_021AA878.st->prevState = g_021AA878.st->state;
    g_021AA878.st->state = v;
}





int DWCi_DeleteAID(unsigned char aid)
{
    DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForAID(aid);
    int profileID;

    if (pNodeInfo == 0) return 0;
    profileID = pNodeInfo->profileID;
    func_02176164(aid);
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
int func_0216BD04(int result)
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
    switch (g_021AA878.st->state) {
    case 1:
        errorCode += (int)0xffff11b8;
        func_0216A3B8(dwcError, errorCode);
        break;
    case 2:
        errorCode += (int)0xffff11b8;
        if (g_021AA878.st->login.state < 1)
            func_0216A3B8(dwcError, errorCode);
        break;
    case 4:
        errorCode += (int)0xfffec398;
        func_0216EB68(dwcError, errorCode);
        break;
    default:
        errorCode += (int)0xfffe9c88;
        break;
    }
    func_02168E50(dwcError, errorCode);
    return result;
}





/*
 * sdk:      DWCi_HandleGT2Error (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216BE00(int result)
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
		func_0216A3B8(dwcError, errorCode - 67000);
	return result;
}





/*
 * DWCi_CloseConnectionHard: closes an aid's connection, or runs the closed path for a node with none.
 */
int DWCi_CloseConnectionHard(unsigned char aid)
{
    void *conn;
    DWCstNodeInfo *node;

    if (g_021AA878.st == 0 || func_02059F38() != 0 ||
        (g_021AA878.st->state != 4 &&
         g_021AA878.st->state != 5)) {
        return -1;
    }
    conn = func_0216BAF4(aid);
    if (conn == 0) {
        node = DWCi_NodeInfoList_GetNodeInfoForAID(aid);
        if (node == 0) {
            return -2;
        }
        DWCi_GT2ClosedProcess(0, 0, 1, node->aid);
        return 0;
    }
    func_02195DC4(conn);
    return 0;
}





void DWCi_LoginCallback(int error, int profileID, void *param)
{
	if (error == 0) {
		g_021AA878.st->profileID = profileID;
		DWCi_SetState(3);
		func_0216909C();
	} else {
		DWCi_SetState(0);
	}
	if (g_021AA878.st->loginCallback != 0)
		g_021AA878.st->loginCallback(error, profileID, g_021AA878.st->loginParam);
}





void DWCi_UpdateServersCallback(int error, int isChanged)
{
    DWCstDwcCnt *p = g_021AA878.st;

    p->updateCallback(error, isChanged, p->updateParam);
}





/*
 * sdk:      DWCi_MatchedCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void DWCi_MatchedCallback(int error, int cancel, int self, int isServer, int index, void *param)
{
	if (error == 0 && cancel != 0) {
		if (g_021AA878.st->match.state == 0) {
			DWCi_SetState(3);
			func_0216EC18();
		}
	} else if (error == 0) {
		DWCi_SetState(5);
	}
	if (g_021AA878.st->match.cancelFromConnection == 0)
		((void (*)(int, int, int, int, int, void *))g_021AA878.st->matchedCallback)(error, cancel, self, isServer, index, g_021AA878.st->matchedParam);
	if (error != 0 && g_021AA878.st != 0 && (unsigned int)(g_021AA878.st->state - 4) <= 1)
		DWCi_SetState(3);
}





void DWCi_GPErrorCallback(void **pconnection, void *arg, void *param)
{
    int v = ((GPErrorArg *)arg)->errorCode;

    if (v == 0x603 || v == 0x901 || v == 0xb01) return;
    func_0216BD04(3);
}




/*
 * sdk:      DWCi_GPRecvBuddyMessageCallback (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
void func_0216C0C4(void **pconnection, GPRecvBuddyMessageArg *arg)
{
    unsigned long len;
    char *message;
    char version[12] = {0};

    message = arg->message;
    if (memcmp(message, g_021A2030, strlen(g_021A2030)) != 0)
        return;
    message += strlen(g_021A2030);
    len = strchr(message, 'v') - message;
    strncpy(version, message, len);
    if (len > 10)
        return;
    if (strtoul(version, 0, 10) != 90)
        return;
    message += len + 1;
    if (memcmp(message, g_021A2038, strlen(g_021A2038)) != 0)
        return;
    if (g_021AA878.st->state != 4) {
        if (g_021AA878.st->state != 5)
            return;
        /* stand-in: the image reloads qr2MatchType for each compare */
        if (*(volatile u8 *)&g_021AA878.st->match.qr2MatchType != 2 && *(volatile u8 *)&g_021AA878.st->match.qr2MatchType != 3)
            return;
    }
    func_0216EAB8(pconnection, arg->profile, message + strlen(g_021A2038));
}


void DWCi_GT2ReceivedCallback(void *connection, unsigned char *message, int size, int reliable)
{
    func_02177340(connection, message, size, reliable);
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
            conninfo = gt2GetConnectionData(connection);
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
        g_021AA878.st->match.suspendBitmap &= ~(1 << aid);

        if (g_021AA878.st->match.f_048 != 0 && isServer) {
            if (!DWCi_IsBackupMine())
                g_021AA878.st->match.suspendRestart = 1;
        }

        i = 0;

        if (profileID == 0)
            profileID = gt2GetConnectionData(func_0216BAF4(aid))->profileID;

        if (!isPseudClose)
            g_021AA8A0[conninfo->index] = 0;
    }

    if (g_021AA878.st->match.flag7c4 == 1 && DWC_IsServerMyself())
        g_021AA878.st->match.flag7c4 = 1;
    /* stand-in: the image reloads qr2MatchTypeExt for each compare */
    else if ((*(volatile u8 *)&g_021AA878.st->match.qr2MatchTypeExt == 3 || *(volatile u8 *)&g_021AA878.st->match.qr2MatchTypeExt == 2))
        g_021AA878.st->match.flag7c4 = 0;
    else if (DWC_GetNumConnectionHost() == 1)
        g_021AA878.st->match.flag7c4 = 1;
    else
        g_021AA878.st->match.flag7c4 = 0;

    if (DWCi_IsBackupMine()) {
        DWCstNodeInfo *pNodeInfo;

        g_021AA878.st->match.serverDownBase = 0;

        for (i = 0; i < DWCi_NodeInfoList_GetCount(); ) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);

            if (pNodeInfo->profileID != g_021AA878.st->match.profileID &&
                func_0216BAF4(pNodeInfo->aid) == 0) {
                if (g_021AA878.st->closedCallback != 0) {
                    g_021AA878.st->closedCallback(dwcError, reason == 0, isServer,
                                          pNodeInfo->aid,
                                          DWCi_GetFriendListIndex(pNodeInfo->profileID),
                                          g_021AA878.st->closedParam);
                }
                DWCi_DeleteAID(pNodeInfo->aid);
            } else {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                g_021AA878.st->match.serverDownBase |= 1 << pNodeInfo->aid;
                i++;
            }
        }
    }

    if (reason != 0 && DWC_IsServerMyself() == 1) {
        g_021AA878.st->match.serverPollingTime = 0;

        if (DWCi_IsFullMesh()) {
            if (g_021AA878.st->match.state == 0x10 && g_021AA878.st->match.cmdCnt.command == 8) {
                g_021AA878.st->match.cmdCnt.sendTime = 0;
            }
        }
    }

    if (g_021AA878.st->closeAllHard == 0 && g_021AA878.st->state == 5 && aidValid == 0) {
        if (!(g_021AA878.st->match.qr2MatchType == 2 && dwcError == 0))
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

    if (g_021AA878.st->match.qr2MatchType == 2) {
        if (g_021AA878.st->closeAllHard == 0)
            DWCi_GPSetServerStatus(-1);
        else if (DWCi_NodeInfoList_GetCount() == 1)
            DWCi_GPSetServerStatus(1);
    } else if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GPSetServerStatus(1);
    }

    if (g_021AA878.st->match.qr2HostState == 2)
        qr2_send_statechanged(g_021AA878.st->match.qr2Obj);

    if (g_021AA878.st->closedCallback != 0 && aidValid != 0) {
        g_021AA878.st->closedCallback(dwcError, reason == 0, isServer, aid,
                              DWCi_GetFriendListIndex(profileID),
                              g_021AA878.st->closedParam);
    }

    if (g_021AA878.st->closeAllHard == 0 && g_021AA878.st->match.qr2MatchType == 2)
        return;

    if (DWCi_StopMeshMaking() == 1)
        DWCi_SetMatchStatus(1);

    if (DWCi_NodeInfoList_GetCount() == 1) {
        if (g_021AA878.st->closeAllHard != 0) {
            DWCi_NNFreeNegotiateList();
            DWCi_SetState(3);
            DWCi_ClearQR2Key();
            g_021AA878.st->match.qr2HostState = 0;
        } else {
            DWCi_SetMatchStatus(0xb);
        }
        return;
    }

    if (g_021AA878.st->match.qr2MatchType == 3 && isServer && DWCi_NodeInfoList_GetCount() >= 1) {
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
    func_02177398(connection, latency);
}


void DWCi_GT2SocketErrorCallback(void *socket)
{
    func_02195E60(socket);
    g_021AA878.lastSocketError = func_0217ED54();
    func_02059F54(9, (int)0xfffe8515);
    *(int *)g_021AA878.st = 0;
}



/*
 * Sets the match type byte and clears the connect group id.
 */
void DWCi_CustomCommonInit(unsigned char v)
{
    g_021AA878.st->match.qr2MatchTypeExt = v;
    g_021AA878.st->match.connectGroupID = 0;
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
    DWCstDwcCnt *p = g_021AA878.st;

    if (p->match.qr2MatchTypeExt != 2)
        if (p->match.f_00D == 0) r = 0;
    return r;
}
