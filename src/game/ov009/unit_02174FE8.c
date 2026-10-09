/*
 * file:     unit_02174FE8.c
 * unit:     yes
 * function: func_02174FE8, func_021753D8, func_02175458, func_021754FC, DWCi_CreateGroupID, func_02175560, func_021755D4, func_02175698
 * address:  0x02174FE8
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
 *   DWCi_GetMatchCnt                 0x02175f3c arm
 *   DWCi_SetMatchStatus              0x02175f4c arm
 *   DWCi_MakeGT2ConnectString        0x0216e808 arm
 *   gt2AddressToString               0x02198620 arm
 *   gt2Connect                       0x02195b44 arm
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID 0x021763ac arm
 *   DWCi_StopMeshMaking              0x02176674 arm
 *   DWCi_HandleGT2Error              0x02173fb4 arm
 *   DWCi_CancelPreConnectedServerProcess 0x021720d8 arm
 *   OS_GetTick                       0x020870d0 arm
 *   DWCi_HandleNNResult              0x02173f54 arm
 *   NNCancel                         0x02199fb4 arm
 *   DWCi_ProcessNNFailure            0x021753d8 arm
 *   DWCi_CancelPreConnectedClientProcess 0x02172124 arm
 *   DWCi_DoNatNegotiationAsync       0x0216fe34 arm
 *   DWCi_HandleNNError               0x02173ef8 arm
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_0216EB68  0x0216EB68  arm  ov009
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_0216FF2C  0x0216FF2C  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_02173CFC  0x02173CFC  arm  ov009
 *   DWCi_GetMathRand32   0x021685CC arm
 *   func_02175530  0x02175530  arm  ov009
 *   func_02176344  0x02176344  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   func_02175F84  0x02175F84  arm  ov009
 *   func_0216F20C  0x0216F20C  arm  ov009
 *   func_02173D28  0x02173D28  arm  ov009
 *   func_0219EC74  0x0219EC74  arm  ov009
 *   func_02173D9C  0x02173D9C  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   func_02174058  0x02174058  arm  ov009
 */
#include "../../matched/arm9_sdk/libc/string.h"

#define MC DWCi_GetMatchCnt()
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

struct SOCSockAddrIn {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
};

struct DWCstNodeInfo {
    int profileID;
    u32 publicInetAddress;
    u32 privateInetAddress;
    u16 publicQueryPort;
    u16 privateQueryPort;
    u32 gt2IP;
    u16 gt2Port;
    u8 aid;
    u8 hasPrivateAddress;
    int nnTryCount;
    unsigned long long nextMeshMakeTryTick;
    u8 connUserData[4];
};

struct DWCstNNInfo {
    u8 isQR2;
    u8 retryCount;
    u16 port;
    u32 ip;
    int cookie;
};

struct DWCstMatchControl {
	int pad0;
	void **f_4;
	void *f_8;
	unsigned char f_c;
	unsigned char padd[0x8];
	unsigned char f_15;
	unsigned char pad16[0x53e];
	int f_554;
	unsigned char pad558[0xc];
	unsigned int f_564;
	unsigned short f_568;
	unsigned char pad56a[0x3a];
	int f_5a4;
	unsigned char pad5a8[0x50];
	unsigned char f_5f8;
	unsigned char pad5f9[0x3];
	int f_5fc;
	unsigned long long f_600;
	unsigned long long f_608;
	unsigned char pad610[0x8];
	int f_618;
	int f_61c;
	unsigned char pad620[0x58];
	int profileID;
};

typedef struct MatchCnt {
	unsigned char pad0[0x14];
	unsigned char f14;
	unsigned char f15;
	unsigned char pad16[0x2];
	unsigned char f18;
	unsigned char pad19[0x53b];
	int f554;
	unsigned char pad558[0x84];
	int f5DC;
	int f5E0;
	unsigned char pad5e4[0x98];
	int f67C;
	unsigned char pad680[0x4];
	int f684;
	int f688;
	unsigned char pad68c[0x104];
	int f790;
	unsigned char pad794[0x30];
	int f7C4;
} MatchCnt;

typedef struct NodeInfo {
    unsigned char pad0[0x16];
    unsigned char f16;
} NodeInfo;

