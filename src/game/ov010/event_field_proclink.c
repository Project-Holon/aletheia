/*
 * file:     event_field_proclink.c
 * unit:     yes
 * function: EVENT_FIELD_PROCLINK_CreatePokeListParam, EVENT_FIELD_PROCLINK_ReturnPokeList, EVENT_FIELD_PROCLINK_CreateZukanParam, EVENT_FIELD_PROCLINK_ReturnZukan, EVENT_FIELD_PROCLINK_CreatePokeStatusParam, EVENT_FIELD_PROCLINK_ReturnPokeStatus, EVENT_FIELD_PROCLINK_IsSpecialZone, EVENT_FIELD_PROCLINK_CreateBagParam, EVENT_FIELD_PROCLINK_ReturnBag, EVENT_FIELD_PROCLINK_CreateTrainerCardView, EVENT_FIELD_PROCLINK_ReturnTrainerCardView, EVENT_FIELD_PROCLINK_CreateTownMapParam, EVENT_FIELD_PROCLINK_ReturnTownMapSelect, EVENT_FIELD_PROCLINK_CreateConfigParam, EVENT_FIELD_PROCLINK_ReturnConfig, EVENT_FIELD_PROCLINK_StartConfigEvent, EVENT_FIELD_PROCLINK_CreateTrainerCardParam, EVENT_FIELD_PROCLINK_ReturnTrainerCard, EVENT_FIELD_PROCLINK_CreateMailParam, EVENT_FIELD_PROCLINK_ReturnMail, EVENT_FIELD_PROCLINK_UnloadMailOverlay, EVENT_FIELD_PROCLINK_CreateEvolutionParam, EVENT_FIELD_PROCLINK_ReturnEvolution, EVENT_FIELD_PROCLINK_CreateReportParam, EVENT_FIELD_PROCLINK_ReturnReport, EVENT_FIELD_PROCLINK_CreateFreeEvent, EVENT_FIELD_PROCLINK_FreeEventMain, EVENT_FIELD_PROCLINK_FreeAnimWork, EVENT_FIELD_PROCLINK_AnimEventMain, EVENT_FIELD_PROCLINK_CreateAnimEvent, EVENT_FIELD_PROCLINK_ObjAnimEventMain, EVENT_FIELD_PROCLINK_CreateObjAnimEvent, EVENT_FIELD_PROCLINK_StartObjAnim, EVENT_FIELD_PROCLINK_InitAnimNode, EVENT_FIELD_PROCLINK_ClearAnimNode, EVENT_FIELD_PROCLINK_IsAnimNodeDone, EVENT_FIELD_PROCLINK_UpdateAnimNode, EVENT_FIELD_PROCLINK_HopEventMain, EVENT_FIELD_PROCLINK_CreateHopEvent, EVENT_FIELD_PROCLINK_IsHopDone, EVENT_FIELD_PROCLINK_IsAnimFlagSet, EVENT_FIELD_PROCLINK_CreateCommExitEvent, EVENT_FIELD_PROCLINK_CommExitEventMain, EVENT_FIELD_PROCLINK_SetCommProcParam, EVENT_FIELD_PROCLINK_StartCommProc, EVENT_FIELD_PROCLINK_StartSeasonCommProc, EVENT_FIELD_PROCLINK_CheckZoneFlag, EVENT_FIELD_PROCLINK_InitEventdataSystem, EVENT_FIELD_PROCLINK_GetEventdataEntry
 * address:  0x02160A94
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
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_SetCommBlocked  0x0201213C  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_02012944  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GAME_DATA_GetMyParty   0x02012934  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02034AC4 0x02034AC4 arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   ZONEDATA_IsZone96Pair 0x02013CE0 thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   GAME_DATA_GetField114  0x020127A4  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   POKE_TOOL_HasRibbonData  0x0201897C  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   MAILTOOL_HasMail  0x021C3E00  thumb  ov136
 *   ov136_id       0x00000088  data
 *   d_02172978     0x02172978  data  a1
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   FIELD_SOUND_SYSTEM_LowerVolume  0x02029DBC  thumb
 *   FIELD_SOUND_SYSTEM_RestoreVolume 0x02029DD8 thumb
 *   sub_02030734   0x02030734  arm
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   ICA_ANIME_GetField114 0x020120F8 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_IsZone1A6 0x02013CC8 thumb
 *   BAG_PARAM_Create  0x0202E474  thumb
 *   func_02008298  0x02008298  thumb
 *   FILE_UTIL_Check136C  0x0202136C  thumb
 *   TRCARD_SYS_CreateViewWork  0x0216F7BC  thumb  ov010
 *   GAME_DATA_GetField16C  0x020128B8  thumb
 *   func_0202138C  0x0202138C  thumb
 *   MAILTOOL_CreateWriteArgs  0x021C3CC0  thumb  ov136
 *   MAILTOOL_CreateArgsFromPartyMon  0x021C3D44  thumb  ov136
 *   MAILTOOL_CreateArgsFromMail  0x021C3DA4  thumb  ov136
 *   MAILTOOL_StoreMailToPartyMon 0x021C3E04 thumb ov136
 *   MAILTOOL_DeleteArgs 0x021C3E24 thumb ov136
 *   SHINKA_CHECK_CheckEvolution  0x0201B2B0  thumb
 *   REPORT_EVENT_Main  0x02169AB8  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_SysSearchMoveCode  0x0216DE54  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_OffMoveBitMovePause  0x0216DB04  thumb  ov010
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLDMMDL_ACMD_ListCreate  0x02197D3C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   d_02171404     0x02171404  data  a1
 *   d_021713FC     0x021713FC  data  a1
 *   d_021713F4     0x021713F4  data  a1
 *   d_021713EC     0x021713EC  data  a1
 *   FLDMMDL_SysSearchObjId 0x0216DE94 thumb ov010
 *   FLDMMDL_ACMD_ListCheckEnd  0x02197DA0  thumb
 *   FLDMMDL_ACMD_ListDelete  0x02197DAC  thumb
 *   d_0217140C     0x0217140C  data
 *   FX_Div         0x0207C768  arm
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDEFF_KEMURI_Start  0x021AC528  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   VEC_Subtract  0x0207CA00  arm
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   GAME_BEACON_SEARCH_SetSimpleEventB  0x0216570C  thumb  ov010
 *   GAMESYSTEM_IsCommBlocked  0x02012144  thumb
 *   gDemo3dProcData     0x021BFB3C  data  ov203
 *   ov203_id       0x000000CB  data
 *   func_02008550  0x02008550  thumb
 *   GF_STANDARD_SetField00 0x0203F4CC arm
 *   func_0202E888 0x0202E888 thumb
 *   FIELD_CLOCK_GetHour 0x02169100 thumb ov010
 *   FIELD_CLOCK_GetMinute 0x02169110 thumb ov010
 *   func_02013A80  0x02013A80  thumb
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry 0x02161E78 thumb ov010
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb
 */



typedef unsigned char u8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned int u32;

typedef enum { FALSE, TRUE } Bool;

typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct GameEvent GameEvent;
typedef struct GameComm GameComm;

#include "../ov131/p_status_types.h"

#include "field_event_types.h"



struct EscapeLocation {
    u8 reserved00[4];
    s16 zoneId;       /* 0x04 */
};


/* Bag screen parameter (0x3C bytes, from the bag creator). */
typedef struct BagParam {
    GameData *gameData;         /* 0x00 */
    void *myStatus;             /* 0x04 */
    void *myItem;               /* 0x08 */
    void *saveWork;             /* 0x0C */
    void *config;               /* 0x10 */
    u8 itemCheck[0x18];         /* 0x14 */
    u32 mode;                   /* 0x2C */
    u32 cycleFlag;              /* 0x30 */
    u8 reserved34[8];
} BagParam;

/* Setting byte pair read by the zone flag setter: 0 turns both off, 1 turns both on. */
typedef struct ZoneFlagSetting {
    u16 reserved00;
    u16 enable;                 /* 0x02 */
} ZoneFlagSetting;

