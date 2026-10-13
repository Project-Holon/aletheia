/*
 * function: WEATHER_BLIZZARD_EndFade
 * address:  0x021EECEC
 * packet:   pkt_ov025_021EECEC
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_BLIZZARD_EndFade  0x021EECEC  thumb  ov025
 *   WEATHER_BLIZZARD_ScrollFogLayer  0x021EEEE0  thumb  ov025
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 */

typedef unsigned int   u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
extern void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);
extern int WEATHER_TASK_IsFogIdle(u32 a);
extern int WEATHER_TASK_GetParticleCount(unsigned char *o);
extern void WEATHER_BLIZZARD_ScrollFogLayer(int, int *);

int WEATHER_BLIZZARD_EndFade(int a, int b, int c)
{
    int *p;
    int t;
    int ok;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            WEATHER_TASK_ChangeFogOffset((u32 *)a, 0x7FFF, 0x3C, b);
        }
    } else {
        if (b != 0) {
            ok = WEATHER_TASK_IsFogIdle(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0) {
            p[2] = 1;
            if (WEATHER_TASK_GetParticleCount((unsigned char *)a) == 0) {
                return 1;
            }
        }
    }
    WEATHER_BLIZZARD_ScrollFogLayer(a, p);
    return 0;
}
