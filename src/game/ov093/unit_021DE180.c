/*
 * file:     unit_021DE180.c
 * unit:     yes
 * function: BTL_HANDLER_ITEM_HitBackAttacker, BTL_HANDLER_ITEM_GetWhiteHerbHandlers, BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats, BTL_HANDLER_ITEM_WhiteHerbCheckAfterAction, BTL_HANDLER_ITEM_WhiteHerbCheckOnStatChange, BTL_HANDLER_ITEM_WhiteHerbRestoreStats, BTL_HANDLER_ITEM_WhiteHerbUseWhenForced, BTL_HANDLER_ITEM_MentalHerbCheckCondition, BTL_HANDLER_ITEM_MentalHerbCureCondition, BTL_HANDLER_ITEM_MentalHerbUseWhenForced
 * address:  0x021DE180
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
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_HANDLER_ITEM_GetParam  0x021DCFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   BTL_POKEPARAM_HasLoweredStatStage 0x021D5D68 thumb ov093
 *   BTL_HANDLER_ITEM_PushUseItem 0x021DD044 thumb ov093
 *   gMentalHerbHandlerTable 0x021F1A84 data a4
 *   BTL_CALC_FindMajorSick 0x021D7E10 thumb ov093
 *   BTL_HANDLER_ITEM_CureSickOnEaten  0x021DD19C  thumb  ov093
 *   gBrightPowderHandlerTable 0x021F1564 data a4
 *   gWhiteHerbHandlerTable     0x021F1E3C  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

#define STR_ID_JABOCA_ROWAP_HIT_BACK 0x407
#define STR_ID_WHITE_HERB_RESTORED 0x3f2

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *poke);
extern int BTL_HANDLER_ITEM_GetParam(struct BtlEventFactor *factor, int paramIndex);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *poke, u32 divisor);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
extern int BTL_POKEPARAM_HasLoweredStatStage(struct BtlPokeParam *poke);
extern void BTL_HANDLER_ITEM_PushUseItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern int BTL_CALC_FindMajorSick(struct BtlPokeParam *poke);
void BTL_HANDLER_ITEM_CureSickOnEaten(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind);
void BTL_HANDLER_ITEM_HitBackAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *BTL_HANDLER_ITEM_GetWhiteHerbHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work);
void BTL_HANDLER_ITEM_WhiteHerbCheckAfterAction(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work);
void BTL_HANDLER_ITEM_WhiteHerbCheckOnStatChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_WhiteHerbRestoreStats(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_WhiteHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void *BTL_HANDLER_ITEM_GetMentalHerbHandlers(int *handlerCount);
void BTL_HANDLER_ITEM_MentalHerbCheckCondition(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_HANDLER_ITEM_MentalHerbCureCondition(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_HANDLER_ITEM_MentalHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void *BTL_HANDLER_ITEM_GetBrightPowderHandlers(int *handlerCount);
extern u8 gMentalHerbHandlerTable[];
extern u8 gBrightPowderHandlerTable[];
extern int gWhiteHerbHandlerTable[];


/*
 * Jaboca and Rowap Berry, use event: the work word holds the attacker id plus
 * one. Damage the attacker for max HP / item divisor unless it has fainted.
 */
void BTL_HANDLER_ITEM_HitBackAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExDamage *record;
    struct BtlPokeParam *attacker;
    u8 attackerId;
    u8 divisor;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        attackerId = *work - 1;
        attacker = func_021C7CF4(flow, attackerId);
        if (BTL_POKEPARAM_IsFainted(attacker) == 0) {
            divisor = BTL_HANDLER_ITEM_GetParam(factor, BTL_ITEM_PARAM_VALUE);
            record = func_021C88A4(flow, HANDEX_KIND_DAMAGE, pokeId);
            record->pokeId = attackerId;
            record->amount = BTL_CALC_DivideMaxHpMin1(attacker, divisor);
            func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_JABOCA_ROWAP_HIT_BACK);
            func_021C8860(&record->str, record->pokeId);
            func_021C8860(&record->str, pokeId);
            func_021C8860(&record->str, BTL_EVENT_GetFactorKey(factor));
            func_021C88C8(flow, record);
        }
    }
}


