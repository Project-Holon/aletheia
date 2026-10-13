/*
 * function: DWCi_ProcessRecvMatchCommand
 * address:  0x021702A0
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ProcessRecvMatchCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * 2026-10-01 (ov SDK wave 2, lane 03): full rewrite from the vendor listing
 *   and DWARF.  Compiles to the full 4396 bytes, 228/228 relocations, every
 *   branch target and frame offset right; 1089 of 1099 instructions identical.
 *   What it took: the jump table starts at index 0 (the old header numbered
 *   cases from 1, so every case was off by one); `case 0x41: break;` gives
 *   the 0x53 pivot; OS_GetTick stores need a u64 temp (call before
 *   DWCi_GetMatchCnt); data[] loads the image does before a GetMatchCnt call
 *   need their own statement; `result = MC()->field; if (result == x)` gives
 *   the field-first cmp (cases 2 and 16); in case 2 data_idx = 1 goes after
 *   MI_CpuFill8 (the early `mov sl,#1` is a pooled constant) and data[11]
 *   lives in the u32 `ip`.
 * residue: case 0x52 only (10 instructions, register names only): the image
 *   gives the pooled constant 1 r6 and bAck r7, we give r7/r6.  Inert:
 *   bAck type/name/scope/initialiser/inner block, every top-level var as
 *   bAck, idx type, ternary spellings (!!, != 0, == 0 ? 0 : 1, ? 1 : bAck),
 *   shift spellings (1U, (u32)1, inline helper), result binding, nested if,
 *   self-assignments at all 12 statement boundaries, empty DWC_Printf
 *   remnants, sendCommand temp.  A standalone micro-repro gives the same
 *   order, so the vendor shape differs in something not visible here.
 * 2026-10-01 (w3 lane24): still 12 B.  SET_TICK's u64 `tick` locals are not
 *   in the vendor DWARF; replaced by inline setters taking the tick (same
 *   bytes, DWARF closer).  Our -g DWARF vs vendor: bAck is r6 here, r0 there;
 *   `bAck = DWCi_IsBackupMine()` reproduces r0 but not the colours.  New
 *   inert spellings: idx/bAck declaration swap, unprototyped GetAID (vendor
 *   DWARF gives it one parameter, yet r1 = 1 is passed), embedded
 *   `GetNodeInfoForIndex(bAck = 0)`, a top-level local holding the 1 (all
 *   eight), `||`-merged early returns (653 B), bAck types incl. long/u64,
 *   `register`, dsi 1.1/1.2/1.2p1/1.2p2/1.3 (all 12 B).  Micro-repro finding:
 *   1.1p1 always colours the user variable bAck before the select temp that
 *   coalesces with the pooled 1 (a `? 2 : 0` or if-statement form puts the
 *   bare constant first); the image orders {1, temp} first.  Read as the
 *   4.0.0.1025 allocator tie (see the 0217D280 / 021D3638 idioms).
 * 2026-10-01 (w4): EXACT.  The Debug build (sdk/TwlDWC/lib/ARM9-TS/Debug,
 *   -O0, non-inlined) of dwc_match.o gives the case 0x52 source: an
 *   `if (srcPid != ...) bAck = FALSE; else bAck = (... & (1 << idx)) != 0;`
 *   pair (the -O0 code is the same for `!= 0` and `? 1 : 0`); at -O4 that
 *   if/else with `!= 0` colours the pooled 1 before bAck.  Neither half alone
 *   moves it (`!= 0` was inert with `bAck = 0; if (==)`).  Also from the Debug
 *   object: the dead `serverAidBitmap = DWCi_LEtoHl(data[0])` local, the
 *   separate `result = DWCi_SendMatchCommand(...)` statement, and the
 *   DWCi_Np_GetTick inline (all byte-neutral, kept for source fidelity).
 *
 * symbols:
 *   DWC_CloseAllConnectionsHard                  0x0216b65c arm ov009
 *   DWC_GetState                                 0x0216b994 arm ov009
 *   DWCi_CancelPreConnectedClientProcess         0x02172124 arm ov009
 *   DWCi_CancelPreConnectedServerProcess         0x021720d8 arm ov009
 *   DWCi_CheckResvCommand                        0x021713cc arm ov009
 *   DWCi_CloseAllConnectionsByTimeout            0x02172e7c arm ov009
 *   DWCi_CloseConnectionHard                     0x0216bea4 arm ov009
 *   DWCi_GetAIDFromProfileID                     0x02173c84 arm ov009
 *   DWCi_GetFriendListIndex                      0x02169038 arm ov009
 *   DWCi_GetGT2Connection                        0x0216baf4 arm ov009
 *   DWCi_GetGT2ConnectionByProfileID             0x0216bbdc arm ov009
 *   DWCi_GetGT2NumConnection                     0x02176978 arm ov009
 *   DWCi_GetHostStatus                           0x02175fb8 arm ov009
 *   DWCi_GetMatchCnt                             0x02175f3c arm ov009
 *   DWCi_GetResvDenyReasonString                 0x021769e0 arm ov009
 *   DWCi_HandleMatchCommandError                 0x021719a4 arm ov009
 *   DWCi_HandleNNError                           0x02173ef8 arm ov009
 *   DWCi_HandleSBError                           0x02173d9c arm ov009
 *   DWCi_InitClWaitTimeout                       0x02173cfc arm ov009
 *   DWCi_IsBackupMine                            0x021754fc arm ov009
 *   DWCi_IsFullMesh                              0x0217695c arm ov009
 *   DWCi_NNCompletedCallback                     0x02174fe8 arm ov009
 *   DWCi_NNStartupAsync                          0x0216fc34 arm ov009
 *   DWCi_NodeInfoList_GetCount                   0x0217603c arm ov009
 *   DWCi_NodeInfoList_GetMyNodeInfo              0x02176344 arm ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex        0x0217637c arm ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID    0x021763ac arm ov009
 *   DWCi_NodeInfoList_GetServerNodeInfo          0x02176358 arm ov009
 *   DWCi_PostProcessConnection                   0x02172254 arm ov009
 *   DWCi_ProcessCancelMatchSynCommand            0x021736ac arm ov009
 *   DWCi_ProcessMatchPollingPacket               0x0216f058 arm ov009
 *   DWCi_ProcessRequestMatch                     0x021758c4 arm ov009
 *   DWCi_ProcessResvOK                           0x02171884 arm ov009
 *   DWCi_ResetLastSomeDataRecvTimeByAidAll       0x02175fe4 arm ov009
 *   DWCi_RestartFromCancel                       0x02172bb8 arm ov009
 *   DWCi_RetryReserving                          0x02171e34 arm ov009
 *   DWCi_SBUpdateAsync                           0x0216f770 arm ov009
 *   DWCi_SendMatchCommand                        0x0216ff2c arm ov009
 *   DWCi_SendResvCommandToFriend                 0x02171c08 arm ov009
 *   DWCi_SetMatchStatus                          0x02175f4c arm ov009
 *   DWCi_StopMatch                               0x0216eb68 arm ov009
 *   DWCi_StopMeshMaking                          0x02176674 arm ov009
 *   DWCi_TempNewNodeInfo_Clear                   0x0217653c arm ov009
 *   DWCi_TempNewNodeInfo_IsValid                 0x02176554 arm ov009
 *   MI_CpuFill8                                  0x02082bcc arm
 *   OS_GetTick                                   0x020870d0 arm
 *   gpIsBuddy                                    0x021861a8 arm ov009
 *   gt2CloseAllConnectionsHard                   0x02195de4 arm ov009
 *   gt2GetSocketSOCKET                           0x02195e60 arm ov009
 */

