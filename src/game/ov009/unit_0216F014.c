/*
 * file:     unit_0216F014.c
 * unit:     yes
 * function: func_0216F014, func_0216F058, func_0216F0A0, func_0216F1E8, func_0216F20C, func_0216F334, func_0216F370, func_0216F388, func_0216F5FC, func_0216F6C0, func_0216F770, func_0216FAD4, func_0216FBB8, func_0216FC34, func_0216FE34, func_0216FEF0, func_0216FF2C, func_021700C8, func_02170168, func_02170200, func_021702A0, func_021713CC, func_02171524, func_02171884, func_021719A4, DWCi_SendResvCommand, DWCi_SendResvCommandToFriend, func_02171E34, func_02171F68, func_02171FD4, func_021720D8, func_02172124, DWCi_PostProcessConnection, DWCi_PostProcessConnectionSYNFinish, func_0217253C, func_021725EC, func_02172604, func_0217273C, func_021728B8, func_02172A58, func_02172B08, func_02172BB8, DWCi_RestartFromTimeout, DWCi_ResumeMatch, func_02172E18, func_02172E7C, func_02172EAC, DWCi_SendMatchSynPacket, func_021732F8, func_0217352C, func_021735A4, func_02173614, func_021736AC, func_021738EC, func_02173AD8, func_02173B18, func_02173B74, INTRUDE_COMM_RecvNoticeBytes, func_02173C84, INTRUDE_COMM_RecvRemoteRecord, func_02173CFC, func_02173D28, func_02173D9C, func_02173E30, func_02173EF8, func_02173F54, func_02173FB4, func_02174058
 * address:  0x0216F014
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
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   DWCi_CloseConnectionHard  0x0216BEA4  arm  ov009
 *   DWC_IsServerMyself  0x0216BA08  arm  ov009
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02176358  0x02176358  arm  ov009
 *   DWC_GetState                0x0216B994 arm   ov009
 *   func_0216EB68                0x0216EB68 arm   ov009
 *   NNCancel                     0x02199FB4 arm   ov009
 *   func_0217603C                0x0217603C arm   ov009
 *   func_02195DE4                0x02195DE4 arm   ov009
 *   func_02175F4C                0x02175F4C arm   ov009
 *   func_020870D0                0x020870D0 arm
 *   func_02172BB8                0x02172BB8 arm   ov009
 *   DWCi_GetMatchCnt                  0x02175F3C arm
 *   d_021A207C  0x021A207C  data
 *   d_021A2080  0x021A2080  data
 *   d_021A2084  0x021A2084  data
 *   d_021A2088  0x021A2088  data
 *   d_021A208C  0x021A208C  data
 *   OS_SNPrintf  0x02084F80  arm
 *   func_02168454  0x02168454  arm  ov009
 *   func_0216848C  0x0216848C  arm  ov009
 *   func_021767F4  0x021767F4  arm  ov009
 *   func_021690D0  0x021690D0  arm  ov009
 *   DWCi_SetMatchCnt         0x02175F1C arm
 *   DWC_Free                 0x0205A1B0 arm
 *   DWCi_ClearGameMatchKeys  0x02173B18 arm
 *   s_bInNNThink             0x021AAA20 data
 *   DWCi_GetMathRand32            0x021685CC  arm  ov009
 *   MIi_CpuClear32                0x02082A7C  arm
 *   DWCi_ClearMeshMakingTempInfo  0x02176870  arm  ov009
 *   DWCi_GetHostStatus            0x02175FB8  arm  ov009
 *   DWCi_SetMatchStatus           0x02175F4C  arm  ov009
 *   DWCi_NodeInfoList_Clear       0x0217601C  arm  ov009
 *   DWCi_TempNewNodeInfo_Clear    0x0217653C  arm  ov009
 *   MI_CpuFill8                   0x02082BCC  arm
 *   func_0216F388  0x0216F388  arm  ov009
 *   g_021AAA20  0x021AAA20  data
 *   func_0219ED4C  0x0219ED4C  arm  ov009
 *   func_02176B34  0x02176B34  arm  ov009
 *   func_0217601C  0x0217601C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_021685CC  0x021685CC  arm  ov009
 *   func_0219F00C  0x0219F00C  arm  ov009
 *   func_0219EED4  0x0219EED4  arm  ov009
 *   OS_GetTick     0x020870D0  arm
 *   stGameMatchKeys          0x021AAA40  data
 *   s_anybodyServerSearchRatio 0x021A203C  data
 *   d_021A2090     0x021A2090  data
 *   d_021A209C     0x021A209C  data
 *   d_021A20A4     0x021A20A4  data
 *   d_021A20AC     0x021A20AC  data
 *   d_021A20D4     0x021A20D4  data
 *   d_021A20E0     0x021A20E0  data
 *   func_02084F80  0x02084F80  arm
 *   func_0209477C  0x0209477C  arm
 *   g_021A20E0     0x021A20E0  data
 *   g_021A20F0     0x021A20F0  data
 *   g_021A209C     0x021A209C  data
 *   g_021A20A4     0x021A20A4  data
 *   g_021A2170     0x021A2170  data
 *   g_021A217C     0x021A217C  data
 *   g_021A2108     0x021A2108  data
 *   g_021A2164     0x021A2164  data
 *   ServerBrowserGetMyPublicIPAddr   0x0219F0D8 arm
 *   SOC_GetHostID                    0x0215F7B0 arm
 *   IsPrivateAddr                    0x0216FBB8 arm
 *   gt2GetLocalPort                  0x02195E40 arm
 *   DWCi_SendMatchCommand            0x0216FF2C arm
 *   DWCi_DoNatNegotiationAsync       0x0216FE34 arm
 *   gt2GetSocketSOCKET               0x02195E60 arm
 *   DWCi_NNCompletedCallback         0x02174FE8 arm
 *   func_02198620  0x02198620  arm  ov009
 *   func_0219EF60  0x0219EF60  arm  ov009
 *   gt2GetSocketSOCKET_Alt  0x02195E60  arm  ov009
 *   func_02199DFC  0x02199DFC  arm  ov009
 *   func_02174FE4  0x02174FE4  arm  ov009
 *   func_02174FE8  0x02174FE8  arm  ov009
 *   DWCi_GetGT2ConnectionByProfileID_Alt  0x0216BBDC  arm  ov009
 *   func_021763AC  0x021763AC  arm  ov009
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   func_02177848  0x02177848  arm  ov009
 *   func_021861A8  0x021861A8  arm  ov009
 *   DWC_Base64Encode  0x02059B40  arm
 *   MIi_CpuCopy32  0x02082A90  arm
 *   func_0219EF08  0x0219EF08  arm  ov009
 *   d_021A2190  0x021A2190  data
 *   d_021A2198  0x021A2198  data
 *   d_021A21A0  0x021A21A0  data
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_021864CC  0x021864CC  arm  ov009
 *   DWC_CloseAllConnectionsHard                  0x0216b65c arm ov009
 *   DWC_GetState                                 0x0216b994 arm ov009
 *   DWCi_CancelPreConnectedClientProcess         0x02172124 arm ov009
 *   DWCi_CheckResvCommand                        0x021713cc arm ov009
 *   DWCi_CloseAllConnectionsByTimeout            0x02172e7c arm ov009
 *   DWCi_CloseConnectionHard                     0x0216bea4 arm ov009
 *   DWCi_GetAIDFromProfileID                     0x02173c84 arm ov009
 *   DWCi_GetFriendListIndex                      0x02169038 arm ov009
 *   DWCi_GetGT2Connection                        0x0216baf4 arm ov009
 *   DWCi_GetGT2ConnectionByProfileID             0x0216bbdc arm ov009
 *   DWCi_GetGT2NumConnection                     0x02176978 arm ov009
 *   DWCi_GetResvDenyReasonString                 0x021769e0 arm ov009
 *   DWCi_HandleMatchCommandError                 0x021719a4 arm ov009
 *   DWCi_HandleNNError                           0x02173ef8 arm ov009
 *   DWCi_HandleSBError                           0x02173d9c arm ov009
 *   DWCi_InitClWaitTimeout                       0x02173cfc arm ov009
 *   DWCi_IsBackupMine                            0x021754fc arm ov009
 *   DWCi_IsFullMesh                              0x0217695c arm ov009
 *   DWCi_NodeInfoList_GetCount                   0x0217603c arm ov009
 *   DWCi_NodeInfoList_GetMyNodeInfo              0x02176344 arm ov009
 *   DWCi_NodeInfoList_GetNodeInfoForIndex        0x0217637c arm ov009
 *   DWCi_NodeInfoList_GetNodeInfoForProfileID    0x021763ac arm ov009
 *   DWCi_NodeInfoList_GetServerNodeInfo          0x02176358 arm ov009
 *   DWCi_ProcessMatchPollingPacket               0x0216f058 arm ov009
 *   DWCi_ProcessRequestMatch                     0x021758c4 arm ov009
 *   DWCi_ProcessResvOK                           0x02171884 arm ov009
 *   DWCi_ResetLastSomeDataRecvTimeByAidAll       0x02175fe4 arm ov009
 *   DWCi_RetryReserving                          0x02171e34 arm ov009
 *   DWCi_SBUpdateAsync                           0x0216f770 arm ov009
 *   DWCi_StopMatch                               0x0216eb68 arm ov009
 *   DWCi_StopMeshMaking                          0x02176674 arm ov009
 *   DWCi_TempNewNodeInfo_IsValid                 0x02176554 arm ov009
 *   gpIsBuddy                                    0x021861a8 arm ov009
 *   gt2CloseAllConnectionsHard                   0x02195de4 arm ov009
 *   INTRUDE_COMM_IsJoinRequestValid                0x02175FB8 arm   ov009
 *   DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID 0x02176500 arm   ov009
 *   func_02176344                0x02176344 arm   ov009
 *   func_02171524                0x02171524 arm   ov009
 *   DWCi_IsServerLocked              0x021767f4 arm
 *   DWCi_IsFriendByIdxList           0x02173b74 arm
 *   DWCi_GetNumEntry                 0x02175760 arm
 *   DWC_GetSuspendMatch              0x0216cb90 arm
 *   DWCi_SetupGameServer_InterChange 0x021755d4 arm
 *   qr2_send_statechanged        0x0219B490 arm   ov009
 *   func_02176474                0x02176474 arm   ov009
 *   func_0217637C                0x0217637C arm   ov009
 *   _s32_div_f                       0x0209C0A4 arm
 *   DWCi_GetUserData                 0x0216A39C arm
 *   DWC_GetGsProfileId               0x020598EC arm
 *   DWCi_Acc_IsValidFriendData       0x020596F0 arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   gpGetBuddyStatus                 0x02185FD4 arm
 *   DWCi_IsLockedBuddyStatus         0x02176984 arm
 *   func_02171C08                0x02171C08 arm   ov009
 *   func_02176554  0x02176554  arm  ov009
 *   func_02176674                0x02176674 arm   ov009
 *   DWCi_CancelPreConnectedServerProcessWithResetLevel 0x02171FD4 arm
 *   func_0217695C                0x0217695C arm   ov009
 *   DWCi_PostProcessSVConnectionFullmesh  0x0217273C  arm
 *   DWCi_PostProcessSVConnectionHybrid    0x02172604  arm
 *   DWCi_SetHostStatus                    0x02175F84  arm
 *   DWCi_NodeInfo_IsValid                 0x02176580  arm
 *   DWCi_NodeInfoList_InsertToTop         0x0217604C  arm
 *   DWCi_NodeInfo_Clear                   0x0217656C  arm
 *   DWCi_GPSetServerStatus                0x0216F20C  arm
 *   DWCi_HandleGPError                    0x02173D28  arm
 *   ServerBrowserClear                    0x0219F00C  arm
 *   DWCi_PostProcessConnectionSYNFinishFullmesh 0x021725EC arm
 *   DWCi_NodeInfoList_Append             0x021760FC arm
 *   DWCi_NodeInfoList_GetNodeInfoForAID  0x02176410 arm
 *   func_0217253C  0x0217253C  arm  ov009
 *   func_02173064                0x02173064 arm   ov009
 *   DWCi_GetNodeInfoCount  0x02176978  arm  ov009
 *   DWCi_GT2GetConnectionListIdx  0x0216BB6C  arm  ov009
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   func_02169038  0x02169038  arm  ov009
 *   DWCi_FinishCancelMatch        0x02172A58  arm  ov009
 *   func_02195DC4  0x02195DC4  arm  ov009
 *   func_02176254  0x02176254  arm  ov009
 *   gt2CloseAllConnections  0x02195DE4  arm  ov009
 *   DWC_Alloc                        0x0205A16C arm
 *   DWCi_SendReliable                0x02176EB0 arm
 *   _ll_udiv                         0x0209C00C arm
 *   DWCi_ServerSynTimeoutExec        0x0217352C arm
 *   DWCi_SendTypeMatchAck            0x021735A4 arm
 *   func_021720D8  0x021720D8  arm  ov009
 *   DWCi_SendCancelMatchSynCommand   0x02173614 arm
 *   DWCi_GetAIDBitmask               0x02173C9C arm
 *   DWCi_CloseShutdownClientSC       0x02172EAC arm
 *   d_021AAA40     0x021AAA40  data
 *   g_021AAA40  0x021AAA40  data
 *   func_02168FF0  0x02168FF0  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 *   g_021A21A4     0x021A21A4  data
 *   g_021A21B0     0x021A21B0  data
 *   @24369         0x021A2188  data
 *   func_0216A3B8  0x0216A3B8  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 *   DWCi_SBPrintServerData                     0x0217478C arm ov009
 *   ServerBrowserCount                         0x0219F068 arm ov009
 *   ServerBrowserGetServer                     0x0219F058 arm ov009
 *   DWCi_CheckDWCServer                        0x02173BE4 arm ov009
 *   ServerBrowserRemoveServer                  0x0219EFA8 arm ov009
 *   SBServerGetPublicInetAddress               0x0219E1EC arm ov009
 *   SBServerGetPublicQueryPort                 0x0219E1F4 arm ov009
 *   SBServerGetPrivateInetAddress              0x0219E238 arm ov009
 *   SBServerGetPrivateQueryPort                0x0219E240 arm ov009
 *   SBServerHasPrivateAddress                  0x0219E220 arm ov009
 *   DWCi_StartMatch                            0x02175AA4 arm ov009
 *   DWCi_NodeInfoList_GetFreeAID               0x02176474 arm ov009
 *   DWCi_EvaluateServers                       0x02174790 arm ov009
 *   DWCi_RandomizeServers                      0x02174930 arm ov009
 *   SBServerGetIntValueA                       0x0219E120 arm ov009
 *   DWCi_ConnectToGameServerAsync_InterChange  0x02175698 arm ov009
 *   DWCi_CancelReservation                     0x02171F68 arm ov009
 *   DWCi_GetTopologyType                       0x02176860 arm ov009
 *   DWCi_ConnectToGameServerAsync              0x0216D27C arm ov009
 */
#include "dwc_match_ctl_types.h"
#include "../../matched/include/G_MatchAnchorA.h"
#include "../../matched/arm9_sdk/libc/string.h"

#define MCP ((char *)DWCi_GetMatchCnt())
#define NULL ((void *)0)
#define MC() DWCi_GetMatchCnt()
#define SOC_HtoNs(s) ((u16)((((s) >> 8) & 0x00ff) | (((s) << 8) & 0xff00)))
#define RETRY() do { MC()->sbUpdateFlag = 2; tick = OS_GetTick(); MC()->sbUpdateTick = tick; } while (0)
struct ServerBrowser;
struct DWCstBinaryMessage;
struct SBServer;
struct GT2Socket { void *pad; };

typedef enum { E0 = 0, E6 = 6 } EFld;

typedef enum { SBFalse, SBTrue } SBBool;

typedef enum { sbe_noError, sbe_socketError, sbe_dnsError, sbe_connectError, sbe_dataError, sbe_allocError, sbe_paramError, sbe_duplicateUpdateError } SBError;

struct nninfo_s {
    unsigned char clientindex;
    unsigned char pad1;
    unsigned short port;
    int ip;
    int cookie;
};

typedef struct {
    char id[5];
} MatchId;

typedef struct {
    MatchId id;
    unsigned char pad[3];
    unsigned char command;
    unsigned char len;
    unsigned short port;
    int ip;
    int pid;
    unsigned int data[32];
} MatchCtrl;

typedef struct DWCstBinaryMessageHeader {
    char identifier[4];
    unsigned long version;
    unsigned char command;
    unsigned char size;
    unsigned short qr2Port;
    unsigned long qr2IP;
    int profileID;
} DWCstBinaryMessageHeader;

typedef struct DWCstBinaryMessage {
    DWCstBinaryMessageHeader header;
    unsigned long data[32];
} DWCstBinaryMessage;

