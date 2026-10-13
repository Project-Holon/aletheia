/*
 * file:     unit_021DCA98.c
 * function: func_021DCA98, func_021DCACC, func_021DCAD8, func_021DCAE0
 * address:  0x021DCA98
 * packet:   pkt_ov093_021DCA98
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E8798  0x021E8798  thumb  ov093
 *   func_021E8744  0x021E8744  thumb  ov093
 *   d_021F0630     0x021F0630  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
#include "unit_021DC6EC_types.h"

extern BtlEventHandler d_021F0630[];

void func_021DCA98(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *func_021DCACC(u32 *handlerCount);
void func_021DCAD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void func_021DCAE0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);

/* Prankster: the owner's status moves get one priority step. */
void func_021DCA98(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    u8 priority;

    if (ownerId == func_021D775C(BTL_EVAR_ATTACKER_ID) && WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_STATUS) {
        priority = func_021D775C(BTL_EVAR_MOVE_PRIORITY);
        func_021D76BC(BTL_EVAR_MOVE_PRIORITY, priority + 1);
    }
}

BtlEventHandler *func_021DCACC(u32 *handlerCount)
{
    *handlerCount = 1;
    return d_021F0630;
}

/* Magic Bounce: the first of its two handlers is the one that Magic Coat uses to reflect a status move. */
void func_021DCAD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    func_021E8744(factor, flow, ownerId, work);
}

/* Magic Bounce: the second handler is the one that Magic Coat uses to counter a status move aimed at the owner. */
void func_021DCAE0(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    func_021E8798(factor, flow, ownerId, work);
}