/* Handler table getter of White Herb. */
int *BTL_HANDLER_ITEM_GetWhiteHerbHandlers(int *handlerCount)
{
    *handlerCount = 6;
    return gWhiteHerbHandlerTable;
}


/*
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries pokeId.
 */
/* White Herb: act when the holder has a lowered stat stage. */
void BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work) { if (BTL_POKEPARAM_HasLoweredStatStage(func_021C7CF4(flow, pokeId))) BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId); }




/*
 * extent: two-byte alignment padding at 021DE26E.
 * interface: original restores r3 from r7 before calling 021DE228.
 */
/* White Herb, after-action event: check unless the turn phase is 6. */
void BTL_HANDLER_ITEM_WhiteHerbCheckAfterAction(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work) { if (BTL_EVENT_GetVar(BTL_EVAR_TURN_PHASE) != 6) BTL_HANDLER_ITEM_WhiteHerbCheckLoweredStats(factor, flow, pokeId, work); }




/*
 * extent: two-byte alignment padding at 021DE29E.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries pokeId.
 */
/* White Herb, stat change event: act when the holder has a lowered stat stage. */
void BTL_HANDLER_ITEM_WhiteHerbCheckOnStatChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) { if(BTL_POKEPARAM_HasLoweredStatStage(func_021C7CF4(flow, pokeId))) BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId); } }




/* White Herb, use event: restores the lowered stat stages and shows the message. */
void BTL_HANDLER_ITEM_WhiteHerbRestoreStats(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExRestoreRanks *restore;
    HandExMessage *message;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        restore = func_021C88A4(flow, HANDEX_KIND_RESTORE_RANKS, pokeId);
        restore->pokeId = pokeId;
        func_021C88C8(flow, restore);
        message = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&message->str, HANDEX_STR_SET, STR_ID_WHITE_HERB_RESTORED);
        func_021C8860(&message->str, pokeId);
        func_021C8860(&message->str, BTL_EVENT_GetFactorKey(factor));
        func_021C88C8(flow, message);
    }
}



/* White Herb, forced use event (Fling): acts only when the item was used from outside. */
void BTL_HANDLER_ITEM_WhiteHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) BTL_HANDLER_ITEM_WhiteHerbRestoreStats(factor, flow, pokeId, work); }



/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
/* Handler table getter of Mental Herb. */
void *BTL_HANDLER_ITEM_GetMentalHerbHandlers(int *handlerCount) { *handlerCount=4; return gMentalHerbHandlerTable; }



/*
 * extent: two-byte alignment padding at 021DE34A.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries pokeId.
 */
/* Mental Herb: act when the holder has one of the conditions it cures. */
void BTL_HANDLER_ITEM_MentalHerbCheckCondition(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) { if(BTL_CALC_FindMajorSick(func_021C7CF4(flow, pokeId))) BTL_HANDLER_ITEM_PushUseItem(factor, flow, pokeId); } }




/* Mental Herb, use event: cures the volatile conditions. */
void BTL_HANDLER_ITEM_MentalHerbCureCondition(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_CureSickOnEaten(factor, flow, pokeId, BTL_SICK_ANY_VOLATILE);
}



/* Mental Herb, forced use event (Fling): acts only when the item was used from outside. */
void BTL_HANDLER_ITEM_MentalHerbUseWhenForced(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) BTL_HANDLER_ITEM_MentalHerbCureCondition(factor, flow, pokeId, work); }



/* Handler table getter of Bright Powder. */
void *BTL_HANDLER_ITEM_GetBrightPowderHandlers(int *handlerCount) { *handlerCount=1; return gBrightPowderHandlerTable; }
