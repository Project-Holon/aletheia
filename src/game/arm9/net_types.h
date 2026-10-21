/*
 * Types shared by net.c and net_irc_wireless.c (the two halves of the
 * network core).  Needs u8, u16, u32 from the including file.
 */
#ifndef NET_TYPES_H
#define NET_TYPES_H

#include "../types.h"

struct GFLNetSession;

/* Callback that gets the session's user argument (the caller's work pointer). */
typedef void (*GFLNetUserFunc)(void *userArg);

/* Limits of the handle table (assert strings "netID < GFL_NET_HANDLE_MAX" and
 * "netID!=GFL_NET_NETID_SERVER" in net_handle.c). */
#define GFL_NET_MACHINE_MAX 8
#define GFL_NET_HANDLE_MAX 9
#define GFL_NET_NETID_SERVER 0xff

/* What a member tells us about itself (0x10 bytes, one per member). */
typedef struct NetMemberRec {
    u8 ownMac[6];            /* our own MAC address */
    u8 peerMac[6];           /* the member's MAC address */
    u8 netID;
    u8 active;               /* the record holds a joined member */
    u8 peerKey;              /* game kind or link flags the member sent */
    u8 ownKey;
} NetMemberRec;

/* One armed timing request of a handle. */
typedef struct NetTimingReq {
    u8 timingNo;
    u8 armed;
} NetTimingReq;

/* One entry of the session's handle table (0x50 bytes, nine entries). */
typedef struct GFLNetHandle {
    void *workBuf;           /* freed when the handle is reset */
    u32  workSize;
    NetMemberRec *memberRec[GFL_NET_HANDLE_MAX]; /* kept across a reset; the last one is never allocated */
    NetTimingReq timingReq[GFL_NET_MACHINE_MAX];
    u8  reserved3C[2];
    u16 notifiedMask;        /* members already sent the join record */
    u16 memberMask;          /* one bit per netID */
    u8  reserved42[2];
    u16 connectFlags;
    u16 tag;
    u8  netID;
    u8  isRemote;
    u8  state;
    u8  pad4B[3];
    u8  joinPhase;
    u8  pad4F;
} GFLNetHandle;

/* The caller's 0x70-byte initialisation block; the session starts with a copy. */
typedef struct GFLNetInitializeStruct {
    struct NetCommandEntry *recvFuncTable;
    u32   recvFuncTableNum;
    void (*connectFunc)(void *userArg, u32 netID);
    void (*disconnectFunc)(int netID, u32 userArg);
    u32  (*negotiationFunc)(void *userArg);
    u32  (*negotiationSizeFunc)(void *userArg);
    void *(*getBeaconDataFunc)(void *arg);
    void *(*getBeaconSizeFunc)(void *arg);
    int  (*compareBeaconFunc)(u8 gameKind, u8 beaconKind, u32 userData);
    void (*stateChangeFunc)(u32 handle, u32 state, void *userArg);
    void (*errorStateFunc)(u32 handle, u32 state, void *userArg);
    void (*connectEndFunc)(void *userArg);
    void (*deviceReadyFunc)(void *userArg);
    u8    reserved34[8];
    void (*deleteFriendFunc)(u32 deletedIndex, u32 srcIndex, void *userArg);
    u32  (*getFriendListFunc)(void *userArg);
    u32  (*getWifiUserDataFunc)(void *userArg);
    u32   heapSize;
    u8    reserved4C[4];
    u32   ggid;
    u16   parentHeapId;
    u16   heapId;
    u16   wifiHeapId;
    u16   beaconHeapId;
    u16   iconX;
    u16   iconY;
    u8    maxConnectNum;
    u8    childSendSize;
    u8    friendListNum;
    u8    reserved63;
    u8    bMPMode;
    u8    bNetType;
    u8    bRenewTgid;
    u8    gameKind;
    u8    reserved68[4];
    u16   parentSendSize;
    u16   linkExtraFlags;
} GFLNetInitializeStruct;

/*
 * Per-mode device table returned by the mode lookup (NET_DEVICE_TABLE_Select), 51 word
 * slots. The Wi-Fi device (ov009), the wireless device (ov014) and the IRC
 * device (ov015) each fill their own subset; an unused slot is null or points
 * at a constant-return stub. Slot numbers are word indices (offset / 4).
 */
