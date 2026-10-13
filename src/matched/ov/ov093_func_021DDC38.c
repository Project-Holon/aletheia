/*
 * function: HAND_ITEM_GetWeakenDamageGhostHandlers
 * address: 0x021DDC38
 * packet: pkt_ov093_021DDC38
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDC24.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageGhostHandlers 0x021F180C data ov093 a4
 */

extern int gBtlItemWeakenDamageGhostHandlers[];
int *HAND_ITEM_GetWeakenDamageGhostHandlers(int *p);

int *HAND_ITEM_GetWeakenDamageGhostHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageGhostHandlers;
}
