/*
 * file:     hand_tokusei_021da624.c
 * unit:     yes
 * function: HAND_TOKUSEI_FriskShowOpponentItem, HAND_TOKUSEI_SturdyBlockOneHitKo, HAND_TOKUSEI_SturdyEndureFromFullHp, HAND_TOKUSEI_SturdyShowEndureMessage, HAND_TOKUSEI_UnawareNeutralizeStatStages, HAND_TOKUSEI_UnawareIgnoreAccuracyStage, HAND_TOKUSEI_UnawareIgnoreEvasionStage, HAND_TOKUSEI_GetUnawareHandlers, HAND_TOKUSEI_HeatproofHalveFirePower, HAND_TOKUSEI_HeatproofHalveBurnDamage, HAND_TOKUSEI_GetHeatproofHandlers, HAND_TOKUSEI_AbsorbCheckMoveType, HAND_TOKUSEI_AbsorbRecoverHp, HAND_TOKUSEI_AbsorbRaiseStat, HAND_TOKUSEI_DrySkinWeatherEffect, HAND_TOKUSEI_DrySkinBoostFireDamage, HAND_TOKUSEI_DrySkinAbsorbWater, HAND_TOKUSEI_WaterAbsorbAbsorbWater, HAND_TOKUSEI_VoltAbsorbAbsorbElectric, HAND_TOKUSEI_MotorDriveAbsorbElectric, HAND_TOKUSEI_ScrappyIgnoreGhostImmunity, HAND_TOKUSEI_SoundproofBlockSoundMove, HAND_TOKUSEI_GetSoundproofHandlers, HAND_TOKUSEI_LevitateSetFlag, HAND_TOKUSEI_LevitateShowMessage, HAND_TOKUSEI_LevitateClearFlag, HAND_TOKUSEI_WonderGuardBlockMove, HAND_TOKUSEI_GetWonderGuardHandlers, HAND_TOKUSEI_TruantToggleLoafing, HAND_TOKUSEI_TruantStartLoafing, HAND_TOKUSEI_TruantShowMessage, HAND_TOKUSEI_TruantClearLoafing, HAND_TOKUSEI_DampBlockExplosion, HAND_TOKUSEI_DampShowMessage, HAND_TOKUSEI_DampAddSkipCheck, HAND_TOKUSEI_DampRemoveSkipCheck, HAND_TOKUSEI_DampRemoveSkipCheckForOwner, HAND_TOKUSEI_DampSkipAftermath, HAND_TOKUSEI_GetDampHandlers, HAND_TOKUSEI_FlashFireBoostFireDamage, HAND_TOKUSEI_FlashFireClearFlag, HAND_TOKUSEI_FlashFireAbsorbFire, HAND_TOKUSEI_GetFlashFireHandlers, HAND_TOKUSEI_BadDreamsHurtSleepers, HAND_TOKUSEI_GetBadDreamsHandlers, HAND_TOKUSEI_RunAwayCheckEscape
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
 *   BTL_SERVER_FLOW_CollectOpponentPokeIds 0x021C7D54 thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord 0x021C88B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gFriskHandlers 0x021F09B0 data a4
 *   gSturdyHandlers 0x021F0B00 data a4
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *   BTL_POKEPARAM_IsHpFull 0x021D5B48 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_CALC_Max   0x021D7B08  thumb ov093
 *   gUnawareHandlers     0x021F0B18  data   ov093  a4
 *   BTL_CALC_DivideMaxHpMin1   0x021D7B74  thumb ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   gDrySkinHandlers 0x021F0B30 data a4
 *   gWaterAbsorbHandlers 0x021F0730 data a4
 *   gMotorDriveHandlers 0x021F0798 data a4
 *   gScrappyHandlers 0x021F0790 data a4
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   gHeatproofHandlers     0x021F09D0  data   ov093  a4
 *   gLevitateHandlers 0x021F0A10 data a4
 *   WAZA_TOOL_IsDamaging   0x0201C314  thumb
 *   gSoundproofHandlers     0x021F0788  data   ov093  a4
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   gTruantHandlers 0x021F0B94 data a4
 *   gWonderGuardHandlers     0x021F0660  data   ov093  a4
 *   BTL_EVENT_ClearFactorSkipCheck  0x021D7324  thumb  ov093
 *   BTLV_CORE_EventSetFlagIfAttacker  0x021E8878  thumb  ov093
 *   BTL_POKEPARAM_TestContFlag 0x021D5BDC thumb ov093
 *   gDampHandlers     0x021F0BD4  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke 0x021C7D00 thumb ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds 0x021C7F68 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   gBadDreamsHandlers 0x021F07E8 data a4
 *   gFlashFireHandlers     0x021F0A28  data   ov093  a4
 */
