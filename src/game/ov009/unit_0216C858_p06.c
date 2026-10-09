/*
 * file:     unit_0216C858_p06.c
 * unit:     yes
 * function: func_0216D57C, func_0216E4C0
 * address:  0x0216D57C
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
 *   DWCi_IsError                     0x02059f38 arm
 *   qr2_think                        0x0219b1e8 arm
 *   gt2Think                         0x02195af0 arm
 *   OS_GetTick                       0x020870d0 arm
 *   _ll_udiv                         0x0209c00c arm
 *   DWCi_StopMatch                   0x0216eb68 arm
 *   DWCi_RetryReserving              0x02171e34 arm
 *   DWCi_StopMeshMaking              0x02176674 arm
 *   DWCi_SetMatchStatus              0x02175f4c arm
 *   DWCi_SendResvCommand             0x021719d0 arm
 *   DWCi_HandleMatchCommandError     0x021719a4 arm
 *   DWCi_TempNewNodeInfo_Clear       0x0217653c arm
 *   DWCi_SBUpdateAsync               0x0216f770 arm
 *   DWCi_HandleSBError               0x02173d9c arm
 *   DWCi_CancelPreConnectedClientProcess 0x02172124 arm
 *   DWCi_StopResendingMatchCommand   0x0216eb48 arm
 *   DWCi_SendMatchCommand            0x0216ff2c arm
 *   DWCi_CancelPreConnectedServerProcess 0x021720d8 arm
 *   DWC_GetState                     0x0216b994 arm
 *   DWCi_IsBackupMine                0x021754fc arm
 *   DWCi_NodeInfoList_GetNodeInfoForIndex 0x0217637c arm
 *   DWCi_GetGT2Connection            0x0216baf4 arm
 *   DWCi_GetAIDFromProfileID         0x02173c84 arm
 *   DWCi_IsServerChangeEnabled       0x02175fc8 arm
 *   DWCi_SendServerDownQuery         0x02175458 arm
 *   qr2_send_statechanged            0x0219b490 arm
 *   DWCi_InitClWaitTimeout           0x02173cfc arm
 *   DWCi_NodeInfoList_GetCount       0x0217603c arm
 *   DWCi_CloseConnectionHard         0x0216bea4 arm
 *   DWCi_SetupGameServer_InterChange 0x021755d4 arm
 *   DWCi_ResetLastSomeDataRecvTimeByAidAll 0x02175fe4 arm
 *   DWCi_AutoSuspendComplete         0x0217689c arm
 *   DWCi_NNCompletedCallback         0x02174fe8 arm
 *   DWCi_GetTopologyType             0x02176860 arm
 *   DWCi_NodeInfoList_GetMyNodeInfo  0x02176344 arm
 *   DWCi_GetNextMeshMakeTryTick      0x02176594 arm
 *   DWCi_ClearMeshMakingTempInfo     0x02176870 arm
 *   ServerBrowserThink               0x0219efd0 arm
 *   ServerBrowserFree                0x0219ed4c arm
 *   ServerBrowserState               0x0219f024 arm
 *   DWCi_SendStateChanged            0x0216d540 arm
 *   NNThink                          0x0219a4a4 arm
 *   NNFreeNegotiateList              0x0219922c arm
 *   DWCi_ResumeMatch                 0x02172de8 arm
 *   DWCi_RequestSuspendMatchProcess  0x02175c64 arm
 *   DWCi_SendServerPolling           0x0217576c arm
 *   DWCi_ProcessMatchSynTimeout      0x021732f8 arm
 *   DWCi_ProcessCancelMatchSynTimeout 0x021738ec arm
 *   s_anybodyServerSearchRatio       0x021a203c data
 *   s_bInNNThink                     0x021aaa20 data
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02175F3C   0x02175F3C  arm  ov009
 *   func_0219C7C0   0x0219C7C0  arm  ov009
 *   func_020923F0   0x020923F0  arm
 *   func_0219AB8C   0x0219AB8C  arm  ov009
 *   g_021A5A7C      0x021A5A7C  data
 */
#include "../../matched/include/G_NNThinkGlobal.h"
#include "../../matched/include/G_MatchAnchorA.h"
#include "../../matched/include/G_Magic6.h"

#define TICK_MS(t) (((t) * 64) / 33514)
struct SOCSockAddrIn;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned long u32;

typedef unsigned long long u64;