struct GPBuddyStatus
{
    int f0;
    int f4;
    u8 pad[0x214 - 8];
};

typedef struct GTI2Socket GTI2Socket;

typedef unsigned long u32_021732F8;

typedef unsigned int   u32_0217352C;

typedef unsigned long u32_021738EC;

typedef unsigned int   u32_02173AD8;

enum E { E_OK, E_A, E_B, E_C, E_D, E_E, E_NET };

extern int DWC_GetAIDBitmap(void);
extern int DWCi_CloseConnectionHard(unsigned char aid);
extern int DWC_IsServerMyself(void);
extern void *func_02176358(void);
extern int DWC_GetState(void);
extern void func_0216EB68(int error, int errorCode);
extern void NNCancel(int cookie);
extern int func_0217603C(void);
extern void func_02195DE4(int *p);
extern void func_02175F4C(int state);
extern u64 func_020870D0(void);
extern void func_02172BB8(int level);
extern int OS_SNPrintf(char *dst, u32 len, const char *fmt, ...);
extern int func_02168454(const char *key, const char *value, char *string, char sep);
extern int func_0216848C(const char *key, const char *value, char *string, char sep);
extern int func_021767F4(void);
extern int func_021690D0(int status, const char *statusString, const char *locString);
extern void DWCi_SetMatchCnt(void *pCnt);
extern void DWC_Free(int name, void *ptr, int flag);
extern void DWCi_ClearGameMatchKeys(void);
extern u32 DWCi_GetMathRand32(u32 max);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern void DWCi_ClearMeshMakingTempInfo(void);
extern int DWCi_GetHostStatus(void);
extern void DWCi_SetMatchStatus(int state);
extern void DWCi_NodeInfoList_Clear(void);
extern void DWCi_TempNewNodeInfo_Clear(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
extern void func_0216F388(int flag);
extern void func_0219ED4C(struct ServerBrowser *sb);
extern void func_02176B34(void);
extern void func_0217601C(void);
extern void func_0217653C(void);
extern u32 func_021685CC(u32 max);
extern void func_0219F00C(char *p);
extern int func_0219EED4(struct ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields, int numBasicFields, char *serverFilter, int maxServers);
extern u64 OS_GetTick(void);
extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern int func_0209477C(const u8 *s);
extern u32 ServerBrowserGetMyPublicIPAddr(void * sb);
extern long SOC_GetHostID(void);
extern int IsPrivateAddr(u32 addr);
extern u32 gt2GetLocalPort(int socket);
extern int DWCi_SendMatchCommand(u8 command, int profileID, u32 ip, u16 port, u32 * data, int len);
extern int DWCi_DoNatNegotiationAsync(void * nnInfo);
extern int gt2GetSocketSOCKET(void *socket);
extern void DWCi_NNCompletedCallback(int result, int gamesocket, void *remoteaddr, void *userdata);
extern char *func_02198620(unsigned int ip, unsigned short port, char *string);
extern int func_0219EF60(struct ServerBrowser *sb, char *ip, unsigned short port, int cookie);
extern int gt2GetSocketSOCKET_Alt(const int *p);
extern int func_02199DFC(int sock, int cookie, int clientindex, void *progress, void *completed, void *userdata);
extern void func_02174FE4(void);
extern void func_02174FE8(void);
extern int *DWCi_GetGT2ConnectionByProfileID_Alt(int pid, int flag);
extern char *func_021763AC();
extern unsigned char DWC_GetMyAID(void);
extern int func_02177848(unsigned char from, unsigned char to, const void *data, int size, int flag);
extern int func_021861A8(void *conn, int pid);
extern int DWC_Base64Encode(const void *src, int srclen, char *dst, int dstlen);
extern void MIi_CpuCopy32(const void *src, void *dst, int size);
extern int func_0219EF08(struct ServerBrowser *sb, char *ip, unsigned short port, char *data, int len);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern int func_021864CC(void **connection, int profile, char *message);
extern int DWC_GetState(void);
extern int DWCi_NodeInfoList_GetCount(void);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForIndex(int index);
extern void DWCi_InitClWaitTimeout(void);
extern u8 DWCi_CheckResvCommand(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType,
                                int connectGroupID, u32 topologyType,
                                u8 *newClientUserData, int meshReserve);
extern int DWCi_ProcessResvOK(int profileID, u32 ip, u16 port);
extern int DWCi_HandleMatchCommandError(int error);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetNodeInfoForProfileID(int profileID);
extern int DWCi_GetFriendListIndex(int profileID);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetMyNodeInfo(void);
extern char *DWCi_GetResvDenyReasonString(u8 denyReason);
extern int DWCi_SBUpdateAsync(int profileID);
extern int DWCi_HandleSBError(int error);
extern int DWCi_HandleNNError(int error);
extern int DWCi_StopMeshMaking(void);
extern void DWCi_StopMatch(int error, int errorCode);
extern int DWCi_RetryReserving(int resendPid);
extern int gpIsBuddy(void *connection, int profile);
extern int DWCi_TempNewNodeInfo_IsValid(void);
extern void *DWCi_GetGT2ConnectionByProfileID(int profileID, int idx);
extern void gt2CloseAllConnectionsHard(void *socket);
extern int DWCi_IsFullMesh(void);
extern int DWCi_GetGT2NumConnection(void);
extern void *DWCi_GetGT2Connection(u8 aid);
extern DWCstNodeInfo *DWCi_NodeInfoList_GetServerNodeInfo(void);
extern int DWCi_CancelPreConnectedClientProcess(int clientPid);
extern void DWCi_CloseAllConnectionsByTimeout(void);
extern int DWCi_CloseConnectionHard(u8 aid);
extern int DWCi_IsBackupMine(void);
extern u8 DWCi_GetAIDFromProfileID(int profileID, int idx);
extern void DWCi_ResetLastSomeDataRecvTimeByAidAll(void);
extern int DWC_CloseAllConnectionsHard(void);
extern int DWCi_ProcessRequestMatch(u8 AID, int suspend, int immediate);
extern unsigned char INTRUDE_COMM_IsJoinRequestValid(void);
extern int DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(int profileID);
extern char *func_02176344(void);
extern u8 func_02171524(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve);
extern int DWCi_IsServerLocked(void);
extern int DWCi_IsFriendByIdxList(int profileID);
extern int DWCi_GetNumEntry(void);
extern int DWC_GetSuspendMatch(void);
extern void DWCi_SetupGameServer_InterChange(int init);
extern void qr2_send_statechanged(void *qrec);
extern u8 func_02176474(void);
extern DWCstNodeInfo *func_0217637C(int index);
extern void * DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(void * userdata, void * frienddata);
extern int DWCi_Acc_IsValidFriendData(void * frienddata);
extern int gpGetBuddyIndex(void * connection, int profile, int * index);
extern int gpGetBuddyStatus(void * connection, int index, struct GPBuddyStatus * status);
extern int DWCi_IsLockedBuddyStatus(struct GPBuddyStatus * status);
extern void _s32_div_f(void);
extern int func_02171C08(int delay, int init, int resendPid);
extern int func_02176554(void);
extern int func_02176674(void);
extern int DWCi_CancelPreConnectedServerProcessWithResetLevel(int clientPid, int resetLevel);
extern int func_0217695C(void);
extern void DWCi_PostProcessSVConnectionFullmesh(void);
extern void DWCi_PostProcessSVConnectionHybrid(void);
extern void DWCi_SetHostStatus(int host);
extern int DWCi_NodeInfo_IsValid(DWCstNodeInfo *node);
extern int DWCi_NodeInfoList_InsertToTop(DWCstNodeInfo *newNode);
extern void DWCi_NodeInfo_Clear(DWCstNodeInfo *node);
extern int DWCi_GPSetServerStatus(int matchType);
extern int DWCi_HandleGPError(int result);
extern void ServerBrowserClear(void *sb);
extern void DWCi_PostProcessConnectionSYNFinishFullmesh(void);
extern int DWCi_NodeInfoList_Append(DWCstNodeInfo *newNode);
extern DWCstNodeInfo * DWCi_NodeInfoList_GetNodeInfoForAID(unsigned char aid);
extern void func_0217253C(void);
extern void func_02173064(u8 aid, u16 type);
extern int DWCi_GetNodeInfoCount(void);
extern int DWCi_GT2GetConnectionListIdx(void);
extern void func_02199FB4(int cookie);
extern int func_02169038(int profileID);
extern void DWCi_FinishCancelMatch(void);
extern void func_02195DC4(int a);
extern int func_02176254(int profileID);
extern void gt2CloseAllConnections(int conn);
extern void * DWC_Alloc(int name, unsigned long size);
extern int DWCi_SendReliable(u16 type, u8 aid, void * buffer, int size);
extern void DWCi_ServerSynTimeoutExec(void);
extern void DWCi_SendTypeMatchAck(void);
extern int func_021720D8(int id);
extern int DWCi_SendCancelMatchSynCommand(int profileID, u8 command);
extern u32 DWCi_GetAIDBitmask(int valid);
extern int DWCi_CloseShutdownClientSC(u32_021738EC bitmap);
extern int func_02168FF0(int idx);
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern void func_0216A3B8(int dwcError, int errorCode);
extern void DWCi_SetError(int dwcError, int errorCode);
extern void DWCi_SBPrintServerData(void *server);
extern int ServerBrowserCount(void *sb);
extern void *ServerBrowserGetServer(void *sb, int index);
extern int DWCi_CheckDWCServer(void *server);
extern void ServerBrowserRemoveServer(void *sb, void *server);
extern u32 SBServerGetPublicInetAddress(void *server);
extern unsigned short SBServerGetPublicQueryPort(void *server);
extern u32 SBServerGetPrivateInetAddress(void *server);
extern unsigned short SBServerGetPrivateQueryPort(void *server);
extern int SBServerHasPrivateAddress(void *server);
extern int DWCi_StartMatch(void);
extern unsigned char DWCi_NodeInfoList_GetFreeAID(void);
extern int DWCi_EvaluateServers(int sort);
extern void DWCi_RandomizeServers(void);
extern int SBServerGetIntValueA(void *server, char *key, int idefault);
extern void DWCi_ConnectToGameServerAsync_InterChange(int a);
extern int DWCi_CancelReservation(int pid);
extern int DWCi_GetTopologyType(void);
extern void DWCi_ConnectToGameServerAsync(int topology, int serverPid,
    void *a, void *b, void *c, void *d, void *e, void *f, void *g);
void func_0216F014(unsigned int bitmap);
void func_0216F058(const Poll *p);
int func_0216F0A0(int error, int errorCode);
void DWCi_ProcessMatchSCClosing(int clientPid);
int func_0216F20C(int status);
void DWCi_ShutdownMatch(void);
int func_0216F370(void);
void DWCi_ResetMatchParam(int level);
void func_0216F5FC(unsigned char matchType, unsigned char numEntry, void *callback, void *param);
void func_0216F6C0(void);
int func_0216FAD4(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
int func_0216FBB8(unsigned long addr_in_netorder);
int DWCi_NNStartupAsync(int isQR2, int cookie, DWCstNodeInfo * node);
int func_0216FE34(struct nninfo_s *nnInfo);
int func_0216FEF0(unsigned char command, int pid);
int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len);
void func_021700C8(DWCstBinaryMessage *message, unsigned char command, unsigned long *data, int len);
int func_02170168(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len);
int func_02170200(void *conn, unsigned char command, int pid, const char *data);
int func_021702A0(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len);
u8 func_021713CC(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve);
unsigned char DWCi_CheckResvCommand_Sub(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, unsigned char *newClientUserData, int meshReserve);
int func_02171884(int profileID);
int func_021719A4(int error);
int DWCi_SendResvCommand(int profileID, int delay);
int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid);
int func_02171E34(int resendPid);
int func_02171F68(int arg);
int func_02171FD4(int clientPid, int resetLevel);
int DWCi_CancelPreConnectedServerProcess(int clientPid);
int func_02172124(void);
void DWCi_PostProcessConnection(int type);
void DWCi_PostProcessConnectionSYNFinish(void);
void DWCi_PostProcessConnectionSYNFinishHybrid(void);
void func_021725EC(void);
int func_02172604(void);
int func_0217273C(void);
void func_02172A58(void);
int func_02172B08(void);
void DWCi_RestartFromCancel(int level);
void DWCi_RestartFromTimeout(void);
int DWCi_ResumeMatch(void);
int func_02172E18(int profileID);
void func_02172E7C(void);
void DWCi_SendMatchSynPacket(u8 aid, u16 type);
int DWCi_ProcessMatchSynTimeout(void);
int func_0217352C(void);
void func_021735A4(void);
int func_02173614(int profileID, unsigned char command);
int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data);
int DWCi_ProcessCancelMatchSynTimeout(void);
u8 func_02173AD8(void);
void func_02173B18(void);
int func_02173B74(int profileID);
int INTRUDE_COMM_RecvNoticeBytes(void *server);
u8 func_02173C84(int profileID, int idxOnly);
unsigned int INTRUDE_COMM_RecvRemoteRecord(int valid);
void func_02173CFC(void);
int func_02173D28(int error);
int func_02173D9C(int error);
int func_02173E30(int error);
int func_02173EF8(int error);
int func_02173F54(int result);
int func_02173FB4(int result);
void func_02174058(void *sb, int reason, void *server);
extern char d_021A207C[];
extern char d_021A2080[];
extern char d_021A2084[];
extern char d_021A2088[];
extern char d_021A208C[];
extern struct NNThinkGlobal s_bInNNThink;
extern struct NNThinkGlobal g_021AAA20;
extern DWCstGameMatchKeyData stGameMatchKeys[154];
extern struct MatchAnchorA s_anybodyServerSearchRatio;
extern char d_021A2090[];
extern char d_021A209C[];
extern char d_021A20A4[];
extern char d_021A20AC[];
extern char d_021A20D4[];
extern char d_021A20E0[];
extern char g_021A20E0[];
extern char g_021A20F0[];
extern char g_021A209C[];
extern char g_021A20A4[];
extern char g_021A2170[];
extern char g_021A217C[];
extern char g_021A2108[];
extern char g_021A2164[];
extern char d_021A2190[];
extern char d_021A2198[];
extern char d_021A21A0[];
extern u8 d_021AAA40[];
extern DWCstGameMatchKeyData g_021AAA40[];
extern char g_021A21A4[];
extern char g_021A21B0[];























/*
 * Hard-closes every aid present now but absent from the given bitmap.
 */
void func_0216F014(unsigned int bitmap)
{
    unsigned int cur = DWC_GetAIDBitmap();
    unsigned int diff = cur & (cur ^ bitmap);
    unsigned char i;

    if (diff == 0) {
        return;
    }
    for (i = 0; i < 0x20; i++) {
        if (diff & (1 << i)) {
            DWCi_CloseConnectionHard(i);
        }
    }
}























/*
 * DWCi_ProcessMatchPollingPacket: on a client, closes the aids a server poll no longer lists.
 */
void func_0216F058(const Poll *p)
{
    int pid = p->pid;
    unsigned int bitmap = p->bitmap;
    int id = p->id;
    int *node;

    if (DWC_IsServerMyself() != 0) {
        return;
    }
    if (id != *(int *)((char *)func_02175F3C() + 0x7c8)) {
        return;
    }
    node = func_02176358();
    if (node == 0) {
        return;
    }
    if (*node != pid) {
        return;
    }
    func_0216F014(bitmap);
}























/*
 * sdk:      DWCi_ProcessMatchClosing (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_0216F0A0(int error, int errorCode)
{
    u64 tick;

    if (DWC_GetState() != 4)
        return 0;
    if (((DWCstMatchControl *)func_02175F3C())->qr2MatchType == 2)
        return 1;
    if (error != 0) {
        func_0216EB68(error, errorCode - 80000);
        return 1;
    }
    if (((DWCstMatchControl *)func_02175F3C())->cancelState == 1 || ((DWCstMatchControl *)func_02175F3C())->closeState == 1)
        return 1;
    if (((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie != 0) {
        NNCancel(((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie);
        ((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie = 0;
    }
    if (func_0217603C() > 1) {
        if (((DWCstMatchControl *)func_02175F3C())->closeState == 0) {
            ((DWCstMatchControl *)func_02175F3C())->closeState = 2;
            func_02195DE4((int *)(*((DWCstMatchControl *)func_02175F3C())->pGt2Socket));
        }
    } else if (((DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
        func_0216EB68(0x16, -80430);
    } else if (((DWCstMatchControl *)func_02175F3C())->state == 1) {
        func_02175F4C(0x15);
        tick = func_020870D0();
        ((DWCstMatchControl *)func_02175F3C())->closedTime = tick;
    } else {
        func_02172BB8(1);
    }
    return 1;
}























void DWCi_ProcessMatchSCClosing(int clientPid)
{
    if (DWCi_GetMatchCnt()->closeState == 1)
        return;
    DWCi_CancelPreConnectedServerProcess(clientPid);
}























/*
 * Builds the match key-value status string and hands it to DWCi_SetGPStatus.
 */
