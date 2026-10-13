/*
 * file:     hand_side.c
 * unit:     yes
 * function: HAND_SIDE_InitTable, HAND_SIDE_AddFactor, HAND_SIDE_GetStackCount, HAND_SIDE_IsActive, HAND_SIDE_Remove, HAND_SIDE_TickTurns, HAND_SIDE_GetStackCountByFactor, HAND_SIDE_GetHandlersReflect, HAND_SIDE_ScreenReduceDamage, HAND_SIDE_GetHandlersSafeguard, HAND_SIDE_SafeguardBlockSick, HAND_SIDE_SafeguardNoticeBlocked, HAND_SIDE_GetHandlersMist, HAND_SIDE_MistBlockStatDrop, HAND_SIDE_MistNoticeStatDrop, HAND_SIDE_GetHandlersTailwind, HAND_SIDE_TailwindDoubleSpeed, HAND_SIDE_GetHandlersLuckyChant, HAND_SIDE_LuckyChantBlockCritical, HAND_SIDE_GetHandlersStealthRock, HAND_SIDE_StealthRockHurtOnEnter, HAND_SIDE_GetHandlersWideGuard, HAND_SIDE_WideGuardBlockSpreadMove, HAND_SIDE_GetHandlersQuickGuard, HAND_SIDE_QuickGuardBlockPriorityMove
 * address:  0x06898BFC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *

 *
 * symbols:
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   BTL_EVENT_SetFactorWork  0x021D70DC  thumb
 *   gHandSideEffectSlots 0x0689E7E0 data a4
 *   MI_CpuFill8 0x02082BCC arm
 *   gHandSideEffectTable 0x0689D780 data ov095 a4
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb
 *   BTL_MAIN_IsPokeIdInSecondPair  0x021B9A40  thumb
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   gHandSideReflectHandlers     0x0689D6F0  data   ov095  a4
 *   gHandSideLightScreenHandlers     0x0689D710  data   ov095  a4
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_CALC_HasDefaultSickCont  0x021D7D6C  thumb  ov093
 *   gHandSideSafeguardHandlers  0x0689D748  data  ov095  a4
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gHandSideMistHandlers  0x0689D758  data  ov095  a4
 *   gHandSideTailwindHandlers  0x0689D738  data  ov095  a4
 *   gHandSideLuckyChantHandlers  0x0689D730  data  ov095  a4
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTL_CALC_GetTypeAffinityVsPair  0x021D799C  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   gHandSideStealthRockHandlers  0x0689D728  data  ov095  a4
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb  arm9
 *   WAZA_TOOL_IsDamaging  0x0201C314  thumb  arm9
 *   gHandSideWideGuardHandlers  0x0689D700  data  ov095  a4
 *   gHandSideQuickGuardHandlers  0x0689D718  data  ov095  a4
 */
#include "hand_field_types.h"
#include "hand_side_types.h"

