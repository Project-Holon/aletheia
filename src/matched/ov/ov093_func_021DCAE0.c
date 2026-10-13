/*
 * function: HAND_TOKUSEI_MagicBounceCounterMove
 * address: 0x021DCAE0
 * packet: pkt_ov093_021DCAE0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCA98.c and filed here.
 *
 * symbols:
 *   BTLV_CORE_EventCounterMove 0x021E8798 thumb ov093
 */

void BTLV_CORE_EventCounterMove(int u, void *a, int b, int d);
void HAND_TOKUSEI_MagicBounceCounterMove(int u, void *a, int b, int d);

void HAND_TOKUSEI_MagicBounceCounterMove(int u, void *a, int b, int d)
{
    BTLV_CORE_EventCounterMove(u, a, b, d);
}
