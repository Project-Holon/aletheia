/*
 * file:     unit_0216AB20_p02.c
 * unit:     yes
 * function: func_0216AE88, func_0216B0E0, func_0216B1E0, func_0216B284, func_0216B354, func_0216B408, func_0216B634, func_0216B65C, func_0216B7E0, func_0216B804, func_0216B838, func_0216B880, func_0216B908, func_0216B94C, func_0216B994, func_0216B9B0, func_0216BA08, func_0216BA4C, func_0216BAF4, func_0216BB54
 * address:  0x0216AE88
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWC_UpdateConnection               0x0205D074  arm
 *   DWCi_IsError                       0x02059F38  arm
 *   GSIAvailableCheckThink             0x0217C900  arm
 *   gpInitialize                       0x021858FC  arm
 *   DWCi_HandleGPError                 0x0216BD04  arm
 *   gpSetCallback                      0x0218597C  arm
 *   DWCi_SetState                      0x0216BC84  arm
 *   DWCi_LoginAsync                    0x0216A278  arm
 *   DWCi_StopLogin                     0x0216A3B8  arm
 *   DWCi_LoginProcess                  0x0216A2B0  arm
 *   DWCi_FriendProcess                 0x02168AD4  arm
 *   DWCi_MatchProcess                  0x0216D57C  arm
 *   DWCi_TransportProcess              0x021773D8  arm
 *   qr2_shutdown                       0x0219B540  arm
 *   stLastSocketError                  0x021AA878  data
 *   DWCi_GPErrorCallback               0x0216C08C  arm
 *   DWCi_GPRecvBuddyMessageCallback    0x0216C0C4  arm
 *   DWCi_GPRecvBuddyAuthCallback       0x02168F18  arm
 *   DWCi_GPRecvBuddyRequestCallback    0x02168ECC  arm
 *   DWCi_GPRecvBuddyStatusCallback     0x02168F4C  arm
 *   func_02059F38  0x02059F38  arm
 *   MIi_CpuClear16 0x02082A48  arm
 *   func_021686E0  0x021686E0  arm  ov009
 *   MIi_CpuCopy16  0x02082A60  arm
 *   func_0205CA20  0x0205CA20  arm
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   func_0216BC84  0x0216BC84  arm  ov009
 *   func_0217C750  0x0217C750  arm  ov009
 *   g_021AA878     0x021AA878  data
 *   func_02168D7C  0x02168D7C  arm  ov009
 *   func_02168DA4  0x02168DA4  arm  ov009
 *   func_0216BF98  0x0216BF98  arm  ov009
 *   func_0216BB98  0x0216BB98  arm  ov009
 *   func_0216C7E0  0x0216C7E0  arm  ov009
 *   func_0216CF1C  0x0216CF1C  arm  ov009
 *   func_0216BFB8  0x0216BFB8  arm  ov009
 *   func_0216D138  0x0216D138  arm  ov009
 *   DWCi_ClearGT2ConnectionList      0x0216bb98 arm
 *   DWCi_GetProfileIDFromList        0x02168ff0 arm
 *   gpIsBuddy                        0x021861a8 arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   gpGetBuddyStatus                 0x02185fd4 arm
 *   DWCi_IsLockedBuddyStatus         0x02176984 arm
 *   DWC_GetCommonValueString         0x021684cc arm
 *   strtoul                          0x02095eac arm
 *   DWCi_CustomCommonInit            0x0216c7e0 arm
 *   DWCi_ConnectToGameServerAsync    0x0216d27c arm
 *   DWCi_SetError                    0x02059f54 arm
 *   DWCi_GPSetServerStatus           0x0216f20c arm
 *   g_021A2028                       0x021a2028 data
 *   g_021A202C                       0x021a202c data
 *   DWCi_MatchedCallback             0x0216bfb8 arm
 *   DWC_CancelMatch              0x0216C858 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_0216F20C                0x0216F20C arm   ov009
 *   DWCi_NNFreeNegotiateList     0x02176B34 arm   ov009
 *   DWCi_ClearQR2Key             0x0216EC18 arm   ov009
 *   func_0217601C                0x0217601C arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_0216F6C0                0x0216F6C0 arm   ov009
 *   func_02195DE4                0x02195DE4 arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   func_0216C230                0x0216C230 arm   ov009
 *   g_021AA8A0                   0x021AA8A0 data
 *   func_0216BEA4  0x0216BEA4  arm  ov009
 *   func_0216C82C  0x0216C82C  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   g_021AA880  0x021AA880  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0216BCD0  0x0216BCD0  arm  ov009
 *   func_02176410  0x02176410  arm  ov009
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_02198620  0x02198620  arm  ov009
 *   func_02195AB4  0x02195AB4  arm  ov009
 *   func_0216BE00  0x0216BE00  arm  ov009
 *   func_02195B20  0x02195B20  arm  ov009
 *   func_02195E68  0x02195E68  arm  ov009
 *   func_0216C7A8  0x0216C7A8  arm  ov009
 *   func_0216E5B0  0x0216E5B0  arm  ov009
 *   func_0216E4C0  0x0216E4C0  arm  ov009
 *   func_02195E78  0x02195E78  arm  ov009
 */