int func_0216F20C(int status)
{
    char value[12];
    char str[0x27];
    int n;

    OS_SNPrintf(value, 12, d_021A207C, *(unsigned char *)((char *)func_02175F3C() + 0x17) + 1);
    func_02168454(d_021A2080, value, str, '/');
    n = func_0217603C();
    if (*(unsigned char *)((char *)func_02175F3C() + 0x15) == 2 && n == 0) {
        n = 1;
    }
    OS_SNPrintf(value, 12, d_021A207C, n);
    func_0216848C(d_021A2084, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, 0x5a);
    func_0216848C(d_021A2088, value, str, '/');
    OS_SNPrintf(value, 12, d_021A207C, func_021767F4() ? 1 : 0);
    func_0216848C(d_021A208C, value, str, '/');
    return func_021690D0(status, str, 0);
}























void DWCi_ShutdownMatch(void)
{
    DWCi_SetMatchCnt(0);
    if (s_bInNNThink.addFilter != 0) {
        DWC_Free(4, s_bInNNThink.addFilter, 0);
        s_bInNNThink.addFilter = 0;
    }
    DWCi_ClearGameMatchKeys();
}























/*
 * Set when the module block is absent.
 */
int func_0216F370(void)
{
    return func_02175F3C() == 0;
}























void DWCi_ResetMatchParam(int level)
{
	*(u8 *)(MCP + 0xc) = 0;
	*(u8 *)(MCP + 0x5f8) = 0;
	*(u16 *)(MCP + 0x5fa) = DWCi_GetMathRand32(0x10000);
	*(u32 *)(MCP + 0x5fc) = 0;
	*(u64 *)(MCP + 0x600) = 0;
	*(u64 *)(MCP + 0x608) = 0;
	*(u8 *)(MCP + 0x620) = 0;
	*(u8 *)(MCP + 0x62a) = 0;
	*(u8 *)(MCP + 0x62b) = 0;
	*(u8 *)(MCP + 0x62c) = 0;
	*(u8 *)(MCP + 0x62d) = 0;
	*(u8 *)(MCP + 0x628) = 0;
	*(u8 *)(MCP + 0x629) = 0;
	*(u16 *)(MCP + 0x632) = 0;
	*(u64 *)(MCP + 0x658) = 0;
	*(u64 *)(MCP + 0x668) = 0;
	MIi_CpuClear32(0, MCP + 0x6d8, 0x98);
	*(u32 *)(MCP + 0x5a4) = 0;
	DWCi_ClearMeshMakingTempInfo();
	if (level == 2) {
		if (DWCi_GetHostStatus() == 2) {
			DWCi_SetMatchStatus(0xd);
			return;
		}
		if (DWCi_GetHostStatus() == 1)
			DWCi_SetMatchStatus(1);
		return;
	}
	*(u8 *)(MCP + 0x18) = 0;
	*(u32 *)(MCP + 0x5dc) = 0;
	*(u32 *)(MCP + 0x5e4) = 0;
	*(u16 *)(MCP + 0x630) = 0;
	*(u8 *)(MCP + 0x621) = 0;
	*(u32 *)(MCP + 0x638) = 0;
	*(u64 *)(MCP + 0x63c) = 0;
	*(u32 *)(MCP + 0x644) = 0;
	*(u64 *)(MCP + 0x648) = 0;
	*(u32 *)(MCP + 0x650) = 0;
	*(u32 *)(MCP + 0x67c) = 0;
	MIi_CpuClear32(0, MCP + 0x610, 0xc);
	*(u32 *)(MCP + 0x788) = 0;
	*(u32 *)(MCP + 0x78c) = 0;
	*(u8 *)(MCP + 0x794) = 0;
	*(u8 *)(MCP + 0x7a8) = 1;
	*(u32 *)(MCP + 0x7ac) = 0;
	*(u8 *)(MCP + 0x16) = 0;
	*(u8 *)(MCP + 0xd) = 0;
	*(u32 *)(MCP + 0x7b8) = 0;
	*(u32 *)(MCP + 0x7c0) = 0;
	DWCi_NodeInfoList_Clear();
	DWCi_TempNewNodeInfo_Clear();
	*(u32 *)(MCP + 0x57c) = 0;
	if (level == 1) {
		if (*(u8 *)(MCP + 0x15) == 0 || *(u8 *)(MCP + 0x15) == 1)
			DWCi_SetMatchStatus(0x16);
		return;
	}
	*(u8 *)(MCP + 0x14) = 0;
	*(u8 *)(MCP + 0x17) = 0;
	*(u8 *)(MCP + 0x4c) = 0;
	*(u32 *)(MCP + 0x680) = 0;
	*(u8 *)(MCP + 0x62e) = 0;
	*(u64 *)(MCP + 0x670) = 0;
	*(u32 *)(MCP + 0x778) = 0;
	*(u32 *)(MCP + 0x77c) = 0;
	MI_CpuFill8(MCP + 0x7bc, 0, 4);
}






















/*
 * sdk:      DWCi_SetMatchCommonParam (dwc_match.o)
 */
void func_0216F5FC(unsigned char matchType, unsigned char numEntry, void *callback, void *param)
{
    func_0216F388(0);
    *(unsigned char *)((char *)func_02175F3C() + 0x14) = matchType;
    *(unsigned char *)((char *)func_02175F3C() + 0x17) = numEntry;
    *(void **)((char *)func_02175F3C() + 0x770) = callback;
    *(void **)((char *)func_02175F3C() + 0x774) = param;
    *(unsigned char *)((char *)func_02175F3C() + 0x5f9) = 0;
    *(int *)((char *)func_02175F3C() + 0x2c) = 0xff;
    *(unsigned char *)((char *)func_02175F3C() + 0x30) = 0;
    *(unsigned char *)((char *)func_02175F3C() + 0x16) = 0;
    *(unsigned char *)((char *)func_02175F3C() + 0x7a8) = 1;
    *(int *)((char *)func_02175F3C() + 0x7ac) = 0;
    *(unsigned char *)((char *)func_02175F3C() + 0x17) = numEntry;
    *(int *)((char *)func_02175F3C() + 0x1c) = 0;
    *(int *)((char *)func_02175F3C() + 0x28) = 0;
    *(unsigned long long *)((char *)func_02175F3C() + 0x20) = 0;
    *(int *)((char *)func_02175F3C() + 0x48) = 0;
    *(int *)((char *)func_02175F3C() + 0x7c4) = 1;
    *(unsigned long long *)((char *)func_02175F3C() + 0x7cc) = 0;
    *(int *)((char *)func_02175F3C() + 0x634) = 0;
}






















/*
 * Resets the match state: frees the server browser and negotiation data and clears the node lists.
 */
void func_0216F6C0(void)
{
    if (func_02175F3C() == 0) {
        return;
    }
    if (*(void **)((char *)func_02175F3C() + 0x5e0) != 0) {
        if (*(int *)(((char *)&g_021AAA20) + 0x14) != 0) {
            *(int *)(((char *)&g_021AAA20) + 0x10) = 1;
        } else {
            func_0219ED4C(*(void **)((char *)func_02175F3C() + 0x5e0));
            *(void **)((char *)func_02175F3C() + 0x5e0) = 0;
        }
    }
    func_02176B34();
    func_02175F4C(0);
    if (*(void **)(((char *)&g_021AAA20) + 0xc) != 0) {
        DWC_Free(4, *(void **)(((char *)&g_021AAA20) + 0xc), 0);
        *(void **)(((char *)&g_021AAA20) + 0xc) = 0;
    }
    func_02173B18();
    *(unsigned char *)((char *)func_02175F3C() + 0x4c) = 1;
    func_0217601C();
    func_0217653C();
    *(int *)((char *)func_02175F3C() + 0x7c4) = 1;
    func_0216F20C(1);
}




















/* * 2026-10-01 (lane 05): rebuilt from the vendor listing, 868/868 bytes and * 6 concrete bytes (was 212 via permuter scaffolding). Fixes: the * ratio tests are -2 then -1 (not -1 then 0) with a signed rand * compare; s_bInNNThink+0xc is a char * static passed as the * SNPrintf argument; cases 3/4/0x16 and 9-11 print profileID (the * parameter, still in r4) with fmt d_021A209C/d_021A20A4; * searchHostType is set only in case 2; sbBlock/sbError are enums * (DWARF); a real u64 tick across DWCi_GetMatchCnt; the key loop * stores then increments; declarations in DWARF order. Stand-in: * the enum `n` (6 before the byte stores, then the retry counter) * is not in the DWARF but is what keeps `mov sl,#6; add r7,sl,#3` * and the do-while counter (an int folds both away; a 6-trip * unrollable loop is not unrolled by 1.1p1). Residue: the three * DWCi_GetDefaultMatchFilter argument loads (image ldr r1 / ldrb r2 * / ldrb r3, ours ldrb r3 first); const members inert. * 2026-10-01 (wave 2 lane 20): EXACT. The three argument loads read * through `(volatile DWCstMatchControl *)` casts, which pins them * in source (argument) order as the 4.0.0.1025 image has them; * volatile on fewer than two of them leaves the 6 B residue. * * sdk: DWCi_SBUpdateAsync (libdwcmatch.TWL.HYB.a(dwc_match.o)) */ static SBError func_0216F770(int profileID);





















/*
 * 2026-10-01 (lane 05): rebuilt from the vendor listing, 868/868 bytes and
 *           6 concrete bytes (was 212 via permuter scaffolding).  Fixes: the
 *           ratio tests are -2 then -1 (not -1 then 0) with a signed rand
 *           compare; s_bInNNThink+0xc is a char * static passed as the
 *           SNPrintf argument; cases 3/4/0x16 and 9-11 print profileID (the
 *           parameter, still in r4) with fmt d_021A209C/d_021A20A4;
 *           searchHostType is set only in case 2; sbBlock/sbError are enums
 *           (DWARF); a real u64 tick across DWCi_GetMatchCnt; the key loop
 *           stores then increments; declarations in DWARF order.  Stand-in:
 *           the enum `n` (6 before the byte stores, then the retry counter)
 *           is not in the DWARF but is what keeps `mov sl,#6; add r7,sl,#3`
 *           and the do-while counter (an int folds both away; a 6-trip
 *           unrollable loop is not unrolled by 1.1p1).  Residue: the three
 *           DWCi_GetDefaultMatchFilter argument loads (image ldr r1 / ldrb r2
 *           / ldrb r3, ours ldrb r3 first); const members inert.
 * 2026-10-01 (wave 2 lane 20): EXACT.  The three argument loads read
 *           through `(volatile DWCstMatchControl *)` casts, which pins them
 *           in source (argument) order as the 4.0.0.1025 image has them;
 *           volatile on fewer than two of them leaves the 6 B residue.
 *
 * sdk:      DWCi_SBUpdateAsync (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
static SBError func_0216F770(int profileID)
{
    char filter[511];
    u8 basicFields[204];
    int len;
    int numBasicFields;
    int i;
    SBError sbError;
    SBBool sbBlock;
    u8 searchHostType;
    EFld n;

    n = E6;
    basicFields[0] = 8;
    basicFields[1] = 0xa;
    basicFields[2] = 0x32;
    basicFields[3] = 0x33;
    basicFields[4] = 0x34;
    basicFields[5] = 0x35;
    basicFields[6] = 0x36;
    basicFields[7] = 0x37;
    basicFields[8] = 0x38;
    numBasicFields = n + 3;
    sbBlock = SBTrue;
    if (func_02175F3C()->qr2MatchTypeExt == 0 || func_02175F3C()->qr2MatchTypeExt == 1) {
        for (i = 0; i < 154; i++) {
            if (stGameMatchKeys[i].keyID) {
                basicFields[numBasicFields] = stGameMatchKeys[i].keyID;
                numBasicFields++;
            }
        }
    }
    switch (func_02175F3C()->state) {
    case 2:
        if ((*(int *)&s_anybodyServerSearchRatio) == -2) {
            searchHostType = (u8)(func_02175F3C()->serverFind == 1 ? 2 : 3);
            func_02175F3C()->serverFind = 0;
        } else if ((*(int *)&s_anybodyServerSearchRatio) == -1) {
            searchHostType = (u8)(func_02175F3C()->serverFind ? 2 : 0);
            func_02175F3C()->serverFind ^= 1;
        } else {
            searchHostType = (u8)((int)func_021685CC(100) < (*(int *)&s_anybodyServerSearchRatio) ? 2 : 0);
        }
        len = func_0216FAD4(filter, ((volatile DWCstMatchControl *)func_02175F3C())->profileID, ((volatile DWCstMatchControl *)func_02175F3C())->qr2NumEntry, ((volatile DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt, searchHostType);
        if (s_bInNNThink.addFilter) {
            OS_SNPrintf(filter + len, 511 - len, d_021A2090, s_bInNNThink.addFilter);
            filter[510] = 0;
        }
        func_02175F3C()->serverBrowserUpdateCount++;
        break;
    case 3:
    case 4:
    case 0x16:
        OS_SNPrintf(filter, 511, d_021A209C, d_021A20A4, profileID);
        func_02175F3C()->reqProfileID = profileID;
        break;
    case 9:
    case 10:
    case 11:
        OS_SNPrintf(filter, 511, d_021A209C, d_021A20A4, profileID);
        sbBlock = SBFalse;
        break;
    case 12:
        OS_SNPrintf(filter, 511, d_021A20AC, d_021A20D4, func_02175F3C()->groupID, d_021A20E0, 2, d_021A20A4, func_02175F3C()->profileID);
        break;
    }

    func_0219F00C(func_02175F3C()->sbObj);
    n = E0;
    do {
        sbError = func_0219EED4(func_02175F3C()->sbObj, sbBlock, SBFalse, basicFields, numBasicFields, filter, func_02175F3C()->state == 0x16 ? 1 : 6);
        if (sbError == 0 || sbError != 2)
            break;
        n++;
    } while (n < 1);
    if (sbError == 0) {
        u64 tick = OS_GetTick();
        func_02175F3C()->sbUpdateRequestTick = tick + 0xefb5f7;
    }
    return sbError;
}





















/*
 * sdk:      DWCi_GetDefaultMatchFilter (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_0216FAD4(char *filter, int profileID, unsigned char numEntry, unsigned char matchType,
                  unsigned char hostState)
{
    char tempFilter[511];

    if (hostState == 3)
        func_02084F80(tempFilter, 511, g_021A20F0, g_021A20E0, 0, g_021A20E0, 2);
    else
        func_02084F80(tempFilter, 511, g_021A209C, g_021A20E0, hostState);
    func_02084F80(filter, 511, g_021A2108, g_021A2164, 90, g_021A20A4, profileID, numEntry, numEntry,
                  g_021A2170, matchType, g_021A217C, 0, tempFilter);
    return func_0209477C((const u8 *)filter);
}





















/*
 * sdk:      IsPrivateAddr (dwc_match.o)
 */
int func_0216FBB8(unsigned long addr_in_netorder)
{
    unsigned long addr_in_hostorder;
    unsigned char a, b;

    addr_in_hostorder = ((addr_in_netorder >> 24) & 0xff) | ((addr_in_netorder >> 8) & 0xff00) | ((addr_in_netorder << 8) & 0xff0000) | ((addr_in_netorder << 24) & 0xff000000);
    a = (addr_in_hostorder & 0xff000000) >> 24;
    b = (addr_in_hostorder & 0xff0000) >> 16;
    if (a == 10)
        return 1;
    if (a == 172 && b >= 16 && b <= 31)
        return 1;
    if (a == 192 && b == 168)
        return 1;
    return 0;
}





