#include "hand_tokusei_021da624_types.h"

void HAND_TOKUSEI_FriskShowOpponentItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetFriskHandlers(int *handlerCount);
BtlEventHandler *HAND_TOKUSEI_GetSturdyHandlers(int *handlerCount);
void HAND_TOKUSEI_SturdyBlockOneHitKo(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_SturdyEndureFromFullHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_SturdyShowEndureMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_UnawareNeutralizeStatStages(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_UnawareIgnoreAccuracyStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_UnawareIgnoreEvasionStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetUnawareHandlers(int *handlerCount);
void HAND_TOKUSEI_HeatproofHalveFirePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_HeatproofHalveBurnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetHeatproofHandlers(int *handlerCount);
int HAND_TOKUSEI_AbsorbCheckMoveType(struct BtlSvFlow *flow, int pokeId, int moveType);
void HAND_TOKUSEI_AbsorbRecoverHp(struct BtlSvFlow *flow, int pokeId, int divisor);
void HAND_TOKUSEI_AbsorbRaiseStat(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount);
void HAND_TOKUSEI_DrySkinWeatherEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_DrySkinBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_DrySkinAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetDrySkinHandlers(int *handlerCount);
void HAND_TOKUSEI_WaterAbsorbAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetWaterAbsorbHandlers(int *handlerCount);
void HAND_TOKUSEI_VoltAbsorbAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetVoltAbsorbHandlers(int *handlerCount);
BtlEventHandler *HAND_TOKUSEI_GetMotorDriveHandlers(int *handlerCount);
void HAND_TOKUSEI_MotorDriveAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_ScrappyIgnoreGhostImmunity(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetScrappyHandlers(int *handlerCount);
void HAND_TOKUSEI_SoundproofBlockSoundMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetSoundproofHandlers(int *handlerCount);
void HAND_TOKUSEI_LevitateSetFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_LevitateShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_LevitateClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_TOKUSEI_GetLevitateHandlers(int *handlerCount);
void HAND_TOKUSEI_WonderGuardBlockMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetWonderGuardHandlers(int *handlerCount);
void HAND_TOKUSEI_TruantToggleLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_TruantStartLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_TruantShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_TruantClearLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_TOKUSEI_GetTruantHandlers(int *handlerCount);
void HAND_TOKUSEI_DampBlockExplosion(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_DampShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_TOKUSEI_DampAddSkipCheck(struct BtlEventFactor *factor);
void HAND_TOKUSEI_DampRemoveSkipCheck(struct BtlEventFactor *factor);
void HAND_TOKUSEI_DampRemoveSkipCheckForOwner(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int HAND_TOKUSEI_DampSkipAftermath(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId);
BtlEventHandler *HAND_TOKUSEI_GetDampHandlers(int *handlerCount);
void HAND_TOKUSEI_FlashFireBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_FlashFireClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void HAND_TOKUSEI_FlashFireAbsorbFire(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetFlashFireHandlers(int *handlerCount);
void HAND_TOKUSEI_BadDreamsHurtSleepers(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
BtlEventHandler *HAND_TOKUSEI_GetBadDreamsHandlers(int *handlerCount);
void HAND_TOKUSEI_RunAwayCheckEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg);
extern void BTLV_CORE_EventSetFlagIfAttacker(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg);

/* Handler tables: pairs of an event id and the function that answers it. */
extern BtlEventHandler gFriskHandlers[], gSturdyHandlers[];
extern BtlEventHandler gUnawareHandlers[];
extern BtlEventHandler gDrySkinHandlers[];
extern BtlEventHandler gWaterAbsorbHandlers[];
extern BtlEventHandler gMotorDriveHandlers[];
extern BtlEventHandler gScrappyHandlers[];
extern BtlEventHandler gHeatproofHandlers[];
extern BtlEventHandler gLevitateHandlers[];
extern BtlEventHandler gSoundproofHandlers[];
extern BtlEventHandler gTruantHandlers[];
extern BtlEventHandler gWonderGuardHandlers[];
extern BtlEventHandler gDampHandlers[];
extern BtlEventHandler gFlashFireHandlers[];
extern BtlEventHandler gBadDreamsHandlers[];

/* Frisk: on entry, shows the held item of one opposing Pokemon chosen at random. */
void HAND_TOKUSEI_FriskShowOpponentItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
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
    targetCount = BTL_SERVER_FLOW_CollectOpponentPokeIds(flow, pokeId, targetIds);
    itemCount = 0;
    for (i = 0; i < targetCount; i++) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetIds[i]);
        itemIds[itemCount] = BTL_POKEPARAM_GetItem(target);
        if (itemIds[itemCount] != 0) itemCount++;
    }
    if (itemCount == 0) return;
    choice = BTL_CALC_Random(itemCount);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FRISK_ITEM);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, itemIds[choice]);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *HAND_TOKUSEI_GetFriskHandlers(int *handlerCount) { *handlerCount = 2; return gFriskHandlers; }

BtlEventHandler *HAND_TOKUSEI_GetSturdyHandlers(int *handlerCount) { *handlerCount = 3; return gSturdyHandlers; }

/* Sturdy: a one-hit knockout move against the owner has no effect. */
void HAND_TOKUSEI_SturdyBlockOneHitKo(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1) == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

/* Sturdy: at full HP the owner survives a knockout blow; work[0] tells the message handler. */
void HAND_TOKUSEI_SturdyEndureFromFullHp(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)) != 0) {
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_ENDURE_REASON, BTL_ENDURE_REASON_STURDY);
            return;
        }
        *work = 0;
    }
}

