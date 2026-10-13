/*
 * file:     hand_tokusei_021d87c8.c
 * unit:     yes
 * function: HAND_TOKUSEI_QuickFeetBoostSpeed, HAND_TOKUSEI_GetQuickFeetHandlers, HAND_TOKUSEI_TangledFeetHalveAccuracy, HAND_TOKUSEI_GetTangledFeetHandlers, HAND_TOKUSEI_HustleLowerAccuracy, HAND_TOKUSEI_HustleBoostPower, HAND_TOKUSEI_GetHustleHandlers, HAND_TOKUSEI_StallMoveLast, HAND_TOKUSEI_GetStallHandlers, HAND_TOKUSEI_SlowStartHalveSpeed, HAND_TOKUSEI_SlowStartHalveAttack, HAND_TOKUSEI_SlowStartOnEnter, HAND_TOKUSEI_SlowStartBeginOnce, HAND_TOKUSEI_SlowStartBegin, HAND_TOKUSEI_SlowStartCountTurn, HAND_TOKUSEI_GetSlowStartHandlers, HAND_TOKUSEI_CompoundEyesBoostAccuracy, HAND_TOKUSEI_SandVeilLowerAccuracy, HAND_TOKUSEI_SandVeilBlockSandDamage, HAND_TOKUSEI_GetSandVeilHandlers, HAND_TOKUSEI_SnowCloakLowerAccuracy, HAND_TOKUSEI_SnowCloakBlockHailDamage, HAND_TOKUSEI_GetSnowCloakHandlers, HAND_TOKUSEI_BlockWeatherDamage, HAND_TOKUSEI_TintedLensDoubleResisted
 * address:  0x021D87C8
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
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gTangledFeetHandlers 0x021F0668 data ov093 a4
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   BTL_CALC_MulRatio  0x021D7B10  thumb  ov093
 *   gQuickFeetHandlers     0x021F0748  data   ov093  a4
 *   HAND_TOKUSEI_PackAbilityHandlerInfo 0x021D84F0 thumb ov093
 *   gStallHandlers 0x021F05A0 data a4
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_GetActionWordByPokeId   0x021C804C  thumb ov093
 *   gHustleHandlers     0x021F09C0  data   ov093  a4
 *   gCompoundEyesHandlers 0x021F0650 data a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   gSlowStartHandlers     0x021F0D6C  data   ov093  a4
 *   gSandVeilHandlers     0x021F09E0  data   ov093  a4
 *   gTintedLensHandlers 0x021F0738 data a4
 *   BTL_CALC_SummarizeTypeAffinity 0x021D7AD4 thumb ov093
 *   gSnowCloakHandlers     0x021F09F0  data   ov093  a4
 */
#include "btl_action_word_types.h"

/* Slow Start state kept in the factor work area. */
typedef struct {
    int started;
    int turnCount;
    int finished;
    int active;
} SlowStartWork;

#define SLOW_START_TURNS 5
#define BTL_STR_TYPE_STD 2
#define BTL_STR_SLOW_START_BEGIN 0x1F0
#define BTL_STR_SLOW_START_END 0x1F3

int BTL_SERVER_FLOW_GetActionWordByPokeId(struct BtlSvFlow *flow, int pokeId, BtlActionWord *outAction);

