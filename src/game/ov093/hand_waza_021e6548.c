/*
 * file:     hand_waza_021e6548.c
 * unit:     yes
 * function: HAND_WAZA_SkullBashOnChargeTurn, HAND_WAZA_AddPluck
 * address:  0x021E6548
 * packet:   pkt_ov093_021E6548
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gPluckHandlers     0x021F27AC  data   ov093  a4
 */
#include "hand_waza_021e62f4_types.h"

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int type, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandWazaMessage *message, u32 arg);
extern int gPluckHandlers[];

#define BTL_RANK_DEFENSE 2

/* Skull Bash: on the charge turn, print the charge message and raise the user's Defense. */
void HAND_WAZA_SkullBashOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaMessageRecord *msg;
    struct HandWazaRankRecord *rank;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x22c);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_RANK_EFFECT, pokeId);
        rank->pokeCount = 1;
        rank->pokeId = pokeId;
        rank->rankKind = BTL_RANK_DEFENSE;
        rank->volume = 1;
        rank->flagB = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
    }
}

/* Pluck and Bug Bite: returns the handler table of the moves (the registry getter). */
int *HAND_WAZA_AddPluck(int *handlerCount)
{
    *handlerCount = 1;
    return gPluckHandlers;
}
