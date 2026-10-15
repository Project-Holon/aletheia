/*
 * file:     scrcmd_network.c
 * unit:     yes
 * function: SCRCMD_NETWORK_WaitCommState, SCRCMD_NETWORK_CmdWaitCommState, SCRCMD_NETWORK_CmdGetCommValue, SCRCMD_NETWORK_CmdStartAutoComm, SCRCMD_NETWORK_CmdRequestCommExit, SCRCMD_NETWORK_CmdRestartAutoComm, SCRCMD_NETWORK_CmdUnblockComm, SCRCMD_NETWORK_CmdGetAlwaysNet, SCRCMD_NETWORK_CmdClearAlwaysNet, SCRCMD_NETWORK_CmdLoadNpcTable, SCRCMD_NETWORK_CmdFreeNpcTable, SCRCMD_NETWORK_CmdSetNpcEventFromTable, SCRCMD_NETWORK_CmdSetNpcEventPairFromTable, SCRCMD_NETWORK_CmdSetNpcTripleFromTable, SCRCMD_NETWORK_CmdApplyTableEventKeys, SCRCMD_NETWORK_PickSixDistinctRandom, SCRCMD_NETWORK_FindNpcTableRow, SCRCMD_NETWORK_HasSituationWarpChanged, SCRCMD_NETWORK_CommProcEventMain, SCRCMD_NETWORK_CreateCommProcEvent, SCRCMD_NETWORK_CommBattleEventMain, SCRCMD_NETWORK_CreateCommBattleEvent, SCRCMD_NETWORK_InitCommBattleOv180Param, SCRCMD_NETWORK_InitCommBattleOv181Param, SCRCMD_NETWORK_InitCommBattleStepSequence, SCRCMD_NETWORK_GetCommExitKind, SCRCMD_NETWORK_AdvanceStep, SCRCMD_NETWORK_SetupMiscSave, SCRCMD_NETWORK_CreateOv020Event, SCRCMD_NETWORK_LoadOv020Task, SCRCMD_NETWORK_LoadOv020, SCRCMD_NETWORK_UnloadOv020, SCRCMD_NETWORK_WifiProcEventMain, SCRCMD_NETWORK_CreateWifiProcEvent, SCRCMD_NETWORK_CreateBattleRecordLinkEvent, SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone, SCRCMD_NETWORK_BattleRecordLinkEventMain, SCRCMD_NETWORK_GetRecordKindByFrameRate, SCRCMD_NETWORK_RecordLinkOnUpdate, SCRCMD_NETWORK_RecordLinkOnClose, SCRCMD_NETWORK_RecordLinkOnFinish
 * address:  0x0215F168
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
 *   EVENT_SHORTCUT_MENU_CreateProcEvent  0x0216075C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_CreateCommExitEvent  0x02161B90  thumb  ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   SCRIPT_WORK_GetUserWorkPtr  0x02158FB4  thumb  ov010
 *   FIELDMAP_CheckCommExit  0x02189734  thumb
 *   func_020307B0  0x020307B0  arm
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   SCRCMD_NETWORK_sFileName     0x0217294C  data  ov010  a4
 *   VM_SetWait  0x020113D0  thumb
 *   func_0202EB44  0x0202EB44  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_SetCommBlocked  0x0201213C  thumb
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag   0x02159168  thumb  ov010
 *   func_0201214C  0x0201214C  thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 *   SCRIPT_WORK_SetReturnFlag 0x02159114 thumb ov010
 *   SCRIPT_WORK_GetReturnFlag  0x0215911C  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetField158  0x02012844  thumb
 *   func_0215A480  0x0215A480  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcEventId  0x02162788  thumb  ov010
 *   func_0215A490  0x0215A490  thumb  ov010
 *   EVENTDATA_SYSTEM_SetNpcObjCode  0x02162774  thumb  ov010
 *   SCRIPT_WORK_GetGameSystem 0x02158F54 thumb ov010
 *   func_0215A500 0x0215A500 thumb ov010
 *   func_020056EC  0x020056EC  thumb
 *   func_02159F80 0x02159F80 thumb ov010
 *   GAME_DATA_GetSituationWarpId 0x02012914 thumb
 *   BRIGHTNESS_Set  0x02023F60  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   d_021B9EC0     0x021B9EC0  data  a4
 *   ov_id_00CD     0x000000CD  data  a1
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_02012944  0x02012944  thumb
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   SYMBOL_MAP_DeleteLinkRecord  0x021666A4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent  0x02014554  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   SCRIPT_SYS_RunRecoverScript  0x02158A20  thumb  ov010
 *   ov180_id       0x000000B4  data
 *   ov181_id       0x000000B5  data
 *   ov205_id       0x000000CD  data
 *   ov182_id       0x000000B6  data
 *   d_021B800C     0x021B800C  data  ov180
 *   d_021BAB24     0x021BAB24  data  ov181
 *   d_021B9E54     0x021B9E54  data  ov205
 *   d_021B9BA0     0x021B9BA0  data  ov182
 *   MOVE_POKEMON_SpawnPendingEntries  0x0215E580  thumb  ov010
 *   GAME_DATA_GetMyParty   0x02012934  thumb
 *   GAME_DATA_GetPlayTime   0x02012FCC  thumb
 *   func_0200873C  0x0200873C  thumb
 *   CONFIG_GetAppliedFlag  0x020083E4  thumb
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_SetGatePoints  0x0200C3B8  thumb
 *   func_02034AC4 0x02034AC4 arm
 *   EVENT_MAPCHANGE_CreateByMode 0x02183B6C thumb ov020
 *   EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent      0x0218571C  thumb  ov020
 *   abs_id_14      0x00000014  data
 *   GF_OVERLAY_Load   0x02034AC4  arm
 *   GF_OVERLAY_Unload   0x02034A5C  arm
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   INTRUDE_SUBDISP_CreateTownWarpEvent  0x0217CE08  thumb
 *   INTRUDE_SUBDISP_CreateGuideScriptEvent  0x0217CDBC  thumb
 *   EVENT_COMM_COMMON_CreateReturnPalaceEvent  0x0217FA24  thumb
 *   ov122_id       0x0000007A  data
 *   ov172_id       0x000000AC  data
 *   d_021D5764     0x021D5764  data  ov122
 *   d_021C7240     0x021C7240  data
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb  ov021
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   func_020355D8  0x020355D8  arm
 *   FIELDMAP_GetZoneId 0x02188C9C thumb ov021
 *   ZONEDATA_IsZone96Pair 0x02013CE0 thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   FIELD_SUBSCREEN_ClearPanelResult  0x021A0FA8  thumb  ov021
 *   FIELD_SUBSCREEN_GetMenuSelectedButton  0x021A12A4  thumb  ov021
 *   func_021945A4  0x021945A4  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   MOVE_POKEMON_InitSkillInfo  0x0215E840  thumb  ov010
 *   MOVE_POKEMON_InitSkillTarget  0x0215EA30  thumb  ov010
 *   MOVE_POKEMON_CreateSkillEvent  0x0215EA38  thumb  ov010
 *   EVENTDATA_SYSTEM_CreateFieldLinkEvent  0x021644F4  thumb  ov010
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_DATA_SetFrameRate  0x020129D0  thumb
 *   SCRCMD_NETWORK_sRecordKindByFrameRate     0x021712AC  data
 *   FIELD_SUBSCREEN_SetMenuSelectedButton   0x021A12BC  thumb
 */

