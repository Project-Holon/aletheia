/*
 * file:     unit_021DBAF0.c
 * unit:     yes
 * function: func_021DBAF0, func_021DBB58, func_021DBB64, func_021DBB98, func_021DBBCC, func_021DBBD8, func_021DBCEC, func_021DBD9C
 * address:  0x021DBAF0
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
 *   func_0689C8CC  0x0689C8CC  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gUnburdenHandlers     0x021F0960  data   ov093  a4
 *   func_021C8120 0x021C8120 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_POKEPARAM_GetConsumedItem 0x021D6740 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   gPickpocketHandlers 0x021F06C0 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   BTLV_CORE_CheckEitherSlotPair  0x021E86E8  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_CALC_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   gPickupHandlers     0x021F06C8  data   ov093  a4
 */
#include "unit_021DBAF0_types.h"

/* Services of the event variable stack, the battle server flow and the poke parameter. */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern u32 BTL_CALC_Random(u32 range);
extern int func_021B9A24(unsigned int pokeIdA, unsigned int pokeIdB);
extern int func_021C7D00(struct BtlServerFlow *flow, int pokeId);
extern u8 func_021C7F68(struct BtlServerFlow *flow, int posKey, u8 *out);
extern struct BtlPokeParam *func_021C7CF4(struct BtlServerFlow *flow, int pokeId);
extern u8 *func_021C8120(struct BtlServerFlow *flow, int size);
extern void *func_021C88A4(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void func_021C8838(BtlStrParam *strParam, int strType, int strId);
extern void func_021C8860(BtlStrParam *strParam, u32 arg);
extern void func_021C88C8(struct BtlServerFlow *flow, void *cmd);
extern int func_021C83D4(struct BtlServerFlow *flow);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int typeId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern int BTL_CALC_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);
extern int func_021E85F8(int pokeId);
extern int BTLV_CORE_CheckEitherSlotPair(struct BtlServerFlow *flow, int pokeIdA, int pokeIdB);
extern union BtlSickCont BTLV_CORE_MakeSlotKind2(int index, int value);
extern int func_0689C8CC(u32 moveId);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);

void func_021DBAF0(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *func_021DBB58(int *handlerCount);
void func_021DBB64(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
void func_021DBB98(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
int *func_021DBBCC(int *handlerCount);
void func_021DBBD8(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId);
void *func_021DBCE0(int *handlerCount);
void func_021DBCEC(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void func_021DBD9C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
extern int gUnburdenHandlers[];
extern u8 gPickpocketHandlers[];
extern int gPickupHandlers[];

/* Magnet Pull: a Steel-type Pokemon among the owner's targets cannot escape. */
void func_021DBAF0(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 targetIds[4];
    u32 targetCount;
    u8 i;

    if (func_021B9A24((u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID), ownerId) == 0) {
        targetCount = func_021C7F68(flow, (u16)(func_021C7D00(flow, ownerId) | 0x100), targetIds);
        for (i = 0; i < targetCount; i++) {
            if (BTL_POKEPARAM_HasType(func_021C7CF4(flow, targetIds[i]), POKETYPE_STEEL) != 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
        }
    }
}

int *func_021DBB58(int *handlerCount)
{
    *handlerCount = 2;
    return gUnburdenHandlers;
}

/* Unburden: remember that the owner is about to lose its held item. */
void func_021DBB64(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_SELF_CAUSED_FLAG) == 0
        && BTL_POKEPARAM_GetItem(func_021C7CF4(flow, ownerId)))
        *work = 1;
}

/* Unburden: once the item is gone, the speed of the owner doubles. */
void func_021DBB98(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work == 1) {
        if (BTL_POKEPARAM_GetItem(func_021C7CF4(flow, ownerId)) == 0) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
        }
    }
}

int *func_021DBBCC(int *handlerCount)
{
    *handlerCount = 1;
    return gPickupHandlers;
}

/* Pickup: an owner without an item takes a random item that a Pokemon around it used this turn. */
void func_021DBBD8(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId)
{
    TokuseiPickupScratch *scratch;
    struct BtlPokeParam *candidate;
    BtlSetItemCmd *cmd;
    u32 posKey;
    u8 i;
    u8 holderCount;
    u8 selectedId;
    u16 itemId;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && !BTL_POKEPARAM_GetItem(func_021C7CF4(flow, ownerId))) {
        posKey = func_021C7D00(flow, ownerId);
        scratch = (TokuseiPickupScratch *)func_021C8120(flow, sizeof(TokuseiPickupScratch));
        scratch->candidateCount = func_021C7F68(flow, (u16)(posKey | 0x200), scratch->candidateIds);
        holderCount = 0;
        scratch->spare = 0;
        for (i = 0; i < (u32)scratch->candidateCount; i++) {
            candidate = func_021C7CF4(flow, scratch->candidateIds[i]);
            if (BTL_POKEPARAM_TestTurnFlag(candidate, BTL_TURN_FLAG_ITEM_USED) && BTL_POKEPARAM_GetConsumedItem(candidate)) {
                scratch->holderIds[holderCount++] = BTL_POKEPARAM_GetPokeId(candidate);
            }
        }
        if (holderCount) {
            selectedId = (scratch->candidateIds + (u8)BTL_CALC_Random(holderCount))[6];
            itemId = BTL_POKEPARAM_GetConsumedItem(func_021C7CF4(flow, selectedId));
            if (itemId) {
                cmd = (BtlSetItemCmd *)func_021C88A4(flow, BTL_CMD_KIND_SET_ITEM, ownerId);
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->pokeId = ownerId;
                cmd->itemId = itemId;
                cmd->clearConsumed = 1;
                cmd->sourcePokeId = selectedId;
                func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_PICKUP);
                func_021C8860(&cmd->strParam, ownerId);
                func_021C8860(&cmd->strParam, itemId);
                func_021C88C8(flow, cmd);
            }
        }
    }
}

