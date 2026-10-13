/*
 * function: HAND_TOKUSEI_BlazeBoostFire
 * address: 0x021D8C3C
 * packet: pkt_ov093_021D8C3C
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
 *   HAND_TOKUSEI_PinchBoostType 0x021D8CAC thumb
 */

void HAND_TOKUSEI_BlazeBoostFire(int a, int b, int c);
void HAND_TOKUSEI_PinchBoostType(int a, int b, int c);

void HAND_TOKUSEI_BlazeBoostFire(int a, int b, int c)
{
    HAND_TOKUSEI_PinchBoostType(b, c, 9);
}