/* Sturdy: shows the message after the owner has endured a blow. */
void HAND_TOKUSEI_SturdyShowEndureMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (*work == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_STURDY_ENDURE);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    *work = 0;
}

/* Unaware: the attacker ignores the defender's defense boosts, the defender ignores the attacker's attack boosts. */
void HAND_TOKUSEI_UnawareNeutralizeStatStages(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        BTL_EVENT_OverwriteVar(BTL_EVAR_DEFENSE_STAGE, BTL_STAT_STAGE_NEUTRAL);
        return;
    }
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ATTACK_STAGE, BTL_STAT_STAGE_NEUTRAL);
}

/* Unaware: when the owner defends, sets the generic flag (ignores the attacker's accuracy boosts). */
void HAND_TOKUSEI_UnawareIgnoreAccuracyStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/* Unaware: when the owner attacks, sets the generic flag (ignores the defender's evasion boosts). */
void HAND_TOKUSEI_UnawareIgnoreEvasionStage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

BtlEventHandler *HAND_TOKUSEI_GetUnawareHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gUnawareHandlers;
}

/* Heatproof: fire moves against the owner lose half their power. */
void HAND_TOKUSEI_HeatproofHalveFirePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_0_5);
}

/* Heatproof: burn damage to the owner is halved (at least 1). */
void HAND_TOKUSEI_HeatproofHalveBurnDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int damage;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_SICK_ID) != BTL_SICK_BURN)
        return;
    damage = BTL_EVENT_GetVar(BTL_EVAR_DAMAGE);
    BTL_EVENT_OverwriteVar(BTL_EVAR_DAMAGE, BTL_CALC_Max(damage / 2, 1));
}

