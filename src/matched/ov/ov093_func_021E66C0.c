/*
 * function: HAND_WAZA_AddDestinyBond
 * address: 0x021E66C0
 * packet: pkt_ov093_021E66C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E65B0_p01.c and filed here.
 *
 * symbols:
 *   gDestinyBondHandlers 0x021F2B40 data ov093 a4
 */

int *HAND_WAZA_AddDestinyBond(int *p);
extern int gDestinyBondHandlers[];

int *HAND_WAZA_AddDestinyBond(int *p)
{
    *p = 3;
    return gDestinyBondHandlers;
}
