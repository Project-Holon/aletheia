/*
 * file:     unit_0216C858.c
 * unit:     yes
 * function: DWC_CancelMatch, DWC_IsValidCancelMatch, func_0216C8DC, func_0216CA04, func_0216CB30, func_0216CB90, func_0216CC28, func_0216CD8C, DWCi_ConnectToAnybodyAsync, func_0216D138, func_0216D27C, DWCi_SendStateChanged, func_0216D57C, func_0216E4C0, DWCi_GT2ConnectAttemptCallback, DWCi_MakeGT2ConnectString, DWCi_GT2ConnectedCallback, func_0216EAB8, func_0216EB48, func_0216EB68, DWCi_ClearQR2Key, DWCi_ProcessMatchSynPacket, func_0216EC84
 * address:  0x0216C858
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
 *   DWCi_DoCancelMatch      0x021728B8 arm
 *   DWCi_GetMatchCnt        0x02175F3C arm
 *   DWCi_IsError      0x02059F38 arm
 *   DWC_GetState      0x0216B994 arm
 *   g_021AAA40     0x021AAA40  data  ov009
 *   func_02173AD8  0x02173AD8  arm  ov009
 *   func_020948E0  0x020948E0  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0205A16C  0x0205A16C  arm
 *   func_02094798  0x02094798  arm
 *   func_0219D158  0x0219D158  arm  ov009
 *   g_021AAA44                   0x021AAA44 data
 *   g_021AAA41                   0x021AAA41 data
 *   g_021AAA42                   0x021AAA42 data
 *   g_021AAA48                   0x021AAA48 data
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02059F38  0x02059F38  arm
 *   func_0219F058  0x0219F058  arm  ov009
 *   func_0219E120  0x0219E120  arm  ov009
 *   func_02175FB8  0x02175FB8  arm  ov009
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   func_02175EB4  0x02175EB4  arm  ov009
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   func_02175F1C  0x02175F1C  arm  ov009
 *   func_02175F4C  0x02175F4C  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0217601C  0x0217601C  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 *   func_02173B18  0x02173B18  arm  ov009
 *   func_0216F388  0x0216F388  arm  ov009
 *   gt2GetSocketSOCKET  0x02195E60  arm  ov009
 *   gt2GetLocalPort  0x02195E40  arm  ov009
 *   func_0219AEB4  0x0219AEB4  arm  ov009
 *   func_0219B540  0x0219B540  arm  ov009
 *   func_02173E30  0x02173E30  arm  ov009
 *   func_0219B1AC  0x0219B1AC  arm  ov009
 *   func_0219B134  0x0219B134  arm  ov009
 *   func_0219B170  0x0219B170  arm  ov009
 *   func_02176ABC  0x02176ABC  arm  ov009
 *   func_0219B490  0x0219B490  arm  ov009
 *   func_02174AA0  0x02174AA0  arm  ov009
 *   func_02174C2C  0x02174C2C  arm  ov009
 *   func_02174C30  0x02174C30  arm  ov009
 *   func_02174C34  0x02174C34  arm  ov009
 *   func_02174CF0  0x02174CF0  arm  ov009
 *   func_02174CF8  0x02174CF8  arm  ov009
 *   func_02174D04  0x02174D04  arm  ov009
 *   func_02174D28  0x02174D28  arm  ov009
 *   func_02174ED0  0x02174ED0  arm  ov009
 *   DWC_Free                0x0205A1B0  arm
 *   func_0216FAD4           0x0216FAD4  arm  ov009
 *   DWC_Alloc               0x0205A16C  arm
 *   MI_CpuCopy8             0x02082D44  arm
 *   func_0216F5FC           0x0216F5FC  arm  ov009
 *   func_02175560           0x02175560  arm  ov009
 *   func_0219EC74           0x0219EC74  arm  ov009
 *   func_02173D9C           0x02173D9C  arm  ov009
 *   func_0216F20C           0x0216F20C  arm  ov009
 *   func_0216F770           0x0216F770  arm  ov009
 *   func_02174058           0x02174058  arm  ov009
 *   g_021AAA20              0x021AAA20  data
 *   g_021A2044              0x021A2044  data
 *   func_02173D28  0x02173D28  arm  ov009
 *   func_02175F84  0x02175F84  arm  ov009
 *   func_02175530  0x02175530  arm  ov009
 *   func_02176344  0x02176344  arm  ov009
 *   func_0217604C  0x0217604C  arm  ov009
 *   func_021719D0  0x021719D0  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   MI_CpuFill8    0x02082BCC  arm
 *   qr2_think         0x0219B1E8 arm
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
 *   func_0219C7C0   0x0219C7C0  arm  ov009
 *   func_020923F0   0x020923F0  arm
 *   func_0219AB8C   0x0219AB8C  arm  ov009
 *   g_021A5A7C      0x021A5A7C  data
 *   gt2Reject                        0x02195B38 arm
 *   strtoul                          0x02095EAC arm
 *   DWCi_GT2GetConnectionListIdx     0x0216BB6C arm
 *   gt2Accept                        0x02195B2C arm
 *   DWCi_GetGT2ConnectionByIdx       0x0216BBCC arm
 *   DWCi_GetConnectionInfoByIdx      0x0216BC2C arm
 *   DWCi_ResetLastSomeDataRecvTimeByAid 0x02177748 arm
 *   gt2SetConnectionData             0x02195E70 arm
 *   DWCi_PostProcessConnection       0x02172254 arm
 *   g_021A204C                       0x021A204C data
 *   g_021A2058                       0x021A2058 data
 *   g_021A2064                       0x021A2064 data
 *   OS_SNPrintf       0x02084F80 arm
 *   g_021A207C        0x021A207C data
 *   gt2AddressToString               0x02198620 arm
 *   gt2Connect                       0x02195B44 arm
 *   DWCi_HandleGT2Error              0x02173FB4 arm
 *   strlen         0x0209477C  arm
 *   func_02059CBC  0x02059CBC  arm
 *   func_021702A0  0x021702A0  arm  ov009
 *   func_02172E7C  0x02172E7C  arm  ov009
 *   DWCi_SetError  0x02059F54  arm
 *   func_02169038  0x02169038  arm  ov009
 *   func_0216F6C0  0x0216F6C0  arm  ov009
 *   DWCi_IsFullMesh                        0x0217695C arm
 *   DWCi_ProcessMatchSynPacketSub_FullMesh 0x0216F008 arm
 *   DWCi_ProcessMatchSynPacketSub_Hybrid   0x0216EC84 arm
 *   DWCi_NodeInfoList_InsertToTop    0x0217604C arm
 *   DWCi_SendMatchSynPacket          0x02173064 arm
 *   DWCi_GetAIDBitmask               0x02173C9C arm
 *   DWCi_GetMathRand32               0x021685CC arm
 *   DWCi_SendTypeMatchAck            0x021735A4 arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_MatchAnchorA.h"
#include "../../matched/include/G_Magic6.h"
#include "dwc_match_ctl_types.h"

struct SOCSockAddrIn;

extern DWCstGameMatchKeyData g_021AAA40[154];
extern struct NNThinkGlobal g_021AAA20;
extern struct MatchAnchorA s_anybodyServerSearchRatio;
extern struct Magic6 g_021A5A7C;
extern char g_021A2044[];
extern char g_021A204C[];
extern char g_021A2058[];
extern char g_021A2064[];
extern char g_021A207C[];

extern DWCstMatchControl *DWCi_GetMatchCnt(void);

/* callees */
extern void DWCi_DoCancelMatch(void);
extern int DWCi_IsError(void);
extern int DWC_GetState(void);
extern int func_020948E0(const char *s1, const char *s2);
extern u8 func_02173AD8(void);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern int func_0209477C(const u8 *s);
extern void *func_0205A16C(int name, u32 size);
extern char *func_02094798(char *dst, const char *src);
extern void func_0219D158(int keyid, char *key);
extern int func_02059F38(void);
extern unsigned char func_02175FB8(void);
extern int DWC_GetAIDBitmap(void);
extern int func_02175EB4(void);
extern unsigned char DWC_GetMyAID(void);
extern void func_02175F1C(int a0);
extern void func_02175F4C(int a0);
extern void func_0217601C(void);
extern void func_0217653C(void);
extern void func_02173B18(void);
extern int func_0216F388(int a0);
extern int gt2GetSocketSOCKET(const int *p);
extern unsigned short gt2GetLocalPort(const unsigned short *p);
extern int func_02173E30(int error);
extern void func_0219B1AC(void *qrec, void *cb);
extern void func_0219B134(void *qrec, void *cb);
extern void func_0219B170(void *qrec, void *cb);
extern void func_02176ABC(void);
extern void func_02174AA0(int keyid, void *outbuf);
extern void func_02174C2C();
extern void func_02174C30();
extern void func_02174C34(int keytype, void *keybuffer);
extern int func_02174CF0();
extern void func_02174CF8();
extern void func_02174D04();
extern void func_02174D28(int cookie);
extern void func_02174ED0(char *data, int len);
extern void DWC_Free(int name, void *ptr, unsigned long size);
extern int func_0216FAD4(char *filter, int profileID, unsigned char numEntry, unsigned char matchType, unsigned char hostState);
extern void *DWC_Alloc(int name, unsigned long size);
extern void func_02175560(void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
extern int func_0216F20C(int status);
extern int func_0216F770(int profileID);
extern void func_02174058(void *sb, int reason, void *server);
extern int func_02173D28(void);
extern void func_02175F84(int a0);
extern int func_02175530(void);
extern void func_021719D0(int a0, int a1);
extern void func_021719A4(void);
extern void MI_CpuFill8(void *dstp, u8 data, u32 size);
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
extern void NNThink(void);
extern void NNFreeNegotiateList(void);
extern int DWCi_ResumeMatch(void);
extern int DWCi_RequestSuspendMatchProcess(void);
extern int DWCi_SendServerPolling(int immediate);
extern int DWCi_ProcessMatchSynTimeout(void);
extern int DWCi_ProcessCancelMatchSynTimeout(void);
extern void MIi_CpuClear32(int v, void *p, int size);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern void gt2Reject(void * connection, void * message, int code);
extern unsigned long strtoul(const char * s, char ** end, int base);
extern int DWCi_GT2GetConnectionListIdx(void);
extern int gt2Accept(void * connection, void * flag);
extern void ** DWCi_GetGT2ConnectionByIdx(int index);
extern struct DWCstConnectionInfo * DWCi_GetConnectionInfoByIdx(int index);
extern void DWCi_ResetLastSomeDataRecvTimeByAid(u8 aid);
extern void gt2SetConnectionData(void * connection, void * data);
extern void DWCi_PostProcessConnection(int type);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern char * gt2AddressToString(u32 ip, u16 port, char * string);
extern int gt2Connect(void * socket, void ** connection, char * remoteAddress, u8 * message, int len, int timeout, void * callbacks, int blocking);
extern int DWCi_HandleGT2Error(int result);
extern int func_02059CBC(const char *src, int srclen, void *dst, int dstlen);
extern void func_02172E7C(void);
extern void DWCi_SetError(int error, int errorCode);
extern int func_02169038(int pid);
extern void func_0216F6C0(void);
extern int DWCi_IsFullMesh(void);
extern void DWCi_ProcessMatchSynPacketSub_FullMesh(unsigned char aid, unsigned short type, unsigned char *data);
extern void DWCi_ProcessMatchSynPacketSub_Hybrid(unsigned char aid, unsigned short type, unsigned char *data);
extern void DWCi_SendMatchSynPacket(unsigned char aid, unsigned short type);
extern unsigned long DWCi_GetAIDBitmask(int valid);
extern unsigned long DWCi_GetMathRand32(unsigned long max);
extern void DWCi_SendTypeMatchAck(void);

extern void func_0216F5FC(u8 matchType, u8 numEntry, void *callback, void *param);
extern int func_02173D9C(int error);
extern void func_0219B490(void *qrec);
extern void *func_0219EC74(char *queryForGamename, char *queryFromGamename, char *queryFromKey, int queryFromVersion, int maxConcUpdates, int queryVersion, int lanBrowse, void *callback, void *instance);
extern void DWCi_SendStateChanged(qr2_implementation_s *qr2Obj);
extern void qr2_think(qr2_implementation_s *qr2Obj);
extern void MI_CpuCopy8(const void *srcp, void *dstp, unsigned long size);
extern struct SBServer *func_0219F058(struct SBServer *sb, int index);
extern int func_0219E120(struct SBServer *server, char *key, int idefault);
extern void func_0219B540(qr2_implementation_s *qrec);
extern void func_0219C7C0(qr2_implementation_s *qr2, unsigned char *message, int len, SOCSockAddrIn *saddr);
extern void func_0219AB8C(char *data, int len, SOCSockAddrIn *fromaddr);
extern int func_0217604C(DWCstNodeInfo *newNode);
extern DWCstNodeInfo *func_02176344(void);
extern int DWCi_NodeInfoList_InsertToTop(DWCstNodeInfo *newNode);
extern void gt2Think(void *socket);
extern int func_0219AEB4(qr2_implementation_s **qrec, int s, int boundport, char *gamename, char *secret_key, int ispublic, int natnegotiate, void *server_key_callback, void *player_key_callback, void *team_key_callback, void *key_list_callback, void *playerteam_count_callback, void *adderror_callback, void *userdata);
extern void func_0216EAB8(int unused, int profileID, char *message);
extern void func_0216EB48(void);
extern void func_021702A0(int type, int profileID, int a2, int a3, u32 *data, int len);
extern void DWCi_DoCancelMatch(void);

/* this unit */
int DWC_CancelMatch(void);
int DWC_IsValidCancelMatch(void);
u8 func_0216C8DC(u8 keyID, char *keyString, int *valueSrc);
u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc);
int func_0216CB30(int index, char *key, int idefault);
int func_0216CB90(void);
int func_0216CC28(int a0, void **pGpObj, void **pGt2Socket, void *gt2Callbacks, char *gameName, char *secretKey, int a6, int a7);
int func_0216CD8C(int profileID);
void DWCi_ConnectToAnybodyAsync(int topology, u8 numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam);
void func_0216D138(int topology, u8 numEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam);
void func_0216D27C(int topology, int serverPid, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam);
void DWCi_MatchProcess(int fullSpec);
int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
void DWCi_GT2ConnectAttemptCallback(void *userdata, void *connection, unsigned int ip, unsigned short port, int latency, unsigned char *message, int len);
void DWCi_MakeGT2ConnectString(char *buf, int bufLen);
void DWCi_GT2ConnectedCallback(void *connection, int result);
void func_0216EB68(int error, int errorCode);
void DWCi_ClearQR2Key(void);
void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);
void func_0216EC84(unsigned char aid, unsigned short type, unsigned char *data);

