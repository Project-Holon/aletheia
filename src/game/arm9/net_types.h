/*
 * Types shared by net.c and net_irc_wireless.c (the two halves of the
 * network core).  Needs u8, u16, u32 from the including file.
 */
#ifndef NET_TYPES_H
#define NET_TYPES_H

struct GFLNetSession;

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
    u32   recvFuncTable;
    u32   recvFuncTableNum;
    void (*connectFunc)(u32 netID, u32 userArg);
    void (*disconnectFunc)(int netID, u32 userArg);
    u32  (*negotiationFunc)(u32 userArg);
    u32  (*beaconSizeFunc)(u32 userArg);
    void *(*getBeaconDataFunc)(void *arg);
    void *(*getBeaconCompareFunc)(void *arg);
    u8    reserved20[4];
    void (*stateChangeFunc)(u32 handle, u32 state, u32 userArg);
    void (*errorStateFunc)(u32 handle, u32 state, u32 userArg);
    void (*connectEndFunc)(u32 userArg);
    void (*deviceReadyFunc)(u32 userArg);
    u8    reserved34[0xC];
    u32  (*getFriendListFunc)(u32 userArg);
    u32  (*getWifiUserDataFunc)(u32 userArg);
    u32   heapSize;
    u8    reserved4C[8];
    u16   parentHeapId;
    u16   heapId;
    u16   wifiHeapId;
    u16   beaconHeapId;
    u16   timeoutFrames;
    u16   timeoutExtra;
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

/* Per-mode operation table returned by the mode lookup (func_0200F17C). */
typedef struct GFLNetModeOps {
    void (*start)(u32 parentHeapId, u32 zero);
    void (*connectToParent)(u16 key, struct GFLNetSession *session, u32 zero, u32 arg);
    void (*stop)(u32 a);
    int  (*requestDisconnect)(u32 a);
    u32  (*setBeaconInterval)(u32 a, u32 b);
    u32  (*setParentMask)(u32 a);
    u8    reserved18[0x28 - 0x18];
    u32  (*getScanResult)(u32 index);
    void *(*getScanResultMac)(u32 index);
    u8    reserved30[0x38 - 0x30];
    u32  (*getScanCount)(u32 a);
    void (*setRecvCallback)(void *cb);
    u32  (*sendToParent)(u32 a, u32 b);
    u32  (*sendToChild)(u32 a, u32 b);
    u32  (*sendBeaconData)(u32 a, u32 b, u32 c, u32 d, u32 e);
    u8    reserved4C[4];
    u32  (*sendPacket)(int a, u32 b, u32 c);
    u32  (*sendPacketMask)(u32 a, u32 b);
    u32  (*getSendBufferFree)(void);
    u32  (*setSendMask)(u32 a);
    u32  (*getRecvSize)(u32 a);
    u32  (*receivePacket)(u32 a, u32 b, u32 c, void *d);
    void (*setErrorCallback)(void *cb);
    u32  (*getRunState)(void);
    int  (*getConnectedNum)(void);
    u32  (*getParentChannel)(void);
    u32  (*getLinkLevel)(void);
    u32  (*getRssi)(void);
    int  (*isParent)(void);
    u32  (*getMyAid)(void);
    int  (*isInitialized)(void);
    void (*setPowerSave)(u32 a);
    u32  (*getBssDesc)(u32 a);
    u8    reserved94[0x9C - 0x94];
    void (*resetLink)(void);
    u32  (*getErrorCode)(void);
    u32  (*getChannel)(void);
    u32  (*getGgid)(void);
    u32  (*getTgid)(void);
    int  (*isBusy)(void);
    void (*forceReset)(void);
    void (*notifyUserEvent)(void *arg);
    int  (*getFrameCount)(void);
    void (*setFrameInterval)(int a);
    void (*setLinkTimeout)(u32 frames);
    void (*setSessionParam)(u32 param);
} GFLNetModeOps;

/* The 0x354-byte session record allocated by the session start function. */
typedef struct GFLNetSession {
    GFLNetInitializeStruct init;
    GFLNetHandle handle[9];
    GFLNetModeOps *ops;
    u32  reserved344;
    void (*exitCallback)(u32 userArg);
    u32  userArg;
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
    u32    callbackArg;
    u32    sessionParam;
    void *(*savedGetBeaconDataFunc)(void *arg);
    void *(*savedGetBeaconCompareFunc)(void *arg);
    void (*savedConnectEndFunc)(u32 userArg);
    void (*onFinishedFunc)(u32 arg);
    void (*onResultFunc)(u32 arg, int flag);
    void (*onReadyFunc)(u32 arg);
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

#endif
