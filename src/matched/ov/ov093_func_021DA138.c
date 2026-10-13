/*
 * function: HAND_TOKUSEI_AddCloudNine
 * address: 0x021DA138
 * packet: pkt_ov093_021DA138
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
 *   gCloudNineHandlers 0x021F0800 data ov093 a4
 */

int *HAND_TOKUSEI_AddCloudNine(int *p);
extern int gCloudNineHandlers[];

int *HAND_TOKUSEI_AddCloudNine(int *p)
{
    *p = 1;
    return gCloudNineHandlers;
}
