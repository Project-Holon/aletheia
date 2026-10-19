/*
 * file:     move_pokemon.c
 * unit:     yes
 * function: MOVE_POKEMON_MoveEntry, MOVE_POKEMON_MoveActiveEntries, MOVE_POKEMON_MoveActiveEntriesChecked, MOVE_POKEMON_GetEntryZoneId, MOVE_POKEMON_HasActiveEntry, MOVE_POKEMON_SetCommonArea, MOVE_POKEMON_SpawnEntry, MOVE_POKEMON_SpawnPendingEntries, MOVE_POKEMON_HandleBattleResult, MOVE_POKEMON_FindEntryByZone, MOVE_POKEMON_IsAnyEntryActive, MOVE_POKEMON_GetEntryIndexBySpecies, MOVE_POKEMON_MoveToNeighbor, MOVE_POKEMON_SetEntryLocation, MOVE_POKEMON_FindEntryBySpecies, MOVE_POKEMON_InitSkillInfo, MOVE_POKEMON_IsSkillBlocked, MOVE_POKEMON_InitSkillTarget, MOVE_POKEMON_CreateSkillEvent, MOVE_POKEMON_CheckCut, MOVE_POKEMON_CreateCutEvent, MOVE_POKEMON_CutEventMain, MOVE_POKEMON_CheckFly, MOVE_POKEMON_CreateFlyEvent, MOVE_POKEMON_FlyEventMain, MOVE_POKEMON_CheckSurf, MOVE_POKEMON_CreateSurfEvent, MOVE_POKEMON_SurfEventMain, MOVE_POKEMON_CheckStrength, MOVE_POKEMON_CreateStrengthEvent, MOVE_POKEMON_StrengthEventMain, MOVE_POKEMON_IsSkill8Unusable, MOVE_POKEMON_CreateDiveEvent, MOVE_POKEMON_StartSkillOnTarget, MOVE_POKEMON_CheckWaterfall, MOVE_POKEMON_CheckFlash, MOVE_POKEMON_CreateFlashEvent, MOVE_POKEMON_FlashEventMain, MOVE_POKEMON_CheckDig, MOVE_POKEMON_CreateDigEvent, MOVE_POKEMON_DigEventMain, MOVE_POKEMON_CheckTeleport, MOVE_POKEMON_CreateTeleportEvent, MOVE_POKEMON_TeleportEventMain, MOVE_POKEMON_CheckMilkDrink, MOVE_POKEMON_CreateMilkDrinkEvent, MOVE_POKEMON_MilkDrinkEventMain, MOVE_POKEMON_CheckSweetScent, MOVE_POKEMON_StartSweetScent, MOVE_POKEMON_SweetScentEventMain, MOVE_POKEMON_CreateSweetScentEvent, MOVE_POKEMON_SoftBoiledEventMain, MOVE_POKEMON_CreateSoftBoiledEvent, MOVE_POKEMON_GetSkillCheckFunc, MOVE_POKEMON_GetSkillEventFunc, MOVE_POKEMON_InitSkillWork, MOVE_POKEMON_IsSkillUsable, MOVE_POKEMON_IsInSkillArea
 * address:  0x0215E358
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_musical.c, move_pokemon.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
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
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
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
 *   FIELD_PLAYER_CheckSurfStartAttr  0x021A3504  thumb  ov021
 *   FIELD_PLAYER_CheckWaterfallClimbAttr  0x021A3524  thumb  ov021
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
 *   GAME_BEACON_SEARCH_SetCountValue  0x02165534  thumb  ov010
 *   FLD_WIPE_3DOBJ_CreateMapChangeEvent  0x021C8268  thumb
 *   FIELDMAP_GetMapEff  0x02189A10  thumb  ov021
 *   FIELDSKILL_MAPEFF_GetFlash  0x021C7FBC  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   FIELD_STATUS_IsFlashActive  0x02014468  thumb
 *   FIELD_STATUS_SetFlashActive  0x02014464  thumb
 *   FIELD_FLASH_SetPendingCommand  0x021C7E50  thumb  ov021
 *   FIELD_STATUS_SetMapEffectMask  0x0201446C  thumb
 *   FIELD_FLASH_GetState  0x021C7E54  thumb  ov021
 *   EVENT_MAPCHANGE_CreateEscapeRopeEvent  0x02184EEC  thumb  ov020
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   EVENT_MAPCHANGE_CreateSituationWarpEvent  0x02184F40  thumb  ov020
 *   EVENT_PERAP_RECORD_Create   0x021D1C24  thumb
 *   d_02171258 0x02171258 data a4
 *   d_02171200 0x02171200 data a4
 *   d_02171254 0x02171254 data a4
 *   d_021711FC 0x021711FC data a4
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 */
#include "../arm9/script_vm_types.h"
#include "scrcmd_musical_shared_types.h"

