/*
 * file:     btl_calc.c
 * unit:     yes
 * function: BTL_CALC_Init, BTL_CALC_SetRngState, BTL_CALC_Exit, BTL_CALC_Random, BTL_CALC_ApplyStatStage, BTL_CALC_ApplyAccuracyStage, BTL_CALC_RollCriticalHit, BTL_CALC_GetTypeAffinity, BTL_CALC_GetTypeAffinityVsPair, BTL_CALC_CombineTypeAffinity, BTL_CALC_CalcBaseDamage, BTL_CALC_ApplyTypeAffinity, BTL_CALC_ListResistingTypes, BTL_CALC_SummarizeTypeAffinity, BTL_CALC_RollPercent, BTL_CALC_Max, BTL_CALC_MulRatio, BTL_CALC_MulRatioMin1, BTL_CALC_MulPercent, BTL_CALC_DivideMaxHp, BTL_CALC_DivideMaxHpMin1, BTL_CALC_RandRange, BTL_CALC_RollHitCount, BTL_CALC_GetWeatherDamage, BTL_CALC_GetWeatherMoveRatio, BTL_CALC_MakeSickContFromSpec, BTL_CALC_MakeDefaultSickCont, BTL_CALC_HasDefaultSickCont, BTL_CALC_MakeSickContTurns, BTL_CALC_MakeSickContPoke, BTL_CALC_MakeSickContFromKind, BTL_CALC_FindMajorSick, BTL_CALC_PickRandomMoveExcluding, BTL_CALC_ContainsU16, BTL_CALC_CalcDefeatExp, BTL_CALC_IsMultiFighterRule, BTL_CALC_GetFightersPerSide, BTL_CALC_GetScanStartIndex, BTL_CALC_IsGymLeaderTrainer, BTL_CALC_IsEliteFourTrainer, BTL_CALC_IsBossTrainer, BTL_CALC_CalcPrizeMoney, BTL_CALC_CalcTrainerPrizeMoney, BTL_CALC_CalcDefeatMoneyLoss, BTL_CALC_SetHeapId, BTL_CALC_NoOp, BTL_CALC_GetItemParam, BTL_CALC_PackPokeIds, BTL_CALC_UnpackPokeIds, BTL_CALC_GetCurseTargetKind, BTL_CALC_DecideMoveTarget, BTL_CALC_PeekMoveTarget, BTL_CLIENT_SET_Clear, BTL_CLIENT_SET_Add, BTL_CLIENT_SET_GetCount, BTL_CLIENT_SET_JudgeResult
 * address:  0x021D7840
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from btl_calc.c, btl_action_word.c, hand_tokusei.c by tools/splitfile.py.
 *
 * symbols:
 *   gBtlCalcFileName 0x021F3AB8 data a1
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   gBtlCalcWork  0x021F6360  data  ov093
 *   gBtlStatStageRatios 0x021F0448 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   gBtlCalcAccuracyStageRatios 0x021F0462 data a1
 *   _s32_div_f 0x0209C0A4 arm
 *   gBtlCalcCriticalRanges 0x021F041C data a1
 *   BTL_ID_GetItemCuredSick  0x0689C9E4  thumb
 *   gBtlCalcTypeAffinityTable  0x021F047C  data  ov093  a1
 *   BTLV_CORE_SplitBytes  0x021E8D0C  thumb  ov093
 *   BTLV_CORE_BytesEqual  0x021E8DA8  thumb  ov093
 *   gBtlCalcAffinityScales  0x021F0427  data  ov093  a1
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 *   gBtlCalcHitCountThresholds 0x021F0421 data a1
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1  0x021E89F8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind4  0x021E8A28  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   POKE_TOOL_GetPersonalParam  0x02019C90  thumb
 *   TPOKE_DATA_GetTrainerKind 0x0202A3FC thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   TPOKE_DATA_GetRecordField 0x0202A230 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 *   gBtlCalcDefeatMoneyScales     0x021F042D  data  ov093  a1
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
 *   BTL_MAIN_GetRule  0x021B8588  thumb  ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke  0x021B8D8C  thumb  ov093
 *   WAZA_TOOL_GetParam   0x0201BD28  thumb
 *   WAZA_TOOL_GetFlag   0x0201BEB8  thumb
 *   BTL_MAIN_GetEnemyLanePosFromWork  0x021B8C50  thumb  ov093
 *   BTL_MAIN_CollectLivingPokeIds  0x021B8D38  thumb  ov093
 *   BTL_MAIN_DecodeMessageCode  0x021B8778  thumb  ov093
 *   BTL_MAIN_IsSameTeamClient  0x021B902C  thumb
 *   BTL_CALC_RollPercent 0x021D7AF0 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   BTL_CALC_HasDefaultSickCont 0x021D7D6C thumb ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont 0x021D7D18 thumb ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   BTL_CALC_Random   0x021D78AC  thumb ov093
 *   BTL_CALC_GetTypeAffinityVsPair   0x021D799C  thumb ov093
 *   BTL_CALC_Max   0x021D7B08  thumb ov093
 *   BTL_CALC_FindMajorSick  0x021D7E10  thumb  ov093
 */