int DWCi_NNStartupAsync(int isQR2, int cookie, DWCstNodeInfo * node)
{
    u32 senddata[2];
    int nnValid;
    int nnError = 0;
    int result;

    NNCancel(DWCi_GetMatchCnt()->nnInfo.cookie);

    if (isQR2 == 0) {
        cookie = (DWCi_GetMatchCnt()->profileID & 0xffff) |
                 (DWCi_GetMatchCnt()->f_5FA << 16);
        if (node->hasPrivateAddress != 0) {
            if (node->publicInetAddress != ServerBrowserGetMyPublicIPAddr(DWCi_GetMatchCnt()->sbObj)) {
                nnValid = 1;
            } else {
                node->gt2IP = node->privateInetAddress;
                node->gt2Port = node->privateQueryPort;
                nnValid = 0;
            }
        } else {
            if (IsPrivateAddr(SOC_GetHostID())) {
                nnValid = 1;
            } else {
                node->gt2IP = node->publicInetAddress;
                node->gt2Port = node->publicQueryPort;
                nnValid = 0;
            }
        }
        if (nnValid) {
            DWCi_GetMatchCnt()->f_5FA = DWCi_GetMathRand32(0x10000);
            DWCi_GetMatchCnt()->nnInfo.cookie = cookie;
        } else {
            senddata[0] = SOC_GetHostID();
            senddata[1] = gt2GetLocalPort(*(int *)DWCi_GetMatchCnt()->pGt2Socket);
            result = DWCi_SendMatchCommand(6, node->profileID, node->publicInetAddress, node->publicQueryPort, senddata, 2);
            DWCi_GetMatchCnt()->cmdCnt.count = 0;
            if (result != 0)
                return 2;
            DWCi_GetMatchCnt()->nnInfo.cookie = 0;
        }
        DWCi_GetMatchCnt()->nnInfo.clientindex = 0;
        DWCi_GetMatchCnt()->nnInfo.f_01 = 0;
        DWCi_GetMatchCnt()->nnInfo.port = node->publicQueryPort;
        DWCi_GetMatchCnt()->nnInfo.ip = node->publicInetAddress;
    } else {
        DWCi_GetMatchCnt()->nnInfo.clientindex = 1;
        DWCi_GetMatchCnt()->nnInfo.f_01 = 0;
        DWCi_GetMatchCnt()->nnInfo.port = 0;
        DWCi_GetMatchCnt()->nnInfo.ip = 0;
        DWCi_GetMatchCnt()->nnInfo.cookie = cookie;
        nnValid = 1;
    }

    if (nnValid) {
        nnError = DWCi_DoNatNegotiationAsync(&DWCi_GetMatchCnt()->nnInfo.clientindex);
    } else {
        DWCstMatchControl * cnt;

        DWCi_NNCompletedCallback(0, gt2GetSocketSOCKET(*DWCi_GetMatchCnt()->pGt2Socket), 0,
                                 &DWCi_GetMatchCnt()->nnInfo.clientindex);
        cnt = DWCi_GetMatchCnt();
        cnt->nnFinishTime = 0;
    }
    return nnError;
}




















/*
 * sdk:      DWCi_DoNatNegotiationAsync (dwc_match.o)
 *
 * notes:    closed (w5_nm): the progress-callback pointer 0x02174FE4 (bx lr leaf,
 *           DWCi_NNProgressCallback) now has a seed, a catalog row and a stub
 *           (src/matched/ov_sdk/ov009_func_02174FE4.c), so it attests as sdk.
 */
int func_0216FE34(struct nninfo_s *nnInfo)
{
    int i;
    int nnError;
    int sbError;

    if (nnInfo->clientindex == 0) {
        sbError = func_0219EF60((struct ServerBrowser *)(*(int *)((char *)func_02175F3C() + 0x5e0)), func_02198620(nnInfo->ip, 0, 0), nnInfo->port, nnInfo->cookie);
        if (func_02173D9C(sbError))
            return 2;
    }
    for (i = 0; i < 1; i++) {
        nnError = func_02199DFC(gt2GetSocketSOCKET_Alt((const int *)(**(int **)((char *)func_02175F3C() + 4))), nnInfo->cookie, nnInfo->clientindex, func_02174FE4, func_02174FE8, nnInfo);
        if (nnError == 0)
            return nnError;
        if (nnError != 3)
            return nnError;
    }
    return nnError;
}




















/*
 * Whether a profile id has both a gt2 connection and a node record.
 */
int func_0216FEF0(unsigned char command, int pid)
{
    int r = 1;

    if (DWCi_GetGT2ConnectionByProfileID_Alt(pid, r) == 0) {
        return 0;
    }
    if (func_021763AC(pid) == 0) {
        r = 0;
    }
    return r;
}




















/*
 * DWCi_SendMatchCommand: sends a match command over gt2, as a GP buddy message, or through the server browser.
 */
int func_0216FF2C(unsigned char command, int pid, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    char buf[0x200];
    unsigned char *node;
    int result;
    int n;
    unsigned long long t;

    if (func_0216FEF0(command, pid) != 0) {
        node = (unsigned char *)func_021763AC(pid);
        func_021700C8((struct DWCstBinaryMessage *)(&ctrl), command, (long unsigned int *)data, len);
        func_02177848(DWC_GetMyAID(), node[0x16], &ctrl, ctrl.len + 0x14, 0);
        result = 0;
    } else if (func_021861A8(*(void **)func_02175F3C(), pid) != 0) {
        n = 0;
        if (data != 0 && len != 0) {
            n = DWC_Base64Encode(data, len * 4, buf, 0x200);
        }
        buf[n] = 0;
        result = func_02170200(*(void **)func_02175F3C(), command, pid, buf);
    } else {
        if (ip == 0) {
            node = (unsigned char *)func_021763AC(pid);
            port = *(unsigned short *)(node + 0xc);
            ip = *(unsigned int *)(node + 4);
        }
        result = func_02170168(command, ip, port, data, len);
    }
    if (command == 2 || command == 6 || command == 8 || command == 9) {
        *(unsigned char *)((char *)func_02175F3C() + 0x6d8) = command;
        *(unsigned short *)((char *)func_02175F3C() + 0x6da) = port;
        *(unsigned int *)((char *)func_02175F3C() + 0x6dc) = ip;
        *(int *)((char *)func_02175F3C() + 0x760) = pid;
        *(int *)((char *)func_02175F3C() + 0x764) = len;
        t = OS_GetTick();
        *(unsigned long long *)((char *)func_02175F3C() + 0x768) = t;
        if (data != 0 && len != 0) {
            MIi_CpuCopy32(data, (char *)func_02175F3C() + 0x6e0, len * 4);
        }
    }
    return result;
}




















/*
 * sdk:      DWCi_EncodeBinaryMsgCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * The 5-byte identifier copy is an inlined `strcpy` of the 4-character
 * keyword literal (vendor template @24369 at 0x021A2188) into the 4-byte
 * identifier; the version word at +4 then overwrites the NUL. Spelling it as a
 * struct copy from an extern gave the same instructions with the pool base in
 * r0 instead of ip (20 B); through strcpy the registers match.
 */
void func_021700C8(DWCstBinaryMessage *message, unsigned char command, unsigned long *data, int len)
{
    if (data == 0 || len == 0) {
        len = 0;
    } else {
        MIi_CpuCopy32(data, message->data, len * 4);
    }
    strcpy(message->header.identifier, "\xbbI\xccM");
    message->header.version = 0x5a;
    message->header.command = command;
    message->header.size = len * 4;
    message->header.qr2Port = *(unsigned short *)((char *)func_02175F3C() + 0x5d4);
    message->header.qr2IP = *(unsigned long *)((char *)func_02175F3C() + 0x5d8);
    message->header.profileID = *(int *)((char *)func_02175F3C() + 0x678);
}




















/*
 * Sends a match command to a host through the server browser.
 */
int func_02170168(unsigned char command, unsigned int ip, unsigned short port, const unsigned int *data, int len)
{
    MatchCtrl ctrl;
    int i;
    int res;

    func_021700C8((struct DWCstBinaryMessage *)(&ctrl), command, (long unsigned int *)data, len);
    for (i = 0; i < 1; i++) {
        res = func_0219EF08(*(void **)((char *)func_02175F3C() + 0x5e0), func_02198620(ip, 0, 0), port, (char *)(&ctrl), ctrl.len + 0x14);
        if (res == 0) {
            return res;
        }
        if (res != 2) {
            return res;
        }
    }
    return res;
}




















/*
 * Sends a match command to a buddy as a GP buddy message.
 */
int func_02170200(void *conn, unsigned char command, int pid, const char *data)
{
    char msg[0x200];
    char *p;
    int len;

    len = OS_SNPrintf(msg, 0x200, d_021A2190, d_021A2198, 0x5a, d_021A21A0);
    msg[len] = command;
    p = msg + 1;
    p[len] = 0;
    p += len;
    if (data != 0) {
        len = func_0209477C((const u8 *)data);
        MI_CpuCopy8(data, p, len);
        p[len] = 0;
    }
    return func_021864CC(conn, pid, msg);
}




















/* SDK inlines (calls in the Debug build of dwc_match.o, inlined in Rom):
 * the tick is read before DWCi_GetMatchCnt, as `MC()->x = DWCi_Np_GetTick()`
 * inlines; DWCi_LEtoHl is the identity on the DS */
static inline u32 DWCi_LEtoHl(u32 x) { return x; }




















static inline u64 DWCi_Np_GetTick(void) { return OS_GetTick(); }




















/*
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
 */
int func_021702A0(u8 command, int srcPid, u32 srcIP, u16 srcPort, u32 *data, int len)
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

    if (MC() == NULL || MC()->state == 0)
        return 1;

    if (DWC_GetState() == 4 && MC()->state == 1 &&
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
            if (MC()->inMeshMaking) {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID(MC()->tempNewNodeInfo.profileID);
                MC()->tempNewNodeInfo.aid = pNodeInfo->aid;
            }
            if (MC()->inMeshMaking == 0 && MC()->qr2MatchType == 2 && MC()->state != 0xe &&
                ((MC()->qr2MatchTypeExt != 0 && MC()->qr2MatchTypeExt != 1) || MC()->f_00D) &&
                MC()->newClientCallback != NULL)
                MC()->newClientCallback(DWCi_GetFriendListIndex(srcPid), MC()->newClientParam);
            pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
            sendlen = 0;
            senddata[sendlen++] = MC()->qr2NumEntry;
            senddata[sendlen++] = pMyNodeInfo->aid;
            senddata[sendlen++] = pMyNodeInfo->profileID;
            senddata[sendlen++] = pMyNodeInfo->publicInetAddress;
            senddata[sendlen++] = pMyNodeInfo->publicQueryPort;
            senddata[sendlen++] = pMyNodeInfo->privateInetAddress;
            senddata[sendlen++] = pMyNodeInfo->privateQueryPort;
            senddata[sendlen++] = pMyNodeInfo->hasPrivateAddress;
            senddata[sendlen++] = *(u32 *)pMyNodeInfo->connUserData;
            senddata[sendlen++] = MC()->groupID;
            senddata[sendlen++] = MC()->tempNewNodeInfo.aid;
            senddata[sendlen++] = profileID;
            senddata[sendlen++] = DWCi_NodeInfoList_GetCount();
            senddata[sendlen++] = MC()->inMeshMaking ? 1 : 0;
            MC();
            DWCi_SetMatchStatus(0xe);
        } else if (sendCommand == 3) {
            DWCi_GetResvDenyReasonString(MC()->denyReason);
            senddata[0] = MC()->denyReason;
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
        if (MC()->state != 3)
            break;
        if (srcPid != MC()->reqProfileID || srcPid != (int)data[2])
            break;
        ip = (int)data[11];
        result = MC()->f_634;
        if (result != ip)
            break;
        if (len >= 14) {
            ip = data[13] == 1 ? 1 : 0;
            if (ip != MC()->inMeshMaking)
                break;
        }
        MC()->f_628 = 0;
        MC()->cmdTimeoutTime = 0;
        MC()->cmdResendFlag = 0;
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
        if (MC()->inMeshMaking == 0)
            DWCi_NodeInfoList_GetMyNodeInfo()->aid = (u8)data[data_idx++];
        MC()->tempNewNodeInfo = peerNodeInfo;
        if (MC()->qr2MatchType == 3) {
            MC()->groupID = ip;
            MC()->qr2NumEntry = (u8)profileID;
        }
        if (MC()->qr2MatchTypeExt == 1 && MC()->evalCallback && MC()->inMeshMaking == 0 && MC()->connectGroupID == 0) {
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

        if (MC()->state != 3)
            break;
        if (srcPid != MC()->reqProfileID)
            break;
        reason = data[0];
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->connectGroupID || MC()->qr2MatchTypeExt == 3) {
            int error;

            error = reason != 0x10 ? 0x15 : 0xc;
            DWCi_StopMatch(error, 0);
            return 0;
        }
        return DWCi_RetryReserving(MC()->reqProfileID);
    }
    case 4:
        if (MC()->state != 3)
            break;
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->connectGroupID) {
            if (srcPid != MC()->reqProfileID)
                break;
            if (!gpIsBuddy(MC()->pGpObj, srcPid))
                break;
            MC()->retryCountMax = 1;
            MC()->scResvRetryCount = 0;
            MC()->cmdTimeoutTime = 12000;
            MC()->cmdTimeoutStartTick = DWCi_Np_GetTick();
        } else {
            if (srcPid != MC()->reqProfileID)
                break;
            MC()->cmdTimeoutStartTick = DWCi_Np_GetTick();
            MC()->f_628 = 0;
            if (MC()->qr2MatchTypeExt == 0) {
                DWCi_TempNewNodeInfo_Clear();
                DWCi_SetMatchStatus(2);
                MC()->sbUpdateFlag = 1;
                MC()->sbUpdateTick = DWCi_Np_GetTick();
            } else if (MC()->qr2MatchTypeExt == 1) {
                DWCi_TempNewNodeInfo_Clear();
                DWCi_SendResvCommandToFriend(1, 0, 0);
            } else if (MC()->qr2MatchTypeExt == 3) {
                MC()->retryCountMax = 1;
                MC()->scResvRetryCount = 0;
                MC()->cmdTimeoutTime = 12000;
                MC()->cmdTimeoutStartTick = DWCi_Np_GetTick();
            }
        }
        break;
    case 5:
        if (MC()->qr2Flag18 == 0)
            break;
        if (srcPid != MC()->serverProfileID)
            break;
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            break;
        }
        if (MC()->qr2MatchType == 2 && DWCi_TempNewNodeInfo_IsValid() == 1 &&
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
        if (!DWCi_IsFullMesh() && MC()->qr2MatchType == 3 && MC()->inMeshMaking == 0)
            break;
        if (MC()->state == 1) {
            DWCi_SetMatchStatus(5);
        } else {
            if (MC()->state != 5 && MC()->state != 0xe)
                break;
            if (srcPid != MC()->serverProfileID)
                break;
        }
        MC()->cmdCnt.command = 0xff;
        remoteaddr.addr.addr = ip;
        remoteaddr.port = SOC_HtoNs(port);
        MC()->nnInfo.clientindex = 1;
        DWCi_NNCompletedCallback(0, gt2GetSocketSOCKET(*MC()->pGt2Socket), &remoteaddr, &MC()->nnInfo.clientindex);
        MC()->nnFinishTime = 0;
        break;
    case 7:
        if (DWCi_StopMeshMaking() == 1)
            DWCi_SetMatchStatus(1);
        if (MC()->state != 1)
            break;
        if (srcPid != DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID)
            break;
        profileID = (int)data[0];
        aid = (u8)data[1];
        if (MC()->tempNewClientInfo.profileID)
            break;
        MC()->serverDownBuff = 0;
        if (DWCi_IsFullMesh()) {
            MC()->tempNewNodeInfo.profileID = profileID;
            MC()->tempNewNodeInfo.aid = aid;
        } else {
            MC()->tempNewClientInfo.profileID = profileID;
        }
        if (MC()->newClientCallback != NULL)
            MC()->newClientCallback(DWCi_GetFriendListIndex(profileID), MC()->newClientParam);
        break;
    case 9: {
        DWCstNodeInfo *nodeInfo;

        nodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(DWCi_GetGT2NumConnection() - 1 - MC()->linkProgress);
        if (MC()->state != 0x10)
            break;
        if (nodeInfo == NULL || nodeInfo->profileID != (int)data[0])
            break;
        MC()->linkProgress++;
        DWCi_PostProcessConnection(0);
        break;
    }
    case 8: {
        DWCstNodeInfo *tmpNode;
        u32 senddata1[1];

        if (MC()->state != 1)
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
            MC()->tempNewClientInfo = MC()->tempNewNodeInfo;
            tmpNode->profileID = profileID;
            tmpNode->aid = aid;
            tmpNode->publicInetAddress = data[3];
            tmpNode->publicQueryPort = (u16)data[4];
            tmpNode->privateInetAddress = data[5];
            tmpNode->privateQueryPort = (u16)data[6];
            tmpNode->hasPrivateAddress = (u8)data[7];
            memcpy(tmpNode->connUserData, &data[8], 4);
            DWCi_SetMatchStatus(5);
            MC()->cmdTimeoutTime = 0;
            MC()->cmdResendFlag = 0;
            DWCi_NNStartupAsync(0, 0, tmpNode);
        }
        break;
    }
    case 10:
        if (MC()->state != 1)
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
        if (MC()->qr2MatchTypeExt == 0 || MC()->qr2MatchTypeExt == 1) {
            if (!DWCi_CancelPreConnectedClientProcess(srcPid))
                return 0;
        } else if (MC()->qr2MatchType == 3) {
            MC()->peerProfileID = srcPid;
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
        beforeCloseState = MC()->closeState;
        MC()->closeState = 1;
        for (i = 0; i < len; i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForProfileID((int)data[i]);
            if (pNodeInfo == NULL) {
                profileID = (int)data[i];
                result = MC()->tempNewClientInfo.profileID;
                if (result == profileID) {
                    DWCi_CloseConnectionHard(MC()->tempNewClientInfo.aid);
                    MC()->tempNewClientInfo.profileID = 0;
                    continue;
                }
            }
            if (pNodeInfo != NULL)
                DWCi_CloseConnectionHard(pNodeInfo->aid);
        }
        MC()->closeState = beforeCloseState;
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
        idx = DWCi_GetAIDFromProfileID(MC()->profileID, 1);
        if (idx == 0xff)
            return 0;
        if (DWCi_GetAIDFromProfileID(srcPid, 1) == 0xff)
            return 0;
        serverAidBitmap = DWCi_LEtoHl(data[0]);
        if (srcPid != DWCi_NodeInfoList_GetNodeInfoForIndex(0)->profileID) {
            bAck = 0;
        } else {
            bAck = (MC()->serverDownBuff & (1 << idx)) != 0;
        }
        result = DWCi_SendMatchCommand(bAck ? 0x53 : 0x54, srcPid, srcIP, srcPort, NULL, 0);
        if (DWCi_HandleMatchCommandError(result))
            return 0;
        MC()->clWaitTime = DWCi_Np_GetTick();
        if (bAck && MC()->state == 0xa) {
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
        MC()->serverDownBuff |= 1 << idx;
        if (DWCi_HandleMatchCommandError(DWCi_SendMatchCommand(0x53, srcPid, srcIP, srcPort, NULL, 0)))
            return 0;
        break;
    }
    case 0x54:
        if (!MC()->f_00D)
            break;
        i = DWCi_NodeInfoList_GetCount();
        if (++MC()->serverDownNakCount > i * 5)
            DWC_CloseAllConnectionsHard();
        else
            MC()->clWaitTime = DWCi_Np_GetTick();
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
                MC()->suspendBitmap = ip;
            }
        }
        break;
    }
    case 0x83:
        func_0216F058((const Poll *)data);
        break;
    }
    return 1;
}



















