/*
 * file:     unit_021DF3A4.c
 * unit:     yes
 * function: func_021DF3A4, func_021DF3F8, func_021DF404, func_021DF420, func_021DF42C, func_021DF438, func_021DF480
 * address:  0x021DF3A4
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
 *   func_021E889C  0x021E889C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C888C  0x021C888C  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C8408  0x021C8408  thumb  ov093
 *   d_021F161C     0x021F161C  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   d_021F1534     0x021F1534  data   ov093  a4
 *   d_021F145C     0x021F145C  data   ov093  a4
 */
#include "unit_021DF3A4_types.h"

extern const BtlEventHandler d_021F161C[];
extern const BtlEventHandler d_021F1534[];
extern const BtlEventHandler d_021F145C[];

void func_021DF3A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF3F8(int *handlerCount);
void func_021DF404(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021DF420(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF42C(int *handlerCount);
void func_021DF438(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DF480(int *handlerCount);

/* Smoke Ball (guess): after the escape check passes, show the escape message with its sound. */
void func_021DF3A4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    TokuseiMessageCmd *msg;

    if (func_021E889C(factor, flow, pokeId) != 0) {
        msg = (TokuseiMessageCmd *)func_021C88A4(flow, BTL_CMD_KIND_MESSAGE, pokeId);
        func_021C8838(&msg->strParam, BTL_STR_TYPE_STANDARD, 0x3ec);
        func_021C8860(&msg->strParam, pokeId);
        func_021C8860(&msg->strParam, func_021D70A8(factor));
        func_021C888C(&msg->strParam, 0x56a);
        func_021C88C8(flow, msg);
    }
}

/* Amulet Coin and Luck Incense: two entries. */
const BtlEventHandler *func_021DF3F8(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F161C;
}

/* Amulet Coin: when the holder enters, flag the prize money as doubled. */
void func_021DF404(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID))
        func_021C8408(flow, pokeId);
}

/*
 * Amulet Coin: the same flag again at the second enter event, without the
 * holder check.
 */
void func_021DF420(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021C8408(flow, pokeId);
}

const BtlEventHandler *func_021DF42C(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F1534;
}

/* Griseous Orb: 1.2 times power for Dragon and Ghost moves of a Giratina. */
void func_021DF438(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId != func_021D775C(BTL_EVAR_ATTACKER_ID))
        return;
    if (func_021D5444(func_021C7CF4(flow, pokeId)) != BTL_SPECIES_GIRATINA)
        return;
    moveType = func_021D775C(BTL_EVAR_MOVE_TYPE);
    if (moveType == BTL_TYPE_DRAGON || moveType == BTL_TYPE_GHOST)
        func_021D7704(BTL_EVAR_MOVE_POWER_RATIO, 0x1333);
}

const BtlEventHandler *func_021DF480(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F145C;
}
