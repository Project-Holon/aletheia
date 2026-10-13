/*
 * file:     hand_waza_021e0d54.c
 * function: HAND_WAZA_HazeResetRanks, HAND_WAZA_GetSplashHandlers
 * address:  0x021E0D54
 * packet:   pkt_ov093_021E0D54
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gSplashHandlers     0x021F26FC  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "hand_waza_021e0518_types.h"

extern const BtlEventHandler gSplashHandlers[];

void HAND_WAZA_HazeResetRanks(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_WAZA_GetSplashHandlers(int *handlerCount);

/* Haze: reset the stat stages of every Pokemon in the battle and show the message. */
void HAND_WAZA_HazeResetRanks(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlResetRanksCmd *resetCmd;
    struct HandExMessageRecord *messageCmd;
    int allPokeBit;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        resetCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RESET_RANKS, pokeId);
        allPokeBit = 0x10;
        resetCmd->pokeCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)((allPokeBit << 7) | BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId)), resetCmd->pokeIds);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, resetCmd);
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->message, BTL_STR_TYPE_PLAIN, 0x65);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}

const BtlEventHandler *HAND_WAZA_GetSplashHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSplashHandlers;
}
