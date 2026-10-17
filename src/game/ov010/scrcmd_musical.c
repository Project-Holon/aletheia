/*
 * file:     scrcmd_musical.c
 * unit:     yes
 * function: SCRCMD_MUSICAL_StartMusical, SCRCMD_MUSICAL_ShowPartyMonMusical, SCRCMD_MUSICAL_GetValue, SCRCMD_MUSICAL_GetProgramInfo, SCRCMD_MUSICAL_AddOwnedProp, SCRCMD_MUSICAL_BufferString, SCRCMD_MUSICAL_ResetProgramRank, SCRCMD_MUSICAL_SelectPartyMon, SCRCMD_MUSICAL_LinkControl, SCRCMD_MUSICAL_CreateLinkWork, SCRCMD_MUSICAL_DeleteLinkWork, SCRCMD_MUSICAL_BeginCommSession, SCRCMD_MUSICAL_CloseCommSession, SCRCMD_MUSICAL_TaskStartMusical, SCRCMD_MUSICAL_TaskShowMusicalProc, SCRCMD_MUSICAL_FreeProcArgs, SCRCMD_MUSICAL_LinkProcCallback, SCRCMD_MUSICAL_WaitEntryMenuParent, SCRCMD_MUSICAL_WaitEntryMenuChild, SCRCMD_MUSICAL_WaitSetMemberCount, SCRCMD_MUSICAL_WaitSessionReady, SCRCMD_MUSICAL_WaitCommAttach, SCRCMD_MUSICAL_WaitCommIdle, SCRCMD_MUSICAL_WaitSessionFinish, SCRCMD_MUSICAL_WifiListCommand, FIELD_ENCOUNT_ST_LoadEncountData, FIELD_ENCOUNT_ST_Create, FIELD_ENCOUNT_ST_Delete, FIELD_ENCOUNT_ST_GetEffectEncount, FIELD_ENCOUNT_ST_ResetGimmickState, MOVE_POKEMON_MoveEntry, MOVE_POKEMON_MoveActiveEntries, MOVE_POKEMON_MoveActiveEntriesChecked, MOVE_POKEMON_GetEntryZoneId, MOVE_POKEMON_HasActiveEntry, MOVE_POKEMON_SetCommonArea, MOVE_POKEMON_SpawnEntry, MOVE_POKEMON_SpawnPendingEntries, MOVE_POKEMON_HandleBattleResult, MOVE_POKEMON_FindEntryByZone, MOVE_POKEMON_IsAnyEntryActive, MOVE_POKEMON_GetEntryIndexBySpecies, MOVE_POKEMON_MoveToNeighbor, MOVE_POKEMON_SetEntryLocation, MOVE_POKEMON_FindEntryBySpecies, MOVE_POKEMON_InitSkillInfo, MOVE_POKEMON_IsSkillBlocked, MOVE_POKEMON_InitSkillTarget, MOVE_POKEMON_CreateSkillEvent, MOVE_POKEMON_CheckCut, MOVE_POKEMON_CreateCutEvent, MOVE_POKEMON_CutEventMain, MOVE_POKEMON_CheckFly, MOVE_POKEMON_CreateFlyEvent, MOVE_POKEMON_FlyEventMain, MOVE_POKEMON_CheckSurf, MOVE_POKEMON_CreateSurfEvent, MOVE_POKEMON_SurfEventMain, MOVE_POKEMON_CheckStrength, MOVE_POKEMON_CreateStrengthEvent, MOVE_POKEMON_StrengthEventMain, MOVE_POKEMON_IsSkill8Unusable
 * address:  0x0215D34C
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
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAME_DATA_GetExternalWork  0x02012F80  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   MUSICAL_EVENT_Create  0x02155A98  thumb  ov010
 *   SCRIPT_SYS_SetNextEventFromWork  0x0215898C  thumb  ov010
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   VM_End  0x02011290  thumb
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MUSICAL_SAVE_NoOp  0x0200A640  thumb
 *   FIELD_STATUS_CreateSubProcCallbackEvent  0x02014808  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   ov112_id       0x00000070  data
 *   d_02172914     0x02172914  data
 *   d_021F8360     0x021F8360  data
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MUSICAL_MCSS_CreateMon  0x021F675C  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   MUSICAL_EVENT_GetLocalSlot  0x021568E0  thumb  ov010
 *   MUSICAL_EVENT_GetMaxScore  0x02156954  thumb  ov010
 *   MUSICAL_EVENT_GetMinScore  0x02156978  thumb  ov010
 *   MUSICAL_EVENT_GetScoreCapped  0x02156934  thumb  ov010
 *   MUSICAL_EVENT_GetPlayerOfSlot  0x021568E8  thumb  ov010
 *   MUSICAL_EVENT_GetProgramBestCategory  0x02156908  thumb  ov010
 *   MUSICAL_EVENT_GetSlotOfRank  0x0215699C  thumb  ov010
 *   MUSICAL_EVENT_GetBestAppealCategory  0x021569A4  thumb  ov010
 *   MUSICAL_EVENT_GetPortraitClass  0x021569EC  thumb  ov010
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   MUSICAL_SAVE_GetOutfits  0x0200A628  thumb
 *   MUSICAL_SAVE_IsPropOwned  0x0200A644  thumb
 *   MUSICAL_SAVE_GetShowCount  0x0200A75C  thumb
 *   MUSICAL_SAVE_GetTopRankCount  0x0200A780  thumb
 *   MUSICAL_SAVE_GetEquippedProp  0x0200A7A0  thumb
 *   MUSICAL_SAVE_GetSelectedProgram  0x0200A7B8  thumb
 *   MUSICAL_SAVE_GetScriptSetting  0x0200A7C8  thumb
 *   MUSICAL_SAVE_SetScriptSetting  0x0200A7D4  thumb
 *   MUSICAL_SAVE_GetHasDistData  0x0200A7E0  thumb
 *   MUSICAL_MCSS_GetMonValue  0x021F6744  thumb  ov112
 *   MUSICAL_SAVE_GetProgram  0x0200A750  thumb
 *   MUSICAL_SAVE_AddProp   0x0200A6BC  thumb
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   MUSICAL_EVENT_AllocTitleString  0x02156914  thumb  ov010
 *   MUSICAL_EVENT_SetPlayerNameWord  0x02156A3C  thumb  ov010
 *   MUSICAL_EVENT_SetPokemonNameWord  0x02156AD4  thumb  ov010
 *   MUSICAL_SAVE_GetStageData  0x0200A7F8  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   EVENT_POKE_STATUS_CreatePokeSelectStatusEvent 0x0215A168 thumb ov010
 *   MUSICAL_EVENT_CheckNetError  0x02156BAC  thumb  ov010
 *   MUSICAL_EVENT_IsAborted  0x02156BCC  thumb  ov010
 *   ICA_ANIME_SetField30  0x02012124  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   VM_SetWait  0x020113D0  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   COMM_ENTRY_MENU_Create  0x021CD48C  thumb  ov021
 *   MUS_COMM_FUNC_SetTimingSync  0x021FCDEC  thumb  ov132
 *   STA_SLOT_GetRecordTable  0x021FDA6C  thumb  ov132
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   ov100_id       0x00000064  data
 *   GAME_DATA_SetExternalWork  0x02012F74  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   ov132_id       0x00000084  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   MUS_COMM_FUNC_Create  0x021FC644  thumb  ov132
 *   MUS_COMM_FUNC_Delete  0x021FC684  thumb
 *   GAME_EVENT_GetGameSystem 0x020124E4 thumb
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   GAME_EVENT_CallEvent 0x02012374 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   MUSICAL_DRESSUP_SYS_ProcTable     0x02172724  data
 *   MUS_COMM_FUNC_InitCommandTable  0x021FC81C  thumb
 *   COMM_ENTRY_MENU_Main  0x021CD688  thumb
 *   MUS_COMM_FUNC_SetHostFlag  0x021FC804  thumb
 *   COMM_ENTRY_MENU_Delete  0x021CD5A4  thumb
 *   MUS_COMM_FUNC_CheckTimingSync  0x021FCE00  thumb
 *   STA_NET_GetIndexedWord5E  0x021FD844  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   STA_NET_GetIndexedWord57  0x021FD910  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_SYNC_GetBlock  0x02009448  thumb
 *   BLOCK20_SAVEDATA_CountEntries  0x02009370  thumb
 *   PDW_POSTMAN_CountUnreceivable  0x021B76F8  thumb  ov021
 *   PDW_POSTMAN_CreateListEvent  0x021B7794  thumb  ov021
 *   PDW_POSTMAN_ReceiveItems  0x021B76B4  thumb  ov021
 *   PDW_POSTMAN_GetUnreceivableItem  0x021B7740  thumb  ov021
 *   WORDSET_SetSlotFromMsg118  0x0201EF5C  thumb
 *   ZONEDATA_GetEncountId  0x02013EC0  thumb
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 *   d_02172928 0x02172928 data a1
 *   FIELDMAP_GetEncount  0x02188CE8  thumb
 *   EFFECT_ENCOUNT_LoadSetting  0x021AA7DC  thumb
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   MOVE_POKEMON_SAVE_GetBlock 0x0200D418 thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   MOVE_POKEMON_SAVE_IsEntryActive 0x0200D488 thumb
 *   MOVE_POKEMON_SAVE_GetEntry  0x0200D4AC  thumb
 *   MOVE_POKEMON_SAVE_GetEntryLocation 0x0200D478 thumb
 *   d_021711C6 0x021711C6 data a2
 *   MOVE_POKEMON_SAVE_SetCommonArea  0x0200D45C  thumb
 *   MOVE_POKEMON_SAVE_SetEntryField  0x0200D50C  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   ZUKAN_SAVE_GetBlock  0x0200CA10  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   MOVE_POKEMON_SAVE_SetEntryState  0x0200D470  thumb
 *   d_0217293C     0x0217293C  data
 *   MOVE_POKEMON_SAVE_GetEntryState 0x0200D468 thumb
 *   GAME_DATA_GetField114  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   BTL_SETUP_GetParty  0x0201313C  thumb
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   MOVE_POKEMON_SAVE_InitEntry  0x0200D494  thumb
 *   MOVE_POKEMON_SAVE_SetEntryLocation  0x0200D480  thumb
 *   TIMEZONE_GetNowTimeZone 0x020113D8 thumb
 *   d_021711A8 0x021711A8 data ov010 a2
 *   MOVE_POKEMON_SAVE_GetEntryField  0x0200D4B8  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   FIELD_PLAYER_SearchFrontMmdl  0x021A3250  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   FIELD_PLAYER_GetFrontAttribute  0x021A3128  thumb  ov021
 *   FIELD_PLAYER_CheckEncountAttr  0x021A3504  thumb  ov021
 *   FIELD_PLAYER_CheckSurfEntryAttr  0x021A3524  thumb  ov021
 *   FIELD_PLAYER_GetNowGridPos  0x021A35FC  thumb  ov021
 *   FLDMMDL_GetObjCode  0x0216D598  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_IsMovedPosObjCode  0x0216E5FC  thumb  ov010
 *   FLDMMDL_CheckMovedPosAtMapPos  0x0216E5B0  thumb  ov010
 *   MOVE_POKEMON_IsInSkillArea  0x0215F118  thumb  ov010
 *   ZONEDATA_IsFlyEnabled  0x02013C40  thumb
 *   ZONEDATA_IsWeatherEnabled  0x02013C50  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_GetMapEffectMask  0x02014470  thumb
 *   FIELD_GetPlayerAreaZoneId  0x021CD440  thumb
 *   ZONEDATA_IsZoneInTableDFB8  0x02013FFC  thumb
 *   ZONEDATA_IsRawZoneF6  0x0201400C  thumb
 *   ZONEDATA_IsRawZoneF7  0x02014018  thumb
 *   ZONEDATA_IsNormalFieldZone  0x02013E04  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   d_021711EC     0x021711EC  data
 *   d_021711F4     0x021711F4  data
 *   MOVE_POKEMON_GetSkillCheckFunc  0x0215F088  thumb  ov010
 *   MOVE_POKEMON_GetSkillEventFunc  0x0215F0B8  thumb  ov010
 *   MOVE_POKEMON_IsSkillUsable  0x0215F104  thumb  ov010
 *   MOVE_POKEMON_InitSkillWork 0x0215F0E8 thumb ov010
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   SCRIPT_SYS_ChangeScriptEvent 0x021587B0 thumb ov010
 *   SCRIPT_WORK_SetParams 0x02159058 thumb ov010
 *   SWEET_SCENT_CreateEvent 0x021C6078 thumb ov021
 */