typedef struct GFLNetModeOps {
    void (*initLibrary)(u32 parentHeapId, u32 zero);                     /* 0: Wi-Fi only (DWC init) */
    void (*setup)(u16 heapId, struct GFLNetSession *session, u32 wmParam, void *userData);
    void (*begin)(u32 doneCallback);                                      /* 2: Wi-Fi login start / wireless immediate done */
    int  (*update)(u32 tick);                                             /* 3: per-frame step */
    u32  (*stepDisconnect)(u32 closeRequest, u32 zero);                   /* 4: request or advance a disconnect */
    u32  (*cleanup)(u32 endCallback);                                     /* 5: end the device, callback when done */
    void (*clearScanList)(void);                                          /* 6: wireless only */
    u8    unusedSlots7To9[0x28 - 0x1C];
    u32  (*getScanResult)(u32 index);                                     /* 10: wireless only */
    void *(*getScanResultMac)(u32 index);                                 /* 11: wireless only */
    u8    unusedSlots12To13[0x38 - 0x30];
    u32  (*hasBeaconBeenSent)(u32 a);                                     /* 14: wireless only */
    void (*setConnectCallback)(void *cb);                                 /* 15: wireless only */
    u32  (*startParent)(u32 a, u32 b);                                    /* 16: wireless only */
    u32  (*startChildScan)(u32 a, u32 b);                                 /* 17: wireless only */
    u32  (*startChild)(u32 a, u32 b, u32 c, u32 d, u32 e);                /* 18: wireless only */
    u32  (*startMatchWithKey)(void *matchValue, int maxPlayers, int useFilter, int unused); /* 19: Wi-Fi only */
    u32  (*startFriendMatch)(int friendIndex, u32 maxPlayers, u32 limitToTwo); /* 20: Wi-Fi only */
    u32  (*pollDisconnect)(u32 closeRequest, u32 zero);                   /* 21: nonzero once the link is closed */
    u32  (*isDataSharing)(void);                                          /* 22: wireless only */
    u32  (*stepDataSharing)(u32 sendData);                                /* 23: wireless only */
    u32  (*getSharedData)(u32 aid);                                       /* 24: wireless only */
    u32  (*sendData)(u32 data, u32 size, u32 unused, void *doneCallback); /* 25 */
    void (*setEventCallback)(void *cb);                                   /* 26 */
    u32  (*isActive)(void);                                               /* 27 */
    int  (*isConnected)(void);                                            /* 28 */
    u32  (*isOffline)(void);                                              /* 29 */
    u32  (*isIdle)(void);                                                 /* 30 */
    u32  (*getAidBitmap)(void);                                           /* 31 */
    int  (*getMyAid)(void);                                               /* 32 */
    u32  (*getSignalLevel)(void);                                         /* 33 */
    int  (*getLastErrorCode)(void);                                       /* 34 */
    void (*setWatchDisconnect)(u32 enabled);                              /* 35 */
    u32  (*isFriendWaiting)(u32 friendIndex);                             /* 36: Wi-Fi only */
    u8    wifiOnlySlots37To38[0x9C - 0x94];                               /* 37 isVchatEnabled, 38 getNewClientAid */
    void (*resetLink)(void);                                              /* 39: IRC device */
    u32  (*getErrorCode)(void);                                           /* 40: IRC device */
    u32  (*getChannel)(void);                                             /* 41: IRC device */
    u32  (*getGgid)(void);                                                /* 42: IRC device */
    u32  (*getTgid)(void);                                                /* 43: IRC device; Wi-Fi isInSession */
    int  (*isBusy)(void);                                                 /* 44: IRC device */
    void (*forceReset)(void);                                             /* 45: IRC device */
    void (*setAcceptConnection)(void *arg);                               /* 46: Wi-Fi setAllowConnect, wireless setAcceptChild */
    int  (*startAutoSearch)(void);                                        /* 47: wireless only */
    void (*startJoinLock)(int frames);                                    /* 48: wireless only */
    void (*setLinkTimeout)(u32 frames);                                   /* 49: IRC device */
    void (*setSessionParam)(u32 param);                                   /* 50: IRC device */
} GFLNetModeOps;

/* The 0x354-byte session record allocated by the session start function. */
typedef struct GFLNetSession {
    GFLNetInitializeStruct init;
    GFLNetHandle handle[9];
    GFLNetModeOps *ops;
    u32  reserved344;
    GFLNetUserFunc exitCallback;
    void *userArg;
    u8   pad350[2];
    u8   errorCheckEnabled;
} GFLNetSession;