#define KEYID(i)  (g_021AAA40[i].keyID)
#define KEYF1(i)  (g_021AAA40[i].isStr)
#define KEYF2(i)  (g_021AAA40[i].pad)
#define KEYSTR(i) (g_021AAA40[i].keyString)
#define KEYVAL(i) (g_021AAA40[i].value)
#define TICK_MS(t) (((t) * 64) / 33514)
#define MC() DWCi_GetMatchCnt()
int DWC_CancelMatch(void);
int DWC_IsValidCancelMatch(void);
u8 func_0216C8DC(u8 keyID, char *keyString, int *valueSrc);
u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc);
int func_0216CB30(int index, char *key, int idefault);
int func_0216CB90(void);
int func_0216CC28(int a0, void **pGpObj, void **pGt2Socket, void *gt2Callbacks, char *gameName, char *secretKey, int a6, int a7);
int func_0216CD8C(int profileID);
void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam);
void func_0216D138(int topology, u8 numEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam);
void func_0216D27C(int topology, int serverPid, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam);
void DWCi_SendStateChanged(struct qr2_implementation_s *qr2Obj);
void DWCi_MatchProcess(int fullSpec);
int func_0216E4C0(int unused, unsigned int ip, unsigned short port, unsigned char *message, int len);
void DWCi_GT2ConnectAttemptCallback(void * userdata, void * connection, unsigned int ip, unsigned short port, int latency, unsigned char * message, int len);
void DWCi_MakeGT2ConnectString(char *buf, int bufLen);
void DWCi_GT2ConnectedCallback(void * connection, int result);
extern void func_0216EAB8(int unused, int profileID, char *message);
void func_0216EB48(void);
void func_0216EB68(int error, int errorCode);
void DWCi_ClearQR2Key(void);
void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data);
void func_0216EC84(unsigned char aid, unsigned short type, unsigned char *data);