/*
 * This file holds three original source files back to back (cuts proposed in
 * the lane notes): scrcmd_musical.c (script commands for the musical link,
 * up to 0x0215E1C0), field_encount_st.c (0x0215E2B8..0x0215E34C, string
 * "field_encount_st.c" at 0x02172928) and move_pokemon.c (from 0x0215E358,
 * string "move_pokemon.c" at 0x0217293C): the two roaming legendaries and
 * the field skill (hidden move) checks and events.
 */

struct ScriptVm;
struct GameSystem;
struct GameData;
struct GameEvent;
struct GameComm;
struct FieldMap;
struct MyStatus;
struct SaveControl;
struct ScriptCtl;
struct ScriptWork;
struct MusicalEvent;
struct MusicalSave;
struct WordSet;
struct MsgData;
struct Strbuf;
struct PokeParty;
struct Pokemon;
struct ArcFile;
struct EventWork;
struct BgmInfo;
struct FieldPlayer;
struct MapObject;
struct ZoneEncounter;
struct MoveModelSys;
struct WifiList;
struct MovePokemonSave;
struct MovePokemonEntry;
struct FieldSkillInfo;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef short s16;

typedef signed int s32;

typedef unsigned long long u64;

typedef s32 fx32;

typedef enum { FALSE, TRUE } BOOL;

/* Script VM (see ica_anime.c): command handlers get the VM and the user work. */
#include "../arm9/script_vm_types.h"

/* Event task callback: (task, state, work). */
typedef int (*EventTaskFn)(struct GameEvent *task, u32 *state, void *work);

typedef void (*SubProcCallback)(void *callbackArg);

/* Musical save block 0x2A (0x2A4 bytes), layout from mystery_data.c. */
typedef struct MusicalOutfit {
    u8 pokeSlot;                          /* 10: none */
    u8 props[5];
} MusicalOutfit;

typedef struct MusicalProgram {
    u8 state;                             /* 4: initial */
    u8 data[3];
} MusicalProgram;

/* The first word of the musical save block (what MUSICAL_SAVE_NoOp points at). */
typedef struct MusicalHeadBits {
    u32 showcaseMonsNo : 16;
    u32 shotState : 5;
    u32 showcaseFlags : 11;
} MusicalHeadBits;

/* script command 0x0215D7D4 reads a program slot as {state, rank, score}. */
typedef struct MusicalProgramView {
    u8 state;
    u8 rank;
    u16 score;
} MusicalProgramView;

/* Link work hung on the game data external-work slot (0x38 bytes). */
typedef struct MusicalLinkWork {
    struct MusicalEvent *musicalEvent;    /* 0x00 */
    void *session;                        /* 0x04: ov132 comm session */
    u32 entryMenu;                        /* 0x08: comm entry menu handle */
    struct GameData *gameData;            /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 procMode;                         /* 0x28: 9 or 10 for the ov100 proc */
    u32 procWork;                         /* 0x2C */
    u16 *resultOut;                       /* 0x30: script variable receiving the result */
    u16 memberCount;                      /* 0x34 */
} MusicalLinkWork;

/* Wait context for the ov100 proc callback. */
typedef struct MusicalLinkWait {
    struct ScriptWork *scriptWork;
    MusicalLinkWork *link;
} MusicalLinkWait;

/* Task work of StartMusical. */
typedef struct MusicalStartTask {
    struct GameEvent *musicalSeq;         /* 0x00: musical link sequence event */
    MusicalLinkWork *link;                /* 0x04 */
    u32 mode;                             /* 0x08 */
} MusicalStartTask;

/* Arguments of the ov112 proc started by StartMusical (mode 2 and up). */
typedef struct MusicalProcArgs {
    u32 startMode;                        /* 0x00 */
    u32 isOffline;                        /* 0x04 */
    MusicalHeadBits *saveBits;            /* 0x08 */
} MusicalProcArgs;

typedef struct MusicalProcBox {
    MusicalProcArgs *args;
} MusicalProcBox;

/* Arguments handed to the musical system proc of ShowPartyMonMusical. */
typedef struct MusicalSystemArgs {
    u32 startMode;                        /* 0x00 */
    u32 musicalSystem;                    /* 0x04: result of MUSICAL_SYSTEM_Create */
    u32 musicalSave;                      /* 0x08 */
} MusicalSystemArgs;

typedef struct MusicalSystemTask {
    MusicalSystemArgs *args;
} MusicalSystemTask;

/* Reads the 0xE8-byte encounter table row of a zone. */
typedef struct EncountRow {
    u8 data0[7];
    u8 flags;                             /* 0x07: 0x80 set after load */
} EncountRow;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Area {
    u16 x;
    u16 z;
    u16 w;
    u16 h;
} Area;

/* Roaming legendary table (save block 0x38): see arm9 unit_0200C7C0.c. */
typedef struct RoamLocationLinks {
    u16 count;
    u8 next[4];
} RoamLocationLinks;

/* Work of the move_pokemon battle-result hook (battle setup, fields used here). */
typedef struct BattleResultWork {
    int resultKind0;                      /* 0x00 */
    int resultKind1;                      /* 0x04 */
    u8 pad08[0x8C - 0x08];
    int battleResult;                     /* 0x8C */
} BattleResultWork;

/* Field skill (hidden move) context filled by MOVE_POKEMON_InitSkillInfo (0x14 bytes). */
typedef struct FieldSkillInfo {
    u16 zoneId;                           /* 0x00 */
    u16 usableMask;                       /* 0x02: bit per skill */
    u32 playerState;                      /* 0x04 */
    struct GameSystem *gameSys;           /* 0x08 */
    struct MapObject *playerObj;          /* 0x0C */
    struct FieldMap *fieldMap;            /* 0x10 */
} FieldSkillInfo;

/* Object returned by FIELDMAP_GetEncount (field map, offset 0x90). */
typedef struct EffectEncountObj {
    u8 pad00[0x10];
    int encountParam;                     /* 0x10 */
} EffectEncountObj;

/* Field gimmick work (GAME_DATA_GetFieldGimmick). */
typedef struct FieldGimmickWork {
    u8 pad00[0x0C];
    u32 state;                            /* 0x0C */
} FieldGimmickWork;

typedef struct SkillTarget {
    u16 id;                               /* 0x00 */
    u16 variant;                          /* 0x02 */
    u32 targetObj;                        /* 0x04 */
} SkillTarget;

typedef struct SkillEventWork {
    u32 magic;                            /* 0x19740205 */
    struct MapObject *playerObj;          /* 0x04 */
    struct GameSystem *gameSys;           /* 0x08 */
    SkillTarget target;                   /* 0x0C */
} SkillEventWork;

/* script work (ov010) */
extern struct ScriptCtl *SCRCMD_WORK_GetScriptWork(struct ScriptWork *scriptWork);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScriptWork *scriptWork);
extern struct GameData *SCRCMD_WORK_GetGameData(struct ScriptWork *scriptWork);
extern u16 SCRCMD_WORK_GetHeapId(struct ScriptWork *scriptWork);
extern int SCRIPT_WORK_ResetFieldParam(struct ScriptCtl *scriptCtl);
extern struct WordSet *SCRIPT_WORK_GetWordSet(struct ScriptCtl *scriptCtl);
extern void SCRIPT_SYS_CallEvent(struct ScriptCtl *scriptCtl, struct GameEvent *task);
extern void SCRIPT_SYS_SetNextEventFromWork(struct ScriptCtl *scriptCtl, struct GameEvent *task);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, struct ScriptWork *scriptWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, struct ScriptWork *scriptWork);
extern struct GameEvent *EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(struct GameSystem *gameSys, u16 *partyIndexVar, u16 *resultVar);
extern int SCRIPT_SYS_ChangeScriptEvent(int scriptCtl, int scriptId, int arg1, int arg2);
extern int SCRIPT_WORK_SetParams(int scriptWork, int eventId, int arg1, int arg2, u16 arg3);

/* game system, game event, game data */
extern struct FieldMap *ICA_ANIME_GetField20(struct GameSystem *gameSys);
extern struct GameData *ICA_ANIME_GetField1C(struct GameSystem *gameSys);
extern struct GameComm *ICA_ANIME_GetField24(struct GameSystem *gameSys);
extern void ICA_ANIME_SetField30(struct GameSystem *gameSys, u32 state);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSys, u32 procId, void *procData, void *procArg);
extern u32 GAMESYSTEM_GetProcStatus(struct GameSystem *gameSys);
extern u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSys);
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSys, void *parent, EventTaskFn taskFn, u32 workSize);
extern void *GAME_EVENT_GetWork(struct GameEvent *task);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *task);
extern void GAME_EVENT_CallEvent(struct GameEvent *task, struct GameEvent *callee);
extern ScriptVm *VM_End(ScriptVm *vm);
/* the wait callback receives the user work of the script command */
typedef int (*ScriptWorkWaitFn)(ScriptVm *vm, struct ScriptWork *scriptWork);
extern void VM_SetWait(ScriptVm *vm, ScriptWorkWaitFn waitFn);
extern void *GAME_DATA_GetExternalWork(struct GameData *gameData);
extern void GAME_DATA_SetExternalWork(struct GameData *gameData, void *externalWork);
extern struct MusicalSave *GAME_DATA_GetSaveBlock2A(struct GameData *gameData);
extern struct PokeParty *GAME_DATA_GetMyParty(struct GameData *gameData);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct BgmInfo *GAME_DATA_GetBgmInfo(struct GameData *gameData);
extern struct FieldGimmickWork *GAME_DATA_GetFieldGimmick(struct GameData *gameData);
extern u8 GAME_DATA_GetSeason(struct GameData *gameData);
extern u16 GAME_DATA_GetPlayerZoneId(void *playerWork);
extern void *GAME_DATA_GetField114(struct GameData *gameData);
extern struct EventWork *GAME_DATA_GetEventWork(struct GameData *gameData);
extern struct MoveModelSys *GAME_DATA_GetMoveModelSys(struct GameData *gameData);
extern int GAME_DATA_GetIntrudeCount(struct GameData *gameData);
extern u32 TIMEZONE_GetNowTimeZone(u32 season);
extern u16 FIELD_STATUS_GetMapEffectMask(struct MoveModelSys *moveModelSys);
extern void *FIELD_STATUS_CreateSubProcCallbackEvent(struct GameSystem *gameSys, struct FieldMap *fieldMap, u32 overlayId, const void *procData, void *procArg, SubProcCallback callback, void *callbackArg);

