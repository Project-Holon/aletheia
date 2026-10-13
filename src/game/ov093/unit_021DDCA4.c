/*
 * file:     unit_021DDCA4.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_BabiriBerryWeakenSteelHit, BTL_HANDLER_ITEM_GetChilanBerryHandlers, BTL_HANDLER_ITEM_ChilanBerryWeakenNormalHit, BTL_HANDLER_ITEM_WeakenHitOfType, BTL_HANDLER_ITEM_ShowResistBerryMessage, BTL_HANDLER_ITEM_HpBerryCheckAfterDamage, BTL_HANDLER_ITEM_HpBerryCheckAtTurnEnd, BTL_HANDLER_ITEM_HpBerryCheckOnUse, BTL_HANDLER_ITEM_HpBerryCheckAndUse, BTL_HANDLER_ITEM_IsHpLowForTrigger, BTL_HANDLER_ITEM_IsHpAtOrBelowFraction, BTL_HANDLER_ITEM_GetCustapBerryHandlers, BTL_HANDLER_ITEM_CustapBerryMoveFirst, BTL_HANDLER_ITEM_CustapBerryShowMessage, BTL_HANDLER_ITEM_GetMicleBerryHandlers, BTL_HANDLER_ITEM_MicleBerryCheckOnSwitchIn, BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage, BTL_HANDLER_ITEM_MicleBerryCheckAfterAction, BTL_HANDLER_ITEM_MicleBerryCheckHp, BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy, BTL_HANDLER_ITEM_MicleBerryUseWhenForced
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
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam 0x021DCFF8 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   gChilanBerryHandlerTable     0x021F184C  data   ov093  a4
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   gCustapBerryHandlerTable     0x021F15EC  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind1Value  0x021E89D4  thumb  ov093
 *   gJabocaBerryHandlerTable 0x021F160C data a4
 *   gMicleBerryHandlerTable     0x021F1E0C  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

/* String ids of the item messages. */
#define STR_ID_RESIST_BERRY_EATEN 219
#define STR_ID_ITEM_ACTED_QUICK 0x401   /* Custap Berry and Quick Claw */
#define STR_ID_MICLE_ACCURACY 0x404

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern u32 BTL_POKEPARAM_HasSubstitute(struct BtlPokeParam *poke);
extern void BTL_EVENT_MultiplyVar(int varId, int ratio);
extern u32 func_021C7EC4(struct BtlSvFlow *flow);
extern int func_021E85F8(int pokeId);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);
extern void BTL_HANDLER_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *poke, int valueId);
extern u32 BTL_CALC_DivideMaxHp(struct BtlPokeParam *poke, u32 fraction);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern int BTLV_CORE_MakeSlotKind1Value(u32 percent);
extern int gChilanBerryHandlerTable[];
extern int gCustapBerryHandlerTable[];
extern u8 gJabocaBerryHandlerTable[];
extern int gMicleBerryHandlerTable[];

void BTL_HANDLER_ITEM_BabiriBerryWeakenSteelHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *BTL_HANDLER_ITEM_GetChilanBerryHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_ChilanBerryWeakenNormalHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity);
void BTL_HANDLER_ITEM_ShowResistBerryMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_HpBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_HpBerryCheckAtTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_HpBerryCheckOnUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_HpBerryCheckAndUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int fraction, int checkTrigger);
int BTL_HANDLER_ITEM_IsHpLowForTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, unsigned int fraction);
int BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(struct BtlSvFlow *flow, int pokeId, u32 fraction);
int *BTL_HANDLER_ITEM_GetCustapBerryHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_CustapBerryMoveFirst(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_CustapBerryShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *BTL_HANDLER_ITEM_GetMicleBerryHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_MicleBerryCheckOnSwitchIn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_MicleBerryCheckAfterAction(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_MicleBerryCheckHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_MicleBerryUseWhenForced(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void *BTL_HANDLER_ITEM_GetJabocaBerryHandlers(int *handlerCount);

/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #8; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl BTL_HANDLER_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
/* Babiri Berry: halves a Steel hit that is super effective. */
void BTL_HANDLER_ITEM_BabiriBerryWeakenSteelHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_STEEL, 0);
}

/* Handler table getter of Chilan Berry. */
int *BTL_HANDLER_ITEM_GetChilanBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gChilanBerryHandlerTable;
}

/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0; str r4, [sp]; movs r4, #1; str r4, [sp, #4]; bl BTL_HANDLER_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
/* Chilan Berry: halves a Normal hit, super effective or not. */
void BTL_HANDLER_ITEM_ChilanBerryWeakenNormalHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_NORMAL, 1);
}

/*
 * Common check of the type-resist berries: the holder is the defender, the
 * move has the berry type, the hit is super effective (unless the berry
 * ignores affinity) and it did not land on a substitute. The damage ratio is
 * halved and the work word is set when the berry will show its message.
 */
int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && moveType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)
        && (ignoreAffinity != 0 || BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_SUPER_EFFECTIVE_ABOVE)
        && BTL_POKEPARAM_HasSubstitute(func_021C7CF4(flow, pokeId)) == 0) {
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_HALF);
        if (func_021C7EC4(flow) == 0)
            *work = 1;
        return 1;
    }
    return 0;
}

