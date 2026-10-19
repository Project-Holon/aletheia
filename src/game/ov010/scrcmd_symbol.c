/*
 * file:     scrcmd_symbol.c
 * unit:     yes
 * function: SCRCMD_SYMBOL_StartViewEvent, SCRCMD_SYMBOL_ApplyLinkRecord, SCRCMD_SYMBOL_SelectObjectEntry, SCRCMD_SYMBOL_MoveObjectEntryToPairedBand, SCRCMD_SYMBOL_SetObjectPokemonWord, SCRCMD_SYMBOL_GetState, SCRCMD_SYMBOL_StartEntryEvent, SCRCMD_SYMBOL_GetMmdl, SCRCMD_SYMBOL_GetTargetObjectKey, SCRCMD_SYMBOL_CreateObjectPokemon, SCRCMD_SYMBOL_SendEntryFlag, SCRCMD_SYMBOL_CreateViewEvent, SCRCMD_SYMBOL_ViewEventMain
 * address:  0x0216ABD8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from scrcmd_trialhouse.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb  ov021
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_EVENT_CallProc 0x02012444 thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SYMBOL_MAP_CreateLinkRecord  0x021664CC  thumb  ov010
 *   INTRUDE_FIELD_SpawnSymbolMons  0x0217C37C  thumb  ov018
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   INTRUDE_FIELD_GetMmdlParam0  0x0217C294  thumb  ov018
 *   SYMBOL_SAVE_RemoveSlotAndCommit  0x0200E18C  thumb
 *   SYMBOL_MAP_MoveRecordToPairedBand  0x0216628C  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   WORDSET_SetSlotMonSpeciesName  0x0201EE84  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   SYMBOL_MAP_IsHomeCell  0x02166618  thumb  ov010
 *   SYMBOL_MAP_IsBlankCell  0x0216662C  thumb  ov010
 *   INTRUDE_COMM_GetMarkerPosForPartner  0x021767F0  thumb  ov011
 *   EVENT_MAPCHANGE_CreateWarpEvent  0x02184D38  thumb  ov020
 *   SYMBOL_MAP_GetSelectedNeighborCell  0x021665F0  thumb  ov010
 *   FIELD_INTRUDE_EVENT_StartSymbolEntry  0x0216B3A8  thumb  ov010
 *   SCRIPT_WORK_GetWorkValue 0x0215901C thumb ov010
 *   INTRUDE_FIELD_GetMmdlParamPair 0x0217C274 thumb ov018
 *   INTRUDE_FIELD_CreateSymbolMon   0x0217C2A0  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SetPendingAreaNotice  0x0217688C  thumb  ov011
 *   GF_STANDARD_CalcCrc16  0x0203F1FC  arm
 *   SYMBOL_SAVE_FindRecord  0x0200E2BC  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   MYITEM_SAVEDATA_AddItem  0x02007E50  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   ZUKAN_SAVE_GetBlock  0x0200CA10  thumb
 *   MYITEM_SAVEDATA_RemoveItem  0x02007F1C  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   PDC_CreateArgs  0x021B6100  thumb  ov098
 *   PDC_GetResult  0x021B6158  thumb  ov098
 *   EVENT_PDC_RETURN_CreateArgs  0x021B95A0  thumb  ov227
 *   EVENT_PDC_RETURN_DeleteArgs  0x021B95C8  thumb  ov227
 *   gPdcProcData     0x021B6D74  data ov098
 *   d_021B98A4     0x021B98A4  data ov227
 */
#include "script_work_types.h"
#include "formchange_shaymin_shared_types.h"
#include "scrcmd_trialhouse_shared_types.h"
#include "scrcmd_mmdl_shared_types.h"

struct GameComm;

struct FieldPlayer;

struct MyStatus;

struct MyItem;

struct Config;

struct WordSet;

struct SymbolSave;

struct IntrudeCommSys;

/* Species and form of a symbol Pokemon, packed in one word. */
typedef struct SymbolKey {
    u32 species : 11;
    u32 pad0 : 12;
    u32 form : 6;
    u32 pad1 : 3;
} SymbolKey;

/* The 0x54-byte record two players exchange over the link (same layout as symbol_map.c). */
typedef struct SymbolMapLinkRecord {
    u32 entries[20];      /* 0x00 */
    u32 entryCount : 6;   /* 0x50 */
    u32 symbolIndex : 4;
    u32 symbolGroup : 4;
    u32 state : 4;
    u32 page : 6;
    u32 reserved : 8;
} SymbolMapLinkRecord;

