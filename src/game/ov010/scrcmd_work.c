/*
 * file:     scrcmd_work.c
 * unit:     yes
 * function: SCRCMD_WORK_CreateCommon, SCRCMD_WORK_DeleteCommon, SCRCMD_WORK_Create, SCRCMD_WORK_Delete, SCRCMD_WORK_GetHeapId, SCRCMD_WORK_GetScriptId, SCRCMD_WORK_GetCallMode, SCRCMD_WORK_GetCallParam, SCRCMD_WORK_GetGameSystem, SCRCMD_WORK_GetGameData, SCRCMD_WORK_GetOccupyInfo, SCRCMD_WORK_GetScriptWork, SCRCMD_WORK_GetMenuHeap, SCRCMD_WORK_GetMsgData, SCRCMD_WORK_GetMsgDataId, SCRCMD_WORK_SetMsgWindow, SCRCMD_WORK_GetMsgWindow, SCRCMD_WORK_SetTimeIcon, SCRCMD_WORK_GetTimeIcon, SCRCMD_WORK_GetWordSetWork, SCRCMD_WORK_SetTargetObject, SCRCMD_WORK_GetTargetObject, SCRCMD_WORK_GetWindowState, SCRCMD_WORK_SetWindowState, SCRCMD_WORK_GetWindowKind, SCRCMD_WORK_SetWindowKind, SCRCMD_WORK_SetWaitCount, SCRCMD_WORK_CheckAnimeTasks, SCRCMD_WORK_DeleteAnimeTasks, SCRCMD_WORK_LoadMsgData, SCRCMD_WORK_InitMenu, SCRCMD_WORK_AddMenuItem, SCRCMD_WORK_StartMenu, SCRCMD_WORK_DeleteMenu, SCRCMD_WORK_WaitMenu, SCRCMD_WORK_WaitMenuOrCancel, SCRCMD_WORK_MenuCursorCallback, SCRCMD_WORK_SaveScriptState, SCRCMD_WORK_RestoreScriptState, SCRCMD_WORK_SetChildScriptIndex, SCRCMD_WORK_GetChildScriptIndex, SCRCMD_WORK_CmdGetRomVersion, SCRCMD_WORK_CmdToggleConfigFlag, SCRCMD_WORK_CmdGetConfigFlag, SCRCMD_WORK_CmdGetRandom, SCRCMD_WORK_CmdGetMsgDataId, SCRCMD_WORK_CmdGetSaveRecord, SCRCMD_WORK_CmdGetFieldRecordA, SCRCMD_WORK_CmdGetFieldRecordB, SCRCMD_WORK_CmdGetFieldRecordPair, SCRCMD_WORK_CmdGetFieldRecordPairB, SCRCMD_WORK_CmdGetSeason, SCRCMD_WORK_CmdGetBirthday, SCRCMD_WORK_CmdGetPlayerRomCode, SCRCMD_WORK_CmdCheckMiscFlag, SCRCMD_WORK_CmdSetMiscFlag, SCRCMD_WORK_CmdGetMiscCount, SCRCMD_WORK_CmdGetSaveStatus, SCRCMD_WORK_CmdGetScriptId, SCRCMD_WORK_CmdSetWarpDestination, SCRCMD_WORK_CmdSetSpecialLocationHere, SCRCMD_WORK_CmdSetSpecialLocation, SCRCMD_WORK_CmdSetMapReplaceFlag, SCRCMD_WORK_CmdCheckMapReplaceFlag, SCRCMD_WORK_CmdRegisterZukanSeen, SCRCMD_WORK_CmdGetZukanSeenCount, SCRCMD_WORK_CmdGetZukanGetCount, SCRCMD_WORK_CmdSetZukanFlagA, SCRCMD_WORK_CmdGetZukanNationalFlag, SCRCMD_WORK_CmdSetZukanFlagB, SCRCMD_WORK_CmdGetButtonMode, SCRCMD_WORK_CmdSetFixedEventFlag, SCRCMD_WORK_CmdSetBoxFlags, SCRCMD_WORK_CmdGetPlayerSaveValue, SCRCMD_WORK_CmdGetMiscByte, SCRCMD_WORK_CmdSetMiscByte, SCRCMD_WORK_CmdCheckMiscByte, SCRCMD_WORK_CmdCheckExtraSaveData, SCRCMD_WORK_CmdEventDataSetA, SCRCMD_WORK_CmdEventDataSetB, SCRCMD_WORK_CmdEventDataSetC, SCRCMD_WORK_CmdSetEventFlagOffset, SCRCMD_WORK_CmdResetEventFlagOffset, SCRCMD_WORK_CmdCheckEventFlagOffset, SCRCMD_WORK_CmdEndFieldCommandA, SCRCMD_WORK_CmdCheckFieldModeA, SCRCMD_WORK_CmdEndFieldCommandB, SCRCMD_WORK_CmdCheckFieldModeB, SCRCMD_WORK_CmdLookupTable
 * address:  0x0215A514
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
 *   func_0201296C  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   SCRCMD_WORK_GetChildScriptIndex  0x0215AA4C  thumb  ov010
 *   SCRCMD_WORK_RestoreScriptState  0x0215AA34  thumb  ov010
 *   SCRCMD_WORK_SetChildScriptIndex  0x0215AA48  thumb  ov010
 *   SCRCMD_WORK_SaveScriptState  0x0215AA24  thumb  ov010
 *   func_02011290  0x02011290  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   func_020120F4  0x020120F4  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02030734  0x02030734  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020307B0  0x020307B0  arm
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   ZONEDATA_SetDirectLocation 0x02014184 thumb
 *   func_02159F84  0x02159F84  thumb  ov010
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   func_02012964  0x02012964  thumb
 *   sScrcmdWorkFileName     0x021728E0  data  ov010  a4
 *   SCRIPT_WORK_GetCmdWork 0x02158F6C thumb ov010
 *   MSGDATA_Delete  0x02045C04  arm
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb
 *   func_02045B38 0x02045B38 arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_MSGBG_CreateMenuItems  0x02190A20  thumb  ov021
 *   BMP_MENUWORK_CountItems  0x0201F91C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   STRBUF_Clone  0x02045874  arm
 *   FIELD_MSGBG_AddMenuItemStr  0x02190A64  thumb  ov021
 *   FIELD_MSGBG_GetMenuItemsWidthChars  0x02190ACC  thumb  ov021
 *   FIELD_MSGBG_GetMenuItemCount  0x02190AC4  thumb  ov021
 *   FIELD_MSGBG_GetMenuHeightChars  0x02190AEC  thumb  ov021
 *   FIELD_MSGBG_SetMenuHeaderRect  0x02190B08  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFuncWork  0x02190988  thumb  ov021
 *   gScrcmdMenuHeader     0x02171140  data  ov010  a4
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   FIELD_MSGBG_MenuFuncMain 0x021909E4 thumb ov021
 *   func_02020D0C  0x02020D0C  thumb
 *   func_020202EC  0x020202EC  thumb
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   FIELD_MSGBG_ClearInfoSysWin  0x02191164  thumb  ov021
 *   FIELD_MSGBG_InfoSysWinPrintStrNow  0x02191184  thumb  ov021
 *   SCRIPT_WORK_BackupLocalWork  0x0215909C  thumb  ov010
 *   SCRIPT_WORK_RestoreLocalWork  0x021590D4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 *   CONFIG_SetAppliedFlag  0x020083EC  thumb
 *   SCRIPT_WORK_ReadWorkValue   0x02159B10  thumb  ov010
 *   func_020056EC   0x020056EC  thumb
 *   TRCARD_SYS_CountStars  0x0216F830  thumb  ov010
 *   FIELD_CLOCK_GetTimeZone  0x021690B4  thumb  ov010
 *   FIELD_CLOCK_GetWeek  0x021690F0  thumb  ov010
 *   FIELD_CLOCK_GetMonth  0x021690D0  thumb  ov010
 *   FIELD_CLOCK_GetDay  0x021690E0  thumb  ov010
 *   FIELD_CLOCK_GetHour  0x02169100  thumb  ov010
 *   FIELD_CLOCK_GetMinute  0x02169110  thumb  ov010
 *   func_02012984  0x02012984  thumb
 *   OS_GetOwnerInfoEx 0x02087D28 arm
 *   func_02008550   0x02008550  thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   func_0200C234 0x0200C234 thumb
 *   func_0200C248  0x0200C248  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   GAME_DATA_GetSaveBlock21  0x02012F5C  thumb
 *   func_02008A7C  0x02008A7C  thumb
 *   func_0200C258  0x0200C258  thumb
 *   func_020071EC  0x020071EC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0200723C  0x0200723C  thumb
 *   func_02012900  0x02012900  thumb
 *   func_02012AA0  0x02012AA0  thumb
 *   func_02012AE4  0x02012AE4  thumb
 *   func_0201289C  0x0201289C  thumb
 *   MAP_REPLACE_SetFlag  0x02159F28  thumb  ov010
 *   MAP_MATRIX_ApplyReplace  0x02159CC4  thumb  ov010
 *   func_02012974  0x02012974  thumb
 *   ZONEDATA_GetMatrixId  0x02013B44  thumb
 *   MAP_REPLACE_CheckFlag  0x02159F54  thumb  ov010
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb
 *   ZUKAN_SAVE_IsCaught  0x0200CED4  thumb
 *   ZUKAN_SAVE_CountSeenNational  0x0200D0CC  thumb
 *   ZUKAN_SAVE_CountCaughtNational  0x0200CF28  thumb
 *   ZUKAN_SAVE_EnableNationalDex  0x0200CA28  thumb
 *   ZUKAN_SAVE_SetDexObtained  0x0200CA40  thumb
 *   CONFIG_GetButtonMode  0x02008428  thumb
 *   func_0201293C 0x0201293C thumb
 *   func_02007A68 0x02007A68 thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02025C88  0x02025C88  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02008A00  0x02008A00  thumb
 *   func_0200C308 0x0200C308 thumb
 *   func_0200C2F0   0x0200C2F0  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   func_020073D8  0x020073D8  thumb
 *   func_0200ECB4  0x0200ECB4  thumb
 *   func_020072A4  0x020072A4  thumb
 *   func_02012844  0x02012844  thumb
 *   EVENTDATA_SYSTEM_SetBgEventGridPos  0x02162A74  thumb  ov010
 *   EVENTDATA_SYSTEM_SetConnectGridPos  0x02162708  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcGridPos  0x02162748  thumb  ov010
 *   SCRCMD_NETWORK_CreateCommProcEvent  0x0215F6E8  thumb  ov010
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   func_02012A44 0x02012A44 thumb
 *   EVENT_BATTLE_IsResultSilent 0x0216EFA8 thumb ov010
 *   gScrcmdValueTable 0x02171160 data a2
 *   func_0215A4D8  0x0215A4D8  thumb  ov010
 *   func_0215A4EC  0x0215A4EC  thumb  ov010
 *   func_0215A500  0x0215A500  thumb  ov010
 */
