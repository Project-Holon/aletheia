/*
 * function: func_021EE908
 * address:  0x021EE908
 * packet:   pkt_ov027_021EE908
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_ChangeFogOffset  0x021A2390  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_GetParticleCount  0x021A21BC  thumb  ov021
 *   func_021EEAF4  0x021EEAF4  thumb  ov027
 */

typedef unsigned int   u32;
int *WEATHER_TASK_GetWorkBuffer(int *p);
int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);
int WEATHER_TASK_IsFogIdle(u32 a);
int WEATHER_TASK_GetParticleCount(unsigned char *o);
void func_021EEAF4(int a, int *p);

int func_021EE908(int a, int b, int c)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);
    int t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
    int r;

    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0)
            WEATHER_TASK_ChangeFogOffset((u32 *)a, 0x7fdf, 0x5a, b);
    } else {
        if (b != 0)
            r = WEATHER_TASK_IsFogIdle(a);
        else
            r = 1;
        if (r != 0 && t != 0) {
            if (WEATHER_TASK_GetParticleCount((unsigned char *)a) == 0)
                return 1;
        }
    }
    func_021EEAF4(a, p);
    return 0;
}