struct EventWork;

struct FieldPlayer;

struct MoveModelSys;

struct MovePokemonSave;

struct MovePokemonEntry;

typedef s32 fx32;

typedef enum { FALSE, TRUE } BOOL;

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

typedef struct SkillEventWork {
    u32 magic;                            /* 0x19740205 */
    struct MapObject *playerObj;          /* 0x04 */
    struct GameSystem *gameSys;           /* 0x08 */
    SkillTarget target;                   /* 0x0C */
} SkillEventWork;

extern void *SCRIPT_SYS_ChangeScriptEvent(void *event, u16 scriptId, void *target, s32 reserved);
struct ScriptWork;

extern int SCRIPT_WORK_SetParams(struct ScriptWork *work, s32 param0, s32 param1, s32 param2, u16 param3);

extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);

extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, void *func, u32 workSize);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern u8 GAME_DATA_GetSeason(struct GameData *gameData);
struct PlayerWork;

extern u16 GAME_DATA_GetPlayerZoneId(struct PlayerWork *player);

extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);

extern void *GAME_DATA_GetEventWork(struct GameData *gameData);

extern struct FieldStatus *GAME_DATA_GetMoveModelSys(struct GameData *gameData);

extern int GAME_DATA_GetIntrudeCount(struct GameData *gameData);

extern u32 TIMEZONE_GetNowTimeZone(u32 season);

extern u16 FIELD_STATUS_GetMapEffectMask(struct FieldStatus *fieldStatus);

/* overlay loading, heap, string helpers */
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);

extern u32 GFL_HEAP_Free(void *ptr);

extern void MI_CpuFill8(void *dst, u8 value, u32 size);

extern u32 GFL_USE_GetRandomBelow(u32 range);
struct Party;
struct PokemonParam;

extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 pos);

extern u32 MYSTATUS_GetId(struct MyStatus *myStatus);

/* move_pokemon: roaming legendary save (arm9 unit_0200C7C0.c) */
extern void *MOVE_POKEMON_SAVE_GetBlock(void *saveControl);

extern u8 MOVE_POKEMON_SAVE_IsEntryActive(struct MovePokemonSave *block, u32 index);

extern struct MovePokemonEntry *MOVE_POKEMON_SAVE_GetEntry(struct MovePokemonSave *block, u32 index);

extern u8 MOVE_POKEMON_SAVE_GetEntryLocation(struct MovePokemonSave *block, u32 index);

extern int MOVE_POKEMON_SAVE_SetCommonArea();

extern void MOVE_POKEMON_SAVE_SetEntryField(struct MovePokemonEntry *entry, u32 field, u32 value);

extern u32 POKE_TOOL_GetPartyParamSize(void);

extern void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *pp, unsigned short species, unsigned short level, unsigned long long otId, unsigned int ivs, unsigned long long personality);

extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);

extern void *ZUKAN_SAVE_GetBlock(void *saveControl);
struct ZukanSave;

extern void ZUKAN_SAVE_RegisterSeen(struct ZukanSave *pZukan, void *pMon);

extern void MOVE_POKEMON_SAVE_SetEntryState(struct MovePokemonSave *block, u32 index, u32 state);

