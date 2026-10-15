/*
 * function: WEATHER_SNOW_BeginPlain
 * address:  0x021EE810
 * packet:   pkt_ov025_021EE810
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_SNOW_BeginPlain  0x021EE810  thumb  ov025
 *   WEATHER_SNOW_SpawnParticles  0x021EEA34  thumb  ov025
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_PrewarmParticles  0x021A2254  thumb  ov021
 *   WEATHER_TASK_SetLight  0x021A2114  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 */

typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(unsigned int *p, int a, int b, int c);
extern void WEATHER_TASK_PrewarmParticles(int, void *, int, int, int, int);
extern int WEATHER_TASK_SetLight(unsigned int a, int b, unsigned int c);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 ZONEDATA_GetLightTableMember(u32 i);
extern void WEATHER_SNOW_SpawnParticles(int a, int n, int idx);

int WEATHER_SNOW_BeginPlain(unsigned int *a, int b, int c)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 0x10, 1, 0x10, -3, 1, 0, (int)((void *)WEATHER_SNOW_SpawnParticles));
    p[1] = 1;
    p[2] = 0;
    WEATHER_TASK_InitFog(a, 8, 0x7F5F, b);
    WEATHER_TASK_PrewarmParticles((int)a, (void *)WEATHER_SNOW_SpawnParticles, 0x14, 1, 0x12, c);
    WEATHER_TASK_SetLight((unsigned int)a, 0x3E, ZONEDATA_GetLightTableMember(1));
    return 1;
}