#include "../arm9/btl_setup_types.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed short s16;
typedef signed int s32;

#define NULL ((void *)0)

struct ScriptWork;
struct ScriptVm;
struct GameSystem;
struct GameData;
struct OccupyInfo;
struct MsgBank;
struct WordSet;
struct Strbuf;
struct BmpMenuWork;
struct BmpMenuList;
struct FieldMenu;
struct FieldMsgWindow;
struct AnimeTask;

/*
 * Field menu header (0x20 bytes) for the ov021 field menu list: a copy of
 * the template sScrcmdMenuHeader is completed by FIELD_MSGBG_SetMenuHeaderRect.
 */
typedef struct FieldMenuHeader {
    int itemCount;                  /* 0x00 */
    int maxLines;                   /* 0x04 */
    u16 frameId;                    /* 0x08 */
    u16 cursorMargin : 3;           /* 0x0A, added to the text width */
    u16 lineSpacing : 4;            /* 0x0A, added to the font height */
    int frameFlags;                 /* 0x0C */
    u16 fontId;                     /* 0x10 */
    u16 fontHeight;                 /* 0x12 */
    u16 posX;                       /* 0x14 */
    u16 posY;                       /* 0x16 */
    u16 width;                      /* 0x18, in characters */
    u16 height;                     /* 0x1A, in characters */
    int reserved;                   /* 0x1C */
} FieldMenuHeader;

/* Script menu state (0xA0 bytes, inside ScrcmdCommonWork at +0x34). */
typedef struct ScrcmdMenu {
    u16 x;                          /* 0x00 */
    u16 y;                          /* 0x02 */
    u16 cursorPos;                  /* 0x04 */
    u8 cancelable;                  /* 0x06 */
    u8 alignRight;                  /* 0x07, 1: x is the right edge */
    u16 *result;                    /* 0x08 */
    struct WordSet *wordSet;        /* 0x0C */
    int ownsMsgData;                /* 0x10 */
    struct MsgBank *msgData;        /* 0x14 */
    struct BmpMenuWork *items;      /* 0x18 */
    struct FieldMenu *fieldMenu;    /* 0x1C */
    struct Strbuf *itemHelp[32];    /* 0x20 */
} ScrcmdMenu;

