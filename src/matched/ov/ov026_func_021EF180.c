/*
 * function: WEATHER_STORM_EndFade
 * address:  0x021EF180
 * packet:   pkt_ov026_021EF180
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 *   WEATHER_STORM_UpdateGust  0x021EF664  thumb  ov026
 *   WEATHER_STORM_ScrollLayers  0x021EF830  thumb  ov026
 */

typedef signed short   s16;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
typedef unsigned int   u32;
extern int WEATHER_TASK_IsFogIdle(u32 a);
extern int WEATHER_TASK_GetParticleCount(unsigned char *o);
extern void WEATHER_STORM_UpdateGust(int a, s16 *p, int b, int d);
extern void WEATHER_STORM_ScrollLayers(int a, s16 *p);

int WEATHER_STORM_EndFade(int a, int b, int c)
{
    int x;
    int y;
    int t;

    x = (int)WEATHER_TASK_GetWorkBuffer((int *)a);
    y = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
    t = (b != 0) ? WEATHER_TASK_IsFogIdle(a) : 1;
    if (t != 0 && y != 0 && WEATHER_TASK_GetParticleCount((unsigned char *)a) == 0) {
        return 1;
    }
    WEATHER_STORM_UpdateGust(a, (s16 *)x, b, 1);
    WEATHER_STORM_ScrollLayers(a, (s16 *)x);
    return 0;
}