#include "btl_calc_types.h"
#include "../arm9/btl_setup_types.h"
#include "btl_main_types.h"

struct BtlParty;

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);

extern u32 func_020307B0(void *p);

extern unsigned int _u32_div_f(unsigned int, unsigned int);

extern int _s32_div_f(int numerator, int denominator);

extern void BTLV_CORE_SplitBytes(int packedTypes, u8 *firstType, u8 *secondType);

extern int BTLV_CORE_BytesEqual(int packedTypes);

extern int BTL_POKEPARAM_GetValue(struct BtlPokeParam *bpp, int valueId);

extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int type);

extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *bpp);

extern union BtlSickCont BTLV_CORE_MakeSlotKind3(u32 pokeId);

extern union BtlSickCont BTLV_CORE_MakeSlotKind2Index(u8 turns);

extern union BtlSickCont BTLV_CORE_MakeSlotKind1(u8 high, u32 low);

extern union BtlSickCont BTLV_CORE_MakeSlotKind4(u32 pokeId, u8 turns);

extern union BtlSickCont BTLV_CORE_MakeSlotKind1Empty(void);

extern int BTL_ID_GetItemCuredSick(int index);

extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sick);

u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);

u32 POKE_TOOL_GetPersonalParam(u16 species, u16 form, u32 paramId);

extern u8 TPOKE_DATA_GetTrainerKind(u32 trainerId);

extern u32 POKEPARTY_GetCount(struct Party *party);

extern void *POKEPARTY_GetMember(struct Party *party, u32 index);

extern u32 TPOKE_DATA_GetRecordField(u32 trainerId, u32 paramIndex);

extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 valueId, u32 arg);

u8 BTL_SLOT_GetCount(struct BtlParty *party);

extern struct BtlPokeParam *BTL_SLOT_GetPokeParam(struct BtlParty *party, u32 index);

extern u32 FILE_UTIL_Get_0FE4(void *mon, u32 paramId, u32 heapId);

extern u32 BTL_MAIN_GetRule(void *main);

extern int BTL_MAIN_GetTrainerSlotOfPoke(void *main, void *posTable, u32 pokeId);

extern u32 WAZA_TOOL_GetParam(u16 moveId, u32 fieldIndex);

extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 bit);

extern u8 BTL_MAIN_GetEnemyLanePosFromWork(void *main, u32 basePos, int lane);

extern u8 BTL_MAIN_CollectLivingPokeIds(void *main, void *posTable, int posCode, u8 *outPokeIds);

extern u8 BTL_MAIN_DecodeMessageCode(void *main, int posCode, u8 *outPositions);

extern int BTL_MAIN_IsSameTeamClient(int clientId, int otherClientId);

void BTL_CALC_Init(const BtlRngState *rng, unsigned int heapId);

void BTL_CALC_SetRngState(const BtlRngState *rng);

void BTL_CALC_Exit(void);

u32 BTL_CALC_Random(u32 range);

unsigned short BTL_CALC_ApplyStatStage(unsigned short stat, int stage);

u8 BTL_CALC_ApplyAccuracyStage(int accuracy, int stage);

int BTL_CALC_RollCriticalHit(int critStage);

int BTL_CALC_GetTypeAffinity(int atkType, int defType);

int BTL_CALC_GetTypeAffinityVsPair(int atkType, int defTypes);

int BTL_CALC_CombineTypeAffinity(int affinityA, int affinityB);

u32 BTL_CALC_CalcBaseDamage(u32 power, u32 attack, u32 level, u32 defense);

u32 BTL_CALC_ApplyTypeAffinity(u32 damage, u32 affinity);

u8 BTL_CALC_ListResistingTypes(int atkType, u8 *outTypes);

int BTL_CALC_SummarizeTypeAffinity(int affinity);

int BTL_CALC_RollPercent(u32 percent);

int BTL_CALC_Max(int value, int floor);

u32 BTL_CALC_MulRatio(u32 value, u32 ratio);

u32 BTL_CALC_MulRatioMin1(u32 value, u32 ratio);

u32 BTL_CALC_MulPercent(u32 value, u32 percent);

u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor);

int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);

u32 BTL_CALC_RandRange(u32 min, u32 max);

int BTL_CALC_RollHitCount(int maxHits);

int BTL_CALC_GetWeatherDamage(struct BtlPokeParam *bpp, int weather);

u32 BTL_CALC_GetWeatherMoveRatio(int weather, int moveType);

void BTL_CALC_MakeSickContFromSpec(struct BtlSickContSpec spec, struct BtlPokeParam *attacker, union BtlSickCont *out);

union BtlSickCont BTL_CALC_MakeDefaultSickCont(int kind);

int BTL_CALC_HasDefaultSickCont(int kind);

