/*
 * file:     hand_waza_021e3420.c
 * unit:     yes
 * function: HAND_WAZA_KnockOffOnDamageEnd, HAND_WAZA_AddMagicCoat, HAND_WAZA_MagicCoatOnExecuteCheck, HAND_WAZA_MagicCoatOnWazaExecute, HAND_WAZA_MagicCoatOnWazaNotice, HAND_WAZA_MagicCoatOnTurnEnd, HAND_WAZA_AddSnatch, HAND_WAZA_SnatchOnWazaExecute, HAND_WAZA_SnatchOnSnatchCheck, HAND_WAZA_SnatchOnSnatched, HAND_WAZA_SnatchOnTurnEnd, HAND_WAZA_AddThief, HAND_WAZA_ThiefOnWazaPrepare, HAND_WAZA_ThiefOnDamageEnd
 * address:  0x021E3420
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
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTLV_CORE_CheckEitherSlotPair   0x021E86E8  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_GetItem   0x021D5B40  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord   0x021C8838  thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg   0x021C8860  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   func_021E8624  0x021E8624  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTLV_CORE_EventRedirectMove  0x021E8744  thumb  ov093
 *   BTLV_CORE_EventCounterMove  0x021E8798  thumb  ov093
 *   BTLV_CORE_EventQueueMoveNotice  0x021E8804  thumb  ov093
 *   BTL_EVENT_RemoveFactor   0x021D7040  thumb
 *   gMagicCoatHandlers     0x021F2F18  data   ov093  a4
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   gSnatchHandlers     0x021F2E38  data   ov093  a4
 *   gTrickHandlers 0x021F2824 data a4
 *   gThiefHandlers     0x021F2A98  data   ov093  a4
 */
#include "hand_waza_021e2988_types.h"

int BTL_EVENT_GetVar(int varId);
int BTLV_CORE_CheckEitherSlotPair(struct BtlSvFlow *flow, int pokeId, int otherPokeId);
struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *poke);
void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int cmdKind, int pokeId);
void BTL_SERVER_FLOW_InitMsgRecord(HandExStr *str, int strType, int strId);
void BTL_SERVER_FLOW_AppendMsgRecordArg(HandExStr *str, unsigned int arg);
void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *cmd);
extern int func_021E8624(struct BtlSvFlow *flow, int pokeId);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeId, unsigned int otherPokeId);
extern void BTLV_CORE_EventRedirectMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
extern void BTLV_CORE_EventCounterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
extern void BTLV_CORE_EventQueueMoveNotice(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
extern void BTL_EVENT_RemoveFactor(struct BtlEventFactor *factor);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *poke, int sickKind);

void HAND_WAZA_KnockOffOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddMagicCoat(int *handlerCount);
void HAND_WAZA_MagicCoatOnExecuteCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnWazaExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnWazaCounter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnWazaNotice(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_MagicCoatOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSnatch(int *handlerCount);
void HAND_WAZA_SnatchOnWazaExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_SnatchOnSnatchCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_SnatchOnSnatched(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_SnatchOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddThief(int *handlerCount);
void HAND_WAZA_ThiefOnWazaPrepare(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_ThiefOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTrick(int *handlerCount);

extern BtlEventHandler gMagicCoatHandlers[];
extern BtlEventHandler gSnatchHandlers[];
extern BtlEventHandler gTrickHandlers[];
extern BtlEventHandler gThiefHandlers[];

/* Knock Off: remove the item that the target holds. */
void HAND_WAZA_KnockOffOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    u16 itemId;
    HandExSetItem *setItem;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    targetId = (u8)BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
    if (BTLV_CORE_CheckEitherSlotPair(flow, pokeId, targetId) != 0)
        return;
    itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, targetId));
    if (itemId == 0)
        return;
    setItem = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SET_ITEM, pokeId);
    setItem->pokeId = targetId;
    setItem->itemId = 0;
    BTL_SERVER_FLOW_InitMsgRecord(&setItem->str, HANDEX_STR_SET, 0x41a);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&setItem->str, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&setItem->str, targetId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&setItem->str, itemId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, setItem);
}

/* Magic Coat. */
BtlEventHandler *HAND_WAZA_AddMagicCoat(int *handlerCount)
{
    *handlerCount = 5;
    return gMagicCoatHandlers;
}

