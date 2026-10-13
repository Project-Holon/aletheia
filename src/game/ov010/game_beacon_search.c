/*
 * file:     game_beacon_search.c
 * unit:     yes
 * function: func_02164B38, func_02164B6C, func_02164BC4, func_02164C04, func_02164C20, func_02164C38, func_02164C64, func_02164D6C, func_02164E04, func_02164E8C, func_02164EB4, func_02164F88, func_02164F8C, func_02164F90, func_02164F98, func_02164F9C, func_02164FC4, func_02164FD0, func_0216505C, func_02165078, func_02165094, func_021650BC, func_021650CC, func_021650F4, func_02165104, func_0216512C, func_0216513C, func_02165164, func_02165174, func_0216519C, func_021651AC, func_021651D4, func_021651E4, func_0216520C, func_0216521C, func_02165244, func_02165254, func_0216527C, func_0216528C, func_021652B4, func_021652C4, func_021652EC, func_0216530C, func_02165334, func_02165344, func_02165368, func_02165374, func_021653B4, func_021653C4, func_021653E8, func_021653F4, func_02165418, func_02165424, func_0216544C, func_02165468, func_02165490, func_021654AC, func_021654D4, func_021654F0, func_02165518, func_02165534, func_0216555C, func_0216556C, func_02165590, func_0216559C, func_021655C4, func_021655D4, func_021655F8, func_02165604, func_02165628, func_02165634, func_0216565C, func_0216566C, func_02165690, func_021656A0, func_021656C4, func_021656D0, func_021656F8, func_0216570C, func_02165730, func_0216573C, func_02165760, func_0216576C, func_02165794, func_021657B0, func_021657D8, func_021657E8, func_02165814, func_02165844, func_0216586C, func_02165888, func_021658D4, func_02165940, func_02165960, func_021659F0, func_02165A10, func_02165AC4, func_02165B04, func_02165B10, func_02165B2C, func_02165B5C, func_02165C10, func_02165C34, func_02165C48, func_02165C50, func_02165C58, func_02165C5C, func_02165C60, func_02165C78, func_02165C90, func_02165CB4, func_02165CC0, func_02165CD8, func_02165CE4, func_02165CE8, func_02165D08, func_02165D10, func_02165D20, func_02165D28, func_02165D34, func_02165D40, func_02165D48, func_02165D50, func_02165D6C, func_02165D8C, func_02165DAC, func_02165DBC, func_02165DF0, func_02165E24, func_02165E34, func_02165E78, func_02165E8C, func_02165E9C, func_02165EAC, func_02165EBC, func_02165ECC, func_02165F30, func_02165F64, func_02165F74, func_02165F84, func_02165F94, func_02165FA4, func_02165FB4
 * address:  0x02164B38
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02164A2C 0x02164A2C thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202647C  0x0202647C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   d_021729BC     0x021729BC  data  ov010  a1
 *   func_02030B50  0x02030B50  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02171C30     0x02171C30  data  ov010  a4
 *   func_02010360 0x02010360 thumb
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   func_0203CEAC 0x0203CEAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   GAME_BEACON_SendIfRequested  0x020267FC  thumb
 *   GAME_COMM_GetNotifyFlag  0x020264AC  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02158570  0x02158570  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0202640C  0x0202640C  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02177BF4  0x02177BF4  thumb  ov014
 *   func_02010498  0x02010498  thumb
 *   GFL_NET_EndDeviceWrapper  0x0203D0FC  arm
 *   GFL_NET_GetScanResultMac  0x0203CF3C  arm
 *   GAME_BEACON_ReceiveInfo  0x02026A60  thumb
 *   NET_WHPIPE_GetEntryKind  0x02178098  thumb ov014
 *   func_0203CF10  0x0203CF10  arm
 *   GAME_BEACON_GetMyInfo 0x020267E4 thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   GFL_NET_SYSTEM_CheckError  0x02039414  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_02087E60  0x02087E60  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   GAMESYSTEM_CanStartAutoComm  0x02012164  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_02026454  0x02026454  thumb
 *   func_020263D8  0x020263D8  thumb
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
 *   d_02171CA0      0x02171CA0  data  ov010  a1
 *   GAME_BEACON_CopyStrbufCodes  0x020270AC  thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C20C 0x0200C20C thumb
 *   func_0201F41C 0x0201F41C thumb
 *   func_02045A38  0x02045A38  arm
 *   func_0203F4CC 0x0203F4CC arm
 *   GAME_BEACON_GetNextNewLogIndex 0x02026CA0 thumb
 *   GAME_BEACON_GetLog 0x02026C1C thumb
 *   GAME_BEACON_ClearNewFlag 0x02026CE0 thumb
 *   GAME_BEACON_SetNewFlagByTrainerId   0x02026D04  thumb
 *   MIi_CpuCopy32  0x02082A90  arm
 *   MIi_CpuCopy16  0x02082A60  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   d_021729D4 0x021729D4 data a4
 *   d_02171CA8     0x02171CA8  data
 *   func_02045994  0x02045994  arm
 *   func_0200E3A4  0x0200E3A4  thumb
 *   OSi_GetOwnerInfoExBuffer  0x02087D1C  arm
 *   STRBUF_Clear  0x0204581C  arm
 *   func_02045924  0x02045924  arm
 *   d_02171CE8  0x02171CE8  data  a1
 */
#include "../arm9/game_beacon_types.h"

struct GameSystem;
struct GameEvent;
struct GameComm;
struct PlayerWork;
struct MyStatus;
struct SaveControl;
struct NetInitParam;
struct Strbuf;

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

/* The search work, 0x84 bytes, made in func_02164B6C. */
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

/* ------------------------------------------------------------------ *
 * The table of received beacons, 0xB08 bytes.
 * ------------------------------------------------------------------ */
