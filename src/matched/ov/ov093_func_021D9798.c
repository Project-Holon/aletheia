/*
 * function: BTL_TOKUSEI_SnowWarning_StartHail
 * address: 0x021D9798
 * packet: pkt_ov093_021D9798
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
 *   BTL_TOKUSEI_StartWeather 0x021D97B4 thumb
 */

void BTL_TOKUSEI_SnowWarning_StartHail(int a, void *b, int c);
void BTL_TOKUSEI_StartWeather(void *a,int b,int c);

void BTL_TOKUSEI_SnowWarning_StartHail(int a, void *b, int c)
{
    BTL_TOKUSEI_StartWeather(b, c, 3);
}
