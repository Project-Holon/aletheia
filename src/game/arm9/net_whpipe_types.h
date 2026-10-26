/* Types of the wireless pipe (net_whpipe.c, net_whpipe_p02.c) and the wireless device table (net_devwireless.c). */
#ifndef NET_WHPIPE_TYPES_H
#define NET_WHPIPE_TYPES_H

#include "../types.h"

#define WHPIPE_ENTRY_MAX 16            /* scanned parents kept at once */
#define WHPIPE_ENTRY_LIFETIME 600      /* frames an entry stays alive without a new beacon */
#define WHPIPE_BEACON_DATA_SIZE 0x68   /* game bytes of a beacon (the caller's size must stay below this) */

/* Flags of NET_WHPIPE_CheckBeaconFlags: which tests to run. */
#define WHPIPE_CHECK_STATUS  0x01      /* beacon status byte is zero */
#define WHPIPE_CHECK_RESERVED 0x02     /* reserved byte is zero */
#define WHPIPE_CHECK_CHECKSUM 0x04     /* checksum over the beacon matches */
#define WHPIPE_CHECK_GGID    0x08      /* game id matches our own */
#define WHPIPE_CHECK_KIND    0x10      /* game kind accepted by the compare callback */
#define WHPIPE_CHECK_MEMBERS 0x20      /* the parent still has room */

/* Beacon payload (user game info) that the parent advertises; a received copy sits at 0x50 of each entry. */
typedef struct WhPipeBeacon {
    u16 checksum;                      /* 0x00 over bytes 2..0x6F */
    u16 ggid;
    u8 kind;                           /* game kind of the parent */
    u8 reserved;
    u8 connectedNum;                   /* members connected to the parent right now */
    u8 status;                         /* 0 open, else the parent refuses joins */
    u8 data[WHPIPE_BEACON_DATA_SIZE];  /* game-defined bytes (beacon data callback) */
} WhPipeBeacon;

/* One scanned parent (a WMBssDesc followed by its game info). */
typedef struct WhPipeEntry {
    u8 header[4];
    u8 bssid[6];
    u8 ssidBlock[0x2C];
    u16 channel;
    u8 gameInfoHeader[0x18];
    WhPipeBeacon beacon;
} WhPipeEntry;

typedef struct WhPipeWork WhPipeWork;
typedef void (*WhPipeTask)(WhPipeWork *work);
typedef void (*WhPipeNotifyFunc)(void *arg, WhPipeEntry *entry, u32 kind, u32 connectedNum);

/* Work block of the wireless pipe; allocated with size 0xCF8 by NET_WHPIPE_Create. */
struct WhPipeWork {
    WhPipeTask task;
    int (*eventCallback)(int a, int b, int c);
    WhPipeEntry entry[WHPIPE_ENTRY_MAX];
    u8 entryTail[0x30];
    WhPipeNotifyFunc notifyFn;
    void *notifyArg;
    u16 entryAge[WHPIPE_ENTRY_MAX];    /* frames left per entry, 0 = free slot */
    void (*onConnected)(void);
    void *userData;                    /* argument of the beacon callbacks */
    u16 tgid;
    u16 startTime;                     /* first tick seen after the watch started, 0xFFFF = none */
    u16 joinLockFrames;
    WhPipeBeacon beacon;               /* our own beacon as advertised */
    u8 targetBssid[6];
    u8 startedFlag;
    u8 padCE5;
    u8 channel;
    u8 shutdownRequest;
    u8 running;
    u8 scanning;
    u8 beaconStatus;
    u8 disconnectDetected;
    u8 watchDisconnect;
    u8 padCED[2];
    u8 entryListChanged;               /* an entry was added or expired since the flag was cleared */
    u8 beaconRefreshCountdown;
    u8 searchChannelIndex;
    u8 searchTimer;
    u8 timerPaused;
    u8 joinLockHold;
    u8 shutdownCountdown;              /* frames to wait for the finalize call to finish */
    u8 padCF6[2];
};

typedef int (*WhPipeBeaconCompareFunc)(u8 gameKind, u8 beaconKind, void *userData);
typedef int (*WhPipeBeaconSizeFunc)(void *userData);
typedef void *(*WhPipeBeaconDataFunc)(void *userData);


#endif
