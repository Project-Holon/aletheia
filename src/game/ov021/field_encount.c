/*
 * file:     field_encount.c
 * unit:     yes
 * function: FIELD_ENCOUNT_SetupParam, FIELD_ENCOUNT_CalcEncountRate, FIELD_ENCOUNT_CreateWildMons, FIELD_ENCOUNT_CreateZoneWildMons, FIELD_ENCOUNT_PickRoamer, FIELD_ENCOUNT_PickWfbcMon, FIELD_ENCOUNT_InitWildPokemon, FIELD_ENCOUNT_InitRoamerPokemon, FIELD_ENCOUNT_GetSwarmZoneId, FIELD_ENCOUNT_ApplyLeadAbility, FIELD_ENCOUNT_IsRepelled, FIELD_ENCOUNT_GetSwarmEntry, FIELD_ENCOUNT_TrySwarmSlot, FIELD_ENCOUNT_LoadSlots, FIELD_ENCOUNT_RollSlotMon, FIELD_ENCOUNT_PickSlotByType, FIELD_ENCOUNT_ApplyHighLevelBias, FIELD_ENCOUNT_SelectMon, FIELD_ENCOUNT_RollHeldItem, FIELD_ENCOUNT_CreatePersonality, FIELD_ENCOUNT_RandPercent, FIELD_ENCOUNT_PickGroundSlot, FIELD_ENCOUNT_PickWaterSlot, FIELD_ENCOUNT_PickFishingSlot, FIELD_ENCOUNT_PickRandomSlot, FIELD_ENCOUNT_Create, FIELD_ENCOUNT_Delete, FIELD_ENCOUNT_CheckWildEncount, FIELD_ENCOUNT_StartScriptedWild, FIELD_ENCOUNT_CheckFishingEncount, FIELD_ENCOUNT_CheckWfbcEncount, FIELD_ENCOUNT_SetFieldSituation, FIELD_ENCOUNT_GetEncountType, FIELD_ENCOUNT_GetEncountRate, FIELD_ENCOUNT_CheckEncountRoll, FIELD_ENCOUNT_CheckWfbcRoll, FIELD_ENCOUNT_SetupWildBattle, FIELD_ENCOUNT_SetupRoamerBattle, FIELD_ENCOUNT_SetupTrainerBattle, FIELD_ENCOUNT_GetBattleWeather, FIELD_ENCOUNT_RandRatePercent, FIELD_ENCOUNT_ResetStepWork, FIELD_ENCOUNT_UpdateStepWork, FIELD_ENCOUNT_GetStepCount
 * address:  0x021A9350
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_effect.c at 0x021A9350: __FILE__ field_encount.c on 0x021A9ED8, 0x021AA490,
 * 0x021AA548; 0x021A9350 (encounter parameter setup) is called only by field_encount functions.
 *
 * symbols:
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_GetNature  0x02018598  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   MOVE_POKEMON_SAVE_IsCooldownDone  0x0200D58C  thumb
 *   POKEPARTY_GetBattleReadyCount  0x0201AA50  thumb
 *   POKEPARTY_FindFirstBattleReady  0x0201AB08  thumb
 *   GPOWER_ApplyEncountRate  0x02010FB0  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   MOVE_POKEMON_SAVE_IsEntryActive  0x0200D488  thumb
 *   MOVE_POKEMON_SAVE_GetEntry  0x0200D4AC  thumb
 *   MOVE_POKEMON_SAVE_GetEntryField  0x0200D4B8  thumb
 *   FIELD_WFBC_GetPeople  0x0219390C  thumb  ov021
 *   FIELD_WFBC_PEOPLE_GetNpcRecord  0x02193C00  thumb  ov021
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_RecalcParam  0x020185C4  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb
 *   sSwarmTable  0x021D8DE8  data
 *   MOVE_POKEMON_SAVE_GetStartLocation  0x0200D454  thumb
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   sSlotPickFuncs  0x021D8DD8  data
 *   sHeldItemWeights  0x021D8DCC  data
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb
 *   POKE_TOOL_CreatePersonalRnd  0x020186C8  thumb
 *   POKE_PERSONAL_IsFixedGender  0x0201AF6C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetEncountData  0x0216255C  thumb  ov010
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   FIELDMAP_GetWeather  0x02188C6C  thumb  ov021
 *   WEATHER_GetWeatherId  0x021A1BF4  thumb  ov021
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   RECORD_AddOne  0x02008DF0  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   BTL_SETUP_Create  0x02013090  thumb
 *   EVENT_BATTLE_CreateScriptedBattle  0x0216E7C8  thumb  ov010
 *   BTL_SETUP_SetStatusFlag  0x02013144  thumb
 *   FIELD_WFBC_IsBackPeople  0x02193920  thumb  ov021
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   ZONEDATA_GetFieldEffectSetId  0x02013ED8  thumb
 *   GF_STANDARD_GetCachedTime  0x0203F4CC  arm
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   FIELD_WFBC_GetPeopleNum  0x021938F4  thumb  ov021
 *   FX_Sqrt  0x0207C7B4  arm
 *   sFieldEncountFileName  0x021DDFA4  data
 *   BTL_SETUP_SetupWild  0x0201347C  thumb
 *   POKE_TOOL_GetPartyParamSize  0x020173EC  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   BTL_SETUP_Clear  0x020130C4  thumb
 *   TPOKE_DATA_GetRecordField  0x0202A230  thumb
 *   TPOKE_DATA_GetTrainerGroup  0x0202A420  thumb
 *   BTL_SETUP_SetupTrainerMulti  0x02013734  thumb
 *   BTL_SETUP_SetupTrainerDouble  0x02013644  thumb
 *   BTL_SETUP_SetupTrainerTag  0x020136E0  thumb
 *   BTL_SETUP_SetupTrainerSingle  0x02013610  thumb
 *   BTL_SETUP_SetupTrainerTriple  0x02013678  thumb
 *   BTL_SETUP_SetupTrainerRotation  0x020136AC  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   EFFECT_ENCOUNT_Create  0x021AA77C  thumb  ov021
 *   EFFECT_ENCOUNT_Delete  0x021AA794  thumb  ov021
 *   EFFECT_ENCOUNT_Init  0x021AA7AC  thumb  ov021
 *   EFFECT_ENCOUNT_Exit  0x021AA7CC  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsPresent  0x021AB100  thumb  ov021
 *   MAP_ATTR_IsTallGrass  0x021AB140  thumb  ov021
 *   MAP_ATTR_IsAnyDoubleGrass  0x021AB29C  thumb  ov021
 *   MAP_ATTR_GetBattleBackground  0x021AB580  thumb  ov021
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "../types.h"
#include "../arm9/gf_standard_types.h"

#include "../arm9/poke_tool_param.h"

#include "field_encount_types.h"
#include "../arm9/btl_setup_types.h"

struct SaveControl;
struct EncountSave;
struct Roamer;
struct EventWork;
struct EventDataSystem;
struct MyStatus;
struct Party;
struct PokemonParam;
struct PersonalData;
struct RecordBlock;
struct FieldPlayer;
struct WeatherSys;
struct FieldG3dMapper;
struct Mmdl;
struct FieldWfbc;
struct FieldWfbcPeople;

/* One generated wild Pokemon (0x14 bytes). */
typedef struct EncountMon {
    u16 species;        /* 0x00 */
    u16 heldItem;       /* 0x02 0 rolls the species items, above 0x272 none */
    u8 level;           /* 0x04 */
    u8 form;            /* 0x05 */
    u8 shinyMode;       /* 0x06 2 never shiny */
    u8 hiddenAbility;   /* 0x07 */
    u8 reserved08[8];
    u8 forcedGender;    /* 0x10 0 any, 1 male, 2 female */
    u8 reserved11[3];
} EncountMon;