void HAND_TOKUSEI_QuickFeetBoostSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetQuickFeetHandlers(int *packedInfo);
void HAND_TOKUSEI_TangledFeetHalveAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *HAND_TOKUSEI_GetTangledFeetHandlers(u32 *packedInfo);
void HAND_TOKUSEI_HustleLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_HustleBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *HAND_TOKUSEI_GetHustleHandlers(int *packedInfo);
void HAND_TOKUSEI_StallMoveLast(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *HAND_TOKUSEI_GetStallHandlers(unsigned int *packedInfo);
void HAND_TOKUSEI_SlowStartHalveSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void HAND_TOKUSEI_SlowStartHalveAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void HAND_TOKUSEI_SlowStartOnEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void HAND_TOKUSEI_SlowStartBeginOnce(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void HAND_TOKUSEI_SlowStartBegin(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
void HAND_TOKUSEI_SlowStartCountTurn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work);
int *HAND_TOKUSEI_GetSlowStartHandlers(int *packedInfo);
void HAND_TOKUSEI_CompoundEyesBoostAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *HAND_TOKUSEI_GetCompoundEyesHandlers(int *packedInfo);
void HAND_TOKUSEI_SandVeilLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_SandVeilBlockSandDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *HAND_TOKUSEI_GetSandVeilHandlers(int *packedInfo);
void HAND_TOKUSEI_SnowCloakLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_SnowCloakBlockHailDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *HAND_TOKUSEI_GetSnowCloakHandlers(int *packedInfo);
void HAND_TOKUSEI_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, unsigned char weather);
void HAND_TOKUSEI_TintedLensDoubleResisted(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *HAND_TOKUSEI_GetTintedLensHandlers(int *packedInfo);
extern u8 gTangledFeetHandlers[];
extern int gQuickFeetHandlers[];
extern unsigned char gStallHandlers[];
extern int gHustleHandlers[];
extern unsigned char gCompoundEyesHandlers[];
extern int gSlowStartHandlers[];
extern int gSandVeilHandlers[];
extern unsigned char gTintedLensHandlers[];
extern int gSnowCloakHandlers[];

/* Quick Feet: a poke with a status condition gets 1.5 times speed and ignores the paralysis penalty. */
void HAND_TOKUSEI_QuickFeetBoostSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    struct BtlPokeParam *bpp;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetMajorStatusIndex(bpp) != 0) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
            BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 0);
        }
    }
}

/* Quick Feet: handler table. */
int *HAND_TOKUSEI_GetQuickFeetHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gQuickFeetHandlers;
}

/* Tangled Feet: halves the accuracy of moves against a confused owner. */
void HAND_TOKUSEI_TangledFeetHalveAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_SICK_CONFUSION))
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
    }
}

/* Tangled Feet: handler table. */
u8 *HAND_TOKUSEI_GetTangledFeetHandlers(u32 *packedInfo)
{
    *packedInfo = 1;
    return gTangledFeetHandlers;
}

/* Hustle: physical moves of the owner lose accuracy. */
void HAND_TOKUSEI_HustleLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && WAZA_TOOL_GetDamageType((unsigned short)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Hustle: physical moves of the owner get 1.5 times power. */
void HAND_TOKUSEI_HustleBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL) {
            BTL_EVENT_OverwriteVar(BTL_EVAR_POWER, BTL_CALC_MulRatio(BTL_EVENT_GetVar(BTL_EVAR_POWER), BTL_RATIO_1_5));
        }
    }
}

/* Hustle: handler table. */
int *HAND_TOKUSEI_GetHustleHandlers(int *packedInfo)
{
    *packedInfo = 2;
    return gHustleHandlers;
}

/* Stall: the owner moves last in its priority bracket. */
void HAND_TOKUSEI_StallMoveLast(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACTION_ORDER, 0);
}

/* Stall: handler table, one handler at priority 7. */
void *HAND_TOKUSEI_GetStallHandlers(unsigned int *packedInfo)
{
    *packedInfo = HAND_TOKUSEI_PackAbilityHandlerInfo(7, 1);
    return gStallHandlers;
}

/* Slow Start: halves the speed while the effect is active. */
void HAND_TOKUSEI_SlowStartHalveSpeed(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->active != 0)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

/* Slow Start: halves the attack power of physical moves while the effect is active. */
void HAND_TOKUSEI_SlowStartHalveAttack(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && work->active != 0 && WAZA_TOOL_GetDamageType((unsigned short)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_5);
}

/* Slow Start: starts the effect when the owner enters. */
void HAND_TOKUSEI_SlowStartOnEnter(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        HAND_TOKUSEI_SlowStartBegin(factor, flow, pokeId, work);
}

