/*
 * function: WEATHER_TASK_RetargetSpawner
 * address:  0x021A2228
 * packet:   pkt_ov021_021A2228
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   WEATHER_TASK_SetSpawnerTarget  0x021A2AAC  thumb  ov021
 */

typedef unsigned char u8;

void WEATHER_TASK_SetSpawnerTarget(char *p, int a, int b, int c, int d);

void WEATHER_TASK_RetargetSpawner(u8 *p, int a, int b, int c, int d)
{
    WEATHER_TASK_SetSpawnerTarget((char *)(p + 0x4C), a, b, c, d);
}
