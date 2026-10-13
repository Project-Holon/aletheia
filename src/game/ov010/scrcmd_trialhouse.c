/*
 * file:     scrcmd_trialhouse.c
 * unit:     yes
 * function: func_0216A298, func_0216A2EC, func_0216A358, func_0216A390, func_0216A3F8, func_0216A420, func_0216A440, func_0216A470, func_0216A4CC, func_0216A510, func_0216A560, func_0216A594, func_0216A5C4, func_0216A5FC, func_0216A634, func_0216A674, func_0216A6B4, func_0216A6EC, func_0216A72C, func_0216A774, func_0216A7A0, func_0216A838, func_0216A884, func_0216A8F0, func_0216AAE4, func_0216ABD8, func_0216AC40, func_0216AC90, func_0216ACCC, func_0216AD1C, func_0216AD70, func_0216AE10, func_0216AED0, func_0216AEE8, func_0216AF1C, func_0216AF3C, func_0216AF74, func_0216B004
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
 *   func_020307B0  0x020307B0  arm
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02012944 0x02012944 thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_0216DE94  0x0216DE94  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_020173EC  0x020173EC  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012444 0x02012444 thumb
 *   func_02017988  0x02017988  thumb
 *   func_02011400  0x02011400  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetListCursor  0x02012F50  thumb
 *   func_021D096C  0x021D096C  thumb
 *   func_021D0A48   0x021D0A48  thumb
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0A74  0x021D0A74  thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_021D0AC0  0x021D0AC0  thumb  ov021
 *   func_021D0BD8  0x021D0BD8  thumb  ov021
 *   func_021D0AB8  0x021D0AB8  thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008E68 0x02008E68 thumb
 *   func_02008E78  0x02008E78  thumb
 *   func_021D0BE4  0x021D0BE4  thumb  ov021
 *   func_021D0DB0  0x021D0DB0  thumb  ov021
 *   func_021D0FE0  0x021D0FE0  thumb
 *   func_021D0FE8  0x021D0FE8  thumb  ov021
 *   func_021D1028  0x021D1028  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021664CC  0x021664CC  thumb  ov010
 *   func_0217C37C  0x0217C37C  thumb  ov018
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0217C294  0x0217C294  thumb  ov018
 *   func_0200E18C  0x0200E18C  thumb
 *   func_0216628C  0x0216628C  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_0201EE84  0x0201EE84  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   func_02012FB0  0x02012FB0  thumb
 *   func_02166618  0x02166618  thumb  ov010
 *   func_0216662C  0x0216662C  thumb  ov010
 *   INTRUDE_COMM_GetMarkerPosForPartner  0x021767F0  thumb  ov011
 *   func_02184D38  0x02184D38  thumb  ov020
 *   func_021665F0  0x021665F0  thumb  ov010
 *   func_0216B3A8  0x0216B3A8  thumb  ov010
 *   func_0215901C 0x0215901C thumb ov010
 *   func_0217C274 0x0217C274 thumb ov018
 *   func_0217C2A0   0x0217C2A0  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   INTRUDE_COMM_SetPendingValue  0x0217688C  thumb  ov011
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_0200E2BC  0x0200E2BC  thumb
 *   func_020124E4  0x020124E4  thumb
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_0200873C  0x0200873C  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   func_02189A08  0x02189A08  thumb  ov021
 *   func_021CF498  0x021CF498  thumb  ov021
 *   func_021B6100  0x021B6100  thumb  ov098
 *   func_021B6158  0x021B6158  thumb  ov098
 *   func_021B95A0  0x021B95A0  thumb  ov227
 *   func_021B95C8  0x021B95C8  thumb  ov227
 *   ov098_id       0x00000062  data
 *   ov227_id       0x000000E3  data
 *   d_021B6D74     0x021B6D74  data ov098
 *   d_021B98A4     0x021B98A4  data ov227
 *   func_02168BF0  0x02168BF0  thumb  ov010
 *   func_02168CF4  0x02168CF4  thumb  ov010
 *   func_02168E5C  0x02168E5C  thumb  ov010
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
extern struct GameSystem *func_0215A5DC(ScrcmdWork *cmdWork);
extern ScriptWork *func_0215A5F4(ScrcmdWork *cmdWork);
extern struct GameData *func_0215A5E4(ScrcmdWork *cmdWork);
extern u16 func_0215A5CC(ScrcmdWork *cmdWork);
extern u32 func_02159B10(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 *func_02159AE8(ScriptVm *vm, ScrcmdWork *cmdWork);
extern void func_0215897C(ScriptWork *scriptWork, struct GameEvent *event);
extern u32 func_0215901C(ScriptWork *scriptWork, struct GameData *gameData, u32 workId);
extern struct WordSet *func_02158F74(ScriptWork *scriptWork);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern TrialHouseWork **GAME_DATA_GetListCursor(struct GameData *gameData);
extern int func_02012FB0(struct GameData *gameData);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern struct MyItem *func_0201292C(struct GameData *gameData);
extern struct Config *func_0200873C(struct SaveControl *saveControl);
extern struct PokedexSave *func_0200CA10(struct SaveControl *saveControl);
extern struct PokedexSave *func_0200CA1C(struct GameData *gameData);
extern void func_0200CFA0(struct PokedexSave *pokedex, struct PokemonParam *mon);

/* Game events. */
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern void func_02012444(struct GameEvent *parent, u32 overlayId, void *procData, void *param);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(struct GameSystem *gameSystem, u32 bgmId);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(struct GameSystem *gameSystem);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);