#include "../../matched/include/G_DwcGlobal.h"

struct DWCstGlobal;
struct GTI2Connection;
typedef unsigned char u8;

struct DWCstDwcCnt
{
	int field0;
	void (*gt2Connected)(void);
	void (*gt2Received)(void);
	void (*gt2Closed)(void);
	void (*gt2Ping)(void);
	unsigned long sendBufSize;
	unsigned long recvBufSize;
	void *gp;
	struct DWCstAccUserData *userdata;
	int state;
	int field28;
	unsigned char pad2c[0x1];
	unsigned char flag2d;
	unsigned char pad2e[0x36];
	int field64;
	void *gameName;
	void *secretKey;
	int field70;
	int field74;
	int field78;
	int field7c;
	void (*field80)(int, int, int, int, int, void *);
	void *field84;
	int field88;
	int field8c;
	unsigned char pad90[0x8];
	int field98;
	unsigned char pad9c[0x2c4];
	void *qr2;
	volatile unsigned char status364;
	unsigned char pad365[0x37];
	unsigned char flag39c;
	unsigned char pad39d[0x3];
};

struct DWCstGlobal
{
    int lastSocketError;            /* +0x00 */
    struct DWCstDwcCnt *pDwc;       /* +0x04 */
};

typedef unsigned short u16;

typedef unsigned long u32_0216AB20;

typedef struct {
    char pad0[0x24];
    int state;
    char pad28[8];
    u16 ingamesn[0x1a];
    char pad64[4];
    char *gamename;
    char pad6c[4];
    void (*callback)(int, int, void *);
    void *param;
} Ctl;

typedef struct DwcState {
	void *gt2Socket;
	unsigned char pad4[0x10];
	int outSize;
	int inSize;
	unsigned char pad1c[0x8];
	int state;
	unsigned char pad28[0x3c];
	int profileID;
	unsigned char pad68[0x8];
	void (*loginCallback)(int, int, void *);
	void *loginParam;
	void *updateCallback;
	void *updateParam;
	void *matchedCallback;
	void *matchedParam;
	unsigned char pad88[0x50];
	unsigned char updateBuf0[0x100];
	unsigned char updateBuf1[0x100];
	unsigned char pad2d8[0x694];
	int a96c;
	unsigned char pad970[0x195];
	unsigned char b05;
	unsigned char padb06[0x2];
} DwcState;

typedef struct DwcGlobal DwcGlobal;

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

struct GT2Socket { int pad; };

