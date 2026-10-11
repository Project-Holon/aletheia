#ifndef ALETHEIA_OV009_DWC_MATCH_TYPES_H
#define ALETHEIA_OV009_DWC_MATCH_TYPES_H
/*
 * DWC match module (ov009, dwc_match.o): the match control block returned by
 * DWCi_GetMatchCnt (0x02175F3C), the node info record, the match-key table and
 * the prototypes unit_0216C858 shares.  Field offsets checked against every
 * view the parts used.  Names are provisional.
 */

#include "qr2_types.h"
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_NNThinkGlobal.h"
#include "../../matched/include/G_MatchAnchorA.h"
#include "../../matched/include/G_Magic6.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

struct SBServer;
struct SOCSockAddrIn;

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

typedef struct DWCstConnectionInfo {
    u8 index;                       /* +0x00 */
    u8 aid;                         /* +0x01 */
    u8 pad2[2];
    u32 profileID;                  /* +0x04 */
} DWCstConnectionInfo;

typedef struct DWCstGameMatchKeyData {
    u8 keyID;                       /* +0x00 */
    u8 isStr;                       /* +0x01 */
    u16 pad;                        /* +0x02 */
    char *keyString;                /* +0x04 */
    void *value;                    /* +0x08 */
} DWCstGameMatchKeyData;

typedef void (*MatchedCallback)(int error, int cancel, int self, int isServer, int index, void *param);

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
    void *gt2Callbacks;             /* +0x008 */
    u8 gt2RetryCount;               /* +0x00C */
    u8 pad00d[3];
    qr2_implementation_s *qr2Obj;   /* +0x010 */
    u8 qr2MatchType;                /* +0x014 */
    u8 qr2MatchTypeExt;             /* +0x015 */
    u8 qr2HostState;                /* +0x016 */
    u8 qr2NumEntry;                 /* +0x017 */
    u8 qr2Flag18;                   /* +0x018 */
    u8 qr2Flag19;                   /* +0x019 */
    u8 pad01a[2];
    u32 suspendBitmap;              /* +0x01C */
    u8 pad020[8];
    int suspendMatch;               /* +0x028 */
    u8 pad02c[0x554 - 0x2C];
    DWCstNodeInfo tempNewNodeInfo;  /* +0x554 */
    DWCstNodeInfo tempNewClientInfo;/* +0x57C */
    int inMeshMaking;               /* +0x5A4 */
    u32 backupState;                /* +0x5A8 */
    u32 backupProfileID;            /* +0x5AC */
    u8 pad5b0[0x5C2 - 0x5B0];
    u8 backupAid;                   /* +0x5C2 */
    u8 pad5c3[0x5D4 - 0x5C3];
    u16 qr2Port;                    /* +0x5D4 */
    u8 pad5d6[2];
    u32 qr2IP;                      /* +0x5D8 */
    int serverProfileID;            /* +0x5DC */
    struct SBServer *sbObj;         /* +0x5E0 */
    int sbUpdateFlag;               /* +0x5E4 */
    u64 sbUpdateTick;               /* +0x5E8 */
    u64 sbUpdateRequestTick;        /* +0x5F0 */
    u8 pad5f8[0x600 - 0x5F8];
    u64 nnFailedTime;               /* +0x600 */
    u64 nnFinishTime;               /* +0x608 */
    u8 nnInfo[0xC];                 /* +0x610 */
    int state;                      /* +0x61C */
    u8 pad620[0x62A - 0x620];
    u8 cancelState;                 /* +0x62A */
    u8 scResvRetryCount;            /* +0x62B */
    u8 synResendCount;              /* +0x62C */
    u8 cancelSynResendCount;        /* +0x62D */
    u8 clWaitTimeoutCount;          /* +0x62E */
    u8 needServerPoll;              /* +0x62F */
    u16 hostLatency;                /* +0x630 */
    u8 pad632[0x638 - 0x632];
    int cmdResendFlag;              /* +0x638 */
    u64 cmdResendTick;              /* +0x63C */
    u32 cmdTimeoutTime;             /* +0x644 */
    u64 cmdTimeoutStartTick;        /* +0x648 */
    u32 synAckBitmap;               /* +0x650 */
    u8 pad654[0x658 - 0x654];
    u64 synAckTick;                 /* +0x658 */
    u8 pad660[0x668 - 0x660];
    u64 closedTime;                 /* +0x668 */
    u64 clWaitTime;                 /* +0x670 */
    int profileID;                  /* +0x678 */
    int reqProfileID;               /* +0x67C */
    int peerProfileID;              /* +0x680 */
    char *gameName;                 /* +0x684 */
    char *secretKey;                /* +0x688 */
    int param68c;                   /* +0x68C */
    int param690;                   /* +0x690 */
    u8 buf694[0x40];                /* +0x694 */
    int flag6d4;                    /* +0x6D4 */
    DWCstMatchCommandControl cmdCnt;/* +0x6D8 */
    MatchedCallback matchedCallback;/* +0x770 */
    void *matchedParam;             /* +0x774 */
    void *newClientCallback;        /* +0x778 */
    void *newClientParam;           /* +0x77C */
    void *evalCallback;             /* +0x780 */
    void *evalParam;                /* +0x784 */
    u32 serverDownBuff;             /* +0x788 */
    u32 serverDownBase;             /* +0x78C */
    u32 groupID;                    /* +0x790 */
    u8 searchGroupIDRetryHostCount; /* +0x794 */
    u8 pad795[3];
    int connectGroupID;             /* +0x798 */
    u8 serverDownQueryCount;        /* +0x79C */
    u8 serverDownNakCount;          /* +0x79D */
    u8 pad79e[2];
    u64 serverPollingTime;          /* +0x7A0 */
    u8 serverFind;                  /* +0x7A8 */
    u8 pad7a9[3];
    u32 serverBrowserUpdateCount;   /* +0x7AC */
    int topologyType;               /* +0x7B0 */
    u8 denyReason;                  /* +0x7B4 */
    u8 cancelFromConnection;        /* +0x7B5 */
    u8 retryCountMax;               /* +0x7B6 */
    u8 pad7b7[5];
    u8 connUserData[4];             /* +0x7BC */
    u8 pad7c0[4];
    int flag7c4;                    /* +0x7C4 */
    u32 flag7c8;                    /* +0x7C8 */
    u8 pad7cc[0x7D4 - 0x7CC];
    int flag7d4;                    /* +0x7D4 */
} DWCstMatchControl;

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
extern int func_0216B908(void);
extern int func_02175EB4(void);
extern unsigned char func_0216B838(void);
extern void func_02175F1C(int a0);
extern void func_02175F4C(int a0);
extern void func_0217601C(void);
extern void func_0217653C(void);
extern void func_02173B18(void);
extern int func_0216F388(int a0);
extern int func_02195E60(const int *p);
extern unsigned short func_02195E40(const unsigned short *p);
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

extern void func_02082BCC(void *p, int v, int n);
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

#endif
