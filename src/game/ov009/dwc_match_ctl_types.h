#ifndef OV009_DWC_MATCH_CTL_TYPES_H
#define OV009_DWC_MATCH_CTL_TYPES_H
/*
 * DWC match control block (ov009, dwc_match.o) as the 23 parts of
 * unit_0216F014 see it: the block returned by DWCi_GetMatchCnt (0x02175F3C),
 * the node record, the match-key slot and the NNThink global. One definition
 * per object; field names follow dwc_match_types.h where that header names the
 * same offset. Offsets were checked against every view the parts had.
 */

#ifndef OV009_DWC_BASIC_TYPES
#define OV009_DWC_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
#endif

#include "../../matched/include/G_NNThinkGlobal.h"

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

/* One game match key slot, 12 bytes (array of 0x9A at 0x021AAA40). */
typedef struct DWCstGameMatchKeyData {
    u8 keyID;                       /* +0x00 */
    u8 pad01[3];
    void *value;                    /* +0x04 */
    int type;                       /* +0x08 */
} DWCstGameMatchKeyData;

/* Server poll packet payload (DWCi_ProcessMatchPollingPacket argument). */
typedef struct {
    int pid;
    unsigned int bitmap;
    int id;
} Poll;

typedef void (*MatchedCallback)(int error, int cancel, int self, int isServer, int index, void *param);
typedef void (*DWCMatchedSCCallback)(int index, void *param);

typedef struct DWCstNNInfo {
    u8 clientindex;                 /* +0x00 */
    u8 f_01;                        /* +0x01 */
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
    u8 f_00D;                       /* +0x00D */
    u8 pad00E[2];
    void *qr2Obj;                   /* +0x010 */
    u8 qr2MatchType;                /* +0x014 */
    u8 qr2MatchTypeExt;             /* +0x015 */
    u8 qr2HostState;                /* +0x016 */
    u8 qr2NumEntry;                 /* +0x017 */
    u8 qr2Flag18;                   /* +0x018 */
    u8 pad019[3];
    u32 suspendBitmap;              /* +0x01C */
    u64 f_020;                      /* +0x020 */
    u8 pad028[0x02C - 0x028];
    int suspendRequest;             /* +0x02C */
    u8 f_030;                       /* +0x030 */
    u8 pad031[0x034 - 0x031];
    void (*suspendCallback)(int, int, void *); /* +0x034 */
    void *suspendResultParam;       /* +0x038 */
    u64 suspendStartTick;           /* +0x03C */
    int suspendRestart;             /* +0x044 */
    int f_048;                      /* +0x048 */
    u8 pad04C[0x050 - 0x04C];
    int nodeCount;                  /* +0x050 */
    DWCstNodeInfo nodeInfoList[32]; /* +0x054 */
    DWCstNodeInfo tempNewNodeInfo;  /* +0x554 */
    DWCstNodeInfo tempNewClientInfo;/* +0x57C */
    int inMeshMaking;               /* +0x5A4 */
    u32 backupState;                /* +0x5A8 */
    u32 backupProfileID;            /* +0x5AC */
    u8 pad5B0[0x5D4 - 0x5B0];
    u16 qr2Port;                    /* +0x5D4 */
    u8 pad5D6[2];
    u32 qr2IP;                      /* +0x5D8 */
    int serverProfileID;            /* +0x5DC */
    void *sbObj;                    /* +0x5E0 */
    int sbUpdateFlag;               /* +0x5E4 */
    u64 sbUpdateTick;               /* +0x5E8 */
    u64 sbUpdateRequestTick;        /* +0x5F0 */
    u8 f_5F8;                       /* +0x5F8 */
    u8 nnFailureCount;              /* +0x5F9 */
    u16 f_5FA;                      /* +0x5FA */
    u32 f_5FC;                      /* +0x5FC */
    u64 nnFailedTime;               /* +0x600 */
    u64 nnFinishTime;               /* +0x608 */
    DWCstNNInfo nnInfo;             /* +0x610 */
    int state;                      /* +0x61C */
    u8 linkProgress;                /* +0x620 */
    u8 f_621;                       /* +0x621 */
    u8 pad622[0x628 - 0x622];
    u8 f_628;                       /* +0x628 */
    u8 closeState;                  /* +0x629 */
    u8 cancelState;                 /* +0x62A */
    u8 scResvRetryCount;            /* +0x62B */
    u8 synResendCount;              /* +0x62C */
    u8 cancelSynResendCount;        /* +0x62D */
    u8 clWaitTimeoutCount;          /* +0x62E */
    u8 needServerPoll;              /* +0x62F */
    u16 hostLatency;                /* +0x630 */
    u16 f_632;                      /* +0x632 */
    int f_634;                      /* +0x634 */
    int cmdResendFlag;              /* +0x638 */
    u64 cmdResendTick;              /* +0x63C */
    u32 cmdTimeoutTime;             /* +0x644 */
    u64 cmdTimeoutStartTick;        /* +0x648 */
    u32 synAckBitmap;               /* +0x650 */
    int f_654;                      /* +0x654 */
    u64 synAckTick;                 /* +0x658 */
    u64 f_660;                      /* +0x660 */
    u64 closedTime;                 /* +0x668 */
    u64 clWaitTime;                 /* +0x670 */
    int profileID;                  /* +0x678 */
    int reqProfileID;               /* +0x67C */
    int peerProfileID;              /* +0x680 */
    char *gameName;                 /* +0x684 */
    char *secretKey;                /* +0x688 */
    u8 *f_68C;                      /* +0x68C */
    int param690;                   /* +0x690 */
    u8 buf694[0x40];                /* +0x694 */
    int flag6d4;                    /* +0x6D4 */
    DWCstMatchCommandControl cmdCnt;/* +0x6D8 */
    MatchedCallback matchedCallback;/* +0x770 */
    void *matchedParam;             /* +0x774 */
    DWCMatchedSCCallback newClientCallback; /* +0x778 */
    void *newClientParam;           /* +0x77C */
    void *evalCallback;             /* +0x780 */
    void *evalParam;                /* +0x784 */
    u32 serverDownBuff;             /* +0x788 */
    u32 serverDownBase;             /* +0x78C */
    u32 groupID;                    /* +0x790 */
    int searchGroupIDRetryHostCount;/* +0x794 */
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
    int (*f_7B8)(unsigned char *, int); /* +0x7B8 */
    u32 f_7BC;                      /* +0x7BC */
    int f_7C0;                      /* +0x7C0 */
    int flag7c4;                    /* +0x7C4 */
    u32 flag7c8;                    /* +0x7C8 */
    u64 f_7CC;                      /* +0x7CC */
    int f_7D4;                      /* +0x7D4 */
} DWCstMatchControl;

/* Same function (0x02175F3C), two names. */
extern DWCstMatchControl *DWCi_GetMatchCnt(void);
extern DWCstMatchControl *func_02175F3C(void);

#endif