BtlEventHandler *HAND_TOKUSEI_GetHeatproofHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHeatproofHandlers;
}

/* Absorb abilities: nonzero when a move of moveType from another Pokemon hits the owner and is nullified. */
int HAND_TOKUSEI_AbsorbCheckMoveType(struct BtlSvFlow *flow, int pokeId, int moveType)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && pokeId != BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && moveType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE))
        return BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1);
    return 0;
}

/* Absorb abilities: restore 1/divisor of the owner's HP, or show "no effect" at full HP. */
void HAND_TOKUSEI_AbsorbRecoverHp(struct BtlSvFlow *flow, int pokeId, int divisor)
{
    struct BtlPokeParam *owner;
    BtlRecoverHpCmd *recoverCmd;
    BtlMessageCmd *messageCmd;

    owner = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    if (BTL_POKEPARAM_IsHpFull(owner) == 0) {
        recoverCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RECOVER_HP, pokeId);
        recoverCmd->pokeId = pokeId;
        recoverCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, divisor);
        recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&recoverCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABSORB_RECOVER_HP);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&recoverCmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, recoverCmd);
    } else {
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
    BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
}

/* Absorb abilities: raise a stat of the owner, or show "no effect" when it cannot rise. */
void HAND_TOKUSEI_AbsorbRaiseStat(struct BtlSvFlow *flow, int pokeId, u32 statId, int amount)
{
    BtlRankCmd *rankCmd;
    BtlMessageCmd *messageCmd;

    if (func_021D5D14(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), statId, amount) != 0) {
        rankCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RANK, pokeId);
        rankCmd->targetCount = 1;
        rankCmd->targets[0] = pokeId;
        rankCmd->showMessage = 1;
        rankCmd->statId = statId;
        rankCmd->amount = amount;
        rankCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, rankCmd);
    } else {
        messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
        messageCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
    }
}

/* Dry Skin: sun hurts the owner by 1/8, rain restores 1/8. */
void HAND_TOKUSEI_DrySkinWeatherEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlDamageCmd *damageCmd;
    BtlRecoverHpCmd *recoverCmd;
    struct BtlPokeParam *owner;
    u8 weather;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        owner = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        weather = BTL_EVENT_GetVar(BTL_EVAR_WEATHER);
        if (weather == BTL_WEATHER_SUN) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            damageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_DAMAGE, pokeId);
            damageCmd->pokeId = pokeId;
            damageCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, 8);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, damageCmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        } else if (weather == BTL_WEATHER_RAIN) {
            recoverCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_RECOVER_HP, pokeId);
            recoverCmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            recoverCmd->pokeId = pokeId;
            recoverCmd->amount = BTL_CALC_DivideMaxHpMin1(owner, 8);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, recoverCmd);
        }
    }
}

/* Dry Skin: fire moves against the owner gain 1.25 times power. */
void HAND_TOKUSEI_DrySkinBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_25);
}

/* Dry Skin: absorbs water moves and restores 1/4 of the HP. */
void HAND_TOKUSEI_DrySkinAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER))
        HAND_TOKUSEI_AbsorbRecoverHp(flow, pokeId, 4);
}

BtlEventHandler *HAND_TOKUSEI_GetDrySkinHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gDrySkinHandlers;
}

/* Water Absorb: absorbs water moves and restores 1/4 of the HP. */
void HAND_TOKUSEI_WaterAbsorbAbsorbWater(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_WATER))
        HAND_TOKUSEI_AbsorbRecoverHp(flow, pokeId, 4);
}

BtlEventHandler *HAND_TOKUSEI_GetWaterAbsorbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWaterAbsorbHandlers;
}

/* Volt Absorb: absorbs electric moves and restores 1/4 of the HP. */
void HAND_TOKUSEI_VoltAbsorbAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC))
        HAND_TOKUSEI_AbsorbRecoverHp(flow, pokeId, 4);
}

/* Volt Absorb's table is the second row after the start of Motor Drive's table object. */
BtlEventHandler *HAND_TOKUSEI_GetVoltAbsorbHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMotorDriveHandlers + 1;
}

