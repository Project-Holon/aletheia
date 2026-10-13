/*
 * function: HAND_TOKUSEI_GetUnawareHandlers
 * address: 0x021DA838
 * packet: pkt_ov093_021DA838
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624_p01.c and filed here.
 *
 * symbols:
 *   gUnawareHandlers 0x021F0B18 data ov093 a4
 */

int *HAND_TOKUSEI_GetUnawareHandlers(int *p);
extern int gUnawareHandlers[];

int *HAND_TOKUSEI_GetUnawareHandlers(int *p)
{
    *p = 3;
    return gUnawareHandlers;
}
