/*
 * file:     hand_waza_021e0f50.c
 * unit:     yes
 * function: HAND_WAZA_ThunderWaveSetAccuracyCheckFlag, HAND_WAZA_GetWorrySeedHandlers, HAND_WAZA_WorrySeedFailOnTruantOrInsomnia, HAND_WAZA_WorrySeedChangeAbility, HAND_WAZA_GetDreamEaterHandlers, HAND_WAZA_DreamEaterFailIfAwake, HAND_WAZA_DreamEaterSetFailFlag, HAND_WAZA_GetCaptivateHandlers, HAND_WAZA_CaptivateFailOnSameOrNoGender, HAND_WAZA_GetTriAttackHandlers
 * address:  0x021E0F50
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
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb
 *   BTL_EVENT_GetVar   0x021D775C  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gWorrySeedHandlers     0x021F2A48  data   ov093  a4
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   gDreamEaterHandlers     0x021F28E8  data   ov093  a4
 *   gCaptivateHandlers     0x021F266C  data   ov093  a4
 *   gTriAttackHandlers     0x021F263C  data   ov093  a4
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gWorrySeedHandlers[];
extern const BtlEventHandler gDreamEaterHandlers[];
extern const BtlEventHandler gCaptivateHandlers[];
extern const BtlEventHandler gTriAttackHandlers[];

void HAND_WAZA_ThunderWaveSetAccuracyCheckFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetWorrySeedHandlers(int *handlerCount);
void HAND_WAZA_WorrySeedFailOnTruantOrInsomnia(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_WorrySeedChangeAbility(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetDreamEaterHandlers(int *handlerCount);
void HAND_WAZA_DreamEaterFailIfAwake(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_DreamEaterSetFailFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetCaptivateHandlers(int *handlerCount);
void HAND_WAZA_CaptivateFailOnSameOrNoGender(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetTriAttackHandlers(int *handlerCount);

/* Thunder Wave (guess from the move id): set the result flag of the accuracy check event. */
void HAND_WAZA_ThunderWaveSetAccuracyCheckFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACCURACY_CHECK_FLAG, 1);
}

const BtlEventHandler *HAND_WAZA_GetWorrySeedHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gWorrySeedHandlers;
}

/* Worry Seed: fails when the target already has Truant or Insomnia. */
void HAND_WAZA_WorrySeedFailOnTruantOrInsomnia(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *target;
    int abilityValueId;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        abilityValueId = BPP_VALUE_ABILITY_ID;
        if (func_021D59B4(target, BPP_VALUE_ABILITY_ID) == BTL_ABILITY_TRUANT || func_021D59B4(target, abilityValueId) == BTL_ABILITY_INSOMNIA)
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
    }
}

/* Worry Seed: the target's ability becomes Insomnia. */
void HAND_WAZA_WorrySeedChangeAbility(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct HandExChangeAbility *cmd;
    int targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CHANGE_ABILITY, pokeId);
        cmd->pokeId = targetId;
        cmd->abilityId = BTL_ABILITY_INSOMNIA;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x195);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, cmd->pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, cmd->abilityId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

const BtlEventHandler *HAND_WAZA_GetDreamEaterHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gDreamEaterHandlers;
}

/* Dream Eater: fails unless the defender is asleep. */
void HAND_WAZA_DreamEaterFailIfAwake(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int defenderId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    defenderId = (unsigned char)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, defenderId), BTL_SICK_SLEEP) == 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
}

/* Dream Eater: the second event sets the fail flag unconditionally (for the attacker). */
void HAND_WAZA_DreamEaterSetFailFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
}

const BtlEventHandler *HAND_WAZA_GetCaptivateHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gCaptivateHandlers;
}

/* Captivate: fails when either Pokemon has no gender or both have the same gender. */
void HAND_WAZA_CaptivateFailOnSameOrNoGender(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *target;
    struct BtlPokeParam *user;
    u8 targetId;
    u8 userGender;
    u8 targetGender;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        userGender = func_021D59B4(user, BPP_VALUE_GENDER);
        targetGender = func_021D59B4(target, BPP_VALUE_GENDER);
        if (userGender == BTL_GENDER_NONE || targetGender == BTL_GENDER_NONE || userGender == targetGender)
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_FAIL_FLAG, 1);
    }
}

/* Tri Attack: the handler is in the next unit. */
const BtlEventHandler *HAND_WAZA_GetTriAttackHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTriAttackHandlers;
}