int DWC_CancelMatch(void)
{
    int bRet;

    if (DWC_IsValidCancelMatch()) {
        DWCi_DoCancelMatch();
        bRet = 1;
    } else {
        DWCi_GetMatchCnt();
        bRet = 0;
    }
    DWCi_GetMatchCnt()->cancelFromConnection = 0;
    return bRet;
}











int DWC_IsValidCancelMatch(void)
{
    if (DWCi_IsError())
        return 0;
    if (DWCi_GetMatchCnt() == 0 ||
        DWC_GetState() != 4 ||
        DWCi_GetMatchCnt()->cancelState != 0)
        return 0;
    return 1;
}












/*
 * DWC_AddMatchKeyInt (dwc_match.o): resolve/create the match-key slot at
 * 0x021AAA40 (12-byte stride: f0 key id, f1 flag, f2 u16, f4 string ptr,
 * f8 int), free the old string, strdup the new one and record the int.
 *
 * BLOCKER (codegen only, size correct at 296): the whole body is logically
 * right but mwcc allocates the three parameters differently -- original
 * keeps a0=r7, a1=r6, a2=r5 with the index in r4 and rematerialises a zero
 * into r2; this front end hoists a zero into r4 and maps a0=r8, a1=r7,
 * a2=r6 with the index in r5.  Every branch target and constant is right;
 * only the register file assignment differs.  Not a witness problem.
 *
 * lane W7 (2026-09-30): applied the unsigned guard the U22 note identified
 * (`(unsigned)a0 >= 0x64u`); the image's first key test is now the image word
 * (`blo`), but the +1 register roll from the hoisted zero is unchanged: still
 * 296/296 with 134 concrete bytes differing and 13/13 relocations resolved.
 * Measured and rejected this wave: computed-zero spellings (a2^a2, a2&0),
 * a separate `key` local, an i-through-pointer local, f4 through a char*,
 * and a global const zero (304 B / 158).  The hoisted `mov r4,#0` (global-CSE
 * of the shared f1/f2 zero into a callee-saved register) remains the sole
 * blocker and is a 1.1p1 allocator behaviour.  Note for the human: the twin
 * 0x0216CA04 lane (T5/U10) pinned this DWC object family to ../2.0/base, where
 * the image allocates index->r4 with no hoisted zero; this lane is bound to
 * dsi/1.1p1 per the wave brief, so the row stays DIFF here.
 *
 * lane U22 (2026-09-30): one CONCRETE byte is wrong in the draft, not just
 * registers.  The image's first key test is +0020 `cmp r7,#0x64; blo` --
 * cond 0x3 (unsigned LO, word 0F 00 00 3A) -- while the parked `a0 >= 0x64`
 * on a signed int emits cond 0xB (`blt`, word 0F 00 00 BA).  Spelling the
 * guard `(unsigned)a0 >= 0x64u` produces the image's word, so the original
 * keys off an unsigned comparison.  The rest is the +1 register roll: ours
 * materialises a shared zero into the callee-saved r4 at +0014 (the image
 * rematerialises `mov r2,#0` at the stores) and that live zero pushes
 * keyID->r8, keyString->r7, valueSrc->r6 with index->r5, against the image's
 * r7/r6/r5 with index->r4.  Measured and not moving the roll: u8 return and
 * u8 params, int* valueSrc, inline indexing (`g[a0-0x64]`), unsigned index,
 * `(u8)0`/`(u16)0` typed zero stores, swap of the two zero stores, zero
 * stores before the f0 store, decl order.  The hoisted zero is the only
 * thing standing between the draft and EXACT on this row and its twin
 * 0x0216CA04.
 *
 * lane W8 (2026-09-30): re-confirmed under dsi/1.1p1.  This is exactly the
 * documented front-end wall of docs/idioms/a-repeated-small-constant-takes-a-
 * callee-saved-register.md: the shared `0` (the `return 0` at +005C and the
 * f1/f2 stores) is pooled into callee-saved r4 at +0014, crossing two calls,
 * which steals the first callee-saved slot and shifts every register +1.  The
 * idiom's own correction says the only known lever is a 2.0 pin.  Measured
 * this wave and no effect on the roll: an enum-typed zero for the stores
 * (docs/idioms/an-enum-typed-zero-keeps-its-own-web-where-a-u32-zero-is-
 * folded.md), assigned both immediately before the stores and first at entry.
 * Cross-check (informational, lead from the twin): under ../2.0/base the whole
 * allocation matches the image (index->r4, no pooled zero) but the size is 300
 * vs 296 -- the twin's one-redundant-copy tail residue (49 concrete) -- so no
 * in-tree compiler reaches EXACT and the row is parked for the object's front
 * end, not a source shape.
 *
 * lane W8b (2026-10-01): re-verified under dsi/1.1p1: identical 296/296, 134
 * concrete, 13/13 relocs.  Re-read the zero idioms; all the named-local zero
 * idioms (a-zero-stored-passed-and-returned-is-a-named-local,
 * a-returned-zero-keeps-r0-out-of-the-rotation,
 * a-repeated-constant-pools-only-within-one-block...) move the benchmark in
 * the opposite direction -- they force a pooled named zero -- and none
 * suppresses 1.1p1's callee-saved hoist.  The image rematerialises `mov r2,#0`
 * (stores) and `mov r0,#0` (returns); 1.1p1 alone pools them into r4.  Wall
 * unchanged.
 *
 * lane W8c (2026-10-01): re-verified under dsi/1.1p1, 296/296, 134 concrete,
 * 13/13 relocs.  Measured this wave and still no effect on the +1 roll: a
 * chained store `f1 = f2 = 0` (300 B / 239 concrete -- worse) and a
 * `do { f0/f1/f2 stores } while (0)` block fence (296 B / 134 -- unchanged).
 * The shared zero at +0014 is 1.1p1 global-CSE across the func_020948E0 call
 * into callee-saved r4; the image rematerialises `mov r2,#0` at the stores and
 * `mov r0,#0` per return.  Confirmed wall.
 *
 * 2026-10-01 (lane02): 134 -> 132 B. Body retyped from DWARF (u8 keyID and
 *   return, int *valueSrc, strcmp(keyString-field, keyString) and
 *   DWC_Free(4, ptr) with their real second arguments). The pooled zero is
 *   still the whole residue. Measured: dropping one zero store still pools,
 *   dropping both stops it (the returns alone never pool); int return and
 *   split NULL guards do not help.
 *
 * 2026-10-01 (w3 lane17): 132 B, unchanged. Mechanism measured: 1.1p1 hoists
 *   the zero to entry when 5 blocks use it (null, strcmp, get-fail and
 *   alloc-fail returns plus the stores) and at least one use is not a return
 *   value; changing any one of the four returns to a non-zero closes every register
 *   (1 B left, the constant), so the residue is exactly this count. The vendor
 *   .debug_line (dwc_match.o) puts one statement per line exactly as this
 *   body (573 guard+return, 579 strcmp test, 583 return, 590/591 get-fail,
 *   595-598 stores, 609 return), so no zero is missing from the source.
 *   Flat: stGameMatchKeys as the object's file static (it is LOCAL in its own
 *   .bss), house string.h with strcmp, enum-typed callee params, static
 *   GetNewMatchKey, || then/else swap, merged get-fail test after the join,
 *   int index from the call, empty DWC_Printf, 12 opt pragmas, all dsi pins.
 *   A goto to one shared `return 0` or an enum local returned at alloc-fail
 *   removes the hoist but changes other bytes. Twin 0216CA04 has the same count.
 *
 * 2026-10-01 (w4): 132 B, unchanged. The hoist is a pure block count, not
 *   very-busy/PRE: with get-fail returning keyID (no zero on that path) plus
 *   one extra zero block elsewhere it still hoists; the zero need not be in
 *   entry (null guard returning 1 + 5 other blocks hoists); extra non-zero
 *   blocks or removing any call do not change it. No late fold exists on 1.1p1:
 *   `return keyID` / `(keyID = f()) == 0` / `keyID >> 8` / `(u8)NULL` /
 *   `keyID > 0xff` either fold early (still hoist) or leave popeq/real ops
 *   (`return keyID` = everything EXACT except the image's moveq r0,#0, 4 B).
 *   const params, optimizer pragmas (common_subs, propagation, lifetimes,
 *   loop_invariants, dead_*, peephole, scheduling, levels) do not close it.
 *   Vendor .debug_line confirms five literal zero sites (573, 583, 591,
 *   597/598, 609), so 1.1p1 needs four; residue is a front-end count rule.
 */