/* Scene description filled in by the field effect code (ov021). */
typedef struct SceneInfo {
    u32 zoneParam;  /* 0x00 */
    u32 areaParam;  /* 0x04 */
    u8 weather;     /* 0x08 */
    u8 season;      /* 0x09 */
    u16 zoneId;     /* 0x0A */
    u8 hour;        /* 0x0C */
    u8 minute;      /* 0x0D */
    u8 pad0E[2];
} SceneInfo;

/* Work of the symbol Pokemon viewing event (0x3C bytes). */
typedef struct SymbolViewWork {
    struct FieldMap *fieldMap;  /* 0x00 */
    void *selectScreen;         /* 0x04: ov098 screen work */
    void *resultScreen;         /* 0x08: ov227 screen work */
    struct PokemonParam *mon;   /* 0x0C */
    SceneInfo scene;            /* 0x10 */
    SymbolKey key;              /* 0x20 */
    u16 heapId;                 /* 0x24 */
    u16 *resultOut;             /* 0x28 */
    u16 crc;                    /* 0x2C */
    u8 pad2E[0x3C - 0x2E];
} SymbolViewWork;

/* ScriptWork, ScrcmdWork and game structure accessors. */
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);

extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);

extern struct GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *cmdWork);

extern u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *cmdWork);

extern u32 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);

extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);

extern void SCRIPT_SYS_CallEvent(void *scriptWork, void *task);
struct ScriptWork;

extern u32 SCRIPT_WORK_GetWorkValue(struct ScriptWork *work, void *gameData, u32 id);

extern void *SCRIPT_WORK_GetWordSet(ScriptWork *scriptWork);

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);

extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern int GAME_DATA_GetSymbolMapFlag(struct GameData *gameData);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern void *GAME_DATA_GetMyItem(struct GameData *gameData);

extern struct Config *SYSTEM_DATA_GetConfig(struct SaveControl *saveControl);

extern void *ZUKAN_SAVE_GetBlock(void *saveControl);

/* Game events. */
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);

extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);

extern void GAME_EVENT_CallProc(struct GameEvent *parent, u32 overlayId, void *procData, void *param);

extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(struct GameSystem *gameSystem, u32 bgmId);

extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(struct GameSystem *gameSystem);

extern struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem);

extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);

extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);

extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, u32 paramId, u32 arg);

extern u32 POKE_TOOL_GetPartyParamSize(void);

extern u16 GF_STANDARD_CalcCrc16(u8 *src, u32 len);

extern void WORDSET_SetSlotMonSpeciesName(struct WordSet *words, u32 slot, void *mon);

extern void MI_CpuFill8(void *dst, int value, int size);

extern unsigned int GFL_HEAP_Free(void *block);

/* Field models and the field map. */
extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);

extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);

extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *outPos);
struct FieldSituation;

extern void FIELD_ENCOUNT_SetFieldSituation(struct FieldSituation *situation, struct GameData *gameData, struct FieldMap *fieldMap);
struct EncEff;

extern struct EncEff *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
struct EncEffWork;

extern void ENCEFF_Start(struct EncEffWork *eff, struct GameEvent *parentEvent, int kind);

extern struct Mmdl *FLDMMDL_SysSearchObjId(struct MmdlSys *mmdlSys, u32 objId);

extern struct GameEvent *EVENT_MAPCHANGE_CreateWarpEvent(struct GameSystem *gameSystem, int unused, int zoneId, VecFx32 *pos, u16 dir, int seasonFadeAllowed);

                                       
extern void *SYMBOL_SAVE_GetBlock(void *saveData);

extern void SYMBOL_SAVE_RemoveSlotAndCommit(struct SymbolSave *save, u32 index);

extern u32 SYMBOL_SAVE_FindRecord(void *saveData, u32 *keyWord, void *heapId, u32 matchMode);

extern SymbolMapLinkRecord *SYMBOL_MAP_CreateLinkRecord(unsigned short heapId, void *gameSystem, unsigned int *outStart);

extern int SYMBOL_MAP_MoveRecordToPairedBand(u32 *save, u32 recordIndex);

extern int SYMBOL_MAP_IsHomeCell(int symbolMapFlag);

extern int SYMBOL_MAP_IsBlankCell(int symbolMapFlag);

