/*
 * file:     unit_021DDCA4.c
 * unit:     yes
 * function: func_021DDCA4, func_021DDCB8, func_021DDCC4, func_021DDCD8, func_021DDD38, func_021DDD8C, func_021DDDC4, func_021DDDFC, func_021DDE30, func_021DDE74, func_021DDEA4, func_021DDEF0, func_021DDEFC, func_021DDF38, func_021DDF8C, func_021DDF98, func_021DDFDC, func_021DE000, func_021DE024, func_021DE058, func_021DE0C0
 * address:  0x021DDCA4
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   d_021F184C     0x021F184C  data   ov093  a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F15EC     0x021F15EC  data   ov093  a4
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   d_021F160C 0x021F160C data a4
 *   d_021F1E0C     0x021F1E0C  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

/* String ids of the item messages. */
#define STR_ID_RESIST_BERRY_EATEN 219
#define STR_ID_ITEM_ACTED_QUICK 0x401   /* Custap Berry and Quick Claw */
#define STR_ID_MICLE_ACCURACY 0x404

extern int func_021D775C(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u32 func_021D6D7C(struct BtlPokeParam *poke);
extern void func_021D7704(int varId, int ratio);
extern u32 func_021C7EC4(struct BtlSvFlow *flow);
extern int func_021E85F8(int pokeId);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
extern int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex);
extern void func_021DD044(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *poke, int valueId);
extern u32 func_021D7B60(struct BtlPokeParam *poke, u32 fraction);
extern int func_021D76BC(int varId, u32 value);
extern int func_021E89D4(u32 percent);
extern int d_021F184C[];
extern int d_021F15EC[];
extern u8 d_021F160C[];
extern int d_021F1E0C[];

void func_021DDCA4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021DDCB8(int *handlerCount);
void func_021DDCC4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int func_021DDCD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity);
void func_021DDD38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DDD8C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DDDC4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DDDFC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DDE30(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int fraction, int checkTrigger);
int func_021DDE74(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, unsigned int fraction);
int func_021DDEA4(struct BtlSvFlow *flow, int pokeId, u32 fraction);
int *func_021DDEF0(int *handlerCount);
void func_021DDEFC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DDF38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021DDF8C(int *handlerCount);
void func_021DDF98(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DDFDC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DE000(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DE024(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DE058(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DE0C0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void *func_021DE0D0(int *handlerCount);

/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #8; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
/* Babiri Berry: halves a Steel hit that is super effective. */
void func_021DDCA4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    func_021DDCD8(factor, flow, pokeId, work, POKETYPE_STEEL, 0);
}

/* Handler table getter of Chilan Berry. */
int *func_021DDCB8(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F184C;
}

/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0; str r4, [sp]; movs r4, #1; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
/* Chilan Berry: halves a Normal hit, super effective or not. */
void func_021DDCC4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    func_021DDCD8(factor, flow, pokeId, work, POKETYPE_NORMAL, 1);
}

/*
 * Common check of the type-resist berries: the holder is the defender, the
 * move has the berry type, the hit is super effective (unless the berry
 * ignores affinity) and it did not land on a substitute. The damage ratio is
 * halved and the work word is set when the berry will show its message.
 */
int func_021DDCD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && moveType == func_021D775C(BTL_EVAR_MOVE_TYPE)
        && (ignoreAffinity != 0 || func_021D775C(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE)
        && func_021D6D7C(func_021C7CF4(flow, pokeId)) == 0) {
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_HALF);
        if (func_021C7EC4(flow) == 0)
            *work = 1;
        return 1;
    }
    return 0;
}

/* Resist berry: shows the message that the berry weakened the hit. */
void func_021DDD38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExItemMessage *record;
    if (*work != 0 && func_021E85F8(pokeId) != 0) {
        record = func_021C88A4(flow, HANDEX_KIND_ITEM_MESSAGE, pokeId);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_RESIST_BERRY_EATEN);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, func_021D70A8(factor));
        func_021C88C8(flow, record);
    }
}

/*
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
/* HP berries, damage event: eat when HP is low, honoring the trigger kind. */
void func_021DDD8C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        func_021DDE30(factor, flow, pokeId, func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE), 1);
    }
}

/* HP berries, turn end event: eat when HP is low (no trigger kind test). */
void func_021DDDC4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        func_021DDE30(factor, flow, pokeId, func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE), 0);
    }
}

