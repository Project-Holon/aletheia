/*
 * file:     unit_021DB0E4.c
 * unit:     yes
 * function: BTL_TOKUSEI_RunAway_ShowEscapeMessage, BTL_TOKUSEI_GetRunAwayHandlers, BTL_TOKUSEI_MoldBreaker_ShowAbilityMessage, BTL_TOKUSEI_MoldBreaker_SkipCheck, BTL_TOKUSEI_MoldBreaker_InstallSkipCheck, BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4, BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A, BTL_TOKUSEI_Forecast_ApplyWeatherForm, BTL_TOKUSEI_Forecast_ApplyWeatherFormOnEntry, BTL_TOKUSEI_Forecast_RefreshWeatherForm, BTL_TOKUSEI_Forecast_ResetFormWhenActive, BTL_TOKUSEI_Forecast_ResetFormOnAbilityChange, BTL_TOKUSEI_Forecast_ResetFormOnEvent6A, BTL_TOKUSEI_Forecast_ResetForm, BTL_TOKUSEI_Forecast_SetFormForWeather, BTL_TOKUSEI_GetForecastHandlers, BTL_TOKUSEI_GetStormDrainHandlers, BTL_TOKUSEI_StormDrain_CheckRedirect, BTL_TOKUSEI_StormDrain_AbsorbWaterMove, BTL_TOKUSEI_LightningRod_CheckRedirect, BTL_TOKUSEI_Redirect_ShowMessage, BTL_TOKUSEI_LightningRod_AbsorbElectricMove, BTL_TOKUSEI_CheckRedirectMoveType
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   gRunAwayHandlers     0x021F08B0  data   ov093  a4
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   BTL_EVENT_ClearFactorSkipCheck 0x021D7324 thumb ov093
 *   gMoldBreakerHandlers 0x021F0C24 data a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_ABILITY_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   BTL_ABILITY_AbsorbRaiseStat 0x021DA96C thumb ov093
 *   gLightningRodHandlers 0x021F0A70 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C8290  0x021C8290  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gForecastHandlers     0x021F0DD4  data   ov093  a4
 *   gStormDrainHandlers     0x021F0A58  data   ov093  a4
 */
#include "unit_021DB0E4_types.h"

/* Ability handlers: Run Away, Mold Breaker (and Turboblaze, Teravolt), Forecast, Storm Drain, Lightning Rod. */

extern int BTLV_CORE_EventTrySetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern int func_0689C9B0(unsigned short abilityId);
extern int func_0689C8EC(int moveId);
extern int BTL_POKEPARAM_GetSpecies(struct BtlPokeParam *bpp);
extern int BTL_ABILITY_AbsorbCheckMoveType(struct BtlSvFlow *flow, int pokeId, int typeId);
extern void BTL_ABILITY_AbsorbRaiseStat(struct BtlSvFlow *flow, int pokeId, unsigned int statId, int amount);
extern int func_021C8290(struct BtlSvFlow *flow, int attackerId, int defenderId, int moveId);

void BTL_TOKUSEI_RunAway_ShowEscapeMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetRunAwayHandlers(int *handlerCount);
void BTL_TOKUSEI_MoldBreaker_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int BTL_TOKUSEI_MoldBreaker_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key);
void BTL_TOKUSEI_MoldBreaker_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
void BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
void BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet);
const BtlEventHandler *BTL_TOKUSEI_GetMoldBreakerHandlers(int *handlerCount);
void BTL_TOKUSEI_Forecast_ApplyWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void BTL_TOKUSEI_Forecast_ApplyWeatherFormOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void BTL_TOKUSEI_Forecast_RefreshWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void BTL_TOKUSEI_Forecast_ResetFormWhenActive(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive);
void BTL_TOKUSEI_Forecast_ResetFormOnAbilityChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_Forecast_ResetFormOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_Forecast_ResetForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_Forecast_SetFormForWeather(struct BtlSvFlow *flow, int pokeId, u32 weather);
const BtlEventHandler *BTL_TOKUSEI_GetForecastHandlers(int *handlerCount);
const BtlEventHandler *BTL_TOKUSEI_GetStormDrainHandlers(int *handlerCount);
void BTL_TOKUSEI_StormDrain_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void BTL_TOKUSEI_StormDrain_AbsorbWaterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *BTL_TOKUSEI_GetLightningRodHandlers(int *handlerCount);
void BTL_TOKUSEI_LightningRod_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void BTL_TOKUSEI_Redirect_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected);
void BTL_TOKUSEI_LightningRod_AbsorbElectricMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int BTL_TOKUSEI_CheckRedirectMoveType(struct BtlSvFlow *flow, int pokeId, int *work, int typeId);

