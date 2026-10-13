/*
 * file:     unit_021D794C.c
 * unit:     yes
 * function: func_021D794C, func_021D799C, func_021D79E8, func_021D7A44, func_021D7A6C, func_021D7A9C, func_021D7AD4, func_021D7AF0, func_021D7B08, func_021D7B10, func_021D7B2C, func_021D7B3C, func_021D7B60, func_021D7B74, func_021D7B8C, func_021D7BA4, func_021D7BD4, func_021D7C38, func_021D7C70, func_021D7D18, func_021D7D6C, func_021D7D78, func_021D7D9C, func_021D7DC0, func_021D7E10
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
 *   d_021F047C  0x021F047C  data  ov093  a1
 *   func_021E8D0C  0x021E8D0C  thumb  ov093
 *   func_021E8DA8  0x021E8DA8  thumb  ov093
 *   d_021F0427  0x021F0427  data  ov093  a1
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   d_021F0421 0x021F0421 data a1
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021E899C  0x021E899C  thumb  ov093
 *   func_021E8940  0x021E8940  thumb  ov093
 *   func_021E89F8  0x021E89F8  thumb  ov093
 *   func_021E8A28  0x021E8A28  thumb  ov093
 *   func_021E89C0  0x021E89C0  thumb  ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 */
#include "unit_021D794C_types.h"

struct BtlPokeParam;

extern void func_021E8D0C(int packedTypes, u8 *firstType, u8 *secondType);
extern int func_021E8DA8(int packedTypes);
extern u32 func_021D78AC(u32 range);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern u32 _u32_div_f(u32, u32);
extern int func_021D5814(struct BtlPokeParam *bpp, int type);
extern u8 func_021D5440(struct BtlPokeParam *bpp);
extern union BtlSickCont func_021E899C(u32 pokeId);
extern union BtlSickCont func_021E8940(u8 turns);
extern union BtlSickCont func_021E89F8(u8 high, u32 low);
extern union BtlSickCont func_021E8A28(u32 pokeId, u8 turns);
extern union BtlSickCont func_021E89C0(void);
extern int func_0689C9E4(int index);
extern int func_021D62C4(struct BtlPokeParam *bpp, int sick);
int func_021D794C(int atkType, int defType);
int func_021D799C(int atkType, int defTypes);
int func_021D79E8(int affinityA, int affinityB);
u32 func_021D7A44(u32 power, u32 attack, u32 level, u32 defense);
u32 func_021D7A6C(u32 damage, u32 affinity);
u8 func_021D7A9C(int atkType, u8 *outTypes);
int func_021D7AD4(int affinity);
int func_021D7AF0(u32 percent);
int func_021D7B08(int value, int floor);
u32 func_021D7B10(u32 value, u32 ratio);
u32 func_021D7B2C(u32 value, u32 ratio);
u32 func_021D7B3C(u32 value, u32 percent);
u32 func_021D7B60(struct BtlPokeParam *bpp, u32 divisor);
int func_021D7B74(struct BtlPokeParam *bpp, u32 divisor);
u32 func_021D7B8C(u32 min, u32 max);
int func_021D7BA4(int maxHits);
int func_021D7BD4(struct BtlPokeParam *bpp, int weather);
u32 func_021D7C38(int weather, int moveType);
void func_021D7C70(struct BtlSickContSpec spec, struct BtlPokeParam *attacker, union BtlSickCont *out);
union BtlSickCont func_021D7D18(int kind);
int func_021D7D6C(int kind);
union BtlSickCont func_021D7D78(u32 turns);
union BtlSickCont func_021D7D9C(u32 pokeId);
void func_021D7DC0(int kind, struct BtlPokeParam *attacker, union BtlSickCont *out);
int func_021D7E10(struct BtlPokeParam *bpp);
/* Type affinity table [attacker][defender]: 0 none, 2 half, 4 normal, 8 double. */
extern u8 d_021F047C[17][17];
/* Affinity class -> scale (0, 1, 2, 4, 8, 16) used to combine two classes. */
extern u8 d_021F0427[];
/* Cumulative percent thresholds for a random hit count (2 to 5 hits). */
extern u8 d_021F0421[6];