/* Swarm entry of one zone (8 bytes); the save picks one of 17 per day. */
typedef struct SwarmEntry {
    u16 zoneId;
    u16 species;
    u8 form;
    u8 minLevel;
    u8 maxLevel;
    u8 reserved07;
} SwarmEntry;

/* Encounter parameters (0x2C), filled from the lead party Pokemon. */
typedef struct FieldEncountParam {
    struct GameData *gameData;        /* 0x00 */
    struct EncountSave *encountSave;  /* 0x04 */
    int encountType;                  /* 0x08 EncountData rate index, 0xFF scripted */
    int triggerMode;                  /* 0x0C 0 walk, 1 rustling spot, 2 forced, 3 White Forest */
    u32 slotTableKind;                /* 0x10 0 ground, 1 water, 2 fishing, 3 swarm */
    u8 slotCount;                     /* 0x14 */
    u8 monCount;                      /* 0x15 */
    u16 leadSpecies;                  /* 0x16 */
    u16 leadItem;                     /* 0x18 */
    u8 leadIsEgg;                     /* 0x1A */
    u8 leadAbility;                   /* 0x1B */
    u8 leadGender;                    /* 0x1C */
    u8 leadNature;                    /* 0x1D */
    u8 leadLevel;                     /* 0x1E level of the first Pokemon able to battle */
    u8 reserved1F;
    u32 ownerId;                      /* 0x20 */
    struct MyStatus *myStatus;        /* 0x24 */
    u32 swarmEnabled : 1;             /* 0x28 */
    u32 isFishing : 1;
    u32 repelActive : 1;
    u32 ignoreRepel : 1;
    u32 unusedFlag : 1;
    u32 isDoubleBattle : 1;
    u32 rateUp : 1;
    u32 rateDown : 1;
    u32 fishingRateUp : 1;
    u32 compoundEyes : 1;
    u32 syncNature : 1;
    u32 cuteCharm : 1;
    u32 magnetPull : 1;
    u32 staticElectric : 1;
    u32 highLevelBias : 1;
    u32 intimidate : 1;
} FieldEncountParam;

/* Steps walked since the last encounter (0x0C bytes, game data field gimmick slot). */
typedef struct EncountStepWork {
    u16 x, y, z;
    u16 moved;
    u32 stepCount;
} EncountStepWork;


#include "../arm9/zonedata.h"
#include "../arm9/mystatus.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/game_data.h"
#include "../arm9/move_pokemon_save.h"
#include "../arm9/pokeparty.h"
#include "../arm9/poke_tool.h"
struct MovePokemonSave;
#include "../arm9/gpower.h"
#include "../arm9/mi_memory.h"
struct MovePokemonEntry;
#include "../arm9/gfl_use.h"
#include "field_wfbc.h"
#include "../arm9/poke_personal.h"
struct BoxPokemon;
#include "fieldmap.h"
#include "../arm9/gamesystem.h"
#include "../ov010/eventdata_system.h"
#include "weather.h"
#include "../arm9/record.h"
#include "../arm9/btl_setup.h"
#include "../ov010/event_battle.h"
#include "field_player.h"
#include "../arm9/gf_standard.h"
#include "../arm9/fx_cp.h"
#include "../arm9/tpoke_data.h"
#include "../ov010/fldmmdl.h"
void FIELD_ENCOUNT_SetupParam(FieldEncountParam *param, struct GameData *gameData, int encountType, int triggerMode, u16 weather);
u32 FIELD_ENCOUNT_CalcEncountRate(FieldEncountParam *param, struct GameData *gameData, u32 baseRate);
int FIELD_ENCOUNT_CreateWildMons(FieldEncountParam *param, EncountSlot *slots, EncountMon *mons);
int FIELD_ENCOUNT_CreateZoneWildMons(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountMon *mons);
struct Roamer *FIELD_ENCOUNT_PickRoamer(EncountData *encountData, FieldEncountParam *param, u32 zoneId);
u32 FIELD_ENCOUNT_PickWfbcMon(struct FieldWfbc *wfbc, FieldEncountParam *param, EncountMon *mon);
void FIELD_ENCOUNT_InitWildPokemon(struct PokemonParam *pp, const FieldEncountParam *param, EncountMon *encMon);
void FIELD_ENCOUNT_InitRoamerPokemon(struct PokemonParam *pp, const FieldEncountParam *param, struct Roamer *roamer);
u16 FIELD_ENCOUNT_GetSwarmZoneId(struct GameData *gameData);
void FIELD_ENCOUNT_ApplyLeadAbility(FieldEncountParam *param, u16 weather);
int FIELD_ENCOUNT_IsRepelled(FieldEncountParam *param, u8 level);
const SwarmEntry *FIELD_ENCOUNT_GetSwarmEntry(struct GameData *gameData);
int FIELD_ENCOUNT_TrySwarmSlot(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slot);
u8 FIELD_ENCOUNT_LoadSlots(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slots);
void FIELD_ENCOUNT_RollSlotMon(EncountSlot *slot, EncountMon *mon);
u8 FIELD_ENCOUNT_PickSlotByType(FieldEncountParam *param, EncountSlot *slots, u32 type);
void FIELD_ENCOUNT_ApplyHighLevelBias(const FieldEncountParam *param, const EncountSlot *slots, EncountMon *mon);
void FIELD_ENCOUNT_SelectMon(FieldEncountParam *param, EncountSlot *slots, EncountMon *mon);
void FIELD_ENCOUNT_RollHeldItem(struct PokemonParam *pp, struct PersonalData *personal, int compoundEyes, int isDarkGrass);
u32 FIELD_ENCOUNT_CreatePersonality(const FieldEncountParam *param, struct PersonalData *personal, EncountMon *encMon);
u32 FIELD_ENCOUNT_RandPercent(void);
u32 FIELD_ENCOUNT_PickGroundSlot(u8 slotCount);
u32 FIELD_ENCOUNT_PickWaterSlot(u8 slotCount);
u32 FIELD_ENCOUNT_PickFishingSlot(u8 slotCount);
u32 FIELD_ENCOUNT_PickRandomSlot(u32 slotCount);
FieldEncount *FIELD_ENCOUNT_Create(struct FieldMap *fieldMap);
void FIELD_ENCOUNT_Delete(FieldEncount *encount);
struct GameEvent *FIELD_ENCOUNT_CheckWildEncount(FieldEncount *encount, int triggerMode);
struct GameEvent *FIELD_ENCOUNT_StartScriptedWild(FieldEncount *encount, u16 species, u8 level, u32 flags);
struct BattleSetupParam *FIELD_ENCOUNT_CheckFishingEncount(FieldEncount *encount, int triggerMode);
struct GameEvent *FIELD_ENCOUNT_CheckWfbcEncount(FieldEncount *encount, struct FieldWfbc *wfbc);
void FIELD_ENCOUNT_SetFieldSituation(struct FieldSituation *situation, struct GameData *gameData, struct FieldMap *fieldMap);
int FIELD_ENCOUNT_GetEncountType(FieldEncount *encount, int triggerMode, u8 *rateBonus);
int FIELD_ENCOUNT_GetEncountRate(FieldEncount *encount, int encountType, int rateBonus);
int FIELD_ENCOUNT_CheckEncountRoll(FieldEncount *encount, EncountStepWork *stepWork, u32 rate);
int FIELD_ENCOUNT_CheckWfbcRoll(EncountStepWork *stepWork, struct FieldWfbc *wfbc);
void FIELD_ENCOUNT_SetupWildBattle(FieldEncount *encount, FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, EncountMon *mons);
void FIELD_ENCOUNT_SetupRoamerBattle(FieldEncount *encount, const FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, struct Roamer *roamer);
void FIELD_ENCOUNT_SetupTrainerBattle(FieldEncount *encount, struct BattleSetupParam *btlSetup, u32 rule, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heapId);
u8 FIELD_ENCOUNT_GetBattleWeather(struct FieldMap *fieldMap);
u32 FIELD_ENCOUNT_RandRatePercent(void);
void FIELD_ENCOUNT_ResetStepWork(EncountStepWork *stepWork, struct FieldPlayer *player);
void FIELD_ENCOUNT_UpdateStepWork(EncountStepWork *stepWork, struct FieldPlayer *player);
u32 FIELD_ENCOUNT_GetStepCount(EncountStepWork *stepWork);
#include "effect_encount.h"
#include "map_attr.h"
extern const SwarmEntry sSwarmTable[];
extern const u8 sHeldItemWeights[];
extern const char sFieldEncountFileName[];
extern u32 (*const sSlotPickFuncs[])(u8 slotCount);

