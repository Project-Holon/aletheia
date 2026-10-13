/*
 * function: HAND_TOKUSEI_RunAwayCheckEscape
 * address: 0x021DB0DC
 * packet: pkt_ov093_021DB0DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624_p02.c and filed here.
 *
 * symbols:
 *   BTLV_CORE_EventSetFlagIfAttacker 0x021E8878 thumb ov093
 */

void BTLV_CORE_EventSetFlagIfAttacker(int a, int b, int c, int d);
void HAND_TOKUSEI_RunAwayCheckEscape(int a, int b, int c, int d);

void HAND_TOKUSEI_RunAwayCheckEscape(int a, int b, int c, int d)
{
    BTLV_CORE_EventSetFlagIfAttacker(a, b, c, d);
}