extern u8 MOVE_POKEMON_SAVE_GetEntryState(struct MovePokemonSave *block, u32 index);

extern void MOVE_POKEMON_SAVE_InitEntry(struct MovePokemonEntry *entry);

extern void MOVE_POKEMON_SAVE_SetEntryLocation(struct MovePokemonSave *block, u32 index, u8 location);

extern u32 MOVE_POKEMON_SAVE_GetEntryField(const struct MovePokemonEntry *entry, u32 field);
struct BattleSetupParam;

extern void *BTL_SETUP_GetParty(struct BattleSetupParam *param, s32 client);

extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);

extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);

extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
struct MmdlSys;

extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);

extern u32 FIELD_PLAYER_GetFormCode(struct FieldPlayer *player);

extern struct MapObject *FIELD_PLAYER_SearchFrontMmdl(struct FieldPlayer *player);

extern u16 FIELD_PLAYER_GetDirDisp(struct FieldPlayer *player);

extern u32 FIELD_PLAYER_GetNowAttribute(struct FieldPlayer *player);

extern u32 FIELD_PLAYER_GetFrontAttribute(struct FieldPlayer *player, u32 index);

extern int FIELD_PLAYER_CheckSurfStartAttr(struct FieldPlayer *player, int a, int b);

extern int FIELD_PLAYER_CheckWaterfallClimbAttr(struct FieldPlayer *player, int a, int b);

extern void FIELD_PLAYER_GetNowGridPos(struct FieldPlayer *player, u16 *x, u16 *y, u16 *z);
struct Mmdl;

extern u16 FLDMMDL_GetObjCode(struct Mmdl *mmdl);
struct MmdlVec;

extern void FLDMMDL_GetPos(struct Mmdl *mmdl, struct MmdlVec *out);

extern int FLDMMDL_IsMovedPosObjCode(u16 kind);

extern int FLDMMDL_CheckMovedPosAtMapPos(void *map, const VecFx32 *pos);

int MOVE_POKEMON_IsInSkillArea(const Area *a, u16 x, u16 z, u32 flag, void *field);

extern u32 ZONEDATA_IsFlyEnabled(u32 zoneId);

extern u32 ZONEDATA_IsWeatherEnabled(u32 zoneId);

extern int FIELD_GetPlayerAreaZoneId(struct FieldMap *fieldMap, u16 *out);

extern u32 ZONEDATA_IsZoneInTableDFB8(u32 zoneId);

extern u32 ZONEDATA_IsRawZoneF6(u32 zoneId);

extern u32 ZONEDATA_IsRawZoneF7(u32 zoneId);

extern u32 ZONEDATA_IsNormalFieldZone(u32 zoneId);

extern void *SWEET_SCENT_CreateEvent(void *gameSys, void *fieldMap, u8 partyIdx);

struct FieldStatus;

/* The Pokemon and its skill target, copied into the skill event work. */
typedef struct FieldSkillTarget {
    u16 partySlot;      /* 0x00 */
    u16 pad02;
    u32 targetParam;    /* 0x04 */
} FieldSkillTarget;

/* Caller context of a skill use or skill event create function. */
typedef struct FieldSkillContext {
    u8 pad00[8];
    struct GameSystem *gameSystem;  /* 0x08 */
    u32 fieldMap;                   /* 0x0C */
    u32 fieldPlayer;                /* 0x10 */
} FieldSkillContext;

/* The 20-byte work of every skill event (MOVE_POKEMON_InitSkillWork). */
typedef struct FieldSkillWork {
    u32 magic;                      /* 0x00: 0x19740205 */
    u32 fieldMap;                   /* 0x04 */
    struct GameSystem *gameSystem;  /* 0x08 */
    FieldSkillTarget target;        /* 0x0C */
} FieldSkillWork;

/* Usability test input of a field skill check function. */
typedef struct FieldSkillCheck {
    u16 zoneId;         /* 0x00 */
    u16 usableMask;     /* 0x02: bit n set = skill n can be used here */
} FieldSkillCheck;