struct DWCControl {
    struct GT2Socket *socket;
    u8 pad0[0x24 - 0x4];
    int state;
    u8 pad1[0x2d - 0x28];
    u8 f2d;
    u8 pad2[0x64 - 0x2e];
    int myProfileID;
    u8 pad3[0xb05 - 0x68];
    u8 fb05;
};

struct DWCstNodeInfo {
	int profileID;
	unsigned int publicInetAddress;
	unsigned int privateInetAddress;
	unsigned short publicQueryPort;
	unsigned short privateQueryPort;
	unsigned int gt2IP;
	unsigned short gt2Port;
	unsigned char aid;
	unsigned char hasPrivateAddress;
	int nnTryCount;
	unsigned long long nextMeshMakeTryTick;
	unsigned char connUserData[4];
};

typedef signed short   s16;

typedef signed char    s8;

extern int DWC_UpdateConnection(void);
extern int DWCi_IsError(void);
extern int GSIAvailableCheckThink(void);
extern int gpInitialize(void **connection, int productID, int namespaceID, int partnerID);
extern int DWCi_HandleGPError(int result);
extern int gpSetCallback(void **connection, int func, void (*callback)(void **, void *, void *), void *param);
extern void DWCi_SetState(int state);
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
extern void MIi_CpuClear16(u16 data, void *destp, u32_0216AB20 size);
extern int func_021686E0(unsigned short *p);
extern void MIi_CpuCopy16(void *srcp, void *destp, u32_0216AB20 size);
extern int func_0205CA20(void);
extern void func_0216A3B8(int error, int errorCode);
extern void func_0216BC84(int state);
extern void func_0217C750(char *gamename);
extern int func_02168D7C(void);
extern void func_02168DA4(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
extern void func_0216BF98(int error, int isChanged);
extern void func_0216BB98(void);
extern void func_0216C7E0(unsigned char matchType);
extern void func_0216CF1C(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
extern void func_0216BFB8(int error, int cancel, int self, int isServer, int index);
extern void func_0216D138(int p0, int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
extern void DWCi_ClearGT2ConnectionList(void);
extern int DWCi_GetProfileIDFromList(int index);
extern int gpIsBuddy(void **connection, int profile);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern int gpGetBuddyStatus(void **connection, int index, GPBuddyStatus *status);
extern int DWCi_IsLockedBuddyStatus(GPBuddyStatus *status);
extern int DWC_GetCommonValueString(char *key, char *value, char *string,
                                    char separator);
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
extern void DWCi_MatchedCallback(int error, int cancel, int self, int isServer,
                                 int index, void *param);
extern int DWC_CancelMatch(void);
extern int func_0217603C(void);
extern int func_0216F20C(int status);
extern void DWCi_NNFreeNegotiateList(void);
extern void DWCi_ClearQR2Key(void);
extern void func_0217601C(void);
extern void func_02175F4C(int state);
extern void func_0216F6C0(void);
extern void func_02195DE4(int *p);
extern unsigned char *func_0217637C(int index);
extern void func_0216C230(struct GTI2Connection *connection, int reason, int isPseudClose, unsigned char closeAid);
extern int func_0216C82C(void);
extern char *func_021763AC(int pid);
extern void MI_CpuFill8(void *p, int v, int n);
extern int func_0216BCD0(unsigned char *p, int n);
extern char *func_02176410(unsigned char aid);
extern unsigned long func_021685CC(unsigned long max);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_02195AB4(void **socket, char *localAddress, int outgoingBufferSize, int incomingBufferSize, void *callback);
extern int func_0216BE00(int result);
extern void func_02195B20(int *p, int v);
extern void func_02195E68(int *p, int v);
extern void func_0216C7A8(void *socket);
extern void func_0216E5B0();
extern int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern int func_02195E78(const int *p);
void DWC_ProcessFriendsMatch(void);
/* * sdk: DWC_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216B0E0(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param);
/* * sdk: DWC_UpdateServersAsync (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216B1E0(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam);
/* * sdk: DWC_ConnectToAnybodyAsync (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
/* * sdk: DWC_SetupGameServer (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam);
int DWC_ConnectToGameServerAsync( int topology, int serverIndex, void (*matchedCallback)(int, int, int, int, int, void *), void *matchedParam, void (*newClientCallback)(int, void *), void *newClientParam, int (*attemptCallback)(unsigned char *, void *), unsigned char *connectionUserData, void *attemptParam);
/* * Stores a at +0x88 and b at +0x8c of the current object; 0 when the block * is absent, 1 when it was written. */ int func_0216B634(int a, int b);
/* * sdk: DWC_CloseAllConnectionsHard (libdwcmatch.TWL.HYB.a dwc_main.o) */ int func_0216B65C(void);
/* * Returns -3 when func_0216BA08 rejects the pointer, else the func_0216BEA4 result. */ int func_0216B7E0(void *p);
int DWC_GetNumConnectionHost(void);
/* * DWC_GetMyAID: this host's aid, or 0xff when none is valid. */ unsigned char func_0216B838(void);
/* * DWC_GetAIDList: fills the static aid list from the node list and returns the node count. */ int func_0216B880(unsigned char **out);
/* * DWC_GetAIDBitmap: the bitmap of every aid in the current node list. */ int func_0216B908(void);
/* * sdk: DWC_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216B94C(unsigned char aid);
int func_0216B994(void);
/* * DWC_GetServerAID: the aid of node 0 while a match is running, else 0xff. */ unsigned char func_0216B9B0(void);
int func_0216BA08(void);
/* * sdk: DWCi_GT2Startup (libdwcmatch.TWL.HYB.a(dwc_main.o)) */ int func_0216BA4C(void);
/* * DWCi_GetGT2Connection: the connection whose aid matches, or zero. */ int func_0216BAF4(int aid);
/* * Byte at +1 of the block, or 0xff when there is none. */ int func_0216BB54(const int *a0);
extern struct DWCstGlobal stLastSocketError;
extern struct DwcGlobal g_021AA878;
extern char g_021A2028[];
extern char g_021A202C[];
extern int g_021AA8A0[];
extern unsigned char g_021AA880[];




void DWC_ProcessFriendsMatch(void)
{
    DWC_UpdateConnection();
    if (stLastSocketError.pDwc == 0 || stLastSocketError.pDwc->state == 0)
        return;
    if (DWCi_IsError())
        return;

    switch (stLastSocketError.pDwc->state)
    {
    case 0:
        break;
    case 1:
        switch (GSIAvailableCheckThink())
        {
        case 1:
            if (DWCi_HandleGPError(gpInitialize(&stLastSocketError.pDwc->gp,
                    stLastSocketError.pDwc->field98, 0x10, 0xb)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    0, DWCi_GPErrorCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    3, DWCi_GPRecvBuddyMessageCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    7, DWCi_GPRecvBuddyAuthCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
                    1, DWCi_GPRecvBuddyRequestCallback, 0)))
                return;
            if (DWCi_HandleGPError(gpSetCallback(&stLastSocketError.pDwc->gp,
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
        if (stLastSocketError.pDwc->status364 == 2
                || stLastSocketError.pDwc->status364 == 3)
            DWCi_MatchProcess(1);
        else if (*(int *)stLastSocketError.pDwc != 0)
            DWCi_MatchProcess(0);
        break;
    }

    if (stLastSocketError.pDwc->flag39c == 1)
    {
        if (stLastSocketError.pDwc->qr2 != 0)
        {
            qr2_shutdown(stLastSocketError.pDwc->qr2);
            stLastSocketError.pDwc->qr2 = 0;
        }
        stLastSocketError.pDwc->flag39c = 0;
    }
}




/*
 * sdk:      DWC_LoginAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B0E0(u16 *ingamesn, int reserved, void (*callback)(int, int, void *), void *param)
{
    u32_0216AB20 len;

    if (!ingamesn)
        return 0;
    if (func_02059F38() || ((Ctl *)g_021AA878.st)->state != 0)
        return 0;
    ((Ctl *)g_021AA878.st)->callback = callback;
    ((Ctl *)g_021AA878.st)->param = param;
    if (!ingamesn || ingamesn[0] == 0) {
        len = 0;
    } else {
        MIi_CpuClear16(0, ((Ctl *)g_021AA878.st)->ingamesn, 0x34);
        len = (u32_0216AB20)func_021686E0(ingamesn) > 25 ? 25 : (u32_0216AB20)func_021686E0(ingamesn);
        MIi_CpuCopy16(ingamesn, ((Ctl *)g_021AA878.st)->ingamesn, len * 2);
    }
    ((Ctl *)g_021AA878.st)->ingamesn[len] = 0;
    if (func_0205CA20() != 4) {
        func_0216A3B8(2, -60010);
        return 0;
    }
    func_0216BC84(1);
    func_0217C750(((Ctl *)g_021AA878.st)->gamename);
    return 1;
}




/*
 * sdk:      DWC_UpdateServersAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B1E0(int unused, void *updateCallback, void *updateParam, void *statusCallback, void *statusParam, void *deleteCallback, void *deleteParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state < 3 || func_02168D7C())
		return 0;
	((DwcState *)g_021AA878.st)->updateCallback = updateCallback;
	((DwcState *)g_021AA878.st)->updateParam = updateParam;
	func_02168DA4((int)((DwcState *)g_021AA878.st)->updateBuf0, (int)((DwcState *)g_021AA878.st)->updateBuf1, (int)func_0216BF98, 0, (int)statusCallback, (int)statusParam, (int)deleteCallback, (int)deleteParam);
	return 1;
}




/*
 * sdk:      DWC_ConnectToAnybodyAsync (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B284(int topology, unsigned char maxEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state != 3)
		return 0;
	func_0216BB98();
	((DwcState *)g_021AA878.st)->matchedCallback = matchedCallback;
	((DwcState *)g_021AA878.st)->matchedParam = matchedParam;
	func_0216BC84(4);
	func_0216C7E0(0);
	func_0216CF1C(topology, maxEntry - 1, addFilter, func_0216BFB8, 0, newClientCallback, newClientParam, evalCallback, evalParam, attemptCallback, connectionUserData, attemptParam);
	return 1;
}




/*
 * sdk:      DWC_SetupGameServer (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B354(int topology, unsigned char maxEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, void *connectionUserData, void *attemptParam)
{
	if (func_02059F38() || ((DwcState *)g_021AA878.st)->state != 3)
		return 0;
	func_0216BB98();
	((DwcState *)g_021AA878.st)->matchedCallback = matchedCallback;
	((DwcState *)g_021AA878.st)->matchedParam = matchedParam;
	func_0216BC84(4);
	func_0216C7E0(2);
	func_0216D138(topology, (unsigned char)(maxEntry - 1), (int)func_0216BFB8, 0, (int)newClientCallback, (int)newClientParam, (int)attemptCallback, (int)connectionUserData, (int)attemptParam);
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

    if (DWCi_IsError() || stLastSocketError.pDwc->state != 3)
        return 0;

    DWCi_ClearGT2ConnectionList();
    stLastSocketError.pDwc->field80 = matchedCallback;
    stLastSocketError.pDwc->field84 = matchedParam;
    DWCi_SetState(4);

    dwcError = DWCi_GetProfileIDFromList(serverIndex);
    if (dwcError == 0 || !gpIsBuddy(&stLastSocketError.pDwc->gp, dwcError))
    {
        dwcError = 0xb;
        goto error;
    }

    gpGetBuddyIndex(&stLastSocketError.pDwc->gp, dwcError, &buddyIdx);
    gpGetBuddyStatus(&stLastSocketError.pDwc->gp, buddyIdx, &status);
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
    stLastSocketError.pDwc->field80(dwcError, 0, 1, 0, 0,
                                    stLastSocketError.pDwc->field84);
    if (stLastSocketError.pDwc != 0 && stLastSocketError.pDwc->state == 4)
    {
        DWCi_SetState(3);
        DWCi_GPSetServerStatus(1);
    }
    return 1;
}




/*
 * Stores a at +0x88 and b at +0x8c of the current object; 0 when the block
 * is absent, 1 when it was written.
 */
int func_0216B634(int a, int b)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);

    if (p == 0) return 0;
    *(int *)(p + 0x88) = a;
    p = *(char **)(((char *)&g_021AA878) + 4);
    *(int *)(p + 0x8c) = b;
    return 1;
}




/*
 * sdk:      DWC_CloseAllConnectionsHard (libdwcmatch.TWL.HYB.a dwc_main.o)
 */
int func_0216B65C(void)
{
    struct DWCstNodeInfo *pNodeInfo;
    int i;
    int anyGT2ConnectionExist = 0;

    ((struct DWCControl *)g_021AA878.st)->fb05 = 1;
    if (DWC_CancelMatch())
        return 1;
    if (g_021AA878.st == 0 || func_02059F38() ||
        (((struct DWCControl *)g_021AA878.st)->state != 4 && ((struct DWCControl *)g_021AA878.st)->state != 5))
        return -1;
    for (i = 0; i < 32; i++) {
        if (g_021AA8A0[i] != 0) {
            anyGT2ConnectionExist = 1;
            break;
        }
    }
    if (anyGT2ConnectionExist == 0) {
        func_0217603C();
        func_0216F20C(1);
        DWCi_NNFreeNegotiateList();
        func_0216BC84(3);
        DWCi_ClearQR2Key();
        func_0217601C();
        func_02175F4C(0);
        func_0216F6C0();
        return 1;
    }
    ((struct DWCControl *)g_021AA878.st)->f2d = 1;
    func_02195DE4((int *)((struct DWCControl *)g_021AA878.st)->socket);
    while (func_0217603C() > 1) {
        for (i = 0; i < func_0217603C(); i++) {
            pNodeInfo = (struct DWCstNodeInfo *)func_0217637C(i);
            if (pNodeInfo->profileID != ((struct DWCControl *)g_021AA878.st)->myProfileID)
                func_0216C230(0, 0, 1, pNodeInfo->aid);
        }
    }
    ((struct DWCControl *)g_021AA878.st)->f2d = 0;
    func_0217601C();
    func_02175F4C(0);
    func_0216F6C0();
    if (func_0216B994() != 3) {
        DWCi_NNFreeNegotiateList();
        func_0216BC84(3);
        DWCi_ClearQR2Key();
    }
    return 0;
}




/*
 * Returns -3 when func_0216BA08 rejects the pointer, else the func_0216BEA4 result.
 */
int func_0216B7E0(void *p)
{
    int func_0216BA08(void);
    int func_0216BEA4(void *);
    if (func_0216BA08() == 0) return -3;
    return func_0216BEA4(p);
}



int DWC_GetNumConnectionHost(void)
{
    int num;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        num = 0;
    } else {
        num = func_0217603C();
    }
    return num;
}



/*
 * DWC_GetMyAID: this host's aid, or 0xff when none is valid.
 */
unsigned char func_0216B838(void)
{
    unsigned char *node;

    if (*(char **)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        return 0xff;
    }
    node = (unsigned char *)func_021763AC(*(int *)(*(char **)(((char *)&g_021AA878) + 4) + 0x64));
    if (node == 0) {
        return 0xff;
    }
    return node[0x16];
}



/*
 * DWC_GetAIDList: fills the static aid list from the node list and returns the node count.
 */
int func_0216B880(unsigned char **out)
{
    int i;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        return 0;
    }
    MI_CpuFill8(g_021AA880, 0, 0x20);
    for (i = 0; i < func_0217603C(); i++) {
        g_021AA880[i] = func_0217637C(i)[0x16];
    }
    *out = g_021AA880;
    return func_0217603C();
}



/*
 * DWC_GetAIDBitmap: the bitmap of every aid in the current node list.
 */
int func_0216B908(void)
{
    unsigned char *list;
    int n;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0 || func_0216C82C() == 0) {
        return 0;
    }
    n = func_0216B880(&list);
    return func_0216BCD0(list, n);
}



/*
 * sdk:      DWC_IsValidAID (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216B94C(unsigned char aid)
{
	if (*(int *)(((char *)&g_021AA878) + 4) == 0)
		return 0;
	if (aid == func_0216B838())
		return 0;
	if (func_02176410(aid))
		return 1;
	return 0;
}



int func_0216B994(void)
{
    int *p = *(int **)(((char *)&g_021AA878) + 4);

    return p != 0 ? *(int *)((char *)p + 0x24) : 0;
}



/*
 * DWC_GetServerAID: the aid of node 0 while a match is running, else 0xff.
 */
unsigned char func_0216B9B0(void)
{
    char *p = *(char **)(((char *)&g_021AA878) + 4);
    unsigned char *node;

    if (p == 0 || *(int *)(p + 0x96c) == 0 || *(int *)(p + 0x96c) == 9 ||
        *(int *)(p + 0x96c) == 10 || *(int *)(p + 0x96c) == 11 ||
        *(unsigned char *)(p + 0x35d) == 0 || *(unsigned char *)(p + 0x366) == 0) {
        return 0xff;
    }
    node = (unsigned char *)func_0217637C(0);
    if (node == 0) {
        return 0xff;
    }
    return node[0x16];
}



int func_0216BA08(void)
{
    if (*(char **)(((char *)&g_021AA878) + 4) == 0) {
        return 0;
    }
    if (func_0216B9B0() == 0xff) {
        return 0;
    }
    return *(unsigned char *)(*(char **)(((char *)&g_021AA878) + 4) + 0x366) == 2;
}



/*
 * sdk:      DWCi_GT2Startup (libdwcmatch.TWL.HYB.a(dwc_main.o))
 */
int func_0216BA4C(void)
{
	int gt2Result;
	unsigned short baseport;

	if (((DwcState *)g_021AA878.st)->gt2Socket != 0)
		return 0;
	baseport = func_021685CC(0x4000) + 0xc000;
	gt2Result = func_02195AB4(&((DwcState *)g_021AA878.st)->gt2Socket, func_02198620(0, baseport, 0), ((DwcState *)g_021AA878.st)->outSize, ((DwcState *)g_021AA878.st)->inSize, func_0216C7A8);
	if (func_0216BE00(gt2Result))
		return gt2Result;
	func_02195B20(((DwcState *)g_021AA878.st)->gt2Socket, (int)func_0216E5B0);
	func_02195E68(((DwcState *)g_021AA878.st)->gt2Socket, (int)func_0216E4C0);
	return gt2Result;
}



/*
 * DWCi_GetGT2Connection: the connection whose aid matches, or zero.
 */
int func_0216BAF4(int aid)
{
    int i;

    if (*(int *)(((char *)&g_021AA878) + 4) == 0) {
        return 0;
    }
    for (i = 0; i < 0x20; i++) {
        if (g_021AA8A0[i] != 0 && aid == ((unsigned char *)func_02195E78((const int *)g_021AA8A0[i]))[1]) {
            return g_021AA8A0[i];
        }
    }
    return 0;
}



/*
 * Byte at +1 of the block, or 0xff when there is none.
 */
int func_0216BB54(const int *a0)
{
    unsigned char *p = (unsigned char *)func_02195E78(a0);

    return p ? *(unsigned char *)(p + 1) : 0xff;
}
