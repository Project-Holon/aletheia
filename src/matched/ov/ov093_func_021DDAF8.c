/*
 * function: HAND_ITEM_GetWeakenDamageElectricHandlers
 * address: 0x021DDAF8
 * packet: pkt_ov093_021DDAF8
 * region: ov093
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DDAE4.c and filed here.
 *
 * symbols:
 *   gBtlItemWeakenDamageElectricHandlers 0x021F178C data ov093 a4
 */

extern int gBtlItemWeakenDamageElectricHandlers[];
int *HAND_ITEM_GetWeakenDamageElectricHandlers(int *p);

int *HAND_ITEM_GetWeakenDamageElectricHandlers(int *p)
{
    *p = 2;
    return gBtlItemWeakenDamageElectricHandlers;
}