typedef struct GameBeaconInfoTable {
    GameBeaconInfo info[30];    /* 0x000 */
    u16 receiveTime[30];        /* 0xAC8: hour << 8 | minute */
    u8  head;                   /* 0xB04: ring start */
    u8  count;                  /* 0xB05 */
} GameBeaconInfoTable;

typedef int (*GameBeaconActionCheckFunc)(const GameBeaconInfo *info);

/* Per-action attributes, 2 bytes. */
typedef struct GameBeaconActionAttr {
    u8 checkIndex;              /* index into d_02171CA8 */
    u8 group;
} GameBeaconActionAttr;

extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, int (*func)(struct GameEvent *, u32 *, void *), u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern int func_02164A2C(struct GameEvent *event, u32 *seq, void *work);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0202647C(struct GameComm *gameComm);
extern u32 func_0202648C(struct GameComm *gameComm);
extern void func_02030B50(u32 heapId);
extern void func_0203CBAC(const struct NetInitParam *init, void (*callback)(void *work), void *work);
extern u8 *func_02010360(int index, u32 heapId);
extern void WIH_DWC_Delete(u8 *wihDwc);
extern int func_0203CEAC(void (*callback)(void *work));
extern u32 func_020307B0(void *memory);
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern u8 func_02012E40(const struct GameData *gameData);
extern void func_02026400(struct GameComm *gameComm);
extern int func_02035390(void);
extern int func_020353B0(void);
extern void GAME_BEACON_SendIfRequested(void);
extern u32 GAME_COMM_GetNotifyFlag(struct GameComm *gameComm);
extern int func_02012B70(const struct GameData *gameData);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *playerWork);
extern int func_02158570(u16 zoneId);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0202640C(struct GameComm *gameComm, void (*callback)(void *work, int cancel), void *work);
extern void MI_CpuFill8(void *dst, u8 value, u32 size);
extern void func_02177BF4(u32 index);
extern void func_02010498(void);
extern void GFL_NET_EndDeviceWrapper(int mode);
extern u8 *GFL_NET_GetScanResultMac(u32 index);
extern int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info);
extern u8 NET_WHPIPE_GetEntryKind(u8 index);
extern void *func_0203CF10(u32 index);
extern void GAME_BEACON_GetMyInfo(GameBeaconInfo *info);
extern int func_0203D1B4(void);
extern u32 GFL_NET_SYSTEM_CheckError(void);
extern int OS_IsRunOnTwl(void);
extern OwnerFlags *func_02087E60(void);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern u32 func_02008530(const struct MyStatus *myStatus);
extern u32 GAMESYSTEM_CanStartAutoComm(const struct GameSystem *gameSystem);
extern int func_0203CD98(void);
extern u32 func_02026454(struct GameComm *gameComm);
extern void func_020263D8(struct GameComm *gameComm, u32 kind, void *work);
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
extern struct MyStatus *func_0200C0F0(struct SaveControl *saveControl);
extern const u16 *func_0200C20C(const struct MyStatus *myStatus);
extern void func_0201F41C(const u16 *src, u16 *dest, u32 length);
extern void func_02045A38(const struct Strbuf *str, u16 *dest, u32 length);
extern void func_0203F4CC(struct RtcTime *time);
extern int GAME_BEACON_GetNextNewLogIndex(int *cursor);
extern GameBeaconRecord *GAME_BEACON_GetLog(int index);
extern void GAME_BEACON_ClearNewFlag(u32 index);
extern int GAME_BEACON_SetNewFlagByTrainerId(const GameBeaconInfo *info);
extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void func_02045994(struct Strbuf *str, const u16 *src, u32 length);
extern u32 func_0200E3A4(const u8 *bits, int id);
extern const u16 *OSi_GetOwnerInfoExBuffer(void);
extern void STRBUF_Clear(struct Strbuf *str);
extern void func_02045924(struct Strbuf *str, const u16 *src);
struct GameEvent *func_02164B38(struct GameSystem *gameSystem, void *unused, u8 mode);
GameBeaconSearchWork *func_02164B6C(void *unused, struct GameSystem *gameSystem);
int func_02164BC4(int *seq, void *unused, GameBeaconSearchWork *work);
void func_02164C04(void *arg);
int func_02164C20(void *unused0, void *unused1, GameBeaconSearchWork *work);
int func_02164C38(void *unused0, void *unused1, GameBeaconSearchWork *work);
void func_02164C5C(void *arg);
void func_02164C64(void *unused, struct GameSystem *gameSystem, GameBeaconSearchWork *work);
GameBeaconSearchTarget *func_02164D6C(GameBeaconSearchWork *work, int *index);
GameBeaconSearchBeacon *func_02164E04(GameBeaconSearchWork *work, int *index);
GameBeaconSearchBeacon *func_02164E8C(GameBeaconSearchWork *work);
void func_02164EB4(GameBeaconSearchBeacon *beacon, struct GameData *gameData);
int func_02164F88(void);
int func_02164F8C(void);
int func_02164F90(void *unused0, void *unused1, GameBeaconSearchWork *work);
void func_02164F98(void);
GameBeaconSearchBeacon *func_02164F9C(GameBeaconSearchBeacon *beacon, GameBeaconSearchBeacon *best);
void func_02164FC4(GameBeaconSearchWork *work);
void func_02164FD0(void *arg, int cancel);
void func_0216505C(u32 monsNo);
void func_02165078(u32 monsNo);
void func_02165094(u32 monsNo);
void func_021650BC(GameBeaconInfo *info, u32 monsNo);
void func_021650CC(u32 monsNo);
void func_021650F4(GameBeaconInfo *info, u32 monsNo);
void func_02165104(u32 monsNo);
void func_0216512C(GameBeaconInfo *info, u32 monsNo);
void func_0216513C(u32 monsNo);
void func_02165164(GameBeaconInfo *info, u32 monsNo);
void func_02165174(u32 trainerId);
void func_0216519C(GameBeaconInfo *info, u32 trainerId);
void func_021651AC(u32 trainerId);
void func_021651D4(GameBeaconInfo *info, u32 trainerId);
void func_021651E4(u32 trainerId);
void func_0216520C(GameBeaconInfo *info, u32 trainerId);
void func_0216521C(u32 trainerId);
void func_02165244(GameBeaconInfo *info, u32 trainerId);
void func_02165254(u32 trainerId);
void func_0216527C(GameBeaconInfo *info, u32 trainerId);
void func_0216528C(u32 trainerId);
void func_021652B4(GameBeaconInfo *info, u32 trainerId);
void func_021652C4(u32 version);
void func_021652EC(GameBeaconInfo *info, u32 version);
void func_0216530C(u32 itemNo);
void func_02165334(GameBeaconInfo *info, u32 itemNo);
void func_02165344(void);
void func_02165368(GameBeaconInfo *info);
void func_02165374(u32 eventId);
void func_021653B4(GameBeaconInfo *info, u32 eventId);
void func_021653C4(void);
void func_021653E8(GameBeaconInfo *info);
void func_021653F4(u16 monsNo);
void func_02165418(GameBeaconInfo *info);
void func_02165424(const struct Strbuf *name);
void func_0216544C(GameBeaconInfo *info, const struct Strbuf *name);
void func_02165468(const struct Strbuf *name);
void func_02165490(GameBeaconInfo *info, const struct Strbuf *name);
void func_021654AC(const struct Strbuf *name);
void func_021654D4(GameBeaconInfo *info, const struct Strbuf *name);
void func_021654F0(const struct Strbuf *name);
void func_02165518(GameBeaconInfo *info, const struct Strbuf *name);
void func_02165534(u32 count);
void func_0216555C(GameBeaconInfo *info, u32 count);
void func_0216556C(void);
void func_02165590(GameBeaconInfo *info);
void func_0216559C(u32 monsNo);
void func_021655C4(GameBeaconInfo *info, u32 monsNo);
void func_021655D4(void);
void func_021655F8(GameBeaconInfo *info);
void func_02165604(void);
void func_02165628(GameBeaconInfo *info);
void func_02165634(u32 value);
void func_0216565C(GameBeaconInfo *info, u32 value);
void func_0216566C(void);
void func_02165690(GameBeaconInfo *info);
void func_021656A0(void);
void func_021656C4(GameBeaconInfo *info);
void func_021656D0(u8 value);
void func_021656F8(GameBeaconInfo *info, u8 value);
void func_0216570C(void);
void func_02165730(GameBeaconInfo *info);
void func_0216573C(void);
void func_02165760(GameBeaconInfo *info);
void func_0216576C(const struct Strbuf *name);
void func_02165794(GameBeaconInfo *info, const struct Strbuf *name);
void func_021657B0(u16 value);
void func_021657D8(GameBeaconInfo *info, u16 value);
void func_021657E8(struct GameData *gameData, u16 trainerId);
void func_02165814(GameBeaconInfo *info, struct GameData *gameData, u16 trainerId);
void func_02165844(const struct Strbuf *text);
void func_0216586C(GameBeaconInfo *info, const struct Strbuf *text);
int func_02165888(GameBeaconInfoTable *table);
int func_021658D4(GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime);
void func_02165940(GameBeaconInfo *infoList);
int func_02165960(GameBeaconInfoTable *table, const GameBeaconInfo *info, int receiveTime, int mode);
int func_021659F0(const GameBeaconInfoTable *table, int offset);
int func_02165A10(GameBeaconInfoTable *table, const GameBeaconInfo *info, u16 receiveTime, int *isNew);
int func_02165AC4(const GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime, int offset);
u8 func_02165B04(const GameBeaconInfoTable *table);
GameBeaconInfo *func_02165B10(u32 heapId);
GameBeaconInfoTable *func_02165B2C(u32 heapId);
int func_02165B5C(const GameBeaconInfo *info);
int func_02165C10(const GameBeaconInfo *info);
void func_02165C34(const GameBeaconInfo *info, struct Strbuf *name);
u32 func_02165C48(const GameBeaconInfo *info);
u32 func_02165C50(const GameBeaconInfo *info);
u8 func_02165C58(const GameBeaconInfo *info);
u8 func_02165C5C(const GameBeaconInfo *info);
u8 func_02165C60(const GameBeaconInfo *info);
u8 func_02165C78(const GameBeaconInfo *info);
void func_02165C90(const GameBeaconInfo *info, GameBeaconPms *pms);
u8 func_02165CB4(const GameBeaconInfo *info);
void func_02165CC0(u16 *rgb, const GameBeaconInfo *info);
u8 func_02165CD8(const GameBeaconInfo *info);
u16 func_02165CE4(const GameBeaconInfo *info);
u8 func_02165CE8(const GameBeaconInfo *info);
u8 func_02165D08(const GameBeaconInfo *info);
void func_02165D10(const GameBeaconInfo *info, u16 *hours, u16 *minutes);
u8 func_02165D20(const GameBeaconInfo *info);
u16 func_02165D28(const GameBeaconInfo *info);
u16 func_02165D34(const GameBeaconInfo *info);
u32 func_02165D40(const GameBeaconInfo *info);
u32 func_02165D48(const GameBeaconInfo *info);
void func_02165D50(const GameBeaconInfo *info, struct Strbuf *greeting);
void func_02165D6C(const GameBeaconInfo *info, struct Strbuf *name);
void func_02165D8C(const GameBeaconInfo *info, struct Strbuf *text);
unsigned func_02165DAC(const GameBeaconInfo *info);
u16 func_02165DBC(const GameBeaconInfo *info);
u16 func_02165DF0(const GameBeaconInfo *info);
u16 func_02165E24(const GameBeaconInfo *info);
u16 func_02165E34(const GameBeaconInfo *info);
u16 func_02165E78(const GameBeaconInfo *info);
u16 func_02165E8C(const GameBeaconInfo *info);
u16 func_02165E9C(const GameBeaconInfo *info);
u16 func_02165EAC(const GameBeaconInfo *info);
u16 func_02165EBC(const GameBeaconInfo *info);
void func_02165ECC(const GameBeaconInfo *info, struct Strbuf *nickname);
u16 func_02165F30(const GameBeaconInfo *info);
u32 func_02165F64(const GameBeaconInfo *info);
u16 func_02165F74(const GameBeaconInfo *info);
u32 func_02165F84(const GameBeaconInfo *info);
u8 func_02165F94(const GameBeaconInfo *info);
u16 func_02165FA4(const GameBeaconInfo *info);
u8 func_02165FB4(u16 action);
extern const char d_021729BC[];
extern const struct NetInitParam d_02171C30;
extern GameBeaconWork *GAME_BEACON_Work;
extern const u8 d_02171CA0[5];
extern const char d_021729D4[];
extern const GameBeaconActionCheckFunc d_02171CA8[];
extern const GameBeaconActionAttr d_02171CE8[];





