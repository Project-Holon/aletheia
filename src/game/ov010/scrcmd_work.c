/*
 * file:     scrcmd_work.c
 * unit:     yes
 * function: SCRCMD_WORK_CreateCommon, SCRCMD_WORK_DeleteCommon, SCRCMD_WORK_Create, SCRCMD_WORK_Delete, SCRCMD_WORK_GetHeapId, SCRCMD_WORK_GetScriptId, SCRCMD_WORK_GetCallMode, SCRCMD_WORK_GetCallParam, SCRCMD_WORK_GetGameSystem, SCRCMD_WORK_GetGameData, SCRCMD_WORK_GetMmdlSys, SCRCMD_WORK_GetScriptWork, SCRCMD_WORK_GetMenuHeap, SCRCMD_WORK_GetMsgData, SCRCMD_WORK_GetMsgDataId, SCRCMD_WORK_SetMsgWindow, SCRCMD_WORK_GetMsgWindow, SCRCMD_WORK_SetTimeIcon, SCRCMD_WORK_GetTimeIcon, SCRCMD_WORK_GetWordSetWork, SCRCMD_WORK_SetTargetObject, SCRCMD_WORK_GetTargetObject, SCRCMD_WORK_GetWindowState, SCRCMD_WORK_SetWindowState, SCRCMD_WORK_GetWindowKind, SCRCMD_WORK_SetWindowKind, SCRCMD_WORK_SetWaitCount, SCRCMD_WORK_CountDownWait, SCRCMD_WORK_GetFadeParam, SCRCMD_WORK_SetFadeParam, SCRCMD_WORK_GetFadeState, SCRCMD_WORK_SetFadeState, SCRCMD_WORK_AddAnimeTask, SCRCMD_WORK_CheckAnimeTasks, SCRCMD_WORK_DeleteAnimeTasks, SCRCMD_WORK_LoadMsgData, SCRCMD_WORK_InitMenu, SCRCMD_WORK_AddMenuItem, SCRCMD_WORK_StartMenu, SCRCMD_WORK_DeleteMenu, SCRCMD_WORK_WaitMenu, SCRCMD_WORK_WaitMenuOrCancel, SCRCMD_WORK_MenuCursorCallback, SCRCMD_WORK_SaveScriptState, SCRCMD_WORK_RestoreScriptState, SCRCMD_WORK_SetChildScriptIndex, SCRCMD_WORK_GetChildScriptIndex, SCRCMD_WORK_CmdGetRomVersion, SCRCMD_WORK_CmdToggleConfigFlag, SCRCMD_WORK_CmdGetConfigFlag, SCRCMD_WORK_CmdGetRandom, SCRCMD_WORK_CmdGetMsgDataId, SCRCMD_WORK_CmdGetTrainerCardStars, SCRCMD_WORK_CmdGetTimeZone, SCRCMD_WORK_CmdGetWeek, SCRCMD_WORK_CmdGetMonthAndDay, SCRCMD_WORK_CmdGetHourAndMinute, SCRCMD_WORK_CmdGetSeason, SCRCMD_WORK_CmdGetBirthday, SCRCMD_WORK_CmdGetPlayerSex, SCRCMD_WORK_CmdCheckBadge, SCRCMD_WORK_CmdSetBadge, SCRCMD_WORK_CmdGetBadgeCount, SCRCMD_WORK_CmdGetSaveStatus, SCRCMD_WORK_CmdGetScriptId, SCRCMD_WORK_CmdSetWarpDestination, SCRCMD_WORK_CmdSetSpecialLocationHere, SCRCMD_WORK_CmdSetSpecialLocation, SCRCMD_WORK_CmdSetMapReplaceFlag, SCRCMD_WORK_CmdCheckMapReplaceFlag, SCRCMD_WORK_CmdRegisterZukanSeen, SCRCMD_WORK_CmdCheckZukanSeenOrCaught, SCRCMD_WORK_CmdGetNationalZukanCount, SCRCMD_WORK_CmdEnableNationalDex, SCRCMD_WORK_CmdGetZukanNationalFlag, SCRCMD_WORK_CmdSetZukanObtained, SCRCMD_WORK_CmdGetButtonMode, SCRCMD_WORK_CmdSetFixedEventFlag, SCRCMD_WORK_CmdSetBoxFlags, SCRCMD_WORK_CmdGetTrainerViewGroupAndMarkSeen, SCRCMD_WORK_CmdGetMiscByte, SCRCMD_WORK_CmdSetMiscByte, SCRCMD_WORK_CmdCheckMiscByte, SCRCMD_WORK_CmdCheckExtraSaveData, SCRCMD_WORK_CmdSetBgEventGridPos, SCRCMD_WORK_CmdSetConnectGridPos, SCRCMD_WORK_CmdSetNpcGridPos, SCRCMD_WORK_CmdSetTrainerDefeatedFlag, SCRCMD_WORK_CmdClearTrainerDefeatedFlag, SCRCMD_WORK_CmdCheckTrainerDefeatedFlag, SCRCMD_WORK_CmdEndScriptStartCommProcA, SCRCMD_WORK_CmdCheckLastBattleResultA, SCRCMD_WORK_CmdEndScriptStartCommProcB, SCRCMD_WORK_CmdCheckLastBattleResultB, SCRCMD_WORK_CmdLookupTable
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
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   SCRCMD_WORK_GetChildScriptIndex  0x0215AA4C  thumb  ov010
 *   SCRCMD_WORK_RestoreScriptState  0x0215AA34  thumb  ov010
 *   SCRCMD_WORK_SetChildScriptIndex  0x0215AA48  thumb  ov010
 *   SCRCMD_WORK_SaveScriptState  0x0215AA24  thumb  ov010
 *   VM_End  0x02011290  thumb
 *   ZONEDATA_SetEventFlag  0x02014314  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MIi_CpuClear32  0x02082A7C  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   ZONEDATA_SetDirectLocation 0x02014184 thumb
 *   MAP_REPLACE_IsValidWarpId  0x02159F84  thumb  ov010
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   SCRIPT_WORK_GetGameSystem  0x02158F54  thumb  ov010
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   sScrcmdWorkFileName     0x021728E0  data  ov010  a4
 *   SCRIPT_WORK_GetCmdWork 0x02158F6C thumb ov010
 *   MSGDATA_Delete  0x02045C04  arm
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_MSGBG_CreateMenuItems  0x02190A20  thumb  ov021
 *   BMP_MENUWORK_CountItems  0x0201F91C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
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
 *   BMP_MENULIST_GetUserData  0x02020D0C  thumb
 *   BMP_MENULIST_GetListIndex  0x020202EC  thumb
 *   SCRIPT_WORK_CheckFlag  0x02159190  thumb  ov010
 *   FIELD_MSGBG_ClearInfoSysWin  0x02191164  thumb  ov021
 *   FIELD_MSGBG_InfoSysWinPrintStrNow  0x02191184  thumb  ov021
 *   SCRIPT_WORK_BackupLocalWork  0x0215909C  thumb  ov010
 *   SCRIPT_WORK_RestoreLocalWork  0x021590D4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   CONFIG_GetTextLanguage  0x020083E4  thumb
 *   CONFIG_SetTextLanguage  0x020083EC  thumb
 *   SCRIPT_WORK_ReadWorkValue   0x02159B10  thumb  ov010
 *   GFL_USE_GetRandom   0x020056EC  thumb
 *   TRCARD_SYS_CountStars  0x0216F830  thumb  ov010
 *   FIELD_CLOCK_GetTimeZone  0x021690B4  thumb  ov010
 *   FIELD_CLOCK_GetWeek  0x021690F0  thumb  ov010
 *   FIELD_CLOCK_GetMonth  0x021690D0  thumb  ov010
 *   FIELD_CLOCK_GetDay  0x021690E0  thumb  ov010
 *   FIELD_CLOCK_GetHour  0x02169100  thumb  ov010
 *   FIELD_CLOCK_GetMinute  0x02169110  thumb  ov010
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   OS_GetOwnerInfoEx 0x02087D28 arm
 *   MYSTATUS_GetSex   0x02008550  thumb
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   MISC_GetBadge 0x0200C234 thumb
 *   MISC_SetBadge  0x0200C248  thumb
 *   GF_STANDARD_GetCachedDate  0x0203F4E4  arm
 *   GAME_DATA_GetTrainerCardSign  0x02012F5C  thumb
 *   TRCARD_SIGN_SetBadgeDate  0x02008A7C  thumb
 *   MISC_CountBadges  0x0200C258  thumb
 *   SAVE_CONTROL_HasFlashSave  0x020071EC  thumb
 *   SAVE_CONTROL_IsNewGame  0x020071E4  thumb
 *   SAVE_CONTROL_GetDiffSize  0x0200723C  thumb
 *   GAME_DATA_SetWarpId  0x02012900  thumb
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GAME_DATA_SetSpecialLocation  0x0201289C  thumb
 *   MAP_REPLACE_SetFlag  0x02159F28  thumb  ov010
 *   MAP_MATRIX_ApplyReplace  0x02159CC4  thumb  ov010
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
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
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   BOX_SAVEDATA_SetFlags 0x02007A68 thumb
 *   TRCARD_SIGN_GetFromSave  0x020089C0  thumb
 *   MYSTATUS_GetTrainerView  0x02008554  thumb
 *   CURSOR_MOVE_GetTableGroup  0x02025C88  thumb
 *   TRCARD_SIGN_GetSeenBefore  0x020089F4  thumb
 *   TRCARD_SIGN_SetSeenBefore  0x02008A00  thumb
 *   MISC_GetSlotState 0x0200C308 thumb
 *   MISC_SetSlotState   0x0200C2F0  thumb
 *   SAVE_CONTROL_LoadExtraSave  0x0200725C  thumb
 *   SAVE_CONTROL_GetExtraSaveRecord  0x020073D8  thumb
 *   DENDOU_SAVEDATA_GetRecordCount  0x0200ECB4  thumb
 *   SAVE_CONTROL_DeleteExtraSave  0x020072A4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_SetBgEventGridPos  0x02162A74  thumb  ov010
 *   EVENTDATA_SYSTEM_SetConnectGridPos  0x02162708  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcGridPos  0x02162748  thumb  ov010
 *   SCRCMD_NETWORK_CreateCommProcEvent  0x0215F6E8  thumb  ov010
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   GAME_DATA_GetLastBattleResult 0x02012A44 thumb
 *   EVENT_BATTLE_IsResultSilent 0x0216EFA8 thumb ov010
 *   gScrcmdValueTable 0x02171160 data a2
 *   EVENT_TRAINER_CheckDefeatedFlag  0x0215A4D8  thumb  ov010
 *   EVENT_TRAINER_SetDefeatedFlag  0x0215A4EC  thumb  ov010
 *   EVENT_TRAINER_ClearDefeatedFlag  0x0215A500  thumb  ov010
 */
