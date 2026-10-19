/*
 * file:     game_beacon_search.c
 * unit:     yes
 * function: CALENDER_CreateTask, GAME_BEACON_SEARCH_Init, GAME_BEACON_SEARCH_InitWait, GAME_BEACON_SEARCH_OnSessionStarted, GAME_BEACON_SEARCH_Exit, GAME_BEACON_SEARCH_FreeWork, GAME_BEACON_SEARCH_OnNetExit, GAME_BEACON_SEARCH_Update, GAME_BEACON_SEARCH_PollScanResult, GAME_BEACON_SEARCH_PickBestScanResult, GAME_BEACON_SEARCH_GetBeaconData, GAME_BEACON_SEARCH_BuildBeaconHeader, GAME_BEACON_SEARCH_GetBeaconSize, GAME_BEACON_SEARCH_CompareBeacon, GAME_BEACON_SEARCH_OnConnected, GAME_BEACON_SEARCH_DummyCallback, GAME_BEACON_SEARCH_SelectBetterEntry, GAME_BEACON_SEARCH_SetStartDelay, GAME_BEACON_SEARCH_StartConnectEvent, GAME_BEACON_SEARCH_SetBattlePokeStart, GAME_BEACON_SEARCH_SetBattlePokeWin, GAME_BEACON_SEARCH_SetBattleWildPokeStart, GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart, GAME_BEACON_SEARCH_SetBattleWildPokeWin, GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin, GAME_BEACON_SEARCH_SetBattleSpecialPokeStart, GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart, GAME_BEACON_SEARCH_SetBattleSpecialPokeWin, GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin, GAME_BEACON_SEARCH_SetBattleTrainerStart, GAME_BEACON_SEARCH_SetInfoBattleTrainerStart, GAME_BEACON_SEARCH_SetBattleTrainerWin, GAME_BEACON_SEARCH_SetInfoBattleTrainerWin, GAME_BEACON_SEARCH_SetBattleLeaderStart, GAME_BEACON_SEARCH_SetInfoBattleLeaderStart, GAME_BEACON_SEARCH_SetBattleLeaderWin, GAME_BEACON_SEARCH_SetInfoBattleLeaderWin, GAME_BEACON_SEARCH_SetBattleBigFourStart, GAME_BEACON_SEARCH_SetInfoBattleBigFourStart, GAME_BEACON_SEARCH_SetBattleBigFourWin, GAME_BEACON_SEARCH_SetInfoBattleBigFourWin, GAME_BEACON_SEARCH_SetVersionAction, GAME_BEACON_SEARCH_SetInfoVersionAction, GAME_BEACON_SEARCH_SetItemFound, GAME_BEACON_SEARCH_SetInfoItemFound, GAME_BEACON_SEARCH_SetScriptEvent, GAME_BEACON_SEARCH_SetInfoScriptEvent, GAME_BEACON_SEARCH_SetPresetEvent, GAME_BEACON_SEARCH_SetInfoPresetEvent, GAME_BEACON_SEARCH_SetFieldEvent, GAME_BEACON_SEARCH_SetInfoFieldEvent, GAME_BEACON_SEARCH_SetPokeEvent, GAME_BEACON_SEARCH_SetInfoPokeEvent, GAME_BEACON_SEARCH_SetEventBattleNameA, GAME_BEACON_SEARCH_SetInfoEventBattleNameA, GAME_BEACON_SEARCH_SetEventBattleNameB, GAME_BEACON_SEARCH_SetInfoEventBattleNameB, GAME_BEACON_SEARCH_SetEventBattleNameC, GAME_BEACON_SEARCH_SetInfoEventBattleNameC, GAME_BEACON_SEARCH_SetEventBattleNameD, GAME_BEACON_SEARCH_SetInfoEventBattleNameD, GAME_BEACON_SEARCH_SetCountValue, GAME_BEACON_SEARCH_SetInfoCountValue, GAME_BEACON_SEARCH_SetSymbolMapEnter, GAME_BEACON_SEARCH_SetInfoSymbolMapEnter, GAME_BEACON_SEARCH_SetSymbolMapPoke, GAME_BEACON_SEARCH_SetInfoSymbolMapPoke, GAME_BEACON_SEARCH_SetFacilityEnter, GAME_BEACON_SEARCH_SetInfoFacilityEnter, GAME_BEACON_SEARCH_SetFacilityExit, GAME_BEACON_SEARCH_SetInfoFacilityExit, GAME_BEACON_SEARCH_SetWordValue, GAME_BEACON_SEARCH_SetInfoWordValue, GAME_BEACON_SEARCH_SetWordClear, GAME_BEACON_SEARCH_SetInfoWordClear, GAME_BEACON_SEARCH_SetSimpleEventA, GAME_BEACON_SEARCH_SetInfoSimpleEventA, GAME_BEACON_SEARCH_SetByteValue, GAME_BEACON_SEARCH_SetInfoByteValue, GAME_BEACON_SEARCH_SetSimpleEventB, GAME_BEACON_SEARCH_SetInfoSimpleEventB, GAME_BEACON_SEARCH_SetSimpleEventC, GAME_BEACON_SEARCH_SetInfoSimpleEventC, GAME_BEACON_SEARCH_SetNamedEvent, GAME_BEACON_SEARCH_SetInfoNamedEvent, GAME_BEACON_SEARCH_SetHalfwordValue, GAME_BEACON_SEARCH_SetInfoHalfwordValue, GAME_BEACON_SEARCH_SetThanks, GAME_BEACON_SEARCH_SetInfoThanks, GAME_BEACON_SEARCH_SetFreeText, GAME_BEACON_SEARCH_SetInfoFreeText, GAME_BEACON_ACCESSOR_TableAddNewLogs, GAME_BEACON_ACCESSOR_TablePop, GAME_BEACON_ACCESSOR_TableMarkLogsNew, GAME_BEACON_ACCESSOR_TableAdd, GAME_BEACON_ACCESSOR_TableGetRingIndex, GAME_BEACON_ACCESSOR_TableRingAdd, GAME_BEACON_ACCESSOR_TableRingGet, GAME_BEACON_ACCESSOR_TableGetCount
 * address:  0x02164B38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   CALENDER_OverlaySequenceEvent 0x02164A2C thumb ov010
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAME_COMM_GetLastKind  0x0202647C  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_BEACON_SEARCH_FileName     0x021729BC  data  ov010  a1
 *   GFL_HEAP_DumpReport  0x02030B50  arm
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GAME_BEACON_SEARCH_NetInit     0x02171C30  data  ov010  a4
 *   WIH_DWC_Create 0x02010360 thumb
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   GFL_NET_Exit 0x0203CEAC arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_ERR_ResetState 0x0200FBA0 thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   DWCi_IsFold  0x02035390  arm
 *   UI_IsPowerConnected  0x020353B0  arm
 *   GAME_BEACON_SendIfRequested  0x020267FC  thumb
 *   GAME_COMM_GetNotifyFlag  0x020264AC  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   INTRUDE_COMM_IsListedId  0x02158570  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   GAME_COMM_RequestExit  0x0202640C  thumb
 *   MI_CpuFill8    0x02082BCC  arm
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
 *   GAME_BEACON_IsSpecialPokemon  0x0202708C  thumb
 *   GAME_BEACON_CheckActionPriority   0x02027060  thumb
 *   GAME_BEACON_RequestSend   0x02026FB8  thumb
 *   GAME_BEACON_Work      0x02146940  data
 *   GAME_BEACON_SetDetailsBattleWildPoke   0x020273C4  thumb
 *   GAME_BEACON_ResetDetails  0x0202744C  thumb
 *   GAME_BEACON_SetDetailsBattleSpecialPoke   0x020273DC  thumb
 *   GAME_BEACON_SetDetailsBattleTrainer   0x020273F8  thumb
 *   GAME_BEACON_SetDetailsBattleLeader   0x02027414  thumb
 *   GAME_BEACON_SetDetailsBattleBigFour   0x02027430  thumb
 *   GAME_BEACON_SEARCH_PresetEventTable      0x02171CA0  data  ov010  a1
 *   GAME_BEACON_CopyStrbufCodes  0x020270AC  thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   BEACON_GetThanksMessage 0x0200C20C thumb
 *   WORDSET_CopyString 0x0201F41C thumb
 *   STRBUF_ToChars  0x02045A38  arm
 *   GF_STANDARD_SetField00 0x0203F4CC arm
 *   GAME_BEACON_GetNextNewLogIndex 0x02026CA0 thumb
 *   GAME_BEACON_GetLog 0x02026C1C thumb
 *   GAME_BEACON_ClearNewFlag 0x02026CE0 thumb
 *   GAME_BEACON_SetNewFlagByTrainerId   0x02026D04  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 */
