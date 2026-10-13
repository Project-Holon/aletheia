/*
 * file:     hand_tokusei_021dbaf0.c
 * unit:     yes
 * function: HAND_TOKUSEI_MagnetPull_BlockSteelEscape, HAND_TOKUSEI_GetUnburdenHandlers, HAND_TOKUSEI_Unburden_MarkItemLost, HAND_TOKUSEI_Unburden_DoubleSpeed, HAND_TOKUSEI_GetPickupHandlers, HAND_TOKUSEI_Pickup_TakeUsedItem, HAND_TOKUSEI_Pickpocket_StealOnContact, HAND_TOKUSEI_CursedBody_DisableAttackerMove
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
 *   func_0689C8CC  0x0689C8CC  thumb  ov095
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   gUnburdenHandlers     0x021F0960  data   ov093  a4
 *   BTL_SERVER_FLOW_GetScratchBuffer 0x021C8120 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_POKEPARAM_GetConsumedItem 0x021D6740 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_InitMsgRecord 0x021C8838 thumb ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg 0x021C8860 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 *   gPickpocketHandlers 0x021F06C0 data a4
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   BTLV_CORE_CheckEitherSlotPair  0x021E86E8  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   HAND_TOKUSEI_RollChanceOrFlag  0x021D85C0  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   gPickupHandlers     0x021F06C8  data   ov093  a4
 */
#include "hand_tokusei_021dbaf0_types.h"

/* Services of the event variable stack, the battle server flow and the poke parameter. */
extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 value);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern u32 BTL_CALC_Random(u32 range);
extern int BTL_MAIN_IsPokeSamePair(unsigned int pokeIdA, unsigned int pokeIdB);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(struct BtlServerFlow *flow, int pokeId);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(struct BtlServerFlow *flow, int posKey, u8 *out);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlServerFlow *flow, int pokeId);
extern u8 *BTL_SERVER_FLOW_GetScratchBuffer(struct BtlServerFlow *flow, int size);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(struct BtlServerFlow *flow, int cmdKind, int pokeId);
extern void BTL_SERVER_FLOW_InitMsgRecord(BtlStrParam *strParam, int strType, int strId);
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(BtlStrParam *strParam, u32 arg);
extern void BTL_SERVER_FLOW_CommitCmdRecord(struct BtlServerFlow *flow, void *cmd);
extern int BTL_SERVER_FLOW_CheckShowdownThunk(struct BtlServerFlow *flow);
extern int BTL_POKEPARAM_HasType(struct BtlPokeParam *bpp, int typeId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_TestTurnFlag(struct BtlPokeParam *bpp, u32 flagIndex);
extern u16 BTL_POKEPARAM_GetConsumedItem(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_GetPokeId(struct BtlPokeParam *bpp);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern int HAND_TOKUSEI_RollChanceOrFlag(struct BtlServerFlow *flow, u32 percent);
extern int func_021E85F8(int pokeId);
extern int BTLV_CORE_CheckEitherSlotPair(struct BtlServerFlow *flow, int pokeIdA, int pokeIdB);
extern union BtlSickCont BTLV_CORE_MakeSlotKind2(int index, int value);
extern int func_0689C8CC(u32 moveId);
extern u32 WAZA_TOOL_GetFlag(u16 moveId, u32 flagBit);

void HAND_TOKUSEI_MagnetPull_BlockSteelEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
int *HAND_TOKUSEI_GetUnburdenHandlers(int *handlerCount);
void HAND_TOKUSEI_Unburden_MarkItemLost(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
void HAND_TOKUSEI_Unburden_DoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work);
int *HAND_TOKUSEI_GetPickupHandlers(int *handlerCount);
void HAND_TOKUSEI_Pickup_TakeUsedItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId);
void *HAND_TOKUSEI_GetPickpocketHandlers(int *handlerCount);
void HAND_TOKUSEI_Pickpocket_StealOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
void HAND_TOKUSEI_CursedBody_DisableAttackerMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId);
extern int gUnburdenHandlers[];
extern u8 gPickpocketHandlers[];
extern int gPickupHandlers[];

/* Magnet Pull: a Steel-type Pokemon among the owner's targets cannot escape. */
void HAND_TOKUSEI_MagnetPull_BlockSteelEscape(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 targetIds[4];
    u32 targetCount;
    u8 i;

    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID), ownerId) == 0) {
        targetCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, ownerId) | 0x100), targetIds);
        for (i = 0; i < targetCount; i++) {
            if (BTL_POKEPARAM_HasType(BTL_SERVER_FLOW_GetPokeParam(flow, targetIds[i]), POKETYPE_STEEL) != 0)
                BTL_EVENT_OverwriteVar(BTL_EVAR_FORCE_GROUNDED_FLAG, 1);
        }
    }
}

int *HAND_TOKUSEI_GetUnburdenHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gUnburdenHandlers;
}

/* Unburden: remember that the owner is about to lose its held item. */
void HAND_TOKUSEI_Unburden_MarkItemLost(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_SELF_CAUSED_FLAG) == 0
        && BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId)))
        *work = 1;
}

