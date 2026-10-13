/*
 * function: WEATHER_STORM_Run
 * address: 0x021EF104
 * packet: pkt_ov026_021EF104
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_StepSpawnTimer 0x021A2248 thumb ov021
 *   WEATHER_STORM_UpdateGust 0x021EF664 thumb ov026
 *   WEATHER_STORM_ScrollLayers 0x021EF830 thumb ov026
 */

typedef unsigned char u8;
typedef short s16;
extern int *WEATHER_TASK_GetWorkBuffer(int *);
extern int WEATHER_TASK_StepSpawnTimer(u8 *, int);
extern void WEATHER_STORM_UpdateGust(int, s16 *, int, int);
extern void WEATHER_STORM_ScrollLayers(int, s16 *);
int WEATHER_STORM_Run(u8 *a, int b, int c)
{
    s16 *p;
    p = (s16 *)WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_StepSpawnTimer(a, c);
    WEATHER_STORM_UpdateGust((int)a, p, b, 0);
    WEATHER_STORM_ScrollLayers((int)a, p);
    return 0;
}
