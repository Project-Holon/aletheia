/*
 * file:     unit_021DDAE4.c
 * function: BTL_ITEM_WeakenDamageWater, BTL_ITEM_GetWeakenDamageElectricHandlers
 * address:  0x021DDAE4
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBtlItemWeakenDamageElectricHandlers     0x021F178C  data   ov093  a4
 *   BTL_ITEM_WeakenDamageWater   0x021DDAE4  thumb
 *   BTL_HANDLER_ITEM_WeakenHitOfType   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xa; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl BTL_HANDLER_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DD588_types.h"

extern int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int gBtlItemWeakenDamageElectricHandlers[];

void BTL_ITEM_WeakenDamageWater(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetWeakenDamageElectricHandlers(int *handlerCount);

void BTL_ITEM_WeakenDamageWater(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_WATER, 0);
}

int *BTL_ITEM_GetWeakenDamageElectricHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageElectricHandlers;
}