extern struct DWCstMatchControl * DWCi_GetMatchCnt(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_MakeGT2ConnectString(char *buf, int bufLen);
extern char *gt2AddressToString(u32 ip, u16 port, char *string);
extern int gt2Connect(void *socket, void *connection, char *remoteAddress,
                      unsigned char *message, int len, int timeout, void *callbacks,
                      int blocking);
extern struct DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_StopMeshMaking(void);
extern int DWCi_HandleGT2Error(int result);
extern int DWCi_CancelPreConnectedServerProcess(int profileID);
extern unsigned long long OS_GetTick(void);
extern int DWCi_HandleNNResult(int result);
extern void NNCancel(int cookie);
extern int DWCi_ProcessNNFailure(int ignoreError);
extern int DWCi_CancelPreConnectedClientProcess(int profileID);
extern int DWCi_DoNatNegotiationAsync(struct DWCstNNInfo *nnInfo);
extern int DWCi_HandleNNError(int error);
extern char *func_02175F3C(void);
extern void func_0216EB68(int error, int code);
extern int func_0217603C(void);
extern char *func_0217637C(int index);
extern int func_0216B908(void);
extern int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
extern int func_021719A4(int result);
extern void func_02173CFC(void);
extern unsigned long DWCi_GetMathRand32(unsigned long max);
extern int func_02175530(void);
extern char *func_02176344(void);
extern void func_02175F4C(int status);
extern void func_02175F84(int status);
extern int func_0216F20C(int matchType);
extern int func_02173D28(int error);
extern int func_0219EC74(int a, int b, int c, int d, int e, int f, int g, void (*cb)(void), int h);
extern int func_02173D9C(int err);
extern int func_021719D0(int a, int b);
extern void func_02174058(void *sb, int reason, void *server);
void DWCi_NNCompletedCallback(int result, int unused, struct SOCSockAddrIn *remoteaddr, struct DWCstNNInfo *nnInfo);
/* * sdk: DWCi_ProcessNNFailure (dwc_match.o) */ int func_021753D8(int ignoreError);
/* * sdk: DWCi_SendServerDownQuery (dwc_match.o) */ int func_02175458(void);
/* * DWCi_IsBackupMine: whether node 0 is this host's own profile. */ int func_021754FC(void);
unsigned long DWCi_CreateGroupID(void);
void func_02175560(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
/* * sdk: DWCi_SetupGameServer_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o) */ void func_021755D4(int init);
/* * sdk: DWCi_ConnectToGameServerAsync_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o) */ void func_02175698(void);



void DWCi_NNCompletedCallback(int result, int unused, struct SOCSockAddrIn *remoteaddr,
                              struct DWCstNNInfo *nnInfo)
{
    char pidStr[24];
    int status;
    unsigned long long tick;
    int gt2Result;

    if (MC->f_61c != 5 && MC->f_61c != 0xe)
        return;
    if (nnInfo == 0)
        return;

    if (result == 0) {
        if (nnInfo->isQR2 != 0) {
        MC->f_564 = remoteaddr->addr;
        {
            int p = remoteaddr->port;
            MC->f_568 = ((p >> 8) & 0xff) | ((p << 8) & 0xff00);
        }
        MC->f_5f8 = 0;
        MC->f_5fc = 0;
        MC->f_600 = 0;
        if (MC->f_61c == 0xe)
            DWCi_SetMatchStatus(0xf);
        else
            DWCi_SetMatchStatus(6);
        MC->f_c = 0;
        DWCi_MakeGT2ConnectString(pidStr, 0x18);
        gt2Result = gt2Connect(*MC->f_4, 0, gt2AddressToString(MC->f_564, MC->f_568, 0),
                               (unsigned char *)pidStr, -1, 5000, MC->f_8, 0);
        if (MC->f_5a4 != 0 && gt2Result != 0) {
            DWCi_NodeInfoList_GetNodeInfoForProfileID(MC->f_554)->nnTryCount++;
            DWCi_StopMeshMaking();
            DWCi_SetMatchStatus(1);
            return;
        }
        if (gt2Result == 1) {
            DWCi_HandleGT2Error(gt2Result);
            return;
        }
        if (gt2Result == 0)
            return;
        DWCi_CancelPreConnectedServerProcess(MC->f_554);
        return;
        }

        if (remoteaddr != 0) {
            MC->f_564 = remoteaddr->addr;
            {
                int p = remoteaddr->port;
                MC->f_568 = ((p >> 8) & 0xff) | ((p << 8) & 0xff00);
            }
        }
        tick = OS_GetTick();
        MC->f_608 = tick;
        DWCi_SetMatchStatus(6);
        return;
    }

    if (nnInfo->cookie == 0)
        return;
    if (MC->f_5a4 != 0) {
        DWCi_NodeInfoList_GetNodeInfoForProfileID(MC->f_554)->nnTryCount++;
        DWCi_StopMeshMaking();
        DWCi_SetMatchStatus(1);
        return;
    }
    status = DWCi_HandleNNResult(result);
    if (status != 2 && status != 1 && status != 3)
        return;
    if (nnInfo->isQR2 == 0) {
        if (status == 1 || status == 3 || (status == 2 && nnInfo->retryCount >= 1)) {
            NNCancel(MC->f_618);
            nnInfo->cookie = 0;
            if (DWCi_ProcessNNFailure(0) == 0)
                return;
            DWCi_CancelPreConnectedClientProcess(MC->f_554);
            return;
        }
        nnInfo->retryCount++;
        DWCi_HandleNNError(DWCi_DoNatNegotiationAsync(nnInfo));
        return;
    }
    tick = OS_GetTick();
    MC->f_600 = tick;
    if (status != 1 && status != 3) {
        if (status != 2)
            return;
        if (MC->f_5f8 < 1)
            return;
    }
    NNCancel(MC->f_618);
    nnInfo->cookie = 0;
    if (MC->f_15 == 3 || MC->f_15 == 2) {
        if (DWCi_ProcessNNFailure(1) == 0)
            return;
    } else {
        if (DWCi_ProcessNNFailure(0) == 0)
            return;
    }
    MC->f_5f8 = 0;
    MC->f_5fc = 0;
    MC->f_600 = 0;
    DWCi_CancelPreConnectedServerProcess(MC->f_554);
}



/*
 * sdk:      DWCi_ProcessNNFailure (dwc_match.o)
 */
int func_021753D8(int ignoreError)
{
    if (ignoreError)
        return 1;
    if (*(unsigned char *)(func_02175F3C() + 0x15) != 3)
        *(unsigned char *)(func_02175F3C() + 0x5f9) += 1;
    if (*(unsigned char *)(func_02175F3C() + 0x15) == 3 || *(int *)(func_02175F3C() + 0x798) != 0 || *(unsigned char *)(func_02175F3C() + 0x5f9) >= 5) {
        func_0216EB68(6, -86420);
        return 0;
    }
    return 1;
}



/*
 * sdk:      DWCi_SendServerDownQuery (dwc_match.o)
 */
int func_02175458(void)
{
    int i;
    int result;
    int hostCount;
    unsigned long aidBitmap;
    char *pNodeInfo;
    unsigned char command;

    func_02175F3C();
    hostCount = func_0217603C();
    for (i = 1; i < hostCount; i++) {
        pNodeInfo = func_0217637C(i);
        aidBitmap = func_0216B908();
        if (*(unsigned int *)(func_02175F3C() + 0x788) & (1 << *(unsigned char *)(pNodeInfo + 0x16)))
            command = 0x55;
        else
            command = 0x52;
        result = func_0216FF2C(command, *(int *)pNodeInfo, *(int *)(pNodeInfo + 4), *(unsigned short *)(pNodeInfo + 12), (const unsigned int *)(&aidBitmap), 1);
        if (func_021719A4(result))
            return 0;
    }
    func_02173CFC();
    return 1;
}



/*
 * DWCi_IsBackupMine: whether node 0 is this host's own profile.
 */
int func_021754FC(void)
{
    int r = 0;
    int *node = (int *)func_0217637C(r);

    if (node != 0 && *node == *(int *)(func_02175F3C() + 0x678)) {
        r = 1;
    }
    return r;
}




unsigned long DWCi_CreateGroupID(void)
{
    return DWCi_GetMatchCnt()->profileID + DWCi_GetMathRand32(10000000) + 100000000;
}




/*
 * sdk:      DWCi_SetConnectionAttemptParam (dwc_match.o)
 */
void func_02175560(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    *(void **)(func_02175F3C() + 0x7b8) = attemptCallback;
    if (connectionUserData)
        memcpy(func_02175F3C() + 0x7bc, connectionUserData, 4);
    else
        memset(func_02175F3C() + 0x7bc, 0, 4);
    *(void **)(func_02175F3C() + 0x7c0) = attemptParam;
}




/*
 * sdk:      DWCi_SetupGameServer_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void func_021755D4(int init)
{
    NodeInfo *pMyNodeInfo;
    int matchType;
    int gpResult;

    if (init) {
        ((MatchCnt *)func_02175F3C())->f790 = func_02175530();
        pMyNodeInfo = (NodeInfo *)func_02176344();
        pMyNodeInfo->f16 = 0;
        ((MatchCnt *)func_02175F3C())->f7C4 = 1;
    }
    ((MatchCnt *)func_02175F3C())->f14 = 2;
    func_02175F4C(13);
    func_02175F84(2);
    ((MatchCnt *)func_02175F3C())->f5DC = 0;
    ((MatchCnt *)func_02175F3C())->f18 = 0;
    if (((MatchCnt *)func_02175F3C())->f15 == 0) {
        matchType = 3;
    } else if (((MatchCnt *)func_02175F3C())->f15 == 1) {
        matchType = 4;
    } else {
        matchType = 6;
    }
    if (((MatchCnt *)func_02175F3C())->f15 == 3)
        ((MatchCnt *)func_02175F3C())->f15 = 2;
    gpResult = func_0216F20C(matchType);
    func_02173D28(gpResult);
    ((MatchCnt *)func_02175F3C())->f67C = 0;
}




/*
 * sdk:      DWCi_ConnectToGameServerAsync_InterChange (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
void func_02175698(void)
{
    int result;

    ((MatchCnt *)func_02175F3C())->f14 = 3;
    if (((MatchCnt *)func_02175F3C())->f5E0 == 0) {
        ((MatchCnt *)func_02175F3C())->f5E0 = func_0219EC74(((MatchCnt *)func_02175F3C())->f684, ((MatchCnt *)func_02175F3C())->f684,
                                              ((MatchCnt *)func_02175F3C())->f688, 0, 20, 1, 0,
                                              (void (*)(void))func_02174058, 0);
    }
    if (((MatchCnt *)func_02175F3C())->f5E0 == 0) {
        if (func_02173D9C(5))
            return;
    }
    func_02175F4C(3);
    result = func_021719D0(((MatchCnt *)func_02175F3C())->f554, 0);
    func_021719A4(result);
}
