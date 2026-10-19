/*
 * file:     game_beacon_search.c
 * unit:     yes
 * function: GAME_BEACON_SEARCH_Init, GAME_BEACON_SEARCH_InitWait, GAME_BEACON_SEARCH_OnSessionStarted, GAME_BEACON_SEARCH_Exit, GAME_BEACON_SEARCH_FreeWork, GAME_BEACON_SEARCH_OnNetExit, GAME_BEACON_SEARCH_Update, GAME_BEACON_SEARCH_PollScanResult, GAME_BEACON_SEARCH_PickBestScanResult, GAME_BEACON_SEARCH_GetBeaconData, GAME_BEACON_SEARCH_BuildBeaconHeader, GAME_BEACON_SEARCH_GetBeaconSize, GAME_BEACON_SEARCH_CompareBeacon, GAME_BEACON_SEARCH_OnConnected, GAME_BEACON_SEARCH_DummyCallback, GAME_BEACON_SEARCH_SelectBetterEntry, GAME_BEACON_SEARCH_SetStartDelay, GAME_BEACON_SEARCH_StartConnectEvent
 * address:  0x02164B6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_skill_check.c, calender.c, game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_COMM_GetLastKind  0x0202647C  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_BEACON_SEARCH_FileName     0x021729BC  data  ov010  a1
 *   GFL_HEAP_DumpReport  0x02030B50  arm
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GAME_BEACON_SEARCH_NetInit     0x02171C30  data  ov010  a4
 *   WIH_DWC_Create 0x02010360 thumb
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_ERR_ResetState 0x0200FBA0 thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   DWCi_IsFold  0x02035390  arm
 *   UI_IsPowerConnected  0x020353B0  arm
 *   GAME_BEACON_SendIfRequested  0x020267FC  thumb
 *   GAME_COMM_GetNotifyFlag  0x020264AC  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   INTRUDE_COMM_IsListedId  0x02158570  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   GAME_COMM_RequestExit  0x0202640C  thumb
 *   NET_WHPIPE_ReleaseEntry  0x02177BF4  thumb  ov014
 *   WIH_DWC_TickTimers  0x02010498  thumb
 *   GFL_NET_EndDeviceWrapper  0x0203D0FC  arm
 *   GFL_NET_GetScanResultMac  0x0203CF3C  arm
 *   GAME_BEACON_ReceiveInfo  0x02026A60  thumb
 *   NET_WHPIPE_GetEntryKind  0x02178098  thumb ov014
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   GAME_BEACON_GetMyInfo 0x020267E4 thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetParentalControlInfoPtr  0x02087E60  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   GAMESYSTEM_CanStartAutoComm  0x02012164  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_Start  0x020263D8  thumb
 */
#include "../arm9/game_beacon_types.h"
#include "field_skill_check_shared_types.h"
#include "game_beacon_search_shared_types.h"

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);

struct GameComm;

struct NetInitParam;

#include "../types.h"

/* ------------------------------------------------------------------ *
 * game_beacon_search.c: the wireless search for other games' beacons.
 * ------------------------------------------------------------------ */

/* The 8-byte header in front of the beacon info, read by the scan. */
typedef struct GameBeaconSearchHeader {
    u8  beaconType;             /* 0x00: 3 for this game */
    u8  memberNum : 4;          /* 0x01: connected members */
    u8  memberMax : 4;
    u8  busy : 1;               /* 0x02: the sender cannot connect now */
    u8  kind : 5;               /* 1 link request, 2 beacon info */
    u8  twlWirelessOn : 1;
    u8  isTwl : 1;
    u8  reserved0 : 1;          /* 0x03 */
    u8  lidClosed : 1;
    u8  reserved1 : 6;
    u32 trainerId;              /* 0x04 */
} GameBeaconSearchHeader;

/* The beacon this game sends, 0x64 bytes. */
typedef struct GameBeaconSearchBeacon {
    GameBeaconSearchHeader header;      /* 0x00 */
    GameBeaconInfo info;                /* 0x08 */
} GameBeaconSearchBeacon;

/* The sender the scan chose to connect to, 9 bytes. */
typedef struct GameBeaconSearchTarget {
    u8 beaconType;              /* 0x00 */
    u8 memberNum;               /* 0x01 */
    u8 memberMax;               /* 0x02 */
    u8 macAddress[6];           /* 0x03 */
} GameBeaconSearchTarget;

