/*
 * file:     enceff.c
 * unit:     yes
 * function: ENCEFF_Create, ENCEFF_Delete, ENCEFF_Start, ENCEFF_GetEffect, ENCEFF_RunUpdate, ENCEFF_AllocWork, ENCEFF_FreeWork, ENCEFF_GetWork, ENCEFF_LoadOverlay, ENCEFF_LoadOverlays4B4D, ENCEFF_LoadOverlay4B, ENCEFF_UnloadOverlays, ENCEFF_SelectEffectAndBgm, ENCEFF_SelectEffectAndBgmForTrainer, SCRCMD_StartCountOtherOtIdsTask, SCRCMD_CountOtherOtIdsTaskMain, SCRCMD_CountPartyOtherOtIds, SCRCMD_CountBoxOtherOtIds, SCRCMD_CountBattleBoxOtherOtIds, SCRCMD_AddOtherOtId, SCRCMD_AddUniqueOtId, SCRCMD_StartSubProcOv057, SCRCMD_GetPlayerLocationValue, INTRUDE_FindOfferSlotAt, INTRUDE_TakeOfferSlot, INTRUDE_GetNextOfferSpot, INTRUDE_OfferEventMain, INTRUDE_StartOfferEvent, SCRCMD_FillPartnerCandidates, SCRCMD_CollectPartnersByLanguage, SCRCMD_GetPartnerCandidateHistoryIndex, SCRCMD_GetPartnerGreetingMessage, SCRCMD_CalcPartnerGreetingIndex, SCRCMD_SetPartnerWords, SCRCMD_GetWifiHistoryCountryCount, SCRCMD_GetWifiHistoryEntryCount, SCRCMD_MarkPartnerCandidate, SCRCMD_IsPartnerCandidateMarked, SCRCMD_SetWifiHistoryRatingLevel, SCRCMD_SetWifiHistoryGreetingSet, SCRCMD_GetWifiHistoryGreetingSet, SCRCMD_FillPartnerCandidatesFromScript, SCRCMD_GetPartnerGreetingMessageFromScript, SCRCMD_HasPlayerLanguage
 * address:  0x021CF45C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021CEDA0 (lane L136, __FILE__ anchor enceff.c at 021CF45C/021CF52C (d_021DE5FC); 021CEDA0..021D0114 are its helpers and the ov010 script command handlers that use them).
 *
 * symbols:
 *   func_0201F02C  0x0201F02C  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   d_021DE5FC     0x021DE5FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GFL_HEAP_GetAllocatableSize  0x0203038C  arm
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DB4FC     0x021DB4FC  data  a4
 *   func_02034AC4  0x02034AC4  arm
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   ov075_id       0x0000004B  data
 *   func_02034A5C  0x02034A5C  arm
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_GetParentZoneId  0x02013E40  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsAnyGrass  0x021AB2BC  thumb  ov021
 *   MAP_ATTR_IsSplashWaterB  0x021AB364  thumb  ov021
 *   MAP_ATTR_IsSandVariant  0x021AB37C  thumb  ov021
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 *   TPOKE_DATA_GetTrainerKind  0x0202A3FC  thumb
 *   TPOKE_DATA_FindTrainerType  0x0202A3D8  thumb
 *   FIELDMAP_GetAreaData  0x02188D58  thumb  ov021
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   d_021DB7E0     0x021DB7E0  data  ov021  a2
 *   d_021DB7F6     0x021DB7F6  data  ov021  a1
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   func_020079BC  0x020079BC  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BATTLE_BOX_GetFromSave  0x0200BAC8  thumb
 *   BATTLE_BOX_GetMon  0x0200BBEC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   abs_id_39      0x00000039  data
 *   d_021F3900     0x021F3900  data  ov057  a4
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   gIntrudeOfferTilePositions  0x021DB834  data  a4
 *   SCRIPT_SYS_ChangeScriptEvent  0x021587B0  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   STRBUF_SetStringN  0x02045994  arm
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200E878  0x0200E878  thumb
 *   GAME_DATA_GetSaveSyncBlock  0x02012F38  thumb
 *   func_02009634  0x02009634  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   CURSOR_MOVE_GetTableValue  0x02025C74  thumb
 *   func_02025B64  0x02025B64  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_02008570  0x02008570  thumb
 *   WORDSET_DeleteMsgdataF094  0x0201F094  thumb
 *   WORDSET_Callback  0x0201EE60  thumb
 *   func_02009628  0x02009628  thumb
 *   func_0201F198  0x0201F198  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   WIFI_HISTORY_GetDisplayCount  0x02009590  thumb
 *   WIFI_HISTORY_GetFirstFreeEntry  0x020095C8  thumb
 *   func_02009698  0x02009698  thumb
 *   WIFI_HISTORY_SetRatingLevel  0x020095FC  thumb
 *   WIFI_HISTORY_SetGreetingSet  0x02009618  thumb
 *   VM_GetU16  0x02011330  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;

struct GameSystem;
struct GameData;
struct GameEvent;
struct FieldMap;
struct FieldPlayer;
struct ScriptVm;
struct ScrcmdWork;
struct ScriptWork;
struct SaveControl;
struct WordSet;
struct Strbuf;
struct PokeParty;
struct PokemonParam;
struct BoxData;
struct BattleBoxSave;
struct WifiHistory;
struct HistoryEntry;
struct PlayerLocation;
struct MyStatus;

/* Encounter effect (ENCEFF): one effect plays before a battle. */
struct EncEffWork;
typedef void (*EncEffUpdateFunc)(struct EncEffWork *eff, u32 self, u32 arg0, u32 arg1);

