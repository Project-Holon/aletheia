/*
 * function: HAND_ITEM_GetWeakenDamageGroundHandlers
 * address: 0x021DDB98
 * packet: pkt_ov093_021DDB98
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDB84.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageGroundHandlers 0x021F17CC data ov093 a4
 */

extern int gBtlItemWeakenDamageGroundHandlers[];
int *HAND_ITEM_GetWeakenDamageGroundHandlers(int *p);

int *HAND_ITEM_GetWeakenDamageGroundHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageGroundHandlers;
}