/* overlay loading, heap, string helpers */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 GFL_HEAP_Free(void *ptr);
extern int GF_OVERLAY_Load(s32 overlayId);
extern void GF_OVERLAY_Unload(s32 overlayId);
extern void MI_CpuFill8(void *dst, u8 value, u32 size);
extern u32 GFL_USE_GetRandomBelow(u32 range);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetStringN(struct Strbuf *dest, const u16 *src, u32 size);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern struct MsgData *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Strbuf *MSGDATA_AllocString(struct MsgData *msgData, u32 index);
extern u32 MSGDATA_Delete(struct MsgData *msgData);
extern void WORDSET_SetSlotTag(struct WordSet *wordSet, u32 slot, const struct Strbuf *str, u32 grammar, u32 form, u32 count);
extern void WORDSET_SetSlotFromMsg118(struct WordSet *wordSet, u32 slot, u32 value);
extern u32 ARC_TOOL_GetHandleMemberSize(struct ArcFile *arc, u32 member);
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *arc, u32 member, u32 offset, u32 size, void *dest);

/* musical save block */
extern struct MusicalOutfit *MUSICAL_SAVE_GetOutfits(struct MusicalSave *musical);
extern MusicalHeadBits *MUSICAL_SAVE_NoOp(struct MusicalSave *musical);
extern u32 MUSICAL_SAVE_IsPropOwned(struct MusicalSave *musical, u8 prop);
extern void MUSICAL_SAVE_AddProp(struct MusicalSave *musical, u32 prop);
extern MusicalProgram *MUSICAL_SAVE_GetProgram(struct MusicalSave *musical, u32 index);
extern u16 MUSICAL_SAVE_GetShowCount(struct MusicalSave *musical);
extern u16 MUSICAL_SAVE_GetTopRankCount(struct MusicalSave *musical);
extern u8 MUSICAL_SAVE_GetEquippedProp(struct MusicalSave *musical, u32 index);
extern u8 MUSICAL_SAVE_GetSelectedProgram(struct MusicalSave *musical);
extern u8 MUSICAL_SAVE_GetScriptSetting(struct MusicalSave *musical);
extern void MUSICAL_SAVE_SetScriptSetting(struct MusicalSave *musical, u8 value);
extern u8 MUSICAL_SAVE_GetHasDistData(struct MusicalSave *musical);
extern u8 *MUSICAL_SAVE_GetStageData(struct MusicalSave *musical);

/* musical event (ov010 musical_dressup_sys.c) */
extern struct GameEvent *MUSICAL_EVENT_Create(struct GameSystem *gameSys, struct GameData *gameData, u8 arg, u32 mode, MusicalLinkWork *link);
extern u8 MUSICAL_EVENT_GetLocalSlot(struct MusicalEvent *event);
extern u16 MUSICAL_EVENT_GetMaxScore(struct MusicalEvent *event);
extern u16 MUSICAL_EVENT_GetMinScore(struct MusicalEvent *event);
extern u8 MUSICAL_EVENT_GetScoreCapped(struct MusicalEvent *event, u8 index);
extern int MUSICAL_EVENT_GetPlayerOfSlot(int event, u8 index);
extern u8 MUSICAL_EVENT_GetProgramBestCategory(struct MusicalEvent *event);
extern u8 MUSICAL_EVENT_GetSlotOfRank(struct MusicalEvent *event, u8 index);
extern u8 MUSICAL_EVENT_GetBestAppealCategory(struct MusicalEvent *event, u8 index);
extern u8 MUSICAL_EVENT_GetPortraitClass(struct MusicalEvent *event, u8 index);
extern struct Strbuf *MUSICAL_EVENT_AllocTitleString(int player, int heapId);
extern void MUSICAL_EVENT_SetPlayerNameWord(struct MusicalEvent *event, u8 index, struct WordSet *wordSet, u32 slot);
extern void MUSICAL_EVENT_SetPokemonNameWord(struct MusicalEvent *event, u8 index, struct WordSet *wordSet, u32 slot);
extern int MUSICAL_EVENT_CheckNetError(struct MusicalEvent *event);
extern u32 MUSICAL_EVENT_IsAborted(struct MusicalEvent *event);

/* party and musical system */
extern u32 POKEPARTY_GetCount(struct PokeParty *party);
extern struct Pokemon *POKEPARTY_GetMember(struct PokeParty *party, u32 index);
extern int MUSICAL_MCSS_GetMonValue(struct Pokemon *mon);
extern u32 MUSICAL_MCSS_CreateMon(struct Pokemon *mon, int mode);
extern u32 MYSTATUS_GetId(struct MyStatus *myStatus);

/* ov132 comm session, ov021 comm entry menu */
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 COMM_ENTRY_MENU_Create(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void MUS_COMM_FUNC_SetTimingSync(int session, int memberCount);
extern unsigned char *STA_SLOT_GetRecordTable(struct GameData *gameData);
extern void MUS_COMM_FUNC_Create(int mode, void *procArg, void *comm, int arg);
extern int MUS_COMM_FUNC_Delete(void *session);
extern u32 GAME_COMM_GetKind(struct GameComm *comm);
extern u32 GAME_COMM_GetWork(struct GameComm *comm);
extern int GFL_NET_IsSessionNull(void);
extern int MUS_COMM_FUNC_InitCommandTable();
extern int COMM_ENTRY_MENU_Main();
extern int MUS_COMM_FUNC_SetHostFlag();
extern int COMM_ENTRY_MENU_Delete();
extern int MUS_COMM_FUNC_CheckTimingSync();
extern int STA_NET_GetIndexedWord5E();
extern int STA_NET_GetIndexedWord57();

/* wifilist and ov021 postman service */
extern struct WifiList *GAME_SYNC_GetBlock(void *saveBlock);
extern u32 BLOCK20_SAVEDATA_CountEntries(const struct WifiList *wifiList);
extern int PDW_POSTMAN_CountUnreceivable(struct GameData *gameData, int key, struct WifiList *wifiList);
extern void *PDW_POSTMAN_CreateListEvent(struct GameSystem *gameSys);
extern void PDW_POSTMAN_ReceiveItems(struct GameData *gameData, int key, int wifiList);
extern void *PDW_POSTMAN_GetUnreceivableItem(struct GameData *gameData, int key, struct WifiList *wifiList, int index);

/* move_pokemon: roaming legendary save (arm9 unit_0200C7C0.c) */
extern void *MOVE_POKEMON_SAVE_GetBlock(struct SaveControl *save);
extern u8 MOVE_POKEMON_SAVE_IsEntryActive(struct MovePokemonSave *block, u32 index);
extern struct MovePokemonEntry *MOVE_POKEMON_SAVE_GetEntry(struct MovePokemonSave *block, u32 index);
extern u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct MovePokemonSave *block, u32 index);
extern int MOVE_POKEMON_SAVE_SetCommonArea();
extern void MOVE_POKEMON_SAVE_SetEntryField(struct MovePokemonEntry *entry, u32 field, u32 value);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void POKE_TOOL_SetupPartyParamEx(struct Pokemon *mon, u16 species, u16 level, unsigned long long personalId, u32 power, unsigned long long rand);
extern u32 POKE_TOOL_GetPartyValue(struct Pokemon *mon, u32 paramId, u32 buf);
extern void *ZUKAN_SAVE_GetBlock(struct SaveControl *save);
extern void ZUKAN_SAVE_RegisterSeen(void *boxData, struct Pokemon *mon);
extern void MOVE_POKEMON_SAVE_SetEntryState(struct MovePokemonSave *block, u32 index, u32 state);
extern u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *block, u32 index);
extern void MOVE_POKEMON_SAVE_InitEntry(struct MovePokemonEntry *entry);
extern void MOVE_POKEMON_SAVE_SetEntryLocation(struct MovePokemonSave *block, u32 index, u8 location);
extern u32 MOVE_POKEMON_SAVE_GetEntryField(const struct MovePokemonEntry *entry, u32 field);
extern void *BTL_SETUP_GetParty(BattleResultWork *work, int index);

/* field encounter and field objects (ov021, ov010) */
extern int ZONEDATA_GetEncountId(u32 zoneId);
extern struct EffectEncountObj *FIELDMAP_GetEncount(struct FieldMap *fieldMap);
extern int EFFECT_ENCOUNT_LoadSetting(struct EffectEncountObj *obj, int param);
extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern void *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern u32 FIELD_PLAYER_GetFormCode(struct FieldPlayer *player);
extern struct MapObject *FIELD_PLAYER_SearchFrontMmdl(struct FieldPlayer *player);
extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);
extern u32 FIELD_PLAYER_GetNowAttribute(struct FieldPlayer *player);
extern u32 FIELD_PLAYER_GetFrontAttribute(struct FieldPlayer *player, u32 index);
extern int FIELD_PLAYER_CheckEncountAttr(struct FieldPlayer *player, int a, int b);
extern int FIELD_PLAYER_CheckSurfEntryAttr(struct FieldPlayer *player, int a, int b);
extern void FIELD_PLAYER_GetNowGridPos(struct FieldPlayer *player, u16 *x, u16 *y, u16 *z);
extern u16 FLDMMDL_GetObjCode(struct MapObject *obj);
extern void FLDMMDL_GetPos(const struct MapObject *obj, VecFx32 *out);
extern int FLDMMDL_IsMovedPosObjCode(u16 kind);
extern int FLDMMDL_CheckMovedPosAtMapPos(void *map, const VecFx32 *pos);
extern int MOVE_POKEMON_IsInSkillArea(const Area *area, u16 x, u16 z, u32 eventFlag, struct FieldMap *fieldMap);
extern u32 ZONEDATA_IsFlyEnabled(u32 zoneId);
extern u32 ZONEDATA_IsWeatherEnabled(u32 zoneId);
extern int FIELD_GetPlayerAreaZoneId(struct FieldMap *fieldMap, u16 *out);
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 zoneId);
extern u32 ZONEDATA_IsRawZoneF6(u32 zoneId);
extern u32 ZONEDATA_IsRawZoneF7(u32 zoneId);
extern u32 ZONEDATA_IsNormalFieldZone(u32 zoneId);
extern void *SWEET_SCENT_CreateEvent(struct GameSystem *gameSys, struct FieldMap *fieldMap, u8 skillId);

/* field skill tables (ov010 event_field_proclink.c) */
typedef int (*SkillCheckFn)(struct FieldSkillInfo *info);
typedef struct GameEvent *(*SkillEventFn)(SkillTarget *target, FieldSkillInfo *info);
extern SkillCheckFn MOVE_POKEMON_GetSkillCheckFunc(FieldSkillInfo *info, int skillIndex);
extern SkillEventFn MOVE_POKEMON_GetSkillEventFunc(FieldSkillInfo *info, int skillIndex);
extern int MOVE_POKEMON_IsSkillUsable(FieldSkillInfo *info, int skillIndex);
extern void MOVE_POKEMON_InitSkillWork(SkillEventWork *work, const SkillTarget *target, FieldSkillInfo *info);

