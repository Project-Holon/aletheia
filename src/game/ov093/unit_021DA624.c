/*
 * file:     unit_021DA624.c
 * unit:     yes
 * function: BTL_ABILITY_FriskShowOpponentItem, BTL_ABILITY_SturdyBlockOneHitKo, BTL_ABILITY_SturdyEndureFromFullHp, BTL_ABILITY_SturdyShowEndureMessage, BTL_ABILITY_UnawareNeutralizeStatStages, BTL_ABILITY_UnawareIgnoreAccuracyStage, BTL_ABILITY_UnawareIgnoreEvasionStage, BTL_ABILITY_GetUnawareHandlers, BTL_ABILITY_HeatproofHalveFirePower, BTL_ABILITY_HeatproofHalveBurnDamage, BTL_ABILITY_GetHeatproofHandlers, BTL_ABILITY_AbsorbCheckMoveType, BTL_ABILITY_AbsorbRecoverHp, BTL_ABILITY_AbsorbRaiseStat, BTL_ABILITY_DrySkinWeatherEffect, BTL_ABILITY_DrySkinBoostFireDamage, BTL_ABILITY_DrySkinAbsorbWater, BTL_ABILITY_WaterAbsorbAbsorbWater, BTL_ABILITY_VoltAbsorbAbsorbElectric, BTL_ABILITY_MotorDriveAbsorbElectric, BTL_ABILITY_ScrappyIgnoreGhostImmunity, BTL_ABILITY_SoundproofBlockSoundMove, BTL_ABILITY_GetSoundproofHandlers, BTL_ABILITY_LevitateSetFlag, BTL_ABILITY_LevitateShowMessage, BTL_ABILITY_LevitateClearFlag, BTL_ABILITY_WonderGuardBlockMove, BTL_ABILITY_GetWonderGuardHandlers, BTL_ABILITY_TruantToggleLoafing, BTL_ABILITY_TruantStartLoafing, BTL_ABILITY_TruantShowMessage, BTL_ABILITY_TruantClearLoafing, BTL_ABILITY_DampBlockExplosion, BTL_ABILITY_DampShowMessage, BTL_ABILITY_DampAddSkipCheck, BTL_ABILITY_DampRemoveSkipCheck, BTL_ABILITY_DampRemoveSkipCheckForOwner, BTL_ABILITY_DampSkipAftermath, BTL_ABILITY_GetDampHandlers, BTL_ABILITY_FlashFireBoostFireDamage, BTL_ABILITY_FlashFireClearFlag, BTL_ABILITY_FlashFireAbsorbFire, BTL_ABILITY_GetFlashFireHandlers, BTL_ABILITY_BadDreamsHurtSleepers, BTL_ABILITY_GetBadDreamsHandlers, BTL_ABILITY_RunAwayCheckEscape
 * address:  0x021DA624
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
 *   BTL_EVENT_SetFactorSkipCheck  0x021D7320  thumb  ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7D54 0x021C7D54 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   gFriskHandlerTable 0x021F09B0 data a4
 *   gSturdyHandlerTable 0x021F0B00 data a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_CALC_Max   0x021D7B08  thumb ov093
 *   gUnawareHandlerTable     0x021F0B18  data   ov093  a4
 *   BTL_CALC_DivideMaxHpMin1   0x021D7B74  thumb ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   gDrySkinHandlerTable 0x021F0B30 data a4
 *   gWaterAbsorbHandlerTable 0x021F0730 data a4
 *   gMotorDriveHandlerTable 0x021F0798 data a4
 *   gScrappyHandlerTable 0x021F0790 data a4
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   gHeatproofHandlerTable     0x021F09D0  data   ov093  a4
 *   gLevitateHandlerTable 0x021F0A10 data a4
 *   WAZA_TOOL_IsDamaging   0x0201C314  thumb
 *   gSoundproofHandlerTable     0x021F0788  data   ov093  a4
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   gTruantHandlerTable 0x021F0B94 data a4
 *   gWonderGuardHandlerTable     0x021F0660  data   ov093  a4
 *   BTL_EVENT_ClearFactorSkipCheck  0x021D7324  thumb  ov093
 *   BTLV_CORE_EventSetFlagIfAttacker  0x021E8878  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   gDampHandlerTable     0x021F0BD4  data   ov093  a4
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   gBadDreamsHandlerTable 0x021F07E8 data a4
 *   gFlashFireHandlerTable     0x021F0A28  data   ov093  a4
 */