#include "../../matched/arm9_sdk/libc/string.h"

#define NULL ((void *)0)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef struct DWCstNodeInfo {
    int profileID;                  /* 0x00 */
    u32 publicInetAddress;          /* 0x04 */
    u32 privateInetAddress;         /* 0x08 */
    u16 publicQueryPort;            /* 0x0C */
    u16 privateQueryPort;           /* 0x0E */
    u32 gt2IP;                      /* 0x10 */
    u16 gt2Port;                    /* 0x14 */
    u8 aid;                         /* 0x16 */
    u8 hasPrivateAddress;           /* 0x17 */
    int nnTryCount;                 /* 0x18 */
    u64 nextMeshMakeTryTick;        /* 0x1C */
    u8 connUserData[4];             /* 0x24 */
} DWCstNodeInfo;

typedef struct SOCInAddr {
    u32 addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
    u8 len;
    u8 family;
    u16 port;
    SOCInAddr addr;
} SOCSockAddrIn;

typedef void (*DWCMatchedSCCallback)(int index, void *param);

typedef struct DWCstMatchControl {
    void **pGpObj;                  /* 0x000 */
    void **pGt2Socket;              /* 0x004 */
    u8 pad008[0x00D - 0x008];
    u8 f_00D;                       /* 0x00D */
    u8 pad00E[0x014 - 0x00E];
    u8 f_014;                       /* 0x014 */
    u8 f_015;                       /* 0x015 */
    u8 pad016;
    u8 f_017;                       /* 0x017 */
    u8 f_018;                       /* 0x018 */
    u8 pad019[0x01C - 0x019];
    u32 f_01C;                      /* 0x01C */
    u64 f_020;                      /* 0x020 */
    u8 pad028[0x030 - 0x028];
    u8 f_030;                       /* 0x030 */
    u8 pad031[0x554 - 0x031];
    DWCstNodeInfo tempNewNodeInfo;  /* 0x554 */
    DWCstNodeInfo f_57C;            /* 0x57C */
    int f_5A4;                      /* 0x5A4 */
    u8 pad5A8[0x5DC - 0x5A8];
    int f_5DC;                      /* 0x5DC */
    u8 pad5E0[0x5E4 - 0x5E0];
    int f_5E4;                      /* 0x5E4 */
    u64 f_5E8;                      /* 0x5E8 */
    u8 pad5F0[0x608 - 0x5F0];
    u64 f_608;                      /* 0x608 */
    u8 f_610;                       /* 0x610 */
    u8 pad611[0x61C - 0x611];
    int f_61C;                      /* 0x61C */
    u8 f_620;                       /* 0x620 */
    u8 pad621[0x628 - 0x621];
    u8 f_628;                       /* 0x628 */
    u8 f_629;                       /* 0x629 */
    u8 pad62A;
    u8 f_62B;                       /* 0x62B */
    u8 pad62C[0x634 - 0x62C];
    int f_634;                      /* 0x634 */
    int f_638;                      /* 0x638 */
    u8 pad63C[0x644 - 0x63C];
    int f_644;                      /* 0x644 */
    u64 f_648;                      /* 0x648 */
    u8 pad650[0x670 - 0x650];
    u64 f_670;                      /* 0x670 */
    int f_678;                      /* 0x678 */
    int f_67C;                      /* 0x67C */
    int f_680;                      /* 0x680 */
    u8 pad684[0x6D8 - 0x684];
    u8 f_6D8;                       /* 0x6D8 */
    u8 pad6D9[0x778 - 0x6D9];
    DWCMatchedSCCallback f_778;     /* 0x778 */
    void *f_77C;                    /* 0x77C */
    int f_780;                      /* 0x780 */
    u8 pad784[0x788 - 0x784];
    u32 f_788;                      /* 0x788 */
    u8 pad78C[0x790 - 0x78C];
    u32 f_790;                      /* 0x790 */
    u8 pad794[0x798 - 0x794];
    int f_798;                      /* 0x798 */
    u8 pad79C;
    u8 f_79D;                       /* 0x79D */
    u8 pad79E[0x7B4 - 0x79E];
    u8 f_7B4;                       /* 0x7B4 */
    u8 pad7B5;
    u8 f_7B6;                       /* 0x7B6 */
    u8 pad7B7[0x7CC - 0x7B7];
    u64 f_7CC;                      /* 0x7CC */
} DWCstMatchControl;

