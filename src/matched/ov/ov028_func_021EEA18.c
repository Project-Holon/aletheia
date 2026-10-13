/*
 * function: WEATHER_FOG_EndFade
 * address:  0x021EEA18
 * packet:   pkt_ov028_021EEA18
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_FOG_EndFade  0x021EEA18  thumb  ov028
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 */

typedef unsigned int   u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);
extern int WEATHER_TASK_IsFogIdle(u32 a);
extern int WEATHER_TASK_GetParticleCount(unsigned char *o);

int WEATHER_FOG_EndFade(int a, int b)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);
    int ok;

    if (p[1] == 0) {
        p[1] = p[1] - 1;
        WEATHER_TASK_ChangeFogOffset((u32 *)a, 0x7FDF, 0x3C, b);
    } else {
        if (b != 0) {
            ok = WEATHER_TASK_IsFogIdle(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && WEATHER_TASK_GetParticleCount((unsigned char *)a) == 0) {
            return 1;
        }
    }
    return 0;
}
