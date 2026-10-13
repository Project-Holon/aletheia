/*
 * file:     unit_021DDC64.c
 * function: BTL_HANDLER_ITEM_HabanBerryWeakenDragonHit, BTL_HANDLER_ITEM_GetColburBerryHandlers
 * address:  0x021DDC64
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gColburBerryHandlerTable     0x021F182C  data   ov093  a4
 *   BTL_HANDLER_ITEM_HabanBerryWeakenDragonHit   0x021DDC64  thumb
 *   BTL_HANDLER_ITEM_WeakenHitOfType   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xf; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl BTL_HANDLER_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DDC44_types.h"

extern int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity);
extern int gColburBerryHandlerTable[];

void BTL_HANDLER_ITEM_HabanBerryWeakenDragonHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *BTL_HANDLER_ITEM_GetColburBerryHandlers(int *handlerCount);

/* Haban Berry: halves a Dragon-type hit that is super effective. */
void BTL_HANDLER_ITEM_HabanBerryWeakenDragonHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_DRAGON, 0);
}

/* Handler table getter of Colbur Berry. */
int *BTL_HANDLER_ITEM_GetColburBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gColburBerryHandlerTable;
}
