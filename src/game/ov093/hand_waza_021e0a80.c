/*
 * file:     hand_waza_021e0a80.c
 * unit:     yes
 * function: HAND_WAZA_SketchLearnTargetMove, HAND_WAZA_GetFollowMeHandlers, HAND_WAZA_FollowMeFailOutsideMultiBattle, HAND_WAZA_FollowMeShowMessage, HAND_WAZA_FollowMeRedirectTarget, HAND_WAZA_FollowMeRemoveFactor, HAND_WAZA_GetRefreshHandlers
 * address:  0x021E0A80
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
 *   gRefreshHandlers     0x021F2434  data   ov093  a4
 *   gFollowMeHandlers 0x021F2D78 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsTransformed 0x021D6D54 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId 0x021D67A8 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_HasMove 0x021D5750 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair   0x021B9A24  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   BTL_SERVER_FLOW_TestStateFlagBit0   0x021C830C  thumb ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHitById   0x021C8290  thumb ov093
 *   HAND_WAZA_RemoveMoveHandlerById  0x021E03F8  thumb  ov093
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gFollowMeHandlers[];
extern const BtlEventHandler gRefreshHandlers[];

void HAND_WAZA_SketchLearnTargetMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetFollowMeHandlers(int *handlerCount);
void HAND_WAZA_FollowMeFailOutsideMultiBattle(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_FollowMeShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_FollowMeRedirectTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_FollowMeRemoveFactor(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetRefreshHandlers(int *handlerCount);

/*
 * Sketch: learn the last move of the target for good. It is refused for no
 * move, Struggle, Sketch, Chatter, a move the user knows, and when the user
 * is transformed.
 */
void HAND_WAZA_SketchLearnTargetMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int move;
    int selectedMove;
    int slot;
    int moveOrMessageId;
    BtlReplaceMoveCmd *replaceCmd;
    struct HandExMessageRecord *messageCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID));
        move = BTL_POKEPARAM_GetLastUsedMoveId(target);
        selectedMove = BTL_POKEPARAM_GetLastSelectedMoveId(target);
        if (selectedMove != move)
            move = selectedMove;
        if (move == 0)
            return;
        if (move == BTL_MOVE_SKETCH)
            return;
        if (move == BTL_MOVE_STRUGGLE)
            return;
        /* The same local holds Chatter for the check and then the base of the message id below. */
        moveOrMessageId = BTL_MOVE_CHATTER;
        if (move == moveOrMessageId || BTL_POKEPARAM_HasMove(user, move) != 0 || BTL_POKEPARAM_IsTransformed(user) != 0)
            return;
        slot = BTL_POKEPARAM_FindMoveSlot(user, BTL_EVENT_GetFactorKey(factor));
        if (slot == BTL_POKEPARAM_MOVE_COUNT)
            return;
        replaceCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REPLACE_MOVE, pokeId);
        replaceCmd->pokeId = pokeId;
        replaceCmd->slot = slot;
        replaceCmd->moveId = move;
        replaceCmd->fullPp = 0;
        replaceCmd->permanent = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, replaceCmd);
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        moveOrMessageId += 240;
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, BTL_STR_TYPE_POKE_NAME, moveOrMessageId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->message, move);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}

/* Follow Me and Rage Powder: four entries. */
const BtlEventHandler *HAND_WAZA_GetFollowMeHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gFollowMeHandlers;
}

/* Follow Me: outside double and triple battles the move fails with a fixed reason (when no reason is set yet). */
void HAND_WAZA_FollowMeFailOutsideMultiBattle(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int failReasonKey = BTL_EVAR_FAIL_REASON;

    if (BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_SINGLE || BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_ROTATION) {
        if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(failReasonKey) == 0)
            BTL_EVENT_OverwriteVar(failReasonKey, BTL_FAIL_REASON_NEEDS_MULTI_BATTLE);
    }
}

/* Follow Me: show the message and mark the factor as activated. */
void HAND_WAZA_FollowMeShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct HandExMessageRecord *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x29e);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        work[HAND_WORK_ACTIVATED] = 1;
    }
}

/*
 * Follow Me: in a double or triple battle, make the user the defender of a
 * move from an enemy, unless the move is Sky Drop or the user is blocked.
 */
void HAND_WAZA_FollowMeRedirectTarget(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    u8 attackerId;
    u16 moveId;

    if (BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_SINGLE)
        return;
    if (BTL_SERVER_FLOW_GetRule(flow) == BTL_RULE_ROTATION)
        return;
    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_MAIN_IsPokeSamePair(pokeId, attackerId) != 0)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID) == BTL_MOVE_SKY_DROP)
        return;
    if (BTL_POKEPARAM_HasSick(user, BTL_SICK_BLOCKS_REDIRECT) != 0)
        return;
    if (BTL_SERVER_FLOW_TestStateFlagBit0(flow) != 0)
        return;
    moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
    if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(flow, attackerId, pokeId, moveId) != 0)
        return;
    BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, pokeId);
}

/* Follow Me: remove the factors of this move from the user. */
void HAND_WAZA_FollowMeRemoveFactor(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HAND_WAZA_RemoveMoveHandlerById(pokeId, BTL_EVENT_GetFactorKey(factor));
}

const BtlEventHandler *HAND_WAZA_GetRefreshHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRefreshHandlers;
}