#include "../version.h"
#include "../arm9/btl_setup_types.h"

#include "../types.h"

#define NULL ((void *)0)

struct ScriptWork;
struct ScriptVm;
struct GameSystem;
struct GameData;
struct MmdlSys;
struct MsgBank;
struct WordSet;
struct Strbuf;
struct BmpMenuWork;
struct BmpMenuList;
struct FieldMenu;
struct FieldMsgWindow;
struct TcbTask;

#include "../ov021/field_msgbg_types.h"

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
    struct MmdlSys *occupyInfo;     /* 0x00C: the move model system */
    void *targetObject;             /* 0x010 */
    struct TcbTask *animeTasks[8]; /* 0x014 */
    ScrcmdMenu menu;                /* 0x034 */
    u8 wordSetWork[0x28];           /* 0x0D4 */
    void *msgWindow; /* 0x0FC */
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
#include "../arm9/gf_standard_types.h"

struct ZukanSave;
struct MiscSave;
struct RecordSave;
struct BoxManager;
struct EventWork;
struct EventData;
struct MapMatrix;

                   
#include "script_work.h"
struct ScriptFieldParam;
#include "script_sys.h"
#include "script_work_cmd.h"
#include "../arm9/vm.h"

/* map_matrix.c, map_replace.c, warp table */
#include "map_matrix.h"
/* extent: two bytes of zero alignment padding at 0x02159F52. */
#include "map_replace.h"