#include "unit_021DA624_types.h"

void BTL_ABILITY_FriskShowOpponentItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetFriskHandlers(int *handlerCount);
BtlEventHandler *BTL_ABILITY_GetSturdyHandlers(int *handlerCount);
void BTL_ABILITY_SturdyBlockOneHitKo(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_SturdyEndureFromFullHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_SturdyShowEndureMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_UnawareNeutralizeStatStages(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_UnawareIgnoreAccuracyStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_UnawareIgnoreEvasionStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetUnawareHandlers(int *handlerCount);
void BTL_ABILITY_HeatproofHalveFirePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_HeatproofHalveBurnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetHeatproofHandlers(int *handlerCount);
int BTL_ABILITY_AbsorbCheckMoveType(struct BtlSvFlow *flow, int pokeId, int moveType);
void BTL_ABILITY_AbsorbRecoverHp(struct BtlSvFlow *flow, int pokeId, int divisor);
void BTL_ABILITY_AbsorbRaiseStat(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount);
void BTL_ABILITY_DrySkinWeatherEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_DrySkinBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_DrySkinAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetDrySkinHandlers(int *handlerCount);
void BTL_ABILITY_WaterAbsorbAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetWaterAbsorbHandlers(int *handlerCount);
void BTL_ABILITY_VoltAbsorbAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetVoltAbsorbHandlers(int *handlerCount);
BtlEventHandler *BTL_ABILITY_GetMotorDriveHandlers(int *handlerCount);
void BTL_ABILITY_MotorDriveAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_ScrappyIgnoreGhostImmunity(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetScrappyHandlers(int *handlerCount);
void BTL_ABILITY_SoundproofBlockSoundMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetSoundproofHandlers(int *handlerCount);
void BTL_ABILITY_LevitateSetFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_LevitateShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_LevitateClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *BTL_ABILITY_GetLevitateHandlers(int *handlerCount);
void BTL_ABILITY_WonderGuardBlockMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetWonderGuardHandlers(int *handlerCount);
void BTL_ABILITY_TruantToggleLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_TruantStartLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_TruantShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_TruantClearLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *BTL_ABILITY_GetTruantHandlers(int *handlerCount);
void BTL_ABILITY_DampBlockExplosion(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_DampShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void BTL_ABILITY_DampAddSkipCheck(struct BtlEventFactor *factor);
void BTL_ABILITY_DampRemoveSkipCheck(struct BtlEventFactor *factor);
void BTL_ABILITY_DampRemoveSkipCheckForOwner(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int BTL_ABILITY_DampSkipAftermath(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);
BtlEventHandler *BTL_ABILITY_GetDampHandlers(int *handlerCount);
void BTL_ABILITY_FlashFireBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_FlashFireClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_ABILITY_FlashFireAbsorbFire(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetFlashFireHandlers(int *handlerCount);
void BTL_ABILITY_BadDreamsHurtSleepers(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *BTL_ABILITY_GetBadDreamsHandlers(int *handlerCount);
void BTL_ABILITY_RunAwayCheckEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg);
extern void BTLV_CORE_EventSetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg);

/* Handler tables: pairs of an event id and the function that answers it. */
extern BtlEventHandler gFriskHandlerTable[], gSturdyHandlerTable[];
extern BtlEventHandler gUnawareHandlerTable[];
extern BtlEventHandler gDrySkinHandlerTable[];
extern BtlEventHandler gWaterAbsorbHandlerTable[];
extern BtlEventHandler gMotorDriveHandlerTable[];
extern BtlEventHandler gScrappyHandlerTable[];
extern BtlEventHandler gHeatproofHandlerTable[];
extern BtlEventHandler gLevitateHandlerTable[];
extern BtlEventHandler gSoundproofHandlerTable[];
extern BtlEventHandler gTruantHandlerTable[];
extern BtlEventHandler gWonderGuardHandlerTable[];
extern BtlEventHandler gDampHandlerTable[];
extern BtlEventHandler gFlashFireHandlerTable[];
extern BtlEventHandler gBadDreamsHandlerTable[];

/* Frisk: on entry, shows the held item of one opposing Pokemon chosen at random. */
void BTL_ABILITY_FriskShowOpponentItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 itemIds[4];
    u8 targetIds[4];
    u8 targetCount;
    u8 itemCount;
    u8 i;
    u8 choice;
    BtlMessageCmd *cmd;
    struct BtlPokeParam *target;
    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) return;
    targetCount = func_021C7D54(flow, pokeId, targetIds);
    itemCount = 0;
    for (i = 0; i < targetCount; i++) {
        target = func_021C7CF4(flow, targetIds[i]);
        itemIds[itemCount] = BTL_POKEPARAM_GetItem(target);
        if (itemIds[itemCount] != 0) itemCount++;
    }
    if (itemCount == 0) return;
    choice = BTL_CALC_Random(itemCount);
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FRISK_ITEM);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C8860(&cmd->strParam, itemIds[choice]);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *BTL_ABILITY_GetFriskHandlers(int *handlerCount) { *handlerCount = 2; return gFriskHandlerTable; }

BtlEventHandler *BTL_ABILITY_GetSturdyHandlers(int *handlerCount) { *handlerCount = 3; return gSturdyHandlerTable; }

/* Sturdy: a one-hit knockout move against the owner has no effect. */
void BTL_ABILITY_SturdyBlockOneHitKo(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1) == 0)
        return;
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

/* Sturdy: at full HP the owner survives a knockout blow; work[0] tells the message handler. */
void BTL_ABILITY_SturdyEndureFromFullHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_IsHpFull(func_021C7CF4(flow, pokeId)) != 0) {
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_ENDURE_REASON, BTL_ENDURE_REASON_STURDY);
            return;
        }
        *work = 0;
    }
}