void FIELD_ENCOUNT_SetupParam(FieldEncountParam *param, struct GameData *gameData, int encountType, int triggerMode, u16 weather)
{
    struct SaveControl *saveControl;
    struct Party *party;
    struct PokemonParam *leadMon;

    saveControl = GAME_DATA_GetSaveControl(gameData);
    party = GAME_DATA_GetMyParty(gameData);
    MI_CpuFill8(param, 0, 0x2C);
    param->encountType = encountType;
    param->triggerMode = triggerMode;
    param->gameData = gameData;
    param->encountSave = MOVE_POKEMON_SAVE_GetBlock(saveControl);
    if (encountType == 5 || encountType == 6)
        param->isFishing = 1;
    param->myStatus = GAME_DATA_GetMyStatus(gameData);
    param->ownerId = MYSTATUS_GetId(param->myStatus);
    leadMon = POKEPARTY_GetMember(party, 0);
    param->leadIsEgg = POKE_TOOL_GetPartyValue(leadMon, 0x4C, 0);
    if (param->leadIsEgg == 0) {
        param->leadSpecies = POKE_TOOL_GetPartyValue(leadMon, 5, 0);
        param->leadItem = POKE_TOOL_GetPartyValue(leadMon, 6, 0);
        param->leadAbility = POKE_TOOL_GetPartyValue(leadMon, 10, 0);
        param->leadGender = POKE_TOOL_GetPartyValue(leadMon, 0x6E, 0);
        param->leadNature = POKE_TOOL_GetNature(leadMon);
        FIELD_ENCOUNT_ApplyLeadAbility(param, weather);
    }
    param->swarmEnabled = ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(gameData), 0x960);
    if (MOVE_POKEMON_SAVE_IsCooldownDone(MOVE_POKEMON_SAVE_GetBlock(saveControl)) == 0)
        param->repelActive = 1;
    if (param->triggerMode == 2) {
        param->ignoreRepel = 1;
        param->triggerMode = 0;
    }
    if (param->triggerMode == 1)
        param->ignoreRepel = 1;
    param->unusedFlag = 0;
    param->isDoubleBattle = 0;
    if (param->encountType == 1 && (int)POKEPARTY_GetBattleReadyCount(party) >= 2 && FIELD_ENCOUNT_RandPercent() < 0x28)
        param->isDoubleBattle = 1;
    if (param->intimidate || param->repelActive)
        param->leadLevel = POKE_TOOL_GetPartyValue(POKEPARTY_GetMember(party, POKEPARTY_FindFirstBattleReady(party)), 0x9E, 0);
    param->monCount = param->isDoubleBattle + 1;
}

/* Cleanse Tag (0xE0) and Pure Incense (0x140) cut the rate to two thirds. */
u32 FIELD_ENCOUNT_CalcEncountRate(FieldEncountParam *param, struct GameData *gameData, u32 baseRate)
{
    u32 rate = baseRate;

    if (param->isFishing) {
        if (param->fishingRateUp) {
            rate = rate * 2;
        }
        if (rate > 100) {
            rate = 100;
        }
        return rate;
    }
    if (param->rateUp) {
        rate = rate * 2;
    } else if (param->rateDown) {
        rate = rate >> 1;
    }
    if (param->leadItem == 0xE0 || param->leadItem == 0x140) {
        rate = (baseRate * 2) / 3;
    }
    if (rate > 100) {
        rate = 100;
    }
    return GPOWER_ApplyEncountRate(rate);
}

int FIELD_ENCOUNT_CreateWildMons(FieldEncountParam *param, EncountSlot *slots, EncountMon *mons)
{
    int count = 0;
    int i;

    for (i = 0; i < param->monCount; i++) {
        EncountMon *mon = &mons[count];
        FIELD_ENCOUNT_SelectMon(param, slots, mon);
        if (FIELD_ENCOUNT_IsRepelled(param, mon->level) == 0)
            count++;
    }
    return count;
}

int FIELD_ENCOUNT_CreateZoneWildMons(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountMon *mons)
{
    EncountSlot slots[12];

    MIi_CpuClear32(0, slots, sizeof(slots));
    FIELD_ENCOUNT_LoadSlots(encountData, param, zoneId, slots);
    return FIELD_ENCOUNT_CreateWildMons(param, slots, mons);
}

/* A roaming Pokemon in this zone appears half of the time. */
struct Roamer *FIELD_ENCOUNT_PickRoamer(EncountData *encountData, FieldEncountParam *param, u32 zoneId)
{
    struct Roamer *candidates[2];
    u8 count = 0;
    u8 i;
    struct Roamer *roamer;