struct ScriptVm;
struct ScriptWork;
struct ScriptCtl;
struct GameSystem;
struct GameData;
struct GameComm;
struct GameEvent;
struct FieldMap;
struct FieldCommLink;
struct MoveModelSys;
struct SaveControl;
struct MyStatus;
struct PokeParty;
struct Config;
struct EventDataSystem;
struct EventWork;
struct MiscSave;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed int s32;

typedef enum { FALSE, TRUE } BOOL;

#include "../arm9/script_vm_types.h"

/* Event task callback: (event, sequence counter, work). */
typedef int (*EventTaskFn)(struct GameEvent *event, u32 *seq, void *work);

/* Wait callback of a script command: receives the script work as user data. */
typedef int (*ScriptWorkWaitFn)(ScriptVm *vm, struct ScriptWork *scriptWork);

/* Heap block behind the script command "wait for the comm state". */
typedef struct CommWaitWork {
    u16 *resultVar;     /* 0x00: script variable that receives 2 when the state is 2 */
} CommWaitWork;

/*
 * One row of the 0x6B-row table in archive member 0xD1 (8 bytes). A row is
 * found by its two keys; the other two fields feed the NPC records of the
 * event data.
 */
#define NPC_TABLE_ROW_COUNT 0x6B

typedef struct NpcTableRow {
    u16 keyA;           /* 0x00 */
    u16 keyB;           /* 0x02 */
    u16 objCode;        /* 0x04: stored as is in the NPC record */
    u16 eventKey;       /* 0x06: converted to the NPC event ids */
} NpcTableRow;

/* Work of the event that starts a comm session from the field (0xC bytes). */
typedef struct CommProcEventWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    int warpChanged;                /* 0x04: selects the script id */
    struct MyStatus *myStatus;      /* 0x08 */
} CommProcEventWork;

/* Parameter blocks that the comm battle event passes to its procs. */
typedef struct CommBattleOv205Param {
    struct GameSystem *gameSystem;  /* 0x00 */
    u32 mode;                       /* 0x04 */
} CommBattleOv205Param;

typedef struct CommBattleOv180Param {
    struct PokeParty *myParty;      /* 0x00 */
    struct MyStatus *myStatus;      /* 0x04 */
    u32 playTime;                   /* 0x08 */
} CommBattleOv180Param;

typedef struct CommBattleOv181Param {
    u32 isMode1;                    /* 0x00 */
    u32 configApplied;              /* 0x04 */
} CommBattleOv181Param;

/* Steps of the comm battle event; the order comes from the sequence table. */
enum {
    COMM_BATTLE_STEP_PREPARE,
    COMM_BATTLE_STEP_FIELD_PREPARE_EVENT,
    COMM_BATTLE_STEP_REQUEST_COMM_IDLE,
    COMM_BATTLE_STEP_WAIT_COMM_IDLE,
    COMM_BATTLE_STEP_CLOSE_FIELD,
    COMM_BATTLE_STEP_CALL_OV180,
    COMM_BATTLE_STEP_WAIT_OV180,
    COMM_BATTLE_STEP_CALL_OV181,
    COMM_BATTLE_STEP_WAIT_OV181,
    COMM_BATTLE_STEP_COMM_EXIT_EVENT,
    COMM_BATTLE_STEP_SET_SCRIPT_STATE,
    COMM_BATTLE_STEP_CALL_OV205,
    COMM_BATTLE_STEP_WAIT_FRAMES,
    COMM_BATTLE_STEP_CALL_OV182,
    COMM_BATTLE_STEP_DONE,
    COMM_BATTLE_STEP_ABORT
};

/* Work of the comm battle event (0x7C bytes). */
typedef struct CommBattleWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameData *gameData;      /* 0x04 */
    u32 mode;                       /* 0x08: 1 selects the second step sequence */
    u8 pad0C[4];
    struct MyStatus *myStatus;      /* 0x10 */
    CommBattleOv205Param ov205Param;/* 0x14 */
    CommBattleOv180Param ov180Param;/* 0x1C */
    CommBattleOv181Param ov181Param;/* 0x28 */
    u32 ov182Param;                 /* 0x30: configApplied again */
    u32 step;                       /* 0x34: seq[current index] */
    u32 seq[16];                    /* 0x38 */
    int frameCount;                 /* 0x78 */
} CommBattleWork;

/* Work of the event that opens the Wi-Fi screens (0x34 bytes). */
typedef struct WifiProcWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameData *gameData;      /* 0x04 */
    struct SaveControl *saveControl;/* 0x08 */
    u8 ov172Param[0x10];            /* 0x0C: parameter block of the ov172 task */
    u32 exitRequest;                /* 0x1C: cleared once the screens closed */
    u32 entryKind;                  /* 0x20: 0 opening, 1 with BGM change */
    u32 savedBgmNo;                 /* 0x24 */
    u32 exitKind;                   /* 0x28: picks the closing screen */
    u8 pad2C[0x34 - 0x2C];
} WifiProcWork;

/* Skill (hidden move) structs shared with move_pokemon.c. */
typedef struct FieldSkillInfo {
    u16 zoneId;                     /* 0x00 */
    u16 usableMask;                 /* 0x02 */
    u32 playerState;                /* 0x04 */
    struct GameSystem *gameSystem;  /* 0x08 */
    void *playerObj;                /* 0x0C */
    struct FieldMap *fieldMap;      /* 0x10 */
} FieldSkillInfo;

typedef struct FieldSkillTarget {
    u16 partySlot;                  /* 0x00 */
    u16 skillIndex;                 /* 0x02 */
    u32 targetParam;                /* 0x04 */
} FieldSkillTarget;

struct RecordLinkWork;

/*
 * Request object that the battle record link hands to the shortcut menu
 * event (event_shortcut_menu.c reads kind/detail/result/next). It sits at
 * 0x1C inside RecordLinkWork and is 0x34 bytes.
 */
typedef struct ShortcutRequest {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct FieldMap *fieldMap;      /* 0x04 */
    struct GameEvent *event;        /* 0x08 */
    u32 kind;                       /* 0x0C */
    int detail;                     /* 0x10: -1 */
    int (*onUpdate)(struct ShortcutRequest *request, struct RecordLinkWork *work);  /* 0x14 */
    int (*onClose)(struct ShortcutRequest *request, struct RecordLinkWork *work);   /* 0x18 */
    int (*onFinish)(struct ShortcutRequest *request, struct RecordLinkWork *work);  /* 0x1C */
    struct RecordLinkWork *work;    /* 0x20 */
    u32 result;                     /* 0x24: set by the menu */
    u32 next;                       /* 0x28: chosen menu entry */
    u32 partySlot;                  /* 0x2C */
    u32 targetParam;                /* 0x30 */
} ShortcutRequest;

/* Work of the battle record link event (0x5C bytes). */
typedef struct RecordLinkWork {
    u16 id;                         /* 0x00 */
    u8 pad02[2];
    struct GameEvent *event;        /* 0x04 */
    struct GameSystem *gameSystem;  /* 0x08 */
    struct FieldMap *fieldMap;      /* 0x0C */
    u32 frameRate;                  /* 0x10 */
    u32 state;                      /* 0x14 */
    int linkMode;                   /* 0x18: 3, 4, 2 or 5 */
    ShortcutRequest request;        /* 0x1C */
    u8 pad50[0x5C - 0x50];
} RecordLinkWork;