/* event_poke_status.c (event work flag offsets) */
/* interface: original narrows r1 by shift pairs; u16 extern preserves this. */
#include "event_trainer.h"

/* game system and game data */
#include "../arm9/gamesystem.h"
extern void *GAME_DATA_GetOccupyInfo(struct GameData *gameData);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *playerWork);
extern u32 GAME_DATA_GetPlayerDirectionType(const struct PlayerWork *playerWork);
extern struct PlayerPosition *GAME_DATA_GetPlayerPosition(struct PlayerWork *playerWork);
extern void GAME_DATA_SetSpecialLocation(struct GameData *gameData, const struct Location *location);
#ifdef __MWERKS__
extern void GAME_DATA_SetWarpId(struct GameData *gameData, int warpId); /* original prototype; the definition differs in argument width */
#else
extern void GAME_DATA_SetWarpId(struct GameData*, u16);
#endif
extern unsigned int GAME_DATA_GetFieldWork(struct GameData *gameData);
extern u8 GAME_DATA_GetSeason(struct GameData *gameData);
extern void *GAME_DATA_GetEventWork(struct GameData *gameData);
extern unsigned int GAME_DATA_GetBoxManager(struct GameData *gameData);
extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern void *GAME_DATA_GetTrainerCardSign(struct GameData *gameData);
extern void *GAME_DATA_GetEventData(struct GameData *gameData);
extern u32 GAME_DATA_GetLastBattleResult(struct GameData *gameData);
#include "../arm9/zonedata.h"
#ifdef __MWERKS__
extern void ZONEDATA_SetDirectLocation(struct Location *location, int zoneId, s16 direction, u32 x, u32 y, u32 z); /* original prototype; the definition differs in argument sign, argument width */
#else
#endif