extern void MI_CpuFill8(void *dst, int value, int size);
extern void BTL_EVENT_SetFactorWork(struct BtlEventFactor *factor, int index, u32 value);
extern int BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int BTL_SERVER_FLOW_GetRule(struct BtlSvFlow *flow);
void HAND_SIDE_InitTable(void);
struct BtlEventFactor *HAND_SIDE_AddFactor(u8 side, int effectId, BtlEffectCont cont);
u32 HAND_SIDE_GetStackCount(u32 side, u32 effectId);
int HAND_SIDE_IsActive(int side, int effectId);
int HAND_SIDE_Remove(u32 side, u32 effectId);
void HAND_SIDE_TickTurns(void (*onExpired)(u8 side, u32 effectId, u32 arg), u32 arg);
int HAND_SIDE_GetStackCountByFactor(struct BtlEventFactor *factor, u32 side);
const BtlEventHandler *HAND_SIDE_GetHandlersReflect(u32 *handlerCount);
void HAND_SIDE_ReflectOnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, void *work);
const BtlEventHandler *HAND_SIDE_GetHandlersLightScreen(u32 *handlerCount);
void HAND_SIDE_LightScreenOnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, void *work);
void HAND_SIDE_ScreenReduceDamage(struct BtlSvFlow *flow, int side, int damageType);
const BtlEventHandler *HAND_SIDE_GetHandlersSafeguard(u32 *handlerCount);
void HAND_SIDE_SafeguardBlockSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
void HAND_SIDE_SafeguardNoticeBlocked(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersMist(u32 *handlerCount);
void HAND_SIDE_MistBlockStatDrop(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
void HAND_SIDE_MistNoticeStatDrop(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersTailwind(u32 *handlerCount);
void HAND_SIDE_TailwindDoubleSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersLuckyChant(u32 *handlerCount);
void HAND_SIDE_LuckyChantBlockCritical(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersStealthRock(u32 *handlerCount);
void HAND_SIDE_StealthRockHurtOnEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersWideGuard(u32 *handlerCount);
void HAND_SIDE_WideGuardBlockSpreadMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
const BtlEventHandler *HAND_SIDE_GetHandlersQuickGuard(u32 *handlerCount);
void HAND_SIDE_QuickGuardBlockPriorityMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work);
extern BtlSideEffectRow gHandSideEffectSlots[BTL_SIDE_COUNT];
extern const HandSideEffectEntry gHandSideEffectTable[BTL_SIDEEFF_COUNT];
extern const BtlEventHandler gHandSideReflectHandlers[1];
extern const BtlEventHandler gHandSideLightScreenHandlers[1];
extern const BtlEventHandler gHandSideSafeguardHandlers[];
extern const BtlEventHandler gHandSideMistHandlers[];
extern const BtlEventHandler gHandSideTailwindHandlers[];
extern const BtlEventHandler gHandSideLuckyChantHandlers[];
extern const BtlEventHandler gHandSideStealthRockHandlers[];
extern const BtlEventHandler gHandSideWideGuardHandlers[];
extern const BtlEventHandler gHandSideQuickGuardHandlers[];


/* Clears the state of all side effects on both sides. */
void HAND_SIDE_InitTable(void)
{
    MI_CpuFill8(gHandSideEffectSlots, 0, sizeof(gHandSideEffectSlots));
}


/*
 * Starts side effect effectId on `side`, or adds a layer if it is already active and below its
 * layer limit (Spikes, Toxic Spikes). `cont` says how long the effect lasts. Returns the factor,
 * or 0 when the id is unknown or the effect is at its layer limit.
 */
struct BtlEventFactor *HAND_SIDE_AddFactor(u8 side, int effectId, BtlEffectCont cont)
{
    BtlSideEffectSlot *slot = &gHandSideEffectSlots[side].effects[effectId];
    u32 i;
    u32 handlerCount;
    for (i = 0; i < BTL_SIDEEFF_COUNT; i++) {
        if (effectId == gHandSideEffectTable[i].effectId) {
            if (slot->layers == 0) {
                struct BtlEventFactor *factor;
                const BtlEventHandler *handlers = gHandSideEffectTable[i].getHandlers(&handlerCount);
                factor = BTL_EVENT_AddFactor(BTL_EVENT_TYPE_SIDE_EFFECT, effectId, 2, 0, side, (u32)handlers, handlerCount);
                BTL_EVENT_SetFactorWork(factor, 6, cont.raw);
                slot->layers = 1;
                slot->turnsElapsed = 0;
                slot->cont.raw = cont.raw;
                slot->factor = factor;
                return factor;
            }
            if (slot->layers < gHandSideEffectTable[i].maxLayers) {
                slot->layers++;
                return slot->factor;
            }
        }
    }
    return 0;
}


/* Number of stacked layers of the effect on the side (0 when inactive). */
u32 HAND_SIDE_GetStackCount(u32 side, u32 effectId)
{
    return gHandSideEffectSlots[side].effects[effectId].layers;
}


/*
 * Indexed presence test: the effect is active on the side when its slot holds a factor.
 */
int HAND_SIDE_IsActive(int side, int effectId)
{
    return gHandSideEffectSlots[side].effects[effectId].factor != 0;
}


/* Ends the effect on the side. Returns 1 if it was active. */
int HAND_SIDE_Remove(u32 side, u32 effectId)
{
    BtlSideEffectSlot *slot = &gHandSideEffectSlots[side].effects[effectId];
    if (slot->factor != 0) {
        BTL_EVENT_RemoveFactor(slot->factor);
        slot->factor = 0;
        slot->layers = 0;
        slot->cont.bits.kind = 0;
        return 1;
    }
    return 0;
}


/*
 * End of turn: every timed effect advances by one turn. An effect whose turn limit is
 * reached is removed and onExpired(side, effectId, arg) is called for it.
 */
void HAND_SIDE_TickTurns(void (*onExpired)(u8 side, u32 effectId, u32 arg), u32 arg)
{
    u32 side;
    u32 effectId;

    for (side = 0; side < BTL_SIDE_COUNT; side++) {
        BtlSideEffectRow *row;

        effectId = 0;
        row = &gHandSideEffectSlots[side];

        for (; effectId < BTL_SIDEEFF_COUNT; effectId++) {
            BtlSideEffectSlot *slot = &row->effects[effectId];

            if (slot->layers != 0 && slot->cont.bits.kind == BTL_EFFECT_CONT_TIMED) {
                slot->turnsElapsed++;
                if (slot->turnsElapsed >= slot->cont.bits.turnLimit) {
                    slot->layers = 0;
                    slot->cont.bits.kind = 0;
                    BTL_EVENT_RemoveFactor(slot->factor);
                    slot->factor = 0;
                    onExpired(side, effectId, arg);
                }
            }
        }
    }
}


/* Layers of the effect that `factor` belongs to, on the side; 0 for an unknown effect or side. */
int HAND_SIDE_GetStackCountByFactor(struct BtlEventFactor *factor, u32 side)
{
    int effectId;
    effectId = BTL_EVENT_GetFactorKey(factor);
    if (effectId < BTL_SIDEEFF_COUNT && side < BTL_SIDE_COUNT)
        return (u8)gHandSideEffectSlots[side].effects[effectId].layers;
    return 0;
}


/*
 * Handed extent 0x06898E0C (72 bytes) opens with a 16-byte `bx pc` veneer
 * to BTL_EVENT_GetFactorKey (ARM linker stub, not compilable); the four functions after
 * it (0x06898E1C..0x06898E54) are this unit. 0x06898E1C and 0x06898E38 are
 * rows of the handler tables at 0x0689D6F0 / 0x0689D710.
 */

/* Handler list of Reflect: one entry on the damage ratio event. */
const BtlEventHandler *HAND_SIDE_GetHandlersReflect(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandSideReflectHandlers;
}


/* Reflect: reduces physical damage. */
void HAND_SIDE_ReflectOnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, void *work)
{
    HAND_SIDE_ScreenReduceDamage(flow, side, BTL_DAMAGE_TYPE_PHYSICAL);
}


/* Handler list of Light Screen: one entry on the damage ratio event. */
const BtlEventHandler *HAND_SIDE_GetHandlersLightScreen(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandSideLightScreenHandlers;
}


/* Light Screen: reduces special damage. */
void HAND_SIDE_LightScreenOnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, void *work)
{
    HAND_SIDE_ScreenReduceDamage(flow, side, BTL_DAMAGE_TYPE_SPECIAL);
}


/*
 * Screen damage reduction: when the defender is on the screen's side, the move has the damage
 * category the screen covers and the hit is not a critical hit, the damage ratio is multiplied
 * by one half (one active Pokemon per side) or about two thirds (two or three).
 */
void HAND_SIDE_ScreenReduceDamage(struct BtlSvFlow *flow, int side, int damageType)
{
    u8 defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);

    if (side == BTL_MAIN_IsPokeIdInSecondPair(defenderId) && damageType == BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) && BTL_EVENT_GetVar(BTL_EVAR_CRITICAL_FLAG) == 0) {
        int rule = BTL_SERVER_FLOW_GetRule(flow);

        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, (rule == BTL_RULE_SINGLE || rule == BTL_RULE_ROTATION) ? HAND_RATIO_SCREEN_SINGLES : HAND_RATIO_SCREEN_DOUBLES);
    }
}