/* Globals at 0x021469E0. */
typedef struct GFLNetMain {
    u16 baseHeapId;
    u16 pad02;
    u32 ircParamB;
    GFLNetSession *session;
    u32 ircParamA;
} GFLNetMain;

struct NetMac {
    u8 addr[6];
    u8 pad06[2];
};

struct NetMacList {
    int count;
    struct NetMac mac[4];
};

/* Wireless link state wrapped around a caller's init block (0x10C bytes). */
typedef struct NetIrcWirelessLink {
    GFLNetInitializeStruct init;
    void  *callbackArg;
    u32    sessionParam;
    void *(*savedGetBeaconDataFunc)(void *arg);
    void *(*savedGetBeaconSizeFunc)(void *arg);
    void (*savedConnectEndFunc)(void *userArg);
    GFLNetUserFunc onFinishedFunc;
    void (*onResultFunc)(void *arg, int flag);
    GFLNetUserFunc onReadyFunc;
    struct NetMacList macs;
    u8     beaconCopy[0x4C];
    u8     timeoutCounter;
    u8     active;
    u8     syncReady;
    u8     connectEnded;
    u8     savedBMPMode;
    u8     netID;
    u8     requestedNetIDPlus1;
    u8     expectedMemberNum;
    u8     retryCount;
    u8     state;
    u8     retryEnabled;
    u8     gameKindOverride;
} NetIrcWirelessLink;

/* net_ring_buff.c ring buffer (16 bytes). */
typedef struct NetRingBuff {
    u8   *buf;
    int   size;
    u32   state;                 /* nothing reads it */
    short readPos;               /* 0x0C */
    volatile short writePos;     /* 0x0E */
} NetRingBuff;

/* net_queue.c: one queued send (0x14 bytes) */
typedef struct NetQueueNode {
    const u8 *data;              /* 0 when the data went to the ring */
    struct NetQueueNode *prev;
    struct NetQueueNode *next;
    u16 size;                    /* 0x0C: bytes still to send */
    u16 command;                 /* 0x0E: 0 = free node */
    u8  sendID;                  /* 0x10 */
    u8  headerSent;              /* 0x11 */
} NetQueueNode;

typedef struct NetQueueList {
    NetQueueNode *head;
    NetQueueNode *tail;
} NetQueueList;

/* net_queue.c send queue, 0x28 bytes */
typedef struct NetQueue {
    NetQueueList  fast;          /* 0x00 */
    NetQueueList  slow;          /* 0x08 */
    NetQueueNode *current;       /* 0x10: node cut by a full send buffer */
    NetRingBuff  *ring;          /* 0x14 */
    NetQueueNode *nodes;         /* 0x18 */
    int           nodeMax;       /* 0x1C */
    u32           pad20;         /* nothing reads it */
    u32           sendContinued; /* 0x24: last packet left the queue unfinished */
} NetQueue;

/* net_queue.c: write window into a send buffer */
typedef struct NetSendBuf {
    u8  *ptr;
    u16  size;                   /* 0xffff: buffer full */
} NetSendBuf;

/* One packet on the wire: 7-byte header, then the payload. */
typedef struct NetPacketHeader {
    u8 checksumLow;      /* low byte of the checksum over everything from size on */
    u8 checksumHigh;
    u8 size;             /* payload size, low 8 bits */
    u8 memberBitmap;     /* members the sender sees as connected */
    u8 flags;            /* 1 = first packet, 2 = continued, 8 = size above 0xFF, 0xFF = empty */
    u8 seq;
    u8 pad06;
    u8 body[1];
} NetPacketHeader;

/* Reassembly state of the packet stream of one sender (16 bytes). */
typedef struct NetRecvCursor {
    int copied;          /* bytes of the current command already copied to dest */
    u8 *dest;            /* where the command data goes (0 = not allocated yet) */
    u16 remaining;       /* bytes of the command still in the ring */
    u16 totalSize;       /* size of the command, 0xFFFF = size not read yet */
    u16 command;         /* command id, 0 = none started */
    u8  senderID;        /* member index, 0xFF = the parent */
    u8  commandOption;   /* byte read after the size, passed to the command table */
} NetRecvCursor;

