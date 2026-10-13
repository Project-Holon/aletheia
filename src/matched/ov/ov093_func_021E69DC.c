/*
 * function: HAND_WAZA_AddFocusPunch
 * address: 0x021E69DC
 * packet: pkt_ov093_021E69DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6994.c and filed here.
 *
 * symbols:
 *   gFocusPunchHandlers 0x021F2734 data ov093 a4
 */

extern int gFocusPunchHandlers[];
int *HAND_WAZA_AddFocusPunch(int *p);

int *HAND_WAZA_AddFocusPunch(int *p)
{
    *p = 1;
    return gFocusPunchHandlers;
}
