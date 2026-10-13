/*
 * function: WEATHER_TASK_GetStagePhase
 * address:  0x021A273C
 * packet:   pkt_ov021_021A273C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWeatherStagePhase  0x021D88E8  data  a1
 */

typedef unsigned char u8;

extern const u8 gWeatherStagePhase[];

u8 WEATHER_TASK_GetStagePhase(u8 *p)
{
    return gWeatherStagePhase[p[0x26]];
}