/* save data */
#include "../arm9/system_data.h"
#include "../arm9/config.h"
#include "../arm9/mystatus.h"
#include "../arm9/save_control.h"
#include "../arm9/box_savedata.h"
#include "../arm9/dendou_savedata.h"
struct TrainerCardSignature;
#include "../arm9/trcard_sign.h"
#include "../arm9/beacon.h"
extern void *ZUKAN_SAVE_GetFromGameData(void *gameData);
extern struct ZukanSave *ZUKAN_SAVE_EnableNationalDex(struct ZukanSave *zukan);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct ZukanSave *zukan);
extern struct ZukanSave *ZUKAN_SAVE_SetDexObtained(struct ZukanSave *zukan);
extern void ZUKAN_SAVE_RegisterSeen(struct ZukanSave *zukan, void *pokemon);
#ifdef __MWERKS__
extern int ZUKAN_SAVE_IsSeen(struct ZukanSave *zukan, int species); /* original prototype; the definition differs in return type, argument width */
#else
extern u32 ZUKAN_SAVE_IsSeen(struct ZukanSave*, u16);
#endif
#ifdef __MWERKS__
extern int ZUKAN_SAVE_IsCaught(struct ZukanSave *zukan, int species); /* original prototype; the definition differs in return type, argument width */
#else
extern u32 ZUKAN_SAVE_IsCaught(struct ZukanSave*, u16);
#endif
extern u16 ZUKAN_SAVE_CountSeenNational(struct ZukanSave *zukan);
extern u16 ZUKAN_SAVE_CountCaughtNational(struct ZukanSave *zukan);
struct EventDataSystem;
extern void EVENTDATA_SYSTEM_SetBgEventGridPos(struct EventDataSystem *system, u32 index, u32 gridX, u32 height, u16 gridZ);
struct EventDataSystem;
extern void EVENTDATA_SYSTEM_SetConnectGridPos(struct EventDataSystem *system, unsigned int index, unsigned short gridX, unsigned int height, unsigned short gridZ);
#ifdef __MWERKS__
extern void EVENTDATA_SYSTEM_SetNpcGridPos(struct EventData *eventData, int eventId, int direction, u16 x, int y, u16 z); /* original prototype; the definition differs in pointer type, argument sign, argument width */
#else
extern void EVENTDATA_SYSTEM_SetNpcGridPos(struct EventDataSystem*, u32, u16, u16, u32, u16);
#endif
#include "event_battle.h"
struct GameEvent;
typedef int Bool;
#include "scrcmd_network.h"

/* system */
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/mi_memory.h"
#include "../arm9/key.h"
#include "../arm9/gfl_use.h"
#include "../arm9/cursor_move.h"
struct OSOwnerInfoEx;
#include "../arm9/os_ownerinfoex.h"
#include "../arm9/gf_standard.h"
#ifdef __MWERKS__
extern void *POKE_TOOL_Create(u32 species, u32 level, u64 id, u32 heapId); /* original prototype; the definition differs in return type, argument width */
#else
#include "../arm9/poke_tool.h"
#endif