/* Work shared by every script command of one script system (0x110 bytes). */
typedef struct ScrcmdCommonWork {
    struct ScriptWork *scriptWork;  /* 0x000 */
    struct GameSystem *gameSystem;  /* 0x004 */
    struct GameData *gameData;      /* 0x008 */
    struct OccupyInfo *occupyInfo;  /* 0x00C */
    void *targetObject;             /* 0x010 */
    struct AnimeTask *animeTasks[8]; /* 0x014 */
    ScrcmdMenu menu;                /* 0x034 */
    u8 wordSetWork[0x28];           /* 0x0D4 */
    struct FieldMsgWindow *msgWindow; /* 0x0FC */
    void *timeIcon;                 /* 0x100 */
    u8 windowState;                 /* 0x104 */
    u8 windowKind;                  /* 0x105 */
    u16 waitCount;                  /* 0x106 */
    int fadeParam;                  /* 0x108 */
    int fadeState;                  /* 0x10C */
} ScrcmdCommonWork;

/* Start parameters of one script, copied into ScrcmdWork at +0x04. */
typedef struct ScrcmdWorkParam {
    u16 scriptId;                   /* 0x00 */
    u32 callParam;                  /* 0x04 */
    u32 callMode;                   /* 0x08 */
    struct ScriptWork *scriptWork;  /* 0x0C */
} ScrcmdWorkParam;

/* Per-script command work (0x24 bytes). */
typedef struct ScrcmdWork {
    u16 heapId;                     /* 0x00 */
    ScrcmdWorkParam param;          /* 0x04 */
    struct MsgBank *msgData;        /* 0x14 */
    u16 msgDataId;                  /* 0x18 */
    u8 childScriptIndex;            /* 0x1A */
    void *savedLocalWork;           /* 0x1C */
    ScrcmdCommonWork *common;       /* 0x20 */
} ScrcmdWork;

/* Owner information from the firmware user settings. */
typedef struct OwnerInfo {
    u8 language, color, month, day;
    u16 name[11], nameLength, comment[27], commentLength;
    u8 country, padding;
} OwnerInfo;

/* Calendar date as the RTC driver returns it (layout as in time_icon.c). */
typedef struct RtcDate {
    int year;
    int month;
    int day;
    int weekday;
} RtcDate;

struct ZukanSave;
struct MiscSave;
struct RecordSave;
struct BoxManager;
struct EventWork;
struct EventData;
struct MapMatrix;

/* script_work.c */
extern struct GameSystem *SCRIPT_WORK_GetGameSystem(struct ScriptWork *scriptWork);
extern int *SCRIPT_WORK_ResetFieldParam(struct ScriptWork *scriptWork);
extern ScrcmdCommonWork *SCRIPT_WORK_GetCmdWork(struct ScriptWork *scriptWork);
extern void *SCRIPT_WORK_BackupLocalWork(struct ScriptWork *scriptWork);
extern int SCRIPT_WORK_RestoreLocalWork(struct ScriptWork *scriptWork, void *localWork);
extern int SCRIPT_WORK_CheckFlag(int);
extern int SCRIPT_SYS_SetNextEventFromWork(struct ScriptWork *scriptWork, void *event);
u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptVm *vm, ScrcmdWork *work);
unsigned int SCRIPT_WORK_ReadWorkValue(struct ScriptVm *vm, ScrcmdWork *work);
extern int func_02011290(struct ScriptVm *vm);

/* map_matrix.c, map_replace.c, warp table */
int MAP_MATRIX_Load(struct MapMatrix *mapMatrix, int matrixId, u16 zoneId, int heapId);
void MAP_MATRIX_ApplyReplace(struct MapMatrix *mapMatrix, struct GameSystem *gameSystem, int heapId);
/* extent: two bytes of zero alignment padding at 0x02159F52. */
void MAP_REPLACE_SetFlag(struct GameData *gameData, int replaceId, int enable);
int MAP_REPLACE_CheckFlag(struct GameData *gameData, int replaceId);
int func_02159F84(int warpId);

/* event_poke_status.c (event work flag offsets) */
/* interface: original narrows r1 by shift pairs; u16 extern preserves this. */
unsigned func_0215A4D8(struct EventWork *eventWork, unsigned offset);
void func_0215A4EC(struct EventWork *eventWork, unsigned offset);
void func_0215A500(struct EventWork *eventWork, unsigned offset);

/* game system and game data */
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct OccupyInfo *func_02012964(struct GameData *gameData);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *playerWork);
extern u32 func_02012AE4(const struct PlayerWork *playerWork);
extern struct PlayerPosition *func_02012AA0(struct PlayerWork *playerWork);
extern void func_0201289C(struct GameData *gameData, const struct Location *location);
extern void func_02012900(struct GameData *gameData, int warpId);
extern struct MapMatrix *func_02012974(struct GameData *gameData);
extern u8 func_02012984(struct GameData *gameData);
extern struct EventWork *func_0201296C(struct GameData *gameData);
extern struct BoxManager *func_0201293C(struct GameData *gameData);
extern struct MiscSave *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern struct RecordSave *GAME_DATA_GetSaveBlock21(struct GameData *gameData);
extern struct EventData *func_02012844(struct GameData *gameData);
extern u32 func_02012A44(struct GameData *gameData);
extern u32 ZONEDATA_GetMatrixId(u32 zoneId);
extern void ZONEDATA_SetDirectLocation(struct Location *location, int zoneId, int direction, int x, int y, int z);
extern u32 ZONEDATA_CheckEventFlag(struct EventWork *eventWork, s32 flagId);
extern void ZONEDATA_SetEventFlag(struct EventWork *eventWork, int flagId);

