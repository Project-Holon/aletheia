/*
 * file:     hand_waza_021e56e0.c
 * unit:     yes
 * function: HAND_WAZA_WishSetPosEffect, HAND_WAZA_FutureSightArmDelayedAttack, HAND_WAZA_FutureSightShowMessage, HAND_WAZA_ArmDelayedAttack, HAND_WAZA_DoomDesireArmDelayedAttack, HAND_WAZA_DoomDesireShowMessage, HAND_WAZA_GastroAcidSuppressAbility, HAND_WAZA_RolePlayCopyAbility
 * address:  0x021E56E0
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
 *   func_0689C91C  0x0689C91C  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gFutureSightHandlers     0x021F29D8  data   ov093  a4
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_GetRule  0x021C815C  thumb  ov093
 *   BTL_MAIN_GetEnemyLanePos  0x021B8C20  thumb  ov093
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   gDoomDesireHandlers     0x021F29E8  data   ov093  a4
 *   gGastroAcidHandlers     0x021F2674  data   ov093  a4
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 *   gRolePlayHandlers     0x021F24F4  data   ov093  a4
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
#include "hand_waza_021e5620_types.h"

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, unsigned int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *record);
extern void BTL_SERVER_FLOW_InitMsgRecord(struct HandExMessage *message, int kind, int messageId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct HandExMessage *message, u32 arg);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int BTL_SERVER_FLOW_GetRule(struct BtlServerFlow *flow);
extern u8 BTL_MAIN_GetEnemyLanePos(int rule, u32 position, u32 lane);
extern u16 BTL_SERVER_FLOW_GetTurnCount(struct BtlServerFlow *flow);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern union SickCont BTLV_CORE_MakeSlotKind1Empty(void);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int func_021D59B4(struct BtlPokeParam *pokeParam, int valueId);
extern int func_0689C91C(u16 abilityId);
void HAND_WAZA_WishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetFutureSightHandlers(int *handlerCount);
void HAND_WAZA_FutureSightArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_FutureSightShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_ArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int targetPosition);
int *HAND_WAZA_GetDoomDesireHandlers(int *handlerCount);
void HAND_WAZA_DoomDesireArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
void HAND_WAZA_DoomDesireShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetGastroAcidHandlers(int *handlerCount);
void HAND_WAZA_GastroAcidSuppressAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
int *HAND_WAZA_GetRolePlayHandlers(int *handlerCount);
void HAND_WAZA_RolePlayCopyAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId);
extern int gFutureSightHandlers[];
extern int gDoomDesireHandlers[];
extern int gGastroAcidHandlers[];
extern int gRolePlayHandlers[];


/* Wish: arm the Wish position effect for the slot of the user. */
void HAND_WAZA_WishSetPosEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExSetPosEffect *posEffect;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_WISH;
        posEffect->position = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
    }
}


/* Future Sight getter: two handler rows. */
int *HAND_WAZA_GetFutureSightHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gFutureSightHandlers;
}


/* Future Sight: arm the delayed attack on the chosen target position. */
void HAND_WAZA_FutureSightArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetPosition;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetPosition = BTL_EVENT_GetVar(BTL_EVAR_TARGET_POSITION);
        HAND_WAZA_ArmDelayedAttack(factor, flow, pokeId, targetPosition);
    }
}


/* Future Sight: message that the user foresaw an attack. */
void HAND_WAZA_FutureSightShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessageRecord *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x432);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}


/* Shared by Future Sight and Doom Desire: arm the delayed attack two turns ahead, owned by this factor. */
void HAND_WAZA_ArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId, int targetPosition)
{
    struct HandExSetPosEffect *posEffect;
    int userPosition;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID) && BTL_EVENT_OverwriteVar(BTL_EVAR_GENERIC_FLAG, 1) != 0) {
        if (targetPosition == BTL_SLOT_NONE) {
            userPosition = BTL_SERVER_FLOW_GetPokeViewPos(flow, pokeId);
            targetPosition = BTL_MAIN_GetEnemyLanePos(BTL_SERVER_FLOW_GetRule(flow), userPosition, 0);
        }
        posEffect = BTL_SERVER_FLOW_AllocCmdRecord(flow, HAND_WAZA_KIND_SET_POS_EFFECT, pokeId);
        posEffect->effectKind = BTL_POS_EFFECT_DELAYED_ATTACK;
        posEffect->position = targetPosition;
        posEffect->param = BTL_SERVER_FLOW_GetTurnCount(flow) + 2;
        posEffect->factorKey = BTL_EVENT_GetFactorKey(factor);
        posEffect->mode = 2;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, posEffect);
    }
}


/* Doom Desire getter: two handler rows. */
int *HAND_WAZA_GetDoomDesireHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gDoomDesireHandlers;
}


/* Doom Desire: arm the delayed attack on the chosen target position. */
void HAND_WAZA_DoomDesireArmDelayedAttack(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    u8 targetPosition;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetPosition = BTL_EVENT_GetVar(BTL_EVAR_TARGET_POSITION);
        HAND_WAZA_ArmDelayedAttack(factor, flow, pokeId, targetPosition);
    }
}


/* Doom Desire: message that the user chose destiny. */
void HAND_WAZA_DoomDesireShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExMessageRecord *messageRecord;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        messageRecord = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, pokeId);
        BTL_SERVER_FLOW_InitMsgRecord(&messageRecord->message, HANDEX_MESSAGE_SET, 0x435);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&messageRecord->message, pokeId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, messageRecord);
    }
}


/* Gastro Acid getter: one handler row. */
int *HAND_WAZA_GetGastroAcidHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gGastroAcidHandlers;
}


/* Gastro Acid: suppress the ability of the target and announce it. */
void HAND_WAZA_GastroAcidSuppressAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExAddSickAnnounce *addSick;
    u8 targetId;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        addSick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_ADD_SICK, pokeId);
        addSick->pokeId = targetId;
        addSick->sickKind = BTL_SICK_ABILITY_SUPPRESSED;
        addSick->sickCont = BTLV_CORE_MakeSlotKind1Empty();
        BTL_SERVER_FLOW_InitMsgRecord(&addSick->message, HANDEX_MESSAGE_SET, 0x235);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&addSick->message, targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, addSick);
    }
}


/* Role Play getter: one handler row. */
int *HAND_WAZA_GetRolePlayHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRolePlayHandlers;
}


/* Role Play: copy the ability of the target when it can be copied. */
void HAND_WAZA_RolePlayCopyAbility(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int pokeId)
{
    struct HandExChangeAbility *changeAbility;
    u8 targetId;
    int targetAbility;

    if (pokeId == BTL_EVENT_GetVar(HANDVAR_ATTACKER_ID)) {
        targetId = BTL_EVENT_GetVar(BTL_EVAR_TARGET_ID);
        targetAbility = func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, targetId), BPP_VALUE_ABILITY);
        if (func_0689C91C(targetAbility) == 0) {
            changeAbility = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CHANGE_ABILITY, pokeId);
            changeAbility->pokeId = pokeId;
            changeAbility->abilityId = targetAbility;
            BTL_SERVER_FLOW_InitMsgRecord(&changeAbility->message, HANDEX_MESSAGE_SET, 0x26b);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&changeAbility->message, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&changeAbility->message, targetId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&changeAbility->message, changeAbility->abilityId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, changeAbility);
        }
    }
}