/* message data, strings, menus */
#include "../arm9/msgdata.h"
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/bmp_menulist.h"
#include "../ov021/field_msgbg.h"
struct FieldMsgBg;
struct FieldMenuFunc;
struct FieldMenuFunc;
struct FieldSysWin;
#include "../ov021/fldmmdl_acmd.h"
#include "trcard_sys.h"
#include "field_clock.h"

extern const char sScrcmdWorkFileName[];
extern FieldMenuHeader gScrcmdMenuHeader;
extern const u16 gScrcmdValueTable[];

void SCRCMD_WORK_MenuCursorCallback(struct BmpMenuList *list);

ScrcmdCommonWork *SCRCMD_WORK_CreateCommon(struct ScriptWork *scriptWork, int heapId)
{
    ScrcmdCommonWork *common = GFL_HEAP_Alloc(heapId, 0x110, 1, sScrcmdWorkFileName, 0x78);

    common->scriptWork = scriptWork;
    common->gameSystem = SCRIPT_WORK_GetGameSystem(scriptWork);
    common->gameData = GAMESYSTEM_GetGameData(common->gameSystem);
    common->occupyInfo = GAME_DATA_GetOccupyInfo(common->gameData);
    common->windowState = 7;
    return common;
}

/* Tail call through a pool word and `bx r3` into the arm9 heap free. */
void SCRCMD_WORK_DeleteCommon(ScrcmdCommonWork *common)
{
    GFL_HEAP_Free(common);
}

/*
 * lever: const source pointer hoists its copy before the destination id store.
 */
ScrcmdWork *SCRCMD_WORK_Create(const ScrcmdWorkParam *param, int heapId)
{
    ScrcmdWork *work;
    const ScrcmdWorkParam *src;
    work = GFL_HEAP_Alloc((unsigned short)((heapId & 0x7fff) | 0x8000), 0x24, 1, sScrcmdWorkFileName, 0x94);
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
        GFL_HEAP_Free(work->savedLocalWork);
    if (work->msgData != NULL)
        MSGDATA_Delete(work->msgData);
    SCRCMD_WORK_DeleteAnimeTasks(work);
    GFL_HEAP_Free(work);
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

struct MmdlSys *SCRCMD_WORK_GetMmdlSys(ScrcmdWork *work)
{
    return work->common->occupyInfo;
}

struct ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *work)
{
    return work->common->scriptWork;
}

int SCRCMD_WORK_GetMenuHeap(ScrcmdWork *work)
{
    return *(s32 *)SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(work));
}

struct MsgBank *SCRCMD_WORK_GetMsgData(ScrcmdWork *work)
{
    return work->msgData;
}

u16 SCRCMD_WORK_GetMsgDataId(ScrcmdWork *work)
{
    return work->msgDataId;
}

void SCRCMD_WORK_SetMsgWindow(ScrcmdWork *work, void *window)
{
    work->common->msgWindow = window;
}

void *SCRCMD_WORK_GetMsgWindow(ScrcmdWork *work)
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

void SCRCMD_WORK_AddAnimeTask(ScrcmdWork *work, struct TcbTask *task)
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
    work->msgData = MSGDATA_CreateFromArchive(0, (u16)arcId, (u16)fileId, work->heapId);
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
    MIi_CpuClear32(0, menu->itemHelp, 0x80);
    if (menu->msgData == NULL) {
        menu->ownsMsgData = 1;
        menu->msgData = MSGDATA_CreateFromArchive(0, 3, 0x80 + 0x86, work->heapId);
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
        MSGDATA_ReadString(menu->msgData, helpMsgId, tmp);
        WORDSET_CopyTaggedText(menu->wordSet, str, tmp);
        menu->itemHelp[index] = STRBUF_Clone(str, work->heapId);
    }
    MSGDATA_ReadString(menu->msgData, msgId, tmp);
    WORDSET_CopyTaggedText(menu->wordSet, str, tmp);
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
    width = FIELD_MSGBG_GetMenuItemsWidthChars((void *)heap, menu->items, header.fontId, header.cursorMargin);
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
    menu->fieldMenu = (struct FieldMenu *)FIELD_MSGBG_CreateMenuFuncWork((void *)heap, &header, menu->items, (uptr)SCRCMD_WORK_MenuCursorCallback, (uptr)work, 0, menu->cursorPos, menu->cancelable);
}