extern DWCstMatchControl *DWCi_GetMatchCnt(void);
extern int DWC_GetState(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void DWCi_InitClWaitTimeout(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern u8 DWCi_CheckResvCommand(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType,
                                int connectGroupID, u32 topologyType,
                                u8 *newClientUserData, int meshReserve);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern int DWCi_ProcessResvOK(int profileID, u32 ip, u16 port);
extern int DWCi_HandleMatchCommandError(int error);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_GetFriendListIndex(int profileID);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern void DWCi_SetMatchStatus(int state);
extern char *DWCi_GetResvDenyReasonString(u8 denyReason);
extern int DWCi_SendMatchCommand(u8 command, int profileID, u32 ip, u16 port,
                                 u32 *data, int len);
extern int DWCi_SBUpdateAsync(int profileID);
extern int DWCi_HandleSBError(int error);
extern int DWCi_NNStartupAsync(int isQR2, int cookie, DWCstNodeInfo *node);
extern int DWCi_HandleNNError(int error);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_StopMatch(int error, int errorCode);
extern int DWCi_RetryReserving(int resendPid);
extern int gpIsBuddy(void **connection, int profile);
extern u64 OS_GetTick(void);
extern int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid);
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern void *DWCi_GetGT2ConnectionByProfileID(int profileID, int idx);
extern void gt2CloseAllConnectionsHard(void *socket);
extern int DWCi_CancelPreConnectedServerProcess(int clientPid);
extern int DWCi_IsFullMesh(void);
extern int gt2GetSocketSOCKET(void *socket);
extern void DWCi_NNCompletedCallback(int result, int gamesocket,
                                     SOCSockAddrIn *remoteaddr, void *userdata);
extern int DWCi_GetGT2NumConnection(void);
extern void DWCi_PostProcessConnection(int type);
extern void *DWCi_GetGT2Connection(u8 aid);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern int DWCi_CancelPreConnectedClientProcess(int clientPid);
extern void DWCi_CloseAllConnectionsByTimeout(void);
extern void DWCi_RestartFromCancel(int level);
extern int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data);
extern int DWCi_CloseConnectionHard(u8 aid);
extern int DWCi_IsBackupMine(void);
extern u8 DWCi_GetAIDFromProfileID(int profileID, int idx);
extern void DWCi_ResetLastSomeDataRecvTimeByAidAll(void);
extern int DWC_CloseAllConnectionsHard(void);
extern int DWCi_GetHostStatus(void);
extern int DWCi_ProcessRequestMatch(u8 AID, int suspend, int immediate);
extern void DWCi_ProcessMatchPollingPacket(u32 *data);

