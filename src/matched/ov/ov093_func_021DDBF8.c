/*
 * function: BTL_ITEM_GetWeakenDamageBugHandlers
 * address: 0x021DDBF8
 * packet: pkt_ov093_021DDBF8
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDBE4.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageBugHandlers 0x021F17EC data ov093 a4
 */

extern int gBtlItemWeakenDamageBugHandlers[];
int *BTL_ITEM_GetWeakenDamageBugHandlers(int *p);

int *BTL_ITEM_GetWeakenDamageBugHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageBugHandlers;
}
