/*
 * function: HAND_WAZA_AddLastResort
 * address: 0x021E1B40
 * packet: pkt_ov093_021E1B40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E18EC.c and filed here.
 *
 * symbols:
 *   gLastResortHandlers 0x021F25C4 data ov093 a4
 */

int *HAND_WAZA_AddLastResort(int *p);
extern int gLastResortHandlers[];

int *HAND_WAZA_AddLastResort(int *p)
{
    *p = 1;
    return gLastResortHandlers;
}
