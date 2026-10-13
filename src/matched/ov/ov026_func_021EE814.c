/*
 * function: WEATHER_RAIN_BeginPlain
 * address:  0x021EE814
 * packet:   pkt_ov026_021EE814
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_RAIN_BeginPlain 0x021EE814 thumb ov026
 *   WEATHER_RAIN_SpawnParticles 0x021EEA18 thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_PrewarmParticles 0x021A2254 thumb ov021
 *   WEATHER_TASK_PlaySe 0x021A25BC thumb ov021
 *   WEATHER_TASK_SetLight 0x021A2114 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_PrewarmParticles(u8 *p, void (*fn)(u8 *, int, u32), int n, int m, int k, u16 w);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
extern int WEATHER_TASK_SetLight(u32 a, int b, u32 c);
extern u16 func_02014A10(u32 i);
extern void WEATHER_RAIN_SpawnParticles(int a, int n, int idx);

int WEATHER_RAIN_BeginPlain(int a, int b, u16 c)
{
    WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 2, 0, 2, 0, -4, 2, 1, (int)WEATHER_RAIN_SpawnParticles);
    WEATHER_TASK_InitFog((u32 *)a, 8, 0x7F5F, b);
    WEATHER_TASK_PrewarmParticles((u8 *)a, (void (*)(u8 *, int,  u32))WEATHER_RAIN_SpawnParticles, 0x14, 0xA, 1, c);
    WEATHER_TASK_PlaySe((unsigned char *)a, 0x691);
    WEATHER_TASK_SetLight(a, 0x3E, func_02014A10(2));
    return 1;
}
