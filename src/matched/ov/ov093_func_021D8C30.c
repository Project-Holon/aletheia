/*
 * function: HAND_TOKUSEI_GetAdaptabilityHandlers
 * address: 0x021D8C30
 * packet: pkt_ov093_021D8C30
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
 *   gAdaptabilityHandlers 0x021F07D8 data ov093 a4
 */

int *HAND_TOKUSEI_GetAdaptabilityHandlers(int *p);
extern int gAdaptabilityHandlers[];

int *HAND_TOKUSEI_GetAdaptabilityHandlers(int *p)
{
    *p = 1;
    return gAdaptabilityHandlers;
}