/* save data */
extern struct Config *func_0200873C(struct SaveControl *saveControl);
extern int CONFIG_GetAppliedFlag(struct Config *config);
extern int CONFIG_SetAppliedFlag(struct Config *config, int flag);
extern int CONFIG_GetButtonMode(struct Config *config);
extern u8 func_02008550(const struct PlayerStatus *status);
extern u8 func_02008554(const struct PlayerStatus *status);
extern unsigned char func_020071EC(const struct SaveControl *saveControl);
extern u8 func_020071E4(const struct SaveControl *saveControl);
extern void func_0200723C(struct SaveControl *saveControl, unsigned *used, unsigned *total);
extern u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 id, u8 heapId);
extern void *func_020073D8(struct SaveControl *saveControl, u32 id, u32 index);
extern void func_020072A4(struct SaveControl *saveControl, u32 id);
extern void func_02007A68(struct BoxManager *boxManager, u32 bits);
extern u32 func_0200ECB4(void *extraSave);
extern struct RecordSave *func_020089C0(struct SaveControl *saveControl);
extern u8 func_020089F4(const struct RecordSave *record);
extern struct RecordSave *func_02008A00(struct RecordSave *record);
extern void func_02008A7C(struct RecordSave *record, u32 index, u32 year, u32 month, u32 day);
extern u32 func_0200C234(struct MiscSave *misc, u32 flagId);
extern void func_0200C248(struct MiscSave *misc, u32 flagId);
extern u32 func_0200C258(struct MiscSave *misc);
extern u8 func_0200C308(struct MiscSave *misc, u32 index);
extern void func_0200C2F0(struct MiscSave *misc, u32 index, u8 value);
extern struct ZukanSave *ZUKAN_SAVE_GetFromGameData(struct GameData *gameData);
extern struct ZukanSave *ZUKAN_SAVE_EnableNationalDex(struct ZukanSave *zukan);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *zukan);
extern struct ZukanSave *ZUKAN_SAVE_SetDexObtained(struct ZukanSave *zukan);
extern void ZUKAN_SAVE_RegisterSeen(struct ZukanSave *zukan, void *pokemon);
extern int ZUKAN_SAVE_IsSeen(struct ZukanSave *zukan, int species);
extern int ZUKAN_SAVE_IsCaught(struct ZukanSave *zukan, int species);
extern u16 ZUKAN_SAVE_CountSeenNational(struct ZukanSave *zukan);
extern u16 ZUKAN_SAVE_CountCaughtNational(struct ZukanSave *zukan);
extern int TRCARD_SYS_CountStars(struct GameData *gameData);
extern int FIELD_CLOCK_GetTimeZone(struct GameData *gameData);
extern int FIELD_CLOCK_GetWeek(struct GameData *gameData);
extern int FIELD_CLOCK_GetMonth(struct GameData *gameData);
extern int FIELD_CLOCK_GetDay(struct GameData *gameData);
extern int FIELD_CLOCK_GetHour(struct GameData *gameData);
extern int FIELD_CLOCK_GetMinute(struct GameData *gameData);

/* event data, battle, network */
extern int EVENTDATA_SYSTEM_SetBgEventGridPos(struct EventData *eventData, int eventId, u16 x, u16 y, u16 z);
extern void EVENTDATA_SYSTEM_SetConnectGridPos(struct EventData *eventData, u32 eventId, u16 x, u32 y, u16 z);
extern int EVENTDATA_SYSTEM_SetNpcGridPos(struct EventData *eventData, int eventId, int direction, u16 x, int y, u16 z);
extern int EVENT_BATTLE_IsResultSilent(u32 fieldMode, int silent);
extern void *SCRCMD_NETWORK_CreateCommProcEvent(struct GameSystem *gameSystem);

/* system */
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02082A7C(int value, void *dest, int size);
extern void MI_CpuFill8(void *dest, int value, int size);
extern u32 KEY_GetTrg(void);
extern u32 func_020056EC(u32 range);
extern u32 func_02025C88(u32 x);
extern void OS_GetOwnerInfoEx(OwnerInfo *info);
extern void func_0203F4E4(RtcDate *date);
extern void *POKE_TOOL_Create(u32 species, u32 level, u64 id, u32 heapId);

/* message data, strings, menus */
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern int MSGDATA_Delete(struct MsgBank *msgData);
extern void func_02045CAC(struct MsgBank *msgData, unsigned int index, struct Strbuf *dest);
extern struct Strbuf *STRBUF_Clone(struct Strbuf *src, unsigned int heapId);
extern int STRBUF_Delete(struct Strbuf *str);
extern void func_0201F250(struct WordSet *wordSet, struct Strbuf *dst, struct Strbuf *src);
extern unsigned int BMP_MENUWORK_CountItems(struct BmpMenuWork *items);
extern ScrcmdWork *func_02020D0C(struct BmpMenuList *list);
extern void func_020202EC(struct BmpMenuList *list, u16 *out);
extern struct BmpMenuWork *FIELD_MSGBG_CreateMenuItems(int count, int heapId);
extern int FIELD_MSGBG_AddMenuItemStr(struct BmpMenuWork *items, struct Strbuf *str, u32 param, u32 heapId);
extern u32 FIELD_MSGBG_GetMenuItemsWidthChars(int *heap, struct BmpMenuWork *items, u32 fontId, u32 margin);
extern unsigned FIELD_MSGBG_GetMenuItemCount(struct BmpMenuWork *items);
extern unsigned FIELD_MSGBG_GetMenuHeightChars(unsigned lines, unsigned fontHeight, unsigned lineSpacing, int scrolls);
extern int FIELD_MSGBG_SetMenuHeaderRect(FieldMenuHeader *header, u32 count, u32 x, u32 y, u32 width, u32 height);
extern struct FieldMenu *FIELD_MSGBG_CreateMenuFuncWork(int *heap, const FieldMenuHeader *header, struct BmpMenuWork *items, void (*callback)(struct BmpMenuList *), ScrcmdWork *work, u16 unused, u16 cursorPos, u32 cancelable);
extern int FIELD_MSGBG_DeleteMenuFunc(struct FieldMenu *fieldMenu);
extern int FIELD_MSGBG_MenuFuncMain(struct FieldMenu *fieldMenu);
extern void FIELD_MSGBG_ClearInfoSysWin(struct FieldMsgWindow *window);
extern void FIELD_MSGBG_InfoSysWinPrintStrNow(struct FieldMsgWindow *window, u32 b, int c, struct Strbuf *str);
extern int FLDMMDL_ACMD_ListCheckEnd(struct AnimeTask *task);
extern int FLDMMDL_ACMD_ListDelete(struct AnimeTask *task);

extern const char sScrcmdWorkFileName[];
extern FieldMenuHeader gScrcmdMenuHeader;
extern const u16 gScrcmdValueTable[];

void SCRCMD_WORK_MenuCursorCallback(struct BmpMenuList *list);

ScrcmdCommonWork *SCRCMD_WORK_CreateCommon(struct ScriptWork *scriptWork, int heapId)
{
    ScrcmdCommonWork *common = func_02030734(heapId, 0x110, 1, sScrcmdWorkFileName, 0x78);

    common->scriptWork = scriptWork;
    common->gameSystem = SCRIPT_WORK_GetGameSystem(scriptWork);
    common->gameData = func_020120F4(common->gameSystem);
    common->occupyInfo = func_02012964(common->gameData);
    common->windowState = 7;
    return common;
}

/* Tail call through a pool word and `bx r3` into the arm9 heap free. */
void SCRCMD_WORK_DeleteCommon(ScrcmdCommonWork *common)
{
    func_020307B0(common);
}

/*
 * lever: const source pointer hoists its copy before the destination id store.
 */
ScrcmdWork *SCRCMD_WORK_Create(const ScrcmdWorkParam *param, int heapId)
{
    ScrcmdWork *work;
    const ScrcmdWorkParam *src;
    work = func_02030734((unsigned short)((heapId & 0x7fff) | 0x8000), 0x24, 1, sScrcmdWorkFileName, 0x94);
    src = param;
    work->heapId = heapId;
    work->param = *src;
    work->common = SCRIPT_WORK_GetCmdWork(param->scriptWork);
    return work;
}