/* script work (ov010) */
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScriptWork *scriptWork);
extern struct ScriptCtl *SCRCMD_WORK_GetScriptWork(struct ScriptWork *scriptWork);
extern struct GameData *SCRCMD_WORK_GetGameData(struct ScriptWork *scriptWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, struct ScriptWork *scriptWork);
extern u32 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, struct ScriptWork *scriptWork);
extern CommWaitWork **SCRIPT_WORK_GetUserWorkPtr(struct ScriptCtl *scriptCtl);
extern struct GameSystem *SCRIPT_WORK_GetGameSystem(struct ScriptCtl *scriptCtl);
extern void SCRIPT_WORK_SetReturnFlag(struct ScriptCtl *scriptCtl, void *table);
extern void *SCRIPT_WORK_GetReturnFlag(struct ScriptCtl *scriptCtl);
extern void SCRIPT_WORK_SetCheckFlag(int flagNo);
extern void SCRIPT_WORK_ResetCheckFlag(int flagNo);
extern void func_0215A500(struct EventWork *eventWork, unsigned eventKey);
extern u16 func_0215A480(unsigned eventKey);
extern u16 func_0215A490(unsigned eventKey);
extern int func_02159F80(void);
extern void *SCRIPT_SYS_CallScriptEvent(struct GameEvent *event, u32 scriptId, u32 targetObj, u32 param, u32 mode);
extern void SCRIPT_SYS_RunRecoverScript(struct GameSystem *gameSystem, int value);
extern int INTRUDE_COMM_GetWorkIfRunning(struct GameComm *gameComm);
extern void EVENTDATA_SYSTEM_SetNpcEventId(struct EventDataSystem *eventData, unsigned slot, u16 eventId);
extern void EVENTDATA_SYSTEM_SetNpcObjCode(struct EventDataSystem *eventData, unsigned slot, u16 objCode);

/* script virtual machine */
extern void VM_SetWait(ScriptVm *vm, ScriptWorkWaitFn waitFn);

/* game system, game event, game data */
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, EventTaskFn taskFn, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern void GAME_EVENT_ChangeEvent(struct GameEvent *event, struct GameEvent *next);
extern void GAME_EVENT_Change(struct GameEvent *event, EventTaskFn taskFn, u32 workSize);
extern void GAME_EVENT_CallProc(struct GameEvent *event, u32 overlayId, const void *procData, void *procArg);
extern struct GameData *ICA_ANIME_GetField1C(struct GameSystem *gameSystem);
extern struct FieldMap *ICA_ANIME_GetField20(struct GameSystem *gameSystem);
extern struct GameComm *ICA_ANIME_GetField24(struct GameSystem *gameSystem);
extern void GAMESYSTEM_SetCommBlocked(struct GameSystem *gameSystem, u32 commBlocked);
extern u32 func_0201214C(struct GameSystem *gameSystem);
extern void GAMESYSTEM_SetAlwaysNetFlag(struct GameSystem *gameSystem, u32 alwaysNet);
extern u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSystem);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, const void *procData, void *procArg);
extern u32 GAMESYSTEM_GetProcStatus(struct GameSystem *gameSystem);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern struct PokeParty *GAME_DATA_GetMyParty(struct GameData *gameData);
extern int GAME_DATA_GetPlayTime(struct GameData *gameData);
extern struct MiscSave *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern struct EventDataSystem *GAME_DATA_GetField158(struct GameData *gameData);
extern struct EventWork *GAME_DATA_GetEventWork(struct GameData *gameData);
extern u16 GAME_DATA_GetSituationWarpId(struct GameData *gameData);
extern void *GAME_DATA_GetEventState(struct GameData *gameData);
extern void GAME_DATA_SetSubscreenType(struct GameData *gameData, u32 subscreenType);
extern void GAME_DATA_SetFrameRate(struct GameData *gameData, u8 frameRate);

/* game comm, config, misc */
extern u32 GAME_COMM_GetKind(struct GameComm *gameComm);
extern void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
extern u32 GAME_COMM_IsTransition(struct GameComm *gameComm);
extern int FIELDMAP_CheckCommExit(struct GameComm *gameComm);
extern int func_0202EB44(void);
extern struct Config *func_0200873C(struct SaveControl *saveControl);
extern int CONFIG_GetAppliedFlag(struct Config *config);
extern int BEACON_SetGatePoints(struct MiscSave *miscSave, int value);
extern u32 GPOWER_GetSpecialPowerId(void);

/* heap, archive, random, overlays, memory */
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *ptr);
extern int ARC_UTIL_LoadMember(int archiveId, int memberId, int heapId, int flags);
extern u32 func_020056EC(u32 range);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(s32 overlayId);
extern int GF_OVERLAY_Load(int overlayId);
extern void GF_OVERLAY_Unload(int overlayId);
extern void MI_CpuFill8(void *dst, int value, int size);

/* screen, sound */
extern void BRIGHTNESS_Set(s32 screen, u32 brightness, u32 mask);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 volume);
extern void GFL_USE_FadeInBgmFull(u32 frames);

