/*
 * function: HAND_ITEM_GetWeakenDamageGrassHandlers
 * address: 0x021DDB18
 * packet: pkt_ov093_021DDB18
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDB04.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageGrassHandlers 0x021F179C data ov093 a4
 */

extern int gBtlItemWeakenDamageGrassHandlers[];
int *HAND_ITEM_GetWeakenDamageGrassHandlers(int *p);

int *HAND_ITEM_GetWeakenDamageGrassHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageGrassHandlers;
}