void SCRCMD_WORK_DeleteMenu(ScrcmdMenu *menu)
{
    int i;
    FIELD_MSGBG_DeleteMenuFunc((struct FieldMenuFunc *)menu->fieldMenu);
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
    selected = FIELD_MSGBG_MenuFuncMain((struct FieldMenuFunc *)menu->fieldMenu);
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
    ScrcmdWork *work = (struct ScrcmdWork *)BMP_MENULIST_GetUserData(list);
    ScrcmdMenu *menu = &work->common->menu;
    BMP_MENULIST_GetListIndex(list, &index);
    if (menu->itemHelp[index] != NULL) {
        if (SCRIPT_WORK_CheckFlag(1) != 0) {
            void *window = SCRCMD_WORK_GetMsgWindow(work);
            FIELD_MSGBG_ClearInfoSysWin((struct FieldSysWin *)window);
            FIELD_MSGBG_InfoSysWinPrintStrNow((struct FieldSysWin *)window, 0, 0, menu->itemHelp[index]);
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
    *ret = PM_VERSION_ID;
    return 0;
}

int SCRCMD_WORK_CmdToggleConfigFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    int flag;
    config = SYSTEM_DATA_GetConfig(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(work)));
    flag = CONFIG_GetTextLanguage(config);
    if (flag == 0) {
        flag = 1;
    } else if (flag == 1) {
        flag = 0;
    }
    CONFIG_SetTextLanguage(config, flag);
    return 0;
}

int SCRCMD_WORK_CmdGetConfigFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    u16 *ret;
    config = SYSTEM_DATA_GetConfig(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(work)));
    ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = CONFIG_GetTextLanguage(config);
    return 0;
}

int SCRCMD_WORK_CmdGetRandom(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = (u16)GFL_USE_GetRandom(SCRIPT_WORK_ReadWorkValue(vm, work));
    return 0;
}

int SCRCMD_WORK_CmdGetMsgDataId(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = SCRCMD_WORK_GetMsgDataId(work);
    return 0;
}

