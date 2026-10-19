/*
 * file:     hand_common.c
 * unit:     yes
 * function: HAND_COMMON_IsMoveTarget, HAND_COMMON_IsLastToAct, HAND_COMMON_IsItemBoundToSpecies, HAND_COMMON_IsHeldItemBoundToOwnSpecies, BTLV_CORE_CheckPartySlotCondition, BTLV_CORE_CheckEitherSlotPair, HAND_COMMON_EventRedirectMove, HAND_COMMON_EventCounterMove, HAND_COMMON_EventQueueMoveNotice, HAND_COMMON_EventScaleDamage, HAND_COMMON_EventSetFlagIfAttacker, HAND_COMMON_EventTrySetFlagIfAttacker
 * address:  0x021E85F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from hand_common.c, btlv_core.c by tools/splitfile.py.
 *
 * symbols:
 *   BTL_ID_IsArceusPlate  0x0689C980  thumb
 *   BTL_ID_IsGenesectDrive  0x0689C990  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AreAllOtherActionsDone  0x021C80AC  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetSpecies  0x021D5444  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   HAND_COMMON_IsItemBoundToSpecies  0x021E8638  thumb  ov093
 *   BTL_SERVER_FLOW_GetCompetitor  0x021C8168  thumb  ov093
 *   BTL_MAIN_PokeIdToClientIdThunk  0x021B8DDC  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   BTL_SERVER_FLOW_PushMoveQueueWithPos  0x021C8434  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 */
#include "hand_common_protos.h"
#include "btlv_core_types.h"

/* Shared helper of the ability, item and move handlers: whether the Pokemon is one of the targets of the current move. */
int HAND_COMMON_IsMoveTarget(int pokeId)
{
    u32 i;
    u32 targetCount;

    targetCount = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_COUNT);
    i = 0;
    if (targetCount != 0) {
        do {
            if (pokeId == BTL_EVENT_GetVar(i + BTL_EVAR_DEFENDER_FIRST))
                return 1;
            i++;
        } while (i < targetCount);
    }
    return 0;
}

/* Shared helper (Protect family, abilities, items): whether every other Pokemon has already acted this turn. */
int HAND_COMMON_IsLastToAct(struct BtlServerFlow *flow, int pokeId)
{
    if (BTL_SERVER_FLOW_AreAllOtherActionsDone(flow, pokeId) != 0)
        return 1;
    return 0;
}

/*
 * Shared helper (Trick family, Knock Off, view code): whether the item cannot be taken from or
 * given to a Pokemon of that species (Griseous Orb on Giratina, Plates on Arceus, Drives on Genesect).
 */
int HAND_COMMON_IsItemBoundToSpecies(int speciesId, int itemId)
{
    switch (speciesId) {
    case BTL_SPECIES_GIRATINA:
        if (itemId == BTL_ITEM_GRISEOUS_ORB)
            return 1;
        break;
    case BTL_SPECIES_ARCEUS:
        if (BTL_ID_IsArceusPlate(itemId) != 0)
            return 1;
        break;
    case BTL_SPECIES_GENESECT:
        if (BTL_ID_IsGenesectDrive(itemId) != 0)
            return 1;
        break;
    }
    return 0;
}

/* Event record from BTL_SERVER_FLOW_AllocCmdRecord: a 4-byte header, then a list. */
struct BtlvEventRec {
    u32 header;
    u8 list[];
};

extern int BTL_SERVER_FLOW_GetCompetitor(void *p);

extern u8 BTL_MAIN_PokeIdToClientIdThunk(u32 x);

extern u32 WAZA_TOOL_GetCategory(u16 move);

extern void BTL_SERVER_FLOW_PushMoveQueueWithPos(u8 *p, int a, int b);

extern int BTL_POKEPARAM_IsSemiInvulnerable(struct BtlPokeParam *p);

int HAND_COMMON_IsHeldItemBoundToOwnSpecies(void *party, int slot);

int BTLV_CORE_CheckPartySlotCondition(void *party, int slot);

int BTLV_CORE_CheckEitherSlotPair(void *party, int slotA, int slotB);

void HAND_COMMON_EventRedirectMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);

void HAND_COMMON_EventCounterMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);

void HAND_COMMON_EventQueueMoveNotice(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1);

void HAND_COMMON_EventScaleDamage(int factor);

void HAND_COMMON_EventSetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId, int unusedArg2);

int HAND_COMMON_EventTrySetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId);

int HAND_COMMON_IsHeldItemBoundToOwnSpecies(void *party, int slot)
{
    struct BtlPokeParam *entry;
    int typeId;
    u16 itemId;

    entry = BTL_SERVER_FLOW_GetPokeParam(party, slot);
    typeId = BTL_POKEPARAM_GetSpecies(entry);
    itemId = (int)BTL_POKEPARAM_GetItem(entry);
    if (HAND_COMMON_IsItemBoundToSpecies(typeId, itemId) != 0)
        return 1;
    return 0;
}

