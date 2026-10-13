/*
 * function: WEATHER_FOG_EndFadeFixed
 * address:  0x021EE800
 * packet:   pkt_ov028_021EE800
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 */

typedef unsigned int   u32;
int *WEATHER_TASK_GetWorkBuffer(int *p);
void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);
int WEATHER_TASK_IsFogIdle(u32 a);
int WEATHER_TASK_GetParticleCount(unsigned char *o);

int WEATHER_FOG_EndFadeFixed(int a, int b)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);
    int v = *p;
    int r;

    if (v == 0) {
        *p = v - 1;
        WEATHER_TASK_ChangeFogOffset((u32 *)a, 0x7fdf, 0x3c, b);
    } else {
        if (b != 0)
            r = WEATHER_TASK_IsFogIdle(a);
        else
            r = 1;
        if (r != 0) {
            if (WEATHER_TASK_GetParticleCount((unsigned char *)a) == 0)
                return 1;
        }
    }
    return 0;
}
