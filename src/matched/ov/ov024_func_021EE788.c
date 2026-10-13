/*
 * function: WEATHER_CLEAR_BeginParticles
 * address:  0x021EE788
 * packet:   pkt_ov024_021EE788
 * region:   ov024
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_CheckZoneFogA  0x021A23E8  thumb  ov021
 *   WEATHER_TASK_GetZoneFogC  0x021A2400  thumb  ov021
 *   WEATHER_TASK_GetZoneFogD  0x021A240C  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_CheckZoneFogB  0x021A23F4  thumb  ov021
 *   WEATHER_TASK_GetZoneFogE  0x021A2418  thumb  ov021
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 */

int *WEATHER_TASK_GetWorkBuffer(int *p);
int WEATHER_TASK_CheckZoneFogA(int *p);
int WEATHER_TASK_GetZoneFogC(int *p);
int WEATHER_TASK_GetZoneFogD(int *p);
typedef unsigned char  u8;
void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
int WEATHER_TASK_CheckZoneFogB(int *p);
int WEATHER_TASK_GetZoneFogE(int *p);
typedef unsigned int   u32;
int WEATHER_TASK_FadeLight(u32 a, int b, int c);
int WEATHER_TASK_IsFogIdle(u32 a);

int WEATHER_CLEAR_BeginParticles(int *p, int v)
{
    int *s = WEATHER_TASK_GetWorkBuffer(p);
    int t;

    if (*s == 0) {
        if (WEATHER_TASK_CheckZoneFogA(p)) {
            t = WEATHER_TASK_GetZoneFogC(p);
            WEATHER_TASK_ChangeFog((u8 *)p, WEATHER_TASK_GetZoneFogD(p), t, 0xA0, v);
        }
        if (WEATHER_TASK_CheckZoneFogB(p)) {
            WEATHER_TASK_FadeLight((u32)p, 0x52, WEATHER_TASK_GetZoneFogE(p));
        }
        *s = 1;
    }
    if (WEATHER_TASK_IsFogIdle((u32)p)) {
        return 1;
    }
    return 0;
}
