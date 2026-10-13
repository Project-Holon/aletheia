/*
 * function: BTL_ABILITY_MagicBounceReflectMove
 * address: 0x021DCAD8
 * packet: pkt_ov093_021DCAD8
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
 *   BTLV_CORE_EventRedirectMove 0x021E8744 thumb ov093
 */

void BTLV_CORE_EventRedirectMove(int u, void *a, int b, int d);
void BTL_ABILITY_MagicBounceReflectMove(int u, void *a, int b, int d);

void BTL_ABILITY_MagicBounceReflectMove(int u, void *a, int b, int d)
{
    BTLV_CORE_EventRedirectMove(u, a, b, d);
}