BtlEventHandler *HAND_TOKUSEI_GetMotorDriveHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gMotorDriveHandlers;
}

/* Motor Drive: absorbs electric moves and raises Speed by one stage. */
void HAND_TOKUSEI_MotorDriveAbsorbElectric(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_ELECTRIC))
        HAND_TOKUSEI_AbsorbRaiseStat(flow, pokeId, BTL_STAT_SPEED, 1);
}

/* Scrappy: the owner's attacks ignore the immunity of Ghost types. */
void HAND_TOKUSEI_ScrappyIgnoreGhostImmunity(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_TYPE) == POKETYPE_GHOST)
        BTL_EVENT_OverwriteVar(BTL_EVAR_IMMUNITY_OVERRIDE_FLAG, 1);
}

BtlEventHandler *HAND_TOKUSEI_GetScrappyHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gScrappyHandlers;
}

/* Soundproof: sound moves against the owner have no effect. */
void HAND_TOKUSEI_SoundproofBlockSoundMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        if (WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_SOUND) != 0 && BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
        }
    }
}

BtlEventHandler *HAND_TOKUSEI_GetSoundproofHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gSoundproofHandlers;
}

/* Levitate: sets the generic flag once for the owner; work[0] gets the result. */
void HAND_TOKUSEI_LevitateSetFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_EVENT_GetVar(BTL_EVAR_FORCE_FLOATING_FLAG) == 0)
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_FLOATING_FLAG, 1);
    }
}

/* Levitate: shows "no effect" once when the flag was set. */
void HAND_TOKUSEI_LevitateShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        *work = 0;
    }
}

/* Levitate: clears the flag when the owner's event ends. */
void HAND_TOKUSEI_LevitateClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        *work = 0;
}

BtlEventHandler *HAND_TOKUSEI_GetLevitateHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gLevitateHandlers;
}

/* Wonder Guard: damaging moves from another Pokemon that are not super effective have no effect. */
void HAND_TOKUSEI_WonderGuardBlockMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *cmd;
    struct BtlPokeParam *defender;
    u16 moveId;

    if (pokeId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID))
        return;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        return;
    defender = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
    moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
    if (WAZA_TOOL_IsDamaging(moveId) == 0)
        return;
    if (moveId == BTL_MOVE_STRUGGLE)
        return;
    if (BTL_EVENT_GetVar(BTL_EVAR_TYPE_AFFINITY) > BTL_AFFINITY_NEUTRAL)
        return;
    if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) == 0)
        return;
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
    BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
    BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
}

BtlEventHandler *HAND_TOKUSEI_GetWonderGuardHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWonderGuardHandlers;
}

/* Truant: every other turn the owner loafs; work[0] is the loafing flag, work[1] the fail result. */
void HAND_TOKUSEI_TruantToggleLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
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
void HAND_TOKUSEI_TruantStartLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), 0))
            *work = 1;
    }
}

/* Truant: shows the loafing message when the fail result is set. */
void HAND_TOKUSEI_TruantShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work[1] != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_TRUANT_LOAFING);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        work[1] = 0;
    }
}

/* Truant: clears the loafing flag when the event variable 12 is 7. */
void HAND_TOKUSEI_TruantClearLoafing(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(12) == 7)
        *work = 0;
}

BtlEventHandler *HAND_TOKUSEI_GetTruantHandlers(int *handlerCount)
{
    *handlerCount = 4;
    return gTruantHandlers;
}

/* Damp: Explosion and Self-Destruct fail; work[0] is the fail result, work[1] the move. */
void HAND_TOKUSEI_DampBlockExplosion(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
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
void HAND_TOKUSEI_DampShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BtlMessageCmd *cmd;
    u32 ownerId;

    if (*work != 0) {
        ownerId = (u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_DAMP_BLOCK);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, ownerId);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, work[1]);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        *work = 0;
    }
}

