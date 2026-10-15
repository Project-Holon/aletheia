/*
 * function: WEATHER_SANDSTORM_BeginParticles
 * address:  0x021EE7A4
 * packet:   pkt_ov027_021EE7A4
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
 *   WEATHER_TASK_ChangeFog  0x021A232C  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 *   WEATHER_TASK_FadeLight  0x021A2108  thumb  ov021
 *   WEATHER_TASK_IsFogIdle  0x021A23B0  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   WEATHER_SANDSTORM_ScrollBillboards  0x021EEAF4  thumb  ov027
 */

typedef unsigned char  u8;
int *WEATHER_TASK_GetWorkBuffer(int *p);
int WEATHER_TASK_StepSpawner(unsigned char *o, int arg);
void WEATHER_TASK_ChangeFog(u8 *p, int a, int b, int c, int d);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 ZONEDATA_GetLightTableMember(u32 i);
int WEATHER_TASK_FadeLight(u32 a, int b, int c);
int WEATHER_TASK_IsFogIdle(u32 a);
void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
void WEATHER_SANDSTORM_ScrollBillboards(int a, int *p);

int WEATHER_SANDSTORM_BeginParticles(int a, int b, int c)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);
    int t = WEATHER_TASK_StepSpawner((unsigned char *)a, c);

    if (*p > 0) {
        *p = *p - 1;
        if (*p == 0) {
            WEATHER_TASK_ChangeFog((u8 *)a, 8, 0x7f5e, 0x5a, b);
            WEATHER_TASK_FadeLight(a, 0x3e, ZONEDATA_GetLightTableMember(3));
        }
    } else if (WEATHER_TASK_IsFogIdle(a) != 0 && t != 0) {
        WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 0);
        return 1;
    }
    WEATHER_SANDSTORM_ScrollBillboards(a, p);
    return 0;
}