/* Work of one running effect (0x20 bytes). */
typedef struct EncEffWork {
    struct GameEvent *effect;    /* 0x00: effect event made by the builder */
    EncEffUpdateFunc update;     /* 0x04 */
    struct FieldMap *fieldMap;   /* 0x08 */
    u32 overlayIds[3];           /* 0x0C: overlays loaded for this effect */
    int overlayCount;            /* 0x18 */
    void *effectWork;            /* 0x1C: memory owned by the effect */
} EncEffWork;

/* One row of the effect table (0x14 bytes, ENCEFF_KIND_COUNT rows). */
typedef struct EncEffEntry {
    struct GameEvent *(*build)(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 arg);   /* 0x00 */
    EncEffUpdateFunc update;                                /* 0x04 */
    int overlayId;                                          /* 0x08: -1 for none */
    u32 buildArg;                                           /* 0x0C */
    u32 minLevel;                                           /* 0x10 */
} EncEffEntry;

enum {
    ENCEFF_KIND_COUNT = 0x25,
    ENCEFF_KIND_FALLBACK = 7,
    ENCEFF_MAX_OVERLAYS = 3
};

/* Pokemon data ids read through the party, box and battle box getters. */
enum {
    MON_DATA_OT_ID = 7,
    MON_DATA_IS_EGG = 0x4C,
    MON_DATA_HAS_SPECIES = 0xA9
};

enum {
    BOX_COUNT = 0x18,
    BOX_SLOT_COUNT = 30,
    BATTLE_BOX_SLOT_COUNT = 6
};

/* Distinct original-trainer ids found so far (0xCC bytes). */
#define OT_ID_LIST_MAX 50
typedef struct OtIdList {
    int count;
    int ids[OT_ID_LIST_MAX];
} OtIdList;

/* Work of the original-trainer count task (0xD8 bytes allocated). */
typedef struct OtCountTask {
    u32 playerId;       /* 0x00: own trainer id, never counted */
    int nextBox;        /* 0x04: next PC box to scan */
    u16 *result;        /* 0x08: script variable that receives the count */
    OtIdList list;      /* 0x0C */
} OtCountTask;

/* A gift left by an Entralink visitor, shown at a map spot (0x14 bytes). */
typedef struct IntrudeOfferSlot {
    u16 senderName[8];  /* 0x00 */
    u16 offerId;        /* 0x10: 0 for an empty slot */
    u8 spotIndex;       /* 0x12: row of the spot table */
    u8 reserved13;
} IntrudeOfferSlot;

#define INTRUDE_OFFER_SLOT_COUNT 20
typedef struct IntrudeOfferLog {
    u8 header[0x10];
    IntrudeOfferSlot slot[INTRUDE_OFFER_SLOT_COUNT];
} IntrudeOfferLog;

/* Where an offer waits: tile position and zone (8 bytes per row). */
typedef struct IntrudeOfferSpot {
    s16 x;
    s16 y;
    s16 z;
    u16 zoneId;
} IntrudeOfferSpot;

/* Up to five Wi-Fi history partners with the same language (16 bytes, synced with the save). */
#define PARTNER_CANDIDATE_MAX 5
typedef struct PartnerCandidates {
    u8 language;                              /* 0x00 */
    u8 count;                                 /* 0x01 */
    u8 mode;                                  /* 0x02 */
    u8 viewId[PARTNER_CANDIDATE_MAX];         /* 0x03: trainer view of the partner */
    u8 historyIndex[PARTNER_CANDIDATE_MAX];   /* 0x08: entry in the Wi-Fi history */
    u8 reserved0D[3];
} PartnerCandidates;

enum {
    WIFI_HISTORY_ENTRY_COUNT = 20,
    WIFI_HISTORY_FIELD_MARKED = 5,
    WIFI_HISTORY_FIELD_INFO = 6
};