/* Sturdy: shows the message after the owner has endured a blow. */
void BTL_ABILITY_SturdyShowEndureMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (*work == 0)
        return;
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_STURDY_ENDURE);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    *work = 0;
}

/* Unaware: the attacker ignores the defender's defense boosts, the defender ignores the attacker's attack boosts. */
void BTL_ABILITY_UnawareNeutralizeStatStages(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENSE_STAGE, BTL_STAT_STAGE_NEUTRAL);
        return;
    }
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ATTACK_STAGE, BTL_STAT_STAGE_NEUTRAL);
}

/* Unaware: when the owner defends, sets the generic flag (ignores the attacker's accuracy boosts). */
void BTL_ABILITY_UnawareIgnoreAccuracyStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
}

/* Unaware: when the owner attacks, sets the generic flag (ignores the defender's evasion boosts). */
void BTL_ABILITY_UnawareIgnoreEvasionStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
}

BtlEventHandler *BTL_ABILITY_GetUnawareHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gUnawareHandlerTable;
}

/* Heatproof: fire moves against the owner lose half their power. */
void BTL_ABILITY_HeatproofHalveFirePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_0_5);
}

/* Heatproof: burn damage to the owner is halved (at least 1). */
void BTL_ABILITY_HeatproofHalveBurnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int damage;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) != BTL_SICK_BURN)
        return;
    damage = BTL_EVENT_GetVar(BTL_EVAR_DAMAGE);
    BTL_EVENT_OverwriteVar(BTL_EVAR_DAMAGE, BTL_CALC_Max(damage / 2, 1));
}

BtlEventHandler *BTL_ABILITY_GetHeatproofHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHeatproofHandlerTable;
}

/* Absorb abilities: nonzero when a move of moveType from another Pokemon hits the owner and is nullified. */
int BTL_ABILITY_AbsorbCheckMoveType(struct BtlSvFlow *flow, int pokeId, int moveType)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && moveType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE))
        return BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    return 0;
}