/* The search work, 0x84 bytes, made in GAME_BEACON_SEARCH_Init. */
typedef struct GameBeaconSearchWork {
    struct GameData *gameData;          /* 0x00 */
    int state;                          /* 0x04: 0 stopped, 1 started, 2 scanning */
    u8  connected;                      /* 0x08 */
    u16 lastZoneId;                     /* 0x0A */
    u32 scanDelay;                      /* 0x0C: frames before beacon info is read */
    GameBeaconSearchBeacon beacon;      /* 0x10 */
    GameBeaconSearchTarget target;      /* 0x74 */
    u8 *wihDwc;                         /* 0x80 */
} GameBeaconSearchWork;

/* The connect request made when a sender is found, 0x0C bytes. */
typedef struct GameBeaconConnectRequest {
    struct GameSystem *gameSystem;      /* 0x00 */
    u8 macAddress[6];                   /* 0x04 */
    u8 reserved[2];
} GameBeaconConnectRequest;

/* The connect event handed to the comm system, 0x10 bytes. */
typedef struct GameBeaconConnectEvent {
    struct GameSystem *gameSystem;      /* 0x00 */
    struct GameComm *gameComm;          /* 0x04 */
    u8 macAddress[6];                   /* 0x08 */
} GameBeaconConnectEvent;

/* OS owner flags: only the two wireless bits are read here. */
typedef struct OwnerFlags {
    u32 wirelessOn : 1;
    u32 reserved0 : 4;
    u32 parentalWirelessOn : 1;
    u32 reserved1 : 26;
} OwnerFlags;

extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GAME_COMM_GetLastKind(struct GameComm *gameComm);

extern u32 GAME_COMM_GetCounter(struct GameComm *gameComm);

extern void GFL_HEAP_DumpReport(u32 heapId);

extern void GFL_NET_StartSession(const struct NetInitParam *init, void (*callback)(void *work), void *work);
struct WihContext;

extern struct WihContext *WIH_DWC_Create(int maxBeacons, void *heap);
struct WihContext;

extern void WIH_DWC_Delete(struct WihContext *context);

extern int GFL_NET_Exit(void (*callback)(void *work));

extern u32 GFL_HEAP_Free(void *memory);

extern u32 GFL_NET_ERR_GetErrorLevel(void);

extern void GFL_NET_ERR_ResetState(void);

extern u8 GAME_DATA_IsSaving(const struct GameData *gameData);

extern void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);

extern int DWCi_IsFold(void);

extern int UI_IsPowerConnected(void);

extern void GAME_BEACON_SendIfRequested(void);

extern u32 GAME_COMM_GetNotifyFlag(struct GameComm *gameComm);

extern int GAME_DATA_GetIntrudeCount(const struct GameData *gameData);

extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *playerWork);

extern int INTRUDE_COMM_IsListedId(u16 zoneId);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern void GAME_COMM_RequestExit(struct GameComm *comm, void (*callback)(void *work, int cancel), unsigned int exitArg);

extern void MI_CpuFill8(void *dst, u8 value, u32 size);

extern void NET_WHPIPE_ReleaseEntry(u32 index);

extern void WIH_DWC_TickTimers(void);

extern void GFL_NET_EndDeviceWrapper(int mode);

extern void *GFL_NET_GetScanResultMac(u32 index);

extern int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info);

extern u8 NET_WHPIPE_GetEntryKind(u8 index);

extern u32 GFL_NET_GetScanResult(u32 index);

extern void GAME_BEACON_GetMyInfo(GameBeaconInfo *info);

extern int GFL_NET_GetNegotiationNum(void);

extern u32 GFL_NET_SYSTEM_CheckError(void);

extern int OS_IsRunOnTwl(void);

extern OwnerFlags *OS_GetParentalControlInfoPtr(void);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern u32 MYSTATUS_GetId(const struct MyStatus *myStatus);

extern u32 GAMESYSTEM_CanStartAutoComm(const struct GameSystem *gameSystem);

extern int GFL_NET_GetRunState(void);

extern u32 GAME_COMM_GetKind(struct GameComm *gameComm);

extern void GAME_COMM_Start(struct GameComm *comm, u32 kind, u32 param);

GameBeaconSearchWork *GAME_BEACON_SEARCH_Init(void *unused, struct GameSystem *gameSystem);

int GAME_BEACON_SEARCH_InitWait(int *seq, void *unused, GameBeaconSearchWork *work);