/* One proc link entry (0x18 bytes); same layout as eventdata_system.c. */
typedef struct ProcLinkEntry {
    u8 active : 4;              /* 0x00: 0 = empty */
    u8 idFilter : 4;            /*       nonzero: only the ids below may use it */
    u8 age;                     /* 0x01 */
    u8 value;                   /* 0x02 */
    u8 kind;                    /* 0x03 */
    u16 allowedIds[8];          /* 0x04 */
    u8 reserved14[4];
} ProcLinkEntry;

/* Return list: two lists of ten entries, at +0x08 and +0xF8. */
typedef struct ProcLinkReturnList {
    u16 flags;                  /* 0x00 */
    u16 kind;                   /* 0x02 */
    u8 reserved04[4];
    ProcLinkEntry current[10];  /* 0x08 */
    ProcLinkEntry pending[10];  /* 0xF8 */
} ProcLinkReturnList;

typedef struct ZukanParam {
    GameData *gameData;         /* 0x00 */
    void *zukanSave;            /* 0x04 */
    u8 *myStatus;               /* 0x08 */
    u16 startSpecies;           /* 0x0C */
    u16 result;                 /* 0x0E */
} ZukanParam;

typedef struct ConfigParam {
    u32 result;                 /* 0x00 */
    GameSystem *gameSystem;     /* 0x04 */
} ConfigParam;

typedef struct TrainerCardParam {
    GameData *gameData;         /* 0x00 */
    u32 result;                 /* 0x04 */
} TrainerCardParam;

/* Town map (fly) screen parameter and result. */
typedef struct TownMapParam {
    u32 viewMode;               /* 0x00 */
    u32 result;                 /* 0x04 */
    u16 zoneId;                 /* 0x08: current zone in, chosen zone out */
    s16 escapeZoneId;  /* 0x0A */
    u32 selectedX;              /* 0x0C */
    u32 selectedZ;              /* 0x10 */
    GameSystem *gameSystem;     /* 0x14 */
} TownMapParam;

/* Trainer card view work: result at 0x10, first page at 0x14. */
typedef struct TrainerCardViewWork {
    u8 reserved00[0x10];
    int result;                 /* 0x10 */
    int startPage;              /* 0x14 */
} TrainerCardViewWork;

typedef struct ReportParam {
    u32 reserved00;
    GameData *gameData;         /* 0x04 */
    u32 reserved08;
    u32 result;                 /* 0x0C */
} ReportParam;


/* Object animation event: up to eight animation handles on a field object. */
typedef struct ObjAnimWork {
    GameSystem *gameSystem;     /* 0x00 */
    void *source;               /* 0x04 */
    GameData *gameData;         /* 0x08 */
    u16 fieldObjectId;          /* 0x0C */
    u8 reserved0E[2];
    const char *animName;       /* 0x10 */
    int handles[8];             /* 0x14 */
} ObjAnimWork;


/* Evolution demo request (0x14 bytes, read by the evolution overlay); same record as event_wificlub_types.h. */
typedef struct EvolutionRequest {
    GameData *gameData;         /* 0x00 */
    void *party;                /* 0x04 */
    u16 targetSpecies;          /* 0x08: result of the evolution check */
    u8 partySlot;               /* 0x0A */
    u8 evolveCondition;         /* 0x0B: how the evolution is triggered */
    u32 fromTrade;              /* 0x0C */
    u32 fromField;              /* 0x10 */
} EvolutionRequest;

/* Work of the map animation event: which map animations it started. */
typedef struct MapAnimWork {
    GameSystem *gameSystem;     /* 0x00 */
    void *fieldMap;             /* 0x04 */
    GameData *gameData;         /* 0x08 */
    u8 busyMask;                /* 0x0C: bit 0, 1, 2 = animation of the main, third, second object running */
} MapAnimWork;

/* Parameter block (0x18 bytes) for the comm proc started by the comm exit event. */
typedef struct CommProcParam {
    GameSystem *gameSystem;     /* 0x00 */
    u32 kind;                   /* 0x04 */
    u32 flags;                  /* 0x08 */
    u8 sub;                     /* 0x0C */
    u8 hour;                    /* 0x0D */
    u8 minute;                  /* 0x0E */
    u8 season : 7;              /* 0x0F */
    u8 flag : 1;
    u8 reserved10[8];
} CommProcParam;

/* Work of the comm exit event (0x24 bytes). */
typedef struct CommProcWork {
    GameSystem *gameSystem;     /* 0x00 */
    GameComm *gameComm;         /* 0x04 */
    CommProcParam procParam;    /* 0x08 */
    u32 savedCommBlocked;       /* 0x20 */
} CommProcWork;

typedef long long s64;

typedef int fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

/* Work of the hop event: a field object jumps from start to start + delta. */
typedef struct HopWork {
    void *owner;                /* 0x00 */
    void *object;               /* 0x04 */
    s16 frame;                  /* 0x08 */
    u8 pad0A[2];
    VecFx32 start;              /* 0x0C */
    VecFx32 delta;              /* 0x18 */
} HopWork;

typedef struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;


extern GameEvent *func_020122C0(GameSystem *gameSystem, void *parent, void *func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern GameData *ICA_ANIME_GetField1C(const GameSystem *gameSystem);


extern void *ICA_ANIME_GetField20(const GameSystem *gameSystem);


extern GameComm *ICA_ANIME_GetField24(const GameSystem *gameSystem);


extern int func_020307B0();

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);


extern u32 GAME_COMM_GetKind(GameComm *gameComm);
extern void GAME_COMM_RequestExitNoCallback(GameComm *gameComm);
extern void GAMESYSTEM_SetCommBlocked(GameSystem *gameSystem, u32 v);


extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);
u8 *func_02012944(const GameData *gameData);


extern void *GAME_DATA_GetSaveControl(const GameData *gameData);
extern void GAMESYSTEM_CallProc(GameSystem *gameSystem, u32 overlayId, const void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const GameSystem *gameSystem);


extern void *GAME_DATA_GetMyParty(const GameData *gameData);

extern void *func_0200873C(void *saveControl);


extern int func_02034AC4(int handle);


extern void MI_CpuFill8();


extern u32 ZONEDATA_IsZone96Pair(u32);
extern void *FIELDMAP_GetMmdlSys(void *fieldMap);


extern void FLDMMDL_SysPauseMove(void *fieldObjects);


extern u16 *GAME_DATA_GetField114(GameData *gameData);


extern void *FIELDMAP_GetMsgBg(void *);


extern u32 POKEPARTY_GetCount(void *party);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 POKE_TOOL_HasRibbonData(void *mon);


