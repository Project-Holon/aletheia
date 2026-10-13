/*
 * file:     unit_021DF370.c
 * function: BTL_HANDLER_ITEM_BigRoot_BoostDrain, BTL_HANDLER_ITEM_GetSmokeBallHandlers, BTL_HANDLER_ITEM_SmokeBall_AllowEscape
 * address:  0x021DF370
 * packet:   pkt_ov093_021DF370
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   BTLV_CORE_EventSetFlagIfAttacker  0x021E8878  thumb  ov093
 *   d_021F15FC     0x021F15FC  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_HANDLER_ITEM_GetBoostRatio  0x021DD008  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_HANDLER_ITEM_GetBoostRatio(struct BtlEventFactor *factor);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern void BTLV_CORE_EventSetFlagIfAttacker(struct BtlEventFactor *factor, void *flow, int pokeId, void *work);
extern int d_021F15FC[];

/* Big Root: the holder's draining move recovers more HP, by the item's ratio. */
void BTL_HANDLER_ITEM_BigRoot_BoostDrain(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, BTL_HANDLER_ITEM_GetBoostRatio(factor));
}

int *BTL_HANDLER_ITEM_GetSmokeBallHandlers(int *count)
{
    *count = 2;
    return d_021F15FC;
}

/* Smoke Ball: guaranteed escape; forwards to the shared escape check (the second handler of the item is in the next file). */
void BTL_HANDLER_ITEM_SmokeBall_AllowEscape(struct BtlEventFactor *factor, void *flow, int pokeId, void *work)
{
    BTLV_CORE_EventSetFlagIfAttacker(factor, flow, pokeId, work);
}
