/*
 * file:     unit_021DC32C.c
 * unit:     yes
 * function: func_021DC32C, func_021DC4A4, func_021DC4D4, func_021DC564
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
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F0658 0x021F0658 data a4
 *   d_021F05F8 0x021F05F8 data a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021D85C0  0x021D85C0  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D84F0 0x021D84F0 thumb ov093
 *   d_021F0600 0x021F0600 data a4
 */
#include "unit_021DBAF0_types.h"

extern int func_021D775C(int key);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern u8 *func_021C8120(struct BtlServerFlow *flow, int size);
extern int func_021D5D14(struct BtlPokeParam *bpp, int statId, int direction);
extern u32 func_021D78AC(u32 range);
extern void func_021C88B4(struct BtlServerFlow *flow, int popupState, int pokeId);
extern void *func_021C88A4(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void func_021C88C8(struct BtlServerFlow *flow, void *cmd);
extern int func_021D76BC(int key, unsigned int value);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);
extern int func_021D85C0(struct BtlServerFlow *flow, u32 percent);
extern u32 func_021D7D18(int sickId);
extern void func_021C8838(BtlStrParam *strParam, int strType, int strId);
extern void func_021C8860(BtlStrParam *strParam, u32 arg);
extern unsigned int func_021D84F0(unsigned int priority, unsigned int handlerCount);
void func_021DC32C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId);
void *func_021DC498(int *handlerCount);
void func_021DC4A4(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *func_021DC4C8(int *handlerCount);
void func_021DC4D4(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void *func_021DC564(unsigned int *packedInfo);
extern u8 d_021F0658[];
extern unsigned char d_021F05F8[];
extern unsigned char d_021F0600[];

/*
 * Moody: at the end of the turn one stat of the owner rises by two stages and another falls by one.
 * The pointer-sum form of the random pick preserves the load sequence of the candidate lists.
 * Signed byte storage of -1 preserves the subtraction from the live one.
 */
void func_021DC32C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId)
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
    if (ownerId == func_021D775C(BTL_EVAR_POKE_ID)) {
        scratch = (TokuseiMoodyScratch *)func_021C8120(flow, sizeof(TokuseiMoodyScratch));
        owner = func_021C7CF4(flow, ownerId);
        lowerableCount = 0;
        raisableCount = 0;
        for (i = 0; i < BTL_STAT_COUNT_RANKED; i++) {
            if (func_021D5D14(owner, i + 1, 1)) scratch->raisableStats[raisableCount++] = i + 1;
            if (func_021D5D14(owner, i + 1, -1)) scratch->lowerableStats[lowerableCount++] = i + 1;
        }
        lowerStat = 0;
        raiseStat = 0;
        if (raisableCount == 0 && lowerableCount != 0) {
            lowerStat = (scratch->lowerableStats + func_021D78AC(lowerableCount))[0];
        } else if (raisableCount != 0 && lowerableCount == 0) {
            raiseStat = (scratch->raisableStats + func_021D78AC(raisableCount))[0];
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
            pair = scratch->pairs[func_021D78AC(pairCount)];
            raiseStat = pair >> 8;
            lowerStat = pair;
        }
        func_021C88B4(flow, BTL_ABILITY_POPUP_OPEN, ownerId);
        if (raiseStat) {
            cmd = (BtlRankCmd *)func_021C88A4(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = raiseStat;
            cmd->amount = 2;
            func_021C88C8(flow, cmd);
        }
        if (lowerStat) {
            cmd = (BtlRankCmd *)func_021C88A4(flow, BTL_CMD_KIND_RANK_EFFECT, ownerId);
            cmd->targetCount = 1;
            cmd->targets[0] = ownerId;
            cmd->statId = lowerStat;
            cmd->amount = -1;
            func_021C88C8(flow, cmd);
        }
        func_021C88B4(flow, BTL_ABILITY_POPUP_CLOSE, ownerId);
    }
}

void *func_021DC498(int *handlerCount) { *handlerCount = 1; return d_021F0658; }

/* Overcoat: weather damage to the owner is prevented. */
void func_021DC4A4(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    if (ownerId == func_021D775C(BTL_EVAR_POKE_ID) && func_021D775C(BTL_EVAR_DAMAGE) > 0)
        func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1);
}

void *func_021DC4C8(int *handlerCount) { *handlerCount = 1; return d_021F05F8; }

/* Poison Touch: a contact move of the owner sometimes poisons the defender. */
void func_021DC4D4(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    BtlAddSickCmd *cmd;
    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID)
        && func_021D775C(BTL_EVAR_SUBSTITUTE_FLAG) == 0
        && func_021D775C(BTL_EVAR_EFFECT_BLOCKED_FLAG) == 0
        && WAZA_TOOL_GetFlag(func_021D775C(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_CONTACT) != 0
        && func_021D85C0(flow, 30) != 0) {
        cmd = func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, ownerId);
        cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
        cmd->targetId = func_021D775C(BTL_EVAR_DEFENDER_ID);
        cmd->sickId = BTL_SICK_POISON;
        cmd->sickCont.raw = func_021D7D18(BTL_SICK_POISON);
        func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_POISON_TOUCH);
        func_021C8860(&cmd->strParam, cmd->targetId);
        func_021C88C8(flow, cmd);
    }
}

void *func_021DC564(unsigned int *packedInfo)
{
    *packedInfo = func_021D84F0(4, 1);
    return d_021F0600;
}