typedef struct DWCstNodeInfo {
    int profileID;                  /* +0x00 */
    u32 publicInetAddress;          /* +0x04 */
    u32 privateInetAddress;         /* +0x08 */
    u16 publicQueryPort;            /* +0x0C */
    u16 privateQueryPort;           /* +0x0E */
    u32 gt2IP;                      /* +0x10 */
    u16 gt2Port;                    /* +0x14 */
    u8 aid;                         /* +0x16 */
    u8 hasPrivateAddress;           /* +0x17 */
    int nnTryCount;                 /* +0x18 */
    u64 nextMeshMakeTryTick;        /* +0x1C */
    u8 connUserData[4];             /* +0x24 */
} DWCstNodeInfo;

typedef struct DWCstMatchCommandControl {
    u8 command;                     /* +0x6D8 */
    u8 count;                       /* +0x6D9 */
    u16 port;                       /* +0x6DA */
    u32 ip;                         /* +0x6DC */
    u32 data[32];                   /* +0x6E0 */
    int profileID;                  /* +0x760 */
    int len;                        /* +0x764 */
    u64 sendTime;                   /* +0x768 */
} DWCstMatchCommandControl;

typedef struct DWCstMatchControl {
    void **pGpObj;                  /* +0x000 */
    void **pGt2Socket;              /* +0x004 */
    u8 pad008[0x10 - 0x8];
    void *qr2Obj;                   /* +0x010 */
    u8 qr2MatchType;                /* +0x014 */
    u8 qr2MatchTypeExt;             /* +0x015 */
    u8 pad016[0x554 - 0x16];
    DWCstNodeInfo tempNewNodeInfo;  /* +0x554 */
    DWCstNodeInfo tempNewClientInfo;/* +0x57C */
    int inMeshMaking;               /* +0x5A4 */
    u8 pad5a8[0x5E0 - 0x5A8];
    void *sbObj;                    /* +0x5E0 */
    int sbUpdateFlag;               /* +0x5E4 */
    u64 sbUpdateTick;               /* +0x5E8 */
    u64 sbUpdateRequestTick;        /* +0x5F0 */
    u8 pad5f8[0x600 - 0x5F8];
    u64 nnFailedTime;               /* +0x600 */
    u64 nnFinishTime;               /* +0x608 */
    u8 nnInfo[0xC];                 /* +0x610 */
    int state;                      /* +0x61C */
    u8 pad620[0x62B - 0x620];
    u8 scResvRetryCount;            /* +0x62B */
    u8 synResendCount;              /* +0x62C */
    u8 cancelSynResendCount;        /* +0x62D */
    u8 clWaitTimeoutCount;          /* +0x62E */
    u8 needServerPoll;              /* +0x62F */
    u8 pad630[0x638 - 0x630];
    int cmdResendFlag;              /* +0x638 */
    u64 cmdResendTick;              /* +0x63C */
    u32 cmdTimeoutTime;             /* +0x644 */
    u64 cmdTimeoutStartTick;        /* +0x648 */
    u8 pad650[0x668 - 0x650];
    u64 closedTime;                 /* +0x668 */
    u64 clWaitTime;                 /* +0x670 */
    int profileID;                  /* +0x678 */
    int reqProfileID;               /* +0x67C */
    u8 pad680[0x6D8 - 0x680];
    DWCstMatchCommandControl cmdCnt;/* +0x6D8 */
    u8 pad770[0x788 - 0x770];
    u32 serverDownBuff;             /* +0x788 */
    u32 serverDownBase;             /* +0x78C */
    u32 groupID;                    /* +0x790 */
    u8 searchGroupIDRetryHostCount; /* +0x794 */
    int connectGroupID;             /* +0x798 */
    u8 serverDownQueryCount;        /* +0x79C */
    u8 serverDownNakCount;          /* +0x79D */
    u64 serverPollingTime;          /* +0x7A0 */
    u8 serverFind;                  /* +0x7A8 */
    u32 serverBrowserUpdateCount;   /* +0x7AC */
    int topologyType;               /* +0x7B0 */
    u8 denyReason;                  /* +0x7B4 */
    u8 cancelFromConnection;        /* +0x7B5 */
    u8 retryCountMax;               /* +0x7B6 */
} DWCstMatchControl;

typedef struct SockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SockAddrIn;

typedef struct MatchCnt {
    unsigned char pad0[0x10];
    void *f10;
} MatchCnt;