/* Absorb abilities: restore 1/divisor of the owner's HP, or show "no effect" at full HP. */
void BTL_ABILITY_AbsorbRecoverHp(struct BtlSvFlow *flow, int pokeId, int divisor)
{
    struct BtlPokeParam *owner;
    BtlRecoverHpCmd *recoverCmd;
    BtlMessageCmd *messageCmd;

    owner = func_021C7CF4(flow, pokeId);
    if (BTL_POKEPARAM_IsHpFull(owner) == 0) {
        recoverCmd = func_021C88A4(flow, BTL_CMD_RECOVER_HP, pokeId);
        recoverCmd->pokeId = pokeId;
        recoverCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, divisor);
        recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&recoverCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABSORB_RECOVER_HP);
        func_021C8860(&recoverCmd->strParam, pokeId);
        func_021C88C8(flow, recoverCmd);
    } else {
        messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        func_021C8860(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C88C8(flow, messageCmd);
    }
    BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
}

/* Absorb abilities: raise a stat of the owner, or show "no effect" when it cannot rise. */
void BTL_ABILITY_AbsorbRaiseStat(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount)
{
    BtlRankCmd *rankCmd;
    BtlMessageCmd *messageCmd;

    if (func_021D5D14(func_021C7CF4(flow, pokeId), statId, amount) != 0) {
        rankCmd = func_021C88A4(flow, BTL_CMD_RANK, pokeId);
        rankCmd->targetCount = 1;
        rankCmd->targets[0] = pokeId;
        rankCmd->showMessage = 1;
        rankCmd->statId = statId;
        rankCmd->amount = amount;
        rankCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C88C8(flow, rankCmd);
    } else {
        messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        func_021C8860(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C88C8(flow, messageCmd);
    }
}

/* Dry Skin: sun hurts the owner by 1/8, rain restores 1/8. */
void BTL_ABILITY_DrySkinWeatherEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlDamageCmd *damageCmd;
    BtlRecoverHpCmd *recoverCmd;
    struct BtlPokeParam *owner;
    u8 weather;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        owner = func_021C7CF4(flow, pokeId);
        weather = BTL_EVENT_GetVar(BTL_EVAR_WEATHER);
        if (weather == BTL_WEATHER_SUN) {
            func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            damageCmd = func_021C88A4(flow, BTL_CMD_DAMAGE, pokeId);
            damageCmd->pokeId = pokeId;
            damageCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, 8);
            func_021C88C8(flow, damageCmd);
            func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        } else if (weather == BTL_WEATHER_RAIN) {
            recoverCmd = func_021C88A4(flow, BTL_CMD_RECOVER_HP, pokeId);
            recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            recoverCmd->pokeId = pokeId;
            recoverCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, 8);
            func_021C88C8(flow, recoverCmd);
        }
    }
}

/* Dry Skin: fire moves against the owner gain 1.25 times power. */
void BTL_ABILITY_DrySkinBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_25);
}

/* Dry Skin: absorbs water moves and restores 1/4 of the HP. */
void BTL_ABILITY_DrySkinAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER))
        BTL_ABILITY_AbsorbRecoverHp(flow, pokeId, 4);
}

BtlEventHandler *BTL_ABILITY_GetDrySkinHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gDrySkinHandlerTable;
}

/* Water Absorb: absorbs water moves and restores 1/4 of the HP. */
void BTL_ABILITY_WaterAbsorbAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER))
        BTL_ABILITY_AbsorbRecoverHp(flow, pokeId, 4);
}

BtlEventHandler *BTL_ABILITY_GetWaterAbsorbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWaterAbsorbHandlerTable;
}

/* Volt Absorb: absorbs electric moves and restores 1/4 of the HP. */
void BTL_ABILITY_VoltAbsorbAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC))
        BTL_ABILITY_AbsorbRecoverHp(flow, pokeId, 4);
}

/* Volt Absorb's table is the second row after the start of Motor Drive's table object. */
BtlEventHandler *BTL_ABILITY_GetVoltAbsorbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMotorDriveHandlerTable + 1;
}

BtlEventHandler *BTL_ABILITY_GetMotorDriveHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMotorDriveHandlerTable;
}

/* Motor Drive: absorbs electric moves and raises Speed by one stage. */
void BTL_ABILITY_MotorDriveAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC))
        BTL_ABILITY_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SPEED, 1);
}