union BtlSickCont BTL_CALC_MakeSickContTurns(u32 turns);

union BtlSickCont BTL_CALC_MakeSickContPoke(u32 pokeId);

void BTL_CALC_MakeSickContFromKind(int kind, struct BtlPokeParam *attacker, union BtlSickCont *out);

int BTL_CALC_FindMajorSick(struct BtlPokeParam *bpp);

u16 BTL_CALC_PickRandomMoveExcluding(const u16 *excludedMoves, int excludedCount);

int BTL_CALC_ContainsU16(const u16 *list,u32 count,u32 value);

u32 BTL_CALC_CalcDefeatExp(struct BtlPokeParam *bpp);

u32 BTL_CALC_IsMultiFighterRule(u32 rule);

u32 BTL_CALC_GetFightersPerSide(u32 rule);

u8 BTL_CALC_GetScanStartIndex(u32 rule, u8 startIndex);

int BTL_CALC_IsGymLeaderTrainer(u32 trainerId);

int BTL_CALC_IsEliteFourTrainer(u32 trainerId);

int BTL_CALC_IsBossTrainer(u32 trainerId);

u32 BTL_CALC_CalcPrizeMoney(struct BattleSetupParam *setup);

u32 BTL_CALC_CalcTrainerPrizeMoney(struct BattleTrainerData *trainer,struct Party *party);

u32 BTL_CALC_CalcDefeatMoneyLoss(u32 badgeCount, struct BtlParty *party);

void BTL_CALC_SetHeapId(u32 heapId);

void BTL_CALC_NoOp(void);

u32 BTL_CALC_GetItemParam(void *itemId,u32 paramId);

u32 BTL_CALC_PackPokeIds(const u8 *pokeIds);

void BTL_CALC_UnpackPokeIds(u32 packed,u8 *pokeIds);

int BTL_CALC_GetCurseTargetKind(struct BtlPokeParam *bpp);

int BTL_CALC_DecideMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId);

int BTL_CALC_PeekMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId, BtlRngState *savedRng);

void BTL_CLIENT_SET_Clear(struct BtlClientSet *set);

void BTL_CLIENT_SET_Add(struct BtlClientSet *set, int clientId);

u32 BTL_CLIENT_SET_GetCount(struct BtlClientSet *set);

int BTL_CLIENT_SET_JudgeResult(struct BtlClientSet *set, u8 localClientId, u32 rule);

extern struct BtlCalcWork gBtlCalcWork;

extern const unsigned char gBtlCalcFileName[];

extern unsigned char gBtlStatStageRatios[][2];

extern const u8 gBtlCalcAccuracyStageRatios[][2];

extern const u8 gBtlCalcCriticalRanges[];

/* Type affinity table [attacker][defender]: 0 none, 2 half, 4 normal, 8 double. */
extern u8 gBtlCalcTypeAffinityTable[17][17];

/* Affinity class -> scale (0, 1, 2, 4, 8, 16) used to combine two classes. */
extern u8 gBtlCalcAffinityScales[];

/* Cumulative percent thresholds for a random hit count (2 to 5 hits). */
extern u8 gBtlCalcHitCountThresholds[6];

/* Money lost on defeat per level point, by badge count (0 to 8). */
extern u8 gBtlCalcDefeatMoneyScales[];

void BTL_CALC_Init(const BtlRngState *rng, unsigned int heapId) { gBtlCalcWork.workTable=func_02030734(heapId,0x460,1,(const char *)gBtlCalcFileName,0x50); gBtlCalcWork.rng=*rng; }

void BTL_CALC_SetRngState(const BtlRngState *rng) { gBtlCalcWork.rng = *rng; }

void BTL_CALC_Exit(void) { if (gBtlCalcWork.workTable) { func_020307B0(gBtlCalcWork.workTable); gBtlCalcWork.workTable = 0; } }

u32 BTL_CALC_Random(u32 range)
{
    struct BtlCalcWork *work = &gBtlCalcWork;
    u32 value;

    work->rng.seed = work->rng.mul * work->rng.seed + work->rng.add;
    if (range == 0) {
        value = (u32)(work->rng.seed >> 32);
    } else {
        value = (u32)(((work->rng.seed >> 32) * range) >> 32);
    }
    return value;
}

unsigned short BTL_CALC_ApplyStatStage(unsigned short stat, int stage) { return _u32_div_f((unsigned short)(stat*gBtlStatStageRatios[stage][0]), gBtlStatStageRatios[stage][1]); }

/* Scales accuracy by the ratio of an accuracy stage (numerator, denominator); the result is at most 100. */
u8 BTL_CALC_ApplyAccuracyStage(int accuracy, int stage)
{
    u32 scaled = _s32_div_f(accuracy * gBtlCalcAccuracyStageRatios[stage][0], gBtlCalcAccuracyStageRatios[stage][1]);
    if (scaled > 100) scaled = 100;
    return scaled;
}