u8 func_0216C8DC(u8 keyID, char *keyString, int *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && g_021AAA40[keyID - 0x64].keyID != 0) {
        if (g_021AAA40[keyID - 0x64].keyString != 0 && func_020948E0(g_021AAA40[keyID - 0x64].keyString, keyString) != 0)
            return 0;
    } else {
        keyID = func_02173AD8();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    g_021AAA40[index].keyID = keyID;
    g_021AAA40[index].isStr = 0;
    g_021AAA40[index].pad = 0;
    if (g_021AAA40[index].keyString != 0)
        func_0205A1B0(4, g_021AAA40[index].keyString, 0);
    g_021AAA40[index].keyString = func_0205A16C(4, func_0209477C((const u8 *)keyString) + 1);
    if (g_021AAA40[index].keyString == 0) {
        func_0216EB68(9, -80001);
        return 0;
    }
    func_02094798(g_021AAA40[index].keyString, keyString);
    g_021AAA40[index].value = valueSrc;
    func_0219D158(keyID, g_021AAA40[index].keyString);
    return keyID;
}










/*
 * sdk:      DWC_AddMatchKeyString (libdwcmatch.TWL.HYB.a dwc_match.o)
 *
 * notes:    closed by DWC_Free's hidden third argument (size 0), see the w4 note.
 *
 * lane T5 (2026-09-30).  PIN LEVER: the DWC object was built with a 2.0-tree
 * compiler, not dsi/1.1p1.  Under `--cc 2.0/base` (also 2.0/sp1, 2.0/sp1p2) the
 * whole register allocation matches the image from +0004 to +0x2C
 * (movs r6,r1 / mov r5,r2 / mov r7,r0 / cmp r7,#0x64 / sub r2,r7,#0x64 /
 * mul r3,r2,r0) and the residue drops from 133 to 42 concrete bytes; every dsi
 * compiler and every flag set tried gives 133.  Residue under 2.0/base is a
 * single redundant instruction in the tail argument set-up, 304 vs 300 bytes:
 *   +00FC  image `mov r0, r7` then `ldr r1, [r8, r4]`  | ours `mov r0, r8`
 *          then `ldr r1, [r0, r4]` then `mov r0, r7`   (one extra register copy,
 *          and the 12-word pool shifts +4 from +0114 on).
 * Measured flat under 2.0/base: explicit struct-member spelling of the tail two
 * statements, an element-pointer local (&g_021AAA40[index]) in three positions,
 * the call before the value store, a keyString local, and an all-element-pointer
 * body (8 spellings) - 42, 42, 50, 55, 103, 131, 140, 147 bytes.
 *
 * lane U10 (2026-09-30).  Pin confirmed and made the header's compiler field:
 * ../2.0/base.  All ten tools/mwccarm/mwccarm/2.0 subdirectories (base, sp1,
 * sp1p2, sp1p5, sp1p6, sp1p7, sp2, sp2p2, sp2p3, sp2p4) compile this source
 * byte-identically, 304 B / 42 concrete diffs against the image's 300; every
 * one of the nine dsi front ends gives 300 B / 133.  So the register
 * allocation from +0004 to +0x2C is the 2.0 tree's and the row is 2.0-pinned
 * on its own bytes; the object's stamp (4.0.0.1025) has no build in the tree.
 * RESIDUE (not closed, 4 bytes, 42 concrete diffs): every one of those 42 is
 * a pool displacement that moved with the extra instruction.  The body is the
 * image's instruction for instruction except one redundant copy at +00FC:
 *   image  +00FC `mov r0, r7`   +0104 `ldr r1, [r8, r4]`
 *   ours   +00FC `mov r0, r8`   +0104 `ldr r1, [r0, r4]`   +0108 `mov r0, r7`
 * i.e. this front end hoists a copy of the keyString base into r0 and folds
 * the load onto it, where the image hoists the keyID copy and loads straight
 * off r8.  19 spellings this lane, all 304/42: the call spelled with
 * g_021AAA40[index].keyString; a char *ks local assigned after the store; a
 * char *ks = KEYSTR(index) hoisted above the store; an element-pointer local
 * for the store and one for both the store and the call; a char *v temp for
 * valueSrc; a char **pv pointer for the value store; (volatile char **) on the
 * value store; two nested blocks; (char *) casts on both the store and the
 * load; a u8 k = keyID local; KEYSTR(keyID - 0x64) instead of KEYSTR(index);
 * the call before the store; the comma operator; (char *)valueSrc.  The role
 * of the last statement's load argument is exact: replacing it with a
 * non-load (w8/w9) yields 300 B / 7 diffs, i.e. the whole 4-byte gap is that
 * one hoisted copy.  DWC_AddMatchKeyInt (0x0216C8DC, same object, same tail
 * shape) moves 296/134 -> 300/50 under the same pin and parks on the same
 * class of residue, so this is the object's front end, not this body.
 * Verified with:
 *   python tools/match.py one --src src/pending/ov_sdk/ov009_func_0216CA04.c \
 *       --func func_0216CA04 --addr 0x0216CA04 --region ov009 --arm \
 *       --lang c99 --cc ../2.0/base
 *
 * lane W8 (2026-09-30).  Re-confirmed both pins on the current source, no
 * spelling changes.  Under the wave brief's dsi/1.1p1 it stays 300 B / 133
 * concrete diffs and the whole gap is the allocator's global-CSE of the
 * shared zero into a callee-saved register (mov r4,#0 at +0014, reused by the
 * +005C return and the +00A0 strh), which rolls keyID/keyString/valueSrc/index
 * up one register.  That is the documented front-end wall
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md
 * (the twin 0x0216C8DC parks on the same wall).  Under ../2.0/base the
 * allocation is the image's from +0004 to +0x2C and the lone residue is the
 * tail base copy at +00FC, unchanged from the T5/U10 notes; ../2.0/sp2
 * measures the same 304 B / 42.  Parked: the C is right, both front ends put
 * one extra/scheduling instruction in the tail that no source lever reaches.
 *
 * lane W8 #2 (2026-10-01).  Re-verified on the current source under both pins:
 * dsi/1.1p1 -> 300 B / 133 concrete (the shared-zero hoist, idiom
 * docs/idioms/a-repeated-small-constant-takes-a-callee-saved-register.md);
 * ../2.0/base -> 304 B / 42 concrete, every one a pool displacement from the
 * single +00FC `mov r0,r8`.  The +00FC copy is our front end materialising the
 * g_021AAA40 base in r0 to address the call's keyString load (`ldr r1,[r0,r4]`)
 * and then moving keyID into r0, where the image addresses straight off r8.
 * Filed as docs/idioms/a-front-end-hoists-a-base-copy-to-fold-an-argument-load.md.
 * No new source lever; parked unchanged.
 *
 * lane03 (2026-10-01): the dsi/1.1p1 shared-zero hoist is a USE COUNT: the body
 * has five literal zeros (four `return 0` and the KEYF2 strh). Replacing any
 * one of the five with a non-zero literal drops the hoist and leaves 1 B (the
 * altered literal itself), so the 1.1p1 body is right and needs one fewer
 * zero literal. Measured inert: `return keyID` on the new-key path (173 B, the
 * image has `moveq r0,#0`), a shared `fail:` label for any one return (296 B,
 * 1.1p1 does not duplicate the return block), enum-typed/(E) zero on the strh.
 *
 * w3 lane16 (2026-10-01): 1.1p1 is the object's compiler (six dwc_match.o
 * siblings EXACT on 1.1p1, five of them DIFF on ../2.0/base). The 1.1p1 hoist
 * counts BLOCKS holding a zero, not uses: 5 blocks hoist, 4 do not (6 uses in
 * 4 blocks: no hoist; a second zero in an existing block: still hoists).
 * Compare zeros do not count. Inert: house string.h strlen/strcpy (+strcmp),
 * void *value field, casts/enum/static const/inline/local for each zero site,
 * (u16)/0L/(char)/!1/keyID-keyID (all fold early), braces, nesting, else-if,
 * ternary condition, test after the if/else. goto-sharing two returns drops
 * the hoist (strcmp-fail -> new-key return: 300 B / 21 B, layout only) but
 * 1.1p1 never predicates or duplicates a shared return, so the image's five
 * private zero sites need a fifth zero that is not a literal at pool time.
 *
 * w4 (2026-10-01): EXACT on dsi/1.1p1 (the ../2.0/base pin was wrong). Closed
 * by a hidden call argument: DWC_Free takes a third `u32 size` (as in the
 * matched arm9 callers, e.g. func_0205A200) and the call passes 0. That zero
 * argument shares r2 with the KEYF2 strh zero, which stops 1.1p1 from hoisting
 * a shared zero into r4 (toy test: any zero use reachable from the strh in a
 * scratch register breaks the hoist). The image leaves r2 = 0 live into the call.
 */
