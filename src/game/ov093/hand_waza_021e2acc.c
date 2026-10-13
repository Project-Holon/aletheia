/*
 * file:     hand_waza_021e2acc.c
 * unit:     yes
 * function: HAND_WAZA_FrustrationOnWazaPower, HAND_WAZA_WakeUpSlapOnWazaPower, HAND_WAZA_WakeUpSlapOnDamageEnd, HAND_WAZA_SmellingSaltOnWazaPower, HAND_WAZA_SmellingSaltOnDamageEnd, HAND_WAZA_PresentOnVariantDecide, HAND_WAZA_PresentOnHealEffect, HAND_WAZA_PresentOnWazaPower, HAND_WAZA_AddTrumpCard, HAND_WAZA_TrumpCardOnWazaPower, HAND_WAZA_AddPunishment, HAND_WAZA_PunishmentOnWazaPower, HAND_WAZA_FuryCutterOnWazaPower, HAND_WAZA_AssuranceOnWazaPower
 * address:  0x021E2ACC
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
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   gWakeUpSlapHandlers     0x021F29F8  data  ov093  a4
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTLV_CORE_EventScaleDamage  0x021E8860  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gSmellingSaltHandlers     0x021F2A08  data  ov093  a4
 *   gPresentHandlers     0x021F2CC0  data  a4
 *   BTL_CALC_RollPercent  0x021D7AF0  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_POKEPARAM_FindMoveSlot  0x021D5778  thumb  ov093
 *   BTL_POKEPARAM_GetMovePPChecked  0x021D5584  thumb  ov093
 *   gTrumpCardPowerByPp     0x021F2860  data  ov093  a4
 *   gPunishmentHandlers     0x021F24BC  data  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   gPunishmentStatIds     0x021F2D3C  data  ov093  a4
 *   gFuryCutterHandlers     0x021F24C4  data  ov093  a4
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   BTL_POKEPARAM_GetMoveStreak  0x021D679C  thumb  ov093
 *   gAssuranceHandlers     0x021F25AC  data  ov093  a4
 *   BTL_POKEPARAM_TestTurnFlag  0x021D5BB0  thumb  ov093
 *   gLowKickHandlers     0x021F24CC  data  ov093  a4
 *   gTrumpCardHandlers     0x021F272C  data   ov093  a4
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern void *BTL_POKEPARAM_GetMon(struct BtlPokeParam *poke);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 valueId, u32 arg);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);
extern u32 BTL_POKEPARAM_HasSubstitute(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *poke, int sickKind);
extern void BTLV_CORE_EventScaleDamage(int ratio);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlSvFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlSvFlow *flow, void *cmd);
extern int BTL_CALC_RollPercent(u32 percent);
extern void BTL_SERVER_FLOW_SetCurTurnStateFlag(struct BtlSvFlow *flow, int variant);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *poke);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *poke, u32 divisor);
extern void BTL_SERVER_FLOW_InitMsgRecord(HandExStr *str, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(HandExStr *str, u32 arg);
extern u32 BTL_CALC_Random(u32 range);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct BtlPokeParam *poke, u16 moveId);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct BtlPokeParam *poke, u32 moveSlot);
extern int func_021D59B4(struct BtlPokeParam *poke, int valueId);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct BtlPokeParam *poke);
extern u16 BTL_POKEPARAM_GetMoveStreak(struct BtlPokeParam *poke);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *poke, u32 turnFlag);

void HAND_WAZA_FrustrationOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddWakeUpSlap(int *handlerCount);
void HAND_WAZA_WakeUpSlapOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_WakeUpSlapOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddSmellingSalt(int *handlerCount);
void HAND_WAZA_SmellingSaltOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_SmellingSaltOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddPresent(int *handlerCount);
void HAND_WAZA_PresentOnVariantDecide(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_PresentOnHealEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
void HAND_WAZA_PresentOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddTrumpCard(int *handlerCount);
void HAND_WAZA_TrumpCardOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddPunishment(int *handlerCount);
void HAND_WAZA_PunishmentOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddFuryCutter(int *handlerCount);
void HAND_WAZA_FuryCutterOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddAssurance(int *handlerCount);
void HAND_WAZA_AssuranceOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
BtlEventHandler *HAND_WAZA_AddLowKick(int *handlerCount);

extern BtlEventHandler gWakeUpSlapHandlers[];
extern BtlEventHandler gSmellingSaltHandlers[];
extern BtlEventHandler gPresentHandlers[];
extern u16 gTrumpCardPowerByPp[]; /* Trump Card power by remaining PP of the move (0 to 4) */
extern BtlEventHandler gPunishmentHandlers[];
extern u32 gPunishmentStatIds[]; /* the seven stat ids whose raised stages count for Punishment */
extern BtlEventHandler gFuryCutterHandlers[];
extern BtlEventHandler gAssuranceHandlers[];
extern BtlEventHandler gLowKickHandlers[];
extern BtlEventHandler gTrumpCardHandlers[];