extern void *GAME_DATA_GetMyItem(const GameData *gameData);
extern void *func_02008FEC(GameData *gameData);
extern void *ZUKAN_SAVE_GetFromGameData(GameData *gameData);
extern u8 GAME_DATA_GetSeason(const GameData *gameData);
extern void func_02034A5C(int handle);
extern u32 MAILTOOL_HasMail(void *mailParam);
extern u32 GAME_DATA_GetBgmInfo(const GameData *gameData);
extern u32 GAMESYSTEM_GetIssSystem(const GameSystem *gameSystem);
extern void FIELD_SOUND_SYSTEM_LowerVolume(u8 *a, u32 b);
extern int FIELD_SOUND_SYSTEM_RestoreVolume(int,int);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(void *zukanSave);
extern u8 *ICA_ANIME_GetField114(const GameSystem *gameSystem);
extern u16 GAME_DATA_GetPlayerZoneId(const void *playerWork);
extern u32 ZONEDATA_IsZone1A6(u32);
extern BagParam *BAG_PARAM_Create(const GameData *gameData, u8 *itemCheck, int mode, int heapId);
extern void func_02008298(void *myItem, u16 pocket);
extern u32 FILE_UTIL_Check136C(u16 v);
extern TrainerCardViewWork *TRCARD_SYS_CreateViewWork(GameData *gameData, int mode, int canFly);
extern struct EscapeLocation *GAME_DATA_GetField16C(const GameData *gameData);
extern u8 func_0202138C(u16 v);
extern void *MAILTOOL_CreateWriteArgs(void *a, unsigned b, unsigned c, unsigned d, unsigned heap);
extern void *MAILTOOL_CreateArgsFromPartyMon(void *a, void *b, unsigned heap);
extern void *MAILTOOL_CreateArgsFromMail(void *a, void *b, unsigned heap);
extern int MAILTOOL_StoreMailToPartyMon(void *mailParam, void *mon);
extern void MAILTOOL_DeleteArgs(void *mailParam);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
extern int REPORT_EVENT_Main(ReportEventWork *work, int *state);
extern void *FLDMMDL_SysSearchPlayer(void *fieldObjects);
extern void *FLDMMDL_SysSearchMoveCode(void *fieldObjects, u32 kind);
extern int FLDMMDL_CheckEndAcmd(void *obj);
extern char *FLDMMDL_OffMoveBitMovePause(void *object);
extern int FLDMMDL_CheckMoveBitMove(void *obj);
extern void FLDMMDL_OnMoveBitMovePause(void *obj);
extern int FLDMMDL_ACMD_ListCreate(void *object, const char *animName);
extern void *FIELDMAP_GetFieldPlayer(void *fieldObject);
extern void *FIELD_PLAYER_GetMmdl(void *object);
extern u16 FLDMMDL_GetDirDisp(void *object);
extern void *FLDMMDL_SysSearchObjId(void *fieldObjects, unsigned int objectId);
extern int FLDMMDL_ACMD_ListCheckEnd();
extern int FLDMMDL_ACMD_ListDelete();
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern void FLDMMDL_SetPos(void *obj, const VecFx32 *pos);
extern void FLDMMDL_GetPos(void *object, VecFx32 *out);
extern void FLDMMDL_InitPosition(void *object, int *position, int direction);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void FLDEFF_KEMURI_Start(u32 object, u32 owner);
extern u32 FIELDMAP_GetEffect(void *fieldWork);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *out);
extern void *FLDMMDL_FreeAcmd(void *object);
extern void GAME_BEACON_SEARCH_SetSimpleEventB(void);
extern u8 GAMESYSTEM_IsCommBlocked(const GameSystem *gameSystem);
extern u8 func_02008550(const u8 *myStatus);
extern void GF_STANDARD_SetField00(RtcTime *time);
extern u8 func_0202E888(void);
extern int FIELD_CLOCK_GetHour(GameData *gameData);
extern int FIELD_CLOCK_GetMinute(GameData *gameData);
extern int func_02013A80();
extern void EVENT_FIELD_PROCLINK_ClearReturnEntry(ProcLinkEntry *entry);
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(ProcLinkEntry *entry);


