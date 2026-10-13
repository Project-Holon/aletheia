/*
 * file:     hand_waza_021e18ec.c
 * unit:     yes
 * function: HAND_WAZA_SwallowOnCalcHealRatio, HAND_WAZA_AddCounter, HAND_WAZA_CounterOnMoveFailCheck, HAND_WAZA_CounterOnDecideTarget, HAND_WAZA_CounterOnCalcFixedDamage, HAND_WAZA_AddMirrorCoat, HAND_WAZA_MirrorCoatOnMoveFailCheck, HAND_WAZA_MirrorCoatOnDecideTarget, HAND_WAZA_MirrorCoatOnCalcFixedDamage, HAND_WAZA_AddMetalBurst, HAND_WAZA_MetalBurstOnMoveFailCheck, HAND_WAZA_MetalBurstOnDecideTarget, HAND_WAZA_MetalBurstOnCalcFixedDamage, HAND_WAZA_RetaliateOnMoveFailCheck, HAND_WAZA_RetaliateOnDecideTarget, HAND_WAZA_RetaliateOnCalcFixedDamage, HAND_WAZA_FindRetaliateHit, HAND_WAZA_AddLastResort
 * address:  0x021E18EC
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
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetCounter  0x021D69AC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gCounterHandlers     0x021F2C00  data   ov093  a4
 *   gMirrorCoatHandlers     0x021F2C18  data   ov093  a4
 *   gMetalBurstHandlers     0x021F2C30  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetPosTableEntryForPoke  0x021C7D44  thumb  ov093
 *   BTL_SERVER_FLOW_DecideMoveTarget  0x021C8030  thumb  ov093
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_POKEPARAM_GetHitRecord  0x021D6940  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   gLastResortHandlers     0x021F25C4  data   ov093  a4
 */
#include "hand_waza_021e10d8_types.h"

void HAND_WAZA_SwallowOnCalcHealRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddCounter(int *handlerCount);
void HAND_WAZA_CounterOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_CounterOnDecideTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_CounterOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddMirrorCoat(int *handlerCount);
void HAND_WAZA_MirrorCoatOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_MirrorCoatOnDecideTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_MirrorCoatOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddMetalBurst(int *handlerCount);
void HAND_WAZA_MetalBurstOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_MetalBurstOnDecideTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_MetalBurstOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_RetaliateOnMoveFailCheck(struct BtlSvFlow *flow, int pokeId, void *work, int damageType);
void HAND_WAZA_RetaliateOnDecideTarget(struct BtlSvFlow *flow, int pokeId, void *work, int damageType);
void HAND_WAZA_RetaliateOnCalcFixedDamage(struct BtlSvFlow *flow, int pokeId, void *work, int damageType, int ratio);
int HAND_WAZA_FindRetaliateHit(struct BtlPokeParam *poke, int damageType, struct BtlHitInfo *out);
BtlEventHandler *HAND_WAZA_AddLastResort(int *handlerCount);
extern BtlEventHandler gCounterHandlers[];
extern BtlEventHandler gMirrorCoatHandlers[];
extern BtlEventHandler gMetalBurstHandlers[];
extern BtlEventHandler gLastResortHandlers[];

/*
 * Swallow, event CALC_HEAL_RATIO: heals a quarter, a half or all of the
 * maximum HP for one, two or three stockpiles (ratios in 20.12 fixed point).
 */
void HAND_WAZA_SwallowOnCalcHealRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    int two = 2;
    int ratio;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID)) {
        switch (BTL_POKEPARAM_GetCounter(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BPP_COUNTER_STOCKPILE)) {
        case 1:
        default:
            ratio = 1 << 10;
            break;
        case 2:
            ratio = two << 10;
            break;
        case 3:
            ratio = two << 11;
            break;
        }
        BTL_EVENT_OverwriteVar(HANDVAR_RATIO, ratio);
    }
}

/* Counter: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddCounter(int *handlerCount)
{
    *handlerCount = 3;
    return gCounterHandlers;
}

/* Counter, event MOVE_FAIL_CHECK: fails unless a physical hit was taken this turn. */
void HAND_WAZA_CounterOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnMoveFailCheck(flow, pokeId, work, BTL_DAMAGE_TYPE_PHYSICAL);
}

/* Counter, event DECIDE_TARGET: targets the Pokemon that dealt the physical hit. */
void HAND_WAZA_CounterOnDecideTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnDecideTarget(flow, pokeId, work, BTL_DAMAGE_TYPE_PHYSICAL);
}

/*
 * Counter, event CALC_FIXED_DAMAGE: twice the damage of the physical hit.
 * The three moves share one body; only the constants differ.
 */
void HAND_WAZA_CounterOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnCalcFixedDamage(flow, pokeId, work, BTL_DAMAGE_TYPE_PHYSICAL, 2 << 12);
}

/* Mirror Coat: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddMirrorCoat(int *handlerCount)
{
    *handlerCount = 3;
    return gMirrorCoatHandlers;
}

/* Mirror Coat, event MOVE_FAIL_CHECK: fails unless a special hit was taken this turn. */
void HAND_WAZA_MirrorCoatOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnMoveFailCheck(flow, pokeId, work, BTL_DAMAGE_TYPE_SPECIAL);
}