void GAME_BEACON_SEARCH_OnSessionStarted(void *arg);

int GAME_BEACON_SEARCH_Exit(void *unused0, void *unused1, GameBeaconSearchWork *work);

int GAME_BEACON_SEARCH_FreeWork(void *unused0, void *unused1, GameBeaconSearchWork *work);

void GAME_BEACON_SEARCH_OnNetExit(void *arg);

void GAME_BEACON_SEARCH_Update(void *unused, struct GameSystem *gameSystem, GameBeaconSearchWork *work);

GameBeaconSearchTarget *GAME_BEACON_SEARCH_PollScanResult(GameBeaconSearchWork *work, int *index);

GameBeaconSearchBeacon *GAME_BEACON_SEARCH_PickBestScanResult(GameBeaconSearchWork *work, int *index);

GameBeaconSearchBeacon *GAME_BEACON_SEARCH_GetBeaconData(GameBeaconSearchWork *work);

void GAME_BEACON_SEARCH_BuildBeaconHeader(GameBeaconSearchBeacon *beacon, struct GameData *gameData);

int GAME_BEACON_SEARCH_GetBeaconSize(void);

int GAME_BEACON_SEARCH_CompareBeacon(void);

int GAME_BEACON_SEARCH_OnConnected(void *unused0, void *unused1, GameBeaconSearchWork *work);

void GAME_BEACON_SEARCH_DummyCallback(void);

GameBeaconSearchBeacon *GAME_BEACON_SEARCH_SelectBetterEntry(GameBeaconSearchBeacon *beacon, GameBeaconSearchBeacon *best);

void GAME_BEACON_SEARCH_SetStartDelay(GameBeaconSearchWork *work);

void GAME_BEACON_SEARCH_StartConnectEvent(void *arg, int cancel);

extern const char GAME_BEACON_SEARCH_FileName[];

extern const struct NetInitParam GAME_BEACON_SEARCH_NetInit;

/* Allocates and initialises the search work. */
GameBeaconSearchWork *GAME_BEACON_SEARCH_Init(void *unused, struct GameSystem *gameSystem)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameComm *gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    GameBeaconSearchWork *work = GFL_HEAP_Alloc(5, sizeof(GameBeaconSearchWork), 1, GAME_BEACON_SEARCH_FileName, 0x9c);

    work->gameData = gameData;
    work->lastZoneId = 0x1ab;
    if (GAME_COMM_GetLastKind(gameComm) == 2 && GAME_COMM_GetCounter(gameComm) == 5) {
        GAME_BEACON_SEARCH_SetStartDelay(work);
    }
    return work;
}

int GAME_BEACON_SEARCH_InitWait(int *seq, void *unused, GameBeaconSearchWork *work)
{
    switch (*seq) {
    case 0:
        GFL_HEAP_DumpReport(12);
        GFL_NET_StartSession(&GAME_BEACON_SEARCH_NetInit, GAME_BEACON_SEARCH_OnSessionStarted, work);
        (*seq)++;
        break;
    case 1:
        if (work->state >= 1) {
            return 1;
        }
        break;
    }
    return 0;
}

void GAME_BEACON_SEARCH_OnSessionStarted(void *arg)
{
    GameBeaconSearchWork *work = arg;

    work->state = 1;
    work->wihDwc = (unsigned char *)WIH_DWC_Create(4, (void *)0x8005);
}

int GAME_BEACON_SEARCH_Exit(void *unused0, void *unused1, GameBeaconSearchWork *work)
{
    WIH_DWC_Delete((struct WihContext *)work->wihDwc);
    GFL_NET_Exit(GAME_BEACON_SEARCH_OnNetExit);
    return 1;
}

int GAME_BEACON_SEARCH_FreeWork(void *unused0, void *unused1, GameBeaconSearchWork *work)
{
    if (work->state == 0) {
        GFL_HEAP_Free(work);
        if (GFL_NET_ERR_GetErrorLevel()) {
            GFL_NET_ERR_ResetState();
        }
        return 1;
    }
    return 0;
}

void GAME_BEACON_SEARCH_OnNetExit(void *arg)
{
    GameBeaconSearchWork *work = arg;

    work->state = 0;
}

static inline int PAD_DetectFold(void)
{
    return (*(vu16 *)0x02FFFFA8 & 0x8000) >> 15;
}

