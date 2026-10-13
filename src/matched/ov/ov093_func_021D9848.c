/*
 * function: BTL_TOKUSEI_IceBody_HealInHail
 * address: 0x021D9848
 * packet: pkt_ov093_021D9848
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
 *   BTL_TOKUSEI_HealInWeather 0x021D9880 thumb
 */

void BTL_TOKUSEI_IceBody_HealInHail(int a, void *b, int c);
void BTL_TOKUSEI_HealInWeather(void *a, int b, int c);

void BTL_TOKUSEI_IceBody_HealInHail(int a, void *b, int c)
{
    BTL_TOKUSEI_HealInWeather(b, c, 3);
}
