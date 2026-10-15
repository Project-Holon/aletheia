/*
 * function: WEATHER_BLIZZARD_BeginPlain
 * address:  0x021EEBE4
 * packet:   pkt_ov025_021EEBE4
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_BLIZZARD_BeginPlain  0x021EEBE4  thumb  ov025
 *   WEATHER_BLIZZARD_SpawnParticles  0x021EEE04  thumb  ov025
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_PrewarmParticles  0x021A2254  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   WEATHER_TASK_SetLight  0x021A2114  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 */

typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(unsigned int *p, int a, int b, int c);
extern void WEATHER_TASK_PrewarmParticles(int, void *, int, int, int, int);
extern void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
extern int WEATHER_TASK_SetLight(unsigned int a, int b, unsigned int c);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 ZONEDATA_GetLightTableMember(u32 i);
extern void WEATHER_BLIZZARD_SpawnParticles(int a, int n, u16 idx);

int WEATHER_BLIZZARD_BeginPlain(unsigned int *a, int b, int c)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 2, 1, 2, -2, 2, 1, (int)((void *)WEATHER_BLIZZARD_SpawnParticles));
    WEATHER_TASK_InitFog(a, 4, 0x7B18, b);
    p[1] = 0;
    p[2] = 0;
    p[9] = 0;
    WEATHER_TASK_PrewarmParticles((int)a, (void *)WEATHER_BLIZZARD_SpawnParticles, 0x14, 2, 2, c);
    WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 0);
    WEATHER_TASK_SetLight((unsigned int)a, 0x3E, ZONEDATA_GetLightTableMember(4));
    return 1;
}
