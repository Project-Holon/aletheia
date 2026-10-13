/*
 * file:     hand_waza_021e0628.c
 * unit:     yes
 * function: HAND_WAZA_GravityAddFieldEffect, HAND_WAZA_GetWaterSportHandlers, HAND_WAZA_WaterSportAddFieldEffect, HAND_WAZA_GetMudSportHandlers
 * address:  0x021E0628
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
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   gWaterSportHandlers     0x021F2664  data   ov093  a4
 *   gMudSportHandlers     0x021F2614  data   ov093  a4
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gWaterSportHandlers[];
extern const BtlEventHandler gMudSportHandlers[];

void HAND_WAZA_GravityAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetWaterSportHandlers(int *handlerCount);
void HAND_WAZA_WaterSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetMudSportHandlers(int *handlerCount);

/*
 * Gravity: start the field effect for five turns unless it is active, then
 * ground the Pokemon in the air. The message is set field by field (no call
 * to the message setter).
 */
void HAND_WAZA_GravityAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_FIELD_GetStaticSlotObject(BTL_FIELD_EFFECT_GRAVITY) == 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
            cmd->effectId = BTL_FIELD_EFFECT_GRAVITY;
            cmd->duration.raw = BTLV_CORE_MakeSlotKind2Index(5);
            cmd->message.kind = BTL_STR_TYPE_PLAIN;
            cmd->message.messageId = 0x75;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_CMD_KIND_APPLY_GRAVITY, pokeId);
        }
    }
}

const BtlEventHandler *HAND_WAZA_GetWaterSportHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWaterSportHandlers;
}

/* Water Sport: start the field effect, which lasts while the user stays in. */
void HAND_WAZA_WaterSportAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
        cmd->effectId = BTL_FIELD_EFFECT_WATER_SPORT;
        cmd->duration = BTLV_CORE_MakeSlotKind3(pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_PLAIN, 0x72);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

const BtlEventHandler *HAND_WAZA_GetMudSportHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMudSportHandlers;
}
