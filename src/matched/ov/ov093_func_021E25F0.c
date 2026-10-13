/*
 * function: HAND_WAZA_RolloutGetHandlers
 * address: 0x021E25F0
 * packet: pkt_ov093_021E25F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E2188.c and filed here.
 *
 * symbols:
 *   gRolloutHandlers 0x021F2EA0 data ov093 a4
 */

int *HAND_WAZA_RolloutGetHandlers(int *p);
extern int gRolloutHandlers[];

int *HAND_WAZA_RolloutGetHandlers(int *p)
{
    *p = 5;
    return gRolloutHandlers;
}