/* field skill tables (ov010 event_field_proclink.c) */
typedef int (*SkillCheckFn)(struct FieldSkillInfo *info);

int MOVE_POKEMON_GetSkillCheckFunc(const FieldSkillCheck *check, int skill);

int MOVE_POKEMON_GetSkillEventFunc(const FieldSkillCheck *check, int skill);

int MOVE_POKEMON_IsSkillUsable(const FieldSkillCheck *check, int skill);

void MOVE_POKEMON_InitSkillWork(FieldSkillWork *work, const FieldSkillTarget *target, const FieldSkillContext *ctx);

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

extern const u16 d_021711C6[];

extern const char d_0217293C[];

extern const RoamLocationLinks d_021711A8[];

extern const Area d_021711EC;

extern const Area d_021711F4;

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
    POKE_TOOL_SetupPartyParamEx((struct PokemonParam *)mon, species, level, MYSTATUS_GetId(myStatus), 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 7, 0);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 8, 1);
    MOVE_POKEMON_SAVE_SetEntryField(entry, 2, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0xAC, 0));
    MOVE_POKEMON_SAVE_SetEntryField(entry, 3, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0, 0));
    MOVE_POKEMON_SAVE_SetEntryField(entry, 10, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x70, 0));
    MOVE_POKEMON_SAVE_SetEntryField(entry, 5, POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0xA1, 0));
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
    GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
    mon = (struct Pokemon *)POKEPARTY_GetMember(BTL_SETUP_GetParty((struct BattleSetupParam *)work, 1), 0);
    species = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 5, 0);
    hp = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0xA0, 0);
    status = POKE_TOOL_GetPartyValue((struct PokemonParam *)mon, 0x9D, 0);
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
        objKind = FLDMMDL_GetObjCode((struct Mmdl *)playerObj);
        map = FIELDMAP_GetMmdlSys(fieldMap);
        FLDMMDL_GetPos((struct Mmdl *)playerObj, (struct MmdlVec *)(&pos));
        if (FLDMMDL_IsMovedPosObjCode(objKind) && FLDMMDL_CheckMovedPosAtMapPos(map, &pos) == 0)
            out->usableMask |= 8;
        if (objKind == 0x6C)
            out->usableMask |= 1;
    }
    playerA = FIELD_PLAYER_GetDirDisp(player);
    playerB = FIELD_PLAYER_GetNowAttribute(player);
    playerC = FIELD_PLAYER_GetFrontAttribute(player, playerA);
    if (FIELD_PLAYER_CheckSurfStartAttr(player, playerB, playerC) == 1)
        out->usableMask |= 2;
    if (FIELD_PLAYER_CheckWaterfallClimbAttr(player, playerB, playerC) == 1)
        out->usableMask |= 4;
    if (ZONEDATA_IsFlyEnabled(out->zoneId) == 1) {
        out->usableMask |= 0x10;
        out->usableMask |= 0x40;
    }
    if (ZONEDATA_IsWeatherEnabled(out->zoneId) == 1)
        out->usableMask |= 0x80;
    if (FIELD_STATUS_GetMapEffectMask(GAME_DATA_GetMoveModelSys(GAMESYSTEM_GetGameData(out->gameSys))) & 1)
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
    if (GAME_DATA_GetIntrudeCount(GAMESYSTEM_GetGameData(out->gameSys)) == 1)
        out->usableMask = 0;
}

/* 1 when the skill has no check function (or its check says it is blocked). */
int MOVE_POKEMON_IsSkillBlocked(int skillIndex, FieldSkillInfo *info)
{
    SkillCheckFn check;

    check = (SkillCheckFn)MOVE_POKEMON_GetSkillCheckFunc((const FieldSkillCheck *)info, skillIndex);
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

    create = (SkillEventFn)MOVE_POKEMON_GetSkillEventFunc((const FieldSkillCheck *)info, skillIndex);
    if (create == 0) {
        return 0;
    }
    return create(target, info);
}

