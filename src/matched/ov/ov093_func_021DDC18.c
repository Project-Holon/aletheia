/*
 * function: BTL_ITEM_GetWeakenDamageRockHandlers
 * address: 0x021DDC18
 * packet: pkt_ov093_021DDC18
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDC04.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageRockHandlers 0x021F17FC data ov093 a4
 */

extern int gBtlItemWeakenDamageRockHandlers[];
int *BTL_ITEM_GetWeakenDamageRockHandlers(int *p);

int *BTL_ITEM_GetWeakenDamageRockHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageRockHandlers;
}
