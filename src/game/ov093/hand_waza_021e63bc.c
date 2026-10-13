/*
 * file:     hand_waza_021e63bc.c
 * unit:     yes
 * function: HAND_WAZA_DigOnChargeTurn, HAND_WAZA_SolarBeamSkipChargeInSun, HAND_WAZA_SolarBeamOnChargeTurn, HAND_WAZA_SolarBeamHalvePowerInBadWeather, HAND_WAZA_AddRazorWind, HAND_WAZA_RazorWindOnChargeTurn, HAND_WAZA_SkyAttackOnChargeTurn
 * address:  0x021E63BC
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
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gSolarBeamHandlers     0x021F2AF8  data   ov093  a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk  0x021C8288  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gSkyAttackHandlers     0x021F25DC  data  a4
 *   gSkullBashHandlers     0x021F25D4  data   ov093  a4
 *   gRazorWindHandlers     0x021F27D4  data   ov093  a4
 */
#include "hand_waza_021e62f4_types.h"

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *message, int type, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandWazaMessage *message, u32 arg);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(u8 *flow);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern int gSolarBeamHandlers[];
extern int gSkyAttackHandlers[];
extern int gSkullBashHandlers[];
extern int gRazorWindHandlers[];

#define BTL_WEATHER_SUN 1

/* Dig: on the charge turn, mark the user as underground and print the charge message. */
void HAND_WAZA_DigOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaStateRecord *state;
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        state = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_SET_STATE, pokeId);
        state->pokeId = pokeId;
        state->state = 5;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, state);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x21a);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

/* Dig: handler of the event that follows the charge turn; it does nothing. */
void HAND_WAZA_DigNoOp(void)
{
}

/* Solar Beam: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSolarBeam(int *handlerCount)
{
    *handlerCount = 3;
    return gSolarBeamHandlers;
}

/* Solar Beam: in sunshine the charge turn is skipped. */
void HAND_WAZA_SolarBeamSkipChargeInSun(int factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SUN)
        BTL_EVENT_OverwriteVar(WAZAVAR_SKIP_FLAG, 1);
}

/* Solar Beam: on the charge turn, print the charge message. */
void HAND_WAZA_SolarBeamOnChargeTurn(int factor, void *flow, int pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x229);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

/* Solar Beam: in rain, hail or sandstorm the power is halved. */
void HAND_WAZA_SolarBeamHalvePowerInBadWeather(int factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID) && (u8)(BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) + 254) <= 2)
        BTL_EVENT_MultiplyVar(WAZAVAR_POWER_RATIO, 2 << 10);
}

/* Razor Wind: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddRazorWind(int *handlerCount)
{
    *handlerCount = 1;
    return gRazorWindHandlers;
}

/* Razor Wind: on the charge turn, print the charge message. */
void HAND_WAZA_RazorWindOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x223);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

/* Sky Attack: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSkyAttack(int *handlerCount)
{
    *handlerCount = 1;
    return gSkyAttackHandlers;
}

/* Sky Attack: on the charge turn, print the charge message. */
void HAND_WAZA_SkyAttackOnChargeTurn(int factor, void *flow, u32 pokeId)
{
    struct HandWazaMessageRecord *msg;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->message, 2, 0x226);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}

/* Skull Bash: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddSkullBash(int *handlerCount)
{
    *handlerCount = 1;
    return gSkullBashHandlers;
}