/* Party and Pokemon. */
extern u32 func_0201AA18(struct Party *party);
extern struct PokemonParam *func_0201AB28(struct Party *party, u32 index);
extern u32 func_02017E1C(struct PokemonParam *mon, u32 paramId, void *buffer);
extern void func_02017988(struct PokemonParam *mon, u16 form);
extern u32 func_020173EC(void);
extern u8 func_02011400(int season, int timeZone);
extern u16 func_0203F1FC(const void *src, u32 len);
extern void func_0201EE84(struct WordSet *wordSet, u32 index, struct PokemonParam *mon);
extern void func_02082BCC(void *dst, int value, int size);
extern void func_020307B0(void *block);

/* Field models and the field map. */
extern struct MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern void func_021A3038(struct FieldPlayer *player, VecFx32 *outPos);
extern void func_021AA304(SceneInfo *out, struct GameData *gameData, struct FieldMap *fieldMap);
extern void *func_02189A08(struct FieldMap *fieldMap);
extern void func_021CF498(void *proc, struct GameEvent *event, int mode);
extern struct Mmdl *func_0216DE94(struct MmdlSys *mmdlSys, u32 objId);
extern void func_0216D88C(struct Mmdl *mmdl, VecFx32 *outPos);
extern void func_0216D89C(struct Mmdl *mmdl, VecFx32 *pos);
extern void func_0216D568(struct Mmdl *mmdl, u32 bits);
extern void *func_02184D38(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effectId, VecFx32 *pos, u16 flag, int param);

/* Trial house (ov021 trial_house.c and ov010 fld_btl_inst_tool.c). */
extern TrialHouseWork *func_021D096C(struct GameSystem *gameSystem);
extern void func_021D0A48(struct GameSystem *gameSystem, TrialHouseWork **slot);
extern void func_021D0A74(TrialHouseWork *work, u32 mode);
extern void func_021D0AB8(TrialHouseWork *work, int value);
extern u16 func_021D0AC0(struct GameSystem *gameSystem, TrialHouseWork *work, int index);
extern struct GameEvent *func_021D0BD8(struct GameSystem *gameSystem, TrialHouseWork *work, u32 index, u32 mmdlId);
extern struct GameEvent *func_021D0BE4(struct GameSystem *gameSystem, TrialHouseWork *work, u16 *outValue);
extern void func_021D0DB0(struct GameSystem *gameSystem, TrialHouseWork *work, u16 *outRank, u16 *outScore);
extern int func_021D0FE0(struct GameSystem *gameSystem, TrialHouseWork *work);
extern struct GameEvent *func_021D0FE8(struct GameSystem *gameSystem, TrialHouseWork *work, int param);
extern int func_021D1028(struct GameSystem *gameSystem);
extern struct RecordBlock *func_02008C58(struct SaveControl *saveControl);
extern void func_02008E68(struct RecordBlock *record, u8 rank);
extern u8 func_02008E78(struct RecordBlock *record);
extern struct GameEvent *func_02168BF0(struct GameSystem *gameSystem, TrialHouseWork *work, int regulationId, int useTempParty, u16 *resultOk);
extern struct GameEvent *func_02168CF4(struct GameSystem *gameSystem, TrialHouseWork *work);
extern struct GameEvent *func_02168E5C(struct GameSystem *gameSystem, int arg0, int arg1);

