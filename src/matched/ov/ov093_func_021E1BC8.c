/*
 * function: HAND_WAZA_AddSnore
 * address: 0x021E1BC8
 * packet: pkt_ov093_021E1BC8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1B4C.c and filed here.
 *
 * symbols:
 *   gSnoreHandlers 0x021F2978 data ov093 a4
 */

int *HAND_WAZA_AddSnore(int *p);
extern int gSnoreHandlers[];

int *HAND_WAZA_AddSnore(int *p)
{
    *p = 2;
    return gSnoreHandlers;
}