    for (i = 0; i < 2; i++) {
        if (MOVE_POKEMON_SAVE_IsEntryActive((struct MovePokemonSave *)param->encountSave, i) == 0)
            continue;
        roamer = (struct Roamer *)MOVE_POKEMON_SAVE_GetEntry((struct MovePokemonSave *)param->encountSave, i);
        if (MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 1) != zoneId)
            continue;
        if (FIELD_ENCOUNT_IsRepelled(param, MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 6)) != 0)
            continue;
        candidates[count++] = roamer;
    }
    if (count == 0 || GFL_USE_GetRandomBelow(1000) < 500)
        return 0;
    return candidates[GFL_USE_GetRandomBelow(count)];
}

/*
 * White Forest: every resident brings one species per table (grass, dark
 * grass, water). The resident record (WfbcNpcRecord) holds the species at
 * 0x08, the levels at 0x10 and the weights at 0x14.
 */
u32 FIELD_ENCOUNT_PickWfbcMon(struct FieldWfbc *wfbc, FieldEncountParam *param, EncountMon *mon)
{
    u32 column;
    u32 totalWeight;
    u32 roll;
    int i;
    WfbcNpcRecord *record;
    struct FieldWfbcPeople *people;

    switch (param->encountType) {
    case 0:
        column = 0;
        break;
    case 1:
        column = 1;
        break;
    case 3:
        column = 2;
        break;
    case 0xFF:
        return 0;
    }
    totalWeight = 0;
    for (i = 0; i < 30; i++) {
        people = FIELD_WFBC_GetPeople(wfbc, i);
        if (people) {
            totalWeight += FIELD_WFBC_PEOPLE_GetNpcRecord(people)->weights[column];
        }
    }
    roll = GFL_USE_GetRandom(totalWeight);
    totalWeight = 0;
    for (i = 0; i < 30; i++) {
        people = FIELD_WFBC_GetPeople(wfbc, i);
        if (people) {
            record = FIELD_WFBC_PEOPLE_GetNpcRecord(people);
            totalWeight += record->weights[column];
            if (roll < totalWeight) {
                MI_CpuFill8(mon, 0, 0x14);
                mon->species = record->speciesIds[column];
                mon->level = record->levels[column];
                return 1;
            }
        }
    }
    return 0;
}

void FIELD_ENCOUNT_InitWildPokemon(struct PokemonParam *pp, const FieldEncountParam *param, EncountMon *encMon)
{
    struct PersonalData *personal = POKE_PERSONAL_Create(encMon->species, encMon->form, 4);
    u32 personality = FIELD_ENCOUNT_CreatePersonality(param, personal, encMon);

    POKE_TOOL_SetupPartyParamEx(pp, encMon->species, encMon->level, param->ownerId, 0xFFFFFFFF, personality);
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_FORM, encMon->form);
    if (encMon->hiddenAbility)
        POKE_TOOL_SetAbility((struct BoxPokemon *)pp, encMon->species, encMon->form);
    if (encMon->heldItem <= 0x272) {
        if (encMon->heldItem != 0)
            POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_HELD_ITEM, encMon->heldItem);
        else
            FIELD_ENCOUNT_RollHeldItem(pp, personal, param->compoundEyes, param->encountType == 1);
    }
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_OT_GENDER, MYSTATUS_GetSex(param->myStatus));
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_OT_NAME, (uptr)MYSTATUS_GetName(param->myStatus));
    if (param->syncNature)
        POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_NATURE, param->leadNature);
    POKE_TOOL_RecalcParam(pp);
    POKE_PERSONAL_Delete(personal);
}

/*
 * Lever: `const FieldEncountParam *param` settles the argument scheduling
 * before the POKE_TOOL_SetupPartyParamEx call (as in FIELD_ENCOUNT_InitWildPokemon).
 */
void FIELD_ENCOUNT_InitRoamerPokemon(struct PokemonParam *pp, const FieldEncountParam *param, struct Roamer *roamer)
{
    u16 species = MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 4);
    u8 level = MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 6);
    u32 ivs = MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 2);

    POKE_TOOL_SetupPartyParamEx(pp, species, level, param->ownerId, ivs, MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 3));
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_NATURE, MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 10));
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_STATUS_CONDITION, MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 7));
    POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_HP, MOVE_POKEMON_SAVE_GetEntryField((struct MovePokemonEntry *)roamer, 5));
    POKE_TOOL_RecalcParam(pp);
}

u16 FIELD_ENCOUNT_GetSwarmZoneId(struct GameData *gameData)
{
    const SwarmEntry *entry = FIELD_ENCOUNT_GetSwarmEntry(gameData);
    if (entry == 0) {
        return 0xffff;
    }
    return entry->zoneId;
}

/* Lead Pokemon abilities that change the rate or the wild Pokemon. */
void FIELD_ENCOUNT_ApplyLeadAbility(FieldEncountParam *param, u16 weather)
{
    switch (param->leadAbility) {
    case 0x23:
    case 0x47:
    case 0x63:
        param->rateUp = 1;
        return;
    case 0x01:
    case 0x49:
    case 0x5F:
        param->rateDown = 1;
        return;
    case 0x08:
        if (weather == 3 || weather == 12)
            param->rateDown = 1;
        return;
    case 0x51:
        if (weather == 1 || weather == 4 || weather == 5)
            param->rateDown = 1;
        return;
    case 0x15:
    case 0x3C:
        if (param->isFishing)
            param->fishingRateUp = 1;
        return;
    case 0x0E:
        param->compoundEyes = 1;
        return;
    }
    if (param->leadAbility == 0x38 && FIELD_ENCOUNT_RandPercent() < 0x43) {
        param->cuteCharm = 1;
        return;
    }
    if (FIELD_ENCOUNT_RandPercent() < 0x32)
        return;
    switch (param->leadAbility) {
    case 0x2A:
        param->magnetPull = 1;
        return;
    case 0x09:
        param->staticElectric = 1;
        return;
    case 0x2E:
    case 0x37:
    case 0x48:
        param->highLevelBias = 1;
        return;
    case 0x16:
    case 0x33:
        param->intimidate = 1;
        return;
    case 0x1C:
        param->syncNature = 1;
        return;
    }
}

/* Returns 1 when a repel or the lead ability keeps a Pokemon of this level away. */
int FIELD_ENCOUNT_IsRepelled(FieldEncountParam *param, u8 level)
{
    if (param->ignoreRepel)
        return 0;
    if (param->intimidate && param->leadLevel >= level + 5)
        return 1;
    if (!param->isFishing && param->repelActive && level < param->leadLevel)
        return 1;
    return 0;
}

const SwarmEntry *FIELD_ENCOUNT_GetSwarmEntry(struct GameData *gameData)
{
    struct SaveControl *saveControl = GAME_DATA_GetSaveControl(gameData);
    u32 index;

    if (ZONEDATA_CheckEventFlag(GAME_DATA_GetEventWork(gameData), 0x960) == 0)
        return 0;
    index = MOVE_POKEMON_SAVE_GetStartLocation(MOVE_POKEMON_SAVE_GetBlock(saveControl));
    if (index >= 0x11)
        index = 0;
    return &sSwarmTable[index];
}