void SCRCMD_WORK_DeleteAnimeTasks(ScrcmdWork *work);

void SCRCMD_WORK_Delete(ScrcmdWork *work)
{
    if (work->savedLocalWork != NULL)
        func_020307B0(work->savedLocalWork);
    if (work->msgData != NULL)
        MSGDATA_Delete(work->msgData);
    SCRCMD_WORK_DeleteAnimeTasks(work);
    func_020307B0(work);
}

u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *work)
{
    return work->heapId;
}

u16 SCRCMD_WORK_GetScriptId(ScrcmdWork *work)
{
    return work->param.scriptId;
}

u32 SCRCMD_WORK_GetCallMode(ScrcmdWork *work)
{
    return work->param.callMode;
}

u32 SCRCMD_WORK_GetCallParam(ScrcmdWork *work)
{
    return work->param.callParam;
}

struct GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *work)
{
    return work->common->gameSystem;
}

struct GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *work)
{
    return work->common->gameData;
}

struct OccupyInfo *SCRCMD_WORK_GetOccupyInfo(ScrcmdWork *work)
{
    return work->common->occupyInfo;
}

struct ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *work)
{
    return work->common->scriptWork;
}

int SCRCMD_WORK_GetMenuHeap(ScrcmdWork *work)
{
    return *SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work));
}

struct MsgBank *SCRCMD_WORK_GetMsgData(ScrcmdWork *work)
{
    return work->msgData;
}

u16 SCRCMD_WORK_GetMsgDataId(ScrcmdWork *work)
{
    return work->msgDataId;
}

void SCRCMD_WORK_SetMsgWindow(ScrcmdWork *work, struct FieldMsgWindow *window)
{
    work->common->msgWindow = window;
}

struct FieldMsgWindow *SCRCMD_WORK_GetMsgWindow(ScrcmdWork *work)
{
    return work->common->msgWindow;
}

void SCRCMD_WORK_SetTimeIcon(ScrcmdWork *work, void *window)
{
    work->common->timeIcon = window;
}

void *SCRCMD_WORK_GetTimeIcon(ScrcmdWork *work)
{
    return work->common->timeIcon;
}

u8 *SCRCMD_WORK_GetWordSetWork(ScrcmdWork *work)
{
    return work->common->wordSetWork;
}

void SCRCMD_WORK_SetTargetObject(ScrcmdWork *work, void *object)
{
    work->common->targetObject = object;
}

void *SCRCMD_WORK_GetTargetObject(ScrcmdWork *work)
{
    return work->common->targetObject;
}

u32 SCRCMD_WORK_GetWindowState(ScrcmdWork *work)
{
    return work->common->windowState;
}

void SCRCMD_WORK_SetWindowState(ScrcmdWork *work, u32 state)
{
    work->common->windowState = state;
}

u8 SCRCMD_WORK_GetWindowKind(ScrcmdWork *work)
{
    return work->common->windowKind;
}

void SCRCMD_WORK_SetWindowKind(ScrcmdWork *work, u8 kind)
{
    work->common->windowKind = kind;
}

void SCRCMD_WORK_SetWaitCount(ScrcmdWork *work, unsigned short count)
{
    work->common->waitCount = count;
}

int SCRCMD_WORK_CountDownWait(ScrcmdWork *work)
{
    unsigned short *waitCount = &work->common->waitCount;
    if (*waitCount == 0) {
        return 1;
    }
    *waitCount = *waitCount - 1;
    return 0;
}

int SCRCMD_WORK_GetFadeParam(ScrcmdWork *work)
{
    return work->common->fadeParam;
}

void SCRCMD_WORK_SetFadeParam(ScrcmdWork *work, int param)
{
    work->common->fadeParam = param;
}

int SCRCMD_WORK_GetFadeState(ScrcmdWork *work)
{
    return work->common->fadeState;
}

void SCRCMD_WORK_SetFadeState(ScrcmdWork *work, int state)
{
    work->common->fadeState = state;
}

void SCRCMD_WORK_AddAnimeTask(ScrcmdWork *work, struct AnimeTask *task)
{
    int i;
    ScrcmdCommonWork *common = work->common;
    for (i = 0; i < 8; i++) {
        if (common->animeTasks[i] == NULL) {
            common->animeTasks[i] = task;
            return;
        }
    }
}

u32 SCRCMD_WORK_CheckAnimeTasks(ScrcmdWork *work)
{
    int i;
    u32 busy = 0;
    for (i = 0; i < 8; i++) {
        if (work->common->animeTasks[i] != NULL) {
            if (FLDMMDL_ACMD_ListCheckEnd(work->common->animeTasks[i]) == 1) {
                FLDMMDL_ACMD_ListDelete(work->common->animeTasks[i]);
                work->common->animeTasks[i] = NULL;
            } else {
                busy = 1;
            }
        }
    }
    return busy;
}

void SCRCMD_WORK_DeleteAnimeTasks(ScrcmdWork *work)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (work->common->animeTasks[i] != NULL) {
            FLDMMDL_ACMD_ListDelete(work->common->animeTasks[i]);
            work->common->animeTasks[i] = NULL;
        }
    }
}

/*
 * interface: original narrows r1/r2 by shift pairs; u16 extern preserves this.
 */
void SCRCMD_WORK_LoadMsgData(ScrcmdWork *work, unsigned arcId, unsigned fileId)
{
    work->msgData = func_02045B38(0, (u16)arcId, (u16)fileId, work->heapId);
    work->msgDataId = fileId;
}

void SCRCMD_WORK_InitMenu(ScrcmdWork *work, unsigned short x, unsigned short y,
                   unsigned short cursorPos, unsigned short cancelable,
                   int alignRight, u16 *result,
                   struct WordSet *wordSet, struct MsgBank *msgData)
{
    ScrcmdCommonWork *common = work->common;
    ScrcmdMenu *menu = &common->menu;
    MI_CpuFill8(menu, 0, 0xa0);
    common->menu.x = x;
    menu->y = y;
    menu->cursorPos = cursorPos;
    menu->cancelable = cancelable;
    menu->alignRight = alignRight;
    menu->result = result;
    menu->wordSet = wordSet;
    menu->msgData = msgData;
    func_02082A7C(0, menu->itemHelp, 0x80);
    if (menu->msgData == NULL) {
        menu->ownsMsgData = 1;
        menu->msgData = func_02045B38(0, 3, 0x80 + 0x86, work->heapId);
    }
    menu->items = FIELD_MSGBG_CreateMenuItems(0x20, work->heapId);
}

