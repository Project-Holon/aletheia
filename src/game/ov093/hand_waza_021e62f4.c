/*
 * file:     hand_waza_021e62f4.c
 * unit:     yes
 * function: HAND_WAZA_BounceOnChargeTurn, HAND_WAZA_BounceNoOp, HAND_WAZA_AddDive
 * address:  0x021E62F4
 * packet:   pkt_ov093_021E62F4
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
 *   gDiveHandlers     0x021F2AC8  data   ov093  a4
 */
#include "hand_waza_021e62f4_types.h"

struct BtlSvFlow;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int type, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandWazaMessage *message, u32 arg);
extern int gDiveHandlers[];

/* Bounce: on the charge turn, mark the user as airborne and print the charge message. */
void HAND_WAZA_BounceOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaStateRecord *state;
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 3;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x220);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

/* Bounce: handler of the event that follows the charge turn; it does nothing. */
void HAND_WAZA_BounceNoOp(void)
{
}

/* Dive: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddDive(int *handlerCount)
{
    *handlerCount = 2;
    return gDiveHandlers;
}
