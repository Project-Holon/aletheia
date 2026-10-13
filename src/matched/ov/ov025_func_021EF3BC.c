/*
 * function: WEATHER_DIAMOND_DUST_Begin
 * address:  0x021EF3BC
 * packet:   pkt_ov025_021EF3BC
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_DIAMOND_DUST_Begin 0x021EF3BC thumb ov025
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_DIAMOND_DUST_SpawnParticles 0x021EF634 thumb ov025
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_DIAMOND_DUST_SpawnParticles(int *a, int n, int idx);

int WEATHER_DIAMOND_DUST_Begin(int a, int b)
{
    int *p;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 2, 0x10, 0x14, 2, -2, 4, 2, (int)((void *)WEATHER_DIAMOND_DUST_SpawnParticles));
    WEATHER_TASK_InitFog((u32 *)a, 8, 0x7FFF, b);
    *p = 0;
    return 1;
}
