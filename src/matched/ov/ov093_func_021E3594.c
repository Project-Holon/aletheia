/*
 * function: HAND_WAZA_AddSnatch
 * address: 0x021E3594
 * packet: pkt_ov093_021E3594
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E3420.c and filed here.
 *
 * symbols:
 *   gSnatchHandlers 0x021F2E38 data ov093 a4
 */

int *HAND_WAZA_AddSnatch(int *p);
extern int gSnatchHandlers[];

int *HAND_WAZA_AddSnatch(int *p)
{
    *p = 4;
    return gSnatchHandlers;
}
