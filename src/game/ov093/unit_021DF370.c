/*
 * file:     unit_021DF370.c
 * function: func_021DF370, func_021DF390, func_021DF39C
 * address:  0x021DF370
 * packet:   pkt_ov093_021DF370
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021E8878  0x021E8878  thumb  ov093
 *   d_021F15FC     0x021F15FC  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int func_021D775C(int key);
extern int func_021DD008(struct BtlEventFactor *factor);
extern void func_021D7704(int key, int multiplier);
extern void func_021E8878(struct BtlEventFactor *factor, void *flow, int pokeId, void *work);
extern int d_021F15FC[];

/* Big Root: the holder's draining move recovers more HP, by the item's ratio. */
void func_021DF370(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID))
        func_021D7704(BTL_EVAR_POWER_RATIO, func_021DD008(factor));
}

int *func_021DF390(int *count)
{
    *count = 2;
    return d_021F15FC;
}

/* Smoke Ball: guaranteed escape; forwards to the shared escape check (the second handler of the item is in the next file). */
void func_021DF39C(struct BtlEventFactor *factor, void *flow, int pokeId, void *work)
{
    func_021E8878(factor, flow, pokeId, work);
}