/* Unburden: once the item is gone, the speed of the owner doubles. */
void HAND_TOKUSEI_Unburden_DoubleSpeed(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId, int *work)
{
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *work == 1) {
        if (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId)) == 0) {
            BTL_EVENT_MultiplyVar(BTL_EVAR_RATIO, BTL_RATIO_2_0);
        }
    }
}

int *HAND_TOKUSEI_GetPickupHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gPickupHandlers;
}

/* Pickup: an owner without an item takes a random item that a Pokemon around it used this turn. */
void HAND_TOKUSEI_Pickup_TakeUsedItem(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 ownerId)
{
    TokuseiPickupScratch *scratch;
    struct BtlPokeParam *candidate;
    BtlSetItemCmd *cmd;
    u32 posKey;
    u8 i;
    u8 holderCount;
    u8 selectedId;
    u16 itemId;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && !BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, ownerId))) {
        posKey = BTL_SERVER_FLOW_GetFrontPosOfPoke(flow, ownerId);
        scratch = (TokuseiPickupScratch *)BTL_SERVER_FLOW_GetScratchBuffer(flow, sizeof(TokuseiPickupScratch));
        scratch->candidateCount = BTL_SERVER_FLOW_CollectAlivePokeIds(flow, (u16)(posKey | 0x200), scratch->candidateIds);
        holderCount = 0;
        scratch->spare = 0;
        for (i = 0; i < (u32)scratch->candidateCount; i++) {
            candidate = BTL_SERVER_FLOW_GetPokeParam(flow, scratch->candidateIds[i]);
            if (BTL_POKEPARAM_TestTurnFlag(candidate, BTL_TURN_FLAG_ITEM_USED) && BTL_POKEPARAM_GetConsumedItem(candidate)) {
                scratch->holderIds[holderCount++] = BTL_POKEPARAM_GetPokeId(candidate);
            }
        }
        if (holderCount) {
            selectedId = (scratch->candidateIds + (u8)BTL_CALC_Random(holderCount))[6];
            itemId = BTL_POKEPARAM_GetConsumedItem(BTL_SERVER_FLOW_GetPokeParam(flow, selectedId));
            if (itemId) {
                cmd = (BtlSetItemCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_SET_ITEM, ownerId);
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->pokeId = ownerId;
                cmd->itemId = itemId;
                cmd->clearConsumed = 1;
                cmd->sourcePokeId = selectedId;
                BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_PICKUP);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, ownerId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, itemId);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}

void *HAND_TOKUSEI_GetPickpocketHandlers(int *handlerCount) { *handlerCount = 1; return gPickpocketHandlers; }

/* Pickpocket: when a contact move hits the owner, the owner takes the item of the attacker. */
void HAND_TOKUSEI_Pickpocket_StealOnContact(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 attackerId;
    struct BtlPokeParam *owner;
    struct BtlPokeParam *attacker;
    BtlStealItemCmd *cmd;

    if (func_021E85F8(ownerId) != 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        if (BTLV_CORE_CheckEitherSlotPair(flow, ownerId, attackerId) == 0
            && WAZA_TOOL_GetFlag(BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID), BTL_WAZA_FLAG_CONTACT) != 0) {
            owner = BTL_SERVER_FLOW_GetPokeParam(flow, ownerId);
            attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
            if (BTL_POKEPARAM_GetItem(owner) == 0 && BTL_POKEPARAM_GetItem(attacker) != 0) {
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_STEAL_ITEM, ownerId);
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                cmd->victimId = attackerId;
                BTL_SERVER_FLOW_InitMsgRecord(&cmd->strParam, BTL_STR_TYPE_STD, BTL_MSG_PICKPOCKET);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, attackerId);
                BTL_SERVER_FLOW_AppendMsgRecordArg(&cmd->strParam, BTL_POKEPARAM_GetItem(attacker));
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
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
void HAND_TOKUSEI_CursedBody_DisableAttackerMove(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int ownerId)
{
    u8 attackerId;
    u16 moveId;
    DisableTurns turns;
    struct BtlPokeParam *attacker;
    BtlAddSickCmd *cmd;

    turns = DISABLE_TURNS_BASE;
    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)
        && BTL_EVENT_GetVar(BTL_EVAR_HIT_SUBSTITUTE_FLAG) == 0
        && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0) {
        attackerId = BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID);
        attacker = BTL_SERVER_FLOW_GetPokeParam(flow, attackerId);
        if (BTL_POKEPARAM_HasSick(attacker, BTL_SICK_DISABLE) == 0) {
            moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID_USED);
            if (moveId != 0 && moveId != BTL_MOVE_STRUGGLE && func_0689C8CC(moveId) == 0
                && HAND_TOKUSEI_RollChanceOrFlag(flow, 30) != 0) {
                if (BTL_POKEPARAM_TestTurnFlag(attacker, BTL_TURN_FLAG_ACTED) != 0) {
                    turns = (DisableTurns)(u8)(turns + 1);
                }
                cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_ADD_SICK, ownerId);
                cmd->sickId = BTL_SICK_DISABLE;
                cmd->sickCont = BTLV_CORE_MakeSlotKind2(turns, moveId);
                cmd->targetId = attackerId;
                cmd->flags |= BTL_CMD_FLAG_FROM_ABILITY;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
            }
        }
    }
}