/* The object _pNetSys points at (0x1f0 bytes, allocated by GFL_NET_SYSTEM_InitWork). */
typedef struct NetSysWork {
    u8  *sendPacketBuf;           /* 0x00: packet being built for a send */
    u8  *sendRingData;            /* 0x04: storage of sendRing, 15 packets */
    u8  *mpParentPacketBuf;       /* 0x08: MP parent packet, parent send size */
    u8  *mpParentRingData;        /* 0x0C: storage of mpParentSendRing */
    u8  *recvRingData;            /* 0x10: storage of the per-member receive rings */
    u8  *parentRecvRingData;      /* 0x14: storage of parentRecvRing */
    u8  *recvScratchBuf;          /* 0x18: buffer a command is copied through */
    NetRingBuff sendRing;         /* 0x1C */
    NetRingBuff parentRecvRing;   /* 0x2C */
    NetRingBuff mpParentSendRing; /* 0x3C */
    NetRingBuff recvRing[GFL_NET_MACHINE_MAX];      /* 0x4C: one per member */
    NetQueue sendQueue;           /* 0xCC */
    NetQueue mpParentSendQueue;   /* 0xF4 */
    NetRecvCursor recvCursor[GFL_NET_MACHINE_MAX];  /* 0x11C: one per member */
    NetRecvCursor parentRecvCursor; /* 0x19C */
    u32 mpWaitMode;               /* 0x1AC: nonzero = the MP parent waits for all children */
    int parentRecvPending;        /* 0x1B0: receives requested from the parent, not yet delivered */
    int recvPending[GFL_NET_MACHINE_MAX];           /* 0x1B4: same, per member */
    u8  mpParentSeq;              /* 0x1D4: sequence of the MP parent packets */
    u8  sendSeq;                  /* 0x1D5 */
    u8  parentRecvSeq;            /* 0x1D6: sequence of the last packet from the parent */
    u8  recvSeq[GFL_NET_MACHINE_MAX];               /* 0x1D7: per member */
    u8  pad1DF;
    u32 packetBufSize;            /* 0x1E0: largest packet plus 0x40 */
    u16 memberBitmap;             /* 0x1E4: members the parent reported as connected */
    u8  pad1E6;
    u8  noChildError;             /* 0x1E7 */
    u8  sendBusy;                 /* 0x1E8: cleared by the reset, never read in this file */
    u8  errorFlag;                /* 0x1E9 */
    u8  noSend;                   /* 0x1EA */
    u8  sendReady;                /* 0x1EB */
    u8  autoFree;                 /* 0x1EC: free the work once the link is down */
    u8  ircRecvPending;           /* 0x1ED */
    u8  pad1EE[2];
} NetSysWork;

/* Error record the state module keeps (four words); GFL_NET_STATE_GetError returns it. */
typedef struct NetErrorInfo {
    int errorCode;
    int errorType;
    int dwcError;
    int gameCode;        /* nonzero once an error was reported */
} NetErrorInfo;

/* One command: receive handler and size handler (both may be null). */
typedef void (*NetCommandRecvFunc)(u32 netId, u32 size, u32 data, u32 userData, u32 handle);
typedef u32 (*NetCommandSizeFunc)(u32 netId, u32 userData, u32 size);

typedef struct NetCommandEntry {
    NetCommandRecvFunc recvFunc;
    NetCommandSizeFunc sizeFunc;
} NetCommandEntry;

typedef struct NetCommandTable {
    NetCommandEntry *list;
    int   listNum;
    void *userData;
    u32   groupKey;
} NetCommandTable;

/* byte 0x17 of a send slot: the header goes first, then the data chunks */
typedef union SendSlotState {
    u8 raw;
    struct {
        u8 dataActive : 4;      /* header sent, chunks are going out */
        u8 headerPending : 4;   /* header still to send */
    } bits;
} SendSlotState;

typedef struct NetSendSlot {
    u32 handleId;
    u32 totalSize;
    void *dataAddr;
    u16 command;
    u16 chunkSize;
    u16 lastChunkSize;
    u16 chunksSent;
    u16 chunkCount;
    u8  destMask;
    SendSlotState state;
} NetSendSlot;

typedef struct NetHugeRecv {
    u32 size;
    u32 data;
    u16 command;
    u16 chunkSize;
    u16 chunksReceived;
    u16 chunkCount;
    u16 destMask;
    u8  used;
} NetHugeRecv;

typedef struct NetCommandWork {
    NetCommandTable commandTables[4];
    NetSendSlot sendSlots[5];
    NetHugeRecv aNetHugeRecv[9];
    u8 pad16c[0xb4];
    u8 memberState[8];
    u8 initDone;
    u8 pad229[3];
} NetCommandWork;

#endif