int SCRCMD_MUSICAL_StartMusical(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_ShowPartyMonMusical(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_GetValue(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_GetProgramInfo(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_AddOwnedProp(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_BufferString(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_ResetProgramRank(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_SelectPartyMon(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_LinkControl(ScriptVm *vm, struct ScriptWork *scriptWork);
void SCRCMD_MUSICAL_CreateLinkWork(struct ScriptCtl *unused, struct GameData *gameData);
void SCRCMD_MUSICAL_DeleteLinkWork(MusicalLinkWork *link, struct GameData *gameData);
void SCRCMD_MUSICAL_BeginCommSession(int link, struct GameSystem *gameSys, struct GameComm *gameComm, int arg);
void SCRCMD_MUSICAL_CloseCommSession(MusicalLinkWork *link);
int SCRCMD_MUSICAL_TaskStartMusical(struct GameEvent *task, u32 *state, void *work);
int SCRCMD_MUSICAL_TaskShowMusicalProc(struct GameEvent *task, u32 *state, void *work);
void SCRCMD_MUSICAL_FreeProcArgs(void *callbackArg);
void SCRCMD_MUSICAL_LinkProcCallback(void *callbackArg);
int SCRCMD_MUSICAL_WaitEntryMenuParent(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_WaitEntryMenuChild(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_WaitSetMemberCount(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_WaitSessionReady(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_WaitCommAttach(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_WaitCommIdle(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_WaitSessionFinish(ScriptVm *vm, struct ScriptWork *scriptWork);
int SCRCMD_MUSICAL_WifiListCommand(ScriptVm *vm, struct ScriptWork *scriptWork);
int FIELD_ENCOUNT_ST_LoadEncountData(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex);
void *FIELD_ENCOUNT_ST_Create(u32 heapId);
void FIELD_ENCOUNT_ST_Delete(void *encountState);
int FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap);
FieldGimmickWork *FIELD_ENCOUNT_ST_ResetGimmickState(struct GameData *gameData);
void MOVE_POKEMON_MoveEntry(struct MovePokemonSave *block, u32 season, u16 slot);
void MOVE_POKEMON_MoveActiveEntries(struct GameData *gameData);
void MOVE_POKEMON_MoveActiveEntriesChecked(struct GameData *gameData);
u32 MOVE_POKEMON_GetEntryZoneId(struct MovePokemonSave *block, u32 slot);
int MOVE_POKEMON_HasActiveEntry(struct MovePokemonSave *block);
void MOVE_POKEMON_SetCommonArea(struct MovePokemonSave *block, int value);
void MOVE_POKEMON_SpawnEntry(struct GameData *gameData, u8 slot);
void MOVE_POKEMON_SpawnPendingEntries(struct GameData *gameData);
void MOVE_POKEMON_HandleBattleResult(struct GameData *gameData, BattleResultWork *work);
int MOVE_POKEMON_FindEntryByZone(struct GameData *gameData, int zoneId);
int MOVE_POKEMON_IsAnyEntryActive(struct GameData *gameData);
int MOVE_POKEMON_GetEntryIndexBySpecies(int species);
void MOVE_POKEMON_MoveToNeighbor(struct MovePokemonSave *block, u32 season, u16 slot, int excludedLocation);
void MOVE_POKEMON_SetEntryLocation(struct MovePokemonSave *block, u32 slot, u8 location, u32 zoneId);
struct MovePokemonEntry *MOVE_POKEMON_FindEntryBySpecies(struct MovePokemonSave *block, int species);
void MOVE_POKEMON_InitSkillInfo(struct FieldMap *fieldMap, FieldSkillInfo *out);
int MOVE_POKEMON_IsSkillBlocked(int skillIndex, FieldSkillInfo *info);
void MOVE_POKEMON_InitSkillTarget(SkillTarget *target, u16 id, u16 variant, u32 targetObj);
struct GameEvent *MOVE_POKEMON_CreateSkillEvent(int skillIndex, SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_CheckCut(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateCutEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_CutEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_CheckFly(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateFlyEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_FlyEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_CheckSurf(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateSurfEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_SurfEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_CheckStrength(FieldSkillInfo *info);
struct GameEvent *MOVE_POKEMON_CreateStrengthEvent(SkillTarget *target, FieldSkillInfo *info);
int MOVE_POKEMON_StrengthEventMain(struct GameEvent *event, u32 *state, void *work);
int MOVE_POKEMON_IsSkill8Unusable(FieldSkillInfo *info);
void *MOVE_POKEMON_CreateDiveEvent(SkillTarget *target, FieldSkillInfo *info);

extern u8 ov112_id[];
extern const char d_02172914[];
extern u8 d_021F8360[];
extern u8 d_021BB6A4[];
extern u8 ov100_id[];
extern u8 ov132_id[];
extern const char MUSICAL_DRESSUP_SYS_ProcTable[];
extern const char d_02172928[];
extern const u16 d_021711C6[];
extern const char d_0217293C[];
extern const RoamLocationLinks d_021711A8[];
extern const Area d_021711EC;
extern const Area d_021711F4;



/*
 * Script command: start the ov010 musical link sequence (MUSICAL_EVENT_Create) for
 * mode 0/1, or push the ov112 proc through FIELD_STATUS_CreateSubProcCallbackEvent otherwise.
 *
 * Levers (all needed for the exact bytes): `d = (mode == 0) ? 0 : 1` instead
 * of an if (removes a register swap); SCRIPT_WORK_ReadWorkValue declared u16 with the
 * argument held in a u16 local (moves the outgoing stack store, see
 * docs/idioms/a-u16-accessor-result-held-in-a-u16-local-moves-the-stack-argument-stores.md).
 * The callback 0x0215DF6C is a 12-byte tail stub in the image.
 * SCRIPT_WORK_ResetFieldParam returns a+0x18 (result ignored); GAME_DATA_GetSaveBlock2A is void in its
 * own file, but this caller uses its result as the musical save pointer.
 */
int SCRCMD_MUSICAL_StartMusical(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u16 arg;
    u8 mode;

    scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    fieldMap = ICA_ANIME_GetField20(gameSys);
    SCRIPT_WORK_ResetFieldParam(scriptCtl);
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    mode = *vm->pc;
    vm->pc++;
    if (mode <= 1) {
        MusicalLinkWork *link = GAME_DATA_GetExternalWork(gameData);
        u32 startMode;
        struct GameEvent *task;
        MusicalStartTask *startTask;

        startMode = (mode == 0) ? 0 : 1;
        task = GAME_EVENT_Create(gameSys, 0, SCRCMD_MUSICAL_TaskStartMusical, sizeof(MusicalStartTask));
        startTask = GAME_EVENT_GetWork(task);
        MI_CpuFill8(startTask, 0, sizeof(MusicalStartTask));
        startTask->musicalSeq = MUSICAL_EVENT_Create(gameSys, gameData, arg, startMode, link);
        startTask->link = link;
        startTask->mode = startMode;
        SCRIPT_SYS_SetNextEventFromWork(scriptCtl, task);
        GAME_DATA_GetBgmInfo(gameData);
        VM_End(vm);
        return 1;
    } else {
        struct MusicalSave *musical = GAME_DATA_GetSaveBlock2A(gameData);
        MusicalProcBox *box;

        box = GFL_HEAP_Alloc(4, sizeof(MusicalProcBox), 1, d_02172914, 0xA9);
        box->args = GFL_HEAP_Alloc(4, 0x14, 1, d_02172914, 0xAA);
        box->args->startMode = 0;
        box->args->saveBits = MUSICAL_SAVE_NoOp(musical);
        box->args->isOffline = 1;
        SCRIPT_SYS_CallEvent(scriptCtl, FIELD_STATUS_CreateSubProcCallbackEvent(gameSys, fieldMap, (u32)ov112_id, d_021F8360, box->args, SCRCMD_MUSICAL_FreeProcArgs, box));
        return 1;
    }
}


/*
 * Script command: show the musical of a party Pokemon. Reads a party index,
 * creates the musical system for that member and runs the proc MUSICAL_DRESSUP_SYS_ProcTable
 * on it from a task (SCRCMD_MUSICAL_TaskShowMusicalProc), which frees the work when done.
 */
int SCRCMD_MUSICAL_ShowPartyMonMusical(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    struct GameSystem *gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(scriptWork);
    int partyIndex;
    u32 musicalSave, musicalSystem;
    struct GameEvent *task;
    MusicalSystemTask *systemTask;

    ICA_ANIME_GetField20(gameSys);
    partyIndex = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    musicalSave = (u32)GAME_DATA_GetSaveBlock2A(gameData);
    musicalSystem = MUSICAL_MCSS_CreateMon(POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), partyIndex), 4);
    task = GAME_EVENT_Create(gameSys, 0, SCRCMD_MUSICAL_TaskShowMusicalProc, 4);
    systemTask = GAME_EVENT_GetWork(task);
    MI_CpuFill8(systemTask, 0, 4);
    systemTask->args = GFL_HEAP_Alloc(4, 0xc, 1, d_02172914, 0xd7);
    systemTask->args->musicalSystem = musicalSystem;
    systemTask->args->musicalSave = musicalSave;
    systemTask->args->startMode = 0;
    SCRIPT_SYS_CallEvent(scriptCtl, task);
    return 1;
}


/*
 * Script command: read a one-byte query id from the script cursor, one
 * argument word and a result variable, and store the answer of the query
 * (musical save counters 0..15, link-result queries 30..39) into the variable.
 *
 * Levers: the per-case best/second locals at function scope in declaration
 * order with op declared last (sets the stack slots), max initialised before
 * best, case 10 loops over its own block-local slot, case 7 tests == 0 first.
 */
int SCRCMD_MUSICAL_GetValue(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u32 arg;
    u16 *resultVar;
    struct GameData *gameData;
    struct MusicalSave *musical;
    struct MusicalEvent *musicalEvent;
    u8 i;
    u8 maxCount;
    u8 uniqueTopSlot;
    u8 lowestSlot;
    u8 topSlot;
    u8 leaderSlot;
    u8 leaderPrevMax;
    u8 runnerUpSlot;
    struct PokeParty *party;
    u8 op;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    op = *vm->pc;
    vm->pc++;
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    musical = GAME_DATA_GetSaveBlock2A(gameData);
    musicalEvent = 0;
    if (op >= 30) {
        struct MusicalEvent **linkEvent = GAME_DATA_GetExternalWork(gameData);

        if (linkEvent == 0) {
            *resultVar = 0;
            return 0;
        }
        musicalEvent = *linkEvent;
    }
    switch (op) {
    case 0:
        *resultVar = MUSICAL_SAVE_GetShowCount(musical);
        break;
    case 1:
        *resultVar = MUSICAL_SAVE_GetTopRankCount(musical);
        break;
    case 2:
        *resultVar = MUSICAL_SAVE_GetSelectedProgram(musical);
        break;
    case 3: {
        /* equipped prop slot with the single highest value, 4 on a tie */
        maxCount = 0;
        uniqueTopSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, i);

            if (value > maxCount) {
                maxCount = value;
                uniqueTopSlot = i;
            } else if (value == maxCount) {
                uniqueTopSlot = 4;
            }
        }
        *resultVar = uniqueTopSlot;
        break;
    }
    case 4:
        *resultVar = MUSICAL_SAVE_GetScriptSetting(musical);
        break;
    case 5:
        MUSICAL_SAVE_SetScriptSetting(musical, arg);
        break;
    case 6:
        *resultVar = 0;
        for (i = 0; i < 4; i++) {
            if (MUSICAL_SAVE_GetEquippedProp(musical, i) != 0)
                *resultVar = 1;
        }
        break;
    case 7:
        if (MUSICAL_SAVE_NoOp(musical)->shotState == 0)
            *resultVar = 0;
        else
            *resultVar = 1;
        break;
    case 8: {
        /* slot with the lowest value (last one on a tie) */
        maxCount = 0xFF;
        lowestSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, i);

            if (value <= maxCount) {
                maxCount = value;
                lowestSlot = i;
            }
        }
        *resultVar = lowestSlot;
        break;
    }
    case 9: {
        /* slot with the highest value (first one on a tie) */
        maxCount = 0;
        topSlot = 4;

        for (i = 0; i < 4; i++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, i);

            if (value > maxCount) {
                maxCount = value;
                topSlot = i;
            }
        }
        *resultVar = topSlot;
        break;
    }
    case 10: {
        /* runner-up slot, 4 when the runner-up ties */
        u8 slot;

        leaderSlot = 4;
        leaderPrevMax = 0;
        maxCount = 0;
        runnerUpSlot = 4;

        for (slot = 0; slot < 4; slot++) {
            u8 value = MUSICAL_SAVE_GetEquippedProp(musical, slot);

            if (value > maxCount) {
                if (leaderPrevMax == maxCount) {
                    runnerUpSlot = 4;
                } else {
                    leaderPrevMax = maxCount;
                    runnerUpSlot = leaderSlot;
                }
                maxCount = value;
                leaderSlot = slot;
            }
        }
        *resultVar = runnerUpSlot;
        break;
    }
    case 11: {
        /* number of party members that can take part in a musical */
        u8 count = 0;
        u8 partyCount;

        party = GAME_DATA_GetMyParty(gameData);
        partyCount = POKEPARTY_GetCount(party);

        for (i = 0; i < partyCount; i++) {
            if ((u32)MUSICAL_MCSS_GetMonValue(POKEPARTY_GetMember(party, (int)i)) == 1)
                count++;
        }
        *resultVar = count;
        break;
    }
    case 12:
        if ((u32)MUSICAL_MCSS_GetMonValue(POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), (int)arg)) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 13: {
        /* any outfit slot in use */
        struct MusicalOutfit *outfits = MUSICAL_SAVE_GetOutfits(musical);

        *resultVar = 0;
        for (i = 0; i < 8; i++) {
            if (outfits[i].pokeSlot != 10)
                *resultVar = 1;
        }
        break;
    }
    case 14:
        if (MUSICAL_SAVE_GetHasDistData(musical) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 15:
        if (MUSICAL_SAVE_IsPropOwned(musical, (u8)arg) == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 30:
        *resultVar = MUSICAL_EVENT_GetLocalSlot(musicalEvent);
        break;
    case 31:
        *resultVar = MUSICAL_EVENT_GetMaxScore(musicalEvent);
        break;
    case 32:
        *resultVar = MUSICAL_EVENT_GetMinScore(musicalEvent);
        break;
    case 33:
        *resultVar = MUSICAL_EVENT_GetScoreCapped(musicalEvent, arg);
        break;
    case 35:
        *resultVar = MUSICAL_EVENT_GetPlayerOfSlot((int)musicalEvent, arg);
        break;
    case 36:
        *resultVar = MUSICAL_EVENT_GetProgramBestCategory(musicalEvent);
        break;
    case 37:
        *resultVar = MUSICAL_EVENT_GetSlotOfRank(musicalEvent, arg);
        break;
    case 38:
        *resultVar = MUSICAL_EVENT_GetBestAppealCategory(musicalEvent, arg);
        break;
    case 39:
        *resultVar = MUSICAL_EVENT_GetPortraitClass(musicalEvent, arg);
        break;
    }
    return 0;
}


/*
 * Script command: read a query kind and a program slot, store a derived
 * value of that musical program into a script variable.
 */
int SCRCMD_MUSICAL_GetProgramInfo(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    int slot;
    u32 kind;
    u16 *resultVar;
    MusicalProgramView *program;

    slot = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    kind = *vm->pc;
    vm->pc++;
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    program = (MusicalProgramView *)MUSICAL_SAVE_GetProgram(GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork)), (u8)slot);
    switch (kind) {
    case 0:
        switch (program->state) {
        case 0: *resultVar = 0x18; break;
        case 1: *resultVar = 0xf; break;
        case 2: *resultVar = 0x2d; break;
        case 3: *resultVar = 0xc; break;
        case 4: *resultVar = 0; break;
        }
        break;
    case 1:
        *resultVar = slot + 5;
        break;
    case 2:
        slot += 0xf;
        *resultVar = slot;
        break;
    case 3:
        *resultVar = program->rank;
        break;
    case 4:
        *resultVar = program->score;
        break;
    }
    return 0;
}


/* Script command: mark a musical prop as owned. The id is truncated to a byte before the arm9 call. */
int SCRCMD_MUSICAL_AddOwnedProp(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    int prop = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);

    MUSICAL_SAVE_AddProp(GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork)), (u8)prop);

    return 0;
}


/*
 * Script command: read a one-byte string kind and a word-set slot from the
 * script cursor, one argument word, and buffer the matching string into the
 * slot (stage name, message-bank entries, link member names, or the three
 * placement labels of a four-way ranking).
 */
int SCRCMD_MUSICAL_BufferString(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(scriptWork);
    u32 heapId = SCRCMD_WORK_GetHeapId(scriptWork);
    struct WordSet *wordSet = SCRIPT_WORK_GetWordSet(scriptCtl);
    u8 kind;
    u8 slot;
    u32 arg;
    struct MsgData *msgData;
    struct Strbuf *str;

    kind = *vm->pc;
    vm->pc++;
    slot = *vm->pc;
    vm->pc++;
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);

    switch (kind) {
    case 0: {
        struct MusicalSave *musical = GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork));

        str = STRBUF_Create(0x26, heapId);
        STRBUF_SetStringN(str, (const u16 *)MUSICAL_SAVE_GetStageData(musical), 0x26);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        break;
    }
    case 1:
    case 8:
        if (kind == 1)
            msgData = MSGDATA_CreateFromArchive(0, 2, 0x4F, heapId);
        else
            msgData = MSGDATA_CreateFromArchive(0, 2, 0x11A, heapId);
        str = MSGDATA_AllocString(msgData, arg + 3);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(msgData);
        break;
    case 2:
        str = MUSICAL_EVENT_AllocTitleString((int)(*((void **)GAME_DATA_GetExternalWork(gameData))), heapId);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        break;
    case 3:
        msgData = MSGDATA_CreateFromArchive(0, 2, 0x4B, heapId);
        str = MSGDATA_AllocString(msgData, arg);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(msgData);
        break;
    case 4:
        msgData = MSGDATA_CreateFromArchive(0, 2, 0x4B, heapId);
        str = MSGDATA_AllocString(msgData, arg + 4);
        WORDSET_SetSlotTag(wordSet, slot, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(msgData);
        break;
    case 5:
        MUSICAL_EVENT_SetPlayerNameWord(*((void **)GAME_DATA_GetExternalWork(gameData)), arg, wordSet, slot);
        break;
    case 6:
        MUSICAL_EVENT_SetPokemonNameWord(*((void **)GAME_DATA_GetExternalWork(gameData)), arg, wordSet, slot);
        break;
    case 7: {
        struct MusicalSave *musical = GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork));
        u16 labelIds[3];
        u8 slotOrder[4];
        u8 slotValue[4];
        u8 i;
        u8 j;

        /* sort the four slots by value, descending (bubble sort) */
        for (i = 0; i < 4; i++) {
            slotOrder[i] = i;
            slotValue[i] = MUSICAL_SAVE_GetEquippedProp(musical, i);
        }
        for (i = 1; i < 4; i++) {
            for (j = 0; j < 4 - i; j++) {
                u8 next = j + 1;

                if (slotValue[j] < slotValue[next]) {
                    u8 tmp = slotValue[j];

                    slotValue[j] = slotValue[next];
                    slotValue[next] = tmp;
                    tmp = slotOrder[j];
                    slotOrder[j] = slotOrder[next];
                    slotOrder[next] = tmp;
                }
            }
        }
        if (slotValue[0] == slotValue[1] && slotValue[0] == slotValue[2]) {
            labelIds[0] = 9;
            labelIds[1] = 8;
        } else {
            labelIds[0] = slotOrder[0] + 4;
            if (slotValue[1] == slotValue[2])
                labelIds[1] = 8;
            else
                labelIds[1] = slotOrder[1] + 4;
        }
        if (slotValue[1] == slotValue[3])
            labelIds[2] = slotOrder[1] + 4;
        else if (slotValue[2] == slotValue[3])
            labelIds[2] = slotOrder[2] + 4;
        else
            labelIds[2] = slotOrder[3] + 4;
        msgData = MSGDATA_CreateFromArchive(0, 2, 0x4B, heapId);
        for (i = 0; i < 3; i++) {
            str = MSGDATA_AllocString(msgData, labelIds[i]);
            WORDSET_SetSlotTag(wordSet, i, str, 0, 1, 2);
            STRBUF_Delete(str);
        }
        MSGDATA_Delete(msgData);
        break;
    }
    }
    return 0;
}


/* Script command: clear the rank byte of a musical program slot. */
int SCRCMD_MUSICAL_ResetProgramRank(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    int slot = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    MusicalProgramView *program = (MusicalProgramView *)MUSICAL_SAVE_GetProgram(GAME_DATA_GetSaveBlock2A(SCRCMD_WORK_GetGameData(scriptWork)), (u8)slot);

    program->rank = 0;
    return 0;
}


/* Script command: open the party selection screen; the two script variables receive the choice. */
int SCRCMD_MUSICAL_SelectPartyMon(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *partyIndexVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    struct ScriptCtl *scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);

    SCRIPT_SYS_CallEvent(scriptCtl, EVENT_POKE_STATUS_CreatePokeSelectStatusEvent(SCRCMD_WORK_GetGameSystem(scriptWork), partyIndexVar, resultVar));
    return 1;
}


/*
 * Script command: link-session control. Reads a sub-command, an argument
 * and a result variable, then opens or closes the link work (0, 1), starts
 * the ov132 session steps (10..18, most of which install a wait callback and
 * suspend the script) or reports the session state into the variable (19..21).
 *
 * The empty `case 100: break;` is what leaves the lone `cmp r6, #0x64`.
 * ov100_id is the overlay id of the ov100 proc (the symbol value is 0x64).
 */
int SCRCMD_MUSICAL_LinkControl(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct ScriptCtl *scriptCtl;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    u16 cmd;
    u16 arg;
    u16 *resultVar;
    int busy;
    MusicalLinkWork *link;

    scriptCtl = SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    fieldMap = ICA_ANIME_GetField20(gameSys);
    cmd = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    arg = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    busy = 0;
    link = 0;
    if (cmd != 0 && cmd != 0x15) {
        link = GAME_DATA_GetExternalWork(gameData);
        if (link->musicalEvent != 0) {
            MUSICAL_EVENT_CheckNetError(link->musicalEvent);
            if (MUSICAL_EVENT_IsAborted(link->musicalEvent) == 1)
                busy = 1;
        }
    }
    switch (cmd) {
    case 0:
        SCRCMD_MUSICAL_CreateLinkWork(scriptCtl, gameData);
        break;
    case 1:
        SCRCMD_MUSICAL_DeleteLinkWork(link, gameData);
        break;
    case 10:
        SCRCMD_MUSICAL_BeginCommSession((int)link, gameSys, ICA_ANIME_GetField24(gameSys), arg);
        break;
    case 11:
        SCRCMD_MUSICAL_CloseCommSession(link);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitCommIdle);
        return 1;
    case 12:
        link->resultOut = resultVar;
        link->entryMenu = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(gameData), fieldMap, 2, 4, 4, 0, 1, 0);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitEntryMenuParent);
        return 1;
    case 13:
        link->resultOut = resultVar;
        link->entryMenu = COMM_ENTRY_MENU_Create(GAME_DATA_GetMyStatus(gameData), fieldMap, 2, 4, 4, 1, 1, 0);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitEntryMenuChild);
        return 1;
    case 14:
        if (link->session == 0 || busy != 0)
            break;
        link->memberCount = arg;
        MUS_COMM_FUNC_SetTimingSync((int)link->session, (u8)link->memberCount);
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitSetMemberCount);
        return 1;
    case 15:
        if (link->session == 0 || busy != 0)
            break;
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitSessionReady);
        return 1;
    case 16:
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitCommAttach);
        return 1;
    case 17:
        if (link->session == 0 || busy != 0)
            break;
        VM_SetWait(vm, SCRCMD_MUSICAL_WaitSessionFinish);
        return 1;
    case 18: {
        MusicalLinkWait *wait = GFL_HEAP_Alloc(0x8004, 8, (u32)1, d_02172914, (u32)0x3C8);

        wait->scriptWork = scriptWork;
        wait->link = link;
        link->resultOut = resultVar;
        link->gameData = gameData;
        link->procWork = (u32)STA_SLOT_GetRecordTable(gameData);
        link->procMode = arg == 0 ? 9 : 10;
        SCRIPT_SYS_CallEvent(scriptCtl, FIELD_STATUS_CreateSubProcCallbackEvent(gameSys, fieldMap, (u32)ov100_id, d_021BB6A4, &link->gameData, SCRCMD_MUSICAL_LinkProcCallback, wait));
        return 1;
    }
    case 19:
        if (link->session != 0 && busy == 1)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 20:
        if (link->session != 0)
            *resultVar = 1;
        else
            *resultVar = 0;
        break;
    case 21:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            ICA_ANIME_SetField30(gameSys, 1);
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 100:
        break;
    }
    return 0;
}