PokeListParam *EVENT_FIELD_PROCLINK_CreatePokeListParam(ProcLinkWork *work, int kind, int mode, void *source);
int EVENT_FIELD_PROCLINK_ReturnPokeList(ProcLinkWork *work, PokeListParam *listResult);
ZukanParam *EVENT_FIELD_PROCLINK_CreateZukanParam(ProcLinkWork *work, int startSpecies);
Bool EVENT_FIELD_PROCLINK_ReturnZukan(ProcLinkWork *work, ZukanParam *param);
PStatusParam *EVENT_FIELD_PROCLINK_CreatePokeStatusParam(ProcLinkWork *work, int page, int mode, PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnPokeStatus(ProcLinkWork *work, PStatusParam *param);
int EVENT_FIELD_PROCLINK_IsSpecialZone(GameSystem *gameSystem);
BagParam *EVENT_FIELD_PROCLINK_CreateBagParam(ProcLinkWork *work, int lastFieldPocket, int bagMode, const PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnBag(ProcLinkWork *work, PokeListParam *listResult);
void EVENT_FIELD_PROCLINK_CreateTrainerCardView(ProcLinkWork *work, int startPage);
int EVENT_FIELD_PROCLINK_ReturnTrainerCardView(ProcLinkWork *work, TrainerCardViewWork *param);
TownMapParam *EVENT_FIELD_PROCLINK_CreateTownMapParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnTownMapSelect(ProcLinkWork *work, TownMapParam *param);
ConfigParam *EVENT_FIELD_PROCLINK_CreateConfigParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnConfig(int unused, ConfigParam *param);
void EVENT_FIELD_PROCLINK_StartConfigEvent(ProcLinkWork *work);
TrainerCardParam *EVENT_FIELD_PROCLINK_CreateTrainerCardParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnTrainerCard(ProcLinkWork *work, TrainerCardParam *param);
int EVENT_FIELD_PROCLINK_CreateMailParam(ProcLinkWork *work, int kind, int mode, const PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnMail(ProcLinkWork *work, void *mailParam);
void EVENT_FIELD_PROCLINK_UnloadMailOverlay(void *mailParam);
EvolutionRequest *EVENT_FIELD_PROCLINK_CreateEvolutionParam(ProcLinkWork *work, int kind, int mode, const PokeListParam *listResult);
int EVENT_FIELD_PROCLINK_ReturnEvolution(ProcLinkWork *work);
ReportParam *EVENT_FIELD_PROCLINK_CreateReportParam(ProcLinkWork *work);
int EVENT_FIELD_PROCLINK_ReturnReport(ProcLinkWork *work, ReportParam *param);
GameEvent *EVENT_FIELD_PROCLINK_CreateFreeEvent(GameSystem *gameSystem, void *fieldObject, u32 heapId, void *objectModel, u32 *resultOut);
int EVENT_FIELD_PROCLINK_FreeEventMain(void *event, int *state, ReportEventWork *work);
void EVENT_FIELD_PROCLINK_FreeAnimWork(void);
int EVENT_FIELD_PROCLINK_AnimEventMain(GameEvent *event, u32 *seq, MapAnimWork *work);
GameEvent *EVENT_FIELD_PROCLINK_CreateAnimEvent(GameSystem *gameSystem, void *fieldMap);
int EVENT_FIELD_PROCLINK_ObjAnimEventMain(void *task, int *state, ObjAnimWork *work);
GameEvent *EVENT_FIELD_PROCLINK_CreateObjAnimEvent(GameSystem *gameSystem, void *source, int fieldObjectId, const char *animName);
GameEvent *EVENT_FIELD_PROCLINK_StartObjAnim(GameSystem *gameSystem, void *source);
void *EVENT_FIELD_PROCLINK_InitAnimNode(void *fieldObjects, unsigned int objectId);
void EVENT_FIELD_PROCLINK_ClearAnimNode(ObjAnimWork *work);
ObjAnimWork *EVENT_FIELD_PROCLINK_IsAnimNodeDone(ObjAnimWork *work, int handle);
int EVENT_FIELD_PROCLINK_UpdateAnimNode(ObjAnimWork *work);
int EVENT_FIELD_PROCLINK_HopEventMain(GameEvent *event, u32 *seq, HopWork *work);
GameEvent *EVENT_FIELD_PROCLINK_CreateHopEvent(GameSystem *gameSystem, void *object, VecFx32 *start, VecFx32 *target);
int EVENT_FIELD_PROCLINK_IsHopDone(void *fieldObject);
int EVENT_FIELD_PROCLINK_IsAnimFlagSet(int handle);
GameEvent *EVENT_FIELD_PROCLINK_CreateCommExitEvent(GameSystem *gameSystem, GameEvent *parent, int kind, int sub, int useRealTime);
int EVENT_FIELD_PROCLINK_CommExitEventMain(GameEvent *event, int *state, CommProcWork *work);
void EVENT_FIELD_PROCLINK_SetCommProcParam(CommProcParam *param, GameSystem *gameSystem, int kind, u8 sub, u32 flags, u8 hour, u8 minute, u8 season);
void EVENT_FIELD_PROCLINK_StartCommProc(CommProcParam *param, GameSystem *gameSystem, u8 kind, u8 sub);
void EVENT_FIELD_PROCLINK_StartSeasonCommProc(CommProcParam *param, GameSystem *gameSystem, u8 kind, u8 sub);
int EVENT_FIELD_PROCLINK_CheckZoneFlag(ZoneFlagSetting *setting);
void EVENT_FIELD_PROCLINK_InitEventdataSystem(ProcLinkReturnList *list);
ProcLinkEntry *EVENT_FIELD_PROCLINK_GetEventdataEntry(ProcLinkReturnList *list, int id, unsigned mode);


extern u8 ov136_id[];
extern const char d_02172978[];
extern const char d_02171404[];
extern const char d_021713FC[];
extern const char d_021713F4[];
extern const char d_021713EC[];
extern const fx32 d_0217140C[];
extern u8 gDemo3dProcData[];
extern u8 ov203_id[];


/*
 * Allocate and fill the 0x98-byte request record for a link step: player
 * handles from the save, the 20-byte header copied out of the context, and
 * the next state (+0x34) chosen from the step kind and the peer's reply.
 */
PokeListParam *EVENT_FIELD_PROCLINK_CreatePokeListParam(ProcLinkWork *work, int kind, int mode, void *source)
{
    GameData *gameData;
    PokeListParam *list;
    const PokeListParam *listResult = source;
    const PStatusParam *statusResult = source;
    u32 value;

    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    list = func_02030734(4, 0x98, 1, d_02172978, 0x330);
    list->party = GAME_DATA_GetMyParty(gameData);
    list->carry = work->carry;
    list->myItem = GAME_DATA_GetMyItem(gameData);
    list->mailBox = func_02008FEC(gameData);
    list->zukanSave = ZUKAN_SAVE_GetFromGameData(gameData);
    list->listMode = 0;
    list->selectedSlot = work->context->partySlot;
    list->argValue2 = 0;
    value = 0xFF;
    list->fieldIndex = value;
    list->zoneId = *GAME_DATA_GetField114(gameData);
    list->season = GAME_DATA_GetSeason(gameData);
    if (kind == 5) {
        list->selectedSlot = 0;
        list->listMode = 5;
        value += 0xD3;
        list->argValue = value;
        work->linkMode = 1;
    } else if (mode == 0) {
        list->selectedSlot = 0;
    } else if (mode == 2) {
        list->argValue = listResult->listArg;
        if (listResult->listMode != 3 && listResult->listMode != 4 && listResult->listMode != 1 && listResult->listMode != 0x12)
            list->selectedSlot = 0;
        switch (listResult->listMode) {
        case 1:
            if (listResult->carry.words[4] == 2)
                list->listMode = 0;
            break;
        case 12:
            list->listMode = 0x10;
            break;
        case 2:
            list->listMode = 9;
            break;
        case 3:
        case 18:
            list->listMode = 10;
            break;
        case 4:
            list->listMode = 10;
            break;
        case 5:
            list->listMode = 5;
            break;
        case 6:
            list->listMode = 6;
            break;
        default:
            list->listMode = 9;
            break;
        }
    } else if (mode == 6) {
        switch (statusResult->retSel) {
        case 0:
        case 1:
            if (statusResult->mode == 2) {
                if (work->purpose == 6) {
                    list->listMode = 8;
                    list->resultParam = work->resultParam;
                } else {
                    list->listMode = 7;
                }
                list->argValue = work->resultValue;
                list->argValue2 = statusResult->newMove;
                if (statusResult->retSel == 0)
                    list->argByte = statusResult->retMovePos;
                else
                    list->argByte = 0xFF;
            } else {
                list->listMode = 0;
                list->selectedSlot = statusResult->pos;
            }
            break;
        }
    } else if (mode == 9) {
        int mailResult;

        func_02034AC4((u32)ov136_id);
        mailResult = MAILTOOL_HasMail(source);
        func_02034A5C((u32)ov136_id);
        if (work->purpose == 0) {
            list->listMode = 0xB;
            list->selectedSlot = work->resultSlot;
            list->argValue = work->resultValue;
        } else if (work->purpose == 2) {
            if (mailResult == 1) {
                list->listMode = 0xC;
                list->selectedSlot = work->resultSlot;
                list->argValue = work->resultValue;
            } else {
                list->listMode = 0;
                list->selectedSlot = work->resultSlot;
            }
        }
    } else if (mode == 10) {
        list->listMode = 5;
        list->argValue = work->resultValue;
    }
    return list;
}


/*
 * Unlabelled (the listing folds it into EVENT_FIELD_PROCLINK_CreatePokeListParam's extent). Consume a
 * reply record: copy its result into the context and pick the next state.
 */
int EVENT_FIELD_PROCLINK_ReturnPokeList(ProcLinkWork *work, PokeListParam *listResult)
{
    work->context->partySlot = listResult->selectedSlot;
    work->resultSlot = listResult->selectedSlot;
    if (work->linkMode == 1) {
        if (listResult->selectedSlot == 8)
            return 1;
        return 0;
    }
    switch (listResult->command) {
    case 0:
        if (listResult->listMode == 6 || work->context->originKind == 2) {
            work->nextState = 2;
            return 4;
        }
        if (listResult->selectedSlot == 8)
            return 1;
        return 0;
    case 1:
        work->nextState = 6;
        return 4;
    case 3:
        work->nextState = 2;
        return 4;
    case 10:
        work->nextState = 2;
        return 4;
    case 4:
    case 5:
        work->nextState = 6;
        work->resultValue = listResult->argValue;
        work->resultParam = listResult->resultParam;
        return 4;
    case 6:
    case 7:
        work->nextState = 9;
        return 4;
    case 8:
    case 9:
        work->nextState = 10;
        work->resultValue = listResult->argValue;
        return 4;
    case 11:
    case 12:
    case 13:
    case 14:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
        work->context->command = listResult->command - 11;
        return 2;
    case 15:
        work->nextState = 7;
        return 4;
    }
    return 1;
}


ZukanParam *EVENT_FIELD_PROCLINK_CreateZukanParam(ProcLinkWork *work, int startSpecies)
{
    ZukanParam *param;
    GameData *gameData;
    int bgmInfo;

    param = func_02030734(4, 0x10, 0, (const char *)d_02172978, 0x49b);
    MI_CpuFill8(param, 0, 0x10);
    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    param->gameData = gameData;
    param->zukanSave = ZUKAN_SAVE_GetFromGameData(gameData);
    param->myStatus = func_02012944(param->gameData);
    bgmInfo = GAME_DATA_GetBgmInfo(param->gameData);
    FIELD_SOUND_SYSTEM_LowerVolume((u8 *)bgmInfo, GAMESYSTEM_GetIssSystem(work->context->gameSystem));
    if (startSpecies != -1) {
        param->startSpecies = startSpecies;
    } else {
        param->startSpecies = 0;
    }
    return param;
}


Bool EVENT_FIELD_PROCLINK_ReturnZukan(ProcLinkWork *work, ZukanParam *param)
{
    u32 bgmInfo = GAME_DATA_GetBgmInfo(param->gameData);

    FIELD_SOUND_SYSTEM_RestoreVolume(bgmInfo, GAMESYSTEM_GetIssSystem(work->context->gameSystem));
    if (param->result == 0)
        return FALSE;
    else
        return TRUE;
}


/*
 * Allocate and fill the 0x28-byte battle setup for mode 0 (from the
 * caller's record) or mode 6 (from the save, picking the first party
 * slot that passes the kind's checks). Levers: both source words read
 * into locals before the two stores, the kind == -1 arm written as the
 * else so it lands at the tail, POKEPARTY_GetCount returning int.
 */
PStatusParam *EVENT_FIELD_PROCLINK_CreatePokeStatusParam(ProcLinkWork *work, int page, int mode, PokeListParam *listResult)
{
    PStatusParam *param;
    GameData *gameData;
    void *saveControl;
    void *zukanSave;
    void *party;
    void *mon;
    void *mailBox;
    int i;

    param = sub_02030734(4, sizeof(PStatusParam), 1, d_02172978, 0x4DE);
    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    zukanSave = ZUKAN_SAVE_GetFromGameData(gameData);
    param->ppt = 1;
    param->config = gameData;
    param->forceExit = 0;
    param->isNationalDex = ZUKAN_SAVE_IsNationalDexEnabled(zukanSave);
    if (mode == 0) {
        party = listResult->party;
        mailBox = listResult->playerSaveBlock;
        param->ppd = party;
        param->callerData = mailBox;
        param->max = POKEPARTY_GetCount(party);
        param->pos = listResult->selectedSlot;
        switch (listResult->command) {
        case 4:
            param->newMove = listResult->argValue2;
            param->mode = 2;
            param->page = 1;
            param->canUseButtons = 0;
            work->purpose = 5;
            break;
        case 5:
            param->newMove = listResult->argValue2;
            param->mode = 2;
            param->page = 1;
            param->canUseButtons = 0;
            work->purpose = 6;
            break;
        default:
            param->page = 0;
            param->mode = 0;
            param->canUseButtons = 1;
            break;
        }
    } else if (mode == 6) {
        param->callerData = func_0200873C(saveControl);
        param->ppd = GAME_DATA_GetMyParty(gameData);
        param->max = POKEPARTY_GetCount(GAME_DATA_GetMyParty(gameData));
        param->pos = 0;
        param->mode = 0;
        param->canUseButtons = 1;
        if (page != -1) {
            param->page = page;
            if (param->page == 2) {
                party = GAME_DATA_GetMyParty(gameData);
                for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
                    mon = POKEPARTY_GetMember(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && POKE_TOOL_HasRibbonData(mon) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        param->pos = i;
                        break;
                    }
                }
            } else if (param->page == 1) {
                party = GAME_DATA_GetMyParty(gameData);
                for (i = 0; i < (int)POKEPARTY_GetCount(party); i++) {
                    mon = POKEPARTY_GetMember(party, i);
                    if (func_02017E1C(mon, 0xA9, 0) && func_02017E1C(mon, 0x4C, 0) == 0) {
                        param->pos = i;
                        break;
                    }
                }
            }
        } else {
            param->page = 0;
        }
    }
    return param;
}


/*
 * Leaf after EVENT_FIELD_PROCLINK_CreatePokeStatusParam's pool (0x02160F88, no func_ label in the
 * listing; reached through a pointer, not a bl).
 */
int EVENT_FIELD_PROCLINK_ReturnPokeStatus(ProcLinkWork *work, PStatusParam *param)
{
    switch (param->retSel) {
    case 0:
    case 1:
        if (work->context->originKind == 6)
            return 0;
        work->nextState = 0;
        return 4;
    case 2:
        return 1;
    }
    return 1;
}


int EVENT_FIELD_PROCLINK_IsSpecialZone(GameSystem *gameSystem)
{
    unsigned short zoneId = GAME_DATA_GetPlayerZoneId(ICA_ANIME_GetField114(gameSystem));

    if (ZONEDATA_IsZone1A6(zoneId) == 1)
        return 1;
    if (ZONEDATA_IsZone96Pair(zoneId) == 1)
        return 3;
    return 0;
}


/*
 * 2026-10-05 (wave P21): EXACT. Older note draft (60 B off) lacked the repeated
 * default body at the end of case 0 (the `b` to the next block at +0x72 is a cross-jumped
 * copy, see a-branch-to-the-next-case-block-is-a-repeated-case-body.md). Plain literals
 * (4, -1) match; the n local was not needed. Sets the dispatch table via explicit cases
 * 1 and 3..8 beside default.
 */
BagParam *EVENT_FIELD_PROCLINK_CreateBagParam(ProcLinkWork *work, int lastFieldPocket, int bagMode, const PokeListParam *listResult)
{
    GameData *gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    BagParam *bag;

    switch (bagMode) {
    case 2:
        bag = BAG_PARAM_Create(gameData, work->bagItemCheck, EVENT_FIELD_PROCLINK_IsSpecialZone(work->context->gameSystem), 4);
        if (lastFieldPocket != -1) {
            func_02008298(bag->saveWork, (u16)lastFieldPocket);
        }
        break;
    case 0:
        if (listResult->command == 3) {
            bag = BAG_PARAM_Create(gameData, work->bagItemCheck, 2, 4);
        } else {
            bag = BAG_PARAM_Create(gameData, work->bagItemCheck, EVENT_FIELD_PROCLINK_IsSpecialZone(work->context->gameSystem), 4);
        }
        break;
    case 1:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    default:
        bag = BAG_PARAM_Create(gameData, work->bagItemCheck, EVENT_FIELD_PROCLINK_IsSpecialZone(work->context->gameSystem), 4);
        break;
    }
    return bag;
}


/*
 * Menu selection dispatch: maps the chosen item (listResult->listMode) to the next
 * state, either a sub-mode (work->context->command, answer 3) or a follow-up
 * screen (work->nextState, answer 4).
 *
 * Levers (2026-09-28 tree_ov010_4): the arms in the image's block order
 * (not case order), and the party fetch in case 18 as its own statement
 * so w->ctx is reloaded after the calls.
 */
int EVENT_FIELD_PROCLINK_ReturnBag(ProcLinkWork *work, PokeListParam *listResult)
{
    void *party;

    switch (listResult->listMode) {
    case 0:
        return 1;
    case 1:
        if (listResult->carry.words[4] == 2) {
            work->nextState = 0;
            return 4;
        }
        return 0;
    case 12:
        work->nextState = 0;
        return 4;
    case 10:
    case 11:
        work->context->command = 0;
        return 3;
    case 13:
        work->context->command = 1;
        return 3;
    case 15:
        work->context->command = 3;
        return 3;
    case 16:
        work->context->command = 4;
        return 3;
    case 14:
        work->context->command = 2;
        return 3;
    case 8:
        work->nextState = 8;
        return 4;
    case 7:
        work->nextState = 7;
        return 4;
    case 17:
        work->nextState = 11;
        return 4;
    case 19:
        work->nextState = 9;
        return 4;
    case 18:
        party = GAME_DATA_GetMyParty(ICA_ANIME_GetField1C(work->context->gameSystem));
        if (func_02017E1C(POKEPARTY_GetMember(party, work->context->partySlot), 6, 0) != 0)
            work->nextState = 0;
        else
            work->nextState = 9;
        work->purpose = 2;
        return 4;
    case 20:
        work->context->command = 5;
        return 3;
    case 2:
        if (FILE_UTIL_Check136C(listResult->listArg) == 1)
            work->purpose = 0;
        work->nextState = 0;
        return 4;
    }
    work->nextState = 0;
    return 4;
}


void EVENT_FIELD_PROCLINK_CreateTrainerCardView(ProcLinkWork *work, int startPage)
{
    GameData *gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    u32 zoneId = *GAME_DATA_GetField114(gameData);
    int canFly = 1;
    int bgmInfo;
    TrainerCardViewWork *viewWork;

    bgmInfo = GAME_DATA_GetBgmInfo(gameData);
    FIELD_SOUND_SYSTEM_LowerVolume((u8 *)bgmInfo, GAMESYSTEM_GetIssSystem(work->context->gameSystem));
    if (ZONEDATA_IsZone1A6(zoneId) != 0 || (int)ZONEDATA_IsZone96Pair((u16)zoneId) != 0) {
        canFly = 0;
    }
    viewWork = TRCARD_SYS_CreateViewWork(gameData, 4, canFly);
    if (startPage != -1) {
        viewWork->startPage = startPage;
    }
}


int EVENT_FIELD_PROCLINK_ReturnTrainerCardView(ProcLinkWork *work, TrainerCardViewWork *param)
{
    GameData *gameData;
    int bgmInfo;

    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    bgmInfo = GAME_DATA_GetBgmInfo(gameData);
    FIELD_SOUND_SYSTEM_RestoreVolume(bgmInfo, GAMESYSTEM_GetIssSystem(work->context->gameSystem));
    if (param->result != 1)
        return 0;
    return 1;
}


/*
 * Allocates a 0x18-byte record (heap 4, clear, site string, tag 0x68A) and fills
 * it from the work's request record.
 */
TownMapParam *EVENT_FIELD_PROCLINK_CreateTownMapParam(ProcLinkWork *work)
{
    TownMapParam *param = func_02030734(4, 0x18, 1, d_02172978, 0x68A);
    void *playerWork;
    void *gameData;

    param->viewMode = 1;
    param->gameSystem = work->context->gameSystem;
    playerWork = GAME_DATA_GetField114(ICA_ANIME_GetField1C(work->context->gameSystem));
    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    param->zoneId = GAME_DATA_GetPlayerZoneId(playerWork);
    param->escapeZoneId = GAME_DATA_GetField16C(gameData)->zoneId;
    if (work->context->originKind == 0)
        param->viewMode = 0;
    else
        param->viewMode = 1;
    return param;
}


int EVENT_FIELD_PROCLINK_ReturnTownMapSelect(ProcLinkWork *work, TownMapParam *param)
{
    int originKind = work->context->originKind;
    if (originKind == 7) {
        switch (param->result) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (originKind == 2) {
        switch (param->result) {
        case 0:
            work->nextState = 2;
            return 4;
        case 1:
            return 1;
        default:
            return 1;
        }
    } else if (originKind == 0) {
        switch (param->result) {
        case 0:
            work->nextState = 0;
            return 4;
        case 1:
            return 1;
        case 2:
            work->context->command = 4;
            work->context->warpZoneId = param->zoneId;
            work->context->warpX = param->selectedX;
            work->context->warpZ = param->selectedZ;
            work->context->warpY = 0;
            return 2;
        default:
            return 1;
        }
    }
    return 1;
}


/*
 * Allocate an 8-byte record and store the save handle at +4. The extent
 * also holds the unlabelled leaf at 0x02161340 (nonzero test of *r1).
 */
ConfigParam *EVENT_FIELD_PROCLINK_CreateConfigParam(ProcLinkWork *work)
{
    ConfigParam *param;

    func_0200873C(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(work->context->gameSystem)));
    param = func_02030734(4, 8, 1, d_02172978, 0x705);
    param->gameSystem = work->context->gameSystem;
    return param;
}


int EVENT_FIELD_PROCLINK_ReturnConfig(int unused, ConfigParam *param)
{
    if (param->result != 0)
        return 1;
    return 0;
}


/*
 * Five arguments to the overlay builder: the two words of the descriptor,
 * the object's halfword, the descriptor's classification and a pointer to
 * the object's tail; the result goes to the arm9 call with the
 * object's word at +0x14.
 */
void EVENT_FIELD_PROCLINK_StartConfigEvent(ProcLinkWork *work)
{
    ProcLinkContext *context = work->context;
    void *objectModel = FIELDMAP_GetMsgBg(context->fieldObject);

    GAME_EVENT_CallEvent(work->event,
                  EVENT_FIELD_PROCLINK_CreateFreeEvent(context->gameSystem, context->fieldObject,
                                work->eventKind, objectModel, &work->resultFlag));
}


/*
 * Allocate an 8-byte record and store the save handle at +0.
 * The extent also holds the unlabelled leaf at 0x021613A4.
 */
TrainerCardParam *EVENT_FIELD_PROCLINK_CreateTrainerCardParam(ProcLinkWork *work)
{
    TrainerCardParam *param;

    param = func_02030734(4, 8, 1, d_02172978, 0x74C);
    param->gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    return param;
}


int EVENT_FIELD_PROCLINK_ReturnTrainerCard(ProcLinkWork *work, TrainerCardParam *param)
{
    if (work->context->originKind == 8) {
        switch (param->result) {
        case 0:
            return 0;
        default:
            return 1;
        }
    }
    switch (param->result) {
    case 0:
        work->nextState = 2;
        return 4;
    default:
        return 1;
    }
}


int EVENT_FIELD_PROCLINK_CreateMailParam(ProcLinkWork *work, int kind, int mode, const PokeListParam *listResult)
{
    GameData *gameData;
    void *party;
    u32 slot;
    int mailParam;
    u16 itemId;

    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    func_02034AC4((u32)ov136_id);
    if (mode == 0) {
        party = GAME_DATA_GetMyParty(gameData);
        slot = listResult->selectedSlot;
        work->resultSlot = slot;
        itemId = listResult->argValue;
        work->resultValue = itemId;
        if (listResult->command == 6)
            return (int)MAILTOOL_CreateWriteArgs(gameData, 2, (u8)listResult->selectedSlot, func_0202138C(itemId), 4);
        work->purpose = 1;
        return (int)MAILTOOL_CreateArgsFromPartyMon(gameData, POKEPARTY_GetMember(party, slot), 4);
    }
    if (listResult->carry.words[4] == 2) {
        mailParam = (int)MAILTOOL_CreateWriteArgs(gameData, 2, (u8)listResult->listArg, func_0202138C((u16)listResult->listArg), 4);
        work->resultValue = listResult->listArg;
        return mailParam;
    }
    work->purpose = 1;
    return (int)MAILTOOL_CreateArgsFromMail(gameData, (void *)func_0202138C((u16)listResult->listArg), 4);
}


/*
 * Lever: second state writes nextState separately in each arm; cross-jumping
 * retains the dead branch after MAILTOOL_StoreMailToPartyMon rather than after movs #0.
 */
int EVENT_FIELD_PROCLINK_ReturnMail(ProcLinkWork *work, void *mailParam)
{
    GameData *gameData;
    u32 nextState;

    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    if (work->childResult == 0) {
        if (work->purpose == 0 || work->purpose == 2) {
            if (MAILTOOL_HasMail(mailParam) == 1) {
                MAILTOOL_StoreMailToPartyMon(mailParam, POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), work->resultSlot));
                nextState = 0;
            } else if (work->purpose == 0) {
                nextState = 2;
            } else {
                nextState = 0;
            }
        } else {
            nextState = 0;
        }
        work->nextState = nextState;
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    if (work->childResult == 2) {
        if (work->purpose == 2) {
            if (MAILTOOL_HasMail(mailParam) == 1) {
                MAILTOOL_StoreMailToPartyMon(mailParam, POKEPARTY_GetMember(GAME_DATA_GetMyParty(gameData), work->resultSlot));
                work->nextState = 0;
            } else {
                work->nextState = 0;
            }
        } else {
            work->nextState = 2;
        }
        func_02034A5C((u32)ov136_id);
        return 4;
    }
    work->nextState = 2;
    func_02034A5C((u32)ov136_id);
    return 4;
}


void EVENT_FIELD_PROCLINK_UnloadMailOverlay(void *mailParam)
{
    func_02034AC4((u32)ov136_id);
    MAILTOOL_DeleteArgs(mailParam);
    func_02034A5C((u32)ov136_id);
}


EvolutionRequest *EVENT_FIELD_PROCLINK_CreateEvolutionParam(ProcLinkWork *work, int kind, int mode, const PokeListParam *listResult)
{
    EvolutionRequest *request;
    GameData *gameData;
    void *party;
    void *mon;
    u32 method;
    u32 targetSpecies;
    u8 season;

    gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    request = 0;
    if (mode == 0) {
        party = GAME_DATA_GetMyParty(gameData);
        if (listResult->command == 8) {
            work->purpose = 3;
            mon = POKEPARTY_GetMember(party, listResult->selectedSlot);
            season = GAME_DATA_GetSeason(gameData);
            targetSpecies = SHINKA_CHECK_CheckEvolution(party, mon, 3, listResult->argValue, season, &method, 4);
        } else {
            work->purpose = 4;
            mon = POKEPARTY_GetMember(party, listResult->selectedSlot);
            targetSpecies = SHINKA_CHECK_CheckEvolution(party, mon, 0, *GAME_DATA_GetField114(gameData), GAME_DATA_GetSeason(gameData), &method, 4);
        }
        request = func_02030734(4, 0x14, 0, d_02172978, 0x868);
        request->gameData = gameData;
        request->party = party;
        request->targetSpecies = targetSpecies;
        request->partySlot = listResult->selectedSlot;
        request->evolveCondition = method;
        request->fromTrade = 1;
        request->fromField = 1;
    }
    return request;
}


int EVENT_FIELD_PROCLINK_ReturnEvolution(ProcLinkWork *work)
{
    ICA_ANIME_GetField1C(work->context->gameSystem);
    if (work->purpose == 3) {
        work->nextState = 2;
        return 4;
    }
    if (work->purpose == 4) {
        work->nextState = 0;
        return 4;
    }
    return 0;
}


/*
 * Allocate an 0x10-byte record and store the save handle at +4.
 * The extent also holds the unlabelled leaf at 0x02161668.
 */
ReportParam *EVENT_FIELD_PROCLINK_CreateReportParam(ProcLinkWork *work)
{
    ReportParam *param;

    param = func_02030734(4, 0x10, 1, d_02172978, 0x8AC);
    param->gameData = ICA_ANIME_GetField1C(work->context->gameSystem);
    return param;
}


int EVENT_FIELD_PROCLINK_ReturnReport(ProcLinkWork *work, ReportParam *param)
{
    if (work->context->originKind == 0xb) {
        switch (param->result) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return 0;
        }
    }
    switch (param->result) {
    case 0:
        work->nextState = 2;
        return 4;
    case 1:
        return 1;
    default:
        return 0;
    }
}