/* A critical hit lands when a roll below the stage's range comes up 0. */
int BTL_CALC_RollCriticalHit(int critStage)
{
    if ((u8)BTL_CALC_Random(gBtlCalcCriticalRanges[critStage]) == 0) return 1;
    return 0;
}

/* Type affinity class of an attack type against one defender type. */
int BTL_CALC_GetTypeAffinity(int atkType, int defType)
{
    if (atkType == BTL_TYPE_NONE || defType == BTL_TYPE_NONE)
        return BTL_AFF_NORMAL;
    switch (gBtlCalcTypeAffinityTable[atkType][defType]) {
    case 0:
        return BTL_AFF_NONE;
    case 2:
        return BTL_AFF_HALF;
    case 4:
        return BTL_AFF_NORMAL;
    case 8:
        return BTL_AFF_DOUBLE;
    default:
        return BTL_AFF_NONE;
    }
}

/* Type affinity class of an attack type against a defender with one or two types. */
int BTL_CALC_GetTypeAffinityVsPair(int atkType, int defTypes)
{
    u8 types[2];
    int firstAffinity;

    BTLV_CORE_SplitBytes(defTypes, &types[1], &types[0]);
    if (BTLV_CORE_BytesEqual(defTypes))
        return BTL_CALC_GetTypeAffinity(atkType, types[1]);
    firstAffinity = BTL_CALC_GetTypeAffinity(atkType, types[1]);
    return BTL_CALC_CombineTypeAffinity(firstAffinity, BTL_CALC_GetTypeAffinity(atkType, types[0]));
}

/*
 * Combines two affinity classes into one (half and half give quarter, double
 * and double give quadruple).
 * note:     a plain switch with case 16 after case 8 (mwcc tables 0..8 and compares 16 in
 *           the default path); the u32 switch value gives the unsigned `bhi` range check.
 */
int BTL_CALC_CombineTypeAffinity(int affinityA, int affinityB)
{
    u32 scale = gBtlCalcAffinityScales[affinityA] * gBtlCalcAffinityScales[affinityB] / 4;

    switch (scale) {
    case 0:
        return BTL_AFF_NONE;
    case 1:
        return BTL_AFF_QUARTER;
    case 2:
        return BTL_AFF_HALF;
    case 4:
        return BTL_AFF_NORMAL;
    case 8:
        return BTL_AFF_DOUBLE;
    case 16:
        return BTL_AFF_QUADRUPLE;
    }
    return BTL_AFF_NONE;
}

/* Base damage: (power * attack * (2 * level / 5 + 2) / defense) / 50 + 2. */
u32 BTL_CALC_CalcBaseDamage(u32 power, u32 attack, u32 level, u32 defense) { return (power*attack*(2*level/5+2)/defense)/50+2; }

/* Scales a damage value by an affinity class (none, quarter, half, normal, double, quadruple). */
u32 BTL_CALC_ApplyTypeAffinity(u32 damage, u32 affinity) { switch(affinity) { case 0:return 0; case 1:return damage/4; case 2:return damage/2; case 3:return damage; case 4:return damage*2; case 5:return damage*4; } return damage; }

/* Lists the defender types that an attack type does not affect or hits for half; returns how many. */
u8 BTL_CALC_ListResistingTypes(int atkType, u8 *outTypes) { u8 count,defType; defType=0; count=0; do { if(gBtlCalcTypeAffinityTable[atkType][defType]==0 || gBtlCalcTypeAffinityTable[atkType][defType]==2) outTypes[count++]=defType; ++defType; } while(defType<17); return count; }

/* Reduces an affinity class to none (0), normal (1), advantage (2) or disadvantage (3). */
int BTL_CALC_SummarizeTypeAffinity(int affinity) { if(affinity>3) return 2; if(affinity==3) return 1; if(affinity!=0) return 3; return 0; }

/* True when a percent roll (0..99) falls under the given percent. */
int BTL_CALC_RollPercent(u32 percent)
{
    if (BTL_CALC_Random(100) < percent) return 1;
    return 0;
}

/* 021D7B08  cmp r0,r1; bge; adds r0,r1,#0 */
/*
 * Larger of two values. Leaf with no calls and no pool; 4 instructions, 8 bytes: cmp r0, r1; bge loc_021D7B0E; adds r0, r1, #0; bx lr.
 */
int BTL_CALC_Max(int value, int floor)
{
    if (value < floor)
        value = floor;
    return value;
}

/*
 * 2026-10-03 (wave B3 lane 10): EXACT. Rounded 20.12 product (half rounds down).
 * The product, the shift and the increment all reuse the parameter value; with
 * a separate product local mwcc copies an operand to r2 first (adds r2,r0,#0; muls).
 * See docs/idioms/a-product-kept-in-its-parameter-multiplies-in-place.md.
 */
u32 BTL_CALC_MulRatio(u32 value, u32 ratio)
{
    u32 fraction;

    value *= ratio;
    fraction = value & 0xfff;
    value >>= 12;
    if (fraction > 0x800)
        value++;
    return value;
}

