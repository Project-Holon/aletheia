/*
 * file:     hand_waza_021e0518.c
 * unit:     yes
 * function: HAND_WAZA_CamouflageChangeType, HAND_WAZA_GetTrickRoomHandlers, HAND_WAZA_TrickRoomAddFieldEffect, HAND_WAZA_GetGravityHandlers
 * address:  0x021E0518
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
 *   BTL_SERVER_FLOW_GetFieldSituationType  0x021C8174  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gTrickRoomHandlers     0x021F26F4  data   ov093  a4
 *   gGravityHandlers     0x021F2424  data   ov093  a4
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gTrickRoomHandlers[];
extern const BtlEventHandler gGravityHandlers[];

void HAND_WAZA_CamouflageChangeType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetTrickRoomHandlers(int *handlerCount);
void HAND_WAZA_TrickRoomAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetGravityHandlers(int *handlerCount);

/* Camouflage: the user takes the type that matches the battle ground. */
void HAND_WAZA_CamouflageChangeType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int type;
    u16 typePair;
    BtlChangeTypeCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        switch (BTL_SERVER_FLOW_GetFieldSituationType(flow)) {
        case 1: case 2: case 3: case 8: case 9: case 15:
            type = POKETYPE_GROUND;
            break;
        case 4: case 14:
        default:
            type = POKETYPE_NORMAL;
            break;
        case 10:
            type = POKETYPE_ROCK;
            break;
        case 0: case 5:
            type = POKETYPE_GRASS;
            break;
        case 6: case 11: case 12:
            type = POKETYPE_WATER;
            break;
        case 7: case 13:
            type = POKETYPE_ICE;
            break;
        }
        typePair = BTLV_CORE_PackByteTwice(type);
        if (typePair != BTL_POKEPARAM_GetTypePair(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId))) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CHANGE_TYPE, pokeId);
            cmd->typePair = typePair;
            cmd->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

const BtlEventHandler *HAND_WAZA_GetTrickRoomHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTrickRoomHandlers;
}

/* Trick Room: start the field effect for five turns, or end it when it is already active. */
void HAND_WAZA_TrickRoomAddFieldEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlFieldEffectAddCmd *addCmd;
    BtlFieldEffectRemoveCmd *removeCmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_FIELD_GetStaticSlotObject(BTL_FIELD_EFFECT_TRICK_ROOM) == 0) {
            addCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_FIELD_EFFECT, pokeId);
            addCmd->effectId = BTL_FIELD_EFFECT_TRICK_ROOM;
            addCmd->duration.raw = BTLV_CORE_MakeSlotKind2Index(5);
            BTL_SERVER_FLOW_InitMsgRecord(&addCmd->message, BTL_STR_TYPE_POKE_NAME, 0x359);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&addCmd->message, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addCmd);
        } else {
            removeCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REMOVE_FIELD_EFFECT, pokeId);
            removeCmd->effectId = BTL_FIELD_EFFECT_TRICK_ROOM;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, removeCmd);
        }
    }
}

const BtlEventHandler *HAND_WAZA_GetGravityHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGravityHandlers;
}
