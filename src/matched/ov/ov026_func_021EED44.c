/*
 * function: WEATHER_THUNDERSTORM_EndFade
 * address:  0x021EED44
 * packet:   pkt_ov026_021EED44
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_THUNDERSTORM_EndFade 0x021EED44 thumb ov026
 *   WEATHER_THUNDERSTORM_ScrollLayers 0x021EEF0C thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_StepSpawner 0x021A223C thumb ov021
 *   WEATHER_TASK_ChangeFogOffset 0x021A2390 thumb ov021
 *   WEATHER_TASK_IsFogIdle 0x021A23B0 thumb ov021
 *   WEATHER_TASK_GetParticleCount 0x021A21BC thumb ov021
 */

typedef signed short s16;

typedef unsigned int   u32;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
extern void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);
extern int WEATHER_TASK_IsFogIdle(u32 a);
extern int WEATHER_TASK_GetParticleCount(unsigned char *o);
extern void WEATHER_THUNDERSTORM_ScrollLayers(int a, int *b);

int WEATHER_THUNDERSTORM_EndFade(int a, int b, int c)
{
    s16 *p;
    int t;
    int ok;

    p = (s16 *)WEATHER_TASK_GetWorkBuffer((int *)a);
    t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
    if (p[1] > 0) {
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            WEATHER_TASK_ChangeFogOffset((u32 *)a, 0x7FDF, 0x32, b);
        }
    } else {
        if (b != 0) {
            ok = WEATHER_TASK_IsFogIdle(a);
        } else {
            ok = 1;
        }
        if (ok != 0 && t != 0 && WEATHER_TASK_GetParticleCount((unsigned char *)a) == 0) {
            return 1;
        }
    }
    WEATHER_THUNDERSTORM_ScrollLayers(a, (int *)p);
    return 0;
}