extern const BtlEventHandler gRunAwayHandlers[];
extern const BtlEventHandler gMoldBreakerHandlers[];
extern const BtlEventHandler gLightningRodHandlers[];
extern const BtlEventHandler gForecastHandlers[];
extern const BtlEventHandler gStormDrainHandlers[];


/* Run Away: after the escape check passes, show the escape message with its sound. */
void BTL_TOKUSEI_RunAway_ShowEscapeMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (BTLV_CORE_EventTrySetFlagIfAttacker(factor, flow, pokeId) != 0) {
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&msg->str, 1, 0x48);
        func_021C888C(&msg->str, 0x56a);
        func_021C88C8(flow, msg);
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetRunAwayHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gRunAwayHandlers;
}


/* Mold Breaker, Turboblaze, Teravolt: when the poke enters, show the message of its own ability. */
void BTL_TOKUSEI_MoldBreaker_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
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
        func_021C88B4(flow, HANDEX_TOKWIN_IN, pokeId);
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        func_021C8838(&msg->str, 2, strId);
        func_021C8860(&msg->str, pokeId);
        func_021C88C8(flow, msg);
        func_021C88B4(flow, HANDEX_TOKWIN_OUT, pokeId);
    }
}


/* Skip check of the holder: ability factors listed as breakable are skipped. */
int BTL_TOKUSEI_MoldBreaker_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && func_0689C9B0(key))
        return 1;
    return 0;
}


/* Mold Breaker: when the holder attacks, install the skip check on its factor (BTL_EVENT_SetFactorSkipCheck stores the pointer unchanged). */
void BTL_TOKUSEI_MoldBreaker_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *skipCheckSet == 0) {
        BTL_EVENT_SetFactorSkipCheck(factor, (u32)BTL_TOKUSEI_MoldBreaker_SkipCheck);
        *skipCheckSet = 1;
    }
}


void BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        BTL_EVENT_ClearFactorSkipCheck(factor);
        *skipCheckSet = 0;
    }
}


void BTL_TOKUSEI_MoldBreaker_RemoveSkipCheckOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *skipCheckSet)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *skipCheckSet == 1) {
        BTL_EVENT_ClearFactorSkipCheck(factor);
        *skipCheckSet = 0;
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetMoldBreakerHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gMoldBreakerHandlers;
}


/* Forecast: set the form of the holder from the current weather. */
void BTL_TOKUSEI_Forecast_ApplyWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    BTL_TOKUSEI_Forecast_SetFormForWeather(flow, pokeId, func_021C8288(flow));
    *formActive = 1;
}


void BTL_TOKUSEI_Forecast_ApplyWeatherFormOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) BTL_TOKUSEI_Forecast_ApplyWeatherForm(factor, flow, pokeId, formActive);
}


void BTL_TOKUSEI_Forecast_RefreshWeatherForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) BTL_TOKUSEI_Forecast_SetFormForWeather(flow, pokeId, func_021C8288(flow));
}


void BTL_TOKUSEI_Forecast_ResetFormWhenActive(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *formActive)
{
    if (*formActive != 0) BTL_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
}


/* Go back to the base form when the holder gets another ability. */
void BTL_TOKUSEI_Forecast_ResetFormOnAbilityChange(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int newAbilityId;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        newAbilityId = BTL_EVENT_GetVar(BTL_EVAR_NEW_ABILITY_ID);
        if (newAbilityId != BTL_EVENT_GetFactorKey(factor)) BTL_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
    }
}


