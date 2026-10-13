/*
 * function: HAND_WAZA_AddMinimize
 * address: 0x021E6918
 * packet: pkt_ov093_021E6918
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
 *   gMinimizeHandlers 0x021F276C data ov093 a4
 */

int *HAND_WAZA_AddMinimize(int *p);
extern int gMinimizeHandlers[];

int *HAND_WAZA_AddMinimize(int *p)
{
    *p = 1;
    return gMinimizeHandlers;
}