/* 1 when skill 0 is not usable. */
int MOVE_POKEMON_CheckCut(FieldSkillInfo *info)
{
    int blocked = 0;

    if (MOVE_POKEMON_IsSkillUsable((const FieldSkillCheck *)info, 0) == 0) {
        blocked = 1;
    }
    return blocked;
}

struct GameEvent *MOVE_POKEMON_CreateCutEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_CutEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), (const FieldSkillTarget *)target, (const FieldSkillContext *)info);
    return event;
}

/* Event main of skill 0: script event 0x2715 on the event work. */
int MOVE_POKEMON_CutEventMain(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = (s32)SCRIPT_SYS_ChangeScriptEvent((void *)event, 0x2715, 0, 0);
    (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)scriptCtl, targetId, 0, 0, 0);
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
    if (MOVE_POKEMON_IsSkillUsable((const FieldSkillCheck *)info, 1) != 0) {
        blocked = 0;
    }
    return blocked;
}

struct GameEvent *MOVE_POKEMON_CreateFlyEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_FlyEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), (const FieldSkillTarget *)target, (const FieldSkillContext *)info);
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
    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = (s32)SCRIPT_SYS_ChangeScriptEvent((void *)event, 0x2713, 0, 0);
    (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)scriptCtl, targetId, 0, 0, 0);
    return 0;
}

/* 1 when skill 2 is not usable. */
int MOVE_POKEMON_CheckSurf(FieldSkillInfo *info)
{
    return MOVE_POKEMON_IsSkillUsable((const FieldSkillCheck *)info, 2) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateSurfEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_SurfEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), (const FieldSkillTarget *)target, (const FieldSkillContext *)info);
    return event;
}

/* Event main of skill 2: script event 0x2717 on the event work. */
int MOVE_POKEMON_SurfEventMain(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = (s32)SCRIPT_SYS_ChangeScriptEvent((void *)event, 0x2717, 0, 0);
    (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)scriptCtl, targetId, 0, 0, 0);
    return 0;
}

/* 1 when skill 3 is not usable. */
int MOVE_POKEMON_CheckStrength(FieldSkillInfo *info)
{
    return MOVE_POKEMON_IsSkillUsable((const FieldSkillCheck *)info, 3) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateStrengthEvent(SkillTarget *target, FieldSkillInfo *info)
{
    struct GameEvent *event;
    event = GAME_EVENT_Create(info->gameSys, 0, MOVE_POKEMON_StrengthEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), (const FieldSkillTarget *)target, (const FieldSkillContext *)info);
    return event;
}

/* Event main of skill 3: script event 0x2711 on the event work. */
int MOVE_POKEMON_StrengthEventMain(struct GameEvent *event, u32 *state, void *work)
{
    SkillEventWork *skillWork = work;
    int targetId;
    int scriptCtl;
    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(skillWork->gameSys));
    targetId = skillWork->target.id;
    scriptCtl = (s32)SCRIPT_SYS_ChangeScriptEvent((void *)event, 0x2711, 0, 0);
    (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)scriptCtl, targetId, 0, 0, 0);
    return 0;
}

/* 1 when skill 8 is not usable. */
int MOVE_POKEMON_IsSkill8Unusable(FieldSkillInfo *info)
{
    return MOVE_POKEMON_IsSkillUsable((const FieldSkillCheck *)info, 8) != 0 ? FALSE : TRUE;
}

/* Create the object of skill 8 from the target id. */
void *MOVE_POKEMON_CreateDiveEvent(SkillTarget *target, FieldSkillInfo *info)
{
    return SWEET_SCENT_CreateEvent(info->gameSys, info->fieldMap, target->id);
}


extern int GAME_BEACON_SEARCH_SetCountValue(u32 seId);

extern struct GameEvent *FLD_WIPE_3DOBJ_CreateMapChangeEvent(struct GameSystem *gameSystem, s32 unused, s32 zoneId);

extern void *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
struct FieldSkillMapEff;

