/*
 * file:     hand_waza_021e072c.c
 * unit:     yes
 * function: HAND_WAZA_DefogLowerEvasionRemoveSideEffects, HAND_WAZA_GetBrickBreakHandlers, HAND_WAZA_BrickBreakSetSkipCheck, HAND_WAZA_BrickBreakClearSkipCheck, HAND_WAZA_BrickBreakRemoveScreens, HAND_WAZA_BrickBreakSkipScreens, HAND_WAZA_GetJumpKickHandlers, HAND_WAZA_JumpKickCrashOnFail, HAND_WAZA_JumpKickDealCrashDamage, HAND_WAZA_GetMimicHandlers, HAND_WAZA_MimicCopyTargetMove
 * address:  0x021E072C
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
 *   func_06898CF4  0x06898CF4  thumb
 *   func_0689CA7C  0x0689CA7C  thumb
 *   gBrickBreakHandlers 0x021F2B70 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSubstitute 0x021D6D7C thumb ov093
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_EVENT_SetFactorSkipCheck  0x021D7320  thumb  ov093
 *   BTL_EVENT_ClearFactorSkipCheck   0x021D7324  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gJumpKickHandlers     0x021F2504  data    a4
 *   BTL_POKEPARAM_IsTransformed 0x021D6D54 thumb ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId 0x021D67A8 thumb ov093
 *   BTL_POKEPARAM_GetLastSelectedMoveId 0x021D67B8 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   BTL_EVENT_GetFactorKey 0x021D70A8 thumb ov093
 *   gMimicHandlers     0x021F280C  data   ov093  a4
 *   HAND_WAZA_GetJumpKickHandlers  0x021E0914  thumb  ov093
 *   HAND_WAZA_JumpKickCrashOnFail  0x021E0920  thumb  ov093
 *   HAND_WAZA_JumpKickDealCrashDamage  0x021E0944  thumb  ov093
 *   HAND_WAZA_GetMimicHandlers  0x021E098C  thumb  ov093
 *   HAND_WAZA_MimicCopyTargetMove  0x021E0998  thumb  ov093
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gBrickBreakHandlers[];
extern const BtlEventHandler gJumpKickHandlers[];
extern const BtlEventHandler gMimicHandlers[];

void HAND_WAZA_DefogLowerEvasionRemoveSideEffects(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetBrickBreakHandlers(int *handlerCount);
void HAND_WAZA_BrickBreakSetSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_BrickBreakClearSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_BrickBreakRemoveScreens(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int HAND_WAZA_BrickBreakSkipScreens(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);
const BtlEventHandler *HAND_WAZA_GetJumpKickHandlers(int *handlerCount);
void HAND_WAZA_JumpKickCrashOnFail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_JumpKickDealCrashDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
const BtlEventHandler *HAND_WAZA_GetMimicHandlers(int *handlerCount);
void HAND_WAZA_MimicCopyTargetMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);

/*
 * Defog: lower the target's evasion by one stage (unless it is behind a
 * substitute), then remove the side effects. The removal command holds a set
 * of side effect ids; each bit is guarded by the size byte of the set, the
 * way an inlined set-bit helper would check it.
 */
void HAND_WAZA_DefogLowerEvasionRemoveSideEffects(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 targetId;
    BtlRankEffectCmd *rankCmd;
    BtlRemoveSideEffectsCmd *removeCmd;
    u32 i;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        if (BTL_POKEPARAM_HasSubstitute(BTL_SERVER_FLOW_GetPokeParam(flow, targetId)) == 0) {
            rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
            rankCmd->rankKind = BTL_RANK_EVASION;
            rankCmd->volume = -1;
            rankCmd->flagB = 1;
            rankCmd->pokeCount = 1;
            rankCmd->pokeId = targetId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
        }
        removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REMOVE_SIDE_EFFECTS, pokeId);
        removeCmd->sideId = BTL_MAIN_IsPokeIdInSecondPair(targetId);
        removeCmd->bytes[0] = 3;
        for (i = 1; i < 3; i++)
            removeCmd->bytes[i] = 0;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_REFLECT;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_LIGHT_SCREEN;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_MIST;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_SAFEGUARD;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_SPIKES;
        if (removeCmd->bytes[0] > 1)
            removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_TOXIC_SPIKES;
        if (removeCmd->bytes[0] > 2)
            removeCmd->bytes[2] |= 1 << (BTL_SIDE_EFFECT_STEALTH_ROCK - 8);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
    }
}