u8 func_0216CA04(u8 keyID, char *keyString, char *valueSrc)
{
    int index;

    if (keyString == 0 || valueSrc == 0)
        return 0;
    if (keyID >= 0x64 && KEYID(keyID - 0x64) != 0) {
        if (KEYSTR(keyID - 0x64) != 0 && func_020948E0(KEYSTR(keyID - 0x64), keyString) != 0)
            return 0;
    } else {
        keyID = func_02173AD8();
        if (keyID == 0)
            return 0;
    }
    index = keyID - 0x64;
    KEYID(index) = keyID;
    KEYF1(index) = 1;
    KEYF2(index) = 0;
    if (KEYSTR(index) != 0)
        func_0205A1B0(4, KEYSTR(index), 0);
    KEYSTR(index) = func_0205A16C(4, func_0209477C((const u8 *)keyString) + 1);
    if (KEYSTR(index) == 0) {
        func_0216EB68(9, -80001);
        return 0;
    }
    func_02094798(KEYSTR(index), keyString);
    KEYVAL(index) = valueSrc;
    func_0219D158(keyID, KEYSTR(index));
    return keyID;
}













/*
 * sdk:      DWC_GetMatchIntValue (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
int func_0216CB30(int index, char *key, int idefault)
{
    struct SBServer *server;

    if (DWCi_GetMatchCnt() == 0 || func_02059F38() != 0) {
        return idefault;
    }
    server = func_0219F058(DWCi_GetMatchCnt()->sbObj, index);
    if (server != 0) {
        idefault = func_0219E120(server, key, idefault);
    }
    return idefault;
}











/*
 * sdk:      DWC_GetSuspendMatch (dwc_match.o)
 */
int func_0216CB90(void)
{
    int bNew = -1;
    unsigned int bitmap;

    if (!DWCi_GetMatchCnt())
        return 0;
    if (!func_02175FB8())
        return 0;
    bitmap = DWCi_GetMatchCnt()->suspendBitmap;
    bitmap &= DWC_GetAIDBitmap();
    if (!func_02175EB4())
        bitmap &= ~(1 << DWC_GetMyAID());
    if ((bitmap ^ DWC_GetAIDBitmap()) == 0)
        bNew = 1;
    else if ((bitmap & DWC_GetAIDBitmap()) == 0)
        bNew = 0;
    if (bNew != -1)
        DWCi_GetMatchCnt()->suspendMatch = bNew == 1;
    return DWCi_GetMatchCnt()->suspendMatch;
}













/*
 * DWCi_MatchInit (dwc_match.o): seed the match parameter block returned by
 * DWCi_GetMatchCnt(), every field through a fresh getter call.  The +0x5f0/+0x5f4
 * pair is the one place a local reuses one getter result.
 */
int func_0216CC28(int a0, void **pGpObj, void **pGt2Socket, void *gt2Callbacks, char *gameName, char *secretKey, int a6, int a7)
{
    DWCstMatchControl *q;

    func_02175F1C(a0);
    DWCi_GetMatchCnt()->pGpObj = pGpObj;
    DWCi_GetMatchCnt()->pGt2Socket = pGt2Socket;
    DWCi_GetMatchCnt()->gt2Callbacks = gt2Callbacks;
    DWCi_GetMatchCnt()->qr2Obj = 0;
    DWCi_GetMatchCnt()->qr2IP = 0;
    DWCi_GetMatchCnt()->qr2Port = 0;
    DWCi_GetMatchCnt()->sbObj = 0;
    func_02175F4C(0);
    DWCi_GetMatchCnt()->qr2Flag19 = 0;
    DWCi_GetMatchCnt()->profileID = 0;
    DWCi_GetMatchCnt()->gameName = gameName;
    DWCi_GetMatchCnt()->secretKey = secretKey;
    DWCi_GetMatchCnt()->param68c = (u8 *)a6;
    DWCi_GetMatchCnt()->param690 = a7;
    MI_CpuFill8(DWCi_GetMatchCnt()->buf694, 0, 0x40);
    DWCi_GetMatchCnt()->flag6d4 = 0;
    DWCi_GetMatchCnt()->matchedCallback = 0;
    DWCi_GetMatchCnt()->matchedParam = 0;
    DWCi_GetMatchCnt()->evalCallback = 0;
    DWCi_GetMatchCnt()->evalParam = 0;
    DWCi_GetMatchCnt()->serverDownBuff = 0;
    DWCi_GetMatchCnt()->serverDownBase = 0;
    DWCi_GetMatchCnt()->groupID = 0;
    DWCi_GetMatchCnt()->searchGroupIDRetryHostCount = 0;
    DWCi_GetMatchCnt()->connectGroupID = 0;
    DWCi_GetMatchCnt()->qr2MatchTypeExt = 0;
    DWCi_GetMatchCnt()->qr2HostState = 0;
    q = DWCi_GetMatchCnt();
    q->sbUpdateRequestTick = 0;
    DWCi_GetMatchCnt()->flag7c8 = 0;
    DWCi_GetMatchCnt()->flag7d4 = 1;
    DWCi_GetMatchCnt()->cancelFromConnection = 0;
    DWCi_GetMatchCnt()->retryCountMax = 0;
    DWCi_GetMatchCnt()->topologyType = 0;
    func_0217601C();
    func_0217653C();
    func_02173B18();
    return func_0216F388(0);
}