/* Damp: while the owner is on the field, Aftermath is blocked. */
void HAND_TOKUSEI_DampAddSkipCheck(struct BtlEventFactor *factor)
{
    BTL_EVENT_SetFactorSkipCheck(factor, HAND_TOKUSEI_DampSkipAftermath);
}

/* Damp: removes the skip check. */
void HAND_TOKUSEI_DampRemoveSkipCheck(struct BtlEventFactor *factor)
{
    BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Damp: removes the skip check when the owner's event comes. */
void HAND_TOKUSEI_DampRemoveSkipCheckForOwner(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}

/* Damp: skip check that blocks the factors of the Aftermath ability. */
int HAND_TOKUSEI_DampSkipAftermath(struct BtlEventFactor *other, void *context, int factorType, int eventId, u16 key, u8 ownerId)
{
    if (factorType == BTL_EVENT_TYPE_ABILITY && key == ABILITY_AFTERMATH) {
        return 1;
    }
    return 0;
}

BtlEventHandler *HAND_TOKUSEI_GetDampHandlers(int *handlerCount)
{
    *handlerCount = 5;
    return gDampHandlers;
}

/* Flash Fire: after absorbing fire, the owner's fire moves gain 1.5 times power. */
void HAND_TOKUSEI_FlashFireBoostFireDamage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_FIRE)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_1_5);
}

/* Flash Fire: clears the absorbed-fire flag of the owner. */
void HAND_TOKUSEI_FlashFireClearFlag(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlContFlagCmd *cmd;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_CLEAR_CONT_FLAG, pokeId);
        cmd->pokeId = pokeId;
        cmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

/* Flash Fire: absorbs fire moves; the first time it also sets the absorbed-fire flag. */
void HAND_TOKUSEI_FlashFireAbsorbFire(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlMessageCmd *messageCmd;
    BtlContFlagCmd *flagCmd;

    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, pokeId, POKETYPE_FIRE) != 0) {
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId), BTL_CONT_FLAG_FLASH_FIRE) == 0) {
            messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_FLASH_FIRE_ABSORB);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
            flagCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_SET_CONT_FLAG, pokeId);
            flagCmd->pokeId = pokeId;
            flagCmd->flagIndex = BTL_CONT_FLAG_FLASH_FIRE;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, flagCmd);
        } else {
            messageCmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&messageCmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_ABILITY_NO_EFFECT);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&messageCmd->strParam, pokeId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, messageCmd);
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *HAND_TOKUSEI_GetFlashFireHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gFlashFireHandlers;
}

/* Bad Dreams: hurts every sleeping opposing Pokemon by 1/8 of its HP. */
void HAND_TOKUSEI_BadDreamsHurtSleepers(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 victimIds[4];
    struct BtlPokeParam *victim;
    u8 victimCount;
    int popupOpen;
    BtlDamageCmd *cmd;
    u8 i;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        popupOpen = 0;
        victimCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, pokeId) | 0x100, victimIds);
        for (i = 0; i < victimCount; i++) {
            victim = BTL_SERVER_FLOW_GetPokeParam(flow, victimIds[i]);
            if (BTL_POKEPARAM_HasSick(victim, BTL_SICK_SLEEP)) {
                if (!popupOpen) {
                    popupOpen = 1;
                    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, pokeId);
                }
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_DAMAGE, pokeId);
                cmd->pokeId = victimIds[i];
                cmd->amount = BTL_CALC_DivideMaxHpMin1(victim, 8);
                BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_BAD_DREAMS_HURT);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, victimIds[i]);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
        if (popupOpen) BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, pokeId);
    }
}

BtlEventHandler *HAND_TOKUSEI_GetBadDreamsHandlers(int *handlerCount) { *handlerCount = 1; return gBadDreamsHandlers; }

/* Run Away: the first handler of its table; belongs to hand_tokusei_021db0e4.c. */
void HAND_TOKUSEI_RunAwayCheckEscape(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int unusedArg)
{
    BTLV_CORE_EventSetFlagIfAttacker(factor, flow, pokeId, unusedArg);
}
