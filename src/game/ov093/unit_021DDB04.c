/*
 * file:     unit_021DDB04.c
 * function: BTL_ITEM_WeakenDamageElectric, BTL_ITEM_GetWeakenDamageGrassHandlers
 * address:  0x021DDB04
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBtlItemWeakenDamageGrassHandlers     0x021F179C  data   ov093  a4
 *   BTL_ITEM_WeakenDamageElectric   0x021DDB04  thumb
 *   BTL_HANDLER_ITEM_WeakenHitOfType   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xc; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl BTL_HANDLER_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DD588_types.h"

extern int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int gBtlItemWeakenDamageGrassHandlers[];

void BTL_ITEM_WeakenDamageElectric(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetWeakenDamageGrassHandlers(int *handlerCount);

void BTL_ITEM_WeakenDamageElectric(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_ELECTRIC, 0);
}

int *BTL_ITEM_GetWeakenDamageGrassHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageGrassHandlers;
}
