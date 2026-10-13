/*
 * file:     unit_021DC6EC.c
 * unit:     yes
 * function: BTL_ABILITY_GetSandForceHandlers, BTL_ABILITY_SandForceBoostPower, BTL_ABILITY_ZenModeUpdateForm, BTL_ABILITY_ZenModeRevertForm, BTL_ABILITY_GetZenModeHandlers, BTL_ABILITY_InfiltratorSkipSideCondition, BTL_ABILITY_InfiltratorEnableSkip, BTL_ABILITY_InfiltratorDisableSkip, BTL_ABILITY_GetInfiltratorHandlers, BTL_ABILITY_GetMoxieHandlers, BTL_ABILITY_MoxieRaiseAttackOnKnockOut, BTL_ABILITY_GetJustifiedHandlers, BTL_ABILITY_JustifiedRaiseAttackOnDarkHit, BTL_ABILITY_GetRattledHandlers
 * address:  0x021DC6EC
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
 *   gSandForceHandlers 0x021F0990 data a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHp  0x021D7B60  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorPokeId 0x021D70AC thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   BTL_EVENT_ClearFactorSkipCheck   0x021D7324  thumb
 *   gZenModeHandlers     0x021F0B48  data   ov093  a4
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   gInfiltratorHandlers     0x021F0A00  data   ov093  a4
 *   gMoxieHandlers     0x021F0770  data   ov093  a4
 *   gJustifiedHandlers     0x021F05D0  data   ov093  a4
 *   gRattledHandlers     0x021F05B0  data   ov093  a4
 */
#include "unit_021DC6EC_types.h"

extern BtlEventHandler gSandForceHandlers[];
extern BtlEventHandler gZenModeHandlers[];
extern BtlEventHandler gInfiltratorHandlers[];
extern BtlEventHandler gMoxieHandlers[];
extern BtlEventHandler gJustifiedHandlers[];
extern BtlEventHandler gRattledHandlers[];

BtlEventHandler *BTL_ABILITY_GetSandForceHandlers(u32 *handlerCount);
void BTL_ABILITY_SandForceBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void BTL_ABILITY_ZenModeUpdateForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void BTL_ABILITY_ZenModeRevertForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *BTL_ABILITY_GetZenModeHandlers(u32 *handlerCount);
int BTL_ABILITY_InfiltratorSkipSideCondition(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId);
void BTL_ABILITY_InfiltratorEnableSkip(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void BTL_ABILITY_InfiltratorDisableSkip(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *BTL_ABILITY_GetInfiltratorHandlers(u32 *handlerCount);
BtlEventHandler *BTL_ABILITY_GetMoxieHandlers(u32 *handlerCount);
void BTL_ABILITY_MoxieRaiseAttackOnKnockOut(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *BTL_ABILITY_GetJustifiedHandlers(u32 *handlerCount);
void BTL_ABILITY_JustifiedRaiseAttackOnDarkHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *BTL_ABILITY_GetRattledHandlers(u32 *handlerCount);

BtlEventHandler *BTL_ABILITY_GetSandForceHandlers(u32 *handlerCount) { *handlerCount = 2; return gSandForceHandlers; }

/* Sand Force: while the owner attacks in a sandstorm, Ground, Rock and Steel moves get 1.3 times power. */
void BTL_ABILITY_SandForceBoostPower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    u8 moveType;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && func_021C8288(flow) == BTL_WEATHER_SAND) {
        moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_GROUND || moveType == POKETYPE_ROCK || moveType == POKETYPE_STEEL)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_RATIO_1_3);
    }
}

/* Zen Mode: a Darmanitan at half HP or less takes the Zen form; above half it takes the base form. */
void BTL_ABILITY_ZenModeUpdateForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    struct BtlPokeParam *bpp;
    u8 wantZenForm;
    BtlFormChangeCmd *cmd;

    bpp = func_021C7CF4(flow, ownerId);
    if (BTL_POKEPARAM_GetSpecies(bpp) == SPECIES_DARMANITAN) {
        wantZenForm = (func_021D59B4(bpp, BTL_BPP_VALUE_HP) <= BTL_CALC_DivideMaxHp(bpp, 2));
        if (wantZenForm != func_021D59B4(bpp, BTL_BPP_VALUE_FORM)) {
            cmd = func_021C88A4(flow, BTL_CMD_KIND_FORM_CHANGE, ownerId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->pokeId = ownerId;
            cmd->form = wantZenForm;
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_ABILITY_LINE, (u16)(wantZenForm == 1 ? BTL_STR_ZEN_MODE_ON : BTL_STR_ZEN_MODE_OFF));
            func_021C88C8(flow, cmd);
        }
    }
}

