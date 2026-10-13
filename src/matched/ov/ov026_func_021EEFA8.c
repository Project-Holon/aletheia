/*
 * function: WEATHER_STORM_BeginParticles
 * address:  0x021EEFA8
 * packet:   pkt_ov026_021EEFA8
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_STORM_BeginParticles  0x021EEFA8  thumb  ov026
 *   WEATHER_STORM_StartCalm  0x021EF614  thumb  ov026
 *   WEATHER_STORM_UpdateGust  0x021EF664  thumb  ov026
 *   WEATHER_STORM_ScrollLayers  0x021EF830  thumb  ov026
 *   func_02014A10  0x02014A10  thumb
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 */

typedef unsigned short u16;
typedef signed short   s16;

typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_FadeLight(unsigned int a, int b, int c);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
extern void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
extern int WEATHER_TASK_IsFogIdle(unsigned int a);
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void WEATHER_STORM_StartCalm(int, u16 *, int, int);
extern void WEATHER_STORM_UpdateGust(int, s16 *, int, int);
extern void WEATHER_STORM_ScrollLayers(int, s16 *);

int WEATHER_STORM_BeginParticles(int a, int b, int c)
{
    s16 *p;
    int t;
    int u;

    p = (s16 *)WEATHER_TASK_GetWorkBuffer((int *)a);
    switch (p[0]) {
    case 0:
        WEATHER_TASK_FadeLight(a, 0x3E, func_02014A10(7));
        p[1] = 0x5A;
        p[0] = p[0] + 1;
        break;
    case 1:
        p[1] = p[1] - 1;
        if (p[1] <= 0) {
            WEATHER_STORM_StartCalm(a, (u16 *)p, b, 1);
            p[7] = 0x78;
            p[1] = 8;
            p[0] = p[0] + 1;
        }
        break;
    case 2:
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            WEATHER_TASK_PlaySe((unsigned char *)a, 0x690);
            WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 0);
            WEATHER_TASK_ChangeFog((u8 *)a, 9, 0x7F80, 10, b);
        }
        t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
        u = WEATHER_TASK_IsFogIdle(a);
        if (t == 1 && u == 1 && p[1] <= 0) {
            return 1;
        }
        break;
    }
    WEATHER_STORM_UpdateGust(a, p, b, 0);
    WEATHER_STORM_ScrollLayers(a, p);
    return 0;
}
