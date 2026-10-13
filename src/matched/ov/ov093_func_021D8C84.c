/*
 * function: HAND_TOKUSEI_GetOvergrowHandlers
 * address: 0x021D8C84
 * packet: pkt_ov093_021D8C84
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8B50.c and filed here.
 *
 * symbols:
 *   gOvergrowHandlers 0x021F0648 data ov093 a4
 */

int *HAND_TOKUSEI_GetOvergrowHandlers(int *p);
extern int gOvergrowHandlers[];

int *HAND_TOKUSEI_GetOvergrowHandlers(int *p)
{
    *p = 1;
    return gOvergrowHandlers;
}
