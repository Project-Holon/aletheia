/*
 * file:     unit_021DB650.c
 * unit:     yes
 * function: func_021DB650, func_021DB6A4, func_021DB6C0, func_021DB6E4, func_021DB6FC, func_021DB734, func_021DB774, func_021DB7DC, func_021DB7E8, func_021DB854, func_021DB87C, func_021DB8D0, func_021DB8DC, func_021DB8E8, func_021DB93C
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
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D70AC  0x021D70AC  thumb  ov093
 *   d_021F0B78     0x021F0B78  data   a2
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7324   0x021D7324  thumb
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F0D9C     0x021F0D9C  data   ov093  a4
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   WAZA_TOOL_GetCategory   0x0201C1BC  thumb
 *   d_021F0AA0     0x021F0AA0  data   ov093  a4
 *   d_021F0AB8     0x021F0AB8  data   ov093  a4
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

extern int func_021D62C4(struct BtlPokeParam *bpp, int sickId);
extern u16 func_021D5B40(struct BtlPokeParam *bpp);
extern u32 WAZA_TOOL_GetCategory(u16 moveId);
extern int func_0689C8DC(int moveId);

int func_021DB650(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key, u8 ownerId);
void func_021DB6A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void func_021DB6C0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void func_021DB6E4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB6FC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB734(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
void func_021DB774(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work);
const BtlEventHandler *func_021DB7DC(int *handlerCount);
void func_021DB7E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB854(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending);
void func_021DB87C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending);
const BtlEventHandler *func_021DB8D0(int *handlerCount);
const BtlEventHandler *func_021DB8DC(int *handlerCount);
void func_021DB8E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DB93C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
extern const u16 d_021F0B78[];
extern const BtlEventHandler d_021F0D9C[];
extern const BtlEventHandler d_021F0AA0[];
extern const BtlEventHandler d_021F0AB8[];


/* Klutz skip check: item factors of the holder are skipped, except the items in the exempt list. */
int func_021DB650(struct BtlEventFactor *other, struct BtlSvFlow *flow, int factorType, int eventId, unsigned short key, u8 ownerId)
{
    u32 i;

    if (func_021D62C4(func_021C7CF4(flow, ownerId), 0x10) != 0)
        return 0;
    if (factorType == 5 && ownerId == func_021D70AC(other)) {
        for (i = 0; i < KLUTZ_EXEMPT_ITEM_COUNT; i++) {
            if (key == d_021F0B78[i])
                return 0;
        }
        return 1;
    }
    return 0;
}


void func_021DB6A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (work->skipCheckSet == 0) {
        func_021D7320(factor, (u32)func_021DB650);
        work->skipCheckSet = 1;
    }
}


void func_021DB6C0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021DB6A4(factor, flow, pokeId, work);
}


void func_021DB6E4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021D7324(factor);
}


/* Klutz: tell the server flow that the held item of the holder changed its effect. */
void func_021DB6FC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExPokeNotice *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021D5B40(func_021C7CF4(flow, pokeId))) {
        cmd = func_021C88A4(flow, HANDEX_POKE_NOTICE, pokeId);
        cmd->pokeId = pokeId;
        func_021C88C8(flow, cmd);
    }
}


/* Klutz: Natural Gift fails when the holder uses it. */
void func_021DB734(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        unsigned short moveId = (unsigned short)func_021D775C(BTL_EVAR_MOVE_ID);
        work->moveBlocked = 0;
        if (moveId == MOVE_NATURAL_GIFT && pokeId == func_021D775C(BTL_EVAR_POKE_ID))
            work->moveBlocked = func_021D76BC(BTL_EVAR_FAIL_REASON, BTL_FAIL_REASON_ITEM_UNUSABLE);
    }
}


/* Klutz: show the message for the blocked move. */
void func_021DB774(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, KlutzWork *work)
{
    HandExMessage *msg;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && work->moveBlocked != 0) {
        func_021D775C(BTL_EVAR_POKE_ID);
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&msg->str, 2, 0x389);
        func_021C8860(&msg->str, pokeId);
        func_021C8860(&msg->str, func_021D775C(BTL_EVAR_MOVE_ID));
        func_021C88C8(flow, msg);
        work->moveBlocked = 0;
    }
}


const BtlEventHandler *func_021DB7DC(int *handlerCount)
{
    *handlerCount = 7;
    return d_021F0D9C;
}


/* Sticky Hold: Trick and Switcheroo against the holder have no effect. */
void func_021DB7E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u16 moveId;
    HandExMessage *msg;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        moveId = func_021D775C(BTL_EVAR_MOVE_ID);
        if (moveId == MOVE_TRICK || moveId == MOVE_SWITCHEROO) {
            if (func_021D76BC(BTL_EVAR_NO_EFFECT_FLAG, 1) != 0) {
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
void func_021DB854(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && func_021D775C(BTL_EVAR_SELF_CAUSED_FLAG) == 0)
        *messagePending = func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1);
}


void func_021DB87C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *messagePending)
{
    HandExMessage *msg;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID) && *messagePending != 0) {
        msg = func_021C88A4(flow, HANDEX_MESSAGE, pokeId);
        msg->header |= BTL_CMD_FLAG_FROM_ABILITY;
        func_021C8838(&msg->str, 2, 0x1ed);
        func_021C8860(&msg->str, pokeId);
        func_021C88C8(flow, msg);
        *messagePending = 0;
    }
}


const BtlEventHandler *func_021DB8D0(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0AA0;
}


const BtlEventHandler *func_021DB8DC(int *handlerCount)
{
    *handlerCount = 3;
    return d_021F0AB8;
}


/* Pressure: when the poke enters, show the ability window and the message. */
void func_021DB8E8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    HandExMessage *msg;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
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
    func_021D76BC(key, value);
}


/* Pressure: a move of an opposing poke costs one more PP. */
void func_021DB93C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    int extraCost;
    u16 moveId;

    if (func_021B9A24((u8)func_021D775C(BTL_EVAR_ATTACKER_ID), pokeId) == 0) {
        extraCost = 0;
        if (func_021E85F8(pokeId) != 0) {
            extraCost = 1;
        } else {
            moveId = func_021D775C(BTL_EVAR_MOVE_ID);
            if (WAZA_TOOL_GetCategory(moveId) == 10)
                extraCost = 1;
            else if (func_0689C8DC(moveId) != 0)
                extraCost = 1;
        }
        if (extraCost != 0)
            overwriteVarU8(BTL_EVAR_VOLUME, func_021D775C(BTL_EVAR_VOLUME) + 1);
    }
}