void GAME_BEACON_SEARCH_Update(void *unused, struct GameSystem *gameSystem, GameBeaconSearchWork *work)
{
    struct GameComm *gameComm;
    struct GameData *gameData;
    int index;
    GameBeaconSearchTarget *target;
    GameBeaconConnectRequest *request;
    u16 zoneId;

    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    index = 0;
    if (GAME_DATA_IsSaving(gameData) == 1)
        return;
    if (GFL_NET_ERR_GetErrorLevel()) {
        GAME_COMM_RequestExitNoCallback(gameComm);
        return;
    }
    if (DWCi_IsFold() == 1 && UI_IsPowerConnected() == 1) {
        GAME_COMM_RequestExitNoCallback(gameComm);
        return;
    }
    if (work->scanDelay != 0)
        work->scanDelay--;
    GAME_BEACON_SendIfRequested();
    target = GAME_BEACON_SEARCH_PollScanResult(work, &index);
    if (target != 0) {
        if (target->beaconType == 2) {
            if (!PAD_DetectFold() && !GAME_COMM_GetNotifyFlag(gameComm) && !GAME_DATA_GetIntrudeCount(gameData)) {
                zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
                if (zoneId != work->lastZoneId) {
                    work->lastZoneId = zoneId;
                    if (INTRUDE_COMM_IsListedId(zoneId) == 1) {
                        request = GFL_HEAP_Alloc(0x8005, sizeof(GameBeaconConnectRequest), 1, GAME_BEACON_SEARCH_FileName, 0x154);
                        request->gameSystem = gameSystem;
                        MI_CpuCopy8(target->macAddress, request->macAddress, 6);
                        GAME_COMM_RequestExit(gameComm, GAME_BEACON_SEARCH_StartConnectEvent, (unsigned int)request);
                        goto end; /* the connect path skips the target reset; bytes need the goto */
                    }
                }
            }
            MI_CpuFill8(&work->target, 0, sizeof(GameBeaconSearchTarget));
            NET_WHPIPE_ReleaseEntry(index);
        } else {
            target->beaconType = 0;
        }
    }
end:
    WIH_DWC_TickTimers();
}

GameBeaconSearchTarget *GAME_BEACON_SEARCH_PollScanResult(GameBeaconSearchWork *work, int *index)
{
    GameBeaconSearchBeacon *beacon;
    u8 *macAddress;
    int i;
    GameBeaconSearchTarget *target = &work->target;

    if (work->state == 0) {
        return 0;
    }
    if (work->state == 1) {
        GFL_NET_EndDeviceWrapper(0);
        work->state = 2;
        return 0;
    }
    if (target->beaconType == 0) {
        beacon = GAME_BEACON_SEARCH_PickBestScanResult(work, index);
        if (beacon != 0) {
            if (beacon->header.busy != 0) {
                NET_WHPIPE_ReleaseEntry(*index);
            } else if (beacon->header.kind == 1) {
                i = 0;
                MI_CpuFill8(target, 0, sizeof(GameBeaconSearchTarget));
                target->beaconType = beacon->header.beaconType;
                target->memberNum = beacon->header.memberNum;
                target->memberMax = beacon->header.memberMax;
                macAddress = GFL_NET_GetScanResultMac(*index);
                for (i = 0; i < 6; i++) {
                    target->macAddress[i] = macAddress[i];
                }
            } else if (beacon->header.kind == 2) {
                GAME_BEACON_ReceiveInfo(&beacon->info);
                NET_WHPIPE_ReleaseEntry(*index);
            }
        }
    }
    if (target->beaconType == 0) {
        target = 0;
    }
    return target;
}

GameBeaconSearchBeacon *GAME_BEACON_SEARCH_PickBestScanResult(GameBeaconSearchWork *work, int *index)
{
    int none = -1;
    int best = -1;
    int i;
    GameBeaconSearchBeacon *beacon;
    int scanState;

    for (i = 0; i < 16; i++) {
        scanState = NET_WHPIPE_GetEntryKind(i);
        if ((u32)(scanState - 2) > 1) {
            continue;
        }
        if (scanState == 2 && work->scanDelay != 0) {
            continue;
        }
        beacon = (struct GameBeaconSearchBeacon *)GFL_NET_GetScanResult(i);
        if (beacon == 0) {
            continue;
        }
        if (beacon->header.memberNum < beacon->header.memberMax) {
            if (best == none) {
                best = i;
            } else if (GAME_BEACON_SEARCH_SelectBetterEntry(beacon, (struct GameBeaconSearchBeacon *)GFL_NET_GetScanResult(best)) == beacon) {
                best = i;
            }
        } else {
            NET_WHPIPE_ReleaseEntry(i);
        }
    }
    if (best != -1) {
        *index = best;
        return (struct GameBeaconSearchBeacon *)GFL_NET_GetScanResult(best);
    }
    return 0;
}

