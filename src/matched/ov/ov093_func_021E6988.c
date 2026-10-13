/*
 * function: HAND_WAZA_AddRoost
 * address: 0x021E6988
 * packet: pkt_ov093_021E6988
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E65B0_p03.c and filed here.
 *
 * symbols:
 *   gRoostHandlers 0x021F255C data ov093 a4
 */

int *HAND_WAZA_AddRoost(int *p);
extern int gRoostHandlers[];

int *HAND_WAZA_AddRoost(int *p)
{
    *p = 1;
    return gRoostHandlers;
}
