/*
 * file:     hand_waza_021e61bc.c
 * unit:     yes
 * function: HAND_WAZA_FlyBeginFlight, HAND_WAZA_FlyChargeEndNoOp, HAND_WAZA_GetShadowForceHandlers, HAND_WAZA_ShadowForceBeginVanish, HAND_WAZA_ShadowForceBreakProtect
 * address:  0x021E61BC
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
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   gBounceHandlers     0x021F2AA8  data   ov093  a4
 *   gShadowForceHandlers     0x021F2F40  data   ov093  a4
 */
#include "hand_waza_021e5620_types.h"

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(struct HandExMessage *message, int kind, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandExMessage *message, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *record);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *pokeParam, u32 turnFlag);
extern int gBounceHandlers[];
extern int gShadowForceHandlers[];

void HAND_WAZA_FlyBeginFlight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FlyChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetShadowForceHandlers(int *handlerCount);
void HAND_WAZA_ShadowForceBeginVanish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_ShadowForceChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_ShadowForceBreakProtect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetBounceHandlers(int *handlerCount);


/* Fly, first turn: the user rises into the air (continuing flag and message). */
void HAND_WAZA_FlyBeginFlight(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetContFlag *setContFlag;
    struct HandExMessageRecord *messageRecord;

    if (pokeId != BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID))
        return;
    setContFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_CONT_FLAG, pokeId);
    setContFlag->pokeId = pokeId;
    setContFlag->contFlag = BTL_CONT_FLAG_FLYING;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, setContFlag);
    messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x211);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
}


/* Fly: nothing to do on this event. */
void HAND_WAZA_FlyChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
}


/* Shadow Force getter: five handler rows. */
int *HAND_WAZA_GetShadowForceHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gShadowForceHandlers;
}


/* Shadow Force, first turn: the user vanishes (continuing flag and message). */
void HAND_WAZA_ShadowForceBeginVanish(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetContFlag *setContFlag;
    struct HandExMessageRecord *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        setContFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_CONT_FLAG, pokeId);
        setContFlag->pokeId = pokeId;
        setContFlag->contFlag = BTL_CONT_FLAG_SHADOW_FORCE;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, setContFlag);
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x21d);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}



/* Shadow Force: nothing to do on this event. */
void HAND_WAZA_ShadowForceChargeEndNoOp(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
}



/* Shadow Force: when the target is protected, break the protection and say so. */
void HAND_WAZA_ShadowForceBreakProtect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExClearTurnFlag *clearTurnFlag;
    struct HandExMessageRecord *messageRecord;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_TURN_FLAG_PROTECTED) != 0) {
            clearTurnFlag = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CLEAR_TURN_FLAG, pokeId);
            clearTurnFlag->pokeId = targetId;
            clearTurnFlag->turnFlag = BTL_TURN_FLAG_PROTECTED;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, clearTurnFlag);
            messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x208);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
        }
    }
}



/* Bounce getter: two handler rows. */
int *HAND_WAZA_GetBounceHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBounceHandlers;
}
