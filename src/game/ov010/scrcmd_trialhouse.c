/*
 * file:     scrcmd_trialhouse.c
 * unit:     yes
 * function: FORMCHANGE_RevertShaymin, FORMCHANGE_RevertShayminIfTimeOfDayChanged, FORMCHANGE_RevertShayminAtNight, FORMCHANGE_RevertShayminAndRegister, SCRCMD_TRIALHOUSE_CreateWork, SCRCMD_TRIALHOUSE_FreeWork, SCRCMD_TRIALHOUSE_SetBattleMode, SCRCMD_TRIALHOUSE_StartPartySelect, SCRCMD_TRIALHOUSE_LoadRecord, SCRCMD_TRIALHOUSE_StartTrainerMessage, SCRCMD_TRIALHOUSE_StartBattle, SCRCMD_TRIALHOUSE_SetRecordSource, SCRCMD_TRIALHOUSE_SetRank, SCRCMD_TRIALHOUSE_GetRank, SCRCMD_TRIALHOUSE_StartDownload, SCRCMD_TRIALHOUSE_GetRankAndScore, SCRCMD_TRIALHOUSE_GetSaveState, SCRCMD_TRIALHOUSE_StartSaveEvent, SCRCMD_TRIALHOUSE_StartAward, SCRCMD_TRIALHOUSE_GetClearFlags, SCRCMD_MMDL_StartRise, SCRCMD_MMDL_RiseEventMain, SCRCMD_MMDL_StartOrbit, SCRCMD_MMDL_OrbitEventMain, FORMCHANGE_UpdateSeasonForms, SCRCMD_SYMBOL_StartViewEvent, SCRCMD_SYMBOL_ApplyLinkRecord, SCRCMD_SYMBOL_SelectObjectEntry, SCRCMD_SYMBOL_MoveObjectEntryToPairedBand, SCRCMD_SYMBOL_SetObjectPokemonWord, SCRCMD_SYMBOL_GetState, SCRCMD_SYMBOL_StartEntryEvent, SCRCMD_SYMBOL_GetMmdl, SCRCMD_SYMBOL_GetTargetObjectKey, SCRCMD_SYMBOL_CreateObjectPokemon, SCRCMD_SYMBOL_SendEntryFlag, SCRCMD_SYMBOL_CreateViewEvent, SCRCMD_SYMBOL_ViewEventMain
 * address:  0x0216A298
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from comm_player.c at 0x0216A298: after the last report_event.c helper; trial house script commands (name guess, no anchor).
 *
 * symbols:
 *   GFL_HEAP_Free  0x020307B0  arm
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb
 *   FIELD_ENCOUNT_SetFieldSituation  0x021AA304  thumb  ov021
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_EVENT_CallProc 0x02012444 thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   VM_GetTimeZoneLight  0x02011400  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   TRIAL_HOUSE_CreateWork  0x021D096C  thumb
 *   TRIAL_HOUSE_DeleteWork   0x021D0A48  thumb
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   TRIAL_HOUSE_SetBattleMode  0x021D0A74  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   TRIAL_HOUSE_LoadTrainer  0x021D0AC0  thumb  ov021
 *   TRIAL_HOUSE_CreateTrainerMsgEvent  0x021D0BD8  thumb  ov021
 *   TRIAL_HOUSE_SetUseDeliveredTrainers  0x021D0AB8  thumb
 *   RECORD_GetFromSave 0x02008C58 thumb
 *   RECORD_SetTrialRank 0x02008E68 thumb
 *   RECORD_GetTrialRank  0x02008E78  thumb
 *   TRIAL_HOUSE_CreateDeliveryTask  0x021D0BE4  thumb  ov021
 *   TRIAL_HOUSE_ComputeScoreAndRank  0x021D0DB0  thumb  ov021
 *   TRIAL_HOUSE_GetDeliveryState  0x021D0FE0  thumb
 *   TRIAL_HOUSE_CreateSaveTask  0x021D0FE8  thumb  ov021
 *   TRIAL_HOUSE_GetRecordSlotsState  0x021D1028  thumb
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FX_SinCosTable_  0x020A1B38  data
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SYMBOL_MAP_CreateLinkRecord  0x021664CC  thumb  ov010
 *   INTRUDE_FIELD_SpawnSymbolMons  0x0217C37C  thumb  ov018
 *   SYMBOL_SAVE_GetBlock  0x0200E0B0  thumb
 *   INTRUDE_FIELD_GetMmdlParam0  0x0217C294  thumb  ov018
 *   SYMBOL_SAVE_RemoveSlotAndCommit  0x0200E18C  thumb
 *   SYMBOL_MAP_MoveRecordToPairedBand  0x0216628C  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   WORDSET_SetSlotMonName  0x0201EE84  thumb
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
 *   INTRUDE_COMM_SetPendingValue  0x0217688C  thumb  ov011
 *   GF_STANDARD_SetupCalc  0x0203F1FC  arm
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
 *   ov098_id       0x00000062  data
 *   ov227_id       0x000000E3  data
 *   gPdcProcData     0x021B6D74  data ov098
 *   d_021B98A4     0x021B98A4  data ov227
 *   FLD_BTL_INST_TOOL_CreatePartySelectStepEvent  0x02168BF0  thumb  ov010
 *   FLD_BTL_INST_TOOL_CreateBattleEvent  0x02168CF4  thumb  ov010
 *   FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent  0x02168E5C  thumb  ov010
 */