extern u32 func_020307B0(void *work);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
extern u32 GFL_HEAP_GetAllocatableSize(u32 key);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern void *func_020124E8(struct GameEvent *event);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(s32 overlayId);
extern u16 FIELDMAP_GetZoneId(struct FieldMap *fieldMap);
extern u16 ZONEDATA_GetParentZoneId(u32 zoneId);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);
extern u32 FIELD_PLAYER_GetNowAttribute(struct FieldPlayer *player);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int MAP_ATTR_IsAnyGrass(u16 tileType);
extern int MAP_ATTR_IsSplashWaterB(u16 tileType);
extern int MAP_ATTR_IsSandVariant(u32 tileType);
extern u32 TPOKE_DATA_GetRecordField(void *trainerData, u32 index);
extern u8 TPOKE_DATA_GetTrainerKind(u32 trainerClass);
extern u8 TPOKE_DATA_FindTrainerType(u32 trainerClass);
extern u32 FIELDMAP_GetAreaData(struct FieldMap *fieldMap);
extern u8 ZONEDATA_GetAreaInnerOuter(u32 areaData);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *cmdWork);
extern struct GameData *SCRCMD_WORK_GetGameData(struct ScrcmdWork *cmdWork);
extern struct ScriptWork *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern u16 SCRIPT_WORK_ReadWorkValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern u16 VM_GetU16(struct ScriptVm *vm);
extern void SCRIPT_SYS_CallEvent(struct ScriptWork *scriptWork, struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, void *func, u32 workSize);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern PartnerCandidates *GAME_DATA_GetSaveSyncBlock(struct GameData *gameData);
extern struct PokeParty *GAME_DATA_GetMyParty(struct GameData *gameData);
extern struct BoxData *GAME_DATA_GetBoxManager(struct GameData *gameData);
extern u32 func_02008530(const void *myStatus);
extern u8 func_0200856C(const void *myStatus);
extern u8 func_02008554(const void *myStatus);
extern u8 func_02008550(const void *myStatus);
extern u8 func_02008570(const void *myStatus);
extern u32 POKEPARTY_GetCount(struct PokeParty *party);
extern struct PokemonParam *POKEPARTY_GetMember(struct PokeParty *party, u32 index);
extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *mon, u32 dataId, u32 arg);
extern int func_020079BC(struct BoxData *boxData, u32 box, u32 slot, int dataId, int arg);
extern struct BattleBoxSave *BATTLE_BOX_GetFromSave(struct SaveControl *saveControl);
extern struct PokemonParam *BATTLE_BOX_GetMon(struct BattleBoxSave *battleBox, u32 team, u32 slot);
extern u32 func_02017E88(struct PokemonParam *mon, u32 dataId, u32 arg);
extern int *FIELD_SUBPROC_Start(int overlayId, int *mapFunc, const int *procData);
extern u32 FIELDMAP_GetMapFunc(struct FieldMap *fieldMap);
extern struct PlayerLocation *func_02008854(struct SaveControl *saveControl);
extern u16 func_02008990(const struct PlayerLocation *location);
extern IntrudeOfferLog *INTRUDE_GetFromSave(struct SaveControl *saveControl);
extern struct ScriptWork *SCRIPT_SYS_ChangeScriptEvent(struct GameEvent *event, int scriptId, int arg1, int heapId);
extern void SCRIPT_WORK_SetParams(struct ScriptWork *scriptWork, int param0, int param1, int param2, u16 param3);
extern struct WordSet *SCRIPT_WORK_GetWordSet(struct ScriptWork *scriptWork);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetStringN(struct Strbuf *dest, const u16 *src, u32 length);
extern void STRBUF_Delete(struct Strbuf *str);
extern void func_0201EE0C(struct WordSet *wordSet, u32 index, const struct Strbuf *src, u32 a, u32 b, u32 c);
extern struct WifiHistory *func_02009470(struct SaveControl *saveControl);
extern struct HistoryEntry *func_0200973C(struct WifiHistory *history, int index);
extern u32 func_02009634(const struct WifiHistory *history, u32 index, u32 field);
extern u8 func_02009628(const struct WifiHistory *history);
extern u8 WIFI_HISTORY_GetDisplayCount(struct WifiHistory *history, struct MyStatus *myStatus, u32 arg);
extern u8 WIFI_HISTORY_GetFirstFreeEntry(const struct WifiHistory *history);
extern void func_02009698(struct WifiHistory *history, int index, u32 field, u32 value);
extern void WIFI_HISTORY_SetRatingLevel(struct WifiHistory *history, int value);
extern void WIFI_HISTORY_SetGreetingSet(struct WifiHistory *history, int value);
extern int func_0200E878(PartnerCandidates *candidates);
extern u32 CURSOR_MOVE_GetTableValue(u32 outfit);
extern u8 func_02025B64(u32 language);
extern void func_0201F048(struct WordSet *wordSet, u32 index, u32 number);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *wordSet, u32 index, u32 a, u32 number);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, const void *myStatus);
extern void WORDSET_Callback(struct WordSet *wordSet, u32 index, u16 value);
extern void func_0201F198(struct WordSet *wordSet, u32 index, u32 value);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 a, u32 b, u32 c, u32 d);

extern char d_021DE5FC[];
extern char abs_id_4b[];
extern char abs_id_4d[];
extern unsigned char ov075_id[];
extern const EncEffEntry d_021DB4FC[];
extern const u16 d_021DB7E0[];
extern const u8 d_021DB7F6[];
extern char abs_id_39[];
extern char d_021F3900[];
extern const IntrudeOfferSpot gIntrudeOfferTilePositions[];

