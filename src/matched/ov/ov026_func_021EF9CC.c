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
 *   MI_CpuFill8 0x02082BCC arm
 */

extern void MI_CpuFill8(int, int, int);

void WEATHER_LIGHTNING_Clear(int a0)
{
    MI_CpuFill8(a0, 0, 0x40);
}