void SCRCMD_WORK_AddMenuItem(ScrcmdWork *work, int msgId, int helpMsgId, int param, struct Strbuf *str, struct Strbuf *tmp)
{
    ScrcmdMenu *menu = &work->common->menu;
    if (helpMsgId != 0xffff) {
        unsigned index = BMP_MENUWORK_CountItems(menu->items);
        if (index >= 0x20) {
            return;
        }
        func_02045CAC(menu->msgData, helpMsgId, tmp);
        func_0201F250(menu->wordSet, str, tmp);
        menu->itemHelp[index] = STRBUF_Clone(str, work->heapId);
    }
    func_02045CAC(menu->msgData, msgId, tmp);
    func_0201F250(menu->wordSet, str, tmp);
    FIELD_MSGBG_AddMenuItemStr(menu->items, str, param, work->heapId);
}

/*
 * The ov021 leaves 0x02190AC4 and 0x02190AEC (unlabelled, formerly the
 * blockers) are matched in their own shards and attest as matched.
 */
void SCRCMD_WORK_StartMenu(ScrcmdWork *work)
{
    int width;
    int height;
    ScrcmdMenu *menu = &work->common->menu;
    FieldMenuHeader header = gScrcmdMenuHeader;
    int *heap = (int *)SCRCMD_WORK_GetMenuHeap(work);
    unsigned lines;
    unsigned count;
    width = FIELD_MSGBG_GetMenuItemsWidthChars(heap, menu->items, header.fontId, header.cursorMargin);
    if (menu->alignRight == 1) {
        menu->x = menu->x - (unsigned short)width;
    }
    count = FIELD_MSGBG_GetMenuItemCount(menu->items);
    lines = 6;
    if (count <= 6) {
        lines = count;
    }
    height = FIELD_MSGBG_GetMenuHeightChars(lines, header.fontHeight, header.lineSpacing, count > 6);
    FIELD_MSGBG_SetMenuHeaderRect(&header, (unsigned short)FIELD_MSGBG_GetMenuItemCount(menu->items), (unsigned short)menu->x, (unsigned short)menu->y, (unsigned short)width, (unsigned short)height);
    menu->fieldMenu = FIELD_MSGBG_CreateMenuFuncWork(heap, &header, menu->items, SCRCMD_WORK_MenuCursorCallback, work, 0, menu->cursorPos, menu->cancelable);
}

void SCRCMD_WORK_DeleteMenu(ScrcmdMenu *menu)
{
    int i;
    FIELD_MSGBG_DeleteMenuFunc(menu->fieldMenu);
    if (menu->ownsMsgData == 1) {
        MSGDATA_Delete(menu->msgData);
    }
    for (i = 0; i < 0x20; i++) {
        if (menu->itemHelp[i] != NULL) {
            STRBUF_Delete(menu->itemHelp[i]);
            menu->itemHelp[i] = NULL;
        }
    }
}

int SCRCMD_WORK_WaitMenu(ScrcmdWork *work)
{
    ScrcmdMenu *menu;
    int selected;
    menu = &work->common->menu;
    selected = FIELD_MSGBG_MenuFuncMain(menu->fieldMenu);
    if (selected == -1)
        return 0;
    SCRCMD_WORK_DeleteMenu(menu);
    if (selected != -2)
        *menu->result = selected;
    else
        *menu->result = 65534;
    return 1;
}

/*
 * lever: result declared before pointer gives original r4/result, r5/base.
 */
int SCRCMD_WORK_WaitMenuOrCancel(ScrcmdWork *work)
{
    int done;
    ScrcmdMenu *menu;
    menu = &work->common->menu;
    done = SCRCMD_WORK_WaitMenu(work);
    if (done == 0 && (KEY_GetTrg() & 1024)) {
        SCRCMD_WORK_DeleteMenu(menu);
        *menu->result = 65533;
        done = 1;
    }
    return done;
}

void SCRCMD_WORK_MenuCursorCallback(struct BmpMenuList *list)
{
    unsigned short index = 0;
    ScrcmdWork *work = func_02020D0C(list);
    ScrcmdMenu *menu = &work->common->menu;
    func_020202EC(list, &index);
    if (menu->itemHelp[index] != NULL) {
        if (SCRIPT_WORK_CheckFlag(1) != 0) {
            struct FieldMsgWindow *window = SCRCMD_WORK_GetMsgWindow(work);
            FIELD_MSGBG_ClearInfoSysWin(window);
            FIELD_MSGBG_InfoSysWinPrintStrNow(window, 0, 0, menu->itemHelp[index]);
        } else if (SCRIPT_WORK_CheckFlag(2) == 0) {
            SCRIPT_WORK_CheckFlag(3);
        }
    }
}

void SCRCMD_WORK_SaveScriptState(ScrcmdWork *work)
{
    work->savedLocalWork = SCRIPT_WORK_BackupLocalWork(SCRCMD_WORK_GetScriptWork(work));
}

void SCRCMD_WORK_RestoreScriptState(ScrcmdWork *work)
{
    SCRIPT_WORK_RestoreLocalWork(SCRCMD_WORK_GetScriptWork(work), work->savedLocalWork);
    work->savedLocalWork = NULL;
}

void SCRCMD_WORK_SetChildScriptIndex(ScrcmdWork *work, int index)
{
    work->childScriptIndex = index;
}

u8 SCRCMD_WORK_GetChildScriptIndex(ScrcmdWork *work)
{
    return work->childScriptIndex;
}

int SCRCMD_WORK_CmdGetRomVersion(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = 0x15;
    return 0;
}

int SCRCMD_WORK_CmdToggleConfigFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    int flag;
    config = func_0200873C(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(work)));
    flag = CONFIG_GetAppliedFlag(config);
    if (flag == 0) {
        flag = 1;
    } else if (flag == 1) {
        flag = 0;
    }
    CONFIG_SetAppliedFlag(config, flag);
    return 0;
}

int SCRCMD_WORK_CmdGetConfigFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    u16 *ret;
    config = func_0200873C(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(work)));
    ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = CONFIG_GetAppliedFlag(config);
    return 0;
}

int SCRCMD_WORK_CmdGetRandom(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = (u16)func_020056EC(SCRIPT_WORK_ReadWorkValue(vm, work));
    return 0;
}

int SCRCMD_WORK_CmdGetMsgDataId(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = SCRCMD_WORK_GetMsgDataId(work);
    return 0;
}

