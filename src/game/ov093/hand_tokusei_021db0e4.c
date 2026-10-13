/*
 * file:     hand_tokusei_021db0e4.c
 * unit:     yes
 * function: HAND_TOKUSEI_RunAway_ShowEscapeMessage, HAND_TOKUSEI_GetRunAwayHandlers, HAND_TOKUSEI_MoldBreaker_ShowAbilityMessage, HAND_TOKUSEI_MoldBreaker_SkipCheck, HAND_TOKUSEI_MoldBreaker_InstallSkipCheck, HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4, HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A, HAND_TOKUSEI_Forecast_ApplyWeatherForm, HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry, HAND_TOKUSEI_Forecast_RefreshWeatherForm, HAND_TOKUSEI_Forecast_ResetFormWhenActive, HAND_TOKUSEI_Forecast_ResetFormOnAbilityChange, HAND_TOKUSEI_Forecast_ResetFormOnEvent6A, HAND_TOKUSEI_Forecast_ResetForm, HAND_TOKUSEI_Forecast_SetFormForWeather, HAND_TOKUSEI_GetForecastHandlers, HAND_TOKUSEI_GetStormDrainHandlers, HAND_TOKUSEI_StormDrain_CheckRedirect, HAND_TOKUSEI_StormDrain_AbsorbWaterMove, HAND_TOKUSEI_LightningRod_CheckRedirect, HAND_TOKUSEI_Redirect_ShowMessage, HAND_TOKUSEI_LightningRod_AbsorbElectricMove, HAND_TOKUSEI_CheckRedirectMoveType
 * address:  0x021DB0E4
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
 *   func_0689C8EC  0x0689C8EC  thumb
 *   func_0689C9B0  0x0689C9B0  thumb
 *   BTLV_CORE_EventTrySetFlagIfAttacker  0x021E889C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_SetMsgRecordSe  0x021C888C  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   gRunAwayHandlers     0x021F08B0  data   ov093  a4
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   BTL_EVENT_ClearFactorSkipCheck 0x021D7324 thumb ov093
 *   gMoldBreakerSkipCheckHandlers 0x021F0C24 data a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRaiseStat 0x021DA96C thumb ov093
 *   gLightningRodHandlers 0x021F0A70 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHitById  0x021C8290  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gForecastHandlers     0x021F0DD4  data   ov093  a4
 *   gStormDrainHandlers     0x021F0A58  data   ov093  a4
 */
#include "hand_tokusei_021db0e4_types.h"

/* Ability handlers: Run Away, Mold Breaker (and Turboblaze, Teravolt), Forecast, Storm Drain, Lightning Rod. */

extern int BTLV_CORE_EventTrySetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern int func_0689C9B0(unsigned short abilityId);
extern int func_0689C8EC(int moveId);
extern int BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);
extern int HAND_TOKUSEI_AbsorbCheckMoveType(struct BtlSvFlow *flow, int pokeId, int typeId);
extern void HAND_TOKUSEI_AbsorbRaiseStat(struct BtlSvFlow *flow, int pokeId, unsigned int statId, int amount);
extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(struct BtlSvFlow *flow, int attackerId, int defenderId, int moveId);

