/*
 * function: HAND_TOKUSEI_GetInnerFocusHandlers
 * address: 0x021D8678
 * packet: pkt_ov093_021D8678
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8434.c and filed here.
 *
 * symbols:
 *   gInnerFocusHandlers 0x021F0710 data ov093 a4
 */

extern int gInnerFocusHandlers[];
int *HAND_TOKUSEI_GetInnerFocusHandlers(int *p);

int *HAND_TOKUSEI_GetInnerFocusHandlers(int *p)
{
    *p = 1;
    return gInnerFocusHandlers;
}