int FIELD_ENCOUNT_TrySwarmSlot(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slot)
{
    const SwarmEntry *entry = FIELD_ENCOUNT_GetSwarmEntry(param->gameData);

    if (entry == 0 || entry->zoneId != zoneId)
        return 0;
    if (param->encountType != 0)
        return 0;
    if (GFL_USE_GetRandomBelow(1000) > 400)
        return 0;
    slot->species = entry->species;
    slot->minLevel = entry->minLevel;
    slot->maxLevel = entry->maxLevel;
    slot->form = entry->form;
    param->slotTableKind = 3;
    param->slotCount = 1;
    return 1;
}

/*
 * Shape: count is a u8 (the return needs no truncation) and each case
 * assigns kind, then count, then src; that order keeps every case its own
 * block with a branch to the join and gives count r6, src r4.
 */
u8 FIELD_ENCOUNT_LoadSlots(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slots)
{
    u8 count = 0;
    u32 kind = 0;
    EncountSlot *src;

    if (FIELD_ENCOUNT_TrySwarmSlot(encountData, param, zoneId, slots) != 0)
        return param->slotCount;
    if (param->encountType >= 7)
        param->encountType = 0;
    switch (param->encountType) {
    case 0:
        count = 12;
        src = encountData->ground[0];
        break;
    case 1:
        count = 12;
        src = encountData->ground[1];
        break;
    case 2:
        count = 12;
        src = encountData->ground[2];
        break;
    case 3:
        kind = 1;
        count = 5;
        src = encountData->water[0];
        break;
    case 4:
        kind = 1;
        count = 5;
        src = encountData->water[1];
        break;
    case 5:
        kind = 2;
        count = 5;
        src = encountData->fishing[0];
        break;
    case 6:
        kind = 2;
        count = 5;
        src = encountData->fishing[1];
        break;
    }
    param->slotTableKind = kind;
    param->slotCount = count;
    MI_CpuCopy8(src, slots, count * 4);
    return count;
}

void FIELD_ENCOUNT_RollSlotMon(EncountSlot *slot, EncountMon *mon)
{
    s16 levelRange = slot->maxLevel - slot->minLevel;
    u8 formCount;
    int form;
    u16 species;

    MI_CpuFill8(mon, 0, 0x14);
    if (levelRange < 0)
        levelRange = 0;
    mon->level = slot->minLevel + FIELD_ENCOUNT_RandPercent() % (u32)(levelRange + 1);
    species = slot->species;
    mon->species = species;
    formCount = POKE_TOOL_GetPersonalParam(species, 0, 0x20);
    form = slot->form;
    if (form == 0x1F)
        mon->form = GFL_USE_GetRandomBelow(formCount);
    else if (form >= formCount)
        mon->form = 0;
    else
        mon->form = form;
}

/* Magnet Pull and Static: pick a random slot whose species has the type. */
u8 FIELD_ENCOUNT_PickSlotByType(FieldEncountParam *param, EncountSlot *slots, u32 type)
{
    u8 candidates[12];
    int i;
    int count;
    u8 type1, type2;

    count = 0;
    for (i = 0; i < param->slotCount; i++) {
        if (slots[i].form != 0x1F) {
            type1 = POKE_TOOL_GetPersonalParam(slots[i].species, slots[i].form, 6);
            type2 = POKE_TOOL_GetPersonalParam(slots[i].species, slots[i].form, 7);
            if (type1 == type || type2 == type) {
                candidates[count] = i;
                count++;
            }
        }
    }
    if (count == 0)
        return 0xFF;
    return candidates[FIELD_ENCOUNT_RandPercent() % count];
}

/*
 * Lever: `const` on both the parameter and the slot-table pointers keeps
 * the per-iteration reload of param->slotCount and the image colouring;
 * declaration order i, maxLevel, baseLevel, hasRange.
 */
void FIELD_ENCOUNT_ApplyHighLevelBias(const FieldEncountParam *param, const EncountSlot *slots, EncountMon *mon)
{
    int i;
    u8 maxLevel;
    u8 baseLevel;
    int hasRange;

    maxLevel = mon->level;
    baseLevel = maxLevel;
    hasRange = 0;
    if (param->highLevelBias == 0)
        return;
    for (i = 0; i < param->slotCount; i++) {
        if (hasRange == 0 && slots[i].minLevel != slots[i].maxLevel)
            hasRange = 1;
        if (mon->species == slots[i].species && maxLevel < slots[i].maxLevel)
            maxLevel = slots[i].maxLevel;
    }
    if (baseLevel + 5 <= maxLevel && hasRange == 1)
        mon->level += 5;
    else
        mon->level = maxLevel;
}

void FIELD_ENCOUNT_SelectMon(FieldEncountParam *param, EncountSlot *slots, EncountMon *mon)
{
    u8 slotIndex = 0xFF;

    if (param->magnetPull)
        slotIndex = FIELD_ENCOUNT_PickSlotByType(param, slots, 8);
    else if (param->staticElectric)
        slotIndex = FIELD_ENCOUNT_PickSlotByType(param, slots, 12);
    if (slotIndex == 0xFF)
        slotIndex = sSlotPickFuncs[param->slotTableKind](param->slotCount);
    FIELD_ENCOUNT_RollSlotMon(&slots[slotIndex], mon);
    FIELD_ENCOUNT_ApplyHighLevelBias(param, slots, mon);
}

void FIELD_ENCOUNT_RollHeldItem(struct PokemonParam *pp, struct PersonalData *personal, int compoundEyes, int isDarkGrass)
{
    u16 itemIds[3];
    int i;
    const u8 *weights;
    u8 roll;
    u8 cumulative;

    for (i = 0; i < 3; i++)
        itemIds[i] = POKE_PERSONAL_GetParam(personal, 0x11 + i);
    if (itemIds[0] == itemIds[1]) {
        POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_HELD_ITEM, itemIds[0]);
        return;
    }
    weights = &sHeldItemWeights[(compoundEyes + isDarkGrass * 2) * 3];
    roll = FIELD_ENCOUNT_RandPercent();
    cumulative = 0;
    for (i = 0; i < 3; i++) {
        cumulative += weights[i];
        if (roll < cumulative) {
            POKE_TOOL_SetPartyValue(pp, POKE_TOOL_PARAM_HELD_ITEM, itemIds[i]);
            return;
        }
    }
}

u32 FIELD_ENCOUNT_CreatePersonality(const FieldEncountParam *param, struct PersonalData *personal, EncountMon *encMon)
{
    u32 gender = 2;
    u32 personality;
    u32 idCheck;

    if (POKE_PERSONAL_IsFixedGender((u8)POKE_PERSONAL_GetParam(personal, 0x14)) != 1) {
        if (param->cuteCharm) {
            if (param->leadGender == 0)
                gender = 1;
            else if (param->leadGender == 1)
                gender = 0;
        }
        if (encMon->forcedGender == 1)
            gender = 0;
        else if (encMon->forcedGender == 2)
            gender = 1;
    }
    personality = POKE_TOOL_CreatePersonalRnd(param->ownerId, encMon->species, encMon->form, gender, 2, encMon->shinyMode == 2 ? 0 : 2);
    if (encMon->shinyMode != 2) {
        idCheck = (u16)personality ^ ((param->ownerId >> 16) ^ (u16)param->ownerId);
        if (idCheck & 1)
            personality |= 0x80000000;
        else
            personality &= 0x7FFFFFFF;
    }
    return personality;
}

