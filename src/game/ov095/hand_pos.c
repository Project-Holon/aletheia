/*
 * file:     hand_pos.c
 * unit:     yes
 * function: HAND_POS_AddFactor, HAND_POS_IsRegistered, HAND_POS_IsNotRegistered, HAND_POS_GetHandlersWish, HAND_POS_WishHealOnTurn, HAND_POS_GetHandlersLunarDance, HAND_POS_LunarDanceOnSwitchIn, HAND_POS_GetHandlersHealingWish, HAND_POS_HealingWishOnSwitchIn, HAND_POS_GetHandlersFutureSight, HAND_POS_FutureSightOnTurn, HAND_POS_GetHandlersPending, HAND_POS_PendingOnEnter
 * address:  0x068981F0
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * note: Two bytes of alignment padding follow the 42-byte function.
 *
 * symbols:
 *   BTL_EVENT_AddFactor  0x021D6F0C  thumb  ov093
 *   BTL_EVENT_SetFactorWork  0x021D70DC  thumb
 *   gHandPosEffectTable     0x0689D6C8  data   ov095  a4
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb
 *   BTL_EVENT_FindFactor  0x021D732C  thumb
 *   BTL_EVENT_FindNextFactor  0x021D7360  thumb
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb
 *   BTL_SERVER_FLOW_GetPokeIdAtFieldIndex  0x021C8020  thumb
 *   BTL_SERVER_FLOW_GetTurnCount  0x021C8138  thumb
 *   BTL_SERVER_FLOW_CheckShowdownThunk  0x021C83D4  thumb
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_IsHpFull  0x021D5B48  thumb
 *   BTL_EVENT_RemoveFactor  0x021D7040  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb
 *   gHandPosWishHandlers 0x0689D698 data ov095 a4
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb
 *   BTL_POKEPARAM_GetMovePPLost  0x021D554C  thumb
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb
 *   gHandPosLunarDanceHandlers 0x0689D6B8 data ov095 a4
 *   gHandPosHealingWishHandlers 0x0689D6A8 data a4
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb
 *   gHandPosFutureSightHandlers 0x0689D6A0 data a4
 *   gHandPosPendingEntryHandlers 0x0689D690 data a4
 */
#include "hand_field_types.h"

extern void BTL_EVENT_SetFactorWork(struct BtlEventFactor *factor, u8 index, u32 value);
extern struct BtlEventFactor *BTL_EVENT_FindFactor(int factorType, int ownerId);
extern u16 BTL_EVENT_GetFactorKey(struct BtlEventFactor *factor);
extern struct BtlEventFactor *BTL_EVENT_FindNextFactor(struct BtlEventFactor *factor);
extern int BTL_SERVER_FLOW_GetPokeViewPos(struct BtlServerFlow *flow, u32 pokeId);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct BtlPokeParam *bpp);
extern u32 BTL_POKEPARAM_GetMoveCount(struct BtlPokeParam *bpp);
extern u8 BTL_POKEPARAM_GetMovePPLost(struct BtlPokeParam *bpp, u8 moveIndex);
extern int BTL_POKEPARAM_GetValue(struct BtlPokeParam *bpp, int valueId);
extern int BTL_POKEPARAM_IsFainted(struct BtlPokeParam *bpp);
struct BtlEventFactor *HAND_POS_AddFactor(int effectId, int position, u32 userPokeId, u32 *values, u8 valueCount);
int HAND_POS_IsRegistered(int a, int b);
int HAND_POS_IsNotRegistered(int effectId, int position);
const BtlEventHandler *HAND_POS_GetHandlersWish(u32 *handlerCount);
void HAND_POS_WishHealOnTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, HandWishWork *work);
const BtlEventHandler *HAND_POS_GetHandlersLunarDance(u32 *handlerCount);
void HAND_POS_LunarDanceOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 position);
const BtlEventHandler *HAND_POS_GetHandlersHealingWish(u32 *handlerCount);
void HAND_POS_HealingWishOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 position);
const BtlEventHandler *HAND_POS_GetHandlersFutureSight(u32 *handlerCount);
void HAND_POS_FutureSightOnTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, HandFutureSightWork *work);
const BtlEventHandler *HAND_POS_GetHandlersPending(u32 *handlerCount);
void HAND_POS_PendingOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, u32 *work);
extern const HandEffectEntry gHandPosEffectTable[BTL_POSEFF_COUNT];
extern const BtlEventHandler gHandPosWishHandlers[1];
extern const BtlEventHandler gHandPosLunarDanceHandlers[2];
extern const BtlEventHandler gHandPosHealingWishHandlers[2];
extern const BtlEventHandler gHandPosFutureSightHandlers[1];
extern const BtlEventHandler gHandPosPendingEntryHandlers[1];


