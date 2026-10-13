/*
 * function: WEATHER_DOWNPOUR_BeginPlain
 * address:  0x021EF068
 * packet:   pkt_ov025_021EF068
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_DOWNPOUR_BeginPlain 0x021EF068 thumb ov025
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_PrewarmParticles 0x021A2254 thumb ov021
 *   WEATHER_TASK_SetLight 0x021A2114 thumb ov021
 *   func_02014A10 0x02014A10 thumb
 *   WEATHER_DOWNPOUR_SpawnParticles 0x021EF2D4 thumb ov025
 */

typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(unsigned int *p, int a, int b, int c);
extern void WEATHER_TASK_PrewarmParticles(int, void *, int, int, int, int);
extern int WEATHER_TASK_SetLight(unsigned int a, int b, unsigned int c);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 func_02014A10(u32 i);
extern void WEATHER_DOWNPOUR_SpawnParticles(int a, int n, int idx);

int WEATHER_DOWNPOUR_BeginPlain(unsigned int *a, int b, int c)
{
    WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 1, 1, 1, -4, 2, 1, (int)((void *)WEATHER_DOWNPOUR_SpawnParticles));
    WEATHER_TASK_InitFog(a, 9, 0x7F80, b);
    WEATHER_TASK_PrewarmParticles((int)a, (void *)WEATHER_DOWNPOUR_SpawnParticles, 0x14, 10, 1, c);
    WEATHER_TASK_SetLight((unsigned int)a, 0x3E, func_02014A10(5));
    return 1;
}