/*
 * Allocator with callback, zero-fills the node, then fills link fields.
 */
GameEvent *EVENT_FIELD_PROCLINK_CreateFreeEvent(GameSystem *gameSystem, void *fieldObject, u32 heapId, void *objectModel, u32 *resultOut)
{
    GameEvent *event = func_020122C0(gameSystem, 0, EVENT_FIELD_PROCLINK_FreeEventMain, 0x1C);
    ReportEventWork *work = func_020124E8(event);

    MI_CpuFill8(work, 0, 0x1C);
    work->msgContext = objectModel;
    work->heapId = heapId;
    work->gameSystem = gameSystem;
    work->fieldMap = fieldObject;
    work->saveControl = GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(gameSystem));
    work->resultOut = resultOut;
    return event;
}


int EVENT_FIELD_PROCLINK_FreeEventMain(void *event, int *state, ReportEventWork *work)
{
    switch (REPORT_EVENT_Main(work, state)) {
    case 0:
        *work->resultOut = 1;
        return 1;
    case 1:
        *work->resultOut = 0;
        return 1;
    }
    return 0;
}


/* Thumb tail call into the ARM function func_020307B0: ldr r3,[pc]; bx r3. */
void EVENT_FIELD_PROCLINK_FreeAnimWork(void)
{
    func_020307B0();
}


