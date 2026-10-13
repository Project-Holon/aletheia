/*
 * function: WEATHER_STORM_EndParticles
 * address:  0x021EF134
 * packet:   pkt_ov026_021EF134
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_STORM_EndParticles 0x021EF134 thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_RetargetSpawner 0x021A2228 thumb ov021
 *   WEATHER_TASK_StopSe 0x021A25CC thumb ov021
 *   WEATHER_TASK_ChangeFogOffset 0x021A2390 thumb ov021
 *   WEATHER_TASK_SetBillboardVisible 0x021A2160 thumb ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_RetargetSpawner(u8 *p, int a, int b, int c, int d);
extern void WEATHER_TASK_StopSe(u8 *p);
extern void WEATHER_TASK_ChangeFogOffset(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);

int WEATHER_STORM_EndParticles(int a, int b)
{
    WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_RetargetSpawner((u8 *)a, 0, 4, 4, -1);
    WEATHER_TASK_StopSe((u8 *)a);
    WEATHER_TASK_ChangeFogOffset((u32 *)a, 0x7FDF, 0x32, b);
    WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 0, 0);
    WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 0, 1);
    return 1;
}
