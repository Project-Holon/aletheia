/*
 * function: HAND_WAZA_GetFakeOutHandlers
 * address: 0x021E6120
 * packet: pkt_ov093_021E6120
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5B78.c and filed here.
 *
 * symbols:
 *   gFakeOutHandlers 0x021F242C data ov093 a4
 */

int *HAND_WAZA_GetFakeOutHandlers(int *p);
extern int gFakeOutHandlers[];

int *HAND_WAZA_GetFakeOutHandlers(int *p)
{
    *p = 1;
    return gFakeOutHandlers;
}
