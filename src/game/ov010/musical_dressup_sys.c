/*
 * file:     musical_dressup_sys.c
 * unit:     yes
 * function: func_02155478, func_021559E4, func_02155A4C, func_02155A6C, func_02155A8C, func_02155A90, func_02155A94, MUSICAL_EVENT_Create, MUSICAL_EVENT_Main, MUSICAL_EVENT_CreateLocalPerformer, MUSICAL_EVENT_Free, MUSICAL_EVENT_CreateDressupParam, MUSICAL_EVENT_SendLocalPerformer, MUSICAL_EVENT_CreateStage, MUSICAL_EVENT_ScorePerformers, MUSICAL_EVENT_CreateShowRecord, MUSICAL_EVENT_ApplyResults, MUSICAL_EVENT_RollProgramRewards, MUSICAL_EVENT_RunLeaveSequence, MUSICAL_EVENT_RunEnterSequence, MUSICAL_EVENT_SpawnSeatEffect, MUSICAL_EVENT_SpawnExitEffect, MUSICAL_EVENT_ShowMessage, MUSICAL_EVENT_CountNpcSlotsBelow, MUSICAL_EVENT_GetLocalSlot, MUSICAL_EVENT_GetPlayerOfSlot, MUSICAL_EVENT_GetProgramBestCategory, MUSICAL_EVENT_AllocTitleString, MUSICAL_EVENT_GetScoreCapped, MUSICAL_EVENT_GetMaxScore, MUSICAL_EVENT_GetMinScore, MUSICAL_EVENT_GetSlotOfRank, MUSICAL_EVENT_GetBestAppealCategory, MUSICAL_EVENT_GetPortraitClass, MUSICAL_EVENT_SetPlayerNameWord, MUSICAL_EVENT_SetPokemonNameWord, MUSICAL_EVENT_ReceiveShowProgram, MUSICAL_EVENT_CheckNetError, MUSICAL_EVENT_IsAborted, MUSICAL_DRESSUP_SYS_Init, MUSICAL_DRESSUP_SYS_Exit, MUSICAL_DRESSUP_SYS_Main, MUSICAL_DRESSUP_SYS_Create, MUSICAL_DRESSUP_SYS_Delete, MUSICAL_STAGE_SYS_Init, MUSICAL_STAGE_SYS_Exit, MUSICAL_STAGE_SYS_Main, MUSICAL_STAGE_SYS_Create, MUSICAL_STAGE_SYS_Delete, MUSICAL_STAGE_SYS_SetLocalPerformer, MUSICAL_STAGE_SYS_CreateNpcPerformer, MUSICAL_STAGE_SYS_SetRemotePerformer, MUSICAL_STAGE_SYS_SetPerformerProp, MUSICAL_PROGRAM_Create, MUSICAL_PROGRAM_Delete, MUSICAL_PROGRAM_SplitBonus, MUSICAL_PROGRAM_GetCategoryBonus, MUSICAL_PROGRAM_PackBonus, MUSICAL_PROGRAM_UnpackBonus, MUSICAL_PROGRAM_PackPicks, MUSICAL_PROGRAM_UnpackPicks, MUSICAL_PROGRAM_GetBestCategory, MUSICAL_PROGRAM_CreateNpcPerformer, MUSICAL_PROGRAM_GetBaseProgramId, MUSICAL_PROGRAM_GetPropRow, MUSICAL_PROGRAM_GetNpcPortraitClass, MUSICAL_PROGRAM_GetNpcNameId, MUSICAL_PROGRAM_GetCategoryShare, func_0215739C, func_02157450, func_02157650, func_0215765C, func_02157660, func_02157664, func_02157668
 * address:  0x02155478
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
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   GFL_NET_ERR_ShowSimpleScreen  0x0200F83C  thumb
 *   func_0200FA84  0x0200FA84  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   BTL_SETUP_Create  0x02013090  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   BTL_SETUP_SetupCommSingle  0x02013790  thumb
 *   BTL_SETUP_SetupCommDouble  0x020137C0  thumb
 *   BTL_SETUP_SetupCommTriple  0x02013864  thumb
 *   BTL_SETUP_SetupCommRotation  0x02013894  thumb
 *   BTL_SETUP_SetupCommMulti  0x020137F0  thumb
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   BTL_SETUP_SetParty  0x02013128  thumb
 *   BTL_SETUP_AllocRecordBuffer  0x02013980  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   BTL_SETUP_Delete  0x020130B4  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   EVENT_BATTLE_REC_SAVE_Start  0x021550A0  thumb  ov008
 *   MUSICAL_EVENT_BuildParty  0x0215518C  thumb  ov010
 *   MUSICAL_EVENT_TrimAllPartiesToThree  0x02155224  thumb  ov010
 *   MUSICAL_EVENT_UpdateFriendRecords  0x02155244  thumb  ov010
 *   MUSICAL_EVENT_BindParticipantSlots  0x02155328  thumb  ov010
 *   ov008_id       0x00000008  data
 *   ov021_id       0x00000015  data
 *   ov093_id       0x0000005D  data
 *   ov100_id       0x00000064  data
 *   ov101_id       0x00000065  data
 *   ov119_id       0x00000077  data
 *   ov195_id       0x000000C3  data
 *   d_021D3FE8     0x021D3FE8  data  ov021
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   d_021F03C4     0x021F03C4  data  ov093
 *   d_021E75D8     0x021E75D8  data  ov119
 *   d_02172700     0x02172700  data  a1
 *   d_02208C40     0x02208C40  data  ov195
 *   d_021B74AC     0x021B74AC  data  ov101
 *   d_0216FEE0     0x0216FEE0  data
 *   func_020122C0  0x020122C0  thumb
 *   GAME_EVENT_Change  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   GAME_BEACON_SEARCH_SetNamedEvent  0x0216576C  thumb  ov010
 *   func_021F685C  0x021F685C  thumb  ov112
 *   func_021F68BC  0x021F68BC  thumb  ov112
 *   func_021FD904  0x021FD904  thumb  ov132
 *   func_021FC848  0x021FC848  thumb  ov132
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   func_0200A7C8  0x0200A7C8  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   func_0200A81C  0x0200A81C  thumb
 *   func_02005728  0x02005728  thumb
 *   func_021FD908  0x021FD908  thumb  ov132
 *   func_021FD918  0x021FD918  thumb  ov132
 *   func_021FD8D4  0x021FD8D4  thumb  ov132
 *   func_021FD8EC  0x021FD8EC  thumb  ov132
 *   func_021FCE28  0x021FCE28  thumb  ov132
 *   func_021FD83C  0x021FD83C  thumb  ov132
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_02008530  0x02008530  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   func_02030B50  0x02030B50  arm
 *   func_020306F0  0x020306F0  arm
 *   MUSICAL_DRESSUP_SYS_ProcTable     0x02172724  data
 *   MUSICAL_STAGE_SYS_ProcTable     0x02172748  data
 *   d_021F8360     0x021F8360  data
 *   func_021F675C  0x021F675C  thumb
 *   func_021FD938  0x021FD938  thumb  ov132
 *   func_021F6888  0x021F6888  thumb
 *   func_021FD948  0x021FD948  thumb  ov132
 *   func_021FD4F8  0x021FD4F8  thumb  ov132
 *   func_021FD964  0x021FD964  thumb  ov186
 *   func_021F4F14  0x021F4F14  thumb  ov112
 *   func_021F5140  0x021F5140  thumb  ov112
 *   func_021F4F40  0x021F4F40  thumb  ov112
 *   func_0203F4E4  0x0203F4E4  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_0200A5F8  0x0200A5F8  thumb
 *   sMusicalEventFileName  0x02172714  data
 *   func_0200A768  0x0200A768  thumb
 *   func_0200A788  0x0200A788  thumb
 *   func_0200A7C0  0x0200A7C0  thumb
 *   func_0200A800  0x0200A800  thumb
 *   func_0200A7AC  0x0200A7AC  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   NATSUKI_Calc  0x0201B7A0  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_0200A750  0x0200A750  thumb
 *   func_021FD8F8  0x021FD8F8  thumb  ov132
 *   func_0200A644  0x0200A644  thumb
 *   d_0216FF14  0x0216FF14  data
 *   d_0216FF28  0x0216FF28  data
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_StartPopTask  0x02029690  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   FIELD_SOUND_SYSTEM_StartPushTask  0x020295A4  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitSettledTask  0x02029C64  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb  ov020
 *   d_0216FEFC  0x0216FEFC  data
 *   d_0216FEF0  0x0216FEF0  data
 *   d_0216FF08  0x0216FF08  data
 *   SCRIPT_SYS_CreateScriptEventSimple   0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork   0x021589D0  thumb  ov010
 *   MSGDATA_CreateFromMemory  0x02045C44  arm
 *   func_02008550  0x02008550  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_021FCE44  0x021FCE44  thumb  ov132
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201EF14  0x0201EF14  thumb
 *   func_021FD954  0x021FD954  thumb  ov132
 *   func_021FD95C  0x021FD95C  thumb  ov132
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   sMusicalDressupSysFileName  0x02172730  data
 *   ov133_id  0x00000085  data
 *   func_020315D4 0x020315D4 arm
 *   func_021B6100  0x021B6100  thumb ov133
 *   func_021B63BC  0x021B63BC  thumb  ov133
 *   func_021B6294  0x021B6294  thumb ov133
 *   func_021FD52C  0x021FD52C  thumb ov132
 *   ov112_id       0x00000070  data
 *   func_021F8480  0x021F8480  thumb ov132
 *   func_021F879C  0x021F879C  thumb
 *   func_021F8640  0x021F8640  thumb
 *   sMusicalStageSysFileName  0x02172754  data
 *   func_021F67E0  0x021F67E0  thumb  ov112
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0203F0A8  0x0203F0A8  arm
 *   _ull_mul  0x0209C054  arm
 *   sMusicalProgramFileName  0x02172768  data
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   BTL_SETUP_FreeSlots  0x020130DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   BTL_SETUP_ApplyRegulation  0x02013160  thumb
 *   func_02034714  0x02034714  arm
 *   d_0217277C     0x0217277C  data
 */
#include "../arm9/btl_setup_types.h"

/*
 * Types of this file. Three original files share it:
 *  - an IR battle entry sequence (IrcBattleEntryWork, func_02155478 and the
 *    accessors after it, plus the IrcBattleTask at the end),
 *  - the musical show sequence (musical_event.c: MusicalEventWork),
 *  - the musical dress-up, stage and show-program objects.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8;
typedef unsigned long long u64;
typedef volatile u16 vu16;

/* Hardware: POWCNT1 (display power control). */
#define HW_POWER_CONTROL_REG (*(vu16 *)0x04000304)

struct GameEvent;
struct NetHandle;
struct MusicalSave;

/* Save block 0x2A entry, 4 bytes (same object as MusicalProgram in mystery_data.c). */
struct MusicalProgram {
    u8 state;       /* 4 = initial, else the best appeal category of the show */
    u8 hasProp;     /* 1 when the program rewards a prop */
    u16 prop;       /* the rewarded prop */
};

/* ---- IR battle entry sequence ---- */

/* Argument block of the overlay that picks the party and result (work+0x08). */
typedef struct IrcBattlePickArgs {
    u32 reserved[2];        /* 0x00 */
    u32 repeatFlag;         /* 0x08: in/out, 1 = come back from the detail screen */
    u32 selection;          /* 0x0C: out */
    u32 subSelection;       /* 0x10: out */
    void *gameData;         /* 0x14 */
    u32 unused;             /* 0x18 */
    void *partyList;        /* 0x1C */
} IrcBattlePickArgs;

/* Argument block of the detail overlay (0x14 bytes, heap). */
typedef struct IrcBattleDetailArgs {
    void *gameData;         /* 0x00 */
    void *partyList;        /* 0x04 */
    u16 selection;          /* 0x08 */
    u8 reserved0A;          /* 0x0A */
    u8 subSelection;        /* 0x0B */
    u32 enabled;            /* 0x0C */
    u32 reserved10;         /* 0x10 */
} IrcBattleDetailArgs;

/* Argument block of the battle menu overlay (work+0x60). */
typedef struct IrcBattleMenuArgs {
    void *gameData;         /* 0x00 */
    void *ownParty;         /* 0x04 */
    void *linkParties[4];   /* 0x08 */
    u8 teamByNetId[4];      /* 0x18 */
    u32 mode;               /* 0x1C: in/out */
} IrcBattleMenuArgs;

/* Argument block of the battle recorder save event (ov008). */
typedef struct BattleRecSaveArgs {
    struct BattleSetupParam *setup;
    void *slotData;
    u32 flag;
} BattleRecSaveArgs;

/* Work of the IR battle entry event task (0xE8 bytes). */
typedef struct IrcBattleEntryWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    IrcBattlePickArgs pickArgs;         /* 0x08 */
    IrcBattleDetailArgs *detailArgs;    /* 0x28 */
    u8 pad2C[0xC];
    void *ownParty;                     /* 0x38 */
    void *linkParties[4];               /* 0x3C */
    void *saveControl;                  /* 0x4C */
    u32 mode;                           /* 0x50: 1..5 battle kind, 6/7/8/12/13 menu results */
    u32 savedBgm;                       /* 0x54 */
    int partyMode;                      /* 0x58 */
    void *recorderArg;                  /* 0x5C */
    IrcBattleMenuArgs menuArgs;         /* 0x60 */
    u8 pad80[8];
    struct BattleSetupParam *setup;     /* 0x88 */
    u8 recorderSlots[0x40];             /* 0x8C */
    u32 reservedCC;                     /* 0xCC */
    u32 ruleCategory;                   /* 0xD0 */
    u32 ruleBase;                       /* 0xD4 */
    u32 ruleOffset;                     /* 0xD8 */
    u32 reservedDC;                     /* 0xDC */
    void *trainerRecord;                /* 0xE0 */
    u32 waitFrames;                     /* 0xE4 */
} IrcBattleEntryWork;

