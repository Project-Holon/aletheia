/*
 * function: HAND_WAZA_PursuitGetHandlers
 * address: 0x021E1D14
 * packet: pkt_ov093_021E1D14
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1C8C.c and filed here.
 *
 * symbols:
 *   gPursuitHandlers 0x021F2C48 data ov093 a4
 */

int *HAND_WAZA_PursuitGetHandlers(int *p);
extern int gPursuitHandlers[];

int *HAND_WAZA_PursuitGetHandlers(int *p)
{
    *p = 3;
    return gPursuitHandlers;
}