/*
 * Allocate the 0x38-byte link work, clear its first two words, attach it to
 * the game data external-work slot and load overlays 132 and 112.
 */
void SCRCMD_MUSICAL_CreateLinkWork(struct ScriptCtl *unused, struct GameData *gameData)
{
    MusicalLinkWork *link = GFL_HEAP_Alloc(4, 0x38, 1, d_02172914, 0x413);

    link->musicalEvent = 0;
    link->session = 0;
    GAME_DATA_SetExternalWork(gameData, link);
    GF_OVERLAY_Load((u32)ov132_id);
    GF_OVERLAY_Load((u32)ov112_id);
}


/* Unload overlays 112 and 132, free the link work and detach it. */
void SCRCMD_MUSICAL_DeleteLinkWork(MusicalLinkWork *link, struct GameData *gameData)
{
    GF_OVERLAY_Unload((u32)ov112_id);
    GF_OVERLAY_Unload((u32)ov132_id);
    GFL_HEAP_Free(link);
    GAME_DATA_SetExternalWork(gameData, 0);
}


/*
 * Forwards three of its four incoming argument registers to a callee whose
 * first parameter is the constant 4. The callee takes four arguments, so a
 * tail call is impossible (bx would spend an argument register on the
 * target), which is why the image keeps a frame and emits a direct bl.
 */
