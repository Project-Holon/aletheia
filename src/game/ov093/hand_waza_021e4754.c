/*
 * file:     hand_waza_021e4754.c
 * unit:     yes
 * function: HAND_WAZA_TauntOnUncategorizedMove, HAND_WAZA_AddTorment, HAND_WAZA_TormentOnUncategorizedMove, HAND_WAZA_AddDisable, HAND_WAZA_DisableOnUncategorizedMove, HAND_WAZA_AddImprison
 * address:  0x021E4754
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_MakeSickContTurns  0x021D7D78  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   gTormentHandlers     0x021F28A8  data   ov093  a4
 *   BTL_POKEPARAM_GetLastSelectedMoveId  0x021D67B8  thumb  ov093
 *   BTL_POKEPARAM_HasMove  0x021D5750  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   gDisableHandlers     0x021F2764  data   ov093  a4
 *   gImprisonHandlers     0x021F2534  data   ov093  a4
 */
#include "hand_waza_021e4754_types.h"

void HAND_WAZA_TauntOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddTorment(int *handlerCount);
void HAND_WAZA_TormentOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddDisable(int *handlerCount);
void HAND_WAZA_DisableOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_WAZA_AddImprison(int *handlerCount);
/*
 * stand-in: an enum typed local keeps its start value from being folded into
 * the (u8) increment (a u8 or int local gets 4 here, the image has 3 plus an add).
 */
typedef enum { BTL_TURN_COUNT_NONE } BtlTurnCount;
#define BTL_TAUNT_TURNS 3
#define BTL_DISABLE_TURNS 4

extern BtlEventHandler gTormentHandlers[];
extern BtlEventHandler gDisableHandlers[];
extern BtlEventHandler gImprisonHandlers[];

/* Taunt: the user taunts the target for 3 turns, 4 when the target already acted this turn. */
void HAND_WAZA_TauntOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlTurnCount turns = BTL_TAUNT_TURNS;
    u8 targetId;
    struct BtlPokeParam *target;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_HasSick(target, BTL_SICK_TAUNT) == 0) {
            if (BTL_POKEPARAM_TestTurnFlag(target, BTL_TURN_FLAG_ACTED) != 0)
                turns = (u8)(turns + 1);
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_TAUNT;
            record->sickCont = BTL_CALC_MakeSickContTurns(turns);
            record->pokeId = targetId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}

BtlEventHandler *HAND_WAZA_AddTorment(int *handlerCount)
{
    *handlerCount = 2;
    return gTormentHandlers;
}

/* Torment: the target cannot use the same move twice in a row (permanent status). */
void HAND_WAZA_TormentOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    struct BtlPokeParam *target;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_HasSick(target, BTL_SICK_TORMENT) == 0) {
            record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            record->sickKind = BTL_SICK_TORMENT;
            record->sickCont = BTLV_CORE_MakeSlotKind1Empty();
            record->pokeId = targetId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
        }
    }
}

BtlEventHandler *HAND_WAZA_AddDisable(int *handlerCount)
{
    *handlerCount = 1;
    return gDisableHandlers;
}

/* Disable: the target cannot use its last selected move for 4 turns, 5 when it already acted this turn. */
void HAND_WAZA_DisableOnUncategorizedMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlTurnCount turns;
    u8 targetId;
    struct BtlPokeParam *target;
    int moveId;
    struct HandExAddSick *record;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_HasSick(target, BTL_SICK_DISABLE) == 0) {
            moveId = BTL_POKEPARAM_GetLastSelectedMoveId(target);
            if (moveId != 0 && moveId != BTL_MOVE_STRUGGLE && BTL_POKEPARAM_HasMove(target, moveId) != 0) {
                turns = BTL_DISABLE_TURNS;
                if (BTL_POKEPARAM_TestTurnFlag(target, BTL_TURN_FLAG_ACTED) != 0)
                    turns = (u8)(turns + 1);
                record = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
                record->sickKind = BTL_SICK_DISABLE;
                record->sickCont = BTLV_CORE_MakeSlotKind2(turns, moveId);
                record->pokeId = targetId;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, record);
            }
        }
    }
}

BtlEventHandler *HAND_WAZA_AddImprison(int *handlerCount)
{
    *handlerCount = 1;
    return gImprisonHandlers;
}