struct GameEvent *func_02164B38(struct GameSystem *gameSystem, void *unused, u8 mode)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, func_02164A2C, sizeof(CalenderEventWork));
    CalenderEventWork *work = func_020124E8(event);
    struct GameData *gameData = func_020120F4(gameSystem);

    work->gameData = gameData;
    work->saveControl = func_02012EBC(gameData);
    work->gameSystem = gameSystem;
    work->mode = mode;
    return event;
}

/* Allocates and initialises the search work. */
GameBeaconSearchWork *func_02164B6C(void *unused, struct GameSystem *gameSystem)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameComm *gameComm = func_02012138(gameSystem);
    GameBeaconSearchWork *work = func_02030734(5, sizeof(GameBeaconSearchWork), 1, d_021729BC, 0x9c);

    work->gameData = gameData;
    work->lastZoneId = 0x1ab;
    if (func_0202647C(gameComm) == 2 && func_0202648C(gameComm) == 5) {
        func_02164FC4(work);
    }
    return work;
}

int func_02164BC4(int *seq, void *unused, GameBeaconSearchWork *work)
{
    switch (*seq) {
    case 0:
        func_02030B50(12);
        func_0203CBAC(&d_02171C30, func_02164C04, work);
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

void func_02164C04(void *arg)
{
    GameBeaconSearchWork *work = arg;

    work->state = 1;
    work->wihDwc = func_02010360(4, 0x8005);
}

int func_02164C20(void *unused0, void *unused1, GameBeaconSearchWork *work)
{
    WIH_DWC_Delete(work->wihDwc);
    func_0203CEAC(func_02164C5C);
    return 1;
}

int func_02164C38(void *unused0, void *unused1, GameBeaconSearchWork *work)
{
    if (work->state == 0) {
        func_020307B0(work);
        if (func_0200FB24()) {
            func_0200FBA0();
        }
        return 1;
    }
    return 0;
}

void func_02164C5C(void *arg)
{
    GameBeaconSearchWork *work = arg;

    work->state = 0;
}

static inline int PAD_DetectFold(void)
{
    return (*(vu16 *)0x02FFFFA8 & 0x8000) >> 15;
}

void func_02164C64(void *unused, struct GameSystem *gameSystem, GameBeaconSearchWork *work)
{
    struct GameComm *gameComm;
    struct GameData *gameData;
    int index;
    GameBeaconSearchTarget *target;
    GameBeaconConnectRequest *request;
    u16 zoneId;

    gameComm = func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    index = 0;
    if (func_02012E40(gameData) == 1)
        return;
    if (func_0200FB24()) {
        func_02026400(gameComm);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1) {
        func_02026400(gameComm);
        return;
    }
    if (work->scanDelay != 0)
        work->scanDelay--;
    GAME_BEACON_SendIfRequested();
    target = func_02164D6C(work, &index);
    if (target != 0) {
        if (target->beaconType == 2) {
            if (!PAD_DetectFold() && !GAME_COMM_GetNotifyFlag(gameComm) && !func_02012B70(gameData)) {
                zoneId = func_02012AC8(func_020127A4(gameData));
                if (zoneId != work->lastZoneId) {
                    work->lastZoneId = zoneId;
                    if (func_02158570(zoneId) == 1) {
                        request = func_02030734(0x8005, sizeof(GameBeaconConnectRequest), 1, d_021729BC, 0x154);
                        request->gameSystem = gameSystem;
                        MI_CpuCopy8(target->macAddress, request->macAddress, 6);
                        func_0202640C(gameComm, func_02164FD0, request);
                        goto end; /* the connect path skips the target reset; bytes need the goto */
                    }
                }
            }
            MI_CpuFill8(&work->target, 0, sizeof(GameBeaconSearchTarget));
            func_02177BF4(index);
        } else {
            target->beaconType = 0;
        }
    }
end:
    func_02010498();
}

GameBeaconSearchTarget *func_02164D6C(GameBeaconSearchWork *work, int *index)
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
        beacon = func_02164E04(work, index);
        if (beacon != 0) {
            if (beacon->header.busy != 0) {
                func_02177BF4(*index);
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
                func_02177BF4(*index);
            }
        }
    }
    if (target->beaconType == 0) {
        target = 0;
    }
    return target;
}