#define MC() DWCi_GetMatchCnt()
/* SDK inlines (calls in the Debug build of dwc_match.o, inlined in Rom):
 * the tick is read before DWCi_GetMatchCnt, as `MC()->x = DWCi_Np_GetTick()`
 * inlines; DWCi_LEtoHl is the identity on the DS */
static inline u32 DWCi_LEtoHl(u32 x) { return x; }
static inline u64 DWCi_Np_GetTick(void) { return OS_GetTick(); }
#define SOC_HtoNs(s) ((u16)((((s) >> 8) & 0x00ff) | (((s) << 8) & 0xff00)))

int DWCi_ProcessRecvMatchCommand(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len)
{
    u8 sendCommand;
    u8 aid;
    u16 port;
    u32 ip;
    u32 senddata[65];
    int profileID;
    int sendlen = 0;
    int result;
    int i;
    int nnError;
    SOCSockAddrIn remoteaddr;

    if (MC() == NULL || MC()->f_61C == 0)
        return 1;

    if (DWC_GetState() == 4 && MC()->f_61C == 1 &&
        DWCi_NodeInfoList_GetCount() > 0 &&
        srcPid == DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID)
        DWCi_InitClWaitTimeout();

    switch (command) {
    case 1: {
        DWCstNodeInfo peerNodeInfo;
        DWCstNodeInfo *pMyNodeInfo;
        int peerConnectGroupID;
        int meshReserve;
        DWCstNodeInfo *pNodeInfo;
        u32 matchType;
        u32 topologyType;

        meshReserve = 0;
        matchType = data[0];
        MI_CpuFill8(&peerNodeInfo, 0, sizeof(DWCstNodeInfo));
        peerNodeInfo.aid = 0xff;
        peerNodeInfo.profileID = srcPid;
        peerNodeInfo.publicInetAddress = data[1];
        peerNodeInfo.publicQueryPort = (u16)data[2];
        peerNodeInfo.privateInetAddress = data[3];
        peerNodeInfo.privateQueryPort = (u16)data[4];
        peerNodeInfo.hasPrivateAddress = (u8)data[5];
        peerConnectGroupID = (int)data[6];
        topologyType = data[7];
        memcpy(peerNodeInfo.connUserData, &data[8], 4);
        profileID = (int)data[9];
        if (len >= 11 && data[10] == 1)
            meshReserve = 1;

        sendCommand = DWCi_CheckResvCommand(peerNodeInfo.profileID, peerNodeInfo.publicInetAddress,
                                            peerNodeInfo.publicQueryPort, matchType,
                                            peerConnectGroupID ? 1 : 0, topologyType,
                                            peerNodeInfo.connUserData, meshReserve);
        if (sendCommand == 2) {
            DWCi_TempNewNodeInfo_Clear();
            MC()->tempNewNodeInfo = peerNodeInfo;
            if (DWCi_HandleMatchCommandError(DWCi_ProcessResvOK(srcPid, srcIP, srcPort)))
                return 0;
            if (MC()->f_5A4) {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(MC()->tempNewNodeInfo.profileID);
                MC()->tempNewNodeInfo.aid = pNodeInfo->aid;
            }
            if (MC()->f_5A4 == 0 && MC()->f_014 == 2 && MC()->f_61C != 0xe &&
                ((MC()->f_015 != 0 && MC()->f_015 != 1) || MC()->f_00D) &&
                MC()->f_778 != NULL)
                MC()->f_778(DWCi_GetFriendListIndex(srcPid), MC()->f_77C);
            pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
            sendlen = 0;
            senddata[sendlen++] = MC()->f_017;
            senddata[sendlen++] = pMyNodeInfo->aid;
            senddata[sendlen++] = pMyNodeInfo->profileID;
            senddata[sendlen++] = pMyNodeInfo->publicInetAddress;
            senddata[sendlen++] = pMyNodeInfo->publicQueryPort;
            senddata[sendlen++] = pMyNodeInfo->privateInetAddress;
            senddata[sendlen++] = pMyNodeInfo->privateQueryPort;
            senddata[sendlen++] = pMyNodeInfo->hasPrivateAddress;
            senddata[sendlen++] = *(u32 *)pMyNodeInfo->connUserData;
            senddata[sendlen++] = MC()->f_790;
            senddata[sendlen++] = MC()->tempNewNodeInfo.aid;
            senddata[sendlen++] = profileID;
            senddata[sendlen++] = DWCi_NodeInfoList_GetCount();
            senddata[sendlen++] = MC()->f_5A4 ? 1 : 0;
            MC();
            DWCi_SetMatchStatus(0xe);
        } else if (sendCommand == 3) {
            DWCi_GetResvDenyReasonString(MC()->f_7B4);
            senddata[0] = MC()->f_7B4;
            sendlen = 1;
        }
        if (sendCommand != 0xff) {
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(sendCommand, peerNodeInfo.profileID,
                                                                   peerNodeInfo.publicInetAddress,
                                                                   peerNodeInfo.publicQueryPort,
                                                                   senddata, sendlen)))
                return 0;
        }
        break;
    }
    case 2: {
        DWCstNodeInfo peerNodeInfo;
        DWCstNodeInfo *pMyNodeInfo;
        u8 data_idx;
        profileID = data[0];
        if (MC()->f_61C != 3)
            break;
        if (srcPid != MC()->f_67C || srcPid != (int)data[2])
            break;
        ip = (int)data[11];
        result = MC()->f_634;
        if (result != ip)
            break;
        if (len >= 14) {
            ip = data[13] == 1 ? 1 : 0;
            if (ip != MC()->f_5A4)
                break;
        }
        MC()->f_628 = 0;
        MC()->f_644 = 0;
        MC()->f_638 = 0;
        MI_CpuFill8(&peerNodeInfo, 0, sizeof(DWCstNodeInfo));
        data_idx = 1;
        peerNodeInfo.aid = (u8)data[data_idx++];
        peerNodeInfo.profileID = (int)data[data_idx++];
        peerNodeInfo.publicInetAddress = data[data_idx++];
        peerNodeInfo.publicQueryPort = (u16)data[data_idx++];
        peerNodeInfo.privateInetAddress = data[data_idx++];
        peerNodeInfo.privateQueryPort = (u16)data[data_idx++];
        peerNodeInfo.hasPrivateAddress = (u8)data[data_idx++];
        memcpy(peerNodeInfo.connUserData, &data[data_idx++], 4);
        ip = data[data_idx++];
        if (MC()->f_5A4 == 0)
            DWCi_NodeInfoList_GetMyNodeInfo()->aid = (u8)data[data_idx++];
        MC()->tempNewNodeInfo = peerNodeInfo;
        if (MC()->f_014 == 3) {
            MC()->f_790 = ip;
            MC()->f_017 = (u8)profileID;
        }
        if (MC()->f_015 == 1 && MC()->f_780 && MC()->f_5A4 == 0 && MC()->f_798 == 0) {
            int sbError;

            DWCi_SetMatchStatus(4);
            sbError = DWCi_SBUpdateAsync(srcPid);
            if (DWCi_HandleSBError(sbError))
                return 0;
        } else {
            DWCi_SetMatchStatus(5);
            ip = DWCi_NNStartupAsync(0, 0, &MC()->tempNewNodeInfo);
            if (DWCi_HandleNNError(ip))
                return 0;
        }
        break;
    }
    case 3: {
        u32 reason;

        if (MC()->f_61C != 3)
            break;
        if (srcPid != MC()->f_67C)
            break;
        reason = data[0];
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->f_798 || MC()->f_015 == 3) {
            int error;

            error = reason != 0x10 ? 0x15 : 0xc;
            DWCi_StopMatch(error, 0);
            return 0;
        }
        return DWCi_RetryReserving(MC()->f_67C);
    }
    case 4:
        if (MC()->f_61C != 3)
            break;
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->f_798) {
            if (srcPid != MC()->f_67C)
                break;
            if (!gpIsBuddy(MC()->pGpObj, srcPid))
                break;
            MC()->f_7B6 = 1;
            MC()->f_62B = 0;
            MC()->f_644 = 12000;
            MC()->f_648 = DWCi_Np_GetTick();
        } else {
            if (srcPid != MC()->f_67C)
                break;
            MC()->f_648 = DWCi_Np_GetTick();
            MC()->f_628 = 0;
            if (MC()->f_015 == 0) {
                DWCi_TempNewNodeInfo_Clear();
                DWCi_SetMatchStatus(2);
                MC()->f_5E4 = 1;
                MC()->f_5E8 = DWCi_Np_GetTick();
            } else if (MC()->f_015 == 1) {
                DWCi_TempNewNodeInfo_Clear();
                DWCi_SendResvCommandToFriend(1, 0, 0);
            } else if (MC()->f_015 == 3) {
                MC()->f_7B6 = 1;
                MC()->f_62B = 0;
                MC()->f_644 = 12000;
                MC()->f_648 = DWCi_Np_GetTick();
            }
        }
        break;
    case 5:
        if (MC()->f_018 == 0)
            break;
        if (srcPid != MC()->f_5DC)
            break;
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->f_014 == 2 && DWCi_TempNewNodeInfo_IsValid() == 1 &&
            DWCi_GetGT2ConnectionByProfileID(MC()->tempNewNodeInfo.profileID, 0) &&
            srcPid == MC()->tempNewNodeInfo.profileID)
            gt2CloseAllConnectionsHard(*MC()->pGt2Socket);
        if (!DWCi_CancelPreConnectedServerProcess(srcPid))
            return 0;
        break;
    case 6:
        ip = data[0];
        port = (u16)data[1];
        if (!DWCi_TempNewNodeInfo_IsValid())
            break;
        if (!DWCi_IsFullMesh() && MC()->f_014 == 3 && MC()->f_5A4 == 0)
            break;
        if (MC()->f_61C == 1) {
            DWCi_SetMatchStatus(5);
        } else {
            if (MC()->f_61C != 5 && MC()->f_61C != 0xe)
                break;
            if (srcPid != MC()->f_5DC)
                break;
        }
        MC()->f_6D8 = 0xff;
        remoteaddr.addr.addr = ip;
        remoteaddr.port = SOC_HtoNs(port);
        MC()->f_610 = 1;
        DWCi_NNCompletedCallback(0, gt2GetSocketSOCKET(*MC()->pGt2Socket), &remoteaddr, &MC()->f_610);
        MC()->f_608 = 0;
        break;
    case 7:
        if (DWCi_StopMeshMaking() == 1)
            DWCi_SetMatchStatus(1);
        if (MC()->f_61C != 1)
            break;
        if (srcPid != DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID)
            break;
        profileID = (int)data[0];
        aid = (u8)data[1];
        if (MC()->f_57C.profileID)
            break;
        MC()->f_788 = 0;
        if (DWCi_IsFullMesh()) {
            MC()->tempNewNodeInfo.profileID = profileID;
            MC()->tempNewNodeInfo.aid = aid;
        } else {
            MC()->f_57C.profileID = profileID;
        }
        if (MC()->f_778 != NULL)
            MC()->f_778(DWCi_GetFriendListIndex(profileID), MC()->f_77C);
        break;
    case 9: {
        DWCstNodeInfo *nodeInfo;

        nodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(DWCi_GetGT2NumConnection() - 1 - MC()->f_620);
        if (MC()->f_61C != 0x10)
            break;
        if (nodeInfo == NULL || nodeInfo->profileID != (int)data[0])
            break;
        MC()->f_620++;
        DWCi_PostProcessConnection(0);
        break;
    }
    case 8: {
        DWCstNodeInfo *tmpNode;
        u32 senddata1[1];

        if (MC()->f_61C != 1)
            break;
        if (srcPid != MC()->tempNewNodeInfo.profileID)
            break;
        profileID = (int)data[0];
        tmpNode = &MC()->tempNewNodeInfo;
        aid = (u8)data[2];
        if (DWCi_GetGT2Connection(aid)) {
            senddata1[0] = (u32)profileID;
            if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(9, srcPid, tmpNode->publicInetAddress,
                                                                   tmpNode->publicQueryPort,
                                                                   senddata1, 1)))
                return 0;
        } else {
            MC()->f_57C = MC()->tempNewNodeInfo;
            tmpNode->profileID = profileID;
            tmpNode->aid = aid;
            tmpNode->publicInetAddress = data[3];
            tmpNode->publicQueryPort = (u16)data[4];
            tmpNode->privateInetAddress = data[5];
            tmpNode->privateQueryPort = (u16)data[6];
            tmpNode->hasPrivateAddress = (u8)data[7];
            memcpy(tmpNode->connUserData, &data[8], 4);
            DWCi_SetMatchStatus(5);
            MC()->f_644 = 0;
            MC()->f_638 = 0;
            DWCi_NNStartupAsync(0, 0, tmpNode);
        }
        break;
    }
    case 10:
        if (MC()->f_61C != 1)
            break;
        if (srcPid != DWCi_NodeInfoList_GetServerNodeInfo()->profileID)
            break;
        profileID = (int)data[0];
        aid = (u8)data[1];
        if (profileID != MC()->tempNewNodeInfo.profileID || aid != MC()->tempNewNodeInfo.aid) {
            MC()->tempNewNodeInfo.aid = aid;
            MC()->tempNewNodeInfo.profileID = profileID;
        }
        break;
    case 12:
        if (srcPid != MC()->tempNewNodeInfo.profileID)
            break;
        if (MC()->f_015 == 0 || MC()->f_015 == 1) {
            if (!DWCi_CancelPreConnectedClientProcess(srcPid))
                return 0;
        } else if (MC()->f_014 == 3) {
            MC()->f_680 = srcPid;
            DWCi_CloseAllConnectionsByTimeout();
            DWCi_RestartFromCancel(0);
        }
        break;
    case 13:
    case 14:
    case 15:
        if (!DWCi_ProcessCancelMatchSynCommand(srcPid, command, data[0]))
            return 0;
        break;
    case 16: {
        DWCstNodeInfo *pNodeInfo;
        u8 beforeCloseState;

        pNodeInfo = DWCi_NodeInfoList_GetServerNodeInfo();
        if (pNodeInfo == NULL)
            return 1;
        if (srcPid != pNodeInfo->profileID)
            return 1;
        beforeCloseState = MC()->f_629;
        MC()->f_629 = 1;
        for (i = 0; i < len; i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID((int)data[i]);
            if (pNodeInfo == NULL) {
                profileID = (int)data[i];
                result = MC()->f_57C.profileID;
                if (result == profileID) {
                    DWCi_CloseConnectionHard(MC()->f_57C.aid);
                    MC()->f_57C.profileID = 0;
                    continue;
                }
            }
            if (pNodeInfo != NULL)
                DWCi_CloseConnectionHard(pNodeInfo->aid);
        }
        MC()->f_629 = beforeCloseState;
        break;
    }
    case 0x40:
        if (!DWCi_TempNewNodeInfo_IsValid())
            break;
        if (srcPid != MC()->tempNewNodeInfo.profileID)
            break;
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x41, srcPid, srcIP, srcPort, NULL, 0)))
            return 0;
        break;
    case 0x41:
        break;
    case 0x52: {
        u32 serverAidBitmap;
        u8 idx;
        int bAck;

        if (!MC()->f_00D)
            break;
        if (DWCi_IsBackupMine())
            return 0;
        idx = DWCi_GetAIDFromProfileID(MC()->f_678, 1);
        if (idx == 0xff)
            return 0;
        if (DWCi_GetAIDFromProfileID(srcPid, 1) == 0xff)
            return 0;
        serverAidBitmap = DWCi_LEtoHl(data[0]);
        if (srcPid != DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID) {
            bAck = 0;
        } else {
            bAck = (MC()->f_788 & (1 << idx)) != 0;
        }
        result = DWCi_SendMatchCommand(bAck ? 0x53 : 0x54, srcPid, srcIP, srcPort, NULL, 0);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
        MC()->f_670 = DWCi_Np_GetTick();
        if (bAck && MC()->f_61C == 0xa) {
            DWCi_SetMatchStatus(1);
            DWCi_ResetLastSomeDataRecvTimeByAidAll();
        }
        break;
    }
    case 0x53: {
        u8 idx;

        if (!MC()->f_00D)
            break;
        if (!DWCi_IsBackupMine())
            break;
        idx = DWCi_GetAIDFromProfileID(srcPid, 1);
        if (idx == 0xff)
            return 0;
        MC()->f_788 |= 1 << idx;
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x53, srcPid, srcIP, srcPort, NULL, 0)))
            return 0;
        break;
    }
    case 0x54:
        if (!MC()->f_00D)
            break;
        i = DWCi_NodeInfoList_GetCount();
        if (++MC()->f_79D > i * 5)
            DWC_CloseAllConnectionsHard();
        else
            MC()->f_670 = DWCi_Np_GetTick();
        break;
    case 0x55:
        MC();
        break;
    case 0x70:
        DWCi_SBUpdateAsync(0);
        DWCi_InitClWaitTimeout();
        DWCi_SetMatchStatus(0xc);
        break;
    case 0x82: {
        u8 fromSV;
        u8 suspend;
        u8 AID;

        fromSV = (u8)data[1];
        suspend = (u8)data[2];
        if (DWCi_NodeInfoList_GetNodeInfoForProfileID((int)data[0]) == NULL)
            break;
        if (DWCi_GetHostStatus() == 2) {
            AID = (u8)data[3];
            if (fromSV != 1)
                DWCi_ProcessRequestMatch(AID, suspend, 1);
        } else if (DWCi_GetHostStatus() == 1) {
            if (fromSV == 0)
                break;
            if (len == 2) {
                if (MC()->f_030 == 1)
                    break;
                MC()->f_030 = 1;
                MC()->f_7CC = 8000;
                MC()->f_020 = DWCi_Np_GetTick();
            } else {
                MC()->f_030 = 1;
                ip = data[3];
                MC()->f_01C = ip;
            }
        }
        break;
    }
    case 0x83:
        DWCi_ProcessMatchPollingPacket(data);
        break;
    }
    return 1;
}