#include "script_work_types.h"

struct GameSystem;
struct GameData;
struct GameComm;
struct GameEvent;
struct FieldMap;
struct FieldPlayer;
struct MmdlSys;
struct Mmdl;
struct Party;
struct PokemonParam;
struct PokedexSave;
struct SaveControl;
struct MyStatus;
struct MyItem;
struct Config;
struct WordSet;
struct SymbolSave;
struct IntrudeCommSys;
struct TrialHouseWork;
struct RecordBlock;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct TrialHouseWork TrialHouseWork;

typedef int fx32;
typedef short s16;
typedef long long s64;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

/* Hour and minute as the RTC code lays them out. */
typedef struct TimeOfDay {
    int hour;
    int minute;
} TimeOfDay;

typedef int (*GameEventFunc)(struct GameEvent *event, u32 *state, void *work);

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

/* Rise of a field model over a number of frames (0x18 bytes). */
typedef struct MmdlRiseWork {
    int totalRise;              /* 0x00: fx32 distance to cover */
    u16 frames;                 /* 0x04 */
    u16 frame;                  /* 0x06 */
    struct Mmdl *mmdl;          /* 0x08 */
    VecFx32 startPos;           /* 0x0C */
} MmdlRiseWork;

/* Spiral and circle motion of a field model around its start position (0x14 bytes). */
typedef struct MmdlOrbitWork {
    u32 frame;                  /* 0x00 */
    struct Mmdl *mmdl;          /* 0x04 */
    VecFx32 centerPos;          /* 0x08 */
} MmdlOrbitWork;

/* ScriptWork, ScrcmdWork and game structure accessors. */
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);
extern ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);
extern struct GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *cmdWork);
extern u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *cmdWork);
extern u32 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);
extern void SCRIPT_SYS_CallEvent(ScriptWork *scriptWork, struct GameEvent *event);
extern u32 SCRIPT_WORK_GetWorkValue(ScriptWork *scriptWork, struct GameData *gameData, u32 workId);
extern struct WordSet *SCRIPT_WORK_GetWordSet(ScriptWork *scriptWork);
extern struct GameData *ICA_ANIME_GetField1C(const struct GameSystem *gameSystem);
extern struct FieldMap *ICA_ANIME_GetField20(const struct GameSystem *gameSystem);
extern struct GameComm *ICA_ANIME_GetField24(const struct GameSystem *gameSystem);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern TrialHouseWork **GAME_DATA_GetListCursor(struct GameData *gameData);
extern int GAME_DATA_GetSymbolMapFlag(struct GameData *gameData);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern struct MyItem *GAME_DATA_GetMyItem(struct GameData *gameData);
extern struct Config *SYSTEM_DATA_GetConfig(struct SaveControl *saveControl);
extern struct PokedexSave *ZUKAN_SAVE_GetBlock(struct SaveControl *saveControl);
extern struct PokedexSave *ZUKAN_SAVE_GetFromGameData(struct GameData *gameData);
extern void ZUKAN_SAVE_RegisterSeen(struct PokedexSave *pokedex, struct PokemonParam *mon);

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

/* Party and Pokemon. */
extern u32 POKEPARTY_GetCount(struct Party *party);
extern struct PokemonParam *POKEPARTY_GetMember(struct Party *party, u32 index);
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *mon, u32 paramId, void *buffer);
extern void POKE_TOOL_ChangeForm(struct PokemonParam *mon, u16 form);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern u8 VM_GetTimeZoneLight(int season, int timeZone);
extern u16 GF_STANDARD_SetupCalc(const void *src, u32 len);
extern void WORDSET_SetSlotMonName(struct WordSet *wordSet, u32 index, struct PokemonParam *mon);
extern void MI_CpuFill8(void *dst, int value, int size);
extern void GFL_HEAP_Free(void *block);

