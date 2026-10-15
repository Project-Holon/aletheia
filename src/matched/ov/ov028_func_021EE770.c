/*
 * function: WEATHER_FOG_BeginParticlesFixed
 * address:  0x021EE770
 * packet:   pkt_ov028_021EE770
 * region:   ov028
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 */

typedef unsigned char  u8;
int *WEATHER_TASK_GetWorkBuffer(int *p);
void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 ZONEDATA_GetLightTableMember(u32 i);
int WEATHER_TASK_FadeLight(u32 a, int b, int c);
int WEATHER_TASK_IsFogIdle(u32 a);

int WEATHER_FOG_BeginParticlesFixed(int a, int b)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    if (*p == 0) {
        WEATHER_TASK_ChangeFog((u8 *)a, p[10], p[11], 0x5a, b);
        WEATHER_TASK_FadeLight(a, 0x3e, ZONEDATA_GetLightTableMember(9));
        *p = *p - 1;
    } else if (WEATHER_TASK_IsFogIdle(a) != 0) {
        return 1;
    }
    return 0;
}