/* Event task of the IR battle entry as the event system sees it. */
typedef struct IrcBattleEventTask {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    u8 pad08[0x30];
    void *ownParty;                     /* 0x38 */
    void *linkParties[4];               /* 0x3C */
    void *saveControl;                  /* 0x4C */
} IrcBattleEventTask;

/* Slot description handed to the battle recorder (0x50 bytes). */
typedef struct IrcBattleSlotInfo {
    u8 data[0x48];
    int formation;                      /* 0x48 */
    int flag;                           /* 0x4C */
} IrcBattleSlotInfo;

typedef struct IrcBattleRequest {
    void *party;                        /* 0x00 */
    u8 pad04[0xC];
    u16 bgmBattle;                      /* 0x10 */
    u8 multiTeam;                       /* 0x12 */
    u8 pad13;
    void *regulation;                   /* 0x14 */
    IrcBattleSlotInfo slot;             /* 0x18 */
} IrcBattleRequest;

/* Work of the IR battle task (0xFC bytes). */
typedef struct IrcBattleTaskWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    struct BattleSetupParam setup;      /* 0x08 */
    IrcBattleSlotInfo *slot;            /* 0xF8 */
} IrcBattleTaskWork;

/* ---- musical ---- */

/* One equipped prop of a performer, indexed by body slot. */
typedef struct MusicalEquip {
    u16 propId;                         /* 0xFF = none */
    s16 offset;
    u8 order;                           /* position in the show record list */
    u8 pad5;
} MusicalEquip;

enum {
    MUSICAL_PERFORMER_LOCAL = 0,
    MUSICAL_PERFORMER_REMOTE = 1,
    MUSICAL_PERFORMER_NPC = 2
};

#define MUSICAL_EQUIP_SLOTS 9
#define MUSICAL_APPEAL_KINDS 4
#define MUSICAL_PERFORMERS 4

typedef struct MusicalPerformer {
    u32 origin;                         /* 0x00: MUSICAL_PERFORMER_* */
    u8 pad04[4];
    u16 monsNo;                         /* 0x08 */
    u8 gender;                          /* 0x0A */
    u8 form;                            /* 0x0B */
    u8 shiny;                           /* 0x0C */
    u8 pad0D[3];
    u32 personality;                    /* 0x10 */
    MusicalEquip equips[MUSICAL_EQUIP_SLOTS]; /* 0x14 */
    u16 totalScore;                     /* 0x4A */
    u16 appealScore[MUSICAL_APPEAL_KINDS]; /* 0x4C */
    u32 equipUsed[MUSICAL_EQUIP_SLOTS]; /* 0x54 */
    u16 appealBase;                     /* 0x78 */
} MusicalPerformer;

/* The four performers of one show, plus what created them. */
typedef struct MusicalStage {
    void *session;                      /* 0x00 */
    MusicalPerformer *performers[MUSICAL_PERFORMERS]; /* 0x04 */
    struct MusicalShowProgram *program; /* 0x14 */
    void *musicalSystem;                /* 0x18 */
    u8 pad1C[4];
} MusicalStage;

/* A show program of the musical system table (0x2C bytes). */
typedef struct MusicalProgramEntry {
    u8 id;                              /* 0x00 */
    u8 bonus[MUSICAL_APPEAL_KINDS];     /* 0x01 */
    u8 bonusTotal;                      /* 0x05 */
    u8 propRow;                         /* 0x06 */
    u8 pad07[0x14 - 0x07];
    u16 levelRequired;                  /* 0x14 */
    u8 pad16[0x2C - 0x16];
} MusicalProgramEntry;

/* Head of the ov112 musical system object. */
typedef struct MusicalSystemHead {
    u32 reserved00;                     /* 0x00 */
    MusicalProgramEntry *programs;      /* 0x04 */
    const void *msgFile;                /* 0x08 */
} MusicalSystemHead;

/* One prop slot of an NPC template. */
typedef struct MusicalRivalProp {
    u16 propId;                         /* 0x1FE, 0x1FF = none */
    u8 bodySlot;
    u8 pad03;
} MusicalRivalProp;

/* An NPC performer template (0x2C bytes, in the table behind the program). */
typedef struct MusicalRivalEntry {
    u16 monsNo;                         /* 0x00 */
    u8 personality[4];                  /* 0x02 */
    u16 appealBase;                     /* 0x06 */
    u8 pad08[4];
    MusicalRivalProp props[8];          /* 0x0C */
} MusicalRivalEntry;

typedef struct MusicalRivalTable {
    u8 pad00[0x0C];
    MusicalRivalEntry entries[1];       /* 0x0C */
} MusicalRivalTable;

/* NPC bytes read by the accessors (same 0x2C-byte records). */
typedef struct MusicalNpcInfo {
    u8 pad00[0x0E];
    u8 portraitClass;                   /* 0x0E */
    u8 nameId;                          /* 0x0F */
    u8 pad10[0x1C];
} MusicalNpcInfo;

/*
 * The random show program: the appeal bonus to split, the share per prop,
 * the three NPC picks, and the table the picks index. The table is read in
 * three layouts by different functions, hence the union.
 */
typedef struct MusicalShowProgram {
    u8 categoryBonus[MUSICAL_APPEAL_KINDS]; /* 0x00 */
    u8 sharePerProp[MUSICAL_APPEAL_KINDS];  /* 0x04 */
    u8 picks[4];                        /* 0x08: three used */
    union {
        MusicalProgramEntry *programs;
        MusicalRivalTable *rivals;
        MusicalNpcInfo *npcInfo;
    } catalog;                          /* 0x0C */
} MusicalShowProgram;

typedef struct MusicalShowEquip {
    u16 propId;                         /* 0xFF = none */
    s16 offset;
    u8 bodySlot;                        /* 10 = none */
    u8 pad[3];
} MusicalShowEquip;

typedef struct MusicalShowPerformer {
    u16 monsNo;
    u16 gender : 2;
    u16 shiny : 1;
    u16 form : 5;
    u32 personality;
    u8 name[0x10];
    MusicalShowEquip props[8];
} MusicalShowPerformer;

/* The record of one show, stored in the musical save (0x1B0 bytes). */
typedef struct MusicalShowRecord {
    u32 programId : 5;
    u32 winnerMask : 4;
    u32 year : 7;
    u32 month : 5;
    u32 day : 6;
    u32 localSlot : 2;
    u32 reserved : 3;
    MusicalShowPerformer performers[MUSICAL_PERFORMERS];
    u16 title[0x25];
    u8 showType;
    u8 valid;
} MusicalShowRecord;

/* What the show screen reads (0x14 bytes, heap). */
typedef struct MusicalShowResult {
    u32 ready;                          /* 0x00 */
    u32 state;                          /* 0x04 */
    MusicalShowRecord *record;          /* 0x08 */
    struct MusicalSave *save;           /* 0x0C */
    void *session;                      /* 0x10 */
} MusicalShowResult;

/* Parameter block of the dress-up proc (12 bytes, heap). */
typedef struct MusicalDressupParam {
    void *session;                      /* 0x00 */
    MusicalPerformer *performer;        /* 0x04 */
    struct MusicalSave *save;           /* 0x08 */
} MusicalDressupParam;

/* Work of the dress-up proc. */
typedef struct MusicalDressupWork {
    u32 *paramCopy;                     /* 0x00 */
    void *ui;                           /* 0x04 */
    int result;                         /* 0x08 */
    MusicalDressupParam *param;         /* 0x0C */
} MusicalDressupWork;

/* Work of the stage proc. */
typedef struct MusicalStageWork {
    MusicalStage *stage;
    void *ui;
    u32 unused;
} MusicalStageWork;

/* Session back pointer used by the link sequence. */
typedef struct MusicalLink {
    struct MusicalEventWork *owner;     /* 0x00 */
    void *session;                      /* 0x04 */
} MusicalLink;

/* Work of the musical show event task (0x54 bytes). */
typedef struct MusicalEventWork {
    void *gameSys;                      /* 0x00 */
    void *gameData;                     /* 0x04 */
    MusicalLink *link;                  /* 0x08 */
    u32 state;                          /* 0x0C */
    u8 step;                            /* 0x10: sub-step of the fade sequences */
    u8 pad11[3];
    u32 linkMode;                       /* 0x14: 1 = wireless session */
    void *ownMon;                       /* 0x18 */
    void *saveControl;                  /* 0x1C */
    void *gameComm;                     /* 0x20 */
    MusicalSystemHead *musicalSystem;   /* 0x24 */
    void *session;                      /* 0x28 */
    MusicalDressupParam *dressup;       /* 0x2C */
    MusicalStage *stage;                /* 0x30 */
    MusicalShowResult *result;          /* 0x34 */
    MusicalShowProgram *program;        /* 0x38 */
    MusicalPerformer *localPerformer;   /* 0x3C */
    struct MusicalSave *save;           /* 0x40 */
    u8 playerSlot[4];                   /* 0x44: stage slot of each player */
    u8 rankOrder[4];                    /* 0x48: stage slot of each rank */
    u8 localSlot;                       /* 0x4C */
    u8 pad4D[3];
    u32 aborted;                        /* 0x50 */
} MusicalEventWork;

enum {
    MUSICAL_EVENT_STATE_ENTER_CLOSE = 0,
    MUSICAL_EVENT_STATE_ENTER_DONE = 1,
    MUSICAL_EVENT_STATE_FINISH = 2,
    MUSICAL_EVENT_STATE_START_DRESSUP = 3,
    MUSICAL_EVENT_STATE_WAIT_DRESSUP = 4,
    MUSICAL_EVENT_STATE_START_STAGE = 5,
    MUSICAL_EVENT_STATE_WAIT_STAGE = 6,
    MUSICAL_EVENT_STATE_START_SHOW = 7,
    MUSICAL_EVENT_STATE_WAIT_SHOW = 8,
    MUSICAL_EVENT_STATE_THANKS = 9,
    MUSICAL_EVENT_STATE_END = 10,
    MUSICAL_EVENT_STATE_LINK_WAIT_PEERS = 11,
    MUSICAL_EVENT_STATE_LINK_WAIT_START = 12,
    MUSICAL_EVENT_STATE_SPAWN_MARKER = 13,
    MUSICAL_EVENT_STATE_CREATE_PERFORMER = 14,
    MUSICAL_EVENT_STATE_LEAVE_DRESSUP = 16,
    MUSICAL_EVENT_STATE_MESSAGE_STAGE = 17,
    MUSICAL_EVENT_STATE_ENTER_STAGE = 18,
    MUSICAL_EVENT_STATE_LEAVE_SHOW = 19,
    MUSICAL_EVENT_STATE_MESSAGE_SHOW = 20,
    MUSICAL_EVENT_STATE_ABORT_LEAVE = 22,
    MUSICAL_EVENT_STATE_ABORT_NET = 23,
    MUSICAL_EVENT_STATE_ABORT_CLEANUP = 24,
    MUSICAL_EVENT_STATE_ABORT_WAIT = 25,
    MUSICAL_EVENT_STATE_ABORT_MESSAGE = 26
};

typedef struct Float3 {
    u32 x;
    u32 y;
    u32 z;
} Float3;

typedef struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RtcDate;

typedef struct Tbl4 { u32 v[4]; } Tbl4;

