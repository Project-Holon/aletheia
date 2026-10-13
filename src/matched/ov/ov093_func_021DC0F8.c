/*
 * function: HAND_TOKUSEI_GetDefeatistHandlers
 * address: 0x021DC0F8
 * packet: pkt_ov093_021DC0F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC0BC.c and filed here.
 *
 * symbols:
 *   gDefeatistHandlers 0x021F07A8 data ov093 a4
 */

int *HAND_TOKUSEI_GetDefeatistHandlers(int *p);
extern int gDefeatistHandlers[];

int *HAND_TOKUSEI_GetDefeatistHandlers(int *p)
{
    *p = 1;
    return gDefeatistHandlers;
}
