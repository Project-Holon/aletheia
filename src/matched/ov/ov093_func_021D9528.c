/*
 * function: BTL_TOKUSEI_BurnGuard_CureOnPeriodicCheck
 * address: 0x021D9528
 * packet: pkt_ov093_021D9528
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   BTL_TOKUSEI_CureSick 0x021D96FC thumb
 */

void BTL_TOKUSEI_BurnGuard_CureOnPeriodicCheck(int a, void *b, int c);
void BTL_TOKUSEI_CureSick(void *a, int b, int c);

void BTL_TOKUSEI_BurnGuard_CureOnPeriodicCheck(int a, void *b, int c)
{
    BTL_TOKUSEI_CureSick(b, c, 4);
}