EncEffWork *ENCEFF_Create(u32 heapId, struct FieldMap *fieldMap);
int ENCEFF_Delete(EncEffWork *eff);
void ENCEFF_Start(EncEffWork *eff, struct GameEvent *parentEvent, int kind);
struct GameEvent *ENCEFF_GetEffect(EncEffWork *eff);
void ENCEFF_RunUpdate(EncEffWork *eff, u32 unused, u32 arg0, u32 arg1);
void ENCEFF_AllocWork(EncEffWork *eff, u32 size, u32 heapId);
void ENCEFF_FreeWork(EncEffWork *eff);
void *ENCEFF_GetWork(EncEffWork *eff);
void ENCEFF_LoadOverlay(EncEffWork *eff, u32 overlayId);
void ENCEFF_LoadOverlays4B4D(EncEffWork *eff);
void ENCEFF_LoadOverlay4B(EncEffWork *eff);
void ENCEFF_UnloadOverlays(EncEffWork *eff);
void ENCEFF_SelectEffectAndBgm(int species, int effectId, int hasWildOpponent, struct FieldMap *fieldMap, u32 *outEffectKind, u16 *outBgmId);
void ENCEFF_SelectEffectAndBgmForTrainer(void *trainerData, struct FieldMap *fieldMap, int *outEffectKind, u16 *outBgmId);
int SCRCMD_StartCountOtherOtIdsTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_CountOtherOtIdsTaskMain(struct GameEvent *event, int *seq, OtCountTask *task);
int SCRCMD_CountPartyOtherOtIds(u32 playerId, struct GameData *gameData, OtIdList *list);
int SCRCMD_CountBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 box, OtIdList *list);
int SCRCMD_CountBattleBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 team, OtIdList *list);
int SCRCMD_AddOtherOtId(int playerId, int otId, OtIdList *list);
int SCRCMD_AddUniqueOtId(int otId, OtIdList *list);
int SCRCMD_StartSubProcOv057(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetPlayerLocationValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int INTRUDE_FindOfferSlotAt(IntrudeOfferLog *log, int zoneId, int x, int y, int z);
void INTRUDE_TakeOfferSlot(IntrudeOfferLog *log, int index, IntrudeOfferSlot *dest);
const IntrudeOfferSpot *INTRUDE_GetNextOfferSpot(IntrudeOfferLog *log, int *index);
int INTRUDE_OfferEventMain(struct GameEvent *event, u32 seq, const IntrudeOfferSlot *offer);
struct GameEvent *INTRUDE_StartOfferEvent(struct GameSystem *gameSystem, u32 heapId, int slotIndex);
void SCRCMD_FillPartnerCandidates(struct GameSystem *gameSystem, int language, u32 mode);
void SCRCMD_CollectPartnersByLanguage(struct WifiHistory *history, PartnerCandidates *out, u32 language, u32 mode);
u8 SCRCMD_GetPartnerCandidateHistoryIndex(PartnerCandidates *candidates, u32 index);
int SCRCMD_GetPartnerGreetingMessage(struct WordSet *wordSet, struct GameSystem *gameSystem, PartnerCandidates *candidates, int index, u32 variant);
int SCRCMD_CalcPartnerGreetingIndex(int outfitVariant, u32 trainerId, u32 tier, int variant, int isSpecialLanguage);
void SCRCMD_SetPartnerWords(struct WordSet *wordSet, struct GameData *gameData, u32 historyIndex);
int SCRCMD_GetWifiHistoryCountryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetWifiHistoryEntryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_MarkPartnerCandidate(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_IsPartnerCandidateMarked(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SetWifiHistoryRatingLevel(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_SetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_FillPartnerCandidatesFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_GetPartnerGreetingMessageFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int SCRCMD_HasPlayerLanguage(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

EncEffWork *ENCEFF_Create(u32 heapId, struct FieldMap *fieldMap)
{
    EncEffWork *eff = func_02030734(heapId, sizeof(EncEffWork), 1, d_021DE5FC, 0x6c);

    eff->fieldMap = fieldMap;
    eff->overlayCount = 0;
    return eff;
}

int ENCEFF_Delete(EncEffWork *eff)
{
    ENCEFF_FreeWork(eff);
    ENCEFF_UnloadOverlays(eff);
    return func_020307B0(eff);
}

/* Builds the effect of kind idx from the table, loading its overlay first. */
void ENCEFF_Start(EncEffWork *eff, struct GameEvent *parentEvent, int kind)
{
    struct GameEvent *effect;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap = eff->fieldMap;

    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    if (kind >= ENCEFF_KIND_COUNT) {
        kind = 0;
    }
    if (GFL_HEAP_GetAllocatableSize(0x15) < d_021DB4FC[kind].minLevel) {
        kind = ENCEFF_KIND_FALLBACK;
    }
    if (d_021DB4FC[kind].overlayId != -1) {
        ENCEFF_LoadOverlay(eff, d_021DB4FC[kind].overlayId);
    }
    effect = d_021DB4FC[kind].build(gameSystem, fieldMap, d_021DB4FC[kind].buildArg);
    GAME_EVENT_CallEvent(parentEvent, effect);
    eff->effect = func_020124E8(effect);
    eff->update = d_021DB4FC[kind].update;
}

struct GameEvent *ENCEFF_GetEffect(EncEffWork *eff)
{
    return eff->effect;
}

/* Calls the update function of the effect, if it has one. */
void ENCEFF_RunUpdate(EncEffWork *eff, u32 unused, u32 arg0, u32 arg1)
{
    if (eff->update != 0) {
        eff->update(eff, (u32)eff->update, arg0, arg1);
    }
}

void ENCEFF_AllocWork(EncEffWork *eff, u32 size, u32 heapId)
{
    eff->effectWork = func_02030734(heapId, size, 1, d_021DE5FC, 0xe3);
}

void ENCEFF_FreeWork(EncEffWork *eff)
{
    void *work = eff->effectWork;
    if (work != 0) {
        func_020307B0(work);
        eff->effectWork = 0;
    }
}

void *ENCEFF_GetWork(EncEffWork *eff)
{
    return eff->effectWork;
}

/* Loads an overlay and remembers its id for the unload. */
void ENCEFF_LoadOverlay(EncEffWork *eff, u32 overlayId)
{
    func_02034AC4(overlayId);
    eff->overlayIds[eff->overlayCount++] = overlayId;
}

void ENCEFF_LoadOverlays4B4D(EncEffWork *eff)
{
    ENCEFF_LoadOverlay(eff, (u32)abs_id_4b);
    ENCEFF_LoadOverlay(eff, (u32)abs_id_4d);
}

void ENCEFF_LoadOverlay4B(EncEffWork *eff)
{
    ENCEFF_LoadOverlay(eff, (u32)ov075_id);
}

/* Unloads the overlays in reverse order. */
void ENCEFF_UnloadOverlays(EncEffWork *eff)
{
    int i;

    if (eff->overlayCount > 0) {
        while (eff->overlayCount > 0) {
            i = eff->overlayCount - 1;
            if (eff->overlayIds[i] != 0) {
                func_02034A5C(eff->overlayIds[i]);
            }
            eff->overlayCount--;
        }
    }
}

/*
 * Picks the effect kind (index into the effect table) and the battle BGM
 * for a battle against a wild or scripted opponent. Legendary species have
 * their own kinds; other battles depend on the tile the player stands on.
 */
void ENCEFF_SelectEffectAndBgm(int species, int effectId, int hasWildOpponent, struct FieldMap *fieldMap, u32 *outEffectKind, u16 *outBgmId)
{
    u32 attr;
    u16 tileType;
    u16 parentZoneId;
    u32 effectKind;
    u16 bgmId;

    parentZoneId = ZONEDATA_GetParentZoneId(FIELDMAP_GetZoneId(fieldMap));
    switch (species) {
    case 0x23B:
        *outBgmId = 0x469;
        *outEffectKind = 0x23;
        return;
    case 0x283:
        *outBgmId = 0x474;
        *outEffectKind = 0x20;
        return;
    case 0x284:
        *outBgmId = 0x475;
        *outEffectKind = 0x20;
        return;
    case 0x286:
        *outBgmId = 0x476;
        *outEffectKind = 0x20;
        return;
    case 0x27D:
        *outBgmId = 0x468;
        *outEffectKind = 0x1f;
        return;
    case 0x1EE:
        *outBgmId = 0x478;
        *outEffectKind = 0x1f;
        return;
    case 0x27E:
    case 0x27F:
    case 0x280:
    case 0x287:
        *outBgmId = 0x478;
        *outEffectKind = 0x22;
        return;
    case 0x281:
    case 0x282:
    case 0x285:
        *outBgmId = 0x477;
        *outEffectKind = 0x21;
        return;
    }
    if (effectId == 1) {
        *outBgmId = 0x469;
        *outEffectKind = 0x1f;
        return;
    }
    if (effectId == 4) {
        if (parentZoneId == 0xd6) {
            *outBgmId = 0x469;
        } else {
            *outBgmId = 0x468;
        }
        *outEffectKind = 2;
        return;
    }
    attr = FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer(fieldMap));
    tileType = MAP_ATTR_GetTerrainId(attr);
    if (MAP_ATTR_GetFlags(attr) & 2) {
        bgmId = 0x468;
        effectKind = 2;
    } else if (MAP_ATTR_IsAnyGrass(tileType)) {
        if (hasWildOpponent) {
            bgmId = 0x469;
            effectKind = 1;
        } else {
            bgmId = 0x468;
            effectKind = 0;
        }
    } else if (MAP_ATTR_IsSplashWaterB(tileType)) {
        bgmId = 0x468;
        effectKind = 0;
    } else {
        if (MAP_ATTR_IsSandVariant(tileType)) {
            bgmId = 0x468;
            effectKind = 4;
        } else {
            bgmId = 0x468;
            effectKind = 3;
        }
    }
    *outEffectKind = effectKind;
    if (parentZoneId == 0xd6) {
        *outBgmId = 0x469;
    } else {
        *outBgmId = bgmId;
    }
}

/*
 * Picks the effect kind and the battle BGM for a trainer battle: from the
 * trainer's two class groups when the first is below 11, otherwise from the
 * tile and the area the player stands in.
 */
void ENCEFF_SelectEffectAndBgmForTrainer(void *trainerData, struct FieldMap *fieldMap, int *outEffectKind, u16 *outBgmId)
{
    int areaIsInner = 1;
    u32 trainerClass = TPOKE_DATA_GetRecordField(trainerData, 1);
    u32 bgmGroup = TPOKE_DATA_GetTrainerKind(trainerClass);
    u32 effectGroup = TPOKE_DATA_FindTrainerType(trainerClass);
    int effectKind;

    if (bgmGroup < 0xb) {
        *outBgmId = d_021DB7E0[bgmGroup];
        *outEffectKind = d_021DB7F6[effectGroup];
        return;
    }
    {
        u32 attr = FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer(fieldMap));
        u32 tileType = MAP_ATTR_GetTerrainId(attr);

        if (MAP_ATTR_GetFlags(attr) & 2) {
            effectKind = 6;
        } else if (MAP_ATTR_IsSandVariant(tileType) != 0) {
            effectKind = 8;
        } else {
            if (ZONEDATA_GetAreaInnerOuter(FIELDMAP_GetAreaData(fieldMap)) == 0) {
                areaIsInner = 0;
            }
            effectKind = 5;
            if (areaIsInner == 0) {
                effectKind = 7;
            }
        }
    }
    *outBgmId = 0x46a;
    *outEffectKind = effectKind;
}

/*
 * Script command: starts the task that counts the original trainers of
 * the player's Pokemon other than the player, and stores the count in a
 * script variable when the task ends.
 */
int SCRCMD_StartCountOtherOtIdsTask(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    struct GameData *gameData = SCRCMD_WORK_GetGameData(cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    struct GameEvent *taskEvent;
    struct MyStatus *myStatus;
    OtCountTask *task;

    taskEvent = func_020122C0(gameSystem, 0, SCRCMD_CountOtherOtIdsTaskMain, 0xd8);
    myStatus = GAME_DATA_GetMyStatus(gameData);
    task = func_020124E8(taskEvent);
    task->playerId = func_02008530(myStatus);
    task->list.count = 0;
    task->nextBox = 0;
    task->result = resultVar;
    SCRIPT_SYS_CallEvent(scriptWork, taskEvent);
    return 1;
}

/*
 * Task body: scans the party, then two PC boxes per frame, then the battle
 * box. Ends when all are scanned or the list is full.
 */
int SCRCMD_CountOtherOtIdsTaskMain(struct GameEvent *event, int *seq, OtCountTask *task)
{
    OtIdList *list;
    int finished = 0;
    struct GameData *gameData;
    int i;

    gameData = GAMESYSTEM_GetGameData(GAME_EVENT_GetGameSystem(event));
    switch (*seq) {
    case 0:
        SCRCMD_CountPartyOtherOtIds(task->playerId, gameData, &task->list);
        (*seq)++;
        break;
    case 1: {
        int firstBox = task->nextBox;
        list = &task->list;
        for (i = finished; i < 2; i++) {
            SCRCMD_CountBoxOtherOtIds(task->playerId, gameData, firstBox + i, list);
            task->nextBox++;
            if (task->nextBox >= BOX_COUNT) {
                (*seq)++;
                break;
            }
        }
        break;
    }
    case 2:
        SCRCMD_CountBattleBoxOtherOtIds(task->playerId, gameData, finished, &task->list);
        finished = 1;
        break;
    }
    if (task->list.count >= OT_ID_LIST_MAX) {
        finished = 1;
    }
    if (finished) {
        *task->result = task->list.count;
        return 1;
    }
    return 0;
}

/* Adds the original trainers of the non-egg party Pokemon to the list. */
int SCRCMD_CountPartyOtherOtIds(u32 playerId, struct GameData *gameData, OtIdList *list)
{
    struct PokeParty *party = GAME_DATA_GetMyParty(gameData);
    int partyCount = POKEPARTY_GetCount(party);
    int added = 0;
    int i;

    for (i = 0; i < partyCount; i++) {
        struct PokemonParam *mon = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(mon, MON_DATA_IS_EGG, 0) == 0) {
            u32 otId = POKE_TOOL_GetPartyValue(mon, MON_DATA_OT_ID, 0);
            if (SCRCMD_AddOtherOtId(playerId, otId, list) != 0) {
                added++;
            }
        }
    }
    return added;
}

/* Adds the original trainers of the non-egg Pokemon of one PC box to the list. */
int SCRCMD_CountBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 box, OtIdList *list)
{
    struct BoxData *boxData = GAME_DATA_GetBoxManager(gameData);
    int added = 0;
    int i;

    for (i = 0; i < BOX_SLOT_COUNT; i++) {
        if (func_020079BC(boxData, box, i, MON_DATA_HAS_SPECIES, 0) != 0) {
            if (func_020079BC(boxData, box, i, MON_DATA_IS_EGG, 0) == 0) {
                u32 otId = func_020079BC(boxData, box, i, MON_DATA_OT_ID, 0);
                if (SCRCMD_AddOtherOtId(playerId, otId, list) != 0) {
                    added++;
                }
            }
        }
    }
    return added;
}

/* Adds the original trainers of one battle box team to the list. */
int SCRCMD_CountBattleBoxOtherOtIds(u32 playerId, struct GameData *gameData, u32 team, OtIdList *list)
{
    struct BattleBoxSave *battleBox;
    int i;
    int added;

    battleBox = BATTLE_BOX_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    added = 0;
    for (i = 0; i < BATTLE_BOX_SLOT_COUNT; i++) {
        struct PokemonParam *mon = BATTLE_BOX_GetMon(battleBox, team, i);
        if (func_02017E88(mon, MON_DATA_HAS_SPECIES, 0) != 0) {
            u32 otId = func_02017E88(mon, MON_DATA_OT_ID, 0);
            if (SCRCMD_AddOtherOtId(playerId, otId, list) != 0) {
                added++;
            }
        }
    }
    return added;
}

/* Adds an original trainer id to the list unless it is the player's own. */
int SCRCMD_AddOtherOtId(int playerId, int otId, OtIdList *list)
{
    int added = 0;

    if (playerId != otId) {
        added = SCRCMD_AddUniqueOtId(otId, list);
    }
    return added;
}

/* Adds an id to the list when it is not in there yet and the list has room. */
int SCRCMD_AddUniqueOtId(int otId, OtIdList *list)
{
    int i;

    if (list->count >= OT_ID_LIST_MAX) {
        return 0;
    }
    for (i = 0; i < list->count; i++) {
        if (otId == list->ids[i]) {
            return 0;
        }
    }
    list->ids[i] = otId;
    list->count++;
    return 1;
}

/*
 * Script command: starts the field sub process of overlay 57 with the map
 * function of the current field map. abs_id_39 is overlay id 57 (pool ABS32
 * 0x39); d_021F3900 is ov057 data.
 */
int SCRCMD_StartSubProcOv057(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldMap = GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(cmdWork));
    FIELD_SUBPROC_Start((int)abs_id_39, (int *)FIELDMAP_GetMapFunc(fieldMap), (const int *)d_021F3900);
    return 0;
}

/* Script command: stores a value of the saved player location in a script variable. */
int SCRCMD_GetPlayerLocationValue(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PlayerLocation *location;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    location = func_02008854(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork))));
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = func_02008990(location);
    return 0;
}

