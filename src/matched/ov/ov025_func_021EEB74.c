/*
 * function: WEATHER_BLIZZARD_BeginParticles
 * address:  0x021EEB74
 * packet:   pkt_ov025_021EEB74
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_BLIZZARD_BeginParticles  0x021EEB74  thumb  ov025
 *   WEATHER_BLIZZARD_ScrollFogLayer  0x021EEEE0  thumb  ov025
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   func_02014A10  0x02014A10  thumb
 */

typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
extern void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
extern int WEATHER_TASK_FadeLight(unsigned int a, int b, int c);
extern int WEATHER_TASK_IsFogIdle(unsigned int a);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void WEATHER_BLIZZARD_ScrollFogLayer(int, int *);

int WEATHER_BLIZZARD_BeginParticles(int a, int b, int c)
{
    int *p;
    int t;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            WEATHER_TASK_ChangeFog((u8 *)a, 4, 0x7B18, 0x5A, b);
            WEATHER_TASK_FadeLight(a, 0x3E, func_02014A10(4));
        }
    } else if (WEATHER_TASK_IsFogIdle(a) != 0 && t != 0) {
        WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 0);
        return 1;
    }
    WEATHER_BLIZZARD_ScrollFogLayer(a, p);
    return 0;
}