/*
 * notes:    the three callback stubs (0x02174C2C PlayerKey, 0x02174C30 TeamKey, 0x02174CF0 Count) were seeded and catalogued by w7_nm from this function's ABS32 pool words
 *
 * sdk:      DWCi_QR2Startup (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
int func_0216CD8C(int profileID)
{
    int i;
    int qr2Error;

    if (DWCi_GetMatchCnt()->qr2Obj != 0)
        return 0;
    for (i = 0; i < 1; i++) {
        qr2Error = func_0219AEB4(&DWCi_GetMatchCnt()->qr2Obj,
                                 gt2GetSocketSOCKET(*DWCi_GetMatchCnt()->pGt2Socket),
                                 gt2GetLocalPort(*DWCi_GetMatchCnt()->pGt2Socket),
                                 DWCi_GetMatchCnt()->gameName,
                                 DWCi_GetMatchCnt()->secretKey,
                                 1, 1,
                                 func_02174AA0, func_02174C2C, func_02174C30,
                                 func_02174C34, func_02174CF0, func_02174CF8,
                                 0);
        if (qr2Error == 0)
            break;
        func_0219B540(DWCi_GetMatchCnt()->qr2Obj);
        DWCi_GetMatchCnt()->qr2Obj = 0;
        if (qr2Error != 3 || i == 0) {
            func_02173E30(qr2Error);
            return qr2Error;
        }
    }
    DWCi_GetMatchCnt()->qr2IP = 0;
    DWCi_GetMatchCnt()->qr2Port = 0;
    func_0219B1AC(DWCi_GetMatchCnt()->qr2Obj, func_02174D04);
    func_0219B134(DWCi_GetMatchCnt()->qr2Obj, func_02174D28);
    func_0219B170(DWCi_GetMatchCnt()->qr2Obj, func_02174ED0);
    func_02176ABC();
    func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    return qr2Error;
}











void DWCi_ConnectToAnybodyAsync(int topology, unsigned char numEntry, char *addFilter, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *evalCallback, void *evalParam, void *attemptCallback, unsigned char *connectionUserData, void *attemptParam)
{
    int sbError;
    unsigned long addFilterLenMax;
    char filter[511];

    if (g_021AAA20.addFilter != 0) {
        DWC_Free(4, g_021AAA20.addFilter, 0);
        g_021AAA20.addFilter = 0;
    }
    if (addFilter != 0) {
        addFilterLenMax = 0x1ff - func_0216FAD4(filter, -1, 32, 3, 3) - func_0209477C((const u8 *)g_021A2044);
        g_021AAA20.addFilter = DWC_Alloc(4, addFilterLenMax);
        if (g_021AAA20.addFilter == 0) {
            func_0216EB68(9, -80001);
            return;
        }
        MI_CpuCopy8(addFilter, g_021AAA20.addFilter, addFilterLenMax);
        (g_021AAA20.addFilter + addFilterLenMax)[-1] = 0;
    }
    func_0216F5FC(0, numEntry, matchedCallback, matchedParam);
    DWCi_GetMatchCnt()->newClientCallback = newClientCallback;
    DWCi_GetMatchCnt()->newClientParam = newClientParam;
    DWCi_GetMatchCnt()->evalCallback = evalCallback;
    DWCi_GetMatchCnt()->evalParam = evalParam;
    DWCi_GetMatchCnt()->topologyType = topology;
    func_02175560(attemptCallback, connectionUserData, attemptParam);
    func_02175F4C(0x16);
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        DWCi_GetMatchCnt()->sbObj = func_0219EC74(DWCi_GetMatchCnt()->gameName, DWCi_GetMatchCnt()->gameName, DWCi_GetMatchCnt()->secretKey, 0, 20, 1, 0, func_02174058, 0);
    }
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        if (func_02173D9C(5))
            return;
    }
    func_0216F20C(3);
    if (DWCi_GetMatchCnt()->qr2Obj == 0) {
        if (func_0216CD8C(DWCi_GetMatchCnt()->profileID))
            return;
    } else {
        func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    }
    sbError = func_0216F770(DWCi_GetMatchCnt()->profileID);
    func_02173D9C(sbError);
}









void func_0216D138(int topology, u8 numEntry, void *matchedCallback, void *matchedParam, void *newClientCallback, void *newClientParam, void *attemptCallback, u8 *connectionUserData, void *attemptParam)
{
    func_0216F5FC(2, numEntry, matchedCallback, matchedParam);
    DWCi_GetMatchCnt()->newClientCallback = newClientCallback;
    DWCi_GetMatchCnt()->newClientParam = newClientParam;
    DWCi_GetMatchCnt()->topologyType = topology;
    func_02175560(attemptCallback, connectionUserData, attemptParam);
    func_02175F4C(0x16);
    func_0216F20C(6);
    if (func_02173D28() != 0)
        return;
    func_02175F84(2);
    DWCi_GetMatchCnt()->flag7c4 = 1;
    if (DWCi_GetMatchCnt()->qr2Obj == 0) {
        if (func_0216CD8C(DWCi_GetMatchCnt()->profileID) != 0)
            return;
    }
    DWCi_GetMatchCnt()->groupID = func_02175530();
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        DWCi_GetMatchCnt()->sbObj = func_0219EC74(DWCi_GetMatchCnt()->gameName,
                                                  DWCi_GetMatchCnt()->gameName,
                                                  DWCi_GetMatchCnt()->secretKey, 0, 0x14, 1, 0,
                                                  func_02174058, 0);
    }
    func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    func_02173D9C(func_0216F770(DWCi_GetMatchCnt()->profileID));
}








/*
 * sdk:      DWCi_ConnectToGameServerAsync (libdwcmatch.TWL.HYB.a(dwc_match.o))
 */
void func_0216D27C(int topology, int serverPid, void *matchedCallback, void *matchedParam,
                   void *newClientCallback, void *newClientParam, void *attemptCallback,
                   u8 *connectionUserData, void *attemptParam)
{
    DWCstNodeInfo tempNodeInfoBackup;
    DWCstNodeInfo myNodeInfoBackup;
    DWCstNodeInfo serverNodeInfo;
    u8 scResvRetryCount;

    if (DWCi_GetMatchCnt()->connectGroupID != 0) {
        tempNodeInfoBackup = DWCi_GetMatchCnt()->tempNewNodeInfo;
        myNodeInfoBackup = *func_02176344();
        scResvRetryCount = DWCi_GetMatchCnt()->scResvRetryCount;
    }
    func_0216F5FC(3, 0, matchedCallback, matchedParam);
    DWCi_GetMatchCnt()->topologyType = topology;
    if (DWCi_GetMatchCnt()->connectGroupID == 0) {
        MI_CpuFill8(&serverNodeInfo, 0, 0x28);
        func_0217653C();
        DWCi_GetMatchCnt()->tempNewNodeInfo.aid = 0xff;
        DWCi_GetMatchCnt()->tempNewNodeInfo.profileID = serverPid;
    } else {
        DWCi_GetMatchCnt()->tempNewNodeInfo = tempNodeInfoBackup;
        func_0217604C(&myNodeInfoBackup);
        MI_CpuCopy8(myNodeInfoBackup.connUserData, DWCi_GetMatchCnt()->connUserData, 4);
        DWCi_GetMatchCnt()->scResvRetryCount = scResvRetryCount;
    }
    DWCi_GetMatchCnt()->newClientCallback = newClientCallback;
    DWCi_GetMatchCnt()->newClientParam = newClientParam;
    func_02175560(attemptCallback, connectionUserData, attemptParam);
    DWCi_GetMatchCnt()->qr2Flag18 = 1;
    DWCi_GetMatchCnt()->serverProfileID = DWCi_GetMatchCnt()->profileID;
    func_02175F84(1);
    if (DWCi_GetMatchCnt()->connectGroupID == 0)
        func_02175F4C(0x16);
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        DWCi_GetMatchCnt()->sbObj = func_0219EC74(
            DWCi_GetMatchCnt()->gameName,
            DWCi_GetMatchCnt()->gameName,
            DWCi_GetMatchCnt()->secretKey, 0, 0x14, 1, 0, func_02174058, 0);
    }
    if (DWCi_GetMatchCnt()->sbObj == 0) {
        if (func_02173D9C(5) != 0)
            return;
    }
    func_0216F20C(5);
    if (func_02173D28() != 0)
        return;
    if (DWCi_GetMatchCnt()->qr2Obj == 0) {
        if (func_0216CD8C(DWCi_GetMatchCnt()->profileID) != 0)
            return;
    } else {
        func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    }
    if (DWCi_GetMatchCnt()->connectGroupID == 0) {
        func_02173D9C(func_0216F770(DWCi_GetMatchCnt()->profileID));
        return;
    }
    func_0219B490(DWCi_GetMatchCnt()->qr2Obj);
    func_02175F4C(3);
    func_021719D0(serverPid, 0);
    func_021719A4();
}









