/*
 * function: WEATHER_THUNDERSTORM_BeginParticles
 * address:  0x021EEB44
 * packet:   pkt_ov026_021EEB44
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_THUNDERSTORM_BeginParticles  0x021EEB44  thumb  ov026
 *   WEATHER_THUNDERSTORM_ScrollLayers  0x021EEF0C  thumb  ov026
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_SetLightColor  0x021A2154  thumb  ov021
 *   WEATHER_TASK_FlashLight  0x021A2130  thumb  ov021
 *   WEATHER_TASK_PlaySeDirect  0x021A25DC  thumb  ov021
 *   WEATHER_TASK_IsLightFlashing  0x021A213C  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   WEATHER_TASK_StepSpawner  0x021A223C  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 */

typedef signed short s16;

typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern int WEATHER_TASK_FadeLight(unsigned int a, int b, int c);
extern void WEATHER_TASK_SetLightColor(u8 *p, unsigned int b, unsigned int c);
extern void WEATHER_TASK_FlashLight(u8 *p, unsigned int b, unsigned int c, unsigned int d);
extern void WEATHER_TASK_PlaySeDirect(u8 *p, int a);
extern int WEATHER_TASK_IsLightFlashing(u8 *p);
extern void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
extern int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
extern int WEATHER_TASK_IsFogIdle(unsigned int a);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 ZONEDATA_GetLightTableMember(u32 i);
extern void WEATHER_THUNDERSTORM_ScrollLayers(int a, int *b);

int WEATHER_THUNDERSTORM_BeginParticles(u8 *a, int b, int c)
{
    s16 *p;
    int t;
    int u;

    p = (s16 *)WEATHER_TASK_GetWorkBuffer((int *)a);
    switch (p[0]) {
    case 0:
        WEATHER_TASK_FadeLight((unsigned int)a, 0x3E, ZONEDATA_GetLightTableMember(6));
        p[0] = p[0] + 1;
        p[1] = 0x5A;
        break;
    case 1:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            p[0] = p[0] + 1;
        }
        break;
    case 2:
        WEATHER_TASK_SetLightColor(a, 0x28C6, 8);
        p[1] = 0x10;
        p[0] = p[0] + 1;
        break;
    case 3:
        p[1] = p[1] - 1;
        if (p[1] < 0) {
            WEATHER_TASK_FlashLight(a, 0x23DE, 4, 0x3C);
            WEATHER_TASK_PlaySeDirect((u8 *)a, 0x692);
            p[0] = p[0] + 1;
        }
        break;
    case 4:
        if (WEATHER_TASK_IsLightFlashing((u8 *)a) == 0) {
            WEATHER_TASK_ChangeFog((u8 *)a, 9, 0x7F80, 0x50, b);
            p[0] = p[0] + 1;
            p[1] = 0x30;
        }
        break;
    case 5:
        p[1] = p[1] - 1;
        if (p[1] == 0) {
            WEATHER_TASK_PlaySe((unsigned char *)a, 0x690);
            WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 0);
        }
        t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);
        u = WEATHER_TASK_IsFogIdle((int)a);
        if (t != 0 && u != 0) {
            return 1;
        }
        break;
    }
    WEATHER_THUNDERSTORM_ScrollLayers((int)a, (int *)p);
    return 0;
}