/* Field models and the field map. */
extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *outPos);
extern void FIELD_ENCOUNT_SetFieldSituation(SceneInfo *out, struct GameData *gameData, struct FieldMap *fieldMap);
extern void *FIELDMAP_GetEncEff(struct FieldMap *fieldMap);
extern void ENCEFF_Start(void *proc, struct GameEvent *event, int mode);
extern struct Mmdl *FLDMMDL_SysSearchObjId(struct MmdlSys *mmdlSys, u32 objId);
extern void FLDMMDL_GetPos(struct Mmdl *mmdl, VecFx32 *outPos);
extern void FLDMMDL_SetPos(struct Mmdl *mmdl, VecFx32 *pos);
extern void FLDMMDL_SetMoveBit(struct Mmdl *mmdl, u32 bits);
extern void *EVENT_MAPCHANGE_CreateWarpEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effectId, VecFx32 *pos, u16 flag, int param);

/* Trial house (ov021 trial_house.c and ov010 fld_btl_inst_tool.c). */
extern TrialHouseWork *TRIAL_HOUSE_CreateWork(struct GameSystem *gameSystem);
extern void TRIAL_HOUSE_DeleteWork(struct GameSystem *gameSystem, TrialHouseWork **slot);
extern void TRIAL_HOUSE_SetBattleMode(TrialHouseWork *work, u32 mode);
extern void TRIAL_HOUSE_SetUseDeliveredTrainers(TrialHouseWork *work, int value);
extern u16 TRIAL_HOUSE_LoadTrainer(struct GameSystem *gameSystem, TrialHouseWork *work, int index);
extern struct GameEvent *TRIAL_HOUSE_CreateTrainerMsgEvent(struct GameSystem *gameSystem, TrialHouseWork *work, u32 index, u32 mmdlId);
extern struct GameEvent *TRIAL_HOUSE_CreateDeliveryTask(struct GameSystem *gameSystem, TrialHouseWork *work, u16 *outValue);
extern void TRIAL_HOUSE_ComputeScoreAndRank(struct GameSystem *gameSystem, TrialHouseWork *work, u16 *outRank, u16 *outScore);
extern int TRIAL_HOUSE_GetDeliveryState(struct GameSystem *gameSystem, TrialHouseWork *work);
extern struct GameEvent *TRIAL_HOUSE_CreateSaveTask(struct GameSystem *gameSystem, TrialHouseWork *work, int param);
extern int TRIAL_HOUSE_GetRecordSlotsState(struct GameSystem *gameSystem);
extern struct RecordBlock *RECORD_GetFromSave(struct SaveControl *saveControl);
extern void RECORD_SetTrialRank(struct RecordBlock *record, u8 rank);
extern u8 RECORD_GetTrialRank(struct RecordBlock *record);
extern struct GameEvent *FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(struct GameSystem *gameSystem, TrialHouseWork *work, int regulationId, int useTempParty, u16 *resultOk);
extern struct GameEvent *FLD_BTL_INST_TOOL_CreateBattleEvent(struct GameSystem *gameSystem, TrialHouseWork *work);
extern struct GameEvent *FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(struct GameSystem *gameSystem, int arg0, int arg1);

/* Symbol map save and link records. */
extern struct SymbolSave *SYMBOL_SAVE_GetBlock(struct SaveControl *saveControl);
extern void SYMBOL_SAVE_RemoveSlotAndCommit(struct SymbolSave *save, u32 index);
extern u32 SYMBOL_SAVE_FindRecord(struct SaveControl *saveControl, SymbolKey *key, u32 heapId, u32 matchMode);
extern SymbolMapLinkRecord *SYMBOL_MAP_CreateLinkRecord(u16 heapId, struct GameSystem *gameSystem, u32 *outStart);
extern int SYMBOL_MAP_MoveRecordToPairedBand(struct SymbolSave *save, u32 index);
extern int SYMBOL_MAP_IsHomeCell(int symbolMapFlag);
extern int SYMBOL_MAP_IsBlankCell(int symbolMapFlag);
extern int SYMBOL_MAP_GetSelectedNeighborCell(struct GameSystem *gameSystem, int cellId, int direction);
extern struct GameEvent *FIELD_INTRUDE_EVENT_StartSymbolEntry(struct GameSystem *gameSystem, int direction, int cell);
extern void INTRUDE_FIELD_GetMmdlParamPair(SymbolKey *outKey, struct Mmdl *mmdl);
extern int INTRUDE_FIELD_GetMmdlParam0(struct Mmdl *mmdl);
extern struct PokemonParam *INTRUDE_FIELD_CreateSymbolMon(int heapId, struct GameData *gameData, SymbolKey *key);
extern void INTRUDE_FIELD_SpawnSymbolMons(struct FieldMap *fieldMap, u32 start, SymbolMapLinkRecord *record, int count, int page);
extern struct IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(struct GameComm *comm);
extern void INTRUDE_COMM_SetPendingValue(struct IntrudeCommSys *linkState, int value);
extern int INTRUDE_COMM_GetPartnerSlot(struct GameComm *comm, struct GameData *gameData);
extern void INTRUDE_COMM_GetMarkerPosForPartner(struct GameComm *comm, struct GameData *gameData, VecFx32 *outPos);