/* Frustration: power is the user's unhappiness, 255 minus friendship, times 10 over 25. */
void HAND_WAZA_FrustrationOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u32 power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = (u32)((0xff - POKE_TOOL_GetPartyValue(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId)), 9, 0)) * 10) / 25;
        if (power == 0)
            power = 1;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Wake-Up Slap. */
BtlEventHandler *HAND_WAZA_AddWakeUpSlap(int *handlerCount)
{
    *handlerCount = 2;
    return gWakeUpSlapHandlers;
}

/* Wake-Up Slap: double power against a sleeping target without a substitute. */
void HAND_WAZA_WakeUpSlapOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *target;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        if (BTL_POKEPARAM_HasSubstitute(target) == 0) {
            if (BTL_POKEPARAM_HasSick(target, BTL_SICK_SLEEP) != 0)
                BTLV_CORE_EventScaleDamage(2);
        }
    }
}

/* Wake-Up Slap: wake the target after the hit. */
void HAND_WAZA_WakeUpSlapOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    HandExCureSick *cure;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_SICK_SLEEP) != 0) {
            cure = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
            cure->pokeIds[0] = targetId;
            cure->pokeCount = 1;
            cure->sickKind = BTL_SICK_SLEEP;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cure);
        }
    }
}

/* Smelling Salt. */
BtlEventHandler *HAND_WAZA_AddSmellingSalt(int *handlerCount)
{
    *handlerCount = 2;
    return gSmellingSaltHandlers;
}

/* Smelling Salt: double power against a paralyzed target without a substitute. */
void HAND_WAZA_SmellingSaltOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *target;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        if (BTL_POKEPARAM_HasSubstitute(target) == 0) {
            if (BTL_POKEPARAM_HasSick(target, BTL_SICK_PARALYSIS) != 0)
                BTLV_CORE_EventScaleDamage(2);
        }
    }
}

/* Smelling Salt: cure the target's paralysis after the hit. */
void HAND_WAZA_SmellingSaltOnDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    HandExCureSick *cure;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DAMAGED_ID);
        if (targetId != BTL_EVENT_NO_POKE) {
            if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BTL_SICK_PARALYSIS) != 0) {
                cure = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, pokeId);
                cure->pokeIds[0] = targetId;
                cure->pokeCount = 1;
                cure->sickKind = BTL_SICK_PARALYSIS;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cure);
            }
        }
    }
}

/* Present. */
BtlEventHandler *HAND_WAZA_AddPresent(int *handlerCount)
{
    *handlerCount = 3;
    return gPresentHandlers;
}

/* Present: a one in five chance that the move heals instead of damaging. */
void HAND_WAZA_PresentOnVariantDecide(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_CALC_RollPercent(0x14) != 0)
            *work = BTL_EVENT_OverwriteVar(BTL_EVAR_HANDLED_FLAG, 1);
        BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, (u8)(*work != 0));
    }
}

