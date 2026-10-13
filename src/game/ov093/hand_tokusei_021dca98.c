/*
 * file:     hand_tokusei_021dca98.c
 * function: HAND_TOKUSEI_PranksterRaiseStatusPriority, HAND_TOKUSEI_GetPranksterHandlers, HAND_TOKUSEI_MagicBounceReflectMove, HAND_TOKUSEI_MagicBounceCounterMove
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
#include "hand_tokusei_021dc6ec_types.h"

extern BtlEventHandler gPranksterHandlers[];

void HAND_TOKUSEI_PranksterRaiseStatusPriority(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
BtlEventHandler *HAND_TOKUSEI_GetPranksterHandlers(u32 *handlerCount);
void HAND_TOKUSEI_MagicBounceReflectMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);
void HAND_TOKUSEI_MagicBounceCounterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work);

/* Prankster: the owner's status moves get one priority step. */
void HAND_TOKUSEI_PranksterRaiseStatusPriority(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    u8 priority;

    if (ownerId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID) && WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_STATUS) {
        priority = BTL_EVENT_GetVar(BTL_EVAR_MOVE_PRIORITY);
        BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_PRIORITY, priority + 1);
    }
}

BtlEventHandler *HAND_TOKUSEI_GetPranksterHandlers(u32 *handlerCount)
{
    *handlerCount = 1;
    return gPranksterHandlers;
}

/* Magic Bounce: the first of its two handlers is the one that Magic Coat uses to reflect a status move. */
void HAND_TOKUSEI_MagicBounceReflectMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BTLV_CORE_EventRedirectMove(factor, flow, ownerId, work);
}

/* Magic Bounce: the second handler is the one that Magic Coat uses to counter a status move aimed at the owner. */
void HAND_TOKUSEI_MagicBounceCounterMove(struct BtlEventFactor *factor, struct BtlSvFlow *flow, u8 ownerId, void *work)
{
    BTLV_CORE_EventCounterMove(factor, flow, ownerId, work);
}