extern int SYMBOL_MAP_GetSelectedNeighborCell(void *gameSystem, int cellId, int dir);

extern struct GameEvent *FIELD_INTRUDE_EVENT_StartSymbolEntry(struct GameSystem *gameSystem, int direction, int cell);

extern void INTRUDE_FIELD_GetMmdlParamPair(unsigned int *out, struct Mmdl *mmdl);

extern int INTRUDE_FIELD_GetMmdlParam0(struct Mmdl *mmdl);
struct SymbolMonEntry;

extern void *INTRUDE_FIELD_CreateSymbolMon(int heapId, struct GameData *gameData, struct SymbolMonEntry *entry);

extern void INTRUDE_FIELD_SpawnSymbolMons(struct FieldMap *fieldMap, int objIdBase, struct SymbolMonEntry *entries, int unused, int cellKind);

extern struct IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(struct GameComm *comm);

extern void INTRUDE_COMM_SetPendingAreaNotice(struct IntrudeCommSys *linkState, int value);

extern u8 INTRUDE_COMM_GetPartnerSlot(void *comm, void *gameData);

extern void INTRUDE_COMM_GetMarkerPosForPartner(struct GameComm *comm, struct GameData *gameData, VecFx32 *outPos);

/* Overlay screens of the symbol Pokemon viewing event. */
extern void *PDC_CreateArgs(struct GameData *gameData, struct PokemonParam *mon, SceneInfo *scene, struct MyStatus *myStatus,
                           struct MyItem *myItem, struct Config *config, struct PokedexSave *pokedex, u16 heapId);
struct PdcArgs;

extern int PDC_GetResult(struct PdcArgs *args);

extern void *EVENT_PDC_RETURN_CreateArgs(unsigned int a, int b, unsigned int c, unsigned int heap);

extern void EVENT_PDC_RETURN_DeleteArgs(void *screen);

extern u32 MYITEM_SAVEDATA_AddItem(struct MyItem *myItem, u16 itemId, u16 quantity, u16 heapId);

extern u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *myItem, u16 itemId, u16 quantity, u16 heapId);

extern int GF_OVERLAY_Load(int handle);

extern void GF_OVERLAY_Unload(int handle);

extern u8 gPdcProcData[];

extern u8 d_021B98A4[];

