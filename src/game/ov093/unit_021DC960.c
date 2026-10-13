/*
 * file:     unit_021DC960.c
 * unit:     yes
 * function: BTL_ABILITY_RattledRaiseSpeedOnHit, BTL_ABILITY_GetMummyHandlers, BTL_ABILITY_MummySpreadAbility, BTL_ABILITY_SapSipperAbsorbGrass, BTL_ABILITY_GetSapSipperHandlers
 * address:  0x021DC960
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   gSapSipperHandlers 0x021F05C8 data a4
 *   BTL_ABILITY_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   BTL_ABILITY_AbsorbRaiseStat 0x021DA96C thumb ov093
 *   gMummyHandlers     0x021F0678  data   ov093  a4
 */
#include "unit_021DC6EC_types.h"

extern BtlEventHandler gSapSipperHandlers[];
extern BtlEventHandler gMummyHandlers[];

void BTL_ABILITY_RattledRaiseSpeedOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *BTL_ABILITY_GetMummyHandlers(u32 *handlerCount);
void BTL_ABILITY_MummySpreadAbility(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void BTL_ABILITY_SapSipperAbsorbGrass(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *BTL_ABILITY_GetSapSipperHandlers(u32 *handlerCount);

/* Rattled: when a Bug, Ghost or Dark move hits the owner, it raises its Speed by one rank. */
void BTL_ABILITY_RattledRaiseSpeedOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlRankCmd *cmd;
    u8 moveType;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0) {
        moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_DARK || moveType == POKETYPE_BUG || moveType == POKETYPE_GHOST) {
            cmd = func_021C88A4(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = BTL_RANK_STAT_SPEED;
            cmd->amount = 1;
            func_021C88C8(flow, cmd);
        }
    }
}

BtlEventHandler *BTL_ABILITY_GetMummyHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gMummyHandlers;
}

/*
 * Mummy: when a contact move hits the owner, the attacker's ability becomes
 * Mummy, unless it already is Mummy or one side has no Pokemon left.
 */
void BTL_ABILITY_MummySpreadAbility(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlAbilityChangeCmd *cmd;
    u8 attackerId;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE) == 0 && func_021C83D4(flow) == 0
        && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), WAZA_FLAG_CONTACT) != 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (func_021D59B4(func_021C7CF4(flow, attackerId), BTL_BPP_VALUE_ABILITY) != ABILITY_MUMMY) {
            cmd = func_021C88A4(flow, BTL_CMD_KIND_ABILITY_CHANGE, ownerId);
            cmd->abilityId = ABILITY_MUMMY;
            cmd->pokeId = attackerId;
            func_021C8838(&cmd->strParam, BTL_STR_TYPE_WITH_POKE_NAME, BTL_STR_MUMMY_SPREAD);
            func_021C8860(&cmd->strParam, cmd->pokeId);
            if (func_021B9A24(ownerId, attackerId) == 0)
                cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            func_021C88C8(flow, cmd);
        }
    }
}

/* Sap Sipper: a Grass move aimed at the owner is absorbed and raises its Attack by one rank. */
void BTL_ABILITY_SapSipperAbsorbGrass(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    if (BTL_ABILITY_AbsorbCheckMoveType(flow, ownerId, POKETYPE_GRASS))
        BTL_ABILITY_AbsorbRaiseStat(flow, ownerId, BTL_RANK_STAT_ATTACK, 1);
}

BtlEventHandler *BTL_ABILITY_GetSapSipperHandlers(u32 *handlerCount) { *handlerCount = 1; return gSapSipperHandlers; }