GameBeaconSearchBeacon *GAME_BEACON_SEARCH_GetBeaconData(GameBeaconSearchWork *work)
{
    GAME_BEACON_SEARCH_BuildBeaconHeader(&work->beacon, work->gameData);
    GAME_BEACON_GetMyInfo(&work->beacon.info);
    work->beacon.header.kind = 2;
    return &work->beacon;
}

void GAME_BEACON_SEARCH_BuildBeaconHeader(GameBeaconSearchBeacon *beacon, struct GameData *gameData)
{
    int wirelessOn;
    int lidClosed;

    MI_CpuFill8(beacon, 0, sizeof(GameBeaconSearchBeacon));
    beacon->header.beaconType = 3;
    beacon->header.memberNum = GFL_NET_GetNegotiationNum();
    beacon->header.memberMax = 3;
    beacon->header.busy = GFL_NET_SYSTEM_CheckError();
    beacon->header.kind = 0;
    beacon->header.trainerId = MYSTATUS_GetId(GAME_DATA_GetMyStatus(gameData));
    beacon->header.isTwl = OS_IsRunOnTwl();
    beacon->header.twlWirelessOn = 0;
    lidClosed = PAD_DetectFold();
    beacon->header.lidClosed = lidClosed;
    if (beacon->header.isTwl == 1) {
        wirelessOn = 1;
        if (OS_GetParentalControlInfoPtr()->wirelessOn == 0 || OS_GetParentalControlInfoPtr()->parentalWirelessOn == 0)
            wirelessOn = 0;
        beacon->header.twlWirelessOn = wirelessOn;
    }
}

int GAME_BEACON_SEARCH_GetBeaconSize(void)
{
    return sizeof(GameBeaconSearchBeacon);
}

int GAME_BEACON_SEARCH_CompareBeacon(void)
{
    return 1;
}

int GAME_BEACON_SEARCH_OnConnected(void *unused0, void *unused1, GameBeaconSearchWork *work)
{
    work->connected = 1;
    return 1;
}

void GAME_BEACON_SEARCH_DummyCallback(void)
{
}

/* Of two scanned beacons, keep the one that has room and fewer members. */
GameBeaconSearchBeacon *GAME_BEACON_SEARCH_SelectBetterEntry(GameBeaconSearchBeacon *beacon, GameBeaconSearchBeacon *best)
{
    if (beacon->header.busy)
        return best;
    if (beacon->header.memberNum >= beacon->header.memberMax || beacon->header.memberNum < best->header.memberNum)
        return best;
    return beacon;
}

void GAME_BEACON_SEARCH_SetStartDelay(GameBeaconSearchWork *work)
{
    work->scanDelay = 0x708;
}

/*
 * Connect callback of the request made in GAME_BEACON_SEARCH_Update: when no other
 * comm is running, it hands a 0x10-byte connect event to the comm system.
 */
void GAME_BEACON_SEARCH_StartConnectEvent(void *arg, int cancel)
{
    u8 macAddress[6];
    GameBeaconConnectRequest *request = arg;
    struct GameSystem *gameSystem = request->gameSystem;
    struct GameComm *gameComm;
    GameBeaconConnectEvent *event;

    MI_CpuCopy8(request->macAddress, macAddress, 6);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    GFL_HEAP_Free(request);
    if (cancel == 0 && GAMESYSTEM_CanStartAutoComm(gameSystem) == 1 && GAME_COMM_GetNotifyFlag(gameComm) == 0
        && GFL_NET_GetRunState() == 0 && GAME_COMM_GetKind(gameComm) == 0) {
        event = GFL_HEAP_Alloc(5, sizeof(GameBeaconConnectEvent), 1, GAME_BEACON_SEARCH_FileName, 0x287);
        event->gameSystem = gameSystem;
        event->gameComm = GAMESYSTEM_GetGameComm(gameSystem);
        MI_CpuCopy8(macAddress, event->macAddress, 6);
        GAME_COMM_Start(gameComm, (u32)2, (u32)event);
    }
}