extern struct FieldSkillMapEff *FIELDMAP_GetMapEff(struct FieldMap *fieldMap);
struct FieldFlash;

extern struct FieldFlash *FIELDSKILL_MAPEFF_GetFlash(struct FieldSkillMapEff *mapEff);

extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);

extern void *SCRIPT_SYS_CallScriptEvent(struct GameEvent *event, u32 msgId, u32 b, u32 c, u32 d);

extern u8 FIELD_STATUS_IsFlashActive(struct FieldStatus *fieldStatus);

extern void FIELD_STATUS_SetFlashActive(struct FieldStatus *fieldStatus, u8 on);

extern void FIELD_FLASH_SetPendingCommand(void *mapEffect, u16 mode);

extern void FIELD_STATUS_SetMapEffectMask(struct FieldStatus *fieldStatus, u32 mask);

extern u16 FIELD_FLASH_GetState(struct FieldFlash *flash);

extern struct GameEvent *EVENT_MAPCHANGE_CreateEscapeRopeEvent(struct GameSystem *gameSystem);

extern void GAME_EVENT_ChangeEvent(struct GameEvent *event, struct GameEvent *next);

extern struct GameEvent *EVENT_MAPCHANGE_CreateSituationWarpEvent(struct GameSystem *gameSystem);

extern struct GameEvent *EVENT_PERAP_RECORD_Create(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 partySlot);

extern u32 ZONEDATA_CheckEventFlag(struct EventWork *ev, s32 flagId);

int MOVE_POKEMON_StartSkillOnTarget(const FieldSkillTarget *target, const FieldSkillContext *ctx, int unused);

int MOVE_POKEMON_CheckWaterfall(const FieldSkillCheck *check);

int MOVE_POKEMON_CheckFlash(const FieldSkillCheck *check);

struct GameEvent *MOVE_POKEMON_CreateFlashEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);

int MOVE_POKEMON_FlashEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);

int MOVE_POKEMON_CheckDig(const FieldSkillCheck *check);

struct GameEvent *MOVE_POKEMON_CreateDigEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);

int MOVE_POKEMON_DigEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);

int MOVE_POKEMON_CheckTeleport(const FieldSkillCheck *check);

struct GameEvent *MOVE_POKEMON_CreateTeleportEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);

int MOVE_POKEMON_TeleportEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);

int MOVE_POKEMON_CheckMilkDrink(const FieldSkillCheck *check);

struct GameEvent *MOVE_POKEMON_CreateMilkDrinkEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);

int MOVE_POKEMON_MilkDrinkEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);

int MOVE_POKEMON_CheckSweetScent(const FieldSkillCheck *check);

void MOVE_POKEMON_StartSweetScent(const FieldSkillTarget *target, const FieldSkillContext *ctx);

int MOVE_POKEMON_SweetScentEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);

struct GameEvent *MOVE_POKEMON_CreateSweetScentEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);

int MOVE_POKEMON_SoftBoiledEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work);

struct GameEvent *MOVE_POKEMON_CreateSoftBoiledEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx);

/* Skill function tables, 11 rows of { create function, check function }:
 * d_021711FC for most zones, d_02171254 for the zones of the 02013FFC table.
 * d_02171200 and d_02171258 are the check columns of the two tables. */
extern int d_02171258[];

extern int d_02171200[];

extern int d_02171254[];

extern int d_021711FC[];

int MOVE_POKEMON_StartSkillOnTarget(const FieldSkillTarget *target, const FieldSkillContext *ctx, int unused)
{
    GAME_BEACON_SEARCH_SetCountValue(0x13);
    return (s32)FLD_WIPE_3DOBJ_CreateMapChangeEvent(ctx->gameSystem, ctx->fieldPlayer, target->targetParam);
}

int MOVE_POKEMON_CheckWaterfall(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 4) != 0 ? FALSE : TRUE;
}

int MOVE_POKEMON_CheckFlash(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 5) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateFlashEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_FlashEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, ctx);
    return event;
}

