/*
 * file:     hand_waza_021e0c8c.c
 * unit:     yes
 * function: HAND_WAZA_RefreshCureMajorStatus, HAND_WAZA_GetTrapHandlers, HAND_WAZA_TrapAddNoEscape, HAND_WAZA_GetHazeHandlers
 * address:  0x021E0C8C
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
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_CALC_MakeSickContPoke  0x021D7D9C  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gTrapHandlers     0x021F2644  data   ov093  a4
 *   gHazeHandlers     0x021F2594  data   ov093  a4
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gTrapHandlers[];
extern const BtlEventHandler gHazeHandlers[];

void HAND_WAZA_RefreshCureMajorStatus(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetTrapHandlers(int *handlerCount);
void HAND_WAZA_TrapAddNoEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetHazeHandlers(int *handlerCount);

/* Refresh: cure the user of poison, paralysis or burn. */
void HAND_WAZA_RefreshCureMajorStatus(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct HandExCureSick *cmd;
    int sickIndex;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        sickIndex = BTL_POKEPARAM_GetMajorStatusIndex(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
        if (sickIndex == BTL_SICK_POISON || sickIndex == BTL_SICK_PARALYSIS || sickIndex == BTL_SICK_BURN) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CURE_SICK, pokeId);
            cmd->sickKind = sickIndex;
            cmd->pokeIds[0] = pokeId;
            cmd->pokeCount = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Spider Web, Mean Look and Block. */
const BtlEventHandler *HAND_WAZA_GetTrapHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gTrapHandlers;
}

/* Trapping moves: the target can no longer escape while the user stays in. */
void HAND_WAZA_TrapAddNoEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlAddSickMessageCmd *cmd;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_SICK_NO_ESCAPE) == 0) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, pokeId);
            cmd->pokeId = targetId;
            cmd->sickKind = BTL_SICK_NO_ESCAPE;
            cmd->cont.raw = BTL_CALC_MakeSickContPoke(pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->message, BTL_STR_TYPE_POKE_NAME, 0x368);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->message, targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

const BtlEventHandler *HAND_WAZA_GetHazeHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHazeHandlers;
}
