/*
 * file:     unit_021DCA98.c
 * function: BTL_ABILITY_PranksterRaiseStatusPriority, BTL_ABILITY_GetPranksterHandlers, BTL_ABILITY_MagicBounceReflectMove, BTL_ABILITY_MagicBounceCounterMove
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
 *   BTLV_CORE_EventCounterMove  0x021E8798  thumb  ov093
 *   BTLV_CORE_EventRedirectMove  0x021E8744  thumb  ov093
 *   gPranksterHandlers     0x021F0630  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
#include "unit_021DC6EC_types.h"

extern BtlEventHandler gPranksterHandlers[];

void BTL_ABILITY_PranksterRaiseStatusPriority(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *BTL_ABILITY_GetPranksterHandlers(u32 *handlerCount);
void BTL_ABILITY_MagicBounceReflectMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void BTL_ABILITY_MagicBounceCounterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);

/* Prankster: the owner's status moves get one priority step. */
void BTL_ABILITY_PranksterRaiseStatusPriority(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    u8 priority;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_STATUS) {
        priority = BTL_EVENT_GetVar(BTL_EVAR_MOVE_PRIORITY);
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_PRIORITY, priority + 1);
    }
}

BtlEventHandler *BTL_ABILITY_GetPranksterHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gPranksterHandlers;
}

/* Magic Bounce: the first of its two handlers is the one that Magic Coat uses to reflect a status move. */
void BTL_ABILITY_MagicBounceReflectMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BTLV_CORE_EventRedirectMove(factor, flow, ownerId, work);
}

/* Magic Bounce: the second handler is the one that Magic Coat uses to counter a status move aimed at the owner. */
void BTL_ABILITY_MagicBounceCounterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BTLV_CORE_EventCounterMove(factor, flow, ownerId, work);
}