/*
 * Three-state sequence step: state 0 opens message 0x2718, state 1 waits
 * for an object to go idle then starts sound 0x94, state 2 waits for a
 * status of 3. Returns 1 when finished.
 */
int MOVE_POKEMON_FlashEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    struct GameData *gameData;
    struct FieldStatus *fieldStatus;
    void *mapEffect;
    u32 windowParam;
    void *msg;
    struct FieldStatus *status;
    u16 partySlot;

    gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    GAME_DATA_GetEventWork(gameData);
    fieldStatus = GAME_DATA_GetMoveModelSys(gameData);
    mapEffect = FIELDSKILL_MAPEFF_GetFlash(FIELDMAP_GetMapEff(GAMESYSTEM_GetFieldMap(work->gameSystem)));
    windowParam = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = SCRIPT_SYS_CallScriptEvent(event, 0x2718, 0, 0, windowParam);
        (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)msg, partySlot, 0, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (FIELD_STATUS_IsFlashActive(fieldStatus) == 0) {
            status = GAME_DATA_GetMoveModelSys(gameData);
            FIELD_STATUS_SetFlashActive(fieldStatus, 1);
            GAME_BEACON_SEARCH_SetCountValue(0x94);
            FIELD_FLASH_SetPendingCommand(mapEffect, 1);
            FIELD_STATUS_SetMapEffectMask(status, (FIELD_STATUS_GetMapEffectMask(status) & ~1) | 2);
        } else {
            return 1;
        }
        (*seq)++;
        break;
    case 2:
        if (FIELD_FLASH_GetState(mapEffect) == 3) {
            return 1;
        }
        break;
    }
    return 0;
}

int MOVE_POKEMON_CheckDig(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 7) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateDigEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    GAME_BEACON_SEARCH_SetCountValue(91);
    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_DigEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, ctx);
    return event;
}

int MOVE_POKEMON_DigEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    void *msg;

    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = (void *)SCRIPT_SYS_CallScriptEvent(event, 0x271a, 0, 0, 0x15);
        (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        GAME_EVENT_ChangeEvent(event, EVENT_MAPCHANGE_CreateEscapeRopeEvent(work->gameSystem));
        break;
    }
    return 0;
}

/*
 * lever: Enum constants preserve the zero-first return arm; int constants fold to the opposite polarity.
 */
int MOVE_POKEMON_CheckTeleport(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 6) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateTeleportEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    GAME_BEACON_SEARCH_SetCountValue(100);
    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_TeleportEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, ctx);
    return event;
}

int MOVE_POKEMON_TeleportEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    void *msg;

    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = (void *)SCRIPT_SYS_CallScriptEvent(event, 0x2719, 0, 0, 0x15);
        (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        GAME_EVENT_ChangeEvent(event, EVENT_MAPCHANGE_CreateSituationWarpEvent(work->gameSystem));
        break;
    }
    return 0;
}

int MOVE_POKEMON_CheckMilkDrink(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 10) != 0 ? FALSE : TRUE;
}

struct GameEvent *MOVE_POKEMON_CreateMilkDrinkEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_MilkDrinkEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, ctx);
    return event;
}

/*
 * lever: Context +8 word and +12 halfword match neighboring callback layout; named call result preserves the early halfword lifetime.
 * interface: 021587B0 returns its final ldr r0,[r4] at 021587DC, read by this caller; 02159058 uses its own int,int,int,int,u16 prototype.
 */
int MOVE_POKEMON_MilkDrinkEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    int partySlot;
    int msg;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(work->gameSystem));
    partySlot = work->target.partySlot;
    msg = (s32)SCRIPT_SYS_ChangeScriptEvent((void *)event, 0x271c, 0, 0);
    (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)msg, partySlot, 0, 0, 0);
    return 0;
}

int MOVE_POKEMON_CheckSweetScent(const FieldSkillCheck *check)
{
    return MOVE_POKEMON_IsSkillUsable(check, 9) != 0 ? FALSE : TRUE;
}

/*
 * Play the skill sound, then hand the game system, the field player and
 * the party slot to the ov021 sweet scent start.
 */