#include "../arm9/game_beacon_types.h"
#include "game_beacon_search_shared_types.h"

struct GameSystem;

struct GameEvent;

struct GameComm;

struct PlayerWork;

struct MyStatus;

struct SaveControl;

struct NetInitParam;

struct RtcTime {
    int hour;
    int minute;
    int second;
};

typedef volatile u16 vu16;

/* ------------------------------------------------------------------ *
 * calender.c (see misplaced.tsv): the calender event work, 0x1C bytes.
 * ------------------------------------------------------------------ */
typedef struct CalenderEventWork {
    struct GameSystem *gameSystem;      /* 0x00 */
    struct GameData *gameData;          /* 0x04 */
    struct SaveControl *saveControl;    /* 0x08 */
    u8 reserved[12];
    u8 mode;                            /* 0x18 */
} CalenderEventWork;

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

extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, int (*func)(struct GameEvent *, u32 *, void *), u32 workSize);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern int CALENDER_OverlaySequenceEvent(struct GameEvent *event, u32 *seq, void *work);

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GAME_COMM_GetLastKind(struct GameComm *gameComm);

extern u32 GAME_COMM_GetCounter(struct GameComm *gameComm);

extern void GFL_HEAP_DumpReport(u32 heapId);

extern void GFL_NET_StartSession(const struct NetInitParam *init, void (*callback)(void *work), void *work);

