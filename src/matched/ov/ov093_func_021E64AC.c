/*
 * function: HAND_WAZA_AddRazorWind
 * address: 0x021E64AC
 * packet: pkt_ov093_021E64AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E63BC.c and filed here.
 *
 * symbols:
 *   gRazorWindHandlers 0x021F27D4 data ov093 a4
 */

int *HAND_WAZA_AddRazorWind(int *p);
extern int gRazorWindHandlers[];

int *HAND_WAZA_AddRazorWind(int *p)
{
    *p = 1;
    return gRazorWindHandlers;
}