/* Same product as above, at least 1. */
u32 BTL_CALC_MulRatioMin1(u32 value, u32 ratio) { u32 result=BTL_CALC_MulRatio(value,ratio); if(result==0) result=1; return result; }

/* Value times percent / 100, rounded half up. */
u32 BTL_CALC_MulPercent(u32 value, u32 percent) { u32 remainder; value*=percent; remainder=value%100; value/=100; if(remainder>=50) ++value; return value; }

/* Maximum HP divided by the divisor. */
u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor) { return (u32)BTL_POKEPARAM_GetValue(bpp,BTL_BPP_VALUE_MAX_HP)/divisor; }

/*
 * Maximum HP divided by the divisor, at least 1.
 * Recursive MATCH unblocker: named callee of the parked ov093 HAND_ITEM_RockyHelmetDamageReaction
 * (the `BTL_CALC_DivideMaxHpMin1(BTL_SERVER_FLOW_GetPokeParam(b, k), (u8)HAND_ITEM_GetParam(a,2))` halfword).
 * Runs BTL_POKEPARAM_GetValue(a, 0xe) through the unsigned divide entry 0x0209C2B0
 * (`_u32_div_f`, see docs/notes/unsigned-divide-entry-is-0209c2b0.c.txt) and
 * floors a zero quotient at 1.
 *
 * Addresses are Black-image addresses.
 */
int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor)
{
    u32 result = BTL_POKEPARAM_GetValue(bpp, BTL_BPP_VALUE_MAX_HP);

    result = result / divisor;
    if (result == 0)
        result = 1;
    return result;
}

/* Random value from min to max, both included (swaps them when reversed). */
u32 BTL_CALC_RandRange(u32 min, u32 max)
{
    u32 swap;
    if (min > max) {
        swap = min;
        min = max;
        max = swap;
    }
    return min + BTL_CALC_Random(max - min + 1);
}

/* Number of hits of a multi-hit move: the fixed count, or 2 to 5 hits when the maximum is 5. */
int BTL_CALC_RollHitCount(int maxHits) { u8 roll,hits; if(maxHits!=5) return maxHits; roll=BTL_CALC_Random(100); for(hits=0;hits<6;++hits) { if(roll<gBtlCalcHitCountThresholds[hits]) return hits; } return maxHits; }

/* Weather damage at turn end: one sixteenth of maximum HP (at least 1), 0 for immune types. */
int BTL_CALC_GetWeatherDamage(struct BtlPokeParam *bpp, int weather)
{
    u16 damage;

    switch (weather) {
    case BTL_WEATHER_SAND:
        if (BTL_POKEPARAM_HasType(bpp, BTL_TYPE_ROCK) != 0) return 0;
        if (BTL_POKEPARAM_HasType(bpp, BTL_TYPE_STEEL) != 0) return 0;
        if (BTL_POKEPARAM_HasType(bpp, BTL_TYPE_GROUND) != 0) return 0;
        break;
    case BTL_WEATHER_HAIL:
        if (BTL_POKEPARAM_HasType(bpp, BTL_TYPE_ICE) != 0) return 0;
        break;
    default:
        return 0;
    }
    damage = BTL_POKEPARAM_GetValue(bpp, BTL_BPP_VALUE_MAX_HP) / 16;
    if (damage == 0) damage = 1;
    return damage;
}

/* Damage ratio (20.12) of a move type in the weather: fire and water swap 1.5 and 0.5 in sun and rain. */
u32 BTL_CALC_GetWeatherMoveRatio(int weather, int moveType) { switch(weather) { case BTL_WEATHER_SUN: if(moveType==BTL_TYPE_FIRE) return 6144; if(moveType==BTL_TYPE_WATER) return 2048; break; case BTL_WEATHER_RAIN: if(moveType==BTL_TYPE_FIRE) return 2048; if(moveType==BTL_TYPE_WATER) return 6144; break; } return 4096; }

/* Builds the volatile-condition record that a move's data describes. */
void BTL_CALC_MakeSickContFromSpec(struct BtlSickContSpec spec, struct BtlPokeParam *attacker, union BtlSickCont *out)
{
    u8 pokeId;
    u8 turns;

    switch (spec.kind) {
    case 3:
        *out = BTLV_CORE_MakeSlotKind3(BTL_POKEPARAM_GetPokeId(attacker));
        break;
    case 2:
        turns = BTL_CALC_RandRange(spec.turnMin, spec.turnMax);
        *out = BTLV_CORE_MakeSlotKind2Index(turns);
        break;
    case 1:
        *out = BTLV_CORE_MakeSlotKind1(spec.turnMax, spec.turnMin);
        break;
    case 4:
        pokeId = BTL_POKEPARAM_GetPokeId(attacker);
        turns = BTL_CALC_RandRange(spec.turnMin, spec.turnMax);
        *out = BTLV_CORE_MakeSlotKind4(pokeId, turns);
        break;
    case 0:
    default:
        break;
    }
}