/* Zen Mode: when the Darmanitan leaves or loses the ability, it returns to the base form. */
void BTL_ABILITY_ZenModeRevertForm(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlFormChangeCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_POKEPARAM_GetSpecies(func_021C7CF4(flow, ownerId)) == SPECIES_DARMANITAN) {
            cmd = func_021C88A4(flow, BTL_CMD_KIND_FORM_CHANGE, ownerId);
            cmd->pokeId = ownerId;
            cmd->form = 0;
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_ABILITY_LINE, BTL_STR_ZEN_MODE_OFF);
            func_021C8860(&cmd->strParam, ownerId);
            func_021C88C8(flow, cmd);
        }
    }
}

BtlEventHandler *BTL_ABILITY_GetZenModeHandlers(u32 *handlerCount)
{
    *handlerCount = 3;
    return gZenModeHandlers;
}

/*
 * Infiltrator skip check: skips the screen-type side conditions that belong to
 * the other side than the Infiltrator's owner.
 */
int BTL_ABILITY_InfiltratorSkipSideCondition(struct BtlEventFactor *factor, void *context, int targetFactorType, int eventId, u16 targetKey, u8 targetOwnerId)
{
    u8 ownSide;

    if (targetFactorType == BTL_EVENT_TYPE_SIDE_CONDITION) {
        ownSide = func_021B9A40(BTL_EVENT_GetFactorPokeId(factor));
        if (ownSide != targetOwnerId && targetKey <= BTL_SIDE_CONDITION_SCREEN_KEY_MAX)
            return 1;
    }
    return 0;
}

/* Infiltrator: while the owner attacks, install the skip check on its factor. */
void BTL_ABILITY_InfiltratorEnableSkip(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_SetFactorSkipCheck(factor, BTL_ABILITY_InfiltratorSkipSideCondition);
}

/* Infiltrator: when the owner's attack ends, remove the skip check again. */
void BTL_ABILITY_InfiltratorDisableSkip(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}

BtlEventHandler *BTL_ABILITY_GetInfiltratorHandlers(u32 *handlerCount)
{
    *handlerCount = 2;
    return gInfiltratorHandlers;
}

BtlEventHandler *BTL_ABILITY_GetMoxieHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gMoxieHandlers;
}

/* Moxie: the owner raises its Attack by one rank for each defender it knocked out. */
void BTL_ABILITY_MoxieRaiseAttackOnKnockOut(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    u32 defenderCount;
    u32 i;
    BtlRankCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        defenderCount = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_COUNT);
        for (i = 0; i < defenderCount; i++) {
            if (BTL_POKEPARAM_IsFainted(func_021C7CF4(flow, (u8)BTL_EVENT_GetVar(i + BTL_EVAR_DEFENDER_FIRST))) != 0) {
                cmd = func_021C88A4(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
                cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->targetCount = 1;
                cmd->targets[0] = ownerId;
                cmd->statId = BTL_RANK_STAT_ATTACK;
                cmd->amount = 1;
                func_021C88C8(flow, cmd);
            }
        }
    }
}

BtlEventHandler *BTL_ABILITY_GetJustifiedHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gJustifiedHandlers;
}

/* Justified: when a Dark move hits the owner, it raises its Attack by one rank. */
void BTL_ABILITY_JustifiedRaiseAttackOnDarkHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlRankCmd *cmd;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0 && BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE) == POKETYPE_DARK) {
        cmd = func_021C88A4(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
        cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->targetCount = 1;
        cmd->targets[0] = ownerId;
        cmd->statId = BTL_RANK_STAT_ATTACK;
        cmd->amount = 1;
        func_021C88C8(flow, cmd);
    }
}

BtlEventHandler *BTL_ABILITY_GetRattledHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gRattledHandlers;
}