/* HP berries, use event: eat when HP is low. */
void func_021DDDFC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021C7CF4(flow, pokeId);
    if (func_021DDEA4(flow, pokeId, func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE)) != 0) func_021DD044(factor, flow, pokeId);
}

/* Eats the berry when the holder's HP is at or below 1/fraction. */
void func_021DDE30(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int fraction, int checkTrigger)
{
    int isLow;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (checkTrigger != 0)
            isLow = func_021DDE74(factor, flow, pokeId, fraction);
        else
            isLow = func_021DDEA4(flow, pokeId, fraction);
        if (isLow != 0)
            func_021DD044(factor, flow, pokeId);
    }
}

/* Same HP test, only when the trigger kind is 0 or 1. */
int func_021DDE74(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, unsigned int fraction)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && (unsigned char)func_021D775C(BTL_EVAR_TRIGGER_KIND) <= 1) return func_021DDEA4(flow, pokeId, fraction);
    return 0;
}

/* True when the Pokemon's HP is at or below max HP / fraction (Gluttony halves a fraction above 2). */
int func_021DDEA4(struct BtlSvFlow *flow, int pokeId, u32 fraction)
{
    struct BtlPokeParam *poke;
    u32 hp;

    poke = func_021C7CF4(flow, pokeId);
    if (func_021D59B4(poke, BTL_VALUE_ABILITY) == BTL_ABILITY_GLUTTONY && fraction > 2)
        fraction >>= 1;
    if (fraction == 0)
        fraction = 1;
    if ((u32)func_021D59B4(poke, BTL_VALUE_MAX_HP) > 1) {
        hp = func_021D59B4(poke, BTL_VALUE_HP);
        if (hp <= func_021D7B60(poke, fraction))
            return 1;
    }
    return 0;
}

/* Handler table getter of Custap Berry. */
int *func_021DDEF0(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F15EC;
}

/* Custap Berry: moves first in its priority bracket when HP is at or below 1/4. */
void func_021DDEFC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021DDEA4(flow, pokeId, 4) != 0 && func_021D76BC(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_FIRST) != 0) func_021DD044(factor, flow, pokeId);
}

/* Custap Berry: shows the message and clears the work word. */
void func_021DDF38(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExMessage *record;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        record = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_ITEM_ACTED_QUICK);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, func_021D70A8(factor));
        func_021C88C8(flow, record);
        *work = 0;
    }
}

/* Handler table getter of Micle Berry. */
int *func_021DDF8C(int *handlerCount)
{
    *handlerCount = 6;
    return d_021F1E0C;
}

/* Micle Berry, switch-in event: eat when HP is low. */
void func_021DDF98(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 fraction;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        fraction = func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE);
        if (func_021DDE74(factor, flow, pokeId, fraction) != 0)
            func_021DD044(factor, flow, pokeId);
    }
}

/* Micle Berry, damage event: check the holder. */
void func_021DDFDC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) func_021DE024(factor, flow, pokeId, work);
}

/* Micle Berry, after-action event: check unless the turn phase is 6. */
void func_021DE000(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (func_021D775C(BTL_EVAR_TURN_PHASE) != 6) func_021DDFDC(factor, flow, pokeId, work);
}

/* Micle Berry: eat when HP is at or below the item fraction. */
void func_021DE024(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    unsigned char fraction;
    func_021C7CF4(flow, pokeId);
    fraction = func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE);
    if (func_021DDEA4(flow, pokeId, fraction) != 0) func_021DD044(factor, flow, pokeId);
}

/* Micle Berry, use event: the next move's accuracy rises (status 0x22, 120 percent). */
void func_021DE058(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExAddSickMessage *record;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        record = func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
        record->pokeId = pokeId;
        record->sickKind = BTL_SICK_MICLE_ACCURACY;
        record->sickCont.raw = func_021E89D4(BTL_RATIO_MICLE_ACCURACY);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_MICLE_ACCURACY);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, func_021D70A8(factor));
        func_021C88C8(flow, record);
    }
}

/* Micle Berry, forced use event (Fling): acts only when the work slot says the item was used from outside. */
void func_021DE0C0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) func_021DE058(factor, flow, pokeId, work); }

/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
/* Handler table getter of Jaboca Berry. */
void *func_021DE0D0(int *handlerCount) { *handlerCount=2; return d_021F160C; }
