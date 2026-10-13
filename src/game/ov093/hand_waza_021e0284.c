/*
 * file:     hand_waza_021e0284.c
 * unit:     yes
 * function: HAND_ITEM_GemMovePower, HAND_ITEM_GemMoveDamageEnd, HAND_WAZA_AddMoveHandler, HAND_WAZA_CanAddMoveHandler, HAND_WAZA_RemoveMoveHandlerUnlessKept, HAND_WAZA_RemoveMoveHandlerOfPoke, HAND_WAZA_IsKeptOnSuspend, HAND_WAZA_RemoveMoveHandlerById, HAND_WAZA_RemoveAllMoveHandlers, HAND_WAZA_GetConversionHandlers, HAND_WAZA_ConversionEffect, HAND_WAZA_GetCamouflageHandlers
 * address:  0x021E0284
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
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_IsActionCounterSet  0x021C7EC4  thumb  ov093
 *   gWazaHandlerRegistry  0x021F3030  data
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   BTL_EVENT_FindFactor  0x021D732C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb  ov093
 *   BTL_EVENT_GetFactorWork  0x021D70B4  thumb  ov093
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   BTL_POKEPARAM_HasType  0x021D5814  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_Random  0x021D78AC  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gHandWazaConversionHandlers     0x021F261C  data   ov093  a4
 *   gHandWazaCamouflageHandlers     0x021F2414  data   ov093  a4
 */
#include "hand_item_types.h"

extern const WazaHandlerEntry gWazaHandlerRegistry[WAZA_HANDLER_REGISTRY_COUNT];
extern BtlEventHandler gHandWazaConversionHandlers[];
extern BtlEventHandler gHandWazaCamouflageHandlers[];

int HAND_WAZA_CanAddMoveHandler(int ownerId, int moveId, u8 *alreadyAdded);
void HAND_WAZA_RemoveMoveHandlerById(int ownerId, int moveId);

/*
 * Gem, move power (event 0x38): the attacker's move of the gem's type gets the
 * 1.5 boost when the gem was just used (work[0]) or the flow test says so.
 */
void HAND_ITEM_GemMovePower(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 gemType)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && gemType == BTL_EVENT_GetVar(BTL_EVAR_MOVE_TYPE)) {
        if (*work == BTL_GEM_STATE_CONSUMED || BTL_SERVER_FLOW_IsActionCounterSet(flow))
            BTL_EVENT_MultiplyVar(BTL_EVAR_MOVE_POWER_RATIO, BTL_GEM_RATIO);
    }
}


/* Gem, end of the move damage (event 0x88): the gem state moves from consumed to done. */
void HAND_ITEM_GemMoveDamageEnd(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && *work == BTL_GEM_STATE_CONSUMED)
        *work = BTL_GEM_STATE_DONE;
}


/*
 * Add the handler of a move to the Pokemon when the move is chosen. Looks the
 * move up in the registry; returns 1 when a handler was added.
 */
int HAND_WAZA_AddMoveHandler(struct BtlPokeParam *bpp, u16 moveId, u32 subPriority)
{
    u32 index;
    u8 ownerId;
    u8 alreadyAdded;
    int handlerCount;
    BtlEventHandler *handlers;

    for (index = 0; index < WAZA_HANDLER_REGISTRY_COUNT; index++) {
        if (moveId == gWazaHandlerRegistry[index].moveId) {
            ownerId = BTL_POKEPARAM_GetPokeId(bpp);
            alreadyAdded = 0;
            if (HAND_WAZA_CanAddMoveHandler(ownerId, moveId, &alreadyAdded) != 0) {
                handlers = gWazaHandlerRegistry[index].getHandlers(&handlerCount);
                if (handlers != 0) {
                    BTL_EVENT_AddFactor(BTL_EVENT_TYPE_WAZA, moveId, 0, subPriority, ownerId, handlers, handlerCount);
                    return 1;
                }
            }
            return 0;
        }
    }
    return 0;
}


/*
 * Check whether a move handler may be added: returns 0 when the owner already
 * holds one for the move (and sets *alreadyAdded) or holds too many handlers.
 */
int HAND_WAZA_CanAddMoveHandler(int ownerId, int moveId, u8 *alreadyAdded)
{
    struct BtlEventFactor *factor;
    u32 scanned = 0;

    for (factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId); factor != 0; factor = BTL_EVENT_FindNextFactor(factor)) {
        if (moveId == BTL_EVENT_GetFactorKey(factor)) {
            *alreadyAdded = 1;
            return 0;
        }
        if (++scanned > WAZA_HANDLER_FACTOR_LIMIT)
            return 0;
    }
    return 1;
}


