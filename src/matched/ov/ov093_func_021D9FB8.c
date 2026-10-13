/*
 * function: HAND_TOKUSEI_AddAftermath
 * address: 0x021D9FB8
 * packet: pkt_ov093_021D9FB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9ADC.c and filed here.
 *
 * symbols:
 *   gAftermathHandlers 0x021F0820 data ov093 a4
 */

int *HAND_TOKUSEI_AddAftermath(int *p);
extern int gAftermathHandlers[];

int *HAND_TOKUSEI_AddAftermath(int *p)
{
    *p = 1;
    return gAftermathHandlers;
}
