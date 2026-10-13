/*
 * function: HAND_TOKUSEI_GetTelepathyHandlers
 * address: 0x021DC320
 * packet: pkt_ov093_021DC320
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC13C.c and filed here.
 *
 * symbols:
 *   gTelepathyHandlers 0x021F05E8 data ov093 a4
 */

int *HAND_TOKUSEI_GetTelepathyHandlers(int *p);
extern int gTelepathyHandlers[];

int *HAND_TOKUSEI_GetTelepathyHandlers(int *p)
{
    *p = 1;
    return gTelepathyHandlers;
}
