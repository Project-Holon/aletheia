/*
 * function: HAND_WAZA_AddPsywave
 * address: 0x021E15DC
 * packet: pkt_ov093_021E15DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E14E4.c and filed here.
 *
 * symbols:
 *   gPsywaveHandlers 0x021F2494 data ov093 a4
 */

int *HAND_WAZA_AddPsywave(int *p);
extern int gPsywaveHandlers[];

int *HAND_WAZA_AddPsywave(int *p)
{
    *p = 1;
    return gPsywaveHandlers;
}