/* Callees outside this file (named tree-wide by the integrator's rename map). */
extern void *GAMESYSTEM_GetFieldMap(void *gameSys);
extern void GAME_EVENT_CallEvent(void *parentEvent, void *childEvent);
extern void *FIELD_STATUS_CreateFieldCloseEvent(void *gameSys, void *fieldMap);
extern void GAMESYSTEM_CallProc(void *gameSys, u32 overlayId, void *procTable, void *procArg);
extern u32 GAMESYSTEM_GetProcStatus(void *gameSys);
extern void *GAMESYSTEM_GetGameData(void *gameSys);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(s32 overlayId);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern struct NetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct NetHandle *handle, u32 timing, u32 range);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct NetHandle *handle, u32 timing, u32 range);
extern u32 func_0200FB24(void);
extern u32 func_0200FBB0(void);
extern void GFL_NET_ERR_ShowSimpleScreen(void);
extern void func_0200FA84(void);
extern void func_0200FBA0(void);
extern struct BattleSetupParam *BTL_SETUP_Create(u32 heapId);
extern void *GAME_DATA_GetTrainerRecord(void *gameData);
extern void BTL_SETUP_SetupCommSingle(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);
extern void BTL_SETUP_SetupCommDouble(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);
extern void BTL_SETUP_SetupCommTriple(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);
extern void BTL_SETUP_SetupCommRotation(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u16 heapId);
extern void BTL_SETUP_SetupCommMulti(struct BattleSetupParam *setup, void *gameData, struct NetHandle *handle, u32 a, u8 team, u16 heapId);
extern u32 GFL_NET_GetHandleNetID(struct NetHandle *handle);
extern void BTL_SETUP_SetParty(struct BattleSetupParam *setup, void *party, int index);
extern void BTL_SETUP_AllocRecordBuffer(struct BattleSetupParam *setup, u32 flag);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u16 fadeFrames);
extern int BTL_SETUP_Delete(struct BattleSetupParam *setup);
extern u32 GFL_NET_IsParentAid(void);
extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(void *gameSys, u32 overlayId, void *proc, void *procArg);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern u32 func_020307B0(void *ptr);
extern int GFL_NET_GetRunState(void);
extern int GFL_NET_Exit(int a0);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *gameSys);
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(void *gameSys, void *fieldMap, int sel, int d);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(void *gameSys, void *fieldMap, int sel, int d, int e, u8 f, u8 g);
extern void *EVENT_BATTLE_REC_SAVE_Start(void *a, const int *p);
extern void MUSICAL_EVENT_BuildParty(int mode, IrcBattleEntryWork *work);
extern void MUSICAL_EVENT_TrimAllPartiesToThree(IrcBattleEntryWork *work);
extern void MUSICAL_EVENT_UpdateFriendRecords(IrcBattleEntryWork *work, void *gameData);
extern void MUSICAL_EVENT_BindParticipantSlots(IrcBattleEntryWork *work, void *gameSys);
extern struct GameEvent *func_020122C0(void *gameSys, void *a, void *proc, u32 size);
extern void GAME_EVENT_Change(void *event, void *proc, u32 size);
extern void *func_020124E8(struct GameEvent *event);
extern void *GAME_DATA_GetSaveControl(void *gameData);
extern void *POKEPARTY_Create(u32 heapId);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *GAMESYSTEM_GetGameComm(void *gameSys);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void *GAME_DATA_GetMyParty(void *gameData);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, void *value);
extern void GAME_BEACON_SEARCH_SetNamedEvent(void *strbuf);
extern void STRBUF_Delete(void *strbuf);
extern void *GAME_DATA_GetSaveBlock2A(void *gameData);
extern void *func_021F685C(u32 heapId);
extern int func_021FD904(void *session);
extern u8 func_0200A7C8(struct MusicalSave *save);
extern void func_021F68BC(void *musicalSystem, void *saveControl, void *session, u8 kind, u16 heapId);
extern void *GAME_DATA_GetMyStatus(void *gameData);
extern void *POKE_TOOL_Dummy(void *mon);
extern void func_021FC848(void *session, void *myStatus, void *monData, void *gameComm, void *musicalSystem, u16 heapId);
extern u16 func_0200A81C(struct MusicalSave *save);
extern u32 func_02005728(u32 n);
extern u32 func_021FD908(void *session);
extern void func_021FD918(void *session, u32 lo, u32 hi);
extern u32 func_021FD8D4(void *session);
extern u8 func_021FD8EC(void *session, int index);
extern void *func_021FCE28(void *session, u32 index);
extern u32 func_021FD83C(void *session);
extern void *func_0200ED48(void *saveControl);
extern void func_0200ED54(void *list, u32 id);
extern u32 func_02008530(const void *myStatus);
extern void GFL_NET_ERR_RequestScreen(void);
extern void func_02030B50(void *p);
extern void func_020306F0(u32 heapId);
extern void *func_021F675C(void *mon, int heapId);
extern void func_021FD938(void *session);
extern int func_021F6888(void *musicalSystem);
extern void func_021FD948(void *session, void *performer);
extern MusicalPerformer *func_021FD4F8(void *session, u8 slot);
extern u32 func_021FD964(void *session, u32 player, u32 index);
extern void *func_021F4F14(int heapId);
extern unsigned char func_021F5140(void *table, int propId);
extern void func_021F4F40(void **table);
extern void func_0203F4E4(RtcDate *date);
extern void STRBUF_ToChars(void *strbuf, u16 *out, u32 n);
extern void MI_CpuCopy8(void *src, void *dst, u32 size);
extern void *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(void *msgData, u32 index);
extern void MSGDATA_Delete(void *msgData);
extern void *func_0200A5F8(void *saveControl);
extern void func_0200A768(struct MusicalSave *save);
extern void func_0200A788(struct MusicalSave *save);
extern void func_0200A7C0(struct MusicalSave *save, u8 value);
extern void func_0200A800(struct MusicalSave *save, s32 delta);
extern void func_0200A7AC(struct MusicalSave *save, u32 index, u8 value);
extern u16 *GAME_DATA_GetMyPlayerWork(void *gameData);
extern void NATSUKI_Calc(void *mon, int a1, int a2, int a3);
extern u32 func_02008DF0(void *trainerRecord, int id);
extern u32 func_02008DAC(void *trainerRecord, int id, u32 delta);
extern struct MusicalProgram *func_0200A750(struct MusicalSave *save, u32 index);
extern u16 *func_021FD8F8(void *session, u32 index);
extern u32 func_0200A644(struct MusicalSave *save, u8 prop);
extern void *GAME_DATA_GetBgmInfo(void *gameData);
extern void *FIELD_SOUND_SYSTEM_StartPopTask(void *gameSys, u32 a, u32 b);
extern void *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(void *gameSys);
extern void *FIELD_SOUND_SYSTEM_StartPushTask(void *gameSys, u32 a);
extern void *FIELD_SOUND_SYSTEM_StartWaitSettledTask(void *gameSys);
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(void *gameSys, void *fieldMap, s16 effectId, const Float3 *pos, u16 x);
extern struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *gameSys, int messageId, int c, int d);
extern int SCRIPT_SYS_GetEventScriptWork(void *event);
extern void *MSGDATA_CreateFromMemory(const void *file, u32 heapId);
extern u8 func_02008550(const void *myStatus);
extern void func_0201F02C(void *wordSet, u32 slot, void *myStatus);
extern void func_0201EE0C(void *wordSet, u32 slot, const void *str, u32 n, u32 f, u32 c);
extern void *func_021FCE44(void *session, u32 index);
extern void func_0201EEF4(void *wordSet, u32 slot, void *mon);
extern void func_0201EF14(void *wordSet, u32 slot, void *mon);
extern u32 func_021FD954(void *session);
extern u32 func_021FD95C(void *session);
extern void *PROCSYS_AllocProcWork(void *proc, u32 size, u32 heapId);
extern void func_020315D4(void *proc);
extern void *func_021B6100(void *param, int heapId);
extern int func_021B63BC(void *ui);
extern void func_021B6294(void *ui);
extern void func_021FD52C(void *session);
extern void *func_021F8480(void *input, int heapId);
extern int func_021F879C(void *ui);
extern void func_021F8640(void *ui);
extern MusicalPerformer *func_021F67E0(u16 monsNo, u8 form, u8 c, u8 d, u32 personality, u16 heapId);
extern u32 func_0203F0A8(void);
extern int _s32_div_f(int dividend, int divisor);
extern void *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(void *gameSys, u32 b);
extern void BTL_SETUP_FreeSlots(struct BattleSetupParam *setup);
extern void *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(void *gameSys);
extern void BTL_SETUP_ApplyRegulation(struct BattleSetupParam *setup, void *regulation, u32 heapId);
extern void func_02034714(const char *expr, u32 line, const char *file);

/* Overlay ids (absolute linker symbols) and data of other overlays. */
extern u8 ov008_id[];
extern u8 ov021_id[];
extern u8 ov093_id[];
extern u8 ov100_id[];
extern u8 ov101_id[];
extern u8 ov119_id[];
extern u8 ov195_id[];
extern u8 ov112_id[];
extern char ov133_id[];
extern u8 d_021D3FE8[];
extern u8 d_021BB6A4[];
extern u8 d_021F03C4[];
extern u8 d_021E75D8[];
extern u8 d_02208C40[];
extern u8 d_021B74AC[];
extern u8 d_021F8360[];

/* Data of this overlay. */
extern const char d_02172700[];
extern const char sMusicalEventFileName[];
extern const char sMusicalDressupSysFileName[];
extern const char sMusicalStageSysFileName[];
extern const char sMusicalProgramFileName[];
extern const Tbl4 d_0216FEE0;
extern u8 MUSICAL_DRESSUP_SYS_ProcTable[];
extern u8 MUSICAL_STAGE_SYS_ProcTable[];
extern const u16 d_0216FF14[10];
extern const u8 d_0216FF28[7][0x28];
extern const Float3 d_0216FEFC;
extern const Float3 d_0216FEF0;
extern const Float3 d_0216FF08;
extern u8 d_0217277C[];

/* Functions of this file. */
int func_02155478(void *parentEvent, int *step, IrcBattleEntryWork *work);
struct GameEvent *func_021559E4(void *gameSys, int unused, struct GameEvent *event, int create);
void func_02155A4C(IrcBattleEntryWork *work);
void func_02155A6C(IrcBattleEntryWork *work);
void func_02155A8C(IrcBattleEntryWork *work, u32 mode);
void *func_02155A90(IrcBattleEntryWork *work);
void *func_02155A94(IrcBattleEntryWork *work);
struct GameEvent *MUSICAL_EVENT_Create(void *gameSys, void *gameData, u8 partyIndex, u32 linkMode, MusicalLink *link);
int MUSICAL_EVENT_Main(void *event, void *unused, MusicalEventWork *work);
void MUSICAL_EVENT_CreateLocalPerformer(MusicalEventWork *work);
int MUSICAL_EVENT_Free(MusicalEventWork *work);
MusicalDressupParam *MUSICAL_EVENT_CreateDressupParam(MusicalEventWork *work);
void MUSICAL_EVENT_SendLocalPerformer(MusicalEventWork *work);
void MUSICAL_EVENT_CreateStage(MusicalEventWork *work);
void MUSICAL_EVENT_ScorePerformers(MusicalEventWork *work);
void MUSICAL_EVENT_CreateShowRecord(MusicalEventWork *work);
void MUSICAL_EVENT_ApplyResults(MusicalEventWork *work);
void MUSICAL_EVENT_RollProgramRewards(MusicalEventWork *work);
int MUSICAL_EVENT_RunLeaveSequence(void *event, MusicalEventWork *work);
int MUSICAL_EVENT_RunEnterSequence(void *event, MusicalEventWork *work);
void MUSICAL_EVENT_SpawnSeatEffect(void *event, MusicalEventWork *work);
void MUSICAL_EVENT_SpawnExitEffect(void *event, MusicalEventWork *work);
void MUSICAL_EVENT_ShowMessage(void *event, MusicalEventWork *work, int messageId);
u8 MUSICAL_EVENT_CountNpcSlotsBelow(MusicalEventWork *work, u8 n);
u8 MUSICAL_EVENT_GetLocalSlot(MusicalEventWork *work);
u8 MUSICAL_EVENT_GetPlayerOfSlot(MusicalEventWork *work, u8 slot);
u8 MUSICAL_EVENT_GetProgramBestCategory(MusicalEventWork *work);
void *MUSICAL_EVENT_AllocTitleString(MusicalEventWork *work, int heapId);
u8 MUSICAL_EVENT_GetScoreCapped(MusicalEventWork *work, u8 slot);
u16 MUSICAL_EVENT_GetMaxScore(MusicalEventWork *work);
u16 MUSICAL_EVENT_GetMinScore(MusicalEventWork *work);
u8 MUSICAL_EVENT_GetSlotOfRank(MusicalEventWork *work, u8 rank);
u8 MUSICAL_EVENT_GetBestAppealCategory(MusicalEventWork *work, u8 slot);
u8 MUSICAL_EVENT_GetPortraitClass(MusicalEventWork *work, u8 slot);
void MUSICAL_EVENT_SetPlayerNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex);
void MUSICAL_EVENT_SetPokemonNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex);
void MUSICAL_EVENT_ReceiveShowProgram(MusicalEventWork *work);
void MUSICAL_EVENT_CheckNetError(MusicalEventWork *work);
u32 MUSICAL_EVENT_IsAborted(MusicalEventWork *work);
int MUSICAL_DRESSUP_SYS_Init(void *proc, u32 *state, MusicalDressupParam *param);
int MUSICAL_DRESSUP_SYS_Exit(void *proc, int unused1, int unused2, MusicalDressupWork *work);
int MUSICAL_DRESSUP_SYS_Main(void *proc, int *state, int unused, MusicalDressupWork *work);
MusicalDressupParam *MUSICAL_DRESSUP_SYS_Create(int heapId, MusicalPerformer *performer, void *saveControl);
void MUSICAL_DRESSUP_SYS_Delete(MusicalDressupParam *param);
int MUSICAL_STAGE_SYS_Init(void *proc, void *unused, MusicalStage *prevStage);
int MUSICAL_STAGE_SYS_Exit(void *proc, int unused, int keepStage, MusicalStageWork *work);
int MUSICAL_STAGE_SYS_Main(void *proc, int *state, int unused, MusicalStageWork *work);
MusicalStage *MUSICAL_STAGE_SYS_Create(u32 heapId, void *session);
int MUSICAL_STAGE_SYS_Delete(MusicalStage *stage);
int MUSICAL_STAGE_SYS_SetLocalPerformer(MusicalStage *stage, int slot, MusicalPerformer *performer);
void MUSICAL_STAGE_SYS_CreateNpcPerformer(MusicalStage *stage, u8 slot, u16 monsNo, u8 form, u32 personality, u16 appealBase, u16 heapId);
int MUSICAL_STAGE_SYS_SetRemotePerformer(MusicalStage *stage, int slot, MusicalPerformer *performer);
void MUSICAL_STAGE_SYS_SetPerformerProp(MusicalStage *stage, u8 slot, u8 bodySlot, u16 propId, s16 offset, u8 order);
MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel);
int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program);
void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage);
u8 MUSICAL_PROGRAM_GetCategoryBonus(MusicalShowProgram *program, int index);
u32 MUSICAL_PROGRAM_PackBonus(const MusicalShowProgram *program);
void MUSICAL_PROGRAM_UnpackBonus(MusicalShowProgram *program, u32 packed);
u32 MUSICAL_PROGRAM_PackPicks(const MusicalShowProgram *program);
void MUSICAL_PROGRAM_UnpackPicks(MusicalShowProgram *program, u32 packed);
u8 MUSICAL_PROGRAM_GetBestCategory(MusicalShowProgram *program);
void MUSICAL_PROGRAM_CreateNpcPerformer(MusicalShowProgram *program, MusicalStage *stage, u8 slot, u8 npcIndex, u16 heapId);
u8 MUSICAL_PROGRAM_GetBaseProgramId(MusicalShowProgram *program);
int MUSICAL_PROGRAM_GetPropRow(MusicalShowProgram *program);
u8 MUSICAL_PROGRAM_GetNpcPortraitClass(MusicalShowProgram *program, u8 npcIndex);
u8 MUSICAL_PROGRAM_GetNpcNameId(MusicalShowProgram *program, int npcIndex);
u16 MUSICAL_PROGRAM_GetCategoryShare(MusicalShowProgram *program, int category);
int func_0215739C(void *event, u32 *state, IrcBattleTaskWork *work);
struct GameEvent *func_02157450(void *gameSys, void *gameData, u32 kind, IrcBattleRequest *request);
void func_02157650(int *formation, int value);
void func_0215765C(void);
void func_02157660(void);
void func_02157664(void);
void func_02157668(void);


