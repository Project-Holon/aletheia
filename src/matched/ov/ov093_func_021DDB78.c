/*
 * function: BTL_ITEM_GetWeakenDamagePoisonHandlers
 * address: 0x021DDB78
 * packet: pkt_ov093_021DDB78
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDB64.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamagePoisonHandlers 0x021F17BC data ov093 a4
 */

extern int gBtlItemWeakenDamagePoisonHandlers[];
int *BTL_ITEM_GetWeakenDamagePoisonHandlers(int *p);

int *BTL_ITEM_GetWeakenDamagePoisonHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamagePoisonHandlers;
}