/*
 * Three-step sequence over the field map's objects: step 0 starts the
 * animations that are not yet running and records them in work->busyMask, step
 * 1 waits until every recorded one has finished, step 2 answers done.
 *
 * The image keeps a second object that is always NULL (`movs r6, #0;
 * beq` reuses the movs flags, and the NULL is still passed to
 * FLDMMDL_CheckMoveBitMove in step 1): written as a pointer local set to 0 and
 * tested. work->fieldMap is read into a local before the switch.
 */
int EVENT_FIELD_PROCLINK_AnimEventMain(GameEvent *event, u32 *seq, MapAnimWork *work)
{
    void *fieldObjects;
    void *mainObject;
    void *unusedObject;
    void *thirdObject;
    void *fieldMap;

    fieldMap = work->fieldMap;
    switch (*seq) {
    case 0:
        fieldObjects = FIELDMAP_GetMmdlSys(fieldMap);
        mainObject = FLDMMDL_SysSearchPlayer(fieldObjects);
        FLDMMDL_SysSearchMoveCode(fieldObjects, 0x30);
        work->busyMask = 0;
        FLDMMDL_SysPauseMove(fieldObjects);
        if (FLDMMDL_CheckEndAcmd(mainObject) == 0) {
            work->busyMask |= 1;
            FLDMMDL_OffMoveBitMovePause(mainObject);
        }
        unusedObject = 0;
        if (unusedObject != 0 && FLDMMDL_CheckMoveBitMove(unusedObject) == 1) {
            work->busyMask |= 4;
            FLDMMDL_OffMoveBitMovePause(unusedObject);
        }
        (*seq)++;
        break;
    case 1:
        fieldObjects = FIELDMAP_GetMmdlSys(fieldMap);
        mainObject = FLDMMDL_SysSearchPlayer(fieldObjects);
        FLDMMDL_SysSearchMoveCode(fieldObjects, 0x30);
        if ((work->busyMask & 1) && FLDMMDL_CheckEndAcmd(mainObject) == 1) {
            FLDMMDL_OnMoveBitMovePause(mainObject);
            work->busyMask &= ~1;
        }
        if (work->busyMask & 4) {
            unusedObject = 0;
            if (FLDMMDL_CheckMoveBitMove(unusedObject) == 0) {
                FLDMMDL_OnMoveBitMovePause(unusedObject);
                work->busyMask &= ~4;
            }
        }
        if (work->busyMask & 2) {
            thirdObject = FLDMMDL_SysSearchMoveCode(fieldObjects, 0x30);
            if (FLDMMDL_CheckMoveBitMove(thirdObject) == 0) {
                FLDMMDL_OnMoveBitMovePause(thirdObject);
                work->busyMask &= ~2;
            }
        }
        if (work->busyMask == 0)
            (*seq)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


GameEvent *EVENT_FIELD_PROCLINK_CreateAnimEvent(GameSystem *gameSystem, void *fieldMap)
{
    GameEvent *event;
    MapAnimWork *work;

    event = func_020122C0(gameSystem, 0, EVENT_FIELD_PROCLINK_AnimEventMain, 0x10);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->gameData = ICA_ANIME_GetField1C(gameSystem);
    return event;
}


int EVENT_FIELD_PROCLINK_ObjAnimEventMain(void *task, int *state, ObjAnimWork *work)
{
    void *fieldObjects;

    fieldObjects = FIELDMAP_GetMmdlSys(work->source);
    switch (*state) {
    case 0:
        fieldObjects = EVENT_FIELD_PROCLINK_InitAnimNode(fieldObjects, work->fieldObjectId);
        if (fieldObjects == 0)
            return 1;
        EVENT_FIELD_PROCLINK_IsAnimNodeDone(work, FLDMMDL_ACMD_ListCreate(fieldObjects, work->animName));
        *state = *state + 1;
        break;
    case 1:
        if (EVENT_FIELD_PROCLINK_UpdateAnimNode(work) == 0)
            return 1;
        break;
    }
    return 0;
}


/*
 * Allocator with callback, then a sub-init call and link fields.
 */
GameEvent *EVENT_FIELD_PROCLINK_CreateObjAnimEvent(GameSystem *gameSystem, void *source, int fieldObjectId, const char *animName)
{
    GameEvent *event = func_020122C0(gameSystem, 0, EVENT_FIELD_PROCLINK_ObjAnimEventMain, 0x34);
    ObjAnimWork *work = func_020124E8(event);

    EVENT_FIELD_PROCLINK_ClearAnimNode(work);
    work->gameSystem = gameSystem;
    work->source = source;
    work->gameData = ICA_ANIME_GetField1C(gameSystem);
    work->fieldObjectId = fieldObjectId;
    work->animName = animName;
    return event;
}


GameEvent *EVENT_FIELD_PROCLINK_StartObjAnim(GameSystem *gameSystem, void *source)
{
    const char *animName;

    switch (FLDMMDL_GetDirDisp(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(source)))) {
    case 0:
        animName = d_02171404;
        break;
    case 1:
        animName = d_021713FC;
        break;
    case 2:
        animName = d_021713F4;
        break;
    case 3:
        animName = d_021713EC;
        break;
    }
    return EVENT_FIELD_PROCLINK_CreateObjAnimEvent(gameSystem, source, 0xFF, animName);
}


void *EVENT_FIELD_PROCLINK_InitAnimNode(void *fieldObjects, unsigned int objectId)
{
    if (objectId == 0xf2)
        return FLDMMDL_SysSearchMoveCode(fieldObjects, 0x30);
    else if (objectId != 0xf1)
        return FLDMMDL_SysSearchObjId(fieldObjects, objectId);
    return fieldObjects;
}


void EVENT_FIELD_PROCLINK_ClearAnimNode(ObjAnimWork *work)
{
    int i = 0;
    int zero = i;

    for (; i < 8; i++)
        work->handles[i] = zero;
}


ObjAnimWork *EVENT_FIELD_PROCLINK_IsAnimNodeDone(ObjAnimWork *work, int handle)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (work->handles[i] == 0) {
            work->handles[i] = handle;
            return work;
        }
    }
    return work;
}