void DWCi_SendStateChanged(struct qr2_implementation_s *qr2Obj)
{
    if (qr2Obj == 0)
        return;
    qr2_think(qr2Obj);
    if (qr2Obj->userstatechangerequested != 0)
        return;
    switch (DWCi_GetMatchCnt()->qr2MatchType) {
    case 0:
    case 2:
    case 3:
        DWCi_GetMatchCnt();
        break;
    }
}







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
            DWCi_NNCompletedCallback(1, 0, 0, &DWCi_GetMatchCnt()->nnInfo);
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
        g_021AAA20.sbCallbackLevel = 0;
        g_021AAA20.needSbFree = 0;
        g_021AAA20.bInNNThink = 1;
        ServerBrowserThink(DWCi_GetMatchCnt()->sbObj);
        if (g_021AAA20.needSbFree) {
            ServerBrowserFree(DWCi_GetMatchCnt()->sbObj);
            DWCi_GetMatchCnt()->sbObj = 0;
        }
        if (DWCi_GetMatchCnt()->sbObj && ServerBrowserState(DWCi_GetMatchCnt()->sbObj) != 0 &&
            DWCi_GetMatchCnt()->sbUpdateRequestTick && OS_GetTick() > DWCi_GetMatchCnt()->sbUpdateRequestTick) {
            DWCi_StopMatch(6, -85010);
        }
    }

    g_021AAA20.bNNFreeNegotiateList = 0;
    g_021AAA20.bInNNThink = 1;
    DWCi_SendStateChanged(DWCi_GetMatchCnt()->qr2Obj);
    NNThink();
    g_021AAA20.bInNNThink = 0;
    if (g_021AAA20.bNNFreeNegotiateList == 1) {
        g_021AAA20.bNNFreeNegotiateList = 0;
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
    SOCSockAddrIn saddr;

    if (len == 0 || message == 0)
        return 0;
    MIi_CpuClear32(0, &saddr, 8);
    saddr.family = 2;
    saddr.port = (unsigned short)(((port >> 8) & 0xFF) | ((port << 8) & 0xFF00));
    saddr.addr.addr = ip;
    ip = message[0];
    if ((ip == 0xFE && message[1] == 0xFD) || ip == 0x5C) {
        if (DWCi_GetMatchCnt()->qr2Obj != 0)
            func_0219C7C0(DWCi_GetMatchCnt()->qr2Obj, message, len, &saddr);
    } else if (func_020923F0(message, (const u8 *)((char *)&g_021A5A7C), 6) == 0) {
        func_0219AB8C((char *)message, len, &saddr);
    } else {
        return 0;
    }
    return 1;
}






void DWCi_GT2ConnectAttemptCallback(void * userdata, void * connection,
                                    unsigned int ip, unsigned short port,
                                    int latency, unsigned char * message, int len)
{
    int index;
    int remotePid = 0;
    DWCstConnectionInfo * pConInfo;
    DWCstMatchControl * m;
    void ** pGt2Con;

    if (DWCi_GetMatchCnt() != 0 && DWCi_GetMatchCnt()->state == 5)
        return;
    if (DWCi_GetMatchCnt() != 0 && DWCi_GetMatchCnt()->state == 6 &&
        DWCi_GetMatchCnt()->cancelState == 0)
        goto process;
    gt2Reject(connection, g_021A204C, -1);
    return;

process:
    if (message != 0 && len != 0)
        remotePid = strtoul((char *)message, 0, 10);
    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        gt2Reject(connection, g_021A2058, -1);
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_StopResendingMatchCommand();
            DWCi_SetMatchStatus(1);
            return;
        }
        DWCi_StopMatch(6, 0xfffeabc4);
        return;
    }
    if (DWCi_GetMatchCnt()->tempNewNodeInfo.gt2IP == ip) {
        if ((unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00)) ==
            DWCi_GetMatchCnt()->tempNewNodeInfo.gt2Port)
            goto accept;
    }
    if (remotePid == DWCi_GetMatchCnt()->tempNewNodeInfo.profileID) {
        DWCi_GetMatchCnt()->tempNewNodeInfo.gt2IP = ip;
        DWCi_GetMatchCnt()->tempNewNodeInfo.gt2Port = ((port >> 8) & 0xff) | ((port << 8) & 0xff00);
        goto accept;
    }
    gt2Reject(connection, g_021A2064, -1);
    return;

accept:
    DWCi_GetMatchCnt()->nnFinishTime = 0;
    if (gt2Accept(connection, DWCi_GetMatchCnt()->gt2Callbacks) == 0) {
        DWCi_StopMatch(6, 0xfffec5e6);
        return;
    }
    DWCi_StopResendingMatchCommand();
    if (DWCi_GetMatchCnt()->inMeshMaking == 0 && DWCi_NodeInfoList_GetCount() == 1) {
        DWCi_GetMatchCnt()->hostLatency =
            (latency >> 1) >= 0xffff ? 0xffff : (latency >> 1);
    }
    pGt2Con = DWCi_GetGT2ConnectionByIdx(index);
    pConInfo = DWCi_GetConnectionInfoByIdx(index);
    *pGt2Con = connection;
    pConInfo->index = index;
    pConInfo->aid = DWCi_GetMatchCnt()->tempNewNodeInfo.aid;
    pConInfo->profileID = DWCi_GetMatchCnt()->tempNewNodeInfo.profileID;
    DWCi_ResetLastSomeDataRecvTimeByAid(pConInfo->aid);
    gt2SetConnectionData(connection, pConInfo);
    DWCi_PostProcessConnection(2);
}





void DWCi_MakeGT2ConnectString(char *buf, int bufLen)
{
    OS_SNPrintf(buf, bufLen, g_021A207C, DWCi_GetMatchCnt()->profileID);
}




void DWCi_GT2ConnectedCallback(void * connection, int result)
{
    DWCstConnectionInfo * pConInfo;
    void ** pGt2Con;
    char pidStr[24];
    int gt2Result;
    int index;

    if (DWCi_GetMatchCnt() != 0) {
        if (DWCi_GetMatchCnt()->state == 6)
            goto entry;
        if (DWCi_GetMatchCnt()->state == 0xf)
            goto entry;
    }
    if (DWCi_GetMatchCnt()->backupState != 0xf)
        return;
entry:
    if (result != 0) {
        if (DWCi_StopMeshMaking() == 1) {
            DWCi_SetMatchStatus(1);
            return;
        }
        if (DWCi_GetMatchCnt()->backupState == 0xf) {
            DWCi_ClearMeshMakingTempInfo();
            return;
        }
        if (result == 5)
            return;
        if (result == 6) {
            DWCi_GetMatchCnt()->gt2RetryCount++;
            if (DWCi_GetMatchCnt()->gt2RetryCount > 5) {
                DWCi_GetMatchCnt()->gt2RetryCount = 0;
                DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID);
                return;
            }
            DWCi_MakeGT2ConnectString(pidStr, 0x18);
            gt2Result = gt2Connect(*(void **)DWCi_GetMatchCnt()->pGt2Socket, 0,
                gt2AddressToString(DWCi_GetMatchCnt()->tempNewNodeInfo.gt2IP,
                                   DWCi_GetMatchCnt()->tempNewNodeInfo.gt2Port, 0),
                (u8 *)pidStr, -1, 0x1388, DWCi_GetMatchCnt()->gt2Callbacks, 0);
            if (gt2Result == 1) {
                DWCi_HandleGT2Error(gt2Result);
                return;
            }
            if (gt2Result == 0)
                return;
            DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID);
            return;
        }
        DWCi_CancelPreConnectedServerProcess(DWCi_GetMatchCnt()->tempNewNodeInfo.profileID);
        return;
    }

    index = DWCi_GT2GetConnectionListIdx();
    if (index == -1) {
        DWCi_StopMatch(6, 0xfffeabc4);
        return;
    }
    pGt2Con = DWCi_GetGT2ConnectionByIdx(index);
    pConInfo = DWCi_GetConnectionInfoByIdx(index);
    *pGt2Con = connection;
    pConInfo->index = index;
    if (DWCi_GetMatchCnt()->backupState != 0xf) {
        pConInfo->aid = DWCi_GetMatchCnt()->tempNewNodeInfo.aid;
        pConInfo->profileID = DWCi_GetMatchCnt()->tempNewNodeInfo.profileID;
    } else {
        pConInfo->aid = DWCi_GetMatchCnt()->backupAid;
        pConInfo->profileID = DWCi_GetMatchCnt()->backupProfileID;
    }
    DWCi_ResetLastSomeDataRecvTimeByAid(pConInfo->aid);
    gt2SetConnectionData(connection, pConInfo);
    if (DWCi_GetMatchCnt()->state == 0xf ||
        DWCi_GetMatchCnt()->backupState == 0xf)
        DWCi_PostProcessConnection(0);
    else
        DWCi_PostProcessConnection(1);
}