int SCRCMD_WORK_CmdGetSaveRecord(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = TRCARD_SYS_CountStars(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetFieldRecordA(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = FIELD_CLOCK_GetTimeZone(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetFieldRecordB(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = FIELD_CLOCK_GetWeek(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetFieldRecordPair(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *retFirst = SCRIPT_WORK_ReadWorkPointer(vm, work);
    u16 *retSecond = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *retFirst = FIELD_CLOCK_GetMonth(gameData);
    *retSecond = FIELD_CLOCK_GetDay(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetFieldRecordPairB(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *retFirst = SCRIPT_WORK_ReadWorkPointer(vm, work);
    u16 *retSecond = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *retFirst = FIELD_CLOCK_GetHour(gameData);
    *retSecond = FIELD_CLOCK_GetMinute(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetSeason(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = func_02012984(SCRCMD_WORK_GetGameData(work));
    return 0;
}

/* extent: compiled 46 bytes; trailing 0x0215AC1A..0x0215AC1C is zero alignment. */
int SCRCMD_WORK_CmdGetBirthday(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *retMonth;
    u16 *retDay;
    OwnerInfo info;
    retMonth = SCRIPT_WORK_ReadWorkPointer(vm, work);
    retDay = SCRIPT_WORK_ReadWorkPointer(vm, work);
    OS_GetOwnerInfoEx(&info);
    *retMonth = info.month;
    *retDay = info.day;
    return 0;
}

int SCRCMD_WORK_CmdGetPlayerRomCode(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = (u16)func_02008550(&func_020127A4(SCRCMD_WORK_GetGameData(work))->status);
    return 0;
}

int SCRCMD_WORK_CmdCheckMiscFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    int flagId = SCRIPT_WORK_ReadWorkValue(vm, work);
    *ret = func_0200C234(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), flagId);
    return 0;
}

int SCRCMD_WORK_CmdSetMiscFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    RtcDate date;
    int flagId = SCRIPT_WORK_ReadWorkValue(vm, work);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    func_0200C248(GAME_DATA_GetMiscSave(gameData), flagId);
    func_0203F4E4(&date);
    func_02008A7C(GAME_DATA_GetSaveBlock21(gameData), flagId, date.year, date.month, date.day);
    return 0;
}

int SCRCMD_WORK_CmdGetMiscCount(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = func_0200C258(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)));
    return 0;
}

int SCRCMD_WORK_CmdGetSaveStatus(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct SaveControl *saveControl;
    unsigned short *retFirst;
    unsigned short *retSecond;
    unsigned short *retThird;
    unsigned total;
    unsigned used;
    saveControl = GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(work));
    retFirst = SCRIPT_WORK_ReadWorkPointer(vm, work);
    retSecond = SCRIPT_WORK_ReadWorkPointer(vm, work);
    retThird = SCRIPT_WORK_ReadWorkPointer(vm, work);
    total = 0;
    used = 0;
    *retFirst = func_020071EC(saveControl);
    *retSecond = func_020071E4(saveControl);
    func_0200723C(saveControl, &used, &total);
    if (used * 3 < total) {
        *retThird = 0;
    } else {
        *retThird = 1;
    }
    return 0;
}

int SCRCMD_WORK_CmdGetScriptId(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = SCRCMD_WORK_GetScriptId(work);
    return 0;
}

int SCRCMD_WORK_CmdSetWarpDestination(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    int warpId = SCRIPT_WORK_ReadWorkValue(vm, work);
    if (func_02159F84(warpId) == 1) {
        func_02012900(gameData, warpId);
    }
    return 0;
}

/*
 * 0x02014184 is an unlabelled Thumb leaf in the ARM9 image with one caller
 * image-wide (label / sole-ref/code refuse it).
 */
int SCRCMD_WORK_CmdSetSpecialLocationHere(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Location location;
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    struct PlayerWork *playerWork = func_020127A4(gameData);
    struct PlayerPosition *position = func_02012AA0(playerWork);
    int zoneId = func_02012AC8(playerWork);
    ZONEDATA_SetDirectLocation(&location, zoneId, (short)func_02012AE4(playerWork), position->x, position->y, position->z);
    func_0201289C(gameData, &location);
    return 0;
}

int SCRCMD_WORK_CmdSetSpecialLocation(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Location location;
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    int zoneId = SCRIPT_WORK_ReadWorkValue(vm, work);
    int direction = SCRIPT_WORK_ReadWorkValue(vm, work);
    int x = SCRIPT_WORK_ReadWorkValue(vm, work);
    int y = SCRIPT_WORK_ReadWorkValue(vm, work);
    int z = SCRIPT_WORK_ReadWorkValue(vm, work);
    ZONEDATA_SetDirectLocation(&location, zoneId, (s16)direction, x << 16, y << 16, z << 16);
    func_0201289C(gameData, &location);
    return 0;
}

int SCRCMD_WORK_CmdSetMapReplaceFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    int replaceId = SCRIPT_WORK_ReadWorkValue(vm, work);
    int enable = SCRIPT_WORK_ReadWorkValue(vm, work);
    int applyNow = SCRIPT_WORK_ReadWorkValue(vm, work);
    struct MapMatrix *mapMatrix;
    int matrixId, heapId;
    u16 zoneId;
    MAP_REPLACE_SetFlag(gameData, replaceId, enable);
    if (applyNow != 0) {
        mapMatrix = func_02012974(gameData);
        zoneId = func_02012AC8(func_020127A4(gameData));
        matrixId = ZONEDATA_GetMatrixId(zoneId);
        heapId = SCRCMD_WORK_GetHeapId(work);
        MAP_MATRIX_Load(mapMatrix, matrixId, zoneId, heapId);
        MAP_MATRIX_ApplyReplace(mapMatrix, gameSystem, heapId);
    }
    return 0;
}

int SCRCMD_WORK_CmdCheckMapReplaceFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    int replaceId = SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = MAP_REPLACE_CheckFlag(gameData, replaceId);
    return 0;
}

int SCRCMD_WORK_CmdRegisterZukanSeen(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    int heapId;
    int mode, species;
    void *pokemon;
    zukan = ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData(work));
    heapId = SCRCMD_WORK_GetHeapId(work);
    mode = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    species = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    pokemon = POKE_TOOL_Create(species, 1, 0xFFFFFFFF00000000ULL, heapId);
    switch (mode) {
    case 0:
        ZUKAN_SAVE_RegisterSeen(zukan, pokemon);
        break;
    case 1:
        break;
    }
    func_020307B0(pokemon);
    return 0;
}

int SCRCMD_WORK_CmdGetZukanSeenCount(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    int mode, species;
    u16 *ret;
    zukan = ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData(work));
    mode = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    species = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    switch (mode) {
    case 0:
        *ret = ZUKAN_SAVE_IsSeen(zukan, species);
        break;
    case 1:
        *ret = ZUKAN_SAVE_IsCaught(zukan, species);
        break;
    default:
        *ret = 0;
        break;
    }
    return 0;
}

int SCRCMD_WORK_CmdGetZukanGetCount(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct ZukanSave *zukan;
    int mode;
    u16 *ret;
    zukan = ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData(work));
    mode = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    switch (mode) {
    case 0:
        *ret = ZUKAN_SAVE_CountSeenNational(zukan);
        break;
    case 1:
        *ret = ZUKAN_SAVE_CountCaughtNational(zukan);
        break;
    default:
        *ret = 0;
        break;
    }
    return 0;
}