/*
 * 2026-10-03: the `cmp r0,#1; beq; bne` pair is a disjunction of two tests that both
 * compare against 1 (likely two constants with the same value); the compiler keeps
 * one branch per operand.
 */
int BTLV_CORE_CheckPartySlotCondition(void *party, int slot)
{
    int result;

    if (BTL_SERVER_FLOW_GetCompetitor(party) == 0) {
        result = BTL_MAIN_PokeIdToClientIdThunk(slot);
        if (result == 1 || result == 1)
            return 1;
    }
    return 0;
}

int BTLV_CORE_CheckEitherSlotPair(void *party, int slotA, int slotB)
{
    struct BtlPokeParam *entryA;
    struct BtlPokeParam *entryB;
    int typeId;
    u16 itemId;

    if (BTLV_CORE_CheckPartySlotCondition(party, slotA) != 0)
        return 1;
    if (HAND_COMMON_IsHeldItemBoundToOwnSpecies(party, slotB) != 0)
        return 1;
    entryA = BTL_SERVER_FLOW_GetPokeParam(party, slotA);
    entryB = BTL_SERVER_FLOW_GetPokeParam(party, slotB);
    typeId = BTL_POKEPARAM_GetSpecies(entryA);
    itemId = (int)BTL_POKEPARAM_GetItem(entryB);
    if (HAND_COMMON_IsItemBoundToSpecies(typeId, itemId) != 0)
        return 1;
    return 0;
}

void HAND_COMMON_EventRedirectMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    u8 attackerId;
    u16 moveId;

    attackerId = BTL_EVENT_GetVar(2);
    if (BTL_MAIN_IsPokeSamePair(attackerId, pokeId) == 0) {
        moveId = BTL_EVENT_GetVar(0x12);
        if (WAZA_TOOL_GetCategory(moveId) == 0xb) {
            if (WAZA_TOOL_GetFlag(moveId, 4) != 0) {
                if (BTL_EVENT_OverwriteVar(0x22, 0x19) != 0)
                    BTL_SERVER_FLOW_PushMoveQueueWithPos(eventCtx, pokeId, attackerId);
            }
        }
    }
}

void HAND_COMMON_EventCounterMove(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    u8 defenderId;
    u16 moveId;
    int flagBit;

    flagBit = 4;
    if (pokeId == BTL_EVENT_GetVar(4)) {
        if (BTL_EVENT_GetVar(0x4e) == 0) {
            if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(eventCtx, pokeId)) == 0) {
                moveId = BTL_EVENT_GetVar(0x12);
                if (WAZA_TOOL_GetFlag(moveId, flagBit) != 0) {
                    flagBit = 1;
                    if (BTL_EVENT_OverwriteVar(0x40, 1) != 0) {
                        defenderId = BTL_EVENT_GetVar(3);
                        BTL_SERVER_FLOW_PushMoveQueueWithPos(eventCtx, pokeId, defenderId);
                        BTL_EVENT_OverwriteVar(0x51, flagBit);
                    }
                }
            }
        }
    }
}

void HAND_COMMON_EventQueueMoveNotice(int unusedArg0, void *eventCtx, int pokeId, int unusedArg1)
{
    struct BtlvEventRec *rec;
    int listKind;

    listKind = 2;
    if (pokeId == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_IsSemiInvulnerable(BTL_SERVER_FLOW_GetPokeParam(eventCtx, pokeId)) == 0) {
            rec = BTL_SERVER_FLOW_AllocCmdRecord(eventCtx, 4, pokeId);
            BTL_SERVER_FLOW_InitMsgRecord(rec->list, listKind, 0x2fc);
            BTL_SERVER_FLOW_AppendMsgRecordArg(rec->list, pokeId);
            BTL_SERVER_FLOW_AppendMsgRecordArg(rec->list, BTL_EVENT_GetVar(0x12));
            BTL_SERVER_FLOW_CommitCmdRecord(eventCtx, rec);
        }
    }
}

void HAND_COMMON_EventScaleDamage(int factor)
{
    factor *= BTL_EVENT_GetVar(0x30);
    BTL_EVENT_OverwriteVar(0x30, factor);
}

void HAND_COMMON_EventSetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId, int unusedArg2)
{
    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(2), pokeId) != 0)
        BTL_EVENT_OverwriteVar(0x51, 1);
}

int HAND_COMMON_EventTrySetFlagIfAttacker(int unusedArg0, int unusedArg1, int pokeId)
{
    if (BTL_MAIN_IsPokeSamePair((u8)BTL_EVENT_GetVar(2), pokeId) != 0) {
        if (BTL_EVENT_OverwriteVar(0x51, 1) != 0)
            return 1;
    }
    return 0;
}
