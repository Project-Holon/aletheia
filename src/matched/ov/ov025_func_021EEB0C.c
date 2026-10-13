/*
 * function: WEATHER_BLIZZARD_Begin
 * address:  0x021EEB0C
 * packet:   pkt_ov025_021EEB0C
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   WEATHER_BLIZZARD_Begin  0x021EEB0C  thumb  ov025
 *   WEATHER_BLIZZARD_SpawnParticles  0x021EEE04  thumb  ov025
 *   WEATHER_TASK_GetWorkBuffer  0x021A21B8  thumb  ov021
 *   WEATHER_TASK_SetupSpawner  0x021A21F8  thumb  ov021
 *   WEATHER_TASK_InitFog  0x021A22E0  thumb  ov021
 *   WEATHER_TASK_SaveCameraPos  0x021A2424  thumb  ov021
 *   WEATHER_TASK_PlaySe  0x021A25BC  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_SaveCameraPos(u8 *p);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
typedef unsigned short u16;
extern void WEATHER_BLIZZARD_SpawnParticles(int a, int n, u16 idx);

int WEATHER_BLIZZARD_Begin(int a, int b)
{
    int *p = WEATHER_TASK_GetWorkBuffer((int *)a);

    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 6, 1, 2, -2, 2, 1, (int)((void *)WEATHER_BLIZZARD_SpawnParticles));
    WEATHER_TASK_InitFog((u32 *)a, 4, 0x7FFF, b);
    p[0] = 8;
    p[1] = 0;
    p[2] = 0;
    p[9] = 0;
    p[8] = 0;
    WEATHER_TASK_SaveCameraPos((u8 *)a);
    WEATHER_TASK_PlaySe((unsigned char *)a, 0x6E3);
    return 1;
}