/* Mirror Coat, event DECIDE_TARGET: targets the Pokemon that dealt the special hit. */
void HAND_WAZA_MirrorCoatOnDecideTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnDecideTarget(flow, pokeId, work, BTL_DAMAGE_TYPE_SPECIAL);
}

/* Mirror Coat, event CALC_FIXED_DAMAGE: twice the damage of the special hit. */
void HAND_WAZA_MirrorCoatOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnCalcFixedDamage(flow, pokeId, work, BTL_DAMAGE_TYPE_SPECIAL, 2 << 12);
}

/* Metal Burst: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddMetalBurst(int *handlerCount)
{
    *handlerCount = 3;
    return gMetalBurstHandlers;
}

/* Metal Burst, event MOVE_FAIL_CHECK: fails unless any hit was taken this turn. */
void HAND_WAZA_MetalBurstOnMoveFailCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnMoveFailCheck(flow, pokeId, work, BTL_DAMAGE_TYPE_ANY);
}

/* Metal Burst, event DECIDE_TARGET: targets the Pokemon that dealt the last hit. */
void HAND_WAZA_MetalBurstOnDecideTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnDecideTarget(flow, pokeId, work, BTL_DAMAGE_TYPE_ANY);
}

/* Metal Burst, event CALC_FIXED_DAMAGE: one and a half times the damage of the last hit (6 << 10 is 1.5 in 20.12 fixed point). */
void HAND_WAZA_MetalBurstOnCalcFixedDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    HAND_WAZA_RetaliateOnCalcFixedDamage(flow, pokeId, work, BTL_DAMAGE_TYPE_ANY, 6 << 10);
}

/* Counter family, event MOVE_FAIL_CHECK: the move fails when no matching hit was taken. */
void HAND_WAZA_RetaliateOnMoveFailCheck(struct BtlSvFlow *flow, int pokeId, void *work, int damageType)
{
    struct BtlHitInfo hit;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID) && HAND_WAZA_FindRetaliateHit(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), damageType, &hit) == 0)
        BTL_EVENT_OverwriteVar(HANDVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
}

/*
 * Counter family, event DECIDE_TARGET: the target is the Pokemon that dealt the hit. When it
 * has left its position, the Pokemon now in that position is the target, then the
 * default target of a plain single-target move (move 1), then the attacker id as it was.
 */
void HAND_WAZA_RetaliateOnDecideTarget(struct BtlSvFlow *flow, int pokeId, void *work, int damageType)
{
    struct BtlHitInfo hit;
    int targetId;
    int pos;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        if (HAND_WAZA_FindRetaliateHit(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), damageType, &hit)) {
            targetId = hit.attackerId;
            if (BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, targetId) == BTL_POS_NONE) {
                pos = hit.attackerPos;
                targetId = BTL_POKEID_NONE;
                if (pos != BTL_POS_NONE)
                    targetId = BTL_SERVER_FLOW_GetPosTableEntryForPoke(flow, pos);
                if (targetId == BTL_POKEID_NONE) {
                    pos = BTL_SERVER_FLOW_DecideMoveTarget(flow, pokeId, 1);
                    if (pos != BTL_POS_NONE)
                        targetId = BTL_SERVER_FLOW_GetPosTableEntryForPoke(flow, pos);
                    if (targetId == BTL_POKEID_NONE)
                        targetId = hit.attackerId;
                }
            }
            BTL_EVENT_OverwriteVar(HANDVAR_DEFENDER_ID, targetId);
        }
    }
}

/* Counter family, event CALC_FIXED_DAMAGE: the damage of the hit times a ratio in 20.12 fixed point. */
void HAND_WAZA_RetaliateOnCalcFixedDamage(struct BtlSvFlow *flow, int pokeId, void *work, int damageType, int ratio)
{
    struct BtlHitInfo hit;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        if (HAND_WAZA_FindRetaliateHit(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), damageType, &hit)) {
            BTL_EVENT_OverwriteVar(HANDVAR_FIXED_DAMAGE, BTL_CALC_MulRatio(hit.damage, ratio));
        }
    }
}

/*
 * Counter family: looks through the hits taken this turn, newest first, for one
 * from a foe whose move has the damage type (0 matches any). Fills hit and returns 1 if found.
 */
int HAND_WAZA_FindRetaliateHit(struct BtlPokeParam *poke, int damageType, struct BtlHitInfo *out)
{
    u8 pokeId = BTL_POKEPARAM_GetPokeId(poke);
    u8 hitsAgo = 0;

    while (BTL_POKEPARAM_GetHitRecord(poke, 0, hitsAgo++, out)) {
        if (BTL_MAIN_IsPokeSamePair(pokeId, out->attackerId) == 0) {
            if (damageType == 0 || damageType == WAZA_TOOL_GetDamageType(out->moveId))
                return 1;
        }
    }
    return 0;
}

/* Last Resort (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddLastResort(int *handlerCount)
{
    *handlerCount = 1;
    return gLastResortHandlers;
}
