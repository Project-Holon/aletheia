/*
 * file:     hand_waza_021e12a4.c
 * unit:     yes
 * function: HAND_WAZA_ChatterOnDecideAddSick, HAND_WAZA_AddTrap, HAND_WAZA_TrapOnDecideAddSick, HAND_WAZA_TrapOnAddSickMessage, HAND_WAZA_AddWhirlpool, HAND_WAZA_WhirlpoolOnInvulnerableCheck, HAND_WAZA_WhirlpoolOnCalcDamageRatio, HAND_WAZA_AddSuperFang
 * address:  0x021E12A4
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
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_SERVER_FLOW_QueryPokeClientFlag  0x021C7ED8  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   BTL_CALC_MakeSickContFromKind  0x021D7DC0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTLV_CORE_SetSlotValue  0x021E8B28  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gBindSickHandlers     0x021F2918  data   ov093  a4
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gWhirlpoolHandlers     0x021F2D98  data   ov093  a4
 *   gSuperFangHandlers     0x021F25A4  data   ov093  a4
 */
#include "hand_waza_021e10d8_types.h"

/* The status that Chatter adds; an enum local keeps the constant in a register (see below). */
typedef enum { CHATTER_SICK_CONFUSION = BTL_SICK_CONFUSION } ChatterSick;

void HAND_WAZA_ChatterOnDecideAddSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddTrap(int *handlerCount);
void HAND_WAZA_TrapOnDecideAddSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_TrapOnAddSickMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddWhirlpool(int *handlerCount);
void HAND_WAZA_WhirlpoolOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_WhirlpoolOnCalcDamageRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSuperFang(int *handlerCount);
extern BtlEventHandler gBindSickHandlers[];
extern BtlEventHandler gWhirlpoolHandlers[];
extern BtlEventHandler gSuperFangHandlers[];

#define SPECIES_CHATOT 0x1b9

/*
 * Chatter, event DECIDE_ADD_SICK: only Chatot confuses, with a chance of 10
 * percent, or 30 percent when the Pokemon has used the move more than twice.
 * Lever: the constant 6 lives in r5 across the calls (movs r5,#6 before the
 * BTL_POKEPARAM_GetMon bl); an int local folds it into each use, an enum local keeps it.
 */
void HAND_WAZA_ChatterOnDecideAddSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *attacker;
    u32 useCount;
    ChatterSick sickId;
    int percent;
    union SickCont sickCont;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetSpecies(attacker) == SPECIES_CHATOT) {
            useCount = BTL_SERVER_FLOW_QueryPokeClientFlag(flow, pokeId);
            if (useCount != 0) {
                sickId = CHATTER_SICK_CONFUSION;
                BTL_POKEPARAM_GetMon(attacker);
                if (useCount > 2)
                    percent = 30;
                else
                    percent = 10;
                BTL_CALC_MakeSickContFromKind(sickId, attacker, &sickCont);
                BTL_EVENT_OverwriteVar(HANDVAR_SICK_ID, sickId);
                BTL_EVENT_OverwriteVar(HANDVAR_SICK_CONT, sickCont.raw);
                BTL_EVENT_OverwriteVar(HANDVAR_ADD_SICK_PERCENT, percent);
            }
        }
    }
}

/* Wrap, Bind, Fire Spin, Clamp, Sand Tomb, Magma Storm: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddTrap(int *handlerCount)
{
    *handlerCount = 2;
    return gBindSickHandlers;
}

/* Trap moves, event DECIDE_ADD_SICK: records the move id in the status data. */
void HAND_WAZA_TrapOnDecideAddSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    union SickCont sickCont;
    u16 moveId;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    moveId = BTL_EVENT_GetFactorKey(factor);
    sickCont.raw = BTL_EVENT_GetVar(HANDVAR_SICK_CONT);
    BTLV_CORE_SetSlotValue(&sickCont, moveId);
    BTL_EVENT_OverwriteVar(HANDVAR_SICK_CONT, sickCont.raw);
}

/* Trap moves, event ADD_SICK_MESSAGE: shows the message of the move that trapped the target. */
void HAND_WAZA_TrapOnAddSickMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct HandExMessage *message;
    u8 defenderId;
    int messageId;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    if (BTL_EVENT_GetVar(HANDVAR_SICK_ID) != BTL_SICK_TRAP)
        return;
    message = (struct HandExMessage *)BTL_EVENT_GetVar(HANDVAR_MESSAGE);
    defenderId = BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID);
    switch (BTL_EVENT_GetFactorKey(factor)) {
    case 0x23: /* Wrap */
        messageId = 0x32a;
        break;
    case 0x14: /* Bind */
        messageId = 0x323;
        break;
    case 0x53: /* Fire Spin */
        messageId = 0x33b;
        break;
    case 0x80: /* Clamp */
        messageId = 0x331;
        break;
    case 0x148: /* Sand Tomb */
        messageId = 0x341;
        break;
    case 0x1cf: /* Magma Storm */
        messageId = 0x33e;
        break;
    case 0xfa: /* Whirlpool */
        messageId = 0x338;
        break;
    default:
        return;
    }
    BTL_SERVER_FLOW_InitMsgRecord(message, HANDEX_MESSAGE_SET, messageId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(message, defenderId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(message, pokeId);
}

/* Whirlpool: stores the handler count and returns the handler table (the trap handlers plus two of its own). */
BtlEventHandler *HAND_WAZA_AddWhirlpool(int *handlerCount)
{
    *handlerCount = 4;
    return gWhirlpoolHandlers;
}

/* Whirlpool, event INVULNERABLE_CHECK: hits a target that is underwater (Dive). */
void HAND_WAZA_WhirlpoolOnInvulnerableCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_EVENT_GetVar(HANDVAR_SEMI_INVULNERABLE) == BTL_SEMI_INVULNERABLE_UNDERWATER)
        BTL_EVENT_OverwriteVar(HANDVAR_AVOID_FLAG, 0);
}

/* Whirlpool, event CALC_DAMAGE_RATIO: doubles the damage against a target that is underwater. */
void HAND_WAZA_WhirlpoolOnCalcDamageRatio(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    int underwaterFlag;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        underwaterFlag = 4;
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(HANDVAR_DEFENDER_ID)), underwaterFlag)) {
            BTL_EVENT_MultiplyVar(HANDVAR_RATIO, underwaterFlag << 11);
        }
    }
}

/* Super Fang (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSuperFang(int *handlerCount)
{
    *handlerCount = 1;
    return gSuperFangHandlers;
}