void SCRCMD_MUSICAL_BeginCommSession(int link, struct GameSystem *gameSys, struct GameComm *gameComm, int arg)
{
    MUS_COMM_FUNC_Create(4, (void *)gameSys, (void *)gameComm, arg);
}


/* Close the comm session of the link work, if any. */
void SCRCMD_MUSICAL_CloseCommSession(MusicalLinkWork *link)
{
    if (link->session != 0) {
        MUS_COMM_FUNC_Delete(link->session);
        link->session = 0;
    }
}


/*
 * Event task of StartMusical (states 0..3): call the link event, close the
 * session, wait for the comm (when mode 1), then free the link work.
 * Lever: the game data pointer stays live in r0 across the switch for
 * GAME_DATA_GetBgmInfo. Two zero alignment bytes follow the 150-byte function.
 */
int SCRCMD_MUSICAL_TaskStartMusical(struct GameEvent *task, u32 *state, void *work)
{
    MusicalStartTask *startTask = work;
    struct GameData *gameData;

    gameData = ICA_ANIME_GetField1C(GAME_EVENT_GetGameSystem(task));
    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(task, startTask->musicalSeq);
        (*state)++;
        break;
    case 1:
        GAME_DATA_GetBgmInfo(gameData);
        SCRCMD_MUSICAL_CloseCommSession(startTask->link);
        (*state)++;
        break;
    case 2:
        {
            struct GameComm *gameComm = ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(task));
            if (startTask->mode != 0) {
                if (GAME_COMM_GetKind(gameComm) != 0)
                    break;
            }
        }
        (*state)++;
        break;
    case 3:
        if (GFL_NET_IsSessionNull() != 1) {
            if (startTask->mode != 0)
                break;
        }
        if (startTask->mode == 1) {
            GAMESYSTEM_TryStartAutoComm(GAME_EVENT_GetGameSystem(task));
        }
        SCRCMD_MUSICAL_DeleteLinkWork(startTask->link, gameData);
        (*state)++;
        return 1;
    }
    return 0;
}


/*
 * Event task of ShowPartyMonMusical: runs the proc MUSICAL_DRESSUP_SYS_ProcTable on the musical
 * system arguments, then frees the system and the argument block.
 */
int SCRCMD_MUSICAL_TaskShowMusicalProc(struct GameEvent *task, u32 *state, void *work)
{
    MusicalSystemTask *systemTask = work;
    struct GameSystem *gameSys = GAME_EVENT_GetGameSystem(task);

    ICA_ANIME_GetField1C(gameSys);
    ICA_ANIME_GetField20(gameSys);
    switch (*state) {
    case 0:
        (*state)++;
        break;
    case 1:
        (*state)++;
        break;
    case 2:
        (*state)++;
        break;
    case 3:
        GAMESYSTEM_CallProc(gameSys, -1, (void *)MUSICAL_DRESSUP_SYS_ProcTable, systemTask->args);
        (*state)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSys) != 0)
            break;
        (*state)++;
        break;
    case 5:
        (*state)++;
        break;
    case 6:
        GFL_HEAP_Free((void *)systemTask->args->musicalSystem);
        GFL_HEAP_Free(systemTask->args);
        return 1;
    }
    return 0;
}


/* Proc callback: free the argument block of the ov112 proc. */
void SCRCMD_MUSICAL_FreeProcArgs(void *callbackArg)
{
    MusicalProcBox *box = callbackArg;

    GFL_HEAP_Free(box->args);
}


/*
 * Callback of the ov100 proc: set the result variable to 1 (0 when the proc
 * mode is 12 or 13) and close the comm session otherwise.
 */
void SCRCMD_MUSICAL_LinkProcCallback(void *callbackArg)
{
    MusicalLinkWait *wait = callbackArg;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    MusicalLinkWork *link;

    gameSys = SCRCMD_WORK_GetGameSystem(wait->scriptWork);
    gameData = SCRCMD_WORK_GetGameData(wait->scriptWork);
    ICA_ANIME_GetField24(gameSys);
    link = wait->link;
    if (link->procMode != 0xc && link->procMode != 0xd) {
        *link->resultOut = 1;
        MUS_COMM_FUNC_InitCommandTable(wait->link->session);
    } else {
        *link->resultOut = 0;
    }
}


/* Wait: entry menu opened as parent. Result 0 = accepted, 1 = declined, 2 = cancelled. */
int SCRCMD_MUSICAL_WaitEntryMenuParent(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;
    int done;
    int status;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    status = COMM_ENTRY_MENU_Main(link->entryMenu);
    done = 0;
    switch (status) {
    case 1:
        *link->resultOut = 0;
        MUS_COMM_FUNC_SetHostFlag(link->session);
        done = 1;
        break;
    case 2:
        *link->resultOut = 1;
        done = 1;
        break;
    case 4:
        *link->resultOut = 2;
        done = 1;
        break;
    }
    if (done == 1) {
        COMM_ENTRY_MENU_Delete(link->entryMenu);
        link->entryMenu = 0;
    }
    return done;
}


/* Wait: entry menu opened as child. Result 3 = accepted, 4 = declined, 2 = cancelled. */
int SCRCMD_MUSICAL_WaitEntryMenuChild(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;
    int done;
    int result;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    done = 0;
    switch (COMM_ENTRY_MENU_Main(link->entryMenu)) {
    case 1:
        *link->resultOut = 3;
        MUS_COMM_FUNC_SetHostFlag(link->session);
        done = 1;
        break;
    case 2:
        result = 4;
        *link->resultOut = result;
        done = 1;
        break;
    case 4:
        result = 2;
        *link->resultOut = result;
        done = 1;
        break;
    }
    if (done == 1) {
        COMM_ENTRY_MENU_Delete(link->entryMenu);
        link->entryMenu = 0;
    }
    return done;
}


/* Wait: member count set on the session (command 14). */
int SCRCMD_MUSICAL_WaitSetMemberCount(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    if (link->musicalEvent != 0) {
        MUSICAL_EVENT_CheckNetError(link->musicalEvent);
        if (MUSICAL_EVENT_IsAborted(link->musicalEvent) == 1)
            return 1;
    }
    if (MUS_COMM_FUNC_CheckTimingSync(link->session, (u8)link->memberCount) == 1)
        return 1;
    return 0;
}


/* Wait: session ready (command 15). */
int SCRCMD_MUSICAL_WaitSessionReady(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    MUSICAL_EVENT_CheckNetError(link->musicalEvent);
    if (MUSICAL_EVENT_IsAborted(link->musicalEvent) == 1)
        return 1;
    if (STA_NET_GetIndexedWord5E(link->session) == 1)
        return 1;
    return 0;
}


/* Wait: attach the link work to the comm session once the comm kind is 4 (command 16). */
int SCRCMD_MUSICAL_WaitCommAttach(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct GameComm *gameComm;
    MusicalLinkWork *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    gameComm = ICA_ANIME_GetField24(gameSys);
    link = GAME_DATA_GetExternalWork(gameData);
    if (GAME_COMM_GetKind(gameComm) == 4) {
        link->session = (void *)GAME_COMM_GetWork(gameComm);
        return 1;
    }
    return 0;
}


/* Wait: the comm is gone and the musical event is idle (command 11). */
int SCRCMD_MUSICAL_WaitCommIdle(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    struct GameComm *gameComm;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    MusicalLinkWork *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    gameComm = ICA_ANIME_GetField24(gameSys);
    link = GAME_DATA_GetExternalWork(gameData);
    if (link->musicalEvent != 0) {
        MUSICAL_EVENT_CheckNetError(link->musicalEvent);
        if (MUSICAL_EVENT_IsAborted(link->musicalEvent) == 1) {
            return 1;
        }
    }
    if (GAME_COMM_GetKind(gameComm) == 0) {
        return 1;
    }
    return 0;
}


/* Wait: session finished (command 17). */
int SCRCMD_MUSICAL_WaitSessionFinish(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    MusicalLinkWork *link;

    SCRCMD_WORK_GetScriptWork(scriptWork);
    link = GAME_DATA_GetExternalWork(SCRCMD_WORK_GetGameData(scriptWork));
    MUSICAL_EVENT_CheckNetError(link->musicalEvent);
    if (MUSICAL_EVENT_IsAborted(link->musicalEvent) == 1)
        return 1;
    if (STA_NET_GetIndexedWord57(link->session) == 1)
        return 1;
    return 0;
}


/*
 * Script command with a six-way sub-command switch over an ov021 service
 * (0x021B76B4..0x021B7794) on the wifi list GAME_SYNC_GetBlock returns;
 * sub-commands 0, 1 and 4 write a halfword result through the result
 * variable, 5 formats a value into the word set.
 */