/* Safeguard: two handlers (block a status condition, show the notice). */
const BtlEventHandler *HAND_SIDE_GetHandlersSafeguard(u32 *handlerCount)
{
    *handlerCount = 2;
    return gHandSideSafeguardHandlers;
}


/* Blocks a status condition that another Pokemon inflicts on the protected side. */
void HAND_SIDE_SafeguardBlockSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    u8 defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    int sickId;

    if (side == BTL_MAIN_IsPokeIdInSecondPair(defenderId) && defenderId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        sickId = BTL_EVENT_GetVar(BTL_EVAR_SICK_ID);
        if (BTL_CALC_HasDefaultSickCont(sickId) != 0 || sickId == BTL_SICK_CONFUSION || sickId == BTL_SICK_YAWN)
            *work = BTL_EVENT_OverwriteVar(HAND_SIDE_EVAR_PREVENT_FLAG, 1);
    }
}


/* Shows the Safeguard notice once after a status condition was blocked. */
void HAND_SIDE_SafeguardNoticeBlocked(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    u8 defenderId;
    struct HandExMessage *cmd;

    if (*work != 0) {
        defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, defenderId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_MESSAGE_SET, BTL_MSG_SAFEGUARD_BLOCKED);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, defenderId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        *work = 0;
    }
}