/*
 * sdk:      DWCi_CheckResvCommand (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
u8 func_021713CC(int profileID, u32 qr2IP, u16 qr2Port, u32 matchType, int connectGroupID, u32 topologyType, u8 *newClientUserData, int meshReserve)
{
    DWCstNodeInfo *pMyNodeInfo;
    u8 sendCommand;
    u64 tick;

    ((DWCstMatchControl *)func_02175F3C())->denyReason = 1;
    switch (INTRUDE_COMM_IsJoinRequestValid()) {
    case 1:
        if (DWCi_NodeInfoList_HasNoGT2ConnectionToProfileID(profileID)) {
            if (((DWCstMatchControl *)func_02175F3C())->inMeshMaking == 0) {
                if (((DWCstMatchControl *)func_02175F3C())->state == 1) {
                    if (((DWCstMatchControl *)func_02175F3C())->tempNewClientInfo.profileID != 0) {
                        sendCommand = 4;
                    } else {
                        ((DWCstMatchControl *)func_02175F3C())->inMeshMaking = 1;
                        DWCi_ClearMeshMakingTempInfo();
                        goto send;
                    }
                } else {
                    sendCommand = 4;
                }
            } else {
                if (((DWCstMatchControl *)func_02175F3C())->state == 3) {
                    pMyNodeInfo = (DWCstNodeInfo *)func_02176344();
                    if (profileID == ((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.profileID) {
                        if (pMyNodeInfo->profileID >= profileID) {
                            sendCommand = 0xff;
                        } else {
                        send:
                            sendCommand = 2;
                            tick = func_020870D0();
                            ((DWCstMatchControl *)func_02175F3C())->cmdCnt.sendTime = tick;
                        }
                    } else {
                        sendCommand = 4;
                    }
                } else {
                    sendCommand = 4;
                }
            }
        } else {
            sendCommand = 3;
            ((DWCstMatchControl *)func_02175F3C())->denyReason = 0x14;
        }
        break;
    case 0:
    case 2:
        sendCommand = func_02171524(profileID, qr2IP, qr2Port, matchType, connectGroupID, topologyType, newClientUserData, meshReserve);
        break;
    }
    return sendCommand;
}



















unsigned char DWCi_CheckResvCommand_Sub(int profileID, u32 qr2IP, u16 qr2Port,
                                        u32 matchType, int connectGroupID,
                                        u32 topologyType,
                                        unsigned char *newClientUserData,
                                        int meshReserve)
{
    unsigned char sendCommand;

    if (DWCi_IsServerLocked() != 0) {
        DWCi_GetMatchCnt()->denyReason = 0x13;
        return 3;
    }
    if (meshReserve != 0) {
        DWCi_GetMatchCnt()->denyReason = 0x18;
        return 3;
    }
    if (connectGroupID != 0)
        goto main;

    if ((matchType == 0 && DWCi_GetMatchCnt()->qr2MatchTypeExt != 0) ||
        (matchType == 1 && DWCi_GetMatchCnt()->qr2MatchTypeExt != 1) ||
        (matchType == 3 && DWCi_GetMatchCnt()->qr2MatchTypeExt != 2)) {
        DWCi_GetMatchCnt()->denyReason = 0x12;
        return 3;
    }

    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        if (gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID) != 0) {
            if (DWCi_GetFriendListIndex(profileID) != -1)
                goto isfriend;
        }
        return 0xff;
    isfriend:
        if (DWCi_IsFriendByIdxList(profileID) != 0)
            goto main;
        DWCi_GetMatchCnt()->denyReason = 0x15;
        return 3;
    }
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2) {
        if (gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID) != 0) {
            if (DWCi_GetFriendListIndex(profileID) != -1)
                goto main;
        }
        return 0xff;
    }

main:
    if (DWCi_GetMatchCnt()->qr2NumEntry + 1 == DWCi_GetNumEntry()) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->denyReason = 0x10;
        goto done;
    }
    if (DWCi_GetMatchCnt()->state == 0x16) {
        sendCommand = 4;
        goto done;
    }
    if (DWC_GetSuspendMatch() != 0 || DWCi_GetMatchCnt()->f_048 != 0) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->denyReason = 0x11;
        goto done;
    }
    if (topologyType != DWCi_GetMatchCnt()->topologyType) {
        sendCommand = 3;
        DWCi_GetMatchCnt()->denyReason = 0x12;
        goto done;
    }
    if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID) != 0) {
        sendCommand = 0xff;
        goto done;
    }
    if (DWCi_GetMatchCnt()->state == 0xd ||
        DWCi_GetMatchCnt()->state == 2 ||
        DWCi_GetMatchCnt()->state == 3) {
        if ((DWCi_GetMatchCnt()->qr2IP != 0 || DWCi_GetMatchCnt()->qr2Port != 0) &&
            (qr2IP != 0 || qr2Port != 0))
            goto lookup;
    }
    if (DWCi_GetMatchCnt()->state == 0xe &&
        profileID == DWCi_GetMatchCnt()->serverProfileID) {
        sendCommand = 0xff;
        goto done;
    }
    sendCommand = 4;
    goto done;

lookup:
    if (DWCi_GetMatchCnt()->qr2MatchType != 2 &&
        DWCi_GetMatchCnt()->reqProfileID != 0) {
        if (profileID == DWCi_GetMatchCnt()->reqProfileID) {
            if (DWCi_GetMatchCnt()->profileID < profileID)
                sendCommand = 2;
            else
                sendCommand = 0xff;
        } else {
            sendCommand = 3;
            DWCi_GetMatchCnt()->denyReason = 0x17;
        }
        goto done;
    }
    sendCommand = 2;
    goto done;

done:
    if (sendCommand == 2) {
        if (DWCi_GetMatchCnt()->f_7B8 != 0) {
            if (DWCi_GetMatchCnt()->f_7B8(newClientUserData, DWCi_GetMatchCnt()->f_7C0) == 0) {
                DWCi_GetMatchCnt()->denyReason = 0x16;
                return 3;
            }
        }
        if (DWCi_GetHostStatus() == 0)
            DWCi_SetupGameServer_InterChange(1);
    }
    return sendCommand;

err12:
    DWCi_GetMatchCnt()->denyReason = 0x12;
    return 3;
}



















/*
 * sdk:      DWCi_ProcessResvOK (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02171884(int profileID)
{
    u32 senddata[16];
    int result;
    int i;
    u8 aid;
    DWCstNodeInfo *pMyNodeInfo;
    DWCstNodeInfo *pNodeInfo;

    if (((DWCstMatchControl *)func_02175F3C())->qr2Flag18 != 0 && profileID == ((DWCstMatchControl *)func_02175F3C())->serverProfileID)
        return 0;
    ((DWCstMatchControl *)func_02175F3C())->qr2Flag18 = 1;
    ((DWCstMatchControl *)func_02175F3C())->serverProfileID = profileID;
    ((DWCstMatchControl *)func_02175F3C())->cmdResendFlag = 0;
    ((DWCstMatchControl *)func_02175F3C())->cmdTimeoutTime = 0;
    qr2_send_statechanged(((DWCstMatchControl *)func_02175F3C())->qr2Obj);
    ((DWCstMatchControl *)func_02175F3C())->reqProfileID = 0;
    aid = func_02176474();
    ((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.aid = aid;
    if (((DWCstMatchControl *)func_02175F3C())->inMeshMaking == 0) {
        senddata[0] = ((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.profileID;
        senddata[1] = ((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.aid;
        pMyNodeInfo = (DWCstNodeInfo *)func_02176344();
        for (i = 0; i < func_0217603C(); i++) {
            pNodeInfo = (DWCstNodeInfo *)func_0217637C(i);
            if (pMyNodeInfo->profileID != pNodeInfo->profileID) {
                result = func_0216FF2C(7, pNodeInfo->profileID, pNodeInfo->publicInetAddress, pNodeInfo->publicQueryPort, (const unsigned int *)senddata, 2);
                if (result != 0)
                    return result;
            }
        }
    }
    return 0;
}



















/*
 * DWCi_HandleMatchCommandError: dispatches to the server-browsing or command error handler.
 */
int func_021719A4(int error)
{
    if (*(unsigned char *)((char *)func_02175F3C() + 0x15) == 0) {
        return func_02173D9C(error);
    }
    return func_02173D28(error);
}


















int DWCi_SendResvCommand(int profileID, int delay)
{
    u32 senddata[16];
    u32 remoteQR2ip = 0;
    u16 remoteQR2port = 0;
    DWCstNodeInfo * pMyNodeInfo;
    unsigned long long tick;
    int result;

    if (delay != 0)
        goto setTimer;
    if (DWCi_GetMatchCnt()->qr2IP != 0 || DWCi_GetMatchCnt()->qr2Port != 0)
        goto send;

setTimer:
    DWCi_GetMatchCnt()->cmdResendFlag = 1;
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->cmdResendTick = tick;
    DWCi_GetMatchCnt()->reqProfileID = 0;
    return 0;

send:
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0) {
        remoteQR2ip = DWCi_GetMatchCnt()->tempNewNodeInfo.publicInetAddress;
        remoteQR2port = DWCi_GetMatchCnt()->tempNewNodeInfo.publicQueryPort;
        DWCi_GetMatchCnt()->reqProfileID = profileID;
    } else {
        DWCi_GetMatchCnt()->reqProfileID = profileID;
        if (gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID) == 0) {
            remoteQR2ip = DWCi_GetMatchCnt()->tempNewNodeInfo.publicInetAddress;
            remoteQR2port = DWCi_GetMatchCnt()->tempNewNodeInfo.publicQueryPort;
        }
    }
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3 ||
        (DWCi_GetMatchCnt()->connectGroupID != 0 &&
         gpIsBuddy(DWCi_GetMatchCnt()->pGpObj, profileID))) {
        DWCi_GetMatchCnt()->retryCountMax = 0;
        DWCi_GetMatchCnt()->cmdTimeoutTime = 0x7530;
    } else {
        DWCi_GetMatchCnt()->retryCountMax = 5;
        DWCi_GetMatchCnt()->cmdTimeoutTime = 0x2ee0;
    }
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->cmdTimeoutStartTick = tick;
    DWCi_GetMatchCnt()->cmdResendFlag = 0;
    pMyNodeInfo = DWCi_NodeInfoList_GetMyNodeInfo();
    senddata[0] = DWCi_GetMatchCnt()->qr2MatchTypeExt;
    senddata[1] = pMyNodeInfo->publicInetAddress;
    senddata[2] = pMyNodeInfo->publicQueryPort;
    senddata[3] = pMyNodeInfo->privateInetAddress;
    senddata[4] = pMyNodeInfo->privateQueryPort;
    senddata[5] = pMyNodeInfo->hasPrivateAddress;
    senddata[6] = DWCi_GetMatchCnt()->connectGroupID;
    senddata[7] = DWCi_GetMatchCnt()->topologyType;
    senddata[8] = *(u32 *)DWCi_GetMatchCnt()->connUserData;
    DWCi_GetMatchCnt()->f_634 = DWCi_GetMathRand32((u32)-2) + 1;
    senddata[9] = DWCi_GetMatchCnt()->f_634;
    senddata[10] = DWCi_GetMatchCnt()->inMeshMaking != 0;
    result = DWCi_SendMatchCommand(1, profileID, remoteQR2ip, remoteQR2port, senddata, 0xb);
    return result;
}

















int DWCi_SendResvCommandToFriend(int delay, int init, int resendPid)
{
    int found = 0;
    int profileID;
    int i;
    int gpResult;
    struct GPBuddyStatus status;
    int buddyIdx;
    unsigned long long tick;

    if (init == 0) {
        DWCi_GetMatchCnt()->f_621++;
        DWCi_GetMatchCnt()->f_621 =
            DWCi_GetMatchCnt()->f_621 % DWCi_GetMatchCnt()->flag6d4;
    }
    DWCi_GetMatchCnt()->qr2MatchType = 3;
    i = 0;
    if (DWCi_GetMatchCnt()->flag6d4 > 0) {
        do {
            profileID = DWC_GetGsProfileId(
                DWCi_GetUserData(),
                DWCi_GetMatchCnt()->param68c +
                    DWCi_GetMatchCnt()->buf694[DWCi_GetMatchCnt()->f_621] * 12);
            if (profileID == 0 || profileID == -1)
                goto next;
            if (DWCi_Acc_IsValidFriendData(
                    DWCi_GetMatchCnt()->param68c +
                    DWCi_GetMatchCnt()->buf694[DWCi_GetMatchCnt()->f_621] * 12) == 0)
                goto next;
            if (DWCi_NodeInfoList_GetNodeInfoForProfileID(profileID) != 0)
                goto next;
            gpResult = gpGetBuddyIndex(DWCi_GetMatchCnt()->pGpObj, profileID, &buddyIdx);
            gpResult |= gpGetBuddyStatus(DWCi_GetMatchCnt()->pGpObj, buddyIdx, &status);
            if (!(DWCi_IsLockedBuddyStatus(&status) == 0 &&
                  gpResult == 0 && status.f4 == 4))
                goto next;
            found = 1;
            break;
        next:
            i++;
            DWCi_GetMatchCnt()->f_621 =
                (i + DWCi_GetMatchCnt()->f_621) % DWCi_GetMatchCnt()->flag6d4;
        } while (i < DWCi_GetMatchCnt()->flag6d4);
    }
    if (found) {
        if (profileID == resendPid)
            delay = 1;
        DWCi_TempNewNodeInfo_Clear();
        DWCi_GetMatchCnt()->tempNewNodeInfo.aid = 0xff;
        DWCi_GetMatchCnt()->tempNewNodeInfo.profileID = profileID;
        return DWCi_SendResvCommand(profileID, delay);
    }
    DWCi_GetMatchCnt()->cmdTimeoutTime = 0xbb8;
    tick = OS_GetTick();
    DWCi_GetMatchCnt()->cmdTimeoutStartTick = tick;
    DWCi_GetMatchCnt()->cmdResendFlag = 0;
    return 0;
}

