GameBeaconSearchBeacon *func_02164E04(GameBeaconSearchWork *work, int *index)
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
        beacon = func_0203CF10(i);
        if (beacon == 0) {
            continue;
        }
        if (beacon->header.memberNum < beacon->header.memberMax) {
            if (best == none) {
                best = i;
            } else if (func_02164F9C(beacon, func_0203CF10(best)) == beacon) {
                best = i;
            }
        } else {
            func_02177BF4(i);
        }
    }
    if (best != -1) {
        *index = best;
        return func_0203CF10(best);
    }
    return 0;
}

GameBeaconSearchBeacon *func_02164E8C(GameBeaconSearchWork *work)
{
    func_02164EB4(&work->beacon, work->gameData);
    GAME_BEACON_GetMyInfo(&work->beacon.info);
    work->beacon.header.kind = 2;
    return &work->beacon;
}

void func_02164EB4(GameBeaconSearchBeacon *beacon, struct GameData *gameData)
{
    int wirelessOn;
    int lidClosed;

    MI_CpuFill8(beacon, 0, sizeof(GameBeaconSearchBeacon));
    beacon->header.beaconType = 3;
    beacon->header.memberNum = func_0203D1B4();
    beacon->header.memberMax = 3;
    beacon->header.busy = GFL_NET_SYSTEM_CheckError();
    beacon->header.kind = 0;
    beacon->header.trainerId = func_02008530(func_02012944(gameData));
    beacon->header.isTwl = OS_IsRunOnTwl();
    beacon->header.twlWirelessOn = 0;
    lidClosed = PAD_DetectFold();
    beacon->header.lidClosed = lidClosed;
    if (beacon->header.isTwl == 1) {
        wirelessOn = 1;
        if (func_02087E60()->wirelessOn == 0 || func_02087E60()->parentalWirelessOn == 0)
            wirelessOn = 0;
        beacon->header.twlWirelessOn = wirelessOn;
    }
}

