/*
 * file:     hand_tokusei_021dc960.c
 * unit:     yes
 * function: HAND_TOKUSEI_RattledRaiseSpeedOnHit, HAND_TOKUSEI_GetMummyHandlers, HAND_TOKUSEI_MummySpreadAbility, HAND_TOKUSEI_SapSipperAbsorbGrass, HAND_TOKUSEI_GetSapSipperHandlers
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
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   gSapSipperHandlers 0x021F05C8 data a4
 *   HAND_TOKUSEI_AbsorbCheckMoveType 0x021DA8A8 thumb ov093
 *   HAND_TOKUSEI_AbsorbRaiseStat 0x021DA96C thumb ov093
 *   gMummyHandlers     0x021F0678  data   ov093  a4
 */
#include "hand_tokusei_021dc6ec_types.h"

extern BtlEventHandler gSapSipperHandlers[];
extern BtlEventHandler gMummyHandlers[];

void HAND_TOKUSEI_RattledRaiseSpeedOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *HAND_TOKUSEI_GetMummyHandlers(u32 *handlerCount);
void HAND_TOKUSEI_MummySpreadAbility(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void HAND_TOKUSEI_SapSipperAbsorbGrass(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *HAND_TOKUSEI_GetSapSipperHandlers(u32 *handlerCount);

/* Rattled: when a Bug, Ghost or Dark move hits the owner, it raises its Speed by one rank. */
void HAND_TOKUSEI_RattledRaiseSpeedOnHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlRankCmd *cmd;
    u8 moveType;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0) {
        moveType = BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_DARK || moveType == POKETYPE_BUG || moveType == POKETYPE_GHOST) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_CHANGE, ownerId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = BTL_RANK_STAT_SPEED;
            cmd->amount = 1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

BtlEventHandler *HAND_TOKUSEI_GetMummyHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gMummyHandlers;
}

/*
 * Mummy: when a contact move hits the owner, the attacker's ability becomes
 * Mummy, unless it already is Mummy or one side has no Pokemon left.
 */
void HAND_TOKUSEI_MummySpreadAbility(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BtlAbilityChangeCmd *cmd;
    u8 attackerId;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID) && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0 && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0
        && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), WAZA_FLAG_CONTACT) != 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(flow, attackerId), BTL_BPP_VALUE_ABILITY) != ABILITY_MUMMY) {
            cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ABILITY_CHANGE, ownerId);
            cmd->abilityId = ABILITY_MUMMY;
            cmd->pokeId = attackerId;
            BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_WITH_POKE_NAME, BTL_STR_MUMMY_SPREAD);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, cmd->pokeId);
            if (BTL_MAIN_IsPokeSamePair(ownerId, attackerId) == 0)
                cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}

/* Sap Sipper: a Grass move aimed at the owner is absorbed and raises its Attack by one rank. */
void HAND_TOKUSEI_SapSipperAbsorbGrass(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    if (HAND_TOKUSEI_AbsorbCheckMoveType(flow, ownerId, POKETYPE_GRASS))
        HAND_TOKUSEI_AbsorbRaiseStat(flow, ownerId, BTL_RANK_STAT_ATTACK, 1);
}

BtlEventHandler *HAND_TOKUSEI_GetSapSipperHandlers(u32 *handlerCount) { *handlerCount = 1; return gSapSipperHandlers; }
