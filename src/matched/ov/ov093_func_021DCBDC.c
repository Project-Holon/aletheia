/*
 * function: HAND_TOKUSEI_AddHeavyMetal
 * address: 0x021DCBDC
 * packet: pkt_ov093_021DCBDC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCAE8.c and filed here.
 *
 * symbols:
 *   gHeavyMetalHandlers 0x021F0680 data ov093 a4
 */

int *HAND_TOKUSEI_AddHeavyMetal(int *p);
extern int gHeavyMetalHandlers[];

int *HAND_TOKUSEI_AddHeavyMetal(int *p)
{
    *p = 1;
    return gHeavyMetalHandlers;
}