void HAND_TOKUSEI_RunAway_ShowEscapeMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_TOKUSEI_GetRunAwayHandlers(int *handlerCount);
void HAND_TOKUSEI_MoldBreaker_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int HAND_TOKUSEI_MoldBreaker_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key);
void HAND_TOKUSEI_MoldBreaker_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
const BtlEventHandler *HAND_TOKUSEI_GetMoldBreakerSkipCheckHandlers(int *handlerCount);
void HAND_TOKUSEI_Forecast_ApplyWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void HAND_TOKUSEI_Forecast_RefreshWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void HAND_TOKUSEI_Forecast_ResetFormWhenActive(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void HAND_TOKUSEI_Forecast_ResetFormOnAbilityChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_Forecast_ResetFormOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_Forecast_ResetForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_Forecast_SetFormForWeather(struct BtlSvFlow *flow, int pokeId, u32 weather);
const BtlEventHandler *HAND_TOKUSEI_GetForecastHandlers(int *handlerCount);
const BtlEventHandler *HAND_TOKUSEI_GetStormDrainHandlers(int *handlerCount);
void HAND_TOKUSEI_StormDrain_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void HAND_TOKUSEI_StormDrain_AbsorbWaterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *HAND_TOKUSEI_GetLightningRodHandlers(int *handlerCount);
void HAND_TOKUSEI_LightningRod_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void HAND_TOKUSEI_Redirect_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void HAND_TOKUSEI_LightningRod_AbsorbElectricMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int HAND_TOKUSEI_CheckRedirectMoveType(struct BtlSvFlow *flow, int pokeId, int *work, int typeId);

extern const BtlEventHandler gRunAwayHandlers[];
extern const BtlEventHandler gMoldBreakerSkipCheckHandlers[];
extern const BtlEventHandler gLightningRodHandlers[];
extern const BtlEventHandler gForecastHandlers[];
extern const BtlEventHandler gStormDrainHandlers[];


/* Run Away: after the escape check passes, show the escape message with its sound. */
void HAND_TOKUSEI_RunAway_ShowEscapeMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (BTLV_CORE_EventTrySetFlagIfAttacker(factor, flow, pokeId) != 0) {
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&msg->str, 1, 0x48);
        BTL_SERVER_FLOW_SetMsgRecordSe(&msg->str, 0x56a);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
    }
}


const BtlEventHandler *HAND_TOKUSEI_GetRunAwayHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRunAwayHandlers;
}


/* Mold Breaker, Turboblaze, Teravolt: when the poke enters, show the message of its own ability. */
void HAND_TOKUSEI_MoldBreaker_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;
    int strId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        switch (BTL_EVENT_GetFactorKey(factor)) {
        case 0xa3:
            strId = 0x1f9;
            break;
        case 0xa4:
            strId = 0x1f6;
            break;
        default:
            strId = 0x1ba;
            break;
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_IN, pokeId);
        msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&msg->str, 2, strId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        BTL_SERVER_FLOW_PushCmdRecord(flow, HANDEX_TOKWIN_OUT, pokeId);
    }
}


/* Skip check of the holder: ability factors listed as breakable are skipped. */
int HAND_TOKUSEI_MoldBreaker_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && func_0689C9B0(key))
        return 1;
    return 0;
}


/* Mold Breaker: when the holder attacks, install the skip check on its factor (BTL_EVENT_SetFactorSkipCheck stores the pointer unchanged). */
void HAND_TOKUSEI_MoldBreaker_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *skipCheckSet == 0) {
        BTL_EVENT_SetFactorSkipCheck(factor, (u32)HAND_TOKUSEI_MoldBreaker_SkipCheck);
        *skipCheckSet = 1;
    }
}


void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        BTL_EVENT_ClearFactorSkipCheck(factor);
        *skipCheckSet = 0;
    }
}


void HAND_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        BTL_EVENT_ClearFactorSkipCheck(factor);
        *skipCheckSet = 0;
    }
}


const BtlEventHandler *HAND_TOKUSEI_GetMoldBreakerSkipCheckHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gMoldBreakerSkipCheckHandlers;
}


/* Forecast: set the form of the holder from the current weather. */
void HAND_TOKUSEI_Forecast_ApplyWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    HAND_TOKUSEI_Forecast_SetFormForWeather(flow, pokeId, BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow));
    *formActive = 1;
}


void HAND_TOKUSEI_Forecast_ApplyWeatherFormOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_Forecast_ApplyWeatherForm(factor, flow, pokeId, formActive);
}


void HAND_TOKUSEI_Forecast_RefreshWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) HAND_TOKUSEI_Forecast_SetFormForWeather(flow, pokeId, BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow));
}


void HAND_TOKUSEI_Forecast_ResetFormWhenActive(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) HAND_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
}


