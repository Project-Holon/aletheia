/*
 * file:     hand_tokusei_021dc32c.c
 * unit:     yes
 * function: HAND_TOKUSEI_Moody_RaiseAndLowerStat, HAND_TOKUSEI_Overcoat_BlockWeatherDamage, HAND_TOKUSEI_PoisonTouch_PoisonOnContact, HAND_TOKUSEI_GetPoisonTouchHandlers
 * address:  0x021DC32C
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
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_PushCmdRecord 0x021C88B4 thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gMoodyHandlers 0x021F0658 data a4
 *   gOvercoatHandlers 0x021F05F8 data a4
 *   BTL_EVENT_OverwriteVar 0x021D76BC thumb ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   HAND_TOKUSEI_PackAbilityHandlerInfo 0x021D84F0 thumb ov093
 *   gPoisonTouchHandlers 0x021F0600 data a4
 */
#include "hand_tokusei_021dbaf0_types.h"

extern int BTL_EVENT_GetVar(int key);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlServerFlow *flow, int size);
extern int func_021D5D14(struct BtlPokeParam *bpp, int statId, int direction);
extern u32 BTL_CALC_Random(u32 range);
extern void BTL_SERVER_FLOW_PushCmdRecord(struct BtlServerFlow *flow, int popupState, int pokeId);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *cmd);
extern int BTL_EVENT_OverwriteVar(int key, unsigned int value);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern int HAND_TOKUSEI_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);
extern u32 BTL_CALC_MakeDefaultSickCont(int sickId);
extern void BTL_SERVER_FLOW_InitMsgRecord(BtlStrParam *strParam, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(BtlStrParam *strParam, u32 arg);
extern unsigned int HAND_TOKUSEI_PackAbilityHandlerInfo(unsigned int priority, unsigned int handlerCount);
void HAND_TOKUSEI_Moody_RaiseAndLowerStat(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId);
void *HAND_TOKUSEI_GetMoodyHandlers(int *handlerCount);
void HAND_TOKUSEI_Overcoat_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *HAND_TOKUSEI_GetOvercoatHandlers(int *handlerCount);
void HAND_TOKUSEI_PoisonTouch_PoisonOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *HAND_TOKUSEI_GetPoisonTouchHandlers(unsigned int *packedInfo);
extern u8 gMoodyHandlers[];
extern unsigned char gOvercoatHandlers[];
extern unsigned char gPoisonTouchHandlers[];

/*
 * Moody: at the end of the turn one stat of the owner rises by two stages and another falls by one.
 * The pointer-sum form of the random pick preserves the load sequence of the candidate lists.
 * Signed byte storage of -1 preserves the subtraction from the live one.
 */
void HAND_TOKUSEI_Moody_RaiseAndLowerStat(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId)
{
    TokuseiMoodyScratch *scratch;
    struct BtlPokeParam *owner;
    u8 raisableCount;
    u8 lowerableCount;
    u32 i;
    u8 pairCount;
    u32 j;
    u8 raiseStat;
    u8 lowerStat;
    u16 pair;
    BtlRankCmd *cmd;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        scratch = (TokuseiMoodyScratch *)BTL_SERVER_FLOW_GetScratchBuffer(flow, sizeof(TokuseiMoodyScratch));
        owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
        lowerableCount = 0;
        raisableCount = 0;
        for (i = 0; i < BTL_STAT_COUNT_RANKED; i++) {
            if (func_021D5D14(owner, i + 1, 1)) scratch->raisableStats[raisableCount++] = i + 1;
            if (func_021D5D14(owner, i + 1, -1)) scratch->lowerableStats[lowerableCount++] = i + 1;
        }
        lowerStat = 0;
        raiseStat = 0;
        if (raisableCount == 0 && lowerableCount != 0) {
            lowerStat = (scratch->lowerableStats + BTL_CALC_Random(lowerableCount))[0];
        } else if (raisableCount != 0 && lowerableCount == 0) {
            raiseStat = (scratch->raisableStats + BTL_CALC_Random(raisableCount))[0];
        } else if (raisableCount != 0 && lowerableCount != 0) {
            pairCount = 0;
            for (i = 0; i < raisableCount; i++) {
                for (j = 0; j < lowerableCount; j++) {
                    if (scratch->raisableStats[i] != scratch->lowerableStats[j]) {
                        scratch->pairs[pairCount++] = (scratch->raisableStats[i] << 8) | scratch->lowerableStats[j];
                        if (pairCount >= 0x54) break;
                    }
                }
            }
            pair = scratch->pairs[BTL_CALC_Random(pairCount)];
            raiseStat = pair >> 8;
            lowerStat = pair;
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_OPEN, ownerId);
        if (raiseStat) {
            cmd = (BtlRankCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = raiseStat;
            cmd->amount = 2;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
        if (lowerStat) {
            cmd = (BtlRankCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = lowerStat;
            cmd->amount = -1;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
        BTL_SERVER_FLOW_PushCmdRecord(flow, BTL_ABILITY_POPUP_CLOSE, ownerId);
    }
}

void *HAND_TOKUSEI_GetMoodyHandlers(int *handlerCount) { *handlerCount = 1; return gMoodyHandlers; }

/* Overcoat: weather damage to the owner is prevented. */
void HAND_TOKUSEI_Overcoat_BlockWeatherDamage(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_DAMAGE) > 0)
        BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
}

void *HAND_TOKUSEI_GetOvercoatHandlers(int *handlerCount) { *handlerCount = 1; return gOvercoatHandlers; }

/* Poison Touch: a contact move of the owner sometimes poisons the defender. */
void HAND_TOKUSEI_PoisonTouch_PoisonOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    BtlAddSickCmd *cmd;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0
        && BTL_EVENT_GetVar(BTL_EVAR_EFFECT_BLOCKED_FLAG) == 0
        && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_CONTACT) != 0
        && HAND_TOKUSEI_RollChanceOrFlag(flow, 30) != 0) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, ownerId);
        cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->targetId = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID);
        cmd->sickId = BTL_SICK_POISON;
        cmd->sickCont.raw = BTL_CALC_MakeDefaultSickCont(BTL_SICK_POISON);
        BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_POISON_TOUCH);
        BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, cmd->targetId);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
    }
}

void *HAND_TOKUSEI_GetPoisonTouchHandlers(unsigned int *packedInfo)
{
    *packedInfo = HAND_TOKUSEI_PackAbilityHandlerInfo(4, 1);
    return gPoisonTouchHandlers;
}
