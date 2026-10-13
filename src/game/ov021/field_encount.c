/*
 * file:     field_encount.c
 * unit:     yes
 * function: func_021A9350, func_021A94B0, func_021A9508, func_021A954C, func_021A957C, func_021A9604, func_021A96B8, func_021A9780, func_021A9810, func_021A9828, func_021A996C, func_021A99A8, func_021A99E4, func_021A9A5C, func_021A9B00, func_021A9B68, func_021A9BE8, func_021A9C58, func_021A9CAC, func_021A9D30, func_021A9DC8, func_021A9DE0, func_021A9E64, func_021A9E98, func_021A9EC4, func_021A9ED8, func_021A9F28, func_021A9F40, func_021AA0A0, func_021AA180, func_021AA248, func_021AA304, func_021AA35C, func_021AA3E0, func_021AA3FC, func_021AA42C, func_021AA490, func_021AA548, func_021AA5CC, func_021AA69C, func_021AA6E0, func_021AA6F8, func_021AA728, func_021AA778
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
 *   func_020142E8  0x020142E8  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02018598  0x02018598  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_02010FB0  0x02010FB0  thumb
 *   MIi_CpuClear32  0x02082A7C  arm
 *   func_02005728  0x02005728  thumb
 *   func_0200D488  0x0200D488  thumb
 *   func_0200D4AC  0x0200D4AC  thumb
 *   func_0200D4B8  0x0200D4B8  thumb
 *   func_0219390C  0x0219390C  thumb  ov021
 *   func_02193C00  0x02193C00  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02018A00  0x02018A00  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   data_021D8DE8  0x021D8DE8  data
 *   func_0200D454  0x0200D454  thumb
 *   func_02019C90  0x02019C90  thumb
 *   data_021D8DD8  0x021D8DD8  data
 *   data_021D8DCC  0x021D8DCC  data
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_020186C8  0x020186C8  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *   func_02030734  0x02030734  arm
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_0216255C  0x0216255C  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02012A38  0x02012A38  thumb
 *   func_02188C6C  0x02188C6C  thumb  ov021
 *   func_021A1BF4  0x021A1BF4  thumb  ov021
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_02013144  0x02013144  thumb
 *   func_02193920  0x02193920  thumb  ov021
 *   func_02012984  0x02012984  thumb
 *   func_02013ED8  0x02013ED8  thumb
 *   func_0203F4CC  0x0203F4CC  arm
 *   func_021A30C8  0x021A30C8  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021938F4  0x021938F4  thumb  ov021
 *   func_0207C7B4  0x0207C7B4  arm
 *   data_021DDFA4  0x021DDFA4  data
 *   func_0201347C  0x0201347C  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020130C4  0x020130C4  thumb
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A420  0x0202A420  thumb
 *   func_02013734  0x02013734  thumb
 *   func_02013644  0x02013644  thumb
 *   func_020136E0  0x020136E0  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013678  0x02013678  thumb
 *   func_020136AC  0x020136AC  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021A3074  0x021A3074  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_021AA77C  0x021AA77C  thumb  ov021
 *   func_021AA794  0x021AA794  thumb  ov021
 *   func_021AA7AC  0x021AA7AC  thumb  ov021
 *   func_021AA7CC  0x021AA7CC  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB100  0x021AB100  thumb  ov021
 *   func_021AB140  0x021AB140  thumb  ov021
 *   func_021AB29C  0x021AB29C  thumb  ov021
 *   func_021AB580  0x021AB580  thumb  ov021
 */
typedef unsigned char u8;

typedef signed short s16;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef long long fx64;

typedef int fx32;

typedef int BOOL;

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
struct TrainerRecord;
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

struct RtcTime { u32 hour; u32 minute; u32 second; };