u32 FIELD_ENCOUNT_RandPercent(void)
{
    return GFL_USE_GetRandom(0xFFFF) / 0x290;
}

u32 FIELD_ENCOUNT_PickGroundSlot(u8 slotCount)
{
    u32 roll = FIELD_ENCOUNT_RandPercent();

    if (roll < 0x14) return 0;
    if (roll >= 0x14 && roll < 0x28) return 1;
    if (roll >= 0x28 && roll < 0x32) return 2;
    if (roll >= 0x32 && roll < 0x3C) return 3;
    if (roll >= 0x3C && roll < 0x46) return 4;
    if (roll >= 0x46 && roll < 0x50) return 5;
    if (roll >= 0x50 && roll < 0x55) return 6;
    if (roll >= 0x55 && roll < 0x5A) return 7;
    if (roll >= 0x5A && roll < 0x5E) return 8;
    if (roll >= 0x5E && roll < 0x62) return 9;
    if (roll == 0x62) return 10;
    return 11;
}

u32 FIELD_ENCOUNT_PickWaterSlot(u8 slotCount)
{
    u32 roll = FIELD_ENCOUNT_RandPercent();
    if (roll < 60) {
        return 0;
    }
    if (roll >= 60 && roll < 90) {
        return 1;
    }
    if (roll >= 90 && roll < 95) {
        return 2;
    }
    if (roll >= 95 && roll < 99) {
        return 3;
    }
    return 4;
}

u32 FIELD_ENCOUNT_PickFishingSlot(u8 slotCount)
{
    u32 roll = FIELD_ENCOUNT_RandPercent();
    if (roll < 40) {
        return 0;
    }
    if (roll < 80) {
        return 1;
    }
    if (roll < 95) {
        return 2;
    }
    if (roll < 99) {
        return 3;
    }
    return 4;
}

u32 FIELD_ENCOUNT_PickRandomSlot(u32 slotCount)
{
    return FIELD_ENCOUNT_RandPercent() % slotCount;
}

FieldEncount *FIELD_ENCOUNT_Create(struct FieldMap *fieldMap)
{
    u32 heapId = FIELDMAP_GetHeapId(fieldMap);
    FieldEncount *encount = GFL_HEAP_Alloc(heapId, 0x14, 1, sFieldEncountFileName, 0x62);
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct EffectEncount *effectEncount;

    encount->fieldMap = fieldMap;
    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    encount->gameSystem = gameSystem;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    encount->gameData = gameData;
    encount->encountData = EVENTDATA_SYSTEM_GetEncountData(GAME_DATA_GetEventData(gameData));
    effectEncount = EFFECT_ENCOUNT_Create(heapId);
    encount->effectEncount = effectEncount;
    EFFECT_ENCOUNT_Init(encount, effectEncount);
    return encount;
}

void FIELD_ENCOUNT_Delete(FieldEncount *encount)
{
    EFFECT_ENCOUNT_Exit(encount, encount->effectEncount);
    EFFECT_ENCOUNT_Delete(encount->effectEncount);
    GFL_HEAP_Free(encount);
}

struct GameEvent *FIELD_ENCOUNT_CheckWildEncount(FieldEncount *encount, int triggerMode)
{
    EncountMon mons[2];
    FieldEncountParam param;
    u8 rateBonus;
    int rate;
    int encountType;
    EncountStepWork *stepWork;
    struct FieldPlayer *player;
    int skipRateCheck;
    struct Roamer *roamer;
    struct BattleSetupParam *btlSetup;
    int monCount;

    skipRateCheck = 0;
    roamer = 0;
    player = FIELDMAP_GetFieldPlayer(encount->fieldMap);
    stepWork = (struct EncountStepWork *)GAME_DATA_GetFieldGimmick(encount->gameData);
    if (triggerMode == 1 || triggerMode == 2)
        skipRateCheck = 1;
    else
        FIELD_ENCOUNT_UpdateStepWork(stepWork, player);
    if (encount->encountData == 0 || !encount->encountData->enabled)
        return 0;
    rateBonus = 0;
    encountType = FIELD_ENCOUNT_GetEncountType(encount, triggerMode, &rateBonus);
    rate = FIELD_ENCOUNT_GetEncountRate(encount, encountType, rateBonus);
    if (encountType == 0xFF || rate == 0)
        return 0;
    FIELD_ENCOUNT_SetupParam(&param, encount->gameData, encountType, triggerMode, WEATHER_GetWeatherId(FIELDMAP_GetWeather(encount->fieldMap)));
    if (!skipRateCheck) {
        if (!FIELD_ENCOUNT_CheckEncountRoll(encount, stepWork, FIELD_ENCOUNT_CalcEncountRate(&param, encount->gameData, rate)))
            return 0;
    }
    if (triggerMode == 1)
        RECORD_AddOne(GAME_DATA_GetTrainerRecord(encount->gameData), 0x70);
    else
        roamer = FIELD_ENCOUNT_PickRoamer(encount->encountData, &param, FIELDMAP_GetZoneId(encount->fieldMap));
    if (roamer) {
        btlSetup = BTL_SETUP_Create(4);
        FIELD_ENCOUNT_SetupRoamerBattle(encount, &param, btlSetup, 4, roamer);
    } else {
        roamer = 0;
        MI_CpuFill8(mons, 0, 0x28);
        monCount = FIELD_ENCOUNT_CreateZoneWildMons(encount->encountData, &param, FIELDMAP_GetZoneId(encount->fieldMap), mons);
        if (monCount == 0)
            return 0;
        if (param.isDoubleBattle && monCount == 1) {
            param.isDoubleBattle = 0;
            param.monCount = monCount;
        }
        btlSetup = BTL_SETUP_Create(4);
        FIELD_ENCOUNT_SetupWildBattle(encount, &param, btlSetup, 4, mons);
    }
    FIELD_ENCOUNT_ResetStepWork(stepWork, player);
    return EVENT_BATTLE_CreateScriptedBattle(encount->gameSystem, encount->fieldMap, btlSetup, 0, triggerMode);
}

/*
 * Scripted wild battle. flags: 1 and 0x80 battle status flags, 2 or 0x10
 * shiny mode, 4 no held item, 8 hidden ability, 0x20 or 0x40 gender,
 * 0x100 status flag 0x200.
 */
struct GameEvent *FIELD_ENCOUNT_StartScriptedWild(FieldEncount *encount, u16 species, u8 level, u32 flags)
{
    EncountMon mons[2];
    FieldEncountParam param;
    struct BattleSetupParam *btlSetup;
    EncountMon *mon;

