/*
 * function: HAND_TOKUSEI_GetBlazeHandlers
 * address: 0x021D8C4C
 * packet: pkt_ov093_021D8C4C
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
 *   gBlazeHandlers 0x021F06B0 data ov093 a4
 */

int *HAND_TOKUSEI_GetBlazeHandlers(int *p);
extern int gBlazeHandlers[];

int *HAND_TOKUSEI_GetBlazeHandlers(int *p)
{
    *p = 1;
    return gBlazeHandlers;
}