int SCRCMD_WORK_CmdGetTrainerCardStars(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = TRCARD_SYS_CountStars(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetTimeZone(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = FIELD_CLOCK_GetTimeZone(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetWeek(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = FIELD_CLOCK_GetWeek(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetMonthAndDay(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    u16 *retFirst = SCRIPT_WORK_ReadWorkPointer(vm, work);
    u16 *retSecond = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *retFirst = FIELD_CLOCK_GetMonth(gameData);
    *retSecond = FIELD_CLOCK_GetDay(gameData);
    return 0;
}

int SCRCMD_WORK_CmdGetHourAndMinute(struct ScriptVm *vm, ScrcmdWork *work)
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
    *ret = GAME_DATA_GetSeason(SCRCMD_WORK_GetGameData(work));
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
    OS_GetOwnerInfoEx((struct OSOwnerInfoEx *)(&info));
    *retMonth = info.month;
    *retDay = info.day;
    return 0;
}

int SCRCMD_WORK_CmdGetPlayerSex(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = (u16)MYSTATUS_GetSex(&GAME_DATA_GetMyPlayerWork(SCRCMD_WORK_GetGameData(work))->status);
    return 0;
}

int SCRCMD_WORK_CmdCheckBadge(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    int flagId = SCRIPT_WORK_ReadWorkValue(vm, work);
    *ret = MISC_GetBadge(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), flagId);
    return 0;
}

int SCRCMD_WORK_CmdSetBadge(struct ScriptVm *vm, ScrcmdWork *work)
{
    RTCDate date;
    int flagId = SCRIPT_WORK_ReadWorkValue(vm, work);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    MISC_SetBadge(GAME_DATA_GetMiscSave(gameData), flagId);
    GF_STANDARD_GetCachedDate(&date);
    TRCARD_SIGN_SetBadgeDate(GAME_DATA_GetTrainerCardSign(gameData), flagId, date.year, date.month, date.day);
    return 0;
}

int SCRCMD_WORK_CmdGetBadgeCount(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = MISC_CountBadges(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)));
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
    *retFirst = SAVE_CONTROL_HasFlashSave(saveControl);
    *retSecond = SAVE_CONTROL_IsNewGame(saveControl);
    SAVE_CONTROL_GetDiffSize(saveControl, &used, &total);
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
    if (MAP_REPLACE_IsValidWarpId(warpId) == 1) {
        GAME_DATA_SetWarpId(gameData, warpId);
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
    struct PlayerWork *playerWork = GAME_DATA_GetMyPlayerWork(gameData);
    struct PlayerPosition *position = GAME_DATA_GetPlayerPosition(playerWork);
    int zoneId = GAME_DATA_GetPlayerZoneId(playerWork);
    ZONEDATA_SetDirectLocation(&location, zoneId, (short)GAME_DATA_GetPlayerDirectionType(playerWork), position->x, position->y, position->z);
    GAME_DATA_SetSpecialLocation(gameData, &location);
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
    GAME_DATA_SetSpecialLocation(gameData, &location);
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
    MAP_REPLACE_SetFlag((sptr)gameData, replaceId, enable);
    if (applyNow != 0) {
        mapMatrix = (struct MapMatrix *)GAME_DATA_GetFieldWork(gameData);
        zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
        matrixId = ZONEDATA_GetMatrixId(zoneId);
        heapId = SCRCMD_WORK_GetHeapId(work);
        MAP_MATRIX_Load(mapMatrix, matrixId, zoneId, heapId);
        MAP_MATRIX_ApplyReplace(mapMatrix, (sptr)gameSystem, heapId);
    }
    return 0;
}

int SCRCMD_WORK_CmdCheckMapReplaceFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    int replaceId = SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = MAP_REPLACE_CheckFlag((sptr)gameData, replaceId);
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
    GFL_HEAP_Free(pokemon);
    return 0;
}

int SCRCMD_WORK_CmdCheckZukanSeenOrCaught(struct ScriptVm *vm, ScrcmdWork *work)
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

int SCRCMD_WORK_CmdGetNationalZukanCount(struct ScriptVm *vm, ScrcmdWork *work)
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

int SCRCMD_WORK_CmdEnableNationalDex(struct ScriptVm *vm, ScrcmdWork *work)
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

int SCRCMD_WORK_CmdSetZukanObtained(struct ScriptVm *vm, ScrcmdWork *work)
{
    ZUKAN_SAVE_SetDexObtained(ZUKAN_SAVE_GetFromGameData(SCRCMD_WORK_GetGameData(work)));
    return 0;
}

int SCRCMD_WORK_CmdGetButtonMode(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct Config *config;
    u16 *ret;
    config = SYSTEM_DATA_GetConfig(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(work))));
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
    ZONEDATA_SetEventFlag(GAME_DATA_GetEventWork(SCRCMD_WORK_GetGameData(work)), 0x963);
    return 0;
}

int SCRCMD_WORK_CmdSetBoxFlags(struct ScriptVm *vm, ScrcmdWork *work)
{
    int bits = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    struct BoxManager *boxManager = (struct BoxManager *)GAME_DATA_GetBoxManager(SCRCMD_WORK_GetGameData(work));
    if ((u16)(bits + 0xFFFF) <= 1)
        BOX_SAVEDATA_SetFlags((struct GameData *)boxManager, bits);
    return 0;
}

int SCRCMD_WORK_CmdGetTrainerViewGroupAndMarkSeen(struct ScriptVm *vm, ScrcmdWork *work)
{
    unsigned short *retSecond;
    unsigned short *retFirst;
    struct GameData *gameData;
    struct PlayerWork *playerWork;
    struct RecordSave *record;
    retSecond = SCRIPT_WORK_ReadWorkPointer(vm, work);
    retFirst = SCRIPT_WORK_ReadWorkPointer(vm, work);
    gameData = SCRCMD_WORK_GetGameData(work);
    playerWork = GAME_DATA_GetMyPlayerWork(gameData);
    record = (struct RecordSave *)TRCARD_SIGN_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    *retFirst = CURSOR_MOVE_GetTableGroup(MYSTATUS_GetTrainerView(&playerWork->status));
    *retSecond = TRCARD_SIGN_GetSeenBefore((struct TrainerCardSignature *)record);
    TRCARD_SIGN_SetSeenBefore((struct TrainerCardSignature *)record);
    return 0;
}

int SCRCMD_WORK_CmdGetMiscByte(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = (MISC_GetSlotState(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), index) & 1) != 0;
    return 0;
}