extern u32 func_020142E8(struct EventWork *eventWork, s32 flagId);
extern const u16 *func_020084F4(const struct MyStatus *myStatus);
extern u8 func_02008550(const struct MyStatus *myStatus);
extern u32 func_020307B0(void *memory);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct Party *func_02012934(const struct GameData *gameData);
extern struct EncountSave *func_0200D418(struct SaveControl *saveControl);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern u32 func_02008530(const struct MyStatus *myStatus);
extern struct PokemonParam *func_0201AB28(struct Party *party, u32 index);
extern u32 func_02017E1C(struct PokemonParam *pp, u32 id, u32 arg);
extern u8 func_02018598(struct PokemonParam *pp);
extern struct EventWork *func_0201296C(const struct GameData *gameData);
extern u32 func_0200D58C(struct EncountSave *encountSave);
extern u32 func_0201AA50(struct Party *party);
extern u32 func_0201AB08(struct Party *party);
extern u32 func_0209C2B0(u32 numerator, u32 denominator);
extern u32 func_02010FB0(u32 rate);
extern void MIi_CpuClear32(u32 data, void *destp, u32 size);
extern u8 func_0200D488(struct EncountSave *encountSave, u32 index);
extern struct Roamer *func_0200D4AC(struct EncountSave *encountSave, u32 index);
extern u32 func_0200D4B8(const struct Roamer *roamer, u32 field);
extern u32 func_02005728(u32 range);
extern struct FieldWfbcPeople *func_0219390C(struct FieldWfbc *wfbc, u32 npcId);
extern u8 *func_02193C00(struct FieldWfbcPeople *people);
extern u32 func_020056EC(u32 range);
extern struct PersonalData *func_0201ADE4(unsigned int species, int form, unsigned int heapId);
extern void func_02017588(struct PokemonParam *pp, u16 species, u16 level, unsigned long long otId, u32 ivs, unsigned long long personality);
extern void func_02017E40(struct PokemonParam *pp, u32 id, u32 value);
extern void func_02018A00(struct PokemonParam *pp, u32 species, u32 form);
extern void func_020185C4(struct PokemonParam *pp);
extern void func_0201AE14(struct PersonalData *personal);
extern u8 func_0200D454(struct EncountSave *encountSave);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);
extern u32 func_02019C90(u16 species, u16 form, u32 field);
extern u32 func_0201AE1C(const struct PersonalData *personal, u32 field);
extern u32 func_0201AF6C(u32 genderRatio);
extern u32 func_020186C8(u32 otId, int species, int form, int ratioMode, int shinyWanted, int mode);
extern u16 func_02188C84(struct FieldMap *fieldMap);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct EventDataSystem *func_02012844(const struct GameData *gameData);
extern EncountData *func_0216255C(struct EventDataSystem *eventData);
extern void *func_02030734(u32 heapId, u32 size, int fromTop, const char *file, u16 line);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern EncountStepWork *func_02012A38(const struct GameData *gameData);
extern struct WeatherSys *func_02188C6C(struct FieldMap *fieldMap);
extern u16 func_021A1BF4(struct WeatherSys *weatherSys);
extern struct TrainerRecord *func_02012F2C(struct GameData *gameData);
extern u32 func_02008DF0(struct TrainerRecord *record, int recordId);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern struct BattleSetupParam *func_02013090(u32 heapId);
extern int func_0216E7C8(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct BattleSetupParam *btlSetup, int isScripted, int triggerMode);
extern void func_02013144(struct BattleSetupParam *btlSetup, int flag);
extern u8 func_02193920(struct FieldWfbc *wfbc);
extern u8 func_02013ED8(u32 zoneId);
extern u32 func_021A30C8(struct FieldPlayer *player);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 func_02012984(const struct GameData *gameData);
extern struct FieldG3dMapper *func_02188C98(struct FieldMap *fieldMap);
extern int func_021938F4(struct FieldWfbc *wfbc);
extern fx32 func_0207C7B4(fx32 x);
extern struct Party *func_0201A920(u32 heapId);
extern u32 func_020173EC(void);
extern u32 func_0201A98C(struct Party *party, const struct PokemonParam *pp);
extern void func_0201347C(struct BattleSetupParam *param, struct GameData *gd, struct Party *wildParty, const struct FieldSituation *sit, u32 rule, u16 heap);
extern void func_020130C4(struct BattleSetupParam *param);
extern u32 func_0202A230(u32 trainerId, u32 field);
extern u32 func_0202A420(u32 trainerType);
extern void func_02013734(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 partnerId, u32 trainerId1, u32 trainerId2, u32 heap);
extern void func_020136E0(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId1, u32 trainerId2, u16 heap);
extern void func_02013644(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
extern void func_02013610(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
extern void func_02013678(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
extern void func_020136AC(struct BattleSetupParam *param, struct GameData *gd, const struct FieldSituation *sit, u32 trainerId, u16 heap);
extern struct Mmdl *func_021A3074(struct FieldPlayer *player);
extern int func_0216D83C(struct Mmdl *mmdl);
extern int func_0216D854(struct Mmdl *mmdl);
extern int func_0216D86C(struct Mmdl *mmdl);
void func_021A9350(FieldEncountParam *param, struct GameData *gameData, int encountType, int triggerMode, u16 weather);
u32 func_021A94B0(FieldEncountParam *param, struct GameData *gameData, u32 baseRate);
int func_021A9508(FieldEncountParam *param, EncountSlot *slots, EncountMon *mons);
int func_021A954C(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountMon *mons);
struct Roamer *func_021A957C(EncountData *encountData, FieldEncountParam *param, u32 zoneId);
u32 func_021A9604(struct FieldWfbc *wfbc, FieldEncountParam *param, EncountMon *mon);
void func_021A96B8(struct PokemonParam *pp, const FieldEncountParam *param, EncountMon *encMon);
void func_021A9780(struct PokemonParam *pp, const FieldEncountParam *param, struct Roamer *roamer);
u16 func_021A9810(struct GameData *gameData);
void func_021A9828(FieldEncountParam *param, u16 weather);
int func_021A996C(FieldEncountParam *param, u8 level);
const SwarmEntry *func_021A99A8(struct GameData *gameData);
int func_021A99E4(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slot);
u8 func_021A9A5C(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slots);
void func_021A9B00(EncountSlot *slot, EncountMon *mon);
u8 func_021A9B68(FieldEncountParam *param, EncountSlot *slots, u32 type);
void func_021A9BE8(const FieldEncountParam *param, const EncountSlot *slots, EncountMon *mon);
void func_021A9C58(FieldEncountParam *param, EncountSlot *slots, EncountMon *mon);
void func_021A9CAC(struct PokemonParam *pp, struct PersonalData *personal, int compoundEyes, int isDarkGrass);
u32 func_021A9D30(const FieldEncountParam *param, struct PersonalData *personal, EncountMon *encMon);
u32 func_021A9DC8(void);
u32 func_021A9DE0(u8 slotCount);
u32 func_021A9E64(u8 slotCount);
u32 func_021A9E98(u8 slotCount);
u32 func_021A9EC4(u32 slotCount);
FieldEncount *func_021A9ED8(struct FieldMap *fieldMap);
void func_021A9F28(FieldEncount *encount);
int func_021A9F40(FieldEncount *encount, int triggerMode);
int func_021AA0A0(FieldEncount *encount, u16 species, u8 level, u32 flags);
struct BattleSetupParam *func_021AA180(FieldEncount *encount, int triggerMode);
int func_021AA248(FieldEncount *encount, struct FieldWfbc *wfbc);
void func_021AA304(struct FieldSituation *situation, struct GameData *gameData, struct FieldMap *fieldMap);
int func_021AA35C(FieldEncount *encount, int triggerMode, u8 *rateBonus);
int func_021AA3E0(FieldEncount *encount, int encountType, int rateBonus);
int func_021AA3FC(FieldEncount *encount, EncountStepWork *stepWork, u32 rate);
int func_021AA42C(EncountStepWork *stepWork, struct FieldWfbc *wfbc);
void func_021AA490(FieldEncount *encount, FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, EncountMon *mons);
void func_021AA548(FieldEncount *encount, const FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, struct Roamer *roamer);
void func_021AA5CC(FieldEncount *encount, struct BattleSetupParam *btlSetup, u32 rule, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heapId);
u8 func_021AA69C(struct FieldMap *fieldMap);
u32 func_021AA6E0(void);
void func_021AA6F8(EncountStepWork *stepWork, struct FieldPlayer *player);
void func_021AA728(EncountStepWork *stepWork, struct FieldPlayer *player);
u32 func_021AA778(EncountStepWork *stepWork);
struct EffectEncount *func_021AA77C(int heapId);
int func_021AA794(struct EffectEncount *effectEncount);
void func_021AA7AC(FieldEncount *encount, struct EffectEncount *effectEncount);
void func_021AA7CC(FieldEncount *encount, struct EffectEncount *effectEncount);
u16 func_021AB0F0(u32 attr);
u16 func_021AB0F8(u32 attr);
BOOL func_021AB100(u32 attr);
int func_021AB140(int attrValue);
BOOL func_021AB29C(u16 attrValue);
u8 func_021AB580(u16 attrValue);
extern const SwarmEntry data_021D8DE8[];
extern const u8 data_021D8DCC[];
extern const char data_021DDFA4[];
extern u32 (*const data_021D8DD8[])(u8 slotCount);

void func_021A9350(FieldEncountParam *param, struct GameData *gameData, int encountType, int triggerMode, u16 weather)
{
    struct SaveControl *saveControl;
    struct Party *party;
    struct PokemonParam *leadMon;

    saveControl = func_02012EBC(gameData);
    party = func_02012934(gameData);
    MI_CpuFill8(param, 0, 0x2C);
    param->encountType = encountType;
    param->triggerMode = triggerMode;
    param->gameData = gameData;
    param->encountSave = func_0200D418(saveControl);
    if (encountType == 5 || encountType == 6)
        param->isFishing = 1;
    param->myStatus = func_02012944(gameData);
    param->ownerId = func_02008530(param->myStatus);
    leadMon = func_0201AB28(party, 0);
    param->leadIsEgg = func_02017E1C(leadMon, 0x4C, 0);
    if (param->leadIsEgg == 0) {
        param->leadSpecies = func_02017E1C(leadMon, 5, 0);
        param->leadItem = func_02017E1C(leadMon, 6, 0);
        param->leadAbility = func_02017E1C(leadMon, 10, 0);
        param->leadGender = func_02017E1C(leadMon, 0x6E, 0);
        param->leadNature = func_02018598(leadMon);
        func_021A9828(param, weather);
    }
    param->swarmEnabled = func_020142E8(func_0201296C(gameData), 0x960);
    if (func_0200D58C(func_0200D418(saveControl)) == 0)
        param->repelActive = 1;
    if (param->triggerMode == 2) {
        param->ignoreRepel = 1;
        param->triggerMode = 0;
    }
    if (param->triggerMode == 1)
        param->ignoreRepel = 1;
    param->unusedFlag = 0;
    param->isDoubleBattle = 0;
    if (param->encountType == 1 && (int)func_0201AA50(party) >= 2 && func_021A9DC8() < 0x28)
        param->isDoubleBattle = 1;
    if (param->intimidate || param->repelActive)
        param->leadLevel = func_02017E1C(func_0201AB28(party, func_0201AB08(party)), 0x9E, 0);
    param->monCount = param->isDoubleBattle + 1;
}

/* Cleanse Tag (0xE0) and Pure Incense (0x140) cut the rate to two thirds. */
u32 func_021A94B0(FieldEncountParam *param, struct GameData *gameData, u32 baseRate)
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
        rate = func_0209C2B0(baseRate * 2, 3);
    }
    if (rate > 100) {
        rate = 100;
    }
    return func_02010FB0(rate);
}

int func_021A9508(FieldEncountParam *param, EncountSlot *slots, EncountMon *mons)
{
    int count = 0;
    int i;

    for (i = 0; i < param->monCount; i++) {
        EncountMon *mon = &mons[count];
        func_021A9C58(param, slots, mon);
        if (func_021A996C(param, mon->level) == 0)
            count++;
    }
    return count;
}

int func_021A954C(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountMon *mons)
{
    EncountSlot slots[12];

    MIi_CpuClear32(0, slots, sizeof(slots));
    func_021A9A5C(encountData, param, zoneId, slots);
    return func_021A9508(param, slots, mons);
}

/* A roaming Pokemon in this zone appears half of the time. */
struct Roamer *func_021A957C(EncountData *encountData, FieldEncountParam *param, u32 zoneId)
{
    struct Roamer *candidates[2];
    u8 count = 0;
    u8 i;
    struct Roamer *roamer;

    for (i = 0; i < 2; i++) {
        if (func_0200D488(param->encountSave, i) == 0)
            continue;
        roamer = func_0200D4AC(param->encountSave, i);
        if (func_0200D4B8(roamer, 1) != zoneId)
            continue;
        if (func_021A996C(param, func_0200D4B8(roamer, 6)) != 0)
            continue;
        candidates[count++] = roamer;
    }
    if (count == 0 || func_02005728(1000) < 500)
        return 0;
    return candidates[func_02005728(count)];
}

/*
 * White Forest: every resident brings one species per table (grass, dark
 * grass, water). The resident record (WfbcNpcRecord) holds the species at
 * 0x08, the levels at 0x10 and the weights at 0x14; the shared record type
 * names those bytes otherwise, so they are read by offset here.
 */
u32 func_021A9604(struct FieldWfbc *wfbc, FieldEncountParam *param, EncountMon *mon)
{
    u32 column;
    u32 totalWeight;
    u32 roll;
    int i;
    u8 *record;
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
        people = func_0219390C(wfbc, i);
        if (people) {
            totalWeight += func_02193C00(people)[column + 0x14];
        }
    }
    roll = func_020056EC(totalWeight);
    totalWeight = 0;
    for (i = 0; i < 30; i++) {
        people = func_0219390C(wfbc, i);
        if (people) {
            record = func_02193C00(people);
            totalWeight += record[column + 0x14];
            if (roll < totalWeight) {
                MI_CpuFill8(mon, 0, 0x14);
                mon->species = ((u16 *)(record + 8))[column];
                mon->level = (record + column)[0x10];
                return 1;
            }
        }
    }
    return 0;
}

