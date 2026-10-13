/*
 * function: BTL_TOKUSEI_FreezeGuard_CureOnPeriodicCheck
 * address: 0x021D94A8
 * packet: pkt_ov093_021D94A8
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

void BTL_TOKUSEI_FreezeGuard_CureOnPeriodicCheck(int a, int b, int c);
void BTL_TOKUSEI_CureSick(void *a, int b, int c);

void BTL_TOKUSEI_FreezeGuard_CureOnPeriodicCheck(int a, int b, int c)
{
    BTL_TOKUSEI_CureSick((void *)b, c, 3);
}
