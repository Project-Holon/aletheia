/*
 * file:     hand_waza_021e06dc.c
 * function: HAND_WAZA_MudSportAddFieldEffect, HAND_WAZA_GetDefogHandlers
 * address:  0x021E06DC
 * packet:   pkt_ov093_021E06DC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gDefogHandlers     0x021F29B8  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gDefogHandlers[];

void HAND_WAZA_MudSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetDefogHandlers(int *handlerCount);

/* Mud Sport: start the field effect, which lasts while the user stays in. */
void HAND_WAZA_MudSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
        cmd->effectId = BTL_FIELD_EFFECT_MUD_SPORT;
        cmd->duration = BTLV_CORE_MakeSlotKind3(pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_PLAIN, 0x73);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

const BtlEventHandler *HAND_WAZA_GetDefogHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gDefogHandlers;
}