/* field events and field */
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 a, u32 b);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 a, u32 b, u32 c, u32 d, u32 e);
extern struct GameEvent *INTRUDE_SUBDISP_CreateTownWarpEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 a, u32 b);
extern struct GameEvent *INTRUDE_SUBDISP_CreateGuideScriptEvent(struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_COMM_COMMON_CreateReturnPalaceEvent(struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELD_PROCLINK_CreateCommExitEvent(struct GameSystem *gameSystem, struct GameEvent *event, int kind, int sub, int flag);
extern struct GameEvent *EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_MAPCHANGE_CreateByMode(struct GameSystem *gameSystem, u32 initParam);
extern void SYMBOL_MAP_DeleteLinkRecord(void *eventState);
extern void MOVE_POKEMON_SpawnPendingEntries(struct GameData *gameData);

/* field map link and moving models */
extern struct FieldCommLink *FIELDMAP_GetSubscreen(struct FieldMap *fieldMap);
extern struct MoveModelSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);
extern u32 ZONEDATA_IsZone96Pair(u32 zoneId);
extern u32 FIELD_SUBSCREEN_GetMode(struct FieldCommLink *link);
extern int func_021A0EE4(struct FieldCommLink *link, int a);
extern void func_020355D8(u8 value);
extern int FIELD_SUBSCREEN_IsIdle(struct FieldCommLink *link);
extern int FIELD_SUBSCREEN_RequestMode(struct FieldCommLink *link, u32 a);
extern int FIELD_SUBSCREEN_GetPanelResult(struct FieldCommLink *link);
extern void FIELD_SUBSCREEN_ClearPanelResult(struct FieldCommLink *link);
extern u32 FIELD_SUBSCREEN_GetMenuSelectedButton(struct FieldCommLink *link);
extern void FIELD_SUBSCREEN_SetMenuSelectedButton(struct FieldCommLink *link, int frameRate);
extern struct GameEvent *func_021945A4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 linkMode);
extern void FLDMMDL_SysPauseMove(struct MoveModelSys *moveModelSys);
extern u32 *FLDMMDL_SysResumeMove(struct MoveModelSys *moveModelSys);
extern void MOVE_POKEMON_InitSkillInfo(struct FieldMap *fieldMap, FieldSkillInfo *info);
extern void MOVE_POKEMON_InitSkillTarget(FieldSkillTarget *target, u16 partySlot, u16 skillIndex, u32 targetParam);
extern struct GameEvent *MOVE_POKEMON_CreateSkillEvent(int skillIndex, FieldSkillTarget *target, FieldSkillInfo *info);
extern struct GameEvent *EVENTDATA_SYSTEM_CreateFieldLinkEvent(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *EVENT_SHORTCUT_MENU_CreateProcEvent(ShortcutRequest *request, u16 id);

extern const char SCRCMD_NETWORK_sFileName[];
extern u8 d_021B9EC0[];
extern u8 ov_id_00CD[];
extern u8 ov180_id[];
extern u8 ov181_id[];
extern u8 ov205_id[];
extern u8 ov182_id[];
extern u8 d_021B800C[];
extern u8 d_021BAB24[];
extern u8 d_021B9E54[];
extern u8 d_021B9BA0[];
extern unsigned char ov020_id[];
extern unsigned char abs_id_14[];
extern u8 ov122_id[];
extern u8 ov172_id[];
extern u8 d_021D5764[];
extern u8 d_021C7240[];
extern const u32 SCRCMD_NETWORK_sRecordKindByFrameRate[];

int SCRCMD_NETWORK_WaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdWaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdGetCommValue(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdStartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdRequestCommExit(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdRestartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdUnblockComm(struct GameSystem **gameSystemRef, void *unused);
int SCRCMD_NETWORK_CmdGetAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdClearAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdLoadNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdFreeNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdSetNpcEventFromTable(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdSetNpcEventPairFromTable(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdSetNpcTripleFromTable(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_CmdApplyTableEventKeys(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_PickSixDistinctRandom(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_NETWORK_FindNpcTableRow(const NpcTableRow *table, int keyA, int keyB);
BOOL SCRCMD_NETWORK_HasSituationWarpChanged(struct GameData *gameData);
int SCRCMD_NETWORK_CommProcEventMain(struct GameEvent *event, u32 *seq, void *workArg);
struct GameEvent *SCRCMD_NETWORK_CreateCommProcEvent(struct GameSystem *gameSystem);
int SCRCMD_NETWORK_CommBattleEventMain(struct GameEvent *event, u32 *seq, void *workArg);
struct GameEvent *SCRCMD_NETWORK_CreateCommBattleEvent(struct GameSystem *gameSystem, int mode);
void SCRCMD_NETWORK_InitCommBattleOv180Param(CommBattleWork *work);
int SCRCMD_NETWORK_InitCommBattleOv181Param(CommBattleWork *work);
void SCRCMD_NETWORK_InitCommBattleStepSequence(CommBattleWork *work);
int SCRCMD_NETWORK_GetCommExitKind(void);
void SCRCMD_NETWORK_AdvanceStep(CommBattleWork *work, u32 *seq);
int SCRCMD_NETWORK_SetupMiscSave(CommBattleWork *work);
struct GameEvent *SCRCMD_NETWORK_CreateOv020Event(struct GameSystem *gameSystem, u32 initParam);
struct GameEvent *SCRCMD_NETWORK_LoadOv020Task(struct GameSystem *gameSystem);
void SCRCMD_NETWORK_LoadOv020(void);
void SCRCMD_NETWORK_UnloadOv020(void);
int SCRCMD_NETWORK_WifiProcEventMain(struct GameEvent *event, u32 *seq, void *workArg);
struct GameEvent *SCRCMD_NETWORK_CreateWifiProcEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct GameEvent *event, int createNew);
struct GameEvent *SCRCMD_NETWORK_CreateBattleRecordLinkEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);
struct GameEvent *SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id);
int SCRCMD_NETWORK_BattleRecordLinkEventMain(struct GameEvent *event, u32 *seq, void *workArg);
u32 SCRCMD_NETWORK_GetRecordKindByFrameRate(u32 frameRate);
int SCRCMD_NETWORK_RecordLinkOnUpdate(ShortcutRequest *request, RecordLinkWork *work);
int SCRCMD_NETWORK_RecordLinkOnClose(ShortcutRequest *request, RecordLinkWork *work);
int SCRCMD_NETWORK_RecordLinkOnFinish(ShortcutRequest *request, RecordLinkWork *work);

/*
 * Wait callback of the "wait for the comm state" command: state 0 keeps
 * waiting, state 1 ends the wait, state 2 ends it and stores 2 in the
 * result variable.
 */
int SCRCMD_NETWORK_WaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    struct GameComm *gameComm = ICA_ANIME_GetField24(gameSystem);
    CommWaitWork *waitWork;

    ICA_ANIME_GetField20(gameSystem);
    waitWork = *SCRIPT_WORK_GetUserWorkPtr(scriptCtl);
    switch (FIELDMAP_CheckCommExit(gameComm)) {
    case 0:
        return 0;
    case 1:
        func_020307B0(waitWork);
        return 1;
    case 2:
        *waitWork->resultVar = 2;
        func_020307B0(waitWork);
        return 1;
    default:
        return 0;
    }
}


int SCRCMD_NETWORK_CmdWaitCommState(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    CommWaitWork **slot;
    u16 *resultVar;
    CommWaitWork *waitWork;

    slot = SCRIPT_WORK_GetUserWorkPtr(SCRCMD_WORK_GetScriptWork(scriptWork));
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    waitWork = func_02030734(4, 4, 1, SCRCMD_NETWORK_sFileName, 0x63);
    *slot = waitWork;
    waitWork->resultVar = resultVar;
    *resultVar = 0;
    VM_SetWait(vm, SCRCMD_NETWORK_WaitCommState);
    return 1;
}


int SCRCMD_NETWORK_CmdGetCommValue(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);

    *resultVar = func_0202EB44();
    return 0;
}


int SCRCMD_NETWORK_CmdStartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);

    GAMESYSTEM_TryStartAutoComm(gameSystem);
    return 1;
}


int SCRCMD_NETWORK_CmdRequestCommExit(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;

    gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    switch (GAME_COMM_GetKind(gameComm)) {
    case 1:
    case 2:
    case 5:
        GAME_COMM_RequestExitNoCallback(gameComm);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    GAMESYSTEM_SetCommBlocked(gameSystem, 1);
    SCRIPT_WORK_SetCheckFlag(0xb);
    return 1;
}


int SCRCMD_NETWORK_CmdRestartAutoComm(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);

    GAMESYSTEM_SetCommBlocked(gameSystem, 0);
    GAMESYSTEM_TryStartAutoComm(gameSystem);
    SCRIPT_WORK_ResetCheckFlag(0xB);

    return 1;
}


/* Callback that takes a cell holding the game system. */
int SCRCMD_NETWORK_CmdUnblockComm(struct GameSystem **gameSystemRef, void *unused)
{
    struct GameSystem *gameSystem = *gameSystemRef;

    GAMESYSTEM_SetCommBlocked(gameSystem, 0);
    GAMESYSTEM_TryStartAutoComm(gameSystem);
    return 1;
}


int SCRCMD_NETWORK_CmdGetAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    *resultVar = func_0201214C(gameSystem);
    return 0;
}


