/*
 * file:     unit_021DDC44.c
 * function: BTL_HANDLER_ITEM_KasibBerryWeakenGhostHit, BTL_HANDLER_ITEM_GetHabanBerryHandlers
 * address:  0x021DDC44
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gHabanBerryHandlerTable     0x021F181C  data   ov093  a4
 *   BTL_HANDLER_ITEM_KasibBerryWeakenGhostHit   0x021DDC44  thumb
 *   BTL_HANDLER_ITEM_WeakenHitOfType   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #7; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl BTL_HANDLER_ITEM_WeakenHitOfType; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DDC44_types.h"

extern int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity);
extern int gHabanBerryHandlerTable[];

void BTL_HANDLER_ITEM_KasibBerryWeakenGhostHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *BTL_HANDLER_ITEM_GetHabanBerryHandlers(int *handlerCount);

/* Kasib Berry: halves a Ghost hit that is super effective. */
void BTL_HANDLER_ITEM_KasibBerryWeakenGhostHit(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, flow, pokeId, work, POKETYPE_GHOST, 0);
}

/* Handler table getter of Haban Berry. */
int *BTL_HANDLER_ITEM_GetHabanBerryHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gHabanBerryHandlerTable;
}