/* Go back to the base form when the holder gets another ability. */
void HAND_TOKUSEI_Forecast_ResetFormOnAbilityChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int newAbilityId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        newAbilityId = BTL_EVENT_GetVar(BTL_EVAR_NEW_ABILITY_ID);
        if (newAbilityId != BTL_EVENT_GetFactorKey(factor)) HAND_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
    }
}


void HAND_TOKUSEI_Forecast_ResetFormOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) HAND_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
}


/* Put a Castform that is not in its base form back to the base form. */
void HAND_TOKUSEI_Forecast_ResetForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == SPECIES_CASTFORM && func_021D59B4(bpp, BPP_VALUE_FORM) != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_CHANGE_FORM, pokeId);
        cmd->pokeId = pokeId;
        cmd->form = 0;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->str, 2, 0xde);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->str, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}


/* Change a Castform to the form of the weather (none, sun, rain, hail); other weather gives the base form. */
void HAND_TOKUSEI_Forecast_SetFormForWeather(struct BtlSvFlow *flow, int pokeId, u32 weather)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;
    u32 currentForm;
    u32 newForm;

    bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == SPECIES_CASTFORM) {
        currentForm = (u8)func_021D59B4(bpp, BPP_VALUE_FORM);
        switch (weather) {
        case 0:
            newForm = 0;
            break;
        case 1:
            newForm = 1;
            break;
        case 2:
            newForm = 2;
            break;
        case 3:
            newForm = 3;
            break;
        default:
            newForm = 0;
            break;
        }
        if (newForm != currentForm) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_CHANGE_FORM, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = pokeId;
            cmd->form = newForm;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->str, 2, 0xde);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->str, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


const BtlEventHandler *HAND_TOKUSEI_GetForecastHandlers(int *handlerCount)
{
    *handlerCount = 9;
    return gForecastHandlers;
}


const BtlEventHandler *HAND_TOKUSEI_GetStormDrainHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gStormDrainHandlers;
}


/* Storm Drain: redirect single-target water moves to the holder. */
void HAND_TOKUSEI_StormDrain_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    *redirected = HAND_TOKUSEI_CheckRedirectMoveType(flow, pokeId, redirected, POKETYPE_WATER);
}


/* Storm Drain: a water move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void HAND_TOKUSEI_StormDrain_AbsorbWaterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER) != 0) HAND_TOKUSEI_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}


const BtlEventHandler *HAND_TOKUSEI_GetLightningRodHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gLightningRodHandlers;
}


/* Lightning Rod: redirect single-target electric moves to the holder. */
void HAND_TOKUSEI_LightningRod_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    *redirected = HAND_TOKUSEI_CheckRedirectMoveType(flow, pokeId, redirected, POKETYPE_ELECTRIC);
}


/* Lightning Rod and Storm Drain: show the message when a move was redirected to the holder. */
void HAND_TOKUSEI_Redirect_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    HandExMessage *msg;

    if (*redirected != 0) {
        if (func_021E85F8(pokeId) != 0) {
            msg = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_MESSAGE, pokeId);
            msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
            BTL_SERVER_FLOW_InitMsgRecord(&msg->str, 2, 0x1c0);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&msg->str, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, msg);
        }
        *redirected = 0;
    }
}


/* Lightning Rod: an electric move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void HAND_TOKUSEI_LightningRod_AbsorbElectricMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC) != 0) HAND_TOKUSEI_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}


/* True if a move of typeId from another poke can be redirected to the poke pokeId. */
int HAND_TOKUSEI_CheckRedirectMoveType(struct BtlSvFlow *flow, int pokeId, int *work, int typeId)
{
    u8 attackerId;
    u16 moveId;
    u8 targetId;

    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId != pokeId && typeId == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(flow, attackerId, pokeId, moveId) == 0 && func_0689C8EC(moveId) == 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, pokeId) != 0 && targetId != pokeId)
                return 1;
        }
    }
    return 0;
}