/*
 * Registers the event factor of position effect effectId for the field position
 * `position`. Returns 0 when the id is unknown or the position already has this effect.
 * The first valueCount words of values become factor work words 0..n-1; work word 6
 * receives the id of the Pokemon that created the effect.
 */
struct BtlEventFactor *HAND_POS_AddFactor(int effectId, int position, u32 userPokeId, u32 *values, u8 valueCount)
{
    u32 i;
    u32 handlerCount;
    struct BtlEventFactor *factor;

    for (i = 0; i < BTL_POSEFF_COUNT; i++) {
        if (effectId == gHandPosEffectTable[i].effectId) {
            const BtlEventHandler *handlers;
            if (HAND_POS_IsNotRegistered(effectId, position) == 0)
                break;
            handlers = gHandPosEffectTable[i].getHandlers(&handlerCount);
            factor = BTL_EVENT_AddFactor(BTL_EVENT_TYPE_POS_EFFECT, effectId, 1, 0, position, (u32)handlers, handlerCount);
            if (factor != 0) {
                for (i = 0; i < valueCount; i++)
                    BTL_EVENT_SetFactorWork(factor, i, values[i]);
                BTL_EVENT_SetFactorWork(factor, 6, userPokeId);
            }
            return factor;
        }
    }
    return 0;
}


int HAND_POS_IsRegistered(int a, int b)
{
    if (HAND_POS_IsNotRegistered(a, b) == 0)
        return 1;
    return 0;
}


/* Returns 1 when position `position` has no position effect factor with this effect id yet. */
int HAND_POS_IsNotRegistered(int effectId, int position)
{
    struct BtlEventFactor *factor = BTL_EVENT_FindFactor(BTL_EVENT_TYPE_POS_EFFECT, position);
    while (factor != 0) {
        if (effectId == BTL_EVENT_GetFactorKey(factor)) return 0;
        factor = BTL_EVENT_FindNextFactor(factor);
    }
    return 1;
}


/*
 * note: Unlabelled follower after the 0689830C veneer; ends before existing 06898328.
 */

/* Handler list of Wish: one entry on the turn check event. */
const BtlEventHandler *HAND_POS_GetHandlersWish(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandPosWishHandlers;
}


/*
 * Wish, turn check: on the first check the effect records the turn count. On a later turn
 * the Pokemon at the position is healed by half of the user's maximum HP (unless it is
 * at full HP) and the effect ends.
 */
void HAND_POS_WishHealOnTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, HandWishWork *work)
{
    if (BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) == BTL_EVENT_NO_POKE && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0) {
        if (work->armed == 0) {
            work->startTurn = BTL_SERVER_FLOW_GetTurnCount(flow);
            work->armed = 1;
        } else if (BTL_SERVER_FLOW_GetTurnCount(flow) > work->startTurn) {
            int targetId = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(flow, position);

            if (targetId != BTL_EVENT_NO_POKE) {
                if (BTL_POKEPARAM_IsHpFull(BTL_SERVER_FLOW_GetPokeParam(flow, targetId)) == 0) {
                    u8 userId = work->userPokeId;
                    struct BtlPokeParam *user = BTL_SERVER_FLOW_GetPokeParam(flow, userId);
                    struct HandExRecoverHp *heal = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, userId);

                    heal->pokeId = targetId;
                    heal->amount = BTL_CALC_DivideMaxHpMin1(user, 2);
                    BTL_SERVER_FLOW_InitMsgRecord(&heal->message, HANDEX_MESSAGE_SET, 0x2bc);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(&heal->message, userId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, heal);
                }
            }
            BTL_EVENT_RemoveFactor(factor);
        }
    }
}


/* Values of BTL_POKEPARAM_GetValue used here. */
enum {
    BPP_VALUE_HP = 13,
    BPP_VALUE_MAX_HP = 14
};


/*
 * extent: 12-byte unlabelled store-and-return follower after non-C veneer 068984AC; next function 068984C8 is already matched.
 */

/* Handler list of Lunar Dance: member enter, and member enter after a faint. */
const BtlEventHandler *HAND_POS_GetHandlersLunarDance(u32 *handlerCount)
{
    *handlerCount = 2;
    return gHandPosLunarDanceHandlers;
}


/*
 * Lunar Dance, member enter: when a Pokemon enters the position the effect guards, it is healed
 * fully, cured of its major status and gets all PP back, but only if something needs restoring.
 * Then the effect ends.
 */