/*
 * Searches the offer slots for one that waits at this zone and tile (the
 * height may be off by one). Returns the slot index, or 0xff.
 */
int INTRUDE_FindOfferSlotAt(IntrudeOfferLog *log, int zoneId, int x, int y, int z)
{
    int i;
    IntrudeOfferSlot *slot = log->slot;

    for (i = 0; i < INTRUDE_OFFER_SLOT_COUNT; i++, slot++) {
        const IntrudeOfferSpot *spot;
        if (slot->offerId == 0) {
            return 0xff;
        }
        spot = &gIntrudeOfferTilePositions[slot->spotIndex];
        if (spot->zoneId == zoneId && spot->x == x && spot->z == z && spot->y - 1 <= y && y <= spot->y + 1) {
            return i;
        }
    }
    return 0xff;
}

/* Copies offer slot i out and shifts the later slots down by one. */
void INTRUDE_TakeOfferSlot(IntrudeOfferLog *log, int index, IntrudeOfferSlot *dest)
{
    *dest = log->slot[index];
    for (index++; index < INTRUDE_OFFER_SLOT_COUNT; index++) {
        log->slot[index - 1] = log->slot[index];
    }
    log->slot[INTRUDE_OFFER_SLOT_COUNT - 1].offerId = 0;
}

