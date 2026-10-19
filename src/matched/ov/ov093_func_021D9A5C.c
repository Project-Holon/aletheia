/*
 * function: HAND_TOKUSEI_GetSereneGraceHandlers
 * address: 0x021D9A5C
 * packet: pkt_ov093_021D9A5C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gSimpleHandlers 0x021F0A88 data ov093 a4
 */

int *HAND_TOKUSEI_GetSereneGraceHandlers(int *p);
extern int gSimpleHandlers[];

int *HAND_TOKUSEI_GetSereneGraceHandlers(int *p)
{
    *p = 3;
    return gSimpleHandlers;
}