/* Magic Coat: the user cannot use it when it is not allowed; moves of other Pokemon may be reflected. */
void HAND_WAZA_MagicCoatOnExecuteCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 userId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
    if (userId == pokeId) {
        if (func_021E8624(flow, pokeId) != 0) {
            BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_MOVE_FAILED);
            return;
        }
    } else if (BTL_MAIN_IsPokeSamePair(pokeId, userId) == 0) {
        BTLV_CORE_EventRedirectMove(factor, flow, pokeId, work);
    }
}

/* Magic Coat: announce the effect once when the user uses the move. */
void HAND_WAZA_MagicCoatOnWazaExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && work[WAZA_WORK_ANNOUNCED] == 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 761);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        work[WAZA_WORK_ANNOUNCED] = 1;
    }
}

/* Magic Coat: reflect the move back at its user. */
void HAND_WAZA_MagicCoatOnWazaCounter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BTLV_CORE_EventCounterMove(factor, flow, pokeId, work);
}

/* Magic Coat: the first bounce of the turn queues the move notice. */
void HAND_WAZA_MagicCoatOnWazaNotice(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1) != 0)
            BTLV_CORE_EventQueueMoveNotice(factor, flow, pokeId, work);
    }
}

/* Magic Coat: the effect ends with the turn. */
void HAND_WAZA_MagicCoatOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}

/* Snatch. */
BtlEventHandler *HAND_WAZA_AddSnatch(int *handlerCount)
{
    *handlerCount = 4;
    return gSnatchHandlers;
}

/* Snatch: announce the effect when the user uses the move. */
void HAND_WAZA_SnatchOnWazaExecute(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && func_021E8624(flow, pokeId) == 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 751);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        work[WAZA_WORK_ANNOUNCED] = 1;
    }
}

/* Snatch: take over a stealable move that another Pokemon is about to use. */
void HAND_WAZA_SnatchOnSnatchCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId != pokeId) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), WAZA_FLAG_SNATCH) != 0) {
            if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_SNATCH_BLOCK) == 0) {
                if (BTL_EVENT_OverwriteVar(BTL_EVAR_POKE_ID, pokeId) != 0) {
                    BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, pokeId);
                    *work = 1;
                }
            }
        }
    }
}

/* Snatch: show the message that the move was snatched, then end the effect. */
void HAND_WAZA_SnatchOnSnatched(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HandExMessage *message;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 754);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID));
        BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        BTL_EVENT_RemoveFactor(factor);
    }
}

/* Snatch: the effect ends with the turn. */
void HAND_WAZA_SnatchOnTurnEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_RemoveFactor(factor);
}

/* Thief and Covet. */
BtlEventHandler *HAND_WAZA_AddThief(int *handlerCount)
{
    *handlerCount = 2;
    return gThiefHandlers;
}

/* Thief and Covet: remember whether the user already holds an item. */
void HAND_WAZA_ThiefOnWazaPrepare(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        *work = (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) ? 1 : 0;
}

/* Thief and Covet: after the hit, take the item of the target when the user holds none. */
void HAND_WAZA_ThiefOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    struct BtlPokeParam *target;
    HandExSwapItem *steal;
    HandExFlagRecord *flag;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0)
        return;
    if (*work != 0)
        return;
    targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
    if (targetId == BTL_EVENT_NO_POKE)
        return;
    target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
    if (BTL_POKEPARAM_GetItem(target) == 0)
        return;
    if (BTLV_CORE_CheckEitherSlotPair(flow, pokeId, targetId) != 0)
        return;
    steal = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_SWAP_ITEM, pokeId);
    steal->targetId = targetId;
    BTL_SERVER_FLOW_InitMsgRecord(&steal->swapMessage, HANDEX_STR_SET, 1057);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&steal->swapMessage, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&steal->swapMessage, targetId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&steal->swapMessage, BTL_POKEPARAM_GetItem(target));
    BTL_SERVER_FLOW_CommitCmdRecord(flow, steal);
    flag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FLAG_RECORD, pokeId);
    flag->header |= HANDEX_FLAG_ITEM_EVENT;
    flag->flag = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, flag);
}

/* Trick and Switcheroo. */
BtlEventHandler *HAND_WAZA_AddTrick(int *handlerCount)
{
    *handlerCount = 1;
    return gTrickHandlers;
}