    FIELDMAP_GetFieldPlayer(encount->fieldMap);
    FIELD_ENCOUNT_SetupParam(&param, encount->gameData, 0xff, 0, WEATHER_GetWeatherId(FIELDMAP_GetWeather(encount->fieldMap)));
    mon = mons;
    MI_CpuFill8(mon, 0, 0x28);
    mons[0].species = species;
    mon->level = level;
    if (flags & 4) {
        mon->heldItem = 0xffff;
    }
    if (flags & 2) {
        mon->shinyMode = 1;
    } else if (flags & 0x10) {
        mon->shinyMode = 2;
    } else {
        mon->shinyMode = 0;
    }
    if (flags & 8) {
        mon->hiddenAbility = 1;
    }
    if (flags & 0x20) {
        mon->forcedGender = 1;
    } else if (flags & 0x40) {
        mon->forcedGender = 2;
    }
    btlSetup = BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupWildBattle(encount, &param, btlSetup, 4, mons);
    if (flags & 1) {
        BTL_SETUP_SetStatusFlag(btlSetup, 4);
    } else if (flags & 0x80) {
        BTL_SETUP_SetStatusFlag(btlSetup, 0x80);
    }
    if (flags & 0x100) {
        BTL_SETUP_SetStatusFlag(btlSetup, 0x200);
    }
    return EVENT_BATTLE_CreateScriptedBattle(encount->gameSystem, encount->fieldMap, btlSetup, 1, 0);
}

struct BattleSetupParam *FIELD_ENCOUNT_CheckFishingEncount(FieldEncount *encount, int triggerMode)
{
    EncountMon mons[2];
    FieldEncountParam param;
    int encountType;
    int baseRate;
    u32 rate;
    struct BattleSetupParam *btlSetup;

    if (encount->encountData == 0 || !encount->encountData->enabled)
        return 0;
    encountType = 6;
    if (triggerMode != 1)
        encountType = 5;
    baseRate = FIELD_ENCOUNT_GetEncountRate(encount, encountType, 0);
    if (baseRate == 0)
        return 0;
    FIELD_ENCOUNT_SetupParam(&param, encount->gameData, encountType, triggerMode, WEATHER_GetWeatherId(FIELDMAP_GetWeather(encount->fieldMap)));
    if (triggerMode != 1) {
        rate = FIELD_ENCOUNT_CalcEncountRate(&param, encount->gameData, baseRate);
        if (FIELD_ENCOUNT_RandRatePercent() > rate)
            return 0;
    }
    btlSetup = 0;
    MI_CpuFill8(mons, 0, 0x28);
    if ((u32)FIELD_ENCOUNT_CreateZoneWildMons(encount->encountData, &param, FIELDMAP_GetZoneId(encount->fieldMap), mons) < param.monCount)
        return btlSetup;
    btlSetup = BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupWildBattle(encount, &param, btlSetup, 4, mons);
    BTL_SETUP_SetStatusFlag(btlSetup, 1);
    btlSetup->fieldSituation.bgAttr = 6;
    return btlSetup;
}

struct GameEvent *FIELD_ENCOUNT_CheckWfbcEncount(FieldEncount *encount, struct FieldWfbc *wfbc)
{
    EncountMon mons[2];
    FieldEncountParam param;
    u8 rateBonus;
    struct FieldPlayer *player;
    EncountStepWork *stepWork;
    int encountType;
    struct BattleSetupParam *btlSetup;

    player = FIELDMAP_GetFieldPlayer(encount->fieldMap);
    stepWork = (struct EncountStepWork *)GAME_DATA_GetFieldGimmick(encount->gameData);
    FIELD_ENCOUNT_UpdateStepWork(stepWork, player);
    if (FIELD_WFBC_IsBackPeople(wfbc) == 1) {
        return 0;
    }
    if (!FIELD_ENCOUNT_CheckWfbcRoll(stepWork, wfbc)) {
        return 0;
    }
    rateBonus = 0;
    encountType = FIELD_ENCOUNT_GetEncountType(encount, 3, &rateBonus);
    FIELD_ENCOUNT_SetupParam(&param, encount->gameData, encountType, 3, WEATHER_GetWeatherId(FIELDMAP_GetWeather(encount->fieldMap)));
    MI_CpuFill8(mons, 0, 0x28);
    if (!FIELD_ENCOUNT_PickWfbcMon(wfbc, &param, mons)) {
        return 0;
    }
    btlSetup = BTL_SETUP_Create(4);
    FIELD_ENCOUNT_SetupWildBattle(encount, &param, btlSetup, 4, mons);
    FIELD_ENCOUNT_ResetStepWork(stepWork, player);
    return EVENT_BATTLE_CreateScriptedBattle(encount->gameSystem, encount->fieldMap, btlSetup, 0, 3);
}

void FIELD_ENCOUNT_SetFieldSituation(struct FieldSituation *situation, struct GameData *gameData, struct FieldMap *fieldMap)
{
    RTCTime time;
    u16 zoneId = FIELDMAP_GetZoneId(fieldMap);
    struct FieldPlayer *player = FIELDMAP_GetFieldPlayer(fieldMap);

    situation->bgType = ZONEDATA_GetFieldEffectSetId(zoneId);
    situation->bgAttr = MAP_ATTR_GetBattleBackground(MAP_ATTR_GetTerrainId(FIELD_PLAYER_GetNowAttribute(player)));
    situation->zoneId = zoneId;
    GF_STANDARD_GetCachedTime(&time);
    situation->hour = time.hour;
    situation->minute = time.minute;
    situation->weather = FIELD_ENCOUNT_GetBattleWeather(fieldMap);
    situation->season = GAME_DATA_GetSeason(gameData);
}

/* Encounter type of the player's cell, 0xFF when nothing can appear there. */
int FIELD_ENCOUNT_GetEncountType(FieldEncount *encount, int triggerMode, u8 *rateBonus)
{
    struct FieldPlayer *player = FIELDMAP_GetFieldPlayer(encount->fieldMap);
    u32 attr;
    u16 attrFlags;
    u16 attrValue;

    FIELDMAP_GetG3dMapper(encount->fieldMap);
    *rateBonus = 0;
    attr = FIELD_PLAYER_GetNowAttribute(player);
    if (MAP_ATTR_IsPresent(attr) == 0)
        return 0xFF;
    attrFlags = MAP_ATTR_GetFlags(attr);
    if (triggerMode != 1 && (attrFlags & 4) == 0)
        return 0xFF;
    attrValue = MAP_ATTR_GetTerrainId(attr);
    if (MAP_ATTR_IsTallGrass(attrValue))
        *rateBonus += 10;
    if (attrFlags & 2) {
        if (triggerMode == 1)
            return 4;
        return 3;
    }
    if (triggerMode == 1)
        return 2;
    if (MAP_ATTR_IsAnyDoubleGrass(attrValue))
        return 1;
    return 0;
}

int FIELD_ENCOUNT_GetEncountRate(FieldEncount *encount, int encountType, int rateBonus)
{
    int rate;

    if (encountType >= 7)
        return 0;
    rate = encount->encountData->rate[encountType];
    if (rate > 0)
        rate += rateBonus;
    if (rate < 0)
        rate = 0;
    return rate;
}