void func_021A96B8(struct PokemonParam *pp, const FieldEncountParam *param, EncountMon *encMon)
{
    struct PersonalData *personal = func_0201ADE4(encMon->species, encMon->form, 4);
    u32 personality = func_021A9D30(param, personal, encMon);

    func_02017588(pp, encMon->species, encMon->level, param->ownerId, 0xFFFFFFFF, personality);
    func_02017E40(pp, 0x6F, encMon->form);
    if (encMon->hiddenAbility)
        func_02018A00(pp, encMon->species, encMon->form);
    if (encMon->heldItem <= 0x272) {
        if (encMon->heldItem != 0)
            func_02017E40(pp, 6, encMon->heldItem);
        else
            func_021A9CAC(pp, personal, param->compoundEyes, param->encountType == 1);
    }
    func_02017E40(pp, 0x9A, func_02008550(param->myStatus));
    func_02017E40(pp, 0x8E, (u32)func_020084F4(param->myStatus));
    if (param->syncNature)
        func_02017E40(pp, 0x70, param->leadNature);
    func_020185C4(pp);
    func_0201AE14(personal);
}

/*
 * Lever: `const FieldEncountParam *param` settles the argument scheduling
 * before the func_02017588 call (as in func_021A96B8).
 */
void func_021A9780(struct PokemonParam *pp, const FieldEncountParam *param, struct Roamer *roamer)
{
    u16 species = func_0200D4B8(roamer, 4);
    u8 level = func_0200D4B8(roamer, 6);
    u32 ivs = func_0200D4B8(roamer, 2);

    func_02017588(pp, species, level, param->ownerId, ivs, func_0200D4B8(roamer, 3));
    func_02017E40(pp, 0x70, func_0200D4B8(roamer, 10));
    func_02017E40(pp, 0x9D, func_0200D4B8(roamer, 7));
    func_02017E40(pp, 0xA0, func_0200D4B8(roamer, 5));
    func_020185C4(pp);
}