/*
 * The IR battle entry sequence: a 28-state machine over *step that loads the
 * sub-overlays (21, 100, 119, 195, 101, 8, 93) as child procs, sets up the
 * party/slot records through MUSICAL_EVENT_BuildParty/MUSICAL_EVENT_BindParticipantSlots/MUSICAL_EVENT_UpdateFriendRecords,
 * runs the fade and wireless-sync waits, and tears everything down in
 * states 21 to 23.
 *
 * Shape levers that closed it (they also settled the work/step register
 * swap): case 18 writes the waitFrames = 0 / (*step)++ tail in both arms;
 * case 19 writes (*step)++ in both arms; state 10 writes the
 * GFL_USE_CancelChangeAndPlayBgm call in each arm.
 */
int func_02155478(void *parentEvent, int *step, IrcBattleEntryWork *work)
{
    Tbl4 ruleTable;
    BattleRecSaveArgs recArgs;
    void *gameSys;
    void *fieldMap;
    IrcBattleDetailArgs *detail;

    gameSys = work->gameSys;
    fieldMap = GAMESYSTEM_GetFieldMap(gameSys);
    switch (*step) {
    case 0:
        GAME_EVENT_CallEvent(parentEvent, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSys, fieldMap, 0, 0));
        (*step)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(parentEvent, FIELD_STATUS_CreateFieldCloseEvent(gameSys, fieldMap));
        *step = 2;
        break;
    case 2:
        GAMESYSTEM_CallProc(gameSys, (u32)ov021_id, d_021D3FE8, work);
        (*step)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            if (work->mode == 8) {
                *step = 24;
            } else if (work->mode == 12) {
                *step = 21;
            } else {
                (*step)++;
            }
        }
        break;
    case 4:
        (*step)++;
        break;
    case 5:
        MUSICAL_EVENT_BuildParty(work->partyMode, work);
        work->menuArgs.gameData = work->gameData;
        work->menuArgs.ownParty = work->ownParty;
        work->menuArgs.linkParties[0] = work->linkParties[0];
        work->menuArgs.linkParties[1] = work->linkParties[1];
        work->menuArgs.linkParties[2] = work->linkParties[2];
        work->menuArgs.linkParties[3] = work->linkParties[3];
        work->menuArgs.mode = work->mode;
        GAMESYSTEM_CallProc(gameSys, (u32)ov100_id, d_021BB6A4, &work->menuArgs);
        (*step)++;
        break;
    case 6:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            work->mode = work->menuArgs.mode;
            switch (work->mode) {
            case 7:
                *step = 20;
                break;
            case 12:
                *step = 20;
                break;
            case 13:
                *step = 2;
                break;
            case 6:
                work->pickArgs.repeatFlag = 0;
                *step = 13;
                break;
            default:
                *step = 7;
                break;
            }
        }
        break;
    case 7:
        func_02034AC4((u32)ov093_id);
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x6e, 12);
        (*step)++;
        break;
    case 8:
        if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0x6e, 12))
            (*step)++;
        if (func_0200FB24()) {
            if (func_0200FBB0() == 1)
                GFL_NET_ERR_ShowSimpleScreen();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *step = 20;
        }
        break;
    case 9:
        work->setup = BTL_SETUP_Create(4);
        work->trainerRecord = GAME_DATA_GetTrainerRecord(work->gameData);
        work->ruleOffset = 0;
        switch (work->mode) {
        case 0:
            break;
        case 1:
            work->ruleCategory = 1;
            work->ruleBase = 2;
            BTL_SETUP_SetupCommSingle(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 2:
            work->ruleCategory = 1;
            work->ruleBase = 6;
            BTL_SETUP_SetupCommDouble(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 3:
            work->ruleCategory = 1;
            work->ruleBase = 10;
            BTL_SETUP_SetupCommTriple(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 4:
            work->ruleCategory = 1;
            work->ruleBase = 14;
            BTL_SETUP_SetupCommRotation(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
            break;
        case 5:
            ruleTable = d_0216FEE0;
            work->ruleCategory = 3;
            work->ruleBase = 18;
            BTL_SETUP_SetupCommMulti(work->setup, work->gameData, GFL_NET_HANDLE_GetCurrentHandle(), 1,
                          ruleTable.v[work->menuArgs.teamByNetId[GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle())]], 4);
            work->setup->multiMode = 1;
            work->setup->rule = 1;
            MUSICAL_EVENT_TrimAllPartiesToThree(work);
            break;
        }
        BTL_SETUP_SetParty(work->setup, work->ownParty, 0);
        BTL_SETUP_AllocRecordBuffer(work->setup, 1);
        work->savedBgm = GFL_USE_GetBgmNo();
        GFL_USE_CancelChangeAndStopBgm();
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 10, 12);
        (*step)++;
        break;
    case 10:
        if (func_0200FB24()) {
            BTL_SETUP_Delete(work->setup);
            work->setup = 0;
            if (func_0200FBB0() == 1)
                GFL_NET_ERR_ShowSimpleScreen();
            else
                func_0200FA84();
            func_02034A5C((u32)ov093_id);
            *step = 20;
        } else if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 10, 12)) {
            if (GFL_NET_IsParentAid())
                GFL_USE_CancelChangeAndPlayBgm(0x48B, 0xFFFF);
            else
                GFL_USE_CancelChangeAndPlayBgm(0x48C, 0xFFFF);
            (*step)++;
        }
        break;
    case 11:
        MUSICAL_EVENT_BindParticipantSlots(work, gameSys);
        func_02034A5C((u32)ov093_id);
        recArgs.setup = work->setup;
        recArgs.slotData = work->recorderSlots;
        recArgs.flag = 1;
        GAME_EVENT_CallEvent(parentEvent, GAME_EVENT_CreateOverlayEvent(gameSys, (u32)ov008_id, EVENT_BATTLE_REC_SAVE_Start, &recArgs));
        (*step)++;
        break;
    case 12:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            MUSICAL_EVENT_UpdateFriendRecords(work, GAMESYSTEM_GetGameData(gameSys));
            BTL_SETUP_Delete(work->setup);
            work->setup = 0;
            GFL_USE_CancelChangeAndStopBgm();
            func_02155A6C(work);
            *step = 17;
        }
        break;
    case 13:
        work->pickArgs.gameData = work->gameData;
        work->pickArgs.partyList = work->ownParty;
        GAMESYSTEM_CallProc(gameSys, (u32)ov119_id, d_021E75D8, &work->pickArgs);
        (*step)++;
        break;
    case 14:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            if (work->pickArgs.repeatFlag == 1)
                *step = 15;
            else
                *step = 17;
        }
        break;
    case 15:
        detail = func_02030734(4, 0x14, 0, d_02172700, 0x219);
        detail->gameData = work->gameData;
        detail->partyList = work->pickArgs.partyList;
        detail->selection = work->pickArgs.selection;
        detail->reserved0A = 0;
        detail->subSelection = work->pickArgs.subSelection;
        detail->enabled = 1;
        detail->reserved10 = 0;
        work->detailArgs = detail;
        GAMESYSTEM_CallProc(gameSys, (u32)ov195_id, d_02208C40, detail);
        (*step)++;
        break;
    case 16:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            func_020307B0(work->detailArgs);
            work->pickArgs.repeatFlag = 1;
            *step = 13;
        }
        break;
    case 17:
        if (GFL_NET_GetRunState() && func_0200FB24() == 0)
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xdc, 12);
        (*step)++;
        break;
    case 18:
        if (GFL_NET_GetRunState() && func_0200FB24() == 0) {
            if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 0xdc, 12) == 0)
                break;
            work->waitFrames = 0;
            (*step)++;
        } else {
            work->waitFrames = 0;
            (*step)++;
        }
        break;
    case 19:
        if (GFL_NET_GetRunState()) {
            work->waitFrames++;
            if (work->waitFrames < 60)
                break;
            GFL_NET_Exit(0);
            (*step)++;
        } else {
            (*step)++;
        }
        break;
    case 20:
        if (GFL_NET_GetRunState() == 0) {
            func_0200FBA0();
            *step = 21;
        }
        break;
    case 21:
        func_02155A6C(work);
        GAME_EVENT_CallEvent(parentEvent, FIELD_STATUS_CreateFieldOpenEvent(gameSys));
        (*step)++;
        break;
    case 22:
        GAME_EVENT_CallEvent(parentEvent, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSys, fieldMap, 0, 0, 1, 0, 0));
        (*step)++;
        break;
    case 23:
        GFL_NET_IRC_WIRELESS_Exit();
        func_02155A4C(work);
        return 1;
    case 24:
        (*step)++;
        break;
    case 25:
        (*step)++;
        break;
    case 26:
        work->recorderArg = work->gameSys;
        GAMESYSTEM_CallProc(gameSys, (u32)ov101_id, d_021B74AC, &work->recorderArg);
        (*step)++;
        break;
    case 27:
        if (GAMESYSTEM_GetProcStatus(gameSys) == 0) {
            HW_POWER_CONTROL_REG |= 0x8000;
            *step = 20;
        }
        break;
    }
    return 0;
}

/*
 * Creates (create != 0) or retargets the IR battle entry event and fills
 * its work: the five party lists are allocated here and freed by
 * func_02155A4C.
 */
struct GameEvent *func_021559E4(void *gameSys, int unused, struct GameEvent *event, int create)
{
    IrcBattleEventTask *task;
    int i;

    if (create != 0)
        event = func_020122C0(gameSys, 0, func_02155478, 0xE8);
    else
        GAME_EVENT_Change(event, func_02155478, 0xE8);
    task = func_020124E8(event);
    task->saveControl = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSys));
    task->gameData = GAMESYSTEM_GetGameData(gameSys);
    task->gameSys = gameSys;
    for (i = 0; i < 4; i++)
        task->linkParties[i] = POKEPARTY_Create(4);
    task->ownParty = POKEPARTY_Create(4);
    return event;
}

/*
 * Frees the four link party lists and then the own party list.
 */
void func_02155A4C(IrcBattleEntryWork *work)
{
    int i;

    for (i = 0; i < 4; i++)
        func_020307B0(work->linkParties[i]);
    func_020307B0(work->ownParty);
}

/*
 * Stops the saved BGM (if any) and clears it.
 */
void func_02155A6C(IrcBattleEntryWork *work)
{
    if (work->savedBgm != 0) {
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgm, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3c);
        work->savedBgm = 0;
    }
}

/*
 * Stores the mode word.
 */
void func_02155A8C(IrcBattleEntryWork *work, u32 mode)
{
    work->mode = mode;
}

/*
 * Reads the game system pointer.
 */
void *func_02155A90(IrcBattleEntryWork *work)
{
    return work->gameSys;
}

/*
 * Reads the save control pointer.
 */
void *func_02155A94(IrcBattleEntryWork *work)
{
    return work->saveControl;
}

/*
 * Creates the musical show event task (MUSICAL_EVENT_Main over a
 * MusicalEventWork) and either starts the wireless exchange (state 11) or
 * shuffles the four player slots and deals locally (state 13). The owner
 * back-pointer is stored through work->link while the session is read
 * through the parameter: storing through the parameter enregisters it
 * instead.
 */
struct GameEvent *MUSICAL_EVENT_Create(void *gameSys, void *gameData, u8 partyIndex, u32 linkMode, MusicalLink *link)
{
    struct GameEvent *event;
    MusicalEventWork *work;
    void *nickname;

    GFL_HEAP_CreateChildHeap(1, 0x802C, 0x42000);
    event = func_020122C0(gameSys, 0, MUSICAL_EVENT_Main, sizeof(MusicalEventWork));
    work = func_020124E8(event);
    work->gameSys = gameSys;
    work->gameData = gameData;
    work->linkMode = linkMode;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameComm = GAMESYSTEM_GetGameComm(gameSys);
    work->link = link;
    work->link->owner = work;
    work->session = link->session;
    work->aborted = 0;
    work->program = 0;
    nickname = STRBUF_Create(11, 4);
    work->ownMon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(work->gameData), partyIndex);
    POKE_TOOL_GetPartyValue(work->ownMon, 0x73, nickname);
    GAME_BEACON_SEARCH_SetNamedEvent(nickname);
    STRBUF_Delete(nickname);
    work->dressup = 0;
    work->stage = 0;
    work->result = 0;
    work->save = GAME_DATA_GetSaveBlock2A(gameData);
    work->musicalSystem = func_021F685C(4);
    if (work->linkMode == 0 || func_021FD904(work->link->session) == 1)
        func_021F68BC(work->musicalSystem, work->saveControl, work->gameData, func_0200A7C8(work->save), 0x2C);
    if (work->linkMode == 1) {
        work->state = MUSICAL_EVENT_STATE_LINK_WAIT_PEERS;
        work->step = 0;
        func_021FC848(work->session, GAME_DATA_GetMyStatus(work->gameData), POKE_TOOL_Dummy(work->ownMon), work->gameComm, work->musicalSystem, 4);
    } else {
        u16 maxLevel = func_0200A81C(work->save);
        u8 i;
        u8 j;
        u8 k;
        u8 temp;

        for (i = 0; i < 4; i++)
            work->playerSlot[i] = i;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 4; j++) {
                k = func_02005728(4);
                temp = work->playerSlot[j];
                work->playerSlot[j] = work->playerSlot[k];
                work->playerSlot[k] = temp;
            }
        }
        work->localSlot = work->playerSlot[0];
        work->program = MUSICAL_PROGRAM_Create(4, work->musicalSystem, maxLevel);
        work->state = MUSICAL_EVENT_STATE_SPAWN_MARKER;
        work->step = 0;
    }
    return event;
}

