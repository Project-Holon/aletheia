/*
 * function: HAND_TOKUSEI_GetGutsHandlers
 * address: 0x021D8D34
 * packet: pkt_ov093_021D8D34
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
 *   gGutsHandlers 0x021F0638 data ov093 a4
 */

int *HAND_TOKUSEI_GetGutsHandlers(int *p);
extern int gGutsHandlers[];

int *HAND_TOKUSEI_GetGutsHandlers(int *p)
{
    *p = 1;
    return gGutsHandlers;
}