int SCRCMD_NETWORK_CmdClearAlwaysNet(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    GAMESYSTEM_SetAlwaysNetFlag(SCRCMD_WORK_GetGameSystem(scriptWork), 0);
    return 0;
}


/* Loads archive member 0xD1 (the NpcTableRow table) into the script control. */
int SCRCMD_NETWORK_CmdLoadNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);

    SCRIPT_WORK_SetReturnFlag(scriptCtl, (void *)ARC_UTIL_LoadMember(0xd1, 0, 0, 0x8004));
    return 0;
}


int SCRCMD_NETWORK_CmdFreeNpcTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    void *table = SCRIPT_WORK_GetReturnFlag(scriptCtl);

    if (table != 0) {
        func_020307B0(table);
        SCRIPT_WORK_SetReturnFlag(scriptCtl, 0);
    }
    return 0;
}


/* Sets the event id of NPC record outSlot from the row found by (keyA, keyB). */
int SCRCMD_NETWORK_CmdSetNpcEventFromTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    u32 keyA = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 outSlot = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 keyB = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    const NpcTableRow *table;
    struct EventDataSystem *eventData;
    u16 eventKey;

    eventData = GAME_DATA_GetField158(SCRCMD_WORK_GetGameData(scriptWork));
    table = SCRIPT_WORK_GetReturnFlag(scriptCtl);
    eventKey = table[(u16)SCRCMD_NETWORK_FindNpcTableRow(table, keyA, keyB)].eventKey;
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, outSlot, func_0215A480(eventKey));
    return 0;
}


/* Same lookup, sets the event ids of two NPC records. */
int SCRCMD_NETWORK_CmdSetNpcEventPairFromTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    u32 keyA = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 outSlotA = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 outSlotB = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 keyB = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    const NpcTableRow *table;
    struct EventDataSystem *eventData;
    u16 index;

    eventData = GAME_DATA_GetField158(SCRCMD_WORK_GetGameData(scriptWork));
    table = SCRIPT_WORK_GetReturnFlag(scriptCtl);
    index = SCRCMD_NETWORK_FindNpcTableRow(table, keyA, keyB);
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, outSlotA, func_0215A480(table[index].eventKey));
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, outSlotB, func_0215A490(table[index].eventKey));
    return 0;
}


/* Sets object code and event id of three NPC records from three table rows. */
int SCRCMD_NETWORK_CmdSetNpcTripleFromTable(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    u32 slot0 = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 slot1 = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 slot2 = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 row0 = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 row1 = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    u32 row2 = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    struct EventDataSystem *eventData = GAME_DATA_GetField158(SCRCMD_WORK_GetGameData(scriptWork));
    NpcTableRow *table = SCRIPT_WORK_GetReturnFlag(scriptCtl);

    EVENTDATA_SYSTEM_SetNpcObjCode(eventData, slot0, table[row0].objCode);
    EVENTDATA_SYSTEM_SetNpcObjCode(eventData, slot1, table[row1].objCode);
    EVENTDATA_SYSTEM_SetNpcObjCode(eventData, slot2, table[row2].objCode);
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, slot0, func_0215A480(table[row0].eventKey));
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, slot1, func_0215A480(table[row1].eventKey));
    EVENTDATA_SYSTEM_SetNpcEventId(eventData, slot2, func_0215A480(table[row2].eventKey));
    return 0;
}


int SCRCMD_NETWORK_CmdApplyTableEventKeys(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl;
    struct EventWork *eventWork;
    int i;
    NpcTableRow *table;

    scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    eventWork = GAME_DATA_GetEventWork(ICA_ANIME_GetField1C(SCRIPT_WORK_GetGameSystem(scriptCtl)));
    table = SCRIPT_WORK_GetReturnFlag(scriptCtl);
    for (i = 0; i < NPC_TABLE_ROW_COUNT; i++)
        func_0215A500(eventWork, table[i].eventKey);
    return 0;
}


/*
 * Draws six distinct values from 0..0x33 (random pick among the ones not
 * yet taken) and writes each plus 0x37 to six script-variable slots.
 *
 * Keys: the work locals live in a nested block opened after the six
 * SCRIPT_WORK_ReadWorkPointer calls, so `u16 picked[6] = {0}` is emitted there (at function
 * scope the initializer lands above the calls) and its stores go through
 * the same `add r4, sp, #0x18` the search loops index. `u16 poolSize = 0x34`
 * declared before picked schedules `movs r7, #0x34` ahead of the zero stores.
 * EXACT* only for the 2-byte pad after the function (218 of 220).
 */
int SCRCMD_NETWORK_PickSixDistinctRandom(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *outVar0, *outVar1, *outVar2, *outVar3, *outVar4, *outVar5;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    outVar0 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar1 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar2 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar3 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar4 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    outVar5 = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    {
        u16 poolSize = 0x34;
        u16 picked[6] = {0};
        int drawIndex, candidate, prior;
        s16 skipCount;

        for (drawIndex = 0; drawIndex < 6; drawIndex++) {
            skipCount = func_020056EC(poolSize);
            for (candidate = 0; candidate < 0x34; candidate++) {
                for (prior = 0; prior < drawIndex; prior++) {
                    if (picked[prior] == candidate)
                        break;
                }
                if (prior == drawIndex) {
                    if (--skipCount < 0) {
                        picked[drawIndex] = candidate;
                        break;
                    }
                }
            }
            poolSize--;
        }
        *outVar0 = picked[0] + 0x37;
        *outVar1 = picked[1] + 0x37;
        *outVar2 = picked[2] + 0x37;
        *outVar3 = picked[3] + 0x37;
        *outVar4 = picked[4] + 0x37;
        *outVar5 = picked[5] + 0x37;
    }
    return 0;
}


/* Index of the first row matching both keys, 0 when none does. */
int SCRCMD_NETWORK_FindNpcTableRow(const NpcTableRow *table, int keyA, int keyB)
{
    int i;

    for (i = 0; i < NPC_TABLE_ROW_COUNT; i++) {
        const NpcTableRow *row = &table[i];

        if (keyA == row->keyA && keyB == row->keyB)
            return i;
    }
    return 0;
}


/* TRUE when the situation warp id differs from the current one. */
BOOL SCRCMD_NETWORK_HasSituationWarpChanged(struct GameData *gameData)
{
    int currentWarpId = func_02159F80();

    if (currentWarpId == GAME_DATA_GetSituationWarpId(gameData))
        return FALSE;
    else
        return TRUE;
}