int EVENT_FIELD_PROCLINK_UpdateAnimNode(ObjAnimWork *work)
{
    int stillRunning = 0;
    int i;

    for (i = 0; i < 8; i++) {
        if (work->handles[i] == 0)
            continue;
        if (FLDMMDL_ACMD_ListCheckEnd(work->handles[i]) == 1) {
            FLDMMDL_ACMD_ListDelete(work->handles[i]);
            work->handles[i] = 0;
        } else {
            stillRunning = 1;
        }
    }
    return stillRunning;
}


static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}


/*
 * Hop-and-land movement of a field object: state 0 follows the arc table
 * d_0217140C while sliding along (dx, dz) over 15 frames, state 1 drops
 * it 8.0 per frame onto start + delta, then snaps it there, plays the
 * landing sound and answers done.
 *
 * Levers (2026-09-28 tree_ov010_4): the frame test as `t > 15u` (cmp #15;
 * bls on the ldrsh), and the landing height read into a local before the
 * drop is computed.
 */
int EVENT_FIELD_PROCLINK_HopEventMain(GameEvent *event, u32 *seq, HopWork *work)
{
    VecFx32 pos;
    fx32 dropY;
    fx32 landingY;
    int done;

    done = 0;
    switch (*seq) {
    case 0:
        pos = work->start;
        pos.y += d_0217140C[work->frame];
        work->frame += 2;
        pos.x += FX_Div(FX_Mul(work->delta.x, work->frame << 12), 15 << 12);
        pos.z += FX_Div(FX_Mul(work->delta.z, work->frame << 12), 15 << 12);
        FLDMMDL_SetPos(work->object, &pos);
        if (work->frame > 15u)
            (*seq)++;
        break;
    case 1:
        FLDMMDL_GetPos(work->object, &pos);
        landingY = work->start.y + work->delta.y;
        dropY = pos.y - 0x8000;
        if (dropY > landingY) {
            pos.y = dropY;
            FLDMMDL_SetPos(work->object, &pos);
        } else {
            pos.y = landingY;
            done = 1;
            pos.x = work->start.x + work->delta.x;
            pos.z = work->start.z + work->delta.z;
            FLDMMDL_InitPosition(work->object, (int *)(&pos), FLDMMDL_GetDirDisp(work->object));
            GFL_USE_PlaySeDefaultVolume(0x67B);
            FLDEFF_KEMURI_Start((u32)work->object, (u32)work->owner);
        }
        break;
    }
    return done;
}