/* No encounter on the first step after a battle; the second step rolls at 1 percent. */
int FIELD_ENCOUNT_CheckEncountRoll(FieldEncount *encount, EncountStepWork *stepWork, u32 rate)
{
    u32 steps;

    if (rate > 100)
        rate = 100;
    steps = FIELD_ENCOUNT_GetStepCount(stepWork);
    if (steps == 0)
        return 0;
    if (steps == 1)
        rate = 1;
    if (FIELD_ENCOUNT_RandRatePercent() <= rate)
        return 1;
    return 0;
}

static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}

/* White Forest rate: (steps - 1) * sqrt(resident count) * 4 percent. */
int FIELD_ENCOUNT_CheckWfbcRoll(EncountStepWork *stepWork, struct FieldWfbc *wfbc)
{
    int steps = FIELD_ENCOUNT_GetStepCount(stepWork);
    int peopleCount = FIELD_WFBC_GetPeopleNum(wfbc);
    int roll = GFL_USE_GetRandom(100);
    fx32 peopleSqrt = FX_Sqrt(peopleCount << 12);
    fx32 chance = FX_MUL((steps - 1) << 12, peopleSqrt);
    chance = FX_MUL(chance, 0x4000);
    return (int)GPOWER_ApplyEncountRate((int)(chance >> 12)) > roll;
}

void FIELD_ENCOUNT_SetupWildBattle(FieldEncount *encount, FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, EncountMon *mons)
{
    struct FieldSituation situation;
    struct Party *party = POKEPARTY_Create(heapId);
    struct PokemonParam *pp = GFL_HEAP_Alloc(heapId, POKE_TOOL_GetPartyParamSize(), 1, sFieldEncountFileName, 0x285);
    int i;

    for (i = 0; i < (u8)param->isDoubleBattle + 1; i++) {
        FIELD_ENCOUNT_InitWildPokemon(pp, param, &mons[i]);
        POKEPARTY_Add(party, pp);
    }
    FIELD_ENCOUNT_SetFieldSituation(&situation, encount->gameData, encount->fieldMap);
    BTL_SETUP_SetupWild(btlSetup, encount->gameData, party, &situation, param->isDoubleBattle, heapId);
    if (param->encountType == 1)
        BTL_SETUP_SetStatusFlag(btlSetup, 0x20);
    GFL_HEAP_Free(pp);
    GFL_HEAP_Free(party);
}

void FIELD_ENCOUNT_SetupRoamerBattle(FieldEncount *encount, const FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, struct Roamer *roamer)
{
    struct FieldSituation situation;
    struct Party *party = POKEPARTY_Create(heapId);
    struct PokemonParam *pp = GFL_HEAP_Alloc((u16)((heapId & 0x7FFF) | 0x8000), POKE_TOOL_GetPartyParamSize(), 1, sFieldEncountFileName, 0x2A4);

    FIELD_ENCOUNT_InitRoamerPokemon(pp, param, roamer);
    POKEPARTY_Add(party, pp);
    FIELD_ENCOUNT_SetFieldSituation(&situation, encount->gameData, encount->fieldMap);
    BTL_SETUP_SetupWild(btlSetup, encount->gameData, party, &situation, 0, heapId);
    BTL_SETUP_SetStatusFlag(btlSetup, 8);
    GFL_HEAP_Free(pp);
    GFL_HEAP_Free(party);
}

void FIELD_ENCOUNT_SetupTrainerBattle(FieldEncount *encount, struct BattleSetupParam *btlSetup, u32 rule, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heapId)
{
    struct FieldSituation situation;
    struct GameData *gameData = encount->gameData;
    u32 trainerBgAttr;

    BTL_SETUP_Clear(btlSetup);
    FIELD_ENCOUNT_SetFieldSituation(&situation, encount->gameData, encount->fieldMap);
    trainerBgAttr = TPOKE_DATA_GetTrainerGroup(TPOKE_DATA_GetRecordField((void *)trainerId1, 1));
    if (trainerBgAttr != 0x11) {
        situation.bgAttr = trainerBgAttr;
    }
    switch (rule) {
    case 1:
        if (partnerId) {
            BTL_SETUP_SetupTrainerMulti(btlSetup, gameData, &situation, partnerId, trainerId1, trainerId2, heapId);
        } else {
            BTL_SETUP_SetupTrainerDouble(btlSetup, gameData, &situation, trainerId1, heapId);
        }
        return;
    case 0:
        if (trainerId2) {
            BTL_SETUP_SetupTrainerTag(btlSetup, gameData, &situation, trainerId1, trainerId2, heapId);
        } else {
            BTL_SETUP_SetupTrainerSingle(btlSetup, gameData, &situation, trainerId1, heapId);
        }
        return;
    case 2:
        BTL_SETUP_SetupTrainerTriple(btlSetup, gameData, &situation, trainerId1, heapId);
        return;
    case 3:
        BTL_SETUP_SetupTrainerRotation(btlSetup, gameData, &situation, trainerId1, heapId);
        return;
    }
}

/* Battle weather for the field weather. */
u8 FIELD_ENCOUNT_GetBattleWeather(struct FieldMap *fieldMap)
{
    switch (WEATHER_GetWeatherId(FIELDMAP_GetWeather(fieldMap))) {
    case 2:
    case 6:
    case 7:
        return 2;
    case 3:
    case 12:
        return 4;
    case 4:
    case 5:
        return 3;
    }
    return 0;
}

u32 FIELD_ENCOUNT_RandRatePercent(void)
{
    return GFL_USE_GetRandom(0xFFFF) / 0x290;
}

void FIELD_ENCOUNT_ResetStepWork(EncountStepWork *stepWork, struct FieldPlayer *player)
{
    struct Mmdl *mmdl = FIELD_PLAYER_GetMmdl(player);

    MI_CpuFill8(stepWork, 0, sizeof(*stepWork));
    stepWork->x = FLDMMDL_GetGridNowX(mmdl);
    stepWork->y = FLDMMDL_GetGridNowY(mmdl);
    stepWork->z = FLDMMDL_GetGridNowZ(mmdl);
}

void FIELD_ENCOUNT_UpdateStepWork(EncountStepWork *stepWork, struct FieldPlayer *player)
{
    struct Mmdl *mmdl = FIELD_PLAYER_GetMmdl(player);

    if (stepWork->moved != 0) {
        if (stepWork->stepCount < 0xA000)
            stepWork->stepCount++;
        return;
    }
    if (stepWork->x != FLDMMDL_GetGridNowX(mmdl) || stepWork->y != FLDMMDL_GetGridNowY(mmdl) || stepWork->z != FLDMMDL_GetGridNowZ(mmdl)) {
        stepWork->moved = 1;
        stepWork->stepCount++;
    }
}

u32 FIELD_ENCOUNT_GetStepCount(EncountStepWork *stepWork)
{
    return stepWork->stepCount;
}