/*
 * Task callback of the musical show event: the whole show flow, from the
 * wireless handshake through dress-up, stage, result screen and cleanup.
 */
int MUSICAL_EVENT_Main(void *event, void *unused, MusicalEventWork *work)
{
    MUSICAL_EVENT_CheckNetError(work);
    switch (work->state) {
    case MUSICAL_EVENT_STATE_LINK_WAIT_PEERS:
        if (func_021FD908(work->link->session) == 1) {
            u32 packedBonus = 0;
            u32 packedPicks = 0;
            void *list;
            u8 i;

            if (func_021FD904(work->link->session) == 1) {
                work->program = MUSICAL_PROGRAM_Create(4, work->musicalSystem, func_0200A81C(work->save));
                packedBonus = MUSICAL_PROGRAM_PackBonus(work->program);
                packedPicks = MUSICAL_PROGRAM_PackPicks(work->program);
            }
            func_021FD918(work->link->session, packedBonus, packedPicks);
            work->state = MUSICAL_EVENT_STATE_LINK_WAIT_START;
            list = func_0200ED48(work->saveControl);
            for (i = 0; i < 4; i++) {
                if (func_021FD8D4(work->link->session) != func_021FD8EC(work->link->session, i)) {
                    void *peerStatus = func_021FCE28(work->link->session, i);
                    if (peerStatus != 0)
                        func_0200ED54(list, func_02008530(peerStatus));
                }
            }
        } else if (work->aborted == 1) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        }
        break;
    case MUSICAL_EVENT_STATE_LINK_WAIT_START:
        if (func_021FD83C(work->link->session) == 1) {
            u8 i;

            work->state = MUSICAL_EVENT_STATE_SPAWN_MARKER;
            for (i = 0; i < 4; i++)
                work->playerSlot[i] = func_021FD8EC(work->link->session, i);
            work->localSlot = func_021FD8D4(work->link->session);
            MUSICAL_EVENT_ReceiveShowProgram(work);
        } else if (work->aborted == 1) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        }
        break;
    case MUSICAL_EVENT_STATE_SPAWN_MARKER:
        MUSICAL_EVENT_SpawnSeatEffect(event, work);
        work->state = MUSICAL_EVENT_STATE_CREATE_PERFORMER;
        break;
    case MUSICAL_EVENT_STATE_CREATE_PERFORMER:
        MUSICAL_EVENT_CreateLocalPerformer(work);
        MUSICAL_EVENT_ShowMessage(event, work, 3);
        work->state = MUSICAL_EVENT_STATE_ENTER_CLOSE;
        break;
    case MUSICAL_EVENT_STATE_ENTER_CLOSE:
        if (work->aborted == 1 && work->step == 0) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        } else if (MUSICAL_EVENT_RunEnterSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_ENTER_DONE;
        }
        break;
    case MUSICAL_EVENT_STATE_ENTER_DONE:
        work->state = MUSICAL_EVENT_STATE_START_DRESSUP;
        break;
    case MUSICAL_EVENT_STATE_START_DRESSUP:
        MUSICAL_EVENT_CreateDressupParam(work);
        GAMESYSTEM_CallProc(work->gameSys, ~0u, MUSICAL_DRESSUP_SYS_ProcTable, work->dressup);
        work->state = MUSICAL_EVENT_STATE_WAIT_DRESSUP;
        break;
    case MUSICAL_EVENT_STATE_WAIT_DRESSUP:
        if (GAMESYSTEM_GetProcStatus(work->gameSys) == 0) {
            MUSICAL_EVENT_SendLocalPerformer(work);
            work->state = MUSICAL_EVENT_STATE_LEAVE_DRESSUP;
        }
        break;
    case MUSICAL_EVENT_STATE_LEAVE_DRESSUP:
        if (MUSICAL_EVENT_RunLeaveSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_MESSAGE_STAGE;
            if (work->aborted == 1)
                work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        }
        break;
    case MUSICAL_EVENT_STATE_MESSAGE_STAGE:
        MUSICAL_EVENT_ShowMessage(event, work, 4);
        work->state = MUSICAL_EVENT_STATE_ENTER_STAGE;
        break;
    case MUSICAL_EVENT_STATE_ENTER_STAGE:
        if (work->aborted == 1 && work->step == 0) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        } else if (MUSICAL_EVENT_RunEnterSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_START_STAGE;
        }
        break;
    case MUSICAL_EVENT_STATE_START_STAGE:
        MUSICAL_EVENT_CreateStage(work);
        GAMESYSTEM_CallProc(work->gameSys, ~0u, MUSICAL_STAGE_SYS_ProcTable, work->stage);
        work->state = MUSICAL_EVENT_STATE_WAIT_STAGE;
        break;
    case MUSICAL_EVENT_STATE_WAIT_STAGE:
        if (GAMESYSTEM_GetProcStatus(work->gameSys) == 0) {
            MUSICAL_EVENT_ScorePerformers(work);
            work->state = MUSICAL_EVENT_STATE_START_SHOW;
            if (work->aborted == 1)
                work->state = MUSICAL_EVENT_STATE_ABORT_LEAVE;
        }
        break;
    case MUSICAL_EVENT_STATE_START_SHOW:
        MUSICAL_EVENT_CreateShowRecord(work);
        GAMESYSTEM_CallProc(work->gameSys, ~0u, d_021F8360, work->result);
        work->state = MUSICAL_EVENT_STATE_WAIT_SHOW;
        break;
    case MUSICAL_EVENT_STATE_WAIT_SHOW:
        if (GAMESYSTEM_GetProcStatus(work->gameSys) == 0) {
            work->state = MUSICAL_EVENT_STATE_LEAVE_SHOW;
            if (work->aborted == 1)
                work->state = MUSICAL_EVENT_STATE_ABORT_LEAVE;
        }
        break;
    case MUSICAL_EVENT_STATE_LEAVE_SHOW:
        if (MUSICAL_EVENT_RunLeaveSequence(event, work) == 1) {
            work->step = 0;
            work->state = MUSICAL_EVENT_STATE_MESSAGE_SHOW;
            MUSICAL_EVENT_RollProgramRewards(work);
            MUSICAL_EVENT_ApplyResults(work);
        }
        break;
    case MUSICAL_EVENT_STATE_MESSAGE_SHOW:
        MUSICAL_EVENT_ShowMessage(event, work, 5);
        work->state = MUSICAL_EVENT_STATE_FINISH;
        break;
    case MUSICAL_EVENT_STATE_FINISH:
        if (work->aborted == 1) {
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        } else {
            MUSICAL_EVENT_Free(work);
            MUSICAL_EVENT_SpawnExitEffect(event, work);
            work->state = MUSICAL_EVENT_STATE_THANKS;
        }
        break;
    case MUSICAL_EVENT_STATE_THANKS:
        MUSICAL_EVENT_ShowMessage(event, work, 0x28CC);
        work->state = MUSICAL_EVENT_STATE_END;
        break;
    case MUSICAL_EVENT_STATE_END:
        func_02030B50((void *)4);
        func_020306F0(0x2C);
        return 1;
    case MUSICAL_EVENT_STATE_ABORT_LEAVE:
        if (MUSICAL_EVENT_RunLeaveSequence(event, work) == 1)
            work->state = MUSICAL_EVENT_STATE_ABORT_NET;
        break;
    case MUSICAL_EVENT_STATE_ABORT_NET:
        GFL_NET_ERR_RequestScreen();
        work->state = MUSICAL_EVENT_STATE_ABORT_CLEANUP;
        break;
    case MUSICAL_EVENT_STATE_ABORT_CLEANUP:
        MUSICAL_EVENT_Free(work);
        MUSICAL_EVENT_SpawnExitEffect(event, work);
        work->state = MUSICAL_EVENT_STATE_ABORT_WAIT;
        break;
    case MUSICAL_EVENT_STATE_ABORT_WAIT:
        work->state = MUSICAL_EVENT_STATE_ABORT_MESSAGE;
        break;
    case MUSICAL_EVENT_STATE_ABORT_MESSAGE:
        MUSICAL_EVENT_ShowMessage(event, work, 0x28CD);
        work->state = MUSICAL_EVENT_STATE_END;
        break;
    }
    return 0;
}

/*
 * Creates the local performer from the own Pokemon. In a wireless session
 * the two session calls follow; the first one's result is unused (the call
 * is kept: the session object is read through it).
 */
void MUSICAL_EVENT_CreateLocalPerformer(MusicalEventWork *work)
{
    work->localPerformer = func_021F675C(work->ownMon, 4);
    if (work->linkMode != 0) {
        func_021FD904(work->link->session);
        func_021FD938(work->link->session);
    }
}

/*
 * Frees everything the event owns: dress-up parameter, stage, result
 * record, musical system, local performer and program, then clears the
 * owner back pointer in the link. Returns the link (r0 left as is).
 */
int MUSICAL_EVENT_Free(MusicalEventWork *work)
{
    MusicalLink *link;

    if (work->dressup != 0)
        MUSICAL_DRESSUP_SYS_Delete(work->dressup);
    if (work->stage != 0)
        MUSICAL_STAGE_SYS_Delete(work->stage);
    if (work->result != 0) {
        func_020307B0(work->result->record);
        func_020307B0(work->result);
    }
    if (work->musicalSystem != 0)
        func_021F6888(work->musicalSystem);
    if (work->localPerformer != 0)
        func_020307B0(work->localPerformer);
    if (work->program != 0)
        MUSICAL_PROGRAM_Delete(work->program);
    link = work->link;
    link->owner = 0;
    return (int)link;
}

/*
 * Creates the dress-up parameter block for the local performer.
 */
MusicalDressupParam *MUSICAL_EVENT_CreateDressupParam(MusicalEventWork *work)
{
    MusicalDressupParam *param;

    param = MUSICAL_DRESSUP_SYS_Create(4, work->localPerformer, work->saveControl);
    work->dressup = param;
    param->session = work->session;
    return param;
}

/*
 * Sends the local performer to the peers of a wireless session.
 */
void MUSICAL_EVENT_SendLocalPerformer(MusicalEventWork *work)
{
    if (work->linkMode == 1)
        func_021FD948(work->session, work->localPerformer);
}

/*
 * Builds the stage: the local performer, the NPC performers (local show)
 * or the peers' performers (wireless show, NPCs fill the empty slots), then
 * the program and its bonus split.
 */
void MUSICAL_EVENT_CreateStage(MusicalEventWork *work)
{
    u8 i;
    u8 npc;
    MusicalPerformer *peer;

    work->stage = MUSICAL_STAGE_SYS_Create(4, work->session);
    if (work->linkMode == 0) {
        for (i = 0; i < 4; i++) {
            if (i == 0)
                MUSICAL_STAGE_SYS_SetLocalPerformer(work->stage, work->playerSlot[i], work->localPerformer);
            else
                MUSICAL_PROGRAM_CreateNpcPerformer(work->program, work->stage, work->playerSlot[i], i - 1, 4);
        }
    } else {
        npc = 0;
        for (i = 0; i < 4; i++) {
            peer = func_021FD4F8(work->session, work->playerSlot[i]);
            if (peer != 0) {
                MUSICAL_STAGE_SYS_SetRemotePerformer(work->stage, work->playerSlot[i], peer);
            } else {
                MUSICAL_PROGRAM_CreateNpcPerformer(work->program, work->stage, work->playerSlot[i], npc, 4);
                npc++;
            }
        }
    }
    work->stage->musicalSystem = work->musicalSystem;
    work->stage->program = work->program;
    MUSICAL_PROGRAM_SplitBonus(4, work->program, work->stage);
}

/*
 * Adds the program's per-category share to the total of every performer for
 * each equipped prop. In a wireless show the props the peers report as used
 * are marked first. The u8 local category is what puts the truncation of
 * func_021F5140's result ahead of the work->program load.
 */
void MUSICAL_EVENT_ScorePerformers(MusicalEventWork *work)
{
    MusicalPerformer *performer;
    void *propTable;
    u8 i;
    u8 j;
    u32 index;
    u8 category;

    if (work->linkMode == 1) {
        for (i = 0; i < 4; i++) {
            performer = work->stage->performers[i];
            for (j = 0; j < 2; j++) {
                index = func_021FD964(work->session, i, j);
                if (index != 0xFF)
                    performer->equipUsed[index] = 1;
            }
        }
    }
    propTable = func_021F4F14(4);
    for (i = 0; i < 4; i++) {
        performer = work->stage->performers[i];
        for (j = 0; j < 9; j++) {
            if (performer->equipUsed[j] == 1) {
                category = (u32)func_021F5140(propTable, (u16)performer->equips[j].propId);
                performer->totalScore += MUSICAL_PROGRAM_GetCategoryShare(work->program, category);
            }
        }
    }
    func_021F4F40(propTable);
}

/*
 * Fills the show record (date, program, title, the four performers with
 * their props) for the result screen and orders the performers by score
 * into rankOrder.
 */