int SCRCMD_SYMBOL_StartViewEvent(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_SYMBOL_ApplyLinkRecord(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_SYMBOL_SelectObjectEntry(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_SYMBOL_MoveObjectEntryToPairedBand(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_SYMBOL_SetObjectPokemonWord(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_SYMBOL_GetState(ScriptVm *vm, ScrcmdWork *cmdWork);

int SCRCMD_SYMBOL_StartEntryEvent(ScriptVm *vm, ScrcmdWork *cmdWork);

struct Mmdl *SCRCMD_SYMBOL_GetMmdl(ScrcmdWork *cmdWork, u32 objId);

void SCRCMD_SYMBOL_GetTargetObjectKey(ScrcmdWork *cmdWork, SymbolKey *outKey);

struct PokemonParam *SCRCMD_SYMBOL_CreateObjectPokemon(ScrcmdWork *cmdWork, struct Mmdl *mmdl, int heapId, SymbolKey *outKey);

void SCRCMD_SYMBOL_SendEntryFlag(ScrcmdWork *cmdWork);

struct GameEvent *SCRCMD_SYMBOL_CreateViewEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct PokemonParam *mon, SymbolKey key,
                                u16 *resultOut, u16 heapId);

int SCRCMD_SYMBOL_ViewEventMain(struct GameEvent *event, u32 *state, void *work);

/* Overlay ids are absolute symbols: the address of ovNNN_id is the id. */
#define FS_OVERLAY_ID(name) ((u32)name##_id)

extern u8 ov098_id[];
extern u8 ov227_id[];

#define SCRIPT_WORK_TARGET_OBJ_ID 0x8011  /* script work holding the object id the script talks to */

#define SYMBOL_MARKER_EFFECT_ID 0x117

#define SYMBOL_MARKER_OFFSET_X (0x3E << 14)

#define SYMBOL_VIEW_BGM_ID 0x468

#define SYMBOL_VIEW_ITEM_ID 0x240  /* item added while the screens run, removed after */

#define SYMBOL_UNSEEN_SPECIES 0x28B

#define SYMBOL_UNSEEN_FORM 12

#define SYMBOL_VIEW_HEAP_ID 4

/* Symbol script command: starts the symbol Pokemon viewing event for a field model. */
int SCRCMD_SYMBOL_StartViewEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    SymbolKey key;
    int objId;
    u16 *resultOut;
    struct Mmdl *mmdl;
    struct PokemonParam *mon;

    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultOut = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    mmdl = SCRCMD_SYMBOL_GetMmdl(cmdWork, objId);
    if (mmdl != 0) {
        mon = SCRCMD_SYMBOL_CreateObjectPokemon(cmdWork, mmdl, SYMBOL_VIEW_HEAP_ID, &key);
        if (mon != 0) {
            ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
            struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

            SCRIPT_SYS_CallEvent(scriptWork, SCRCMD_SYMBOL_CreateViewEvent(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), mon, key, resultOut, SYMBOL_VIEW_HEAP_ID));
        }
    }
    return 1;
}

/* Symbol script command: builds the link record and hands its entries to the field map. */
int SCRCMD_SYMBOL_ApplyLinkRecord(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    SymbolMapLinkRecord *record;
    u32 start;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GAMESYSTEM_GetGameComm(gameSystem);
    record = SYMBOL_MAP_CreateLinkRecord(SCRCMD_WORK_GetHeapId(cmdWork), gameSystem, &start);
    if (record != 0) {
        INTRUDE_FIELD_SpawnSymbolMons(fieldMap, start, (struct SymbolMonEntry *)record, record->entryCount, record->page);
        GFL_HEAP_Free(record);
    }
    return 0;
}

/* Symbol script command: moves a field model's symbol entry to the symbol save index of its key. */
int SCRCMD_SYMBOL_SelectObjectEntry(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    struct SymbolSave *symbolSave;
    struct Mmdl *mmdl;

    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    symbolSave = SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    mmdl = SCRCMD_SYMBOL_GetMmdl(cmdWork, objId);
    if (mmdl != 0) {
        SYMBOL_SAVE_RemoveSlotAndCommit(symbolSave, INTRUDE_FIELD_GetMmdlParam0(mmdl));
        SCRCMD_SYMBOL_SendEntryFlag(cmdWork);
    }
    return 0;
}

/* Symbol script command: moves a field model's symbol record to the paired band, storing the result. */
int SCRCMD_SYMBOL_MoveObjectEntryToPairedBand(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    u16 *result;
    struct SymbolSave *symbolSave;
    struct Mmdl *mmdl;

    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    symbolSave = SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData(cmdWork)));
    mmdl = SCRCMD_SYMBOL_GetMmdl(cmdWork, objId);
    if (mmdl != 0) {
        *result = SYMBOL_MAP_MoveRecordToPairedBand((u32 *)symbolSave, INTRUDE_FIELD_GetMmdlParam0(mmdl));
        SCRCMD_SYMBOL_SendEntryFlag(cmdWork);
    } else {
        *result = 0;
    }
    return 0;
}

/* Symbol script command: registers the symbol Pokemon of a field model in a word set slot. */
int SCRCMD_SYMBOL_SetObjectPokemonWord(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    SymbolKey key;
    int objId;
    int wordSetIndex;
    struct Mmdl *mmdl;
    struct PokemonParam *mon;

    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    wordSetIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mmdl = SCRCMD_SYMBOL_GetMmdl(cmdWork, objId);
    if (mmdl != 0) {
        mon = SCRCMD_SYMBOL_CreateObjectPokemon(cmdWork, mmdl, SCRCMD_WORK_GetHeapId(cmdWork), &key);
        if (mon != 0) {
            WORDSET_SetSlotMonSpeciesName(SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork)), wordSetIndex, mon);
            GFL_HEAP_Free(mon);
        }
    }
    return 0;
}

/*
 * Symbol script command: reads one property of the symbol map state into a script work.
 * Queries: 0 own link record is the local one, 1 selection is the home cell, 2 selection is
 * a blank cell, 3 species and 4 form of the target object symbol Pokemon.
 */
