/*
 * file:     unit_021DE180.c
 * unit:     yes
 * function: func_021DE180, func_021DE21C, func_021DE228, func_021DE24C, func_021DE270, func_021DE2A0, func_021DE300, func_021DE31C, func_021DE34C, func_021DE358
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D5D68 0x021D5D68 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   d_021F1A84 0x021F1A84 data a4
 *   func_021D7E10 0x021D7E10 thumb ov093
 *   func_021DD19C  0x021DD19C  thumb  ov093
 *   d_021F1564 0x021F1564 data a4
 *   d_021F1E3C     0x021F1E3C  data   ov093  a4
 */
#include "unit_021DDC44_types.h"

#define STR_ID_JABOCA_ROWAP_HIT_BACK 0x407
#define STR_ID_WHITE_HERB_RESTORED 0x3f2

extern int func_021D775C(int varId);
extern struct BtlPokeParam *func_021C7CF4(struct BtlSvFlow *flow, int pokeId);
extern int func_021D5B68(struct BtlPokeParam *poke);
extern int func_021DCFF8(struct BtlEventFactor *factor, int paramIndex);
extern void *func_021C88A4(struct BtlSvFlow *flow, int kind, int pokeId);
extern int func_021D7B74(struct BtlPokeParam *poke, u32 divisor);
extern void func_021C8838(HandExStr *str, int strType, int strId);
extern void func_021C8860(HandExStr *str, u32 arg);
extern u16 func_021D70A8(struct BtlEventFactor *factor);
extern void func_021C88C8(struct BtlSvFlow *flow, void *record);
extern int func_021D5D68(struct BtlPokeParam *poke);
extern void func_021DD044(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern int func_021D7E10(struct BtlPokeParam *poke);
void func_021DD19C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int sickKind);
void func_021DE180(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021DE21C(int *handlerCount);
void func_021DE228(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work);
void func_021DE24C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work);
void func_021DE270(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DE2A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DE300(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void *func_021DE310(int *handlerCount);
void func_021DE31C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DE34C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void func_021DE358(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void *func_021DE368(int *handlerCount);
extern u8 d_021F1A84[];
extern u8 d_021F1564[];
extern int d_021F1E3C[];


/*
 * Jaboca and Rowap Berry, use event: the work word holds the attacker id plus
 * one. Damage the attacker for max HP / item divisor unless it has fainted.
 */
void func_021DE180(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExDamage *record;
    struct BtlPokeParam *attacker;
    u8 attackerId;
    u8 divisor;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && *work != 0) {
        attackerId = *work - 1;
        attacker = func_021C7CF4(flow, attackerId);
        if (func_021D5B68(attacker) == 0) {
            divisor = func_021DCFF8(factor, BTL_ITEM_PARAM_VALUE);
            record = func_021C88A4(flow, HANDEX_KIND_DAMAGE, pokeId);
            record->pokeId = attackerId;
            record->amount = func_021D7B74(attacker, divisor);
            func_021C8838(&record->str, HANDEX_STR_SET, STR_ID_JABOCA_ROWAP_HIT_BACK);
            func_021C8860(&record->str, record->pokeId);
            func_021C8860(&record->str, pokeId);
            func_021C8860(&record->str, func_021D70A8(factor));
            func_021C88C8(flow, record);
        }
    }
}


/* Handler table getter of White Herb. */
int *func_021DE21C(int *handlerCount)
{
    *handlerCount = 6;
    return d_021F1E3C;
}


/*
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries pokeId.
 */
/* White Herb: act when the holder has a lowered stat stage. */
void func_021DE228(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work) { if (func_021D5D68(func_021C7CF4(flow, pokeId))) func_021DD044(factor, flow, pokeId); }




/*
 * extent: two-byte alignment padding at 021DE26E.
 * interface: original restores r3 from r7 before calling 021DE228.
 */
/* White Herb, after-action event: check unless the turn phase is 6. */
void func_021DE24C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int work) { if (func_021D775C(BTL_EVAR_TURN_PHASE) != 6) func_021DE228(factor, flow, pokeId, work); }




/*
 * extent: two-byte alignment padding at 021DE29E.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries pokeId.
 */
/* White Herb, stat change event: act when the holder has a lowered stat stage. */
void func_021DE270(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId == func_021D775C(BTL_EVAR_POKE_ID)) { if(func_021D5D68(func_021C7CF4(flow, pokeId))) func_021DD044(factor, flow, pokeId); } }




/* White Herb, use event: restores the lowered stat stages and shows the message. */
void func_021DE2A0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExRestoreRanks *restore;
    HandExMessage *message;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        restore = func_021C88A4(flow, HANDEX_KIND_RESTORE_RANKS, pokeId);
        restore->pokeId = pokeId;
        func_021C88C8(flow, restore);
        message = func_021C88A4(flow, HANDEX_KIND_MESSAGE, pokeId);
        func_021C8838(&message->str, HANDEX_STR_SET, STR_ID_WHITE_HERB_RESTORED);
        func_021C8860(&message->str, pokeId);
        func_021C8860(&message->str, func_021D70A8(factor));
        func_021C88C8(flow, message);
    }
}



/* White Herb, forced use event (Fling): acts only when the item was used from outside. */
void func_021DE300(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) func_021DE2A0(factor, flow, pokeId, work); }



/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
/* Handler table getter of Mental Herb. */
void *func_021DE310(int *handlerCount) { *handlerCount=4; return d_021F1A84; }



/*
 * extent: two-byte alignment padding at 021DE34A.
 * interface: func_021C7CF4 leaves r0 live for the following call; r1 carries pokeId.
 */
/* Mental Herb: act when the holder has one of the conditions it cures. */
void func_021DE31C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId) { if(pokeId == func_021D775C(BTL_EVAR_POKE_ID)) { if(func_021D7E10(func_021C7CF4(flow, pokeId))) func_021DD044(factor, flow, pokeId); } }




/* Mental Herb, use event: cures the volatile conditions. */
void func_021DE34C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    func_021DD19C(factor, flow, pokeId, BTL_SICK_ANY_VOLATILE);
}



/* Mental Herb, forced use event (Fling): acts only when the item was used from outside. */
void func_021DE358(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work) { if (work[ITEM_WORK_FORCED_USE]) func_021DE34C(factor, flow, pokeId, work); }



/* Handler table getter of Bright Powder. */
void *func_021DE368(int *handlerCount) { *handlerCount=1; return d_021F1564; }
