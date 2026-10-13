/*
 * file:     hand_tokusei_021dc57c.c
 * unit:     yes
 * function: HAND_TOKUSEI_Regenerator_RecoverOnSwitchOut, HAND_TOKUSEI_GetRegeneratorHandlers, HAND_TOKUSEI_GetIndirectGuardCause2Handlers, HAND_TOKUSEI_IndirectGuardCause2_Block, HAND_TOKUSEI_IndirectGuardCause2_ShowMessage, HAND_TOKUSEI_GetSandRushHandlers, HAND_TOKUSEI_SandRush_DoubleSpeedInSand, HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy, HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast
 * address:  0x021DC57C
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
 *   func_0689C8CC  0x0689C8CC  thumb  ov095
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_IsFainted   0x021D5B68  thumb ov093
 *   BTL_POKEPARAM_IsHpFull   0x021D5B48  thumb ov093
 *   BTL_CALC_DivideMaxHpMin1   0x021D7B74  thumb ov093
 *   func_021D59B4   0x021D59B4  thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord   0x021C88A4  thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord   0x021C88C8  thumb ov093
 *   HAND_TOKUSEI_BlockIndirectDamage   0x021D928C  thumb
 *   HAND_TOKUSEI_ShowIndirectGuardMessage   0x021D92CC  thumb
 *   gRegeneratorHandlers     0x021F0700  data   ov093  a4
 *   gIndirectGuardCause2Handlers     0x021F0940  data   ov093  a4
 *   gWonderSkinHandlers 0x021F06D0 data a4
 *   BTL_SERVER_FLOW_GetEffectiveWeatherThunk 0x021C8288 thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   gAnalyticHandlers 0x021F0628 data a4
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   func_021E8624 0x021E8624 thumb ov093
 *   gSandRushHandlers     0x021F0950  data   ov093  a4
 */
#include "hand_tokusei_021dbaf0_types.h"

extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_IsHpFull(struct BtlPokeParam *bpp);
extern int BTL_CALC_DivideMaxHpMin1(struct BtlPokeParam *bpp, u32 divisor);
extern int func_021D59B4(struct BtlPokeParam *bpp, int valueId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *cmd);
extern int BTL_SERVER_FLOW_GetEffectiveWeatherThunk(struct BtlServerFlow *flow);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern int BTL_EVENT_OverwriteVar(int key, unsigned int value);
extern int func_0689C8CC(u16 moveId);
extern int func_021E8624(struct BtlServerFlow *flow, int pokeId);
/* The indirect damage guard pair shared with the other guards (cause, then message). */
extern void HAND_TOKUSEI_BlockIndirectDamage(struct BtlServerFlow *flow, int pokeId, int *work, int blockedCause);
extern void HAND_TOKUSEI_ShowIndirectGuardMessage(struct BtlServerFlow *flow, int pokeId, int *work, int stringId);
void HAND_TOKUSEI_Regenerator_RecoverOnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetRegeneratorHandlers(int *handlerCount);
int *HAND_TOKUSEI_GetIndirectGuardCause2Handlers(int *handlerCount);
void HAND_TOKUSEI_IndirectGuardCause2_Block(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
void HAND_TOKUSEI_IndirectGuardCause2_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
int *HAND_TOKUSEI_GetSandRushHandlers(int *handlerCount);
void HAND_TOKUSEI_SandRush_DoubleSpeedInSand(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *HAND_TOKUSEI_GetWonderSkinHandlers(int *handlerCount);
void HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *HAND_TOKUSEI_GetAnalyticHandlers(int *handlerCount);
void HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
extern int gRegeneratorHandlers[];
extern int gIndirectGuardCause2Handlers[];
extern unsigned char gWonderSkinHandlers[];
extern unsigned char gAnalyticHandlers[];
extern int gSandRushHandlers[];

/*
 * Regenerator: when the owner leaves the field, it recovers a third of its
 * hit points (at most what it lacks). Two live calls with no free saved
 * register put the first result on the stack.
 */
void HAND_TOKUSEI_Regenerator_RecoverOnSwitchOut(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    struct BtlPokeParam *owner;
    u32 recoverAmount, missingHp;
    BtlRegenerateHpCmd *cmd;

    if (ownerId != BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        return;
    owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
    if (BTL_POKEPARAM_IsFainted(owner) != 0)
        return;
    if (BTL_POKEPARAM_IsHpFull(owner) != 0)
        return;
    recoverAmount = BTL_CALC_DivideMaxHpMin1(owner, 3);
    missingHp = func_021D59B4(owner, BTL_POKEPARAM_VALUE_MAX_HP) - func_021D59B4(owner, BTL_POKEPARAM_VALUE_HP);
    if (recoverAmount > missingHp)
        recoverAmount = missingHp;
    cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_REGENERATE_HP, ownerId);
    cmd->pokeId = ownerId;
    cmd->amount = recoverAmount;
    cmd->mode = 1;
    cmd->showBar = 1;
    BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
}

int *HAND_TOKUSEI_GetRegeneratorHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gRegeneratorHandlers;
}

int *HAND_TOKUSEI_GetIndirectGuardCause2Handlers(int *handlerCount)
{
    *handlerCount = 2;
    return gIndirectGuardCause2Handlers;
}

/* Indirect damage guard of cause 2: blocks the damage (same family as cause 1, 6 and 8). */
void HAND_TOKUSEI_IndirectGuardCause2_Block(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    HAND_TOKUSEI_BlockIndirectDamage(flow, ownerId, work, 0x2);
}

/* Indirect damage guard of cause 2: shows its message. */
void HAND_TOKUSEI_IndirectGuardCause2_ShowMessage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    HAND_TOKUSEI_ShowIndirectGuardMessage(flow, ownerId, work, 0xcc);
}

int *HAND_TOKUSEI_GetSandRushHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gSandRushHandlers;
}

/* Sand Rush: in a sandstorm the speed of the owner doubles. */
void HAND_TOKUSEI_SandRush_DoubleSpeedInSand(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_SERVER_FLOW_GetEffectiveWeatherThunk(flow) == BTL_WEATHER_SAND)
        BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
}

void *HAND_TOKUSEI_GetWonderSkinHandlers(int *handlerCount) { *handlerCount = 1; return gWonderSkinHandlers; }

/* Wonder Skin: the accuracy of a status move against the owner is at most 50. */
void HAND_TOKUSEI_WonderSkin_CapStatusMoveAccuracy(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE_TYPE) == BTL_DAMAGE_TYPE_STATUS
        && (unsigned int)BTL_EVENT_GetVar(BTL_EVAR_ACCURACY) > 50)
        BTL_EVENT_OverwriteVar(BTL_EVAR_ACCURACY, 50);
}

void *HAND_TOKUSEI_GetAnalyticHandlers(int *handlerCount) { *handlerCount = 1; return gAnalyticHandlers; }

/* Analytic: when every other Pokemon has already moved, the power of the owner is 1.3 times. */
void HAND_TOKUSEI_Analytic_BoostPowerWhenMovingLast(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && func_0689C8CC(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 0
        && func_021E8624(flow, ownerId) != 0)
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
}