/*
 * former blocker: ABS32 0x000000CD (ov_id_00CD) has no witness outside the function (literal pool word only)
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int SCRCMD_NETWORK_CommProcEventMain(struct GameEvent *event, u32 *seq, void *workArg)
{
    CommProcEventWork *work = workArg;

    switch (*seq) {
    case 0:
        BRIGHTNESS_Set(-16, 0x37, 1);
        BRIGHTNESS_Set(-16, 0x3f, 2);
        GAME_EVENT_CallProc(event, (u32)ov_id_00CD, d_021B9EC0, work);
        (*seq)++;
        break;
    case 1:
        BRIGHTNESS_Set(0, 0x3f, 3);
        GAME_EVENT_CallEvent(event, SCRCMD_NETWORK_LoadOv020Task(work->gameSystem));
        (*seq)++;
        break;
    case 2:
        if (work->warpChanged == 0) {
            SCRIPT_SYS_CallScriptEvent(event, 3, 0, 0, 0x15);
        } else {
            SCRIPT_SYS_CallScriptEvent(event, 0x7d1, 0, 0, 0x15);
        }
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}


struct GameEvent *SCRCMD_NETWORK_CreateCommProcEvent(struct GameSystem *gameSystem)
{
    struct GameData *gameData = ICA_ANIME_GetField1C(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, SCRCMD_NETWORK_CommProcEventMain, sizeof(CommProcEventWork));
    CommProcEventWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->warpChanged = SCRCMD_NETWORK_HasSituationWarpChanged(gameData);
    work->myStatus = func_02012944(gameData);
    SYMBOL_MAP_DeleteLinkRecord(GAME_DATA_GetEventState(gameData));
    GAMESYSTEM_SetCommBlocked(gameSystem, 0);
    return event;
}


/*
 * Step machine of the comm battle event: the step comes from work->seq[*seq]
 * through SCRCMD_NETWORK_AdvanceStep, loading ov180/ov181 as procs and ov205/ov182 as
 * tasks. Byte-correct first draft.
 * Former blocker (MATCH): ov205_id and ov182_id reach r1 of GAME_EVENT_CallProc, which
 * is not in match.py's OVERLAY_ID_CONSUMERS; d_021B9BA0 then fails its
 * ov182 hint for want of that overlay_id site. Same blocker as
 * SCRCMD_NETWORK_WifiProcEventMain.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int SCRCMD_NETWORK_CommBattleEventMain(struct GameEvent *event, u32 *seq, void *workArg)
{
    CommBattleWork *work = workArg;
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameComm *gameComm;
    struct FieldMap *fieldMap;

    GAME_DATA_GetSaveControl(work->gameData);
    fieldMap = ICA_ANIME_GetField20(work->gameSystem);
    gameComm = ICA_ANIME_GetField24(work->gameSystem);
    switch (work->step) {
    case COMM_BATTLE_STEP_PREPARE:
        if (work->mode == 1)
            SCRCMD_NETWORK_SetupMiscSave(work);
        GFL_USE_FadeOutBgm(30);
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_FIELD_PREPARE_EVENT:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_REQUEST_COMM_IDLE:
        if (GAME_COMM_GetKind(gameComm))
            GAME_COMM_RequestExitNoCallback(gameComm);
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_WAIT_COMM_IDLE:
        if (GAME_COMM_GetKind(gameComm) == 0)
            SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_CLOSE_FIELD:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(gameSystem, fieldMap));
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_CALL_OV180:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov180_id, d_021B800C, &work->ov180Param);
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_WAIT_OV180:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_CALL_OV181:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov181_id, d_021BAB24, &work->ov181Param);
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_WAIT_OV181:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_COMM_EXIT_EVENT:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateCommExitEvent(gameSystem, event, SCRCMD_NETWORK_GetCommExitKind(), 0, 0));
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_SET_SCRIPT_STATE:
        SCRIPT_SYS_RunRecoverScript(gameSystem, 4);
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_CALL_OV205:
        GAME_EVENT_CallProc(event, (u32)ov205_id, d_021B9E54, &work->ov205Param);
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_WAIT_FRAMES:
        if (work->frameCount > 60) {
            work->frameCount = 0;
            SCRCMD_NETWORK_AdvanceStep(work, seq);
        }
        work->frameCount++;
        break;
    case COMM_BATTLE_STEP_CALL_OV182:
        GAME_EVENT_CallProc(event, (u32)ov182_id, d_021B9BA0, &work->ov182Param);
        GAMESYSTEM_SetAlwaysNetFlag(gameSystem, 0);
        SCRCMD_NETWORK_AdvanceStep(work, seq);
        break;
    case COMM_BATTLE_STEP_DONE:
        return 1;
    case COMM_BATTLE_STEP_ABORT:
        return 0;
    }
    return 0;
}


struct GameEvent *SCRCMD_NETWORK_CreateCommBattleEvent(struct GameSystem *gameSystem, int mode)
{
    struct GameData *gameData = ICA_ANIME_GetField1C(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, SCRCMD_NETWORK_CommBattleEventMain, 0x7C);
    CommBattleWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->gameData = gameData;
    work->mode = mode;
    work->myStatus = func_02012944(gameData);
    work->frameCount = 0;
    work->ov205Param.gameSystem = gameSystem;
    work->ov205Param.mode = mode;
    MOVE_POKEMON_SpawnPendingEntries(gameData);
    SCRCMD_NETWORK_InitCommBattleOv180Param(work);
    SCRCMD_NETWORK_InitCommBattleOv181Param(work);
    SCRCMD_NETWORK_InitCommBattleStepSequence(work);
    return event;
}


/* Caches the party, status and play time of the game data for the ov180 proc. */
void SCRCMD_NETWORK_InitCommBattleOv180Param(CommBattleWork *work)
{
    work->ov180Param.myParty = GAME_DATA_GetMyParty(work->gameData);
    work->ov180Param.myStatus = func_02012944(work->gameData);
    work->ov180Param.playTime = GAME_DATA_GetPlayTime(work->gameData);
}


/* Fills the ov181 and ov182 parameters from the config applied flag. */
int SCRCMD_NETWORK_InitCommBattleOv181Param(CommBattleWork *work)
{
    struct SaveControl *saveControl;
    struct Config *config;
    int configApplied;

    if (work->mode == 1)
        work->ov181Param.isMode1 = 1;
    else
        work->ov181Param.isMode1 = 0;
    saveControl = GAME_DATA_GetSaveControl(work->gameData);
    config = func_0200873C(saveControl);
    configApplied = CONFIG_GetAppliedFlag(config);
    work->ov181Param.configApplied = configApplied;
    work->ov182Param = configApplied;
    return configApplied;
}


/*
 * Picks the step sequence from the mode and loads its first step.
 * Addresses are Black-image addresses.
 */
void SCRCMD_NETWORK_InitCommBattleStepSequence(CommBattleWork *work)
{
    if (work->mode == 0 || work->mode != 1) {
        work->seq[0] = COMM_BATTLE_STEP_PREPARE;
        work->seq[1] = COMM_BATTLE_STEP_REQUEST_COMM_IDLE;
        work->seq[2] = COMM_BATTLE_STEP_WAIT_COMM_IDLE;
        work->seq[3] = COMM_BATTLE_STEP_CLOSE_FIELD;
        work->seq[4] = COMM_BATTLE_STEP_CALL_OV181;
        work->seq[5] = COMM_BATTLE_STEP_WAIT_OV181;
        work->seq[6] = COMM_BATTLE_STEP_WAIT_FRAMES;
        work->seq[7] = COMM_BATTLE_STEP_COMM_EXIT_EVENT;
        work->seq[8] = COMM_BATTLE_STEP_WAIT_FRAMES;
        work->seq[9] = COMM_BATTLE_STEP_SET_SCRIPT_STATE;
        work->seq[10] = COMM_BATTLE_STEP_CALL_OV205;
        work->seq[11] = COMM_BATTLE_STEP_WAIT_FRAMES;
        work->seq[12] = COMM_BATTLE_STEP_CALL_OV182;
        work->seq[13] = COMM_BATTLE_STEP_DONE;
    } else {
        work->seq[0] = COMM_BATTLE_STEP_PREPARE;
        work->seq[1] = COMM_BATTLE_STEP_REQUEST_COMM_IDLE;
        work->seq[2] = COMM_BATTLE_STEP_FIELD_PREPARE_EVENT;
        work->seq[3] = COMM_BATTLE_STEP_WAIT_COMM_IDLE;
        work->seq[4] = COMM_BATTLE_STEP_CLOSE_FIELD;
        work->seq[5] = COMM_BATTLE_STEP_CALL_OV180;
        work->seq[6] = COMM_BATTLE_STEP_WAIT_OV180;
        work->seq[7] = COMM_BATTLE_STEP_SET_SCRIPT_STATE;
        work->seq[8] = COMM_BATTLE_STEP_CALL_OV205;
        work->seq[9] = COMM_BATTLE_STEP_CALL_OV181;
        work->seq[10] = COMM_BATTLE_STEP_WAIT_OV181;
        work->seq[11] = COMM_BATTLE_STEP_CALL_OV182;
        work->seq[12] = COMM_BATTLE_STEP_DONE;
    }
    work->step = work->seq[0];
}