void HAND_POS_LunarDanceOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 position)
{
    u32 i;
    u32 j;
    u8 enteringId;
    struct BtlPokeParam *enteringPoke;
    int needsRestore;
    void *cmd;
    u32 moveCount;
    int maxHp;
    u32 moveCount2;
    u8 ppLost;
    struct HandExPosHealNotice *notice;
    struct HandExRecoverHp *heal;
    struct HandExCureSick *cure;
    struct HandExRestorePp *restorePp;

    enteringId = (u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
    if (position == BTL_SERVER_FLOW_GetPokeViewPos(flow, enteringId)) {
        enteringPoke = BTL_SERVER_FLOW_GetPokeParam(flow, enteringId);
        needsRestore = 0;
        if (BTL_POKEPARAM_IsHpFull(enteringPoke) == 0)
            needsRestore = 1;
        if (BTL_POKEPARAM_GetMajorStatusIndex(enteringPoke) != 0)
            needsRestore = 1;
        moveCount = BTL_POKEPARAM_GetMoveCount(enteringPoke);
        for (i = 0; i < moveCount; i++) {
            if (BTL_POKEPARAM_GetMovePPLost(enteringPoke, i) != 0)
                needsRestore = 1;
        }
        if (needsRestore != 0) {
            notice = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_POS_HEAL_NOTICE, enteringId);
            notice->animId = 0x280;
            notice->position = position;
            notice->targetKind = 6;
            notice->restorePp = 1;
            BTL_SERVER_FLOW_InitMsgRecord(&notice->message, HANDEX_MESSAGE_SET, 0x2b6);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&notice->message, enteringId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, notice);
            if (BTL_POKEPARAM_IsHpFull(enteringPoke) == 0) {
                heal = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, enteringId);
                heal->pokeId = enteringId;
                maxHp = BTL_POKEPARAM_GetValue(enteringPoke, BPP_VALUE_MAX_HP);
                heal->amount = maxHp - BTL_POKEPARAM_GetValue(enteringPoke, BPP_VALUE_HP);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, heal);
            }
            if (BTL_POKEPARAM_GetMajorStatusIndex(enteringPoke) != 0) {
                cure = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, enteringId);
                cure->pokeCount = 1;
                cure->pokeIds[0] = enteringId;
                cure->sickKind = 36;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cure);
            }
            moveCount2 = BTL_POKEPARAM_GetMoveCount(enteringPoke);
            for (j = 0; j < moveCount2; j++) {
                ppLost = BTL_POKEPARAM_GetMovePPLost(enteringPoke, j);
                if (ppLost != 0) {
                    restorePp = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RESTORE_PP, enteringId);
                    restorePp->pokeId = enteringId;
                    restorePp->amount = ppLost;
                    restorePp->moveIndex = j;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, restorePp);
                }
            }
        }
        BTL_EVENT_RemoveFactor(factor);
    }
}




/*
 * extent: 12-byte store-and-return follower after non-C veneer 06898798.
 */

/* Handler list of Healing Wish: member enter, and member enter after a faint. */
const BtlEventHandler *HAND_POS_GetHandlersHealingWish(u32 *handlerCount)
{
    *handlerCount = 2;
    return gHandPosHealingWishHandlers;
}


/*
 * Healing Wish, member enter: when a Pokemon enters the position the effect guards, it is
 * healed fully and cured of its major status, but only if something needs restoring.
 * Then the effect ends.
 */
void HAND_POS_HealingWishOnSwitchIn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, u8 position)
{
    u8 enteringId;
    struct BtlPokeParam *enteringPoke;
    int needsRestore;
    int maxHp;
    struct HandExPosHealNotice *notice;
    struct HandExRecoverHp *heal;
    struct HandExCureSick *cure;

    enteringId = (u8)BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
    if (position == BTL_SERVER_FLOW_GetPokeViewPos(flow, enteringId)) {
        enteringPoke = BTL_SERVER_FLOW_GetPokeParam(flow, enteringId);
        needsRestore = 0;
        if (BTL_POKEPARAM_IsHpFull(enteringPoke) == 0)
            needsRestore = 1;
        if (BTL_POKEPARAM_GetMajorStatusIndex(enteringPoke) != 0)
            needsRestore = 1;
        if (needsRestore != 0) {
            notice = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_POS_HEAL_NOTICE, enteringId);
            notice->animId = 0x27f;
            notice->position = position;
            notice->targetKind = 6;
            BTL_SERVER_FLOW_InitMsgRecord(&notice->message, HANDEX_MESSAGE_SET, 0x2b9);
            BTL_SERVER_FLOW_AppendMsgRecordArg(&notice->message, enteringId);
            BTL_SERVER_FLOW_CommitCmdRecord(flow, notice);
            if (BTL_POKEPARAM_IsHpFull(enteringPoke) == 0) {
                heal = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_RECOVER_HP, enteringId);
                heal->pokeId = enteringId;
                maxHp = BTL_POKEPARAM_GetValue(enteringPoke, BPP_VALUE_MAX_HP);
                heal->amount = maxHp - BTL_POKEPARAM_GetValue(enteringPoke, BPP_VALUE_HP);
                BTL_SERVER_FLOW_CommitCmdRecord(flow, heal);
            }
            if (BTL_POKEPARAM_GetMajorStatusIndex(enteringPoke) != 0) {
                cure = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_CURE_SICK, enteringId);
                cure->pokeCount = 1;
                cure->pokeIds[0] = enteringId;
                cure->sickKind = 36;
                BTL_SERVER_FLOW_CommitCmdRecord(flow, cure);
            }
        }
        BTL_EVENT_RemoveFactor(factor);
    }
}


