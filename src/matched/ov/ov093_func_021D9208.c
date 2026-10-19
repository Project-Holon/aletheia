/*
 * function: HAND_TOKUSEI_GetHyperCutterHandlers
 * address: 0x021D9208
 * packet: pkt_ov093_021D9208
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9118.c and filed here.
 *
 * symbols:
 *   gIndirectGuardCause1Handlers 0x021F0880 data ov093 a4
 */

int *HAND_TOKUSEI_GetHyperCutterHandlers(int *p);
extern int gIndirectGuardCause1Handlers[];

int *HAND_TOKUSEI_GetHyperCutterHandlers(int *p)
{
    *p = 2;
    return gIndirectGuardCause1Handlers;
}