void BTL_TOKUSEI_Forecast_ResetFormOnEvent6A(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) BTL_TOKUSEI_Forecast_ResetForm(factor, flow, pokeId);
}


/* Put a Castform that is not in its base form back to the base form. */
void BTL_TOKUSEI_Forecast_ResetForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;

    bpp = func_021C7CF4(flow, pokeId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == SPECIES_CASTFORM && func_021D59B4(bpp, BPP_VALUE_FORM) != 0) {
        cmd = func_021C88A4(flow, HANDEX_CHANGE_FORM, pokeId);
        cmd->pokeId = pokeId;
        cmd->form = 0;
        func_021C8838(&cmd->str, 2, 0xde);
        func_021C8860(&cmd->str, pokeId);
        func_021C88C8(flow, cmd);
    }
}


/* Change a Castform to the form of the weather (none, sun, rain, hail); other weather gives the base form. */
void BTL_TOKUSEI_Forecast_SetFormForWeather(struct BtlSvFlow *flow, int pokeId, u32 weather)
{
    HandExChangeForm *cmd;
    struct BtlPokeParam *bpp;
    u32 currentForm;
    u32 newForm;

    bpp = func_021C7CF4(flow, pokeId);
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
            cmd = func_021C88A4(flow, HANDEX_CHANGE_FORM, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = pokeId;
            cmd->form = newForm;
            func_021C8838(&cmd->str, 2, 0xde);
            func_021C8860(&cmd->str, pokeId);
            func_021C88C8(flow, cmd);
        }
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetForecastHandlers(int *handlerCount)
{
    *handlerCount = 9;
    return gForecastHandlers;
}


const BtlEventHandler *BTL_TOKUSEI_GetStormDrainHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gStormDrainHandlers;
}


/* Storm Drain: redirect single-target water moves to the holder. */
void BTL_TOKUSEI_StormDrain_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    *redirected = BTL_TOKUSEI_CheckRedirectMoveType(flow, pokeId, redirected, POKETYPE_WATER);
}


/* Storm Drain: a water move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void BTL_TOKUSEI_StormDrain_AbsorbWaterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER) != 0) BTL_ABILITY_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}


const BtlEventHandler *BTL_TOKUSEI_GetLightningRodHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gLightningRodHandlers;
}


/* Lightning Rod: redirect single-target electric moves to the holder. */
void BTL_TOKUSEI_LightningRod_CheckRedirect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    *redirected = BTL_TOKUSEI_CheckRedirectMoveType(flow, pokeId, redirected, POKETYPE_ELECTRIC);
}


/* Lightning Rod and Storm Drain: show the message when a move was redirected to the holder. */
void BTL_TOKUSEI_Redirect_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *redirected)
{
    HandExMessage *msg;

    if (*redirected != 0) {
        if (func_021E85F8(pokeId) != 0) {
            msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
            msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
            func_021C8838(&msg->str, 2, 0x1c0);
            func_021C8860(&msg->str, pokeId);
            func_021C88C8(flow, msg);
        }
        *redirected = 0;
    }
}


/* Lightning Rod: an electric move that hit the holder is absorbed; the holder gains a Sp. Atk rank. */
void BTL_TOKUSEI_LightningRod_AbsorbElectricMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC) != 0) BTL_ABILITY_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SP_ATTACK, 1);
}


/* True if a move of typeId from another poke can be redirected to the poke pokeId. */
int BTL_TOKUSEI_CheckRedirectMoveType(struct BtlSvFlow *flow, int pokeId, int *work, int typeId)
{
    u8 attackerId;
    u16 moveId;
    u8 targetId;

    attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
    if (attackerId != pokeId && typeId == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (func_021C8290(flow, attackerId, pokeId, moveId) == 0 && func_0689C8EC(moveId) == 0) {
            targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENDER_ID, pokeId) != 0 && targetId != pokeId)
                return 1;
        }
    }
    return 0;
}