/* Default record of a condition kind: 1, 3, 4 and 5 are permanent, 2 lasts 2 to 4 turns. */
union BtlSickCont BTL_CALC_MakeDefaultSickCont(int kind)
{
    union BtlSickCont sickCont;
    sickCont.raw = 0;
    switch (kind) {
    case 1:
    case 3:
    case 4:
    case 5:
        sickCont.byPart.kind = 1;
        break;
    case 2:
        sickCont.byPart.kind = 2;
        sickCont.byPart.paramLow = BTL_CALC_RandRange(2, 4);
        break;
    case 0:
    default:
        sickCont.byPart.kind = 0;
        break;
    }
    return sickCont;
}

/* 021D7D6C  cmp r0,#6; bge; movs r0,#1; bx lr; movs r0,#0; bx lr */
/* True for the kinds that have a default record (below 6). */
int BTL_CALC_HasDefaultSickCont(int kind)
{
    if (kind < 6)
        return 1;
    return 0;
}

/* Record that lasts the given number of turns. */
union BtlSickCont BTL_CALC_MakeSickContTurns(u32 turns) { union BtlSickCont sickCont; sickCont.raw=0; sickCont.byPart.kind=2; sickCont.byPart.paramLow=turns; return sickCont; }

/* Record tied to a Pokemon id. */
union BtlSickCont BTL_CALC_MakeSickContPoke(u32 pokeId) { union BtlSickCont sickCont; sickCont.raw=0; sickCont.byPart.kind=3; sickCont.byPart.paramLow=pokeId; return sickCont; }

/* Builds a condition record from a condition kind: default record, the attacker's id, or 2 to 5 turns. */
void BTL_CALC_MakeSickContFromKind(int kind, struct BtlPokeParam *attacker, union BtlSickCont *out)
{
    u8 turns;

    if (kind < 6) {
        *out = BTL_CALC_MakeDefaultSickCont(kind);
        return;
    }
    out->raw = 0;
    switch (kind) {
    case 7:
        *out = BTLV_CORE_MakeSlotKind3(BTL_POKEPARAM_GetPokeId(attacker));
        break;
    case 6:
        turns = BTL_CALC_RandRange(2, 5);
        *out = BTLV_CORE_MakeSlotKind2Index(turns);
        break;
    default:
        *out = BTLV_CORE_MakeSlotKind1Empty();
        break;
    }
}

/*
 * The first major status condition the Pokemon has (0 when none).
 * lever: declare sick before index; both exits return sick to retain r0 on the zero path.
 * extent: trailing two-byte alignment before Thumb-to-ARM veneer 021D7E34.
 */
int BTL_CALC_FindMajorSick(struct BtlPokeParam *bpp) { int sick; int index=0; for (;;) { sick=BTL_ID_GetItemCuredSick(index++); if(sick==0) return sick; if(BTL_POKEPARAM_HasSick(bpp,sick)) return sick; } }

/* Number of move ids (0 is not a move). */
#define BTL_MOVE_ID_LIMIT 0x230

/* BattleSetupParam.competitor value of a trainer battle. */
#define BTL_COMPETITOR_TRAINER 1

/* Argument index of the money rate in the trainer record reader. */
#define TRAINER_PARAM_MONEY_RATE 10

/* Value id of the level in the Pokemon value reader. */
#define POKE_VALUE_LEVEL 158

/* A random move id that is not in the given list (the move id table is the work table). */
u16 BTL_CALC_PickRandomMoveExcluding(const u16 *excludedMoves, int excludedCount)
{
    u16 moveId;
    u16 count = 0;

    for (moveId = 1; moveId < BTL_MOVE_ID_LIMIT; moveId++) {
        if (BTL_CALC_ContainsU16(excludedMoves, excludedCount, moveId) == 0)
            gBtlCalcWork.workTable[count++] = moveId;
    }
    return gBtlCalcWork.workTable[(u16)BTL_CALC_Random(count)];
}

/* True when the value is in the list of halfwords. */
int BTL_CALC_ContainsU16(const u16 *list,u32 count,u32 value) { u32 index; for(index=0;index<count;index++) { if(value==list[index]) return 1; } return 0; }

/* Experience a defeated Pokemon gives: base experience * level / 5. */
u32 BTL_CALC_CalcDefeatExp(struct BtlPokeParam *bpp)
{
    int species = BTL_POKEPARAM_GetSpecies(bpp);
    u16 form = BTL_POKEPARAM_GetValue(bpp, BTL_BPP_VALUE_FORM);
    u16 level = BTL_POKEPARAM_GetValue(bpp, BTL_BPP_VALUE_LEVEL);
    u32 baseExp = POKE_TOOL_GetPersonalParam(species, form, 9);
    return (baseExp * level) / 5;
}

