/*
 * function: HAND_WAZA_AddGrudge
 * address: 0x021E67F4
 * packet: pkt_ov093_021E67F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E65B0_p02.c and filed here.
 *
 * symbols:
 *   gGrudgeHandlers 0x021F2B58 data ov093 a4
 */

extern int gGrudgeHandlers[];
int *HAND_WAZA_AddGrudge(int *p);

int *HAND_WAZA_AddGrudge(int *p)
{
    *p = 3;
    return gGrudgeHandlers;
}