/* Scrappy: the owner's attacks ignore the immunity of Ghost types. */
void BTL_ABILITY_ScrappyIgnoreGhostImmunity(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_TYPE) == POKETYPE_GHOST)
        BTL_EVENT_OverwriteVar(BTL_EVAR_IGNORE_IMMUNITY_FLAG, 1);
}

BtlEventHandler *BTL_ABILITY_GetScrappyHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gScrappyHandlerTable;
}

/* Soundproof: sound moves against the owner have no effect. */
void BTL_ABILITY_SoundproofBlockSoundMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_SOUND) != 0 && BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
            func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            func_021C8860(&cmd->strParam, pokeId);
            func_021C88C8(flow, cmd);
            func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        }
    }
}

BtlEventHandler *BTL_ABILITY_GetSoundproofHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSoundproofHandlerTable;
}

/* Levitate: sets the generic flag once for the owner; work[0] gets the result. */
void BTL_ABILITY_LevitateSetFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_GENERIC_FLAG) == 0)
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1);
    }
}

/* Levitate: shows "no effect" once when the flag was set. */
void BTL_ABILITY_LevitateShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        func_021C8860(&cmd->strParam, pokeId);
        func_021C88C8(flow, cmd);
        *work = 0;
    }
}

/* Levitate: clears the flag when the owner's event ends. */
void BTL_ABILITY_LevitateClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        *work = 0;
}

BtlEventHandler *BTL_ABILITY_GetLevitateHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gLevitateHandlerTable;
}

/* Wonder Guard: damaging moves from another Pokemon that are not super effective have no effect. */
void BTL_ABILITY_WonderGuardBlockMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;
    struct BtlPokeParam *defender;
    u16 moveId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    defender = func_021C7CF4(flow, pokeId);
    moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
    if (WAZA_TOOL_IsDamaging(moveId) == 0)
        return;
    if (moveId == BTL_MOVE_STRUGGLE)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_NEUTRAL)
        return;
    if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) == 0)
        return;
    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
    func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    func_021C8860(&cmd->strParam, pokeId);
    func_021C88C8(flow, cmd);
    func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *BTL_ABILITY_GetWonderGuardHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWonderGuardHandlerTable;
}

/* Truant: every other turn the owner loafs; work[0] is the loafing flag, work[1] the fail result. */
void BTL_ABILITY_TruantToggleLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (*work != 0) {
            work[1] = BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY);
            *work = 0;
        } else
            *work = 1;
    }
}

/* Truant: starts loafing for the next turn after the owner acted. */
void BTL_ABILITY_TruantStartLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_TestTurnFlag(func_021C7CF4(flow, pokeId), 0))
            *work = 1;
    }
}

/* Truant: shows the loafing message when the fail result is set. */
void BTL_ABILITY_TruantShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work[1] != 0) {
        cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_TRUANT_LOAFING);
        func_021C8860(&cmd->strParam, pokeId);
        func_021C88C8(flow, cmd);
        work[1] = 0;
    }
}

/* Truant: clears the loafing flag when the event variable 12 is 7. */
void BTL_ABILITY_TruantClearLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(12) == 7)
        *work = 0;
}

BtlEventHandler *BTL_ABILITY_GetTruantHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gTruantHandlerTable;
}

/* Damp: Explosion and Self-Destruct fail; work[0] is the fail result, work[1] the move. */
void BTL_ABILITY_DampBlockExplosion(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u16 moveId;
    moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
    *work = 0;
    if (moveId == BTL_MOVE_EXPLOSION || moveId == BTL_MOVE_SELF_DESTRUCT) {
        if (BTL_EVENT_GetVar(BTL_EVAR_FAIL_REASON) == 0) {
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ABILITY);
            work[1] = moveId;
        }
    }
}

/* Damp: shows the message that names the owner and the blocked move. */
void BTL_ABILITY_DampShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;
    u32 ownerId;

    if (*work != 0) {
        ownerId = (u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
        cmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_DAMP_BLOCK);
        func_021C8860(&cmd->strParam, ownerId);
        func_021C8860(&cmd->strParam, work[1]);
        func_021C88C8(flow, cmd);
        *work = 0;
    }
}

/* Damp: while the owner is on the field, Aftermath is blocked. */
void BTL_ABILITY_DampAddSkipCheck(struct BtlEventFactor *factor)
{
    BTL_EVENT_SetFactorSkipCheck(factor, BTL_ABILITY_DampSkipAftermath);
}