/*
 * True for the rules with several fighters per side that are not rotation (double, triple).
 * lever: nonzero/non-3 conjunction puts return 1 before the return 0 arm.
 * leaf: only-blocker of ov093 021CEA94; parent expanded scope.
 * semantics: original compares full-word r0 with 0 and 3; no arithmetic,
 * domain bounds, narrowed input, uninitialized values or side effects.
 */
u32 BTL_CALC_IsMultiFighterRule(u32 rule)
{
    if (rule != BTL_RULE_SINGLE && rule != BTL_RULE_ROTATION) return 1;
    return 0;
}

/* Number of Pokemon that fight at once on one side: 1, 2, 3, and 1 for rotation. */
u32 BTL_CALC_GetFightersPerSide(u32 rule) { switch(rule) { case BTL_RULE_SINGLE:return 1; case BTL_RULE_DOUBLE:return 2; case BTL_RULE_TRIPLE:return 3; case BTL_RULE_ROTATION:return 1; default:return 1; } }

/* First list index to scan: 3 in a rotation battle, else the given start. */
u8 BTL_CALC_GetScanStartIndex(u32 rule, u8 startIndex)
{
    if (rule == BTL_RULE_ROTATION)
        startIndex = 3;
    return startIndex;
}

/* Trainer table category 2 (guess: gym leader). */
int BTL_CALC_IsGymLeaderTrainer(u32 trainerId) { if(TPOKE_DATA_GetTrainerKind(trainerId)==2) return 1; return 0; }

/* Trainer table category 3 (guess: Elite Four). */
int BTL_CALC_IsEliteFourTrainer(u32 trainerId) { if(TPOKE_DATA_GetTrainerKind(trainerId)==3) return 1; return 0; }

/* A boss trainer: category 2 or 3, or trainer 89. */
int BTL_CALC_IsBossTrainer(u32 trainerId) { if(BTL_CALC_IsGymLeaderTrainer(trainerId)) return 1; if(BTL_CALC_IsEliteFourTrainer(trainerId)) return 1; return trainerId==89; }

/* Prize money of a trainer battle: the sum over the two enemy trainer slots (1 and 3). */
u32 BTL_CALC_CalcPrizeMoney(struct BattleSetupParam *setup) { u32 money=0; if(setup->competitor==BTL_COMPETITOR_TRAINER) { if(setup->trainerData[1] && setup->party[1]) money+=BTL_CALC_CalcTrainerPrizeMoney(setup->trainerData[1],setup->party[1]); if(setup->trainerData[3] && setup->party[3]) money+=BTL_CALC_CalcTrainerPrizeMoney(setup->trainerData[3],setup->party[3]); } return money; }

/* Prize money of one trainer: money rate * level of the last party member * 4. */
u32 BTL_CALC_CalcTrainerPrizeMoney(struct BattleTrainerData *trainer,struct Party *party) { u8 count; void *lastMon; u32 moneyRate; if(party) { count=(u8)POKEPARTY_GetCount(party); if(count) { lastMon=POKEPARTY_GetMember(party,count-1); moneyRate=TPOKE_DATA_GetRecordField(trainer->trainerId,TRAINER_PARAM_MONEY_RATE); return moneyRate*POKE_TOOL_GetPartyValue(lastMon,POKE_VALUE_LEVEL,0)*4; } } return 0; }

/* Money lost on defeat: badge table value * highest party level * 4. */
u32 BTL_CALC_CalcDefeatMoneyLoss(u32 badgeCount, struct BtlParty *party)
{
    u32 count = BTL_SLOT_GetCount(party);
    u32 maxLevel = 1;
    u32 index;
    u32 level;

    for (index = 0; index < count; index++) {
        level = BTL_POKEPARAM_GetValue(BTL_SLOT_GetPokeParam(party, (u8)index), BTL_BPP_VALUE_LEVEL);
        if (level > maxLevel)
            maxLevel = level;
    }
    if (badgeCount >= 9)
        badgeCount = 8;
    return gBtlCalcDefeatMoneyScales[badgeCount] * (maxLevel << 2);
}

/* Stores the heap id that the battle uses for temporary reads. */
void BTL_CALC_SetHeapId(u32 heapId) { gBtlCalcWork.heapId=heapId; }

void BTL_CALC_NoOp(void) { }

/* Reads one parameter of an item (the item id is passed as a pointer-sized value) with the stored heap id. */
u32 BTL_CALC_GetItemParam(void *itemId,u32 paramId) { return FILE_UTIL_Get_0FE4(itemId,paramId,gBtlCalcWork.heapId); }

/* Packs six Pokemon ids (5 bits each) into one word. */
u32 BTL_CALC_PackPokeIds(const u8 *pokeIds) { u32 packed=0; u32 index; for(index=0;index<6;index++) packed|=(pokeIds[index]&31)<<(index*5); return packed; }

/* Unpacks six Pokemon ids from a word. */
void BTL_CALC_UnpackPokeIds(u32 packed,u8 *pokeIds) { u32 index; for(index=0;index<6;index++) { pokeIds[index]=packed&31; packed>>=5; } }

