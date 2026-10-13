/*
 * function: BTL_ITEM_GetWeakenDamageFireHandlers
 * address: 0x021DDAB8
 * packet: pkt_ov093_021DDAB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DD87C.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageFireHandlers 0x021F175C data ov093 a4
 */

int *BTL_ITEM_GetWeakenDamageFireHandlers(int *p);
extern int gBtlItemWeakenDamageFireHandlers[];

int *BTL_ITEM_GetWeakenDamageFireHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageFireHandlers;
}
