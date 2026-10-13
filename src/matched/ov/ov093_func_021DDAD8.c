/*
 * function: HAND_ITEM_GetWeakenDamageWaterHandlers
 * address: 0x021DDAD8
 * packet: pkt_ov093_021DDAD8
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDAC4.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageWaterHandlers 0x021F177C data ov093 a4
 */

extern int gBtlItemWeakenDamageWaterHandlers[];
int *HAND_ITEM_GetWeakenDamageWaterHandlers(int *p);

int *HAND_ITEM_GetWeakenDamageWaterHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageWaterHandlers;
}