/*
 * sdk:      DWCi_MatchGPRecvBuddyMsgCallback (dwc_match.o)
 */
extern void func_0216EAB8(int unused, int profileID, char *message)
{
    unsigned long data[128];
    int msgLen;
    int dataLen;

    msgLen = strlen(message);
    if (msgLen - 1 == 0) {
        dataLen = 0;
    } else {
        int len = func_02059CBC(message + 1, msgLen - 1, data, 512);

        if (len == -1)
            return;
        if (len % 4 != 0)
            return;
        if (len > 512)
            return;
        dataLen = len / 4;
    }
    func_021702A0(*(unsigned char *)message, profileID, 0, 0, data, dataLen);
}






/*
 * Arms both module flags.
 */
void func_0216EB48(void)
{
    DWCi_GetMatchCnt()->cmdCnt.command = 0xff;
    DWCi_GetMatchCnt()->cmdCnt.count = 0;
}






/*
 * DWCi_StopMatch: closes every connection, records the error and reports the failure to the match callback.
 */
void func_0216EB68(int error, int errorCode)
{
    int self;
    int isServer;

    if (DWCi_GetMatchCnt() == 0 || error == 0) {
        return;
    }
    func_02172E7C();
    DWCi_SetError(error, errorCode);
    self = 1;
    func_0216F20C(self);
    if (DWCi_GetMatchCnt()->peerProfileID != 0) {
        self = 0;
    }
    (DWCi_GetMatchCnt()->matchedCallback)(
        error, 0, self, DWCi_GetMatchCnt()->qr2MatchType == 2,
        func_02169038(DWCi_GetMatchCnt()->peerProfileID), DWCi_GetMatchCnt()->matchedParam);
    func_0216F6C0();
}



void DWCi_ClearQR2Key(void)
{
    if (DWC_GetState() != 3)
        return;
    DWCi_GetMatchCnt()->qr2NumEntry = 0;
    DWCi_GetMatchCnt()->groupID = 0;
    qr2_send_statechanged(DWCi_GetMatchCnt()->qr2Obj);
}




void DWCi_ProcessMatchSynPacket(unsigned char aid, unsigned short type, unsigned char *data)
{
    if (DWCi_IsFullMesh())
        DWCi_ProcessMatchSynPacketSub_FullMesh(aid, type, data);
    else
        DWCi_ProcessMatchSynPacketSub_Hybrid(aid, type, data);
}


void func_0216EC84(unsigned char aid, unsigned short type, unsigned char *data)
{
    DWCstNodeInfo tempNodeInfo;
    DWCstNodeInfo tempNodeInfo2;
    int i;
    u32 *entry;
    int clientCount;

    switch (type) {
    case 2:
        if (MC()->state != 1)
            return;
        if (*(u32 *)data == 1) {
            MC()->peerProfileID = 0;
            MC()->tempNewClientInfo.profileID = 0;
            {
                u32 v = *(u32 *)(data + 4);

                MC()->flag7c8 = v;
            }
            if (DWCi_IsFullMesh())
                DWCi_NodeInfoList_InsertToTop(&MC()->tempNewNodeInfo);
        } else {
            u32 w;
            u32 *p = (u32 *)data;

            MI_CpuFill8(&tempNodeInfo, 0, sizeof(tempNodeInfo));
            w = p[1];
            tempNodeInfo.aid = (u8)w;
            tempNodeInfo.hasPrivateAddress = (u8)(w >> 16);
            tempNodeInfo.profileID = p[2];
            tempNodeInfo.publicInetAddress = p[3];
            tempNodeInfo.privateInetAddress = p[4];
            tempNodeInfo.publicQueryPort = (u16)(p[5] >> 16);
            tempNodeInfo.privateQueryPort = (u16)p[5];
            memcpy(&tempNodeInfo.connUserData, data + 0x18, 4);
            MC()->tempNewClientInfo = tempNodeInfo;
            w = p[7];
            MC()->flag7c8 = w;
            MC()->peerProfileID = tempNodeInfo.profileID;
        }
        {
            int latency;

            if (DWCi_NodeInfoList_GetCount() == 1)
                latency = 0x15f90;
            else
                latency = DWCi_NodeInfoList_GetCount() * 0x2ee0;
            MC()->clWaitTime = latency;
        }
        MC()->clWaitTimeoutCount = 0;
        DWCi_SetMatchStatus(8);
        DWCi_SendMatchSynPacket(aid, 3);
        return;
    case 3: {
        u16 onewayGT2Latency;
        u32 bitmask;

        if (MC()->state == 0x13) {
            onewayGT2Latency = (u16)(data[0] | (data[1] << 8));
            MC()->synAckBitmap |= 1 << aid;
            if (MC()->hostLatency < onewayGT2Latency)
                MC()->hostLatency = onewayGT2Latency;
            bitmask = DWCi_GetAIDBitmask(0);
            if (bitmask != MC()->synAckBitmap)
                return;
            {
                DWCstMatchControl *mc = MC();

                mc->flag7c8 = DWCi_GetMathRand32(0 - 2) + 1;
            }
            DWCi_SendTypeMatchAck();
            MC()->synResendCount = 0;
            {
                unsigned long long tick = OS_GetTick();

                MC()->synAckTick = tick;
            }
        } else {
            DWCi_SendMatchSynPacket(aid, 4);
        }
        return;
    }
    case 4:
        if (MC()->state != 8)
            return;
        clientCount = *(int *)data;
        if (clientCount != 0) {
            u32 v;

            for (i = 0; i < clientCount; i++) {
                entry = (u32 *)(data + 4) + (clientCount - 1 - i) * 6;

                MI_CpuFill8(&tempNodeInfo2, 0, sizeof(tempNodeInfo2));
                tempNodeInfo2.aid = (u8)entry[0];
                tempNodeInfo2.hasPrivateAddress = (u8)(entry[0] >> 16);
                tempNodeInfo2.profileID = entry[1];
                tempNodeInfo2.publicInetAddress = entry[2];
                tempNodeInfo2.privateInetAddress = entry[3];
                tempNodeInfo2.privateQueryPort = (u16)entry[4];
                tempNodeInfo2.publicQueryPort = (u16)(entry[4] >> 16);
                memcpy(&tempNodeInfo2.connUserData, (u8 *)entry + 0x14, 4);
                DWCi_NodeInfoList_InsertToTop(&tempNodeInfo2);
            }
            v = ((u32 *)data + clientCount * 6)[1];
            MC()->flag7c8 = v;
            DWCi_NodeInfoList_InsertToTop(&MC()->tempNewNodeInfo);
            DWCi_TempNewNodeInfo_Clear();
        } else {
            u32 v = *(u32 *)(data + 4);

            MC()->flag7c8 = v;
        }
        DWCi_PostProcessConnection(3);
        return;
    default:
        return;
    }
}
