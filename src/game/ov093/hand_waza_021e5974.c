/*
 * file:     hand_waza_021e5974.c
 * unit:     yes
 * function: HAND_WAZA_GetUTurnHandlers, HAND_WAZA_UTurnSwitchOut, HAND_WAZA_RapidSpinClearBindingAndHazards
 * address:  0x021E5968
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
 *   func_06898CF4  0x06898CF4  thumb
 *   gUTurnHandlers     0x021F2584  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckClientHasBackupPoke  0x021C7F24  thumb  ov093
 *   BTL_SERVER_FLOW_TrySetOnceFlag  0x021C7F4C  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   gRapidSpinHandlers     0x021F258C  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_MAIN_IsPokeIdInSecondPair 0x021B9A40 thumb ov093
 */
#include "hand_waza_021e5620_types.h"

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CheckClientHasBackupPoke(struct BtlServerFlow *flow, int pokeId);
extern int BTL_SERVER_FLOW_TrySetOnceFlag(struct BtlServerFlow *flow);
extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(struct HandExMessage *message, int kind, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandExMessage *message, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *record);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, unsigned int pokeId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *pokeParam, int sickKind);
extern unsigned char BTL_MAIN_IsPokeIdInSecondPair(unsigned int pokeId);
extern int func_06898CF4(int side, int hazardKind);
extern int gUTurnHandlers[];
extern int gRapidSpinHandlers[];
int *HAND_WAZA_GetUTurnHandlers(int *handlerCount);
void HAND_WAZA_UTurnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetRapidSpinHandlers(int *handlerCount);
void HAND_WAZA_RapidSpinClearBindingAndHazards(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);

/* Registry hazard kinds that Rapid Spin checks on the side of the user. */
#define HAZARD_SPIKES 6
#define HAZARD_TOXIC_SPIKES 7
#define HAZARD_STEALTH_ROCK 8

/* U-turn and Volt Switch getter: one handler row. */
int *HAND_WAZA_GetUTurnHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gUTurnHandlers;
}


/* U-turn and Volt Switch: announce the switch, then send the user back to its ball. */
void HAND_WAZA_UTurnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessageAnim *messageAnim;
    struct HandExSwitchOut *switchOut;
    int trainerId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_SERVER_FLOW_CheckClientHasBackupPoke(flow, pokeId) != 0 && BTL_SERVER_FLOW_TrySetOnceFlag(flow) != 0) {
        trainerId = BTL_MAIN_PokeIdToClientIdThunk(pokeId);
        messageAnim = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_MESSAGE_ANIM, pokeId);
        messageAnim->pokeId = pokeId;
        BTL_SERVER_FLOW_InitMsgRecord(&messageAnim->message, HANDEX_MESSAGE_SET, 0x302);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageAnim->message, pokeId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageAnim->message, trainerId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageAnim);
        switchOut = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SWITCH_OUT, pokeId);
        switchOut->messageId = (BTL_EVENT_GetFactorKey(factor) == 0x171) ? 0x283 : 0x284;
        switchOut->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        switchOut->replacementSlot = BTL_SLOT_NONE;
        switchOut->header |= HANDEX_FLAG_NO_WAIT;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, switchOut);
    }
}


/* Rapid Spin getter: one handler row. */
int *HAND_WAZA_GetRapidSpinHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRapidSpinHandlers;
}

/* Rapid Spin: free the user from binding and Leech Seed, then clear the hazards on its side. */
void HAND_WAZA_RapidSpinClearBindingAndHazards(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct BtlPokeParam *pokeParam;
    struct HandExCureSick *cureSick;
    struct HandExClearHazards *clearHazards;
    int side;
    u8 hasSpikes, hasToxicSpikes, hasStealthRock;
    u32 i;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        pokeParam = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_LEECH_SEED) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            cureSick->sickKind = BTL_SICK_LEECH_SEED;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
        if (BTL_POKEPARAM_HasSick(pokeParam, BTL_SICK_BIND) != 0) {
            cureSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cureSick->pokeCount = 1;
            cureSick->pokeIds[0] = pokeId;
            cureSick->sickKind = BTL_SICK_BIND;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cureSick);
        }
        side = BTL_MAIN_IsPokeIdInSecondPair(pokeId);
        hasSpikes = func_06898CF4(side, HAZARD_SPIKES);
        hasToxicSpikes = func_06898CF4(side, HAZARD_TOXIC_SPIKES);
        hasStealthRock = func_06898CF4(side, HAZARD_STEALTH_ROCK);
        if (hasSpikes || hasToxicSpikes || hasStealthRock) {
            clearHazards = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_CLEAR_HAZARDS, pokeId);
            clearHazards->side = side;
            clearHazards->maskBytes[0] = 3;
            for (i = 1; i < 3; i++)
                clearHazards->maskBytes[i] = 0;
            if (hasSpikes && clearHazards->maskBytes[0] > 1)
                clearHazards->maskBytes[1] |= 0x40;
            if (hasToxicSpikes && clearHazards->maskBytes[0] > 1)
                clearHazards->maskBytes[1] |= 0x80;
            if (hasStealthRock && clearHazards->maskBytes[0] > 2)
                clearHazards->maskBytes[2] |= 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, clearHazards);
        }
    }
}
