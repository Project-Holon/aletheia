/*
 * file:     unit_021DDBE4.c
 * function: BTL_ITEM_WeakenDamagePsychic, BTL_ITEM_GetWeakenDamageBugHandlers
 * address:  0x021DDBE4
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gBtlItemWeakenDamageBugHandlers     0x021F17EC  data   ov093  a4
 *   BTL_ITEM_WeakenDamagePsychic   0x021DDBE4  thumb
 *   BTL_HANDLER_ITEM_WeakenHitOfType   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xd; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl BTL_HANDLER_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DD588_types.h"

extern int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int gBtlItemWeakenDamageBugHandlers[];

void BTL_ITEM_WeakenDamagePsychic(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetWeakenDamageBugHandlers(int *handlerCount);

void BTL_ITEM_WeakenDamagePsychic(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_PSYCHIC, 0);
}

int *BTL_ITEM_GetWeakenDamageBugHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageBugHandlers;
}
