/*
 * function: WEATHER_LIGHTNING_Clear
 * address:  0x021EF9CC
 * packet:   pkt_021EF9CC
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_LIGHTNING_Clear 0x021EF9CC thumb
 *   func_02082BCC 0x02082BCC arm
 */

extern void func_02082BCC(int, int, int);

void WEATHER_LIGHTNING_Clear(int a0)
{
    func_02082BCC(a0, 0, 0x40);
}