int SCRCMD_WORK_CmdSetZukanFlagA(struct ScriptVm *vm, ScrcmdWork *work)
{
    ZUKAN_SAVE_EnableNationalDex(ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData(work)));
    return 0;
}

int SCRCMD_WORK_CmdGetZukanNationalFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = ZUKAN_SAVE_IsNationalDexEnabled(ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData(work)));
    return 0;
}

int SCRCMD_WORK_CmdSetZukanFlagB(struct ScriptVm *vm, ScrcmdWork *work)
{
    ZUKAN_SAVE_SetDexObtained(ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData(work)));
    return 0;
}

int SCRCMD_WORK_CmdGetButtonMode(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    u16 *ret;
    config = func_0200873C(GAME_DATA_GetSaveControl(func_020120F4(SCRCMD_WORK_GetGameSystem(work))));
    ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    switch (CONFIG_GetButtonMode(config)) {
    case 0:
        *ret = 0;
        break;
    case 1:
        *ret = 1;
        break;
    }
    return 0;
}

int SCRCMD_WORK_CmdSetFixedEventFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    ZONEDATA_SetEventFlag(func_0201296C(SCRCMD_WORK_GetGameData(work)), 0x963);
    return 0;
}

int SCRCMD_WORK_CmdSetBoxFlags(struct ScriptVm *vm, ScrcmdWork *work)
{
    int bits = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    struct BoxManager *boxManager = func_0201293C(SCRCMD_WORK_GetGameData(work));
    if ((u16)(bits + 0xFFFF) <= 1)
        func_02007A68(boxManager, bits);
    return 0;
}

int SCRCMD_WORK_CmdGetPlayerSaveValue(struct ScriptVm *vm, ScrcmdWork *work)
{
    unsigned short *retSecond;
    unsigned short *retFirst;
    struct GameData *gameData;
    struct PlayerWork *playerWork;
    struct RecordSave *record;
    retSecond = SCRIPT_WORK_ReadWorkPointer(vm, work);
    retFirst = SCRIPT_WORK_ReadWorkPointer(vm, work);
    gameData = SCRCMD_WORK_GetGameData(work);
    playerWork = func_020127A4(gameData);
    record = func_020089C0(GAME_DATA_GetSaveControl(gameData));
    *retFirst = func_02025C88(func_02008554(&playerWork->status));
    *retSecond = func_020089F4(record);
    func_02008A00(record);
    return 0;
}

int SCRCMD_WORK_CmdGetMiscByte(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = (func_0200C308(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), index) & 1) != 0;
    return 0;
}

int SCRCMD_WORK_CmdSetMiscByte(struct ScriptVm *vm, ScrcmdWork *work)
{
    u32 index = SCRIPT_WORK_ReadWorkValue(vm, work);
    func_0200C2F0(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), index, 1);
    return 0;
}

int SCRCMD_WORK_CmdCheckMiscByte(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    if (func_0200C308(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), index) == 3)
        *ret = 1;
    else
        *ret = 0;
    return 0;
}

int SCRCMD_WORK_CmdCheckExtraSaveData(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    struct EventWork *eventWork = func_0201296C(gameData);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    struct SaveControl *saveControl;
    int result;
    if (ZONEDATA_CheckEventFlag(eventWork, 0x97B) != 0) {
        saveControl = GAME_DATA_GetSaveControl(gameData);
        result = SAVE_CONTROL_LoadExtraSave(saveControl, 8, 4);
        switch (result) {
        case 0:
            *ret = 0;
            break;
        case 1:
        case 2:
            if (func_0200ECB4(func_020073D8(saveControl, 8, 0)) == 0) {
                *ret = 0;
            } else {
                *ret = 1;
            }
            break;
        default:
            *ret = 2;
            break;
        }
        func_020072A4(saveControl, 8);
    } else {
        *ret = 0;
    }
    return 0;
}

int SCRCMD_WORK_CmdEventDataSetA(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 x = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 y = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 z = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENTDATA_SYSTEM_SetBgEventGridPos(func_02012844(SCRCMD_WORK_GetGameData(work)), eventId, x, y, z);
    return 0;
}

int SCRCMD_WORK_CmdEventDataSetB(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 x = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 y = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 z = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENTDATA_SYSTEM_SetConnectGridPos(func_02012844(SCRCMD_WORK_GetGameData(work)), eventId, x, (u16)y, z);
    return 0;
}

int SCRCMD_WORK_CmdEventDataSetC(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    int direction = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 x = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 y = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 z = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENTDATA_SYSTEM_SetNpcGridPos(func_02012844(SCRCMD_WORK_GetGameData(work)), eventId, direction, x, y << 16, z);
    return 0;
}

int SCRCMD_WORK_CmdSetEventFlagOffset(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    struct EventWork *eventWork = func_0201296C(gameData);
    unsigned offset = SCRIPT_WORK_ReadWorkValue(vm, work);
    func_0215A4EC(eventWork, offset);
    return 0;
}

int SCRCMD_WORK_CmdResetEventFlagOffset(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    struct EventWork *eventWork = func_0201296C(gameData);
    unsigned offset = SCRIPT_WORK_ReadWorkValue(vm, work);
    func_0215A500(eventWork, offset);
    return 0;
}

int SCRCMD_WORK_CmdCheckEventFlagOffset(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct EventWork *eventWork = func_0201296C(SCRCMD_WORK_GetGameData(work));
    unsigned offset = SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = func_0215A4D8(eventWork, offset);
    return 0;
}

int SCRCMD_WORK_CmdEndFieldCommandA(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    SCRIPT_SYS_SetNextEventFromWork(scriptWork, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
    func_02011290(vm);
    return 1;
}

int SCRCMD_WORK_CmdCheckFieldModeA(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    int notSilent = 1;
    if (EVENT_BATTLE_IsResultSilent(func_02012A44(SCRCMD_WORK_GetGameData(work)), 1) == 1)
        *ret = 0;
    else
        *ret = notSilent;
    return 0;
}

int SCRCMD_WORK_CmdEndFieldCommandB(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    SCRIPT_SYS_SetNextEventFromWork(scriptWork, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
    func_02011290(vm);
    return 1;
}

int SCRCMD_WORK_CmdCheckFieldModeB(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    int silent = 0;
    if (EVENT_BATTLE_IsResultSilent(func_02012A44(SCRCMD_WORK_GetGameData(work)), 0) == 1)
        *ret = silent;
    else
        *ret = 1;
    return 0;
}

int SCRCMD_WORK_CmdLookupTable(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = gScrcmdValueTable[index];
    return 0;
}