int func_02164F88(void)
{
    return sizeof(GameBeaconSearchBeacon);
}

int func_02164F8C(void)
{
    return 1;
}

int func_02164F90(void *unused0, void *unused1, GameBeaconSearchWork *work)
{
    work->connected = 1;
    return 1;
}

void func_02164F98(void)
{
}

/* Of two scanned beacons, keep the one that has room and fewer members. */
GameBeaconSearchBeacon *func_02164F9C(GameBeaconSearchBeacon *beacon, GameBeaconSearchBeacon *best)
{
    if (beacon->header.busy)
        return best;
    if (beacon->header.memberNum >= beacon->header.memberMax || beacon->header.memberNum < best->header.memberNum)
        return best;
    return beacon;
}

void func_02164FC4(GameBeaconSearchWork *work)
{
    work->scanDelay = 0x708;
}

/*
 * Connect callback of the request made in func_02164C64: when no other
 * comm is running, it hands a 0x10-byte connect event to the comm system.
 */
void func_02164FD0(void *arg, int cancel)
{
    u8 macAddress[6];
    GameBeaconConnectRequest *request = arg;
    struct GameSystem *gameSystem = request->gameSystem;
    struct GameComm *gameComm;
    GameBeaconConnectEvent *event;

    MI_CpuCopy8(request->macAddress, macAddress, 6);
    gameComm = func_02012138(gameSystem);
    func_020307B0(request);
    if (cancel == 0 && GAMESYSTEM_CanStartAutoComm(gameSystem) == 1 && GAME_COMM_GetNotifyFlag(gameComm) == 0
        && func_0203CD98() == 0 && func_02026454(gameComm) == 0) {
        event = func_02030734(5, sizeof(GameBeaconConnectEvent), 1, d_021729BC, 0x287);
        event->gameSystem = gameSystem;
        event->gameComm = func_02012138(gameSystem);
        MI_CpuCopy8(macAddress, event->macAddress, 6);
        func_020263D8(gameComm, 2, event);
    }
}
/* ------------------------------------------------------------------ *
 * Action setters: each pair checks that the action may be sent now,
 * writes it into the own beacon and sends the beacon.
 * ------------------------------------------------------------------ */

/* Battle start against a pokemon: special pokemon have their own action. */
void func_0216505C(u32 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        func_02165104(monsNo);
    } else {
        func_02165094(monsNo);
    }
}

void func_02165078(u32 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        func_0216513C(monsNo);
    } else {
        func_021650CC(monsNo);
    }
}