/* Mist: two handlers (block a stat drop, show the notice). */
const BtlEventHandler *HAND_SIDE_GetHandlersMist(u32 *handlerCount)
{
    *handlerCount = 2;
    return gHandSideMistHandlers;
}


/* Blocks a stat drop that another Pokemon causes on the protected side. */
void HAND_SIDE_MistBlockStatDrop(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    u8 pokeId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);

    if (side == BTL_MAIN_IsPokeIdInSecondPair(pokeId)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_VOLUME) < 0) {
            if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
                *work = BTL_EVENT_OverwriteVar(HAND_SIDE_EVAR_PREVENT_FLAG, 1);
            }
        }
    }
}


/* Work slot 0: a stat drop was blocked. Work slot 1: the stat of the last notice. */
void HAND_SIDE_MistNoticeStatDrop(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    int statId;
    u8 pokeId;
    struct HandExMessage *cmd;

    if (work[0] != 0) {
        statId = BTL_EVENT_GetVar(HAND_SIDE_EVAR_STAT_ID);
        if (statId == 0 || work[1] != statId) {
            pokeId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_MESSAGE_SET, BTL_MSG_MIST_BLOCKED);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            work[1] = statId;
        }
        work[0] = 0;
    }
}


/* Tailwind: one handler (double the speed). */
const BtlEventHandler *HAND_SIDE_GetHandlersTailwind(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandSideTailwindHandlers;
}


/* Doubles the speed ratio of the Pokemon on the side with Tailwind. */
void HAND_SIDE_TailwindDoubleSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    u8 pokeId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);

    if (side == BTL_MAIN_IsPokeIdInSecondPair(pokeId)) {
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, HAND_RATIO_DOUBLE);
    }
}


/* Lucky Chant: one handler (block critical hits). */
const BtlEventHandler *HAND_SIDE_GetHandlersLuckyChant(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandSideLuckyChantHandlers;
}


/* Blocks critical hits against the protected side. */
void HAND_SIDE_LuckyChantBlockCritical(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    u8 defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);

    if (side == BTL_MAIN_IsPokeIdInSecondPair(defenderId)) {
        BTL_EVENT_OverwriteVar(HAND_SIDE_EVAR_PREVENT_FLAG, 1);
    }
}


