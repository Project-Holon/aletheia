/*
 * file:     hand_waza_021e10d8.c
 * unit:     yes
 * function: HAND_WAZA_TriAttackOnDecideAddSick, HAND_WAZA_AddSecretPower, HAND_WAZA_SecretPowerGetGroundEffect, HAND_WAZA_SecretPowerOnPrepareMove, HAND_WAZA_SecretPowerOnAddEffect
 * address:  0x021E10D8
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
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gTriAttackSickIds     0x021F286C  data   ov093  a4
 *   BTL_SERVER_FLOW_GetFieldSituationType  0x021C8174  thumb  ov093
 *   BTL_SERVER_FLOW_SetCurTurnStateFlag  0x021C83DC  thumb  ov093
 *   gChatterHandlers 0x021F253C data a4
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   BTL_CALC_MakeSickContFromKind 0x021D7DC0 thumb ov093
 *   gSecretPowerHandlers     0x021F2908  data   ov093  a4
 */
#include "hand_waza_021e10d8_types.h"

void HAND_WAZA_TriAttackOnDecideAddSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddSecretPower(int *handlerCount);
u8 HAND_WAZA_SecretPowerGetGroundEffect(struct BtlSvFlow *flow, u8 *effectKind, u8 *effectValue);
void HAND_WAZA_SecretPowerOnPrepareMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
void HAND_WAZA_SecretPowerOnAddEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work);
BtlEventHandler *HAND_WAZA_AddChatter(int *handlerCount);
extern u32 gTriAttackSickIds[];
extern BtlEventHandler gChatterHandlers[];
extern BtlEventHandler gSecretPowerHandlers[];

/*
 * Tri Attack, event DECIDE_ADD_SICK (the handler table is in the previous
 * unit): picks paralysis, burn or freeze at random with a chance of 20 percent.
 */
void HAND_WAZA_TriAttackOnDecideAddSick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    u32 sickId;
    union SickCont sickCont;
    int choiceCount;

    choiceCount = 3;
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        sickId = gTriAttackSickIds[(u8)BTL_CALC_Random(choiceCount)];
        sickCont = BTL_CALC_MakeDefaultSickCont(sickId);
        BTL_EVENT_OverwriteVar(HANDVAR_SICK_ID, sickId);
        BTL_EVENT_OverwriteVar(HANDVAR_SICK_CONT, sickCont.raw);
        BTL_EVENT_OverwriteVar(HANDVAR_ADD_SICK_PERCENT, 20);
    }
}

/* Secret Power: stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddSecretPower(int *handlerCount)
{
    *handlerCount = 2;
    return gSecretPowerHandlers;
}

/*
 * Secret Power: maps the kind of ground the battle is fought on to the extra
 * effect. effectKind: 0 add a status, 1 lower a stat stage, 2 flinch.
 * effectValue: the status id or the stat stage id. Returns the number of the
 * animation that goes with the ground; either out pointer may be 0.
 */
u8 HAND_WAZA_SecretPowerGetGroundEffect(struct BtlSvFlow *flow, u8 *effectKind, u8 *effectValue)
{
    u8 anim;
    u8 kind;
    u8 value;
    int ground;

    ground = BTL_SERVER_FLOW_GetFieldSituationType(flow);
    switch (ground) {
    case 1:
    case 2:
    case 3:
    case 8:
    case 15:
        kind = 1;
        value = BTL_RANK_ACCURACY;
        anim = 1;
        break;
    case 4:
    case 14:
    default:
        kind = 0;
        value = BTL_SICK_PARALYSIS;
        anim = 0;
        break;
    case 10:
        kind = 2;
        value = 0;
        anim = 6;
        break;
    case 0:
    case 5:
        kind = 0;
        value = BTL_SICK_SLEEP;
        anim = 7;
        break;
    case 6:
    case 11:
    case 12:
        kind = 1;
        value = BTL_RANK_ATTACK;
        anim = 5;
        break;
    case 9:
        kind = 1;
        value = BTL_RANK_SPEED;
        anim = 2;
        break;
    case 7:
    case 13:
        kind = 0;
        value = BTL_SICK_FREEZE;
        anim = (ground == 7) ? value : 4;
        break;
    }
    if (effectKind)
        *effectKind = kind;
    if (effectValue)
        *effectValue = value;
    return anim;
}

/* Secret Power, event PREPARE_MOVE: hands the animation of the ground to the flow. */
void HAND_WAZA_SecretPowerOnPrepareMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    if (pokeId == BTL_EVENT_GetVar(HANDVAR_POKE_ID))
        BTL_SERVER_FLOW_SetCurTurnStateFlag(flow, HAND_WAZA_SecretPowerGetGroundEffect(flow, 0, 0));
}

/*
 * Secret Power, event ADD_EFFECT: with a chance of 30 percent adds the extra
 * effect of the ground. Skipped when an ability blocks extra effects.
 */
void HAND_WAZA_SecretPowerOnAddEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, void *work)
{
    struct BtlPokeParam *attacker;
    u8 targetId;
    u8 effectKind;
    u8 effectValue;
    struct HandExAddSick *addSick;
    struct HandExRankChange *rank;
    struct HandExFlinch *flinch;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_EVENT_GetVar(HANDVAR_EFFECT_BLOCKED) == 0 && BTL_CALC_Random(100) < 30) {
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        targetId = BTL_EVENT_GetVar(HANDVAR_EFFECT_TARGET_ID);
        HAND_WAZA_SecretPowerGetGroundEffect(flow, &effectKind, &effectValue);
        switch (effectKind) {
        case 0:
            addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
            addSick->pokeId = targetId;
            addSick->sickKind = effectValue;
            BTL_CALC_MakeSickContFromKind(effectValue, attacker, &addSick->sickCont);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
            break;
        case 1:
            rank = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RANK_EFFECT, pokeId);
            rank->pokeCount = 1;
            rank->pokeId = targetId;
            rank->rankKind = effectValue;
            rank->volume = -1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, rank);
            break;
        case 2:
            flinch = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FLINCH, pokeId);
            flinch->pokeId = targetId;
            flinch->percent = 100;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, flinch);
            break;
        }
    }
}

/* Chatter (its handler is in the next unit): stores the handler count and returns the handler table. */
BtlEventHandler *HAND_WAZA_AddChatter(int *handlerCount)
{
    *handlerCount = 1;
    return gChatterHandlers;
}
