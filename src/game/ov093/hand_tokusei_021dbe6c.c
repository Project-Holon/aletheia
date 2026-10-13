/*
 * file:     hand_tokusei_021dbe6c.c
 * unit:     yes
 * function: HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed, HAND_TOKUSEI_GetWeakArmorHandlers, HAND_TOKUSEI_SheerForce_BoostPower, HAND_TOKUSEI_SheerForce_BlockAddedEffect, HAND_TOKUSEI_SheerForce_BlockAttackerSideEffect, HAND_TOKUSEI_SheerForce_FlagNoAddedEffect, HAND_TOKUSEI_SheerForce_IsBoostedMove, HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop, HAND_TOKUSEI_GetDefiantHandlers
 * address:  0x021DBE6C
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
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   gSheerForceHandlers 0x021F0D14 data a4
 *   WAZA_TOOL_GetCategory  0x0201C1BC  thumb
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb
 *   WAZA_TOOL_GetRankEffectCount  0x0201C020  thumb
 *   WAZA_TOOL_GetRankEffect  0x0201C0BC  thumb
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   gWeakArmorHandlers     0x021F07D0  data   ov093  a4
 *   gDefiantHandlers     0x021F0688  data   ov093  a4
 */
#include "hand_tokusei_021dbaf0_types.h"

extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int func_021D5D14(struct BtlPokeParam *bpp, int statId, int direction);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *bpp);
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlServerFlow *flow, int popupState, int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *cmd);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern int BTL_EVENT_OverwriteVar(int key, unsigned int value);
extern u32 WAZA_TOOL_GetCategory(u16 moveId);
extern u32 WAZA_TOOL_GetParam(u16 moveId, u32 field);
extern u8 WAZA_TOOL_GetRankEffectCount(u16 moveId);
extern u8 WAZA_TOOL_GetRankEffect(u16 moveId, u32 index, s32 *out);
extern int BTL_MAIN_IsPokeSamePair(u32 pokeIdA, u32 pokeIdB);
void HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId);
int *HAND_TOKUSEI_GetWeakArmorHandlers(int *handlerCount);
void HAND_TOKUSEI_SheerForce_BoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void HAND_TOKUSEI_SheerForce_BlockAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void HAND_TOKUSEI_SheerForce_BlockAttackerSideEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void HAND_TOKUSEI_SheerForce_FlagNoAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetSheerForceHandlers(int *handlerCount);
int HAND_TOKUSEI_SheerForce_IsBoostedMove(u16 moveId);
void HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId);
int *HAND_TOKUSEI_GetDefiantHandlers(int *handlerCount);
extern int gSheerForceHandlers;
extern int gWeakArmorHandlers[];
extern int gDefiantHandlers[];

/* Weak Armor: a physical hit lowers the defense of the owner and raises its speed. */
void HAND_TOKUSEI_WeakArmor_LowerDefenseRaiseSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId)
{
    BtlRankCmd *cmd;
    struct BtlPokeParam *owner;
    int canChange;
    if (ownerId != BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        return;
    }
    if (BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) != BTL_DAMAGE_TYPE_PHYSICAL) {
        return;
    }
    if (BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) != 0) {
        return;
    }
    owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
    canChange = 0;
    if (func_021D5D14(owner, BTL_STAT_DEFENSE, -1) != 0 || func_021D5D14(owner, BTL_STAT_SPEED, 1) != 0) {
        canChange = 1;
    }
    if (canChange == 0) {
        return;
    }
    if (BTL_POKEPARAM_IsFainted(owner) != 0) {
        return;
    }
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, ownerId);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
    cmd->targetCount = 1;
    cmd->targets[0] = ownerId;
    cmd->showMessage = 1;
    cmd->statId = BTL_STAT_DEFENSE;
    cmd->amount = -1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
    cmd->targetCount = 1;
    cmd->targets[0] = ownerId;
    cmd->showMessage = 1;
    cmd->statId = BTL_STAT_SPEED;
    cmd->amount = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, ownerId);
}

int *HAND_TOKUSEI_GetWeakArmorHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gWeakArmorHandlers;
}

/* Sheer Force: moves with an added effect hit 1.3 times harder. */
void HAND_TOKUSEI_SheerForce_BoostPower(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && HAND_TOKUSEI_SheerForce_IsBoostedMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
}

/* Sheer Force: the added effect of such a move does not happen. */
void HAND_TOKUSEI_SheerForce_BlockAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && HAND_TOKUSEI_SheerForce_IsBoostedMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Sheer Force: the side effect that would follow the attack of the owner is prevented. */
void HAND_TOKUSEI_SheerForce_BlockAttackerSideEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

/* Sheer Force: marks such a move as having no added effect. */
void HAND_TOKUSEI_SheerForce_FlagNoAddedEffect(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && HAND_TOKUSEI_SheerForce_IsBoostedMove(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)))
        BTL_EVENT_OverwriteVar(BTL_EVAR_ADDED_EFFECT_OFF_FLAG, 1);
}

int *HAND_TOKUSEI_GetSheerForceHandlers(int *handlerCount) { *handlerCount = 5; return &gSheerForceHandlers; }

/* True when Sheer Force boosts the move: it has an added effect that is not a self stat loss. */
int HAND_TOKUSEI_SheerForce_IsBoostedMove(u16 moveId)
{
    u32 category = WAZA_TOOL_GetCategory(moveId);
    if (WAZA_TOOL_GetParam(moveId, BTL_WAZA_PARAM_ADDED_EFFECT_RATE) != 0) {
        return 1;
    }
    switch (category) {
    case BTL_WAZA_CATEGORY_DAMAGE_PLUS_EFFECT:
        if (WAZA_TOOL_GetParam(moveId, BTL_WAZA_PARAM_ADDED_EFFECT_KIND) == 8) {
            return 0;
        }
    case BTL_WAZA_CATEGORY_DAMAGE_PLUS_SICK:
        return 1;
    case BTL_WAZA_CATEGORY_DAMAGE_PLUS_RANK: {
        u32 effectCount;
        u32 i;
        s32 amount;
        effectCount = WAZA_TOOL_GetRankEffectCount(moveId);
        for (i = 0; i < effectCount; i++) {
            WAZA_TOOL_GetRankEffect(moveId, i, &amount);
            if (amount < 0) {
                return 0;
            }
        }
        return 1;
    }
    default:
        if (moveId == BTL_MOVE_SECRET_POWER) {
            return 1;
        }
        return 0;
    }
}

/* Defiant: when an enemy lowers a stat of the owner, its attack rises by two stages. */
void HAND_TOKUSEI_Defiant_RaiseAttackOnStatDrop(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u32 ownerId)
{
    BtlRankCmd *cmd;
    u8 attackerId;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)
        && (attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID), BTL_MAIN_IsPokeSamePair(ownerId, attackerId)) == 0
        && BTL_EVENT_GetVar(BTL_EVAR_VOLUME) < 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
        cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->statId = BTL_STAT_ATTACK;
        cmd->amount = 2;
        cmd->showMessage = 1;
        cmd->targetCount = 1;
        cmd->targets[0] = ownerId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

int *HAND_TOKUSEI_GetDefiantHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gDefiantHandlers;
}