GameEvent *EVENT_FIELD_PROCLINK_CreateHopEvent(GameSystem *gameSystem, void *object, VecFx32 *start, VecFx32 *target)
{
    GameEvent *event;
    HopWork *work;

    event = func_020122C0(gameSystem, 0, EVENT_FIELD_PROCLINK_HopEventMain, 0x24);
    work = func_020124E8(event);
    work->object = object;
    work->owner = (void *)FIELDMAP_GetEffect(ICA_ANIME_GetField20(gameSystem));
    work->start = *start;
    VEC_Subtract(target, start, &work->delta);
    GFL_USE_PlaySeDefaultVolume(0x55E);
    return event;
}


int EVENT_FIELD_PROCLINK_IsHopDone(void *fieldObject)
{
    const char *animName;
    void *object;

    object = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldObject));
    switch (FLDMMDL_GetDirDisp(object)) {
    case 0:
        animName = d_02171404;
        break;
    case 1:
        animName = d_021713FC;
        break;
    case 2:
        animName = d_021713F4;
        break;
    case 3:
        animName = d_021713EC;
        break;
    }
    FLDMMDL_FreeAcmd(object);
    return FLDMMDL_ACMD_ListCreate(object, animName);
}


int EVENT_FIELD_PROCLINK_IsAnimFlagSet(int handle)
{
    if (FLDMMDL_ACMD_ListCheckEnd(handle) == 1) {
        FLDMMDL_ACMD_ListDelete(handle);
        return 1;
    }
    return 0;
}


GameEvent *EVENT_FIELD_PROCLINK_CreateCommExitEvent(GameSystem *gameSystem, GameEvent *parent, int kind, int sub, int useRealTime)
{
    GameEvent *event;
    CommProcWork *work;

    event = func_020122C0(gameSystem, parent, EVENT_FIELD_PROCLINK_CommExitEventMain, 0x24);
    work = func_020124E8(event);
    MI_CpuFill8(work, 0, 0x24);
    work->gameSystem = gameSystem;
    work->gameComm = ICA_ANIME_GetField24(gameSystem);
    if (useRealTime != 0)
        EVENT_FIELD_PROCLINK_StartCommProc(&work->procParam, gameSystem, kind, sub);
    else
        EVENT_FIELD_PROCLINK_StartSeasonCommProc(&work->procParam, gameSystem, kind, sub);
    if (kind == 3)
        GAME_BEACON_SEARCH_SetSimpleEventB();
    return event;
}


int EVENT_FIELD_PROCLINK_CommExitEventMain(GameEvent *event, int *state, CommProcWork *work)
{
    switch (*state) {
    case 0:
        work->savedCommBlocked = GAMESYSTEM_IsCommBlocked(work->gameSystem);
        GAMESYSTEM_SetCommBlocked(work->gameSystem, 1);
        if (GAME_COMM_GetKind(work->gameComm) == 0) {
            *state = *state + 2;
        } else {
            GAME_COMM_RequestExitNoCallback(work->gameComm);
            *state = *state + 1;
        }
        break;
    case 1:
        if (GAME_COMM_GetKind(work->gameComm) == 0)
            *state = *state + 1;
        break;
    case 2:
        GAMESYSTEM_CallProc(work->gameSystem, (u32)ov203_id, gDemo3dProcData, &work->procParam);
        *state = *state + 1;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(work->gameSystem) == 0) {
            GAMESYSTEM_SetCommBlocked(work->gameSystem, work->savedCommBlocked);
            return 1;
        }
        break;
    }
    return 0;
}


void EVENT_FIELD_PROCLINK_SetCommProcParam(CommProcParam *param, GameSystem *gameSystem, int kind, u8 sub, u32 flags, u8 hour, u8 minute, u8 season)
{
    MI_CpuFill8(param, 0, 0x18);
    param->gameSystem = gameSystem;
    param->kind = kind;
    param->sub = sub;
    param->flags = flags;
    param->hour = hour;
    param->minute = minute;
    param->season = season;
    param->flag = (u8)(int)func_02008550(func_02012944(ICA_ANIME_GetField1C(gameSystem)));
}


void EVENT_FIELD_PROCLINK_StartCommProc(CommProcParam *param, GameSystem *gameSystem, u8 kind, u8 sub)
{
    RtcTime time;
    u8 season;

    GF_STANDARD_SetField00(&time);
    season = func_0202E888();
    EVENT_FIELD_PROCLINK_SetCommProcParam(param, gameSystem, kind, sub, 0, time.hour, time.minute, season);
}


/*
 * Padding: two zero alignment bytes after the 74-byte function.
 * Lever: kind and sub are u8, as in matched caller ov010_func_02161B90.c;
 * this puts the kind home store before r0 is assigned gameSystem for the first call.
 */
void EVENT_FIELD_PROCLINK_StartSeasonCommProc(CommProcParam *param, GameSystem *gameSystem, u8 kind, u8 sub)
{
    GameData *gameData = ICA_ANIME_GetField1C(gameSystem);
    int hour = FIELD_CLOCK_GetHour(gameData);
    int minute = FIELD_CLOCK_GetMinute(gameData);
    u8 season = GAME_DATA_GetSeason(gameData);

    EVENT_FIELD_PROCLINK_SetCommProcParam(param, gameSystem, kind, sub, 0, (u8)hour, (u8)minute, season);
}


int EVENT_FIELD_PROCLINK_CheckZoneFlag(ZoneFlagSetting *setting)
{
    int result;

    result = setting->enable;
    if (result == 1) {
        func_02013A80(0, 1);
        result = func_02013A80(1, 1);
    }
    result = setting->enable;
    if (result == 0) {
        func_02013A80(0, 0);
        result = func_02013A80(1, 0);
    }
    return result;
}


void EVENT_FIELD_PROCLINK_InitEventdataSystem(ProcLinkReturnList *list)
{
    int i;

    list->flags = 0;
    list->kind = 2;
    for (i = 0; i < 10; i++) {
        EVENT_FIELD_PROCLINK_ClearReturnEntry(&list->current[i]);
        EVENT_FIELD_PROCLINK_ClearReturnEntry(&list->pending[i]);
    }
}


ProcLinkEntry *EVENT_FIELD_PROCLINK_GetEventdataEntry(ProcLinkReturnList *list, int id, unsigned mode)
{
    int i;
    ProcLinkEntry *pending;
    ProcLinkEntry *current;
    unsigned modeMinus1;

    modeMinus1 = mode - 1;
    current = list->current;
    i = 0;
    pending = list->pending;

    for (; i < 10; i++) {
        if (mode == 0 || mode == 2) {
            if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&current[i]) != 0 && list->current[i].age == id)
                return &list->current[i];
        }
        if (modeMinus1 <= 1) {
            if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(&pending[i]) != 0 && list->pending[i].age == id)
                return &list->pending[i];
        }
    }
    return 0;
}