extern DWCstMatchControl *DWCi_GetMatchCnt(void);
extern int DWCi_IsError(void);
extern void qr2_think(void *qrec);
extern void gt2Think(void *socket);
extern u64 OS_GetTick(void);
extern void DWCi_StopMatch(int error, int errorCode);
extern int DWCi_RetryReserving(int resendPid);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_SetMatchStatus(int state);
extern int DWCi_SendResvCommand(int profileID, int delay);
extern int DWCi_HandleMatchCommandError(int error);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_SBUpdateAsync(int profileID);
extern int DWCi_HandleSBError(int error);
extern int DWCi_CancelPreConnectedClientProcess(int clientPid);
extern void DWCi_StopResendingMatchCommand(void);
extern int DWCi_SendMatchCommand(u8 command, int profileID, u32 ip, u16 port, u32 *data, int len);
extern int DWCi_CancelPreConnectedServerProcess(int clientPid);
extern int DWC_GetState(void);
extern int DWCi_IsBackupMine(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void *DWCi_GetGT2Connection(u8 aid);
extern u8 DWCi_GetAIDFromProfileID(int profileID, int idxOnly);
extern int DWCi_IsServerChangeEnabled(void);
extern int DWCi_SendServerDownQuery(void);
extern void qr2_send_statechanged(void *qrec);
extern void DWCi_InitClWaitTimeout(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern int DWCi_CloseConnectionHard(u8 aid);
extern void DWCi_SetupGameServer_InterChange(int init);
extern void DWCi_ResetLastSomeDataRecvTimeByAidAll(void);
extern void DWCi_AutoSuspendComplete(void);
extern void DWCi_NNCompletedCallback(int result, int gamesocket, void *remoteaddr, void *userdata);
extern int DWCi_GetTopologyType(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern u64 DWCi_GetNextMeshMakeTryTick(void);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern int ServerBrowserThink(void *sb);
extern void ServerBrowserFree(void *sb);
extern int ServerBrowserState(void *sb);
extern void DWCi_SendStateChanged(void *qr2Obj);
extern void NNThink(void);
extern void NNFreeNegotiateList(void);
extern int DWCi_ResumeMatch(void);
extern int DWCi_RequestSuspendMatchProcess(void);
extern int DWCi_SendServerPolling(int immediate);
extern int DWCi_ProcessMatchSynTimeout(void);
extern int DWCi_ProcessCancelMatchSynTimeout(void);
extern void MIi_CpuClear32(int v, void *p, int size);
extern int func_02175F3C(void);
extern void func_0219C7C0(void *qr2, unsigned char *message, int len, SockAddrIn *saddr);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void func_0219AB8C(char *data, int len, struct SOCSockAddrIn *fromaddr);
void DWCi_MatchProcess(int fullSpec);
int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
extern struct MatchAnchorA s_anybodyServerSearchRatio;
extern struct NNThinkGlobal s_bInNNThink;
extern struct Magic6 g_021A5A7C;


/* clWaitTime rewound so the next poll fires 6000 ms after now (30000 ms timeout) */
static inline void DWCi_SetClWaitTime(u64 now)
{
    DWCi_GetMatchCnt()->clWaitTime = now - (u64)24000 * 33514 / 64;
}


void DWCi_MatchProcess(int fullSpec)
{
    u32 sbInterval;
    DWCstNodeInfo *node;
    DWCstMatchControl *mc;
    u8 idx;

    if (DWCi_GetMatchCnt() == 0 || DWCi_IsError())
        return;

    if (!fullSpec) {
        if (DWCi_GetMatchCnt()->qr2Obj)
            qr2_think(DWCi_GetMatchCnt()->qr2Obj);
        if (DWCi_GetMatchCnt()->pGt2Socket)
            gt2Think(*DWCi_GetMatchCnt()->pGt2Socket);
        return;
    }

    if (DWCi_GetMatchCnt()->state == 0)
        return;

    switch (DWCi_GetMatchCnt()->state) {
    case 3:
        if (DWCi_GetMatchCnt()->cmdTimeoutTime &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdTimeoutStartTick) > DWCi_GetMatchCnt()->cmdTimeoutTime) {
            DWCi_GetMatchCnt()->cmdTimeoutTime = 0;
            if (DWCi_GetMatchCnt()->connectGroupID) {
                DWCi_GetMatchCnt();
                DWCi_GetMatchCnt()->scResvRetryCount++;
                if (DWCi_GetMatchCnt()->scResvRetryCount > DWCi_GetMatchCnt()->retryCountMax) {
                    DWCi_StopMatch(0x16, -80432);
                    return;
                }
                DWCi_RetryReserving(0);
                return;
            }
            if (DWCi_StopMeshMaking() == 1) {
                DWCi_SetMatchStatus(1);
                break;
            }
            if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3) {
                DWCi_GetMatchCnt();
                DWCi_GetMatchCnt()->scResvRetryCount++;
                if (DWCi_GetMatchCnt()->scResvRetryCount > DWCi_GetMatchCnt()->retryCountMax) {
                    DWCi_StopMatch(0x16, -80430);
                    return;
                }
                if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID, 0)))
                    return;
            } else if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
                DWCi_TempNewNodeInfo_Clear();
                if (!DWCi_RetryReserving(0))
                    return;
            } else {
                DWCi_TempNewNodeInfo_Clear();
                if (!DWCi_RetryReserving(0))
                    return;
            }
        }
        if (DWCi_GetMatchCnt()->cmdResendFlag &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdResendTick) >= 3000) {
            if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID, 0)))
                return;
        }
        break;

    case 2:
    case 4:
    case 22:
        if (DWCi_GetMatchCnt()->sbUpdateFlag > 0) {
            if (DWCi_GetMatchCnt()->state == 2) {
                if (DWCi_GetMatchCnt()->sbUpdateFlag == 1 || DWCi_GetMatchCnt()->serverBrowserUpdateCount <= 1)
                    sbInterval = 4000;
                else
                    sbInterval = 12000;
            } else {
                if (DWCi_GetMatchCnt()->state == 22)
                    sbInterval = 4000;
                else if (DWCi_GetMatchCnt()->sbUpdateFlag == 1)
                    sbInterval = 4000;
                else
                    sbInterval = 12000;
            }
            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->sbUpdateTick) > sbInterval) {
                if (DWCi_HandleSBError(DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->reqProfileID)))
                    return;
                DWCi_GetMatchCnt()->sbUpdateFlag = 0;
            }
        }
        break;

    case 6:
        if (DWCi_GetMatchCnt()->nnFinishTime) {
            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->nnFinishTime) > 25000) {
                DWCi_GetMatchCnt()->nnFinishTime = 0;
                if (DWCi_StopMeshMaking() == 1) {
                    DWCi_SetMatchStatus(1);
                } else if (!DWCi_CancelPreConnectedClientProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID)) {
                    DWCi_TempNewNodeInfo_Clear();
                    return;
                }
            }
        } else if (DWCi_GetMatchCnt()->cmdCnt.command == 6) {
            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 6000) {
                if (DWCi_StopMeshMaking() == 1) {
                    DWCi_StopResendingMatchCommand();
                    DWCi_SetMatchStatus(1);
                } else {
                    DWCi_GetMatchCnt()->cmdCnt.count++;
                    if (DWCi_GetMatchCnt()->cmdCnt.count > 5) {
                        DWCi_StopResendingMatchCommand();
                        if (!DWCi_CancelPreConnectedClientProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID)) {
                            DWCi_TempNewNodeInfo_Clear();
                            return;
                        }
                    } else if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(6,
                                   DWCi_GetMatchCnt()->cmdCnt.profileID,
                                   DWCi_GetMatchCnt()->cmdCnt.ip,
                                   DWCi_GetMatchCnt()->cmdCnt.port,
                                   DWCi_GetMatchCnt()->cmdCnt.data,
                                   DWCi_GetMatchCnt()->cmdCnt.len))) {
                        return;
                    }
                }
            }
        }
        break;

    case 14:
        if (DWCi_GetMatchCnt()->cmdCnt.command == 2) {
            if ((DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 &&
                 TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 6000) ||
                (DWCi_GetMatchCnt()->qr2MatchTypeExt != 0 &&
                 TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 19000)) {
                DWCi_StopResendingMatchCommand();
                if (DWCi_StopMeshMaking() == 1) {
                    DWCi_SetMatchStatus(1);
                } else if (!DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID)) {
                    return;
                }
            }
        }
        break;

    case 16:
        if (DWCi_GetMatchCnt()->cmdCnt.command == 8 &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->cmdCnt.sendTime) > 30000) {
            DWCi_GetMatchCnt()->cmdCnt.count++;
            if (DWCi_GetMatchCnt()->cmdCnt.count > 0) {
                DWCi_StopResendingMatchCommand();
                if (!DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID))
                    return;
            }
        }
        break;

    case 1:
        if (DWC_GetState() == 4 && DWCi_GetMatchCnt()->needServerPoll &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 30000) {
            node = &DWCi_GetMatchCnt()->tempNewNodeInfo;
            if (DWCi_GetMatchCnt()->clWaitTimeoutCount >= 5) {
                if (!DWCi_CancelPreConnectedClientProcess(node->profileID))
                    return;
            } else {
                if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x40, node->profileID, node->publicInetAddress,
                                                                       node->publicQueryPort, 0, 0)))
                    return;
                DWCi_GetMatchCnt()->clWaitTimeoutCount++;
                DWCi_SetClWaitTime(OS_GetTick());
            }
        }
        break;

    case 9:
        DWCi_StopMeshMaking();
        mc = DWCi_GetMatchCnt();
        mc->serverDownBuff = 0;
        mc->serverDownQueryCount = 0;
        mc->serverDownNakCount = 0;
        if (!DWCi_IsBackupMine() && !DWCi_GetGT2Connection(DWCi_NodeInfoList_GetNodeInfoForIndex(0)->aid)) {
            DWCi_StopMatch(0x16, -80431);
            return;
        }
        idx = DWCi_GetAIDFromProfileID(mc->profileID, 1);
        mc->serverDownBuff |= 1 << idx;
        if (DWCi_IsBackupMine()) {
            if (!DWCi_IsServerChangeEnabled()) {
                DWCi_StopMatch(0x16, -80431);
            } else {
                DWCi_SendServerDownQuery();
                DWCi_SetMatchStatus(10);
                qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
                DWCi_InitClWaitTimeout();
            }
        } else {
            qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
            DWCi_SetMatchStatus(10);
            DWCi_InitClWaitTimeout();
        }
        break;

    case 10:
        if (DWCi_IsBackupMine()) {
            u32 noResponseHosts;
            int i;

            if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 5000) {
                DWCi_SendServerDownQuery();
                if (++DWCi_GetMatchCnt()->serverDownQueryCount > 5) {
                    noResponseHosts = ~(DWCi_GetMatchCnt()->serverDownBuff & DWCi_GetMatchCnt()->serverDownBase);
                    for (i = 0; i < DWCi_NodeInfoList_GetCount(); i++) {
                        DWCstNodeInfo *info = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                        if (noResponseHosts & (1 << info->aid))
                            DWCi_CloseConnectionHard(info->aid);
                    }
                    DWCi_GetMatchCnt()->serverDownBuff = DWCi_GetMatchCnt()->serverDownBase;
                }
            }
            if (!(DWCi_GetMatchCnt()->serverDownBuff ^ DWCi_GetMatchCnt()->serverDownBase))
                DWCi_SetMatchStatus(11);
        } else if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 60000) {
            DWCi_StopMatch(0x16, -80431);
        }
        break;

    case 11:
        if (DWCi_IsBackupMine()) {
            if (!DWCi_IsServerChangeEnabled()) {
                DWCi_StopMatch(0x16, -80431);
            } else {
                DWCi_SetupGameServer_InterChange(0);
                DWCi_GetMatchCnt()->serverPollingTime = 0;
                DWCi_ResetLastSomeDataRecvTimeByAidAll();
                DWCi_AutoSuspendComplete();
                qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
            }
        } else if (TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->clWaitTime) > 20000) {
            DWCi_SetMatchStatus(1);
        }
        break;

    case 12:
        if (DWCi_GetMatchCnt()->sbUpdateFlag > 0 &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->sbUpdateTick) > 8000) {
            if (++DWCi_GetMatchCnt()->searchGroupIDRetryHostCount > 15) {
                DWCi_StopMatch(0x16, -80432);
            } else {
                if (DWCi_HandleSBError(DWCi_SBUpdateAsync(0)))
                    return;
                DWCi_GetMatchCnt()->sbUpdateFlag = 0;
            }
        }
        break;

    default:
        break;
    }

    if (DWCi_GetMatchCnt()->state == 14 || DWCi_GetMatchCnt()->state == 5) {
        if (DWCi_GetMatchCnt()->nnFailedTime &&
            TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->nnFailedTime) > 10000) {
            DWCi_NNCompletedCallback(1, 0, 0, DWCi_GetMatchCnt()->nnInfo);
        }
    }

    if (DWCi_GetTopologyType() == 0 && DWCi_GetMatchCnt()->inMeshMaking == 0 && DWCi_GetMatchCnt()->state == 1 &&
        DWCi_GetMatchCnt()->tempNewClientInfo.profileID == 0 && DWCi_NodeInfoList_GetCount() > 2) {
        int i;

        for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
            DWCstNodeInfo *pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
            void *connection;

            if (DWCi_NodeInfoList_GetMyNodeInfo() == pNodeInfo)
                continue;
            connection = DWCi_GetGT2Connection(pNodeInfo->aid);
            if (connection)
                continue;
            if (pNodeInfo->nextMeshMakeTryTick == 0)
                pNodeInfo->nextMeshMakeTryTick = DWCi_GetNextMeshMakeTryTick();
            if (OS_GetTick() > pNodeInfo->nextMeshMakeTryTick &&
                pNodeInfo->nnTryCount <= s_anybodyServerSearchRatio.meshMakeNNRetryMax) {
                pNodeInfo->nextMeshMakeTryTick = DWCi_GetNextMeshMakeTryTick();
                DWCi_GetMatchCnt()->tempNewNodeInfo = *pNodeInfo;
                DWCi_GetMatchCnt()->inMeshMaking = 1;
                if (DWCi_HandleMatchCommandError(DWCi_SendResvCommand(pNodeInfo->profileID, 0))) {
                    DWCi_GetMatchCnt()->inMeshMaking = 0;
                    DWCi_TempNewNodeInfo_Clear();
                } else {
                    DWCi_ClearMeshMakingTempInfo();
                    DWCi_SetMatchStatus(3);
                }
                break;
            }
        }
    }

    if (DWCi_GetMatchCnt()->sbObj) {
        s_bInNNThink.sbCallbackLevel = 0;
        s_bInNNThink.needSbFree = 0;
        s_bInNNThink.bInNNThink = 1;
        ServerBrowserThink(DWCi_GetMatchCnt()->sbObj);
        if (s_bInNNThink.needSbFree) {
            ServerBrowserFree(DWCi_GetMatchCnt()->sbObj);
            DWCi_GetMatchCnt()->sbObj = 0;
        }
        if (DWCi_GetMatchCnt()->sbObj && ServerBrowserState(DWCi_GetMatchCnt()->sbObj) != 0 &&
            DWCi_GetMatchCnt()->sbUpdateRequestTick && OS_GetTick() > DWCi_GetMatchCnt()->sbUpdateRequestTick) {
            DWCi_StopMatch(6, -85010);
        }
    }

    s_bInNNThink.bNNFreeNegotiateList = 0;
    s_bInNNThink.bInNNThink = 1;
    DWCi_SendStateChanged(DWCi_GetMatchCnt()->qr2Obj);
    NNThink();
    s_bInNNThink.bInNNThink = 0;
    if (s_bInNNThink.bNNFreeNegotiateList == 1) {
        s_bInNNThink.bNNFreeNegotiateList = 0;
        NNFreeNegotiateList();
    }

    if (DWCi_GetMatchCnt()->pGt2Socket)
        gt2Think(*DWCi_GetMatchCnt()->pGt2Socket);

    if (DWCi_GetMatchCnt()->state == 21 &&
        TICK_MS(OS_GetTick() - DWCi_GetMatchCnt()->closedTime) > 3000) {
        if (DWCi_ResumeMatch())
            return;
    }

    DWCi_RequestSuspendMatchProcess();
    DWCi_SendServerPolling(0);
    if (!DWCi_ProcessMatchSynTimeout())
        return;
    DWCi_ProcessCancelMatchSynTimeout();
}


/*
 * sdk:      DWCi_GT2UnrecognizedMessageCallback (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len)
{
    SockAddrIn saddr;

    if (len == 0 || message == 0)
        return 0;
    MIi_CpuClear32(0, &saddr, 8);
    saddr.family = 2;
    saddr.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
    saddr.addr = ip;
    ip = message[0];
    if ((ip == 0xFE && message[1] == 0xFD) || ip == 0x5C) {
        if (((MatchCnt *)func_02175F3C())->f10 != 0)
            func_0219C7C0(((MatchCnt *)func_02175F3C())->f10, message, len, &saddr);
    } else if (func_020923F0(message, (const u8 *)((char *)&g_021A5A7C), 6) == 0) {
        func_0219AB8C((char *)message, len, (struct SOCSockAddrIn *)(&saddr));
    } else {
        return 0;
    }
    return 1;
}
