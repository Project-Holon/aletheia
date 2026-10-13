/*
 * function: HAND_WAZA_GetEncoreHandlers
 * address: 0x021E467C
 * packet: pkt_ov093_021E467C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4340_p01.c and filed here.
 *
 * symbols:
 *   gEncoreHandlers 0x021F25E4 data ov093 a4
 */

int *HAND_WAZA_GetEncoreHandlers(int *p);
extern int gEncoreHandlers[];

int *HAND_WAZA_GetEncoreHandlers(int *p)
{
    *p = 1;
    return gEncoreHandlers;
}