/*
 * Kind passed to the comm exit event: 7 for power 0x15, else 8. The 0x14
 * test is redundant but is in the bytes.
 */
int SCRCMD_NETWORK_GetCommExitKind(void)
{
    int powerId = GPOWER_GetSpecialPowerId();

    if (powerId == 0x14 || powerId != 0x15)
        return 8;
    return 7;
}


/*
 * Advance the step counter and load the next step from the sequence.
 */
void SCRCMD_NETWORK_AdvanceStep(CommBattleWork *work, u32 *seq)
{
    (*seq)++;
    work->step = work->seq[*seq];
}


int SCRCMD_NETWORK_SetupMiscSave(CommBattleWork *work)
{
    struct MiscSave *miscSave = GAME_DATA_GetMiscSave(work->gameData);

    return BEACON_SetGatePoints(miscSave, 0x5a0);
}


struct GameEvent *SCRCMD_NETWORK_CreateOv020Event(struct GameSystem *gameSystem, u32 initParam)
{
    func_02034AC4((u32)ov020_id);
    return EVENT_MAPCHANGE_CreateByMode(gameSystem, initParam);
}


/*
 * Loads overlay 20 (GF_OVERLAY_Load with the pooled id abs_id_14) and returns
 * the task that ov020 EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent creates for the game system.  The bytes
 * are the same as the TWL DSPi_WaitForPipe (dsp_pipe.o), which named it before.
 */
struct GameEvent *SCRCMD_NETWORK_LoadOv020Task(struct GameSystem *gameSystem)
{
    GF_OVERLAY_Load((int)abs_id_14);
    return EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(gameSystem);
}


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM GF_OVERLAY_Load with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with SCRCMD_NETWORK_UnloadOv020 (same id, into GF_OVERLAY_Unload).
 */
void SCRCMD_NETWORK_LoadOv020(void)
{
    GF_OVERLAY_Load((int)abs_id_14);
}


/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           abs_id_14 (20) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * Thumb tail call into the ARM GF_OVERLAY_Unload with the id 0x14, which the
 * original loads from its own pool rather than as `movs r0, #0x14`: the
 * pooled small constant is an absolute linker symbol
 * (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md).
 * Unlabelled in the listing (no lr-saving prologue, callers only in arm9);
 * the pair with SCRCMD_NETWORK_LoadOv020 (same id, into GF_OVERLAY_Load).
 */
void SCRCMD_NETWORK_UnloadOv020(void)
{
    GF_OVERLAY_Unload((int)abs_id_14);
}


/*
 * Event main of the Wi-Fi screens: 11 states that push the child
 * tasks, load ov122 and ov172, and pick the closing screen from
 * work->exitKind.
 * Byte-correct (first draft plus one lever: in state 9 the `exitKind == 2`
 * test and the call share an else block ending in the one `*seq = 10`
 * store, so that store is the copy the other arms cross-jump to).
 * Former blocker (MATCH): the pooled 0xAC is ov172_id passed in r1 to
 * GAME_EVENT_CallProc, which is not in match.py's OVERLAY_ID_CONSUMERS
 * (GAME_EVENT_CallProc stores r1 in a task descriptor, src/matched/GAME_EVENT_CallProc.c),
 * so the ABS32 at +0x190 has no witness.
 *
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */
int SCRCMD_NETWORK_WifiProcEventMain(struct GameEvent *event, u32 *seq, void *workArg)
{
    WifiProcWork *work = workArg;
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameComm *gameComm = ICA_ANIME_GetField24(gameSystem);
    struct GameData *gameData = ICA_ANIME_GetField1C(gameSystem);
    struct FieldMap *fieldMap = ICA_ANIME_GetField20(gameSystem);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        *seq = 2;
        break;
    case 2:
        (*seq)++;
    case 3:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov122_id, d_021D5764, work);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        switch (work->entryKind) {
        case 0:
            if (INTRUDE_COMM_GetWorkIfRunning(gameComm) && work->exitKind == 2)
                GAME_DATA_SetSubscreenType(gameData, 3);
            *seq = 6;
            break;
        case 1:
            work->savedBgmNo = GFL_USE_GetBgmNo();
            GAME_EVENT_CallProc(event, (u32)ov172_id, d_021C7240, work->ov172Param);
            *seq = 5;
            break;
        default:
            *seq = 6;
            break;
        }
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus(gameSystem) != 0)
            break;
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
        GFL_USE_FadeInBgmFull(60);
        *seq = 6;
        break;
    case 6:
        work->exitRequest = 0;
        (*seq)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 9:
        if (work->entryKind == 0) {
            if (work->exitKind == 0) {
                if (GAME_COMM_IsTransition(gameComm))
                    break;
                if (GAME_COMM_GetKind(gameComm)) {
                    GAME_COMM_RequestExitNoCallback(gameComm);
                    break;
                }
                GAME_EVENT_CallEvent(event, INTRUDE_SUBDISP_CreateTownWarpEvent(gameSystem, fieldMap, 0x117, 0));
                *seq = 10;
            } else if (work->exitKind == 3) {
                GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateReturnPalaceEvent(gameSystem));
                *seq = 10;
            } else {
                if (work->exitKind != 2)
                    GAME_EVENT_CallEvent(event, INTRUDE_SUBDISP_CreateGuideScriptEvent(gameSystem));
                *seq = 10;
            }
        } else {
            *seq = 10;
        }
        break;
    case 10:
        return 1;
    }
    return 0;
}


/*
 * Creates the Wi-Fi screens event, or turns the given event into it when
 * createNew is 0.
 */
struct GameEvent *SCRCMD_NETWORK_CreateWifiProcEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct GameEvent *event, int createNew)
{
    WifiProcWork *work;
    struct GameData *gameData;

    FIELDMAP_GetSubscreen(fieldMap);
    if (createNew != 0) {
        event = func_020122C0(gameSystem, 0, SCRCMD_NETWORK_WifiProcEventMain, 0x34);
    } else {
        GAME_EVENT_Change(event, SCRCMD_NETWORK_WifiProcEventMain, 0x34);
    }
    work = func_020124E8(event);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    work->gameData = gameData;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameSystem = gameSystem;
    return event;
}