extern u8 *WIH_DWC_Create(int index, u32 heapId);

extern void WIH_DWC_Delete(u8 *wihDwc);

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

extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);

extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *playerWork);

extern int INTRUDE_COMM_IsListedId(u16 zoneId);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern void GAME_COMM_RequestExit(struct GameComm *gameComm, void (*callback)(void *work, int cancel), void *work);

extern void MI_CpuFill8(void *dst, u8 value, u32 size);

extern void NET_WHPIPE_ReleaseEntry(u32 index);

extern void WIH_DWC_TickTimers(void);

extern void GFL_NET_EndDeviceWrapper(int mode);

extern u8 *GFL_NET_GetScanResultMac(u32 index);

extern int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info);

extern u8 NET_WHPIPE_GetEntryKind(u8 index);

extern void *GFL_NET_GetScanResult(u32 index);

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

extern void GAME_COMM_Start(struct GameComm *gameComm, u32 kind, void *work);

extern int GAME_BEACON_IsSpecialPokemon(u32 monsNo);

extern u32 GAME_BEACON_CheckActionPriority(u32 action);

extern void GAME_BEACON_RequestSend(GameBeaconRecord *record);

extern void GAME_BEACON_SetDetailsBattleWildPoke(GameBeaconInfo *info, u32 monsNo);

extern void GAME_BEACON_ResetDetails(GameBeaconInfo *info);

extern void GAME_BEACON_SetDetailsBattleSpecialPoke(GameBeaconInfo *info, u32 monsNo);

extern void GAME_BEACON_SetDetailsBattleTrainer(GameBeaconInfo *info, u32 trainerId);

extern void GAME_BEACON_SetDetailsBattleLeader(GameBeaconInfo *info, u32 trainerId);

extern void GAME_BEACON_SetDetailsBattleBigFour(GameBeaconInfo *info, u32 trainerId);

extern void GAME_BEACON_CopyStrbufCodes(const struct Strbuf *str, u16 *dest);

extern struct MyStatus *BEACON_GetBlock(struct SaveControl *saveControl);

extern const u16 *BEACON_GetThanksMessage(const struct MyStatus *myStatus);

extern void WORDSET_CopyString(const u16 *src, u16 *dest, u32 length);

extern void STRBUF_ToChars(const struct Strbuf *str, u16 *dest, u32 length);