u16 func_021A9810(struct GameData *gameData)
{
    const SwarmEntry *entry = func_021A99A8(gameData);
    if (entry == 0) {
        return 0xffff;
    }
    return entry->zoneId;
}

/* Lead Pokemon abilities that change the rate or the wild Pokemon. */
void func_021A9828(FieldEncountParam *param, u16 weather)
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
    if (param->leadAbility == 0x38 && func_021A9DC8() < 0x43) {
        param->cuteCharm = 1;
        return;
    }
    if (func_021A9DC8() < 0x32)
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
int func_021A996C(FieldEncountParam *param, u8 level)
{
    if (param->ignoreRepel)
        return 0;
    if (param->intimidate && param->leadLevel >= level + 5)
        return 1;
    if (!param->isFishing && param->repelActive && level < param->leadLevel)
        return 1;
    return 0;
}

const SwarmEntry *func_021A99A8(struct GameData *gameData)
{
    struct SaveControl *saveControl = func_02012EBC(gameData);
    u32 index;

    if (func_020142E8(func_0201296C(gameData), 0x960) == 0)
        return 0;
    index = func_0200D454(func_0200D418(saveControl));
    if (index >= 0x11)
        index = 0;
    return &data_021D8DE8[index];
}

int func_021A99E4(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slot)
{
    const SwarmEntry *entry = func_021A99A8(param->gameData);

    if (entry == 0 || entry->zoneId != zoneId)
        return 0;
    if (param->encountType != 0)
        return 0;
    if (func_02005728(1000) > 400)
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
u8 func_021A9A5C(EncountData *encountData, FieldEncountParam *param, u16 zoneId, EncountSlot *slots)
{
    u8 count = 0;
    u32 kind = 0;
    EncountSlot *src;

    if (func_021A99E4(encountData, param, zoneId, slots) != 0)
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

void func_021A9B00(EncountSlot *slot, EncountMon *mon)
{
    s16 levelRange = slot->maxLevel - slot->minLevel;
    u8 formCount;
    int form;
    u16 species;

    MI_CpuFill8(mon, 0, 0x14);
    if (levelRange < 0)
        levelRange = 0;
    mon->level = slot->minLevel + func_021A9DC8() % (u32)(levelRange + 1);
    species = slot->species;
    mon->species = species;
    formCount = func_02019C90(species, 0, 0x20);
    form = slot->form;
    if (form == 0x1F)
        mon->form = func_02005728(formCount);
    else if (form >= formCount)
        mon->form = 0;
    else
        mon->form = form;
}

/* Magnet Pull and Static: pick a random slot whose species has the type. */
u8 func_021A9B68(FieldEncountParam *param, EncountSlot *slots, u32 type)
{
    u8 candidates[12];
    int i;
    int count;
    u8 type1, type2;

    count = 0;
    for (i = 0; i < param->slotCount; i++) {
        if (slots[i].form != 0x1F) {
            type1 = func_02019C90(slots[i].species, slots[i].form, 6);
            type2 = func_02019C90(slots[i].species, slots[i].form, 7);
            if (type1 == type || type2 == type) {
                candidates[count] = i;
                count++;
            }
        }
    }
    if (count == 0)
        return 0xFF;
    return candidates[func_021A9DC8() % count];
}

/*
 * Lever: `const` on both the parameter and the slot-table pointers keeps
 * the per-iteration reload of param->slotCount and the image colouring;
 * declaration order i, maxLevel, baseLevel, hasRange.
 */
void func_021A9BE8(const FieldEncountParam *param, const EncountSlot *slots, EncountMon *mon)
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

void func_021A9C58(FieldEncountParam *param, EncountSlot *slots, EncountMon *mon)
{
    u8 slotIndex = 0xFF;

    if (param->magnetPull)
        slotIndex = func_021A9B68(param, slots, 8);
    else if (param->staticElectric)
        slotIndex = func_021A9B68(param, slots, 12);
    if (slotIndex == 0xFF)
        slotIndex = data_021D8DD8[param->slotTableKind](param->slotCount);
    func_021A9B00(&slots[slotIndex], mon);
    func_021A9BE8(param, slots, mon);
}

void func_021A9CAC(struct PokemonParam *pp, struct PersonalData *personal, int compoundEyes, int isDarkGrass)
{
    u16 itemIds[3];
    int i;
    const u8 *weights;
    u8 roll;
    u8 cumulative;

    for (i = 0; i < 3; i++)
        itemIds[i] = func_0201AE1C(personal, 0x11 + i);
    if (itemIds[0] == itemIds[1]) {
        func_02017E40(pp, 6, itemIds[0]);
        return;
    }
    weights = &data_021D8DCC[(compoundEyes + isDarkGrass * 2) * 3];
    roll = func_021A9DC8();
    cumulative = 0;
    for (i = 0; i < 3; i++) {
        cumulative += weights[i];
        if (roll < cumulative) {
            func_02017E40(pp, 6, itemIds[i]);
            return;
        }
    }
}

u32 func_021A9D30(const FieldEncountParam *param, struct PersonalData *personal, EncountMon *encMon)
{
    u32 gender = 2;
    u32 personality;
    u32 idCheck;

    if (func_0201AF6C((u8)func_0201AE1C(personal, 0x14)) != 1) {
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
    personality = func_020186C8(param->ownerId, encMon->species, encMon->form, gender, 2, encMon->shinyMode == 2 ? 0 : 2);
    if (encMon->shinyMode != 2) {
        idCheck = (u16)personality ^ ((param->ownerId >> 16) ^ (u16)param->ownerId);
        if (idCheck & 1)
            personality |= 0x80000000;
        else
            personality &= 0x7FFFFFFF;
    }
    return personality;
}

u32 func_021A9DC8(void)
{
    return func_0209C2B0(func_020056EC(0xFFFF), 0x290);
}

u32 func_021A9DE0(u8 slotCount)
{
    u32 roll = func_021A9DC8();

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

u32 func_021A9E64(u8 slotCount)
{
    u32 roll = func_021A9DC8();
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

u32 func_021A9E98(u8 slotCount)
{
    u32 roll = func_021A9DC8();
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

u32 func_021A9EC4(u32 slotCount)
{
    return func_021A9DC8() % slotCount;
}

FieldEncount *func_021A9ED8(struct FieldMap *fieldMap)
{
    u32 heapId = func_02188C84(fieldMap);
    FieldEncount *encount = func_02030734(heapId, 0x14, 1, data_021DDFA4, 0x62);
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct EffectEncount *effectEncount;

    encount->fieldMap = fieldMap;
    gameSystem = func_02188C80(fieldMap);
    encount->gameSystem = gameSystem;
    gameData = func_020120F4(gameSystem);
    encount->gameData = gameData;
    encount->encountData = func_0216255C(func_02012844(gameData));
    effectEncount = func_021AA77C(heapId);
    encount->effectEncount = effectEncount;
    func_021AA7AC(encount, effectEncount);
    return encount;
}

void func_021A9F28(FieldEncount *encount)
{
    func_021AA7CC(encount, encount->effectEncount);
    func_021AA794(encount->effectEncount);
    func_020307B0(encount);
}

int func_021A9F40(FieldEncount *encount, int triggerMode)
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
    player = func_02188CB4(encount->fieldMap);
    stepWork = func_02012A38(encount->gameData);
    if (triggerMode == 1 || triggerMode == 2)
        skipRateCheck = 1;
    else
        func_021AA728(stepWork, player);
    if (encount->encountData == 0 || !encount->encountData->enabled)
        return 0;
    rateBonus = 0;
    encountType = func_021AA35C(encount, triggerMode, &rateBonus);
    rate = func_021AA3E0(encount, encountType, rateBonus);
    if (encountType == 0xFF || rate == 0)
        return 0;
    func_021A9350(&param, encount->gameData, encountType, triggerMode, func_021A1BF4(func_02188C6C(encount->fieldMap)));
    if (!skipRateCheck) {
        if (!func_021AA3FC(encount, stepWork, func_021A94B0(&param, encount->gameData, rate)))
            return 0;
    }
    if (triggerMode == 1)
        func_02008DF0(func_02012F2C(encount->gameData), 0x70);
    else
        roamer = func_021A957C(encount->encountData, &param, func_02188C9C(encount->fieldMap));
    if (roamer) {
        btlSetup = func_02013090(4);
        func_021AA548(encount, &param, btlSetup, 4, roamer);
    } else {
        roamer = 0;
        MI_CpuFill8(mons, 0, 0x28);
        monCount = func_021A954C(encount->encountData, &param, func_02188C9C(encount->fieldMap), mons);
        if (monCount == 0)
            return (int)roamer;
        if (param.isDoubleBattle && monCount == 1) {
            param.isDoubleBattle = 0;
            param.monCount = monCount;
        }
        btlSetup = func_02013090(4);
        func_021AA490(encount, &param, btlSetup, 4, mons);
    }
    func_021AA6F8(stepWork, player);
    return func_0216E7C8(encount->gameSystem, encount->fieldMap, btlSetup, 0, triggerMode);
}

/*
 * Scripted wild battle. flags: 1 and 0x80 battle status flags, 2 or 0x10
 * shiny mode, 4 no held item, 8 hidden ability, 0x20 or 0x40 gender,
 * 0x100 status flag 0x200.
 */
int func_021AA0A0(FieldEncount *encount, u16 species, u8 level, u32 flags)
{
    EncountMon mons[2];
    FieldEncountParam param;
    struct BattleSetupParam *btlSetup;
    EncountMon *mon;

    func_02188CB4(encount->fieldMap);
    func_021A9350(&param, encount->gameData, 0xff, 0, func_021A1BF4(func_02188C6C(encount->fieldMap)));
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
    btlSetup = func_02013090(4);
    func_021AA490(encount, &param, btlSetup, 4, mons);
    if (flags & 1) {
        func_02013144(btlSetup, 4);
    } else if (flags & 0x80) {
        func_02013144(btlSetup, 0x80);
    }
    if (flags & 0x100) {
        func_02013144(btlSetup, 0x200);
    }
    return func_0216E7C8(encount->gameSystem, encount->fieldMap, btlSetup, 1, 0);
}

struct BattleSetupParam *func_021AA180(FieldEncount *encount, int triggerMode)
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
    baseRate = func_021AA3E0(encount, encountType, 0);
    if (baseRate == 0)
        return 0;
    func_021A9350(&param, encount->gameData, encountType, triggerMode, func_021A1BF4(func_02188C6C(encount->fieldMap)));
    if (triggerMode != 1) {
        rate = func_021A94B0(&param, encount->gameData, baseRate);
        if (func_021AA6E0() > rate)
            return 0;
    }
    btlSetup = 0;
    MI_CpuFill8(mons, 0, 0x28);
    if ((u32)func_021A954C(encount->encountData, &param, func_02188C9C(encount->fieldMap), mons) < param.monCount)
        return btlSetup;
    btlSetup = func_02013090(4);
    func_021AA490(encount, &param, btlSetup, 4, mons);
    func_02013144(btlSetup, 1);
    btlSetup->fieldSituation.bgAttr = 6;
    return btlSetup;
}

int func_021AA248(FieldEncount *encount, struct FieldWfbc *wfbc)
{
    EncountMon mons[2];
    FieldEncountParam param;
    u8 rateBonus;
    struct FieldPlayer *player;
    EncountStepWork *stepWork;
    int encountType;
    struct BattleSetupParam *btlSetup;

    player = func_02188CB4(encount->fieldMap);
    stepWork = func_02012A38(encount->gameData);
    func_021AA728(stepWork, player);
    if (func_02193920(wfbc) == 1) {
        return 0;
    }
    if (!func_021AA42C(stepWork, wfbc)) {
        return 0;
    }
    rateBonus = 0;
    encountType = func_021AA35C(encount, 3, &rateBonus);
    func_021A9350(&param, encount->gameData, encountType, 3, func_021A1BF4(func_02188C6C(encount->fieldMap)));
    MI_CpuFill8(mons, 0, 0x28);
    if (!func_021A9604(wfbc, &param, mons)) {
        return 0;
    }
    btlSetup = func_02013090(4);
    func_021AA490(encount, &param, btlSetup, 4, mons);
    func_021AA6F8(stepWork, player);
    return func_0216E7C8(encount->gameSystem, encount->fieldMap, btlSetup, 0, 3);
}

void func_021AA304(struct FieldSituation *situation, struct GameData *gameData, struct FieldMap *fieldMap)
{
    struct RtcTime time;
    u16 zoneId = func_02188C9C(fieldMap);
    struct FieldPlayer *player = func_02188CB4(fieldMap);

    situation->bgType = func_02013ED8(zoneId);
    situation->bgAttr = func_021AB580(func_021AB0F0(func_021A30C8(player)));
    situation->zoneId = zoneId;
    func_0203F4CC(&time);
    situation->hour = time.hour;
    situation->minute = time.minute;
    situation->weather = func_021AA69C(fieldMap);
    situation->season = func_02012984(gameData);
}

/* Encounter type of the player's cell, 0xFF when nothing can appear there. */
int func_021AA35C(FieldEncount *encount, int triggerMode, u8 *rateBonus)
{
    struct FieldPlayer *player = func_02188CB4(encount->fieldMap);
    u32 attr;
    u16 attrFlags;
    u16 attrValue;

    func_02188C98(encount->fieldMap);
    *rateBonus = 0;
    attr = func_021A30C8(player);
    if (func_021AB100(attr) == 0)
        return 0xFF;
    attrFlags = func_021AB0F8(attr);
    if (triggerMode != 1 && (attrFlags & 4) == 0)
        return 0xFF;
    attrValue = func_021AB0F0(attr);
    if (func_021AB140(attrValue))
        *rateBonus += 10;
    if (attrFlags & 2) {
        if (triggerMode == 1)
            return 4;
        return 3;
    }
    if (triggerMode == 1)
        return 2;
    if (func_021AB29C(attrValue))
        return 1;
    return 0;
}

int func_021AA3E0(FieldEncount *encount, int encountType, int rateBonus)
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
int func_021AA3FC(FieldEncount *encount, EncountStepWork *stepWork, u32 rate)
{
    u32 steps;

    if (rate > 100)
        rate = 100;
    steps = func_021AA778(stepWork);
    if (steps == 0)
        return 0;
    if (steps == 1)
        rate = 1;
    if (func_021AA6E0() <= rate)
        return 1;
    return 0;
}

static inline fx32 FX_MUL(fx32 v1, fx32 v2)
{
    return (fx32)(((fx64)v1 * v2 + 0x800LL) >> 12);
}

/* White Forest rate: (steps - 1) * sqrt(resident count) * 4 percent. */
int func_021AA42C(EncountStepWork *stepWork, struct FieldWfbc *wfbc)
{
    int steps = func_021AA778(stepWork);
    int peopleCount = func_021938F4(wfbc);
    int roll = func_020056EC(100);
    fx32 peopleSqrt = func_0207C7B4(peopleCount << 12);
    fx32 chance = FX_MUL((steps - 1) << 12, peopleSqrt);
    chance = FX_MUL(chance, 0x4000);
    return (int)func_02010FB0((int)(chance >> 12)) > roll;
}

void func_021AA490(FieldEncount *encount, FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, EncountMon *mons)
{
    struct FieldSituation situation;
    struct Party *party = func_0201A920(heapId);
    struct PokemonParam *pp = func_02030734(heapId, func_020173EC(), 1, data_021DDFA4, 0x285);
    int i;

    for (i = 0; i < (u8)param->isDoubleBattle + 1; i++) {
        func_021A96B8(pp, param, &mons[i]);
        func_0201A98C(party, pp);
    }
    func_021AA304(&situation, encount->gameData, encount->fieldMap);
    func_0201347C(btlSetup, encount->gameData, party, &situation, param->isDoubleBattle, heapId);
    if (param->encountType == 1)
        func_02013144(btlSetup, 0x20);
    func_020307B0(pp);
    func_020307B0(party);
}

void func_021AA548(FieldEncount *encount, const FieldEncountParam *param, struct BattleSetupParam *btlSetup, u16 heapId, struct Roamer *roamer)
{
    struct FieldSituation situation;
    struct Party *party = func_0201A920(heapId);
    struct PokemonParam *pp = func_02030734((u16)((heapId & 0x7FFF) | 0x8000), func_020173EC(), 1, data_021DDFA4, 0x2A4);

    func_021A9780(pp, param, roamer);
    func_0201A98C(party, pp);
    func_021AA304(&situation, encount->gameData, encount->fieldMap);
    func_0201347C(btlSetup, encount->gameData, party, &situation, 0, heapId);
    func_02013144(btlSetup, 8);
    func_020307B0(pp);
    func_020307B0(party);
}

void func_021AA5CC(FieldEncount *encount, struct BattleSetupParam *btlSetup, u32 rule, u32 partnerId, u32 trainerId1, u32 trainerId2, u16 heapId)
{
    struct FieldSituation situation;
    struct GameData *gameData = encount->gameData;
    u32 trainerBgAttr;

    func_020130C4(btlSetup);
    func_021AA304(&situation, encount->gameData, encount->fieldMap);
    trainerBgAttr = func_0202A420(func_0202A230(trainerId1, 1));
    if (trainerBgAttr != 0x11) {
        situation.bgAttr = trainerBgAttr;
    }
    switch (rule) {
    case 1:
        if (partnerId) {
            func_02013734(btlSetup, gameData, &situation, partnerId, trainerId1, trainerId2, heapId);
        } else {
            func_02013644(btlSetup, gameData, &situation, trainerId1, heapId);
        }
        return;
    case 0:
        if (trainerId2) {
            func_020136E0(btlSetup, gameData, &situation, trainerId1, trainerId2, heapId);
        } else {
            func_02013610(btlSetup, gameData, &situation, trainerId1, heapId);
        }
        return;
    case 2:
        func_02013678(btlSetup, gameData, &situation, trainerId1, heapId);
        return;
    case 3:
        func_020136AC(btlSetup, gameData, &situation, trainerId1, heapId);
        return;
    }
}

/* Battle weather for the field weather. */
u8 func_021AA69C(struct FieldMap *fieldMap)
{
    switch (func_021A1BF4(func_02188C6C(fieldMap))) {
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

u32 func_021AA6E0(void)
{
    return func_0209C2B0(func_020056EC(0xFFFF), 0x290);
}

void func_021AA6F8(EncountStepWork *stepWork, struct FieldPlayer *player)
{
    struct Mmdl *mmdl = func_021A3074(player);

    MI_CpuFill8(stepWork, 0, sizeof(*stepWork));
    stepWork->x = func_0216D83C(mmdl);
    stepWork->y = func_0216D854(mmdl);
    stepWork->z = func_0216D86C(mmdl);
}

void func_021AA728(EncountStepWork *stepWork, struct FieldPlayer *player)
{
    struct Mmdl *mmdl = func_021A3074(player);

    if (stepWork->moved != 0) {
        if (stepWork->stepCount < 0xA000)
            stepWork->stepCount++;
        return;
    }
    if (stepWork->x != func_0216D83C(mmdl) || stepWork->y != func_0216D854(mmdl) || stepWork->z != func_0216D86C(mmdl)) {
        stepWork->moved = 1;
        stepWork->stepCount++;
    }
}

u32 func_021AA778(EncountStepWork *stepWork)
{
    return stepWork->stepCount;
}
