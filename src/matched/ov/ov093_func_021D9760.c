/*
 * function: HAND_TOKUSEI_Drought_StartSun
 * address: 0x021D9760
 * packet: pkt_ov093_021D9760
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
 *   HAND_TOKUSEI_StartWeather 0x021D97B4 thumb
 */

void HAND_TOKUSEI_Drought_StartSun(int a, void *b, int c);
void HAND_TOKUSEI_StartWeather(void *a,int b,int c);

/*
 * Extent ends with two bytes of zero alignment padding.
 */
void HAND_TOKUSEI_Drought_StartSun(int a, void *b, int c)
{
    HAND_TOKUSEI_StartWeather(b, c, 1);
}
