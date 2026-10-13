/*
 * file:     hand_waza_021e37c0.c
 * unit:     yes
 * function: HAND_WAZA_TrickOnWazaExecute, HAND_WAZA_MagnitudeOnWazaStart
 * address:  0x021E37C0
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
 *   gMagnitudeHandlers 0x021F2E58 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_POKEPARAM_GetSpecies 0x021D5444 thumb ov093
 *   BTLV_CORE_CheckPartySlotCondition 0x021E86C8 thumb ov093
 *   func_021E8638 0x021E8638 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   gMagnitudeRows  0x021F2878  data   a1
 *   (unused)  0x021F2879  data   a1
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *poke);
extern u16 BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *poke);
extern int BTLV_CORE_CheckPartySlotCondition(struct BtlSvFlow *flow, int pokeId);
extern int func_021E8638(int species, int itemId);
extern u32 func_0202136C(u16 itemId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(HandExStr *str, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(HandExStr *str, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *cmd);
extern u32 BTL_CALC_Random(u32 range);

void HAND_WAZA_TrickOnWazaExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddMagnitude(int *handlerCount);
void HAND_WAZA_MagnitudeOnWazaStart(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);

extern BtlEventHandler gMagnitudeHandlers[];
extern MagnitudeRow gMagnitudeRows[]; /* rolls below rollLimit give the row's Magnitude, the rows run from 4 to 10 */

/* Trick and Switcheroo: the user and the target exchange their held items. */
void HAND_WAZA_TrickOnWazaExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    u16 userItem;
    u16 targetItem;
    int userSpecies;
    int targetSpecies;
    HandExSwapItem *swap;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
    if (BTLV_CORE_CheckPartySlotCondition(flow, pokeId) != 0)
        return;
    user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    userItem = (int)BTL_POKEPARAM_GetItem(user);
    targetItem = (int)BTL_POKEPARAM_GetItem(target);
    if (userItem == 0 && targetItem == 0)
        return;
    userSpecies = BTL_POKEPARAM_GetSpecies(user);
    targetSpecies = BTL_POKEPARAM_GetSpecies(target);
    if (func_0202136C(userItem) != 0)
        return;
    if (func_0202136C(targetItem) != 0)
        return;
    if (func_021E8638(userSpecies, targetItem) != 0)
        return;
    if (func_021E8638(targetSpecies, userItem) != 0)
        return;
    if (func_021E8638(userSpecies, userItem) != 0)
        return;
    if (func_021E8638(targetSpecies, targetItem) != 0)
        return;
    swap = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SWAP_ITEM, pokeId);
    swap->targetId = targetId;
    BTL_SERVER_FLOW_InitMsgRecord(&swap->swapMessage, HANDEX_STR_SET, 682);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&swap->swapMessage, pokeId);
    if (targetItem != 0) {
        BTL_SERVER_FLOW_InitMsgRecord(&swap->userGetsMessage, HANDEX_STR_SET, 685);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&swap->userGetsMessage, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&swap->userGetsMessage, targetItem);
    }
    if (userItem != 0) {
        BTL_SERVER_FLOW_InitMsgRecord(&swap->targetGetsMessage, HANDEX_STR_SET, 685);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&swap->targetGetsMessage, targetId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&swap->targetGetsMessage, userItem);
    }
    BTL_SERVER_FLOW_CommitCmdRecord(flow, swap);
}

/* Magnitude. */
BtlEventHandler *HAND_WAZA_AddMagnitude(int *handlerCount)
{
    *handlerCount = 4;
    return gMagnitudeHandlers;
}

/* Magnitude: roll the magnitude, announce it and keep its power in the work word. */
void HAND_WAZA_MagnitudeOnWazaStart(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 row;
    u8 roll;
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        roll = BTL_CALC_Random(100);
        for (row = 0; row < MAGNITUDE_ROW_COUNT; row++) {
            if (roll < gMagnitudeRows[row].rollLimit)
                break;
        }
        *work = gMagnitudeRows[row].power;
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_STANDARD, (u16)(row + 0x68));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
    }
}