void func_02165094(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x02)) {
        func_021650BC(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021650BC(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x02;
    info->actionArg = monsNo;
    GAME_BEACON_SetDetailsBattleWildPoke(info, monsNo);
}

void func_021650CC(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x03)) {
        func_021650F4(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021650F4(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x03;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void func_02165104(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x04)) {
        func_0216512C(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216512C(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x04;
    info->actionArg = monsNo;
    GAME_BEACON_SetDetailsBattleSpecialPoke(info, monsNo);
}

void func_0216513C(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x05)) {
        func_02165164(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165164(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x05;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void func_02165174(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x06)) {
        func_0216519C(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216519C(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x06;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleTrainer(info, trainerId);
}

void func_021651AC(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x07)) {
        func_021651D4(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021651D4(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x07;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void func_021651E4(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x08)) {
        func_0216520C(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216520C(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x08;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleLeader(info, trainerId);
}

void func_0216521C(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x09)) {
        func_02165244(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165244(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x09;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void func_02165254(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x0A)) {
        func_0216527C(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216527C(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x0A;
    info->actionData.value = trainerId;
    GAME_BEACON_SetDetailsBattleBigFour(info, trainerId);
}

void func_0216528C(u32 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x0B)) {
        func_021652B4(&GAME_BEACON_Work->own.info, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021652B4(GameBeaconInfo *info, u32 trainerId)
{
    info->action = 0x0B;
    info->actionData.value = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void func_021652C4(u32 version)
{
    if (GAME_BEACON_CheckActionPriority(0x12)) {
        func_021652EC(&GAME_BEACON_Work->own.info, version);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021652EC(GameBeaconInfo *info, u32 version)
{
    info->action = 0x12;
    info->infoVersion = (u8)version;
    GAME_BEACON_ResetDetails(info);
}

void func_0216530C(u32 itemNo)
{
    if (GAME_BEACON_CheckActionPriority(0x13)) {
        func_02165334(&GAME_BEACON_Work->own.info, itemNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165334(GameBeaconInfo *info, u32 itemNo)
{
    info->action = 0x13;
    info->actionData.value = itemNo;
    GAME_BEACON_ResetDetails(info);
}

void func_02165344(void)
{
    if (GAME_BEACON_CheckActionPriority(0x15)) {
        func_02165368(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165368(GameBeaconInfo *info)
{
    info->action = 0x15;
    GAME_BEACON_ResetDetails(info);
}

/* Only the preset events of d_02171CA0 are sent. */
void func_02165374(u32 eventId)
{
    u32 i;

    if (GAME_BEACON_CheckActionPriority(0x16)) {
        for (i = 0; i < 5; i++) {
            if (eventId == d_02171CA0[i]) {
                func_021653B4(&GAME_BEACON_Work->own.info, eventId);
                GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
                return;
            }
        }
    }
}

void func_021653B4(GameBeaconInfo *info, u32 eventId)
{
    info->action = 0x16;
    info->actionData.wordValue = eventId;
    GAME_BEACON_ResetDetails(info);
}

void func_021653C4(void)
{
    if (GAME_BEACON_CheckActionPriority(0x17)) {
        func_021653E8(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021653E8(GameBeaconInfo *info)
{
    info->action = 0x17;
    GAME_BEACON_ResetDetails(info);
}

void func_021653F4(u16 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x1E)) {
        func_02165418(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165418(GameBeaconInfo *info)
{
    info->action = 0x1E;
    GAME_BEACON_ResetDetails(info);
}

void func_02165424(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x1F)) {
        func_0216544C(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216544C(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x1F;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void func_02165468(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x20)) {
        func_02165490(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165490(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x20;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void func_021654AC(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x21)) {
        func_021654D4(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021654D4(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x21;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void func_021654F0(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x22)) {
        func_02165518(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165518(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x22;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void func_02165534(u32 count)
{
    if (GAME_BEACON_CheckActionPriority(0x24)) {
        func_0216555C(&GAME_BEACON_Work->own.info, count);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216555C(GameBeaconInfo *info, u32 count)
{
    info->action = 0x24;
    info->actionData.value = count;
    GAME_BEACON_ResetDetails(info);
}

void func_0216556C(void)
{
    if (GAME_BEACON_CheckActionPriority(0x25)) {
        func_02165590(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165590(GameBeaconInfo *info)
{
    info->action = 0x25;
    GAME_BEACON_ResetDetails(info);
}

void func_0216559C(u32 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0x26)) {
        func_021655C4(&GAME_BEACON_Work->own.info, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021655C4(GameBeaconInfo *info, u32 monsNo)
{
    info->action = 0x26;
    info->actionArg = monsNo;
    GAME_BEACON_ResetDetails(info);
}

void func_021655D4(void)
{
    if (GAME_BEACON_CheckActionPriority(0x27)) {
        func_021655F8(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021655F8(GameBeaconInfo *info)
{
    info->action = 0x27;
    GAME_BEACON_ResetDetails(info);
}

void func_02165604(void)
{
    if (GAME_BEACON_CheckActionPriority(0x28)) {
        func_02165628(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165628(GameBeaconInfo *info)
{
    info->action = 0x28;
    GAME_BEACON_ResetDetails(info);
}

void func_02165634(u32 value)
{
    if (GAME_BEACON_CheckActionPriority(0x29)) {
        func_0216565C(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216565C(GameBeaconInfo *info, u32 value)
{
    info->action = 0x29;
    info->actionData.wordValue = value;
    GAME_BEACON_ResetDetails(info);
}

void func_0216566C(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2A)) {
        func_02165690(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165690(GameBeaconInfo *info)
{
    info->action = 0x2A;
    info->actionData.wordValue = 0;
    GAME_BEACON_ResetDetails(info);
}

void func_021656A0(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2B)) {
        func_021656C4(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021656C4(GameBeaconInfo *info)
{
    info->action = 0x2B;
    GAME_BEACON_ResetDetails(info);
}

void func_021656D0(u8 value)
{
    if (GAME_BEACON_CheckActionPriority(0x2C)) {
        func_021656F8(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021656F8(GameBeaconInfo *info, u8 value)
{
    info->action = 0x2C;
    info->actionData.byteValue = value;
    GAME_BEACON_ResetDetails(info);
}

void func_0216570C(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2D)) {
        func_02165730(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165730(GameBeaconInfo *info)
{
    info->action = 0x2D;
    GAME_BEACON_ResetDetails(info);
}

void func_0216573C(void)
{
    if (GAME_BEACON_CheckActionPriority(0x2E)) {
        func_02165760(&GAME_BEACON_Work->own.info);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165760(GameBeaconInfo *info)
{
    info->action = 0x2E;
    GAME_BEACON_ResetDetails(info);
}

void func_0216576C(const struct Strbuf *name)
{
    if (GAME_BEACON_CheckActionPriority(0x2F)) {
        func_02165794(&GAME_BEACON_Work->own.info, name);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165794(GameBeaconInfo *info, const struct Strbuf *name)
{
    info->action = 0x2F;
    GAME_BEACON_CopyStrbufCodes(name, info->actionData.nickname);
    GAME_BEACON_ResetDetails(info);
}

void func_021657B0(u16 value)
{
    if (GAME_BEACON_CheckActionPriority(0x30)) {
        func_021657D8(&GAME_BEACON_Work->own.info, value);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_021657D8(GameBeaconInfo *info, u16 value)
{
    info->action = 0x30;
    info->actionData.value = value;
    GAME_BEACON_ResetDetails(info);
}

void func_021657E8(struct GameData *gameData, u16 trainerId)
{
    if (GAME_BEACON_CheckActionPriority(0x18)) {
        func_02165814(&GAME_BEACON_Work->own.info, gameData, trainerId);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_02165814(GameBeaconInfo *info, struct GameData *gameData, u16 trainerId)
{
    func_0201F41C(func_0200C20C(func_0200C0F0(func_02012EBC(gameData))), info->actionData.text, 9);
    info->action = 0x18;
    info->actionData.special.targetTrainerId = trainerId;
    GAME_BEACON_ResetDetails(info);
}

void func_02165844(const struct Strbuf *text)
{
    if (GAME_BEACON_CheckActionPriority(0x31)) {
        func_0216586C(&GAME_BEACON_Work->own.info, text);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

void func_0216586C(GameBeaconInfo *info, const struct Strbuf *text)
{
    func_02045A38(text, info->actionData.text, 9);
    info->action = 0x31;
    GAME_BEACON_ResetDetails(info);
}

/* ------------------------------------------------------------------ *
 * The table of received beacons (30 entries with their receive time).
 * ------------------------------------------------------------------ */

/* Moves the new beacon log entries into the table; returns how many. */
int func_02165888(GameBeaconInfoTable *table)
{
    struct RtcTime time;
    int cursor;
    int added;
    int receiveTime;
    int logIndex;
    int tableIndex;

    added = 0;
    cursor = 0;
    func_0203F4CC(&time);
    receiveTime = (u16)((time.hour << 8) | time.minute);
    for (;;) {
        logIndex = GAME_BEACON_GetNextNewLogIndex(&cursor);
        if (logIndex == 30) {
            break;
        }
        tableIndex = func_02165960(table, &GAME_BEACON_GetLog(logIndex)->info, receiveTime, 0);
        if (tableIndex == 30) {
            break;
        }
        GAME_BEACON_ClearNewFlag(logIndex);
        added++;
    }
    return added;
}

/* Pops the first entry: copies it out and shifts the rest down. */
int func_021658D4(GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime)
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
void func_02165940(GameBeaconInfo *infoList)
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
int func_02165960(GameBeaconInfoTable *table, const GameBeaconInfo *info, int receiveTime, int mode)
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
int func_021659F0(const GameBeaconInfoTable *table, int offset)
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
int func_02165A10(GameBeaconInfoTable *table, const GameBeaconInfo *info, u16 receiveTime, int *isNew)
{
    int i;
    int index;

    if (isNew)
        *isNew = 0;
    for (i = 0; i < 30; i++) {
        index = func_021659F0(table, i);
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
    index = func_021659F0(table, -1);
    table->info[index] = *info;
    table->receiveTime[index] = receiveTime;
    table->head = index;
    if (table->count < 30)
        table->count++;
    return 0;
}

int func_02165AC4(const GameBeaconInfoTable *table, GameBeaconInfo *info, u16 *receiveTime, int offset)
{
    int index = func_021659F0(table, offset);

    if (table->info[index].versionBit == 0)
        return 0;
    *info = table->info[index];
    *receiveTime = table->receiveTime[index];
    return 1;
}

u8 func_02165B04(const GameBeaconInfoTable *table)
{
    return table->count;
}

GameBeaconInfo *func_02165B10(u32 heapId)
{
    return func_02030734(heapId, sizeof(GameBeaconInfo), 1, d_021729D4, 0x1b3);
}

GameBeaconInfoTable *func_02165B2C(u32 heapId)
{
    GameBeaconInfoTable *table = func_02030734(heapId, sizeof(GameBeaconInfoTable), 1, d_021729D4, 0x1c1);

    table->head = 0;
    table->count = 0;
    return table;
}

/* ------------------------------------------------------------------ *
 * Beacon info accessors.
 * ------------------------------------------------------------------ */

/* Returns 1 when a field is out of range or the action check fails. */
int func_02165B5C(const GameBeaconInfo *info)
{
    if (info->action == 0 || info->action >= 0x33)
        return 1;
    if (info->detailsPms.bits.detailsType >= 6)
        return 1;
    if (info->researchTeamRank >= 6)
        return 1;
    if (info->playHours > 999 || info->playMinutes > 59)
        return 1;
    if (info->infoVersion > 0x2D && info->infoVersion != 0x30)
        return 1;
    if (info->zoneId >= 427 || info->townmapRootZoneId >= 427)
        return 1;
    if (info->thanksCount > 99999 || info->passCount > 99999)
        return 1;
    if (d_02171CA8[func_02165FB4(info->action)](info) != 0)
        return 1;
    return 0;
}

int func_02165C10(const GameBeaconInfo *info)
{
    switch (info->action) {
    case 0x19:
    case 0x1A:
    case 0x1B:
    case 0x32:
        return 1;
    }
    return 0;
}

void func_02165C34(const GameBeaconInfo *info, struct Strbuf *name)
{
    func_02045994(name, info->name, 8);
}

u32 func_02165C48(const GameBeaconInfo *info)
{
    return info->pmVersion;
}

u32 func_02165C50(const GameBeaconInfo *info)
{
    return info->language;
}

u8 func_02165C58(const GameBeaconInfo *info)
{
    return info->nation;
}

u8 func_02165C5C(const GameBeaconInfo *info)
{
    return info->area;
}

/* Questionnaire answers: 0xFF when the question has no answer. */
u8 func_02165C60(const GameBeaconInfo *info)
{
    u32 answer = func_0200E3A4(info->questionnaire, 0x1a);

    if (answer == 0)
        return 0xff;
    return answer;
}

u8 func_02165C78(const GameBeaconInfo *info)
{
    u32 answer = func_0200E3A4(info->questionnaire, 0x19);

    if (answer == 0)
        return 0xff;
    return answer;
}

void func_02165C90(const GameBeaconInfo *info, GameBeaconPms *pms)
{
    pms->sentenceType = info->detailsPms.bits.pmsSentenceType;
    pms->sentenceId = info->detailsPms.bits.pmsSentenceId;
    pms->word[0] = info->pmsWord[0];
    pms->word[1] = info->pmsWord[1];
}

u8 func_02165CB4(const GameBeaconInfo *info)
{
    return info->researchTeamRank;
}

/* The owner color table has 16 entries. */
void func_02165CC0(u16 *rgb, const GameBeaconInfo *info)
{
    int color = info->favoriteColor;
    const u16 *colorTable = OSi_GetOwnerInfoExBuffer();

    *rgb = colorTable[color & 0xF];
}

u8 func_02165CD8(const GameBeaconInfo *info)
{
    return info->favoriteColor;
}

u16 func_02165CE4(const GameBeaconInfo *info)
{
    return info->trainerId;
}

/* Trainer appearance: the female ones follow the 8 male ones. */
u8 func_02165CE8(const GameBeaconInfo *info)
{
    if (info->sex == 0) {
        return info->trainerView;
    }
    return info->trainerView + 8;
}

u8 func_02165D08(const GameBeaconInfo *info)
{
    return info->sex;
}

void func_02165D10(const GameBeaconInfo *info, u16 *hours, u16 *minutes)
{
    *hours = info->playHours;
    *minutes = info->playMinutes;
}

u8 func_02165D20(const GameBeaconInfo *info)
{
    return info->infoVersion;
}

u16 func_02165D28(const GameBeaconInfo *info)
{
    return info->zoneId;
}

u16 func_02165D34(const GameBeaconInfo *info)
{
    return info->townmapRootZoneId;
}

u32 func_02165D40(const GameBeaconInfo *info)
{
    return info->passCount;
}

u32 func_02165D48(const GameBeaconInfo *info)
{
    return info->thanksCount;
}

void func_02165D50(const GameBeaconInfo *info, struct Strbuf *greeting)
{
    STRBUF_Clear(greeting);
    func_02045994(greeting, info->greeting, 9);
}

void func_02165D6C(const GameBeaconInfo *info, struct Strbuf *name)
{
    if (info->action != 0x18) {
        STRBUF_Clear(name);
    } else {
        func_02045924(name, info->actionData.text);
    }
}

void func_02165D8C(const GameBeaconInfo *info, struct Strbuf *text)
{
    if (info->action != 0x31) {
        STRBUF_Clear(text);
    } else {
        func_02045924(text, info->actionData.text);
    }
}

unsigned func_02165DAC(const GameBeaconInfo *info)
{
    unsigned type = info->detailsPms.bits.detailsType;

    if (type >= 6)
        type = 5;
    return type;
}

u16 func_02165DBC(const GameBeaconInfo *info)
{
    unsigned type = info->detailsPms.bits.detailsType;
    unsigned trainerNo = info->detailsValue;

    switch (type) {
    case 2:
    case 3:
    case 4:
        if (trainerNo == 0 || trainerNo >= 616)
            trainerNo = 1;
        return trainerNo;
    default:
        return 1;
    }
}

u16 func_02165DF0(const GameBeaconInfo *info)
{
    unsigned type = info->detailsPms.bits.detailsType;
    unsigned monsNo = info->detailsValue;

    switch (type) {
    case 0:
    case 1:
        if (monsNo == 0 || monsNo > 649)
            monsNo = 504;
        return monsNo;
    default:
        return 504;
    }
}

u16 func_02165E24(const GameBeaconInfo *info)
{
    u16 action = info->action;

    if (action == 0 || action >= 0x33)
        action = 1;
    return action;
}

u16 func_02165E34(const GameBeaconInfo *info)
{
    switch (info->action) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 14:
    case 15:
    case 17:
    case 38:
        return info->actionArg;
    }
    return 0x1F8;
}

u16 func_02165E78(const GameBeaconInfo *info)
{
    if (info->action == 0x13 || info->action == 0x23)
        return info->actionData.value;
    return 0x11;
}

u16 func_02165E8C(const GameBeaconInfo *info)
{
    if (info->action == 0x24)
        return info->actionData.value;
    return 1;
}

u16 func_02165E9C(const GameBeaconInfo *info)
{
    if (info->action == 0x19)
        return info->actionData.special.monsNo;
    return 0x1F8;
}

u16 func_02165EAC(const GameBeaconInfo *info)
{
    if (info->action == 0x1A)
        return info->actionData.special.itemNo;
    return 0x11;
}

u16 func_02165EBC(const GameBeaconInfo *info)
{
    if (info->action == 0x32)
        return info->actionData.special.serial;
    return 0;
}

/* The case list has no effect; the original keeps it after the copy. */
void func_02165ECC(const GameBeaconInfo *info, struct Strbuf *nickname)
{
    STRBUF_Clear(nickname);
    func_02045994(nickname, info->actionData.nickname, 11);
    switch (info->action) {
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 38:
    case 47:
        return;
    }
}

u16 func_02165F30(const GameBeaconInfo *info)
{
    switch (info->action) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return info->actionData.value;
    }
    return 1;
}

u32 func_02165F64(const GameBeaconInfo *info)
{
    if (info->action == 0x16)
        return info->actionData.wordValue;
    return 1;
}

u16 func_02165F74(const GameBeaconInfo *info)
{
    if (info->action == 0x14)
        return info->actionData.value;
    return 1;
}

u32 func_02165F84(const GameBeaconInfo *info)
{
    if (info->action == 0x29)
        return info->actionData.wordValue;
    return 1;
}

u8 func_02165F94(const GameBeaconInfo *info)
{
    if (info->action == 0x2C)
        return info->actionData.byteValue;
    return 0;
}

u16 func_02165FA4(const GameBeaconInfo *info)
{
    if (info->action == 0x30)
        return info->actionData.value;
    return 0;
}

u8 func_02165FB4(u16 action)
{
    return d_02171CE8[action].checkIndex;
}
