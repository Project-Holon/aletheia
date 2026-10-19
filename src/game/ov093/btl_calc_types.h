#ifndef BTL_CALC_TYPES_H
#define BTL_CALC_TYPES_H
/*
 * ov093 battle calculation: the random number state and the calculation work
 * area.
 */

#include "../types.h"

/* Parameters of the 64 bit linear congruential generator. */
typedef struct {
    u64 seed;
    u64 mul;
    u64 add;
} BtlRngState;

/* The calculation state at 021F6360. */
struct BtlCalcWork {
    u16 heapId; /* heap used for Pokemon parameter reads */
    u16 pad02;
    u16 *workTable;
    BtlRngState rng;
};

/*
 * ov093 battle calculation helpers that follow btl_calc.c: type affinity,
 * damage arithmetic, volatile-condition records, prize money and the packed
 * battle action word.
 */

#ifndef OV093_BASIC_TYPES

#endif

/* Pokemon types used by the helpers (the battle type list, 0 = normal). */
#define BTL_TYPE_GHOST 7

#define BTL_TYPE_STEEL 8

#define BTL_TYPE_FIRE 9

#define BTL_TYPE_WATER 10

#define BTL_TYPE_ICE 14

#define BTL_TYPE_ROCK 5

#define BTL_TYPE_GROUND 4

#define BTL_TYPE_NONE 17 /* "no type": always affinity normal */

/* Type affinity classes returned by the affinity helpers. */
#define BTL_AFF_NONE 0     /* no effect */

#define BTL_AFF_QUARTER 1

#define BTL_AFF_HALF 2

#define BTL_AFF_NORMAL 3

#define BTL_AFF_DOUBLE 4

#define BTL_AFF_QUADRUPLE 5

/* Weather values. */
#define BTL_WEATHER_SUN 1

#define BTL_WEATHER_RAIN 2

#define BTL_WEATHER_HAIL 3

#define BTL_WEATHER_SAND 4

/* Value ids read with the battle Pokemon value getter. */
#define BTL_BPP_VALUE_HP 13

#define BTL_BPP_VALUE_MAX_HP 14

#define BTL_BPP_VALUE_LEVEL 15

#define BTL_BPP_VALUE_FORM 19

/* Battle rules (BattleSetupParam.rule). */
#define BTL_RULE_SINGLE 0

#define BTL_RULE_DOUBLE 1

#define BTL_RULE_TRIPLE 2

#define BTL_RULE_ROTATION 3

/*
 * One volatile-condition record: a kind and the parameters that go with it
 * (turn counts, a Pokemon id). Same word as the sickCont slots of
 * btl_pokeparam_types.h; kept here so this unit does not depend on that header.
 * Kinds: 0 none, 1 permanent, 2 turns, 3 tied to a Pokemon, 4 turns and Pokemon.
 */
union BtlSickCont {
    u32 raw;
    struct { u32 kind : 3; u32 paramLow : 6; u32 paramHigh : 6; u32 flags : 17; } byPart;
};

/* Client id that marks an empty entry of a BtlClientSet. */
#define BTL_CLIENT_ID_NONE 4

/*
 * Recipe for a volatile condition as move data stores it (16 bits): the kind
 * of record to make and the turn limits.
 */
struct BtlSickContSpec {
    u16 kind : 4;
    u16 turnMin : 6;
    u16 turnMax : 6;
};

/*
 * One packed battle action word. kind 0 = none, 1 = fight, 2 = item,
 * 3 = change Pokemon, 4 = escape, 5 = skip, 6 = rotate (rotation battle). The
 * views read the same word.
 */
/* Kinds of an action word (the low four bits). 7 to 9 are record-only values. */
enum BtlActionKind {
    BTL_ACTION_KIND_NONE = 0,
    BTL_ACTION_KIND_FIGHT = 1,
    BTL_ACTION_KIND_ITEM = 2,
    BTL_ACTION_KIND_CHANGE = 3,
    BTL_ACTION_KIND_ESCAPE = 4,
    BTL_ACTION_KIND_SKIP = 5,
    BTL_ACTION_KIND_ROTATE = 6,
    BTL_ACTION_KIND_FORCED_SKIP = 7,
    BTL_ACTION_KIND_RECORD_RESET = 8,
    BTL_ACTION_KIND_RECORD_ERROR = 9
};

union BtlAction {
    u32 raw;
    struct {
        u32 kind : 4;
        u32 rest : 28;
    } head;
    struct {
        u32 kind : 4;
        u32 targetPos : 3;
        u32 moveId : 16;
        u32 unused : 3;
        u32 slotFlag : 1;  /* set: the client looks up the move's slot */
        u32 rest : 5;
    } fight;
    struct {
        u32 kind : 4;
        u32 targetIndex : 3;
        u32 itemId : 16;
        u32 itemParam : 8;
        u32 rest : 1;
    } item;
    struct {
        u32 kind : 4;
        u32 posIndex : 3;
        u32 memberIndex : 3;
        u32 depleted : 1;  /* the change is forced by a fainted Pokemon */
        u32 rest : 21;
    } change;
    struct {
        u32 kind : 4;
        u32 direction : 3;
        u32 rest : 25;
    } rotate;
};

#endif