int SCRCMD_MUSICAL_WifiListCommand(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u32 cmd;
    u16 *resultVar;
    u16 key;
    struct GameSystem *gameSys;
    struct GameData *gameData;
    struct WifiList *wifiList;
    u32 limit;
    void *postEvent;
    struct WordSet *wordSet;

    cmd = SCRIPT_WORK_ReadWorkValue(vm, scriptWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    key = SCRCMD_WORK_GetHeapId(scriptWork);
    gameSys = SCRCMD_WORK_GetGameSystem(scriptWork);
    gameData = SCRCMD_WORK_GetGameData(scriptWork);
    wifiList = GAME_SYNC_GetBlock(GAME_DATA_GetSaveControl(gameData));
    limit = (int)BLOCK20_SAVEDATA_CountEntries(wifiList);
    if (ICA_ANIME_GetField20(gameSys) == 0 && cmd != 0) {
        return 0;
    }
    switch (cmd) {
    case 0:
        *resultVar = (int)BLOCK20_SAVEDATA_CountEntries(wifiList) > 0 ? 1 : 0;
        break;
    case 1:
        if (PDW_POSTMAN_CountUnreceivable(gameData, key, wifiList) < limit) {
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 2:
        postEvent = PDW_POSTMAN_CreateListEvent(gameSys);
        SCRIPT_SYS_CallEvent(SCRCMD_WORK_GetScriptWork(scriptWork), postEvent);
        return 1;
    case 3:
        PDW_POSTMAN_ReceiveItems(gameData, key, (int)wifiList);
        break;
    case 5:
        wordSet = SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(scriptWork));
        WORDSET_SetSlotFromMsg118(wordSet, 0, (u32)PDW_POSTMAN_GetUnreceivableItem(gameData, key, wifiList, *resultVar));
        break;
    case 4:
        *resultVar = PDW_POSTMAN_CountUnreceivable(gameData, key, wifiList);
        break;
    }
    return 0;
}



/*
 * Read the encounter row of a zone from the encounter archive into `row`
 * (0xE8 bytes). Zones with one row use it for every season, zones with four
 * rows use the row of the season index. Returns 0 when the zone has no row
 * or the member has another size.
 */
int FIELD_ENCOUNT_ST_LoadEncountData(EncountRow *row, struct ArcFile *arc, u32 zoneId, int seasonIndex)
{
    u32 rowCount;
    int member;

    MI_CpuFill8(row, 0, 0xe8);
    member = ZONEDATA_GetEncountId(zoneId);
    if (member == 0xffff) {
        return 0;
    }
    rowCount = ARC_TOOL_GetHandleMemberSize(arc, member) / 0xe8;
    if (rowCount != 1 && rowCount != 4) {
        return 0;
    }
    if (rowCount == 1) {
        seasonIndex = 0;
    }
    ARC_TOOL_ReadHandleMemberRange(arc, member, seasonIndex * 0xe8, 0xe8, row);
    row->flags |= 0x80;
    return 1;
}


/* Allocate the 0x20-byte field encounter state. */
void *FIELD_ENCOUNT_ST_Create(u32 heapId)
{
    return GFL_HEAP_Alloc(heapId, 32, 1, d_02172928, 45);
}


void FIELD_ENCOUNT_ST_Delete(void *encountState)
{
    GFL_HEAP_Free(encountState);
}


/* Result of the effect-encounter query for the field effect object of `fieldMap`. */
int FIELD_ENCOUNT_ST_GetEffectEncount(struct FieldMap *fieldMap)
{
    EffectEncountObj *obj;

    obj = FIELDMAP_GetEncount(fieldMap);
    return EFFECT_ENCOUNT_LoadSetting(obj, obj->encountParam);
}


/* Clear the state word (offset 0xC) of the field gimmick work and return the work. */
FieldGimmickWork *FIELD_ENCOUNT_ST_ResetGimmickState(struct GameData *gameData)
{
    FieldGimmickWork *gimmick;

    gimmick = GAME_DATA_GetFieldGimmick(gameData);
    gimmick->state = 0;
    return gimmick;
}


/* Move entry `slot` to a new location, excluding no location (0xff). */
void MOVE_POKEMON_MoveEntry(struct MovePokemonSave *block, u32 season, u16 slot)
{
    MOVE_POKEMON_MoveToNeighbor(block, season, slot, 0xff);
}


/* After a battle: move every active roaming entry. */
void MOVE_POKEMON_MoveActiveEntries(struct GameData *gameData)
{
    u8 i;
    u32 season;
    struct MovePokemonSave *block;

    block = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    season = GAME_DATA_GetSeason(gameData);
    for (i = 0; i < 2; i++) {
        if (MOVE_POKEMON_SAVE_IsEntryActive(block, i) != 0) MOVE_POKEMON_MoveEntry(block, season, i);
    }
}


/* Same as MOVE_POKEMON_MoveActiveEntries, with an unused entry lookup per slot. */
void MOVE_POKEMON_MoveActiveEntriesChecked(struct GameData *gameData)
{
    u8 i;
    u32 season;
    struct MovePokemonSave *block;

    block = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    season = GAME_DATA_GetSeason(gameData);
    for (i = 0; i < 2; i++) {
        MOVE_POKEMON_SAVE_GetEntry(block, i);
        if (MOVE_POKEMON_SAVE_IsEntryActive(block, i) != 0) {
            MOVE_POKEMON_MoveEntry(block, season, i);
        }
    }
}


/* Zone id of the location an entry is in (319 for an invalid location). */
u32 MOVE_POKEMON_GetEntryZoneId(struct MovePokemonSave *block, u32 slot)
{
    u32 location = MOVE_POKEMON_SAVE_GetEntryLocation(block, slot);
    if (location > 16) return 319;
    return d_021711C6[location];
}


/* 1 when any of the two entries is active. */
int MOVE_POKEMON_HasActiveEntry(struct MovePokemonSave *block)
{
    u8 i = 0;

    do {
        if (MOVE_POKEMON_SAVE_IsEntryActive(block, i) != 0)
            return 1;
        i++;
    } while (i < 2);
    return 0;
}


/* Store the common area value when an entry is active. */
void MOVE_POKEMON_SetCommonArea(struct MovePokemonSave *block, int value)
{
    if (MOVE_POKEMON_HasActiveEntry(block) != 0)
        MOVE_POKEMON_SAVE_SetCommonArea(block, value);
}


/*
 * Hand out the roaming legendary of entry `slot` (Thundurus 642 or Tornadus
 * 641 at level 40): fill the entry record, create the Pokemon into the box,
 * and mark the entry. Levers: level and the entry flag assigned the same
 * value in both switch arms (the tail-merged assignments keep them as
 * variables: level spilled to the frame, the flag in r6), species as u32
 * truncated at the call, `entries` declared before `save`.
 */
void MOVE_POKEMON_SpawnEntry(struct GameData *gameData, u8 slot)
{
    struct MovePokemonSave *block;
    struct SaveControl *save;
    struct MovePokemonEntry *entry;
    struct MyStatus *myStatus;
    struct Pokemon *mon;
    u32 species;
    u16 level;
    u32 flag;

    save = GAME_DATA_GetSaveControl(gameData);
    block = MOVE_POKEMON_SAVE_GetBlock(save);
    entry = MOVE_POKEMON_SAVE_GetEntry(block, slot);
    switch (slot) {
    case 0:
        species = 642;
        level = 40;
        flag = 1;
        break;
    case 1:
        species = 641;
        level = 40;
        flag = 1;
        break;
    default:
        return;
    }
    MOVE_POKEMON_SAVE_SetEntryField(entry, 4, species);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 6, level);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 9, flag);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    mon = GFL_HEAP_Alloc(0x8003, POKE_TOOL_GetPartyParamSize(), 1, d_0217293C, 0x12E);
    POKE_TOOL_SetupPartyParamEx(mon, species, level, MYSTATUS_GetId(myStatus), 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 7, 0);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 8, 1);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 2, POKE_TOOL_GetPartyValue(mon, 0xAC, 0));
    MOVE_POKEMON_SAVE_SetEntryField(entry, 3, POKE_TOOL_GetPartyValue(mon, 0, 0));
    MOVE_POKEMON_SAVE_SetEntryField(entry, 10, POKE_TOOL_GetPartyValue(mon, 0x70, 0));
    MOVE_POKEMON_SAVE_SetEntryField(entry, 5, POKE_TOOL_GetPartyValue(mon, 0xA1, 0));
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetBlock(save), mon);
    GFL_HEAP_Free(mon);
    MOVE_POKEMON_MoveToNeighbor(block, (u32)((void *)GAME_DATA_GetSeason(gameData)), slot, 5);
    MOVE_POKEMON_SAVE_SetEntryState(block, slot, 1);
}


/* Spawn every entry that waits to appear (state 2). */
void MOVE_POKEMON_SpawnPendingEntries(struct GameData *gameData)
{
    int i;
    struct MovePokemonSave *block = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    for (i = 0; i < 2; i++) {
        if (MOVE_POKEMON_SAVE_GetEntryState(block, (u8)i) == 2) MOVE_POKEMON_SpawnEntry(gameData, i);
    }
}


/*
 * Battle-result hook: reads species (5), hp (0xA0) and status (0x9D) of the
 * lead party member of the battle setup, looks up the roaming entry for the
 * species (MOVE_POKEMON_FindEntryBySpecies) and either rolls a 30% chance of moving the
 * entries (MOVE_POKEMON_MoveActiveEntries) when there is none, sets one of two states on it
 * for results 1-2 (with hp 0) or 5 (caught), or copies hp and status into it
 * and moves the entries.
 *
 * The local declaration order (mon, species, hp, index, block, status) is
 * load-bearing.
 */
void MOVE_POKEMON_HandleBattleResult(struct GameData *gameData, BattleResultWork *work)
{
    struct Pokemon *mon;
    u16 species;
    u16 hp;
    u32 entryIndex;
    struct MovePokemonSave *block;
    u8 status;
    struct MovePokemonEntry *entry;

    if (work->resultKind1 != 0 || work->resultKind0 != 0) {
        return;
    }
    GAME_DATA_GetPlayerZoneId(GAME_DATA_GetField114(gameData));
    mon = POKEPARTY_GetMember(BTL_SETUP_GetParty(work, 1), 0);
    species = POKE_TOOL_GetPartyValue(mon, 5, 0);
    hp = POKE_TOOL_GetPartyValue(mon, 0xA0, 0);
    status = POKE_TOOL_GetPartyValue(mon, 0x9D, 0);
    block = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    entry = MOVE_POKEMON_FindEntryBySpecies(block, species);
    if (entry == 0) {
        if (GFL_USE_GetRandomBelow(100) < 30) {
            MOVE_POKEMON_MoveActiveEntries(gameData);
        }
        return;
    }
    entryIndex = MOVE_POKEMON_GetEntryIndexBySpecies(species);
    if ((work->battleResult == 1 || work->battleResult == 2) && hp == 0) {
        MOVE_POKEMON_SAVE_InitEntry(entry);
        MOVE_POKEMON_SAVE_SetEntryLocation(block, entryIndex, 0x10);
        MOVE_POKEMON_SAVE_SetEntryState(block, entryIndex, 2);
        return;
    }
    if (work->battleResult == 5) {
        MOVE_POKEMON_SAVE_InitEntry(entry);
        MOVE_POKEMON_SAVE_SetEntryLocation(block, entryIndex, 0x10);
        MOVE_POKEMON_SAVE_SetEntryState(block, entryIndex, 3);
        return;
    }
    MOVE_POKEMON_SAVE_SetEntryField(entry, 5, hp);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 7, status);
    MOVE_POKEMON_MoveActiveEntries(gameData);
}


/* Entry whose current zone is `zoneId`: returns 6 or 7 (the entry index + 6), 0xffff when none. */
int MOVE_POKEMON_FindEntryByZone(struct GameData *gameData, int zoneId)
{
    u8 i;
    struct MovePokemonSave *block;

    block = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    i = 0;
    if (MOVE_POKEMON_SAVE_IsEntryActive(block, 0) != 0 && zoneId == MOVE_POKEMON_GetEntryZoneId(block, i)) {
        return 6;
    }
    i = 1;
    if (MOVE_POKEMON_SAVE_IsEntryActive(block, 1) != 0 && zoneId == MOVE_POKEMON_GetEntryZoneId(block, i)) {
        return 7;
    }
    return 0xffff;
}


