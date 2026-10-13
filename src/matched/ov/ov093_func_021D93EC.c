/*
 * function: BTL_TOKUSEI_ParalysisGuard_CureOnEntry
 * address: 0x021D93EC
 * packet: pkt_ov093_021D93EC
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
 *   BTL_TOKUSEI_CureSickIfOwner 0x021D96DC thumb
 */

void BTL_TOKUSEI_ParalysisGuard_CureOnEntry(int a, int b, int c);
void BTL_TOKUSEI_CureSickIfOwner(int a,int b,int c);

void BTL_TOKUSEI_ParalysisGuard_CureOnEntry(int a, int b, int c)
{
    BTL_TOKUSEI_CureSickIfOwner(b, c, 1);
}