/* Type affinity class of an attack type against one defender type. */
int func_021D794C(int atkType, int defType)
{
    if (atkType == BTL_TYPE_NONE || defType == BTL_TYPE_NONE)
        return BTL_AFF_NORMAL;
    switch (d_021F047C[atkType][defType]) {
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
int func_021D799C(int atkType, int defTypes)
{
    u8 types[2];
    int firstAffinity;

    func_021E8D0C(defTypes, &types[1], &types[0]);
    if (func_021E8DA8(defTypes))
        return func_021D794C(atkType, types[1]);
    firstAffinity = func_021D794C(atkType, types[1]);
    return func_021D79E8(firstAffinity, func_021D794C(atkType, types[0]));
}


/*
 * Combines two affinity classes into one (half and half give quarter, double
 * and double give quadruple).
 * note:     a plain switch with case 16 after case 8 (mwcc tables 0..8 and compares 16 in
 *           the default path); the u32 switch value gives the unsigned `bhi` range check.
 */
int func_021D79E8(int affinityA, int affinityB)
{
    u32 scale = d_021F0427[affinityA] * d_021F0427[affinityB] / 4;

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
u32 func_021D7A44(u32 power, u32 attack, u32 level, u32 defense) { return (power*attack*(2*level/5+2)/defense)/50+2; }


/* Scales a damage value by an affinity class (none, quarter, half, normal, double, quadruple). */
u32 func_021D7A6C(u32 damage, u32 affinity) { switch(affinity) { case 0:return 0; case 1:return damage/4; case 2:return damage/2; case 3:return damage; case 4:return damage*2; case 5:return damage*4; } return damage; }


/* Lists the defender types that an attack type does not affect or hits for half; returns how many. */
u8 func_021D7A9C(int atkType, u8 *outTypes) { u8 count,defType; defType=0; count=0; do { if(d_021F047C[atkType][defType]==0 || d_021F047C[atkType][defType]==2) outTypes[count++]=defType; ++defType; } while(defType<17); return count; }


/* Reduces an affinity class to none (0), normal (1), advantage (2) or disadvantage (3). */
int func_021D7AD4(int affinity) { if(affinity>3) return 2; if(affinity==3) return 1; if(affinity!=0) return 3; return 0; }


/* True when a percent roll (0..99) falls under the given percent. */
int func_021D7AF0(u32 percent)
{
    if (func_021D78AC(100) < percent) return 1;
    return 0;
}


/* 021D7B08  cmp r0,r1; bge; adds r0,r1,#0 */
/*
 * Larger of two values. Leaf with no calls and no pool; 4 instructions, 8 bytes: cmp r0, r1; bge loc_021D7B0E; adds r0, r1, #0; bx lr.
 */
int func_021D7B08(int value, int floor)
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
u32 func_021D7B10(u32 value, u32 ratio)
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
u32 func_021D7B2C(u32 value, u32 ratio) { u32 result=func_021D7B10(value,ratio); if(result==0) result=1; return result; }


/* Value times percent / 100, rounded half up. */
u32 func_021D7B3C(u32 value, u32 percent) { u32 remainder; value*=percent; remainder=value%100; value/=100; if(remainder>=50) ++value; return value; }


/* Maximum HP divided by the divisor. */
u32 func_021D7B60(struct BtlPokeParam *bpp, u32 divisor) { return (u32)func_021D59B4(bpp,BTL_BPP_VALUE_MAX_HP)/divisor; }


/*
 * Maximum HP divided by the divisor, at least 1.
 * Recursive MATCH unblocker: named callee of the parked ov093 func_021DFABC
 * (the `func_021D7B74(func_021C7CF4(b, k), (u8)func_021DCFF8(a,2))` halfword).
 * Runs func_021D59B4(a, 0xe) through the unsigned divide entry 0x0209C2B0
 * (`_u32_div_f`, see docs/notes/unsigned-divide-entry-is-0209c2b0.c.txt) and
 * floors a zero quotient at 1.
 *
 * Addresses are Black-image addresses.
 */
int func_021D7B74(struct BtlPokeParam *bpp, u32 divisor)
{
    u32 result = func_021D59B4(bpp, BTL_BPP_VALUE_MAX_HP);

    result = result / divisor;
    if (result == 0)
        result = 1;
    return result;
}


/* Random value from min to max, both included (swaps them when reversed). */
u32 func_021D7B8C(u32 min, u32 max)
{
    u32 swap;
    if (min > max) {
        swap = min;
        min = max;
        max = swap;
    }
    return min + func_021D78AC(max - min + 1);
}


/* Number of hits of a multi-hit move: the fixed count, or 2 to 5 hits when the maximum is 5. */
int func_021D7BA4(int maxHits) { u8 roll,hits; if(maxHits!=5) return maxHits; roll=func_021D78AC(100); for(hits=0;hits<6;++hits) { if(roll<d_021F0421[hits]) return hits; } return maxHits; }


/* Weather damage at turn end: one sixteenth of maximum HP (at least 1), 0 for immune types. */
int func_021D7BD4(struct BtlPokeParam *bpp, int weather)
{
    u16 damage;

    switch (weather) {
    case BTL_WEATHER_SAND:
        if (func_021D5814(bpp, BTL_TYPE_ROCK) != 0) return 0;
        if (func_021D5814(bpp, BTL_TYPE_STEEL) != 0) return 0;
        if (func_021D5814(bpp, BTL_TYPE_GROUND) != 0) return 0;
        break;
    case BTL_WEATHER_HAIL:
        if (func_021D5814(bpp, BTL_TYPE_ICE) != 0) return 0;
        break;
    default:
        return 0;
    }
    damage = func_021D59B4(bpp, BTL_BPP_VALUE_MAX_HP) / 16;
    if (damage == 0) damage = 1;
    return damage;
}


/* Damage ratio (20.12) of a move type in the weather: fire and water swap 1.5 and 0.5 in sun and rain. */
u32 func_021D7C38(int weather, int moveType) { switch(weather) { case BTL_WEATHER_SUN: if(moveType==BTL_TYPE_FIRE) return 6144; if(moveType==BTL_TYPE_WATER) return 2048; break; case BTL_WEATHER_RAIN: if(moveType==BTL_TYPE_FIRE) return 2048; if(moveType==BTL_TYPE_WATER) return 6144; break; } return 4096; }


/* Builds the volatile-condition record that a move's data describes. */
void func_021D7C70(struct BtlSickContSpec spec, struct BtlPokeParam *attacker, union BtlSickCont *out)
{
    u8 pokeId;
    u8 turns;

    switch (spec.kind) {
    case 3:
        *out = func_021E899C(func_021D5440(attacker));
        break;
    case 2:
        turns = func_021D7B8C(spec.turnMin, spec.turnMax);
        *out = func_021E8940(turns);
        break;
    case 1:
        *out = func_021E89F8(spec.turnMax, spec.turnMin);
        break;
    case 4:
        pokeId = func_021D5440(attacker);
        turns = func_021D7B8C(spec.turnMin, spec.turnMax);
        *out = func_021E8A28(pokeId, turns);
        break;
    case 0:
    default:
        break;
    }
}


/* Default record of a condition kind: 1, 3, 4 and 5 are permanent, 2 lasts 2 to 4 turns. */
union BtlSickCont func_021D7D18(int kind)
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
        sickCont.byPart.paramLow = func_021D7B8C(2, 4);
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
int func_021D7D6C(int kind)
{
    if (kind < 6)
        return 1;
    return 0;
}


/* Record that lasts the given number of turns. */
union BtlSickCont func_021D7D78(u32 turns) { union BtlSickCont sickCont; sickCont.raw=0; sickCont.byPart.kind=2; sickCont.byPart.paramLow=turns; return sickCont; }


/* Record tied to a Pokemon id. */
union BtlSickCont func_021D7D9C(u32 pokeId) { union BtlSickCont sickCont; sickCont.raw=0; sickCont.byPart.kind=3; sickCont.byPart.paramLow=pokeId; return sickCont; }


/* Builds a condition record from a condition kind: default record, the attacker's id, or 2 to 5 turns. */
void func_021D7DC0(int kind, struct BtlPokeParam *attacker, union BtlSickCont *out)
{
    u8 turns;

    if (kind < 6) {
        *out = func_021D7D18(kind);
        return;
    }
    out->raw = 0;
    switch (kind) {
    case 7:
        *out = func_021E899C(func_021D5440(attacker));
        break;
    case 6:
        turns = func_021D7B8C(2, 5);
        *out = func_021E8940(turns);
        break;
    default:
        *out = func_021E89C0();
        break;
    }
}


/*
 * The first major status condition the Pokemon has (0 when none).
 * lever: declare sick before index; both exits return sick to retain r0 on the zero path.
 * extent: trailing two-byte alignment before Thumb-to-ARM veneer 021D7E34.
 */
int func_021D7E10(struct BtlPokeParam *bpp) { int sick; int index=0; for (;;) { sick=func_0689C9E4(index++); if(sick==0) return sick; if(func_021D62C4(bpp,sick)) return sick; } }
