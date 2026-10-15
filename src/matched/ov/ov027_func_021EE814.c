/*
 * function: WEATHER_SANDSTORM_BeginPlain
 * address:  0x021EE814
 * packet:   pkt_ov027_021EE814
 * region:   ov027
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_PrewarmParticles  0x021A2254  thumb  ov021
 *   WEATHER_TASK_SetBillboardVisible  0x021A2160  thumb  ov021
 *   ZONEDATA_GetLightTableMember  0x02014A10  thumb
 *   WEATHER_TASK_SetLight  0x021A2114  thumb  ov021
 *   WEATHER_SANDSTORM_SpawnParticles  0x021EEA04  thumb  ov027
 */

typedef unsigned char  u8;
int *WEATHER_TASK_GetWorkBuffer(int *p);
void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
void WEATHER_TASK_InitFog(unsigned int *p, int a, int b, int c);
void WEATHER_TASK_PrewarmParticles(int a, void (*b)(int, int, int), int c, int d, int e, int f);
void WEATHER_TASK_SetBillboardVisible(unsigned char *o, unsigned int v, int i);
typedef unsigned short u16;
typedef unsigned int   u32;
u16 ZONEDATA_GetLightTableMember(u32 i);
int WEATHER_TASK_SetLight(u32 a, int b, u32 c);
void WEATHER_SANDSTORM_SpawnParticles(int a, int b, int c);

int WEATHER_SANDSTORM_BeginPlain(unsigned int *a, int b, int c)
{
    WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 2, 1, 2, -2, 4, 1, (int)WEATHER_SANDSTORM_SpawnParticles);
    WEATHER_TASK_InitFog(a, 8, 0x7f5e, b);
    WEATHER_TASK_PrewarmParticles((int)a, WEATHER_SANDSTORM_SpawnParticles, 24, 2, 2, c);
    WEATHER_TASK_SetBillboardVisible((unsigned char *)a, 1, 0);
    WEATHER_TASK_SetLight((u32)a, 0x3e, ZONEDATA_GetLightTableMember(3));
    return 1;
}