int SCRCMD_WORK_CmdSetMiscByte(struct ScriptVm *vm, ScrcmdWork *work)
{
    u32 index = SCRIPT_WORK_ReadWorkValue(vm, work);
    MISC_SetSlotState(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), index, 1);
    return 0;
}

int SCRCMD_WORK_CmdCheckMiscByte(struct ScriptVm *vm, ScrcmdWork *work)
{
    int index = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    if (MISC_GetSlotState(GAME_DATA_GetMiscSave(SCRCMD_WORK_GetGameData(work)), index) == 3)
        *ret = 1;
    else
        *ret = 0;
    return 0;
}

int SCRCMD_WORK_CmdCheckExtraSaveData(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
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
            if (DENDOU_SAVEDATA_GetRecordCount(SAVE_CONTROL_GetExtraSaveRecord(saveControl, 8, 0)) == 0) {
                *ret = 0;
            } else {
                *ret = 1;
            }
            break;
        default:
            *ret = 2;
            break;
        }
        SAVE_CONTROL_DeleteExtraSave(saveControl, 8);
    } else {
        *ret = 0;
    }
    return 0;
}

int SCRCMD_WORK_CmdSetBgEventGridPos(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 x = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 y = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 z = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENTDATA_SYSTEM_SetBgEventGridPos((void *)(GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData(work))), (s32)eventId, (u16)x, (u16)y, z);
    return 0;
}

int SCRCMD_WORK_CmdSetConnectGridPos(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 x = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 y = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 z = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENTDATA_SYSTEM_SetConnectGridPos(GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData(work)), eventId, x, (u16)y, z);
    return 0;
}

int SCRCMD_WORK_CmdSetNpcGridPos(struct ScriptVm *vm, ScrcmdWork *work)
{
    int eventId = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    int direction = (int)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 x = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 y = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    s16 z = (s16)SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENTDATA_SYSTEM_SetNpcGridPos(GAME_DATA_GetEventData(SCRCMD_WORK_GetGameData(work)), eventId, direction, x, y << 16, z);
    return 0;
}

int SCRCMD_WORK_CmdSetTrainerDefeatedFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
    unsigned offset = SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENT_TRAINER_SetDefeatedFlag((char *)eventWork, offset);
    return 0;
}

int SCRCMD_WORK_CmdClearTrainerDefeatedFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(work);
    struct EventWork *eventWork = GAME_DATA_GetEventWork(gameData);
    unsigned offset = SCRIPT_WORK_ReadWorkValue(vm, work);
    EVENT_TRAINER_ClearDefeatedFlag((char *)eventWork, offset);
    return 0;
}

int SCRCMD_WORK_CmdCheckTrainerDefeatedFlag(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct EventWork *eventWork = GAME_DATA_GetEventWork(SCRCMD_WORK_GetGameData(work));
    unsigned offset = SCRIPT_WORK_ReadWorkValue(vm, work);
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    *ret = EVENT_TRAINER_CheckDefeatedFlag(eventWork, offset);
    return 0;
}

int SCRCMD_WORK_CmdEndScriptStartCommProcA(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    SCRIPT_SYS_SetNextEventFromWork(scriptWork, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
    VM_End(vm);
    return 1;
}

int SCRCMD_WORK_CmdCheckLastBattleResultA(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    int notSilent = 1;
    if (EVENT_BATTLE_IsResultSilent(GAME_DATA_GetLastBattleResult(SCRCMD_WORK_GetGameData(work)), 1) == 1)
        *ret = 0;
    else
        *ret = notSilent;
    return 0;
}

int SCRCMD_WORK_CmdEndScriptStartCommProcB(struct ScriptVm *vm, ScrcmdWork *work)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(work);
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(work);
    SCRIPT_SYS_SetNextEventFromWork(scriptWork, SCRCMD_NETWORK_CreateCommProcEvent(gameSystem));
    VM_End(vm);
    return 1;
}

int SCRCMD_WORK_CmdCheckLastBattleResultB(struct ScriptVm *vm, ScrcmdWork *work)
{
    u16 *ret = SCRIPT_WORK_ReadWorkPointer(vm, work);
    int silent = 0;
    if (EVENT_BATTLE_IsResultSilent(GAME_DATA_GetLastBattleResult(SCRCMD_WORK_GetGameData(work)), 0) == 1)
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
