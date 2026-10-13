/*
 * function: HAND_TOKUSEI_AddAngerPoint
 * address: 0x021D9C80
 * packet: pkt_ov093_021D9C80
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
 *   gAngerPointHandlers 0x021F0858 data ov093 a4
 */

int *HAND_TOKUSEI_AddAngerPoint(int *p);
extern int gAngerPointHandlers[];

int *HAND_TOKUSEI_AddAngerPoint(int *p)
{
    *p = 1;
    return gAngerPointHandlers;
}