/* Symbol map save and link records. */
extern struct SymbolSave *func_0200E0B0(struct SaveControl *saveControl);
extern void func_0200E18C(struct SymbolSave *save, u32 index);
extern u32 func_0200E2BC(struct SaveControl *saveControl, SymbolKey *key, u32 heapId, u32 matchMode);
extern SymbolMapLinkRecord *func_021664CC(u16 heapId, struct GameSystem *gameSystem, u32 *outStart);
extern int func_0216628C(struct SymbolSave *save, u32 index);
extern int func_02166618(int symbolMapFlag);
extern int func_0216662C(int symbolMapFlag);
extern int func_021665F0(struct GameSystem *gameSystem, int cellId, int direction);
extern struct GameEvent *func_0216B3A8(struct GameSystem *gameSystem, int direction, int cell);
extern void func_0217C274(SymbolKey *outKey, struct Mmdl *mmdl);
extern int func_0217C294(struct Mmdl *mmdl);
extern struct PokemonParam *func_0217C2A0(int heapId, struct GameData *gameData, SymbolKey *key);
extern void func_0217C37C(struct FieldMap *fieldMap, u32 start, SymbolMapLinkRecord *record, int count, int page);
extern struct IntrudeCommSys *func_02158344(struct GameComm *comm);
extern void INTRUDE_COMM_SetPendingValue(struct IntrudeCommSys *linkState, int value);
extern int INTRUDE_COMM_GetPartnerSlot(struct GameComm *comm, struct GameData *gameData);
extern void INTRUDE_COMM_GetMarkerPosForPartner(struct GameComm *comm, struct GameData *gameData, VecFx32 *outPos);

/* Overlay screens of the symbol Pokemon viewing event. */
extern void *func_021B6100(struct GameData *gameData, struct PokemonParam *mon, SceneInfo *scene, struct MyStatus *myStatus,
                           struct MyItem *myItem, struct Config *config, struct PokedexSave *pokedex, u16 heapId);
extern int func_021B6158(void *screen);
extern void *func_021B95A0(struct GameData *gameData, int accepted, struct PokemonParam *mon, u16 heapId);
extern void func_021B95C8(void *screen);
extern u32 func_02007E50(struct MyItem *myItem, u16 itemId, u16 quantity, u16 heapId);
extern u32 func_02007F1C(struct MyItem *myItem, u16 itemId, u16 quantity, u16 heapId);
extern int func_02034AC4(u32 overlayId);
extern void func_02034A5C(u32 overlayId);
extern const s16 FX_SinCosTable_[];
extern u8 ov098_id[];
extern u8 ov227_id[];
extern u8 d_021B6D74[];
extern u8 d_021B98A4[];