void MUSICAL_EVENT_CreateShowRecord(MusicalEventWork *work)
{
    MusicalShowRecord *record;
    RtcDate date;
    void *title;
    u8 sortScore[4];
    u8 i;
    u8 j;
    u8 pair;
    u8 bestScore;
    u8 score;
    int pairs;
    void *peerName;
    MusicalPerformer *performer;
    void *msgData;
    u8 left;
    u8 swapSlot;
    u8 right;
    u8 k;

    work->result = func_02030734(4, 0x14, 0, sMusicalEventFileName, 0x312);
    work->result->record = func_02030734(4, 0x1b0, 1, sMusicalEventFileName, 0x313);
    work->result->state = 0;
    work->result->session = work->session;
    record = work->result->record;
    func_0203F4E4(&date);
    record->programId = MUSICAL_PROGRAM_GetBaseProgramId(work->program);
    record->year = date.year;
    record->month = date.month;
    record->day = date.day;
    title = MUSICAL_EVENT_AllocTitleString(work, 4);
    STRBUF_ToChars(title, record->title, 0x25);
    STRBUF_Delete(title);
    record->reserved = 0;
    record->showType = 0x15;
    record->valid = 1;
    record->localSlot = work->localSlot;
    bestScore = 0;
    for (i = 0; i < 4; i++) {
        score = work->stage->performers[i]->totalScore;
        if (bestScore < score) {
            record->winnerMask = 0;
            bestScore = score;
        }
        if (bestScore == score)
            record->winnerMask = record->winnerMask + (1 << i);
    }
    for (i = 0; i < 4; i++) {
        peerName = 0;
        performer = work->stage->performers[i];
        record->performers[i].monsNo = performer->monsNo;
        record->performers[i].gender = performer->gender;
        record->performers[i].shiny = performer->shiny;
        record->performers[i].form = performer->form;
        record->performers[i].personality = performer->personality;
        if (i == work->localSlot)
            peerName = GAME_DATA_GetMyStatus(work->gameData);
        else if (work->linkMode == 1)
            peerName = func_021FCE28(work->session, MUSICAL_EVENT_GetPlayerOfSlot(work, i));
        if (peerName != 0) {
            MI_CpuCopy8(peerName, record->performers[i].name, 0x10);
        } else {
            u8 nameId = MUSICAL_PROGRAM_GetNpcNameId(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, MUSICAL_EVENT_GetPlayerOfSlot(work, i)));

            msgData = func_02045B38(0, 2, 0x4C, 4);
            title = func_02045EC0(msgData, nameId);
            STRBUF_ToChars(title, (u16 *)record->performers[i].name, 8);
            STRBUF_Delete(title);
            MSGDATA_Delete(msgData);
        }
        for (j = 0; j < 8; j++) {
            record->performers[i].props[j].propId = 0xFF;
            record->performers[i].props[j].offset = 0;
            record->performers[i].props[j].bodySlot = 10;
        }
        for (j = 0; j < 9; j++) {
            if (performer->equips[j].propId != 0xFF) {
                u8 order = performer->equips[j].order;

                record->performers[i].props[order].propId = performer->equips[j].propId;
                record->performers[i].props[order].offset = performer->equips[j].offset;
                record->performers[i].props[order].bodySlot = j;
            }
        }
    }
    work->result->ready = 1;
    work->result->save = func_0200A5F8(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(work->gameSys)));
    for (k = 0; k < 4; k++) {
        sortScore[k] = work->stage->performers[k]->totalScore;
        work->rankOrder[k] = k;
    }
    for (k = 0; k < 4; k++) {
        pairs = 4 - (k + 1);
        for (pair = 0; pair < pairs; pair++) {
            left = sortScore[pair];
            right = sortScore[pair + 1];
            if (right > left) {
                swapSlot = work->rankOrder[pair + 1];
                sortScore[pair + 1] = left;
                work->rankOrder[pair + 1] = work->rankOrder[pair];
                sortScore[pair] = right;
                work->rankOrder[pair] = swapSlot;
            }
        }
    }
}

/*
 * Writes the show results into the musical save, the trainer record and the
 * friendship of the own Pokemon. The u16 read through GAME_DATA_GetMyPlayerWork's result
 * goes through a local; passed inline it is copied to r2 before the ldrh.
 * The tally array is `u8 count[4] = {0, ...}` in a nested block (as in
 * MUSICAL_PROGRAM_Create).
 */
void MUSICAL_EVENT_ApplyResults(MusicalEventWork *work)
{
    u8 localScore;
    u8 topScore;
    u8 j;
    void *propTable;
    MusicalPerformer *performer;
    void *trainerRecord;
    u16 zoneId;

    localScore = MUSICAL_EVENT_GetScoreCapped(work, work->localSlot);
    topScore = MUSICAL_EVENT_GetScoreCapped(work, work->rankOrder[0]);
    func_0200A768(work->save);
    if (localScore == topScore && localScore != 0)
        func_0200A788(work->save);
    func_0200A7C0(work->save, localScore);
    func_0200A800(work->save, localScore);
    {
        u8 count[4] = {0, 0, 0, 0};

        propTable = func_021F4F14(4);
        performer = work->stage->performers[work->localSlot];
        for (j = 0; j < 9; j++) {
            if (performer->equips[j].propId != 0xFF)
                count[(u8)(u32)func_021F5140(propTable, (u16)performer->equips[j].propId)]++;
        }
        for (j = 0; j < 4; j++)
            func_0200A7AC(work->save, j, count[j]);
    }
    func_021F4F40(propTable);
    zoneId = *GAME_DATA_GetMyPlayerWork(work->gameData);
    NATSUKI_Calc(work->ownMon, 6, zoneId, 4);
    trainerRecord = GAME_DATA_GetTrainerRecord(work->gameData);
    if (work->linkMode == 0) {
        func_02008DF0(trainerRecord, 0x72);
        if (localScore == topScore && localScore != 0)
            func_02008DF0(trainerRecord, 0x73);
    } else {
        func_02008DF0(trainerRecord, 0x74);
        if (localScore == topScore && localScore != 0)
            func_02008DF0(trainerRecord, 0x75);
    }
    func_02008DAC(trainerRecord, 0x76, localScore);
}

/*
 * Rolls the rewards of the ten save programs after a show. The reward level
 * comes from the summed scores; the programs to reward are picked by a
 * shuffled order, each with a chance equal to the local score to also give
 * an unowned prop from the program's prop row. Two levers: the spilled
 * locals are declared in the order of their stack slots from the top down,
 * and the table row pointer is set in the for-initialiser after j (a
 * separate statement stores it before `j = 0`).
 */
void MUSICAL_EVENT_RollProgramRewards(MusicalEventWork *work)
{
    u8 shuffle[10];
    u8 *candidates;
    struct MusicalProgram *program;
    u32 scoreSum;
    u32 propRow;
    u16 *peerValue;
    u8 j;
    u8 value;
    u8 pick;
    u8 chance;
    u8 i;
    u8 level;
    u8 candidateCount;
    u32 category;
    const u8 *row;
    u8 round;

    candidates = func_02030734(4, 0x28, 1, sMusicalEventFileName, 0x3F9);
    scoreSum = 0;
    for (i = 0; i < 10; i++) {
        program = func_0200A750(work->save, i);
        program->state = 4;
        program->hasProp = 0;
        program->prop = 0;
    }
    if (work->linkMode == 0) {
        scoreSum = func_0200A81C(work->save) + MUSICAL_EVENT_GetScoreCapped(work, work->localSlot);
    } else {
        for (j = 0; j < 4; j++) {
            peerValue = func_021FD8F8(work->session, MUSICAL_EVENT_GetPlayerOfSlot(work, j));
            if (func_021FD4F8(work->session, j) != 0) {
                scoreSum += *peerValue;
                scoreSum += MUSICAL_EVENT_GetScoreCapped(work, j);
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if (d_0216FF14[i] <= scoreSum) {
            level = 10 - i;
            break;
        }
    }
    propRow = MUSICAL_PROGRAM_GetPropRow(work->program);
    if (propRow < 7) {
        candidateCount = 0;
        for (j = 0, row = d_0216FF28[propRow]; j < 0x28; j++) {
            value = row[j];
            if (func_0200A644(work->save, value) == 0) {
                candidates[candidateCount] = value;
                candidateCount++;
            }
        }
    }
    category = MUSICAL_PROGRAM_GetBestCategory(work->program);
    for (i = 0; i < 10; i++)
        shuffle[i] = i;
    for (round = 0; round < 10; round++) {
        for (j = 0; j < 10; j++) {
            pick = func_02005728(10);
            value = shuffle[j];
            shuffle[j] = shuffle[pick];
            shuffle[pick] = value;
        }
    }
    for (i = 0; i < level; i++) {
        program = func_0200A750(work->save, shuffle[i]);
        chance = MUSICAL_EVENT_GetScoreCapped(work, work->localSlot);
        program->state = category;
        if ((u8)func_02005728(100) < chance && candidateCount != 0) {
            pick = func_02005728(candidateCount);
            program->hasProp = 1;
            program->prop = candidates[pick];
            for (; pick < candidateCount - 1; pick++)
                candidates[pick] = candidates[pick + 1];
            candidateCount--;
        }
    }
    func_020307B0(candidates);
}

/*
 * Return sequence after a screen: pop the sound, reopen the field, wait
 * for the sound request to be accepted. Returns 1 when done.
 */
int MUSICAL_EVENT_RunLeaveSequence(void *event, MusicalEventWork *work)
{
    GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(work->gameSys));
    switch (work->step) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopTask(work->gameSys, 0, 0x3C));
        work->step++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(work->gameSys));
        work->step++;
        break;
    case 2:
        work->step++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(work->gameSys));
        work->step++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/*
 * Enter sequence before a screen: push the sound, close the field, wait
 * until the sound settles. Returns 1 when done.
 */
int MUSICAL_EVENT_RunEnterSequence(void *event, MusicalEventWork *work)
{
    void *fieldMap;

    GAME_DATA_GetBgmInfo(GAMESYSTEM_GetGameData(work->gameSys));
    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSys);
    switch (work->step) {
    case 0:
        work->step++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushTask(work->gameSys, 30));
        work->step++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(work->gameSys, fieldMap));
        work->step++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitSettledTask(work->gameSys));
        work->step++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/*
 * Spawns the effect object (id 0x4E) at the position of the local slot.
 */
void MUSICAL_EVENT_SpawnSeatEffect(void *event, MusicalEventWork *work)
{
    void *fieldMap;
    Float3 pos;

    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSys);
    pos = d_0216FEFC;
    pos.x += work->localSlot << 17;
    GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(work->gameSys, fieldMap, 0x4E, &pos, 0));
}

/*
 * Spawns the effect object (id 0x4D) at the exit position (one position for
 * a wireless show, one for a local show). The call result goes through a
 * local so both arms share one GAME_EVENT_CallEvent call (calling it in each arm
 * keeps event in r6).
 */
void MUSICAL_EVENT_SpawnExitEffect(void *event, MusicalEventWork *work)
{
    void *fieldMap;
    Float3 localPos;
    void *effect;
    Float3 linkPos;

    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSys);
    localPos = d_0216FEF0;
    linkPos = d_0216FF08;
    if (work->linkMode == 1)
        effect = EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(work->gameSys, fieldMap, 0x4D, &linkPos, 1);
    else
        effect = EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(work->gameSys, fieldMap, 0x4D, &localPos, 1);
    GAME_EVENT_CallEvent(event, effect);
}

/*
 * Shows a field message window and attaches it to the event.
 */
void MUSICAL_EVENT_ShowMessage(void *event, MusicalEventWork *work, int messageId)
{
    struct GameEvent *message = SCRIPT_SYS_CreateScriptEventSimple(work->gameSys, messageId, 0, 0x15);

    SCRIPT_SYS_GetEventScriptWork(message);
    GAME_EVENT_CallEvent(event, message);
}

/*
 * Counts the NPC slots below n: without a session every slot but 0, with a
 * session the slots that have no peer record.
 */
u8 MUSICAL_EVENT_CountNpcSlotsBelow(MusicalEventWork *work, u8 n)
{
    u8 i;
    u8 count;

    count = 0;
    for (i = 0; i < n; i++) {
        if (work->session == 0) {
            if (i == 0)
                continue;
        } else if (func_021FCE28(work->session, i) != 0) {
            continue;
        }
        count++;
    }
    return count;
}

/*
 * Returns the stage slot of the local player.
 */
u8 MUSICAL_EVENT_GetLocalSlot(MusicalEventWork *work)
{
    return work->localSlot;
}

/*
 * Returns the player whose stage slot is slot.
 */
u8 MUSICAL_EVENT_GetPlayerOfSlot(MusicalEventWork *work, u8 slot)
{
    u8 i;

    for (i = 0; i < 4; i++) {
        if (work->playerSlot[i] == slot)
            return i;
    }
    return 0;
}

/*
 * Returns the best appeal category of the show program.
 */
u8 MUSICAL_EVENT_GetProgramBestCategory(MusicalEventWork *work)
{
    return MUSICAL_PROGRAM_GetBestCategory(work->program);
}

/*
 * Allocates the show title string (entry 0 of the musical system's
 * message file).
 */
void *MUSICAL_EVENT_AllocTitleString(MusicalEventWork *work, int heapId)
{
    void *title;
    void *msgData;

    msgData = MSGDATA_CreateFromMemory(work->musicalSystem->msgFile, heapId);
    title = func_02045EC0(msgData, 0);
    MSGDATA_Delete(msgData);
    return title;
}

/*
 * Returns the total score of the performer in slot, capped to 255.
 */
u8 MUSICAL_EVENT_GetScoreCapped(MusicalEventWork *work, u8 slot)
{
    u16 score;

    score = work->stage->performers[slot]->totalScore;
    if (score < 0x100)
        return score;
    return 0xFF;
}

/*
 * Returns the highest total score of the four performers.
 */
u16 MUSICAL_EVENT_GetMaxScore(MusicalEventWork *work)
{
    u16 best = 0;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (best < work->stage->performers[i]->totalScore)
            best = work->stage->performers[i]->totalScore;
    }
    return best;
}

/*
 * Returns the lowest total score of the four performers (255 at most).
 */
u16 MUSICAL_EVENT_GetMinScore(MusicalEventWork *work)
{
    u16 lowest = 0xFF;
    u8 i;

    for (i = 0; i < 4; i++) {
        if (lowest > work->stage->performers[i]->totalScore)
            lowest = work->stage->performers[i]->totalScore;
    }
    return lowest;
}

/*
 * Returns the stage slot of the performer at the given rank.
 */
u8 MUSICAL_EVENT_GetSlotOfRank(MusicalEventWork *work, u8 rank)
{
    return work->rankOrder[rank];
}