/* Walks the slots from *index to the next used one and returns its spot row. */
const IntrudeOfferSpot *INTRUDE_GetNextOfferSpot(IntrudeOfferLog *log, int *index)
{
    int i = *index;

    if (i < INTRUDE_OFFER_SLOT_COUNT) {
        do {
            if (log->slot[i].offerId != 0) {
                const IntrudeOfferSpot *spot = &gIntrudeOfferTilePositions[log->slot[i].spotIndex];
                (*index)++;
                return spot;
            }
            i = ++*index;
        } while (i < INTRUDE_OFFER_SLOT_COUNT);
    }
    return 0;
}

/*
 * Event task: starts the offer script with the offer id as parameter and
 * registers the sender's name in word 3.
 */
int INTRUDE_OfferEventMain(struct GameEvent *event, u32 seq, const IntrudeOfferSlot *offer)
{
    IntrudeOfferSlot copy = *offer;
    struct ScriptWork *scriptWork;
    struct WordSet *wordSet;
    struct Strbuf *name;

    scriptWork = SCRIPT_SYS_ChangeScriptEvent(event, 0x0AFC, 0, 0x15);
    SCRIPT_WORK_SetParams(scriptWork, copy.offerId, 0, 0, 0);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    name = STRBUF_Create(8, 0x15);
    STRBUF_SetStringN(name, (const u16 *)&copy, 8);
    func_0201EE0C(wordSet, 3, name, 1, 1, 2);
    STRBUF_Delete(name);
    return 0;
}

