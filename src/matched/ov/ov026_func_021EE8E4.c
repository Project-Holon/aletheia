/*
 * function: WEATHER_RAIN_EndFade
 * address:  0x021EE8E4
 * packet:   pkt_ov026_021EE8E4
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_RAIN_EndFade 0x021EE8E4 thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_StepSpawner 0x021A223C thumb ov021
 *   WEATHER_TASK_ChangeFogOffset 0x021A2390 thumb ov021
 *   WEATHER_TASK_IsFogIdle 0x021A23B0 thumb ov021
 *   WEATHER_TASK_GetParticleCount 0x021A21BC thumb ov021
 *   WEATHER_TASK_GetCameraScroll 0x021A244C thumb ov021
 *   WEATHER_TASK_ShiftParticles 0x021A2564 thumb ov021
 */

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
extern void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);
extern int WEATHER_TASK_IsFogIdle(u32 a);
extern int WEATHER_TASK_GetParticleCount(unsigned char *o);
extern void WEATHER_TASK_GetCameraScroll(u8 *o, s32 *outX, s32 *outY);
extern void WEATHER_TASK_ShiftParticles(int, int, int);

int WEATHER_RAIN_EndFade(int a, int b, int c)
{
    int *p;
    int t;
    int ok;
    int x;
    int y;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
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
    WEATHER_TASK_GetCameraScroll((u8 *)a, &x, &y);
    WEATHER_TASK_ShiftParticles(a, x, y);
    return 0;
}