/*
 * Follower of the non-C veneer at 0x068989B0; code and pool end at 0x068989CC.
 */

/* Handler list of Future Sight and Doom Desire: one entry on the turn check event. */
const BtlEventHandler *HAND_POS_GetHandlersFutureSight(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandPosFutureSightHandlers;
}


/*
 * Future Sight / Doom Desire, turn check: once the trigger turn is reached, the Pokemon at the
 * position is shown the "took the attack" message and the damage command is queued (unless
 * it is the user itself or has fainted). Then the effect ends.
 *
 * The message pointer is passed live in r1 to the commit veneer, which
 * targets the two-argument BTL_SERVER_FLOW_CommitCmdRecord. Omitting it lost its r0-to-r1 copy.
 */
void HAND_POS_FutureSightOnTurn(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, HandFutureSightWork *work)
{
    if (BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) == BTL_EVENT_NO_POKE && BTL_SERVER_FLOW_CheckShowdownThunk(flow) == 0) {
        u8 turn = BTL_SERVER_FLOW_GetTurnCount(flow);
        if (turn >= work->triggerTurn) {
            int targetId = BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(flow, position);
            u8 userId = work->userPokeId;
            if (targetId != BTL_EVENT_NO_POKE && targetId != userId) {
                if (BTL_POKEPARAM_IsFainted(BTL_SERVER_FLOW_GetPokeParam(flow, targetId)) == 0) {
                    struct HandExMessage *notice = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_MESSAGE, userId);
                    struct HandExFutureSightHit *hit;
                    BTL_SERVER_FLOW_InitMsgRecord(&notice->message, HANDEX_MESSAGE_SET, 0x438);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(&notice->message, targetId);
                    BTL_SERVER_FLOW_AppendMsgRecordArg(&notice->message, work->moveId);
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, notice);
                    hit = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_FUTURE_SIGHT_HIT, userId);
                    hit->attackerId = userId;
                    hit->targetId = targetId;
                    hit->moveId = work->moveId;
                    BTL_SERVER_FLOW_CommitCmdRecord(flow, hit);
                }
            }
            BTL_EVENT_RemoveFactor(factor);
        }
    }
}


/*
 * note: Unlabelled follower after the non-C veneer at 0x06898B50.
 */

/* Handler list of the pending entry effect: one entry on the member enter event. */
const BtlEventHandler *HAND_POS_GetHandlersPending(u32 *handlerCount)
{
    *handlerCount = 1;
    return gHandPosPendingEntryHandlers;
}


/*
 * Pending entry, member enter: when the Pokemon that enters is the one at the position the
 * effect guards, a command with the stored value (work word 0) is queued for it and the
 * effect ends. The purpose of command kind 0x2a is not known.
 *
 * The returned record pointer stays live in r1 for the commit veneer, which
 * reaches the two-argument BTL_SERVER_FLOW_CommitCmdRecord. A one-argument declaration loses
 * the pointer copy and leaves 18 differing bytes (62/64).
 */
void HAND_POS_PendingOnEnter(struct BtlEventFactor *factor, struct BtlServerFlow *flow, int position, u32 *work)
{
    u8 enteringId = BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
    struct HandExPendingEntry *cmd;
    if (enteringId == BTL_SERVER_FLOW_GetPokeIdAtFieldIndex(flow, position)) {
        cmd = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_KIND_PENDING_ENTRY, BTL_EVENT_NO_POKE);
        cmd->value = *work;
        cmd->pokeId = enteringId;
        BTL_SERVER_FLOW_CommitCmdRecord(flow, cmd);
        BTL_EVENT_RemoveFactor(factor);
    }
}