/*
 * Index of the performer's best appeal category, or 4 on a tie for the best.
 * The loop counter is set before the performer load (i = 0; then
 * for (; ...)). That gives the work->stage temporary the register the image
 * uses (r6, shared with performer). Setting i in the for-init is 2 bytes
 * out.
 */
u8 MUSICAL_EVENT_GetBestAppealCategory(MusicalEventWork *work, u8 slot)
{
    u8 best;
    u8 i;
    u8 bestScore;
    u8 tie;
    MusicalPerformer *performer;

    bestScore = 0;
    best = 0;
    tie = 0;
    i = 0;
    performer = work->stage->performers[slot];
    for (; i < 4; i++) {
        if (bestScore < performer->appealScore[i]) {
            tie = 0;
            best = i;
            bestScore = performer->appealScore[i];
        } else if (bestScore == performer->appealScore[i]) {
            tie = 1;
        }
    }
    if (tie == 1)
        best = 4;
    return best;
}

/*
 * Portrait class of the performer in slot: 0 for the local player, 1 or 4
 * from the peer's outfit variant in a wireless show, else the class byte of
 * its NPC template.
 */
u8 MUSICAL_EVENT_GetPortraitClass(MusicalEventWork *work, u8 slot)
{
    u8 player = MUSICAL_EVENT_GetPlayerOfSlot(work, slot);
    void *peerStatus;

    if (slot == work->localSlot)
        return 0;
    if (work->linkMode == 1) {
        peerStatus = func_021FCE28(work->session, player);
        if (peerStatus != 0) {
            if (func_02008550(peerStatus) == 0)
                return 1;
            return 4;
        }
    }
    return MUSICAL_PROGRAM_GetNpcPortraitClass(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, player));
}

/*
 * Registers the name of the player in slot as word wordIndex: the own
 * trainer, a peer's trainer, or the NPC name from message bank 0x4C.
 */
void MUSICAL_EVENT_SetPlayerNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex)
{
    int done = 0;
    u8 player = MUSICAL_EVENT_GetPlayerOfSlot(work, slot);
    void *peerStatus;

    if (slot == work->localSlot) {
        func_0201F02C(wordSet, wordIndex, GAME_DATA_GetMyStatus(work->gameData));
        done = 1;
    } else if (work->linkMode == 1) {
        peerStatus = func_021FCE28(work->session, player);
        if (peerStatus != 0) {
            func_0201F02C(wordSet, wordIndex, peerStatus);
            done = 1;
        }
    }
    if (!done) {
        u8 nameId = MUSICAL_PROGRAM_GetNpcNameId(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, player));
        void *msgData = func_02045B38(0, 2, 0x4C, 4);
        void *str = func_02045EC0(msgData, nameId);

        func_0201EE0C(wordSet, wordIndex, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(msgData);
    }
}

/*
 * Twin of MUSICAL_EVENT_SetPlayerNameWord for the Pokemon name: the own Pokemon, the peer's
 * Pokemon (func_021FCE44), or failing both the NPC Pokemon name from message
 * bank 0x4D.
 */
void MUSICAL_EVENT_SetPokemonNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex)
{
    int done = 0;
    u8 player = MUSICAL_EVENT_GetPlayerOfSlot(work, slot);
    void *peerMon;

    if (slot == work->localSlot) {
        GAME_DATA_GetMyStatus(work->gameData);
        func_0201EEF4(wordSet, wordIndex, work->ownMon);
        done = 1;
    } else if (work->linkMode == 1) {
        peerMon = func_021FCE44(work->session, player);
        if (peerMon != 0) {
            func_0201EF14(wordSet, wordIndex, peerMon);
            done = 1;
        }
    }
    if (!done) {
        u8 nameId = MUSICAL_PROGRAM_GetNpcNameId(work->program, MUSICAL_EVENT_CountNpcSlotsBelow(work, player));
        void *msgData = func_02045B38(0, 2, 0x4D, 4);
        void *str = func_02045EC0(msgData, nameId);

        func_0201EE0C(wordSet, wordIndex, str, 0, 1, 2);
        STRBUF_Delete(str);
        MSGDATA_Delete(msgData);
    }
}

/*
 * Receives the show program from the session host: the two packed words
 * are read from the session and unpacked into the program (created first
 * if this machine has none yet).
 */
void MUSICAL_EVENT_ReceiveShowProgram(MusicalEventWork *work)
{
    u32 packedBonus;
    u32 packedPicks;

    packedBonus = func_021FD954(work->session);
    packedPicks = func_021FD95C(work->session);
    if (work->program == 0)
        work->program = MUSICAL_PROGRAM_Create(4, work->musicalSystem, 0);
    MUSICAL_PROGRAM_UnpackBonus(work->program, packedBonus);
    MUSICAL_PROGRAM_UnpackPicks(work->program, packedPicks);
}

/*
 * One-shot network error test: only when the session is wireless and the
 * network reports an error does the aborted flag get set.
 */
void MUSICAL_EVENT_CheckNetError(MusicalEventWork *work)
{
    int linkMode = work->linkMode;

    if (linkMode == 1) {
        if (func_0200FB24()) {
            if (work->aborted == 0) {
                work->aborted = 1;
            }
        }
    }
}

/*
 * Reads the aborted flag.
 */
u32 MUSICAL_EVENT_IsAborted(MusicalEventWork *work) { return work->aborted; }

/*
 * Init of the dress-up proc: loads overlay 133 and copies the parameter
 * block to a heap copy the UI keeps.
 */
int MUSICAL_DRESSUP_SYS_Init(void *proc, u32 *state, MusicalDressupParam *param)
{
    MusicalDressupWork *work;
    *state = 0;
    func_02034AC4((u32)ov133_id);
    GFL_HEAP_CreateChildHeap(1, 0x2d, 1 << 18);
    work = PROCSYS_AllocProcWork(proc, 0x10, 0x2d);
    work->paramCopy = func_02030734(0x2d, 0xc, 0, sMusicalDressupSysFileName, 0x4e);
    work->param = param;
    work->paramCopy[0] = ((u32 *)param)[0];
    work->paramCopy[1] = ((u32 *)param)[1];
    work->paramCopy[2] = ((u32 *)param)[2];
    return 1;
}

/*
 * Exit of the dress-up proc: frees the parameter copy and the proc work,
 * unloads overlay 133.
 */
int MUSICAL_DRESSUP_SYS_Exit(void *proc, int unused1, int unused2, MusicalDressupWork *work)
{
    func_020307B0(work->paramCopy);
    func_020315D4(proc);
    func_020306F0(0x2d);
    func_02034A5C((u32)ov133_id);
    return 1;
}

/*
 * Main of the dress-up proc: start the UI over the parameter copy, wait for
 * its result, close it. In a wireless session the host side is told first.
 */
int MUSICAL_DRESSUP_SYS_Main(void *proc, int *state, int unused, MusicalDressupWork *work)
{
    switch (*state) {
    case 0:
        work->ui = func_021B6100(work->paramCopy, 0x2d);
        *state = 1;
        if (work->param->session != 0) {
            if (func_021FD904(work->param->session) == 1)
                func_021FD52C(work->param->session);
        }
        break;
    case 1: {
        int result = func_021B63BC(work->ui);
        if (result != 0) {
            work->result = result;
            *state = 2;
        }
        break;
    }
    case 2:
        func_021B6294(work->ui);
        return 1;
    }
    return 0;
}

/*
 * Creates the dress-up parameter block.
 */
MusicalDressupParam *MUSICAL_DRESSUP_SYS_Create(int heapId, MusicalPerformer *performer, void *saveControl)
{
    MusicalDressupParam *param;
    int zero = 0;

    param = func_02030734(heapId, 12, 0, sMusicalDressupSysFileName, 0xa7);
    param->session = (void *)zero;
    param->save = func_0200A5F8(saveControl);
    param->performer = performer;
    return param;
}

/*
 * Frees the dress-up parameter block (tail call through a pool word and
 * `bx r3`: docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 */
void MUSICAL_DRESSUP_SYS_Delete(MusicalDressupParam *param)
{
    func_020307B0(param);
}

/*
 * Init of the stage proc: builds the stage (four NPC performers with their
 * props, the program and its split) or takes over the stage handed in. The
 * pooled 0x70 is ov112_id and the three colour masks come from one `mask`
 * local shifted.
 */
int MUSICAL_STAGE_SYS_Init(void *proc, void *unused, MusicalStage *prevStage)
{
    MusicalStageWork *work;
    u32 mask;

    GFL_HEAP_CreateChildHeap(1, 0x2E, 0xA8000);
    work = PROCSYS_AllocProcWork(proc, sizeof(MusicalStageWork), 0x2E);
    if (prevStage == 0) {
        func_02034AC4((u32)ov112_id);
        work->stage = MUSICAL_STAGE_SYS_Create(0x2E, 0);
        mask = 0xFF000000;
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 0, 0x147, 0, mask, 60, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 1, 0x147, 0, mask >> 8, 120, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 2, 0x147, 0, mask >> 16, -3, 0x2E);
        MUSICAL_STAGE_SYS_CreateNpcPerformer(work->stage, 3, 0x147, 0, 0x000000FF, -1, 0x2E);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 0, 7, 0x13, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 0, 8, 0x13, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 0, 2, 0x10, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 1, 0x07, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 5, 0x09, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 7, 0x18, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 1, 8, 0x2B, 0, 3);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 2, 7, 0x1F, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 2, 8, 0x1E, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 2, 2, 0x0F, 0, 2);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 3, 7, 0x1E, 0, 0);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 3, 8, 0x1E, 0, 1);
        MUSICAL_STAGE_SYS_SetPerformerProp(work->stage, 3, 2, 0x15, 0, 2);
        work->stage->performers[1]->origin = MUSICAL_PERFORMER_LOCAL;
        GFL_HEAP_CreateChildHeap(1, 0x802C, 0x80000);
        work->stage->musicalSystem = func_021F685C(1);
        func_021F68BC(work->stage->musicalSystem, 0, 0, 0, 0x2C);
        work->stage->program = MUSICAL_PROGRAM_Create(0x2E, work->stage->musicalSystem, 0);
        MUSICAL_PROGRAM_SplitBonus(0x2E, work->stage->program, work->stage);
        work->stage->performers[0]->totalScore = 75;
        work->stage->performers[1]->totalScore = 45;
        work->stage->performers[2]->totalScore = 30;
        work->stage->performers[3]->totalScore = 0;
    } else {
        work->stage = prevStage;
    }
    return 1;
}

/*
 * Exit of the stage proc. With keepStage == 0 the stage and everything it
 * owns is freed here (performer 1 is flagged as an NPC performer first so
 * the stage frees it too).
 */
int MUSICAL_STAGE_SYS_Exit(void *proc, int unused, int keepStage, MusicalStageWork *work)
{
    if (keepStage == 0) {
        MUSICAL_PROGRAM_Delete(work->stage->program);
        func_021F6888(work->stage->musicalSystem);
        func_020306F0(0x2c);
        work->stage->performers[1]->origin = MUSICAL_PERFORMER_NPC;
        MUSICAL_STAGE_SYS_Delete(work->stage);
        func_02034A5C((u32)ov112_id);
    }
    func_020315D4(proc);
    func_020306F0(0x2e);
    return 1;
}

/*
 * Main of the stage proc: start the stage UI, wait for it, close it.
 */
int MUSICAL_STAGE_SYS_Main(void *proc, int *state, int unused, MusicalStageWork *work)
{
    switch (*state) {
    case 0:
        work->ui = func_021F8480(work->stage, 0x2e);
        *state = 1;
        break;
    case 1:
        if (func_021F879C(work->ui) == 1)
            *state = 2;
        break;
    case 2:
        func_021F8640(work->ui);
        return 1;
    }
    return 0;
}

/*
 * Creates an empty stage for a session.
 */
MusicalStage *MUSICAL_STAGE_SYS_Create(u32 heapId, void *session)
{
    MusicalStage *stage;
    u8 i;

    stage = func_02030734(heapId, 0x20, 0, sMusicalStageSysFileName, 0xBE);
    stage->session = session;
    for (i = 0; i < 4; i++)
        stage->performers[i] = 0;
    return stage;
}

/*
 * Frees the NPC performers of the stage and the stage itself.
 */
int MUSICAL_STAGE_SYS_Delete(MusicalStage *stage){
    u8 i;

    for (i = 0; i < 4; i++) {
        if (stage->performers[i] != 0 && stage->performers[i]->origin == MUSICAL_PERFORMER_NPC)
            func_020307B0(stage->performers[i]);
    }
    func_020307B0(stage);
}

/*
 * Puts the local performer in a stage slot.
 * stand-in: the integer form (stage + 4 computed first, then the byte
 * offset) is the only one that keeps the base add ahead of the shift; the
 * plain stage->performers[slot] form compiles to shift, add, store.
 */
int MUSICAL_STAGE_SYS_SetLocalPerformer(MusicalStage *stage, int slot, MusicalPerformer *performer)
{
    int list;
    int offset;

    list = (int)stage + 4;
    offset = slot << 2;
    *(MusicalPerformer **)((char *)list + offset) = performer;
    performer->origin = MUSICAL_PERFORMER_LOCAL;
    return MUSICAL_PERFORMER_LOCAL;
}

/*
 * Creates an NPC performer (species, form, personality, appeal base) in a
 * stage slot.
 */
void MUSICAL_STAGE_SYS_CreateNpcPerformer(MusicalStage *stage, u8 slot, u16 monsNo, u8 form, u32 personality, u16 appealBase, u16 heapId)
{
    stage->performers[slot] = func_021F67E0(monsNo, form, 0, 0, personality, heapId);
    stage->performers[slot]->origin = MUSICAL_PERFORMER_NPC;
    stage->performers[slot]->appealBase = appealBase;
}

/*
 * Puts a peer's performer in a stage slot. Same integer form as
 * MUSICAL_STAGE_SYS_SetLocalPerformer (stand-in, same reason).
 */