/* Present: heal a quarter of the target's HP, or show the failure message at full HP. */
void HAND_WAZA_PresentOnHealEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    u8 targetId;
    HandExRecoverHp *heal;
    HandExMessage *message;
    struct BtlPokeParam *target;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *work != 0) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        target = BTL_SERVER_FLOW_GetPokeParam(flow, targetId);
        if (BTL_POKEPARAM_IsHpFull(target) == 0) {
            heal = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, pokeId);
            heal->pokeId = targetId;
            heal->amount = BTL_CALC_DivideMaxHpMin1(target, 4);
            BTL_SERVER_FLOW_InitMsgRecord(&heal->str, HANDEX_STR_SET, 0x183);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&heal->str, targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, heal);
        } else {
            message = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(&message->str, HANDEX_STR_SET, 0xd2);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&message->str, targetId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, message);
        }
    }
}

/* Present: random power, 40 on the low rolls, 120 on the high rolls, 80 otherwise. */
void HAND_WAZA_PresentOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    int power;
    u32 roll;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        power = 0x50;
        roll = BTL_CALC_Random(0x50);
        if (roll < 0x28)
            power = 0x28;
        else if (roll >= 0x46)
            power = 0x78;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Trump Card. */
BtlEventHandler *HAND_WAZA_AddTrumpCard(int *handlerCount)
{
    *handlerCount = 1;
    return gTrumpCardHandlers;
}

/* Trump Card: power from the PP left in the move. */
void HAND_WAZA_TrumpCardOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *user;
    u32 pp;
    int slot;
    int power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        slot = BTL_POKEPARAM_FindMoveSlot(user, BTL_EVENT_GetFactorKey(factor));
        if (slot != BTL_MOVE_SLOT_NONE) {
            pp = (u8)(int)BTL_POKEPARAM_GetMovePPChecked(user, (int)slot);
            if (pp >= 5)
                pp = 4;
            power = gTrumpCardPowerByPp[pp];
        } else {
            power = 0x28;
        }
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Punishment. */
BtlEventHandler *HAND_WAZA_AddPunishment(int *handlerCount)
{
    *handlerCount = 1;
    return gPunishmentHandlers;
}

/* Punishment: 60 power plus 20 for every raised stat stage of the target, up to 200. */
void HAND_WAZA_PunishmentOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *target;
    u32 i;
    int rank;
    int raisedStages;
    u32 power;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        target = BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID));
        raisedStages = 0;
        for (i = 0; i < 7; i++) {
            rank = func_021D59B4(target, gPunishmentStatIds[i]);
            if (rank > 6)
                raisedStages += rank - 6;
        }
        power = raisedStages * 20 + 0x3c;
        if (power > PUNISHMENT_MAX_POWER)
            power = PUNISHMENT_MAX_POWER;
        BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
    }
}

/* Fury Cutter. */
BtlEventHandler *HAND_WAZA_AddFuryCutter(int *handlerCount)
{
    *handlerCount = 1;
    return gFuryCutterHandlers;
}

/* Fury Cutter: the power doubles with every consecutive use, up to 160. */
void HAND_WAZA_FuryCutterOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    struct BtlPokeParam *user;
    u32 power;
    u32 streak;
    u32 i;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        user = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        if (BTL_POKEPARAM_GetLastUsedMoveId(user) == BTL_EVENT_GetFactorKey(factor)) {
            power = BTL_EVENT_GetVar(BTL_EVAR_WAZA_POWER);
            streak = BTL_POKEPARAM_GetMoveStreak(user);
            for (i = 0; i < streak; i++) {
                power <<= 1;
                if (power > FURY_CUTTER_MAX_POWER) {
                    power = FURY_CUTTER_MAX_POWER;
                    break;
                }
            }
            BTL_EVENT_OverwriteVar(BTL_EVAR_WAZA_POWER, power);
        }
    }
}

/* Assurance. */
BtlEventHandler *HAND_WAZA_AddAssurance(int *handlerCount)
{
    *handlerCount = 1;
    return gAssuranceHandlers;
}

/* Assurance: double power when the target already took damage this turn. */
void HAND_WAZA_AssuranceOnWazaPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_TestTurnFlag(BTL_SERVER_FLOW_GetPokeParam(flow, (u8)BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)), BTL_TURN_FLAG_DAMAGED) != 0)
            BTLV_CORE_EventScaleDamage(2);
    }
}

/* Low Kick and Grass Knot. */
BtlEventHandler *HAND_WAZA_AddLowKick(int *handlerCount)
{
    *handlerCount = 1;
    return gLowKickHandlers;
}