void func_0216A298(struct GameData *gameData, struct Party *party);
int func_0216A2EC(struct GameData *gameData, struct Party *party, int elapsedMinutes, TimeOfDay *time, int season);
int func_0216A358(struct GameData *gameData, struct Party *party, u32 *hour, int season);
void func_0216A390(struct GameData *gameData, struct Party *party);
int func_0216A3F8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A420(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A440(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A470(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A4CC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A510(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A560(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A594(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A5C4(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A5FC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A634(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A674(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A6B4(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A6EC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A72C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A774(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A7A0(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A838(struct GameEvent *event, u32 *state, void *work);
int func_0216A884(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216A8F0(struct GameEvent *event, u32 *mode, void *work);
void func_0216AAE4(struct GameData *gameData, struct Party *party, int season);
int func_0216ABD8(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216AC40(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216AC90(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216ACCC(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216AD1C(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216AD70(ScriptVm *vm, ScrcmdWork *cmdWork);
int func_0216AE10(ScriptVm *vm, ScrcmdWork *cmdWork);
struct Mmdl *func_0216AED0(ScrcmdWork *cmdWork, u32 objId);
void func_0216AEE8(ScrcmdWork *cmdWork, SymbolKey *outKey);
struct PokemonParam *func_0216AF1C(ScrcmdWork *cmdWork, struct Mmdl *mmdl, int heapId, SymbolKey *outKey);
void func_0216AF3C(ScrcmdWork *cmdWork);
struct GameEvent *func_0216AF74(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct PokemonParam *mon, SymbolKey key,
                                u16 *resultOut, u16 heapId);
int func_0216B004(struct GameEvent *event, u32 *state, void *work);

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

/* Table columns of func_02011400: first hour of the day and first hour of the night. */
#define TIME_ZONE_DAY_START 0
#define TIME_ZONE_NIGHT_START 3

/* Shaymin sky forme back to land forme for every Shaymin in the party. */
void func_0216A298(struct GameData *gameData, struct Party *party)
{
    int i;
    int count;
    struct PokemonParam *mon;
    int species;
    int form;

    count = func_0201AA18(party);
    for (i = 0; i < count; i++) {
        mon = func_0201AB28(party, i);
        species = func_02017E1C(mon, PARAM_SPECIES, 0);
        form = func_02017E1C(mon, PARAM_FORM, 0);
        if (species == SPECIES_SHAYMIN && form == SHAYMIN_FORM_SKY)
            func_02017988(mon, SHAYMIN_FORM_LAND);
    }
}

/*
 * Reverts Shaymin when more time has passed than the current time of day has
 * lasted so far (elapsedMinutes against the minutes since the day or night began).
 * Returns 1 when the party was changed.
 */
int func_0216A2EC(struct GameData *gameData, struct Party *party, int elapsedMinutes, TimeOfDay *time, int season)
{
    int nightStart;
    int dayStart;
    int hour;
    int hoursSince;

    nightStart = func_02011400(season, TIME_ZONE_NIGHT_START);
    dayStart = func_02011400(season, TIME_ZONE_DAY_START);
    hour = time->hour;
    if (!((u32)hour < (u32)nightStart && (u32)hour >= (u32)dayStart)) {
        hoursSince = hour;
        if (hoursSince < dayStart) {
            hoursSince += 24;
        }
        hoursSince = hoursSince - nightStart;
        if (time->minute + hoursSince * 60 < elapsedMinutes + 1) {
            func_0216A298(gameData, party);
            return 1;
        }
        return 0;
    }
    hoursSince = hour - dayStart;
    if (time->minute + hoursSince * 60 < elapsedMinutes) {
        func_0216A298(gameData, party);
        return 1;
    }
    return 0;
}

/* At night: reverts Shaymin and records the form change. Returns 1 at night. */
int func_0216A358(struct GameData *gameData, struct Party *party, u32 *hour, int season)
{
    u32 nightStart;
    u32 dayStart;
    int result;

    nightStart = func_02011400(season, TIME_ZONE_NIGHT_START);
    dayStart = func_02011400(season, TIME_ZONE_DAY_START);
    result = 0;
    if (!(*hour < nightStart && *hour >= dayStart)) {
        func_0216A390(gameData, party);
        result = 1;
    }
    return result;
}

/* Reverts every sky forme Shaymin, registering the first one in the Pokedex. */
void func_0216A390(struct GameData *gameData, struct Party *party)
{
    int registered;
    int count;
    struct PokedexSave *pokedex;
    int i;
    struct PokemonParam *mon;
    int species;
    int form;

    pokedex = func_0200CA1C(gameData);
    registered = 0;
    count = func_0201AA18(party);
    for (i = 0; i < count; i++) {
        mon = func_0201AB28(party, i);
        species = func_02017E1C(mon, PARAM_SPECIES, 0);
        form = func_02017E1C(mon, PARAM_FORM, 0);
        if (species == SPECIES_SHAYMIN && form == SHAYMIN_FORM_SKY) {
            func_02017988(mon, SHAYMIN_FORM_LAND);
            if (registered == 0) {
                func_0200CFA0(pokedex, mon);
                registered = 1;
            }
        }
    }
}

/* Trial house script command: creates the trial house work once. */
int func_0216A3F8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    TrialHouseWork **slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));

    if (*slot == 0) {
        *slot = func_021D096C(gameSystem);
    }
    return 0;
}

/* Trial house script command: frees the trial house work. */
int func_0216A420(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);

    func_021D0A48(gameSystem, GAME_DATA_GetListCursor(func_020120F4(gameSystem)));
    return 0;
}

/* Trial house script command: sets the battle mode (party size) from a script value. */
int func_0216A440(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u32 mode;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    mode = func_02159B10(vm, cmdWork);
    func_021D0A74(*slot, mode);
    return 0;
}

int func_0216A470(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int regulationId;
    int useTempParty;
    u16 *resultOk;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    regulationId = func_02159B10(vm, cmdWork);
    useTempParty = func_02159B10(vm, cmdWork);
    resultOk = func_02159AE8(vm, cmdWork);
    func_0215897C(scriptWork, func_02168BF0(gameSystem, *slot, regulationId, useTempParty, resultOk));
    return 1;
}

int func_0216A4CC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int index;
    u16 *outValue;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    index = func_02159B10(vm, cmdWork);
    outValue = func_02159AE8(vm, cmdWork);
    *outValue = func_021D0AC0(gameSystem, *slot, index);
    return 0;
}

int func_0216A510(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    int index;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    index = func_02159B10(vm, cmdWork);
    func_0215897C(scriptWork, func_021D0BD8(gameSystem, *slot, index, func_02159B10(vm, cmdWork)));
    return 1;
}

int func_0216A560(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    func_0215897C(scriptWork, func_02168CF4(gameSystem, *slot));
    return 1;
}

int func_0216A594(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    func_021D0AB8(*slot, func_02159B10(vm, cmdWork));
    return 0;
}

/* Trial house script command: sets the trial house rank byte of the save from a script value. */
int func_0216A5C4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    u32 rank;

    func_0215A5F4(cmdWork);
    gameData = func_020120F4(func_0215A5DC(cmdWork));
    rank = func_02159B10(vm, cmdWork);
    func_02008E68(func_02008C58(func_02012EBC(gameData)), rank);
    return 0;
}

/* Trial house script command: stores the trial house rank byte of the save in a script work. */
int func_0216A5FC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u16 *outRank;
    struct SaveControl *saveControl;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    outRank = func_02159AE8(vm, cmdWork);
    saveControl = func_02012EBC(gameData);
    *outRank = func_02008E78(func_02008C58(saveControl));
    return 0;
}

int func_0216A634(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    func_0215897C(scriptWork, func_021D0BE4(gameSystem, *slot, func_02159AE8(vm, cmdWork)));
    return 1;
}

int func_0216A674(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u16 *outRank;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    outRank = func_02159AE8(vm, cmdWork);
    func_021D0DB0(gameSystem, *slot, outRank, func_02159AE8(vm, cmdWork));
    return 0;
}

int func_0216A6B4(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;
    u16 *outValue;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    outValue = func_02159AE8(vm, cmdWork);
    *outValue = func_021D0FE0(gameSystem, *slot);
    return 0;
}

int func_0216A6EC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    TrialHouseWork **slot;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    slot = GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    func_0215897C(scriptWork, func_021D0FE8(gameSystem, *slot, func_02159B10(vm, cmdWork)));
    return 1;
}

int func_0216A72C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int arg0;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    GAME_DATA_GetListCursor(func_020120F4(gameSystem));
    arg0 = func_02159B10(vm, cmdWork);
    func_0215897C(scriptWork, func_02168E5C(gameSystem, arg0, func_02159B10(vm, cmdWork)));
    return 1;
}

int func_0216A774(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *outValue;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    outValue = func_02159AE8(vm, cmdWork);
    *outValue = func_021D1028(gameSystem);
    return 0;
}

/* Script command: raises a field model to a height over a number of frames. */
int func_0216A7A0(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int objId;
    int height;
    int frames;
    struct GameEvent *event;
    MmdlRiseWork *work;
    struct Mmdl *mmdl;

    func_0215A5E4(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    objId = func_02159B10(vm, cmdWork);
    height = func_02159B10(vm, cmdWork);
    frames = func_02159B10(vm, cmdWork);
    event = func_020122C0(gameSystem, 0, func_0216A838, sizeof(MmdlRiseWork));
    work = func_020124E8(event);
    work->frames = frames;
    work->frame = 0;
    mmdl = func_0216DE94(func_02188C7C(func_0201210C(gameSystem)), objId);
    func_0216D88C(mmdl, &work->startPos);
    work->mmdl = mmdl;
    func_0216D568(mmdl, MMDL_MOVE_BIT_RISE);
    work->totalRise = (height << 15) - work->startPos.y;
    func_0215897C(scriptWork, event);
    return 1;
}

int func_0216A838(struct GameEvent *event, u32 *state, void *work)
{
    MmdlRiseWork *rise = work;
    VecFx32 pos;

    rise->frame = rise->frame + 1;
    pos = rise->startPos;
    pos.y += (rise->totalRise * rise->frame) / rise->frames;
    func_0216D89C(rise->mmdl, &pos);
    if (rise->frame >= rise->frames) {
        return 1;
    }
    return 0;
}

/* Script command: moves a field model in a spiral and circle around its position. */
int func_0216A884(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    int objId;
    struct GameEvent *event;
    struct Mmdl *mmdl;
    MmdlOrbitWork *work;

    func_0215A5E4(cmdWork);
    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    objId = func_02159B10(vm, cmdWork);
    event = func_020122C0(gameSystem, 0, func_0216A8F0, sizeof(MmdlOrbitWork));
    work = func_020124E8(event);
    work->frame = 0;
    mmdl = func_0216DE94(func_02188C7C(func_0201210C(gameSystem)), objId);
    func_0216D88C(mmdl, &work->centerPos);
    work->mmdl = mmdl;
    func_0215897C(scriptWork, event);
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
int func_0216A8F0(struct GameEvent *event, u32 *mode, void *work)
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
        func_0216D89C(orbit->mmdl, &pos);
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
        func_0216D89C(orbit->mmdl, &pos);
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
        func_0216D89C(orbit->mmdl, &pos);
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
void func_0216AAE4(struct GameData *gameData, struct Party *party, int season)
{
    struct PokedexSave *pokedex;
    int i;
    int count;
    int deerlingForm;
    int sawsbuckForm;
    int deerlingRegistered;
    int sawsbuckRegistered;

    pokedex = func_0200CA1C(gameData);
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

    count = func_0201AA18(party);
    for (i = 0; i < count; i++) {
        struct PokemonParam *mon = func_0201AB28(party, i);
        int species = func_02017E1C(mon, PARAM_SPECIES, 0);
        int form = func_02017E1C(mon, PARAM_FORM, 0);

        if (species == SPECIES_DEERLING && form != deerlingForm) {
            func_02017988(mon, deerlingForm);
            if (!deerlingRegistered) {
                func_0200CFA0(pokedex, mon);
                deerlingRegistered = 1;
            }
        } else if (species == SPECIES_SAWSBUCK && form != sawsbuckForm) {
            func_02017988(mon, sawsbuckForm);
            if (!sawsbuckRegistered) {
                func_0200CFA0(pokedex, mon);
                sawsbuckRegistered = 1;
            }
        }
    }
}

/* Symbol script command: starts the symbol Pokemon viewing event for a field model. */
int func_0216ABD8(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    SymbolKey key;
    int objId;
    u16 *resultOut;
    struct Mmdl *mmdl;
    struct PokemonParam *mon;

    objId = func_02159B10(vm, cmdWork);
    resultOut = func_02159AE8(vm, cmdWork);
    mmdl = func_0216AED0(cmdWork, objId);
    if (mmdl != 0) {
        mon = func_0216AF1C(cmdWork, mmdl, SYMBOL_VIEW_HEAP_ID, &key);
        if (mon != 0) {
            ScriptWork *scriptWork = func_0215A5F4(cmdWork);
            struct GameSystem *gameSystem = func_0215A5DC(cmdWork);

            func_0215897C(scriptWork, func_0216AF74(gameSystem, func_0201210C(gameSystem), mon, key, resultOut, SYMBOL_VIEW_HEAP_ID));
        }
    }
    return 1;
}

/* Symbol script command: builds the link record and hands its entries to the field map. */
int func_0216AC40(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    SymbolMapLinkRecord *record;
    u32 start;

    gameSystem = func_0215A5DC(cmdWork);
    fieldMap = func_0201210C(gameSystem);
    func_02012138(gameSystem);
    record = func_021664CC(func_0215A5CC(cmdWork), gameSystem, &start);
    if (record != 0) {
        func_0217C37C(fieldMap, start, record, record->entryCount, record->page);
        func_020307B0(record);
    }
    return 0;
}

/* Symbol script command: moves a field model's symbol entry to the symbol save index of its key. */
int func_0216AC90(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    struct SymbolSave *symbolSave;
    struct Mmdl *mmdl;

    objId = func_02159B10(vm, cmdWork);
    symbolSave = func_0200E0B0(func_02012EBC(func_0215A5E4(cmdWork)));
    mmdl = func_0216AED0(cmdWork, objId);
    if (mmdl != 0) {
        func_0200E18C(symbolSave, func_0217C294(mmdl));
        func_0216AF3C(cmdWork);
    }
    return 0;
}

/* Symbol script command: moves a field model's symbol record to the paired band, storing the result. */
int func_0216ACCC(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int objId;
    u16 *result;
    struct SymbolSave *symbolSave;
    struct Mmdl *mmdl;

    objId = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    symbolSave = func_0200E0B0(func_02012EBC(func_0215A5E4(cmdWork)));
    mmdl = func_0216AED0(cmdWork, objId);
    if (mmdl != 0) {
        *result = func_0216628C(symbolSave, func_0217C294(mmdl));
        func_0216AF3C(cmdWork);
    } else {
        *result = 0;
    }
    return 0;
}

/* Symbol script command: registers the symbol Pokemon of a field model in a word set slot. */
int func_0216AD1C(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    SymbolKey key;
    int objId;
    int wordSetIndex;
    struct Mmdl *mmdl;
    struct PokemonParam *mon;

    objId = func_02159B10(vm, cmdWork);
    wordSetIndex = func_02159B10(vm, cmdWork);
    mmdl = func_0216AED0(cmdWork, objId);
    if (mmdl != 0) {
        mon = func_0216AF1C(cmdWork, mmdl, func_0215A5CC(cmdWork), &key);
        if (mon != 0) {
            func_0201EE84(func_02158F74(func_0215A5F4(cmdWork)), wordSetIndex, mon);
            func_020307B0(mon);
        }
    }
    return 0;
}

/*
 * Symbol script command: reads one property of the symbol map state into a script work.
 * Queries: 0 own link record is the local one, 1 selection is the home cell, 2 selection is
 * a blank cell, 3 species and 4 form of the target object symbol Pokemon.
 */
int func_0216AD70(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    int query;
    u16 *result;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct GameComm *comm;
    SymbolKey speciesKey;
    SymbolKey formKey;

    query = func_02159B10(vm, cmdWork);
    result = func_02159AE8(vm, cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    func_0200E0B0(func_02012EBC(gameData));
    comm = func_02012138(gameSystem);
    switch (query) {
    case 0:
        if (INTRUDE_COMM_GetPartnerSlot(comm, gameData) == 4)
            *result = 1;
        else
            *result = 0;
        break;
    case 1:
        *result = func_02166618(func_02012FB0(gameData));
        break;
    case 2:
        *result = func_0216662C(func_02012FB0(gameData));
        break;
    case 3:
        func_0216AEE8(cmdWork, &speciesKey);
        *result = speciesKey.species;
        break;
    case 4:
        func_0216AEE8(cmdWork, &formKey);
        *result = formKey.form;
        break;
    }
    return 0;
}

/* Symbol script command: starts the symbol map entry event (marker or cell entry). */
int func_0216AE10(ScriptVm *vm, ScrcmdWork *cmdWork)
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

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    direction = func_02159B10(vm, cmdWork);
    cell = func_02012FB0(gameData);
    if (direction == 1 && func_0216662C(cell) != 0) {
        fieldMap = func_0201210C(gameSystem);
        player = func_02188CB4(fieldMap);
        comm = func_02012138(gameSystem);
        func_021A3038(player, &playerPos);
        INTRUDE_COMM_GetMarkerPosForPartner(comm, gameData, &markerPos);
        markerPos.x = markerPos.x + (playerPos.x - SYMBOL_MARKER_OFFSET_X);
        event = func_02184D38(gameSystem, fieldMap, SYMBOL_MARKER_EFFECT_ID, &markerPos, 1, 0);
    } else {
        if (direction != 9)
            cell = func_021665F0(gameSystem, func_02012FB0(gameData), direction);
        event = func_0216B3A8(gameSystem, direction, cell);
    }
    func_0215897C(scriptWork, event);
    return 1;
}

/* Finds the field model whose object id is the given one. */
struct Mmdl *func_0216AED0(ScrcmdWork *cmdWork, u32 objId)
{
    return func_0216DE94(func_02188C7C(func_0201210C(func_0215A5DC(cmdWork))), objId);
}

/* Key of the field model that work 0x8011 names. */
void func_0216AEE8(ScrcmdWork *cmdWork, SymbolKey *outKey)
{
    ScriptWork *scriptWork;

    scriptWork = func_0215A5F4(cmdWork);
    func_0217C274(outKey, func_0216AED0(cmdWork, func_0215901C(scriptWork, func_0215A5E4(cmdWork), SCRIPT_WORK_TARGET_OBJ_ID)));
}

/*
 * The heap id is not used: the allocation below always takes heap 4.
 */
struct PokemonParam *func_0216AF1C(ScrcmdWork *cmdWork, struct Mmdl *mmdl, int heapId, SymbolKey *outKey)
{
    struct GameData *gameData = func_0215A5E4(cmdWork);

    func_0217C274(outKey, mmdl);
    return func_0217C2A0(SYMBOL_VIEW_HEAP_ID, gameData, outKey);
}

void func_0216AF3C(ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    struct IntrudeCommSys *linkState;

    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    saveControl = func_02012EBC(gameData);
    func_0200E0B0(saveControl);
    linkState = func_02158344(func_02012138(gameSystem));
    if (linkState != 0) {
        INTRUDE_COMM_SetPendingValue(linkState, func_02012FB0(gameData));
    }
}

/* Creates the symbol Pokemon viewing event. */
struct GameEvent *func_0216AF74(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct PokemonParam *mon, SymbolKey key,
                                u16 *resultOut, u16 heapId)
{
    struct GameData *gameData;
    struct GameEvent *event;
    SymbolViewWork *work;

    gameData = func_020120F4(gameSystem);
    event = func_020122C0(gameSystem, 0, func_0216B004, sizeof(SymbolViewWork));
    work = func_020124E8(event);
    func_02082BCC(work, 0, sizeof(SymbolViewWork));
    work->fieldMap = fieldMap;
    work->resultOut = resultOut;
    work->heapId = heapId;
    work->mon = mon;
    work->key = key;
    work->crc = func_0203F1FC(mon, func_020173EC());
    if (func_0200E2BC(func_02012EBC(gameData), &key, heapId, 0) == 0)
        work->key.species = SYMBOL_UNSEEN_SPECIES;
    func_021AA304(&work->scene, gameData, fieldMap);
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
int func_0216B004(struct GameEvent *event, u32 *state, void *procWork)
{
    SymbolViewWork *work = procWork;
    struct GameSystem *gameSystem = func_020124E4(event);
    struct GameData *gameData = func_020120F4(gameSystem);
    int ok;

    switch (*state) {
    case 0:
        func_02012374(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSystem, SYMBOL_VIEW_BGM_ID));
        (*state)++;
        break;
    case 1: {
        u32 heapId;
        struct PokemonParam *mon;
        SymbolKey key;

        mon = work->mon;
        heapId = work->heapId;

        key.species = func_02017E1C(mon, PARAM_SPECIES, 0);
        key.form = func_02017E1C(mon, PARAM_FORM, 0);
        if (func_0200E2BC(func_02012EBC(gameData), &key, heapId, 1) == 0)
            work->key.form = SYMBOL_UNSEEN_FORM;
        func_021CF498(func_02189A08(work->fieldMap), event, 0);
        (*state)++;
        break;
    }
    case 2:
        (*state)++;
        break;
    case 3:
        func_02012374(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, work->fieldMap));
        (*state)++;
        break;
    case 4: {
        struct SaveControl *saveControl = func_02012EBC(gameData);

        func_02007E50(func_0201292C(gameData), SYMBOL_VIEW_ITEM_ID, 1, work->heapId);
        func_02034AC4(FS_OVERLAY_ID(ov098));
        work->selectScreen = func_021B6100(gameData, work->mon, &work->scene, func_02012944(gameData), func_0201292C(gameData),
                                           func_0200873C(saveControl), func_0200CA10(saveControl), work->heapId);
        func_02012444(event, -1, d_021B6D74, work->selectScreen);
        (*state)++;
        break;
    }
    case 5: {
        u32 heapId;
        struct PokemonParam *mon;
        SymbolKey key;

        ok = func_021B6158(work->selectScreen);
        mon = work->mon;
        heapId = work->heapId;

        key.species = func_02017E1C(mon, PARAM_SPECIES, 0);
        key.form = func_02017E1C(mon, PARAM_FORM, 0);
        if (func_0200E2BC(func_02012EBC(gameData), &key, heapId, 1) == 0
            || func_0200E2BC(func_02012EBC(gameData), &work->key, work->heapId, 0) == 0)
            ok = 0;
        if (ok == 1)
            *work->resultOut = 1;
        else
            *work->resultOut = 0;
        func_02034A5C(FS_OVERLAY_ID(ov098));
        func_02034AC4(FS_OVERLAY_ID(ov227));
        work->resultScreen = func_021B95A0(gameData, ok, work->mon, work->heapId);
        func_02012444(event, -1, d_021B98A4, work->resultScreen);
        func_02007F1C(func_0201292C(gameData), SYMBOL_VIEW_ITEM_ID, 1, work->heapId);
        (*state)++;
        break;
    }
    case 6:
        func_021B95C8(work->resultScreen);
        func_02034A5C(FS_OVERLAY_ID(ov227));
        func_02012374(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSystem));
        (*state)++;
        break;
    case 7:
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 8:
        func_02012374(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*state)++;
        break;
    default:
        func_020307B0(work->mon);
        func_020307B0(work->selectScreen);
        return 1;
    }
    return 0;
}