/* Takes offer slot slotIndex out of the log and starts the event task that shows it. */
struct GameEvent *INTRUDE_StartOfferEvent(struct GameSystem *gameSystem, u32 heapId, int slotIndex)
{
    struct GameEvent *taskEvent = func_020122C0(gameSystem, 0, INTRUDE_OfferEventMain, 0x14);
    IntrudeOfferSlot *offer = func_020124E8(taskEvent);

    INTRUDE_TakeOfferSlot(INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))), slotIndex, offer);
    return taskEvent;
}

/*
 * Fills the partner candidates in the save sync block for a language, or
 * clears them when the language is out of range.
 */
void SCRCMD_FillPartnerCandidates(struct GameSystem *gameSystem, int language, u32 mode)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    PartnerCandidates *candidates = GAME_DATA_GetSaveSyncBlock(gameData);

    if (language < 0xe9) {
        SCRCMD_CollectPartnersByLanguage(func_02009470(GAME_DATA_GetSaveControl(gameData)), candidates, language, mode);
        return;
    }
    func_0200E878(candidates);
}

/* Collects up to five Wi-Fi history partners of one language into out. */
void SCRCMD_CollectPartnersByLanguage(struct WifiHistory *history, PartnerCandidates *out, u32 language, u32 mode)
{
    int i;

    out->language = language;
    out->mode = mode;
    out->count = 0;
    for (i = 0; i < WIFI_HISTORY_ENTRY_COUNT; i++) {
        if ((u8)func_02009634(history, i, WIFI_HISTORY_FIELD_INFO) != 0) {
            struct HistoryEntry *entry = func_0200973C(history, i);
            u32 entryLanguage;
            if (entry != 0 && (entryLanguage = func_0200856C(entry), entryLanguage == language)) {
                u32 outfit = func_02008554(entry);
                if (outfit > 0xf) {
                    outfit = (func_02008550(entry) != 0) ? 0xf : 0xb;
                }
                out->historyIndex[out->count] = i;
                out->viewId[out->count] = CURSOR_MOVE_GetTableValue(outfit);
                out->count++;
                if (out->count >= PARTNER_CANDIDATE_MAX) {
                    break;
                }
            }
        }
    }
}

/* Returns the history index of candidate i, or 0xff. */
u8 SCRCMD_GetPartnerCandidateHistoryIndex(PartnerCandidates *candidates, u32 index)
{
    u8 historyIndex = 0xff;

    if (index < PARTNER_CANDIDATE_MAX && index < candidates->count) {
        historyIndex = candidates->historyIndex[index];
    }
    return historyIndex;
}

/*
 * Registers the words of candidate index and returns the index of the
 * greeting message for that partner (4 when the index is out of range).
 */
int SCRCMD_GetPartnerGreetingMessage(struct WordSet *wordSet, struct GameSystem *gameSystem, PartnerCandidates *candidates, int index, u32 variant)
{
    u32 outfitVariant, trainerId, tier, historyIndex;
    struct HistoryEntry *entry;
    struct WifiHistory *history;
    struct GameData *gameData;
    u32 isSpecialLanguage;

    isSpecialLanguage = 0;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    history = func_02009470(GAME_DATA_GetSaveControl(gameData));
    if (index >= PARTNER_CANDIDATE_MAX) {
        return 4;
    }
    historyIndex = candidates->historyIndex[index];
    SCRCMD_SetPartnerWords(wordSet, gameData, historyIndex);
    entry = func_0200973C(history, historyIndex);
    outfitVariant = func_02008550(entry);
    tier = func_02009634(history, historyIndex, 4);
    trainerId = func_02008530(entry);
    if (func_02025B64(GAME_DATA_GetSaveSyncBlock(gameData)->language)) {
        isSpecialLanguage = 1;
    }
    return SCRCMD_CalcPartnerGreetingIndex(outfitVariant, trainerId, tier, variant, isSpecialLanguage);
}