/* 1 when any of the two entries is active. */
int MOVE_POKEMON_IsAnyEntryActive(struct GameData *gameData)
{
    struct MovePokemonSave *block;

    block = MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    if (MOVE_POKEMON_SAVE_IsEntryActive(block, 0) != 0 || MOVE_POKEMON_SAVE_IsEntryActive(block, 1) != 0)
        return 1;
    return 0;
}


/* Entry index of a roaming species: Thundurus 0, Tornadus 1, anything else 2. */
int MOVE_POKEMON_GetEntryIndexBySpecies(int species)
{
    switch(species) {
    case 642: return 0;
    case 641: return 1;
    }
    return 2;
}


/*
 * Move entry `slot` to a neighbouring location. Unless the entry is hidden
 * (location 0x10), there is a 20% chance to hide it instead. The candidates
 * are the links of the current area, minus the current location and
 * `excludedLocation`. Lever: slot is u16 in the function and both receiving
 * externs, causing its immediate home reload; the selected byte remains u8.
 */
void MOVE_POKEMON_MoveToNeighbor(struct MovePokemonSave *block, u32 season, u16 slot, int excludedLocation)
{
    const RoamLocationLinks *links;
    int currentLocation;
    u8 candidates[4];
    u8 chosen;
    int candidate;
    int candidateCount;
    int i;

    currentLocation = MOVE_POKEMON_SAVE_GetEntryLocation(block, slot);
    links = &d_021711A8[(u16)TIMEZONE_GetNowTimeZone(season)];
    if (currentLocation != 0x10 && GFL_USE_GetRandomBelow(100) < 20) {
        MOVE_POKEMON_SetEntryLocation(block, slot, 0x10, 0xffff);
        return;
    }
    candidateCount = 0;
    for (i = 0; i < links->count; i++) {
        candidate = links->next[i];
        if (candidate != currentLocation && candidate != excludedLocation) {
            candidates[candidateCount++] = candidate;
        }
    }
    chosen = candidates[GFL_USE_GetRandomBelow(candidateCount)];
    MOVE_POKEMON_SetEntryLocation(block, slot, chosen, chosen > 0x10 ? 0x13f : d_021711C6[chosen]);
}


/* Set the location of an entry and the zone id that goes with it. */
void MOVE_POKEMON_SetEntryLocation(struct MovePokemonSave *block, u32 slot, u8 location, u32 zoneId)
{
    struct MovePokemonEntry *entry = MOVE_POKEMON_SAVE_GetEntry(block, slot);
    MOVE_POKEMON_SAVE_SetEntryLocation(block, slot, location);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 1, zoneId);
}


/* Active entry of `species`, or 0. */
struct MovePokemonEntry *MOVE_POKEMON_FindEntryBySpecies(struct MovePokemonSave *block, int species)
{
    u8 i = 0;
    struct MovePokemonEntry *entry;

    do {
        if (MOVE_POKEMON_SAVE_IsEntryActive(block, i) != 0) {
            entry = MOVE_POKEMON_SAVE_GetEntry(block, i);
            if (species == MOVE_POKEMON_SAVE_GetEntryField(entry, 4))
                return entry;
        }
        i++;
    } while (i < 2);
    return 0;
}


/*
 * Fill the 0x14-byte skill info for the field: zone id, the ov021 handles,
 * and the usable-skill mask from the object kind, the map tests and the
 * save flags. One lever: the u16 for FIELD_GetPlayerAreaZoneId is declared before x
 * (stack order).
 */
void MOVE_POKEMON_InitSkillInfo(struct FieldMap *fieldMap, FieldSkillInfo *out)
{
    VecFx32 pos;
    u16 swimFlag;
    u16 tileX;
    u16 tileY;
    u16 tileZ;
    struct FieldPlayer *player;
    struct MapObject *playerObj;
    void *map;
    u16 objKind;
    u32 playerA;
    u32 playerB;
    u32 playerC;

    MI_CpuFill8(out, 0, sizeof(FieldSkillInfo));
    out->zoneId = FIELDMAP_GetZoneId(fieldMap);
    out->gameSys = FIELDMAP_GetGameSystem(fieldMap);
    out->fieldMap = fieldMap;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    out->playerState = FIELD_PLAYER_GetFormCode(player);
    playerObj = FIELD_PLAYER_SearchFrontMmdl(player);
    out->playerObj = playerObj;
    if (playerObj != 0) {
        objKind = FLDMMDL_GetObjCode(playerObj);
        map = FIELDMAP_GetMmdlSys(fieldMap);
        FLDMMDL_GetPos(playerObj, &pos);
        if (FLDMMDL_IsMovedPosObjCode(objKind) && FLDMMDL_CheckMovedPosAtMapPos(map, &pos) == 0)
            out->usableMask |= 8;
        if (objKind == 0x6C)
            out->usableMask |= 1;
    }
    playerA = FIELD_PLAYER_GetDirDisp(player);
    playerB = FIELD_PLAYER_GetNowAttribute(player);
    playerC = FIELD_PLAYER_GetFrontAttribute(player, playerA);
    if (FIELD_PLAYER_CheckEncountAttr(player, playerB, playerC) == 1)
        out->usableMask |= 2;
    if (FIELD_PLAYER_CheckSurfEntryAttr(player, playerB, playerC) == 1)
        out->usableMask |= 4;
    if (ZONEDATA_IsFlyEnabled(out->zoneId) == 1) {
        out->usableMask |= 0x10;
        out->usableMask |= 0x40;
    }
    if (ZONEDATA_IsWeatherEnabled(out->zoneId) == 1)
        out->usableMask |= 0x80;
    if (FIELD_STATUS_GetMapEffectMask(GAME_DATA_GetMoveModelSys(ICA_ANIME_GetField1C(out->gameSys))) & 1)
        out->usableMask |= 0x20;
    if (FIELD_GetPlayerAreaZoneId(fieldMap, &swimFlag) == 1)
        out->usableMask |= 0x400;
    if (ZONEDATA_IsZoneInTableDFB8(out->zoneId)) {
        FIELD_PLAYER_GetNowGridPos(FIELDMAP_GetFieldPlayer(out->fieldMap), &tileX, &tileY, &tileZ);
        if (ZONEDATA_IsRawZoneF6(out->zoneId) && MOVE_POKEMON_IsInSkillArea(&d_021711EC, tileX, tileZ, 0x113, fieldMap))
            out->usableMask |= 0x20;
        if (ZONEDATA_IsRawZoneF7(out->zoneId) && MOVE_POKEMON_IsInSkillArea(&d_021711F4, tileX, tileZ, 0x112, fieldMap))
            out->usableMask |= 8;
    }
    if (ZONEDATA_IsNormalFieldZone(out->zoneId) == 0) {
        out->usableMask = 0;
    } else {
        out->usableMask |= 0x100;
        out->usableMask |= 0x200;
    }
    if (GAME_DATA_GetIntrudeCount(ICA_ANIME_GetField1C(out->gameSys)) == 1)
        out->usableMask = 0;
}


/* 1 when the skill has no check function (or its check says it is blocked). */
int MOVE_POKEMON_IsSkillBlocked(int skillIndex, FieldSkillInfo *info)
{
    SkillCheckFn check;

    check = MOVE_POKEMON_GetSkillCheckFunc(info, skillIndex);
    if (check == 0) {
        return 1;
    }
    return check(info);
}


/* Fill a skill target (id, variant and object) for the skill events. */
void MOVE_POKEMON_InitSkillTarget(SkillTarget *target, u16 id, u16 variant, u32 targetObj)
{
    target->id = id;
    target->variant = variant;
    target->targetObj = targetObj;
}


/* Start the event of a skill through its table entry; 0 when it has none. */
struct GameEvent *MOVE_POKEMON_CreateSkillEvent(int skillIndex, SkillTarget *target, FieldSkillInfo *info)
{
    SkillEventFn create;

    create = MOVE_POKEMON_GetSkillEventFunc(info, skillIndex);
    if (create == 0) {
        return 0;
    }
    return create(target, info);
}


/* 1 when skill 0 is not usable. */
int MOVE_POKEMON_CheckCut(FieldSkillInfo *info)
{
    int blocked = 0;

    if (MOVE_POKEMON_IsSkillUsable(info, 0) == 0) {
        blocked = 1;
    }
    return blocked;
}


struct GameEvent *MOVE_POKEMON_CreateCutEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_CutEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, info);
    return event;
}


/* Event main of skill 0: script event 0x2715 on the event work. */
int MOVE_POKEMON_CutEventMain(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;

    GAME_DATA_GetEventWork(ICA_ANIME_GetField1C(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = SCRIPT_SYS_ChangeScriptEvent((int)event, 0x2715, 0, 0);
    SCRIPT_WORK_SetParams(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* Skill 1: blocked states 2 and 3 map to 4 and 1, else 1 when not usable. */
int MOVE_POKEMON_CheckFly(FieldSkillInfo *info)
{
    int blocked;

    if (info->playerState == 2) {
        return 4;
    }
    if (info->playerState == 3) {
        return 1;
    }
    blocked = 1;
    if (MOVE_POKEMON_IsSkillUsable(info, 1) != 0) {
        blocked = 0;
    }
    return blocked;
}


struct GameEvent *MOVE_POKEMON_CreateFlyEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_FlyEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, info);
    return event;
}


/*
 * Event main of skill 1: script event 0x2713 on the event work.
 * Interface: 021587B0 returns its final ldr r0,[r4] at 021587DC; the caller
 * consumes that result despite older callers declaring void.
 */
int MOVE_POKEMON_FlyEventMain(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    GAME_DATA_GetEventWork(ICA_ANIME_GetField1C(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = SCRIPT_SYS_ChangeScriptEvent((int)event, 0x2713, 0, 0);
    SCRIPT_WORK_SetParams(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* 1 when skill 2 is not usable. */
int MOVE_POKEMON_CheckSurf(FieldSkillInfo *info)
{
    return MOVE_POKEMON_IsSkillUsable(info, 2) != 0 ? FALSE : TRUE;
}


struct GameEvent *MOVE_POKEMON_CreateSurfEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_SurfEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, info);
    return event;
}


/* Event main of skill 2: script event 0x2717 on the event work. */
int MOVE_POKEMON_SurfEventMain(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    GAME_DATA_GetEventWork(ICA_ANIME_GetField1C(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = SCRIPT_SYS_ChangeScriptEvent((int)event, 0x2717, 0, 0);
    SCRIPT_WORK_SetParams(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* 1 when skill 3 is not usable. */
int MOVE_POKEMON_CheckStrength(FieldSkillInfo *info)
{
    return MOVE_POKEMON_IsSkillUsable(info, 3) != 0 ? FALSE : TRUE;
}


struct GameEvent *MOVE_POKEMON_CreateStrengthEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_StrengthEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, info);
    return event;
}


/* Event main of skill 3: script event 0x2711 on the event work. */
int MOVE_POKEMON_StrengthEventMain(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    GAME_DATA_GetEventWork(ICA_ANIME_GetField1C(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = SCRIPT_SYS_ChangeScriptEvent((int)event, 0x2711, 0, 0);
    SCRIPT_WORK_SetParams(scriptCtl, targetId, 0, 0, 0);
    return 0;
}


/* 1 when skill 8 is not usable. */
int MOVE_POKEMON_IsSkill8Unusable(FieldSkillInfo *info)
{
    return MOVE_POKEMON_IsSkillUsable(info, 8) != 0 ? FALSE : TRUE;
}


/* Create the object of skill 8 from the target id. */
void *MOVE_POKEMON_CreateDiveEvent(SkillTarget *target, FieldSkillInfo *info)
{
    return SWEET_SCENT_CreateEvent(info->gameSys, info->fieldMap, target->id);
}