int MUSICAL_STAGE_SYS_SetRemotePerformer(MusicalStage *stage, int slot, MusicalPerformer *performer)
{
    int list;
    int offset;

    list = (int)stage + 4;
    offset = slot << 2;
    *(MusicalPerformer **)((char *)list + offset) = performer;
    performer->origin = MUSICAL_PERFORMER_REMOTE;
    return MUSICAL_PERFORMER_REMOTE;
}

/*
 * Equips a prop on a performer: body slot, prop, offset, list order.
 */
void MUSICAL_STAGE_SYS_SetPerformerProp(MusicalStage *stage, u8 slot, u8 bodySlot, u16 propId, s16 offset, u8 order)
{
    MusicalPerformer *performer;

    performer = stage->performers[slot];
    performer->equips[bodySlot].propId = propId;
    performer->equips[bodySlot].offset = offset;
    performer->equips[bodySlot].order = order;
}

static inline u32 RandBelow(u32 n)
{
    u32 r = func_0203F0A8();

    if (n != 0)
        r = ((u64)r * n) >> 32;
    return r;
}

/*
 * Creates the show program: copies the base program's category bonuses,
 * deals the extra bonus (bonusTotal / 5 steps of 5 points) to random
 * categories and picks three of the six NPC templates the musical level
 * allows. The candidate buffer is `u8 buf[6] = {0, ...}` in a nested block
 * (see docs/idioms/an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six explicit zero stores rematerialise sp+8 for the fill loop, and a plain
 * block-scope array hoists catalog out of it. RandBelow is the inline
 * `(u64)rand * n >> 32` helper; its n != 0 test folds away for constant n.
 */
MusicalShowProgram *MUSICAL_PROGRAM_Create(u32 heapId, MusicalSystemHead *musicalSystem, u16 maxLevel)
{
    MusicalShowProgram *program;
    u8 i;
    u8 remaining;
    u8 chunk;
    u8 count;
    u8 first;
    u8 second;
    u8 round;

    program = func_02030734(heapId, 0x10, 0, sMusicalProgramFileName, 100);
    program->catalog.programs = musicalSystem->programs;
    for (i = 0; i < 4; i++) {
        program->categoryBonus[i] = 0;
        program->sharePerProp[i] = 0;
    }
    for (i = 0; i < 4; i++)
        program->categoryBonus[i] = program->catalog.programs->bonus[i];
    remaining = program->catalog.programs->bonusTotal / 5;
    while (remaining != 0) {
        chunk = RandBelow(3) + 1;
        if (chunk > remaining)
            chunk = remaining;
        program->categoryBonus[RandBelow(4)] += (u8)(chunk * 5);
        remaining -= chunk;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};

        count = 0;
        for (i = 0; i < 6; i++) {
            if (program->catalog.programs[i].levelRequired <= maxLevel) {
                buf[count] = i;
                count++;
            }
        }
        if (count < 3) {
            buf[0] = 0;
            buf[1] = 1;
            buf[2] = 2;
            count = 3;
        }
        for (round = 0; round < 30; round++) {
            first = RandBelow(count);
            second = RandBelow(count);
            chunk = buf[first];
            buf[first] = buf[second];
            buf[second] = chunk;
        }
        for (i = 0; i < 3; i++)
            program->picks[i] = buf[i];
    }
    return program;
}

/*
 * Frees the show program (tail call through a pool word and `bx r3`:
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 */
int MUSICAL_PROGRAM_Delete(MusicalShowProgram *program){

    func_020307B0(program);
}

/*
 * Splits each category bonus over the four performers by how many of their
 * nine props fall in that category: sharePerProp = bonus / props in the
 * category, appealScore = share * the performer's props there. recoup: the
 * loop 2 and loop 4 performer pointer and the loop 2 byte counter j are
 * block-local declarations (MusicalPerformer *performer inside each for
 * body, u8 j inside the loop 2 body). Function-scope declarations gave 21
 * bytes of register swaps.
 */
void MUSICAL_PROGRAM_SplitBonus(u32 heapId, MusicalShowProgram *program, MusicalStage *stage)
{
    void *propTable;
    u8 i;
    u8 j;
    u8 category;
    u8 score;
    u8 propsInCategory[4];
    u8 propsOfPerformer[4][4];

    propTable = func_021F4F14(heapId);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++)
            propsOfPerformer[j][i] = 0;
        propsInCategory[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        MusicalPerformer *performer = stage->performers[i];
        u8 j;
        for (j = 0; j < 9; j++) {
            if (performer->equips[j].propId != 0xFF) {
                category = (u32)func_021F5140(propTable, (u16)performer->equips[j].propId);
                propsOfPerformer[i][category]++;
                propsInCategory[category]++;
            }
        }
    }
    for (i = 0; i < 4; i++)
        program->sharePerProp[i] = _s32_div_f(program->categoryBonus[i], propsInCategory[i]);
    for (i = 0; i < 4; i++) {
        MusicalPerformer *performer = stage->performers[i];
        for (j = 0; j < 4; j++) {
            score = program->sharePerProp[j] * propsOfPerformer[i][j];
            performer->totalScore += score;
            performer->appealScore[j] = score;
        }
    }
    func_021F4F40(propTable);
}

/*
 * Reads the category bonus byte at index.
 */
u8 MUSICAL_PROGRAM_GetCategoryBonus(MusicalShowProgram *program, int index) { return program->categoryBonus[index]; }

/*
 * Little-endian 32-bit read of the category bonuses (inverse of
 * MUSICAL_PROGRAM_UnpackBonus).
 */
u32 MUSICAL_PROGRAM_PackBonus(const MusicalShowProgram *program)
{
    return program->categoryBonus[0] + (program->categoryBonus[1] << 8) + (program->categoryBonus[2] << 16) + (program->categoryBonus[3] << 24);
}

/*
 * Stores a packed 32-bit word into the category bonuses.
 */
void MUSICAL_PROGRAM_UnpackBonus(MusicalShowProgram *program, u32 packed)
{
    program->categoryBonus[0] = packed;
    program->categoryBonus[1] = (packed & 0xFF00) >> 8;
    program->categoryBonus[2] = (packed & 0xFF0000) >> 16;
    program->categoryBonus[3] = (packed & 0xFF000000) >> 24;
}

/*
 * Little-endian 24-bit read of the three picks (inverse of MUSICAL_PROGRAM_UnpackPicks).
 */
u32 MUSICAL_PROGRAM_PackPicks(const MusicalShowProgram *program)
{
    return program->picks[0] + (program->picks[1] << 8) + (program->picks[2] << 16);
}

/*
 * Stores a packed 24-bit word into the three picks.
 */
void MUSICAL_PROGRAM_UnpackPicks(MusicalShowProgram *program, u32 packed)
{
    program->picks[0] = packed;
    program->picks[1] = (packed & 0xFF00) >> 8;
    program->picks[2] = (packed & 0xFF0000) >> 16;
}

/*
 * Index of the category with the highest bonus (first one on a tie).
 * Declaration order i, best, index is what colours them r2, r3, r4.
 */
u8 MUSICAL_PROGRAM_GetBestCategory(MusicalShowProgram *program)
{
    u8 i;
    u8 best;
    u8 index;

    best = 0;
    index = 0;
    for (i = 0; i < 4; i++) {
        if (best < program->categoryBonus[i]) {
            best = program->categoryBonus[i];
            index = i;
        }
    }
    return index;
}

/*
 * Creates the NPC performer for stage slot `slot` from the template picked
 * as npcIndex, then equips its props. The stage slot is a u8 (as wide as
 * either callee's parameter); a u32 or int is reloaded from its spill one
 * instruction early. The personality u32 is spelled out in the call, not
 * through an inline reader, so the top byte is loaded once and kept in ip
 * for the fourth argument.
 */
void MUSICAL_PROGRAM_CreateNpcPerformer(MusicalShowProgram *program, MusicalStage *stage, u8 slot, u8 npcIndex, u16 heapId)
{
    MusicalRivalEntry *rival;
    u8 j;

    rival = &program->catalog.rivals->entries[program->picks[npcIndex]];
    MUSICAL_STAGE_SYS_CreateNpcPerformer(stage, slot, rival->monsNo, rival->personality[3], rival->personality[0] + (rival->personality[1] << 8) + (rival->personality[2] << 16) + (rival->personality[3] << 24), rival->appealBase, heapId);
    for (j = 0; j < 8; j++) {
        if (rival->props[j].propId != 0x1FE && rival->props[j].propId != 0x1FF)
            MUSICAL_STAGE_SYS_SetPerformerProp(stage, slot, rival->props[j].bodySlot, rival->props[j].propId, 0, j);
    }
}

/*
 * Id of the base program (first catalog entry).
 */
u8 MUSICAL_PROGRAM_GetBaseProgramId(MusicalShowProgram *program)
{
    return program->catalog.programs->id;
}

/*
 * Prop row of the base program (selects the row of the reward prop table).
 */
int MUSICAL_PROGRAM_GetPropRow(MusicalShowProgram *program)
{
    return program->catalog.programs->propRow;
}

/*
 * Portrait class byte of the picked NPC template npcIndex.
 */
u8 MUSICAL_PROGRAM_GetNpcPortraitClass(MusicalShowProgram *program, u8 npcIndex)
{
    return program->catalog.npcInfo[program->picks[npcIndex]].portraitClass;
}

/*
 * Name id byte of the picked NPC template npcIndex.
 */
u8 MUSICAL_PROGRAM_GetNpcNameId(MusicalShowProgram *program, int npcIndex)
{
    return program->catalog.npcInfo[program->picks[npcIndex]].nameId;
}

/*
 * Share of the bonus per prop for a category.
 */
u16 MUSICAL_PROGRAM_GetCategoryShare(MusicalShowProgram *program, int category)
{
    return program->sharePerProp[category];
}

/*
 * Task callback of the IR battle task: a 10-state sequence that closes the
 * field, runs the battle (the ov008 runner gets the setup, the slot record
 * and a zero word) and returns 1 when done.
 */
int func_0215739C(void *event, u32 *state, IrcBattleTaskWork *work)
{
    void *gameSys = work->gameSys;

    switch (*state) {
    case 0:
        *state = 3;
        break;
    case 1:
    case 2:
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSys, work->setup.bgmBattle));
        (*state)++;
        break;
    case 4: {
        BattleRecSaveArgs args;

        args.setup = &work->setup;
        args.slotData = work->slot;
        args.flag = 0;
        GAME_EVENT_CallEvent(event, GAME_EVENT_CreateOverlayEvent(gameSys, (u32)ov008_id, EVENT_BATTLE_REC_SAVE_Start, &args));
        (*state)++;
        break;
    }
    case 5:
        BTL_SETUP_FreeSlots(&work->setup);
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSys));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSys));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSys, work->gameData, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSys));
        (*state)++;
        break;
    case 9:
        return 1;
    }
    return 0;
}

/*
 * Creates the IR battle task: allocates it with func_0215739C as its
 * callback, picks the formation slot for battle kinds 4..23 (four kinds per
 * rule, the first matching case wins through func_02157650), runs the
 * matching setup builder and returns the event.
 */
struct GameEvent *func_02157450(void *gameSys, void *gameData, u32 kind, IrcBattleRequest *request)
{
    int formation = 0x29;
    struct GameEvent *event = func_020122C0(gameSys, 0, func_0215739C, 0xFC);
    IrcBattleTaskWork *work = func_020124E8(event);
    struct BattleSetupParam *setup;
    void *sysData;

    work->gameSys = gameSys;
    work->gameData = gameData;
    work->slot = &request->slot;
    setup = &work->setup;
    switch (kind) {
    case 5:
        func_02157650(&formation, 0);
    case 4:
        func_02157650(&formation, 2);
    case 7:
        func_02157650(&formation, 1);
    case 6:
        func_02157650(&formation, 3);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommSingle(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 9:
        func_02157650(&formation, 4);
    case 8:
        func_02157650(&formation, 6);
    case 11:
        func_02157650(&formation, 5);
    case 10:
        func_02157650(&formation, 7);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommDouble(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 13:
        func_02157650(&formation, 8);
    case 12:
        func_02157650(&formation, 10);
    case 15:
        func_02157650(&formation, 9);
    case 14:
        func_02157650(&formation, 11);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommTriple(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 17:
        func_02157650(&formation, 12);
    case 16:
        func_02157650(&formation, 14);
    case 19:
        func_02157650(&formation, 13);
    case 18:
        func_02157650(&formation, 15);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommRotation(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, 4);
        break;
    case 21:
        func_02157650(&formation, 16);
    case 20:
        func_02157650(&formation, 18);
    case 23:
        func_02157650(&formation, 17);
    case 22:
        func_02157650(&formation, 19);
        sysData = GAMESYSTEM_GetGameData(gameSys);
        BTL_SETUP_SetupCommMulti(setup, sysData, GFL_NET_HANDLE_GetCurrentHandle(), 1, request->multiTeam, 4);
        break;
    default:
        func_02034714((const char *)d_0217277C, 0, (const char *)d_0217277C);
        return 0;
    }
    BTL_SETUP_SetParty(setup, request->party, 0);
    BTL_SETUP_ApplyRegulation(setup, request->regulation, 4);
    setup->bgmBattle = request->bgmBattle;
    work->slot->formation = formation;
    work->slot->flag = 0;
    BTL_SETUP_AllocRecordBuffer(setup, 1);
    return event;
}

/*
 * Stores value into *formation only while it still holds the unset
 * sentinel 0x29, so the first call wins.
 */
void func_02157650(int *formation, int value)
{
    if (*formation == 0x29)
        *formation = value;
}

/* Four empty leaves (unused callback slots). */
void func_0215765C(void)
{
}

void func_02157660(void)
{
}

void func_02157664(void)
{
}

void func_02157668(void)
{
}
