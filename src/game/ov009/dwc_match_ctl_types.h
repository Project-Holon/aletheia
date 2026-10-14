#ifndef OV009_DWC_MATCH_CTL_TYPES_H
#define OV009_DWC_MATCH_CTL_TYPES_H
/*
 * DWC match control block (ov009, dwc_match.o): the block returned by
 * DWCi_GetMatchCnt (0x02175F3C), the node record, the connection record, the
 * match-key slot and the NNThink global. One definition per object, shared by
 * dwc_match_1, dwc_match_3 and dwc_match_13.
 */

#if !defined(OV009_DWC_BASIC_TYPES) && !defined(ALETHEIA_OV009_DWC_LOGIN_TYPES_H)
#define OV009_DWC_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
#endif

#include "qr2_types.h"
#include "../../matched/include/G_NNThinkGlobal.h"

struct SBServer;

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

/* One game match key slot, 12 bytes (array of 0x9A at 0x021AAA40). */
typedef struct DWCstGameMatchKeyData {
    u8 keyID;                       /* +0x00 */
    u8 isStr;                       /* +0x01 */
    u16 pad;                        /* +0x02 */
    char *keyString;                /* +0x04 */
    void *value;                    /* +0x08 */
} DWCstGameMatchKeyData;

/* Server poll packet payload (DWCi_ProcessMatchPollingPacket argument). */
typedef struct {
    int pid;
    unsigned int bitmap;
    int id;
} Poll;

typedef void (*MatchedCallback)(int error, int cancel, int self, int isServer, int index, void *param);
typedef void (*DWCMatchedSCCallback)(int index, void *param);
typedef int (*DWCEvalCallback)(int index, void *param);

typedef struct DWCstNNInfo {
    u8 clientindex;                 /* +0x00 */
    u8 retryCount;                        /* +0x01 */
    u16 port;                       /* +0x02 */
    int ip;                         /* +0x04 */
    int cookie;                     /* +0x08 */
} DWCstNNInfo;

typedef struct DWCstMatchCommandControl {
    u8 command;                     /* +0x00 */
    u8 count;                       /* +0x01 */
    u16 port;                       /* +0x02 */
    u32 ip;                         /* +0x04 */
    u32 data[32];                   /* +0x08 */
    int profileID;                  /* +0x88 */
    int len;                        /* +0x8C */
    u64 sendTime;                   /* +0x90 */
} DWCstMatchCommandControl;