/*
 * sdk:      DWCi_RetryReserving (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02171E34(int resendPid)
{
    int result;
    int sbError;
    u64 tick;

    ((DWCstMatchControl *)func_02175F3C())->reqProfileID = 0;
    ((DWCstMatchControl *)func_02175F3C())->f_628 = 0;
    tick = func_020870D0();
    ((DWCstMatchControl *)func_02175F3C())->cmdTimeoutStartTick = tick;
    func_0217653C();
    if (((DWCstMatchControl *)func_02175F3C())->connectGroupID != 0) {
        func_02175F4C(0xc);
        sbError = func_02173D9C(func_0216F770(0));
        if (sbError != 0)
            return 0;
    } else if (((DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 0) {
        func_02175F4C(2);
        if (resendPid != 0) {
            ((DWCstMatchControl *)func_02175F3C())->sbUpdateFlag = 1;
            tick = func_020870D0();
            ((DWCstMatchControl *)func_02175F3C())->sbUpdateTick = tick;
        } else {
            sbError = func_02173D9C(func_0216F770(0));
            if (sbError != 0)
                return 0;
        }
    } else if (((DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 1) {
        result = func_021719A4(func_02171C08(1, 0, resendPid));
        if (result != 0)
            return 0;
    } else if (((DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
        func_0216EB68(6, -80410);
        return 0;
    }
    return 1;
}

















/*
 * Sends command 5 to the new node recorded in the temporary node info.
 */
int func_02171F68(int arg)
{
    int result;

    if (func_02176554() == 0) {
        return 0;
    }
    result = func_0216FF2C(5, *(int *)((char *)func_02175F3C() + 0x554), *(unsigned int *)((char *)func_02175F3C() + 0x558),
                           *(unsigned short *)((char *)func_02175F3C() + 0x560), 0, 0);
    *(int *)((char *)func_02175F3C() + 0x67c) = 0;
    return result;
}
















/*
 * sdk:      DWCi_CancelPreConnectedServerProcessWithResetLevel (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02171FD4(int clientPid, int resetLevel)
{
    DWCstNodeInfo *pNodeInfo;
    int i;

    if (func_02176554())
        func_0217653C();
    ((DWCstMatchControl *)func_02175F3C())->cmdCnt.command = 0xff;
    if (((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie != 0) {
        NNCancel(((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie);
        ((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie = 0;
    }
    ((DWCstMatchControl *)func_02175F3C())->reqProfileID = 0;
    if (INTRUDE_COMM_IsJoinRequestValid() == 2) {
        ((DWCstMatchControl *)func_02175F3C())->qr2Flag18 = 0;
        ((DWCstMatchControl *)func_02175F3C())->serverProfileID = 0;
        func_02175F4C(0x11);
        ((DWCstMatchControl *)func_02175F3C())->f_654 = 0;
        ((DWCstMatchControl *)func_02175F3C())->f_632 = 0;
        func_02172E18(clientPid);
        for (i = 1; i < func_0217603C(); i++) {
            pNodeInfo = (DWCstNodeInfo *)func_0217637C(i);
            if (!func_02173614(pNodeInfo->profileID, 0xd))
                return 0;
        }
        if (func_0217603C() == 1)
            func_02172BB8(resetLevel);
    } else {
        func_02176674();
    }
    return 1;
}
















int DWCi_CancelPreConnectedServerProcess(int clientPid)
{
    int resetLevel = 2;

    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 ||
        DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
        if (DWCi_GetMatchCnt()->f_00D == 0)
            resetLevel = 1;
    }
    return DWCi_CancelPreConnectedServerProcessWithResetLevel(clientPid, resetLevel);
}
















/*
 * sdk:      DWCi_CancelPreConnectedClientProcess (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02172124(void)
{
    int result = 1;

    if (((DWCstMatchControl *)func_02175F3C())->connectGroupID != 0)
        goto stop;
    if (((DWCstMatchControl *)func_02175F3C())->qr2MatchTypeExt == 3) {
    stop:
        if (func_0217603C() > 1)
            func_02172E7C();
        if (((DWCstMatchControl *)func_02175F3C())->connectGroupID != 0)
            func_0216EB68(0x16, -80432);
        else
            func_0216EB68(0x16, -80430);
        return 0;
    }
    if (func_02176674() == 1)
        return result;
    if (((DWCstMatchControl *)func_02175F3C())->tempNewClientInfo.profileID != 0)
        ((DWCstMatchControl *)func_02175F3C())->tempNewClientInfo.profileID = 0;
    if (((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie != 0) {
        NNCancel(((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie);
        ((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie = 0;
    }
    if (func_0217695C()) {
        if (((DWCstMatchControl *)func_02175F3C())->needServerPoll != 0)
            goto restart;
    }
    if (func_02176554()) {
        if (DWCi_GetGT2ConnectionByProfileID_Alt(((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.profileID, 1) != 0)
            goto restart;
    }
    if (func_0217603C() > 1) {
    restart:
        DWCi_RestartFromTimeout();
    } else {
        func_02175F4C(3);
        result = func_02171E34(0);
    }
    return result;
}















void DWCi_PostProcessConnection(int type)
{
    u32 senddata[1];
    int result;
    DWCstMatchControl *p;

    switch (type)
    {
    case 0:
        if (DWCi_IsFullMesh())
            DWCi_PostProcessSVConnectionFullmesh();
        else
            DWCi_PostProcessSVConnectionHybrid();
        break;
    case 1:
        DWCi_SetMatchStatus(1);
        if (DWCi_GetMatchCnt()->qr2MatchType == 3)
            DWCi_GetMatchCnt()->peerProfileID = DWCi_GetMatchCnt()->tempNewNodeInfo.profileID;
        break;
    case 2:
        DWCi_SetMatchStatus(1);
        if (DWCi_StopMeshMaking() == 1)
        {
            DWCi_ClearMeshMakingTempInfo();
            break;
        }
        DWCi_SetHostStatus(1);
        DWCi_GetMatchCnt()->qr2MatchType = 3;
        if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0 || DWCi_GetMatchCnt()->qr2MatchTypeExt == 1)
        {
            DWCi_GetMatchCnt()->qr2Flag18 = 1;
            DWCi_GetMatchCnt()->serverProfileID = DWCi_GetMatchCnt()->profileID;
        }
        DWCi_InitClWaitTimeout();
        if (DWCi_IsFullMesh())
        {
            if (DWCi_NodeInfo_IsValid(&DWCi_GetMatchCnt()->tempNewClientInfo))
            {
                DWCstNodeInfo *pNodeInfo;
                DWCstMatchControl *p;

                pNodeInfo = &DWCi_GetMatchCnt()->tempNewNodeInfo;
                senddata[0] = pNodeInfo->profileID;
                DWCi_NodeInfoList_InsertToTop(pNodeInfo);
                DWCi_GetMatchCnt()->tempNewNodeInfo =
                    DWCi_GetMatchCnt()->tempNewClientInfo;
                p = DWCi_GetMatchCnt();
                pNodeInfo = &p->tempNewNodeInfo;
                result = DWCi_SendMatchCommand(9,
                    p->tempNewNodeInfo.profileID,
                    pNodeInfo->publicInetAddress,
                    pNodeInfo->publicQueryPort,
                    senddata, 1);
                DWCi_NodeInfo_Clear(&DWCi_GetMatchCnt()->tempNewClientInfo);
                if (DWCi_HandleMatchCommandError(result))
                    return;
            }
            DWCi_GetMatchCnt()->needServerPoll = 1;
        }
        break;
    case 3:
        DWCi_GetMatchCnt()->f_00D = 1;
        DWCi_PostProcessConnectionSYNFinish();
        DWCi_GetMatchCnt()->connectGroupID = 0;
        qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
        {
            int flag = (DWCi_GetMatchCnt()->peerProfileID == 0);
            DWCstMatchControl *p = DWCi_GetMatchCnt();
            result = DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID);
            p->matchedCallback(0, 0, flag, 0, result, DWCi_GetMatchCnt()->matchedParam);
        }
        if (DWCi_GetMatchCnt()->qr2MatchType == 2)
        {
            if (DWCi_HandleGPError(DWCi_GPSetServerStatus(-1)))
                return;
            DWCi_SetMatchStatus(0xd);
        }
        else
        {
            DWCi_GPSetServerStatus(2);
            DWCi_SetMatchStatus(1);
        }
        DWCi_GetMatchCnt()->peerProfileID = 0;
        DWCi_GetMatchCnt()->cancelState = 0;
        DWCi_ResetLastSomeDataRecvTimeByAidAll();
        break;
    }

    if (DWCi_GetMatchCnt()->sbObj != 0)
    {
        ServerBrowserClear(DWCi_GetMatchCnt()->sbObj);
        p = DWCi_GetMatchCnt();
        *(unsigned long long *)&p->sbUpdateRequestTick = 0;
    }
}














void DWCi_PostProcessConnectionSYNFinish(void)
{
    DWCi_GetMatchCnt()->nnFailureCount = 0;
    if (DWCi_IsFullMesh())
        DWCi_PostProcessConnectionSYNFinishFullmesh();
    else
        DWCi_PostProcessConnectionSYNFinishHybrid();
}













void DWCi_PostProcessConnectionSYNFinishHybrid(void)
{
    DWCstMatchControl *p;

    if (DWCi_GetMatchCnt()->qr2MatchType == 2) {
        if (DWCi_TempNewNodeInfo_IsValid() == 0)
            return;
        DWCi_NodeInfoList_Append(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    if (DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_NodeInfoList_InsertToTop(&DWCi_GetMatchCnt()->tempNewNodeInfo);
        DWCi_TempNewNodeInfo_Clear();
        return;
    }
    p = DWCi_GetMatchCnt();
    {
        DWCstNodeInfo *newNode = &p->tempNewClientInfo;
        DWCstNodeInfo *n;

        if (newNode->profileID == 0)
            return;
        n = DWCi_NodeInfoList_GetNodeInfoForProfileID(newNode->profileID);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        n = DWCi_NodeInfoList_GetNodeInfoForAID(newNode->aid);
        if (n != 0)
            DWCi_CloseConnectionHard(n->aid);
        DWCi_NodeInfoList_Append(newNode);
        newNode->profileID = 0;
    }
}













/*
 * Clears the byte at +0x62f of the module block.
 */
void func_021725EC(void)
{
    func_0217253C();

    *(unsigned char *)((char *)func_02175F3C() + 0x62f) = 0;
}













/*
 * sdk:      DWCi_PostProcessSVConnectionHybrid (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02172604(void)
{
    int sbClear = 0;
    int i;
    u64 tick;

    if (((DWCstMatchControl *)func_02175F3C())->inMeshMaking != 0 || ((DWCstMatchControl *)func_02175F3C())->backupState == 0xf) {
        ((DWCstMatchControl *)func_02175F3C())->qr2Flag18 = 0;
        ((DWCstMatchControl *)func_02175F3C())->serverProfileID = 0;
        func_02175F4C(1);
        func_02176674();
        return sbClear;
    }
    ((DWCstMatchControl *)func_02175F3C())->qr2Flag18 = 0;
    ((DWCstMatchControl *)func_02175F3C())->serverProfileID = 0;
    if (((DWCstMatchControl *)func_02175F3C())->f_00D == 0 && func_0217603C() == 1) {
        tick = func_020870D0();
        ((DWCstMatchControl *)func_02175F3C())->serverPollingTime = tick;
    }
    qr2_send_statechanged(((DWCstMatchControl *)func_02175F3C())->qr2Obj);
    if (((DWCstMatchControl *)func_02175F3C())->qr2MatchType == 2)
        ((DWCstMatchControl *)func_02175F3C())->peerProfileID = ((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.profileID;
    func_02175F4C(0x13);
    ((DWCstMatchControl *)func_02175F3C())->synAckBitmap = 0;
    for (i = 1; i < func_0217603C(); i++)
        func_02173064(func_0217637C(i)->aid, 2);
    func_02173064(((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.aid, 2);
    if (((DWCstMatchControl *)func_02175F3C())->qr2MatchType != 2)
        sbClear = 1;
    return sbClear;
}












int func_0217273C(void)
{
    unsigned long senddata[16];
    int result;
    DWCstNodeInfo tmpNewNodeInfo;
    unsigned char linkProgress;
    DWCstNodeInfo *pNodeInfo;
    DWCstNodeInfo *pNew;

    result = 0;
    tmpNewNodeInfo = func_02175F3C()->tempNewNodeInfo;
    pNew = &tmpNewNodeInfo;
    if (func_02175F3C()->linkProgress < DWCi_GetNodeInfoCount() - 1) {
        linkProgress = DWCi_GetNodeInfoCount() - 1 - func_02175F3C()->linkProgress;
        func_02175F4C(0x10);
        pNodeInfo = (DWCstNodeInfo *)func_0217637C(linkProgress);
        senddata[0] = pNodeInfo->profileID;
        senddata[1] = linkProgress;
        senddata[2] = pNodeInfo->aid;
        senddata[3] = pNodeInfo->publicInetAddress;
        senddata[4] = pNodeInfo->publicQueryPort;
        senddata[5] = pNodeInfo->privateInetAddress;
        senddata[6] = pNodeInfo->privateQueryPort;
        senddata[7] = pNodeInfo->hasPrivateAddress;
        senddata[8] = *(unsigned long *)pNodeInfo->connUserData;
    } else {
        func_02175F3C()->linkProgress = result;
        return func_02172604();
    }
    if (func_02175F3C()->state != 0x13) {
        if (func_021719A4(func_0216FF2C(8, pNew->profileID, pNew->publicInetAddress,
                                       pNew->publicQueryPort, (const unsigned int *)senddata, 9)))
            return result;
        pNodeInfo = (DWCstNodeInfo *)func_0217637C(linkProgress);
        senddata[0] = pNew->profileID;
        senddata[1] = pNew->aid;
        if (func_021719A4(func_0216FF2C(10, pNodeInfo->profileID, pNodeInfo->publicInetAddress,
                                       pNodeInfo->publicQueryPort, (const unsigned int *)senddata, 2)))
            return result;
        func_02175F3C()->cmdCnt.count = result;
    }
    return 0;
}











/*
 * sdk:      DWCi_DoCancelMatch (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The DWARF declares DWCi_CancelReservation(void); every call site here loads
 * r0 = 0 first, so the file passes the argument.
 */
