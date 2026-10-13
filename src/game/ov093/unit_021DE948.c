/*
 * file:     unit_021DE948.c
 * unit: yes
 * function: BTL_HANDLER_ITEM_ChoiceBand_BoostAttack, BTL_HANDLER_ITEM_GetChoiceSpecsHandlers
 * address: 0x021DE948
 * packet: pkt_ov093_021DE948
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes store-return follower 0x021DE974.
 * symbols:
 *   d_021F18EC 0x021F18EC data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 */
#include "unit_021DE7E4_types.h"

struct BtlEventFactor;

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int multiplier);
extern int WAZA_TOOL_GetDamageType(int moveId);
extern int d_021F18EC;

/* Choice Band: 1.5 times power for physical moves. */
void BTL_HANDLER_ITEM_ChoiceBand_BoostAttack(struct BtlEventFactor *factor, void *flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)BTL_EVENT_GetVar(BTL_EVAR_MOVE_ID)) == 1)
            BTL_EVENT_MultiplyVar(BTL_EVAR_POWER_RATIO, 6144);
    }
}

int *BTL_HANDLER_ITEM_GetChoiceSpecsHandlers(int *count)
{
    *count = 3;
    return &d_021F18EC;
}