int SCRCMD_SYMBOL_GetState(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int query;
    u16 *result;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct GameComm *comm;
    SymbolKey speciesKey;
    SymbolKey formKey;

    query = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    result = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    SYMBOL_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData));
    comm = GAMESYSTEM_GetGameComm(gameSystem);
    switch (query) {
    case 0:
        if (INTRUDE_COMM_GetPartnerSlot(comm, gameData) == 4)
            *result = 1;
        else
            *result = 0;
        break;
    case 1:
        *result = SYMBOL_MAP_IsHomeCell(GAME_DATA_GetSymbolMapFlag(gameData));
        break;
    case 2:
        *result = SYMBOL_MAP_IsBlankCell(GAME_DATA_GetSymbolMapFlag(gameData));
        break;
    case 3:
        SCRCMD_SYMBOL_GetTargetObjectKey(cmdWork, &speciesKey);
        *result = speciesKey.species;
        break;
    case 4:
        SCRCMD_SYMBOL_GetTargetObjectKey(cmdWork, &formKey);
        *result = formKey.form;
        break;
    }
    return 0;
}

/* Symbol script command: starts the symbol map entry event (marker or cell entry). */
int SCRCMD_SYMBOL_StartEntryEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 markerPos;
    VecFx32 playerPos;
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    int direction;
    int cell;
    struct FieldMap *fieldMap;
    struct FieldPlayer *player;
    struct GameComm *comm;
    struct GameEvent *event;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    direction = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    cell = GAME_DATA_GetSymbolMapFlag(gameData);
    if (direction == 1 && SYMBOL_MAP_IsBlankCell(cell) != 0) {
        fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        comm = GAMESYSTEM_GetGameComm(gameSystem);
        FIELD_PLAYER_GetPos(player, &playerPos);
        INTRUDE_COMM_GetMarkerPosForPartner(comm, gameData, &markerPos);
        markerPos.x = markerPos.x + (playerPos.x - SYMBOL_MARKER_OFFSET_X);
        event = EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, (int)fieldMap, SYMBOL_MARKER_EFFECT_ID, &markerPos, 1, 0);
    } else {
        if (direction != 9)
            cell = SYMBOL_MAP_GetSelectedNeighborCell(gameSystem, GAME_DATA_GetSymbolMapFlag(gameData), direction);
        event = FIELD_INTRUDE_EVENT_StartSymbolEntry(gameSystem, direction, cell);
    }
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

/* Finds the field model whose object id is the given one. */
struct Mmdl *SCRCMD_SYMBOL_GetMmdl(ScrcmdWork *cmdWork, u32 objId)
{
    return FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork))), objId);
}

/* Key of the field model that work 0x8011 names. */
void SCRCMD_SYMBOL_GetTargetObjectKey(ScrcmdWork *cmdWork, SymbolKey *outKey)
{
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    INTRUDE_FIELD_GetMmdlParamPair((unsigned int *)outKey, SCRCMD_SYMBOL_GetMmdl(cmdWork, SCRIPT_WORK_GetWorkValue(scriptWork, SCRCMD_WORK_GetGameData(cmdWork), SCRIPT_WORK_TARGET_OBJ_ID)));
}

/*
 * The heap id is not used: the allocation below always takes heap 4.
 */
struct PokemonParam *SCRCMD_SYMBOL_CreateObjectPokemon(ScrcmdWork *cmdWork, struct Mmdl *mmdl, int heapId, SymbolKey *outKey)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);

    INTRUDE_FIELD_GetMmdlParamPair((unsigned int *)outKey, mmdl);
    return INTRUDE_FIELD_CreateSymbolMon(SYMBOL_VIEW_HEAP_ID, gameData, (struct SymbolMonEntry *)outKey);
}

void SCRCMD_SYMBOL_SendEntryFlag(ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    struct IntrudeCommSys *linkState;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    SYMBOL_SAVE_GetBlock(saveControl);
    linkState = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    if (linkState != 0) {
        INTRUDE_COMM_SetPendingAreaNotice(linkState, GAME_DATA_GetSymbolMapFlag(gameData));
    }
}

/* Creates the symbol Pokemon viewing event. */
struct GameEvent *SCRCMD_SYMBOL_CreateViewEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct PokemonParam *mon, SymbolKey key,
                                u16 *resultOut, u16 heapId)
{
    struct GameData *gameData;
    struct GameEvent *event;
    SymbolViewWork *work;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_SYMBOL_ViewEventMain, sizeof(SymbolViewWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(SymbolViewWork));
    work->fieldMap = fieldMap;
    work->resultOut = resultOut;
    work->heapId = heapId;
    work->mon = mon;
    work->key = key;
    work->crc = GF_STANDARD_CalcCrc16((u8 *)mon, POKE_TOOL_GetPartyParamSize());
    if (SYMBOL_SAVE_FindRecord((void *)(GAME_DATA_GetSaveControl(gameData)), (u32 *)(&key), (void *)heapId, 0) == 0)
        work->key.species = SYMBOL_UNSEEN_SPECIES;
    FIELD_ENCOUNT_SetFieldSituation((struct FieldSituation *)(&work->scene), gameData, fieldMap);
    return event;
}

