/*
 * file:     unit_021D794C.c
 * unit:     yes
 * function: BTL_CALC_GetTypeAffinity, BTL_CALC_GetTypeAffinityVsPair, BTL_CALC_CombineTypeAffinity, BTL_CALC_CalcBaseDamage, BTL_CALC_ApplyTypeAffinity, BTL_CALC_ListResistingTypes, BTL_CALC_SummarizeTypeAffinity, BTL_CALC_RollPercent, BTL_CALC_Max, BTL_CALC_MulRatio, BTL_CALC_MulRatioMin1, BTL_CALC_MulPercent, BTL_CALC_DivideMaxHp, BTL_CALC_DivideMaxHpMin1, BTL_CALC_RandRange, BTL_CALC_RollHitCount, BTL_CALC_GetWeatherDamage, BTL_CALC_GetWeatherMoveRatio, BTL_CALC_MakeSickContFromSpec, BTL_CALC_MakeDefaultSickCont, BTL_CALC_HasDefaultSickCont, BTL_CALC_MakeSickContTurns, BTL_CALC_MakeSickContPoke, BTL_CALC_MakeSickContFromKind, BTL_CALC_FindMajorSick
 * address:  0x021D794C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C9E4  0x0689C9E4  thumb
 *   gBtlCalcTypeAffinityTable  0x021F047C  data  ov093  a1
 *   BTLV_CORE_SplitBytes  0x021E8D0C  thumb  ov093
 *   BTLV_CORE_BytesEqual  0x021E8DA8  thumb  ov093
 *   gBtlCalcAffinityScales  0x021F0427  data  ov093  a1
 *   _u32_div_f 0x0209C2B0 arm
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   gBtlCalcHitCountThresholds 0x021F0421 data a1
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1  0x021E89F8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind4  0x021E8A28  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 */
#include "unit_021D794C_types.h"

struct BtlPokeParam;

extern void BTLV_CORE_SplitBytes(int packedTypes, u8 *firstType, u8 *secondType);
extern int BTLV_CORE_BytesEqual(int packedTypes);
extern u32 BTL_CALC_Random(u32 range);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern u32 _u32_div_f(u32, u32);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int type);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *bpp);
extern union BtlSickCont BTLV_CORE_MakeSlotKind3(u32 pokeId);
extern union BtlSickCont BTLV_CORE_MakeSlotKind2Index(u8 turns);
extern union BtlSickCont BTLV_CORE_MakeSlotKind1(u8 high, u32 low);
extern union BtlSickCont BTLV_CORE_MakeSlotKind4(u32 pokeId, u8 turns);
extern union BtlSickCont BTLV_CORE_MakeSlotKind1Empty(void);
extern int func_0689C9E4(int index);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sick);
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
/* Type affinity table [attacker][defender]: 0 none, 2 half, 4 normal, 8 double. */
extern u8 gBtlCalcTypeAffinityTable[17][17];
/* Affinity class -> scale (0, 1, 2, 4, 8, 16) used to combine two classes. */
extern u8 gBtlCalcAffinityScales[];
/* Cumulative percent thresholds for a random hit count (2 to 5 hits). */
extern u8 gBtlCalcHitCountThresholds[6];


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
u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *bpp, u32 divisor) { return (u32)func_021D59B4(bpp,BTL_BPP_VALUE_MAX_HP)/divisor; }


/*
 * Maximum HP divided by the divisor, at least 1.
 * Recursive MATCH unblocker: named callee of the parked ov093 BTL_HANDLER_ITEM_RockyHelmetDamageReaction
 * (the `BTL_CALC_DivideMaxHpMin1(func_021C7CF4(b, k), (u8)BTL_HANDLER_ITEM_GetParam(a,2))` halfword).
 * Runs func_021D59B4(a, 0xe) through the unsigned divide entry 0x0209C2B0
 * (`_u32_div_f`, see docs/notes/unsigned-divide-entry-is-0209c2b0.c.txt) and
 * floors a zero quotient at 1.
 *
 * Addresses are Black-image addresses.
 */
int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor)
{
    u32 result = func_021D59B4(bpp, BTL_BPP_VALUE_MAX_HP);

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
    damage = func_021D59B4(bpp, BTL_BPP_VALUE_MAX_HP) / 16;
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
int BTL_CALC_FindMajorSick(struct BtlPokeParam *bpp) { int sick; int index=0; for (;;) { sick=func_0689C9E4(index++); if(sick==0) return sick; if(BTL_POKEPARAM_HasSick(bpp,sick)) return sick; } }
