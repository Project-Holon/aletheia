/*
 * file:     unit_021DB650.c
 * unit:     yes
 * function: BTL_TOKUSEI_Klutz_SkipCheck, BTL_TOKUSEI_Klutz_InstallSkipCheck, BTL_TOKUSEI_Klutz_InstallSkipCheckOnEntry, BTL_TOKUSEI_Klutz_RemoveSkipCheck, BTL_TOKUSEI_Klutz_NoticeHeldItem, BTL_TOKUSEI_Klutz_BlockNaturalGift, BTL_TOKUSEI_Klutz_ShowBlockedMoveMessage, BTL_TOKUSEI_GetKlutzHandlers, BTL_TOKUSEI_StickyHold_BlockTrick, BTL_TOKUSEI_StickyHold_BlockItemRemoval, BTL_TOKUSEI_StickyHold_ShowMessage, BTL_TOKUSEI_GetStickyHoldHandlers, BTL_TOKUSEI_GetPressureHandlers, BTL_TOKUSEI_Pressure_ShowAbilityMessage, BTL_TOKUSEI_Pressure_AddPPCost
 * address:  0x021DB650
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
 *   func_0689C8DC  0x0689C8DC  thumb
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_GetFactorPokeId  0x021D70AC  thumb  ov093
 *   gKlutzExemptItemIds     0x021F0B78  data   a2
 *   BTL_EVENT_SetFactorSkipCheck 0x021D7320 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_ClearFactorSkipCheck   0x021D7324  thumb
 *   BTL_POKEPARAM_GetItem 0x021D5B40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   gKlutzHandlers     0x021F0D9C  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   gStickyHoldHandlers     0x021F0AA0  data   ov093  a4
 *   gPressureHandlers     0x021F0AB8  data   ov093  a4
 */
#include "unit_021DB0E4_types.h"

/* Ability handlers: Klutz, Sticky Hold, Pressure. */

#define KLUTZ_EXEMPT_ITEM_COUNT 13
#define MOVE_NATURAL_GIFT 0x16B
#define MOVE_TRICK 0x10F
#define MOVE_SWITCHEROO 0x19F
#define BTL_FAIL_REASON_ITEM_UNUSABLE 0x13

/* The work area of a Klutz factor. */
typedef struct KlutzWork {
    int skipCheckSet;
    int pad04;
    int moveBlocked;
} KlutzWork;

extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *bpp);
extern u32 WAZA_TOOL_GetCategory(u16 moveId);
extern int func_0689C8DC(int moveId);

int BTL_TOKUSEI_Klutz_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key, u8 ownerId);
void BTL_TOKUSEI_Klutz_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void BTL_TOKUSEI_Klutz_InstallSkipCheckOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void BTL_TOKUSEI_Klutz_RemoveSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_Klutz_NoticeHeldItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_Klutz_BlockNaturalGift(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void BTL_TOKUSEI_Klutz_ShowBlockedMoveMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
const BtlEventHandler *BTL_TOKUSEI_GetKlutzHandlers(int *handlerCount);
void BTL_TOKUSEI_StickyHold_BlockTrick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_StickyHold_BlockItemRemoval(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending);
void BTL_TOKUSEI_StickyHold_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending);
const BtlEventHandler *BTL_TOKUSEI_GetStickyHoldHandlers(int *handlerCount);
const BtlEventHandler *BTL_TOKUSEI_GetPressureHandlers(int *handlerCount);
void BTL_TOKUSEI_Pressure_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void BTL_TOKUSEI_Pressure_AddPPCost(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern const u16 gKlutzExemptItemIds[];
extern const BtlEventHandler gKlutzHandlers[];
extern const BtlEventHandler gStickyHoldHandlers[];
extern const BtlEventHandler gPressureHandlers[];


/* Klutz skip check: item factors of the holder are skipped, except the items in the exempt list. */
int BTL_TOKUSEI_Klutz_SkipCheck(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key, u8 ownerId)
{
    u32 i;

    if (BTL_POKEPARAM_HasSick(func_021C7CF4(flow, ownerId), 0x10) != 0)
        return 0;
    if (factorType == 5 && ownerId == BTL_EVENT_GetFactorPokeId(other)) {
        for (i = 0; i < KLUTZ_EXEMPT_ITEM_COUNT; i++) {
            if (key == gKlutzExemptItemIds[i])
                return 0;
        }
        return 1;
    }
    return 0;
}


void BTL_TOKUSEI_Klutz_InstallSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (work->skipCheckSet == 0) {
        BTL_EVENT_SetFactorSkipCheck(factor, (u32)BTL_TOKUSEI_Klutz_SkipCheck);
        work->skipCheckSet = 1;
    }
}


