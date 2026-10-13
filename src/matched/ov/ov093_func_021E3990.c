/*
 * function: HAND_WAZA_GetSurfHandlers
 * address: 0x021E3990
 * packet: pkt_ov093_021E3990
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E396C.c and filed here.
 *
 * symbols:
 *   gSurfHandlers 0x021F2AB8 data ov093 a4
 */

int *HAND_WAZA_GetSurfHandlers(int *p);
extern int gSurfHandlers[];

int *HAND_WAZA_GetSurfHandlers(int *p)
{
    *p = 2;
    return gSurfHandlers;
}