/*
 * Proc main of the symbol Pokemon viewing event: a 9-state machine that registers the
 * party member's species/form key with the save (clearing the form to 12
 * when it is not yet seen), runs the ov098 screen and then the ov227 one,
 * and frees both work buffers when it runs past the last state.
 *
 * Levers: `ok` at function scope (its slot sits above the case-1 locals),
 * heap declared before mon in both key blocks, and the u16 flag stored in
 * both arms of an if/else.
 */
int SCRCMD_SYMBOL_ViewEventMain(struct GameEvent *event, u32 *state, void *procWork)
{
    SymbolViewWork *work = procWork;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    int ok;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSystem, SYMBOL_VIEW_BGM_ID));
        (*state)++;
        break;
    case 1: {
        u32 heapId;
        struct PokemonParam *mon;
        SymbolKey key;

        mon = work->mon;
        heapId = work->heapId;

        key.species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        key.form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);
        if ((void *)(void *)SYMBOL_SAVE_FindRecord((void *)(GAME_DATA_GetSaveControl(gameData)), (u32 *)(&key), (void *)heapId, 1) == 0)
            work->key.form = SYMBOL_UNSEEN_FORM;
        ENCEFF_Start((struct EncEffWork *)(FIELDMAP_GetEncEff(work->fieldMap)), event, 0);
        (*state)++;
        break;
    }
    case 2:
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, work->fieldMap));
        (*state)++;
        break;
    case 4: {
        struct SaveControl *saveControl = GAME_DATA_GetSaveControl(gameData);

        MYITEM_SAVEDATA_AddItem(GAME_DATA_GetMyItem(gameData), SYMBOL_VIEW_ITEM_ID, 1, work->heapId);
        GF_OVERLAY_Load(FS_OVERLAY_ID(ov098));
        work->selectScreen = PDC_CreateArgs(gameData, work->mon, &work->scene, GAME_DATA_GetMyStatus(gameData), GAME_DATA_GetMyItem(gameData),
                                           SYSTEM_DATA_GetConfig(saveControl), ZUKAN_SAVE_GetBlock(saveControl), work->heapId);
        GAME_EVENT_CallProc(event, -1, gPdcProcData, work->selectScreen);
        (*state)++;
        break;
    }
    case 5: {
        u32 heapId;
        struct PokemonParam *mon;
        SymbolKey key;

        ok = PDC_GetResult(work->selectScreen);
        mon = work->mon;
        heapId = work->heapId;

        key.species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        key.form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);
        if ((void *)(void *)SYMBOL_SAVE_FindRecord((void *)(GAME_DATA_GetSaveControl(gameData)), (u32 *)(&key), (void *)heapId, 1) == 0
            || SYMBOL_SAVE_FindRecord((void *)(GAME_DATA_GetSaveControl(gameData)), (u32 *)(&work->key), (void *)work->heapId, 0) == 0)
            ok = 0;
        if (ok == 1)
            *work->resultOut = 1;
        else
            *work->resultOut = 0;
        GF_OVERLAY_Unload(FS_OVERLAY_ID(ov098));
        GF_OVERLAY_Load(FS_OVERLAY_ID(ov227));
        work->resultScreen = EVENT_PDC_RETURN_CreateArgs((unsigned int)gameData, ok, (unsigned int)work->mon, work->heapId);
        GAME_EVENT_CallProc(event, -1, d_021B98A4, work->resultScreen);
        MYITEM_SAVEDATA_RemoveItem(GAME_DATA_GetMyItem(gameData), SYMBOL_VIEW_ITEM_ID, 1, work->heapId);
        (*state)++;
        break;
    }
    case 6:
        EVENT_PDC_RETURN_DeleteArgs(work->resultScreen);
        GF_OVERLAY_Unload(FS_OVERLAY_ID(ov227));
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSystem));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*state)++;
        break;
    default:
        GFL_HEAP_Free(work->mon);
        GFL_HEAP_Free(work->selectScreen);
        return 1;
    }
    return 0;
}