static void func_021728B8(void)
{
    int anyGT2ConnectionExist;
    int result;

    ((DWCstMatchControl *)func_02175F3C())->peerProfileID = 0;
    anyGT2ConnectionExist = 0;
    if (((DWCstMatchControl *)func_02175F3C())->state == 22) {
        func_02172A58();
        return;
    }
    if (DWCi_GT2GetConnectionListIdx())
        anyGT2ConnectionExist = 1;
    ((DWCstMatchControl *)func_02175F3C())->cancelState = 1;

    if (((DWCstMatchControl *)func_02175F3C())->qr2MatchType == 3) {
        if (((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie) {
            func_02199FB4(((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie);
            ((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie = 0;
        }
        ((DWCstMatchControl *)func_02175F3C())->cancelState = 1;
        if (anyGT2ConnectionExist) {
            func_02195DE4((int *)(*((DWCstMatchControl *)func_02175F3C())->pGt2Socket));
        } else {
            result = func_021719A4(func_02171F68(0));
            if (result)
                return;
        }
        func_02172A58();
        return;
    }

    if (((DWCstMatchControl *)func_02175F3C())->state == 3 || ((DWCstMatchControl *)func_02175F3C())->state == 4 ||
        ((DWCstMatchControl *)func_02175F3C())->state == 5 || ((DWCstMatchControl *)func_02175F3C())->state == 6 ||
        ((DWCstMatchControl *)func_02175F3C())->state == 14 || ((DWCstMatchControl *)func_02175F3C())->state == 15) {
        if (((DWCstMatchControl *)func_02175F3C())->reqProfileID) {
            result = func_021719A4(func_02171F68(0));
            if (result)
                return;
        }
        result = func_021719A4(func_02172B08());
        if (result)
            return;
    }
    if (((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie) {
        func_02199FB4(((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie);
        ((DWCstMatchControl *)func_02175F3C())->nnInfo.cookie = 0;
    }
    if (anyGT2ConnectionExist) {
        ((DWCstMatchControl *)func_02175F3C())->cancelState = 1;
        func_02195DE4((int *)(*((DWCstMatchControl *)func_02175F3C())->pGt2Socket));
    }
    func_02172A58();
}











/*
 * sdk:      DWCi_FinishCancelMatch (dwc_match.o)
 */
void func_02172A58(void)
{
    int gpResult;
    int a = 1;
    int b;

    gpResult = func_0216F20C(a);
    if (func_02173D28(gpResult))
        return;
    func_0216F6C0();
    if (*(int *)((char *)func_02175F3C() + 0x680) == 0) {
        if (*(unsigned char *)((char *)func_02175F3C() + 0x14) != 2)
            a = 0;
    }
    b = *(int *)((char *)func_02175F3C() + 0x680) == 0;
    {
        char *m = (char *)func_02175F3C();

        (*(int (**)(int, int, int, int, int, int))(m + 0x770))(0, 1, b, a, func_02169038(*(int *)((char *)func_02175F3C() + 0x680)), *(int *)((char *)func_02175F3C() + 0x774));
    }
    *(unsigned char *)((char *)func_02175F3C() + 0x62a) = 0;
}










/*
 * sdk:      DWCi_InvalidateReservation (dwc_match.o)
 */
int func_02172B08(void)
{
    int result;
    unsigned long senddata = 0;

    result = 0;
    if (*(unsigned char *)((char *)func_02175F3C() + 0x18) != 0 && *(int *)((char *)func_02175F3C() + 0x5dc) != 0
        && *(int *)((char *)func_02175F3C() + 0x5dc) != *(int *)((char *)func_02175F3C() + 0x678)) {
        result = func_0216FF2C(12, *(int *)((char *)func_02175F3C() + 0x5dc), *(int *)((char *)func_02175F3C() + 0x558), *(unsigned short *)((char *)func_02175F3C() + 0x560), (const unsigned int *)(&senddata), 1);
        *(unsigned char *)((char *)func_02175F3C() + 0x18) = 0;
        *(int *)((char *)func_02175F3C() + 0x5dc) = 0;
        func_0217653C();
    }
    return result;
}










void DWCi_RestartFromCancel(int level)
{
	int sbError;
	int b;

	if (level == 0) {
		DWCi_FinishCancelMatch();
		return;
	}
	DWCi_ResetMatchParam(level);
	if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2 || DWCi_GetMatchCnt()->qr2MatchTypeExt == 3) {
		b = DWCi_GetMatchCnt()->peerProfileID == 0;
		DWCi_GetMatchCnt()->matchedCallback(0, 1, b, 0,
		        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID),
		        DWCi_GetMatchCnt()->matchedParam);
		return;
	}
	if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 0) {
		if (DWCi_GetMatchCnt()->f_00D != 0) {
			b = DWCi_GetMatchCnt()->peerProfileID == 0;
			DWCi_GetMatchCnt()->matchedCallback(0, 1, b, 0,
			        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID),
			        DWCi_GetMatchCnt()->matchedParam);
		}
		if (level == 1) {
			DWCi_SetHostStatus(0);
			DWCi_SetMatchStatus(0x16);
			sbError = DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->profileID);
			DWCi_HandleSBError(sbError);
		}
		return;
	}
	if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 1) {
		if (DWCi_GetMatchCnt()->f_00D != 0) {
			b = DWCi_GetMatchCnt()->peerProfileID == 0;
			DWCi_GetMatchCnt()->matchedCallback(0, 1, b, 0,
			        DWCi_GetFriendListIndex(DWCi_GetMatchCnt()->peerProfileID),
			        DWCi_GetMatchCnt()->matchedParam);
		}
		if (level == 1) {
			DWCi_SetHostStatus(0);
			DWCi_GetMatchCnt()->connectGroupID = 0;
			DWCi_SetMatchStatus(0x16);
			sbError = DWCi_SBUpdateAsync(DWCi_GetMatchCnt()->profileID);
			DWCi_HandleSBError(sbError);
		}
		return;
	}
}









void DWCi_RestartFromTimeout(void)
{
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 2)
        return;
    if (DWCi_GetMatchCnt()->qr2MatchTypeExt == 3)
        return;
    DWCi_CloseAllConnectionsByTimeout();
    DWCi_RestartFromCancel(1);
}








int DWCi_ResumeMatch(void)
{
    DWCi_GetMatchCnt()->qr2Flag18 = 0;
    DWCi_GetMatchCnt()->serverProfileID = 0;
    DWCi_GetMatchCnt()->closeState = 0;
    DWCi_RestartFromCancel(1);
    return 0;
}








/*
 * sdk:      DWCi_CloseCancelHostAsync (dwc_match.o)
 */
int func_02172E18(int profileID)
{
    int **connection;
    int ret;

    *(int *)((char *)func_02175F3C() + 0x680) = profileID;
    connection = (int **)DWCi_GetGT2ConnectionByProfileID_Alt(profileID, 0);
    if (connection) {
        *(char *)((char *)func_02175F3C() + 0x629) = 1;
        func_02195DC4((int)(*connection));
        *(char *)((char *)func_02175F3C() + 0x629) = 0;
        func_02176254(profileID);
        ret = 1;
    } else {
        func_02176254(profileID);
        ret = 0;
    }
    return ret;
}








/*
 * DWCi_CloseAllConnectionsByTimeout: closes every gt2 connection with the closing flag raised.
 */
void func_02172E7C(void)
{
    ((char *)func_02175F3C())[0x629] = 1;
    gt2CloseAllConnections(**(int **)((char *)func_02175F3C() + 4));
    ((char *)func_02175F3C())[0x629] = 0;
}







/*
 * sdk:      DWCi_CloseShutdownClientSC (libdwcmatch.TWL.HYB.a(dwc_match.o))
 *
 * The DWARF declares DWCi_GetAIDFromProfileID with one parameter; the call site
 * loads r1 = 0, so the file passes it. The list stores index first and increment
 * after (validPid[len] = x; len++;); the post-increment form colors the counts
 * differently and adds a copy in the new-node block.
 */
static int func_02172EAC(u32 bitmap)
{
    u8 aid;
    int senddata[32];
    int senddataLen;
    int validPid[32];
    int validPidLen;
    int result;
    int i;
    int bShutdownNewNode;
    int bRet;
    DWCstNodeInfo *nodeInfo;

    senddataLen = 0;
    validPidLen = 0;
    bShutdownNewNode = 0;
    bRet = 1;

    for (i = 1; i < func_0217603C(); i++) {
        DWCstNodeInfo *nodeInfo = (DWCstNodeInfo *)func_0217637C(i);

        if (nodeInfo) {
            if (bitmap & (1 << nodeInfo->aid)) {
                validPid[validPidLen] = nodeInfo->profileID;
                validPidLen++;
            } else {
                senddata[senddataLen] = nodeInfo->profileID;
                senddataLen++;
            }
        }
    }

    if (func_02176554()) {
        DWCstNodeInfo *nodeInfo = &((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo;

        if (bitmap & (1 << nodeInfo->aid)) {
            validPid[validPidLen] = nodeInfo->profileID;
            validPidLen++;
        } else {
            senddata[senddataLen] = nodeInfo->profileID;
            senddataLen++;
            bShutdownNewNode = 1;
        }
    }

    for (i = 0; i < validPidLen; i++) {
        nodeInfo = (DWCstNodeInfo *)func_021763AC(validPid[i]);
        if (func_02176554() && nodeInfo == 0 &&
            validPid[i] == ((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.profileID)
            nodeInfo = &((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo;
        if (nodeInfo) {
            result = func_0216FF2C(0x10, validPid[i], nodeInfo->publicInetAddress,
                                   nodeInfo->publicQueryPort, (const unsigned int *)senddata, senddataLen);
            if (func_021719A4(result))
                bRet = 0;
        }
    }

    ((DWCstMatchControl *)func_02175F3C())->closeState = 1;
    if (bShutdownNewNode) {
        DWCi_CloseConnectionHard(((DWCstMatchControl *)func_02175F3C())->tempNewNodeInfo.aid);
        func_0217653C();
    }
    for (i = 0; i < senddataLen; i++) {
        aid = func_02173C84(senddata[i], 0);
        if (aid != 0xff)
            DWCi_CloseConnectionHard(aid);
    }
    ((DWCstMatchControl *)func_02175F3C())->closeState = 0;
    return bRet;
}






void DWCi_SendMatchSynPacket(u8 aid, u16 type)
{
    u8 buf[8];
    DWCstNodeInfo * pNodeInfo;
    int clientCount;
    u8 i;
    u32 * pSendBuf;
    int sendCount;
    int sendSize;

    sendSize = 4;
    pSendBuf = (u32 *)buf;

    switch (type) {
    case 2:
        if (DWCi_TempNewNodeInfo_IsValid() != 0 &&
            aid == DWCi_GetMatchCnt()->tempNewNodeInfo.aid) {
            pSendBuf[0] = 1;
            break;
        }
        sendSize = 0x1c;
        pSendBuf = DWC_Alloc(4, sendSize);
        if (pSendBuf == 0)
            return;
        pSendBuf[0] = 0;
        pNodeInfo = &DWCi_GetMatchCnt()->tempNewNodeInfo;
        pSendBuf[1] = ((pNodeInfo->hasPrivateAddress << 16) & 0xffff0000) | pNodeInfo->aid;
        pSendBuf[2] = pNodeInfo->profileID;
        pSendBuf[3] = pNodeInfo->publicInetAddress;
        pSendBuf[4] = pNodeInfo->privateInetAddress;
        pSendBuf[5] = ((pNodeInfo->publicQueryPort << 16) & 0xffff0000) | pNodeInfo->privateQueryPort;
        pSendBuf[6] = *(u32 *)pNodeInfo->connUserData;
        break;
    case 3:
        {
            u8 *senddata = (u8 *)pSendBuf;
            senddata[0] = DWCi_GetMatchCnt()->hostLatency;
            senddata[1] = DWCi_GetMatchCnt()->hostLatency >> 8;
        }
        break;
    case 4:
        if (DWCi_TempNewNodeInfo_IsValid() == 0 ||
            aid != DWCi_GetMatchCnt()->tempNewNodeInfo.aid)
            goto fourElse;
        if (DWCi_IsFullMesh() != 0)
            clientCount = 0;
        else
            clientCount = DWCi_NodeInfoList_GetCount() - 1;
        if (clientCount == 0) {
            {
                u8 *senddata = (u8 *)pSendBuf;
                senddata[0] = 0;
                senddata[1] = 0;
                senddata[2] = 0;
                senddata[3] = 0;
            }
            pSendBuf[1] = DWCi_GetMatchCnt()->flag7c8;
            sendSize = 8;
            break;
        }
        sendSize = clientCount * 0x18 + 8;
        pSendBuf = DWC_Alloc(4, sendSize);
        if (pSendBuf == 0)
            return;
        pSendBuf[0] = clientCount;
        sendCount = 1;
        for (i = 0; i < clientCount; i++) {
            pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i + 1);
            pSendBuf[sendCount++] = ((pNodeInfo->hasPrivateAddress << 16) & 0xffff0000) | pNodeInfo->aid;
            pSendBuf[sendCount++] = pNodeInfo->profileID;
            pSendBuf[sendCount++] = pNodeInfo->publicInetAddress;
            pSendBuf[sendCount++] = pNodeInfo->privateInetAddress;
            pSendBuf[sendCount++] = ((pNodeInfo->publicQueryPort << 16) & 0xffff0000) | pNodeInfo->privateQueryPort;
            pSendBuf[sendCount++] = *(u32 *)pNodeInfo->connUserData;
        }
        pSendBuf[sendCount] = DWCi_GetMatchCnt()->flag7c8;
        break;
    fourElse:
        {
            u8 *senddata = (u8 *)pSendBuf;
            senddata[0] = 0;
            senddata[1] = 0;
            senddata[2] = 0;
            senddata[3] = 0;
        }
        sendSize = 8;
        pSendBuf[1] = DWCi_GetMatchCnt()->flag7c8;
        break;
    }
    DWCi_SendReliable(type, aid, pSendBuf, sendSize);
    if (pSendBuf != (u32 *)buf)
        DWC_Free(4, pSendBuf, 0);
    {
        unsigned long long tick = OS_GetTick();
        DWCi_GetMatchCnt()->synAckTick = tick;
    }
}





DWCstMatchControl;





int DWCi_ProcessMatchSynTimeout(void)
{
    DWCstNodeInfo * node;
    unsigned long long passTime;
    int i;

    if (DWCi_GetMatchCnt()->state == 8 ||
        DWCi_GetMatchCnt()->state == 0x13 ||
        DWCi_GetMatchCnt()->state == 0x17 ||
        DWCi_GetMatchCnt()->state == 0x14) {
        passTime = OS_GetTick() - DWCi_GetMatchCnt()->synAckTick;
        passTime = passTime * 64 / 0x82ea;
    } else {
        return 1;
    }

    switch (DWCi_GetMatchCnt()->state) {
    case 8:
        if (passTime <= DWCi_GetMatchCnt()->clWaitTime)
            break;
        DWCi_NodeInfoList_GetCount();
        DWCi_GetMatchCnt()->tempNewClientInfo.profileID = 0;
        node = DWCi_NodeInfoList_GetServerNodeInfo();
        if (DWCi_CancelPreConnectedClientProcess(node->profileID) == 0)
            return 0;
        break;
    case 0x13:
        if (passTime <= 0x1770)
            break;
        DWCi_GetMatchCnt()->synResendCount++;
        if (DWCi_GetMatchCnt()->synResendCount > 5) {
            DWCi_GetMatchCnt()->synResendCount = 0;
            passTime = OS_GetTick();
            DWCi_GetMatchCnt()->synAckTick = passTime;
            DWCi_ServerSynTimeoutExec();
        } else {
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                node = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                if (DWCi_GetMatchCnt()->synAckBitmap & (1 << node->aid))
                    continue;
                DWCi_SendMatchSynPacket(node->aid, 2);
            }
            node = &DWCi_GetMatchCnt()->tempNewNodeInfo;
            if (!(DWCi_GetMatchCnt()->synAckBitmap & (1 << node->aid)))
                DWCi_SendMatchSynPacket(node->aid, 2);
        }
        break;
    case 0x17:
        if (passTime <= 0xbb8)
            break;
        DWCi_SendTypeMatchAck();
        break;
    case 0x14:
        if (passTime <= DWCi_GetMatchCnt()->hostLatency)
            break;
        DWCi_PostProcessConnection(3);
        break;
    }
    return 1;
}





/*
 * sdk:      DWCi_ServerSynTimeoutExec (dwc_match.o)
 */
int func_0217352C(void)
{
    if (!func_02172EAC(*(int *)((char *)func_02175F3C() + 0x650)))
        return 0;
    if (func_0217603C() > 1 || func_02176554()) {
        unsigned long long t = func_020870D0();
        *(unsigned long long *)((char *)func_02175F3C() + 0x658) = t;
        func_02175F4C(23);
    } else if (!func_021720D8(*(int *)((char *)func_02175F3C() + 0x680))) {
        return 0;
    }
    return 1;
}





/*
 * sdk:      DWCi_SendTypeMatchAck (dwc_match.o)
 */
void func_021735A4(void)
{
    int i;

    if (INTRUDE_COMM_IsJoinRequestValid() != 2)
        return;
    for (i = 1; i < func_0217603C(); i++)
        func_02173064(*(unsigned char *)((char *)func_0217637C(i) + 0x16), 4);
    if (func_02176554())
        func_02173064(*(unsigned char *)((char *)func_02175F3C() + 0x56a), 4);
    func_02175F4C(20);
}




int func_02173614(int profileID, unsigned char command)
{
    char *pNodeInfo;
    int result;
    int len;
    unsigned long senddata[1];

    if (command != 13) {
        len = 0;
    } else {
        senddata[0] = *(unsigned long *)((char *)func_02175F3C() + 0x680);
        len = 1;
    }
    pNodeInfo = func_021763AC(profileID);
    if (!pNodeInfo)
        return 0;
    result = func_0216FF2C(command, profileID, *(int *)(pNodeInfo + 4), *(unsigned short *)(pNodeInfo + 12), (const unsigned int *)senddata, len);
    if (func_021719A4(result))
        return 0;
    {
        unsigned long long t = func_020870D0();
        *(unsigned long long *)((char *)func_02175F3C() + 0x660) = t;
    }
    return 1;
}




int DWCi_ProcessCancelMatchSynCommand(int profileID, u8 command, u32 data)
{
    DWCstNodeInfo * pNodeInfo;
    int i;
    unsigned long long latency;
    unsigned long long baseTime;
    u32 bitmask;
    u8 aid;

    if (DWC_GetState() != 5)
        return 1;

    switch (command) {
    case 0xd:
        if (DWCi_GetMatchCnt()->state != 7) {
            DWCi_SetMatchStatus(7);
            DWCi_GetMatchCnt()->peerProfileID = data;
            if (DWCi_GetMatchCnt()->tempNewClientInfo.profileID != 0)
                DWCi_GetMatchCnt()->tempNewClientInfo.profileID = 0;
            DWCi_TempNewNodeInfo_Clear();
        }
        if (DWCi_SendCancelMatchSynCommand(profileID, 0xe) != 0)
            break;
        return 0;
    case 0xe:
        if (DWCi_GetMatchCnt()->state == 0x11) {
            baseTime = OS_GetTick();
            if ((baseTime - DWCi_GetMatchCnt()->f_660) * 64 / 0x82ea / 2 > 0x12c) {
                latency = (baseTime - DWCi_GetMatchCnt()->f_660) * 64 / 0x82ea / 2 - 0x12c;
                if (latency > DWCi_GetMatchCnt()->f_632)
                    DWCi_GetMatchCnt()->f_632 = latency;
            }
            aid = DWCi_GetAIDFromProfileID(profileID, 0);
            if (aid != 0xff)
                DWCi_GetMatchCnt()->f_654 |= 1 << aid;
            bitmask = DWCi_GetAIDBitmask(1);
            if (bitmask != DWCi_GetMatchCnt()->f_654)
                break;
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(i);
                if (DWCi_SendCancelMatchSynCommand(pNodeInfo->profileID, 0xf) == 0)
                    return 0;
            }
            DWCi_SetMatchStatus(0x12);
        } else if (DWCi_SendCancelMatchSynCommand(profileID, 0xf) == 0) {
            return 0;
        }
        break;
    case 0xf:
        if (DWCi_GetMatchCnt()->state == 7)
            DWCi_RestartFromCancel(2);
        break;
    }
    return 1;
}



int DWCi_ProcessCancelMatchSynTimeout(void)
{
    unsigned long long passTime;
    int i;

    if (DWCi_GetMatchCnt()->state == 7 ||
        DWCi_GetMatchCnt()->state == 0x11 ||
        DWCi_GetMatchCnt()->state == 0x12) {
        passTime = OS_GetTick() - DWCi_GetMatchCnt()->f_660;
        passTime = passTime * 64 / 0x82ea;
    } else {
        return 1;
    }

    switch (DWCi_GetMatchCnt()->state) {
    case 7: {
        DWCstNodeInfo * pNodeInfo;

        if (passTime <= 0x1770)
            break;
        pNodeInfo = DWCi_NodeInfoList_GetNodeInfoForIndex(0);
        if (DWCi_SendCancelMatchSynCommand(pNodeInfo->profileID, 0xe) == 0)
            return 0;
        break;
    }
    case 0x11:
        if (passTime <= 0x1770)
            break;
        DWCi_GetMatchCnt()->cancelSynResendCount++;
        if (DWCi_GetMatchCnt()->cancelSynResendCount > 5) {
            if (DWCi_CloseShutdownClientSC(DWCi_GetMatchCnt()->f_654) == 0)
                return 0;
            if (DWCi_NodeInfoList_GetCount() > 1) {
                DWCi_GetMatchCnt()->cancelSynResendCount = 0;
                passTime = OS_GetTick();
                DWCi_GetMatchCnt()->f_660 = passTime;
            } else {
                DWCi_RestartFromCancel(2);
            }
        } else {
            for (i = 1; i < DWCi_NodeInfoList_GetCount(); i++) {
                DWCstNodeInfo * pNodeInfo =
                    DWCi_NodeInfoList_GetNodeInfoForIndex(i);

                if (DWCi_GetMatchCnt()->f_654 & (1 << pNodeInfo->aid))
                    continue;
                if (DWCi_SendCancelMatchSynCommand(pNodeInfo->profileID, 0xd) == 0)
                    return 0;
            }
        }
        break;
    case 0x12:
        if (passTime <= DWCi_GetMatchCnt()->f_632)
            break;
        DWCi_RestartFromCancel(2);
        break;
    }
    return 1;
}



/*
 * Finds the first empty record (stride 0xc) among 0x9a entries and returns
 * its biased index; 0 when none is free.
 */
u8 func_02173AD8(void)
{
    u8 i;

    for (i = 0; i < 0x9a; i++) {
        if (d_021AAA40[i * 0xc] == 0)
            return (i + 0x64) & 0xff;
    }
    return 0;
}



/*
 * DWCi_ClearGameMatchKeys: frees every game match key value and clears the key table.
 */
void func_02173B18(void)
{
    int i;

    for (i = 0; i < 0x9a; i++) {
        if (g_021AAA40[i].keyString != 0) {
            DWC_Free(4, g_021AAA40[i].keyString, 0);
        }
    }
    MIi_CpuClear32(0, g_021AAA40, sizeof(DWCstGameMatchKeyData) * 0x9a);
}



/*
 * sdk:      DWCi_IsFriendByIdxList (dwc_match.o)
 */
int func_02173B74(int profileID)
{
    int i;
    int id;

    if (*(int *)((char *)func_02175F3C() + 0x68c) == 0)
        return 0;
    for (i = 0; i < *(int *)((char *)func_02175F3C() + 0x6d4); i++) {
        id = func_02168FF0(*(unsigned char *)((char *)func_02175F3C() + i + 0x694));
        if (id > 0 && id == profileID)
            return 1;
    }
    return 0;
}



/*
 * sdk:      DWCi_CheckDWCServer (dwc_match.o)
 */
int INTRUDE_COMM_RecvNoticeBytes(void *server)
{
    if (func_0219E120(server, g_021A21A4, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A21B0, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2170, -1) == -1)
        return 0;
    if (func_0219E120(server, g_021A2164, -1) == -1)
        return 0;
    return func_0219E120(server, g_021A20A4, 0);
}



/*
 * Byte at +0x16 of the block, or 0xff when there is none.
 */
u8 func_02173C84(int profileID, int idxOnly)
{
    unsigned char *p = (unsigned char *)func_021763AC(profileID);

    if (p == 0)
        return 0xff;
    return *(unsigned char *)(p + 0x16);
}


/*
 * sdk:      DWCi_GetAIDBitmask (dwc_match.o)
 */
unsigned int INTRUDE_COMM_RecvRemoteRecord(int valid)
{
    unsigned int bitmask = 0;
    int i;

    for (i = 1; i < func_0217603C(); i++)
        bitmask |= 1 << *(unsigned char *)((char *)func_0217637C(i) + 0x16);
    if (valid == 0)
        bitmask |= 1 << *(unsigned char *)((char *)func_02175F3C() + 0x56a);
    return bitmask;
}


/*
 * DWCi_InitClWaitTimeout: clears the wait flag and stamps the current tick.
 */
void func_02173CFC(void)
{
    unsigned long long t;

    ((char *)func_02175F3C())[0x62e] = 0;
    t = OS_GetTick();
    *(unsigned long long *)((char *)func_02175F3C() + 0x670) = t;
}


/*
 * Maps a match-command error to a DWC error and stops the match.
 */
int func_02173D28(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
        dwcError = 9;
        errorCode = -2;
        break;
    case 3:
        dwcError = 6;
        errorCode = -10;
        break;
    case 4:
        dwcError = 6;
        errorCode = -20;
        break;
    }
    func_0216EB68(dwcError, errorCode + -81000);
    return error;
}


/*
 * DWCi_HandleSBError: maps a server browsing error to a DWC error and stops the match.
 */
int func_02173D9C(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -30;
        break;
    case 3:
        dwcError = 6;
        errorCode = -20;
        break;
    case 4:
        dwcError = 6;
        errorCode = -40;
        break;
    case 5:
        dwcError = 9;
        errorCode = -1;
        break;
    case 6:
        dwcError = 9;
        errorCode = -2;
        break;
    }
    func_0216EB68(dwcError, errorCode + -85000);
    return error;
}


/*
 * sdk:      DWCi_HandleQR2Error (libdwcmatch.TWL.HYB.a dwc_match.o)
 */
int func_02173E30(int error)
{
    int errorCode;
    int dwcError;

    if (error == 0)
        return 0;
    switch (error) {
    case 1:
        dwcError = 6;
        errorCode = -50;
        break;
    case 2:
        dwcError = 6;
        errorCode = -60;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    case 4:
        dwcError = 6;
        errorCode = -80;
        break;
    case 5:
        dwcError = 6;
        errorCode = -20;
        break;
    }
    switch (DWC_GetState()) {
    case 2:
        func_0216A3B8(dwcError, errorCode - 64000);
        break;
    case 4:
        func_0216EB68(dwcError, errorCode - 84000);
        break;
    default:
        DWCi_SetError(dwcError, errorCode - 94000);
        break;
    }
    return error;
}


/*
 * DWCi_HandleNNError: maps a NAT negotiation error to a DWC error and stops the match.
 */
int func_02173EF8(int error)
{
    int dwcError;
    int errorCode;

    if (error == 0) {
        return 0;
    }
    switch (error) {
    case 1:
        dwcError = 9;
        errorCode = -1;
        break;
    case 2:
        dwcError = 6;
        errorCode = -50;
        break;
    case 3:
        dwcError = 6;
        errorCode = -30;
        break;
    }
    func_0216EB68(dwcError, errorCode + -86000);
    return error;
}


int func_02173F54(int result)
{
    enum E dwcError;

    if (result == 0)
        return 0;
    switch (result) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        dwcError = E_NET;
        break;
    }
    if (dwcError != E_OK)
        func_0216EB68(dwcError, -86009);
    return result;
}


/*
 * sdk:      DWCi_HandleGT2Error (dwc_match.o)
 */
int func_02173FB4(int result)
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
        func_0216EB68(dwcError, errorCode + -87000);
    return result;
}


/*
 * notes:    the retry tail (state 2 and a fresh timeout tick) is written out at the end of
 *           cases 0x16, 4 and 0xC; the compiler cross-jumps the identical copies, which
 *           leaves the one-instruction jump stubs the image has. The counter, running
 *           maximum and per-server count of the case 0xC scan are block locals of its
 *           sbCount > 1 arm; declaration order in the function block fixes the rest of
 *           the register assignment. The bare MC() call and the unused
 *           ServerBrowserGetServer(sb, 0) call in case 4 are in the image and kept.
 *
 * sdk:      DWCi_SBCallback (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
void func_02174058(void *sb, int reason, void *server)
{
    int sbCount;
    void *targetServer;
    int i;
    int profileID;
    u64 tick;
    DWCstNodeInfo tmpNodeInfo;

    s_bInNNThink.sbCallbackLevel++;

    if (MC()->sbUpdateRequestTick != 0) {
        if (reason == 4 || reason == 5) {
            MC()->sbUpdateRequestTick = 0;
        } else {
            tick = OS_GetTick();
            MC()->sbUpdateRequestTick = tick + (u64)0xEFB5F7;
        }
    }

    switch (reason) {
    case 0:
        DWCi_SBPrintServerData(server);
        break;
    case 4:
        MC()->sbUpdateRequestTick = 0;
        for (i = 0; i < ServerBrowserCount(sb); i++) {
            server = ServerBrowserGetServer(sb, i);
            if (DWCi_CheckDWCServer(server) == 0) {
                ServerBrowserRemoveServer(sb, server);
                i--;
            }
        }
        switch (MC()->state) {
        case 0x16: {
            int j;

            j = 0;
            if (ServerBrowserCount(sb) > 0) {
                do {
                    server = ServerBrowserGetServer(sb, j);
                    if (MC()->qr2IP != 0 &&
                        MC()->qr2IP == SBServerGetPublicInetAddress(server) &&
                        MC()->qr2Port != 0 &&
                        MC()->qr2Port == SBServerGetPublicQueryPort(server))
                        break;
                    j++;
                } while (j < ServerBrowserCount(sb));
            }
            if (j < ServerBrowserCount(sb)) {
                MI_CpuFill8(&tmpNodeInfo, 0, 0x28);
                tmpNodeInfo.profileID = MC()->profileID;
                tmpNodeInfo.aid = 0xFF;
                tmpNodeInfo.publicInetAddress = MC()->qr2IP;
                tmpNodeInfo.publicQueryPort = MC()->qr2Port;
                tmpNodeInfo.privateInetAddress = SBServerGetPrivateInetAddress(server);
                tmpNodeInfo.privateQueryPort = SBServerGetPrivateQueryPort(server);
                tmpNodeInfo.hasPrivateAddress = SBServerHasPrivateAddress(server);
                MI_CpuCopy8(MC()->connUserData, &tmpNodeInfo.connUserData, 4);
                if (MC()->qr2MatchTypeExt == 0) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->qr2MatchTypeExt == 1) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->qr2MatchTypeExt == 2) {
                    tmpNodeInfo.aid = DWCi_NodeInfoList_GetFreeAID();
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                } else if (MC()->qr2MatchTypeExt == 3) {
                    DWCi_NodeInfoList_InsertToTop(&tmpNodeInfo);
                    DWCi_StartMatch();
                }
                goto end;
            }
            RETRY();
            goto end;
        }
        case 2:
            DWCi_EvaluateServers(1);
            DWCi_RandomizeServers();
            if (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                DWCi_TempNewNodeInfo_Clear();
                MC()->tempNewNodeInfo.profileID = SBServerGetIntValueA(server, g_021A20A4, 0);
                MC()->tempNewNodeInfo.aid = 0xFF;
                MC()->tempNewNodeInfo.publicInetAddress = SBServerGetPublicInetAddress(server);
                MC()->tempNewNodeInfo.publicQueryPort = SBServerGetPublicQueryPort(server);
                MC()->tempNewNodeInfo.privateInetAddress = SBServerGetPrivateInetAddress(server);
                MC()->tempNewNodeInfo.privateQueryPort = SBServerGetPrivateQueryPort(server);
                MC()->tempNewNodeInfo.hasPrivateAddress = SBServerHasPrivateAddress(server);
                DWCi_ConnectToGameServerAsync_InterChange(MC()->tempNewNodeInfo.profileID);
            } else {
                MC()->sbUpdateFlag = 2;
                tick = OS_GetTick();
                MC()->sbUpdateTick = tick;
                DWCi_TempNewNodeInfo_Clear();
            }
            goto end;
        case 4:
            while (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                if (SBServerGetPublicInetAddress(server) == MC()->tempNewNodeInfo.publicInetAddress &&
                    SBServerGetPublicQueryPort(server) == MC()->tempNewNodeInfo.publicQueryPort)
                    break;
                ServerBrowserRemoveServer(sb, server);
            }
            if (ServerBrowserCount(sb) != 0) {
                server = ServerBrowserGetServer(sb, 0);
                profileID = SBServerGetIntValueA(server, g_021A20A4, 0);
                if (MC()->qr2MatchTypeExt == 1) {
                    MC();
                    if (profileID != MC()->reqProfileID ||
                        DWCi_EvaluateServers(0) == 0) {
                        if (DWCi_HandleMatchCommandError(
                                DWCi_CancelReservation(MC()->reqProfileID)) != 0)
                            goto end;
                        DWCi_SetMatchStatus(3);
                        DWCi_TempNewNodeInfo_Clear();
                        DWCi_HandleMatchCommandError(
                            DWCi_SendResvCommandToFriend(0, 0, MC()->reqProfileID));
                        goto end;
                    }
                }
                DWCi_SetMatchStatus(5);
                ServerBrowserGetServer(sb, 0);
                DWCi_HandleNNError(DWCi_NNStartupAsync(0, 0,
                    (DWCstNodeInfo *)&MC()->tempNewNodeInfo.profileID));
                goto end;
            }
            RETRY();
            goto end;
        case 0xC:
            sbCount = ServerBrowserCount(sb);
            if (sbCount != 0) {
                if (sbCount > 1) {
                    int k;
                    int max_numplayers;
                    int numplayers;

                    max_numplayers = -1;
                    for (k = 0; k < sbCount; k++) {
                        server = ServerBrowserGetServer(sb, k);
                        numplayers = SBServerGetIntValueA(server, g_021A21A4, -1);
                        if (max_numplayers < numplayers) {
                            targetServer = server;
                            max_numplayers = numplayers;
                        }
                    }
                } else {
                    targetServer = ServerBrowserGetServer(sb, 0);
                }
                DWCi_TempNewNodeInfo_Clear();
                MC()->tempNewNodeInfo.profileID = SBServerGetIntValueA(targetServer, g_021A20A4, 0);
                MC()->tempNewNodeInfo.aid = 0xFF;
                MC()->tempNewNodeInfo.publicInetAddress = SBServerGetPublicInetAddress(targetServer);
                MC()->tempNewNodeInfo.publicQueryPort = SBServerGetPublicQueryPort(targetServer);
                MC()->tempNewNodeInfo.privateInetAddress = SBServerGetPrivateInetAddress(targetServer);
                MC()->tempNewNodeInfo.privateQueryPort = SBServerGetPrivateQueryPort(targetServer);
                MC()->tempNewNodeInfo.hasPrivateAddress = SBServerHasPrivateAddress(targetServer);
                MC()->qr2MatchTypeExt = SBServerGetIntValueA(targetServer, g_021A2170, -1);
                {
                    int topology = DWCi_GetTopologyType();

                    profileID = SBServerGetIntValueA(targetServer, g_021A20A4, 0);
                    DWCi_ConnectToGameServerAsync(topology, profileID,
                        (void *)MC()->matchedCallback, (void *)MC()->matchedParam,
                        (void *)MC()->newClientCallback, (void *)MC()->newClientParam,
                        (void *)MC()->f_7B8, MC()->connUserData,
                        (void *)MC()->f_7C0);
                }
                goto end;
            }
            RETRY();
            goto end;
        default:
            goto end;
        }
        break;
    }
end:
    s_bInNNThink.sbCallbackLevel--;
}