extern void GF_STANDARD_SetField00(struct RtcTime *time);

extern int GAME_BEACON_GetNextNewLogIndex(int *cursor);

extern GameBeaconRecord *GAME_BEACON_GetLog(int index);

extern void GAME_BEACON_ClearNewFlag(u32 index);

extern int GAME_BEACON_SetNewFlagByTrainerId(const GameBeaconInfo *info);

extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);

extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);

struct GameEvent *CALENDER_CreateTask(struct GameSystem *gameSystem, void *unused, u8 mode);

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

void GAME_BEACON_SEARCH_SetBattlePokeStart(u32 monsNo);

void GAME_BEACON_SEARCH_SetBattlePokeWin(u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleWildPokeStart(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleWildPokeWin(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetBattleTrainerStart(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleTrainerWin(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleTrainerWin(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleLeaderStart(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleLeaderStart(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleLeaderWin(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleLeaderWin(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleBigFourStart(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleBigFourStart(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetBattleBigFourWin(u32 trainerId);

void GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(GameBeaconInfo *info, u32 trainerId);

void GAME_BEACON_SEARCH_SetVersionAction(u32 version);

void GAME_BEACON_SEARCH_SetInfoVersionAction(GameBeaconInfo *info, u32 version);

void GAME_BEACON_SEARCH_SetItemFound(u32 itemNo);

void GAME_BEACON_SEARCH_SetInfoItemFound(GameBeaconInfo *info, u32 itemNo);

void GAME_BEACON_SEARCH_SetScriptEvent(void);

void GAME_BEACON_SEARCH_SetInfoScriptEvent(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetPresetEvent(u32 eventId);

void GAME_BEACON_SEARCH_SetInfoPresetEvent(GameBeaconInfo *info, u32 eventId);

void GAME_BEACON_SEARCH_SetFieldEvent(void);

void GAME_BEACON_SEARCH_SetInfoFieldEvent(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetPokeEvent(u16 monsNo);

void GAME_BEACON_SEARCH_SetInfoPokeEvent(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetEventBattleNameA(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameA(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetEventBattleNameB(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameB(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetEventBattleNameC(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameC(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetEventBattleNameD(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoEventBattleNameD(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetCountValue(u32 count);

void GAME_BEACON_SEARCH_SetInfoCountValue(GameBeaconInfo *info, u32 count);

void GAME_BEACON_SEARCH_SetSymbolMapEnter(void);

void GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetSymbolMapPoke(u32 monsNo);

void GAME_BEACON_SEARCH_SetInfoSymbolMapPoke(GameBeaconInfo *info, u32 monsNo);

void GAME_BEACON_SEARCH_SetFacilityEnter(void);

void GAME_BEACON_SEARCH_SetInfoFacilityEnter(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetFacilityExit(void);

void GAME_BEACON_SEARCH_SetInfoFacilityExit(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetWordValue(u32 value);

void GAME_BEACON_SEARCH_SetInfoWordValue(GameBeaconInfo *info, u32 value);

void GAME_BEACON_SEARCH_SetWordClear(void);

void GAME_BEACON_SEARCH_SetInfoWordClear(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetSimpleEventA(void);

void GAME_BEACON_SEARCH_SetInfoSimpleEventA(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetByteValue(u8 value);

void GAME_BEACON_SEARCH_SetInfoByteValue(GameBeaconInfo *info, u8 value);

void GAME_BEACON_SEARCH_SetSimpleEventB(void);

void GAME_BEACON_SEARCH_SetInfoSimpleEventB(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetSimpleEventC(void);

void GAME_BEACON_SEARCH_SetInfoSimpleEventC(GameBeaconInfo *info);

void GAME_BEACON_SEARCH_SetNamedEvent(const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetInfoNamedEvent(GameBeaconInfo *info, const struct Strbuf *name);

void GAME_BEACON_SEARCH_SetHalfwordValue(u16 value);

void GAME_BEACON_SEARCH_SetInfoHalfwordValue(GameBeaconInfo *info, u16 value);

void GAME_BEACON_SEARCH_SetThanks(struct GameData *gameData, u16 trainerId);

void GAME_BEACON_SEARCH_SetInfoThanks(GameBeaconInfo *info, struct GameData *gameData, u16 trainerId);

void GAME_BEACON_SEARCH_SetFreeText(const struct Strbuf *text);

void GAME_BEACON_SEARCH_SetInfoFreeText(GameBeaconInfo *info, const struct Strbuf *text);

int GAME_BEACON_ACCESSOR_TableAddNewLogs(GameBeaconInfoTable *table);

int GAME_BEACON_ACCESSOR_TablePop(GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime);

void GAME_BEACON_ACCESSOR_TableMarkLogsNew(GameBeaconInfo *infoList);

int GAME_BEACON_ACCESSOR_TableAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, int receiveTime, int mode);

int GAME_BEACON_ACCESSOR_TableGetRingIndex(const GameBeaconInfoTable *table, int offset);

int GAME_BEACON_ACCESSOR_TableRingAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, u16 receiveTime, int *isNew);

int GAME_BEACON_ACCESSOR_TableRingGet(const GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime, int offset);

u8 GAME_BEACON_ACCESSOR_TableGetCount(const GameBeaconInfoTable *table);

extern const char GAME_BEACON_SEARCH_FileName[];

extern const struct NetInitParam GAME_BEACON_SEARCH_NetInit;

extern GameBeaconWork *GAME_BEACON_Work;

extern const u8 GAME_BEACON_SEARCH_PresetEventTable[5];

struct GameEvent *CALENDER_CreateTask(struct GameSystem *gameSystem, void *unused, u8 mode)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, CALENDER_OverlaySequenceEvent, sizeof(CalenderEventWork));
    CalenderEventWork *work = GAME_EVENT_GetWork(event);
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);

    work->gameData = gameData;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameSystem = gameSystem;
    work->mode = mode;
    return event;
}

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
    work->wihDwc = WIH_DWC_Create(4, 0x8005);
}

int GAME_BEACON_SEARCH_Exit(void *unused0, void *unused1, GameBeaconSearchWork *work)
{
    WIH_DWC_Delete(work->wihDwc);
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
                        GAME_COMM_RequestExit(gameComm, GAME_BEACON_SEARCH_StartConnectEvent, request);
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
        beacon = GFL_NET_GetScanResult(i);
        if (beacon == 0) {
            continue;
        }
        if (beacon->header.memberNum < beacon->header.memberMax) {
            if (best == none) {
                best = i;
            } else if (GAME_BEACON_SEARCH_SelectBetterEntry(beacon, GFL_NET_GetScanResult(best)) == beacon) {
                best = i;
            }
        } else {
            NET_WHPIPE_ReleaseEntry(i);
        }
    }
    if (best != -1) {
        *index = best;
        return GFL_NET_GetScanResult(best);
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
        GAME_COMM_Start(gameComm, 2, event);
    }
}

/* ------------------------------------------------------------------ *
 * Action setters: each pair checks that the action may be sent now,
 * writes it into the own beacon and sends the beacon.
 * ------------------------------------------------------------------ */

/* Battle start against a pokemon: special pokemon have their own action. */
void GAME_BEACON_SEARCH_SetBattlePokeStart(u32 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(monsNo);
    } else {
        GAME_BEACON_SEARCH_SetBattleWildPokeStart(monsNo);
    }
}

void GAME_BEACON_SEARCH_SetBattlePokeWin(u32 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(monsNo);
    } else {
        GAME_BEACON_SEARCH_SetBattleWildPokeWin(monsNo);
    }
}

void GAME_BEACON_SEARCH_SetBattleWildPokeStart(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x02)) {
        GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeStart(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x02;
    info->actionArg = monsNo;
    GAME_BEACON_SetDetailsBattleWildPoke(info, monsNo);
}

void GAME_BEACON_SEARCH_SetBattleWildPokeWin(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x03)) {
        GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleWildPokeWin(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x03;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleSpecialPokeStart(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x04)) {
        GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeStart(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x04;
    info->actionArg = monsNo;
    GAME_BEACON_SetDetailsBattleSpecialPoke(info, monsNo);
}

void GAME_BEACON_SEARCH_SetBattleSpecialPokeWin(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x05)) {
        GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleSpecialPokeWin(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x05;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleTrainerStart(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x06)) {
        GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleTrainerStart(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x06;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleTrainer(info, trainerId);
}

void GAME_BEACON_SEARCH_SetBattleTrainerWin(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x07)) {
        GAME_BEACON_SEARCH_SetInfoBattleTrainerWin(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleTrainerWin(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x07;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleLeaderStart(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x08)) {
        GAME_BEACON_SEARCH_SetInfoBattleLeaderStart(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleLeaderStart(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x08;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleLeader(info, trainerId);
}

void GAME_BEACON_SEARCH_SetBattleLeaderWin(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x09)) {
        GAME_BEACON_SEARCH_SetInfoBattleLeaderWin(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleLeaderWin(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x09;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetBattleBigFourStart(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x0A)) {
        GAME_BEACON_SEARCH_SetInfoBattleBigFourStart(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleBigFourStart(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x0A;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleBigFour(info, trainerId);
}

void GAME_BEACON_SEARCH_SetBattleBigFourWin(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x0B)) {
        GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoBattleBigFourWin(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x0B;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetVersionAction(u32 version)
{
    if (GAME_BEACON_CheckActionPriority(0x12)) {
        GAME_BEACON_SEARCH_SetInfoVersionAction(&GAME_BEACON_Work->own.info, version);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoVersionAction(GameBeaconInfo *info, u32 version)
{
    info->action = 0x12;
    info->infoVersion = (u8)version;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetItemFound(u32 itemNo)
{
    if (GAME_BEACON_CheckActionPriority(0x13)) {
        GAME_BEACON_SEARCH_SetInfoItemFound(&GAME_BEACON_Work->own.info, itemNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoItemFound(GameBeaconInfo *info, u32 itemNo)
{
    info->action = 0x13;
    info->actionData.value = itemNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetScriptEvent(void)
{
    if (GAME_BEACON_CheckActionPriority(0x15)) {
        GAME_BEACON_SEARCH_SetInfoScriptEvent(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoScriptEvent(GameBeaconInfo *info)
{
    info->action = 0x15;
    GAME_BEACON_ResetDetails(info);
}

/* Only the preset events of GAME_BEACON_SEARCH_PresetEventTable are sent. */
void GAME_BEACON_SEARCH_SetPresetEvent(u32 eventId)
{
    u32 i;

    if (GAME_BEACON_CheckActionPriority(0x16)) {
        for (i = 0; i < 5; i++) {
            if (eventId == GAME_BEACON_SEARCH_PresetEventTable[i]) {
                GAME_BEACON_SEARCH_SetInfoPresetEvent(&GAME_BEACON_Work->own.info, eventId);
                GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
                return;
            }
        }
    }
}

void GAME_BEACON_SEARCH_SetInfoPresetEvent(GameBeaconInfo *info, u32 eventId)
{
    info->action = 0x16;
    info->actionData.wordValue = eventId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFieldEvent(void)
{
    if (GAME_BEACON_CheckActionPriority(0x17)) {
        GAME_BEACON_SEARCH_SetInfoFieldEvent(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFieldEvent(GameBeaconInfo *info)
{
    info->action = 0x17;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetPokeEvent(u16 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x1E)) {
        GAME_BEACON_SEARCH_SetInfoPokeEvent(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoPokeEvent(GameBeaconInfo *info)
{
    info->action = 0x1E;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameA(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x1F)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameA(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameA(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x1F;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameB(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x20)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameB(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameB(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x20;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameC(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x21)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameC(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameC(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x21;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetEventBattleNameD(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x22)) {
        GAME_BEACON_SEARCH_SetInfoEventBattleNameD(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoEventBattleNameD(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x22;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetCountValue(u32 count)
{
    if (GAME_BEACON_CheckActionPriority(0x24)) {
        GAME_BEACON_SEARCH_SetInfoCountValue(&GAME_BEACON_Work->own.info, count);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoCountValue(GameBeaconInfo *info, u32 count)
{
    info->action = 0x24;
    info->actionData.value = count;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSymbolMapEnter(void)
{
    if (GAME_BEACON_CheckActionPriority(0x25)) {
        GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSymbolMapEnter(GameBeaconInfo *info)
{
    info->action = 0x25;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSymbolMapPoke(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x26)) {
        GAME_BEACON_SEARCH_SetInfoSymbolMapPoke(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSymbolMapPoke(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x26;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFacilityEnter(void)
{
    if (GAME_BEACON_CheckActionPriority(0x27)) {
        GAME_BEACON_SEARCH_SetInfoFacilityEnter(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFacilityEnter(GameBeaconInfo *info)
{
    info->action = 0x27;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFacilityExit(void)
{
    if (GAME_BEACON_CheckActionPriority(0x28)) {
        GAME_BEACON_SEARCH_SetInfoFacilityExit(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFacilityExit(GameBeaconInfo *info)
{
    info->action = 0x28;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetWordValue(u32 value)
{
    if (GAME_BEACON_CheckActionPriority(0x29)) {
        GAME_BEACON_SEARCH_SetInfoWordValue(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoWordValue(GameBeaconInfo *info, u32 value)
{
    info->action = 0x29;
    info->actionData.wordValue = value;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetWordClear(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2A)) {
        GAME_BEACON_SEARCH_SetInfoWordClear(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoWordClear(GameBeaconInfo *info)
{
    info->action = 0x2A;
    info->actionData.wordValue = 0;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSimpleEventA(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2B)) {
        GAME_BEACON_SEARCH_SetInfoSimpleEventA(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSimpleEventA(GameBeaconInfo *info)
{
    info->action = 0x2B;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetByteValue(u8 value)
{
    if (GAME_BEACON_CheckActionPriority(0x2C)) {
        GAME_BEACON_SEARCH_SetInfoByteValue(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoByteValue(GameBeaconInfo *info, u8 value)
{
    info->action = 0x2C;
    info->actionData.byteValue = value;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSimpleEventB(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2D)) {
        GAME_BEACON_SEARCH_SetInfoSimpleEventB(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSimpleEventB(GameBeaconInfo *info)
{
    info->action = 0x2D;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetSimpleEventC(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2E)) {
        GAME_BEACON_SEARCH_SetInfoSimpleEventC(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoSimpleEventC(GameBeaconInfo *info)
{
    info->action = 0x2E;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetNamedEvent(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x2F)) {
        GAME_BEACON_SEARCH_SetInfoNamedEvent(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoNamedEvent(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x2F;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetHalfwordValue(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0x30)) {
        GAME_BEACON_SEARCH_SetInfoHalfwordValue(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoHalfwordValue(GameBeaconInfo *info, u16 value)
{
    info->action = 0x30;
    info->actionData.value = value;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetThanks(struct GameData *gameData, u16 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x18)) {
        GAME_BEACON_SEARCH_SetInfoThanks(&GAME_BEACON_Work->own.info, gameData, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoThanks(GameBeaconInfo *info, struct GameData *gameData, u16 trainerId)
{
    WORDSET_CopyString(BEACON_GetThanksMessage(BEACON_GetBlock(GAME_DATA_GetSaveControl(gameData))), info->actionData.text, 9);
    info->action = 0x18;
    info->actionData.special.targetTrainerId = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void GAME_BEACON_SEARCH_SetFreeText(const struct Strbuf *text)
{
    if (GAME_BEACON_CheckActionPriority(0x31)) {
        GAME_BEACON_SEARCH_SetInfoFreeText(&GAME_BEACON_Work->own.info, text);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void GAME_BEACON_SEARCH_SetInfoFreeText(GameBeaconInfo *info, const struct Strbuf *text)
{
    STRBUF_ToChars(text, info->actionData.text, 9);
    info->action = 0x31;
    GAME_BEACON_ResetDetails(info);
}

/* ------------------------------------------------------------------ *
 * The table of received beacons (30 entries with their receive time).
 * ------------------------------------------------------------------ */

/* Moves the new beacon log entries into the table; returns how many. */
int GAME_BEACON_ACCESSOR_TableAddNewLogs(GameBeaconInfoTable *table)
{
    struct RtcTime time;
    int cursor;
    int added;
    int receiveTime;
    int logIndex;
    int tableIndex;

    added = 0;
    cursor = 0;
    GF_STANDARD_SetField00(&time);
    receiveTime = (u16)((time.hour << 8) | time.minute);
    for (;;) {
        logIndex = GAME_BEACON_GetNextNewLogIndex(&cursor);
        if (logIndex == 30) {
            break;
        }
        tableIndex = GAME_BEACON_ACCESSOR_TableAdd(table, &GAME_BEACON_GetLog(logIndex)->info, receiveTime, 0);
        if (tableIndex == 30) {
            break;
        }
        GAME_BEACON_ClearNewFlag(logIndex);
        added++;
    }
    return added;
}

/* Pops the first entry: copies it out and shifts the rest down. */
int GAME_BEACON_ACCESSOR_TablePop(GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime)
{
    int i;

    if (table->info[0].versionBit == 0)
        return 0;
    *info = table->info[0];
    *receiveTime = table->receiveTime[0];
    for (i = 1; i < 30; i++) {
        table->info[i - 1] = table->info[i];
        table->receiveTime[i - 1] = table->receiveTime[i];
    }
    MI_CpuFill8(&table->info[29], 0, sizeof(GameBeaconInfo));
    return 1;
}

/* Hands every used entry back to the beacon log as new. */
void GAME_BEACON_ACCESSOR_TableMarkLogsNew(GameBeaconInfo *infoList)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (infoList[i].versionBit == 0)
            break;
        GAME_BEACON_SetNewFlagByTrainerId(&infoList[i]);
    }
}

/*
 * Stores the beacon in the first free entry or over the entry of the same
 * trainer. When the table is full and mode is 1, the oldest entry is
 * dropped. Returns the entry used, or 30 when nothing was stored.
 */
int GAME_BEACON_ACCESSOR_TableAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, int receiveTime, int mode)
{
    int i;

    for (i = 0; i < 30; i++) {
        if (table->info[i].versionBit == 0 || info->trainerId == table->info[i].trainerId) {
            table->info[i] = *info;
            table->receiveTime[i] = receiveTime;
            return i;
        }
    }
    if (mode == 1) {
        MIi_CpuCopy32(&table->info[1], &table->info[0], 29 * sizeof(GameBeaconInfo));
        MIi_CpuCopy16(&table->receiveTime[1], &table->receiveTime[0], 29 * sizeof(u16));
        table->info[29] = *info;
        table->receiveTime[29] = receiveTime;
        return 29;
    }
    return 30;
}

/* Ring use of the table: entry at a signed offset from the head. */
int GAME_BEACON_ACCESSOR_TableGetRingIndex(const GameBeaconInfoTable *table, int offset)
{
    int head = table->head;

    if (offset < 0)
        return (head + offset + 30) % 30;
    return (head + offset) % 30;
}

/*
 * Ring insert: replaces the entry of the same trainer, else pushes a new
 * head. *isNew (optional) is 1 when a new entry was taken.
 */
int GAME_BEACON_ACCESSOR_TableRingAdd(GameBeaconInfoTable *table, const GameBeaconInfo *info, u16 receiveTime, int *isNew)
{
    int i;
    int index;

    if (isNew)
        *isNew = 0;
    for (i = 0; i < 30; i++) {
        index = GAME_BEACON_ACCESSOR_TableGetRingIndex(table, i);
        if (table->info[index].versionBit == 0)
            break;
        if (info->trainerId == table->info[index].trainerId) {
            table->info[index] = *info;
            table->receiveTime[index] = receiveTime;
            return i;
        }
    }
    if (isNew)
        *isNew = 1;
    index = GAME_BEACON_ACCESSOR_TableGetRingIndex(table, -1);
    table->info[index] = *info;
    table->receiveTime[index] = receiveTime;
    table->head = index;
    if (table->count < 30)
        table->count++;
    return 0;
}

int GAME_BEACON_ACCESSOR_TableRingGet(const GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime, int offset)
{
    int index = GAME_BEACON_ACCESSOR_TableGetRingIndex(table, offset);

    if (table->info[index].versionBit == 0)
        return 0;
    *info = table->info[index];
    *receiveTime = table->receiveTime[index];
    return 1;
}

u8 GAME_BEACON_ACCESSOR_TableGetCount(const GameBeaconInfoTable *table)
{
    return table->count;
}
