/*
 * function: WEATHER_BLIZZARD_Run
 * address:  0x021EEC64
 * packet:   pkt_ov025_021EEC64
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_BLIZZARD_Run  0x021EEC64  thumb  ov025
 *   WEATHER_BLIZZARD_SpawnParticles  0x021EEE04  thumb  ov025
 *   WEATHER_BLIZZARD_ScrollFogLayer  0x021EEEE0  thumb  ov025
 *   gBlizzardWindSpeedX  0x021EF770  data  ov025  a4
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_StepSpawnTimer  0x021A2248  thumb  ov021
 */

extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_StepSpawnTimer(unsigned char *o, int arg);
extern void WEATHER_BLIZZARD_SpawnParticles(int, int, int);
extern void WEATHER_BLIZZARD_ScrollFogLayer(int, int *);
extern int gBlizzardWindSpeedX[];

int WEATHER_BLIZZARD_Run(int a, int b, int c)
{
    int *p;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    if (WEATHER_TASK_StepSpawnTimer((unsigned char *)a, c) != 0) {
        if (gBlizzardWindSpeedX[p[1] / 256] <= -8) {
            WEATHER_BLIZZARD_SpawnParticles(a, 1, c);
        }
    }
    WEATHER_BLIZZARD_ScrollFogLayer(a, p);
    return 0;
}