/* Remove the handlers of a move from the Pokemon unless their keep slot is set. */
void HAND_WAZA_RemoveMoveHandlerUnlessKept(struct BtlPokeParam *bpp, int moveId)
{
    struct BtlEventFactor *factor;
    struct BtlEventFactor *next;

    factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, BTL_POKEPARAM_GetPokeId(bpp));
    while (factor != 0) {
        next = BTL_EVENT_FindNextFactor(factor);
        if (moveId == BTL_EVENT_GetFactorKey(factor) && BTL_EVENT_GetFactorWork(factor, BTL_FACTOR_WORK_KEEP) == 0) {
            BTL_EVENT_RemoveFactor(factor);
        }
        factor = next;
    }
}


/* Remove every handler of a move from the Pokemon (the second callee takes the first one's result). */
void HAND_WAZA_RemoveMoveHandlerOfPoke(struct BtlPokeParam *bpp, int moveId)
{
    HAND_WAZA_RemoveMoveHandlerById(BTL_POKEPARAM_GetPokeId(bpp), moveId);
}


/* Tells the event list whether a move handler stays active when its owner is suspended (the keep slot is set). */
int HAND_WAZA_IsKeptOnSuspend(struct BtlEventFactor *factor, u32 *work)
{
    if (work[BTL_FACTOR_WORK_KEEP] != 0) return 1;
    return 0;
}


/* Remove every handler of a move from the owner with that id. */
void HAND_WAZA_RemoveMoveHandlerById(int ownerId, int moveId)
{
    struct BtlEventFactor *factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId);

    while (factor != 0) {
        if (moveId == BTL_EVENT_GetFactorKey(factor)) {
            BTL_EVENT_RemoveFactor(factor);
            factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId);
        } else {
            factor = BTL_EVENT_FindNextFactor(factor);
        }
    }
}


/* Remove every move handler of the Pokemon. */
void HAND_WAZA_RemoveAllMoveHandlers(struct BtlPokeParam *bpp)
{
    int ownerId = BTL_POKEPARAM_GetPokeId(bpp);
    struct BtlEventFactor *factor;

    while ((factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_WAZA, ownerId)) != 0)
        BTL_EVENT_RemoveFactor(factor);
}


/* Conversion handler table (move 160): move effect. */
BtlEventHandler *HAND_WAZA_GetConversionHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHandWazaConversionHandlers;
}


/* Conversion: the user becomes the type of one of its other moves that it does not have yet, chosen at random. */
void HAND_WAZA_ConversionEffect(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 candidateTypes[4];
    struct BtlPokeParam *bpp;
    u32 moveCount;
    u16 slot;
    u16 candidateCount;
    u32 moveType;
    BtlChangeTypeCmd *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        bpp = BTL_SERVER_FLOW_GetPokeParam(flow, pokeId);
        moveCount = BTL_POKEPARAM_GetMoveCount(bpp);
        slot = 0;
        candidateCount = 0;
        for (; slot < moveCount; slot++) {
            moveType = BTL_POKEPARAM_GetMoveId(bpp, (u8)slot);
            if (moveType != BTL_EVENT_GetFactorKey(factor)) {
                moveType = WAZA_TOOL_GetType(moveType);
                if (BTL_POKEPARAM_HasType(bpp, moveType) == 0) {
                    candidateTypes[candidateCount++] = moveType;
                }
            }
        }
        if (candidateCount != 0) {
            cmd = (BtlChangeTypeCmd *)BTL_SERVER_FLOW_AllocCmdRecord(flow, BTL_CMD_KIND_CHANGE_TYPE, pokeId);
            cmd->typePair = BTLV_CORE_PackByteTwice(candidateTypes[(u16)BTL_CALC_Random(candidateCount)]);
            cmd->pokeId = pokeId;
            BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        }
    }
}


/*
 * Camouflage handler table (move 293); the handler is in the next unit.
 * extent: 021E05C2 alignment padding.
 */
BtlEventHandler *HAND_WAZA_GetCamouflageHandlers(int *handlerCount)
{
    *handlerCount = 1;
    return gHandWazaCamouflageHandlers;
}