/* Brick Break: the table holds the skip check setup, its removal and the screen removal. */
const BtlEventHandler *HAND_WAZA_GetBrickBreakHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gBrickBreakHandlers;
}

/* Brick Break: make the move's own damage calculation skip the screens. */
void HAND_WAZA_BrickBreakSetSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_SetFactorSkipCheck(factor, HAND_WAZA_BrickBreakSkipScreens);
}

/* Brick Break: stop skipping the screens. */
void HAND_WAZA_BrickBreakClearSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Brick Break: when the defender's side has Reflect or Light Screen, remove both and queue the end record. */
void HAND_WAZA_BrickBreakRemoveScreens(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int sideId;
    BtlRemoveSideEffectsCmd *removeCmd;
    BtlByteCmd *endCmd;
    unsigned i;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        sideId = (int)BTL_MAIN_IsPokeIdInSecondPair((u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        if (func_06898CF4(sideId, BTL_SIDE_EFFECT_REFLECT) != 0 || func_06898CF4(sideId, BTL_SIDE_EFFECT_LIGHT_SCREEN) != 0) {
            removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REMOVE_SIDE_EFFECTS, pokeId);
            removeCmd->sideId = sideId;
            removeCmd->bytes[0] = 3;
            for (i = 1; i < 3; i++) {
                removeCmd->bytes[i] = 0;
            }
            if (removeCmd->bytes[0] > 1) {
                removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_REFLECT;
            }
            if (removeCmd->bytes[0] > 1) {
                removeCmd->bytes[1] |= 1 << BTL_SIDE_EFFECT_LIGHT_SCREEN;
            }
            BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
            endCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_SIDE_EFFECTS_REMOVED, pokeId);
            endCmd->value = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, endCmd);
        }
    }
}

/*
 * Skip check of Brick Break (set with BTL_EVENT_SetFactorSkipCheck): skip the
 * factors of Reflect and Light Screen, which are side effect factors with the
 * keys 0 and 1.
 */
int HAND_WAZA_BrickBreakSkipScreens(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    if (factorType == BTL_EVENT_TYPE_SIDE_EFFECT && key <= BTL_SIDE_EFFECT_LIGHT_SCREEN)
        return 1;
    return 0;
}

/* Jump Kick and High Jump Kick. */
const BtlEventHandler *HAND_WAZA_GetJumpKickHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gJumpKickHandlers;
}

/* Jump Kick: when the kick fails, the user takes the crash damage. */
void HAND_WAZA_JumpKickCrashOnFail(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_WAZA_JumpKickDealCrashDamage(factor, flow, pokeId, work);
}

/* Jump Kick: the user loses half of its maximum HP. */
void HAND_WAZA_JumpKickDealCrashDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct HandExDamage *cmd;
    int damage;

    damage = BTL_CALC_DivideMaxHpMin1(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 2);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_DAMAGE, pokeId);
    cmd->pokeId = pokeId;
    cmd->amount = damage;
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x386);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}

const BtlEventHandler *HAND_WAZA_GetMimicHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMimicHandlers;
}

/*
 * Mimic: copy the last move of the target into the slot of Mimic. The move
 * stays an int: the slot search takes the full value without narrowing.
 */
void HAND_WAZA_MimicCopyTargetMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    struct BtlPokeParam *target;
    int move;
    int selectedMove;
    int slot;
    BtlReplaceMoveCmd *replaceCmd;
    struct HandExMessageRecord *messageCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_IsTransformed(user) != 0)
            return;
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID));
        move = BTL_POKEPARAM_GetLastUsedMoveId(target);
        selectedMove = BTL_POKEPARAM_GetLastSelectedMoveId(target);
        if (selectedMove != move)
            move = selectedMove;
        if (move == 0 || func_0689CA7C(move) != 0 || BTL_POKEPARAM_FindMoveSlot(user, move) != BTL_POKEPARAM_MOVE_COUNT)
            return;
        slot = BTL_POKEPARAM_FindMoveSlot(user, BTL_EVENT_GetFactorKey(factor));
        if (slot == BTL_POKEPARAM_MOVE_COUNT)
            return;
        replaceCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REPLACE_MOVE, pokeId);
        replaceCmd->pokeId = pokeId;
        replaceCmd->slot = slot;
        replaceCmd->moveId = move;
        replaceCmd->fullPp = 0;
        replaceCmd->permanent = 0;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, replaceCmd);
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, BTL_STR_TYPE_POKE_NAME, 0x2b0);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->message, move);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}