/* Overlay screens of the symbol Pokemon viewing event. */
extern void *PDC_CreateArgs(struct GameData *gameData, struct PokemonParam *mon, SceneInfo *scene, struct MyStatus *myStatus,
                           struct MyItem *myItem, struct Config *config, struct PokedexSave *pokedex, u16 heapId);
extern int PDC_GetResult(void *screen);
extern void *EVENT_PDC_RETURN_CreateArgs(struct GameData *gameData, int accepted, struct PokemonParam *mon, u16 heapId);
extern void EVENT_PDC_RETURN_DeleteArgs(void *screen);
extern u32 MYITEM_SAVEDATA_AddItem(struct MyItem *myItem, u16 itemId, u16 quantity, u16 heapId);
extern u32 MYITEM_SAVEDATA_RemoveItem(struct MyItem *myItem, u16 itemId, u16 quantity, u16 heapId);
extern int GF_OVERLAY_Load(u32 overlayId);
extern void GF_OVERLAY_Unload(u32 overlayId);
extern const s16 FX_SinCosTable_[];
extern u8 ov098_id[];
extern u8 ov227_id[];
extern u8 gPdcProcData[];
extern u8 d_021B98A4[];

void FORMCHANGE_RevertShaymin(struct GameData *gameData, struct Party *party);
int FORMCHANGE_RevertShayminIfTimeOfDayChanged(struct GameData *gameData, struct Party *party, int elapsedMinutes, TimeOfDay *time, int season);
int FORMCHANGE_RevertShayminAtNight(struct GameData *gameData, struct Party *party, u32 *hour, int season);
void FORMCHANGE_RevertShayminAndRegister(struct GameData *gameData, struct Party *party);
int SCRCMD_TRIALHOUSE_CreateWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_FreeWork(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_SetBattleMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartPartySelect(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_LoadRecord(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartTrainerMessage(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartBattle(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_SetRecordSource(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_SetRank(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetRank(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartDownload(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetRankAndScore(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetSaveState(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartSaveEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_StartAward(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_TRIALHOUSE_GetClearFlags(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MMDL_StartRise(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MMDL_RiseEventMain(struct GameEvent *event, u32 *state, void *work);
int SCRCMD_MMDL_StartOrbit(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MMDL_OrbitEventMain(struct GameEvent *event, u32 *mode, void *work);
void FORMCHANGE_UpdateSeasonForms(struct GameData *gameData, struct Party *party, int season);
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

#define SCRIPT_WORK_TARGET_OBJ_ID 0x8011  /* script work holding the object id the script talks to */
#define MMDL_MOVE_BIT_RISE 0x8000
#define SYMBOL_MARKER_EFFECT_ID 0x117
#define SYMBOL_MARKER_OFFSET_X (0x3E << 14)
#define SYMBOL_VIEW_BGM_ID 0x468
#define SYMBOL_VIEW_ITEM_ID 0x240  /* item added while the screens run, removed after */
#define SYMBOL_UNSEEN_SPECIES 0x28B
#define SYMBOL_UNSEEN_FORM 12
#define SYMBOL_VIEW_HEAP_ID 4

/* Species and form ids. */
#define SPECIES_SHAYMIN 0x1EC
#define SPECIES_DEERLING 585
#define SPECIES_SAWSBUCK 586
#define PARAM_SPECIES 5
#define PARAM_FORM 0x6F
#define SHAYMIN_FORM_SKY 1
#define SHAYMIN_FORM_LAND 0

/* Table columns of VM_GetTimeZoneLight: first hour of the day and first hour of the night. */
#define TIME_ZONE_DAY_START 0
#define TIME_ZONE_NIGHT_START 3

/* Shaymin sky forme back to land forme for every Shaymin in the party. */
void FORMCHANGE_RevertShaymin(struct GameData *gameData, struct Party *party)
{
    int i;
    int count;
    struct PokemonParam *mon;
    int species;
    int form;

    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);
        if (species == SPECIES_SHAYMIN && form == SHAYMIN_FORM_SKY)
            POKE_TOOL_ChangeForm(mon, SHAYMIN_FORM_LAND);
    }
}

/*
 * Reverts Shaymin when more time has passed than the current time of day has
 * lasted so far (elapsedMinutes against the minutes since the day or night began).
 * Returns 1 when the party was changed.
 */
int FORMCHANGE_RevertShayminIfTimeOfDayChanged(struct GameData *gameData, struct Party *party, int elapsedMinutes, TimeOfDay *time, int season)
{
    int nightStart;
    int dayStart;
    int hour;
    int hoursSince;

    nightStart = VM_GetTimeZoneLight(season, TIME_ZONE_NIGHT_START);
    dayStart = VM_GetTimeZoneLight(season, TIME_ZONE_DAY_START);
    hour = time->hour;
    if (!((u32)hour < (u32)nightStart && (u32)hour >= (u32)dayStart)) {
        hoursSince = hour;
        if (hoursSince < dayStart) {
            hoursSince += 24;
        }
        hoursSince = hoursSince - nightStart;
        if (time->minute + hoursSince * 60 < elapsedMinutes + 1) {
            FORMCHANGE_RevertShaymin(gameData, party);
            return 1;
        }
        return 0;
    }
    hoursSince = hour - dayStart;
    if (time->minute + hoursSince * 60 < elapsedMinutes) {
        FORMCHANGE_RevertShaymin(gameData, party);
        return 1;
    }
    return 0;
}

/* At night: reverts Shaymin and records the form change. Returns 1 at night. */
int FORMCHANGE_RevertShayminAtNight(struct GameData *gameData, struct Party *party, u32 *hour, int season)
{
    u32 nightStart;
    u32 dayStart;
    int result;

    nightStart = VM_GetTimeZoneLight(season, TIME_ZONE_NIGHT_START);
    dayStart = VM_GetTimeZoneLight(season, TIME_ZONE_DAY_START);
    result = 0;
    if (!(*hour < nightStart && *hour >= dayStart)) {
        FORMCHANGE_RevertShayminAndRegister(gameData, party);
        result = 1;
    }
    return result;
}

/* Reverts every sky forme Shaymin, registering the first one in the Pokedex. */
void FORMCHANGE_RevertShayminAndRegister(struct GameData *gameData, struct Party *party)
{
    int registered;
    int count;
    struct PokedexSave *pokedex;
    int i;
    struct PokemonParam *mon;
    int species;
    int form;

    pokedex = ZUKAN_SAVE_GetFromGameData(gameData);
    registered = 0;
    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        mon = POKEPARTY_GetMember(party, i);
        species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);
        if (species == SPECIES_SHAYMIN && form == SHAYMIN_FORM_SKY) {
            POKE_TOOL_ChangeForm(mon, SHAYMIN_FORM_LAND);
            if (registered == 0) {
                ZUKAN_SAVE_RegisterSeen(pokedex, mon);
                registered = 1;
            }
        }
    }
}

/* Trial house script command: creates the trial house work once. */
int SCRCMD_TRIALHOUSE_CreateWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    TrialHouseWork **slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));

    if (*slot == 0) {
        *slot = TRIAL_HOUSE_CreateWork(gameSystem);
    }
    return 0;
}

/* Trial house script command: frees the trial house work. */
int SCRCMD_TRIALHOUSE_FreeWork(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);

    TRIAL_HOUSE_DeleteWork(gameSystem, GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem)));
    return 0;
}

/* Trial house script command: sets the battle mode (party size) from a script value. */
int SCRCMD_TRIALHOUSE_SetBattleMode(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u32 mode;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    mode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    TRIAL_HOUSE_SetBattleMode(*slot, mode);
    return 0;
}

int SCRCMD_TRIALHOUSE_StartPartySelect(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int regulationId;
    int useTempParty;
    u16 *resultOk;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    regulationId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    useTempParty = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultOk = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreatePartySelectStepEvent(gameSystem, *slot, regulationId, useTempParty, resultOk));
    return 1;
}

int SCRCMD_TRIALHOUSE_LoadRecord(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int index;
    u16 *outValue;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    index = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    outValue = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *outValue = TRIAL_HOUSE_LoadTrainer(gameSystem, *slot, index);
    return 0;
}

int SCRCMD_TRIALHOUSE_StartTrainerMessage(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int index;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    index = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, TRIAL_HOUSE_CreateTrainerMsgEvent(gameSystem, *slot, index, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_StartBattle(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreateBattleEvent(gameSystem, *slot));
    return 1;
}

int SCRCMD_TRIALHOUSE_SetRecordSource(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    TRIAL_HOUSE_SetUseDeliveredTrainers(*slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Trial house script command: sets the trial house rank byte of the save from a script value. */
int SCRCMD_TRIALHOUSE_SetRank(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    u32 rank;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = ICA_ANIME_GetField1C(SCRCMD_WORK_GetGameSystem(cmdWork));
    rank = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    RECORD_SetTrialRank(RECORD_GetFromSave(GAME_DATA_GetSaveControl(gameData)), rank);
    return 0;
}

/* Trial house script command: stores the trial house rank byte of the save in a script work. */
int SCRCMD_TRIALHOUSE_GetRank(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u16 *outRank;
    struct SaveControl *saveControl;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    outRank = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    saveControl = GAME_DATA_GetSaveControl(gameData);
    *outRank = RECORD_GetTrialRank(RECORD_GetFromSave(saveControl));
    return 0;
}

int SCRCMD_TRIALHOUSE_StartDownload(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    SCRIPT_SYS_CallEvent(scriptWork, TRIAL_HOUSE_CreateDeliveryTask(gameSystem, *slot, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_GetRankAndScore(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u16 *outRank;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    outRank = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    TRIAL_HOUSE_ComputeScoreAndRank(gameSystem, *slot, outRank, SCRIPT_WORK_ReadWorkPointer(vm, cmdWork));
    return 0;
}

int SCRCMD_TRIALHOUSE_GetSaveState(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u16 *outValue;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    outValue = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *outValue = TRIAL_HOUSE_GetDeliveryState(gameSystem, *slot);
    return 0;
}

int SCRCMD_TRIALHOUSE_StartSaveEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    slot = GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    SCRIPT_SYS_CallEvent(scriptWork, TRIAL_HOUSE_CreateSaveTask(gameSystem, *slot, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_StartAward(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int arg0;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    GAME_DATA_GetListCursor(ICA_ANIME_GetField1C(gameSystem));
    arg0 = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_SYS_CallEvent(scriptWork, FLD_BTL_INST_TOOL_CreateTrialHouseAwardEvent(gameSystem, arg0, SCRIPT_WORK_ReadWorkValue(vm, cmdWork)));
    return 1;
}

int SCRCMD_TRIALHOUSE_GetClearFlags(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *outValue;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    outValue = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *outValue = TRIAL_HOUSE_GetRecordSlotsState(gameSystem);
    return 0;
}

/* Script command: raises a field model to a height over a number of frames. */
int SCRCMD_MMDL_StartRise(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int objId;
    int height;
    int frames;
    struct GameEvent *event;
    MmdlRiseWork *work;
    struct Mmdl *mmdl;

    SCRCMD_WORK_GetGameData(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    height = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    frames = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_MMDL_RiseEventMain, sizeof(MmdlRiseWork));
    work = GAME_EVENT_GetWork(event);
    work->frames = frames;
    work->frame = 0;
    mmdl = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(ICA_ANIME_GetField20(gameSystem)), objId);
    FLDMMDL_GetPos(mmdl, &work->startPos);
    work->mmdl = mmdl;
    FLDMMDL_SetMoveBit(mmdl, MMDL_MOVE_BIT_RISE);
    work->totalRise = (height << 15) - work->startPos.y;
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

int SCRCMD_MMDL_RiseEventMain(struct GameEvent *event, u32 *state, void *work)
{
    MmdlRiseWork *rise = work;
    VecFx32 pos;

    rise->frame = rise->frame + 1;
    pos = rise->startPos;
    pos.y += (rise->totalRise * rise->frame) / rise->frames;
    FLDMMDL_SetPos(rise->mmdl, &pos);
    if (rise->frame >= rise->frames) {
        return 1;
    }
    return 0;
}

/* Script command: moves a field model in a spiral and circle around its position. */
int SCRCMD_MMDL_StartOrbit(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int objId;
    struct GameEvent *event;
    struct Mmdl *mmdl;
    MmdlOrbitWork *work;

    SCRCMD_WORK_GetGameData(cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_MMDL_OrbitEventMain, sizeof(MmdlOrbitWork));
    work = GAME_EVENT_GetWork(event);
    work->frame = 0;
    mmdl = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(ICA_ANIME_GetField20(gameSystem)), objId);
    FLDMMDL_GetPos(mmdl, &work->centerPos);
    work->mmdl = mmdl;
    SCRIPT_SYS_CallEvent(scriptWork, event);
    return 1;
}

static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

/*
 * Three-phase orbit step: spiral out over 110 frames, circle at radius 3
 * for 80, spiral in for 80, returning 1 when done. FX_Mul must be the
 * inline function with the table value first (the macro, or the radius
 * first, puts the radius in r0:r1 and spills its sign word: 368 out).
 */
int SCRCMD_MMDL_OrbitEventMain(struct GameEvent *event, u32 *mode, void *work)
{
    MmdlOrbitWork *orbit = work;
    VecFx32 pos;
    u32 frame;
    int index;
    fx32 radius;

    pos = orbit->centerPos;
    frame = ++orbit->frame;
    switch (*mode) {
    case 0:
        index = (frame << 17) / 110;
        if (index >= 0x10000)
            index %= 0x10000;
        index = (index >> 4) * 2;
        radius = (frame * 3 << 16) / 110;
        pos.x += FX_Mul(FX_SinCosTable_[index + 1], radius);
        pos.z += FX_Mul(FX_SinCosTable_[index], radius);
        FLDMMDL_SetPos(orbit->mmdl, &pos);
        if (orbit->frame >= 110) {
            orbit->frame = 0;
            *mode = 1;
        }
        break;
    case 1:
        index = (frame << 16) / 80;
        if (index >= 0x10000)
            index %= 0x10000;
        index = (index >> 4) * 2;
        pos.x += FX_Mul(FX_SinCosTable_[index + 1], 0x30000);
        pos.z += FX_Mul(FX_SinCosTable_[index], 0x30000);
        FLDMMDL_SetPos(orbit->mmdl, &pos);
        if (orbit->frame >= 80) {
            orbit->frame = 0;
            *mode = 2;
        }
        break;
    case 2:
        index = (frame << 16) / 80;
        if (index >= 0x10000)
            index %= 0x10000;
        index = (index >> 4) * 2;
        radius = ((80 - frame) * 3 << 16) / 80;
        pos.x += FX_Mul(FX_SinCosTable_[index + 1], radius);
        pos.z += FX_Mul(FX_SinCosTable_[index], radius);
        FLDMMDL_SetPos(orbit->mmdl, &pos);
        if (orbit->frame >= 80)
            return 1;
        break;
    }
    return 0;
}

/*
 * Season change: walks every mon of a party and sets the form (field 0x6F)
 * of Deerling and Sawsbuck to the season index, registering each species once
 * with the Pokedex when one of its members actually changed.
 */
void FORMCHANGE_UpdateSeasonForms(struct GameData *gameData, struct Party *party, int season)
{
    struct PokedexSave *pokedex;
    int i;
    int count;
    int deerlingForm;
    int sawsbuckForm;
    int deerlingRegistered;
    int sawsbuckRegistered;

    pokedex = ZUKAN_SAVE_GetFromGameData(gameData);
    deerlingRegistered = 0;
    sawsbuckRegistered = 0;

    switch (season) {
    case 0:
        deerlingForm = 0;
        sawsbuckForm = 0;
        break;
    case 1:
        deerlingForm = 1;
        sawsbuckForm = 1;
        break;
    case 2:
        deerlingForm = 2;
        sawsbuckForm = 2;
        break;
    case 3:
        deerlingForm = 3;
        sawsbuckForm = 3;
        break;
    default:
        deerlingForm = 0;
        sawsbuckForm = 0;
        break;
    }

    count = POKEPARTY_GetCount(party);
    for (i = 0; i < count; i++) {
        struct PokemonParam *mon = POKEPARTY_GetMember(party, i);
        int species = POKE_TOOL_GetPartyValue(mon, PARAM_SPECIES, 0);
        int form = POKE_TOOL_GetPartyValue(mon, PARAM_FORM, 0);

        if (species == SPECIES_DEERLING && form != deerlingForm) {
            POKE_TOOL_ChangeForm(mon, deerlingForm);
            if (!deerlingRegistered) {
                ZUKAN_SAVE_RegisterSeen(pokedex, mon);
                deerlingRegistered = 1;
            }
        } else if (species == SPECIES_SAWSBUCK && form != sawsbuckForm) {
            POKE_TOOL_ChangeForm(mon, sawsbuckForm);
            if (!sawsbuckRegistered) {
                ZUKAN_SAVE_RegisterSeen(pokedex, mon);
                sawsbuckRegistered = 1;
            }
        }
    }
}

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

            SCRIPT_SYS_CallEvent(scriptWork, SCRCMD_SYMBOL_CreateViewEvent(gameSystem, ICA_ANIME_GetField20(gameSystem), mon, key, resultOut, SYMBOL_VIEW_HEAP_ID));
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
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    ICA_ANIME_GetField24(gameSystem);
    record = SYMBOL_MAP_CreateLinkRecord(SCRCMD_WORK_GetHeapId(cmdWork), gameSystem, &start);
    if (record != 0) {
        INTRUDE_FIELD_SpawnSymbolMons(fieldMap, start, record, record->entryCount, record->page);
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
        *result = SYMBOL_MAP_MoveRecordToPairedBand(symbolSave, INTRUDE_FIELD_GetMmdlParam0(mmdl));
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
            WORDSET_SetSlotMonName(SCRIPT_WORK_GetWordSet(SCRCMD_WORK_GetScriptWork(cmdWork)), wordSetIndex, mon);
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
    comm = ICA_ANIME_GetField24(gameSystem);
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
        fieldMap = ICA_ANIME_GetField20(gameSystem);
        player = FIELDMAP_GetFieldPlayer(fieldMap);
        comm = ICA_ANIME_GetField24(gameSystem);
        FIELD_PLAYER_GetPos(player, &playerPos);
        INTRUDE_COMM_GetMarkerPosForPartner(comm, gameData, &markerPos);
        markerPos.x = markerPos.x + (playerPos.x - SYMBOL_MARKER_OFFSET_X);
        event = EVENT_MAPCHANGE_CreateWarpEvent(gameSystem, fieldMap, SYMBOL_MARKER_EFFECT_ID, &markerPos, 1, 0);
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
    return FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(ICA_ANIME_GetField20(SCRCMD_WORK_GetGameSystem(cmdWork))), objId);
}

/* Key of the field model that work 0x8011 names. */
void SCRCMD_SYMBOL_GetTargetObjectKey(ScrcmdWork *cmdWork, SymbolKey *outKey)
{
    ScriptWork *scriptWork;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    INTRUDE_FIELD_GetMmdlParamPair(outKey, SCRCMD_SYMBOL_GetMmdl(cmdWork, SCRIPT_WORK_GetWorkValue(scriptWork, SCRCMD_WORK_GetGameData(cmdWork), SCRIPT_WORK_TARGET_OBJ_ID)));
}

/*
 * The heap id is not used: the allocation below always takes heap 4.
 */
struct PokemonParam *SCRCMD_SYMBOL_CreateObjectPokemon(ScrcmdWork *cmdWork, struct Mmdl *mmdl, int heapId, SymbolKey *outKey)
{
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);

    INTRUDE_FIELD_GetMmdlParamPair(outKey, mmdl);
    return INTRUDE_FIELD_CreateSymbolMon(SYMBOL_VIEW_HEAP_ID, gameData, outKey);
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
    linkState = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    if (linkState != 0) {
        INTRUDE_COMM_SetPendingValue(linkState, GAME_DATA_GetSymbolMapFlag(gameData));
    }
}

/* Creates the symbol Pokemon viewing event. */
struct GameEvent *SCRCMD_SYMBOL_CreateViewEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct PokemonParam *mon, SymbolKey key,
                                u16 *resultOut, u16 heapId)
{
    struct GameData *gameData;
    struct GameEvent *event;
    SymbolViewWork *work;

    gameData = ICA_ANIME_GetField1C(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, SCRCMD_SYMBOL_ViewEventMain, sizeof(SymbolViewWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(SymbolViewWork));
    work->fieldMap = fieldMap;
    work->resultOut = resultOut;
    work->heapId = heapId;
    work->mon = mon;
    work->key = key;
    work->crc = GF_STANDARD_SetupCalc(mon, POKE_TOOL_GetPartyParamSize());
    if (SYMBOL_SAVE_FindRecord(GAME_DATA_GetSaveControl(gameData), &key, heapId, 0) == 0)
        work->key.species = SYMBOL_UNSEEN_SPECIES;
    FIELD_ENCOUNT_SetFieldSituation(&work->scene, gameData, fieldMap);
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
    struct GameData *gameData = ICA_ANIME_GetField1C(gameSystem);
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
        if (SYMBOL_SAVE_FindRecord(GAME_DATA_GetSaveControl(gameData), &key, heapId, 1) == 0)
            work->key.form = SYMBOL_UNSEEN_FORM;
        ENCEFF_Start(FIELDMAP_GetEncEff(work->fieldMap), event, 0);
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
        if (SYMBOL_SAVE_FindRecord(GAME_DATA_GetSaveControl(gameData), &key, heapId, 1) == 0
            || SYMBOL_SAVE_FindRecord(GAME_DATA_GetSaveControl(gameData), &work->key, work->heapId, 0) == 0)
            ok = 0;
        if (ok == 1)
            *work->resultOut = 1;
        else
            *work->resultOut = 0;
        GF_OVERLAY_Unload(FS_OVERLAY_ID(ov098));
        GF_OVERLAY_Load(FS_OVERLAY_ID(ov227));
        work->resultScreen = EVENT_PDC_RETURN_CreateArgs(gameData, ok, work->mon, work->heapId);
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
