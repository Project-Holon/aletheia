/*
 * function: WEATHER_DOWNPOUR_Begin
 * address:  0x021EEF94
 * packet:   pkt_ov025_021EEF94
 * region:   ov025
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_DOWNPOUR_Begin 0x021EEF94 thumb ov025
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_SaveCameraPos 0x021A2424 thumb ov021
 *   WEATHER_TASK_PlaySe 0x021A25BC thumb ov021
 *   WEATHER_DOWNPOUR_SpawnParticles 0x021EF2D4 thumb ov025
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_SaveCameraPos(u8 *p);
extern void WEATHER_TASK_PlaySe(unsigned char *o, int arg);
extern void WEATHER_DOWNPOUR_SpawnParticles(int a, int n, int idx);

int WEATHER_DOWNPOUR_Begin(int a, int b)
{
    int *p;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 0, 8, 1, 1, -4, 2, 1, (int)((void *)WEATHER_DOWNPOUR_SpawnParticles));
    WEATHER_TASK_InitFog((u32 *)a, 9, 0x7FDF, b);
    *p = 1;
    WEATHER_TASK_SaveCameraPos((u8 *)a);
    WEATHER_TASK_PlaySe((unsigned char *)a, 0x6E4);
    return 1;
}