/* Computes the greeting message index from the partner's data. */
int SCRCMD_CalcPartnerGreetingIndex(int outfitVariant, u32 trainerId, u32 tier, int variant, int isSpecialLanguage)
{
    int index;

    if (isSpecialLanguage != 0) {
        index = 4;
    } else {
        index = 0x44;
    }
    if (tier < 5) {
        index += tier * 0xc;
    }
    if (outfitVariant != 0) {
        index += 6;
    }
    if (variant == 0) {
        index++; index += trainerId % 5;
    }
    return index;
}

/* Registers the words (names, numbers) of one Wi-Fi history partner in the word set. */
void SCRCMD_SetPartnerWords(struct WordSet *wordSet, struct GameData *gameData, u32 historyIndex)
{
    struct WifiHistory *history;
    struct HistoryEntry *entry;
    u32 value;
    u8 language;

    history = func_02009470(GAME_DATA_GetSaveControl(gameData));
    language = GAME_DATA_GetSaveSyncBlock(gameData)->language;
    entry = func_0200973C(history, historyIndex);
    func_0201F048(wordSet, 0, language);
    if (func_02025B64(language)) {
        WORDSET_DeleteMsgdataF094(wordSet, 1, language, func_02008570(entry));
    }
    func_0201F02C(wordSet, 3, GAME_DATA_GetMyStatus(gameData));
    WORDSET_Callback(wordSet, 5, func_02009634(history, historyIndex, 0));
    func_0201F198(wordSet, 6, func_02009628(history));
    func_0201F02C(wordSet, 7, entry);
    value = func_02009634(history, historyIndex, 3);
    if (value == 0) {
        value = 1;
    }
    func_0201EFA4(wordSet, 8, value, 3, 0, 1);
    WORDSET_Callback(wordSet, 9, func_02009634(history, historyIndex, 1));
    language = func_02009634(history, historyIndex, 2);
    func_0201F198(wordSet, 10, language);
}

/* Script command: stores the number of countries in the Wi-Fi history, looked up with the argument. */
int SCRCMD_GetWifiHistoryCountryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 arg;
    struct GameData *gameData;
    struct WifiHistory *history;
    struct GameSystem *gameSystem;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    arg = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    history = func_02009470(GAME_DATA_GetSaveControl(gameData));
    *resultVar = WIFI_HISTORY_GetDisplayCount(history, GAME_DATA_GetMyStatus(gameData), arg);
    return 0;
}

/* Script command: stores the number of entries of the Wi-Fi history. */
int SCRCMD_GetWifiHistoryEntryCount(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = WIFI_HISTORY_GetFirstFreeEntry(func_02009470(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))));
    return 0;
}

/* Script command: marks the Wi-Fi history entry of partner candidate n. */
int SCRCMD_MarkPartnerCandidate(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    PartnerCandidates *candidates;
    u32 historyIndex;
    u8 candidateIndex;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    candidates = GAME_DATA_GetSaveSyncBlock(gameData);
    candidateIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    historyIndex = SCRCMD_GetPartnerCandidateHistoryIndex(candidates, candidateIndex);
    if (historyIndex != 0xff) {
        func_02009698(func_02009470(GAME_DATA_GetSaveControl(gameData)), historyIndex, WIFI_HISTORY_FIELD_MARKED, 1);
    }
    return 0;
}

/* Script command: stores 1 when the history entry of partner candidate n is marked. */
int SCRCMD_IsPartnerCandidateMarked(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    PartnerCandidates *candidates;
    u32 candidateIndex, historyIndex;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork));
    candidates = GAME_DATA_GetSaveSyncBlock(gameData);
    candidateIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = 0;
    historyIndex = SCRCMD_GetPartnerCandidateHistoryIndex(candidates, candidateIndex);
    if (historyIndex != 0xff) {
        if ((u8)func_02009634(func_02009470(GAME_DATA_GetSaveControl(gameData)), historyIndex, WIFI_HISTORY_FIELD_MARKED)) {
            *resultVar = 1;
        }
    }
    return 0;
}

/* Script command: sets the rating level of the Wi-Fi history. */
int SCRCMD_SetWifiHistoryRatingLevel(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 ratingLevel;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ratingLevel = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WIFI_HISTORY_SetRatingLevel(func_02009470(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))), ratingLevel);
    return 0;
}

/* Script command: sets the greeting set of the Wi-Fi history. */
int SCRCMD_SetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 greetingSet;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    greetingSet = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    WIFI_HISTORY_SetGreetingSet(func_02009470(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))), greetingSet);
    return 0;
}

/* Script command: stores the greeting set of the Wi-Fi history. */
int SCRCMD_GetWifiHistoryGreetingSet(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = func_02009628(func_02009470(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))));
    return 0;
}

/* Script command: fills the partner candidates for a language and mode read from the script. */
int SCRCMD_FillPartnerCandidatesFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRCMD_FillPartnerCandidates(SCRCMD_WORK_GetGameSystem(cmdWork), SCRIPT_WORK_ReadWorkValue(vm, cmdWork), SCRIPT_WORK_ReadWorkValue(vm, cmdWork));
    return 0;
}

/* Script command: stores the greeting message index for partner candidate n. */
int SCRCMD_GetPartnerGreetingMessageFromScript(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct WordSet *wordSet;
    PartnerCandidates *candidates;
    u32 candidateIndex, variant;
    u16 *resultVar;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    candidates = GAME_DATA_GetSaveSyncBlock(GAMESYSTEM_GetGameData(gameSystem));
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    candidateIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    variant = VM_GetU16(vm);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    *resultVar = SCRCMD_GetPartnerGreetingMessage(wordSet, gameSystem, candidates, candidateIndex, variant);
    return 0;
}

/* Script command: stores 1 when the player's language value is set. */
int SCRCMD_HasPlayerLanguage(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = func_0200856C(GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(cmdWork)))) != 0 ? 1 : 0;
    return 0;
}