/* Slow Start: starts the effect once if it has not started. */
void HAND_TOKUSEI_SlowStartBeginOnce(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    if (work->started == 0)
        HAND_TOKUSEI_SlowStartBegin(factor, flow, pokeId, work);
}

/* Slow Start: resets the work area and shows the start message. */
void HAND_TOKUSEI_SlowStartBegin(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    BtlMessageCmd *msg;

    work->started = 1;
    work->turnCount = 0;
    work->finished = 0;
    work->active = 1;
    msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
    msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
    BTL_SERVER_FLOW_InitMsgRecord(msg->strParam, BTL_STR_TYPE_STD, BTL_STR_SLOW_START_BEGIN);
    BTL_SERVER_FLOW_AppendMsgRecordArg(msg->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
}

/*
 * Slow Start: counts the turns on which the owner took an action other than
 * a switch; after 5 it shows the end message and ends the effect.
 */
void HAND_TOKUSEI_SlowStartCountTurn(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, SlowStartWork *work)
{
    BtlActionWord action;
    BtlMessageCmd *msg;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (work->finished != 0)
        return;
    if (work->turnCount < SLOW_START_TURNS) {
        if (BTL_SERVER_FLOW_GetActionWordByPokeId(flow, pokeId, &action) == 0)
            return;
        if (action.kind == BTL_ACTION_CHANGE)
            return;
        work->turnCount += 1;
    }
    if (work->turnCount < SLOW_START_TURNS)
        return;
    msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, 4, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(msg->strParam, BTL_STR_TYPE_STD, BTL_STR_SLOW_START_END);
    BTL_SERVER_FLOW_AppendMsgRecordArg(msg->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    work->active = 0;
    work->finished = 1;
}

/* Slow Start: handler table. */
int *HAND_TOKUSEI_GetSlowStartHandlers(int *packedInfo)
{
    *packedInfo = 6;
    return gSlowStartHandlers;
}

/* Compound Eyes: multiplies the accuracy of the owner's moves by 1.3. */
void HAND_TOKUSEI_CompoundEyesBoostAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_3);
}

/* Compound Eyes: handler table. */
void *HAND_TOKUSEI_GetCompoundEyesHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gCompoundEyesHandlers;
}

/* Sand Veil: lowers the accuracy of moves against the owner in a sandstorm. */
void HAND_TOKUSEI_SandVeilLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SAND)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Sand Veil: no damage from the sandstorm. */
void HAND_TOKUSEI_SandVeilBlockSandDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockWeatherDamage(factor, flow, pokeId, work, BTL_WEATHER_SAND);
}

/* Sand Veil: handler table. */
int *HAND_TOKUSEI_GetSandVeilHandlers(int *packedInfo)
{
    *packedInfo = 2;
    return gSandVeilHandlers;
}

/* Snow Cloak: lowers the accuracy of moves against the owner in hail. */
void HAND_TOKUSEI_SnowCloakLowerAccuracy(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_HAIL)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_0_8);
}

/* Snow Cloak: no damage from hail. */
void HAND_TOKUSEI_SnowCloakBlockHailDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    HAND_TOKUSEI_BlockWeatherDamage(factor, flow, pokeId, work, BTL_WEATHER_HAIL);
}

/* Snow Cloak: handler table. */
int *HAND_TOKUSEI_GetSnowCloakHandlers(int *packedInfo)
{
    *packedInfo = 2;
    return gSnowCloakHandlers;
}

/* Prevents the weather damage of the given weather for the owner. */
void HAND_TOKUSEI_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, unsigned char weather)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE) > 0 && weather == BTL_EVENT_GetVar(BTL_EVAR_WEATHER))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Tinted Lens: doubles the damage of moves that are not very effective. */
void HAND_TOKUSEI_TintedLensDoubleResisted(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_CALC_SummarizeTypeAffinity(BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY)) == BTL_AFFINITY_RESISTED)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

/* Tinted Lens: handler table. */
void *HAND_TOKUSEI_GetTintedLensHandlers(int *packedInfo)
{
    *packedInfo = 1;
    return gTintedLensHandlers;
}