struct GameEvent *SCRCMD_NETWORK_CreateBattleRecordLinkEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id)
{
    struct FieldCommLink *link;
    int workSize = 0x5c;
    struct GameEvent *event;
    RecordLinkWork *work;
    int linkMode;

    link = FIELDMAP_GetSubscreen(fieldMap);
    event = func_020122C0(gameSystem, 0, SCRCMD_NETWORK_BattleRecordLinkEventMain, workSize);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, workSize);
    work->gameSystem = gameSystem;
    work->event = event;
    work->fieldMap = fieldMap;
    work->id = id;
    work->state = 0;
    work->request.gameSystem = gameSystem;
    work->request.fieldMap = fieldMap;
    work->request.event = event;
    work->request.onUpdate = SCRCMD_NETWORK_RecordLinkOnUpdate;
    work->request.onClose = SCRCMD_NETWORK_RecordLinkOnClose;
    work->request.onFinish = SCRCMD_NETWORK_RecordLinkOnFinish;
    work->request.work = work;
    work->request.detail = workSize - 0x5d;
    linkMode = FIELD_SUBSCREEN_GetMode(link);
    switch (linkMode) {
    case 3:
        linkMode = 3;
        break;
    case 4:
        linkMode = 4;
        break;
    default:
        linkMode = func_021A0EE4(FIELDMAP_GetSubscreen(work->fieldMap), 0);
        break;
    }
    work->linkMode = linkMode;
    func_020355D8(1);
    return event;
}


struct GameEvent *SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 id)
{
    struct GameEvent *event;
    RecordLinkWork *work;

    event = SCRCMD_NETWORK_CreateBattleRecordLinkEvent(gameSystem, fieldMap, id);
    work = func_020124E8(event);
    work->linkMode = ZONEDATA_IsZone96Pair(FIELDMAP_GetZoneId(fieldMap)) == 1 ? 5 : 2;
    return event;
}


/*
 * Nine-state link setup task of the ov010 field (the extent ends at
 * 0x0215FEC6; 0x0215FEC8 is its unlabelled table-lookup leaf). State 3
 * keeps the call arm inside the negated test so the `return 1` block
 * follows it.
 */
int SCRCMD_NETWORK_BattleRecordLinkEventMain(struct GameEvent *event, u32 *seq, void *workArg)
{
    RecordLinkWork *work = workArg;
    FieldSkillTarget target;
    FieldSkillInfo info;
    struct MoveModelSys *moveModelSys;
    struct GameData *gameData;
    struct GameEvent *skillEvent;
    u32 frameRate;
    int linkState;

    switch (work->state) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(FIELDMAP_GetSubscreen(work->fieldMap)) == 1) {
            moveModelSys = FIELDMAP_GetMmdlSys(work->fieldMap);
            gameData = ICA_ANIME_GetField1C(GAME_EVENT_GetGameSystem(event));
            FLDMMDL_SysPauseMove(moveModelSys);
            GAME_DATA_SetFrameRate(gameData, 1);
            FIELD_SUBSCREEN_RequestMode(FIELDMAP_GetSubscreen(work->fieldMap), 1);
            work->state = 1;
        }
        break;
    case 1:
        linkState = FIELD_SUBSCREEN_GetPanelResult(FIELDMAP_GetSubscreen(work->fieldMap));
        if (linkState == 3) {
            work->state = 2;
            FIELD_SUBSCREEN_ClearPanelResult(FIELDMAP_GetSubscreen(work->fieldMap));
        } else if (linkState == 4) {
            work->state = 3;
            FIELD_SUBSCREEN_ClearPanelResult(FIELDMAP_GetSubscreen(work->fieldMap));
        }
        break;
    case 2:
        gameData = ICA_ANIME_GetField1C(GAME_EVENT_GetGameSystem(event));
        frameRate = FIELD_SUBSCREEN_GetMenuSelectedButton(FIELDMAP_GetSubscreen(work->fieldMap));
        GAME_DATA_SetFrameRate(gameData, frameRate);
        work->frameRate = FIELD_SUBSCREEN_GetMenuSelectedButton(FIELDMAP_GetSubscreen(work->fieldMap));
        work->request.kind = SCRCMD_NETWORK_GetRecordKindByFrameRate(frameRate);
        work->state = 5;
        break;
    case 3:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        if (work->request.result != 1 && work->request.result != 4) {
            GAME_EVENT_ChangeEvent(event, func_021945A4(GAME_EVENT_GetGameSystem(event), work->fieldMap, work->linkMode));
            return 0;
        }
        return 1;
    case 4:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        MOVE_POKEMON_InitSkillInfo(ICA_ANIME_GetField20(work->gameSystem), &info);
        MOVE_POKEMON_InitSkillTarget(&target, work->request.partySlot, work->request.next, work->request.targetParam);
        skillEvent = MOVE_POKEMON_CreateSkillEvent(work->request.next, &target, &info);
        if (skillEvent == 0)
            return 1;
        GAME_EVENT_ChangeEvent(work->event, skillEvent);
        break;
    case 5:
        GAME_EVENT_CallEvent(event, EVENT_SHORTCUT_MENU_CreateProcEvent(&work->request, work->id));
        work->state = 6;
        break;
    case 6:
        if (work->request.result == 0)
            work->state = 1;
        else if (work->request.result == 1)
            work->state = 3;
        else if (work->request.result == 3)
            work->state = 7;
        else if (work->request.result == 2)
            work->state = 4;
        else if (work->request.result == 4)
            work->state = 3;
        break;
    case 7:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        GAME_EVENT_CallEvent(event, EVENTDATA_SYSTEM_CreateFieldLinkEvent(work->request.next, work->gameSystem, work->fieldMap));
        work->state = 8;
        break;
    case 8:
        return 1;
    }
    return 0;
}


/*
 * Unlabelled leaf after SCRCMD_NETWORK_BattleRecordLinkEventMain (bl from 0x0215FDD0): the request
 * kind for a frame rate.
 */
u32 SCRCMD_NETWORK_GetRecordKindByFrameRate(u32 frameRate)
{
    return SCRCMD_NETWORK_sRecordKindByFrameRate[frameRate];
}


/*
 * Conditional arm9 pair call on the record's second field; the first
 * call's result is the first operand either way.
 */
int SCRCMD_NETWORK_RecordLinkOnUpdate(ShortcutRequest *request, RecordLinkWork *work)
{
    struct FieldCommLink *link = FIELDMAP_GetSubscreen(work->fieldMap);

    if (request->result == 0)
        FIELD_SUBSCREEN_SetMenuSelectedButton(link, work->frameRate);

    return 1;
}


/*
 * Unlabelled leaf: returns 1.
 */
int SCRCMD_NETWORK_RecordLinkOnClose(ShortcutRequest *request, RecordLinkWork *work)
{
    return 1;
}


int SCRCMD_NETWORK_RecordLinkOnFinish(ShortcutRequest *request, RecordLinkWork *work)
{
    struct GameData *gameData = ICA_ANIME_GetField1C(work->gameSystem);

    switch (request->result) {
    case 4:
        GAME_DATA_SetSubscreenType(gameData, 6);
        break;
    case 0:
        GAME_DATA_SetSubscreenType(gameData, 1);
        break;
    case 1:
    case 2:
    case 3:
        GAME_DATA_SetSubscreenType(gameData, (u8)work->linkMode);
        break;
    default:
        break;
    }
    return 1;
}