void *func_021DBCE0(int *handlerCount) { *handlerCount = 1; return gPickpocketHandlers; }

/* Pickpocket: when a contact move hits the owner, the owner takes the item of the attacker. */
void func_021DBCEC(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 attackerId;
    struct BtlPokeParam *owner;
    struct BtlPokeParam *attacker;
    BtlStealItemCmd *cmd;

    if (func_021E85F8(ownerId) != 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (BTLV_CORE_CheckEitherSlotPair(flow, ownerId, attackerId) == 0
            && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_CONTACT) != 0) {
            owner = func_021C7CF4(flow, ownerId);
            attacker = func_021C7CF4(flow, attackerId);
            if (BTL_POKEPARAM_GetItem(owner) == 0 && BTL_POKEPARAM_GetItem(attacker) != 0) {
                cmd = func_021C88A4(flow, BTL_CMD_KIND_STEAL_ITEM, ownerId);
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->victimId = attackerId;
                func_021C8838(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_PICKPOCKET);
                func_021C8860(&cmd->strParam, attackerId);
                func_021C8860(&cmd->strParam, BTL_POKEPARAM_GetItem(attacker));
                func_021C88C8(flow, cmd);
            }
        }
    }
}

/* The number of turns of Disable: 4, or 5 when the target has already acted this turn. */
typedef enum { DISABLE_TURNS_BASE = 4, DISABLE_TURNS_ACTED = 5 } DisableTurns;

/*
 * Cursed Body: sometimes disables the move that hit the owner.
 * note:     BTLV_CORE_MakeSlotKind2 returns a one-word struct: its return temporary is
 *           the unreferenced third frame word and moves turns/moveId to r6/r7
 *           (an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md);
 *           the enum DisableTurns keeps turns + 1 out of constant folding.
 */
void func_021DBD9C(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 attackerId;
    u16 moveId;
    DisableTurns turns;
    struct BtlPokeParam *attacker;
    BtlAddSickCmd *cmd;

    turns = DISABLE_TURNS_BASE;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_SUBSTITUTE_FLAG) == 0
        && func_021C83D4(flow) == 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        attacker = func_021C7CF4(flow, attackerId);
        if (BTL_POKEPARAM_HasSick(attacker, BTL_SICK_DISABLE) == 0) {
            moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID_USED);
            if (moveId != 0 && moveId != BTL_MOVE_STRUGGLE && func_0689C8CC(moveId) == 0
                && BTL_CALC_RollChanceOrFlag(flow, 30) != 0) {
                if (BTL_POKEPARAM_TestTurnFlag(attacker, BTL_TURN_FLAG_ACTED) != 0) {
                    turns = (DisableTurns)(u8)(turns + 1);
                }
                cmd = func_021C88A4(flow, BTL_CMD_KIND_ADD_SICK, ownerId);
                cmd->sickId = BTL_SICK_DISABLE;
                cmd->sickCont = BTLV_CORE_MakeSlotKind2(turns, moveId);
                cmd->targetId = attackerId;
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                func_021C88C8(flow, cmd);
            }
        }
    }
}