/* Damp: removes the skip check. */
void BTL_ABILITY_DampRemoveSkipCheck(struct BtlEventFactor *factor)
{
    BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Damp: removes the skip check when the owner's event comes. */
void BTL_ABILITY_DampRemoveSkipCheckForOwner(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Damp: skip check that blocks the factors of the Aftermath ability. */
int BTL_ABILITY_DampSkipAftermath(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && key == ABILITY_AFTERMATH) {
        return 1;
    }
    return 0;
}

BtlEventHandler *BTL_ABILITY_GetDampHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gDampHandlerTable;
}

/* Flash Fire: after absorbing fire, the owner's fire moves gain 1.5 times power. */
void BTL_ABILITY_FlashFireBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_POKEPARAM_TestContFlag(func_021C7CF4(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
}

/* Flash Fire: clears the absorbed-fire flag of the owner. */
void BTL_ABILITY_FlashFireClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlContFlagCmd *cmd;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_POKEPARAM_TestContFlag(func_021C7CF4(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE)) {
        cmd = func_021C88A4(flow, BTL_CMD_CLEAR_CONT_FLAG, pokeId);
        cmd->pokeId = pokeId;
        cmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
        func_021C88C8(flow, cmd);
    }
}

/* Flash Fire: absorbs fire moves; the first time it also sets the absorbed-fire flag. */
void BTL_ABILITY_FlashFireAbsorbFire(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *messageCmd;
    BtlContFlagCmd *flagCmd;

    if (BTL_ABILITY_AbsorbCheckMoveType(flow, pokeId, POKETYPE_FIRE) != 0) {
        func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
        if (BTL_POKEPARAM_TestContFlag(func_021C7CF4(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) == 0) {
            messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
            func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FLASH_FIRE_ABSORB);
            func_021C8860(&messageCmd->strParam, pokeId);
            func_021C88C8(flow, messageCmd);
            flagCmd = func_021C88A4(flow, BTL_CMD_SET_CONT_FLAG, pokeId);
            flagCmd->pokeId = pokeId;
            flagCmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
            func_021C88C8(flow, flagCmd);
        } else {
            messageCmd = func_021C88A4(flow, BTL_CMD_MESSAGE, pokeId);
            func_021C8838(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            func_021C8860(&messageCmd->strParam, pokeId);
            func_021C88C8(flow, messageCmd);
        }
        func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *BTL_ABILITY_GetFlashFireHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gFlashFireHandlerTable;
}

/* Bad Dreams: hurts every sleeping opposing Pokemon by 1/8 of its HP. */
void BTL_ABILITY_BadDreamsHurtSleepers(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 victimIds[4];
    struct BtlPokeParam *victim;
    u8 victimCount;
    int popupOpen;
    BtlDamageCmd *cmd;
    u8 i;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        popupOpen = 0;
        victimCount = func_021C7F68(flow, func_021C7D00(flow, pokeId) | 0x100, victimIds);
        for (i = 0; i < victimCount; i++) {
            victim = func_021C7CF4(flow, victimIds[i]);
            if (BTL_POKEPARAM_HasSick(victim, BTL_SICK_SLEEP)) {
                if (!popupOpen) {
                    popupOpen = 1;
                    func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
                }
                cmd = func_021C88A4(flow, BTL_CMD_DAMAGE, pokeId);
                cmd->pokeId = victimIds[i];
                cmd->amount = BTL_CALC_DivideMaxHpMin1(victim, 8);
                func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_BAD_DREAMS_HURT);
                func_021C8860(&cmd->strParam, victimIds[i]);
                func_021C88C8(flow, cmd);
            }
        }
        if (popupOpen) func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *BTL_ABILITY_GetBadDreamsHandlers(int *handlerCount) { *handlerCount = 1; return gBadDreamsHandlerTable; }

/* Run Away: the first handler of its table; belongs to unit_021DB0E4.c. */
void BTL_ABILITY_RunAwayCheckEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg)
{
    BTLV_CORE_EventSetFlagIfAttacker(factor, flow, pokeId, unusedArg);
}