/* Stealth Rock: one handler (hurt a Pokemon that enters). */
const BtlEventHandler *HAND_SIDE_GetHandlersStealthRock(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandSideStealthRockHandlers;
}


/* Hurts a Pokemon that enters the side: 1/2 of its max HP at quadruple weakness down to 1/32 at quadruple resistance. */
void HAND_SIDE_StealthRockHurtOnEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    int divisor;
    u8 pokeId;
    struct BtlPokeParam *bpp;
    struct HandExDamage *cmd;

    divisor = 2;
    pokeId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
    if (side == BTL_MAIN_IsPokeIdInSecondPair(pokeId)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        switch (BTL_CALC_GetTypeAffinityVsPair(BTL_TYPE_ROCK, BTL_POKEPARAM_GetTypePair(bpp))) {
        default:
            divisor = 0x20;
            break;
        case BTL_AFFINITY_CLASS_HALF:
            divisor = 0x10;
            break;
        case BTL_AFFINITY_CLASS_NEUTRAL:
            divisor = 8;
            break;
        case BTL_AFFINITY_CLASS_DOUBLE:
            divisor = 4;
            break;
        case BTL_AFFINITY_CLASS_QUADRUPLE:
            break;
        }
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_DAMAGE, 0x1f);
        cmd->pokeId = pokeId;
        cmd->amount = BTL_CALC_DivideMaxHpMin1(bpp, divisor);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, HANDEX_MESSAGE_SET, BTL_MSG_STEALTH_ROCK_HURT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Wide Guard: one handler (block moves that hit several Pokemon). */
const BtlEventHandler *HAND_SIDE_GetHandlersWideGuard(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandSideWideGuardHandlers;
}


/* Blocks a damaging move whose target range is several Pokemon and shows the notice. */
void HAND_SIDE_WideGuardBlockSpreadMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    u8 defenderId;
    u16 moveId;
    u32 targetRange;
    BtlStrParam *message;

    defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    if (side == BTL_MAIN_IsPokeIdInSecondPair(defenderId)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        targetRange = WAZA_TOOL_GetParam(moveId, WAZA_PARAM_TARGET_RANGE);
        if (WAZA_TOOL_IsDamaging(moveId) != 0) {
            if (targetRange == WAZA_RANGE_ALL_ENEMIES || targetRange == WAZA_RANGE_ALL_OTHERS) {
                if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
                    message = (BtlStrParam *)BTL_EVENT_GetVar(HAND_SIDE_EVAR_MESSAGE_PARAM);
                    BTL_SERVER_FLOW_InitMsgRecord(message, HANDEX_MESSAGE_SET, BTL_MSG_WIDE_GUARD_BLOCKED);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(message, (int)defenderId);
                }
            }
        }
    }
}


/* Quick Guard: one handler (block moves with raised priority). */
const BtlEventHandler *HAND_SIDE_GetHandlersQuickGuard(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandSideQuickGuardHandlers;
}


/* Blocks a move of positive priority that another Pokemon aims at the protected side and shows the notice. */
void HAND_SIDE_QuickGuardBlockPriorityMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int side, int *work)
{
    u8 defenderId;
    BtlStrParam *message;

    defenderId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    if (side == BTL_MAIN_IsPokeIdInSecondPair(defenderId) && defenderId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && (s32)WAZA_TOOL_GetParam(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), WAZA_PARAM_PRIORITY) >= 1
        && BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
        message = (BtlStrParam *)BTL_EVENT_GetVar(HAND_SIDE_EVAR_MESSAGE_PARAM);
        BTL_SERVER_FLOW_InitMsgRecord(message, HANDEX_MESSAGE_SET, BTL_MSG_QUICK_GUARD_BLOCKED);
        BTL_SERVER_FLOW_AppendMsgRecordArg(message, (int)defenderId);
    }
}