void BTL_TOKUSEI_Klutz_InstallSkipCheckOnEntry(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_TOKUSEI_Klutz_InstallSkipCheck(factor, flow, pokeId, work);
}


void BTL_TOKUSEI_Klutz_RemoveSkipCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
        BTL_EVENT_ClearFactorSkipCheck(factor);
}


/* Klutz: tell the server flow that the held item of the holder changed its effect. */
void BTL_TOKUSEI_Klutz_NoticeHeldItem(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExPokeNotice *cmd;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_POKEPARAM_GetItem(func_021C7CF4(flow, pokeId))) {
        cmd = func_021C88A4(flow, HANDEX_POKE_NOTICE, pokeId);
        cmd->pokeId = pokeId;
        func_021C88C8(flow, cmd);
    }
}


/* Klutz: Natural Gift fails when the holder uses it. */
void BTL_TOKUSEI_Klutz_BlockNaturalGift(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        unsigned short moveId = (unsigned short)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        work->moveBlocked = 0;
        if (moveId == MOVE_NATURAL_GIFT && pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID))
            work->moveBlocked = BTL_EVENT_OverwriteVar(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ITEM_UNUSABLE);
    }
}


/* Klutz: show the message for the blocked move. */
void BTL_TOKUSEI_Klutz_ShowBlockedMoveMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && work->moveBlocked != 0) {
        BTL_EVENT_GetVar(BTL_EVAR_POKE_ID);
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&msg->str, 2, 0x389);
        func_021C8860(&msg->str, pokeId);
        func_021C8860(&msg->str, BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID));
        func_021C88C8(flow, msg);
        work->moveBlocked = 0;
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetKlutzHandlers(int *handlerCount)
{
    *handlerCount = 7;
    return gKlutzHandlers;
}


/* Sticky Hold: Trick and Switcheroo against the holder have no effect. */
void BTL_TOKUSEI_StickyHold_BlockTrick(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 moveId;
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_ID)) {
        moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
        if (moveId == MOVE_TRICK || moveId == MOVE_SWITCHEROO) {
            if (BTL_EVENT_OverwriteVar(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
                msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
                msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
                func_021C8838(&msg->str, 2, 0xd2);
                func_021C8860(&msg->str, pokeId);
                func_021C88C8(flow, msg);
            }
        }
    }
}


/* Sticky Hold: block the removal of the item of the holder when another poke causes it. */
void BTL_TOKUSEI_StickyHold_BlockItemRemoval(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && BTL_EVENT_GetVar(BTL_EVAR_SELF_CAUSED_FLAG) == 0)
        *messagePending = BTL_EVENT_OverwriteVar(BTL_EVAR_PREVENT_FLAG, 1);
}


void BTL_TOKUSEI_StickyHold_ShowMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID) && *messagePending != 0) {
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&msg->str, 2, 0x1ed);
        func_021C8860(&msg->str, pokeId);
        func_021C88C8(flow, msg);
        *messagePending = 0;
    }
}


const BtlEventHandler *BTL_TOKUSEI_GetStickyHoldHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gStickyHoldHandlers;
}


const BtlEventHandler *BTL_TOKUSEI_GetPressureHandlers(int *handlerCount)
{
    *handlerCount = 3;
    return gPressureHandlers;
}


/* Pressure: when the poke enters, show the ability window and the message. */
void BTL_TOKUSEI_Pressure_ShowAbilityMessage(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        func_021C88B4(flow, HANDEX_TOKWIN_IN, pokeId);
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        func_021C8838(&msg->str, 2, 0x1e7);
        func_021C8860(&msg->str, pokeId);
        func_021C88C8(flow, msg);
        func_021C88B4(flow, HANDEX_TOKWIN_OUT, pokeId);
    }
}


static inline void overwriteVarU8(int key, u8 value)
{
    BTL_EVENT_OverwriteVar(key, value);
}


/* Pressure: a move of an opposing poke costs one more PP. */
void BTL_TOKUSEI_Pressure_AddPPCost(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int extraCost;
    u16 moveId;

    if (func_021B9A24((u8)BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID), pokeId) == 0) {
        extraCost = 0;
        if (func_021E85F8(pokeId) != 0) {
            extraCost = 1;
        } else {
            moveId = BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID);
            if (WAZA_TOOL_GetCategory(moveId) == 10)
                extraCost = 1;
            else if (func_0689C8DC(moveId) != 0)
                extraCost = 1;
        }
        if (extraCost != 0)
            overwriteVarU8(BTL_EVAR_VOLUME, BTL_EVENT_GetVar(BTL_EVAR_VOLUME) + 1);
    }
}