/* Target kind that Curse uses: 7 (the user), or 0 for a ghost-type user. */
int BTL_CALC_GetCurseTargetKind(struct BtlPokeParam *bpp)
{
    int targetKind = 7;
    if (BTL_POKEPARAM_HasType(bpp, BTL_TYPE_GHOST)) targetKind = 0;
    return targetKind;
}

/*
 * Picks the target position of a move automatically: from the attacker's
 * position and the move's target kind, narrowed to a range code (range in the
 * high byte, position in the low byte), then a random position or Pokemon
 * from that range. 6 means no target.
 */
int BTL_CALC_DecideMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId)
{
    u32 rule;
    int posCode;
    u32 targetKind;
    u8 reachesFar;
    u8 candidates[8];
    u8 candidate;

    rule = BTL_MAIN_GetRule(main);
    posCode = BTL_MAIN_GetTrainerSlotOfPoke(main, posTable, BTL_POKEPARAM_GetPokeId(attacker));
    targetKind = WAZA_TOOL_GetParam(moveId, 0x1B);
    if (moveId == 0xAE) targetKind = BTL_CALC_GetCurseTargetKind(attacker);

    if (rule == BTL_RULE_SINGLE) {
        switch (targetKind) {
        case 0:
        case 3:
        case 4:
        case 5:
        case 9:
            return BTL_MAIN_GetEnemyLanePosFromWork(main, posCode, 0);
        case 1:
        case 7:
            return posCode;
        case 13:
        default:
            return 6;
        }
    }

    reachesFar = 0;
    if (rule == BTL_RULE_TRIPLE) reachesFar = WAZA_TOOL_GetFlag(moveId, 0xB);

    switch (targetKind) {
    case 0:
    case 3:
    case 9:
        if (reachesFar) posCode = (u16)(posCode | (6 << 8));
        else posCode = (u16)(posCode | (1 << 8));
        break;
    case 1:
        posCode = (u16)(posCode | (3 << 8));
        break;
    case 2:
        if (reachesFar) posCode = (u16)(posCode | (7 << 8));
        else posCode = (u16)(posCode | (4 << 8));
        break;
    case 7:
        return posCode;
    default:
        return 6;
    }

    /* candidate holds the number of Pokemon in range, then the index picked. */
    candidate = BTL_MAIN_CollectLivingPokeIds(main, posTable, posCode, candidates);
    if (candidate) {
        candidate = BTL_CALC_Random(candidate);
        return BTL_MAIN_GetTrainerSlotOfPoke(main, posTable, candidates[candidate]);
    }
    candidate = BTL_MAIN_DecodeMessageCode(main, posCode, candidates);
    if (candidate) return candidates[(u8)BTL_CALC_Random(candidate)];
    return 6;
}

/*
 * Picks a move's target like BTL_CALC_DecideMoveTarget, then puts the random number
 * state back, so the pick does not advance the battle's random numbers.
 * savedRng receives the state before the pick and is copied back afterwards.
 */
int BTL_CALC_PeekMoveTarget(void *main, void *posTable, struct BtlPokeParam *attacker, u16 moveId, BtlRngState *savedRng)
{
    int targetPos;

    *savedRng = gBtlCalcWork.rng;
    targetPos = BTL_CALC_DecideMoveTarget(main, posTable, attacker, moveId);
    gBtlCalcWork.rng = *savedRng;
    return targetPos;
}

/* Empties a set of client ids. */
void BTL_CLIENT_SET_Clear(struct BtlClientSet *set) { u32 index; for(index=0;index<4;index++) set->ids[index]=BTL_CLIENT_ID_NONE; set->count=0; }

/* Adds a client id to the set unless it is already there. */
void BTL_CLIENT_SET_Add(struct BtlClientSet *set, int clientId) { u32 index; for(index=0;index<4;index++) { if(set->ids[index]==clientId) return; if(set->ids[index]==BTL_CLIENT_ID_NONE) { set->ids[index]=clientId; ++set->count; return; } } }

/* 021D826C  ldr r0,[r0] */
/*
 * Number of clients in the set (the u32 field at offset 0).
 */
u32 BTL_CLIENT_SET_GetCount(struct BtlClientSet *set) { return set->count; }

/*
 * Result code from the set of defeated clients, as seen by the local client:
 * 3 when only its own team is in the set, 4 when only the other team is,
 * and for a mix 3 in single and double battles, else 2.
 */
int BTL_CLIENT_SET_JudgeResult(struct BtlClientSet *set, u8 localClientId, u32 rule)
{
    int foeDefeated = 0;
    int friendDefeated = 0;
    u32 index;
    for (index = 0; index < set->count; index++) {
        if (BTL_MAIN_IsSameTeamClient(set->ids[index], localClientId))
            friendDefeated = 1;
        else
            foeDefeated = 1;
    }
    if (friendDefeated && foeDefeated) {
        if (rule <= 1)
            return 3;
        return 2;
    }
    return friendDefeated ? 3 : 4;
}
