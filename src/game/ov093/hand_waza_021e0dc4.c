/*
 * file:     hand_waza_021e0dc4.c
 * unit:     yes
 * function: HAND_WAZA_SplashShowMessage, HAND_WAZA_GetCurseHandlers, HAND_WAZA_CurseSetTargetKind, HAND_WAZA_CurseApply, HAND_WAZA_GetThunderWaveHandlers
 * address:  0x021E0DC4
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
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_CALC_GetCurseTargetKind  0x021D80A8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   gCurseHandlers     0x021F28D8  data   ov093  a4
 *   gThunderWaveHandlers     0x021F24D4  data   ov093  a4
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gCurseHandlers[];
extern const BtlEventHandler gThunderWaveHandlers[];

void HAND_WAZA_SplashShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetCurseHandlers(int *handlerCount);
void HAND_WAZA_CurseSetTargetKind(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_WAZA_CurseApply(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetThunderWaveHandlers(int *handlerCount);

/* Splash: only the message. */
void HAND_WAZA_SplashShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct HandExMessageRecord *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_PLAIN, 102);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}

const BtlEventHandler *HAND_WAZA_GetCurseHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gCurseHandlers;
}

/* Curse: the target kind of the move depends on the user (a Ghost aims at one Pokemon). */
void HAND_WAZA_CurseSetTargetKind(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TARGET_KIND, BTL_CALC_GetCurseTargetKind(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)));
}

/*
 * Curse: a Ghost user pays half of its HP and curses the target; any other
 * user gets speed -1, attack +1 and defense +1. The by-value return of
 * BTLV_CORE_MakeSlotKind1Empty reserves a four byte stack temporary, which is
 * the second slot of the original frame.
 */
void HAND_WAZA_CurseApply(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *user;
    int ghostCursed;
    u8 targetId;
    BtlAddSickMessageCmd *sickCmd;
    BtlHpDeltaCmd *hpCmd;
    BtlRankEffectCmd *rankCmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    ghostCursed = 0;
    if (BTL_POKEPARAM_HasType(user, POKETYPE_GHOST)) {
        if (func_021D59B4(user, BPP_VALUE_HP) > 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
            if (targetId != BTL_POKEID_NONE) {
                sickCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
                sickCmd->pokeId = targetId;
                sickCmd->sickKind = BTL_SICK_CURSE;
                sickCmd->cont = BTLV_CORE_MakeSlotKind1Empty();
                BTL_SERVER_FLOW_InitMsgRecord(&sickCmd->message, BTL_STR_TYPE_POKE_NAME, 1064);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&sickCmd->message, pokeId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&sickCmd->message, targetId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, sickCmd);
                hpCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_HP_DELTA, pokeId);
                hpCmd->pokeId = pokeId;
                hpCmd->delta = -BTL_CALC_DivideMaxHpMin1(user, 2);
                hpCmd->mode = 1;
                hpCmd->header |= BTL_CMD_FLAG_SELF_INFLICTED;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, hpCmd);
            }
        }
        ghostCursed = 1;
    } else {
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
        rankCmd->pokeCount = 1;
        rankCmd->pokeId = pokeId;
        rankCmd->rankKind = BTL_RANK_SPEED;
        rankCmd->volume = -1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
        rankCmd->pokeCount = 1;
        rankCmd->pokeId = pokeId;
        rankCmd->rankKind = BTL_RANK_ATTACK;
        rankCmd->volume = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, pokeId);
        rankCmd->pokeCount = 1;
        rankCmd->pokeId = pokeId;
        rankCmd->rankKind = BTL_RANK_DEFENSE;
        rankCmd->volume = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
    }
    BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, ghostCursed);
}

const BtlEventHandler *HAND_WAZA_GetThunderWaveHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gThunderWaveHandlers;
}