/* Resist berry: shows the message that the berry weakened the hit. */
void BTL_HANDLER_ITEM_ShowResistBerryMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExItemMessage *record;
    if (*work != 0 && func_021E85F8(pokeId) != 0) {
        record = func_021C88A4(flow, HANDEX_KIND_ITEM_MESSAGE, pokeId);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_RESIST_BERRY_EATEN);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, record);
    }
}

/*
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
/* HP berries, damage event: eat when HP is low, honoring the trigger kind. */
void BTL_HANDLER_ITEM_HpBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        BTL_HANDLER_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE), 1);
    }
}

/* HP berries, turn end event: eat when HP is low (no trigger kind test). */
void BTL_HANDLER_ITEM_HpBerryCheckAtTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        BTL_HANDLER_ITEM_HpBerryCheckAndUse(factor, flow, pokeId, BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE), 0);
    }
}

/* HP berries, use event: eat when HP is low. */
void BTL_HANDLER_ITEM_HpBerryCheckOnUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021C7CF4(flow, pokeId);
    if (BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(flow, pokeId, BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE)) != 0) BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
}

/* Eats the berry when the holder's HP is at or below 1/fraction. */
void BTL_HANDLER_ITEM_HpBerryCheckAndUse(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int fraction, int checkTrigger)
{
    int isLow;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (checkTrigger != 0)
            isLow = BTL_HANDLER_ITEM_IsHpLowForTrigger(factor, flow, pokeId, fraction);
        else
            isLow = BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(flow, pokeId, fraction);
        if (isLow != 0)
            BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Same HP test, only when the trigger kind is 0 or 1. */
int BTL_HANDLER_ITEM_IsHpLowForTrigger(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, unsigned int fraction)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && (unsigned char)BTL_EVENT_GetVar(BTL_EVAR_TRIGGER_KIND) <= 1) return BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(flow, pokeId, fraction);
    return 0;
}

/* True when the Pokemon's HP is at or below max HP / fraction (Gluttony halves a fraction above 2). */
int BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(struct BtlSvFlow *flow, int pokeId, u32 fraction)
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
        if (hp <= BTL_CALC_DivideMaxHp(poke, fraction))
            return 1;
    }
    return 0;
}

/* Handler table getter of Custap Berry. */
int *BTL_HANDLER_ITEM_GetCustapBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gCustapBerryHandlerTable;
}

/* Custap Berry: moves first in its priority bracket when HP is at or below 1/4. */
void BTL_HANDLER_ITEM_CustapBerryMoveFirst(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(flow, pokeId, 4) != 0 && BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, BTL_ACTION_ORDER_FIRST) != 0) BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
}

/* Custap Berry: shows the message and clears the work word. */
void BTL_HANDLER_ITEM_CustapBerryShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_ITEM_ACTED_QUICK);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, record);
        *work = 0;
    }
}

/* Handler table getter of Micle Berry. */
int *BTL_HANDLER_ITEM_GetMicleBerryHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gMicleBerryHandlerTable;
}

/* Micle Berry, switch-in event: eat when HP is low. */
void BTL_HANDLER_ITEM_MicleBerryCheckOnSwitchIn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 fraction;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        fraction = BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
        if (BTL_HANDLER_ITEM_IsHpLowForTrigger(factor, flow, pokeId, fraction) != 0)
            BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
    }
}

/* Micle Berry, damage event: check the holder. */
void BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) BTL_HANDLER_ITEM_MicleBerryCheckHp(factor, flow, pokeId, work);
}

/* Micle Berry, after-action event: check unless the turn phase is 6. */
void BTL_HANDLER_ITEM_MicleBerryCheckAfterAction(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (BTL_EVENT_GetVar(BTL_EVAR_TURN_PHASE) != 6) BTL_HANDLER_ITEM_MicleBerryCheckAfterDamage(factor, flow, pokeId, work);
}

/* Micle Berry: eat when HP is at or below the item fraction. */
void BTL_HANDLER_ITEM_MicleBerryCheckHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    unsigned char fraction;
    func_021C7CF4(flow, pokeId);
    fraction = BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
    if (BTL_HANDLER_ITEM_IsHpAtOrBelowFraction(flow, pokeId, fraction) != 0) BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId);
}

/* Micle Berry, use event: the next move's accuracy rises (status 0x22, 120 percent). */
void BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExAddSickMessage *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        func_021C7CF4(flow, pokeId);
        record = func_021C88A4(flow, HANDEX_KIND_ADD_SICK, pokeId);
        record->pokeId = pokeId;
        record->sickKind = BTL_SICK_MICLE_ACCURACY;
        record->sickCont.raw = BTLV_CORE_MakeSlotKind1Value(BTL_RATIO_MICLE_ACCURACY);
        func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_MICLE_ACCURACY);
        func_021C8860(&record->str, pokeId);
        func_021C8860(&record->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, record);
    }
}

/* Micle Berry, forced use event (Fling): acts only when the work slot says the item was used from outside. */
void BTL_HANDLER_ITEM_MicleBerryUseWhenForced(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) BTL_HANDLER_ITEM_MicleBerryRaiseAccuracy(factor, flow, pokeId, work); }

/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
/* Handler table getter of Jaboca Berry. */
void *BTL_HANDLER_ITEM_GetJabocaBerryHandlers(int *handlerCount) { *handlerCount=2; return gJabocaBerryHandlerTable; }
