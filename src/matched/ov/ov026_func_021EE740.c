/*
 * function: WEATHER_RAIN_Begin
 * address:  0x021EE740
 * packet:   pkt_ov026_021EE740
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WEATHER_RAIN_Begin 0x021EE740 thumb ov026
 *   WEATHER_TASK_GetWorkBuffer 0x021A21B8 thumb ov021
 *   WEATHER_TASK_SetupSpawner 0x021A21F8 thumb ov021
 *   WEATHER_TASK_InitFog 0x021A22E0 thumb ov021
 *   WEATHER_TASK_SaveCameraPos 0x021A2424 thumb ov021
 *   WEATHER_RAIN_SpawnParticles 0x021EEA18 thumb ov026
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int *WEATHER_TASK_GetWorkBuffer(int *p);
extern void WEATHER_TASK_SetupSpawner(u8 *p, int a, int b, int c, int d, int e, int f, int g, int h);
extern void WEATHER_TASK_InitFog(u32 *p, int a, int b, int c);
extern void WEATHER_TASK_SaveCameraPos(u8 *p);
extern void WEATHER_RAIN_SpawnParticles(int a, int n, int idx);

int WEATHER_RAIN_Begin(int a, int b)
{
    int *p;

    p = WEATHER_TASK_GetWorkBuffer((int *)a);
    WEATHER_TASK_SetupSpawner((u8 *)a, 1, 8, 2, 0, -4, 2, 1, (int)((void *)WEATHER_RAIN_SpawnParticles));
    WEATHER_TASK_InitFog((u32 *)a, 8, 0x7FDF, b);
    *p = 1;
    WEATHER_TASK_SaveCameraPos((u8 *)a);
    return 1;
}
