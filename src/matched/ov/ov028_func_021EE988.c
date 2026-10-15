/*
 * function: WEATHER_FOG_BeginParticles
 * address:  0x021EE988
 * packet:   pkt_ov028_021EE988
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_FOG_BeginParticles  0x021EE988  thumb  ov028
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 */

typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
extern int WEATHER_TASK_FadeLight(unsigned int a, int b, int c);
extern int WEATHER_TASK_IsFogIdle(unsigned int a);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 ZONEDATA_GetLightTableMember(u32 i);

int WEATHER_FOG_BeginParticles(int a, int b)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    if (p[1] == 0) {
        WEATHER_TASK_ChangeFog((u8 *)a, p[11], p[12], 0x5A, b);
        WEATHER_TASK_FadeLight(a, 0x3E, ZONEDATA_GetLightTableMember(p[0]));
        p[1] = p[1] - 1;
    } else if (WEATHER_TASK_IsFogIdle(a) != 0) {
        return 1;
    }
    return 0;
}