typedef struct DWCstMatchControl {
    void **pGpObj;                  /* +0x000 */
    void **pGt2Socket;              /* +0x004 */
    void *gt2Callbacks;             /* +0x008 */
    u8 gt2RetryCount;               /* +0x00C */
    u8 connectionEstablished;                       /* +0x00D */
    u8 pad00E[2];
    qr2_implementation_s *qr2Obj;   /* +0x010 */
    u8 qr2MatchType;                /* +0x014 */
    u8 qr2MatchTypeExt;             /* +0x015 */
    u8 qr2HostState;                /* +0x016 */
    u8 qr2NumEntry;                 /* +0x017 */
    u8 qr2Flag18;                   /* +0x018 */
    u8 qr2Flag19;                   /* +0x019 */
    u8 pad01A[2];
    u32 suspendBitmap;              /* +0x01C */
    u64 suspendRequestTick;                      /* +0x020 */
    int suspendMatch;               /* +0x028 */
    int suspendRequest;             /* +0x02C */
    u8 suspendReqPending;                       /* +0x030 */
    u8 pad031[0x034 - 0x031];
    void (*suspendCallback)(int, int, void *); /* +0x034 */
    void *suspendResultParam;       /* +0x038 */
    u64 suspendStartTick;           /* +0x03C */
    int suspendRestart;             /* +0x044 */
    int suspendActive;                      /* +0x048 */
    u8 qr2ShutdownReq;              /* +0x04C */
    u8 pad04D[0x050 - 0x04D];
    int nodeCount;                  /* +0x050 */
    DWCstNodeInfo nodeInfoList[32]; /* +0x054 */
    DWCstNodeInfo tempNewNodeInfo;  /* +0x554 */
    DWCstNodeInfo tempNewClientInfo;/* +0x57C */
    int inMeshMaking;               /* +0x5A4 */
    u32 backupState;                /* +0x5A8 */
    u32 backupProfileID;            /* +0x5AC */
    u8 pad5B0[0x5C2 - 0x5B0];
    u8 backupAid;                   /* +0x5C2 */
    u8 pad5C3[0x5D4 - 0x5C3];
    u16 qr2Port;                    /* +0x5D4 */
    u8 pad5D6[2];
    u32 qr2IP;                      /* +0x5D8 */
    int serverProfileID;            /* +0x5DC */
    void *sbObj;                    /* +0x5E0 */
    int sbUpdateFlag;               /* +0x5E4 */
    u64 sbUpdateTick;               /* +0x5E8 */
    u64 sbUpdateRequestTick;        /* +0x5F0 */
    u8 nnSameCookieCount;                       /* +0x5F8 */
    u8 nnFailureCount;              /* +0x5F9 */
    u16 nnCookieSeed;                      /* +0x5FA */
    u32 nnLastCookie;                      /* +0x5FC */
    u64 nnFailedTime;               /* +0x600 */
    u64 nnFinishTime;               /* +0x608 */
    DWCstNNInfo nnInfo;             /* +0x610 */
    int state;                      /* +0x61C */
    u8 linkProgress;                /* +0x620 */
    u8 connectCursor;                       /* +0x621 */
    u8 pad622[0x628 - 0x622];
    u8 replyWaiting;                       /* +0x628 */
    u8 closeState;                  /* +0x629 */
    u8 cancelState;                 /* +0x62A */
    u8 scResvRetryCount;            /* +0x62B */
    u8 synResendCount;              /* +0x62C */
    u8 cancelSynResendCount;        /* +0x62D */
    u8 clWaitTimeoutCount;          /* +0x62E */
    u8 needServerPoll;              /* +0x62F */
    u16 hostLatency;                /* +0x630 */
    u16 maxCancelLatency;                      /* +0x632 */
    int connectNonce;                      /* +0x634 */
    int cmdResendFlag;              /* +0x638 */
    u64 cmdResendTick;              /* +0x63C */
    u32 cmdTimeoutTime;             /* +0x644 */
    u64 cmdTimeoutStartTick;        /* +0x648 */
    u32 synAckBitmap;               /* +0x650 */
    int cancelAckBitmap;                      /* +0x654 */
    u64 synAckTick;                 /* +0x658 */
    u64 cancelStartTick;                      /* +0x660 */
    u64 closedTime;                 /* +0x668 */
    u64 clWaitTime;                 /* +0x670 */
    int profileID;                  /* +0x678 */
    int reqProfileID;               /* +0x67C */
    int peerProfileID;              /* +0x680 */
    char *gameName;                 /* +0x684 */
    char *secretKey;                /* +0x688 */
    u8 *friendKeyList;                   /* +0x68C */
    int friendKeyListLen;                   /* +0x690 */
    u8 friendListIndex[0x40];                /* +0x694 */
    int friendListIndexCount;                    /* +0x6D4 */
    DWCstMatchCommandControl cmdCnt;/* +0x6D8 */
    MatchedCallback matchedCallback;/* +0x770 */
    void *matchedParam;             /* +0x774 */
    DWCMatchedSCCallback newClientCallback; /* +0x778 */
    void *newClientParam;           /* +0x77C */
    DWCEvalCallback evalCallback;   /* +0x780 */
    void *evalParam;                /* +0x784 */
    u32 serverDownBuff;             /* +0x788 */
    u32 serverDownBase;             /* +0x78C */
    u32 groupID;                    /* +0x790 */
    u8 searchGroupIDRetryHostCount; /* +0x794 */
    u8 pad795[3];
    int connectGroupID;             /* +0x798 */
    u8 serverDownQueryCount;        /* +0x79C */
    u8 serverDownNakCount;          /* +0x79D */
    u8 pad79E[2];
    u64 serverPollingTime;          /* +0x7A0 */
    u8 serverFind;                  /* +0x7A8 */
    u8 pad7A9[3];
    u32 serverBrowserUpdateCount;   /* +0x7AC */
    int topologyType;               /* +0x7B0 */
    u8 denyReason;                  /* +0x7B4 */
    u8 cancelFromConnection;        /* +0x7B5 */
    u8 retryCountMax;               /* +0x7B6 */
    u8 pad7B7;
    int (*attemptCallback)(unsigned char *, int); /* +0x7B8 */
    u8 connUserData[4];             /* +0x7BC */
    int attemptParam;                      /* +0x7C0 */
    int isFirstServer;                    /* +0x7C4 */
    u32 matchSessionID;                    /* +0x7C8 */
    u64 suspendRetryDelayMs;                      /* +0x7CC */
    int serverLockEnabled;                    /* +0x7D4 */
} DWCstMatchControl;

typedef struct DWCstBinaryMessageHeader {
    char identifier[4];
    unsigned int version;
    unsigned char command;
    unsigned char size;
    unsigned short qr2Port;
    unsigned int qr2IP;
    int profileID;
} DWCstBinaryMessageHeader;

typedef struct DWCstBinaryMessage {
    DWCstBinaryMessageHeader header;
    unsigned int data[32];
} DWCstBinaryMessage;

extern DWCstMatchControl *DWCi_GetMatchCnt(void);

#endif