void MOVE_POKEMON_StartSweetScent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    GAME_BEACON_SEARCH_SetCountValue(0x1C0);
    EVENT_PERAP_RECORD_Create(ctx->gameSystem, (struct FieldMap *)ctx->fieldPlayer, (u8)target->partySlot);
}

int MOVE_POKEMON_SweetScentEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    u32 windowParam;
    void *msg;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(work->gameSystem));
    windowParam = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = SCRIPT_SYS_CallScriptEvent(event, 0x271e, 0, 0, windowParam);
        (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        SCRIPT_SYS_ChangeScriptEvent((void *)event, 0x28e3, 0, 0);
        break;
    }
    return 0;
}

struct GameEvent *MOVE_POKEMON_CreateSweetScentEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_SweetScentEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, ctx);
    return event;
}

int MOVE_POKEMON_SoftBoiledEventMain(struct GameEvent *event, int *seq, FieldSkillWork *work)
{
    u32 partySlot;
    u32 windowParam;
    void *msg;

    GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(work->gameSystem));
    windowParam = FIELDMAP_GetHeapId(GAMESYSTEM_GetFieldMap(work->gameSystem));
    switch (*seq) {
    case 0:
        partySlot = work->target.partySlot;
        msg = SCRIPT_SYS_CallScriptEvent(event, 0x271d, 0, 0, windowParam);
        (struct ScriptWork *)SCRIPT_WORK_SetParams((struct ScriptWork *)msg, partySlot, 0, 0, 0);
        *seq = *seq + 1;
        break;
    case 1:
        SCRIPT_SYS_ChangeScriptEvent((void *)event, 0x28e2, 0, 0);
        break;
    }
    return 0;
}

struct GameEvent *MOVE_POKEMON_CreateSoftBoiledEvent(const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    struct GameEvent *event;

    event = GAME_EVENT_Create(ctx->gameSystem, 0, (void *)MOVE_POKEMON_SoftBoiledEventMain, 20);
    MOVE_POKEMON_InitSkillWork(GAME_EVENT_GetWork(event), target, ctx);
    return event;
}

int MOVE_POKEMON_GetSkillCheckFunc(const FieldSkillCheck *check, int skill)
{
    if (skill >= 11) return 0;
    if (ZONEDATA_IsZoneInTableDFB8(check->zoneId)) return *(int *)((u32)d_02171258 + ((u32)skill << 3));
    return *(int *)((u32)d_02171200 + ((u32)skill << 3));
}

int MOVE_POKEMON_GetSkillEventFunc(const FieldSkillCheck *check, int skill)
{
    if (skill >= 11) return 0;
    if (ZONEDATA_IsZoneInTableDFB8(check->zoneId)) return *(int *)((u32)d_02171254 + ((u32)skill << 3));
    return *(int *)((u32)d_021711FC + ((u32)skill << 3));
}

void MOVE_POKEMON_InitSkillWork(FieldSkillWork *work, const FieldSkillTarget *target, const FieldSkillContext *ctx)
{
    work->magic = 0x19740205;
    work->fieldMap = ctx->fieldMap;
    work->target = *target;
    work->gameSystem = ctx->gameSystem;
}

int MOVE_POKEMON_IsSkillUsable(const FieldSkillCheck *check, int skill)
{
    if ((check->usableMask & (1 << skill)) != 0)
        return 1;
    return 0;
}

/*
 * Inside test of (x, z) against an Area's half extents, refused when the
 * flag is already set in the field's save block.
 */
int MOVE_POKEMON_IsInSkillArea(const Area *a, u16 x, u16 z, u32 flag, void *field)
{
    int dx;
    int dz;

    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(field))), flag) != 0)
        return 0;
    dx = a->x - x;
    dz = a->z - z;
    if (dx < 0)
        dx = -dx;
    if (dx < a->w) {
        if (dz < 0)
            dz = -dz;
        if (dz < a->h)
            return 1;
    }
    return 0;
}
