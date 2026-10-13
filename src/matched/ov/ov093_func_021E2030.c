/*
 * function: HAND_WAZA_PayDayGetHandlers
 * address: 0x021E2030
 * packet: pkt_ov093_021E2030
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1E44.c and filed here.
 *
 * symbols:
 *   gPayDayHandlers 0x021F247C data ov093 a4
 */

int *HAND_WAZA_PayDayGetHandlers(int *p);
extern int gPayDayHandlers[];

int *HAND_WAZA_PayDayGetHandlers(int *p)
{
    *p = 1;
    return gPayDayHandlers;
}
