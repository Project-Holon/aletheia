/*
 * function: HAND_TOKUSEI_SandStream_StartSandstorm
 * address: 0x021D977C
 * packet: pkt_ov093_021D977C
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

void HAND_TOKUSEI_SandStream_StartSandstorm(int a, void *b, int c);
void HAND_TOKUSEI_StartWeather(void *a,int b,int c);

void HAND_TOKUSEI_SandStream_StartSandstorm(int a, void *b, int c)
{
    HAND_TOKUSEI_StartWeather(b, c, 4);
}
